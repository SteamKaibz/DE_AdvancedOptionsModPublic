#pragma once

#include <windows.h>
#include <string>
#include <iostream>
#include <format>
#include "loguru.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unordered_map>


//#include "../Common/Voice.h"
#include "../DE/enumsCustom.h"
//#include "DE/GameInfoManager.h"
//#include "DE/GameInfoManager.h"



//! 5/9/24 inluding macros here instead of adding loguru.h file in other file so we could potentially change logger easily in the future.
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



//! 5/9/24 if you ever need to create Solution configuration (ex Dev_Sandbox) check Vs reminder file as this can be tricky, or check commit from this date.

class Config
{
private:
//! 5/9/24 macros defined at solution configuration level. Check project properties => C++ => Preprocessor
#ifdef GAME_VERSION_SANDBOX
	static inline bool m_isModSandboxVersion = true;
#else
	static inline bool m_isModSandboxVersion = false;
#endif

//? Warning: DevMode does not have _DEBUG defined (way to speed up build times) another Dev_Debug solution config could be added.
#ifdef DE_DEV
	static inline bool m_isDevMode = true;
#else
	static inline bool m_isDevMode = false;
#endif

	//x not using _DEBUG macro as debug mode for the nexus release doesn't mean and actual debug but simply more log verbose and more sanity check like for exampl is isBadPtr(). the _DEBUG macro would also make build time significantly longer.
	//todo could improve build time with precompile headers (?)
#ifdef _DEBUG
	static inline bool  m_isDebugMode = true;
#else
	static inline bool  m_isDebugMode  = false;
#endif


	static inline bool m_isLogIdConsoleToFile = false;

	static inline FILE* fp;
	static inline bool m_isModError;

	static inline std::string m_gameDirectoryStr;
	static inline std::string m_currentModuleNameStrToLower;
	static inline std::string m_currentGameVersionStr = "";
	static inline std::string m_windowsVersionStr = "unknown Windows version (?!)";
	static inline std::string m_cpuInfoStr = "unknown CPU info";
	static inline std::string m_gpuInfoStr = "unknown GPU info";
	//static inline bool m_isSandboxModule = false;
	

public:

	static const inline float MOD_BUILD_F = 2.4f;

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

	static const inline std::string OLD_REVISION_3_GAME_BUILD_STR = "20230804-000051-white-wine";

	//! this is a way to give simple names to game version as nowwhere in the game is a patch version like 6.6.6 rev3 present this is just made up somewhere else. because it would be a pain to have folders of data which start with the actual game build str like 20240722-204955-eggplant-purple we'll use a simple conversion below
	static const inline std::unordered_map<std::string, std::string> GameBuildVersionMap = {
	{OLD_REVISION_3_GAME_BUILD_STR, "6.66-Rev2 (OLD!)"}, //! 
	{"20240722-204955-eggplant-purple", "Vanilla_V1"}, //! vanilla version
	{"20240822-095543-coral-blue", "Sandbox_V2"} //! sandbox version
	};

	static const inline std::string GAME_WINDOW_CLASS_NAME = "Ghost_CLASS";

	//static const inline std::string MOD_NEXUS_LINK = "https://www.nexusmods.com/doometernal/mods/1255";

	static const inline std::vector<std::string> CREDITS_VEC = { "Belazr for fixing crash/freeze issue with Vulkan/Imgui for AMD GPU", "Decimation for all his help/advices", "MethanHydrat for making me get into modding", "SamPT for his help, testing and advices", "SunBeam for his idTech findings and articles", "Chrispy for his amazing Meathook mod", "Zwip - Zwap Zapony for all that he has done for the DE modding community", "Crazyslugger for testing and feedback", "The Doom Eternal Modding Discord Community" };
	

	static bool isModSandboxVersion();
	static bool isDevMode();
	static bool isDebugMode();


	static bool isModError();
	static void setModError(std::string erroMsg);

	loguru::Verbosity VerbosityForFile(const loguru::Verbosity& verbosity);

	static void setLoggerLevel(LogVerbose verbose);
	
	//static void setLogLevelToInfo(bool islogLevelInfo);

	//static void setGameVersion(GameVersion gameVersion);
	//static void setDevMode(bool isDevMode);


	static void setLogIdConsoleToFile(bool isLogIdConsoleToFile);
	static bool isLogIdConsoleToFile();

	//static std::string getGameVersion_K();
	//static std::string

	static std::string& getCurrentModuleNameStrToLower();
	static void setCurrentModuleNameStrToLower(const std::string& moduleName);


	//static void logConfigSummary();
	static std::string getGameVersionK_Str();
	static void aquireGameVersionStr(std::string gameVersionStr);
	static void aquireWindowsVersion(std::string windowsVersionStr);
	static void acquireCpuInfo(std::string cpuInfoStr);
	static void acquireGpuInfo(std::string gpuInfoStr);
	static std::string getInfoSummaryStr();
	static std::string getInfoSummaryForLogFile();
	static std::string getModBuildStr();
	static std::string getModVersionAsStr();
	static std::string getTimeDateStr();
	static std::string getCreditsStr();

	static std::string getModInfoTextForGui();

	static std::string getGameDirectoryStr();
	static void setGameDirectoryStr(std::string dirPath);

};



