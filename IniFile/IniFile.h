//#pragma once
//
//
//#include <windows.h>
//#include <filesystem> //C++ 17
//#include <string>
//#include <iostream>
//#include <Shlwapi.h>
//#include <iostream>
//#include <filesystem>
//#include <chrono>
//#include <ctime>
//#include <sys/stat.h>
//#include "dictionary.h"
//#include "iniparser.h"
//#include "IniFileData.h"
////#include "Config.h"
//#include "../Config/Config.h"
//#include "IniStrings.h"
//
//
//
//namespace fs = std::filesystem;
////#include "Common.h"
//
//
//
////#define _CRT_SECURE_NO_WARNINGS
//
////#ifdef _MSC_VER
////#define _CRT_SECURE_NO_WARNINGS
////#endif
//
//class IniFile
//{
//
//private:
//	const std::string m_iniFileName = g_iniFileName;
//	std::string m_modDirectoryPath = "";
//	std::string m_iniFilePath = "";
//	IniFileStatus m_lastLoadStatus = IniFileStatus::iniFileStatusUnknown;
//	uint64_t m_lastSaveMs = 0;
//	int m_saveCount = 0;
//
//
//public:
//
//	void printStatus() {
//		logDebug("printStatus");
//
//		std::string lastStatusAsStr = getIniFileStatusStr(m_lastLoadStatus);
//		if (m_lastSaveMs == 0) {
//			logInfo("IniFile status: Mod directory: %s Ini File Path: %s Last save: NEVER. Last load status: %s", m_modDirectoryPath.c_str(), m_iniFilePath.c_str(), lastStatusAsStr.c_str());
//			
//		}
//		else {
//			uint64_t lastSaveInSeconds = (EpochMillis() - m_lastSaveMs)/1000;
//			logInfo("IniFile status: Mod directory: %s Ini File Path: %s last save: %llu seconds ago. Last load status: %s ", m_modDirectoryPath.c_str(), m_iniFilePath.c_str(), lastSaveInSeconds, lastStatusAsStr.c_str());
//		}
//	}
//
//	std::string getIniFileStatusStr(IniFileStatus status) {
//		logDebug("getIniFileStatusStr");
//
//		switch (status) {
//		case iniFileStatusUnknown:
//			return "iniFileStatusUnknown, error finding ini file. This should not happen.";
//		case iniFileUndefined:
//			return "iniFileUndefined. This should not happen, contact the mod author on nexxus.";
//		case iniFileVersionMismatch:
//			return "iniFileVersionMismatch, a new ini file should have been generated.";
//		case iniFileSavingDefault:
//			return "iniFileSavingDefault, could not find an ini file, creating new one.";
//		case iniFileLoaded:
//			return "iniFileLoaded, ini file correctly loaded.";
//		case iniFileParsingError:
//			return "iniFileParsingError, could not parse some of the values, may be deleting the ini file and relaunching the game would be a good idea.";
//		case iniFileExceptionError:
//			return "iniFileExceptionError. This should not happen, contact the mod author on nexxus.";
//		default:
//			return "Unknown Error.";
//		}
//	}
//
//	IniFileStatus getlastLoadStatus() {
//		return m_lastLoadStatus;
//	}
//
//	std::string getIniFilePath() const {
//		return m_iniFilePath;
//	}
//
//	void load() {
//		logDebug("load");
//
//		//logInfo("load() called");
//		//IniFileStatus iniFileStatus = iniFileUndefined;
//
//		try
//		{
//			if (m_iniFilePath == "") {
//				GetIniFilePath();
//			}
//		
//			if (!isIniFileExist()) {
//				//? can not have a log here as it would/could mess with the console window see ModMain func start for more info
//				logWarn("load: Ini file does not exist, creating ini file with default values...");
//				//! if we're here, saveFile will use default values.
//				m_lastLoadStatus = iniFileSavingDefault;
//				saveFile();
//			}
//			else {
//				/*if (IniFileData::getIniFileVersion() != Config::getShortModVersionAsInt()) {
//				IniFileData::resetToDefault();
//				m_lastLoadStatus = iniFileVersionMismatch;
//				saveFile();
//				}*/
//				if (!isParseIniFileData()) {
//					//logErr("error parsing ini file");
//					//IniFileData::resetToDefault();
//					m_lastLoadStatus = iniFileParsingError;
//					saveFile();
//				}			
//				else {
//					//! saving file at mod start so that the file gets regenerated in case user has deleted some elements last session. Basically regenerating ini file but keeping its user values, we do it only once because we don't want to trigger the auto reload everytime we save and get in an infinite loop, but because load() is called before FileWatcher initialization this should work.
//					if (m_saveCount == 0) {
//						saveFile();
//					}
//					m_lastLoadStatus = iniFileLoaded;
//				}
//			}
//			
//			//return iniFileStatus;
//		}
//		catch (const std::exception) {
//	
//			//logErr("load(): exception %s" ,ex.what());
//			m_lastLoadStatus = iniFileExceptionError;
//		}		
//	}
//
//
//	std::string WStringToString(const std::wstring& wstr)
//	{
//		logDebug("WStringToString");
//
//		std::string str;
//		size_t size;
//		str.resize(wstr.length());
//		wcstombs_s(&size, &str[0], str.size() + 1, wstr.c_str(), wstr.size());
//		return str;
//	}
//
//
//	void GetIniFilePath()
//	{
//		//logDebug("GetIniFilePath");
//
//		try
//		{
//			std::wstring PathAndName;
//			std::wstring OnlyPath;
//			const int BUFSIZE = 4096;
//			wchar_t buffer[BUFSIZE];
//			//if (::GetModuleFileNameW(m_DllHandle, buffer, BUFSIZE - 1) <= 0)
//			if (::GetModuleFileNameW(NULL, buffer, BUFSIZE - 1) <= 0)
//			{
//				logErr("GetIniFilePath: GetModuleFileNameW < 0 can not get ini file path, mod may not function correctly. Close the game, delete the ini file and relaunch the game.");
//			}
//			else {
//				PathAndName = buffer;
//				size_t found = PathAndName.find_last_of(L"/\\");
//				OnlyPath = PathAndName.substr(0, found);
//				//std::wcout << "IniFile::GetIniFilePath: dll path: " << OnlyPath << std::endl;
//				m_modDirectoryPath = WStringToString(OnlyPath);
//				fs::path dir(m_modDirectoryPath);
//				fs::path file(m_iniFileName);
//				fs::path full_path = dir / file;
//				m_iniFilePath = full_path.generic_string();
//				//m_iniFilePath = PathCombine(dirPath, m_iniFileName);
//				//m_iniFilePath = dirPath + '\\' + m_iniFileName;
//				//m_iniFilePath = dirPath + "/" + m_iniFileName;
//				logInfo("GetIniFilePath: m_modDirectoryPath: %s m_iniFilePath: %s", m_modDirectoryPath.c_str(), m_iniFilePath.c_str());
//			}
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("IniFile::GetIniFilePath: ERROR: %s setting m_iniFilePath to empty. Mod may not function correctly. Close the game, delete the ini file and relaunch the game.", ex.what());
//			m_iniFilePath = "";
//		}
//	}
//
//	bool isIniFileExist()
//	{
//		logDebug("isIniFileExist");
//
//		//return PathIsDirectoryA((LPCSTR)m_iniFilePath.c_str());
//		//return PathIsDirectoryA(m_iniFilePath.c_str());
//		//if (PathIsDirectoryA((LPCSTR)m_iniFilePath.c_str());
//		return PathFileExistsA(m_iniFilePath.c_str());
//		//return isFile;
//	}
//
//	
//	//! should return a value >= 0 if not error reading the file
//	bool isParseIniFileData() {
//		logDebug("isParseIniFileData");
//
//		unsigned int parsingErrorsCount = 0;
//		dictionary* ini;
//		logInfo("IniFile: m_iniFilePath.c_str(): %s", m_iniFilePath.c_str());
//		ini = iniparser_load(m_iniFilePath.c_str());
//		//ini = iniparser_load(ini_name);
//		if (ini == NULL) {
//			logErr("IniFile: cannot parse file: %s", m_iniFilePath.c_str());
//			//fprintf(stderr, "cannot parse file: %s\n", ini_name);
//			return false;
//		}
//		iniparser_dump(ini, stderr);
//
//		//logInfo("IniFile:isParseIniFileData: parsing ini file...");
//
//		
//		int failureCount = 0;
//
//		if (!IniFileData::parseIniFileVersion(iniparser_getstring(ini, "Info:IniFileVersion", NULL))) {
//			logErr("isParseIniFileData: Failed to parse IniFileVersion");
//			failureCount++;
//		}
//			
//			
//
//		if (!IniFileData::parseIsIniFileAutoReload(iniparser_getboolean(ini, "Settings:Auto_Reload_Ini_File", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Auto_Reload_Ini_File");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseReloadIniFileVkCode(iniparser_getstring(ini, "Settings:Reload_Ini_File_Key", NULL))){
//			logErr("isParseIniFileData: Failed to parse Reload_Ini_File_Key");
//			failureCount++;
//		}
//
//		
//
//		if (!IniFileData::parseReticleScale(iniparser_getint(ini, "Settings:Crosshair_Scale", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Crosshair_Scale");
//			failureCount++;
//		}
//
//		/*if (!IniFileData::parseReticleScaleAds(iniparser_getint(ini, "Settings:CrosshairADS_Scale", IniDefault::iniFileIntNotFoundVal)))
//			failureCount++;*/
//
//		if (!IniFileData::parseImmersiveCrosshairLevel(iniparser_getint(ini, "Settings:Immersive_Crosshair_Level", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Immersive_Crosshair_Level");
//			failureCount++;
//		}
//			
//
//		if (!IniFileData::parseOverrideReticleColor(iniparser_getint(ini, "Settings:Dot_Crosshair_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Dot_Crosshair_Color");
//			failureCount++;
//		}
//			
//
//		if (!IniFileData::parseOverrideReticleCooldownColor(iniparser_getint(ini, "Settings:Dot_Crosshair_Cooldown_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Dot_Crosshair_Cooldown_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseOverrideDotReticleFragNadeReadyColor(iniparser_getint(ini, "Settings:Dot_Crosshair_Frag_Nade_Ready_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Dot_Crosshair_Frag_Nade_Ready_Color");
//			failureCount++;
//		}
//		
//
//		if (!IniFileData::parseOverrideDotReticleIceNadeReadyColor(iniparser_getint(ini, "Settings:Dot_Crosshair_Ice_Nade_Ready_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Dot_Crosshair_Ice_Nade_Ready_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseOverrideDotReticleBothNadeReadyColor(iniparser_getint(ini, "Settings:Dot_Crosshair_Both_Nades_Ready_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Dot_Crosshair_Both_Nades_Ready_Color");
//			failureCount++;
//		}			
//
//		if (!IniFileData::parseOverrideBloodPunchColor1(iniparser_getint(ini, "Settings:BloodPunch_1_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse BloodPunch_1_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseOverrideBloodPunchColor2(iniparser_getint(ini, "Settings:BloodPunch_2_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse BloodPunch_2_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseOverrideDesperatePunchColor(iniparser_getint(ini, "Settings:Desperate_Punch_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Desperate_Punch_Icon_Color");
//			failureCount++;
//		}	
//
//		if (!IniFileData::parseOverrideFuel3PipsColor(iniparser_getint(ini, "Settings:Fuel_3_Pips_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Fuel_3_Pips_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseFragGrenadeReadyOverrideColor(iniparser_getint(ini, "Settings:FragNade_Ready_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse FragNade_Ready_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseFragGrenadeCooldownOverrideColor(iniparser_getint(ini, "Settings:FragNade_Cooldown_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse FragNade_Cooldown_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseIceGrenadeReadyOverrideColor(iniparser_getint(ini, "Settings:IceNade_Ready_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse IceNade_Ready_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseOverrideIceGrenadeCooldownColor(iniparser_getint(ini, "Settings:IceNade_Cooldown_Icon_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse IceNade_Cooldown_Icon_Color");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseIsWeaponBarColored(iniparser_getboolean(ini, "Settings:Colored_Weapon_Bar", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Colored_Weapon_Bar");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseOverrideRadMeterColor(iniparser_getint(ini, "Settings:Radsuit_Bar_Color", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Radsuit_Bar_Color");
//			failureCount++;
//
//		}
//
//		if (!IniFileData::parseIsRemoveBindsReminderOnHud(iniparser_getboolean(ini, "Settings:Clean_Hud", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Clean_Hud");
//			failureCount++;
//
//		}		
//
//		if (!IniFileData::parseIsDisableHitMarker(iniparser_getboolean(ini, "Settings:Disable_Hit_Marker", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Disable_Hit_Marker");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseIsDisabledDashBlurEffect(iniparser_getboolean(ini, "Settings:Remove_Dash_Blur_Effect", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Remove_Dash_Blur_Effect");
//			failureCount++;
//
//		}
//
//		if (!IniFileData::parseGameUiSettingsMinFov(iniparser_getint(ini, "Settings:Game_Settings_Min_FOV", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Game_Settings_Min_FOV");
//			failureCount++;
//		}
//
//
//		if (!IniFileData::parseGameUiSettingsMaxFov(iniparser_getint(ini, "Settings:Game_Settings_Max_FOV", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Game_Settings_Max_FOV");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseHandsFOV(iniparser_getint(ini, "Settings:Weapon_FOV_Override", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Weapon_FOV_Override");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseBoltMouseSens(iniparser_getint(ini, "Settings:PrecisionBolt_ADS_Mouse_Sens", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse PrecisionBolt_ADS_Mouse_Sens");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseArbalestMouseSens(iniparser_getint(ini, "Settings:Arbalest_ADS_Mouse_Sens", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Arbalest_ADS_Mouse_Sens");
//			failureCount++;
//
//		}
//
//		if (!IniFileData::parseBoltControllerSens(iniparser_getint(ini, "Settings:PrecisionBolt_ADS_Controller_Sens", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse PrecisionBolt_ADS_Controller_Sens");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseArbalestControllerSens(iniparser_getint(ini, "Settings:Arbalest_ADS_Controller_Sens", IniDefault::iniFileIntNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Arbalest_ADS_Controller_Sens");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseIsImprovedShotgunConfigVal(iniparser_getboolean(ini, "Settings:Remove_Shotguns_Zoom_And_Sens_Change", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Remove_Shotguns_Zoom_And_Sens_Change");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseIsRemoveBalistatZoom(iniparser_getboolean(ini, "Settings:Remove_Balista_Arbalest_Zoom", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Remove_Balista_Arbalest_Zoom");
//			failureCount++;
//		}
//		
//
//		if (!IniFileData::parseIsImprovedSwitchingVal(iniparser_getboolean(ini, "Settings:Weapon_Switch_Fix", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Weapon_Switch_Fix");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseIsImprovedSwitchingBeepVal(iniparser_getboolean(ini, "Settings:Weapon_Switch_Fix_Beep", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Weapon_Switch_Fix_Beep");
//			failureCount++;
//		}
//		
//
//		if (!IniFileData::parseIsPlayModLoadedBeepVal(iniparser_getboolean(ini, "Settings:Mod_Loaded_Beep", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Mod_Loaded_Beep");
//			failureCount++;
//		}
//
//		if (!IniFileData::parseUserDebugModeLevel(iniparser_getint(ini, "Settings:Debug_Level", IniDefault::iniFileBoolNotFoundVal))) {
//			logErr("isParseIniFileData: Failed to parse Debug_Level");
//			failureCount++;
//		}
//
//
//
//		/*IniFileData::parseOverrideFragGrenadeArrowColor(iniparser_getint(ini, "Settings:FragArrowColor", iniFileIntNotFoundVal));*/
//		/*infileData.setCrosshairSize(iniparser_getint(ini, "Settings:CrosshairSize", iniFileIntNotFoundVal));
//		infileData.setCrosshairOulineThickness(iniparser_getint(ini, "Settings:CrosshairOutlineThickness", iniFileIntNotFoundVal));*/
//
//		if (failureCount) {
//			logWarn("isParseIniFileData: FAILED to parse: %d settings ", failureCount);
//			return false;
//		}		
//		return true;
//		/*logInfo("isParseIniFileData: Succesfully parsed all ini file settings !");
//		return true;*/
//	}
//
//
//
//	//? you need the # when you just enter text like at the start of the file here (# IF YOU HAVE ERRORS WIT...)
//	/*void saveFile()
//	{
//		logDebug("saveFile");
//		try
//		{
//			FILE* ini;
//			if ((ini = fopen(m_iniFilePath.c_str(), "w")) == NULL) {
//				logErr("IniFile:saveFile: can not create ini file, will default values.");				
//				return;
//			}
//
//			fprintf(ini, iniStr::getIniWholeStr().c_str());
//			fclose(ini);
//
//			m_lastSaveMs = EpochMillis();
//			if (m_saveCount < std::numeric_limits<int>::max()) {
//				m_saveCount++;
//			}
//
//			logInfo("saveFile: saving file...m_saveCount: %d", m_saveCount);
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("saveFile: ERROR: %s", ex.what());
//		}
//		IniFileData::debugPrint();
//		
//	}*/
//
//	void saveFile() {
//		logDebug("saveFile");
//
//		try {
//			// Open the file for writing using C++ file streams
//			std::ofstream iniFileStream(m_iniFilePath);
//
//			if (!iniFileStream.is_open()) {
//				logErr("IniFile:saveFile: Unable to create ini file, will use default values.");
//				return;
//			}
//
//			// Write the ini data to the file
//			iniFileStream << iniStr::getIniWholeStr();
//			iniFileStream.close();
//
//			m_lastSaveMs = EpochMillis();
//
//			if (m_saveCount < std::numeric_limits<int>::max()) {
//				m_saveCount++;
//			}
//
//			logInfo("saveFile: Saving file... m_saveCount: %d", m_saveCount);
//		}
//		catch (const std::exception& ex) {
//			logErr("saveFile: ERROR: %s", ex.what());
//		}
//		printStatus();
//		IniFileData::debugPrint();
//	}
//
//
//
//	
//
//	//void saveDefaultFileTest()
//	//{
//	//	FILE* ini;
//
//	//	//if ((ini = fopen("example.ini", "w")) == NULL) {
//	//	if ((ini = fopen(m_iniFilePath.c_str(), "w")) == NULL) {
//	//		fprintf(stderr, "iniparser: cannot create example.ini\n");
//	//		std::cerr << "iniparser: cannot create example.ini" << std::endl;
//
//	//		return;
//	//	}
//
//	//	fprintf(ini,
//	//		"#\n"
//	//		"# This is an example of ini file\n"
//	//		"#\n"
//	//		"\n"
//	//		"[Pizza]\n"
//	//		"\n"
//	//		"Ham       = yes ;\n"
//	//		"Mushrooms = TRUE ;\n"
//	//		"Capres    = 0 ;\n"
//	//		"Cheese    = Non ;\n"
//	//		"\n"
//	//		"\n"
//	//		"[Wine]\n"
//	//		"\n"
//	//		"Grape     = Cabernet Sauvignon ;\n"
//	//		"Year      = 1989 ;\n"
//	//		"Country   = Spain ;\n"
//	//		"Alcohol   = 12.5  ;\n"
//	//		"\n");
//	//	fclose(ini);
//	//	//try
//	//	//{
//	//	//	ini["Fov"]["userFov"] = std::to_string(m_defaultFov_f);
//	//	//	file.generate(ini, true); //! generate pretty default file
//	//	//	std::cout << "saveFile: saving..." << std::endl;
//	//	//}
//	//	//catch (const std::exception&)
//	//	//{
//	//	//	std::cout << "saveFile: error" << std::endl;
//	//	//}
//	//}
//
//	//void printIniFilePath()
//	//{
//	//	spdlog::info("IniFile: printIniFilePath {}", m_iniFilePath);
//	//	//std::cout << "IniFile::printIniFilePath:  " << m_iniFilePath << std::endl;
//	//}
//
//	//void SettingsFile::saveUserFov(float val)
//	//{
//	//	try
//	//	{
//	//		ini["Fov"]["userFov"] = val;
//	//		file.write(ini, true);
//	//		std::cout << "saveUserFov: saving fov val:" << val << std::endl;
//	//	}
//	//	catch (const std::exception&)
//	//	{
//	//		std::cout << "saveUserFov: error" << std::endl;
//	//	}
//	//}
//
//	
//
//
//
//};
//
