#pragma once

#include "../DE/TypeInfoManager.h"


//std::vector<ClassDef> classDefsVec;


struct ClassDef {

    //! not adding a fake classVariableInfo_t ptr to fake inheritance of idResource it's not only inelegant but could lead to error and also setting/changing a char* value is asking for trouble, ask gepeto. 
    classTypeInfo_t* classInfoPtr = nullptr;
    std::vector<classVariableInfo_t*> varInfoVec;
    std::vector<std::string> inheritanceStrVec;
    std::string classNameStr;
    int currentOffset = 0;

    ClassDef(const char* classNameArg, const std::vector<const char*>& vars)
    {

        classNameStr = classNameArg;

        classInfoPtr = TypeInfoManager::findClassInfo(classNameStr.c_str());
        if (!classInfoPtr) {
            logErr("ClassDef: failed to find classInfo for classNameStr:  %s", classNameStr.c_str());
            return;
        }

        logInfo("ClassDef: classNameArg: %s and classNameStr: %s classInfoPtr classInfoPtr->name: %s", classNameArg, classNameStr.c_str(), classInfoPtr->name);

        for (size_t i = 0; i < vars.size(); i++)
        {
            auto member = TypeInfoManager::findClassField(classNameStr.c_str(), vars[i]);
            if (!member) {
                logErr("ClassDef: failed to find findClassField for classNameStr.c_str(): %s var: %s .Clearing varInfoVec so that this ClassDef doesn't get processed, you should check if there is a type in the var names", classNameStr.c_str(), vars[i]);
                varInfoVec.clear();
                return;
            }
            //! we still add a null member so that we can detect it in the dump and skip dump for this class if it happens
            varInfoVec.push_back(TypeInfoManager::findClassField(classNameStr.c_str(), vars[i]));
        }

        acquirreInheritanceList();
        SortVarInfoVec();

    }

    std::string getFormatedClsName() {
        if (classInfoPtr) {
            return replaceDoubleScopeWithUnderscore(classInfoPtr->name);
        }
        return "*/! ERROR GETTING FORMATTED CLS NAME !/*";
    }

    static std::string replaceDoubleScopeWithUnderscore(std::string typeName) {
        std::regex doubleScope("::");
        return std::regex_replace(typeName, doubleScope, "_");
    }


    //! this needs to be static btw: "In C++, when you want to use a member function as a comparison function for sorting with std::sort, it must be a static member function."
    static bool CompareByOffset(const classVariableInfo_t* a, const classVariableInfo_t* b) {
        return a->offset < b->offset;
    }

    // Function to sort varInfoVec by offset
    void SortVarInfoVec() {
        std::sort(varInfoVec.begin(), varInfoVec.end(), CompareByOffset);
    }

    void acquirreInheritanceList() {

        inheritanceStrVec.clear();

        if (!classInfoPtr) {
            logErr("acquirreInheritanceList: classInfoPtr is null for cls: %s returning", classNameStr.c_str());
            return;
        }

        //! this seems overkill but i had weird results and i wondered why then i realised that the line  classInfoPtr = TypeInfoManager::findClassInfo(superType.c_str()); in the while loop is screaming for trouble, we don't touch classInfoPtr.
        classTypeInfo_t* tempClassInfo = TypeInfoManager::findClassInfo(classNameStr.c_str());

        std::string superType;

        while (true)
        {
            if (!tempClassInfo) {
                logWarn("acquirreInheritanceList: tempClassInfo is nullptr, breaking");
                break;
            }
            superType = tempClassInfo->superType;

            if (superType.empty()) {
                //logInfo("acquirreInheritanceList: found empty string breaking");
                break;
            }
            //else if (superType == "idEventArgUser") {
            //    //logInfo("acquirreInheritanceList: found idEventArgUser, breaking.");
            //    inheritanceStrVec.push_back("idEventArgUser"); 
            //    break;
            //}
            inheritanceStrVec.push_back(superType);
            tempClassInfo = TypeInfoManager::findClassInfo(superType.c_str());
        }
    }

    std::string getInheritanceListStr() {

        if (inheritanceStrVec.size() <= 0) {
            return std::string();
        }

        //std::string result = "// ";
        std::string result;

        for (size_t i = 0; i < inheritanceStrVec.size(); i++) {
            result += inheritanceStrVec[i];

            // Check if this is the last element
            if (i < inheritanceStrVec.size() - 1) {
                result += " : ";
            }
        }
        return result;
    }

    bool hasInheritance() {
        return (inheritanceStrVec.size() > 0);
    }

    //! if a cls inherits form idResource that means it has a name (str) field
   /* bool isClsInheritFromIdResource() {
        for (size_t i = 0; i < inheritanceStrVec.size(); i++)
        {
            if (inheritanceStrVec[i] == "idResource") {
                logInfo("isClsInheritFromIdResource: cls: %s inherits from idResource", classNameStr.c_str());
                return true;
            }
        }
        return false;
    }

    bool isClsInheritFromidInventoryItem() {
        for (size_t i = 0; i < inheritanceStrVec.size(); i++)
        {
            if (inheritanceStrVec[i] == "idInventoryItem") {
                logInfo("isClsInheritFromidInventoryItem: cls: %s inherits from idInventoryItem", classNameStr.c_str());
                return true;
            }
        }
        return false;
    }*/

    classVariableInfo_t* getLastVarInfoEntry() {
        if (!varInfoVec.empty()) {
            return varInfoVec.back();           
        }
        return nullptr;
    }

    std::string getLastOffsetInHex(int offset) {
        if (offset < 0) {
            logErr("getLastOffsetInHex: offset is <0: %d", offset);
            return std::string();
        }
        std::stringstream ss;
        ss << std::hex <<  std::uppercase << offset << "h";
        return ss.str();
    }

    std::string getLastPaddingStr(int currentOffset) {
        classVariableInfo_t* lastVarInfo = getLastVarInfoEntry();

        if (lastVarInfo == nullptr) {
            logErr("getLastPaddingStr: lastVarInfo is nullPtr can not get last Padding right");
            return "ERROR LAST PADDING CAN NOT BE COMPUTED, CHECK THE LOG";
        }

        if (!classInfoPtr) {
            logErr("getLastPaddingStr: classInfoPtr is nullPtr can not get last Padding right");
            return "ERROR LAST PADDING CAN NOT BE COMPUTED, CHECK THE LOG";
        }

        //int lastPaddingSize = classInfoPtr->size - currentOffset - lastVarInfo->size;       
        int lastPaddingSize = classInfoPtr->size - currentOffset ;       

       

        if (lastPaddingSize < 0) {
            logErr("getLastPaddingStr: for class: %s lastPaddingSize is < 0, can not get last Padding right. classInfoPtr->size: %d currentOffset: %d lastVarInfo->size: %d lastVarInfo->name: %s", classInfoPtr->name, classInfoPtr->size, currentOffset, lastVarInfo->size, lastVarInfo->name);
            return "ERROR LAST PADDING CAN NOT BE COMPUTED, CHECK THE LOG";
        }
        else {
            logInfo("getLastPaddingStr: for class: %s lastPaddingSize == %d classInfoPtr->size: %d currentOffset: %d lastVarInfo->size: %d lastVarInfo->name: %s", classInfoPtr->name, lastPaddingSize, classInfoPtr->size, currentOffset, lastVarInfo->size, lastVarInfo->name);
        }

        //logInfo("debug crash end");


        if (lastPaddingSize == 0) { 
            return std::string(); //! this is ok it means we have all the fields of the class even if it'll be rare
        }

        std::string result;
        result += "char pad_End[";
        result += std::to_string(lastPaddingSize);
        result += "]; // offset: ";       
        result += getLastOffsetInHex(currentOffset);
        //? i crashed (and will again) many times because i would write smth like: result += " (" + classInfoPtr->size);  and forgeting to make it a str first and 
        result += " (" + std::to_string(currentOffset); // size of last pad in dec
        result += "d) size: ";       
        result += std::to_string(lastPaddingSize);
        return result;
    }

   
};
