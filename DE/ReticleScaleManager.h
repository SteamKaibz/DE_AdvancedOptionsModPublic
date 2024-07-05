#pragma once
#include "Types.h"
#include "../IniFile/IniFileData.h"
#include "idPlayer.h"

class ReticleScaleManager {

private:

    static std::vector<std::string>m_ballistaReticlesNamesVec;
    static float m_lastIniReticleScaleVal;
    static ImmersiveCrosshairLevel m_lastIniImmersiveCrosshairLevel;
    static bool m_isSpriteScaleUpdateNeeded;

    static float m_debugLastReticleScale;

public:

    static void setIsSpriteReloadedNeeded(bool isNeeded) {
        m_isSpriteScaleUpdateNeeded = isNeeded;
    }

    static bool isSpriteReloadedNeeded() {
        return m_isSpriteScaleUpdateNeeded;
    }
    
    //! triggered from hook, check made for declWeaponReticle and idSWFSpriteInstance. reticle scale change can happen on any reticle not just the dot.
	static bool updateScale(idDeclWeaponReticle* declWeaponReticle) {
        if (!declWeaponReticle) return false;
        logDebug("updateScale");

        float computedReticleScale = computeReticleScale(declWeaponReticle, modSettings::getReticleScale(), fastCvarManager::getReticleMode());
        //float computedReticleScale = computeReticleScale(declWeaponReticle, modSettings::getReticleScale(), idCmd::getReticleMode());

        //logInfo("updateScale debug: computedReticleScale: %.3f and declWeaponReticle->reticleModelScale: %.3f", computedReticleScale, declWeaponReticle->reticleModelScale);

        if (declWeaponReticle->reticleModelScale != computedReticleScale) {
            declWeaponReticle->reticleModelScale = computedReticleScale;
            logInfo("updateScale: just changed  declWeaponReticle->reticleModelScale, reticle scale needs updating");
            return true;
        }
        //! we need that because we want to reload the sprite cause it will not reload if the declWeaponReticle->reticleModelScale changes and either user goes to menu or changes weapon
        else if (isModSettingsChanged()) {
            logInfo("updateScale: returning true cause isModSettingsChanged");
            return true;
        }
        return false;
	}


    static bool isModSettingsChanged() {
        if (modSettings::getReticleScale() != m_lastIniReticleScaleVal) {
            m_lastIniReticleScaleVal = modSettings::getReticleScale();
            return true;
        }
        if (modSettings::getImmersiveCrosshairLevel() != m_lastIniImmersiveCrosshairLevel) {
            m_lastIniImmersiveCrosshairLevel = modSettings::getImmersiveCrosshairLevel();
            return true;
        }
        return false;
    }


    /*static bool isImmersiveCrosshairMode() {
        static ImmersiveCrosshairLevel debugLastImmersiveCrosshairMode = ImmersiveCrosshairLevel::IMMERSIVE_CROSSHAIR_LEVEL_UNKNOWN;

        ImmersiveCrosshairLevel immersiveCrosshairLevel = IniFileData::getImmersiveCrosshairLevel();
        if (immersiveCrosshairLevel != debugLastImmersiveCrosshairMode) {
            debugLastImmersiveCrosshairMode = immersiveCrosshairLevel;
            logInfo("isImmersiveCrosshairMode: ImmersiveCrosshairMode level is: %d", immersiveCrosshairLevel);
        }        
        return (immersiveCrosshairLevel == ImmersiveCrosshairLevel::HAR_ONLY) || (immersiveCrosshairLevel == ImmersiveCrosshairLevel::HAR_BALISTA);

    }*/

    static float getReticleScaleForImmersiveCrosshairMode(std::string& reticleName) {
        ImmersiveCrosshairLevel immersiveCrosshairLevel = modSettings::getImmersiveCrosshairLevel();
        

        if (immersiveCrosshairLevel == ImmersiveCrosshairLevel::HAR_ADS) {
            if (reticleName == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed) {
                return Reticle::g_defaultReticleScale;
            }
        }
        else if (immersiveCrosshairLevel == ImmersiveCrosshairLevel::HAR_ADS_BALISTA_BOTH) { 
            if (reticleName == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed) {
                return Reticle::g_defaultReticleScale;
            }            
            else if (reticleName == Reticle::g_weaponreticleGaussBallista) {
                return Reticle::defaultReticleScaleForBalistaWeapons; //! we can't handle balista ads crosshair only here because the reticle is the same (same name) for hips or ads view so we have to poll in main. 
            }
        }  
        else if (immersiveCrosshairLevel == ImmersiveCrosshairLevel::HAR_ADS_BALISTA_ADS) {
            //logInfo("HAR_BALISTA_ADS triggered");
            if (reticleName == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed) {
                //logInfo("HAR_BALISTA_ADS 1");
                return Reticle::g_defaultReticleScale;
            }
            else if (reticleName == Reticle::g_weaponreticleGaussBallista && idPlayer_K::wantZoom()) {
                //logInfo("HAR_BALISTA_ADS 2");
                return Reticle::defaultReticleScaleForBalistaWeapons; 
            }
        }
        //else if (reticleName == Reticle::g_weaponreticleGaussBallista && idPlayer_K::wantZoom()) {
        ////else if (reticleName == Reticle::g_weaponreticleGaussSiege) {// no rtc in hips and ads
        ////else if (reticleName == Reticle::g_weaponreticleGaussCannon) { // no rtc in hips and ads
        ////else if (reticleName == Reticle::g_weaponreticleGaussBallista) { // rtcl for hips and ads
        //    return Reticle::defaultReticleScaleForBalistaWeapons;
        //}
        return Reticle::g_invisibleReticleScale;
    }


    static float getDefaultReticleScaleFor(idDeclWeaponReticle* weaponReticlePtr) {
        logDebug("getDefaultReticleScaleFor");
       
        std::string reticleName = idResourceManager::getDeclWeaponReticleName(weaponReticlePtr);
        //std::string reticleName = weaponReticlePtr->getNameStr();
        //logDebug("getDefaultReticleScaleFor: reticleName: %s", reticleName.c_str());

        if(isReticleNameBalistaWeapons(reticleName)){
            if (weaponReticlePtr->reticleModelScale != Reticle::defaultReticleScaleForBalistaWeapons) {
                logInfo("getDefaultReticleScaleFor: returning Reticle needs to be changed to Reticle::defaultReticleScaleForBalistaWeapons: %.3f", Reticle::defaultReticleScaleForBalistaWeapons);
            }
            return Reticle::defaultReticleScaleForBalistaWeapons;
        }
       
        //! this is not the ads assault rifle, it's the hips version and it's 0.5f
        if (reticleName == Reticle::g_weaponreticleAssaultRifleBase) {
            if (weaponReticlePtr->reticleModelScale != Reticle::defaultReticleScaleAssaultRifleBase) {
                logInfo("getDefaultReticleScaleFor: returning Reticle needs to be changed to Reticle::defaultReticleScaleAssaultRifleBase: %.3f", Reticle::defaultReticleScaleAssaultRifleBase);
            }
            return Reticle::defaultReticleScaleAssaultRifleBase;
        }
     
        return Reticle::g_defaultReticleScale;
    }

    static bool isReticleNameBalistaWeapons(std::string reticleName) {
        for (size_t i = 0; i < m_ballistaReticlesNamesVec.size(); i++)
        {
            if (reticleName == m_ballistaReticlesNamesVec[i]) {
                return true;
            }
        }
        return false;
    }

    static bool setReticleScaleToDefault(idDeclWeaponReticle* weaponReticlePtr) {
        logDebug("setReticleScaleToDefault");
        std::string reticleName = idResourceManager::getDeclWeaponReticleName(weaponReticlePtr);

        if (isReticleNameBalistaWeapons(reticleName)) {
            if (weaponReticlePtr->reticleModelScale != Reticle::defaultReticleScaleForBalistaWeapons) {
                weaponReticlePtr->reticleModelScale = Reticle::defaultReticleScaleForBalistaWeapons;
                logInfo("Reticle: %s has been set back to its default value: %.3f", idResourceManager::getDeclWeaponReticleName(weaponReticlePtr).c_str(), weaponReticlePtr->reticleModelScale);
                return true;
            }

        }       
        if (reticleName == Reticle::g_weaponreticleAssaultRifleBase) {
            if (weaponReticlePtr->reticleModelScale != Reticle::defaultReticleScaleAssaultRifleBase) {
                weaponReticlePtr->reticleModelScale = Reticle::defaultReticleScaleAssaultRifleBase;
                logInfo("Reticle: %s has been set back to its default value: %.3f", idResourceManager::getDeclWeaponReticleName(weaponReticlePtr).c_str(), weaponReticlePtr->reticleModelScale);
                return true;
            }
        }
        if (weaponReticlePtr->reticleModelScale != Reticle::g_defaultReticleScale) {
            weaponReticlePtr->reticleModelScale = Reticle::g_defaultReticleScale;
            logInfo("Reticle: %s has been set back to its default value: %.3f", idResourceManager::getDeclWeaponReticleName(weaponReticlePtr).c_str(), weaponReticlePtr->reticleModelScale);
            return true;
        }
        return false;
    }


    static bool isIniCrosshairScaleDefault() {
        return (modSettings::getReticleScale() == Reticle::g_defaultReticleScale);
    }


    static float computeReticleScale(idDeclWeaponReticle* weaponReticlePtr, float userRequestedReticleScaleFloat, UI_ReticleMode reticleMode) {
        logDebug("computeReticleScale debug called and weaponReticlePtr name is %s and userRequestedReticleScaleFloat is %.3f", idResourceManager::getDeclWeaponReticleName(weaponReticlePtr).c_str(), userRequestedReticleScaleFloat);

        bool isOvewrite = false;
        std::string reticleName = idResourceManager::getDeclWeaponReticleName(weaponReticlePtr);

        if (modSettings::isImmersiveCrosshairModeEnabled()) {
            if (reticleMode == UI_ReticleMode::None) { 
                logWarn("computeReticleScale current reticle Mode is: %d and setting it to Full", (int)reticleMode);
                //todo carefull about having state here, atm each else prevents issues but i don't like it.
                idCmd::setReticleMode(UI_ReticleMode::Full); //! forcing to full arbitrarily even it should work with dot
            }
            userRequestedReticleScaleFloat = getReticleScaleForImmersiveCrosshairMode(reticleName);
        }
        else if (reticleName == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed && reticleMode == UI_ReticleMode::Full) { //! Full Reticle for Ads HAR has to be 1.0 otherwise it looks weird
            //logInfo("computeReticleScale : reticleName == Reticle::g_weaponreticleHeavyCannonBoltActionZoomed  && reticleMode == UI_ReticleMode::Full");
            userRequestedReticleScaleFloat = Reticle::g_defaultReticleScale;;
        }

        else if (isIniCrosshairScaleDefault() && reticleMode == UI_ReticleMode::Full) {
            //userRequestedReticleScaleFloat = getDefaultReticleScaleFor(weaponReticlePtr);
            userRequestedReticleScaleFloat = getDefaultReticleScaleFor(weaponReticlePtr);
        }

        if (userRequestedReticleScaleFloat != m_debugLastReticleScale) {
            m_debugLastReticleScale = userRequestedReticleScaleFloat;
            logInfo("computeReticleScale : userRequestedReticleScaleFloat has changed to : %.3f", userRequestedReticleScaleFloat);
        }
        return userRequestedReticleScaleFloat; //! returning input if it doen't need change.
    }
};


std::vector<std::string> ReticleScaleManager::m_ballistaReticlesNamesVec = { Reticle::g_weaponreticleGaussCannon , Reticle::g_weaponreticleGaussBallista , Reticle::g_weaponreticleGaussSiege , Reticle::g_weaponreticleBallistaDestroyerMastery };

 float ReticleScaleManager::m_lastIniReticleScaleVal = -1.0f;
 ImmersiveCrosshairLevel ReticleScaleManager::m_lastIniImmersiveCrosshairLevel = ImmersiveCrosshairLevel::IMMERSIVE_CROSSHAIR_LEVEL_UNKNOWN;

 bool ReticleScaleManager::m_isSpriteScaleUpdateNeeded = false;
 float ReticleScaleManager::m_debugLastReticleScale =  -1.0f;