//#pragma once
//#include <string>
//#include "../DE/GameVersionInfoManager.h"

//? side note if you do "*******" + "\n" it will be invalid cause you cannot directly concatenate a string with a line break in between.
//std::string Config::getLogHeaderString()
//{
//	std::string headerStr =
//		"**********************************************************************************************\n"
//		"This is the log file. THIS IS NOT WHERE YOU WILL MAKE CHANGES TO THE MOD SETTINGS. IF YOU WANT TO CHANGE THE SETTINGS OR OPTIONS OF THE MOD OPEN THE FILE CALLED: " + g_iniFileName
//		+ "\n\n"
//		+ "Mod Name: " + g_modFullNameWithSpaces + "\n"
//		+ "Mod Build Date: " + getDatedBuildStr() + "\n"
//		+ getDebugLogLevelAsStr() + "\n"
//		+ GameVersionInfoManager::getEngineVersionStr() + "\n"
//		+ GameVersionInfoManager::getBuildVersionStr() + "\n"
//		+ "Mod Author: " + g_modAuthor + "\n"
//		+ "Date: " + getTimeDateStr() + " (Day/Month/Year format)" + "\n"
//		+ "For more info on how the mod works, configuration, troubleshooting....Check Install.txt or contact mod author at the Nexus mod page. " + "\n"
//		+ "**********************************************************************************************" + "\n"
//		;
//
//	return headerStr;
//}

