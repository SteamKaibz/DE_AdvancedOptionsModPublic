#pragma once


#include <Windows.h>
#include <vector>
#include "MemHelper.h"
#include "idLib.h"
#include "GeneratedClasses.h"
#include "../K_Utils/K_Utils.h"

//#include "CustomizedWeaponManager.h"

//#include "Config.h"

//? had to make my own as it's not documented
struct declWeaponListContainer_K {
    char pa0[8];
    unsigned long long resourceID;
    idDeclWeapon* declWeaponPtr;
};


//? this whole class is a bit of a mess...i think we could do better, next mod update....
class idResourceListManager {

private:


    
    //! _QWORD *__fastcall idResourceListManager::ForClassName(char *a1)
    typedef uintptr_t(__fastcall* idResourceList__ForClassName)(const char* a1);

    //! new version 25/4/24
    typedef idResourceList* (__fastcall* getIdResourceListForClassName_t)(const char* clsName);
   

    static inline std::vector<__int64> m_idMaterial2Vec;

    //! oldversion, i'll keep that for now to not break old funcs
    static inline __int64 m_idResourceListForClassNameAddr = 0;

    static inline getIdResourceListForClassName_t m_getResourceListForClsNameFp = nullptr;

    //! 12/5/24 getResourceFromidResourceList_t_MB_A511B0
    //typedef __int64(__fastcall* getResourceFromidResourceList_t)(__int64 resourceList_t_a1, int a2);
    typedef __int64(__fastcall* getResourceFromidResourceList_t)(resourceList_t_K* resourceList_t_Ptr, int a2);

    static inline getResourceFromidResourceList_t m_getResourceFp = nullptr;


public:

    static bool acquirreResourceListForClassNameAddr(__int64 addr);  

    static bool acquireGetResourceFp(__int64 addr);

    //? each ressource is in a list that start at resourceListPtr + 0x10 and each element separated by 0x18 
    static uintptr_t getResourceListFirstElementPtr(const char* classname);



    static std::vector<idDeclWeapon*> getCustomizableDeclWeaponsPtrsVec();

    static std::vector<idDeclWeapon*> getDeclWeaponsStartingWith(std::string inputStr);

    //! this should list res like declWeapons for ex
    static std::vector<idResource*> getResourceVecForClsName(const char* classname);

	static void addResourcePtr(__int64 ptr);

    static void printIdMaterialsInfo();

    static const std::vector<__int64>& getIdResources();


    static void debugLogPlayerDeclWeapons();

    static void debugPrintIdMaterial2ResourceListAddr();

    static void getidDeclWeaponResourceListTest();

    static uintptr_t getIdResourceListForClsName(std::string inputStr);

    //! from __int64 __fastcall getResourceFromidResourceList_t_MB_A511B0(__int64 resourceList_t_a1, int a2)
    //static __int64 getResource(void* resourceList_t_a1, int a2);
    static idDeclGlobalShell* getIdDeclGlobalShellPtr();
};

