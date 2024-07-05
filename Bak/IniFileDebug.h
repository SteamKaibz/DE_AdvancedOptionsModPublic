//#pragma once
//
//
//#include <windows.h>
//#include <filesystem> //C++ 17
//#include <string>
//#include <iostream>
//#include <Shlwapi.h>
//#include "dictionary.h"
//#include "iniparser.h"
//#include "IniFileData.h"
////#include "Config.h"
//#include "../Config/Config.h"
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
//	const std::string m_iniFileName = iniFileName;
//	std::string m_iniFilePath = "";
//
//
//public:
//
//	//IniFile()
//	//{
//	//	//GetIniFilePath();
//	//	//if (m_iniFilePath != "") {
//	//	//	//getDataTest(m_iniFilePath.c_str());
//	//	//}
//	//}
//
//	IniFileStatus load(IniFileData& inifileData) {
//		IniFileStatus iniFileStatus = iniFileUndefined;
//
//		try
//		{
//			if (m_iniFilePath == "") {
//				GetIniFilePath();
//			}
//			logInfo("load() called");
//			if (!isIniFileExist()) {
//				logWarn("load: Ini file does not exist, creating file with default values...");
//				//! if we're here, saveFile will use default values.
//				iniFileStatus = iniFileSavingDefault;
//			}
//			else {
//				if (!isParseIniFileData(inifileData)) {
//					logErr("error parsing ini file, reseting file to default values.");
//					inifileData.resetToDefault();
//					iniFileStatus = iniFileParsinError;
//				}
//				else {
//					iniFileStatus = iniFileLoaded;
//				}
//			}
//			saveFile(inifileData);
//
//			return iniFileStatus;
//		}
//		catch (const std::exception& ex) {
//
//			logErr("load(): exception %s", ex.what());
//			return iniFileExceptionError;
//		}
//
//
//	}
//
//	//? saving original load in case we mess the one we're working on
//	//bool load(IniFileData& inifileData) {
//	//	bool isLoaded = false;
//
//	//	if (m_iniFilePath == "") {
//	//		GetIniFilePath();
//	//	}
//	//	spdlog::info("IniFile:load() called");
//	//	if (!isIniFileExist()) {
//	//		saveFile(inifileData); //! this will save file using default values.
//	//	}
//	//	else {
//	//		if (!isParseIniFileData(inifileData)) {
//	//			spdlog::error("IniFile: error parsing ini file, using default values.");
//	//		}
//	//		else {
//	//			isLoaded = true;
//	//		}
//	//	}
//	//	inifileData.debugPrint();
//	//	return isLoaded;
//	//}
//
//
//	std::string WStringToString(const std::wstring& wstr)
//	{
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
//		try
//		{
//			std::wstring PathAndName;
//			std::wstring OnlyPath;
//			const int BUFSIZE = 4096;
//			wchar_t buffer[BUFSIZE];
//			//if (::GetModuleFileNameW(m_DllHandle, buffer, BUFSIZE - 1) <= 0)
//			if (::GetModuleFileNameW(NULL, buffer, BUFSIZE - 1) <= 0)
//			{
//				logErr("GetIniFilePath: GetModuleFileNameW < 0 can not get ini file path");
//			}
//			else {
//				PathAndName = buffer;
//				size_t found = PathAndName.find_last_of(L"/\\");
//				OnlyPath = PathAndName.substr(0, found);
//				//std::wcout << "IniFile::GetIniFilePath: dll path: " << OnlyPath << std::endl;
//				std::string dirPath = WStringToString(OnlyPath);
//				fs::path dir(dirPath);
//				fs::path file(m_iniFileName);
//				fs::path full_path = dir / file;
//				m_iniFilePath = full_path.generic_string();
//				//m_iniFilePath = PathCombine(dirPath, m_iniFileName);
//				//m_iniFilePath = dirPath + '\\' + m_iniFileName;
//				//m_iniFilePath = dirPath + "/" + m_iniFileName;
//				logInfo("GetIniFilePath: m_iniFilePath: %s", m_iniFilePath.c_str());
//			}
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("IniFile::GetIniFilePath: ERROR: %s setting m_iniFilePath to empty", ex.what());
//			m_iniFilePath = "";
//		}
//	}
//
//	bool isIniFileExist()
//	{
//		//return PathIsDirectoryA((LPCSTR)m_iniFilePath.c_str());
//		//return PathIsDirectoryA(m_iniFilePath.c_str());
//		//if (PathIsDirectoryA((LPCSTR)m_iniFilePath.c_str());
//		return PathFileExistsA(m_iniFilePath.c_str());
//		//return isFile;
//	}
//
//
//	//! should return a value >= 0 if not error reading the file
//	bool isParseIniFileData(IniFileData& infileData) {
//		dictionary* ini;
//		ini = iniparser_load(m_iniFilePath.c_str());
//		//ini = iniparser_load(ini_name);
//		if (ini == NULL) {
//			logErr("IniFile: cannot parse file: %s", m_iniFilePath.c_str());
//			//fprintf(stderr, "cannot parse file: %s\n", ini_name);
//			return false;
//		}
//		iniparser_dump(ini, stderr);
//
//		logInfo("IniFile:isParseIniFileData: parsing ini file...");
//		infileData.setReloadIniFileVkCode(iniparser_getstring(ini, "Settings:ReloadFileKey", NULL));
//		infileData.setIsPlayModLoadedBeepVal(iniparser_getboolean(ini, "Settings:ModLoadedBeep", iniFileBoolNotFoundVal));
//
//		/*infileData.setCrosshairSize(iniparser_getint(ini, "Settings:CrosshairSize", iniFileIntNotFoundVal));
//		infileData.setCrosshairOulineThickness(iniparser_getint(ini, "Settings:CrosshairOutlineThickness", iniFileIntNotFoundVal));*/
//
//		infileData.setIsOnlyShowCrosshairInHARScope(iniparser_getboolean(ini, "Settings:OnlyShowDotCrosshairInPrecisionBoltADS", iniFileBoolNotFoundVal));
//		infileData.setOverrideBloodPunchColorSet(iniparser_getint(ini, "Settings:BloodPunchColorOverrideSet", iniFileIntNotFoundVal));
//		infileData.setOverrideGrenadeArrowColorSet(iniparser_getint(ini, "Settings:GrenadeArrowColorOverrideSet", iniFileIntNotFoundVal));
//		infileData.setOverrideRadMeterColor(iniparser_getint(ini, "Settings:RadsuitMeterColorOverride", iniFileIntNotFoundVal));
//		infileData.setisRemoveBindsReminderOnHud(iniparser_getboolean(ini, "Settings:CleanHud", iniFileBoolNotFoundVal));
//
//		infileData.setBoltMouseSens(iniparser_getint(ini, "Settings:PrecisionBolt_ADS_Mouse_Sens", iniFileIntNotFoundVal));
//		infileData.setArbalestMouseSens(iniparser_getint(ini, "Settings:Arbalest_ADS_Mouse_Sens", iniFileIntNotFoundVal));
//		infileData.setBoltControllerSens(iniparser_getint(ini, "Settings:PrecisionBolt_ADS_Controller_Sens", iniFileIntNotFoundVal));
//		infileData.setArbalestControllerSens(iniparser_getint(ini, "Settings:Arbalest_ADS_Controller_Sens", iniFileIntNotFoundVal));
//
//		infileData.setIsImprovedShotgunConfigVal(iniparser_getboolean(ini, "Settings:Remove_Shotgun_Annoyances", iniFileBoolNotFoundVal));
//		infileData.setIsImprovedSwitchingVal(iniparser_getboolean(ini, "Settings:Weapon_Bug_Fix", iniFileBoolNotFoundVal));
//		infileData.setIsImprovedSwitchingBeepVal(iniparser_getboolean(ini, "Settings:Weapon_Bug_Beep", iniFileBoolNotFoundVal));
//		infileData.setHandsFOV(iniparser_getint(ini, "Settings:Weapon_FOV_Override", iniFileIntNotFoundVal));
//
//		return true;
//	}
//
//
//
//
//	void saveFile(IniFileData& inifileData)
//	{//? you need the # when you just enter text like at the start of the file here (# IF YOU HAVE ERRORS WIT...)
//		FILE* ini;
//		if ((ini = fopen(m_iniFilePath.c_str(), "w")) == NULL) {
//			logErr("IniFile:saveFile: can not create ini file, using default values.");
//			/*fprintf(stderr, "iniparser: cannot create example.ini\n");
//			std::cerr << "iniparser: cannot create example.ini" << std::endl;*/
//			return;
//		}
//		logWarn("saveFile: saving file...");
//
//		fprintf(ini,
//			"\n"
//			"# Dedicated Grenades Keys Mod Settings (created by: %s)\n"
//			"\n"
//			"# These are the user settings. For more info check the install.txt file. \n"
//			"\n"
//			"# For example, if you want to change the sensitivity of the precision bold while the game is running, you have to edit this file, SAVE IT and then press the ReloadFileKey while in game.\n"
//			"\n"
//			"# IF YOU HAVE ISSUES WITH THIS FILE or want to reset it to its original values you can, close the the .ini file, close the game, delete the .ini file, and relaunch the game so the .ini file gets regenerated automatically.\n"
//			"\n"
//			"\n"
//			"[Settings]\n"
//			"\n"
//			"\n"
//			"ReloadFileKey = %s ;    (A-Z or 0-9 or F1-12, other key or modifiers will not work and will default back to F8) \n"
//			"\n"
//			"\n"
//			"ModLoadedBeep  = %s ;    (yes: plays 2 beeps when the mod load succesfully. no: does not play any beep when mod is loaded.\n"
//			"\n"
//			"\n"
//			"OnlyShowCrosshairInPrecisionBoltADS = %s ;    (Use this only if you want to play the game with no hud.  yes: will set the game to no hud mode and will disable the crosshair for all weapons EXCEPT when in the precison bold ADS view, this is useful for those who like to play with no crosshair except when in this weapon's ADS view. no: will use default settings.)\n"
//			"\n"
//			"\n"
//			"BloodPunchColorOverrideSet = %d ;    (Will change color of the Bloodpunch icon depending if you have 0, 1 or 2 bloodpunch ready. 0: will use the default game behaviour. 1: baseColor=>Yellow=>Red, 2:XXXXXXXXX)\n"
//			"\n"
//			"\n"
//			"GrenadeArrowColorOverrideSet = %d ;    (Will change color of the arrow on the right side of the grenade icon when the other grenade is available.  0: green arrow when frag available and blue arrow when ice available 1: XXXXXXXXX )\n"
//			"\n"
//			"\n"
//			"RadsuitMeterColorOverride = %d ;    (Will change color of the radsuit meter so that it's easily distinguishable from the health meter. 0: no change, default game color  1: XXXXXXXXXXXX)\n"
//			"\n"
//			"\n"
//			"CleanHud = %d ;    (yes: will remove the binds reminders on the hud, if you've played the game a bit you don't need those anymore. no: default game behaviour)\n"
//			"\n"
//			"\n"
//			"PrecisionBolt_ADS_Mouse_Sens  = %d ;    (from 0 to 100. The lower the slower mouse mouvements, default game setting: 50) \n"
//			"\n"
//			"\n"
//			"Arbalest_ADS_Mouse_Sens = %d ;    (from 0 to 100. The lower the slower mouse mouvements, default game setting: 60) \n"
//			"\n"
//			"\n"
//			"PrecisionBolt_ADS_Controller_Sens  = %d ;    (from 0 to 100, the lower the slower the controller mouvements, default game setting: 40)\n"
//			"\n"
//			"\n"
//			"Arbalest_ADS_Controller_Sens = %d ;    (from 0 to 100, the lower the slower the controller mouvements, default game setting: 60)\n"
//			"\n"
//			"\n"
//			"Remove_Shotgun_Annoyances  = %s ;    (yes: removes the zoom effects and lowered sensitivity when using sticky bombs and full auto mods. no: uses default game setting)\n"
//			"\n"
//			"\n"
//			"Weapon_Bug_Fix  =  %s ;    (yes: improves the weapon switching by making sure the last weapon key pressed will be the weapon selected. no: uses default game setting)\n"
//			"\n"
//			"\n"
//			"Weapon_Bug_Beep = %s ;    (yes: plays a small beep when the mod detects a bug and resends the right weapon button/key. no: no beep.)\n"
//			"\n"
//			"\n"
//			"Weapon_FOV_Override = %d ;    (from 0 to 100. Higer values mean higher FOV. 0 means default game setting.) "
//			"\n", modAuthor.c_str(), inifileData.getreloadIniFileVkCodeStr().c_str(), inifileData.getisPlayModLoadedBeepStr().c_str(), inifileData.getIsOnlyShowCrosshairInHARScopeStr().c_str(), inifileData.getOverrideBloodPunchColorSetInt(), inifileData.getOverrideGrenadeArrowColorSetInt(), inifileData.getOverrideRadMeterColorInt(), inifileData.getIsRemoveBindsReminderOnHudStr().c_str(), inifileData.getassaultRiflePrecisionBoltMouseSensInt(), inifileData.getballistaArbalestMouseSensInt(), inifileData.getssaultRiflePrecisionBoltControllerSensInt(), inifileData.getballistaArbalestControllerSensInt(), inifileData.getisOverideShotgunConfigStr().c_str(), inifileData.getisImprovedWeaponSwitchingStr().c_str(), inifileData.getisImprovedWeaponSwitchingBeepStr().c_str(), inifileData.getHandsFovInt());
//		fclose(ini);
//
//
//		inifileData.debugPrint();
//		/*if (Config::isDebugMode()) {
//			inifileData.debugPrint();
//		}*/
//	}
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
