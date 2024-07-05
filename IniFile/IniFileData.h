#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include "../DE/CommonDE.h"
#include "../Config/Config.h"

//! data we need: dotCrosshairColor, dotCrosshairCooldownColor, 

//class IniFileData
//{
//private:
//	//const int m_iniFileIntErrorVal = -1;	 
//	//! need: crosshair size, crosshair outline size, is ammobar, isoverideBloodpunchColor, isoverideRadSuitColor
//	//float m_crosshairSize = defaultCrosshairSize;
//	//float m_crosshairOutlineThickness = defaultCrosshairOutlineThickness;
//	
//	//bool m_isAmmoBar = defaultIsAmmoBar;
//	//bool m_isOverrideBloodPunchColor = defaultIsOverrideBloodPunchColor;
//	//bool m_isOverriRadSuitBarColor = defaultIsOverriRadSuitBarColor;
//
//	//! whichi is not necesseraly the same a Mod version, and that's what we want to know
//	static int m_iniFileVersionInt;
//	//? dont forget to update the debug print func !
//	static float m_assaultRiflePrecisionBoltMouseSens;
//	static float m_assaultRiflePrecisionBoltControllerSens;
//	static float m_ballistaArbalestMouseSens;
//	static float m_ballistaArbalestControllerSens;
//	static bool m_isPlayModLoadedBeep;
//	static bool m_isOverideShotgunConfig;
//	static bool m_isRemoveBalistaZoom;
//	static bool m_isImprovedWeaponSwitching;
//	static bool m_isImprovedWeaponSwitchingBeep;
//	static unsigned int m_reloadIniFileVkCode;
//	static bool m_isIniFileAutoReload;
//
//	static int m_gameUiSettingsMinFov;
//	static int m_gameUiSettingsMaxFov;
//	static int m_handsFOV;
//
//	static float m_reticleScale;
//
//	static int m_immersiveCrosshairLevel;
//
//	static int m_OverrideDotReticleColor;
//	static int m_OverrideDotReticleCooldownColor;
//	static int m_OverrideDotReticleFragNadeReadyColor;
//	static int m_OverrideDotReticleIceNadeReadyColor;
//	static int m_OverrideDotReticleBothNadeReadyColor;
//
//	static int m_OverrideBloodPunchColor1;
//	static int m_OverrideBloodPunchColor2;
//	static int m_OverrideDesperatePunchColor;
//
//	static int m_OverrideFuel3PipsColor;
//
//	static int m_OverrideFragGrenadeAvailable_Color;
//	static int m_OverrideFragGrenadeCoolDown_Color;
//
//	static int m_OverrideIceGrenadeAvailable__Color;
//	static int m_OverrideIceGrenadeCoolDown_Color;
//
//	static bool m_IsWeaponBarColored;
//
//	static int m_OverrideRadMeterColor;
//
//	static bool m_isRemoveBindsReminderOnHud;
//
//	static bool m_isDashBlurEffectDisabled;
//
//	static bool m_isHitMarkerDisabled;
//
//	static int m_userDebugLevelInt;
//
//
//public:
//
//	static void resetToDefault() {
//
//		logWarn("resetting Settings to default");
//		//m_crosshairSize = defaultCrosshairSize;
//		//m_crosshairOutlineThickness = defaultCrosshairOutlineThickness;
//		
//		//m_isAmmoBar = defaultIsAmmoBar;
//		//m_isOverrideBloodPunchColor = defaultIsOverrideBloodPunchColor;
//		//m_isOverriRadSuitBarColor = defaultIsOverriRadSuitBarColor;
//
//		m_iniFileVersionInt = Config::getShortModVersionAsInt();
//
//		m_assaultRiflePrecisionBoltMouseSens = IniDefault::g_defaultPrecisionBoltMouseSens;
//		m_assaultRiflePrecisionBoltControllerSens = IniDefault::g_defaultPrecisionBoltControllerSens;
//		m_ballistaArbalestMouseSens = IniDefault::g_defaultBallistaArbalesteMouseSens;
//		m_ballistaArbalestControllerSens = IniDefault::g_defaultBallistaArbalesteControllerSens;
//		m_isOverideShotgunConfig = IniDefault::g_defaultIsOverideShotgunConfig;
//
//		m_isRemoveBalistaZoom = IniDefault::g_defaultIsRemoveBalistaZoom;
//
//
//		m_isPlayModLoadedBeep = IniDefault::g_defaultIsSoundBeepWhenModLoaded;
//
//		m_isImprovedWeaponSwitching = IniDefault::g_defaultIsImprovedWeaponSwitchEnabled;
//		m_isImprovedWeaponSwitchingBeep = IniDefault::g_defaultIsImprovedWeaponSwitchBeep;
//
//		m_reloadIniFileVkCode = IniDefault::g_defaultReloadIniFileVkey;
//		m_isIniFileAutoReload = IniDefault::g_defaultIsIniFileAutoReload;
//
//		m_handsFOV = IniDefault::g_defaultHandsFOV;
//		m_gameUiSettingsMinFov = IniDefault::g_defaultGameUISettingMinFOV;
//		m_gameUiSettingsMaxFov = IniDefault::g_defaultGameUISettingMaxFOV;
//
//		m_immersiveCrosshairLevel = IniDefault::g_defaultImmersiveCrosshairLevel;
//		//m_isOnlyShowCrosshairInHARScope = IniDefault::g_defaultOnlyShowCrosshairInHARScope;
//
//		m_reticleScale = Reticle::g_defaultReticleScale;
//		//m_reticleScaleADS = IniDefault::g_defaultReticleScaleADS;
//
//		m_OverrideDotReticleColor = IniDefault::g_defaultOverrideDotReticleColor;
//		m_OverrideDotReticleCooldownColor = IniDefault::g_defaultOverrideDotReticleCooldownColor;
//
//		m_OverrideDotReticleFragNadeReadyColor = IniDefault::g_defaultOverrideDotReticleFragNadeReadyColor;
//		m_OverrideDotReticleIceNadeReadyColor = IniDefault::g_defaultOverrideDotReticleIceNadeReadyColor;
//		m_OverrideDotReticleBothNadeReadyColor = IniDefault::g_defaultOverrideDotReticleBothNadesReadyColor;
//
//
//		m_OverrideBloodPunchColor1 = IniDefault::g_defaultOverrideBloodPunchColor1;
//		m_OverrideBloodPunchColor2 = IniDefault::g_defaultOverrideBloodPunchColor2;
//		m_OverrideDesperatePunchColor = IniDefault::g_defaultOverrideDesperatePunchColor;
//
//		m_OverrideFuel3PipsColor = IniDefault::g_defaultOverrideFuel3Pips_Color;
//
//		m_OverrideFragGrenadeAvailable_Color = IniDefault::g_defaultOverrideFragGrenadeAvailable_Color;
//		m_OverrideFragGrenadeCoolDown_Color = IniDefault::g_defaultOverrideFragGrenadeCooldown_Color;
//
//		m_OverrideIceGrenadeAvailable__Color = IniDefault::g_defaultOverrideIceGrenadeAvailable_Color;
//		m_OverrideIceGrenadeCoolDown_Color = IniDefault::g_defaultOverrideIceGrenadeCoolDown_Color;
//
//		m_IsWeaponBarColored = IniDefault::g_defaultIsWeaponBarColored;
//
//		m_OverrideRadMeterColor = IniDefault::g_defaultOverrideRadMeterColor;
//		
//		m_isRemoveBindsReminderOnHud = IniDefault::g_defaultIsRemoveBindsReminderOnHud;
//
//		m_isDashBlurEffectDisabled = IniDefault::g_defaultIsDashBlurEffectDisabled;
//
//		m_isHitMarkerDisabled = IniDefault::g_defaultIsHitMarkerDisabled;
//
//		m_userDebugLevelInt = IniDefault::g_defaultUserDebugLevelInt;
//	}
//
//
//
//
//
//	//! this is used to generate/update the ini file
//
//	static std::string getIniFileVersionAsStr() {
//		/*return m_iniFileVersionInt;*/
//		return Config::getShortModVersionAsString();
//	}
//	
//	static int getassaultRiflePrecisionBoltMouseSensInt() {
//		return getIntSensFromFloat(m_assaultRiflePrecisionBoltMouseSens);
//	}
//	static int getssaultRiflePrecisionBoltControllerSensInt() {
//		
//	
//		return getIntSensFromFloat(m_assaultRiflePrecisionBoltControllerSens);
//	}
//	static int getballistaArbalestMouseSensInt() {
//		return getIntSensFromFloat(m_ballistaArbalestMouseSens);
//	}
//	static int getballistaArbalestControllerSensInt() {
//		return getIntSensFromFloat(m_ballistaArbalestControllerSens);
//	}
//	static std::string getisPlayModLoadedBeepStr() {
//		return getBoolAsStr(m_isPlayModLoadedBeep);
//	}
//	static std::string getisOverideShotgunConfigStr() {
//		return getBoolAsStr(m_isOverideShotgunConfig);
//	}
//
//	static std::string getIsRemoveBalistaZoomStr() {
//		return getBoolAsStr(m_isRemoveBalistaZoom);
//	}
//	static std::string getisImprovedWeaponSwitchingStr() {
//		return getBoolAsStr(m_isImprovedWeaponSwitching);
//	}
//	static std::string getisImprovedWeaponSwitchingBeepStr() {
//		return getBoolAsStr(m_isImprovedWeaponSwitchingBeep);
//	}
//	static std::string getreloadIniFileVkCodeStr() {
//		return getStrFromVkKey(m_reloadIniFileVkCode);
//	}
//
//	static std::string getIsInifileAutoReloadStr() {
//		return getBoolAsStr(m_isIniFileAutoReload);
//	}
//
//	static int getGameUiSettingsMaxFovInt() {
//		return m_gameUiSettingsMaxFov;
//	}
//
//	static int getGameUiSettingsMinFovInt() {
//		return m_gameUiSettingsMinFov;
//	}
//
//	static int getHandsFovInt() {
//		return m_handsFOV;
//	}
//		 
//	static int getReticleScaleInt() {
//		return getReticleScaleIntFromFloat(m_reticleScale);
//	}
//
//	/*static int getReticleScaleAdsInt() {
//		return getReticleScaleIntFromFloat(m_reticleScaleADS);
//	}*/
//
//
//
//	static int getImmersiveCrosshairLevelInt() {
//		return m_immersiveCrosshairLevel;
//	}
//
//	static int getOverrideReticleColorInt() {
//		return m_OverrideDotReticleColor;
//	}
//
//	static int getOverrideReticleCooldownColorInt() {
//		return m_OverrideDotReticleCooldownColor;
//	}
//
//	static int getOverrideDotReticleFragNadeReadyColorInt() {
//		return m_OverrideDotReticleFragNadeReadyColor;
//	}
//
//	static int getOverrideDotReticleIceNadeReadyColorInt() {
//		return m_OverrideDotReticleIceNadeReadyColor;
//	}
//
//	static int getOverrideDotReticleBothNadeReadyColorInt() {
//		return m_OverrideDotReticleBothNadeReadyColor;
//	}
//
//	static int getOverrideBloodPunchColor1Int()  {
//		return m_OverrideBloodPunchColor1;
//	}
//
//	static int getOverrideBloodPunchColor2Int() {
//		return m_OverrideBloodPunchColor2;
//	}
//		
//	static int getOverrideDesperatePunchInt() {
//		return m_OverrideDesperatePunchColor;
//	}
//
//	static int getOverrideFuel3PipsColorInt() {
//		return m_OverrideFuel3PipsColor;
//	}
//
//	static int getOverrideFragGrenadeColorInt() {
//		return m_OverrideFragGrenadeAvailable_Color;
//	}
//
//	static int getOverrideFragGrenadeCoolDownColorInt() {
//		return m_OverrideFragGrenadeCoolDown_Color;
//	}
//
//	static int getOverrideIceGrenadeColorInt() {
//		return m_OverrideIceGrenadeAvailable__Color;
//	}
//
//	static int getOverrideIceGrenadeCooldownColorInt() {
//		return m_OverrideIceGrenadeCoolDown_Color;
//	}	
//
//	static std::string getIsIsWeaponBarColoredStr() {
//		return getBoolAsStr(m_IsWeaponBarColored);
//	}
//
//	static int getOverrideRadMeterColorInt()  {
//		return m_OverrideRadMeterColor;
//	}
//
//	static std::string getIsRemoveBindsReminderOnHudStr()  {
//		return getBoolAsStr(m_isRemoveBindsReminderOnHud);
//	}
//
//	static std::string getIsDisableDashBlurEffectStr() {
//		return getBoolAsStr(m_isDashBlurEffectDisabled);
//	}
//
//	static std::string getIsDisableHitMarkerStr() {
//		return getBoolAsStr(m_isHitMarkerDisabled);
//	}
//
//	static int getIsUserDebugModLevelInt() {
//		return m_userDebugLevelInt;
//	}
//
//
//
//
//	//! Getters :	
//
//	static int getIniFileVersion() {
//		return m_iniFileVersionInt;
//	}
//
//	static float getAssaultRiflePrecisionBoltMouseSens() {
//		return m_assaultRiflePrecisionBoltMouseSens;
//	}
//
//	static float getAssaultRiflePrecisionBoltControllerSens(){
//		return m_assaultRiflePrecisionBoltControllerSens;
//	}
//
//	static float getBallistaArbalestMouseSens() {
//		return m_ballistaArbalestMouseSens;
//	}
//
//	static float getBallistaArbalestControllerSens() {
//		return m_ballistaArbalestControllerSens;
//	}
//
//	static bool isPlayModLoadedBeep() {
//		return m_isPlayModLoadedBeep;
//	}
//
//	static bool isOverideShotgunConfig() {
//		return m_isOverideShotgunConfig;
//	}
//
//	static bool isRemoveBalistaZoom() {
//		return m_isRemoveBalistaZoom;
//	}
//	static bool isImprovedWeaponSwitching() {
//		return m_isImprovedWeaponSwitching;
//	}
//
//	static bool isImprovedWeaponSwitchingBeep() {
//		return m_isImprovedWeaponSwitchingBeep;
//	}
//
//
//	static unsigned int getReloadIniFileVkCode() {
//		return m_reloadIniFileVkCode;
//	}
//
//	static bool isIniFileAutoReload() {
//		return m_isIniFileAutoReload;
//	}
//
//	static int getGameUiSettingsMinFov() {
//		return m_gameUiSettingsMinFov;
//	}
//
//	static int getGameUiSettingsMaxFov() {
//		return m_gameUiSettingsMaxFov;
//	}
//
//	static int getHandsFOV() {
//		return m_handsFOV;
//	}
//
//	static float getReticleScale() {
//		return m_reticleScale;
//	}
//
//
//	static ImmersiveCrosshairLevel getImmersiveCrosshairLevel() {
//		if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::NO_IMMERSIVE_CROSSHAIR) {
//			return ImmersiveCrosshairLevel::NO_IMMERSIVE_CROSSHAIR;
//		}
//		else if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ONLY) {
//			return ImmersiveCrosshairLevel::HAR_ONLY;
//		}		
//		else if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_BALISTA_ADS) {
//			return ImmersiveCrosshairLevel::HAR_BALISTA_ADS;
//		}
//		else if (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_BALISTA) {
//			return ImmersiveCrosshairLevel::HAR_BALISTA;
//		}
//		return ImmersiveCrosshairLevel::NO_IMMERSIVE_CROSSHAIR;
//	}
//
//	//! helper
//	static bool isImmersiveCrosshairModeEnabled() {
//		return (m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_ONLY || m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_BALISTA || m_immersiveCrosshairLevel == (int)ImmersiveCrosshairLevel::HAR_BALISTA_ADS);
//	}
//
//
//	static int getOverrideReticleColor() {
//		return m_OverrideDotReticleColor;
//	}
//
//	static int getOVerrideReticleCooldownColor() {
//		return m_OverrideDotReticleCooldownColor;
//	}
//
//	static int getOverrideDotReticleFragNadeReadyColor() {
//		return m_OverrideDotReticleFragNadeReadyColor;
//	}
//
//	static int getOverrideDotReticleIceNadeReadyColor() {
//		return m_OverrideDotReticleIceNadeReadyColor;
//	}
//
//	static int getOverrideDotReticleBothNadeReadyColor() {
//		return m_OverrideDotReticleBothNadeReadyColor;
//	}
//
//	static int getOverrideBloodPunchColor1() {
//		return m_OverrideBloodPunchColor1;
//	}
//
//	static int getOverrideBloodPunchColor2() {
//		return m_OverrideBloodPunchColor2;
//	}
//
//	static int getOverrideDesperatePunchColor() {
//		return m_OverrideDesperatePunchColor;
//	}
//
//	static int getOverrideFuel3PipsColor() {
//		return m_OverrideFuel3PipsColor;
//	}
//
//
//	static int getOverrideFragGrenadeColor() {
//		//logInfo("getOverrideFragGrenadeColor is: %d", m_OverrideFragGrenadeAvailable_Color);
//		return m_OverrideFragGrenadeAvailable_Color;
//	}
//
//	static int getOverrideFragGrenadeCooldownColor() {
//		//logInfo("m_OverrideFragGrenadeCoolDown_Color is: %d", m_OverrideFragGrenadeCoolDown_Color);
//		return m_OverrideFragGrenadeCoolDown_Color;
//	}
//	
//
//	//? just a test delete this:
//	/*static void debugForceFragNadeColor(int namedColorId) {
//		m_OverrideFragGrenadeAvailable_Color = namedColorId;
//	}
//	*/
//	static int getOverrideIceGrenadeColor() {
//		return m_OverrideIceGrenadeAvailable__Color;
//	}
//
//	//? just a test delete this:
//	/*static void debugForceIceNadeColor(int namedColorId) {
//		m_OverrideIceGrenadeAvailable__Color = namedColorId;
//	}*/
//
//	static int getOverrideIceGrenadeCooldownColor() {
//		/*logInfo("getOverrideIceGrenadeCooldownArrowColor: m_OverrideIceGrenadeCoolDown_Color: %d", (m_OverrideIceGrenadeCoolDown_Color));*/
//		return m_OverrideIceGrenadeCoolDown_Color;
//	}
//
//	static bool getIsWeaponBarColored() {
//		return m_IsWeaponBarColored;
//
//	}
//
//	static int getOverrideRadMeterColor() {
//		return m_OverrideRadMeterColor;
//	}
//
//	static bool getIsRemoveBindsReminderOnHud() {
//		return m_isRemoveBindsReminderOnHud;
//	}
//
//	static bool getIsDisabledDashBlurEffect() {
//		return m_isDashBlurEffectDisabled;
//	}
//
//	static HitMarkerState getIsDisableHitMarker() {
//		return (HitMarkerState)m_isHitMarkerDisabled;
//	}
//
//	static ModDebugVersion getModDebugVersion() {
//		//ModDebugVersion modVersion = ModDebugVersion::modeReleaseUserDebugLevelError;
//		ModDebugVersion modVersion = (ModDebugVersion)m_userDebugLevelInt;
//
//		switch (modVersion)
//		{		
//		case ModDebugVersion::modeReleaseUserDebugLevelError:
//			return modVersion;
//		case ModDebugVersion::modeReleaseUserDebugLevelWarn:
//			return modVersion;
//		case ModDebugVersion::modeReleaseUserDebugLevelInfo:
//			return modVersion;
//		case ModDebugVersion::modeReleaseDevDebugLevelError:
//			return modVersion;
//		case ModDebugVersion::modeReleaseDevDebugLevelWarn:
//			return modVersion;
//		case ModDebugVersion::modeReleaseDevDebugLevelInfo:
//			return modVersion;
//		case ModDebugVersion::modeReleaseDevDebugLevelMax:
//			return modVersion;
//		default:
//			logWarn("getModDebugVersion: default case");
//			return ModDebugVersion::modeReleaseUserDebugLevelError;
//			break;
//		}
//
//		
//		////if (m_userDebugLevelInt == IniDefault::g_userHiddenLogLevelMaxVerboseInt) {
//		////	//? WARNING this will make the log file VERY big VERY fast
//		////	return ModDebugVersion::modeReleaseUserDebugLevelMax;
//		////}
//		//if (m_userDebugLevelInt <= IniDefault::g_userLogLevelErrorInt) {
//		//	return ModDebugVersion::modeReleaseUserDebugLevelError;
//		//}
//		//else if (m_userDebugLevelInt >= IniDefault::g_userLogLevelInfoInt) {
//		//	return ModDebugVersion::modeReleaseUserDebugLevelInfo;
//		//}		
//		//else if (m_userDebugLevelInt == IniDefault::g_userLogLevelWarningInt) {
//		//	return ModDebugVersion::modeReleaseUserDebugLevelWarn;
//		//}
//		//return ModDebugVersion::modeReleaseUserDebugLevelError;
//	}
//
//
//
//
//
//	//! Parser:
//
//	static bool parseIniFileVersion(const char* iniFileVersionCharPtr) {		
//		if (iniFileVersionCharPtr == 0) {
//			logErr("SetIniFileVersion: failed to find iniFileVersionCharPtr");
//			m_iniFileVersionInt = 0;
//		}
//		else {
//			try
//			{
//				std::string iniFileVersionStr = std::string(iniFileVersionCharPtr);
//				if (!(iniFileVersionStr == Config::getShortModVersionAsString())) {
//					logWarn("SetIniFileVersion: version missmatched");
//					m_iniFileVersionInt = 0;
//				}
//				else {
//					m_iniFileVersionInt = Config::getShortModVersionAsInt();
//					return true;
//				}				
//			}
//			catch (const std::exception& ex)
//			{
//				logErr("SetIniFileVersion: exception error: %s ", ex.what());
//				m_iniFileVersionInt = 0;
//			}
//			
//		}
//		return false;
//		//logInfo("SetIniFileVersion: m_iniFileVersionInt: %d", m_iniFileVersionInt);
//	}
//
//
//	static bool parseReloadIniFileVkCode(const char* c_charPtr) {
//		
//		if (c_charPtr == 0) {
//			
//			std::string defaultReloadKeyStr = getStrFromVkKey(IniDefault::g_defaultReloadIniFileVkey);
//			logWarn("IniFileData: setReloadIniFileVkCode, iniFileVersionCharPtr is null, setting default keycode: %X (%s)", IniDefault::g_defaultReloadIniFileVkey, defaultReloadKeyStr.c_str());
//			m_reloadIniFileVkCode = IniDefault::g_defaultReloadIniFileVkey;
//		}
//		else {
//			try
//			{
//				std::string strVal = c_charPtr;
//				m_reloadIniFileVkCode = keyStrToVK_KeyMap.at(strVal);
//				return true;
//			}
//			catch (const std::exception& ex)
//			{
//			  logErr("IniFileData: setReloadIniFileVkCode, exception error: %s setting reload ini file key to default", ex.what());
//			  m_reloadIniFileVkCode = IniDefault::g_defaultReloadIniFileVkey;
//			}			
//		}
//		return false;
//	}
//
//	static bool parseIsPlayModLoadedBeepVal(int val) {
//		if (val == IniDefault::iniFileBoolNotFoundVal) {
//			m_isPlayModLoadedBeep = IniDefault::g_defaultIsSoundBeepWhenModLoaded;
//			logWarn("IniFileData: parsed wrong value for isPlayModLoadedBeep, using default value: %d", IniDefault::g_defaultIsSoundBeepWhenModLoaded);
//		}
//		else {
//			m_isPlayModLoadedBeep = (bool)val;
//			return true;
//		}
//		return false;
//	}
//	
//	static bool parseIsImprovedShotgunConfigVal(int val) {
//		if (val == IniDefault::iniFileBoolNotFoundVal) {
//			m_isOverideShotgunConfig = IniDefault::g_defaultIsOverideShotgunConfig;
//			logWarn("IniFileData: parsed wrong value for isOverideShotgunConfig, using default value: %d", IniDefault::g_defaultIsOverideShotgunConfig);
//		}
//		else {
//			m_isOverideShotgunConfig = (bool)val;
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseIsRemoveBalistatZoom(int val) {
//		if (val == IniDefault::iniFileBoolNotFoundVal) {
//			m_isRemoveBalistaZoom = IniDefault::g_defaultIsRemoveBalistaZoom;
//			logWarn("IniFileData: parsed wrong value for m_isRemoveBalistaZoom, using default value: %d", IniDefault::g_defaultIsRemoveBalistaZoom);
//		}
//		else {
//			m_isRemoveBalistaZoom = (bool)val;
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseIsImprovedSwitchingVal(int val) {
//		if (val == IniDefault::iniFileBoolNotFoundVal) {
//			m_isImprovedWeaponSwitching = IniDefault::g_defaultIsImprovedWeaponSwitchEnabled;
//			logWarn("IniFileData: parsed wrong value for isImprovedWeaponSwitching, using default value: %d", IniDefault::g_defaultIsImprovedWeaponSwitchEnabled);
//		}
//		else {
//			m_isImprovedWeaponSwitching = (bool)val;
//			return true;
//		}
//		return false;
//	}	
//
//	static bool parseIsImprovedSwitchingBeepVal(int val) {
//		if (val == IniDefault::iniFileBoolNotFoundVal) {
//			m_isImprovedWeaponSwitchingBeep = IniDefault::g_defaultIsImprovedWeaponSwitchBeep;
//			logWarn("IniFileData: parsed wrong value for isImprovedWeaponSwitchingBeep, using default value: %d", IniDefault::g_defaultIsImprovedWeaponSwitchBeep);
//		}
//		else {
//			m_isImprovedWeaponSwitchingBeep = (bool)val;
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseIsIniFileAutoReload(int val) {
//		if (val == IniDefault::iniFileBoolNotFoundVal) {
//			m_isIniFileAutoReload = IniDefault::g_defaultIsIniFileAutoReload;
//			logWarn("IniFileData: parsed wrong value for m_isIniFileAutoReload, using default value: %d", IniDefault::g_defaultIsIniFileAutoReload);
//		}
//		else {
//			m_isIniFileAutoReload = (bool)val;
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseBoltMouseSens(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_assaultRiflePrecisionBoltMouseSens = IniDefault::g_defaultPrecisionBoltMouseSens;
//			logWarn("IniFileData: parsed wrong value for assaultRiflePrecisionBoltMouseSens, using default value: %.2f", IniDefault::g_defaultPrecisionBoltMouseSens);
//		}
//		else {
//			m_assaultRiflePrecisionBoltMouseSens = getFloatFromSensInt(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseBoltControllerSens(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_assaultRiflePrecisionBoltControllerSens = IniDefault::g_defaultPrecisionBoltControllerSens;
//			logWarn("IniFileData: parsed wrong value for assaultRiflePrecisionBoltControllerSens, using default value: %.2f", IniDefault::g_defaultPrecisionBoltControllerSens);
//		}
//		else {
//			m_assaultRiflePrecisionBoltControllerSens = getFloatFromSensInt(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseArbalestMouseSens(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_ballistaArbalestMouseSens = IniDefault::g_defaultBallistaArbalesteMouseSens;
//			logWarn("IniFileData: parsed wrong value for ballistaArbalestMouseSens, using default value: %.2f", IniDefault::g_defaultBallistaArbalesteMouseSens);
//		}
//		else {
//			m_ballistaArbalestMouseSens = getFloatFromSensInt(iniFileVal);
//			return true;
//
//		}
//		return false;
//
//	}
//
//	static bool parseArbalestControllerSens(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_ballistaArbalestControllerSens = IniDefault::g_defaultBallistaArbalesteControllerSens;
//			logWarn("IniFileData: parsed wrong value for ballistaArbalestControllerSens, using default value: %.2f", IniDefault::g_defaultBallistaArbalesteControllerSens);
//		}
//		else {
//			m_ballistaArbalestControllerSens = getFloatFromSensInt(iniFileVal);
//			return true;
//
//		}
//		return false;
//
//	}
//
//	static bool parseGameUiSettingsMinFov(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_gameUiSettingsMinFov = IniDefault::g_defaultGameUISettingMinFOV;
//			logWarn("IniFileData: parsed wrong value for m_gameUiSettingsMinFov, using default value: %d", IniDefault::g_defaultGameUISettingMinFOV);
//		}
//		else {
//			m_gameUiSettingsMinFov = getMinGameFovClamped(iniFileVal);
//			return true;
//
//		}
//		return false;
//	}
//
//
//	static bool parseGameUiSettingsMaxFov(int iniFileVal){
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_gameUiSettingsMaxFov = IniDefault::g_defaultGameUISettingMaxFOV;
//			logWarn("IniFileData: parsed wrong value for m_gameUiSettingsMaxFov, using default value: %d", IniDefault::g_defaultGameUISettingMaxFOV);
//		}
//		else {
//			m_gameUiSettingsMaxFov = getMaxGameFovClamped(iniFileVal);
//			return true;
//
//		}
//		return false;
//	}
//
//	static bool parseHandsFOV(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_handsFOV = IniDefault::g_defaultHandsFOV;
//			logWarn("IniFileData: parsed wrong value for m_handsFOV, using default value: %d", IniDefault::g_defaultHandsFOV);
//		}
//		else {
//			m_handsFOV = iniFileVal;
//			return true;
//
//		}
//		return false;
//
//	}
//
//	
//	 
//	static bool parseReticleScale(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_reticleScale = Reticle::g_defaultReticleScale;
//			logWarn("IniFileData: parsed wrong value for m_reticleScale, using default value: %.2f", Reticle::g_defaultReticleScale);
//		}
//		else {
//			m_reticleScale = getFloatFromReticleScaleInt(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseImmersiveCrosshairLevel(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_immersiveCrosshairLevel = IniDefault::g_defaultImmersiveCrosshairLevel;
//			logWarn("IniFileData: parsed wrong value for m_immersiveCrosshairLevel, using default value: %d", IniDefault::g_defaultImmersiveCrosshairLevel);
//		}
//		else {
//			m_immersiveCrosshairLevel = iniFileVal;
//			return true;
//		}
//		return false;
//	}
//
//
//	static bool parseOverrideReticleColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideDotReticleColor = IniDefault::g_defaultOverrideDotReticleColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideDotReticleColor, using default value: %d", IniDefault::g_defaultOverrideDotReticleColor);
//		}
//		else {
//			m_OverrideDotReticleColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseOverrideReticleCooldownColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideDotReticleCooldownColor = IniDefault::g_defaultOverrideDotReticleCooldownColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideDotReticleCooldownColor, using default value: %d", IniDefault::g_defaultOverrideDotReticleCooldownColor);
//		}
//		else {
//			m_OverrideDotReticleCooldownColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseOverrideDotReticleFragNadeReadyColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideDotReticleFragNadeReadyColor = IniDefault::g_defaultOverrideDotReticleFragNadeReadyColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideDotReticleFragNadeReadyColor, using default value: %d", IniDefault::g_defaultOverrideDotReticleFragNadeReadyColor);
//		}
//		else {
//			m_OverrideDotReticleFragNadeReadyColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseOverrideDotReticleIceNadeReadyColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideDotReticleIceNadeReadyColor = IniDefault::g_defaultOverrideDotReticleIceNadeReadyColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideDotReticleIceNadeReadyColor, using default value: %d", IniDefault::g_defaultOverrideDotReticleIceNadeReadyColor);
//		}
//		else {
//			m_OverrideDotReticleIceNadeReadyColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseOverrideDotReticleBothNadeReadyColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideDotReticleBothNadeReadyColor = IniDefault::g_defaultOverrideDotReticleBothNadesReadyColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideDotReticleBothNadeReadyColor, using default value: %d", IniDefault::g_defaultOverrideDotReticleBothNadesReadyColor);
//		}
//		else {
//			m_OverrideDotReticleBothNadeReadyColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//
//
//
//	static bool parseOverrideBloodPunchColor1(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideBloodPunchColor1 = IniDefault::g_defaultOverrideBloodPunchColor1;
//			logWarn("IniFileData: parsed wrong value for m_OverrideBloodPunchColor1, using default value: %d", IniDefault::g_defaultOverrideBloodPunchColor1);
//		}
//		else {
//			m_OverrideBloodPunchColor1 = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseOverrideBloodPunchColor2(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideBloodPunchColor2 = IniDefault::g_defaultOverrideBloodPunchColor2;
//			logWarn("IniFileData: parsed wrong value for m_OverrideBloodPunchColor2, using default value: %d", IniDefault::g_defaultOverrideBloodPunchColor2);
//		}
//		else {
//			m_OverrideBloodPunchColor2 = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseOverrideDesperatePunchColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideDesperatePunchColor = IniDefault::g_defaultOverrideDesperatePunchColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideDesperatePunchColor, using default value: %d", IniDefault::g_defaultOverrideDesperatePunchColor);
//		}
//		else {
//			m_OverrideDesperatePunchColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//
//	static bool parseOverrideFuel3PipsColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideFuel3PipsColor = IniDefault::g_defaultOverrideFuel3Pips_Color;
//			logWarn("IniFileData: parsed wrong value for m_OverrideFuel3PipsColor, using default value: %d", IniDefault::g_defaultOverrideFuel3Pips_Color);
//		}
//		else {
//			m_OverrideFuel3PipsColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseFragGrenadeReadyOverrideColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideFragGrenadeAvailable_Color = IniDefault::g_defaultOverrideFragGrenadeAvailable_Color;
//			logWarn("IniFileData: parsed wrong value for m_OverrideFragGrenadeAvailable_Color:  using default value: %d", IniDefault::g_defaultOverrideFragGrenadeAvailable_Color);
//		}
//		else {
//			m_OverrideFragGrenadeAvailable_Color = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseFragGrenadeCooldownOverrideColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideFragGrenadeCoolDown_Color = IniDefault::g_defaultOverrideFragGrenadeCooldown_Color;
//			logWarn("IniFileData: parsed wrong value for m_OverrideFragGrenadeCoolDown_Color:  using default value: %d", IniDefault::g_defaultOverrideFragGrenadeCooldown_Color);
//		}
//		else {
//			m_OverrideFragGrenadeCoolDown_Color = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//
//	
//	static bool parseIceGrenadeReadyOverrideColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideIceGrenadeAvailable__Color = IniDefault::g_defaultOverrideIceGrenadeAvailable_Color;
//			logWarn("IniFileData: parsed wrong value for m_OverrideIceGrenadeAvailable__Color:  using default value: %d", IniDefault::g_defaultOverrideIceGrenadeAvailable_Color);
//		}
//		else {
//			m_OverrideIceGrenadeAvailable__Color = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//
//	static bool parseOverrideIceGrenadeCooldownColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideIceGrenadeCoolDown_Color = IniDefault::g_defaultOverrideIceGrenadeCoolDown_Color;
//			logWarn("IniFileData: parsed wrong value for m_OverrideIceGrenadeCoolDown_Color: using default value: %d", IniDefault::g_defaultOverrideIceGrenadeCoolDown_Color);
//		}
//		else {
//			m_OverrideIceGrenadeCoolDown_Color = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//
//	}
//
//	static bool parseIsWeaponBarColored(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileBoolNotFoundVal) {		
//			m_IsWeaponBarColored = IniDefault::g_defaultIsWeaponBarColored;
//			logWarn("IniFileData: parsed wrong value for m_IsWeaponBarColored, using default value: %d", IniDefault::g_defaultIsWeaponBarColored);
//		}
//		else {
//			m_IsWeaponBarColored = (bool)iniFileVal;
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseOverrideRadMeterColor(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_OverrideRadMeterColor = IniDefault::g_defaultOverrideRadMeterColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideRadMeterColor, using default value: %d", IniDefault::g_defaultOverrideRadMeterColor);
//		}
//		else {
//			m_OverrideRadMeterColor = getClampedColorVal(iniFileVal);
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseIsRemoveBindsReminderOnHud(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileBoolNotFoundVal) {
//			m_isRemoveBindsReminderOnHud = IniDefault::g_defaultIsRemoveBindsReminderOnHud;
//			logWarn("IniFileData: parsed wrong value for m_isRemoveBindsReminderOnHud, using default value: %d", IniDefault::g_defaultIsRemoveBindsReminderOnHud);
//		}
//		else {
//			m_isRemoveBindsReminderOnHud = (bool)iniFileVal;
//			return true;
//		}
//		return false;
//
//	}
//
//	
//
//	static bool parseIsDisabledDashBlurEffect(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileBoolNotFoundVal) {
//			m_isDashBlurEffectDisabled = IniDefault::g_defaultIsDashBlurEffectDisabled;
//			logWarn("IniFileData: parsed wrong value for m_isDashBlurEffectDisabled, using default value: %d", IniDefault::g_defaultIsDashBlurEffectDisabled);
//		}
//		else {
//			m_isDashBlurEffectDisabled = (bool)iniFileVal;
//			return true;
//		}
//		return false;
//	}
//
//	static bool parseIsDisableHitMarker(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileBoolNotFoundVal) {
//			m_isHitMarkerDisabled = IniDefault::g_defaultIsHitMarkerDisabled;
//			logWarn("IniFileData: parsed wrong value for m_isHitMarkerDisabled, using default value: %d", IniDefault::g_defaultIsHitMarkerDisabled);
//		}
//		else {
//			m_isHitMarkerDisabled = (bool)iniFileVal;
//			return true;
//		}
//		return false;
//	}
//
//
//	static bool parseUserDebugModeLevel(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileIntNotFoundVal) {
//			m_userDebugLevelInt = IniDefault::g_defaultUserDebugLevelInt;
//			logWarn("IniFileData: parsed wrong value for m_userDebugLevelInt, using default value: %d", IniDefault::g_defaultUserDebugLevelInt);
//		}
//		else {
//			m_userDebugLevelInt = iniFileVal;
//			return true;
//		}
//		return false;
//	}
//
//
//
//	/*static bool parseIsUserDebugModeEnabled(int iniFileVal) {
//		if (iniFileVal == IniDefault::iniFileBoolNotFoundVal) {
//			m_isUserDebugModeEnabled = IniDefault::g_defaultIsUserDebugModeEnabled;
//			logWarn("IniFileData: parsed wrong value for m_isUserDebugModeEnabled, using default value: %d", IniDefault::g_defaultIsUserDebugModeEnabled);			
//		}
//		else {
//			m_isUserDebugModeEnabled = (bool)iniFileVal;
//			return true;
//		}
//		return false;
//
//	}*/
//
//	/*void setIsImprovedSwitchingBeepVal(int val) {
//		if (val == iniFileBoolNotFoundVal) {
//			m_isImprovedWeaponSwitchingBeep = g_defaultIsImprovedWeaponSwitchBeep;
//			logWarn("IniFileData: parsed wrong value for isImprovedWeaponSwitchingBeep, using default value: %d", g_defaultIsImprovedWeaponSwitchBeep);
//		}
//		else {
//			m_isImprovedWeaponSwitchingBeep = (bool)val;
//		}
//	}*/
//
//	/*static std::string getModVersionAsString() {
//		
//	}*/
//
//	
//
//	//! Converters:
//	//! 
//
//
//
//	/*static int getClampedHandsFovValue(int intVal) {
//		if (intVal < 1) {
//			return 1;
//		}
//		else if(intVal > )
//	}*/
//
//	/*static int getClampedDebugLevel(int val) {
//		if (val <= IniDefault::g_defaultUserDebugLevelInt) {
//			return IniDefault::g_defaultUserDebugLevelInt;
//		}
//		else if (val > IniDefault::g_userMaxDebugLevelInt) {
//			return  IniDefault::g_userMaxDebugLevelInt;
//		}
//		return val;
//	}*/
//
//	static int getMinGameFovClamped(int val) {
//		if (val < IniDefault::g_gameUISettingAllowedFOV_Min) {
//			return IniDefault::g_gameUISettingAllowedFOV_Min;
//		}
//		if (val > IniDefault::g_defaultGameUISettingMinFOV) {
//			return IniDefault::g_defaultGameUISettingMinFOV;
//		}
//		return val;
//	}
//
//
//	static int getMaxGameFovClamped(int val) {
//		if (val < IniDefault::g_defaultGameUISettingMaxFOV) {
//			return IniDefault::g_defaultGameUISettingMaxFOV;
//		}
//		if (val > IniDefault::g_gameUISettingAllowedFOV_Max) {
//			return IniDefault::g_gameUISettingAllowedFOV_Max;
//		}
//		return val;
//	}
//
//
//
//
//	//! this is first and foremost to get a val in the file that is not ridiculous, there is another check down the road
//	static int getClampedColorVal(int val) {
//
//		if (val > (int)SWF_CUSTOM_NAMED_COLOR_INVISIBLE || val < (int)SWF_CUSTOM_NAMED_COLOR_DEFAULT) {
//			logWarn("getClampedColorVal: found out of bound value in ini file: %d setting value to default: %d", val, (int)SWF_CUSTOM_NAMED_COLOR_DEFAULT);
//			return (int)SWF_CUSTOM_NAMED_COLOR_DEFAULT;
//		}		
//		return val;
//	}
//
//	static float roundToDecimalPlaces(float value, int decimalPlaces) {
//		// Calculate the multiplier based on the desired decimal places
//		float multiplier = 1.0f;
//		for (int i = 0; i < decimalPlaces; ++i) {
//			multiplier *= 10.0f;
//		}
//		// Round the value to the specified number of decimal places
//		float roundedValue = std::round(value * multiplier) / multiplier;
//		return roundedValue;
//	}
//
//	//! input between 0 and 200
//	static float getFloatFromReticleScaleInt(int valInt) {
//		float valFloat = 0;
//		if (valInt >= IniDefault::g_userMaxReticleScaleIntValue) {
//			valFloat = IniDefault::g_userMaxReticleScale;
//		}
//		else if (valInt <= IniDefault::g_userMinReticleScaleIntValue) {
//			valFloat = IniDefault::g_userMinReticleScale;
//		}
//		else {
//			float rawFloat = (float)valInt / 100.0f;
//			valFloat = roundToDecimalPlaces(rawFloat, 2);
//		}		
//		logInfo("getFloatFromReticleScaleInt: returning : %.3f (3 decimal places)", valFloat);
//		return valFloat;
//		//return g_userMinReticleScale + 1.8f * (float)val / g_userMaxReticleScaleFloatValue;
//	}
//
//	static int getReticleScaleIntFromFloat(float scale) {
//		return (int)(scale * IniDefault::g_userMaxSensIntValue);
//	}
//
//	static float getFloatFromSensInt(int val) {
//
//		if (val > IniDefault::g_userMaxSensIntValue) {
//			return IniDefault::g_maxSensValue;
//		}
//		if (val <= 0) {
//			return IniDefault::g_minSensValue;
//		}
//		return (float)val / (float)IniDefault::g_userMaxSensIntValue;
//	}
//
//	static int getIntSensFromFloat(float sens) {
//		return (int)(sens * IniDefault::g_userMaxSensIntValue);
//	}
//
//	
//
//	static std::string getBoolAsStr(bool boolVal) {
//		if (boolVal) {
//			return "yes";
//		}
//		return "no";
//	}
//
//	static std::string getStrFromVkKey(unsigned int vkKey) {
//		auto it = vKToKeyStrMap.find(vkKey);
//		if (it != vKToKeyStrMap.end()) {
//			return it->second;
//		}
//		return "unknown vkKey";
//	}
//
//
//
//	static void debugPrint() {
//		logInfo("");
//		logInfo("IniFileData:debugPrint: (all float vals are .3f)");
//		logInfo("m_iniFileVersionInt: %d", m_iniFileVersionInt);
//
//		logInfo("m_assaultRiflePrecisionBoltMouseSens: %.3f", m_assaultRiflePrecisionBoltMouseSens);
//		logInfo("m_assaultRiflePrecisionBoltControllerSens: %.3f", m_assaultRiflePrecisionBoltControllerSens);
//		logInfo("m_ballistaArbalestMouseSens: %.3f", m_ballistaArbalestMouseSens);
//		logInfo("m_ballistaArbalestControllerSens: %.3f", m_ballistaArbalestControllerSens);
//
//		logInfo("m_isPlayModLoadedBeep: %s", m_isPlayModLoadedBeep ? "true" : "false");
//		logInfo("m_isOverideShotgunConfig: %s", m_isOverideShotgunConfig ? "true" : "false");
//		logInfo("m_isRemoveBalistaZoom: %s", m_isRemoveBalistaZoom ? "true" : "false");
//		logInfo("m_isImprovedWeaponSwitching: %s", m_isImprovedWeaponSwitching ? "true" : "false");
//		logInfo("m_isImprovedWeaponSwitchingBeep: %s", m_isImprovedWeaponSwitchingBeep ? "true" : "false");
//
//		logInfo("m_reloadIniFileVkCode: %u", m_reloadIniFileVkCode);
//		logInfo("m_isIniFileAutoReload: %s", m_isIniFileAutoReload ? "true" : "false");
//
//		logInfo("m_gameUiSettingsMaxFov: %d", m_gameUiSettingsMaxFov);
//		logInfo("m_handsFOV: %d", m_handsFOV);
//
//		logInfo("m_reticleScale: %.3f", m_reticleScale);
//		logInfo("m_immersiveCrosshairLevel: %d", m_immersiveCrosshairLevel);
//
//		logInfo("m_OverrideDotReticleColor: %d", m_OverrideDotReticleColor);
//		logInfo("m_OverrideDotReticleCooldownColor: %d", m_OverrideDotReticleCooldownColor);
//		logInfo("m_OverrideDotReticleFragNadeReadyColor: %d", m_OverrideDotReticleFragNadeReadyColor);
//		logInfo("m_OverrideDotReticleIceNadeReadyColor: %d", m_OverrideDotReticleIceNadeReadyColor);
//		logInfo("m_OverrideDotReticleBothNadeReadyColor: %d", m_OverrideDotReticleBothNadeReadyColor);
//
//		logInfo("m_OverrideBloodPunchColor1: %d", m_OverrideBloodPunchColor1);
//		logInfo("m_OverrideBloodPunchColor2: %d", m_OverrideBloodPunchColor2);
//		logInfo("m_OverrideDesperatePunchColor: %d", m_OverrideDesperatePunchColor);
//
//		logInfo("m_OverrideFuel3PipsColor: %d", m_OverrideFuel3PipsColor);
//
//		logInfo("m_OverrideFragGrenadeAvailable_Color: %d", m_OverrideFragGrenadeAvailable_Color);
//		logInfo("m_OverrideIceGrenadeAvailable__Color: %d", m_OverrideIceGrenadeAvailable__Color);
//		logInfo("m_OverrideIceGrenadeCoolDown_Color: %d", m_OverrideIceGrenadeCoolDown_Color);
//
//		logInfo("m_IsWeaponBarColored: %s", m_IsWeaponBarColored ? "true" : "false");
//		logInfo("m_OverrideRadMeterColor: %d", m_OverrideRadMeterColor);
//
//		logInfo("m_isRemoveBindsReminderOnHud: %s", m_isRemoveBindsReminderOnHud ? "true" : "false");
//		logInfo("m_isDashBlurEffectDisabled: %s", m_isDashBlurEffectDisabled ? "true" : "false");
//		logInfo("m_isHitMarkerDisabled: %s", m_isHitMarkerDisabled ? "true" : "false");
//
//		logInfo("m_userDebugLevelInt: %d", m_userDebugLevelInt);
//
//		logInfo("");
//
//	}
//
//	
//	
//	/*float getCrosshairSize() {
//		return m_crosshairSize;
//	}
//
//	float getCrosshairOutlineThickness() {
//		return m_crosshairOutlineThickness;
//	}*/
//
//
//
//	/*bool getIsAmmoBar() {
//		return m_isAmmoBar;
//	}*/
//
//
//	/*bool getIsBloodPunchColorOverride() {
//		logInfo("getIsBloodPunchColorOverride: val is %d", m_isOverrideBloodPunchColor);
//		return m_isOverrideBloodPunchColor;
//	}*/
//
//	/*bool getIsRadSuitColorOverride() {
//		return m_isOverriRadSuitBarColor;
//	}*/
//
//};
//
//int IniFileData::m_iniFileVersionInt = Config::getShortModVersionAsInt();
//float IniFileData::m_assaultRiflePrecisionBoltMouseSens = IniDefault::g_defaultPrecisionBoltMouseSens;
//float IniFileData::m_assaultRiflePrecisionBoltControllerSens = IniDefault::g_defaultPrecisionBoltControllerSens;
//float IniFileData::m_ballistaArbalestMouseSens = IniDefault::g_defaultBallistaArbalesteMouseSens;
//float IniFileData::m_ballistaArbalestControllerSens = IniDefault::g_defaultBallistaArbalesteControllerSens;
//bool IniFileData::m_isPlayModLoadedBeep = IniDefault::g_defaultIsSoundBeepWhenModLoaded;
//
//bool IniFileData::m_isOverideShotgunConfig = IniDefault::g_defaultIsOverideShotgunConfig;
//bool IniFileData::m_isRemoveBalistaZoom = IniDefault::g_defaultIsRemoveBalistaZoom;
//
//bool IniFileData::m_isImprovedWeaponSwitching = IniDefault::g_defaultIsImprovedWeaponSwitchEnabled;
//bool IniFileData::m_isImprovedWeaponSwitchingBeep = IniDefault::g_defaultIsImprovedWeaponSwitchBeep;
//unsigned int IniFileData::m_reloadIniFileVkCode = IniDefault::g_defaultReloadIniFileVkey;
//bool IniFileData::m_isIniFileAutoReload = IniDefault::g_defaultIsIniFileAutoReload;
//
//int IniFileData::m_gameUiSettingsMinFov = IniDefault::g_defaultGameUISettingMinFOV;
//int IniFileData::m_gameUiSettingsMaxFov = IniDefault::g_defaultGameUISettingMaxFOV;
//
//int IniFileData::m_handsFOV = IniDefault::g_defaultHandsFOV;
//float IniFileData::m_reticleScale = Reticle::g_defaultReticleScale;
////float IniFileData::m_reticleScaleADS = IniDefault::g_defaultReticleScaleADS;
//
////bool IniFileData::m_isOnlyShowCrosshairInHARScope = IniDefault::g_defaultOnlyShowCrosshairInHARScope;
//int IniFileData::m_immersiveCrosshairLevel = IniDefault::g_defaultImmersiveCrosshairLevel;
//
//int IniFileData::m_OverrideDotReticleColor = IniDefault::g_defaultOverrideDotReticleColor;
//int IniFileData::m_OverrideDotReticleCooldownColor = IniDefault::g_defaultOverrideDotReticleCooldownColor;
//
//int IniFileData::m_OverrideDotReticleFragNadeReadyColor = IniDefault::g_defaultOverrideDotReticleFragNadeReadyColor;
//int IniFileData::m_OverrideDotReticleIceNadeReadyColor = IniDefault::g_defaultOverrideDotReticleIceNadeReadyColor;
//int IniFileData::m_OverrideDotReticleBothNadeReadyColor = IniDefault::g_defaultOverrideDotReticleBothNadesReadyColor;
//
//int IniFileData::m_OverrideBloodPunchColor1 = IniDefault::g_defaultOverrideBloodPunchColor1;
//int IniFileData::m_OverrideBloodPunchColor2 = IniDefault::g_defaultOverrideBloodPunchColor2;
//
//int IniFileData::m_OverrideDesperatePunchColor = IniDefault::g_defaultOverrideDesperatePunchColor;
//
//int IniFileData::m_OverrideFuel3PipsColor = IniDefault::g_defaultOverrideFuel3Pips_Color;
//
//int IniFileData::m_OverrideFragGrenadeAvailable_Color = IniDefault::g_defaultOverrideFragGrenadeAvailable_Color;
//int IniFileData::m_OverrideFragGrenadeCoolDown_Color = IniDefault::g_defaultOverrideFragGrenadeCooldown_Color;
//
//
//int IniFileData::m_OverrideIceGrenadeAvailable__Color = IniDefault::g_defaultOverrideIceGrenadeAvailable_Color;
//int IniFileData::m_OverrideIceGrenadeCoolDown_Color = IniDefault::g_defaultOverrideIceGrenadeCoolDown_Color;
//
//bool IniFileData::m_IsWeaponBarColored = IniDefault::g_defaultIsWeaponBarColored;
//
//
//int IniFileData::m_OverrideRadMeterColor = IniDefault::g_defaultOverrideRadMeterColor;
//
//bool IniFileData::m_isRemoveBindsReminderOnHud = IniDefault::g_defaultIsRemoveBindsReminderOnHud;
//
//bool IniFileData::m_isDashBlurEffectDisabled = IniDefault::g_defaultIsDashBlurEffectDisabled;
//
//bool IniFileData::m_isHitMarkerDisabled = IniDefault::g_defaultIsHitMarkerDisabled;
//
//
//int IniFileData::m_userDebugLevelInt = IniDefault::g_defaultUserDebugLevelInt;
//
//
