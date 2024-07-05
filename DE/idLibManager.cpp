#include "idLibManager.h"



void idLibManager::generateIdLibFiles()
{
    int debugSafeCounter = 0;
    int counter = 0;
    int classCounter = 0;
    int enumCounter = 0;


    logInfo("generateIdLibFiles: starting...");


    std::filesystem::path idaStringsFile = m_idaIdbStringsFileName;
    if (!std::filesystem::exists(idaStringsFile)) {
        logErr("generateIdLibFiles: m_idaIdbStringsFileName: %s not found, can not generate idLib returning", m_idaIdbStringsFileName.c_str());
        return;
    }

    auto idaAllStrsSet = K_Utils::loadFileToSet(m_idaIdbStringsFileName);

    std::vector<std::string> classTypesStrVec{};
    classTypesStrVec.reserve(131072);

    std::vector<std::string> enumTypesStrVec{};
    enumTypesStrVec.reserve(131072);

    for (const auto& idaStr : idaAllStrsSet)
    {
        bool isMatch = false;

        auto clsInfoPtr = TypeInfoManager::findClassInfo(idaStr.c_str());
        if (clsInfoPtr) {
            isMatch = true;
            auto clsStr = getClsInfoAsText(clsInfoPtr);
            if (!clsStr.empty()) {
                classTypesStrVec.push_back(clsStr);
                classCounter++;
            }
        }
        auto enumInfoPtr = TypeInfoManager::FindEnumInfo(idaStr.c_str());
        if (enumInfoPtr) {
            isMatch = true;
            auto enumStr = getEnumInfoAsText(enumInfoPtr);
            if (!enumStr.empty()) {
                enumTypesStrVec.push_back(enumStr);
                enumCounter++;
            }
        }

        if (!isMatch) {
            //logWarn("generateIdLibFiles: failed to find match for ida str: %s", idaStr.c_str());
        }
    }
    std::string clsSummary = "\n" + std::to_string(classCounter) + " classes types were found.";
    classTypesStrVec.push_back(clsSummary);

    std::string enumsSummary = "\n" + std::to_string(enumCounter) + " enums types were found.";
    enumTypesStrVec.push_back(enumsSummary);

    K_Utils::saveVecToFile(m_idLibClassesFileName, classTypesStrVec);
    K_Utils::saveVecToFile(m_idLibEnumsFileName, enumTypesStrVec);

    logInfo("generateIdLibFiles: done. found: %d classes and %d enums", classCounter, enumCounter);
}





std::string idLibManager::getClsInfoAsText(classTypeInfo_t* typeInfoPtr)
{
    //logInfo("getClsInfoAsText: parsing: cls: %s addr: %p", typeInfoPtr->name, typeInfoPtr);

    std::string clsTxt;

    if (MemHelper::isBadReadPtr(typeInfoPtr)) {
        logErr("getClsInfoAsText: typeInfoPtr is bad ptr: %p ", typeInfoPtr);
        return clsTxt;
    }

   /* clsTxt += "\n// Cls index: ";
    clsTxt += std::to_string(clsCounter);*/


    std::string inheritanceChainStr = getInheritanceChainStr(typeInfoPtr);
  
    if (!inheritanceChainStr.empty()) {
        clsTxt += "\n// Inheritance: ";
        clsTxt += inheritanceChainStr;
    }

    clsTxt += "\nstruct ";
    clsTxt += typeInfoPtr->name;

    //! not sure about this cmt as the crash happened from somewhere else as far as i remember...
    //x this will (create crash at some point:
    //if (typeInfoPtr->superType && typeInfoPtr->superType[0]) {

    if (typeInfoPtr->superType && (typeInfoPtr->superType[0] != '\0')) {
        clsTxt += " : public ";
        clsTxt += typeInfoPtr->superType;
    }
    clsTxt += " {\n";

    /*logInfo("dumpTypeTest: &typeInfoPtr->variables: %p ", &typeInfoPtr->variables);
    logInfo("dumpTypeTest: size of classVariableInfo_t: %zu (dec)", sizeof(classVariableInfo_t));*/

    for (auto member = typeInfoPtr->variables; member && member->name && member->name[0]; ++member) {

        clsTxt += "\t//";

        std::string offsetHex = K_Utils::intToHexString(member->offset);
        clsTxt += "Offset ";
        clsTxt += offsetHex.c_str();  
        clsTxt += " \tSize ";
        std::string sizeHex = K_Utils::intToHexString(member->size);
        clsTxt += sizeHex;
        clsTxt += " (";
        clsTxt += std::to_string(member->size);
        clsTxt += ")";

        //? could not find a use for flags.
       /* clsTxt += " Flags: ";
        clsTxt += std::to_string(member->flags);
        clsTxt += " ";*/

        if (member->comment && member->comment[0]) {
            clsTxt += "\t ";
            clsTxt += member->comment;           
        }

        clsTxt += "\n\t";

        clsTxt += member->type;
        if (member->ops) {
            clsTxt += member->ops;
        }
        clsTxt += " ";
        clsTxt += member->name;
        clsTxt += ";\n";
    }
    clsTxt += "}; // Size: " + K_Utils::intToHexString(typeInfoPtr->size) + " (Size Dec: " + std::to_string(typeInfoPtr->size) + ")\n";
    return clsTxt;
}


//std::string idLibManager::getSuperTypeStr(classTypeInfo_t* typeInfoPtr) {
//
//    std::string result;
//
//    if (typeInfoPtr->superType < 0) return result;
//
//    typeInfoPtr = typeInfoManager::findClassTypeInfoByIndex(typeInfoPtr->superType);
//
//    if (!typeInfoPtr || typeInfoPtr->name == nullptr) {
//        logWarn("getSuperTypeStr: typeInfoPtr is nullptr || typeInfoPtr->name == nullptr returning empty str");
//        return result;
//    }
//
//    return typeInfoPtr->name;
//}



std::string idLibManager::getInheritanceChainStr(classTypeInfo_t* typeInfoPtr)
{
    std::vector<std::string> inheritanceStrVec;
    std::string result;

    while (true)
    {
        if (!(typeInfoPtr->superType) || !(typeInfoPtr->superType[0])) break;
        //typeInfoPtr = typeInfoManager::findClassTypeInfoByIndex(typeInfoPtr->superType);
        //logInfo("getInheritanceChainStr typeInfoPtr->superType: %s", typeInfoPtr->superType);
        typeInfoPtr = TypeInfoManager::findClassInfo(typeInfoPtr->superType);
        //typeInfoPtr = typeInfoPtr->superType;
        if (!typeInfoPtr || typeInfoPtr->name == nullptr || !typeInfoPtr->name[0]) {
            logErr("getInheritanceChainStr: typeInfoPtr == nullptr || typeInfoPtr->name == nullptr || !typeInfoPtr->name[0] breaking");
            break;
        }
        inheritanceStrVec.push_back(typeInfoPtr->name);
    }


    for (size_t i = 0; i < inheritanceStrVec.size(); i++)
    {
        if (i != 0) {
            result += ": ";
        }
        result += inheritanceStrVec[i];
    }

    return result;
}




std::string idLibManager::getUniqueEnumVarName(std::string enumVarName) {
    for (size_t i = 0; i < m_uniqueEnumVarNamesVec.size(); i++)
    {
        if (enumVarName == m_uniqueEnumVarNamesVec[i]) {
            std::string uniqueName = enumVarName + "_dup_" + std::to_string(m_dupeEnumVarsCounter);
            m_dupeEnumVarsCounter++;
            return uniqueName;
        }
    }
    m_uniqueEnumVarNamesVec.push_back(enumVarName);
    return enumVarName;
}

std::string idLibManager::getEnumInfoAsText(enumTypeInfo_t* enumTypeInfoPtr)
{
    int enumVarsCounter = 0;

    std::string enumAsStr;
    if (!enumTypeInfoPtr) {
        logErr("getEnumInfoAsText: enumTypeInfo is null can not get def");
        return enumAsStr;
    }
    enumAsStr += "enum ";

    //enumAsStr += replaceDoubleScopeWithUnderscore(enumTypeInfoPtr->name);
    enumAsStr += enumTypeInfoPtr->name;

    enumAsStr += " {\n";


    for (auto eval = enumTypeInfoPtr->values; eval && eval->name && eval->name[0]; eval++) {

        enumAsStr += "\t";
        enumAsStr += getUniqueEnumVarName(eval->name);
        enumAsStr += " = ";
        std::string enumValeHex = K_Utils::intToHexString(eval->value);
        enumAsStr += enumValeHex;
        enumAsStr += ",\n";
        enumVarsCounter++;
    }
    enumAsStr += "};\n";

    if (enumVarsCounter == 0) {
        return std::string();
    }
    return enumAsStr;
}



//? this will not work because it misses sooo many classes, the best way to do it is, imo, to get strings from ida, or use the list from meathook mod.
//void idLibManager::generateIdLibClassesFile()
//{
//    int classNum = 0;
//
//    std::vector<std::string> classTypesStrVec{};
//    classTypesStrVec.reserve(131072);
//
//    typeInfoGenerated_t* typeInfoGenerated = TypeInfoManager::getTypeInfoGenerated_t();
//    if (!typeInfoGenerated) {
//        logErr("generateIdLibClassesFile: typeInfoGenerated is nullptr, can not generate.");
//        return;
//    }
//
//    classNum = typeInfoGenerated->numClasses;
//    classTypeInfo_t* clsTypeInfoPtr = typeInfoGenerated->classes;
//
//    for (size_t i = 0; i < classNum; i++)
//    {
//        if (!clsTypeInfoPtr || !clsTypeInfoPtr->name) {
//            logWarn("generateIdLibClassesFile: clsInfoPtr is bad ptr or name is null: stopping lib generation...");
//            break;
//        }
//
//        else {
//            logInfo("generateIdLibClassesFile: debug: clsTypeInfoPtr: %p seems to be a valid ptr and value its name is: %s", clsTypeInfoPtr, clsTypeInfoPtr->name);
//        }
//
//        std::string clsStr = getClsInfoAsText(clsTypeInfoPtr, i);
//
//        logInfo("generateIdLibClassesFile: debug:  clsStr: %s", clsStr.c_str());
//        //logInfo("generateIdLibClassesFile: debug: clsTypeInfoPtr: %p clsStr: %s", clsTypeInfoPtr, clsStr.c_str());
//
//        if (!clsStr.empty()) {
//            classTypesStrVec.push_back(clsStr);
//        }
//
//        clsTypeInfoPtr++;
//    }
//
//    std::string clsSummary = "\n" + std::to_string(classTypesStrVec.size()) + " classes types were found. numClasses was: " + std::to_string(classNum);
//    classTypesStrVec.push_back(clsSummary);
//
//    K_Utils::saveVecToFile(m_idLibClassesFileName, classTypesStrVec);
//
//
//    logInfo("generateIdLibClassesFile: done");
//
//}