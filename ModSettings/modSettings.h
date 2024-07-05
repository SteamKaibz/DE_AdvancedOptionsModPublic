#pragma once

#include <Windows.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <unordered_set>
#include "../ImGui/dependencies/imgui/imgui.h"
#include "../DE/idCmd.h"
#include "../DE/WeaponSettings.h"
#include "../DE/UserColorSet.h"
#include "../DE/ColorManager.h"
#include "../DE/GeneratedEnums.h"


#include "../Config/Config.h"
#include "../FileOp/FileOp.h"
#include "../K_Utils/K_Utils.h"
//#include "../DE/customizedWeapon.h"
#include "../DE/idFxManager.h"
#include "../DE/idDeclGlobalShellManager.h"
#include "../ImGui/menu/menu.hpp"








class modSettings
{
public:

	//static const inline unsigned int DefaultGameSpeedKeyVkCode = VK_F1;
	
	
	/*static const inline bool DefaulIsUseImgui = true;
	static const inline bool DefaulIsLogConsoleToLogFile = false;*/


	

private:	

	//? this will be true as long as the user has not been in the mod menu at least once, which is ok because they will need to go in the menu to enabled the custom hud anyway. The idea is that the settings save only when out of the mod menu.
	static inline bool m_isFirstTimeModLaunch = modSettingsDefault::defaultIsFirstTimeModLaunch;

	static inline bool m_isUseDedicatedNadeKeys = modSettingsDefault::defaultIsUseDedicatedNadeKeys;

	static inline unsigned int m_toggleModSettingsVkCode = modSettingsDefault::defaultToggleModSettingsVkCode;	
	static inline ImU32 m_modSettingsShortcutTextColorImU32 = modSettingsDefault::defaultmodSettingsShortcutTextColorImU32;

	static inline bool m_isDisableNewCampaignPopUp = modSettingsDefault::defaultIsDisableNewCampaignPopUp;
	//! the pop up when you put a battery cell in the socket on the ship
	static inline bool m_isDisableBatterySocketPopUp = modSettingsDefault::defaultIsDisableBatterySocketPopUp;
	static inline bool m_isSpeedUpBatterySocketAnimation = modSettingsDefault::defaultIsSpeedUpBatterySocketAnimation;

	static inline bool m_isSkipCustomAnimations = modSettingsDefault::defaultIsSkipCustomAnimations;

	static inline bool m_IsOverideInteractionFOV = modSettingsDefault::defaultIsOverideInteractionFOV;
	static inline float m_interactionFOV = modSettingsDefault::defaultInteractionFOV;

	


	//! game hud colors
	static inline int m_OverrideBloodPunchColor1 = modSettingsDefault::g_defaultOverrideBloodPunchColor1;

	static inline int m_OverrideBloodPunchColor2 = modSettingsDefault::g_defaultOverrideBloodPunchColor2;

	static inline int m_OverrideDesperatePunchColor = modSettingsDefault::g_defaultOverrideDesperatePunchColor;

	static inline int m_OverrideFuel3PipsColor = modSettingsDefault::g_defaultOverrideFuel3Pips_Color;

	static inline int m_OverrideFragGrenadeAvailable_Color = modSettingsDefault::g_defaultOverrideFragGrenadeAvailable_Color;

	static inline int m_OverrideFragGrenadeCoolDown_Color = modSettingsDefault::g_defaultOverrideFragGrenadeCooldown_Color;

	static inline int m_OverrideIceGrenadeAvailable__Color = modSettingsDefault::g_defaultOverrideIceGrenadeAvailable_Color;

	static inline int m_OverrideIceGrenadeCoolDown_Color = modSettingsDefault::g_defaultOverrideIceGrenadeCoolDown_Color;

	static inline bool m_IsWeaponBarColored = modSettingsDefault::g_defaultIsWeaponBarColored;

	
	static inline int m_OverrideRadMeterColor = modSettingsDefault::g_defaultOverrideRadMeterColor;



	static inline float m_assaultRiflePrecisionBoltMouseSens = modSettingsDefault::g_defaultPrecisionBoltMouseSens;
	static inline float m_assaultRiflePrecisionBoltControllerSens = modSettingsDefault::g_defaultPrecisionBoltControllerSens;
	static inline float m_ballistaArbalestMouseSens = modSettingsDefault::g_defaultBallistaArbalesteMouseSens;
	static inline float m_ballistaArbalestControllerSens = modSettingsDefault::g_defaultBallistaArbalesteControllerSens;

	
	static inline bool m_isOverideShotgunConfig = modSettingsDefault::g_defaultIsOverideShotgunConfig;
	static inline bool m_isRemoveBalistaZoom = modSettingsDefault::g_defaultIsRemoveBalistaZoom;
	static inline bool m_isImprovedWeaponSwitching = modSettingsDefault::g_defaultIsImprovedWeaponSwitchEnabled;
	static inline bool m_isImprovedWeaponSwitchingBeep = modSettingsDefault::g_defaultIsImprovedWeaponSwitchBeep;


	static inline bool m_isGameFovUnlocked = modSettingsDefault::g_defaultIsGameFovUnlocked;

	static inline int m_handsFOV = modSettingsDefault::g_defaultHandsFOV;
		  
	static inline float m_reticleScale = Reticle::g_defaultReticleScale;
		  
	static inline int m_immersiveCrosshairLevel = modSettingsDefault::g_defaultImmersiveCrosshairLevel;


	//! mod menu
	static inline float m_eternalFontSize = modSettingsDefault::g_defaultEternalFontSize;
	static inline float m_robotoFontSize = modSettingsDefault::g_defaultRobotoFontSize;


	//! kaibz crosshair
	static inline bool m_useImGuiCustomDotCrosshair = modSettingsDefault::g_defaultUseImguiCustomDotCrosshair;

	static inline float m_imguiCustomDotCrosshairRadiusPix = modSettingsDefault::g_defaultimguiCustomDotCrosshairRadiusPix;

	static inline ImU32 m_customDotCrosshairColorImU32 = modSettingsDefault::g_defaultCustomDotCrosshairColorImU32;
	
	static inline ImU32 m_customDotCrosshairCooldownColorImU32 = modSettingsDefault::g_defaultCustomDotCrosshairCooldownColorImU32;

	static inline bool m_customCrosshairIsShowHealthAsColor = modSettingsDefault::g_defaultCustomDotCrosshairIsShowHealthAsColor;


	//! kaibz hud
	static inline bool m_isUseKaibzHud = modSettingsDefault::g_defaultIsUseKaibzHud;
	static inline float m_kaibzHudIconFontSize = modSettingsDefault::g_defaultKaibzHudIconFontSize;
	static inline int m_kaibzHudOffsetX = modSettingsDefault::g_defaultHudOffsetInt;
	static inline int m_kaibzHudOffsetY = modSettingsDefault::g_defaultHudOffsetInt;
	static inline uint64_t m_kaibzHudFlags = modSettingsDefault::g_defaultHudFlags;
	static inline float m_kaibzHudIconExtraSpacingMul = modSettingsDefault::g_defaultIconExtraSpacingMul;
	static inline float m_kaibzHudBgOpacity = modSettingsDefault::g_defaultKaibzHudBgOpacity;




	//? the reason why we failed with ImU32 was because of the initialization, all we had to do was to init them using smth like var = IM_COL32(0, 0, 0, 255); instead of using hex values....
	static inline ImU32 m_kaibzHudDisabledColorImU32 = modSettingsDefault::g_defaultkaibzHudDisabledColorImU32;
	static inline ImU32 m_kaibzHudCautionColorImU32 = modSettingsDefault::g_defaultkaibzHudCautionColorImU32;
	static inline ImU32 m_kaibzHudWarningColorImU32 = modSettingsDefault::g_defaultkaibzHudWarningColorImU32;
	static inline ImU32 m_kaibzHudCriticalColorImU32 = modSettingsDefault::g_defaultkaibzHudCriticalColorImU32;
	static inline ImU32 m_kaibzHudExtraLivesColorImU32 = modSettingsDefault::g_defaultkaibzHudExtraLivesColorImU32;
	static inline ImU32 m_kaibzHudBloodPunch1ColorImU32 = modSettingsDefault::g_defaultkaibzHudBloodPunch1ColorImU32;
	static inline ImU32 m_kaibzHudBloodPunch2ColorImU32 = modSettingsDefault::g_defaultkaibzHudBloodPunch2ColorImU32;
	static inline ImU32 m_kaibzHudBloodPunchDesperateColorImU32 = modSettingsDefault::g_defaultkaibzHudBloodPunchDesperateColorImU32;
	static inline ImU32 m_kaibzHudHealthMaxColorImU32 = modSettingsDefault::g_defaultkaibzHudHealthMaxColorImU32;
	static inline ImU32 m_kaibzHudHealthColorImU32 = modSettingsDefault::g_defaultkaibzHudHealthColorImU32;
	static inline ImU32 m_kaibzHudArmorMaxColorImU32 = modSettingsDefault::g_defaultkaibzHudArmorMaxColorImU32;
	static inline ImU32 m_kaibzHudArmorColorImU32 = modSettingsDefault::g_defaultkaibzHudArmorColorImU32;
	static inline ImU32 m_kaibzHudRadsuitColorImU32 = modSettingsDefault::g_defaultkaibzHudRadsuitColorImU32;
	static inline ImU32 m_kaibzHudOxygenColorImU32 = modSettingsDefault::g_defaultkaibzHudOxygenColorImU32;
	static inline ImU32 m_kaibzHudAmmoColorImU32 = modSettingsDefault::g_defaultkaibzHudAmmoColorImU32;
	static inline ImU32 m_kaibzHudHammerCrucibleColorImU32 = modSettingsDefault::g_defaultkaibzHudHammerCrucibleColorImU32;
	static inline ImU32 m_kaibzHudFlameBelchColorImU32 = modSettingsDefault::g_defaultkaibzHudFlameBelchColorImU32;
	static inline ImU32 m_kaibzHudFuel1ColorImU32 = modSettingsDefault::g_defaultkaibzHudFuel1ColorImU32;
	static inline ImU32 m_kaibzHudFuel2ColorImU32 = modSettingsDefault::g_defaultkaibzHudFuel2ColorImU32;
	static inline ImU32 m_kaibzHudFuel3ColorImU32 = modSettingsDefault::g_defaultkaibzHudFuel3ColorImU32;
	static inline ImU32 m_kaibzHudFrag1ColorImU32 = modSettingsDefault::g_defaultkaibzHudFrag1ColorImU32;
	static inline ImU32 m_kaibzHudFrag2ColorImU32 = modSettingsDefault::g_defaultkaibzHudFrag2ColorImU32;
	static inline ImU32 m_kaibzHudIceColorImU32 = modSettingsDefault::g_defaultkaibzHudIceColorImU32;
	static inline ImU32 m_kaibzHudIceCooldownColorImU32 = modSettingsDefault::g_defaultkaibzHudIceCooldownColorImU32;

	
		  
	static inline bool m_isRemoveBindsReminderOnHud = modSettingsDefault::g_defaultIsRemoveBindsReminderOnHud;
		  
	static inline bool m_isDashBlurEffectDisabled = modSettingsDefault::g_defaultIsDashBlurEffectDisabled;
		  
	static inline bool m_isHitMarkerDisabled = modSettingsDefault::g_defaultIsHitMarkerDisabled;
		  

	//! Other settings
	static inline bool m_isDisableAntiAliasing = modSettingsDefault::g_defaultIsDisableAntiAliasing;
	static inline bool m_isDisableMouseSmoothing = modSettingsDefault::g_defaultIsDisableMouseSmoothing;
	static inline bool m_isDisableBloom = modSettingsDefault::g_defaultIsDisableBloom;
	static inline int m_decalLifetimeMultiplier = modSettingsDefault::g_defaultDecalLifetimeMultiplier;
	static inline float m_desaturate = modSettingsDefault::g_defaultDesaturate;	
	//static inline int m_textureLodBias = modSettingsDefault::g_defaultTextureLodBias;
	//static inline bool m_isForceRainAnywhere = modSettingsDefault::g_defaultForceRainAnywhere;
	//static inline int m_forceSnowAnywhere = modSettingsDefault::g_defaultForceSnowAnywhere;
	//static inline float ai_haste_overriderate = modSettingsDefault::g_defaultAi_haste_overriderate;
	
	//! Gameplay Settings:
	static inline bool m_isForceAiHaste = modSettingsDefault::g_defaultisForceAiHaste;

	
	//! mod settings
	static inline bool m_isUseImgui = modSettingsDefault::g_defaulIsUseImgui;
	static inline bool m_isLogGameConsoleToLogFile = modSettingsDefault::g_defaulIsLogConsoleToLogFile;
	//? not using a debug var cause it's just better to have 2 version of the mod trust me.
	//static inline int m_isDebugMode = modSettingsDefault::g_defaultisDebugMode;
	//? don't need that as it's only available for the dev/debug version
	//static inline bool m_isPlayModLoadedBeep = modSettingsDefault::g_defaultIsSoundBeepWhenModLoaded;

	//! debug settings
	static inline unsigned int m_reloadImguiHooksVk_Key = 0;
	static inline std::string m_reloadImguiHooksKeyName = modSettingsDefault::g_defaultReloadImguiHooksKeyName;

	
	//! used to check if data has changed and log it
	//static inline std::string m_lastLoadedSerializedDataStr = "";


public:




	//! so other cls can acces vals without having to use getters/setters. a bit late though...
	static modSettings& getInstance();

	static void loadSettings();
	static void saveSettings();	



	static void apply();
	//static void sanatizeData(std::string callerStr);

	//static void update(bool isShowModMenu); //! loading and saving when needed

	//? will be set to false fist time this func is called.
	static bool getIsFirstTimeModLaunch();
	static void setIsFirstTimeModLaunch(bool value);

	static bool getIsUseDedicatedNadeKeys();
	static void setIsUseDedicatedNadeKeys(bool value);

	static unsigned int getToggleModSettingsVkCode();
	static void setToggleModSettingsVkCode(unsigned int vkcode);

	static ImU32 getModSettingsShortcutTextColorImU32();
	static void setModSettingsShortcutTextColorImU32(ImU32 value);

	static bool getIsDisableNewCampaignPopUp();
	static void setIsDisableNewCampaignPopUp(bool value);

	static bool getIsDisableBatterySocketPopUp();
	static void setIsDisableBatterySocketPopUp(bool value);

	static bool getIsSpeedUpBatterySocketAnimation();
	static void setIsSpeedUpBatterySocketAnimation(bool value);

	static bool getIsSkipCustomAnimations();
	static void setIsSkipCustomAnimations(bool value);

	static bool getIsOverideInteractionFOV();
	static void setIsOverideInteractionFOV(bool value);

	static float getInteractionFOV();
	static void setInteractionFOV(float value);

	static float getReticleScale();
	static void setReticleScale(float value);

	static bool isImmersiveCrosshairModeEnabled();

	static void setImmersiveCrosshairLevel(int level);
	static ImmersiveCrosshairLevel getImmersiveCrosshairLevel();



	//! custom crosshair 
	static bool getIsUseImguiDotCrosshair();
	static void setIsUseImguiDotCrosshair(bool value);

	static ImU32 getCustomDotCrosshairColorImU32();
	static void setCustomDotCrosshairColorImU32(ImU32 packedValue);

	static ImU32 getCustomDotCrosshairCooldownColorImU32();
	static void setCustomDotCrosshairCooldownColorImU32(ImU32 packedValue);

	static float getImguiCustomDotCrosshairRadiusPix();
	static void setImguiCustomDotCrosshairRadiusPix(float value);

	static bool getCustomCrosshairIsShowHealthAsColor();
	static void setCustomCrosshairIsShowHealthAsColor(bool value);



	//! kaibz hud
	static bool getIsUseKaibzHud();
	static void setIsUseKaibzHud(bool value);

	static float getRobotoFontSize();
	static void setRobotoFontSize(float value);

	static float getEternalFontSize();
	static void setEternalFontSize(float fontSize);

	static float getKaibzHudIconFontSize();
	static void setKaibzHudIconFontSize(float fontSize);

	static int getKaibzHudOffsetX();
	static void setKaibzHudOffsetX(int value);

	static int getKaibzHudOffsetY();
	static void setKaibzHudOffsetY(int value);

	static float getKaibzHudIconExtraSpacingMul();
	static void setKaibzHudIconExtraSpacingMul(float value);

	static float getKaibzHudBgOpacity();
	static void setKaibzHudBgOpacity(float opacity);

	//static uint64_t getKaibzHudFlags();
	//static void setKaibzHudFlags(uint64_t flags);

	static void setFlag(KaibzHudFlag flag, bool value);
	static bool getFlag(KaibzHudFlag flag);

	//static std::string debuGetFlagString();


	static ImU32 getKaibzHudDisabledColorImU32();
	static void setKaibzHudDisabledColorImU32(ImU32 color);

	static ImU32 getKaibzHudCautionColorImU32();
	static void setKaibzHudCautionColorImU32(ImU32 value);

	static ImU32 getKaibzHudWarningColorImU32();
	static void setKaibzHudWarningColorImU32(ImU32 color);

	static ImU32 getKaibzHudCriticalColorImU32();
	static void setKaibzHudCriticalColorImU32(ImU32 color);

	static ImU32 getKaibzHudExtraLivesColorImU32();
	static void setKaibzHudExtraLivesColorImU32(ImU32 color);

	static ImU32 getKaibzHudBloodPunch1ColorImU32();
	static void setKaibzHudBloodPunch1ColorImU32(ImU32 color);

	static ImU32 getKaibzHudBloodPunch2ColorImU32();
	static void setKaibzHudBloodPunch2ColorImU32(ImU32 color);

	static ImU32 getKaibzHudBloodPunchDesperateColorImU32();
	static void setKaibzHudBloodPunchDesperateColorImU32(ImU32 color);

	static ImU32 getKaibzHudHealthMaxColorImU32();
	static void setKaibzHudHealthMaxColorImU32(ImU32 color);

	static ImU32 getKaibzHudHealthColorImU32();
	static void setKaibzHudHealthColorImU32(ImU32 color);

	static ImU32 getKaibzHudArmorMaxColorImU32();
	static void setKaibzHudArmorMaxColorImU32(ImU32 color);

	static ImU32 getKaibzHudArmorColorImU32();
	static void setKaibzHudArmorColorImU32(ImU32 color);

	static ImU32 getKaibzHudRadsuitColorImU32();
	static void setKaibzHudRadsuitColorImU32(ImU32 color);

	static ImU32 getKaibzHudOxygenColorImU32();
	static void setKaibzHudOxygenColorImU32(ImU32 color);

	static ImU32 getKaibzHudAmmoColorImU32();
	static void setKaibzHudAmmoColorImU32(ImU32 color);

	static ImU32 getKaibzHudHammerCrucibleColorImU32();
	static void setKaibzHudHammerCrucibleColorImU32(ImU32 color);

	static ImU32 getKaibzHudFlameBelchColorImU32();
	static void setKaibzHudFlameBelchColorImU32(ImU32 color);

	static ImU32 getKaibzHudFuel1ColorImU32();
	static void setKaibzHudFuel1ColorImU32(ImU32 color);

	static ImU32 getKaibzHudFuel2ColorImU32();
	static void setKaibzHudFuel2ColorImU32(ImU32 color);

	static ImU32 getKaibzHudFuel3ColorImU32();
	static void setKaibzHudFuel3ColorImU32(ImU32 color);

	static ImU32 getKaibzHudFrag1ColorImU32();
	static void setKaibzHudFrag1ColorImU32(ImU32 color);

	static ImU32 getKaibzHudFrag2ColorImU32();
	static void setKaibzHudFrag2ColorImU32(ImU32 color);

	static ImU32 getKaibzHudIceColorImU32();
	static void setKaibzHudIceColorImU32(ImU32 color);

	static ImU32 getkaibzHudIceCooldownColorImU32();
	static void setkaibzHudIceCooldownColorImU32(ImU32 color);






	//! custom weapons:
	static float getAssaultRiflePrecisionBoltMouseSens();
	static void setAssaultRiflePrecisionBoltMouseSens(float value);

	static float getAssaultRiflePrecisionBoltControllerSens();
	static void setAssaultRiflePrecisionBoltControllerSens(float value);

	static float getBallistaArbalestMouseSens();
	static void setBallistaArbalestMouseSens(float value);

	static float getBallistaArbalestControllerSens();
	static void setBallistaArbalestControllerSens(float value);

	/*static bool isPlayModLoadedBeep();	
	static void setIsPlayModLoadedBeep(bool value);*/

	static bool isOverideShotgunConfig();
	static void setIsOverideShotgunConfig(bool value);

	static bool isRemoveBalistaZoom();
	static void setIsRemoveBalistaZoom(bool value);

	static bool isImprovedWeaponSwitching();
	static void setIsImprovedWeaponSwitching(bool value);

	static bool isImprovedWeaponSwitchingBeep();
	static void setIsImprovedWeaponSwitchingBeep(bool value);

	//static unsigned int getReloadIniFileVkCode();
	
	static bool getIsGameFovMenuUnlocked();
	static void setIsGameFovMenuUnlocked(bool value);


	static int getHandsFOV();
	static void setHandsFOV(int value);

	


	//static int getOVerrideReticleCooldownColor();
	//static int getOverrideDotReticleFragNadeReadyColor();
	//static int getOverrideDotReticleIceNadeReadyColor();
	//static int getOverrideDotReticleBothNadeReadyColor();
	static int getOverrideBloodPunchColor1();
	static int getOverrideBloodPunchColor2();
	static int getOverrideDesperatePunchColor();
	static int getOverrideFuel3PipsColor();
	static int getOverrideFragGrenadeColor();
	static int getOverrideFragGrenadeCooldownColor();
	static int getOverrideIceGrenadeColor();
	static int getOverrideIceGrenadeCooldownColor();
	static bool getIsWeaponBarColored();
	static int getOverrideRadMeterColor();

	static void setOverrideBloodPunchColor1(int value);
	static void setOverrideBloodPunchColor2(int value);
	static void setOverrideDesperatePunchColor(int value);
	static void setOverrideFuel3PipsColor(int value);
	static void setOverrideFragGrenadeColor(int value);
	static void setOverrideFragGrenadeCooldownColor(int value);
	static void setOverrideIceGrenadeColor(int value);
	static void setOverrideIceGrenadeCooldownColor(int value);
	static void setIsWeaponBarColored(bool value);
	static void setOverrideRadMeterColor(int value);

	static void resetGameHudColorsToDefault();



	static bool getIsRemoveBindsReminderOnHud();
	static void setIsRemoveBindsReminderOnHud(bool value);

	static bool getIsDisabledDashBlurEffect();
	static void setIsDisabledDashBlurEffect(bool value);

	static HitMarkerState getIsDisableHitMarker();
	static void setIsDisableHitMarker(bool value);

	//! this is managed in main loop
	static bool getIsDisableAA();
	static void setIsDisableAA(bool value);


	static bool GetIsDisableMouseSmoothing();
	static void SetIsDisableMouseSmoothing(bool value);


	static bool GetIsDisableBloom();
	static void SetIsDisableBloom(bool value);

	//static int GetTextureLodBias();
	//static void SetTextureLodBias(int value);

	static int GetDecalLifetimeMultiplier();
	static void SetDecalLifetimeMultiplier(int value);

	static float GetDesaturate();
	static void SetDesaturate(float value);
		

	//static bool GetIsForceRainAnywhere();
	//static void SetIsForceRainAnywhere(bool value);
	//
	//static int GetForceSnowAnywhere();
	//static void SetForceSnowAnywhere(int value);


	/*static antialiasingLevel GetAntiAliasingLevel();
	static void SetAntiAliasingLevel(antialiasingLevel value);*/

	/*static unsigned int getReloadModSettingsFileVkCode();*/
	//static void setReloadModSettingsFileVkCode(unsigned int vkCode);


	//! gameplay settings
	static bool GetIsForceAiHaste();
	static void SetIsForceAiHaste(bool value);



	//! mod settings 
	static bool getIsUseImgui();

	static bool isLogConsoleToLogFile();
	static void setIsLogConsoleToLogFile(bool isLogConsole);	


	//! mod debug
	static unsigned int getReloadImguiHooksVk_Key();
	static void setReloadImguiHooksVkKey();


	static void logModSettings(std::string reasonStr);

	//static idColor ConvertIntToIdColor(int colorInt);

	//static ImVec4 ConvertIntToImVec4Color(int colorInt);

	//static int ConvertImVec4ColorToInt(const ImVec4& color);

	//static ImU32 ConvertIntColorToImU32(unsigned int hexColor);

	static void LogImU32Color(ImU32 colorU32);

	static std::string ImVec4ToString(const ImVec4& color);

	//static float convertIntSensToFloatScale(int menuValInt);

	

	

	
	

};

