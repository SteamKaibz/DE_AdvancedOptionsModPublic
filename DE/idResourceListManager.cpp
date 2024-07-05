#include "idResourceListManager.h"

 bool idResourceListManager::acquirreResourceListForClassNameAddr(__int64 addr) {
    if (MemHelper::isBadReadPtr((void*)addr)) {
        return false;
    }
    m_idResourceListForClassNameAddr = addr;
    m_getResourceListForClsNameFp = reinterpret_cast<getIdResourceListForClassName_t>(addr);
    logInfo("acquirreResourceListForClassNameAddr: m_idResourceListForClassNameAddr and m_getResourceListForClsNameFp set to: %p ", m_getResourceListForClsNameFp);
    return true;
}

 bool idResourceListManager::acquireGetResourceFp(__int64 addr)
 {
     if (MemHelper::isBadReadPtr((void*)addr)) {
         m_getResourceFp = nullptr;
         return false;
     }
     m_getResourceFp = (getResourceFromidResourceList_t)addr;
     logInfo("acquireGetResourceFp: m_getResourceFp set to: %p ", m_getResourceFp);
     return true;
 }

 void idResourceListManager::debugPrintIdMaterial2ResourceListAddr() {   

    auto pidResourceList__ForClassNameFunc = reinterpret_cast<idResourceList__ForClassName>(m_idResourceListForClassNameAddr);
    uintptr_t resourceListAddr = pidResourceList__ForClassNameFunc("idMaterial2");
    logInfo("debugPrintIdMaterial2ResourceListAddr: resourceListAddr: %p", (void*)resourceListAddr);
}

 void idResourceListManager::getidDeclWeaponResourceListTest() {   

    auto pidResourceList__ForClassNameFunc = reinterpret_cast<idResourceList__ForClassName>(m_idResourceListForClassNameAddr);
    uintptr_t resourceListAddr = pidResourceList__ForClassNameFunc("idDeclWeapon");
    logInfo("getidDeclWeaponResourceListTest: resourceListAddr: %p", (void*)resourceListAddr);
}


 uintptr_t idResourceListManager::getIdResourceListForClsName(std::string inputStr) {
     auto pidResourceList__ForClassNameFunc = reinterpret_cast<idResourceList__ForClassName>(m_idResourceListForClassNameAddr);
     uintptr_t resourceListAddr = pidResourceList__ForClassNameFunc(inputStr.c_str());
     return resourceListAddr;
 }




 idDeclGlobalShell* idResourceListManager::getIdDeclGlobalShellPtr() {

     idResourceList* idDeclGlobalShellResListPtr = (idResourceList * )idResourceListManager::getIdResourceListForClsName("idDeclGlobalShell");

     if (!idDeclGlobalShellResListPtr) {
         logErr("getIdDeclGlobalShellPtr: failed to get idDeclGlobalShellResList");
         return nullptr;
     }

     //! not really knowing what a2 is, but in ida 0 works for this specific resource.
     return (idDeclGlobalShell*)m_getResourceFp(idDeclGlobalShellResListPtr->resourceList, 0);
     //return (idDeclGlobalShell*)getResource(idDeclGlobalShellResListPtr->resourceList, 0);
 }



//? 25/4/24 this is the old version (it still works though)
//! each ressource is in a list that start at resourceListPtr + 0x10 and each element separated by 0x18 
 uintptr_t idResourceListManager::getResourceListFirstElementPtr(const char* classname) {

    if (MemHelper::isBadReadPtr((void*)m_idResourceListForClassNameAddr)) {
        logErr("getResourceListFirstElementPtr: bad ptr for m_idResourceListForClassNameAddr: %p returning ", (void*)m_idResourceListForClassNameAddr);
        return 0;
    }
    auto pidResourceList__ForClassNameFunc = reinterpret_cast<idResourceList__ForClassName>(m_idResourceListForClassNameAddr);
    uintptr_t idDeclInfoTemplatePtr = pidResourceList__ForClassNameFunc(classname);
    logInfo("getResourceListFirstElementPtr: idDeclInfoTemplatePtr: %p", (void*)idDeclInfoTemplatePtr);
    if (MemHelper::isBadReadPtr((void*)idDeclInfoTemplatePtr)) {
        logWarn("getResourceListFirstElementPtr: bad ptr for idDeclInfoTemplatePtr: %p returning ", (void*)idDeclInfoTemplatePtr);
        return 0;
    }
    uintptr_t resourceContainerPtr = *(uintptr_t*)(idDeclInfoTemplatePtr + 8);
    if (MemHelper::isBadReadPtr((void*)resourceContainerPtr)) {
        logWarn("getResourceListFirstElementPtr: bad ptr for resourceContainerPtr: %p returning ", (void*)resourceContainerPtr);
        return 0;
    }
    uintptr_t resourceListPtr = *(uintptr_t*)(resourceContainerPtr + 0x40);
    if (MemHelper::isBadReadPtr((void*)resourceListPtr)) {
        logWarn("getResourceListFirstElementPtr: bad ptr for resourceListPtr: %p returning ", (void*)resourceListPtr);
        return 0;
    }
    auto result = resourceListPtr + 0x10;
    logInfo("getResourceListFirstElementPtr: for class: %s  found resource list start addr: %p ", classname, (void*)result);
    return result;

 }

 


 //! removed the fist, equipment... to only get the weapons user can customize
 std::vector<idDeclWeapon*> idResourceListManager::getCustomizableDeclWeaponsPtrsVec() {

     std::vector<idDeclWeapon*> declWeaponPtrVec;     

     idResourceList* resListPtr = m_getResourceListForClsNameFp("idDeclWeapon");
     if (!resListPtr) {
         logErr("getCustomizableDeclWeaponsPtrsVec: could not get any idDeclWeapon cause resListPtr is null ptr");
         return declWeaponPtrVec;
     }

     declWeaponListContainer_K* containerPtr = (declWeaponListContainer_K*)resListPtr->resourceList->declList.list;
     int declListNum = resListPtr->resourceList->declList.num;

     for (size_t i = 0; i < resListPtr->resourceList->declList.num; i++)
     {
         std::string declName = containerPtr->declWeaponPtr->getNameStr();
         if (declName == "weapon/player/shotgun") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/shotgun_secondary_pop_rockets") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/shotgun_secondary_pop_rockets_mastery") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/shotgun_secondary_full_auto") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/heavy_cannon") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/heavy_cannon_bolt_action") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/heavy_cannon_burst_detonate") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/heavy_cannon_burst_detonate_faster_recharge") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/heavy_cannon_burst_detonate_mastery") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/plasma_rifle") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/plasma_rifle_secondary_aoe") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/plasma_rifle_secondary_aoe_mastery_primary_supercharge") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/plasma_rifle_secondary_microwave") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/rocket_launcher") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/rocket_launcher_detonate") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/rocket_launcher_lock_mod") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/rocket_launcher_lock_mod_mastery") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }         
         else if (declName == "weapon/player/gauss_rifle") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/gauss_rifle_ballista") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/gauss_rifle_destroyer") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }   
         else if (declName == "weapon/player/double_barrel") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/double_barrel_meat_hook") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/double_barrel_primary_lockon") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }         
         else if (declName == "weapon/player/chaingun") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/chaingun_turret_primary") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/chaingun_turret_secondary") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/chaingun_energy_shell_primary") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }        
         //? there are many more bfg versions but....later....
         else if (declName == "weapon/player/bfg") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/unmaykr") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }         
         else if (declName == "weapon/player/crucible") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/hammer") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/hammer_slam") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }
         else if (declName == "weapon/player/hammer_horde") {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }

         containerPtr++;
     }

     return declWeaponPtrVec;

 }

 //! only get the decl which start with a certain str like weapon/player/... meaning not the demon or ai decl weapons;.
 std::vector<idDeclWeapon*> idResourceListManager::getDeclWeaponsStartingWith(std::string inputStr) {
     std::vector<idDeclWeapon*> declWeaponPtrVec;

     idResourceList* resListPtr = m_getResourceListForClsNameFp("idDeclWeapon");
     if (!resListPtr) {
         logErr("getPlayerDeclWeaponsVec: could not get any idDeclWeapon cause resListPtr is null ptr");
         return declWeaponPtrVec;
     }

     declWeaponListContainer_K* containerPtr = (declWeaponListContainer_K*)resListPtr->resourceList->declList.list;
     int declListNum = resListPtr->resourceList->declList.num;    

     for (size_t i = 0; i < resListPtr->resourceList->declList.num; i++)
     {
         std::string declName = containerPtr->declWeaponPtr->getNameStr();
         if (declName.starts_with(inputStr)) {
             declWeaponPtrVec.push_back(containerPtr->declWeaponPtr);
         }

         containerPtr++;
     }

     return declWeaponPtrVec;
 }


 void idResourceListManager::debugLogPlayerDeclWeapons() {

     idResourceList* resListPtr = m_getResourceListForClsNameFp("idDeclWeapon");
     if (!resListPtr) {
         logErr("debugLogPlayerDeclWeapons: could not get any idDeclWeapon cause resListPtr is null ptr");
         return;
     }

     declWeaponListContainer_K* containerPtr = (declWeaponListContainer_K*)resListPtr->resourceList->declList.list;
     int declListNum = resListPtr->resourceList->declList.num;

     logInfo("debugLogPlayerDeclWeapons: Player decl Weapons:");
     for (size_t i = 0; i < resListPtr->resourceList->declList.num; i++)
     {
         std::string declName = containerPtr->declWeaponPtr->getNameStr();
         if (declName.starts_with("weapon/player/")) {
             logInfo("\tname: %s ptr: %p", declName.c_str(), containerPtr->declWeaponPtr);
         }
         containerPtr++;
     }

 }


 //? it might not be safe to use this func for other decl than decl weapons atm cause even if we know the decl weapons are part of a declWeaponListContainer_K we'not sure if the container as the same layout for other decl even if there is a big chance the answer is yes. Keep it though for reference.
 std::vector<idResource*> idResourceListManager::getResourceVecForClsName(const char* classname) {
     std::vector<idResource*> idResVec;

     idResourceList* resListPtr = m_getResourceListForClsNameFp(classname);
     if (!resListPtr) {
         logWarn("getResourceVecForClsName: could not get results for input: %s cause resListPtr is null ptr", classname); 
         return idResVec;
     }
     //? i think our confusion to list through here compare to our code in new colossus (idResourceManager::getResPtrsVecForClsName) is that in colosus the idlist is a list of pointers and here we have a list of a 'container' for whichi i haven't a def yet, in which there is a idDeclWeapo ptr and that containers seems to be of size 0x18, so let's work on that....

     //todo btw why don't we just check //Offset 0x4ED0 	Size 0x18 (24)	 list of the order in which weapons should be auto-selected when the current weapon runs out of ammo    idList < const idDeclWeapon*, TAG_IDLIST, false > weaponAutoSelectPriorityList;  and patch those instead?

     declWeaponListContainer_K* containerPtr = (declWeaponListContainer_K*)resListPtr->resourceList->declList.list;
     int declListNum = resListPtr->resourceList->declList.num;

     logInfo("getResourceVecForClsName debug: containerPtr %p declListNum: %d", containerPtr, declListNum);
     logInfo("getResourceVecForClsName listing decl names:");

     for (size_t i = 0; i < resListPtr->resourceList->declList.num; i++)
     {
         std::string declName = containerPtr->declWeaponPtr->getNameStr();
         logInfo("%s", declName.c_str());
         containerPtr++;
     }

     //logInfo("getResourceVecForClsName debug: input: %s  resListPtr is %p ", classname, resListPtr);



     return idResVec;

 }




 void idResourceListManager::addResourcePtr(__int64 ptr) {
    logDebug("addResourcePtr");
    if (std::find(m_idMaterial2Vec.begin(), m_idMaterial2Vec.end(), ptr) == m_idMaterial2Vec.end()) {
        // value not found, add it to the vector
        m_idMaterial2Vec.push_back(ptr);
        //LI("addResourcePtr: adding...");
    }
}

 void idResourceListManager::printIdMaterialsInfo() {
    logDebug("printIdMaterialsInfo");
    if (m_idMaterial2Vec.size() == 0) {
        logWarn("printIdMaterialsInfo: no data in m_idMaterial2Vec");
        return;
    }
    else {
        logInfo("printIdMaterialsInfo: m_idMaterial2Vec has data.");
    }

    for (size_t i = 0; i < m_idMaterial2Vec.size(); i++)
    {
        __int64 resourcePtr = m_idMaterial2Vec[i];
        if (!MemHelper::isBadReadPtr((void*)resourcePtr))
        {

            __int64 typeAddr = *(__int64*)(resourcePtr + 0x10);
            __int64 typeStr = *(__int64*)(typeAddr + 0x8);

            std::string typeString = (const char*)(typeStr);
            if (typeString == "idMaterial2") {
                __int64 materialNameStr = *(__int64*)(resourcePtr + 0x8);
                logInfo("printIdMaterialsInfo found idMaterial2: resourcePtr: %p name: %s", (void*)resourcePtr, (const char*)(materialNameStr));
            }

            //LI("printIdMaterialsInfo found type: %s", (const char*)(typeStr));
            //uintptr_t materialStrAddr = *(uintptr_t*)(resourcePtr + 0x8);
        }

    }
}

 const std::vector<__int64>& idResourceListManager::getIdResources() {
    logDebug("getIdResources");
    return m_idMaterial2Vec;
}
