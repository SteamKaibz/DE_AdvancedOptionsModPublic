#include "modSettings.h"


modSettings& modSettings::getInstance() {
    static modSettings instance; // Create a static instance of modSettings
    return instance; // Return the reference to the singleton instance
}


void modSettings::loadSettings()
{
    std::string filePath = FileOp::getMainModSettingsFilePath();
    logInfo("loadSettings: loading file: %s", filePath.c_str());

    if (!std::filesystem::exists(filePath)) {
        logWarn("loadSettings: creating default settings file: %s", filePath.c_str());
        saveSettings();
        return;
    }

    // Attempt to open the file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        logErr("loadSettings: Failed to open file for reading: %s", filePath.c_str());
        return;
    }
   

    try {       
        nlohmann::json j;
        file >> j;  
       
        m_isFirstTimeModLaunch = j.value("m_isFirstTimeModLaunch", modSettingsDefault::defaultIsFirstTimeModLaunch);

        m_isUseDedicatedNadeKeys = j.value("m_isUseDedicatedNadeKeys", modSettingsDefault::defaultIsUseDedicatedNadeKeys);

        m_toggleModSettingsVkCode = j.value("m_toggleModSettingsVkCode", modSettingsDefault::defaultToggleModSettingsVkCode);
        m_modSettingsShortcutTextColorImU32 = j.value("m_modSettingsShortcutTextColorImU32", modSettingsDefault::defaultmodSettingsShortcutTextColorImU32);

        m_isDisableNewCampaignPopUp = j.value("m_isDisableNewCampaignPopUp", modSettingsDefault::defaultIsDisableNewCampaignPopUp);

        m_isDisableBatterySocketPopUp = j.value("m_isDisableBatterySocketPopUp", modSettingsDefault::defaultIsDisableBatterySocketPopUp);
        m_isSpeedUpBatterySocketAnimation = j.value("m_isSpeedUpBatterySocketAnimation", modSettingsDefault::defaultIsSpeedUpBatterySocketAnimation);

        m_isSkipCustomAnimations = j.value("m_isSkipCustomAnimations", modSettingsDefault::defaultIsSkipCustomAnimations);


        m_IsOverideInteractionFOV = j.value("m_IsOverideInteractionFOV", modSettingsDefault::defaultIsOverideInteractionFOV);
        m_interactionFOV = j.value("m_interactionFOV", modSettingsDefault::defaultInteractionFOV);


        m_assaultRiflePrecisionBoltMouseSens = j.value("m_assaultRiflePrecisionBoltMouseSens", modSettingsDefault::g_defaultPrecisionBoltMouseSens);
        m_assaultRiflePrecisionBoltControllerSens = j.value("m_assaultRiflePrecisionBoltControllerSens", modSettingsDefault::g_defaultPrecisionBoltControllerSens);
        m_ballistaArbalestMouseSens = j.value("m_ballistaArbalestMouseSens", modSettingsDefault::g_defaultBallistaArbalesteMouseSens);
        m_ballistaArbalestControllerSens = j.value("m_ballistaArbalestControllerSens", modSettingsDefault::g_defaultBallistaArbalesteControllerSens);

        m_isOverideShotgunConfig = j.value("m_isOverideShotgunConfig", modSettingsDefault::g_defaultIsOverideShotgunConfig);
        m_isRemoveBalistaZoom = j.value("m_isRemoveBalistaZoom", modSettingsDefault::g_defaultIsRemoveBalistaZoom);
        m_isImprovedWeaponSwitching = j.value("m_isImprovedWeaponSwitching", modSettingsDefault::g_defaultIsImprovedWeaponSwitchEnabled);
        m_isImprovedWeaponSwitchingBeep = j.value("m_isImprovedWeaponSwitchingBeep", modSettingsDefault::g_defaultIsImprovedWeaponSwitchBeep);      

        m_isGameFovUnlocked = j.value("m_isGameFovUnlocked", modSettingsDefault::g_defaultIsGameFovUnlocked);

        m_handsFOV = j.value("m_handsFOV", modSettingsDefault::g_defaultHandsFOV);

        m_reticleScale = j.value("m_reticleScale", Reticle::g_defaultReticleScale);

        m_immersiveCrosshairLevel = j.value("m_immersiveCrosshairLevel", modSettingsDefault::g_defaultImmersiveCrosshairLevel);


        //! CUSTOM CROSSHAIR
        m_useImGuiCustomDotCrosshair = j.value("m_useImGuiCustomDotCrosshair", modSettingsDefault::g_defaultUseImguiCustomDotCrosshair);
        m_imguiCustomDotCrosshairRadiusPix = j.value("m_imguiCustomDotCrosshairRadiusPix", modSettingsDefault::g_defaultimguiCustomDotCrosshairRadiusPix);
        m_customDotCrosshairColorImU32 = j.value("m_customDotCrosshairColorImU32", modSettingsDefault::g_defaultCustomDotCrosshairColorImU32);
        m_customDotCrosshairCooldownColorImU32 = j.value("m_customDotCrosshairCooldownColorImU32", modSettingsDefault::g_defaultCustomDotCrosshairCooldownColorImU32);
        m_customCrosshairIsShowHealthAsColor = j.value("m_customCrosshairIsShowHealthAsColor", modSettingsDefault::g_defaultCustomDotCrosshairIsShowHealthAsColor);


        //! CUSTOM HUD
        m_isUseKaibzHud = j.value("m_isUseKaibzHud", modSettingsDefault::g_defaultIsUseKaibzHud);
        m_eternalFontSize = j.value("m_eternalFontSize", modSettingsDefault::g_defaultEternalFontSize);
        m_robotoFontSize = j.value("m_robotoFontSize", modSettingsDefault::g_defaultRobotoFontSize);
        m_kaibzHudIconFontSize = j.value("m_kaibzHudIconFontSize", modSettingsDefault::g_defaultKaibzHudIconFontSize);
        m_kaibzHudOffsetX = j.value("m_kaibzHudOffsetX", modSettingsDefault::g_defaultHudOffsetInt);
        m_kaibzHudOffsetY = j.value("m_kaibzHudOffsetY", modSettingsDefault::g_defaultHudOffsetInt);
        m_kaibzHudFlags = j.value("m_kaibzHudFlags", modSettingsDefault::g_defaultHudFlags);
        m_kaibzHudIconExtraSpacingMul = j.value("m_kaibzHudIconExtraSpacingMul", modSettingsDefault::g_defaultIconExtraSpacingMul);
        m_kaibzHudBgOpacity = j.value("m_kaibzHudBgOpacity", modSettingsDefault::g_defaultKaibzHudBgOpacity);

        m_kaibzHudDisabledColorImU32 = j.value("m_kaibzHudDisabledColorImU32", modSettingsDefault::g_defaultkaibzHudDisabledColorImU32);
        m_kaibzHudCautionColorImU32 = j.value("m_kaibzHudCautionColorImU32", modSettingsDefault::g_defaultkaibzHudCautionColorImU32);
        m_kaibzHudWarningColorImU32 = j.value("m_kaibzHudWarningColorImU32", modSettingsDefault::g_defaultkaibzHudWarningColorImU32);
        m_kaibzHudCriticalColorImU32 = j.value("m_kaibzHudCriticalColorImU32", modSettingsDefault::g_defaultkaibzHudCriticalColorImU32);
        m_kaibzHudExtraLivesColorImU32 = j.value("m_kaibzHudExtraLivesColorImU32", modSettingsDefault::g_defaultkaibzHudExtraLivesColorImU32);
        m_kaibzHudBloodPunch1ColorImU32 = j.value("m_kaibzHudBloodPunch1ColorImU32", modSettingsDefault::g_defaultkaibzHudBloodPunch1ColorImU32);
        m_kaibzHudBloodPunch2ColorImU32 = j.value("m_kaibzHudBloodPunch2ColorImU32", modSettingsDefault::g_defaultkaibzHudBloodPunch2ColorImU32);
        m_kaibzHudBloodPunchDesperateColorImU32 = j.value("m_kaibzHudBloodPunchDesperateColorImU32", modSettingsDefault::g_defaultkaibzHudBloodPunchDesperateColorImU32);
        m_kaibzHudHealthMaxColorImU32 = j.value("m_kaibzHudHealthMaxColorImU32", modSettingsDefault::g_defaultkaibzHudHealthMaxColorImU32);
        m_kaibzHudHealthColorImU32 = j.value("m_kaibzHudHealthColorImU32", modSettingsDefault::g_defaultkaibzHudHealthColorImU32);
        m_kaibzHudArmorMaxColorImU32 = j.value("m_kaibzHudArmorMaxColorImU32", modSettingsDefault::g_defaultkaibzHudArmorMaxColorImU32);
        m_kaibzHudRadsuitColorImU32 = j.value("m_kaibzHudRadsuitColorImU32", modSettingsDefault::g_defaultkaibzHudRadsuitColorImU32);
        m_kaibzHudOxygenColorImU32 = j.value("m_kaibzHudOxygenColorImU32", modSettingsDefault::g_defaultkaibzHudOxygenColorImU32);
        m_kaibzHudAmmoColorImU32 = j.value("m_kaibzHudAmmoColorImU32", modSettingsDefault::g_defaultkaibzHudAmmoColorImU32);
        m_kaibzHudHammerCrucibleColorImU32 = j.value("m_kaibzHudHammerCrucibleColorImU32", modSettingsDefault::g_defaultkaibzHudHammerCrucibleColorImU32);
        m_kaibzHudFlameBelchColorImU32 = j.value("m_kaibzHudFlameBelchColorImU32", modSettingsDefault::g_defaultkaibzHudFlameBelchColorImU32);
        m_kaibzHudFuel1ColorImU32 = j.value("m_kaibzHudFuel1ColorImU32", modSettingsDefault::g_defaultkaibzHudFuel1ColorImU32);
        m_kaibzHudFuel2ColorImU32 = j.value("m_kaibzHudFuel2ColorImU32", modSettingsDefault::g_defaultkaibzHudFuel2ColorImU32);
        m_kaibzHudFuel3ColorImU32 = j.value("m_kaibzHudFuel3ColorImU32", modSettingsDefault::g_defaultkaibzHudFuel3ColorImU32);
        m_kaibzHudFrag1ColorImU32 = j.value("m_kaibzHudFrag1ColorImU32", modSettingsDefault::g_defaultkaibzHudFrag1ColorImU32);
        m_kaibzHudFrag2ColorImU32 = j.value("m_kaibzHudFrag2ColorImU32", modSettingsDefault::g_defaultkaibzHudFrag2ColorImU32);
        m_kaibzHudIceColorImU32 = j.value("m_kaibzHudIceColorImU32", modSettingsDefault::g_defaultkaibzHudIceColorImU32);
        m_kaibzHudIceCooldownColorImU32 = j.value("m_kaibzHudIceCooldownColorImU32", modSettingsDefault::g_defaultkaibzHudIceCooldownColorImU32);



        //! GAME HUD COLORS
        m_OverrideBloodPunchColor1 = j.value("m_OverrideBloodPunchColor1", modSettingsDefault::g_defaultOverrideBloodPunchColor1);
        m_OverrideBloodPunchColor2 = j.value("m_OverrideBloodPunchColor2", modSettingsDefault::g_defaultOverrideBloodPunchColor2);
        m_OverrideDesperatePunchColor = j.value("m_OverrideDesperatePunchColor", modSettingsDefault::g_defaultOverrideDesperatePunchColor);

        m_OverrideFuel3PipsColor = j.value("m_OverrideFuel3PipsColor", modSettingsDefault::g_defaultOverrideFuel3Pips_Color);

        m_OverrideFragGrenadeAvailable_Color = j.value("m_OverrideFragGrenadeAvailable_Color", modSettingsDefault::g_defaultOverrideFragGrenadeAvailable_Color);
        m_OverrideFragGrenadeCoolDown_Color = j.value("m_OverrideFragGrenadeCoolDown_Color", modSettingsDefault::g_defaultOverrideFragGrenadeCooldown_Color);

        m_OverrideIceGrenadeAvailable__Color = j.value("m_OverrideIceGrenadeAvailable__Color", modSettingsDefault::g_defaultOverrideIceGrenadeAvailable_Color);
        m_OverrideIceGrenadeCoolDown_Color = j.value("m_OverrideIceGrenadeCoolDown_Color", modSettingsDefault::g_defaultOverrideIceGrenadeCoolDown_Color);

        m_IsWeaponBarColored = j.value("m_IsWeaponBarColored", modSettingsDefault::g_defaultIsWeaponBarColored);
        m_OverrideRadMeterColor = j.value("m_OverrideRadMeterColor", modSettingsDefault::g_defaultOverrideRadMeterColor);

        m_isRemoveBindsReminderOnHud = j.value("m_isRemoveBindsReminderOnHud", modSettingsDefault::g_defaultIsRemoveBindsReminderOnHud);

        m_isDashBlurEffectDisabled = j.value("m_isDashBlurEffectDisabled", modSettingsDefault::g_defaultIsDashBlurEffectDisabled);
        m_isHitMarkerDisabled = j.value("m_isHitMarkerDisabled", modSettingsDefault::g_defaultIsHitMarkerDisabled);

        //m_isDebugMode = j.value("m_isDebugMode", modSettingsDefault::g_defaultisDebugMode);
        //m_isPlayModLoadedBeep = j.value("m_isPlayModLoadedBeep", modSettingsDefault::g_defaultIsSoundBeepWhenModLoaded);
       
        //! other settings
        m_isDisableAntiAliasing = j.value("m_isDisableAntiAliasing", modSettingsDefault::g_defaultIsDisableAntiAliasing);      
        m_isDisableMouseSmoothing = j.value("m_isDisableMouseSmoothing", modSettingsDefault::g_defaultIsDisableMouseSmoothing);
        m_isDisableBloom = j.value("m_isDisableBloom", modSettingsDefault::g_defaultIsDisableBloom);
        m_decalLifetimeMultiplier = j.value("m_decalLifetimeMultiplier", modSettingsDefault::g_defaultDecalLifetimeMultiplier);
        m_desaturate = j.value("m_desaturate", modSettingsDefault::g_defaultDesaturate);  
        //m_textureLodBias = j.value("m_textureLodBias", modSettingsDefault::g_defaultTextureLodBias);
        //m_isForceRainAnywhere = j.value("m_isForceRainAnywhere", modSettingsDefault::g_defaultForceRainAnywhere);
        //m_forceSnowAnywhere = j.value("m_forceSnowAnywhere", modSettingsDefault::g_defaultForceSnowAnywhere);
       

        //! gameplay settings:
        m_isForceAiHaste = j.value("m_isForceAiHaste", modSettingsDefault::g_defaultisForceAiHaste);

        //! mod settings
        m_isUseImgui = j.value("m_isUseImgui", modSettingsDefault::g_defaulIsUseImgui);
        m_isLogGameConsoleToLogFile = j.value("m_isLogGameConsoleToLogFile", modSettingsDefault::g_defaulIsLogConsoleToLogFile);

        //! debug:
        m_reloadImguiHooksKeyName = j.value("m_reloadImguiHooksKeyName", modSettingsDefault::g_defaultReloadImguiHooksKeyName);


    }
    catch (const nlohmann::json::parse_error& e) {
        logErr("loadSettings: JSON parsing error: %s ", e.what());

    }

    file.close();   
}

//? Btw: no you can not easily serialize the modSettings class, you have to do it member by member...
void modSettings::saveSettings()
{
    static bool isFirstTimeSave = true;
    static std::string lastSerializedData = "";

    std::string filePath = FileOp::getMainModSettingsFilePath();

    nlohmann::json j;

    j["m_isFirstTimeModLaunch"] = m_isFirstTimeModLaunch;

    j["m_isUseDedicatedNadeKeys"] = m_isUseDedicatedNadeKeys;

    j["m_toggleModSettingsVkCode"] = m_toggleModSettingsVkCode;
    j["m_modSettingsShortcutTextColorImU32"] = m_modSettingsShortcutTextColorImU32;

    j["m_isDisableNewCampaignPopUp"] = m_isDisableNewCampaignPopUp;

    j["m_isDisableBatterySocketPopUp"] = m_isDisableBatterySocketPopUp;
    j["m_isSpeedUpBatterySocketAnimation"] = m_isSpeedUpBatterySocketAnimation;

    j["m_isSkipCustomAnimations"] = m_isSkipCustomAnimations;

    j["m_IsOverideInteractionFOV"] = m_IsOverideInteractionFOV;
    j["m_interactionFOV"] = m_interactionFOV;


    j["m_assaultRiflePrecisionBoltMouseSens"] = m_assaultRiflePrecisionBoltMouseSens;
    j["m_assaultRiflePrecisionBoltControllerSens"] = m_assaultRiflePrecisionBoltControllerSens;
    j["m_ballistaArbalestMouseSens"] = m_ballistaArbalestMouseSens;
    j["m_ballistaArbalestControllerSens"] = m_ballistaArbalestControllerSens;
    j["m_isOverideShotgunConfig"] = m_isOverideShotgunConfig;
    j["m_isRemoveBalistaZoom"] = m_isRemoveBalistaZoom;
    j["m_isImprovedWeaponSwitching"] = m_isImprovedWeaponSwitching;
    j["m_isImprovedWeaponSwitchingBeep"] = m_isImprovedWeaponSwitchingBeep;

    j["m_isGameFovUnlocked"] = m_isGameFovUnlocked;
    j["m_handsFOV"] = m_handsFOV;
    j["m_reticleScale"] = m_reticleScale;
    j["m_immersiveCrosshairLevel"] = m_immersiveCrosshairLevel;

    //! CUSTOM CROSSHAIR
    j["m_useImGuiCustomDotCrosshair"] = m_useImGuiCustomDotCrosshair;
    j["m_customDotCrosshairColorImU32"] = m_customDotCrosshairColorImU32;
    j["m_customDotCrosshairCooldownColorImU32"] = m_customDotCrosshairCooldownColorImU32;
    j["m_imguiCustomDotCrosshairRadiusPix"] = m_imguiCustomDotCrosshairRadiusPix;
    j["m_customCrosshairIsShowHealthAsColor"] = m_customCrosshairIsShowHealthAsColor;

    //! CUSTOM HUD
    j["m_isUseKaibzHud"] = m_isUseKaibzHud;
    j["m_eternalFontSize"] = m_eternalFontSize;
    j["m_robotoFontSize"] = m_robotoFontSize;
    j["m_kaibzHudIconFontSize"] = m_kaibzHudIconFontSize;
    j["m_kaibzHudOffsetX"] = m_kaibzHudOffsetX;
    j["m_kaibzHudOffsetY"] = m_kaibzHudOffsetY;
    j["m_kaibzHudFlags"] = m_kaibzHudFlags;
    j["m_kaibzHudIconExtraSpacingMul"] = m_kaibzHudIconExtraSpacingMul;
    j["m_kaibzHudBgOpacity"] = m_kaibzHudBgOpacity;


    j["m_kaibzHudDisabledColorImU32"] = m_kaibzHudDisabledColorImU32;
    j["m_kaibzHudCautionColorImU32"] = m_kaibzHudCautionColorImU32;
    j["m_kaibzHudWarningColorImU32"] = m_kaibzHudWarningColorImU32;
    j["m_kaibzHudCriticalColorImU32"] = m_kaibzHudCriticalColorImU32;
    j["m_kaibzHudExtraLivesColorImU32"] = m_kaibzHudExtraLivesColorImU32;
    j["m_kaibzHudBloodPunch1ColorImU32"] = m_kaibzHudBloodPunch1ColorImU32;
    j["m_kaibzHudBloodPunch2ColorImU32"] = m_kaibzHudBloodPunch2ColorImU32;
    j["m_kaibzHudBloodPunchDesperateColorImU32"] = m_kaibzHudBloodPunchDesperateColorImU32;
    j["m_kaibzHudHealthMaxColorImU32"] = m_kaibzHudHealthMaxColorImU32;
    j["m_kaibzHudHealthColorImU32"] = m_kaibzHudHealthColorImU32;
    j["m_kaibzHudArmorMaxColorImU32"] = m_kaibzHudArmorMaxColorImU32;
    j["m_kaibzHudRadsuitColorImU32"] = m_kaibzHudRadsuitColorImU32;
    j["m_kaibzHudOxygenColorImU32"] = m_kaibzHudOxygenColorImU32;
    j["m_kaibzHudAmmoColorImU32"] = m_kaibzHudAmmoColorImU32;
    j["m_kaibzHudHammerCrucibleColorImU32"] = m_kaibzHudHammerCrucibleColorImU32;
    j["m_kaibzHudFlameBelchColorImU32"] = m_kaibzHudFlameBelchColorImU32;
    j["m_kaibzHudFuel1ColorImU32"] = m_kaibzHudFuel1ColorImU32;
    j["m_kaibzHudFuel2ColorImU32"] = m_kaibzHudFuel2ColorImU32;
    j["m_kaibzHudFuel3ColorImU32"] = m_kaibzHudFuel3ColorImU32;
    j["m_kaibzHudFrag1ColorImU32"] = m_kaibzHudFrag1ColorImU32;
    j["m_kaibzHudFrag2ColorImU32"] = m_kaibzHudFrag2ColorImU32;
    j["m_kaibzHudIceColorImU32"] = m_kaibzHudIceColorImU32;
    j["m_kaibzHudIceCooldownColorImU32"] = m_kaibzHudIceCooldownColorImU32;



    //! GAME HUD COLORS
    j["m_OverrideBloodPunchColor1"] = m_OverrideBloodPunchColor1;
    j["m_OverrideBloodPunchColor2"] = m_OverrideBloodPunchColor2;
    j["m_OverrideDesperatePunchColor"] = m_OverrideDesperatePunchColor;
    j["m_OverrideFuel3PipsColor"] = m_OverrideFuel3PipsColor;
    j["m_OverrideFragGrenadeAvailable_Color"] = m_OverrideFragGrenadeAvailable_Color;
    j["m_OverrideFragGrenadeCoolDown_Color"] = m_OverrideFragGrenadeCoolDown_Color;
    j["m_OverrideIceGrenadeAvailable__Color"] = m_OverrideIceGrenadeAvailable__Color;
    j["m_OverrideIceGrenadeCoolDown_Color"] = m_OverrideIceGrenadeCoolDown_Color;
    j["m_IsWeaponBarColored"] = m_IsWeaponBarColored;
    j["m_OverrideRadMeterColor"] = m_OverrideRadMeterColor;
    j["m_isRemoveBindsReminderOnHud"] = m_isRemoveBindsReminderOnHud;
    j["m_isDashBlurEffectDisabled"] = m_isDashBlurEffectDisabled;
    j["m_isHitMarkerDisabled"] = m_isHitMarkerDisabled;

    //! gameplay settings:
    j["m_isForceAiHaste"] = m_isForceAiHaste;



    //! other settings
    j["m_isDisableAntiAliasing"] = m_isDisableAntiAliasing;
    j["m_isDisableMouseSmoothing"] = m_isDisableMouseSmoothing;
    j["m_isDisableBloom"] = m_isDisableBloom;
    j["m_decalLifetimeMultiplier"] = m_decalLifetimeMultiplier;
    j["m_desaturate"] = m_desaturate;
    //j["m_textureLodBias"] = m_textureLodBias;
    //j["m_isForceRainAnywhere"] = m_isForceRainAnywhere;
    //j["m_forceSnowAnywhere"] = m_forceSnowAnywhere; 




    //! mod settings   
    j["m_isUseImgui"] = m_isUseImgui;
    j["m_isLogGameConsoleToLogFile"] = m_isLogGameConsoleToLogFile;


    //! mod debug
    j["m_reloadImguiHooksKeyName"] = m_reloadImguiHooksKeyName;
    //j["m_isDebugMode"] = m_isDebugMode;
   //j["m_isPlayModLoadedBeep"] = m_isPlayModLoadedBeep;


    // Serialize JSON to string
    std::string serializedData = j.dump(4);

    if (serializedData != lastSerializedData) {

        if (lastSerializedData == "") {           
            logModSettings("First time save");
        }
        else {//! first time saving
            logModSettings("Settings have changed");
        }

        // Write JSON to file
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << j.dump(4);
            file.close();
        }

        lastSerializedData = serializedData;

        if (isFirstTimeSave) {
            logInfo("saveSettings: mod settings filePath: %s", filePath.c_str());
            isFirstTimeSave = false;
        }
    }
}






void modSettings::apply()
{
    idCmd::skipHudBtnsCallOut(getIsRemoveBindsReminderOnHud());

    idCmd::setHandsFov(getHandsFOV());

    idCmd::setMinMaxFov(getIsGameFovMenuUnlocked());

    idFxManager::setDashEffect(! getIsDisabledDashBlurEffect());

    idDeclGlobalShellManager::disableNewCampaignPopUp(getIsDisableNewCampaignPopUp());   
   
    idCmd::setMouseSmoothing(GetIsDisableMouseSmoothing());

    idCmd::setHdrBloom(GetIsDisableBloom());

    idCmd::setDecalLifetimeMultiplier(GetDecalLifetimeMultiplier());

    idCmd::setDesaturate(GetDesaturate());

    idCmd::setIsForceAiHaste(GetIsForceAiHaste());



    //! FIRST TIME MOD LAUNCH SETTING:

    if (getIsFirstTimeModLaunch()) {
        logWarn("mod launching for the first time! (will be true as long as user does not go in mod menu at least once): ");

       
        idDeclUIColorManager::setKaibzHudColorsToGameColorProfile(); //! custom hud colors
      

    }
    else {

        Menu::initKaibzHudColors(); //! custom hud colors
        
    }
    setIsFirstTimeModLaunch(false); 


    WeaponSettings::overwriteDeclWeaponsWithUserSettings();   

    UserColorSet::Update();

    ColorManager::reapplySwfColors();
}



//void modSettings::update(bool isShowModMenu)
//{
//    //static bool isFirstTime = true;
//    static bool lastIsShowMenu = false;
//
//    if (isShowModMenu != lastIsShowMenu) {
//
//        if (isShowModMenu) {
//            loadFile(); //! going in menu
//        }
//        else {
//            saveFile(); //! leaving menu
//        }
//
//        lastIsShowMenu = isShowModMenu;
//    }
//}



bool modSettings::getIsFirstTimeModLaunch()  {
    return m_isFirstTimeModLaunch;
}

void modSettings::setIsFirstTimeModLaunch(bool value) {
    m_isFirstTimeModLaunch = value;
}


bool modSettings::getIsUseDedicatedNadeKeys()  {
    return m_isUseDedicatedNadeKeys;
}

void modSettings::setIsUseDedicatedNadeKeys(bool value) {
    m_isUseDedicatedNadeKeys = value;
}

unsigned int modSettings::getToggleModSettingsVkCode() {
    return m_toggleModSettingsVkCode;
}

void modSettings::setToggleModSettingsVkCode(unsigned int vkcode) {
    m_toggleModSettingsVkCode = vkcode;
}


ImU32 modSettings::getModSettingsShortcutTextColorImU32()
{
    return m_modSettingsShortcutTextColorImU32;
}

void modSettings::setModSettingsShortcutTextColorImU32(ImU32 value)
{
    m_modSettingsShortcutTextColorImU32 = value;
}


bool modSettings::getIsDisableNewCampaignPopUp() {
    return m_isDisableNewCampaignPopUp;
}

void modSettings::setIsDisableNewCampaignPopUp(bool value) {
    m_isDisableNewCampaignPopUp = value;
}


bool modSettings::getIsDisableBatterySocketPopUp() {
    return m_isDisableBatterySocketPopUp;
}

void modSettings::setIsDisableBatterySocketPopUp(bool value) {
    m_isDisableBatterySocketPopUp = value;
}

bool modSettings::getIsSpeedUpBatterySocketAnimation() {
    return m_isSpeedUpBatterySocketAnimation;
}

void modSettings::setIsSpeedUpBatterySocketAnimation(bool value) {
    m_isSpeedUpBatterySocketAnimation = value;
}


bool modSettings::getIsSkipCustomAnimations()
{
    return m_isSkipCustomAnimations;
}

void modSettings::setIsSkipCustomAnimations(bool value)
{
    m_isSkipCustomAnimations = value;
}


bool modSettings::getIsOverideInteractionFOV()
{
    return m_IsOverideInteractionFOV;
}

void modSettings::setIsOverideInteractionFOV(bool value)
{
    m_IsOverideInteractionFOV = value;
}


float modSettings::getInteractionFOV()
{
    return m_interactionFOV;
}
void modSettings::setInteractionFOV(float value)
{
    m_interactionFOV = value;
}




float modSettings::getAssaultRiflePrecisionBoltMouseSens() {
	return m_assaultRiflePrecisionBoltMouseSens;
}

void modSettings::setAssaultRiflePrecisionBoltMouseSens(float value)
{
    m_assaultRiflePrecisionBoltMouseSens = value;
}

float modSettings::getAssaultRiflePrecisionBoltControllerSens() {
	return m_assaultRiflePrecisionBoltControllerSens;
}

void modSettings::setAssaultRiflePrecisionBoltControllerSens(float value)
{
    m_assaultRiflePrecisionBoltControllerSens = value;
}

float modSettings::getBallistaArbalestMouseSens() {
	return m_ballistaArbalestMouseSens;
}

void modSettings::setBallistaArbalestMouseSens(float value)
{
    m_ballistaArbalestMouseSens = value;
}

float modSettings::getBallistaArbalestControllerSens() {
	return m_ballistaArbalestControllerSens;
}

void modSettings::setBallistaArbalestControllerSens(float value)
{
    m_ballistaArbalestControllerSens = value;
}



//bool modSettings::isPlayModLoadedBeep() {
//	return m_isPlayModLoadedBeep;
//}
//
//void modSettings::setIsPlayModLoadedBeep(bool value)
//{
//    m_isPlayModLoadedBeep = value;
//}

bool modSettings::isOverideShotgunConfig() {
	return m_isOverideShotgunConfig;
}

void modSettings::setIsOverideShotgunConfig(bool value)
{
    m_isOverideShotgunConfig = value;
}


bool modSettings::isRemoveBalistaZoom() {
	return m_isRemoveBalistaZoom;
}
void modSettings::setIsRemoveBalistaZoom(bool value)
{
    m_isRemoveBalistaZoom = value;
}


bool modSettings::isImprovedWeaponSwitching() {
	return m_isImprovedWeaponSwitching;
}

void modSettings::setIsImprovedWeaponSwitching(bool value)
{
    m_isImprovedWeaponSwitching = value;
}


bool modSettings::isImprovedWeaponSwitchingBeep() {
	return m_isImprovedWeaponSwitchingBeep;
}

void modSettings::setIsImprovedWeaponSwitchingBeep(bool value) {
    m_isImprovedWeaponSwitchingBeep = value;
}


//unsigned int modSettings::getReloadModSettingsFileVkCode() {
//	return m_reloadModSettingsFileVkCode;
//}

//bool modSettings::isIniFileAutoReload() {
//	return m_isIniFileAutoReload;
//}

bool modSettings::getIsGameFovMenuUnlocked() {
    return m_isGameFovUnlocked;
}

void modSettings::setIsGameFovMenuUnlocked(bool value)
{
    m_isGameFovUnlocked = value;
}



//int modSettings::getGameUiSettingsMinFov() {
//	return m_gameUiSettingsMinFov;
//}
//
//int modSettings::getGameUiSettingsMaxFov() {
//	return m_gameUiSettingsMaxFov;
//}

int modSettings::getHandsFOV() {
	return m_handsFOV;
}

void modSettings::setHandsFOV(int value) {
    m_handsFOV = value;
}


float modSettings::getReticleScale() {
	return m_reticleScale;
}

void modSettings::setReticleScale(float value)
{
    m_reticleScale = value;
}


void modSettings::setImmersiveCrosshairLevel(int level) {
    m_immersiveCrosshairLevel = (int)level;
}

ImmersiveCrosshairLevel modSettings::getImmersiveCrosshairLevel() {
	if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::NO_IMMERSIVE_CROSSHAIR) {
		return ImmersiveCrosshairLevel::NO_IMMERSIVE_CROSSHAIR;
	}
	else if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ADS) {
		return ImmersiveCrosshairLevel::HAR_ADS;
	}
	else if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ADS_BALISTA_ADS) {
		return ImmersiveCrosshairLevel::HAR_ADS_BALISTA_ADS;
	}
	else if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ADS_BALISTA_BOTH) {
		return ImmersiveCrosshairLevel::HAR_ADS_BALISTA_BOTH;
	}
	return ImmersiveCrosshairLevel::NO_IMMERSIVE_CROSSHAIR;
}



//! CUSTOM CROSSHAIR
bool modSettings::getIsUseImguiDotCrosshair() {
    return m_useImGuiCustomDotCrosshair;
}

void modSettings::setIsUseImguiDotCrosshair(bool value) {
    m_useImGuiCustomDotCrosshair = value;
}


ImU32 modSettings::getCustomDotCrosshairColorImU32()
{
    return m_customDotCrosshairColorImU32;
}

void modSettings::setCustomDotCrosshairColorImU32(ImU32 packedValue)
{
    m_customDotCrosshairColorImU32 = packedValue;
}

ImU32 modSettings::getCustomDotCrosshairCooldownColorImU32()
{
    return m_customDotCrosshairCooldownColorImU32;
}

void modSettings::setCustomDotCrosshairCooldownColorImU32(ImU32 packedValue)
{
    m_customDotCrosshairCooldownColorImU32 = packedValue;
}

float modSettings::getImguiCustomDotCrosshairRadiusPix() {
    return  m_imguiCustomDotCrosshairRadiusPix;        
}

void modSettings::setImguiCustomDotCrosshairRadiusPix(float value) {
    m_imguiCustomDotCrosshairRadiusPix = value;
}

bool modSettings::getCustomCrosshairIsShowHealthAsColor() {
    return m_customCrosshairIsShowHealthAsColor;
}

void modSettings::setCustomCrosshairIsShowHealthAsColor(bool value) {
    m_customCrosshairIsShowHealthAsColor = value;
}






//! Kaibz Hud:
//! 
bool modSettings::getIsUseKaibzHud() {
    return m_isUseKaibzHud;
}

void modSettings::setIsUseKaibzHud(bool value) {
    m_isUseKaibzHud = value;
}



float modSettings::getRobotoFontSize() {
    return m_robotoFontSize;
}

void modSettings::setRobotoFontSize(float value) {
    m_robotoFontSize = value;
}


float modSettings::getEternalFontSize() {
    return m_eternalFontSize;
}

void modSettings::setEternalFontSize(float fontSize) {
    m_eternalFontSize = fontSize;
}


float modSettings::getKaibzHudIconFontSize() {
    return m_kaibzHudIconFontSize;
}

void modSettings::setKaibzHudIconFontSize(float fontSize) {
    m_kaibzHudIconFontSize = fontSize;
}


int modSettings::getKaibzHudOffsetX()  {
    return m_kaibzHudOffsetX;
}

void modSettings::setKaibzHudOffsetX(int value) {
    m_kaibzHudOffsetX = value;
}

int modSettings::getKaibzHudOffsetY()  {
    return m_kaibzHudOffsetY;
}

void modSettings::setKaibzHudOffsetY(int value) {
    m_kaibzHudOffsetY = value;
}

float modSettings::getKaibzHudIconExtraSpacingMul() {
    return m_kaibzHudIconExtraSpacingMul;
}

void modSettings::setKaibzHudIconExtraSpacingMul(float value) {
    m_kaibzHudIconExtraSpacingMul = value;
}


float modSettings::getKaibzHudBgOpacity() {
    return m_kaibzHudBgOpacity;
}

void modSettings::setKaibzHudBgOpacity(float opacity) {
    m_kaibzHudBgOpacity = opacity;
}



void modSettings::setFlag(KaibzHudFlag flag, bool value) {
    if (value) {
        // Set the bit corresponding to the flag
        m_kaibzHudFlags |= static_cast<uint64_t>(flag);
    }
    else {
        // Clear the bit corresponding to the flag
        m_kaibzHudFlags &= ~static_cast<uint64_t>(flag);
    }
}

bool modSettings::getFlag(KaibzHudFlag flag) {
    // Check if the bit corresponding to the flag is set
    return (m_kaibzHudFlags & static_cast<uint64_t>(flag)) != 0;
}


//std::string modSettings::debuGetFlagString() {
//
//    std::map<KaibzHudFlag, std::string> flagNames = {
//        {KaibzHudFlag::ShowNumbers, "ShowNumbers"},
//        {KaibzHudFlag::ShowExtraLives, "ShowExtraLives"},
//        {KaibzHudFlag::ShowBloodPunch, "ShowBloodPunch"},
//        {KaibzHudFlag::ShowRadsuitOrOxygen, "ShowRadsuitOrOxygen"},
//        {KaibzHudFlag::ShowBasics, "ShowBasics"},      
//        {KaibzHudFlag::ShowHammerOrCrucible, "ShowHammerOrCrucible"},
//        {KaibzHudFlag::ShowFlameBelch, "ShowFlameBelch"},
//        {KaibzHudFlag::ShowFuel, "ShowFuel"},
//        {KaibzHudFlag::ShowFrag, "ShowFrag"},
//        {KaibzHudFlag::ShowIce, "ShowIce"}
//    };
//
//    std::string result;
//    for (auto const& pair : flagNames) {
//        if (static_cast<uint64_t>(m_kaibzHudFlags) & static_cast<uint64_t>(pair.first)) {
//            if (!result.empty()) {
//                result += ", ";
//            }
//            result += pair.second;
//        }
//    }
//    return result;
//}



ImU32 modSettings::getKaibzHudDisabledColorImU32() {
    return m_kaibzHudDisabledColorImU32;
}

void modSettings::setKaibzHudDisabledColorImU32(ImU32 color) {
    m_kaibzHudDisabledColorImU32 = color;
}


ImU32 modSettings::getKaibzHudCautionColorImU32() {
    return m_kaibzHudCautionColorImU32;
}

void modSettings::setKaibzHudCautionColorImU32(ImU32 value) {
    m_kaibzHudCautionColorImU32 = value;
}


ImU32 modSettings::getKaibzHudWarningColorImU32() {
    return m_kaibzHudWarningColorImU32;
}

void modSettings::setKaibzHudWarningColorImU32(ImU32 color) {
    m_kaibzHudWarningColorImU32 = color;
}


ImU32 modSettings::getKaibzHudCriticalColorImU32() {
    return m_kaibzHudCriticalColorImU32;
}

void modSettings::setKaibzHudCriticalColorImU32(ImU32 color) {
    m_kaibzHudCriticalColorImU32 = color;
}


ImU32 modSettings::getKaibzHudExtraLivesColorImU32() {
    return m_kaibzHudExtraLivesColorImU32;
}

void modSettings::setKaibzHudExtraLivesColorImU32(ImU32 color) {
    m_kaibzHudExtraLivesColorImU32 = color;
}


ImU32 modSettings::getKaibzHudBloodPunch1ColorImU32() {
    return m_kaibzHudBloodPunch1ColorImU32;
}

void modSettings::setKaibzHudBloodPunch1ColorImU32(ImU32 color) {
    m_kaibzHudBloodPunch1ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudBloodPunch2ColorImU32() {
    return m_kaibzHudBloodPunch2ColorImU32;
}

void modSettings::setKaibzHudBloodPunch2ColorImU32(ImU32 color) {
    m_kaibzHudBloodPunch2ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudBloodPunchDesperateColorImU32() {
    return m_kaibzHudBloodPunchDesperateColorImU32;
}

void modSettings::setKaibzHudBloodPunchDesperateColorImU32(ImU32 color) {
    m_kaibzHudBloodPunchDesperateColorImU32 = color;
}


ImU32 modSettings::getKaibzHudHealthMaxColorImU32() {
    return m_kaibzHudHealthMaxColorImU32;
}

void modSettings::setKaibzHudHealthMaxColorImU32(ImU32 color) {
    m_kaibzHudHealthMaxColorImU32 = color;
}


ImU32 modSettings::getKaibzHudHealthColorImU32() {
    return m_kaibzHudHealthColorImU32;
}

void modSettings::setKaibzHudHealthColorImU32(ImU32 color) {
    m_kaibzHudHealthColorImU32 = color;
}


ImU32 modSettings::getKaibzHudArmorMaxColorImU32() {
    return m_kaibzHudArmorMaxColorImU32;
}

void modSettings::setKaibzHudArmorMaxColorImU32(ImU32 color) {
    m_kaibzHudArmorMaxColorImU32 = color;
}


ImU32 modSettings::getKaibzHudArmorColorImU32() {
    return m_kaibzHudArmorColorImU32;
}

void modSettings::setKaibzHudArmorColorImU32(ImU32 color) {
    m_kaibzHudArmorColorImU32 = color;
}


ImU32 modSettings::getKaibzHudRadsuitColorImU32() {
    return m_kaibzHudRadsuitColorImU32;
}

void modSettings::setKaibzHudRadsuitColorImU32(ImU32 color) {
    m_kaibzHudRadsuitColorImU32 = color;
}


ImU32 modSettings::getKaibzHudOxygenColorImU32() {
    return m_kaibzHudOxygenColorImU32;
}

void modSettings::setKaibzHudOxygenColorImU32(ImU32 color) {
    m_kaibzHudOxygenColorImU32 = color;
}


ImU32 modSettings::getKaibzHudAmmoColorImU32() {
    return m_kaibzHudAmmoColorImU32;
}

void modSettings::setKaibzHudAmmoColorImU32(ImU32 color) {
    m_kaibzHudAmmoColorImU32 = color;
}


ImU32 modSettings::getKaibzHudHammerCrucibleColorImU32() {
    return m_kaibzHudHammerCrucibleColorImU32;
}

void modSettings::setKaibzHudHammerCrucibleColorImU32(ImU32 color) {
    m_kaibzHudHammerCrucibleColorImU32 = color;
}


ImU32 modSettings::getKaibzHudFlameBelchColorImU32() {
    return m_kaibzHudFlameBelchColorImU32;
}

void modSettings::setKaibzHudFlameBelchColorImU32(ImU32 color) {
    m_kaibzHudFlameBelchColorImU32 = color;
}


ImU32 modSettings::getKaibzHudFuel1ColorImU32() {
    return m_kaibzHudFuel1ColorImU32;
}

void modSettings::setKaibzHudFuel1ColorImU32(ImU32 color) {
    m_kaibzHudFuel1ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudFuel2ColorImU32() {
    return m_kaibzHudFuel2ColorImU32;
}

void modSettings::setKaibzHudFuel2ColorImU32(ImU32 color) {
    m_kaibzHudFuel2ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudFuel3ColorImU32() {
    return m_kaibzHudFuel3ColorImU32;
}

void modSettings::setKaibzHudFuel3ColorImU32(ImU32 color) {
    m_kaibzHudFuel3ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudFrag1ColorImU32() {
    return m_kaibzHudFrag1ColorImU32;
}

void modSettings::setKaibzHudFrag1ColorImU32(ImU32 color) {
    m_kaibzHudFrag1ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudFrag2ColorImU32() {
    return m_kaibzHudFrag2ColorImU32;
}

void modSettings::setKaibzHudFrag2ColorImU32(ImU32 color) {
    m_kaibzHudFrag2ColorImU32 = color;
}


ImU32 modSettings::getKaibzHudIceColorImU32() {
    return m_kaibzHudIceColorImU32;
}

void modSettings::setKaibzHudIceColorImU32(ImU32 color) {
    m_kaibzHudIceColorImU32 = color;
}


ImU32 modSettings::getkaibzHudIceCooldownColorImU32() {
    return m_kaibzHudIceCooldownColorImU32;
}

void modSettings::setkaibzHudIceCooldownColorImU32(ImU32 color) {
    m_kaibzHudIceCooldownColorImU32 = color;
}









//! helper
bool modSettings::isImmersiveCrosshairModeEnabled() {
	return (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ADS || m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ADS_BALISTA_BOTH || m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ADS_BALISTA_ADS);
}




int modSettings::getOverrideBloodPunchColor1() {
    return m_OverrideBloodPunchColor1;
}

void modSettings::setOverrideBloodPunchColor1(int value) {
    m_OverrideBloodPunchColor1 = value;
}

int modSettings::getOverrideBloodPunchColor2() {
    return m_OverrideBloodPunchColor2;
}

void modSettings::setOverrideBloodPunchColor2(int value) {
    m_OverrideBloodPunchColor2 = value;
}

int modSettings::getOverrideDesperatePunchColor() {
    return m_OverrideDesperatePunchColor;
}

void modSettings::setOverrideDesperatePunchColor(int value) {
    m_OverrideDesperatePunchColor = value;
}

int modSettings::getOverrideFuel3PipsColor() {
    return m_OverrideFuel3PipsColor;
}

void modSettings::setOverrideFuel3PipsColor(int value) {
    m_OverrideFuel3PipsColor = value;
}

int modSettings::getOverrideFragGrenadeColor() {
    return m_OverrideFragGrenadeAvailable_Color;
}

void modSettings::setOverrideFragGrenadeColor(int value) {
    m_OverrideFragGrenadeAvailable_Color = value;
}

int modSettings::getOverrideFragGrenadeCooldownColor() {
    return m_OverrideFragGrenadeCoolDown_Color;
}

void modSettings::setOverrideFragGrenadeCooldownColor(int value) {
    m_OverrideFragGrenadeCoolDown_Color = value;
}

int modSettings::getOverrideIceGrenadeColor() {
    return m_OverrideIceGrenadeAvailable__Color;
}

void modSettings::setOverrideIceGrenadeColor(int value) {
    m_OverrideIceGrenadeAvailable__Color = value;
}

int modSettings::getOverrideIceGrenadeCooldownColor() {
    return m_OverrideIceGrenadeCoolDown_Color;
}

void modSettings::setOverrideIceGrenadeCooldownColor(int value) {
    m_OverrideIceGrenadeCoolDown_Color = value;
}

bool modSettings::getIsWeaponBarColored() {
    return m_IsWeaponBarColored;
}

void modSettings::setIsWeaponBarColored(bool value) {
    m_IsWeaponBarColored = value;
}

int modSettings::getOverrideRadMeterColor() {
    return m_OverrideRadMeterColor;
}

void modSettings::setOverrideRadMeterColor(int value) {
    m_OverrideRadMeterColor = value;
}


void modSettings::resetGameHudColorsToDefault() {

    int defaultColorInt = (int)SWF_CUSTOM_NAMED_COLOR_DEFAULT;

    modSettings::setOverrideBloodPunchColor1(defaultColorInt);
    modSettings::setOverrideBloodPunchColor2(defaultColorInt);
    modSettings::setOverrideDesperatePunchColor(defaultColorInt);
    modSettings::setOverrideFuel3PipsColor(defaultColorInt);
    modSettings::setOverrideFragGrenadeColor(defaultColorInt);
    modSettings::setOverrideFragGrenadeCooldownColor(defaultColorInt);
    modSettings::setOverrideIceGrenadeColor(defaultColorInt);
    modSettings::setOverrideIceGrenadeCooldownColor(defaultColorInt);
    modSettings::setOverrideRadMeterColor(defaultColorInt);

    modSettings::setIsWeaponBarColored(true);
}




bool modSettings::getIsRemoveBindsReminderOnHud() {
	return m_isRemoveBindsReminderOnHud;
}

void modSettings::setIsRemoveBindsReminderOnHud(bool value) {
    m_isRemoveBindsReminderOnHud = value;
}

bool modSettings::getIsDisabledDashBlurEffect() {
	return m_isDashBlurEffectDisabled;
}

void modSettings::setIsDisabledDashBlurEffect(bool value)
{
    m_isDashBlurEffectDisabled = value;
}

HitMarkerState modSettings::getIsDisableHitMarker() {
	return (HitMarkerState)m_isHitMarkerDisabled;
}
void modSettings::setIsDisableHitMarker(bool value) {
    m_isHitMarkerDisabled = value;
}




//! more settings:

bool modSettings::getIsDisableAA()
{
    return m_isDisableAntiAliasing;
}

void modSettings::setIsDisableAA(bool value)
{
    m_isDisableAntiAliasing = value;
}




bool modSettings::GetIsDisableMouseSmoothing()  {
    return m_isDisableMouseSmoothing;
}          

void modSettings::SetIsDisableMouseSmoothing(bool value) {
    m_isDisableMouseSmoothing = value;
}


bool modSettings::GetIsDisableBloom()  {
    return m_isDisableBloom;
}

void modSettings::SetIsDisableBloom(bool value) {
    m_isDisableBloom = value;
}

//int modSettings::GetTextureLodBias()  {
//    return m_textureLodBias;
//}
//
//void modSettings::SetTextureLodBias(int value) {
//    m_textureLodBias = value;
//}

int modSettings::GetDecalLifetimeMultiplier()  {
    return m_decalLifetimeMultiplier;
}

void modSettings::SetDecalLifetimeMultiplier(int value) {
    m_decalLifetimeMultiplier = value;
}

float modSettings::GetDesaturate()  {
    return m_desaturate;
}

void modSettings::SetDesaturate(float value) {
    m_desaturate = value;
}

//bool modSettings::GetIsForceRainAnywhere()  {
//    return m_isForceRainAnywhere;
//}
//
//void modSettings::SetIsForceRainAnywhere(bool value) {
//    m_isForceRainAnywhere = value;
//}
//
//int modSettings::GetForceSnowAnywhere()  {
//    return m_forceSnowAnywhere;
//}
//
//void modSettings::SetForceSnowAnywhere(int value) {
//    m_forceSnowAnywhere = value;
//}

//! Gameplay
bool modSettings::GetIsForceAiHaste()  {
    logInfo("GetIsForceAiHaste: m_isForceAiHaste is: %d", m_isForceAiHaste);
    return m_isForceAiHaste;
}

void modSettings::SetIsForceAiHaste(bool value) {

    if (value != m_isForceAiHaste) {
        logWarn("SetIsForceAiHaste: debug: setting m_isForceAiHaste to: %d", value);
    }
    m_isForceAiHaste = value;
}





//! mod settings:
bool modSettings::getIsUseImgui()
{
    return m_isUseImgui;
}

//? not used atm
bool modSettings::isLogConsoleToLogFile()
{
    return m_isLogGameConsoleToLogFile;
}

void modSettings::setIsLogConsoleToLogFile(bool isLogConsole)
{
    m_isLogGameConsoleToLogFile = isLogConsole;
}

unsigned int modSettings::getReloadImguiHooksVk_Key()
{
    if (m_reloadImguiHooksVk_Key == 0) {
        modSettings::setReloadImguiHooksVkKey();
    }
    return m_reloadImguiHooksVk_Key;
}

//void modSettings::setReloadImguiHooksVk_Key(std::string keyName)
//{
//    m_reloadImguiHooksKeyName = keyName;
//}


void modSettings::setReloadImguiHooksVkKey() {
    auto it = ValidKeyBindsMap.find(m_reloadImguiHooksKeyName);
    if (it != ValidKeyBindsMap.end()) {
        m_reloadImguiHooksVk_Key = it->second;
        logInfo("setReloadImguiHooksVkKey: m_reloadImguiHooksVk_Key to default: %zu", m_reloadImguiHooksVk_Key);
       
    }
    else {
        logWarn("setReloadImguiHooksVkKey: failed to parse vk code setting it to default: %zu", modSettingsDefault::g_defaultReloadImguiHooksVkCode);
        m_reloadImguiHooksVk_Key = modSettingsDefault::g_defaultReloadImguiHooksVkCode;
    }

    if (m_reloadImguiHooksVk_Key == m_toggleModSettingsVkCode) {
        logErr("setReloadImguiHooksVkKey: m_reloadImguiHooksVk_Key is the same as m_toggleModSettingsVkCode, user will not be able to reload imgui graphic hooks ! please set the m_reloadImguiHooksKeyName in the json file to another key name ");
    }
}




void modSettings::logModSettings(std::string reasonStr)
{
    logInfo("logModSettings: reason: %s", reasonStr.c_str());


    logInfo("m_isUseImgui: %s", m_isUseImgui ? "true" : "false");

    logInfo("m_isLogGameConsoleToLogFile: %s", m_isLogGameConsoleToLogFile ? "true" : "false");
    
    logInfo("");
}


//idColor modSettings::ConvertIntToIdColor(int colorInt) {
//    int r = (colorInt >> 16) & 0xFF;
//    int g = (colorInt >> 8) & 0xFF;
//    int b = colorInt & 0xFF;
//    int a = (colorInt >> 24) & 0xFF;
//
//    r = std::clamp(r, 0, 255);
//    g = std::clamp(g, 0, 255);
//    b = std::clamp(b, 0, 255);
//    a = std::clamp(a, 0, 255);
//
//    return idColor(static_cast<float>(r) / 255.0f,
//        static_cast<float>(g) / 255.0f,
//        static_cast<float>(b) / 255.0f,
//        static_cast<float>(a) / 255.0f);
//}







//ImVec4 modSettings::ConvertIntToImVec4Color(int colorInt) {
//    int r = (colorInt >> 16) & 0xFF;
//    int g = (colorInt >> 8) & 0xFF;
//    int b = colorInt & 0xFF;
//    int a = (colorInt >> 24) & 0xFF;
//
//    // Ensure each component is within the valid range
//    r = std::clamp(r, 0, 255);
//    g = std::clamp(g, 0, 255);
//    b = std::clamp(b, 0, 255);
//    a = std::clamp(a, 0, 255);
//
//    return ImVec4(static_cast<float>(r) / 255.0f,
//        static_cast<float>(g) / 255.0f,
//        static_cast<float>(b) / 255.0f,
//        static_cast<float>(a) / 255.0f);
//}

//int modSettings::ConvertImVec4ColorToInt(const ImVec4& color) {
//    int r = static_cast<int>(color.x * 255.0f);
//    int g = static_cast<int>(color.y * 255.0f);
//    int b = static_cast<int>(color.z * 255.0f);
//    int a = static_cast<int>(color.w * 255.0f);
//
//    // Ensure each component is within the valid range
//    r = std::clamp(r, 0, 255);
//    g = std::clamp(g, 0, 255);
//    b = std::clamp(b, 0, 255);
//    a = std::clamp(a, 0, 255);
//
//    return (a << 24) | (r << 16) | (g << 8) | b;
//}


//ImU32 modSettings::ConvertIntColorToImU32(unsigned int hexColor) {
//    unsigned int a = (hexColor >> 24) & 0xFF;
//    unsigned int r = (hexColor >> 16) & 0xFF;
//    unsigned int g = (hexColor >> 8) & 0xFF;
//    unsigned int b = hexColor & 0xFF;
//
//    return IM_COL32(r, g, b, a);
//}


void modSettings::LogImU32Color(ImU32 colorU32) {
    unsigned int a = (colorU32 >> 24) & 0xFF;
    unsigned int r = (colorU32 >> 16) & 0xFF;
    unsigned int g = (colorU32 >> 8) & 0xFF;
    unsigned int b = colorU32 & 0xFF;

    logInfo("ImU32 Color: 0x%02X%02X%02X%02X\n", a, r, g, b);
}


std::string modSettings::ImVec4ToString(const ImVec4& color) {
    std::stringstream ss;
    ss << "R: " << std::fixed << std::setprecision(2) << color.x << ", "
        << "G: " << std::fixed << std::setprecision(2) << color.y << ", "
        << "B: " << std::fixed << std::setprecision(2) << color.z << ", "
        << "A: " << std::fixed << std::setprecision(2) << color.w;
    return ss.str();
}



//float modSettings::convertIntSensToFloatScale(int menuValInt) {
//
//    if (menuValInt > modSettingsDefault::g_userMaxSensIntValue) {
//        return modSettingsDefault::g_maxSensValue;
//    }
//    if (menuValInt <= 0) {
//        return modSettingsDefault::g_minSensValue;
//    }
//    return (float)menuValInt / (float)modSettingsDefault::g_userMaxSensIntValue;
//}