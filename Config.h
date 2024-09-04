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


#include "../Common/Voice.h"
#include "../DE/enumsCustom.h"



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






//! comment this if you want to build for vanilla, and uncomment you want to build for sandbox
//#define GAME_VERSION_SANDBOX

class Config
{
private:

#ifdef GAME_VERSION_SANDBOX
	static inline bool m_isModSandboxVersion = true;
#else
	static inline bool m_isModSandboxVersion = false;
#endif

#ifdef DE_DEV
	static inline bool m_isDevMode = true;
#else
	static inline bool m_isDevMode = false;
#endif

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
	//static inline bool m_isSandboxModule = false;
	

public:

	static const inline float MOD_BUILD_F = 2.32f;

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
	

	static bool isModSandboxVersion();
	static bool isDevMode();
	static bool isDebugMode();

	static std::string getModVersionAsStr();

	static bool isModError();
	static void setModError(std::string erroMsg);

	loguru::Verbosity VerbosityForFile(const loguru::Verbosity& verbosity);

	static void setLoggerLevel(LogVerbose verbose);
	
	//static void setLogLevelToInfo(bool islogLevelInfo);

	//static void setGameVersion(GameVersion gameVersion);
	//static void setDevMode(bool isDevMode);


	static void setLogIdConsoleToFile(bool isLogIdConsoleToFile);
	static bool isLogIdConsoleToFile();

	static std::string getModBuildStr();
	//static std::string getModConfigStr();

	static std::string& getCurrentModuleNameStrToLower();
	static void setCurrentModuleNameStrToLower(const std::string& moduleName);

	//static bool isSandboxModule();
	//static void setIsSandboxModule(std::string moduleNameStrToLower);

	/*static void setDevMode(bool isDevMode);*/

	static std::string getCreditsStr();

	static void printHeaderInLogFile();
	static std::string getLogHeaderString();
	static std::string getTimeDateStr();

	static std::string getModInfoTextForGui();

	static std::string getGameDirectoryStr();
	static void setGameDirectoryStr(std::string dirPath);





};



