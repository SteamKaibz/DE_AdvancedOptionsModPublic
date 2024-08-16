#include "Config.h"
//#include "../DE/GameVersionInfoManager.h"



bool Config::isModError() {
	return m_isModError;
}

void Config::setModError(std::string erroMsg) {
	logErr("Config::setModError: %s", erroMsg.c_str());
	m_isModError = true;
}

loguru::Verbosity Config::VerbosityForFile(const loguru::Verbosity& verbosity)
{
	// You can implement your runtime conditions here
	// For example, change verbosity based on the current time or any other condition
	if (true)
	{
		return loguru::Verbosity_INFO;  // Change to desired verbosity level
	}
	else
	{
		return loguru::Verbosity_WARNING;  // Default verbosity level
	}
}


void Config::setLogLevelToInfo(bool islogLevelInfo) {

	static bool isFirstTime = true;
	loguru::FileMode loguruFileMode = loguru::FileMode::Truncate;

	if (islogLevelInfo) {
		logInfo("setLogLevelToInfo: islogLevelInfo: %d all info up to error msgs should be visible in log file", islogLevelInfo);
	}
	else {
		logInfo("setLogLevelToInfo: islogLevelInfo: %d only warning and error messages should now be visible in log file", islogLevelInfo);
	}

	if (isFirstTime) {
		//! those removes things we don't want to see in the logs, list is here: https://emilk.github.io/loguru/index.html#logging/logfunctions
		loguru::g_preamble_thread = false;
		loguru::g_preamble_date = false;
		loguru::g_preamble_uptime = false;
	}

	//? attempting to be able to change verbosity at runtime for file logging
	loguru::remove_all_callbacks();

	//! making sure we have all the log for this session
	if (!isFirstTime) {
		loguruFileMode = loguru::FileMode::Append;
	}

	if (islogLevelInfo) {
		loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
	}
	else {
		loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_WARNING); //! warn and error msgs
	}

	isFirstTime = false;
}


void Config::setDevMode(bool isDevMode)
{
	m_isDevMode = isDevMode;

	//logInfo("setDevMode:: m_isDevMode set to: %d", m_isDevMode);	
}


bool Config::isModDevMode()
{
	return m_isDevMode;
}

void Config::setLogIdConsoleToFile(bool isLogIdConsoleToFile)
{
	m_isLogIdConsoleToFile = isLogIdConsoleToFile;
}

bool Config::isLogIdConsoleToFile()
{
	return m_isLogIdConsoleToFile;
}


//void Config::set(ModConfig debugVersion)
//{
//	static bool isFirsTimeSet = true;
//
//	//! those removes things we don't want to see in the logs, list is here: https://emilk.github.io/loguru/index.html#logging/logfunctions
//	if (isFirsTimeSet) {
//		loguru::g_preamble_thread = false;
//		loguru::g_preamble_date = false;
//		loguru::g_preamble_uptime = false;
//	}
//
//
//	m_modConfig = debugVersion;
//
//	//bool isfreopen_sError = false;
//
//	//? attempting to be able to change verbosity at runtime for file logging
//	loguru::remove_all_callbacks();
//
//
//	loguru::FileMode loguruFileMode = loguru::FileMode::Truncate;
//	if (!isFirsTimeSet) {
//		loguruFileMode = loguru::FileMode::Append;
//		logErr("loguruFileMode is being set more than once, mod author should be contacted this is not normal");
//	}
//
//	switch (m_modConfig)
//	{
//
//	case ModConfig::nexusRelease:
//		loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
//		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_WARNING);
//		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_WARNING);
//		break;
//	case ModConfig::nexusDebug:
//		//loguru::g_stderr_verbosity = loguru::Verbosity_OFF; //! disabled log to console	
//		loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
//		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
//		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_INFO);
//		break;
//	case ModConfig::dev:
//		loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
//		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::FileMode::Append, loguru::Verbosity_INFO);
//		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
//		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_INFO);
//		break;
//	default:
//		loguru::g_stderr_verbosity = loguru::Verbosity_OFF; //! disabled log to console			
//		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);	//! truncate will create new file every time.
//		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_INFO);	//! truncate will create new file every time.
//		logErr("Config::set: default condition, how did that happen ?!");
//		break;
//	}
//
//
//	logInfo("Config::set: log level: %d", (int)debugVersion);
//	isFirsTimeSet = false;
//
//
//}




//bool Config::isImprovedWeaponSwitchingEnabled()
//{
//	return m_isImprovedWeaponSwitchingEnabled;
//}

void Config::printHeaderInLogFile()
{
	logInfo(getLogHeaderString().c_str());	
}





std::string Config::getLogHeaderString()
{
	std::string headerStr =
		"\n\n**********************************************************************************************\nThis is the log file.\nGame Exe: "+ DE_VANILLA_MODULE_NAME_TOLOWER + "\nMod Name : " + MOD_FULL_NAME
		+ " (Build: " + getModBuildStr() + "  Config: " + getModConfigStr() + ")\n" 		
		+ "For more info on how the mod works, configuration, troubleshooting....Check the mod description on the Nexus mod page. " + "\n"
		+ "**********************************************************************************************" + "\n\n"
		;

	return headerStr;
}




std::string Config::getTimeDateStr() {

	try
	{
		SYSTEMTIME localTime;
		GetLocalTime(&localTime);

		// Format the local time as a string
		std::stringstream ss;
		ss << std::setfill('0');
		ss << std::setw(2) << localTime.wDay << '.' << std::setw(2) << localTime.wMonth << '.' << localTime.wYear;
		ss << ' ' << std::setw(2) << localTime.wHour << ':' << std::setw(2) << localTime.wMinute << ':' << std::setw(2) << localTime.wSecond;

		return ss.str();
	}
	catch (const std::exception& ex)
	{
		logErr("getTimeDateStr: %s", ex.what());
	}
	return "Error: could not get getTimeDateStr";

}



//ModConfig Config::get()
//{
//	return m_modConfig;
//}


//bool Config::isDevMode() {
//
//	bool result = (m_modConfig == ModConfig::dev);
//	//logErr("Config::isDevMode(): m_modConfig is: %d and result is: %d", m_modConfig, result);
//	return result;
//}

std::string Config::getModBuildStr() {

	std::string result = std::to_string(MOD_VERSION_F);
	size_t dotPos = result.find('.');
	if (dotPos != std::string::npos) {
		result = result.substr(0, dotPos + 3);  // 2 decimal places
	}

	return result;
	//return "Mod Version: " + result + " (Build Date: " + BUILD_DATE + ")";
}


std::string Config::getModConfigStr()
{
	if (m_isDevMode) {
		return "Dev";
	}
	else {
		return "Nexus Release";
	}
}


std::string& Config::getCurrentModuleNameStrToLower() {
	return m_currentModuleNameStrToLower;
}

// Setter for m_currentModuleNameStrToLower
void Config::setCurrentModuleNameStrToLower(const std::string& moduleName) {

	logInfo("setCurrentModuleNameStrToLower: m_currentModuleNameStrToLower is being set to: %s", moduleName.c_str());
	m_currentModuleNameStrToLower = moduleName;
}


//std::string& Config::getCurrentModuleNameStrToLower() {
//	return m_currentModuleNameStrToLower;
//}
//
//// Setter for m_currentModuleNameStrToLower
//void Config::setCurrentModuleNameStrToLower(const std::string& moduleName) {
//
//	logInfo("setCurrentModuleNameStrToLower: setting m_currentModuleNameStrToLower to: %s", moduleName.c_str());
//	m_currentModuleNameStrToLower = moduleName;
//}
//
//
//bool Config::isSandboxModule() {
//	return m_isSandboxModule;
//}
//
//void Config::setIsSandboxModule(std::string moduleNameStrToLower) {
//
//	if (moduleNameStrToLower == DE_VANILLA_MODULE_NAME_TOLOWER) {
//		m_isSandboxModule = false;
//	}
//	else if (moduleNameStrToLower == DE_SANDBOX_MODULE_NAME_TOLOWER) {
//		m_isSandboxModule = true;
//	}
//	else {
//		logErr("setIsSandboxModule: cur module is not valid, this should not happen!");
//		m_isSandboxModule = false;
//	}
//}


//std::string Config::getModuleName()
//{
//	return GAME_FILE_NAME;
//}



//std::string Config::getGameFileNameToLowerStr()
//{
//	return GAME_FILE_NAME_TO_LOWER;
//}


std::string Config::getCreditsStr() {

	std::string result;

	for (size_t i = 0; i < CREDITS_VEC.size(); i++)
	{
		result += "  ";
		result += CREDITS_VEC[i];
		result += "\n";
	}

	return result;
}



std::string Config::getModInfoTextForGui()
{
	std::string result = "";

	result += "Game Exe Version: ";
	result += DE_VANILLA_MODULE_NAME_TOLOWER;
	result += "Mod Name: ";
	result += MOD_FULL_NAME;
	result += "\n\n";
	result += "Mod Version: ";
	result += getModConfigStr();
	result += "  ";
	result += "Mod Build: ";
	result += getModBuildStr();
	result += "\n\n";	
	result += "For more Info about the mod (changelog, troubleshooting, bug report...)check the mod nexus page";
	//result += MOD_NEXUS_LINK;
	result += "\n\n";
	result += "Credits: ";
	result += "\n\n";
	result += getCreditsStr();

	return result;
}

std::string Config::getGameDirectoryStr()
{
	return m_gameDirectoryStr;
}

void Config::setGameDirectoryStr(std::string dirPath)
{
	m_gameDirectoryStr = dirPath;
	logInfo("setGameDirectoryStr: m_gameDirectoryStr set to: %s", m_gameDirectoryStr.c_str());
}

//bool Config::isGameDirectoryValid()
//{
//	return FileOp::isExistDirectory(m_gameDirectoryStr);
//}


