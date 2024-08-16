#pragma once

#include <windows.h>
#include <string>
#include <iostream>
#include <format>
#include "../Loguru/loguru.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
//#include "stdafx.h


//#include "spdlog/spdlog.h"
//#include "spdlog/sinks/basic_file_sink.h"
#include "../DE/UtilsDE.h"
#include "../DE/CommonDE.h"
#include "../Voice/Voice.h"


#ifndef logDebug
#define logDebug(...) VLOG_F(loguru::Verbosity_1 , __VA_ARGS__)
#endif 

#ifndef logInfo
#define logInfo(...) VLOG_F(loguru::Verbosity_0 , __VA_ARGS__)
#endif // !logInfo

#ifndef logWarn
#define logWarn(...) VLOG_F(loguru::Verbosity_WARNING , __VA_ARGS__)
#endif // 

#ifndef logErr
#define logErr(...) VLOG_F(loguru::Verbosity_ERROR , __VA_ARGS__)
#endif // 


//enum class ModDebugVersion
//{
//	//modeDebug = -1,
//	modeReleaseUserDebugLevelError = 0,
//	modeReleaseUserDebugLevelWarn = 1,
//	modeReleaseUserDebugLevelInfo = 2,
//	//modeReleaseUserDebugLevelMax = 3,
//	modeReleaseDevDebugLevelError = 666,
//	modeReleaseDevDebugLevelWarn = 667,
//	modeReleaseDevDebugLevelInfo = 668,
//	modeReleaseDevDebugLevelMax = 669,
//	MAX_VERSIONS
//	//modeDebugConsole,			//! this is just for dev.
//	//modeInfoConsole,			//! info level with console output
//	//modDebugFileLog,			//! this could be the default debug mode for nexus
//	//modReleaseInfoFileLog,		//! this could be the default release mode for nexus
//	//modReleaseNoLog				//! No log for max performance (?)
//	
//};


//enum class ModConfig
//{
//	nexusRelease,
//	nexusDebug,
//	dev,
//	MAX_VERSIONS
//
//};

class Config
{
private:

	static inline bool m_isDevMode = false;
	static inline bool m_isLogIdConsoleToFile = false;

	static inline FILE* fp;
	static inline bool m_isModError;

	static inline std::string m_gameDirectoryStr;
	static inline std::string m_currentModuleNameStrToLower;
	//static inline bool m_isSandboxModule = false;
	

public:

	static const inline float MOD_VERSION_F = 2.31f;

	static const inline std::string MOD_FOLDER_NAME = "DE_AdvancedOptionsMod";

	static const inline std::string MOD_FULL_NAME = "Doom Eternal Advanced Options Mod";

	static const inline std::string MOD_NAME_IMGUI = "DE Advanced Options";


	static const inline std::string MOD_LOG_FILE_NAME = "DE_AdvancedOptionsMod_Log.txt";

	static const inline std::string MOD_MAIN_SETTINGS_FILE_NAME = "DE_ModMainSettings.json";

	static const inline std::string MOD_WEAPON_SETTINGS_FILE_NAME = "DE_ModWeaponSettings.json";

	//static const inline std::string GAME_FILE_NAME = "DOOMEternalx64vk.exe";

	//static const inline std::string GAME_FILE_NAME_TO_LOWER = "doometernalx64vk.exe";

	static const inline std::string DE_VANILLA_MODULE_NAME_TOLOWER = "doometernalx64vk.exe";
	static const inline std::string DE_SANDBOX_MODULE_NAME_TOLOWER = "doomsandbox64vk.exe";

	static const inline std::vector<std::string> VALID_GAME_EXE_NAMES_TO_LOWER_VEC = {
		"doometernalx64vk.exe", "doomsandbox64vk.exe"
	};

	static const inline std::string GAME_WINDOW_CLASS_NAME = "Ghost_CLASS";

	//static const inline std::string MOD_NEXUS_LINK = "https://www.nexusmods.com/doometernal/mods/1255";

	static const inline std::vector<std::string> CREDITS_VEC = { "Belazr for fixing crash/freeze issue with Vulkan/Imgui for AMD GPU", "Decimation for all his help/advices", "MethanHydrat for making me get into modding", "SamPT for his help, testing and advices", "SunBeam for his idTech findings and articles", "Chrispy for his amazing Meathook mod", "Zwip - Zwap Zapony for all that he has done for the DE modding community", "Crazyslugger for testing and feedback", "The Doom Eternal Modding Discord Community" };
	


	static bool isModError();
	static void setModError(std::string erroMsg);

	loguru::Verbosity VerbosityForFile(const loguru::Verbosity& verbosity);
	
	static void setLogLevelToInfo(bool islogLevelInfo);

	static void setDevMode(bool isDevMode);
	static bool isModDevMode();

	static void setLogIdConsoleToFile(bool isLogIdConsoleToFile);
	static bool isLogIdConsoleToFile();

	static std::string getModBuildStr();
	static std::string getModConfigStr();

	static std::string& getCurrentModuleNameStrToLower();
	static void setCurrentModuleNameStrToLower(const std::string& moduleName);

	//static bool isSandboxModule();
	//static void setIsSandboxModule(std::string moduleNameStrToLower);

	//static bool isDevMode();

	static std::string getCreditsStr();

	static void printHeaderInLogFile();
	static std::string getLogHeaderString();
	static std::string getTimeDateStr();

	static std::string getModInfoTextForGui();

	static std::string getGameDirectoryStr();
	static void setGameDirectoryStr(std::string dirPath);





};



