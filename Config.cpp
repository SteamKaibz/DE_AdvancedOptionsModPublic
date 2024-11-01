#include "Config.h"
//#include "../DE/GameInfoManager.h"



bool Config::isModSandboxVersion()
{
	return m_isModSandboxVersion;
}

std::string Config::getModVersionAsStr()
{
	std::string versionStr;

	if (m_isModSandboxVersion) {
		versionStr += "Sandbox ";
	}
	else {
		versionStr += "Vanilla ";
	}

	if (m_isDevMode) {
		versionStr += "DEV MODE";
	}
	else if (m_isDebugMode) {
		versionStr += "DEBUG MODE";
	}
	else {
		versionStr += "Nexus";
	}

	return versionStr;
}

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


void Config::setLoggerLevel(LogVerbose verbose) {

	static bool isFirstTime = true;
	loguru::FileMode loguruFileMode = loguru::FileMode::Truncate;

	/*if (islogLevelInfo) {
		logInfo("setLogLevelToInfo: islogLevelInfo: %d all info up to error msgs should be visible in log file", islogLevelInfo);
	}
	else {
		logInfo("setLogLevelToInfo: islogLevelInfo: %d only warning and error messages should now be visible in log file", islogLevelInfo);
	}*/

	if (isFirstTime) {
		//! those removes things we don't want to see in the logs, list is here: https://emilk.github.io/loguru/index.html#logging/logfunctions
		loguru::g_preamble_thread = false;
		loguru::g_preamble_date = false;
		loguru::g_preamble_uptime = false;
	}

	//? this prevent erros/crash when attempting to be able to change verbosity at runtime for file logging
	loguru::remove_all_callbacks();

	//! making sure we keep the log even if log level changes
	if (!isFirstTime) {
		loguruFileMode = loguru::FileMode::Append;
	}

	switch (verbose)
	{
	case LogVerbose::Info:
		loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
		break;
	case LogVerbose::Warn:
		loguru::g_stderr_verbosity = loguru::Verbosity_WARNING;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_WARNING); //! warn and error msgs
		break;
	case LogVerbose::Err:
		loguru::g_stderr_verbosity = loguru::Verbosity_ERROR;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_ERROR); 
		break;
	case LogVerbose::Fatal:
		loguru::g_stderr_verbosity = loguru::Verbosity_FATAL;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_FATAL);
		break;
	default:
		loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
		break;
	}

	//if (islogLevelInfo) {
	//	loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
	//	loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
	//}
	//else {
	//	loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
	//	loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_WARNING); //! warn and error msgs
	//}

	isFirstTime = false;
}



//void Config::setLogLevelToInfo(bool islogLevelInfo) {
//
//	static bool isFirstTime = true;
//	loguru::FileMode loguruFileMode = loguru::FileMode::Truncate;
//
//	if (islogLevelInfo) {
//		logInfo("setLogLevelToInfo: islogLevelInfo: %d all info up to error msgs should be visible in log file", islogLevelInfo);
//	}
//	else {
//		logInfo("setLogLevelToInfo: islogLevelInfo: %d only warning and error messages should now be visible in log file", islogLevelInfo);
//	}
//
//	if (isFirstTime) {
//		//! those removes things we don't want to see in the logs, list is here: https://emilk.github.io/loguru/index.html#logging/logfunctions
//		loguru::g_preamble_thread = false;
//		loguru::g_preamble_date = false;
//		loguru::g_preamble_uptime = false;
//	}
//
//	//? attempting to be able to change verbosity at runtime for file logging
//	loguru::remove_all_callbacks();
//
//	//! making sure we keep the log even if log level changes
//	if (!isFirstTime) {
//		loguruFileMode = loguru::FileMode::Append;
//	}
//
//	if (islogLevelInfo) {
//		loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
//		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
//	}
//	else {
//		loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
//		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_WARNING); //! warn and error msgs
//	}
//
//	isFirstTime = false;
//}



bool Config::isDevMode()
{
	return m_isDevMode;
}

bool Config::isDebugMode()
{
	return m_isDebugMode;
}

//void Config::setDevMode(bool isDevMode)
//{
//	m_isDevMode = isDevMode;
//
//	logInfo("setDevMode:: m_isDevMode set to: %d", m_isDevMode);	
//}


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

//void Config::logConfigSummary()
//{
//	logInfo(getInfoSummaryStr().c_str());
//}


std::string Config::getGameVersionK_Str() {
	
	static bool isFirstime = true;

	std::string gameBuildResultStr = "Game Build Unknown";
	std::string gameBuildStrCustomResult = "???";

	// Check if the build string exists in the map
	auto it = GameBuildVersionMap.find(m_currentGameVersionStr);

	// If found, return the version, otherwise return "Unknown_Game_Version"
	if (it != GameBuildVersionMap.end()) {
		gameBuildResultStr = it->first;
		gameBuildStrCustomResult = it->second;

		if (m_currentGameVersionStr == OLD_REVISION_3_GAME_BUILD_STR) {
			if (isFirstime) {
				logWarn("Game version is OLD_REVISION_3_GAME_BUILD, mod might not work as intended or at all, or crash");
			}
		}
	}
	else {
		if (isFirstime) {
			logWarn("Game version is Unknown, user is using an old game version or the game has been updated ");
		}

		if (m_currentGameVersionStr.empty()) {
			logErr("getGameVersionK_Str: m_currentGameVersionStr is empty, Config::aquireGameVersionStr has not been called or returned unexpected result !");
		}
	}

	isFirstime = false;
	
	return "Game Build: " +  gameBuildResultStr + " - " + gameBuildStrCustomResult;
}


void Config::aquireGameVersionStr(std::string gameVersionStr) {
	m_currentGameVersionStr = gameVersionStr;
}

void Config::aquireWindowsVersion(std::string windowsVersionStr) {
	m_windowsVersionStr = windowsVersionStr;
}

void Config::acquireCpuInfo(std::string cpuInfoStr) {
	m_cpuInfoStr = cpuInfoStr;
}

void Config::acquireGpuInfo(std::string gpuInfoStr) {
	m_gpuInfoStr = gpuInfoStr;
}


std::string Config::getInfoSummaryStr() {

	std::string resultStr = "Windows version : " + m_windowsVersionStr + "\n";
	resultStr += "CPU Info : " + m_cpuInfoStr + "\n";
	resultStr += "GPU Info : " + m_gpuInfoStr + "\n";
	resultStr += "Mod Name : " + MOD_FULL_NAME + "\n";
	resultStr += "Mod Version " + getModVersionAsStr() + "\n";
	resultStr += "Mod Build: " + getModBuildStr() + "\n";
	resultStr += "Game Exe : " + getCurrentModuleNameStrToLower() + "\n";
	resultStr += "Game Build: " + getGameVersionK_Str() + "\n";
	if (m_isModError) {
		resultStr += "Mod state: ERROR\n";
	}
	else {
		resultStr += "Mod state: All good\n";
	}
	return resultStr;
}


std::string Config::getInfoSummaryForLogFile()
{
	std::string headerStr;
	headerStr += "\n\n\n";
	headerStr += "============================================================================================================\n";
	headerStr += "Info Summary:\n";
	headerStr += getInfoSummaryStr();
	headerStr += "============================================================================================================\n";
	headerStr += "\n\n\n";	

	return headerStr;
}


std::string Config::getModInfoTextForGui()
{
	std::string result = "";

	result += getInfoSummaryStr();
	result += "\n\n";
	result += "Credits: ";
	result += "\n\n";
	result += getCreditsStr();

	return result;
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

	std::string result = std::to_string(MOD_BUILD_F);
	size_t dotPos = result.find('.');
	if (dotPos != std::string::npos) {
		result = result.substr(0, dotPos + 3);  // 2 decimal places
	}

	return result;
	//return "Mod Version: " + result + " (Build Date: " + BUILD_DATE + ")";
}





//std::string Config::getModConfigStr()
//{
//	if (m_isDevMode) {
//		return "Dev";
//	}
//	else {
//		return "Nexus Release";
//	}
//}


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


