#include "idDeclUIColorManager.h"


//void idDeclUIColorManager::initColors() {
//    acquireDefaultColors();
//    updateCustomIdColors();
//}

//void idDeclUIColorManager::updateCurrentIdDeclUIColorFromHook(idDeclUIColor* idDeclUIColorPtr)
//{
//    static idDeclUIColor* lastidDeclUIColorPtr = nullptr;
//
//    if (idDeclUIColorPtr != lastidDeclUIColorPtr) {
//        lastidDeclUIColorPtr = idDeclUIColorPtr;
//        logInfo("updateCurrentIdDeclUIColorFromHook: idDeclUIColorPtr has changed to: %p", idDeclUIColorPtr);
//    }
//    m_currentIdDeclUIColor = idDeclUIColorPtr;
//}



//? alpha should always be 1.0. at least from my tests
ImU32 idDeclUIColorManager::ConvertIdColorToU32(const idColor& idColor)
{
    ImU32 out;
    out = ((ImU32)IM_F32_TO_INT8_SAT(idColor.r)) << IM_COL32_R_SHIFT;
    out |= ((ImU32)IM_F32_TO_INT8_SAT(idColor.g)) << IM_COL32_G_SHIFT;
    out |= ((ImU32)IM_F32_TO_INT8_SAT(idColor.b)) << IM_COL32_B_SHIFT;
    out |= ((ImU32)IM_F32_TO_INT8_SAT(idColor.a)) << IM_COL32_A_SHIFT;
    return out;
}



// forcing alpha to max as user can not change alpha value in color picker cause it's a bit confusing.
//ImVec4 idDeclUIColorManager::convertIdColorToImVec4(idColor idcolor) {
//    logInfo("convertIdColorToImVec4: idcolor.r: %.3f idcolor.g: %.3f idcolor.b: %.3f idcolor.a: %.3f (forcing alpha to 1.0)", idcolor.r, idcolor.g, idcolor.b, idcolor.a);
//    return ImVec4(idcolor.r, idcolor.g, idcolor.b, 1.0f);
//    //return ImVec4(idcolor.r, idcolor.g, idcolor.b, idcolor.a);
//}


void idDeclUIColorManager::setKaibzHudColorsToGameColorProfile() {

    logInfo("setKaibzHudColorsToGameColorProfile: attempting to set custom hud colors to current game profile colors");

    idDeclUIColor* currentIdDeclUIColorPtr = idDeclGlobalShellManager::getCurrentColorProfile();
    if (! currentIdDeclUIColorPtr) {
        logErr("setKaibzHudColorsToGameColorProfile: currentIdDeclUIColorPtr is nullptr returning");
        return;
    }

    modSettings::setKaibzHudCautionColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiCaution.color));

    modSettings::setKaibzHudWarningColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiWarning.color));    
    //! uiCaution will be yellow for the default profile so not good
    //modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiCaution.color));    
    //! uiFailure will also be a different tint of orange in default profile so this is not good
    //modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiFailure.color));
    //! this is red but not very saturated:
    //modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->screenDamage.color));
    //! this is darkred
    //modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->reticleWarningGlow.color));    
    //! this is orange
    //modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->reticleWarningBase.color));
    //! pinkish
    //modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->weaponHammerFull.color));
    //! this seems to work fine
    modSettings::setKaibzHudCriticalColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudBossHealthBase.color));


    //? none of the extralives field do have a color corresponding to the game icon, weird. hudText seems to work well though.
    modSettings::setKaibzHudExtraLivesColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudText.color));

    modSettings::setKaibzHudBloodPunch1ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiWarning.color));
    //modSettings::setKaibzHudBloodPunch2ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiCaution.color));
    modSettings::setKaibzHudBloodPunch2ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudBossHealthBase.color));
    modSettings::setKaibzHudBloodPunchDesperateColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->supportRuneGlow.color));

    modSettings::modSettings::setKaibzHudHealthMaxColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiHealth.color));
    modSettings::setKaibzHudHealthColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiHealth.color));

    modSettings::setKaibzHudArmorMaxColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiArmor.color));
    modSettings::setKaibzHudArmorColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiArmor.color));

    modSettings::setKaibzHudRadsuitColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiRadiation.color));
    modSettings::setKaibzHudOxygenColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiOxygen.color));

    modSettings::setKaibzHudAmmoColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudHeader.color));

    modSettings::setKaibzHudHammerCrucibleColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentHammer.color));

    modSettings::setKaibzHudFlameBelchColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentFlameBelch.color));

    modSettings::setKaibzHudFuel1ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentChainsaw.color));
    //modSettings::setKaibzHudFuel2ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiWarning.color));
    modSettings::setKaibzHudFuel2ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->uiWarning.color));
    modSettings::setKaibzHudFuel3ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudBossHealthBase.color));

    modSettings::setKaibzHudFrag1ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentFragIcon.color));
    modSettings::setKaibzHudFrag2ColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentFrag.color));

    modSettings::setKaibzHudIceColorImU32(ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentCyro.color));
}


ImU32 idDeclUIColorManager::getCurGameProfileColorElemImU32(KaibzHudColor_t color_k) {

    idDeclUIColor* currentIdDeclUIColorPtr = idDeclGlobalShellManager::getCurrentColorProfile();
    if (! currentIdDeclUIColorPtr) {
        logErr("getCurGameProfileColorElemImU32: currentIdDeclUIColor is nullptr returning white");
        return IM_COL32(255, 255, 255, 255); // white;
    }

    
    switch (color_k)
    {
  /*  case KaibzHudColor_t::disabledColor:
        return Menu::DarkGreyColorImVec4;*/
    case KaibzHudColor_t::warningColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->uiWarning.color);
    case KaibzHudColor_t::criticalColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->uiCaution.color);
    case KaibzHudColor_t::extraLivesColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->extraLifeIcon.color);
    /*case KaibzHudColor_t::bloodPunch1Color:
        return Menu::BloodPunch1ColorImVec4;
    case KaibzHudColor_t::bloodPunch2Color:
        return Menu::BloodPunch2ColorImVec4;
    case KaibzHudColor_t::bloodPunchDesperateColor:
        return Menu::BloodPunchDesperateColorImVec4;*/
   /* case KaibzHudColor_t::healthMaxColor:
        return Menu::HealthMaxColorImVec4;*/
    case KaibzHudColor_t::healthColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->uiHealth.color);
    //case KaibzHudColor_t::armorMaxColor:
    //    return Menu::ArmorMaxColorImVec4;
    case KaibzHudColor_t::armorColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->uiArmor.color);
    case KaibzHudColor_t::radsuitColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->uiRadiation.color);
    case KaibzHudColor_t::oxygenColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->uiOxygen.color);
   /* case KaibzHudColor_t::ammoColor:
        return Menu::AmmoColorImVec4;*/
    case KaibzHudColor_t::hammerCrucibleColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentHammer.color);
    case KaibzHudColor_t::flameBelchColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentFlameBelch.color);
    case KaibzHudColor_t::fuel1Color:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentChainsaw.color);
  /*  case KaibzHudColor_t::fuel2Color:
        return Menu::Fuel2ColorImVec4;
    case KaibzHudColor_t::fuel3Color:
        return Menu::Fuel3ColorImVec4;*/
    case KaibzHudColor_t::frag1Color:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentFrag.color);
   /* case KaibzHudColor_t::frag2Color:
        return Menu::Frag2ColorImVec4;*/
    case KaibzHudColor_t::iceColor:
        return ConvertIdColorToU32(currentIdDeclUIColorPtr->hudEquipmentCyro.color);
    default:
        logWarn("getCurGameProfileColorElemImU32: returning default for KaibzHudColor_t: %d (?!) may be this hud element should not go through getCurGameProfileColorElemImU32...", color_k);
        return IM_COL32(255, 255, 255, 255); // white;
        
    }

}

//idColor GameHudColorsManager::getCurrentProfileFragNadeIconColor() {
//    logDebug("getCurrentProfileFragNadeIconColor");
//
//    if (!MemHelper::isBadReadPtr((void*)m_currentIdDeclUIColor)) {
//        idDeclUIColor* declUIColorPtr = (idDeclUIColor*)m_currentIdDeclUIColor;
//        return declUIColorPtr->hudEquipmentFragIcon.color;
//    }
//    logWarn("getCurrentProfileFragNadeIconColor could not find color, returning default");
//    return m_defaultFragNadeIconColor;
//}


//void idDeclUIColorManager::debugLogCurrentColorProfileName(int index) {
//
//    idList* idDeclUIColorListPtr = idDeclGlobalShellManager::getColorProfileColorsIdList();
//
//    if (!idDeclUIColorListPtr) {
//        logErr("debugLogCurrentColorProfileName: idDeclUIColorListPtr is nullptr");
//        return;
//    }
//
//    int curColorProfileIndex = fastCvarManager::getColorProfileIndex();
//
//    logInfo("debugLogCurrentColorProfileName: idDeclUIColorListPtr: %p idDeclUIColorListPtr->num : %d curColorProfileIndex: %d", idDeclUIColorListPtr, idDeclUIColorListPtr->num, curColorProfileIndex);
//
//   
//   __int64* idDeclUIColorPtr = (__int64*)idDeclUIColorListPtr->list;
//
//
//    for (size_t i = 0; i < idDeclUIColorListPtr->num; i++)
//    {
//
//        if (idDeclUIColorPtr) {
//            idDeclUIColor* declColorPtr = (idDeclUIColor*) *(__int64*)idDeclUIColorPtr;
//            if (declColorPtr) {
//                idResource* resPtr = (idResource*)declColorPtr;
//                logInfo("idDeclUIColor res name: %s (cur num: %zu)", resPtr->name.str, i);
//            }
//
//        }
//
//        idDeclUIColorPtr++;
//        //logInfo("idDeclUIColor ptr: %p", idDeclUIColorPtr);
//        
//        //? this crashes
//        /*idResource* resPtr = (idResource*)idDeclUIColorPtr;
//        if (resPtr->name.str && resPtr->name.str[0]) {
//            logInfo("idDeclUIColor res name: %s (cur num: %zu)", resPtr->name.str, i);
//        }
//        else {
//            logWarn("no name for ptr: %p", idDeclUIColorPtr);
//        }*/
//       
//    }
//
//
//}

//void idDeclUIColorManager::acquireDefaultColors()
//{
//    
//    idList* idDeclUIColorListPtr = idDeclGlobalShellManager::getColorProfileColorsIdList();
//
//    if (!idDeclUIColorListPtr) {
//        logErr("acquireDefaultColors: idDeclUIColorListPtr is nullptr");
//        m_isInitialized = false;
//        return;
//    }
//
//    logInfo("acquireDefaultColors: debug: idDeclUIColorListPtr: %p and idDeclUIColorListPtr->num: %d", idDeclUIColorListPtr, idDeclUIColorListPtr->num);
//
//    m_idDeclUIColor_Custom_Vec.clear();
//
//    idDeclUIColor* idDeclUIColorPtr = (idDeclUIColor*)idDeclUIColorListPtr->list;
//
//    for (size_t i = 0; i < idDeclUIColorListPtr->num; i++)
//    {
//        idDeclUIColor_Custom custContainer;
//        if (createCustomColorDeclBAK(custContainer, idDeclUIColorPtr)) {
//            m_idDeclUIColor_Custom_Vec.push_back(custContainer);          
//        }
//
//        idDeclUIColorPtr++;     
//    }
//    
//    logInfo("acquireDefaultColors: acquired %zu custom color profiles setting m_isInitialized to true",  m_idDeclUIColor_Custom_Vec.size());
//    m_isInitialized = true;
//}
//
//bool idDeclUIColorManager::createCustomColorDeclBAK(idDeclUIColor_Custom& customColor, const idDeclUIColor* originalColor) {
//    //idDeclUIColor_Custom customColor;
//
//    if (!originalColor) {
//        logErr("createCustomColorDeclBAK: originalColor is bad ptr returning");
//        return false;
//    }
//
//    logInfo("createCustomColorDeclBAK: originalColor ptr: %p", originalColor);
//
//    // Copying members from originalColor to customColor
//    customColor.displayName = originalColor->displayName;
//    //logInfo("createCustomColorDeclBAK: debug customColor.displayName.id: 0x%X originalColor->displayName.id: 0x%X", customColor.displayName.id, originalColor->displayName.id);
//    customColor.isColorBlindProfile = originalColor->isColorBlindProfile;
//    customColor.uiRadiation = originalColor->uiRadiation;
//    customColor.uiRadiationGradient = originalColor->uiRadiationGradient;
//    customColor.white = originalColor->white;
//    customColor.weaponChainsaw = originalColor->weaponChainsaw;
//    customColor.weaponShotgun = originalColor->weaponShotgun;
//    customColor.weaponDoubleBarrel = originalColor->weaponDoubleBarrel;
//    customColor.weaponAssualtRifle = originalColor->weaponAssualtRifle;
//    customColor.weaponChaingun = originalColor->weaponChaingun;
//    customColor.weaponPlasmaRifle = originalColor->weaponPlasmaRifle;
//    customColor.weaponBallista = originalColor->weaponBallista;
//    customColor.weaponRocketLauncher = originalColor->weaponRocketLauncher;
//    customColor.weaponBfg = originalColor->weaponBfg;
//    customColor.weaponUnmaykr = originalColor->weaponUnmaykr;
//    customColor.weaponCrucible = originalColor->weaponCrucible;
//    customColor.weaponHammer = originalColor->weaponHammer;
//    customColor.weaponShotgunFull = originalColor->weaponShotgunFull;
//    customColor.weaponDoubleBarrelFull = originalColor->weaponDoubleBarrelFull;
//    customColor.weaponAssualtRifleFull = originalColor->weaponAssualtRifleFull;
//    customColor.weaponChaingunFull = originalColor->weaponChaingunFull;
//    customColor.weaponPlasmaRifleFull = originalColor->weaponPlasmaRifleFull;
//    customColor.weaponBallistaFull = originalColor->weaponBallistaFull;
//    customColor.weaponRocketLauncherFull = originalColor->weaponRocketLauncherFull;
//    customColor.weaponBfgFull = originalColor->weaponBfgFull;
//    customColor.weaponUnmaykrFull = originalColor->weaponUnmaykrFull;
//    customColor.weaponHammerFull = originalColor->weaponHammerFull;
//    customColor.reticleBase = originalColor->reticleBase;
//    customColor.reticleGlow = originalColor->reticleGlow;
//    customColor.hudEquipmentFrag = originalColor->hudEquipmentFrag;
//    customColor.hudEquipmentFragIcon = originalColor->hudEquipmentFragIcon;
//    customColor.hudEquipmentCyro = originalColor->hudEquipmentCyro;
//    customColor.hudEquipmentCyroIcon = originalColor->hudEquipmentCyroIcon;
//    customColor.hudEquipmentChainsaw = originalColor->hudEquipmentChainsaw;
//    customColor.hudEquipmentChainsawIcon = originalColor->hudEquipmentChainsawIcon;
//    customColor.bloodPunchSuperchargeBase = originalColor->bloodPunchSuperchargeBase;
//    customColor.bloodPunchSuperchargeGlow = originalColor->bloodPunchSuperchargeGlow;
//
//    customColor.isInitialized = true;
//
//    return true;
//}
//
//void idDeclUIColorManager::restoreColorsForHudElement(hudElementColorRef hudElementRef, idDeclUIColor* originalColorPtr)
//{    
//    if (!originalColorPtr) {
//        logErr("restoreColorsForHudElement: found originalColorPtr which is nullptr");
//        return;
//    }
//
//    idDeclUIColor_Custom customColor = findCustomColorByDisplayName(originalColorPtr->displayName.id);
//    if (!customColor.isInitialized) {
//        logErr("restoreColorsForHudElement: found unitialized idDeclUIColor_Custom for idDeclUIColor ptr: %p", originalColorPtr);
//        return;
//    }
//
//    switch (hudElementRef)
//    {
//    case hudElementColorRef::bloodpunch:
//        originalColorPtr->bloodPunchSuperchargeBase = customColor.bloodPunchSuperchargeBase;
//        originalColorPtr->bloodPunchSuperchargeGlow = customColor.bloodPunchSuperchargeGlow;
//        break;
//    case hudElementColorRef::fuel:
//        originalColorPtr->hudEquipmentChainsaw = customColor.hudEquipmentChainsaw;
//        originalColorPtr->hudEquipmentChainsawIcon = customColor.hudEquipmentChainsawIcon;
//        break;
//    case hudElementColorRef::fragNade:
//        originalColorPtr->hudEquipmentFrag = customColor.hudEquipmentFrag;
//        originalColorPtr->hudEquipmentFragIcon = customColor.hudEquipmentFragIcon;
//        break;
//    case hudElementColorRef::iceNade:
//        originalColorPtr->hudEquipmentCyro = customColor.hudEquipmentCyro;
//        originalColorPtr->hudEquipmentCyroIcon = customColor.hudEquipmentCyroIcon;
//        break;
//    case hudElementColorRef::weapons:
//        originalColorPtr->weaponChainsaw = customColor.weaponChainsaw;
//        originalColorPtr->weaponShotgun = customColor.weaponShotgun;
//        originalColorPtr->weaponDoubleBarrel = customColor.weaponDoubleBarrel;
//        originalColorPtr->weaponAssualtRifle = customColor.weaponAssualtRifle;
//        originalColorPtr->weaponChaingun = customColor.weaponChaingun;
//        originalColorPtr->weaponPlasmaRifle = customColor.weaponPlasmaRifle;
//        originalColorPtr->weaponBallista = customColor.weaponBallista;
//        originalColorPtr->weaponRocketLauncher = customColor.weaponRocketLauncher;
//        originalColorPtr->weaponBfg = customColor.weaponBfg;
//        originalColorPtr->weaponUnmaykr = customColor.weaponUnmaykr;
//        originalColorPtr->weaponCrucible = customColor.weaponCrucible;
//        originalColorPtr->weaponHammer = customColor.weaponHammer;
//        originalColorPtr->weaponShotgunFull = customColor.weaponShotgunFull;
//        originalColorPtr->weaponDoubleBarrelFull = customColor.weaponDoubleBarrelFull;
//        originalColorPtr->weaponAssualtRifleFull = customColor.weaponAssualtRifleFull;
//        originalColorPtr->weaponChaingunFull = customColor.weaponChaingunFull;
//        originalColorPtr->weaponPlasmaRifleFull = customColor.weaponPlasmaRifleFull;
//        originalColorPtr->weaponBallistaFull = customColor.weaponBallistaFull;
//        originalColorPtr->weaponRocketLauncherFull = customColor.weaponRocketLauncherFull;
//        originalColorPtr->weaponBfgFull = customColor.weaponBfgFull;
//        originalColorPtr->weaponUnmaykrFull = customColor.weaponUnmaykrFull;
//        originalColorPtr->weaponHammerFull = customColor.weaponHammerFull;
//        break;
//    case hudElementColorRef::radmeter:
//        originalColorPtr->uiRadiation = customColor.uiRadiation;
//        originalColorPtr->uiRadiationGradient = customColor.uiRadiationGradient;
//        break;
//    default:
//        logWarn("restoreColorsForHudElement: default case (?!)");
//        break;
//    }
//}
//
//
//idDeclUIColor_Custom idDeclUIColorManager::findCustomColorByDisplayName(unsigned int displayNameId) {
//    for (const auto& customColor : m_idDeclUIColor_Custom_Vec) {
//        if (customColor.displayName.id == displayNameId) {
//            return customColor;
//        }
//    }
//    // If not found, return a default-initialized object
//    return idDeclUIColor_Custom();
//}
//
//
//void idDeclUIColorManager::restoreAllProfilesColorsForHudElement(hudElementColorRef hudElementRef) {
//
//    int debugCounter = 0;
//    idList* idDeclUIColorListPtr = idDeclGlobalShellManager::getColorProfileColorsIdList();
//
//    if (!idDeclUIColorListPtr) {
//        logErr("restoreAllProfilesColorsForHudElement: idDeclUIColorListPtr is nullptr");
//        return;
//    }
//
//  /*  logInfo("acquireDefaultColors: debug: idDeclUIColorListPtr: %p and idDeclUIColorListPtr->num: %d", idDeclUIColorListPtr, idDeclUIColorListPtr->num);*/  
//
//    idDeclUIColor* idDeclUIColorPtr = (idDeclUIColor*)idDeclUIColorListPtr->list;
//
//    for (size_t i = 0; i < idDeclUIColorListPtr->num; i++)
//    {       
//        restoreColorsForHudElement(hudElementRef, idDeclUIColorPtr);
//        idDeclUIColorPtr++;
//        debugCounter++;
//    }
//
//    logInfo("restoreAllProfilesColorsForHudElement: done restoring %d color profiles for hud element: %d", debugCounter, hudElementRef);
//}


//idColor idDeclUIColorManager::getDefaultColorForElement(idDeclUIColor* originalColorPtr) {
//
//}

//void idDeclUIColorManager::applyHudColorsFromModSettings()
//{   
//
//
//    idList* idDeclUIColorListPtr = idDeclGlobalShellManager::getColorProfileColorsIdList();
//    if (!idDeclUIColorListPtr) {
//        logErr("applyHudColorsFromModSettings: idDeclUIColorListPtr is nullptr");       
//        return;
//    }  
//    idDeclUIColor* idDeclUIColorPtr = (idDeclUIColor*) idDeclUIColorListPtr->list;
//
//    for (size_t i = 0; i < idDeclUIColorListPtr->num; i++)
//    {      
//        applyUserSettingsToColorProfile(idDeclUIColorPtr);
//        idDeclUIColorPtr++;       
//    }
//}


//? we need an update func tion taht will be triggered in main t hat will check if current color profile index has changed and if yes will get the nuw idDeclUIColor ptr, then it will do all the checks made in GameHudColorsManager::getColor and that'sit.

//void idDeclUIColorManager::applyUserSettingsToColorProfile(idDeclUIColor* colorProfilePtr) {
//
//    if (!colorProfilePtr) return;
//
//    colorProfilePtr->bloodPunchSuperchargeBase.color = modSettings::ConvertIntToIdColor(modSettings::getOverrideBloodPunchColor1Int());
//
//    colorProfilePtr->bloodPunchSuperchargeGlow.color = modSettings::ConvertIntToIdColor(modSettings::getOverrideBloodPunchColor1Int());
//
//    colorProfilePtr->hudEquipmentFrag.color = modSettings::ConvertIntToIdColor(modSettings::getOverrideBloodPunchColor1Int());
//
//
//    originalColorPtr->hudEquipmentFrag = customColor.hudEquipmentFrag;
//    originalColorPtr->hudEquipmentFragIcon = customColor.hudEquipmentFragIcon;
//}


//void idDeclUIColorManager::updateCustomIdColors() {
//
//    colorOverrideBloodPunch1 = modSettings::ConvertIntToIdColor(modSettings::getOverrideBloodPunchColor1());
//    colorOverrideBloodPunch2 = modSettings::ConvertIntToIdColor(modSettings::getOverrideBloodPunchColor2());
//    colorFuel3Pip = modSettings::ConvertIntToIdColor(modSettings::getOverrideFuel3PipsColorInt());
//    colorFragGrenadeAvailable = modSettings::ConvertIntToIdColor(modSettings::getOverrideFragGrenadeAvailable_ColorInt());
//    colorFragGrenadeCoolDown = modSettings::ConvertIntToIdColor(modSettings::getOverrideFragGrenadeCoolDown_ColorInt());
//    colorIceGrenadeAvailable = modSettings::ConvertIntToIdColor(modSettings::getOverrideIceGrenadeAvailable__ColorInt());
//    colorIceGrenadeCoolDown = modSettings::ConvertIntToIdColor(modSettings::getOverrideIceGrenadeCoolDown_ColorInt());
//    colorWeaponBar = modSettings::ConvertIntToIdColor(modSettings::getWeaponBarColorInt());
//    colorRadMeterColor = modSettings::ConvertIntToIdColor(modSettings::getOverrideRadMeterColorInt());
//
//}

//void idDeclUIColorManager::updateHudColors() {  
//
//    static idDeclUIColor* lastidDeclUIColorPtr = nullptr;
//    static idPlayer* lastIdPlayerPtr = nullptr;
//    static uint64_t lastForcedUpdateMs = 0;
//
//    bool isForcedUpdateRequired = false;
//
//    if (!m_currentIdDeclUIColor) return;
//
//
//    if (m_currentIdDeclUIColor != lastidDeclUIColorPtr) {
//        lastidDeclUIColorPtr = m_currentIdDeclUIColor;
//        isForcedUpdateRequired = true;
//    }
//
//    if (K_Utils::EpochMillis() - lastForcedUpdateMs > 1000) {
//
//        lastForcedUpdateMs = K_Utils::EpochMillis();
//        isForcedUpdateRequired = true;
//    }
//
//
//    static int lastchainsawAmmo = idPlayer_K::getChainsawAmmo();
//    int chainsawAmmo = idPlayer_K::getChainsawAmmo();
//
//    if (chainsawAmmo != lastchainsawAmmo || isForcedUpdateRequired) {
//        lastchainsawAmmo = chainsawAmmo;
//
//        if (chainsawAmmo >= 3) {
//
//            m_currentIdDeclUIColor->weaponChaingunFull.color = colorFuel3Pip; 
//        }
//        else if (chainsawAmmo < 1) {
//            m_currentIdDeclUIColor->weaponChaingunFull.color = colorDkGrey;
//        }
//        else {
//            restoreColorsForHudElement(hudElementColorRef::fuel, m_currentIdDeclUIColor);
//        }
//    }  
//
//
//
//
//
//
//
//
//
//}





//void idDeclUIColorManager::restoreOriginalColorProfile(idDeclUIColor_Custom customColor, idDeclUIColor* originalColorPtr) {
//
//   if (!originalColorPtr) {
//        logErr("restoreOriginalColorProfile: originalColorPtr is nullptr returning");
//        return;
//   }
//
//    // Restore original colors from customColor to originalColorPtr
//    originalColorPtr->displayName = customColor.displayName;
//    originalColorPtr->isColorBlindProfile = customColor.isColorBlindProfile;
//    originalColorPtr->uiRadiation = customColor.uiRadiation;
//    originalColorPtr->uiRadiationGradient = customColor.uiRadiationGradient;
//    originalColorPtr->white = customColor.white;
//    originalColorPtr->weaponChainsaw = customColor.weaponChainsaw;
//    originalColorPtr->weaponShotgun = customColor.weaponShotgun;
//    originalColorPtr->weaponDoubleBarrel = customColor.weaponDoubleBarrel;
//    originalColorPtr->weaponAssualtRifle = customColor.weaponAssualtRifle;
//    originalColorPtr->weaponChaingun = customColor.weaponChaingun;
//    originalColorPtr->weaponPlasmaRifle = customColor.weaponPlasmaRifle;
//    originalColorPtr->weaponBallista = customColor.weaponBallista;
//    originalColorPtr->weaponRocketLauncher = customColor.weaponRocketLauncher;
//    originalColorPtr->weaponBfg = customColor.weaponBfg;
//    originalColorPtr->weaponUnmaykr = customColor.weaponUnmaykr;
//    originalColorPtr->weaponCrucible = customColor.weaponCrucible;
//    originalColorPtr->weaponHammer = customColor.weaponHammer;
//    originalColorPtr->weaponShotgunFull = customColor.weaponShotgunFull;
//    originalColorPtr->weaponDoubleBarrelFull = customColor.weaponDoubleBarrelFull;
//    originalColorPtr->weaponAssualtRifleFull = customColor.weaponAssualtRifleFull;
//    originalColorPtr->weaponChaingunFull = customColor.weaponChaingunFull;
//    originalColorPtr->weaponPlasmaRifleFull = customColor.weaponPlasmaRifleFull;
//    originalColorPtr->weaponBallistaFull = customColor.weaponBallistaFull;
//    originalColorPtr->weaponRocketLauncherFull = customColor.weaponRocketLauncherFull;
//    originalColorPtr->weaponBfgFull = customColor.weaponBfgFull;
//    originalColorPtr->weaponUnmaykrFull = customColor.weaponUnmaykrFull;
//    originalColorPtr->weaponHammerFull = customColor.weaponHammerFull;
//    originalColorPtr->reticleBase = customColor.reticleBase;
//    originalColorPtr->reticleGlow = customColor.reticleGlow;
//    originalColorPtr->hudEquipmentFrag = customColor.hudEquipmentFrag;
//    originalColorPtr->hudEquipmentFragIcon = customColor.hudEquipmentFragIcon;
//    originalColorPtr->hudEquipmentCyro = customColor.hudEquipmentCyro;
//    originalColorPtr->hudEquipmentCyroIcon = customColor.hudEquipmentCyroIcon;
//    originalColorPtr->hudEquipmentChainsaw = customColor.hudEquipmentChainsaw;
//    originalColorPtr->hudEquipmentChainsawIcon = customColor.hudEquipmentChainsawIcon;
//    originalColorPtr->bloodPunchSuperchargeBase = customColor.bloodPunchSuperchargeBase;
//    originalColorPtr->bloodPunchSuperchargeGlow = customColor.bloodPunchSuperchargeGlow;
//}