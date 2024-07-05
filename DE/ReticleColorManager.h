#pragma once

#include <string>
#include <vector>
#include "CommonDE.h"
#include "MemHelper.h"
#include "idCmd.h"
#include "idSWFWidget_Hud_ReticleManager.h"
#include "GeneratedClasses.h"
#include "idSWFSpriteInstanceManager.h"
#include "idDeclWeaponReticleManager.h"
#include "idPlayer.h"
#include "UserColorSet.h"
#include "idInventoryManager.h"


//#include "ObjectLocator.h"
//#include "ObjectLocator.h"

class ReticleColorManager
{

private:    

    //static UI_ReticleMode m_lastReticleMode;
    //? this is bs this is state, this is trouble:
    //x cached for performance but not sure if needed/meaningfull, as so much refactor is needed
    //static idWeapon* m_cachedShotgunIdWeaponPtr;
    //static idWeapon* m_cachedSSGIdWeaponPtr;


public:

    
   /* static void updateDotColorV3(idSWFWidget_Hud_Reticle* idSWFWidget_Hud_ReticlePtr, idDeclWeaponReticle* declWeaponReticle, idSWFSpriteInstance* idSWFSpriteInstancePtr);*/



   /* static bool isWeaponOnCoolDownFromDotReticleData() {
        logDebug("isWeaponOnCoolDownFromDotReticleData");
        idSWFWidget_Hud_Reticle* dSWFWidget_Hud_Reticle_Dot = idHUD_ReticleManager::getidSWFWidget_Hud_Reticle_Dot();
        if (MemHelper::isBadReadPtr(dSWFWidget_Hud_Reticle_Dot)) {
            logErr("isWeaponOnCoolDownFromDotReticleData dSWFWidget_Hud_Reticle_Dot is badPtr");
            return false;
        }
        return dSWFWidget_Hud_Reticle_Dot->getChargeCooldown() != 1.0f;
    }*/
   


    //static void updateDotColor() {
    //    logDebug("updateDotColor");

    //    //! if any weap other that shogun and ssg set default color
    //    if (!(idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::SHOTGUN) && (!(idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::SSG))) {
    //        if (getDotColor() != UserColorSet::getDotCrosshair_Color()) {
    //            setDotColor(UserColorSet::getDotCrosshair_Color());
    //        }
    //    }
    //    else { //! if weap is shotgun or ssg
    //        if (isWeaponOnCoolDownFromDotReticleData()) {
    //            if (getDotColor() != UserColorSet::getDotCrosshairCoodown_Color()) {
    //                setDotColor(UserColorSet::getDotCrosshairCoodown_Color());
    //            }
    //        }
    //        else {
    //            if (getDotColor() != UserColorSet::getDotCrosshair_Color()) {
    //                setDotColor(UserColorSet::getDotCrosshair_Color());
    //            }
    //        }
    //    }            
    //}


   /* static swfNamedColors_t getDotColor() {              
        logDebug("getDotColor");
        idSWFWidget_Hud_Reticle* idSWFWidget_Hud_Reticle_Dot = idHUD_ReticleManager::getidSWFWidget_Hud_Reticle_Dot();
        if (MemHelper::isBadReadPtr(idSWFWidget_Hud_Reticle_Dot)) {
            logErr("getDotColor dSWFWidget_Hud_Reticle_Dot is badPtr: %p returning SWF_NAMED_COLOR_INVALID", idSWFWidget_Hud_Reticle_Dot);
            return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
        }
        logDebug("getDotColor about to return");
        return idSWFWidget_Hud_Reticle_Dot->getReticleColorId();
    }*/

    //static void setDotColor(swfNamedColors_t swfNamedColor);




   




    /*static bool isDemonReticle(std::string reticuleNameStr) {
        logDebug("isDemonReticle");
        for (size_t i = 0; i < m_demonsReticlesNamesVec.size(); i++)
        {
            if (reticuleNameStr == m_demonsReticlesNamesVec[i]) {
                return true;
            }
        }
        return false;
    }*/

    //! not using this as i'll find a quicker way but keep it
    //bool isWeaponReticle(const char* argument) {
    //    logDebug("isWeaponReticle");

    //    // Convert the const char* to std::string and then call the previous function
    //    return isWeaponReticle(std::string(argument));
    //}

   /* static bool isWeaponReticle(const std::string& argument) {
        logDebug("isWeaponReticle");
        return (argument == Reticle::g_weaponreticleDefault ||
            argument == Reticle::g_weaponreticleShotgun ||
            argument == Reticle::g_weaponreticleShotgunPoprocket ||
            argument == Reticle::g_weaponreticleShotgunFullAuto ||
            argument == Reticle::g_weaponreticleShotgunPoprocketMastery ||
            argument == Reticle::g_weaponreticlePlasmaRifleBase ||
            argument == Reticle::g_weaponreticlePlasmaMicrowave ||
            argument == Reticle::g_weaponreticlePistolCharged ||
            argument == Reticle::g_weaponreticlePlasmaRifleAoe ||
            argument == Reticle::g_weaponreticleRocketLauncher ||
            argument == Reticle::g_weaponreticleRocketLauncherBase ||
            argument == Reticle::g_weaponreticleRocketLauncherLockonMod ||
            argument == Reticle::g_weaponreticleChaingunBase ||
            argument == Reticle::g_weaponreticleChaingunTurret ||
            argument == Reticle::g_weaponreticleChaingunEnergyShell ||
            argument == Reticle::g_weaponreticleChaingunTurretMastery ||
            argument == Reticle::g_weaponreticleGaussCannon ||
            argument == Reticle::g_weaponreticleGaussBallista ||
            argument == Reticle::g_weaponreticleGaussSiege ||
            argument == Reticle::g_weaponreticleBallistaDestroyerMastery ||
            argument == Reticle::g_weaponreticleAssaultRifleBase ||
            argument == Reticle::g_weaponreticleHeavyCannon ||
            argument == Reticle::g_weaponreticleHeavyCannonBoltAction ||
            argument == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed ||
            argument == Reticle::g_weaponreticleHeavyCannonBurstDetonate ||
            argument == Reticle::g_weaponreticleFists ||
            argument == Reticle::g_weaponreticleHammer ||
            argument == Reticle::g_weaponreticleUnmakyr ||
            argument == Reticle::g_weaponreticleChainsawBase ||
            argument == Reticle::g_weaponreticleBfg ||
            argument == Reticle::g_weaponreticleShotgunDb ||
            argument == Reticle::g_weaponreticleShotgunDbMeathook ||
            argument == Reticle::g_weaponreticleCrucible ||
            argument == Reticle::g_weaponreticleArchvile ||
            argument == Reticle::g_weaponreticleMancubus ||
            argument == Reticle::g_weaponreticleMarauder ||
            argument == Reticle::g_weaponreticlePainElemental ||
            argument == Reticle::g_weaponreticleRevenant ||
            argument == Reticle::g_weaponreticleDreadknight);
    }*/

   


    //static void debugPrintDotReticleInfo() {
    //    logDebug("debugPrintDotReticleInfo");

    //    //idHUDEvent_ReticleDataUpdate_idReticleData_t* lastreticleDataPtr = 0;
    //   
    //    idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();

    //    idSWFWidget_Hud_Reticle* idSWFWidget_Hud_Reticle_Dot = idHUD_ReticleManager::getidSWFWidget_Hud_Reticle_Dot();

    //    logInfo("debugPrintDotReticleInfo: idPlayer: %p idSWFWidget_Hud_Reticle_Dot: %p ", idPlayer, idSWFWidget_Hud_Reticle_Dot);
    //}



   /* static void debugSetGlobalReticleStyle() {
        logDebug("debugSetGlobalReticleStyle");


    }*/

    //? watch out hard coded 47330 will make the game crash if using the hud decrapifier mod
    //! this will modified the current weapon crosshair scale but it will not update the scale until user has changed to another weapon and come back to it.
    //static void debugSetReticleScaleRealTimeTest(float reticuleScaleUserOverideFloat) {
    //    logDebug("debugSetReticleScaleRealTimeTest");

    //    try
    //    {
    //        idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();


    //        if (idPlayer) {
    //            logInfo("debugSetReticleScaleRealTimeTest idPlayerAddr %p", (void*)idPlayer);
    //            char* idHUD_ReticlePtr = ((char*)idPlayer + 0x47330);
    //            char* dereferencedidHUD_ReticlePtr = (char*)*(__int64*)idHUD_ReticlePtr;
    //            logInfo("debugSetReticleScaleRealTimeTest idHUD_ReticlePtr: %p dereferencedidHUD_ReticlePtr: %p", idHUD_ReticlePtr, (dereferencedidHUD_ReticlePtr));
    //            char* idDeclWeaponReticlePtr = (char*)(*(__int64*)idHUD_ReticlePtr) + 0xF8;
    //            //__int64* idDeclWeaponReticlePtr = (__int64*)((*idHUD_ReticlePtr) + 0xF8);
    //            logInfo("debugSetReticleScaleRealTimeTest idDeclWeaponReticlePtr %p", (void*)idDeclWeaponReticlePtr);
    //            float reticleScaleFloat = *(float*) (*(__int64*)idDeclWeaponReticlePtr + 0xF8);
    //            //float reticleScaleFloatPtr = *(float*)((*idDeclWeaponReticlePtr) + 0xF8);
    //            logInfo("debugSetReticleScaleRealTimeTest current reticleScaleFloat val is %.2f", reticleScaleFloat);
    //            *(float*) ((*(__int64*)idDeclWeaponReticlePtr) + 0xF8 ) = reticuleScaleUserOverideFloat;
    //            reticleScaleFloat = *(float*)(*(__int64*)idDeclWeaponReticlePtr + 0xF8);
    //            logInfo("debugSetReticleScaleRealTimeTest New reticleScaleFloat val is %.2f", reticleScaleFloat);

    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        logErr("debugSetReticleScaleRealTimeTest: ERROR: %s ", ex.what());
    //    }
    //}


    //static void debugUpdateDotColorV2() {
    //    logDebug("debugUpdateDotColorV2");

    //    static weaponSlot_t lastWeaponSlot = weaponSlot_t::UNDEFINED;
    //    static uint64_t m_lastHARWeaponEquippedMs = 0;

    //    idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();


    //    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (idPlayer) {
    //        //idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayer->idHUD_ReticlePtr && idPlayer->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot) {
    //            idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayer->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;

    //            if (idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::HAR) {
    //                m_lastHARWeaponEquippedMs = EpochMillis();
    //            }

    //            if ((idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::SHOTGUN) || ((idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::SSG))) {

    //                if (((EpochMillis() - m_lastHARWeaponEquippedMs) > 500) && isWeaponOnCoolDownFromDotReticleData()) {
    //                    if (getDotColor() != UserColorSet::getDotCrosshairCoodown_Color()) {
    //                        setDotColor(UserColorSet::getDotCrosshairCoodown_Color());
    //                    }
    //                    return;
    //                }
    //            }

    //            if (getDotColor() != UserColorSet::getDotCrosshair_Color()) {
    //                setDotColor(UserColorSet::getDotCrosshair_Color());
    //            }
    //        }
    //    }
    //}


    //! lastWeaponFireWasZoomed(idPlayer) is maybe what we want 
    //static void debugUpdateDotColor() {
    //    logDebug("debugUpdateDotColor");

    //    static weaponSlot_t lastWeaponSlot = weaponSlot_t::UNDEFINED;
    //    static uint64_t m_lastHARWeaponEquippedMs = 0;

    //    idPlayer_t* idPlayer = idMapInstanceLocalManager::getIdPlayerPtr();
    //    //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
    //    if (idPlayer) {
    //        //idPlayer_t* idPlayer = (idPlayer_t*)idPlayerAddr;
    //        if (idPlayer->idHUD_ReticlePtr && idPlayer->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot) {
    //            idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayer->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;

    //            if (idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::HAR) {
    //                m_lastHARWeaponEquippedMs = EpochMillis();
    //            }

    //            if ((idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::SHOTGUN) || ((idPlayer_K::getcurrentWeaponSlotIndex() == weaponSlot_t::SSG))) {

    //                if (((EpochMillis() - m_lastHARWeaponEquippedMs) > 500) && isWeaponOnCoolDownFromDotReticleData()) {
    //                    if (getDotColor() != UserColorSet::getDotCrosshairCoodown_Color()) {
    //                        setDotColor(UserColorSet::getDotCrosshairCoodown_Color());
    //                    }
    //                    return;
    //                }
    //            }

    //            if (getDotColor() != UserColorSet::getDotCrosshair_Color()) {
    //                setDotColor(UserColorSet::getDotCrosshair_Color());
    //            }
    //        }
    //    }
    //}






};

//? if we loop all the declReticle and try to set the reticle scale on the last one, often, the game will crash. This is used to prevent that.
//const unsigned int ReticleColorManager::m_declReticleMaxCount = 39;
//const unsigned int ReticleColorManager::m_nextDeclWeaponReticlePtrOffset = 0x18;


//idWeapon* ReticleColorManager::m_cachedShotgunIdWeaponPtr = 0;
//idWeapon* ReticleColorManager::m_cachedSSGIdWeaponPtr = 0;

//std::vector<std::string> ReticleColorManager::m_ballistaReticlesNamesVec = { Reticle::g_weaponreticleGaussCannon , Reticle::g_weaponreticleGaussBallista , Reticle::g_weaponreticleGaussSiege , Reticle::g_weaponreticleBallistaDestroyerMastery };

//std::vector<std::string> ReticleColorManager::m_demonsReticlesNamesVec = { Reticle::g_weaponreticleArchvile , Reticle::g_weaponreticleMancubus , Reticle::g_weaponreticleMarauder , Reticle::g_weaponreticlePainElemental,  Reticle::g_weaponreticleRevenant , Reticle::g_weaponreticleDreadknight };

//UI_ReticleMode ReticleColorManager::m_lastReticleMode = UI_ReticleMode::Unknown;

