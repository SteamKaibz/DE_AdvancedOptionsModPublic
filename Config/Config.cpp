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


void Config::set(ModConfig debugVersion)
{
	static bool isFirsTimeSet = true;

	//! those removes things we don't want to see in the logs, list is here: https://emilk.github.io/loguru/index.html#logging/logfunctions
	if (isFirsTimeSet) {
		loguru::g_preamble_thread = false;
		loguru::g_preamble_date = false;
		loguru::g_preamble_uptime = false;
	}


	m_modConfig = debugVersion;

	//bool isfreopen_sError = false;

	//? attempting to be able to change verbosity at runtime for file logging
	loguru::remove_all_callbacks();


	loguru::FileMode loguruFileMode = loguru::FileMode::Truncate;
	if (!isFirsTimeSet) {
		loguruFileMode = loguru::FileMode::Append;
	}

	switch (m_modConfig)
	{

	case ModConfig::nexusRelease:
		loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_WARNING);
		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_WARNING);
		break;
	case ModConfig::nexusDebug:
		//loguru::g_stderr_verbosity = loguru::Verbosity_OFF; //! disabled log to console	
		loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_INFO);
		break;
	case ModConfig::dev:
		loguru::g_stderr_verbosity = loguru::Verbosity_INFO;
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);
		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_INFO);
		break;
	default:
		loguru::g_stderr_verbosity = loguru::Verbosity_OFF; //! disabled log to console			
		loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguruFileMode, loguru::Verbosity_INFO);	//! truncate will create new file every time.
		//loguru::add_file(MOD_LOG_FILE_NAME.c_str(), loguru::Truncate, loguru::Verbosity_INFO);	//! truncate will create new file every time.
		logErr("Config::set: default condition, how did that happen ?!");
		break;
	}


	logInfo("Config::set: log level: %d", (int)debugVersion);
	isFirsTimeSet = false;


}




//bool Config::isImprovedWeaponSwitchingEnabled()
//{
//	return m_isImprovedWeaponSwitchingEnabled;
//}

void Config::printHeaderInLogFile()
{
	switch (m_modConfig)
	{
	case ModConfig::nexusRelease:
		logWarn(getLogHeaderString().c_str());
		break;
	case ModConfig::nexusDebug:
		logInfo(getLogHeaderString().c_str());
		break;
	case ModConfig::dev:
		logInfo(getLogHeaderString().c_str());
		logWarn("******* This is the dev version, this should not be released on nexxus to prevent issues mod being unloaded is pressing numpad2 **********");
		break;
	case ModConfig::MAX_VERSIONS:
		logInfo(getLogHeaderString().c_str());
		break;
	default:
		logWarn(getLogHeaderString().c_str());
		break;
	}
}





std::string Config::getLogHeaderString()
{
	std::string headerStr =
		"\n\n**********************************************************************************************\nThis is the log file. \nMod Name: " + MOD_FULL_NAME + "\n"
		+ "Build: " + getModBuildStr() + "\n"
		+ "Config: " + getModConfigStr() + "\n"
		+ "Mod Author: Kaibz" + "\n"
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



ModConfig Config::get()
{
	return m_modConfig;
}


bool Config::isDevMode() {

	bool result = (m_modConfig == ModConfig::dev);
	//logErr("Config::isDevMode(): m_modConfig is: %d and result is: %d", m_modConfig, result);
	return result;
}

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

	switch (m_modConfig)
	{
	case ModConfig::dev:
		return "Dev";
	case ModConfig::nexusDebug:
		return "Debug";
	case ModConfig::nexusRelease:
		return "Release";
	case ModConfig::MAX_VERSIONS:
		return "MAX_VERSIONS (?!)";
	default:
		return "default..?!";
		break;
	}
}

std::string Config::getModuleName()
{
	return GAME_FILE_NAME;
}



std::string Config::getGameFileNameToLowerStr()
{
	return GAME_FILE_NAME_TO_LOWER;
}


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
	result += "Mod Name: ";
	result += MOD_FULL_NAME;
	result += "\n\n";
	result += "Mod Version: ";
	result += getModConfigStr();
	result += "\n\n";
	result += "Mod Build: ";
	result += getModBuildStr();
	result += "\n\n";
	result += "Mod Author: Kaibz";
	result += "\n\n";
	result += "For more Info about the mod (changelog, troubleshooting, bug report...)check the mod nexus page";
	//result += MOD_NEXUS_LINK;
	result += "\n\n";
	result += "Credits: ";
	result += "\n\n";
	result += getCreditsStr();

	return result;
}


