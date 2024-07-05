#include "idHudManager.h"



bool isHudFlag(hudElementFlags_t flag) {
    idHUD* playerHud = idPlayer_K::getPlayerHud();
    if (playerHud) {
        return (playerHud->currentHudMode & HUD_ELEMENT_MODE_NONE);
    }
    return false;
}

bool idHudManager::acquireIsWorldMenuAtIndexActiveFuncAddr(__int64 faddr)
{
    if (MemHelper::isBadReadPtr((void*)faddr)) {
        logErr("acquireIsWorldMenuAtIndexActiveFuncAddr: bad ptr: %p", (void*)faddr);
        m_isWorldMenuAtIndexActiveFp = nullptr;
        return false;
    }
    m_isWorldMenuAtIndexActiveFp = (isWorldMenuAtIndexActive_t)faddr;
    logInfo("acquireIsWorldMenuAtIndexActiveFuncAddr: m_isWorldMenuAtIndexActiveFp set to: %p", m_isWorldMenuAtIndexActiveFp);
    return true;
}


//std::vector<idHUDElement*>idHudManager::getIdHudPtrsVec(std::vector<std::string> idHudNamesStrVec) {
//
//    std::vector<idHUDElement*> resultVec;
//
//    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
//    idList* IdHud_Elements_ListPtr = (idList*)&idPlayerObj->playerHud.idGrowableList_idHUDElement_elements;
//
//    if (!IdHud_Elements_ListPtr || MemHelper::isBadReadPtr(IdHud_Elements_ListPtr)) {
//        logErr("getIdHudPtrsVec: IdHud_Elements_ListPtr is null or badPtr");
//        return resultVec;
//    }
//
//    __int64* IdHud_ElementPtr = (__int64*)IdHud_Elements_ListPtr->list;
//    for (size_t i = 0; i < IdHud_Elements_ListPtr->num; i++)
//    {
//        if (MemHelper::isBadReadPtr(IdHud_ElementPtr)) continue;
//        idHUDElement* IdHud_Element = (idHUDElement*)*(__int64*)IdHud_ElementPtr;
//        if (MemHelper::isBadReadPtr(IdHud_Element)) continue;
//
//        idDeclHUDElement* declElement = IdHud_Element->decl;
//
//
//        std::string idHud_ElementNameStr = idResourceManager::getDeclHudElementName(declElement);
//
//
//        if (idHud_ElementNameStr == requestedHudElementName) {
//
//            return resultVec;
//        }
//        IdHud_ElementPtr++;
//    }
//    logErr("getIdHud_Element failed to find requestedHudElementName: %s in idGrowable list", requestedHudElementName.c_str());
//    return nullptr;
//}


idHUDElement* idHudManager::getIdHud_Element(std::string requestedHudElementName) {

    idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
    idList* IdHud_Elements_ListPtr = (idList*)&idPlayerObj->playerHud.idGrowableList_idHUDElement_elements;
    //idList* IdHud_Elements_ListPtr = (idList*)&idPlayerObj->playerHud.idGrowableList_elements;

    if (!IdHud_Elements_ListPtr || MemHelper::isBadReadPtr(IdHud_Elements_ListPtr)) {
        logErr("getIdHud_Element: IdHud_Elements_ListPtr is null or badPtr");
        return nullptr;
    }
    __int64* IdHud_ElementPtr = (__int64*)IdHud_Elements_ListPtr->list;
    for (size_t i = 0; i < IdHud_Elements_ListPtr->num; i++)
    {
        if (MemHelper::isBadReadPtr(IdHud_ElementPtr)) continue;
        idHUDElement* IdHud_Element = (idHUDElement*)*(__int64*)IdHud_ElementPtr;
        //char* IdHud_Element = (char*)*(__int64*)IdHud_ElementPtr;
        if (MemHelper::isBadReadPtr(IdHud_Element)) continue;

        idDeclHUDElement* declElement = IdHud_Element->decl;


        std::string idHud_ElementNameStr = idResourceManager::getDeclHudElementName(declElement);


        if (idHud_ElementNameStr == requestedHudElementName) {

            return IdHud_Element;
        }
        IdHud_ElementPtr++;
    }
    logErr("getIdHud_Element failed to find requestedHudElementName: %s in idGrowable list", requestedHudElementName.c_str());
    return nullptr;
}


bool idHudManager::isWorldMenuActive(hudMenuID_t hudMenuID) {
    if (m_isWorldMenuAtIndexActiveFp) {
        idHUD* playerHudPtr = idPlayer_K::getPlayerHud();
        if (playerHudPtr) {
            return m_isWorldMenuAtIndexActiveFp(playerHudPtr, hudMenuID);
        }
    }
    else {
        logErr("isWorldMenuActive: m_isWorldMenuAtIndexActiveFp is nullptr");
    }
    return false;
}


 std::string idHudManager::getDdgStrForImgui() {

     std::string resultStr = "idHudManager: Debug:\n";
    

     idHUD* playerHud = idPlayer_K::getPlayerHud();
     if (playerHud) {

         hudElementFlags_t currentHudState = (hudElementFlags_t)playerHud->currentHudMode;

         std::string hudStateStr = idHudManager::getHudStateString(currentHudState);
         std::string currentHudStateStr = "playerHud: " + K_Utils::ptrToHexString(playerHud) + " Current Hud Mode: " + hudStateStr + " hudMode int: " + std::to_string(playerHud->currentHudMode) + " gameWasPaused: " + std::to_string(playerHud->gameWasPaused);
         resultStr += "\t" + currentHudStateStr + "\n";

         //! there are many pause menus but here we are interested in this specific one:
         std::string HudMenuIDStr = "is HUD_MENU_PAUSE active: " + std::to_string(isWorldMenuActive(HUD_MENU_PAUSE));
         resultStr += "\t" + HudMenuIDStr + "\n";

         idHUD_WeaponInfo* idHud_WeaponInfoPtr = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
         std::string WeaponInfoStr = "";

         if (idHud_WeaponInfoPtr) {
             WeaponInfoStr = "idHud_WeaponInfoPtr data:";
             idUIElement* idUIElement_WeaponInfoPtr = (idUIElement*)idHud_WeaponInfoPtr;
             WeaponInfoStr += " is active: " + std::to_string(idUIElement_WeaponInfoPtr->isActive);

             idHUDElement* idHUDElement_WeaponInfoPtr = (idHUDElement*)idHud_WeaponInfoPtr;
             WeaponInfoStr += " is faded: " + std::to_string(idHUDElement_WeaponInfoPtr->isFaded);

         }
         else {
             WeaponInfoStr = "idHud_WeaponInfoPtr is null ptr";
         }      
         resultStr += "\t" + WeaponInfoStr + "\n";

         std::string declWeaponInfoStr = "declWeapon Info: ";
         idHUD_Reticle* idHUD_ReticlePtr = (idHUD_Reticle*)idHudManager::getIdHud_Element(HudElementName::Reticle);
         if (idHUD_ReticlePtr) {            
             idDeclWeapon* currentWeapDecl = idHUD_ReticlePtr->currentReticleData.currentWeaponDecl;
             if (currentWeapDecl) {
                 std::string declName = currentWeapDecl->getNameStr();
                 declWeaponInfoStr = " currentWeapDecl name: "  + declName;
             }
         }
         else {
             declWeaponInfoStr = "idHUD_ReticlePtr is nullp ptr";
         }
         resultStr += "\t" + declWeaponInfoStr + "\n";


        /* idUIElement* idUIElement_SkipCinematicPtr = (idUIElement*)idHudManager::getIdHud_Element(HudElementName::SkipCinematic);
         std::string idUIElement_SkipCinematicStatusStr = "idUIElement_SkipCinematic is null ptr";
         if (idUIElement_SkipCinematicPtr) {
             idUIElement_SkipCinematicStatusStr = "idUIElement_SkipCinematic is active: " + std::to_string(idUIElement_SkipCinematicPtr->isActive);
         }
         resultStr += "\t" + idUIElement_SkipCinematicStatusStr + "\n";   */



         idUIElement* idUIElement_ReticlePtr = (idUIElement*)idHudManager::getIdHud_Element(HudElementName::Reticle);
         std::string idHUD_ReticleStr = "idUIElement_ReticlePtr is null ptr";
         if (idUIElement_ReticlePtr) {
             idHUD_ReticleStr = "idUIElement_ReticlePtr: is active: " + std::to_string(idUIElement_ReticlePtr->isActive);
         }
         resultStr += "\t" + idHUD_ReticleStr + "\n";


        /* idHUD_Reticle* idHUD_ReticlePtr = (idHUD_Reticle*)idHudManager::getIdHud_Element(HudElementName::Reticle);
         std::string idHUD_ReticleStr = "idHUD_ReticlePtr is null ptr";
         if (idHUD_ReticlePtr) {
             if (idHUD_ReticlePtr->currentReticleData.currentWeaponDecl) {
                 idHUD_ReticleStr = "idHUD_ReticlePtr: currentWeaponDecl exists: " + K_Utils::ptrToHexString(idHUD_ReticlePtr->currentReticleData.currentWeaponDecl);
             }
             else {
                 idHUD_ReticleStr = "**** idHUD_ReticlePtr: currentWeaponDecl is NULL *****";
             }             
         }*/


         idHUD_playerInhibitInfo_t* savedInhibit = &playerHud->savedInhibit;
         std::string savedInhibitStr = "Inhibit data: inhibitFlags: "  +  K_Utils::intToHexString(savedInhibit->inhibitFlags) + " disableMovementDuringCustomAnim: " + std::to_string(savedInhibit->disableMovementDuringCustomAnim);
         resultStr += "\t" + savedInhibitStr + "\n";
        

        std::string isPOIVisibleStr = "isPOIVisible:  " + std::to_string(playerHud->isPOIVisible);
        resultStr += "\t" + isPOIVisibleStr + "\n";


         std::string isInScopeStr = "isInScope: " + std::to_string(playerHud->inScope);
         resultStr += "\t" + isInScopeStr + "\n";
     }
     else {
         resultStr += "\tCan't get data cause playerHud and/or player is nullptr\n";         
     }

     return resultStr;
 }


 std::string idHudManager::getHudStateString(hudElementFlags_t state) {
     std::stringstream ss;

     if (state & HUD_ELEMENT_MODE_NONE) ss << "NONE ";
     if (state & HUD_ELEMENT_MODE_INPUT_ONLY) ss << "INPUT_ONLY ";
     if (state & HUD_ELEMENT_MODE_COMBAT) ss << "COMBAT ";
     if (state & HUD_ELEMENT_MODE_NON_COMBAT) ss << "NON_COMBAT ";
     if (state & HUD_ELEMENT_MODE_CINEMATIC) ss << "CINEMATIC ";
     if (state & HUD_ELEMENT_MODE_DEMON) ss << "DEMON ";
     if (state & HUD_ELEMENT_MODE_RADAR) ss << "RADAR ";
     if (state & HUD_ELEMENT_MODE_DIAGNOSTICS) ss << "DIAGNOSTICS ";
     if (state & HUD_ELEMENT_MODE_INVASION) ss << "INVASION ";
     if (state & HUD_ELEMENT_MODE_PVP) ss << "PVP ";
     if (state & HUD_ELEMENT_MODE_EXTRA_LIFE) ss << "EXTRA_LIFE ";
     if (state & HUD_ELEMENT_MODE_PVP_SPECTATOR) ss << "PVP_SPECTATOR ";
     if (state & HUD_ELEMENT_MODE_PVP_ROUND_TRANSITION) ss << "PVP_ROUND_TRANSITION ";
     if (state & HUD_ELEMENT_MODE_TARGETSTRIKE) ss << "TARGETSTRIKE ";
     if (state & HUD_ELEMENT_MODE_DEAD) ss << "DEAD ";
     if (state & HUD_ELEMENT_MODE_TUTORIAL) ss << "TUTORIAL ";
     if (state & HUD_ELEMENT_MODE_PVP_END_OF_MATCH) ss << "PVP_END_OF_MATCH ";
     if (state & HUD_ELEMENT_MODE_BACKDROP) ss << "BACKDROP ";
     if (state & HUD_ELEMENT_MODE_IN_WORLD_MENU) ss << "IN_WORLD_MENU ";
     if (state & HUD_ELEMENT_MODE_MASTER_LEVEL) ss << "MASTER_LEVEL ";
     if (state & HUD_ELEMENT_MODE_DISABLE_PAUSE) ss << "DISABLE_PAUSE ";
     if (state & HUD_ELEMENT_MODE_PVP_DEAD) ss << "PVP_DEAD ";
     if (state & HUD_ELEMENT_MODE_TUTORIAL_POPUP) ss << "TUTORIAL_POPUP ";
     if (state & HUD_ELEMENT_MODE_SLAYER_VERSUS) ss << "SLAYER_VERSUS ";
     if (state & HUD_ELEMENT_MODE_HORDE) ss << "HORDE ";
     if (state & HUD_ELEMENT_MODE_TEXT_CHAT) ss << "TEXT_CHAT ";
     //if (state & HUD_ELEMENT_MODE_ANY) ss << "HUD_ELEMENT_MODE_ANY ";

     return ss.str();
 }



 void idHudManager::debugPrintAllHud_ElementsAddr() {
     logDebug("debugPrintAllHud_ElementsAddr");

     idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
     idList* IdHud_Elements_ListPtr = (idList*)&idPlayerObj->playerHud.idGrowableList_idHUDElement_elements;
     //idList* IdHud_Elements_ListPtr = (idList*)&idPlayerObj->playerHud.idGrowableList_elements;

     if (!IdHud_Elements_ListPtr || MemHelper::isBadReadPtr(IdHud_Elements_ListPtr)) {
         logErr("debugPrintAllHud_ElementsAddr: IdHud_Elements_ListPtr is null or badPtr");
         return;
     }
     __int64* IdHud_ElementPtr = (__int64*)IdHud_Elements_ListPtr->list;
     for (size_t i = 0; i < IdHud_Elements_ListPtr->num; i++)
     {
         if (MemHelper::isBadReadPtr(IdHud_ElementPtr)) continue;
         idHUDElement* IdHud_Element = (idHUDElement*)*(__int64*)IdHud_ElementPtr;
         //char* IdHud_Element = (char*)*(__int64*)IdHud_ElementPtr;
         if (MemHelper::isBadReadPtr(IdHud_Element)) continue;

         idDeclHUDElement* declElement = IdHud_Element->decl;

         std::string idHud_ElementNameStr = idResourceManager::getDeclHudElementName(declElement);
         //std::string idHud_ElementNameStr = idHUDElementManager::getDeclName(IdHud_Element);

         logInfo("debugPrintAllHud_ElementsAddr: found  IdHud_Element: %s at addr: %p  ", idHud_ElementNameStr.c_str(), IdHud_Element);

         //if (idHud_ElementNameStr == requestedHudElementName) {
         //    //logInfo("getIdHud_Element: found requestedHudElementName: %s returning IdHud_Element: %p", requestedHudElementName.c_str(), IdHud_Element);
         //    return IdHud_Element;
         //}
         IdHud_ElementPtr++;
     }
     logInfo("debugPrintAllHud_ElementsAddr: done listing IdHud Elements");
 }


 void idHudManager::debugLogUniqueDeclName(std::string declName, __int64 hudElementAddr) {
     if (m_debugTempUniqueDeclNames.find(declName) == m_debugTempUniqueDeclNames.end()) {
         // If not, add it to the set and proceed
         m_debugTempUniqueDeclNames.insert(declName);
         logInfo("debugacquirreDeclName: found decl name: %s hudAddr: %p", declName.c_str(), (void*)hudElementAddr);
     }

}
