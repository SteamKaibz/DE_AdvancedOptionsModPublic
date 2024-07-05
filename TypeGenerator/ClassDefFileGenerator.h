#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::hex and std::setw
#include <sstream> // For stringstream
#include <cstdint>
#include <regex>
#include "../DE/TypeInfoManager.h"
#include "ClassDef.h"
#include "ClassDefContainer.h"
#include "varInfoCustom.h"




class ClassDefFileGenerator {

private:

    std::string m_enumFileInclude = "#include \"GeneratedEnums.h\"\n"; 

    static std::string getPragmaOnce() {
        return "#pragma once\n";
    }


    static std::string getClassesFileIncludesStr() {
        std::string result;
        result += "#include \"idLib.h\"\n";
        result += "#include \"idColor.h\"\n";
        result += "#include \"GeneratedEnums.h\"\n";
        result += "\n\n";
        return result;
    }

    static std::string getPragmaPackStartStr() {
        return "#pragma pack(push, 1) // making sure no padding is added by compiler\n\n";
    }

    static std::string getPragmaPackEndStr() {
        return "#pragma pack(pop) // Restore default packing alignment\n";
    }

    

    

    //! i struggled with this simply because i was inputing a str that started with 4 spaces so ofc it didn't trigger
    //static std::string formatType(std::string typeWithOpsStr) {
    //    logInfo("formatType: debug input is: %s", typeWithOpsStr.c_str());      
    //    if (typeWithOpsStr.starts_with("idArray")) {
    //        logInfo("formatType: found idArray type: %s", typeWithOpsStr.c_str());
    //        auto firstFieldVar = TypeInfoManager::findClassFirstField(typeWithOpsStr.c_str());
    //        if (!firstFieldVar) {
    //            logErr("formatClass failed to find typeWithOpsStr for: %s", typeWithOpsStr.c_str());
    //            return typeWithOpsStr;
    //        }
    //        logInfo("formatType: formatted idArray type: %s", firstFieldVar->type);
    //        return firstFieldVar->type;
    //    }
    //    return typeWithOpsStr;
    //}
       
      
    static std::string getClassDefStr(ClassDef classDef) {
        //logInfo("debug: logClassDef called");
        std::string fourSpaces = "    ";
        /*const int defaultOffsetIfInheritFromIdResource = 0x40;
        const int defaultOffsetIfInheritFromidInventoryItem = 0x40;*/

        if (!classDef.classInfoPtr) {
            logErr("getClassDefStr: can not get class def cause classDef.classInfoPtr is null");
            return "\n!!! ERROR COULD NOT GENERATE CLASS DEF CAUSE OF classInfoPtr BEING NULL, CHECK THE LOG !!!\n";
        }
        if (classDef.varInfoVec.empty()) {
            logErr("getClassDefStr: varInfoVec is empty, can not get class def check the log there was a problem instanciating this ClassDef ");
            return "\n !!! ERROR COULD NOT GENERATE CLASS DEF CAUSE OF varInfoVec BEING EMPTY, CHECK THE LOG !!!\n";
        }

        logInfo("getClassDefStr classDef.classInfoPtr->name is %s and classDef.className: %s", classDef.classInfoPtr->name, classDef.classNameStr.c_str());

        std::ostringstream result;
        //std::string inheritanceStr = findInheritancesStr(classDef.classInfoPtr);
        result << "\n";
        if (classDef.hasInheritance()) {
            result << "// " << classDef.classInfoPtr->name << " : " << classDef.getInheritanceListStr() << "\n";
        }        
        //std::string formatedClassName = replaceDoubleScopeWithUnderscore(classDef.classInfoPtr->name);
        result << "class " << classDef.getFormatedClsName() << " {\npublic:\n";

        int currentOffset = 0;

        //logInfo("debug: logClassDef: so far result: %s", result.str().c_str());

        //? I'm removing the 'fake' inheritance system, instead, if we need the value of an inherited field, we just use a wrapper cls, cast the inherited cls pointer on the obj and get it this way. MUCH cleaner and less prone to potential errors.       

        for (classVariableInfo_t* varInfo : classDef.varInfoVec) {
            if (!varInfo) {
                logErr("getClassDefStr: found null varInfo, something is wrong, not logging class");
                return "\n !!! ERROR COULD NOT GENERATE CLASS DEF CAUSE A varInfo IS NULL, CHECK THE LOG !!!\n";
            }         
           
            //logInfo("debug: logClassDef: varInfo is not null it seems and its name is: %s", varInfo->name);
            // Calculate padding size based on the difference between the current offset and member offset
            int paddingSize = varInfo->offset - currentOffset;

            // Add padding if necessary  
            if (paddingSize > 0) {
                result << fourSpaces  << "char pad_" <<  std::setfill('0') << std::dec << std::uppercase  << currentOffset << "["  << paddingSize << "]; // offset: " << std::hex << currentOffset  << "h" <<  " (" << std::dec << currentOffset << "d) size: " << paddingSize << "\n";
            }
           

            varInfoCustom customVarInfo(varInfo);
            result << customVarInfo.getStr();
            
            currentOffset = varInfo->offset + varInfo->size;
        }

        std::string lastPaddingStr = classDef.getLastPaddingStr(currentOffset);

        if (!lastPaddingStr.empty()) {
            result << fourSpaces << lastPaddingStr << "\n";
        }
        result << "}; // size: " << std::dec << classDef.classInfoPtr->size  << "\n\n";

        return result.str();
        //logInfo("%s", result.str().c_str());
        
    }



public:    

    static void dumpClassDefs() {

        std::string result;

        result += getPragmaOnce();
        result += getClassesFileIncludesStr();
        result += getPragmaPackStartStr();
        result += "\n";
        result += "//? THOSES TYPES HAVE BEEN GENERATED AUTOMATICALLY BY TygeGenerator::dumpClassDefs CLS, IF THE GAMES IS UPDATED AT SOME POINT IN THE FUTURE? JUST LAUNCH this func (numpad 1 when mod loaded in debug mode) AND YOU WILL GET THOSES TYPES/CLASSES WITH CORRECTED OFFSETS DUMPED IN A FILE IN THE SAME FOLDER AS THE GAME";
        result += "\n\n";
        //logInfo("dumpClassDefs: debug: result with start prags:: %s", result.c_str());

        //std::vector<ClassDef> classDefsVec = ClassDefContainer::getInstance();
       
        
        //for (size_t i = 0; i < classDefsVec.size(); i++)
        for (size_t i = 0; i < ClassDefContainer::getInstance().size(); i++)
        {
            result += getClassDefStr(ClassDefContainer::getInstance()[i]);
            //result += getClassDefStr(classDefsVec[i]);
            //logInfo("dumpClassDefs: debug: result in for loop: %s", result.c_str());
            //logClassDef(classDefsVec[i]);
        }

        //logInfo("dumpClassDefs: debug: result before prag end: %s", result.c_str());

        result += "\n\n";
        result += getPragmaPackEndStr();
        result += "\n";

        //logInfo("idActorClsDef generateClassV2 result: %s", result.c_str());

        try
        {
            FILE* outtypes = nullptr;
            fopen_s(&outtypes, "eternal_Classes_K.h", "w");
            if (outtypes) {
                logInfo("writing File eternal_Classes_K.h....");
                fputs(result.c_str(), outtypes);
                fclose(outtypes);
            }
            else {
                logErr("outtypes is null for Classes(?!)");
            }
            
        }
        catch (const std::exception& ex)
        {
            logErr("dumpClassDefs: failed: %s", ex.what());
        }

    }
    

   

    
   
    
   

};


