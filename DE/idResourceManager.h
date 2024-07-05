#pragma once
#include "TypeInfoManager.h"




class idResourceManager {

private:

 //   static const std::string m_name_not_found_str;
	//static classVariableInfo_t* m_name_VarInfo;

public:


    static std::string getDeclWeaponName(idDeclWeapon* idDeclWeaponPtr);

    static std::string getDeclWeaponReticleName(idDeclWeaponReticle* idDeclWeaponReticlePtr);

    static std::string getDeclHudElementName(idDeclHUDElement* idDeclHUDElementPtr);

    static std::string getIdMaterial2Name(idMaterial2* matr);

    static std::string getidDeclInventoryName(idDeclInventory* decl);

   
};

//classVariableInfo_t* idResourceManager::m_name_VarInfo = nullptr;
//const std::string idResourceManager::m_name_not_found_str = "idRes_name_not_found";










//#pragma once
//#include "TypeInfoManager.h"



//? static verison:
//class idResourceManager {
//
//private:
//
//    static const std::string m_name_not_found_str;
//    static classVariableInfo_t* m_name_VarInfo;
//
//public:
//
//    static bool initVarInfos() {
//        logDebug("initVarInfos");
//        m_name_VarInfo = TypeInfoManager::findClassField("idResource", "name");
//        if (!m_name_VarInfo) {
//            logErr("initVarInfos: failed to acquire m_name_VarInfo");
//            return false;
//        }
//        logInfo("initVarInfos: Succes");
//        return true;
//    }
//
//    static classVariableInfo_t* getNameVarInfo() {
//        return m_name_VarInfo;
//    }
//
//    static std::string getName() {
//        logDebug("getName");
//        if (!m_name_VarInfo) {
//            logErr("getName: m_name_VarInfo is nullptr returning m_name_not_found_str");
//            return m_name_not_found_str;
//        }
//        if (!MemHelper::isBadReadPtr(this)) {
//            char* namePtr = (idResourcePtr + m_name_VarInfo->offset);
//            logInfo("getName: %s", namePtr);
//            return std::string(namePtr);
//        }
//        return m_name_not_found_str;
//    }
//
//    /* static std::string getName(char* idResourcePtr) {
//         logDebug("getName");
//         if (!m_name_VarInfo) {
//             logErr("getName: m_name_VarInfo is nullptr returning m_name_not_found_str");
//             return m_name_not_found_str;
//         }
//         if (!MemHelper::isBadReadPtr(idResourcePtr)) {
//             char* namePtr = (idResourcePtr + m_name_VarInfo->offset);
//             logInfo("getName: %s", namePtr);
//             return std::string(namePtr);
//         }
//         return m_name_not_found_str;
//     }*/
//
//};
//
//classVariableInfo_t* idResourceManager::m_name_VarInfo = nullptr;
//const std::string idResourceManager::m_name_not_found_str = "idRes_name_not_found";