#pragma once

#include "CommonDE.h"
#include "MemHelper.h"
#include "../Config/Config.h"
#include "Types.h"
#include "idCmd.h"
#include <Logger.h>
#include "idHudManager.h"
#include "GeneratedClasses.h"
#include "idMapInstanceLocalManager.h"
#include "idSWFSpriteInstanceManager.h"
#include "PlayerStateChecker.h"

//#include "../VarName.h"
//#include <Logger.h>

enum class equipmentIndex_t {
    FRAG = 0,
    ICE = 1,
    FLAME = 2,
    UNKNOWN = 3
};


class idPlayer_K {

private:

    //! About to rewrite this class using only TypeInfo to figure out offset as this would effectively make the code much more robust to updates and less prone to crashes.
    
    //static const char* m_idPlayerClsName;

    //static classVariableInfo_t* m_idPlayer_dashboard_VarInfo;

    //static classVariableInfo_t* m_dashboard_GKUpgrades_VarInfo;

    //static classVariableInfo_t* m_idGK_UpgradeHandler_fxBloodPunchAOE_VarInfo;
    //static classVariableInfo_t* m_idGK_UpgradeHandler_bloodPunchSuperChargedSoundActivated_VarInfo;


    //! bool __fastcall idPlayer::UseEquipmentItem_A5F3D90(__int64 *idPlayer_a1, __int64 idDeclThrowable_a2, char a3, int a4)
    //typedef bool(__fastcall* idPlayer_UseEquipmentItem)(__int64* idPlayer_a1, __int64 idDeclThrowable_a2, char a3, int a4);
    //static idPlayer_UseEquipmentItem p_idPlayer_UseEquipmentItem;
    //static idPlayer_UseEquipmentItem p_idPlayer_UseEquipmentItem = reinterpret_cast<idPlayer_UseEquipmentItem>(getFuncAddr(0xA5F3D90));

    //static int m_lastDesperatePunchCount; //! can only have one but hacky way to set it to -1
    //static int  m_lastBloodPunchCount;
    //static int m_lastFragGrenadeCount;
    //static int  m_lastIceGrenadeCount;

    //static GrenadeType  m_lastHudSelectedGrenadeType;

    static inline const int m_equipmentFragIndex = 0;
    static inline const int m_equipmentIceIndex = 1;
    static inline const int m_equipmentFlameIndex = 2;

   static inline int m_lastDesperatePunchCount = -1;
   static inline int m_lastBloodPunchCount = -1;
   static inline int m_lastFragGrenadeCount = -1;
   static inline int m_lastIceGrenadeCount = -1;
   //static inline GrenadeType  m_lastHudSelectedGrenadeType = GrenadeType::None;


public:

    //? delete this when done
    //static inline  uint64_t LastSlayerReticleUpdateTimeStampMs = 0;

    static std::string getDbgStrForImgui();

    static void resetLastBloodPunchCount();

    //! bp and desperate punch
    static bool isBloodPunchCountChanged();

    static int getBloodPunchCountInt();

    static float getBloodPunchCountFloat();

    static bool isDesperatePunchRuneEquipped();


    static bool isDesperatePunchSoundActivated();

    static bool isDesperatePunchAvailable();


       

    //! Imo this is better to use this method than using the hook simply because we cache the data we get from the hook so there is a possibility that this data is not accurate so i think this is better.
    static weaponSlot_t getcurrentWeaponSlotIndex();


   

    static bool wantZoom();


    static bool isInScope();

    //? returning true by default so less rendering so less potential crash/issue...
    static bool isHideReticle();

    //static bool isHudRenderCustomIceNadeFlag();

    //? returning true by default so less rendering so less potential crash/issue...
    //static bool isInCinematicOrPOIVisible();

    static bool isSlayerActiveFlag();

    static bool isDemonActiveFlag();

    static bool isSlayerInTheWorldFlag();

    static int getCurrentActiveReticleInt();

    // doesn't work got get if weponInfo is showing or not during cinematics
   /* static bool isHudWeaponInfoFaded() {
        idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
      
        if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
            logErr("isHudWeaponInfoFaded: badPtr:idHud_WeaponInfo %p returning false", idHud_WeaponInfo);
            return false;
        }
        idHUDElement* idHUDElementObj = (idHUDElement*) idHud_WeaponInfo;
        if (MemHelper::isBadReadPtr(&idHUDElementObj->isFaded)) {
            logErr("isHudWeaponInfoFaded: badPtr: &idHUDElementObj->isFaded: %p  returning false", (void*)&idHUDElementObj->isFaded);
            return false;
           
        }
        return idHUDElementObj->isFaded;
    }*/



    

   static bool isPlayerDemon();
   

    static void resetLastIceGrenadeCount();

    static void resetLastFragGrenadeCount();

    static bool isIceNadeCountChanged();

    //! gepeto says: "equipmentInfo is a value (a struct inside another struct), not a pointer, so we don't need to check it. The array equipmentItems_ptr is also a statically allocated array inside the struct, so checking idPlayerObj is enough for them."
    static int getIceNadeCount();

    static int getEquipmentCount(equipmentIndex_t equipmentIndex);


    static idPlayer_equipmentInfo_t_itemData_t getEquipmentTimers(equipmentIndex_t equipmentIndex);

    static bool isFragNadeCountChanged();

    static int getFragNadeCount();

    static int getFlameBelchCount();

    //! this seems to be a copy of flame so we can ignore it.
    static int getUnknowEquipmentCount();





    //static bool isHudSelectedGrenadeChanged();

    //using decl item id to identify current nade type instead
    //static GrenadeType getHudSelectedGrenadeTypeV2();
    
    //static GrenadeType getHudSelectedGrenadeType() {
    //    logDebug("getHudSelectedGrenadeType");
    //    
    //   /* logWarn("getHudSelectedGrenadeType: FORCE RETURNING FOR CRASH ISOLATION DETECTION");
    //    return GrenadeType::None;*/

    //    //? this is where i used to have this mind breaking crash cause we used the ipPlayer from OjectLocator that was out of date. keep this comment for posterity.
    //    //logInfo("getHudSelectedGrenadeType called, this is what used to ");
    //    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();


    //    
    //    //__int64 idPlayerFromGameLocalDebug = idGameLocal::getIdPlayer_1_Addr();
    //    //idPlayer_t* idPlayerPtr = idMapInstanceLocalManager::getIdPlayerPtr();
    //  
    //   /* logInfo("idPlayerAddr from ObjectLocator: %p idPlayerFromGameLocalDebug: %p idPlayerVoidPtrFromEntityFinder: %p", (void*)idPlayerAddr, (void*)idPlayerFromGameLocalDebug, idPlayerVoidPtrFromEntityFinder);*/

    //   
    //    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);


    //    //? we need to know and log if this fails even we're going to change the way we find that data anyway...
    //    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
    //        logErr("getHudSelectedGrenadeType: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
    //        return GrenadeType::None;
    //    }
    //    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    //    if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidget)) {
    //        logErr("getHudSelectedGrenadeType: badPtr:idHud_WeaponInfo->equipmentWidget: %p ", idHud_WeaponInfo->equipmentWidget);
    //        return GrenadeType::None;
    //    }
    //    if (MemHelper::isBadReadPtr((void*)idHud_WeaponInfo->equipmentWidget->dynamincIconName.data)) {
    //        logErr("getHudSelectedGrenadeType: badPtr: idHud_WeaponInfo->equipmentWidget->dynamincIconName.data: %p", (void*)idHud_WeaponInfo->equipmentWidget->dynamincIconName.data);
    //        return GrenadeType::None;
    //    }
    //    

    //    std::string iconName = idHud_WeaponInfo->equipmentWidget->dynamincIconName.data;

    //    if (iconName == g_fragNadeIconNameStr) {
    //        //logInfo("getHudSelectedGrenadeType: frag");
    //        return GrenadeType::Frag;
    //    }
    //    else if (iconName == g_icebombIconNameStr) {
    //        //logInfo("getHudSelectedGrenadeType: ice");
    //        return GrenadeType::Ice;
    //    }

    //    //if (equipmentWidgetPtr->iconName) {
    //    //    //logInfo("getHudSelectedGrenadeType ref3");
    //    //    if (equipmentWidgetPtr->getIconNameStr() == g_fragNadeIconNameStr) {
    //    //        return GrenadeType::Frag;
    //    //    }
    //    //    else if (equipmentWidgetPtr->getIconNameStr() == g_icebombIconNameStr) {
    //    //        return GrenadeType::Ice;
    //    //    }
    //    //   
    //    //}
    //    else {
    //        logErr("getHudSelectedGrenadeType: iconName is: %s returning GrenadeType::None", iconName.c_str());
    //    }

    //   
    //    return GrenadeType::None;
    //}
    //

    static bool isFuelAmmoFull();

    static int getChainsawAmmo();

    //? keep this for documentation as this is may be the source of frequent level loading crash
    //static GrenadeType getHudSelectedGrenadeType() {
    //    //! this actually checks the name of the currently displayed nade icon so it's more accurate in that sens but i suppose also potentially slightly slower but i think the mod can handle it.
    //    logInfo("getHudSelectedGrenadeType called");
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();

    //    //! still checking for bad ptrs even though i'm not sure i need it of it it slows my code too much
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //       
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayerPtr->idHUD_WeaponInfoPtr &&
    //            idPlayerPtr->idHUD_WeaponInfoPtr->equipmentWidgetPtr &&
    //            idPlayerPtr->idHUD_WeaponInfoPtr->equipmentWidgetPtr->iconName) {
    //            if (strcmp(idPlayerPtr->idHUD_WeaponInfoPtr->equipmentWidgetPtr->iconName, g_fragNadeIconName) == 0) {
    //                return GrenadeType::Frag;
    //            }
    //            else if (strcmp(idPlayerPtr->idHUD_WeaponInfoPtr->equipmentWidgetPtr->iconName, g_icebombIconName) == 0) {
    //                return GrenadeType::Ice;
    //            }
    //        }
    //        else {
    //            logErr("getHudSelectedGrenadeType: bad ptr returning");
    //        }
    //    }
    //    else {
    //        logErr("getHudSelectedGrenadeType: can not get grenade type because idPlayerAddr is bad ptr");
    //    }
    //    return GrenadeType::None;
    //}
    //
    
    static equipmentType_t getSelectedGrenadeType();
   

    //static void setGrenadeType(GrenadeType grenadeType);


    static swfRect_t getEquipmentIconCoords(int fullpathHash);




    //! DEBUG:

    static void debugPrintFragNadeCoordsFromWeaponInfoV2();


    static void debugPrintFragNadeCoordsFromWeaponInfo();


    static void debugEquipmentCount();

   

    static bool isAbilityIndicatorHudActive();

    //? AbilityIndicators are actually the small icons close to the crosshair not the ones in the equipment hud bottom right
    static void debugSpriteInstanceFromidHUD_AbilityIndicators();


    //? AbilityIndicators are actually the small icons close to the crosshair not the ones in the equipment hud bottom right
    static void debugAbilityIndicatorsiceGrenadeWidget();

    //? AbilityIndicators are actually the small icons close to the crosshair not the ones in the equipment hud bottom right
    static void debugAbilityIndicatorsGrenadeWidget();

    //? irrelevant
    static void debug_hudFlagsBeforeDemon();

    static idHUD* getPlayerHud();

    //! only broadcastSystemId changes and i'm not even sure what's it's supposed to be, great.
    static void debug_Id_Hud();


    //? doesn't work to get state like if it's hidden cause in menu, cinamtic or else it's always 1. Keep this though
    static void debugEquipmentWidgetState();

    //? doesn't work always shows 0
    //static void debugEquipmentDeferredOp() {
    //    idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);

    //    if (MemHelper::isBadReadPtr(idHud_WeaponInfo)) {
    //        logErr("debugEquipmentDeferredOp: badPtr:idHud_WeaponInfo %p", idHud_WeaponInfo);
    //        return;
    //    }
    //    //if (MemHelper::isBadReadPtr(idHud_WeaponInfo->equipmentWidgetPtr)) {
    //    if (MemHelper::isBadReadPtr(&idHud_WeaponInfo->equipmentWidget)) {
    //        logErr("debugEquipmentDeferredOp: badPtr: &idHud_WeaponInfo->equipmentWidget %p ", (void*)&idHud_WeaponInfo->equipmentWidget);
    //        return;
    //    }
    //    idSWFWidget* widget = (idSWFWidget*)idHud_WeaponInfo->equipmentWidget;
    //    std::string nameStr = std::string(widget->spriteName.data);
    //    logInfo("debugEquipmentDeferredOp: widget: %s deferredOperations: %d", nameStr.c_str(), widget->deferredOperations);
    //}


    //! don't need this we already have this value at idPlayer + 0x6F48
    //static GrenadeType getUISelectedGrenadeType() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();

    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;

    //        /* logInfo("setGrenadeType: idPlayerPtr is %p idPlayerPtr->EquippedGrenadeType is: %d", idPlayerPtr,(int)idPlayerPtr->EquippedGrenadeType);*/
    //    }
    //    else {
    //        logErr("getUISelectedGrenadeType: can not getUISelectedGrenadeType because idPlayerAddr is bad ptr");
    //    }
    //}

    //static int32_t getInventoryCount() {
    //    logDebug("getInventoryCount");

    //    try
    //    {
    //        idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();

    //        //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();

    //        if (idPlayer) {
    //            //idPlayer_t* idPlayerPtr = *(idPlayer_t**)idPlayerAddr; //? this is from GH on reclass tut vid

    //            //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //            return idPlayer->InventoryItemsCount;
    //            //logInfo("setGrenadeType: idPlayerPtr is %p ", idPlayerPtr);
    //            //idPlayerPtr->EquippedGrenadeType = (int)grenadeType;

    //            /* logInfo("setGrenadeType: idPlayerPtr is %p idPlayerPtr->EquippedGrenadeType is: %d", idPlayerPtr,(int)idPlayerPtr->EquippedGrenadeType);*/
    //        }
    //        else {
    //            logErr("getInventoryCount: can not getInventoryCount cause idPlayer is bad ptr");
    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        logErr("getInventoryCount: ERROR: %s ", ex.what());            
    //    }
    //    return 0;
    //}



    //! if reticuleScaleUserOveride 
    //static void setReticleScaleTest(float reticuleScaleUserOverideFloat) {
    //    logDebug("setReticleScaleTest");

    //    //float val = 0.0f;
    //    /*if (reticuleScaleUserOverideFloat != 0.0f) {

    //    }*/

    //    try
    //    {
    //        idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();


    //        //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //        if (idPlayer) {
    //            logInfo("setReticleScaleTest idPlayerAddr %p", (void*)idPlayer);
    //            __int64* idHUD_ReticlePtr = (__int64*)(idPlayer + 0x47330);
    //            __int64 dereferencedidHUD_ReticlePtr = *(__int64*)idHUD_ReticlePtr;
    //            logInfo("setReticleScaleTest idHUD_ReticlePtr: %p dereferencedidHUD_ReticlePtr: %p", (void*)idHUD_ReticlePtr, (void*)(dereferencedidHUD_ReticlePtr));
    //            __int64* idDeclWeaponReticlePtr = (__int64*)((*idHUD_ReticlePtr) + 0xF8);
    //            logInfo("setReticleScaleTest idDeclWeaponReticlePtr %p", (void*)idDeclWeaponReticlePtr);
    //            float reticleScaleFloatPtr = *(float*)((*idDeclWeaponReticlePtr) + 0xF8);
    //            logInfo("setReticleScaleTest reticleScaleFloatPtr val is %.2f", reticleScaleFloatPtr);
    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        logErr("setReticleScaleTest: ERROR: %s ", ex.what());
    //    }
    //}








    /* static HudAmmoDataV2 debugGetFakeAmmoData() {
         __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
         if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
             idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
             uint64_t timeleft = idPlayerPtr->debugGetIceNadeCoolDownMicros();
             logInfo("debugPrintIceNadeCooldown: %llu:", timeleft);
         }
         else {
             logErr("debugPrintIceNadeCooldown: can not debugPrintIceNadeCooldown because idPlayerAddr is bad ptr");
         }
     }*/

     //? this doesn't work as idPlayer exists when player posses a deamon...
     /*static float isSlayer() {
         __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
         if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
             return true;
         }
         return false;
     }*/

     //! making sure hud is off if player is a demon:
     //static bool isSlayer() {
     //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
     //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
     //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
     //        //logInfo("idPlayerPtr->BloodPunch: %.2f ", (float)idPlayerPtr->BloodPunch);
     //        return (idPlayerPtr->actormodifierListIndex == -1);
     //    }
     //    return false;
     //}


    ////? need to add actual user defined colors from inifile
    //static void updateDotReticleColor() {
    //    if (isWeaponOnCoolDownFromDotReticleData()) {
    //        if (getDotReticleColor() != SWF_NAMED_COLOR_KEYCARD_RED) {
    //            setDotReticleColor(swfNamedColors_t::SWF_NAMED_COLOR_KEYCARD_RED);
    //        }
    //    }
    //    else {
    //        if (getDotReticleColor() != swfNamedColors_t::SWF_NAMED_COLOR_WHITE) {
    //            setDotReticleColor(swfNamedColors_t::SWF_NAMED_COLOR_WHITE);
    //        }
    //    }
    //}

    //static bool isWeaponOnCoolDownFromDotReticleData() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot) {
    //            idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;
    //            //! chargeCooldown will be 1.0 when the weapon is ready to be used and less than 1 when not.
    //            return reticleDataPtr->chargeCooldown != 1.0f;

    //            //! the cooldown will always be 0 whether the meathook is recharging or not
    //            //logInfo("debug_printWeaponCoolDownValOfDotReticle: chargeCooldown: %.2f  cooldown: %.2f", reticleDataPtr->chargeCooldown, reticleDataPtr->cooldown);

    //            /* logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idSWFWidget_Hud_ReticlePtr_Dot address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot);

    //             logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData);*/

    //        }

    //    }
    //    return true; //! returning true in case there is any issue that way the crosshair color goes back to defaut user color for dot crosshair.
    //}

    //static swfNamedColors_t getDotReticleColor() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite) {
    //            return (swfNamedColors_t)(idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId);
    //        }
    //    }
    //    logWarn("getDotReticleColor: could not find color returning SWF_NAMED_COLOR_INVALID");
    //}

    //static void setDotReticleColor(swfNamedColors_t swfNamedColor) {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite) {              
    //            logInfo("setDotReticleColor: setting color: %d", (int)swfNamedColor);             
    //            idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId = (int)swfNamedColor;
    //            idCmd::reapplySwfColorsCmd();
    //        }
    //    }
    //}

    //static void setDotReticleScaleV2(float reticuleScaleUserOverideFloat) {
    //    logDebug("setDotReticleScaleV2");


    //    idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();


    //    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (idPlayer) {
    //        //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayer->idHUD_ReticlePtr) {

    //            idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayer->idHUD_ReticlePtr->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;

    //            if (reticleDataPtr->currentReticle) {
    //                float currentDotReticleVal = reticleDataPtr->currentReticle->reticleModelScale;
    //                logInfo("setDotReticleScale: idDeclWeaponReticle: %s current dot reticle scale:  %.2f setting it to %.2f and &reticleModelScale is: %p", reticleDataPtr->currentReticle->name, currentDotReticleVal, reticuleScaleUserOverideFloat, &reticleDataPtr->currentReticle->reticleModelScale);
    //                reticleDataPtr->currentReticle->reticleModelScale = reticuleScaleUserOverideFloat;
    //            }


    //            //idPlayerPtr->idHUD_ReticlePtr->activeReticleDecl->reticleModelScale = reticuleScaleUserOverideFloat;

    //            /*idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;*/
    //            //! chargeCooldown will be 1.0 when the weapon is ready to be used and less than 1 when not.
    //            //return reticleDataPtr->chargeCooldown != 1.0f;


    //            //! the cooldown will always be 0 whether the meathook is recharging or not
    //            //logInfo("debug_printWeaponCoolDownValOfDotReticle: chargeCooldown: %.2f  cooldown: %.2f", reticleDataPtr->chargeCooldown, reticleDataPtr->cooldown);

    //            /* logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idSWFWidget_Hud_ReticlePtr_Dot address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot);

    //             logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData);*/

    //        }

    //    }
    //}


    //static void setDotReticleScale(float reticuleScaleUserOverideFloat) {
    //    logDebug("setDotReticleScale");


    //    idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();


    //    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (idPlayer) {
    //        //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayer->idHUD_ReticlePtr && idPlayer->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot ) {

    //            idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayer->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;

    //            if (reticleDataPtr->currentReticle) {
    //                float currentDotReticleVal = reticleDataPtr->currentReticle->reticleModelScale;
    //                logInfo("setDotReticleScale: idDeclWeaponReticle: %s current dot reticle scale:  %.2f setting it to %.2f", reticleDataPtr->currentReticle->name, currentDotReticleVal, reticuleScaleUserOverideFloat);
    //                reticleDataPtr->currentReticle->reticleModelScale = reticuleScaleUserOverideFloat;

    //            }
    //           
    //         
    //            //idPlayerPtr->idHUD_ReticlePtr->activeReticleDecl->reticleModelScale = reticuleScaleUserOverideFloat;

    //            /*idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;*/
    //            //! chargeCooldown will be 1.0 when the weapon is ready to be used and less than 1 when not.
    //            //return reticleDataPtr->chargeCooldown != 1.0f;


    //            //! the cooldown will always be 0 whether the meathook is recharging or not
    //            //logInfo("debug_printWeaponCoolDownValOfDotReticle: chargeCooldown: %.2f  cooldown: %.2f", reticleDataPtr->chargeCooldown, reticleDataPtr->cooldown);

    //            /* logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idSWFWidget_Hud_ReticlePtr_Dot address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot);

    //             logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData);*/

    //        }

    //    }
    //}


    

    //static void debugLogCurrentIdDeclWeaponName() {
  //    logDebug("debugLogCurrentIdDeclWeaponName");

  //  /*  const unsigned int idDeclWeaponOveride1Offset = 0x3330;
  //    const unsigned int idDeclWeaponOveride2Offset = 0x3708;*/

  //    __int64 idWeaponAdd = ObjectLocator::getCurrentIdWeaponAddr();
  //    idWeapon* idWeaponObj = (idWeapon*)idWeaponAdd;
  //    idWeaponObj->print();

  //   /* const char* weaponBaseName = idWeaponAddr
  //    logInfo("idWeaponAddr + m_idDeclWeaponPtrOffset is %p weapon base name: %s", (void*)(idWeaponAddr), );
  //    if (MemHelper::isBadReadPtr((void*)(idWeaponAddr + idDeclWeaponOveride1Offset))) {

  //    }


  //    __int64 declWeaponAddr = *(__int64*)(idWeaponAddr + m_idDeclWeaponPtrOffset);
  //    if (declWeaponAddr != debugLastDeclWeaponAddr) {
  //        debugLastDeclWeaponAddr = declWeaponAddr;
  //        logInfo("declWeaponAddr has changed to: %p", (void*)(declWeaponAddr));
  //    }*/
  //}


    //! this actually works, the only issus is that it doesn't trigger the "empty" sound when equipment is recharging.
    //static void testThrowNade(int type) {
    //    __int64 idPlayerPtr = ObjectLocator::getIdPlayerAdrr();
    //    //__int64 nadeType = 1;

    //    if (!MemHelper::isBadReadPtr((void*)idPlayerPtr)) {
    //        __int64 throwableDecl = *(uint64_t*)(*(uint64_t*)(*(uint64_t*)(idPlayerPtr + 0x2F510) + 0x840i64) + 0x10 * (__int64)type);
    //        if (!MemHelper::isBadReadPtr((void*)throwableDecl)) {
    //            p_idPlayer_UseEquipmentItem((__int64*)idPlayerPtr, throwableDecl, 0, 0);
    //        }
    //        else {
    //            logErr("testThrowNade: badptr throwableDecl :  %p", (void*)throwableDecl);
    //        }
    //    }
    //    else {
    //        logErr("testThrowNade: badptr idPlayerPtr:  %p", (void*)idPlayerPtr);
    //    }
    //}    

       //! (weapon info: actual weap info and equipment) meaning is weapon info displayed or not (if in cutscence for ex)
    //static bool isWeaponInfoFadedOut() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;  
    //       /* logInfo("idPlayerPtr->idHUD_WeaponInfoPtr is: %p ", (void*)((__int64)idPlayerPtr->idHUD_WeaponInfoPtr));
    //        BYTE result = *(BYTE*)((__int64)idPlayerPtr->idHUD_WeaponInfoPtr + 0xF4);
    //        logInfo("result is: %d ", result);*/
    //        return *(BYTE*)((__int64)idPlayerPtr->idHUD_WeaponInfoPtr + 0xF4) == 1;
    //    }
    //    return 0.0f;
    //}


    //static bool isMeatHookOnCoolDown() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        //__int64 idHUD_ReticleAddr = (__int64)idPlayerPtr->idHUD_ReticlePtr;
    //        float val = *(float*)((__int64)idPlayerPtr->idHUD_ReticlePtr + 0x134);
    //        if (std::abs(val - 1.0F) < 0.0001) {
    //            return false;
    //        }
    //        else {
    //            return true;
    //        }
    //       /* logInfo("isMeatHookOnCoolDown: val: %d ", val);
    //        return val < 1.0f;*/
    //    }
    //    return false;
    //}

    //static bool isMeatHookOnCoolDown() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        //__int64 idHUD_ReticleAddr = (__int64)idPlayerPtr->idHUD_ReticlePtr;
    //        int val = *(int*)((__int64)idPlayerPtr->idHUD_ReticlePtr + 0x12C);
    //        logInfo("isMeatHookOnCoolDown: val: %d ", val);
    //        return *(int*)((__int64)idPlayerPtr->idHUD_ReticlePtr + 0x12C) == 0;
    //    }
    //    return false;
    //}

    //! using the flags the game use to disable the dot crosshair to disable our custom one like in the cutscenes
    //static bool isGameDotCrosshairHidden() {
    //    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
    //        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //       //__int64 idHUD_ReticleAddr = (__int64)idPlayerPtr->idHUD_ReticlePtr;
    //       //! *(int*)(idHUD_ReticleAddr + 0x330) <= this will be -1 when in menu btw.;
    //       //logInfo("idHUD_ReticleAddr is: %p ", (void*)(idHUD_ReticleAddr));
    //       //logInfo("idPlayerPtr->idHUD_ReticlePtr is: %p ", (void*)(idPlayerPtr->idHUD_ReticlePtr));
    //       //bool result = *(int*)((__int64)idPlayerPtr->idHUD_ReticlePtr + 0x330);
    //       //bool result = *(int*)(idHUD_ReticleAddr + 0x330);
    //       //return result == 0;
    //       return *(int*)((__int64)idPlayerPtr->idHUD_ReticlePtr + 0x330) == 0;
    //    }
    //    return false;
    //}

   /* static void debugPrintIceNadeCooldown() {
        __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
        if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
            idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
            uint64_t timeleft = idPlayerPtr->debugGetIceNadeCoolDownMicros();
            logInfo("debugPrintIceNadeCooldown: %llu:", timeleft);
        }
        else {
            logErr("debugPrintIceNadeCooldown: can not debugPrintIceNadeCooldown because idPlayerAddr is bad ptr");
        }
    }*/


    /* static uint64_t getIceNadeCoolDownSec() {
         __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
         if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
             idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
             return idPlayerPtr->getIceNadeCoolDownSec();
         }
         else {
             logErr("getIceNadeCoolDownSec: can not get CoolDown because idPlayerAddr is bad ptr");
         }
         return 0;
     }*/

     /* static uint64_t getIceNadeCoolDownEndMicros() {
          __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
          if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
              idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
              return idPlayerPtr->IceNadeCooldownEndMrs;
          }
          else {
              logErr("getIceNadeCoolDownEndMicros: can not get CoolDown because idPlayerAddr is bad ptr returning 0");
          }
          return 0;
      }*/

};
//idPlayer::idPlayer_UseEquipmentItem idPlayer::p_idPlayer_UseEquipmentItem = reinterpret_cast<idPlayer_UseEquipmentItem>(MemHelper::getFuncAddr(0xA5F3D90));
//const char* idPlayer_K::m_idPlayerClsName = "idPlayer";

//classVariableInfo_t* idPlayer_K::m_idHud_VarInfo = nullptr;



//classVariableInfo_t* idPlayer_K::m_idPlayer_dashboard_VarInfo = nullptr;

//classVariableInfo_t* idPlayer_K::m_dashboard_GKUpgrades_VarInfo = nullptr;

//classVariableInfo_t* idPlayer_K::m_idGK_UpgradeHandler_fxBloodPunchAOE_VarInfo = nullptr;
//classVariableInfo_t* idPlayer_K::m_idGK_UpgradeHandler_bloodPunchSuperChargedSoundActivated_VarInfo = nullptr;