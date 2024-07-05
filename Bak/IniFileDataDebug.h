//#pragma once
//#include <windows.h>
//#include <string>
//#include <iostream>
//#include "../DE/CommonDE.h"
//#include "../Config/Config.h"
//
//
//
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
//	float m_assaultRiflePrecisionBoltMouseSens = g_defaultPrecisionBoltMouseSens;
//	float m_assaultRiflePrecisionBoltControllerSens = g_defaultPrecisionBoltControllerSens;
//	float m_ballistaArbalestMouseSens = g_defaultBallistaArbalesteMouseSens;
//	float m_ballistaArbalestControllerSens = g_defaultBallistaArbalesteControllerSens;
//	bool m_isPlayModLoadedBeep = g_defaultIsSoundBeepWhenModLoaded;
//	bool m_isOverideShotgunConfig = defaultIsOverideShotgunConfig;
//	bool m_isImprovedWeaponSwitching = g_defaultIsImprovedWeaponSwitchEnabled;
//	bool m_isImprovedWeaponSwitchingBeep = g_defaultIsImprovedWeaponSwitchBeep;
//	unsigned int m_reloadIniFileVkCode = g_defaultReloadIniFileVkey;
//	int m_handsFOV = defaultHandsFOV;
//
//	bool m_isOnlyShowCrosshairInHARScope = defaultOnlyShowCrosshairInHARScope;
//	int m_OverrideBloodPunchColorSet = defaultOverrideBloodPunchColorSet; // 0 to 10 and each value is 3 colors (no bp, 1bp, 2bp)
//	int m_OverrideGrenadeArrowColorSet = defaultOverrideGrenadeArrowColorSet; // 0 to 10 and each value is 2 colors (1 for nade 1 for ice)
//	int m_OverrideRadMeterColor = defaultOverrideRadMeterColor; // 0 to 10 and each value is a 1 color
//	bool m_isRemoveBindsReminderOnHud = defaultIsRemoveBindsReminderOnHud; //
//
//
//public:
//
//	void resetToDefault() {
//		//m_crosshairSize = defaultCrosshairSize;
//		//m_crosshairOutlineThickness = defaultCrosshairOutlineThickness;
//
//		//m_isAmmoBar = defaultIsAmmoBar;
//		//m_isOverrideBloodPunchColor = defaultIsOverrideBloodPunchColor;
//		//m_isOverriRadSuitBarColor = defaultIsOverriRadSuitBarColor;
//
//		m_assaultRiflePrecisionBoltMouseSens = g_defaultPrecisionBoltMouseSens;
//		m_assaultRiflePrecisionBoltControllerSens = g_defaultPrecisionBoltControllerSens;
//		m_ballistaArbalestMouseSens = g_defaultBallistaArbalesteMouseSens;
//		m_ballistaArbalestControllerSens = g_defaultBallistaArbalesteControllerSens;
//		m_isPlayModLoadedBeep = g_defaultIsSoundBeepWhenModLoaded;
//		m_isOverideShotgunConfig = defaultIsOverideShotgunConfig;
//		m_isImprovedWeaponSwitching = g_defaultIsImprovedWeaponSwitchEnabled;
//		m_isImprovedWeaponSwitchingBeep = g_defaultIsImprovedWeaponSwitchBeep;
//		m_reloadIniFileVkCode = g_defaultReloadIniFileVkey;
//		m_handsFOV = defaultHandsFOV;
//
//		m_isOnlyShowCrosshairInHARScope = defaultOnlyShowCrosshairInHARScope;
//		m_OverrideBloodPunchColorSet = defaultOverrideBloodPunchColorSet;
//		m_OverrideGrenadeArrowColorSet = defaultOverrideGrenadeArrowColorSet;
//		m_OverrideRadMeterColor = defaultOverrideRadMeterColor;
//		m_isRemoveBindsReminderOnHud = defaultIsRemoveBindsReminderOnHud;
//	}
//
//
//	//! this is used to generate/update the ini file
//
//	/*int getCrosshairSizeInt() {
//		return (int)m_crosshairSize;
//	}*/
//
//	/*int getCrosshairOutlineThicknessInt() {
//		return (int)m_crosshairOutlineThickness;
//	}*/
//
//
//
//	/*std::string getIsAmmoBarStr() {
//		return getBoolAsStr(m_isAmmoBar);
//	}*/
//
//	/*std::string getIsOverrideBloodPunchColorStr() {
//		return getBoolAsStr(m_isOverrideBloodPunchColor);
//	}*/
//
//	/*std::string getIsOverriRadSuitBarColorStr() {
//		return getBoolAsStr(m_isOverriRadSuitBarColor);
//	}*/
//
//	int getassaultRiflePrecisionBoltMouseSensInt() {
//		return getIntSensFromFloat(m_assaultRiflePrecisionBoltMouseSens);
//	}
//	int getssaultRiflePrecisionBoltControllerSensInt() {
//
//		//int val = getIntSensFromFloat(m_assaultRiflePrecisionBoltControllerSens);
//		/*spdlog::warn("IniFileData: getssaultRiflePrecisionBoltControllerSensInt, debug: m_assaultRiflePrecisionBoltControllerSens {} val:  {}", m_assaultRiflePrecisionBoltControllerSens, val);*/
//		return getIntSensFromFloat(m_assaultRiflePrecisionBoltControllerSens);
//	}
//	int getballistaArbalestMouseSensInt() {
//		return getIntSensFromFloat(m_ballistaArbalestMouseSens);
//	}
//	int getballistaArbalestControllerSensInt() {
//		return getIntSensFromFloat(m_ballistaArbalestControllerSens);
//	}
//	std::string getisPlayModLoadedBeepStr() {
//		return getBoolAsStr(m_isPlayModLoadedBeep);
//	}
//	std::string getisOverideShotgunConfigStr() {
//		return getBoolAsStr(m_isOverideShotgunConfig);
//	}
//	std::string getisImprovedWeaponSwitchingStr() {
//		return getBoolAsStr(m_isImprovedWeaponSwitching);
//	}
//	std::string getisImprovedWeaponSwitchingBeepStr() {
//		return getBoolAsStr(m_isImprovedWeaponSwitchingBeep);
//	}
//	std::string getreloadIniFileVkCodeStr() {
//		return getStrFromVkKey(m_reloadIniFileVkCode);
//	}
//	int getHandsFovInt() {
//		return m_handsFOV;
//	}
//
//	//! new
//
//	std::string getIsOnlyShowCrosshairInHARScopeStr() {
//		return getBoolAsStr(m_isOnlyShowCrosshairInHARScope);
//	}
//
//	int getOverrideBloodPunchColorSetInt() {
//		return m_OverrideBloodPunchColorSet;
//	}
//
//	int getOverrideGrenadeArrowColorSetInt() {
//		return m_OverrideGrenadeArrowColorSet;
//	}
//
//	int getOverrideRadMeterColorInt() {
//		return m_OverrideRadMeterColor;
//	}
//
//	std::string getIsRemoveBindsReminderOnHudStr() {
//		return getBoolAsStr(m_isRemoveBindsReminderOnHud);
//	}
//
//
//	//! Getters :
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
//	float getAssaultRiflePrecisionBoltMouseSens() {
//		return m_assaultRiflePrecisionBoltMouseSens;
//	}
//
//	float getAssaultRiflePrecisionBoltControllerSens() {
//		return m_assaultRiflePrecisionBoltControllerSens;
//	}
//
//	float getBallistaArbalestMouseSens() {
//		return m_ballistaArbalestMouseSens;
//	}
//
//	float getBallistaArbalestControllerSens() {
//		return m_ballistaArbalestControllerSens;
//	}
//
//	bool isPlayModLoadedBeep() {
//		return m_isPlayModLoadedBeep;
//	}
//
//	bool isOverideShotgunConfig() {
//		return m_isOverideShotgunConfig;
//	}
//	bool isImprovedWeaponSwitching() {
//		return m_isImprovedWeaponSwitching;
//	}
//
//	bool isImprovedWeaponSwitchingBeep() {
//		return m_isImprovedWeaponSwitchingBeep;
//	}
//
//
//	unsigned int getReloadIniFileVkCode() {
//		return m_reloadIniFileVkCode;
//	}
//
//	int getHandsFOV() {
//		return m_handsFOV;
//	}
//
//	bool getIsOnlyShowCrosshairInHARScope() {
//		return m_isOnlyShowCrosshairInHARScope;
//	}
//
//	int getOverrideBloodPunchColorSet() {
//		return m_OverrideBloodPunchColorSet;
//	}
//
//	int getOverrideGrenadeArrowColorSet() {
//		return m_OverrideGrenadeArrowColorSet;
//	}
//
//	int getOverrideRadMeterColor() {
//		return m_OverrideRadMeterColor;
//	}
//
//	bool getIsRemoveBindsReminderOnHud() {
//		return m_isRemoveBindsReminderOnHud;
//	}
//
//
//
//	//! setters:
//
//
//	/*void setCrosshairSize(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_crosshairSize = defaultCrosshairSize;
//			logWarn("IniFileData: parsed wrong value for m_crosshairSize, using default value: %.2f", defaultCrosshairSize);
//		}
//		else {
//			if (iniFileVal >= 30) {
//				m_crosshairSize = 30.0f;
//			}
//			else if (iniFileVal <= 2) {
//				m_crosshairSize = 2.0f;
//			}
//			else {
//				m_crosshairSize = (float)iniFileVal;
//			}
//		}
//	}*/
//
//	/*void setCrosshairOulineThickness(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_crosshairOutlineThickness = defaultCrosshairOutlineThickness;
//			logWarn("IniFileData: parsed wrong value for m_crosshairOutlineThickness, using default value:%.2f", defaultCrosshairOutlineThickness);
//		}
//		else {
//			if (iniFileVal >= 4) {
//				m_crosshairOutlineThickness = 4.0f;
//			}
//			else if (iniFileVal <= 1) {
//				m_crosshairOutlineThickness = 1.0f;
//			}
//			else {
//				m_crosshairOutlineThickness = (float)iniFileVal;
//			}
//		}
//	}*/
//
//
//
//
//	/*void setIsAmmoBar(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_isAmmoBar = defaultIsAmmoBar;
//			logWarn("IniFileData: parsed wrong value for m_isAmmoBar, using default value: %d", defaultIsAmmoBar);
//		}
//		else {
//			m_isAmmoBar = (bool)iniFileVal;
//		}
//	}*/
//
//	/*void setIsBloodPunchOverride(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_isOverrideBloodPunchColor = defaultIsOverrideBloodPunchColor;
//			logWarn("IniFileData: parsed wrong value for m_isOverrideBloodPunchColor, using default value: %d", defaultIsOverrideBloodPunchColor);
//		}
//		else {
//			m_isOverrideBloodPunchColor = (bool)iniFileVal;
//		}
//	}*/
//
//	/*void setIsRadSuitOverrideColor(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_isOverriRadSuitBarColor = defaultIsOverriRadSuitBarColor;
//			logWarn("IniFileData: parsed wrong value for m_isOverriRadSuitBarColor, using default value: %d", defaultIsOverriRadSuitBarColor);
//		}
//		else {
//			m_isOverriRadSuitBarColor = (bool)iniFileVal;
//		}
//	}*/
//
//
//	void setReloadIniFileVkCode(const char* c_charPtr) {
//
//		if (c_charPtr == 0) {
//
//			std::string defaultReloadKeyStr = getStrFromVkKey(g_defaultReloadIniFileVkey);
//			logWarn("IniFileData: setReloadIniFileVkCode, c_charPtr is null, setting default keycode: %X (%s)", g_defaultReloadIniFileVkey, defaultReloadKeyStr.c_str());
//			m_reloadIniFileVkCode = g_defaultReloadIniFileVkey;
//		}
//		else {
//			try
//			{
//				std::string strVal = c_charPtr;
//				m_reloadIniFileVkCode = keyStrToVK_KeyMap.at(strVal);
//			}
//			catch (const std::exception& ex)
//			{
//				logErr("IniFileData: setReloadIniFileVkCode, exception error: %s setting reload ini file key to default", ex.what());
//				m_reloadIniFileVkCode = g_defaultReloadIniFileVkey;
//			}
//		}
//	}
//
//	void setIsPlayModLoadedBeepVal(int val) {
//		if (val == iniFileBoolNotFoundVal) {
//			m_isPlayModLoadedBeep = g_defaultIsSoundBeepWhenModLoaded;
//			logWarn("IniFileData: parsed wrong value for isPlayModLoadedBeep, using default value: %d", g_defaultIsSoundBeepWhenModLoaded);
//		}
//		else {
//			m_isPlayModLoadedBeep = (bool)val;
//		}
//	}
//
//	void setIsImprovedShotgunConfigVal(int val) {
//		if (val == iniFileBoolNotFoundVal) {
//			m_isOverideShotgunConfig = defaultIsOverideShotgunConfig;
//			logWarn("IniFileData: parsed wrong value for isOverideShotgunConfig, using default value: %d", defaultIsOverideShotgunConfig);
//		}
//		else {
//			m_isOverideShotgunConfig = (bool)val;
//		}
//	}
//
//	void setIsImprovedSwitchingVal(int val) {
//		if (val == iniFileBoolNotFoundVal) {
//			m_isImprovedWeaponSwitching = g_defaultIsImprovedWeaponSwitchEnabled;
//			logWarn("IniFileData: parsed wrong value for isImprovedWeaponSwitching, using default value: %d", g_defaultIsImprovedWeaponSwitchEnabled);
//		}
//		else {
//			m_isImprovedWeaponSwitching = (bool)val;
//		}
//	}
//
//	void setIsImprovedSwitchingBeepVal(int val) {
//		if (val == iniFileBoolNotFoundVal) {
//			m_isImprovedWeaponSwitchingBeep = g_defaultIsImprovedWeaponSwitchBeep;
//			logWarn("IniFileData: parsed wrong value for isImprovedWeaponSwitchingBeep, using default value: %d", g_defaultIsImprovedWeaponSwitchBeep);
//		}
//		else {
//			m_isImprovedWeaponSwitchingBeep = (bool)val;
//		}
//	}
//
//	void setBoltMouseSens(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_assaultRiflePrecisionBoltMouseSens = g_defaultPrecisionBoltMouseSens;
//			logWarn("IniFileData: parsed wrong value for assaultRiflePrecisionBoltMouseSens, using default value: %.2f", g_defaultPrecisionBoltMouseSens);
//		}
//		else {
//			m_assaultRiflePrecisionBoltMouseSens = getFloatFromSensInt(iniFileVal);
//		}
//	}
//
//	void setBoltControllerSens(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_assaultRiflePrecisionBoltControllerSens = g_defaultPrecisionBoltControllerSens;
//			logWarn("IniFileData: parsed wrong value for assaultRiflePrecisionBoltControllerSens, using default value: %.2f", g_defaultPrecisionBoltControllerSens);
//		}
//		else {
//			m_assaultRiflePrecisionBoltControllerSens = getFloatFromSensInt(iniFileVal);
//
//		}
//	}
//
//	void setArbalestMouseSens(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_ballistaArbalestMouseSens = g_defaultBallistaArbalesteMouseSens;
//			logWarn("IniFileData: parsed wrong value for ballistaArbalestMouseSens, using default value: %.2f", g_defaultBallistaArbalesteMouseSens);
//		}
//		else {
//			m_ballistaArbalestMouseSens = getFloatFromSensInt(iniFileVal);
//		}
//	}
//
//	void setArbalestControllerSens(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_ballistaArbalestControllerSens = g_defaultBallistaArbalesteControllerSens;
//			logWarn("IniFileData: parsed wrong value for ballistaArbalestControllerSens, using default value: %.2f", g_defaultBallistaArbalesteControllerSens);
//		}
//		else {
//			m_ballistaArbalestControllerSens = getFloatFromSensInt(iniFileVal);
//		}
//	}
//
//	void setHandsFOV(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_handsFOV = defaultHandsFOV;
//			logWarn("IniFileData: parsed wrong value for m_handsFOV, using default value: %d", defaultHandsFOV);
//		}
//		else {
//			m_handsFOV = iniFileVal;
//		}
//	}
//
//
//	//! new
//
//	void setIsOnlyShowCrosshairInHARScope(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_isOnlyShowCrosshairInHARScope = defaultOnlyShowCrosshairInHARScope;
//			logWarn("IniFileData: parsed wrong value for m_isOnlyShowCrosshairInHARScope, using default value: %d", defaultOnlyShowCrosshairInHARScope);
//		}
//		else {
//			m_isOnlyShowCrosshairInHARScope = (bool)iniFileVal;
//		}
//	}
//
//	void setOverrideBloodPunchColorSet(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_OverrideBloodPunchColorSet = defaultOverrideBloodPunchColorSet;
//			logWarn("IniFileData: parsed wrong value for m_OverrideBloodPunchColorSet, using default value: %d", defaultOverrideBloodPunchColorSet);
//		}
//		else {
//			m_OverrideBloodPunchColorSet = iniFileVal;
//		}
//	}
//
//	void setOverrideGrenadeArrowColorSet(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_OverrideGrenadeArrowColorSet = defaultOverrideGrenadeArrowColorSet;
//			logWarn("IniFileData: parsed wrong value for m_OverrideGrenadeArrowColorSet, using default value: %d", defaultOverrideGrenadeArrowColorSet);
//		}
//		else {
//			m_OverrideGrenadeArrowColorSet = iniFileVal;
//		}
//	}
//
//	void setOverrideRadMeterColor(int iniFileVal) {
//		if (iniFileVal == iniFileIntNotFoundVal) {
//			m_OverrideRadMeterColor = defaultOverrideRadMeterColor;
//			logWarn("IniFileData: parsed wrong value for m_OverrideRadMeterColor, using default value: %d", defaultOverrideRadMeterColor);
//		}
//		else {
//			m_OverrideRadMeterColor = iniFileVal;
//		}
//	}
//
//	void setisRemoveBindsReminderOnHud(int iniFileVal) {
//		if (iniFileVal == iniFileBoolNotFoundVal) {
//			m_isRemoveBindsReminderOnHud = defaultIsRemoveBindsReminderOnHud;
//			logWarn("IniFileData: parsed wrong value for m_isRemoveBindsReminderOnHud, using default value: %d", defaultIsRemoveBindsReminderOnHud);
//		}
//		else {
//			m_isRemoveBindsReminderOnHud = (bool)iniFileVal;
//		}
//	}
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
//
//
//	float getFloatFromSensInt(int val) {
//
//		if (val > 100) {
//			return 1.0f;
//		}
//		if (val <= 0) {
//			return 0.0f;
//		}
//		return (float)val / 100;
//	}
//
//	int getIntSensFromFloat(float sens) {
//		return (int)(sens * 100);
//	}
//
//	std::string getBoolAsStr(bool boolVal) {
//		if (boolVal) {
//			return "yes";
//		}
//		return "no";
//	}
//
//	std::string getStrFromVkKey(unsigned int vkKey) {
//		auto it = vKToKeyStrMap.find(vkKey);
//		if (it != vKToKeyStrMap.end()) {
//			return it->second;
//		}
//		return "unknown vkKey";
//	}
//
//
//	//void debugPrint() {
//	//	logInfo("IniFileData:debugPrint:");
//	//	logInfo("m_assaultRiflePrecisionBoltMouseSens: %.2f", m_assaultRiflePrecisionBoltMouseSens);
//	//	logInfo("m_assaultRiflePrecisionBoltControllerSens: %.2f", m_assaultRiflePrecisionBoltControllerSens);
//	//	logInfo("m_ballistaArbalestMouseSens: %.2f", m_ballistaArbalestMouseSens);
//	//	logInfo("m_ballistaArbalestControllerSens: %.2f", m_ballistaArbalestControllerSens);
//	//	logInfo("m_isPlayModLoadedBeep: %d", m_isPlayModLoadedBeep);
//	//	logInfo("m_isOverideShotgunConfig: %d", m_isOverideShotgunConfig);
//	//	logInfo("m_isImprovedWeaponSwitching: %d", m_isImprovedWeaponSwitching);
//	//	logInfo("m_isImprovedWeaponSwitchingBeep: %d", m_isImprovedWeaponSwitchingBeep);
//	//	logInfo("m_reloadIniFileVkCode: (hex)%X (%s)", m_reloadIniFileVkCode, getStrFromVkKey(m_reloadIniFileVkCode).c_str());
//	//	/*logInfo("m_crosshairSize: %.2f", m_crosshairSize);
//	//	logInfo("m_crosshairOutlineThickness: %.2f", m_crosshairOutlineThickness);
//	//	logInfo("m_isOnlyShowCrosshairInHARScope: %d", m_isOnlyShowCrosshairInHARScope);
//	//	logInfo("m_isAmmoBar: %d", m_isAmmoBar);
//	//	logInfo("m_isOverrideBloodPunchColor: %d", m_isOverrideBloodPunchColor);
//	//	logInfo("m_isOverriRadSuitBarColor: %d", m_isOverriRadSuitBarColor);*/
//	//}
//
//	void debugPrint() {
//		logInfo("IniFileData:debugPrint:");
//		logInfo("m_assaultRiflePrecisionBoltMouseSens: %.2f", m_assaultRiflePrecisionBoltMouseSens);
//		logInfo("m_assaultRiflePrecisionBoltControllerSens: %.2f", m_assaultRiflePrecisionBoltControllerSens);
//		logInfo("m_ballistaArbalestMouseSens: %.2f", m_ballistaArbalestMouseSens);
//		logInfo("m_ballistaArbalestControllerSens: %.2f", m_ballistaArbalestControllerSens);
//		logInfo("m_isPlayModLoadedBeep: %d", m_isPlayModLoadedBeep);
//		logInfo("m_isOverideShotgunConfig: %d", m_isOverideShotgunConfig);
//		logInfo("m_isImprovedWeaponSwitching: %d", m_isImprovedWeaponSwitching);
//		logInfo("m_isImprovedWeaponSwitchingBeep: %d", m_isImprovedWeaponSwitchingBeep);
//		logInfo("m_reloadIniFileVkCode: (hex)%X (%s)", m_reloadIniFileVkCode, getStrFromVkKey(m_reloadIniFileVkCode).c_str());
//		logInfo("m_handsFOV: %d", m_handsFOV);
//		logInfo("m_isOnlyShowCrosshairInHARScope: %d", m_isOnlyShowCrosshairInHARScope);
//		logInfo("m_OverrideBloodPunchColorSet: %d", m_OverrideBloodPunchColorSet);
//		logInfo("m_OverrideGrenadeArrowColorSet: %d", m_OverrideGrenadeArrowColorSet);
//		logInfo("m_OverrideRadMeterColor: %d", m_OverrideRadMeterColor);
//		logInfo("m_isRemoveBindsReminderOnHud: %d", m_isRemoveBindsReminderOnHud);
//	}
//
//
//};
//
