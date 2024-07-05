#include "idPlayer.h"



std::string idPlayer_K::getDbgStrForImgui() {

    static uint64_t lastDebugLoopCheckMs = 0;
    std::string resultStr = "idPlayer: Debug:\n";

    __int64 IdMapInstanceLocalPtr = idMapInstanceLocalManager::getIdMapInstanceLocalPtr();
    resultStr += "\tIdMapInstanceLocalPtr: " + K_Utils::intToHexString(IdMapInstanceLocalPtr) + "\n";

    idPlayer* idPlayerPtr = idMapInstanceLocalManager::getIdPlayer();

    if (idPlayerPtr) {      

        resultStr += "\tidPlayerPtr: " + K_Utils::ptrToHexString(idPlayerPtr) + "\n";

        /*char* specCamAddr = (char*)idPlayerPtr + 0x4D2A0;
        std::string specCamAddrStr = "spec Cam idManagedClassPtr addr: " + K_Utils::ptrToHexString(specCamAddr);
        resultStr += "\t" + specCamAddrStr + "\n";*/

        std::string hideHudForCinematicStr = "hideHudForCinematic addr: " + K_Utils::ptrToHexString(&idPlayerPtr->hideHudForCinematic);
        resultStr += "\t" + hideHudForCinematicStr + "\n";

        std::string demonStateStr = "Is Demon: ";
        demonStateStr += K_Utils::getBoolAsStr(idPlayer_K::isPlayerDemon());       
        resultStr += "\t" + demonStateStr + "\n";

        std::string isSlayerInTheWorldFlagStr = "isSlayerInTheWorldFlag: ";
        isSlayerInTheWorldFlagStr += K_Utils::getBoolAsStr(idPlayer_K::isSlayerInTheWorldFlag());
        resultStr += "\t" + isSlayerInTheWorldFlagStr + "\n";

        std::string isSlayerActiveFlagStr = "isSlayerActiveFlagStr: ";
        isSlayerActiveFlagStr += K_Utils::getBoolAsStr(idPlayer_K::isSlayerActiveFlag());
        resultStr += "\t" + isSlayerActiveFlagStr + "\n";

        uint64_t lastReticleRefreshMs = K_Utils::EpochMillis() - PlayerStateChecker::getlastReticleRefreshMs();
        if (lastReticleRefreshMs < 100) {
            lastReticleRefreshMs = 0;
        }
        std::string LastDebugTimeStampMsStr =  "lastReticleRefreshMs (rounded to 0 below 100ms) :" + std::to_string(lastReticleRefreshMs);
        resultStr += "\t" + LastDebugTimeStampMsStr + "\n";


        //? check this doesnt seem right....
        std::string idHandsStr = "idHandsStr: XXXX";
        idHands_idHandsAction* pendingAction = (idHands_idHandsAction*)((__int64)idPlayerPtr + 0x15F98);
        idHandsStr = "idHands: pendingAction addr: " + K_Utils::ptrToHexString(pendingAction);
        resultStr += "\t" + idHandsStr + "\n";


        std::string InteractStr = "InteractStr: XXXX";
        idPlayer_playerUseState_t useState = (idPlayer_playerUseState_t) *(int*)((__int64)idPlayerPtr + 0x7D60);
        idManagedClassPtr_idSyncEntity* idSyncEnt_MC = (idManagedClassPtr_idSyncEntity*) ((__int64)idPlayerPtr + 0x8440);
        InteractStr = "useState: " + K_Utils::intToHexString(useState) + " idSyncEntity ptr: " + K_Utils::ptrToHexString(idSyncEnt_MC->idSyncEntity_ptr);

        resultStr += "\t" + InteractStr + "\n";
        


        //? playerBodyReactions is useless
        //!Offset 0x4F78
     /*   std::string playerBodyReactionsStr = "XXXX";
        __int64 playerBodyReactionsAddr = (__int64)((char*)idPlayerPtr + 0x4F78);*/


       /* std::string debugSTR = "playerBodyReactionsAddr: " + K_Utils::intToHexString(playerBodyReactionsAddr) + " &playerBodyReactionsAddr: " + K_Utils::ptrToHexString(&playerBodyReactionsAddr);*/

        //idPlayerBodyReactions* playerBodyReactions = (idPlayerBodyReactions*) &playerBodyReactionsAddr;
       /* idPlayerBodyReactions* playerBodyReactions = (idPlayerBodyReactions*) playerBodyReactionsAddr;
        playerBodyReactionsStr = " playerBodyReactions: is enabled: " + K_Utils::getBoolAsStr(playerBodyReactions->enable);
        if (playerBodyReactions->curReactionState) {
            int fpHandsCustomAnim = (int)playerBodyReactions->curReactionState->fpHandsCustomAnim;
            playerBodyReactionsStr += " fpHandsCustomAnim : " + K_Utils::intToHexString(fpHandsCustomAnim);
        }
        else {
            playerBodyReactionsStr += " curReactionState is null so no fpHandsCustomAnim";
        }*/

      


       /* playerBodyReactionsStr = "playerBodyReactions: &playerBodyReactions->curReactionState : " +
            K_Utils::ptrToHexString(&playerBodyReactions->curReactionState) + " &playerBodyReactions->curReactionState->fpHandsCustomAnim : " +
            K_Utils::ptrToHexString(&playerBodyReactions->curReactionState->fpHandsCustomAnim) + " &playerBodyReactions->enable: " + K_Utils::ptrToHexString (&playerBodyReactions->enable);*/
       /* int fpHandsCustomAnim = (int)playerBodyReactions->curReactionState->fpHandsCustomAnim;
        playerBodyReactionsStr = " playerBodyReactions: is enabled: " + K_Utils::getBoolAsStr(playerBodyReactions->enable) +  " fpHandsCustomAnim : " + K_Utils::intToHexString(fpHandsCustomAnim);*/
      /*  resultStr += "\t" + playerBodyReactionsStr + "\n";*/

    }
    else {
        resultStr += "\tidPlayerPtr in null ptr\n";
    }

    return resultStr;
}


 void idPlayer_K::resetLastBloodPunchCount() {
    logDebug("resetLastBloodPunchCount");
    m_lastBloodPunchCount = -1;
    m_lastDesperatePunchCount = -1;
}

//! bp and desperate punch

 bool idPlayer_K::isBloodPunchCountChanged() {
    logDebug("isBloodPunchCountChanged");

    int currentBloodPunchCount = getBloodPunchCountInt();
    if (currentBloodPunchCount != m_lastBloodPunchCount) {
        m_lastBloodPunchCount = currentBloodPunchCount;
        return true;
    }
    int currentDesperatePunchCount = isDesperatePunchAvailable();
    if (m_lastDesperatePunchCount != currentDesperatePunchCount) {
        m_lastDesperatePunchCount = currentDesperatePunchCount;
        return true;
    }
    return false;
}

 int idPlayer_K::getBloodPunchCountInt() {
    logDebug("getBloodPunchCountInt");
    float valFloat = getBloodPunchCountFloat();
    if (valFloat < 1.0f) return 0;
    if (valFloat < 2.0f) return 1;
    return 2;
}

 float idPlayer_K::getBloodPunchCountFloat() {
    logDebug("getBloodPunchCountFloat");


    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
        //logInfo("idPlayerPtr->BloodPunch: %.2f ", (float)idPlayerPtr->BloodPunch);
        return (idPlayerObj->dashboard.GKUpgrades.bloodPunchChargePercent);
    }
    return 0.0f;
}

 bool idPlayer_K::isDesperatePunchRuneEquipped() {
    idPlayer* idPlayer1 = idMapInstanceLocalManager::getIdPlayer();

    if (!idPlayer1) {
        logErr("isDesperatePunchRuneEquipped: failed to acquirre idPlayer returning false");
        return false;
    }
    fxCondition_t fxBloodPunchAOE = idPlayer1->dashboard.GKUpgrades.fxBloodPunchAOE;
    return fxBloodPunchAOE == fxCondition_t::FX_GLORY_SAVAGERY_AOE_LOW_HEALTH_START_END;
    //logInfo("isDesperatePunchRuneEquipped: debug: fxBloodPunchAOE val is %d", fxBloodPunchAOE);
}

 bool idPlayer_K::isDesperatePunchSoundActivated() {
    idPlayer* idPlayer1 = idMapInstanceLocalManager::getIdPlayer();

    if (!idPlayer1) {
        logErr("isDesperatePunchSoundActivated: failed to acquirre idPlayer returning false");
        return false;
    }
    bool isActivated = idPlayer1->dashboard.GKUpgrades.bloodPunchSuperChargedSoundActivated;
    return isActivated;
}

 bool idPlayer_K::isDesperatePunchAvailable() {

    return isDesperatePunchRuneEquipped() && isDesperatePunchSoundActivated();
}


 //! not needed cause low rad meter does not change color
 /*bool idPlayer_K::isRadMeterLowWarning() {
     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();    
     if (!idPlayerObj) {       
         return false;
     }   

     idHUD_HealthInfo* idHUD_HealthInfoPtr = (idHUD_HealthInfo*)idHudManager::getIdHud_Element(HudElementName::HealthInfo);    
     if (MemHelper::isBadReadPtr(idHUD_HealthInfoPtr)) {
         logErr("isRadMeterLowWarning: badPtr returning false");
         return false;
     }

     return idHUD_HealthInfoPtr->radShieldDesc.isLowHealthState;

 }*/

//! Imo this is better to use this method than using the hook simply because we cache the data we get from the hook so there is a possibility that this data is not accurate so i think this is better.
 weaponSlot_t idPlayer_K::getcurrentWeaponSlotIndex() {
  

    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    if (!idPlayerObj) {
        logErr("getcurrentWeaponSlotIndex: badPtr: idPlayerPtr returning weaponSlot_t::UNDEFINED");
        return weaponSlot_t::UNDEFINED;
    }
    //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("getcurrentWeaponSlotIndex: badPtr: idHud_WeaponInfo: %p returning weaponSlot_t::UNDEFINED", idHud_WeaponInfo);
        return weaponSlot_t::UNDEFINED;
    }
    if (MemHelper::isBadReadPtr(idHud_WeaponInfo->currentWeapon)) {
        logErr("getcurrentWeaponSlotIndex: badPtr:idHud_WeaponInfo->currentWeapon : %p returning weaponSlot_t::UNDEFINED", idHud_WeaponInfo->currentWeapon);
        return weaponSlot_t::UNDEFINED;
    }
    logInfo("getcurrentWeaponSlotIndex: returning : %d", idHud_WeaponInfo->currentWeapon->weaponSelectionGroup);
    return (weaponSlot_t)idHud_WeaponInfo->currentWeapon->weaponSelectionGroup;
}

 bool idPlayer_K::wantZoom() {
    logDebug("wantZoom");
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
        //logInfo("idPlayerPtr->BloodPunch: %.2f ", (float)idPlayerPtr->BloodPunch);
        return idPlayerObj->wantZoom == true;
    }
    return false;
}

 bool idPlayer_K::isInScope() {
    
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        return idPlayerObj->playerHud.inScope == true;
    }
    else {
        logErr("isInScope: can not get isInScope because idPlayer is bad ptr");
    }
    return false;
}

//? returning true by default so less rendering so less potential crash/issue...

 bool idPlayer_K::isHideReticle() {
    logDebug("isHideReticle");
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        return idPlayerObj->hideReticle;
    }
    /*else {
    logErr("isHideReticle: can not get hideReticle because idPlayer is bad ptr returning true;");
    }*/
    return true;
}


 /*bool idPlayer_K::isHudRenderCustomIceNadeFlag() {

     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     if (idPlayerObj) {

         if (idPlayerObj->hideHudForCinematic || idPlayerObj->playerHud.isPOIVisible) {
             return false;
         }

         hudElementFlags_t currentHudState = idPlayerObj->playerHud.currentHudMode;
         if (currentHudState & HUD_ELEMENT_MODE_DEAD) return false;
         if (currentHudState & HUD_ELEMENT_MODE_DEMON) return false;
         if (currentHudState & HUD_ELEMENT_MODE_IN_WORLD_MENU) return false;   

         return true;
     }   
     return false;
 }*/

 //? don't forget if you want to use this for custom hud, you will need other checks like is zoomed
 //! meaning, in game, not a demon, not in cutscene, not dead.
 bool idPlayer_K::isSlayerActiveFlag() {
     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     if (idPlayerObj) {

         if (idPlayerObj->hideHudForCinematic || idPlayerObj->playerHud.isPOIVisible) {
             return false;
         }

         hudElementFlags_t currentHudState = idPlayerObj->playerHud.currentHudMode;
         if (currentHudState & HUD_ELEMENT_MODE_DEAD) return false;
         if (currentHudState & HUD_ELEMENT_MODE_DEMON) return false;
         if (currentHudState & HUD_ELEMENT_MODE_IN_WORLD_MENU) return false;

         return true;
     }
     return false;
}


 bool idPlayer_K::isDemonActiveFlag() {
     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     if (idPlayerObj) {

         if (idPlayerObj->hideHudForCinematic || idPlayerObj->playerHud.isPOIVisible) {
             return false;
         }

         hudElementFlags_t currentHudState = idPlayerObj->playerHud.currentHudMode;
         if (currentHudState & HUD_ELEMENT_MODE_DEAD) return false;         
         if (currentHudState & HUD_ELEMENT_MODE_IN_WORLD_MENU) return false;

         if (currentHudState & HUD_ELEMENT_MODE_DEMON) return true;
     }
     return false;
 }


 bool idPlayer_K::isSlayerInTheWorldFlag() {
     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     if (idPlayerObj) {       

         hudElementFlags_t currentHudState = idPlayerObj->playerHud.currentHudMode;
         if (currentHudState & HUD_ELEMENT_MODE_DEAD) return false;
         if (currentHudState & HUD_ELEMENT_MODE_DEMON) return false;
         if (currentHudState & HUD_ELEMENT_MODE_IN_WORLD_MENU) return false;

         return true;
     }
     return false;
 }


 int idPlayer_K::getCurrentActiveReticleInt() {
    idHUD_Reticle* idHud_ReticleObj = (idHUD_Reticle*)idHudManager::getIdHud_Element(HudElementName::Reticle);
    if (MemHelper::isBadReadPtr(idHud_ReticleObj)) {
        logErr("getCurrentActiveReticleInt: badPtr: idHud_ReticleObj: %p returning -99", idHud_ReticleObj);
        return -99;
    }
    if (MemHelper::isBadReadPtr(&idHud_ReticleObj->activeReticleStyle)) {
        logErr("getCurrentActiveReticleInt: badPtr: &idHud_ReticleObj->activeReticleStyle : %p returning -99", &idHud_ReticleObj->activeReticleStyle);
        return -99;
    }
    return idHud_ReticleObj->activeReticleStyle;
}


 bool idPlayer_K::isPlayerDemon() {
     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     if (idPlayerObj) {     

         hudElementFlags_t currentHudState = idPlayerObj->playerHud.currentHudMode;       
         if (currentHudState & HUD_ELEMENT_MODE_DEMON) return true;      

     }
     return false;
 }


// bool idPlayer_K::isPlayerDemon() {
//    idHUD_LowWarning* idHud_LowWarning = (idHUD_LowWarning*)idHudManager::getIdHud_Element(HudElementName::LowWarning);
//
//    //? we need to know and log if this fails even we're going to change the way we find that data anyway...
//    if (MemHelper::isBadReadPtr(idHud_LowWarning)) {
//        //logErr("isPlayerDemon: badPtr:idHud_LowWarning %p", idHud_LowWarning);
//        return false;
//    }
//    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
//    if (MemHelper::isBadReadPtr(&idHud_LowWarning->isDemonPlayer)) {
//        //logErr("isPlayerDemon: badPtr:&idHud_LowWarning->isDemonPlayer: %p ", (void*)&idHud_LowWarning->isDemonPlayer);
//        return false;
//    }
//    return idHud_LowWarning->isDemonPlayer;
//}

 void idPlayer_K::resetLastIceGrenadeCount() {
    logDebug("resetLastIceGrenadeCount");
    m_lastIceGrenadeCount = -1;
}

 void idPlayer_K::resetLastFragGrenadeCount() {
    logDebug("resetLastFragGrenadeCount");
    m_lastFragGrenadeCount = -1;
}

 bool idPlayer_K::isIceNadeCountChanged() {
    logDebug("isIceNadeCountChanged");
    //logInfo("isIceNadeCountChanged called");
    int iceNadeCount = getIceNadeCount();
    if (iceNadeCount != m_lastIceGrenadeCount) {
        m_lastIceGrenadeCount = iceNadeCount;
        return true;
    }
    return false;
}

//! gepeto says: "equipmentInfo is a value (a struct inside another struct), not a pointer, so we don't need to check it. The array equipmentItems_ptr is also a statically allocated array inside the struct, so checking idPlayerObj is enough for them."

 int idPlayer_K::getIceNadeCount() {
    logDebug("getIceNadeCount");
    /* int result = getEquipmentCount(equipmentIndex_t::ICE);
    logInfo("getIceNadeCount(): %d", result);*/
    return getEquipmentCount(equipmentIndex_t::ICE);
}

 int idPlayer_K::getEquipmentCount(equipmentIndex_t equipmentIndex) {
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        // Check if m_equipmentIceIndex is in bounds
        const int ARRAY_SIZE = sizeof(idPlayerObj->equipmentInfo.equipmentItems_ptr) / sizeof(idPlayer_equipmentInfo_t_itemData_t);
        if ((int)equipmentIndex < 0 || (int)equipmentIndex >= ARRAY_SIZE) {
            logErr("getEquipmentCount: equipmentIndex is out of bounds returning 0");
            return 0;
        }
        //int count = idPlayerObj->equipmentInfo.equipmentItems_ptr[(int)equipmentIndex].equipmentUsesAvailable;
        //logInfo("debug: getEquipmentCount: count for equipmentIndex: equipmentIndex: %d is %d", (int)equipmentIndex, count);
        //return count;
        return idPlayerObj->equipmentInfo.equipmentItems_ptr[(int)equipmentIndex].equipmentUsesAvailable;
    }
    else {
        logErr("getEquipmentCount: can not get count because idPlayer is bad ptr returnin 0");
    }
    return 0;
}

 idPlayer_equipmentInfo_t_itemData_t idPlayer_K::getEquipmentTimers(equipmentIndex_t equipmentIndex) {
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        // Check if m_equipmentIceIndex is in bounds
        const int ARRAY_SIZE = sizeof(idPlayerObj->equipmentInfo.equipmentItems_ptr) / sizeof(idPlayer_equipmentInfo_t_itemData_t);
        if ((int)equipmentIndex < 0 || (int)equipmentIndex >= ARRAY_SIZE) {
            logErr("getEquipmentTimers: equipmentIndex is out of bounds returning empty data");
            return idPlayer_equipmentInfo_t_itemData_t();
        }
        return idPlayerObj->equipmentInfo.equipmentItems_ptr[(int)equipmentIndex];
    }
    else {
        logErr("getEquipmentTimers: can not get count because idPlayer is bad ptr returnin empty data");
    }
    return idPlayer_equipmentInfo_t_itemData_t();
}

 bool idPlayer_K::isFragNadeCountChanged() {
    logDebug("isFragNadeCountChanged");
    int fragNadeCount = getFragNadeCount();
    if (fragNadeCount != m_lastFragGrenadeCount) {
        m_lastFragGrenadeCount = fragNadeCount;
        return true;
    }
    return false;
}

 int idPlayer_K::getFragNadeCount() {
    logDebug("getFragNadeCount");

    /* int result = getEquipmentCount(equipmentIndex_t::FRAG);
    logInfo("getFragNadeCount(): %d", result);*/
    return getEquipmentCount(equipmentIndex_t::FRAG);
}

 int idPlayer_K::getFlameBelchCount() {
    logDebug("getFlameBelchCount");

    return getEquipmentCount(equipmentIndex_t::FLAME);
}

//! this seems to be a copy of flame so we can ignore it.

 int idPlayer_K::getUnknowEquipmentCount() {
    logDebug("getUnknowEquipmentCount");

    return getEquipmentCount(equipmentIndex_t::FLAME);
}


 //? i'm going to try to not use the 2 funcs below and see what happens....
// bool idPlayer_K::isHudSelectedGrenadeChanged() {
//    logDebug("isHudSelectedGrenadeChanged");
//    //GrenadeType hudSelectedNadeType = getHudSelectedGrenadeType();
//    GrenadeType hudSelectedNadeType = getHudSelectedGrenadeTypeV2();
//    if (hudSelectedNadeType != m_lastHudSelectedGrenadeType) {
//        m_lastHudSelectedGrenadeType = hudSelectedNadeType;
//        logInfo("isHudSelectedGrenadeChanged: hugSelectedNadeType: %d", (int)hudSelectedNadeType);
//        return true;
//    }
//    return false;
//}

//using decl item id to identify current nade type instead

// GrenadeType idPlayer_K::getHudSelectedGrenadeTypeV2() {
//    logDebug("getHudSelectedGrenadeTypeV2");
//
//    //? this is where i used to have this mind breaking crash cause we used the ipPlayer from OjectLocator that was out of date. keep this comment for posterity.
//    //logInfo("getHudSelectedGrenadeType called, this is what used to ");
//    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();                
//
//    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
//
//    //? we need to know and log if this fails even we're going to change the way we find that data anyway...
//    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
//        logErr("getHudSelectedGrenadeTypeV2: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
//        return GrenadeType::None;
//    }
//    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
//    if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentItem)) {
//        logErr("getHudSelectedGrenadeTypeV2: badPtr:idHud_WeaponInfo->equipmentItem: %p ", idHud_WeaponInfo->equipmentItem);
//        return GrenadeType::None;
//    }
//    if (MemHelper::isBadReadPtr((void*)&idHud_WeaponInfo->equipmentItem->displayName.id)) {
//        logErr("getHudSelectedGrenadeTypeV2: badPtr: &idHud_WeaponInfo->equipmentItem->displayName.id %p", &idHud_WeaponInfo->equipmentItem->displayName.id);
//        return GrenadeType::None;
//    }
//
//    displayName_Id itemId = (displayName_Id)idHud_WeaponInfo->equipmentItem->displayName.id;
//    //std::string iconName = idHud_WeaponInfo->equipmentWidget->dynamincIconName.data;
//
//    if (itemId == displayName_Id::FragGrenade) {
//        //logInfo("getHudSelectedGrenadeType: frag");
//        return GrenadeType::Frag;
//    }
//    else if (itemId == displayName_Id::IceBomb) {
//        //logInfo("getHudSelectedGrenadeType: ice");
//        return GrenadeType::Ice;
//    }    
//
//    return GrenadeType::None;
//}

 bool idPlayer_K::isFuelAmmoFull() {

    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("isFuelAmmoFull: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
        return false;
    }
    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->chainsawMaxAmmo)) {
        logErr("isFuelAmmoFull: badPtr:&idHud_WeaponInfo->chainsawMaxAmmo: %p ", (void*)&idHud_WeaponInfo->chainsawMaxAmmo);
        return false;
    }
    return idHud_WeaponInfo->chainsawMaxAmmo == idHud_WeaponInfo->chainsawAmmo;
}

 int idPlayer_K::getChainsawAmmo() {
    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("getChainsawAmmo: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
        return 0;
    }
    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->chainsawMaxAmmo)) {
        logErr("getChainsawAmmo: badPtr:&idHud_WeaponInfo->chainsawMaxAmmo: %p ", (void*)&idHud_WeaponInfo->chainsawMaxAmmo);
        return 0;
    }
    return idHud_WeaponInfo->chainsawAmmo;
}

 equipmentType_t idPlayer_K::getSelectedGrenadeType() {

    //! This method is not that accurate as sometimes what is on the hud differs from what we find at idPlayerPtr->EquippedGrenadeType and i suspect this is because of our mod. 
    //logInfo("getSelectedGrenadeType called");


    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();

    if (idPlayerObj) {
        //idPlayer_t* idPlayerPtr = *(idPlayer_t**)idPlayerAddr; //? this is from GH on reclass tut vid

        //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;

        ////? debug remove when done:
        //GrenadeType nadeType = (GrenadeType)idPlayerPtr->EquippedGrenadeType;
        //logInfo("getCurrentGrenadeType: nadeType: %d ", (int)nadeType);
        //! it looks like value in mem will be max int when slayer doesn't own any nade

        /*logErr("getSelectedGrenadeType can not figure out the data yet returning GrenadeType::None idPlayerObj->equipmentInfo.currentIndex is %d", idPlayerObj->equipmentInfo.currentIndex);
        return GrenadeType::None;*/

        
        if (idPlayerObj->equipmentInfo.currentIndex == INT_MAX) {
            return equipmentType_t::EQUIPMENT_NONE;
        }
        return (equipmentType_t)idPlayerObj->equipmentInfo.currentIndex;
    }
    else {
        logErr("getSelectedGrenadeType: can not get grenade type because idPlayer is bad ptr");
    }
    return equipmentType_t::EQUIPMENT_NONE;
}



 //? use our EquipmentManager::switchEquipment instead
// void idPlayer_K::setGrenadeType(GrenadeType grenadeType) {
//
//    try
//    {
//        idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
//
//        //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
//
//        if (idPlayerObj) {
//            //idPlayer_t* idPlayerPtr = *(idPlayer_t**)idPlayerAddr; //? this is from GH on reclass tut vid
//
//            //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
//            //logInfo("setGrenadeType: idPlayerPtr is %p ", idPlayerPtr);
//            idPlayerObj->equipmentInfo.currentIndex = (int)grenadeType;
//
//            /* logInfo("setGrenadeType: idPlayerPtr is %p idPlayerPtr->EquippedGrenadeType is: %d", idPlayerPtr,(int)idPlayerPtr->EquippedGrenadeType);*/
//        }
//        else {
//            logErr("setGrenadeType: can not change grenade type because idPlayer is bad ptr");
//        }
//    }
//    catch (const std::exception& ex)
//    {
//        logErr("setGrenadeType: ERROR: %s ", ex.what());
//    }
//}

 swfRect_t idPlayer_K::getEquipmentIconCoords(int fullpathHash) {
    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);

    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("getEquipmentIconCoords: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
        return swfRect_t();
    }
    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->equipmentWidget)) {
        logErr("getEquipmentIconCoords: badPtr: &idHud_WeaponInfo->equipmentWidget %p ", (void*)&idHud_WeaponInfo->equipmentWidget);
        return swfRect_t();
    }
    idSWFWidget* widget = (idSWFWidget*)idHud_WeaponInfo->equipmentWidget;
    idSWFSpriteInstance* spriteInstance = widget->boundSprite;
    if (!MemHelper::isBadReadPtr(spriteInstance)) {
        auto displayEntriesPtrVec = idSWFSpriteInstanceManager::getSpriteInstancesPtrVecFromDisplayEntry(spriteInstance);
        for (size_t i = 0; i < displayEntriesPtrVec.size(); i++)
        {
            auto displayEntrySpriteInstance = displayEntriesPtrVec[i];
            if (MemHelper::isBadReadPtr(displayEntrySpriteInstance)) {
                logWarn("getEquipmentIconCoords: found bad ptr for displayEntrySpriteInstance: %p continuing...", displayEntrySpriteInstance);
                continue;
            }
            if (displayEntrySpriteInstance->fullPathHash == fullpathHash) {
                std::string sname = std::string(displayEntrySpriteInstance->name.str);
                auto rect = displayEntrySpriteInstance->bounds;
                //logInfo("getEquipmentIconCoords: found entry with fullpathHash: 0x%X name: %s rect: %.2f %.2f %.2f %.2f ", fullpathHash, sname.c_str(), rect.tl.x, rect.tl.y, rect.br.x, rect.br.y);
                return displayEntrySpriteInstance->bounds;
            }
        }
    }
    else {
        logErr("getEquipmentIconCoords: spriteInstance is bad ptr: %p", spriteInstance);
    }
    return swfRect_t();

}

 void idPlayer_K::debugPrintFragNadeCoordsFromWeaponInfoV2() {
    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);

    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("debugPrintFragNadeCoordsFromWeaponInfoV2: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
        return;
    }
    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->equipmentWidget)) {
        logErr("debugPrintFragNadeCoordsFromWeaponInfoV2: badPtr: &idHud_WeaponInfo->equipmentWidget %p ", (void*)&idHud_WeaponInfo->equipmentWidget);
        return;
    }
    idSWFWidget* widget = (idSWFWidget*)idHud_WeaponInfo->equipmentWidget;
    idSWFSpriteInstance* spriteInstance = widget->boundSprite;
    if (!MemHelper::isBadReadPtr(spriteInstance)) {
        auto displayEntriesPtrVec = idSWFSpriteInstanceManager::getSpriteInstancesPtrVecFromDisplayEntry(spriteInstance);
        for (size_t i = 0; i < displayEntriesPtrVec.size(); i++)
        {
            auto displayEntrySpriteInstance = displayEntriesPtrVec[i];
            if (MemHelper::isBadReadPtr(displayEntrySpriteInstance)) {
                logWarn("debugPrintFragNadeCoordsFromWeaponInfoV2: found bad ptr for displayEntrySpriteInstance: %p continuing...", displayEntrySpriteInstance);
                continue;
            }
            std::string sname = std::string(displayEntrySpriteInstance->name.str);
            auto rect = displayEntrySpriteInstance->bounds;
            logInfo("debugPrintFragNadeCoordsFromWeaponInfoV2: found display entry sprite instance: %s with hash: 0x%X (%d) rect: %.2f %.2f %.2f %.2f (w: %.2f, h: %.2f)", sname.c_str(), displayEntrySpriteInstance->fullPathHash, displayEntrySpriteInstance->fullPathHash, rect.tl.x, rect.tl.y, rect.br.x, rect.br.y, rect.getWidth(), rect.getHeight());
        }
    }
    else {
        logErr("debugPrintFragNadeCoordsFromWeaponInfoV2: spriteInstance is bad ptr: %p", spriteInstance);
    }

}

 void idPlayer_K::debugPrintFragNadeCoordsFromWeaponInfo() {
    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);

    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("debugPrintFragNadeCoordsFromWeaponInfo: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
        return;
    }
    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->equipmentWidget)) {
        logErr("debugPrintFragNadeCoordsFromWeaponInfo: badPtr: &idHud_WeaponInfo->equipmentWidget %p ", (void*)&idHud_WeaponInfo->equipmentWidget);
        return;
    }
    idSWFWidget* widget = (idSWFWidget*)idHud_WeaponInfo->equipmentWidget;
    idSWFSpriteInstance* spriteInstance = widget->boundSprite;
    if (!MemHelper::isBadReadPtr(spriteInstance)) {
        if (spriteInstance->displayList.num > 0) {
            logInfo("debugPrintFragNadeCoordsFromWeaponInfo: spriteInstance at %p spriteInstance->displayList.num: %d ", spriteInstance, spriteInstance->displayList.num);
            for (size_t i = 0; i < spriteInstance->displayList.num; i++)
            {
                swfDisplayEntry_t* displayEntry = (swfDisplayEntry_t*)&spriteInstance->displayList.list[i];
                swfDisplayEntry_t* displayEntryAlt = (swfDisplayEntry_t*)spriteInstance->displayList.list[i];
                swfDisplayEntry_t* displayEntryAlt2 = (swfDisplayEntry_t*)spriteInstance->displayList.list;
                logInfo("debugPrintFragNadeCoordsFromWeaponInfo:  &displayEntry: %p and displayEntry: %p:", &displayEntry, displayEntry);
                logInfo("debugPrintFragNadeCoordsFromWeaponInfo:  &displayEntryAlt: %p and displayEntryAlt: %p:", &displayEntryAlt, displayEntryAlt);
                logInfo("debugPrintFragNadeCoordsFromWeaponInfo:  &displayEntryAlt2: %p and displayEntryAlt2: %p:", &displayEntryAlt2, displayEntryAlt2);
                if (!MemHelper::isBadReadPtr((void*)displayEntry)) {
                    idSWFSpriteInstance* spriteInstance = displayEntry->spriteInstance;
                    if (MemHelper::isBadReadPtr((void*)spriteInstance)) {
                        logErr("debugPrintFragNadeCoordsFromWeaponInfo: found bad ptr for: spriteInstance in display entry: spriteInstance: %p at addr: %p continuing...", spriteInstance, &displayEntry->spriteInstance);
                        continue;
                    }
                    std::string sname = std::string(spriteInstance->name.str);
                    auto rect = spriteInstance->bounds;
                    logInfo("debugPrintFragNadeCoordsFromWeaponInfo: found sprite instance: %s with hash: %0xX (%d) rect: %.2f %.2f %.2f %.2f ", sname.c_str(), spriteInstance->fullPathHash, spriteInstance->fullPathHash, rect.tl.x, rect.tl.y, rect.br.x, rect.br.y);
                }
                else {
                    logWarn("debugPrintFragNadeCoordsFromWeaponInfo: displayEntry is bad ptr: %p", displayEntry);
                }
            }
        }
        else {
            logWarn("debugPrintFragNadeCoordsFromWeaponInfo: displayEntry is empty");
        }

    }

    logInfo("debugPrintFragNadeCoordsFromWeaponInfo: widget: %s widgetState: %d", widget->spriteName.data, widget->widgetState);

}

 void idPlayer_K::debugEquipmentCount() {
    logInfo("debugEquipmentCount frag: %d", getFragNadeCount());
    logInfo("debugEquipmentCount ice: %d", getIceNadeCount());
    logInfo("debugEquipmentCount flame: %d", getFlameBelchCount());
    logInfo("debugEquipmentCount mysterious equipment: %d", getUnknowEquipmentCount());
}

 bool idPlayer_K::isAbilityIndicatorHudActive() {
    idHUD_AbilityIndicators* idHUD_AbilityIndicatorsObj = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);
    if (MemHelper::isBadReadPtr(idHUD_AbilityIndicatorsObj)) {
        logErr("debugAbilityIndicatorsHud: badPtr: idHUD_AbilityIndicatorsObj %p returning false", idHUD_AbilityIndicatorsObj);
        return false;
    }
    idUIElement* uiElement = (idUIElement*)idHUD_AbilityIndicatorsObj;
    return uiElement->isActive;
}

//? AbilityIndicators are actually the small icons close to the crosshair not the ones in the equipment hud bottom right

 void idPlayer_K::debugSpriteInstanceFromidHUD_AbilityIndicators() {
    idHUD_AbilityIndicators* idHUD_AbilityIndicatorsObj = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);

    if (MemHelper::isBadReadPtr(idHUD_AbilityIndicatorsObj)) {
        logWarn("debugSpriteInstanceFromidHUD_AbilityIndicators: idHUD_AbilityIndicatorsObj is badPtr:  %p", idHUD_AbilityIndicatorsObj);
        return;
    }
    //if (!MemHelper::isBadReadPtr((void*)idHUD_AbilityIndicatorsObj->grenadeWidget)) {
    if (!MemHelper::isBadReadPtr((void*)idHUD_AbilityIndicatorsObj->iceGrenadeHollowPipWidget)) {

        //idSWFWidget* fragWidget = idHUD_AbilityIndicatorsObj->grenadeWidget;
        idSWFWidget* widget = idHUD_AbilityIndicatorsObj->iceGrenadeHollowPipWidget;
        auto spriteInstance = widget->boundSprite;
        if (!MemHelper::isBadReadPtr(spriteInstance)) {
            auto rect = spriteInstance->bounds;
            std::string name = std::string(spriteInstance->name.str);
            logInfo("debugSpriteInstanceFromidHUD_AbilityIndicators: name: %s, hash %X (dec:%d ): rect: %.2f %.2f %.2f %.2f", name.c_str(), spriteInstance->fullPathHash, spriteInstance->fullPathHash, rect.tl.x, rect.tl.y, rect.br.x, rect.br.y);
        }
        else {
            logWarn("debugSpriteInstanceFromidHUD_AbilityIndicators: spriteInstance is badPtr:  %p", spriteInstance);
        }
    }
    else {
        logWarn("debugLogFragNadeSpriteInstanceFromidHUD_AbilityIndicators: idHUD_AbilityIndicatorsObj->iceGrenadeHollowPipWidget is badPtr:  %p", idHUD_AbilityIndicatorsObj->iceGrenadeHollowPipWidget);
    }
}

//? AbilityIndicators are actually the small icons close to the crosshair not the ones in the equipment hud bottom right

 void idPlayer_K::debugAbilityIndicatorsiceGrenadeWidget() {
    idHUD_AbilityIndicators* idHUD_AbilityIndicatorsObj = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);

    if (MemHelper::isBadReadPtr(idHUD_AbilityIndicatorsObj)) {
        logErr("debugAbilityIndicatorsiceGrenadeWidget: badPtr: idHUD_AbilityIndicatorsObj %p", idHUD_AbilityIndicatorsObj);
        return;
    }
    if (!MemHelper::isBadReadPtr((void*)idHUD_AbilityIndicatorsObj->iceGrenadeWidget)) {

        idSWFWidget* widget = idHUD_AbilityIndicatorsObj->iceGrenadeWidget;
        std::string wName = std::string(widget->spriteName.data);
        logInfo("debugAbilityIndicatorsiceGrenadeWidget: Widget: %s State: %d", wName.c_str(), widget->widgetState);
        idSWFSpriteInstanceManager::debugPrintSpriteInstanceDisplayList(widget->boundSprite);
    }
    else {
        logInfo("debugAbilityIndicatorsiceGrenadeWidget: Widget is bad Ptr:...");
    }

    logInfo("debugAbilityIndicatorsiceGrenadeWidget: updateFlags: %d elementState: %d icegrenadeHollowPipShowing: %d iceGrenadeShowing: %d inCampaign: %d fragEquipped: %d", idHUD_AbilityIndicatorsObj->updateFlags, (int)idHUD_AbilityIndicatorsObj->elementState, idHUD_AbilityIndicatorsObj->icegrenadeHollowPipShowing, idHUD_AbilityIndicatorsObj->iceGrenadeShowing, idHUD_AbilityIndicatorsObj->inCampaign, idHUD_AbilityIndicatorsObj->fragEquipped);
}

//? AbilityIndicators are actually the small icons close to the crosshair not the ones in the equipment hud bottom right

 void idPlayer_K::debugAbilityIndicatorsGrenadeWidget() {
    idHUD_AbilityIndicators* idHUD_AbilityIndicatorsObj = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);

    if (MemHelper::isBadReadPtr(idHUD_AbilityIndicatorsObj)) {
        logErr("debugAbilityIndicatorsGrenadeWidget: badPtr: idHUD_AbilityIndicatorsObj %p", idHUD_AbilityIndicatorsObj);
        return;
    }
    if (!MemHelper::isBadReadPtr((void*)idHUD_AbilityIndicatorsObj->grenadeWidget)) {

        idSWFWidget* widget = idHUD_AbilityIndicatorsObj->grenadeWidget;
        std::string wName = std::string(widget->spriteName.data);
        logInfo("debugAbilityIndicatorsGrenadeWidget: widget: %s State: %d", wName.c_str(), widget->widgetState);
        idSWFSpriteInstanceManager::debugPrintSpriteInstanceDisplayList(widget->boundSprite);
    }
    else {
        logInfo("debugAbilityIndicatorsGrenadeWidget: widget is bad Ptr:...");
    }

    logInfo("debugAbilityIndicatorsGrenadeWidget: updateFlags: %d elementState: %d icegrenadeHollowPipShowing: %d iceGrenadeShowing: %d inCampaign: %d fragEquipped: %d", idHUD_AbilityIndicatorsObj->updateFlags, (int)idHUD_AbilityIndicatorsObj->elementState, idHUD_AbilityIndicatorsObj->icegrenadeHollowPipShowing, idHUD_AbilityIndicatorsObj->iceGrenadeShowing, idHUD_AbilityIndicatorsObj->inCampaign, idHUD_AbilityIndicatorsObj->fragEquipped);
}

//? irrelevant

 void idPlayer_K::debug_hudFlagsBeforeDemon() {
    logDebug("debug_hudFlagsBeforeDemon");
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        //! this is always 0 from my logs.
        logInfo("debug_hudFlagsBeforeDemon: hudFlagsBeforeDemon: %d", idPlayerObj->hudFlagsBeforeDemon);
        //return idPlayerObj->hudFlagsBeforeDemon;
    }
    /* else {
    logErr("isInCinematic: can not get isInScope because idPlayer is bad ptr returning true;");
    }
    return true;*/
}


 idHUD* idPlayer_K::getPlayerHud() {
     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     if (idPlayerObj) {
         return (idHUD*) &idPlayerObj->playerHud;
        /* logInfo("debug_Id_Hud: broadcastSystemId: %d, pauseMenuIndex: %d, isPOIVisible: %d, readyForMapStart: %d, currentHudMode: %d, prevShowMenuVisibilityMask: %d", idPlayerObj->playerHud.broadcastSystemId, idPlayerObj->playerHud.pauseMenuIndex, idPlayerObj->playerHud.isPOIVisible, idPlayerObj->playerHud.readyForMapStart, idPlayerObj->playerHud.currentHudMode, idPlayerObj->playerHud.prevShowMenuVisibilityMask);*/
         //return idPlayerObj->playerHud.inScope == true;
     }
     return nullptr;
 }

//! only broadcastSystemId changes and i'm not even sure what's it's supposed to be, great.
 void idPlayer_K::debug_Id_Hud() {
    logDebug("debug_Id_Hud");
    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    if (idPlayerObj) {
        logInfo("debug_Id_Hud:  idPlayerObj->playerHud: %p broadcastSystemId: %d, pauseMenuIndex: %d, isPOIVisible: %d, readyForMapStart: %d, currentHudMode: %d, prevShowMenuVisibilityMask: %d", &idPlayerObj->playerHud, idPlayerObj->playerHud.broadcastSystemId, idPlayerObj->playerHud.pauseMenuIndex, idPlayerObj->playerHud.isPOIVisible, idPlayerObj->playerHud.readyForMapStart, idPlayerObj->playerHud.currentHudMode, idPlayerObj->playerHud.prevShowMenuVisibilityMask);
        //return idPlayerObj->playerHud.inScope == true;
    }
}



//? doesn't work to get state like if it's hidden cause in menu, cinamtic or else it's always 1. Keep this though

 void idPlayer_K::debugEquipmentWidgetState() {
    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);

    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
        logErr("debugEquipmentWidgetState: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
        return;
    }
    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->equipmentWidget)) {
        logErr("debugEquipmentWidgetState: badPtr: &idHud_WeaponInfo->equipmentWidget %p ", (void*)&idHud_WeaponInfo->equipmentWidget);
        return;
    }
    idSWFWidget* widget = (idSWFWidget*)idHud_WeaponInfo->equipmentWidget;
    logInfo("debugEquipmentWidgetState: widget: %s widgetState: %d", widget->spriteName.data, widget->widgetState);

}
