#pragma once
#include <string>
#include <vector>
#include "../DE/TypeInfoManager.h"
#include <regex>


class EnumsDefFileGenerator {
private:

    std::string m_enumFileInclude = "#include \"GeneratedEnums.h\"\n";

    static std::string getPragmaOnce() {
        return "#pragma once\n";
    }

    static std::string getEnumFileIncludesStr() {
        return "#include <cstdint>\n";
    }

    static std::string getClassesFileIncludesStr() {
        std::string result;
        result += "#include \"idLib.h\"\n";
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

    //! i made that up from trial and error by checking the enums in eternal lib and checking what was the type for each types of enum, so it may be fragile but i suppose it will do.
    static std::string getEnumTypeAsStr(int enumType) {
        switch (enumType) {
        case 0:
            return "int8_t";  // type 0
        case 1:
            return "uint8_t"; // type 1
        case 2:
            return "int16_t"; // type 2
        case 3:
            return "uint16_t"; // type 3
        case 4:
            return "int32_t"; // type 4
        case 5:
            return "uint32_t"; // type 5
        case 6:
            return "int64_t"; // type 6
        case 7:
            return "uint64_t"; // type 7
        default:
            return "ERROR COULD NOT FIND ENUM TYPE ENUM IS NOT VALID"; // Unknown type
        }
    }

    static std::string getEnumDefStr(enumTypeInfo_t* enumTypeInfo) {
        int counter = 1;

        std::string result;
        if (!enumTypeInfo) {
            logErr("getEnumDefStr: enumTypeInfo is null can not get def");
            return result;
        }
        logInfo("getEnumDefStr: found valueIndexLength: %d", enumTypeInfo->valueIndexLength);
        result += "enum ";
        result += replaceDoubleScopeWithUnderscore(enumTypeInfo->name); //! making sure there is no ::
        result += " : ";
        result += getEnumTypeAsStr(enumTypeInfo->type);
        //result += getEnumTypeAsStr(enumTypeInfo->type);
        result += " {\n";


        for (auto eval = enumTypeInfo->values; eval && eval->name && eval->name[0]; eval++) {

            result += eval->name;
            result += " = ";
            result += std::to_string(eval->value);
            if (counter >= enumTypeInfo->valueIndexLength) {
                result += "\n";
            }
            else {
                result += ",\n";
            }
            counter++;
            //logInfo("getEnumDefStr for loop result is: %s", result.c_str());
        }
        result += "};\n";

        return result;
    }


    static std::string replaceDoubleScopeWithUnderscore(std::string typeName) {
        std::regex doubleScope("::");
        return std::regex_replace(typeName, doubleScope, "_");
    }
   

public:

    static void DumpEnumDefs() {

        std::string result;
        result += getPragmaOnce();
        result += "\n";
        result += getEnumFileIncludesStr();
        result += "\n\n";

        std::vector<enumTypeInfo_t*> enumTypesInfoVec;

        enumTypesInfoVec.push_back(TypeInfoManager::FindEnumInfo("fxCondition_t"));
        enumTypesInfoVec.push_back(TypeInfoManager::FindEnumInfo("idDeclWeapon::weaponSelectionGroup_t"));
        enumTypesInfoVec.push_back(TypeInfoManager::FindEnumInfo("idDeclWeapon::weaponSelectionGroupSlot_t"));
        enumTypesInfoVec.push_back(TypeInfoManager::FindEnumInfo("idDeclWeaponReticle::reticleStyle_t"));
        enumTypesInfoVec.push_back(TypeInfoManager::FindEnumInfo("idSWFWidgetState_t"));
        enumTypesInfoVec.push_back(TypeInfoManager::FindEnumInfo("idHUD_AbilityIndicators::elementState_t"));



        for (size_t i = 0; i < enumTypesInfoVec.size(); i++)
        {
            result += getEnumDefStr(enumTypesInfoVec[i]);
            result += "\n\n";
        }

        try
        {
            FILE* outtypes = nullptr;
            fopen_s(&outtypes, "eternal_Enums_K.h", "w");
            if (outtypes) {
                logInfo("writing File eternal_Enums_K.h....");
                fputs(result.c_str(), outtypes);
                fclose(outtypes);
            }
            else {
                logErr("outtypes is null for Enums (?!)");
            }

        }
        catch (const std::exception& ex)
        {
            logErr("DumpEnumDefs: failed: %s", ex.what());
        }


        //? btw handle if not exist as i just crash cause enum didnt exist




    }
};

