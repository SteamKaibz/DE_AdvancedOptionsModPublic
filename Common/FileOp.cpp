#include "FileOp.h"




//std::string FileOp::m_modDirectoryPathStr = "";
std::string FileOp::m_modSettingsFilePath = "";


//! Alt version for debug:
std::string FileOp::getDoomEternalDirectory() {
	HMODULE hModules[1024];
	DWORD cbNeeded;

	if (EnumProcessModules(GetCurrentProcess(), hModules, sizeof(hModules), &cbNeeded)) {
		for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
			char szModule[MAX_PATH];

			if (GetModuleFileNameExA(GetCurrentProcess(), hModules[i], szModule, sizeof(szModule) / sizeof(char))) {
				std::string modulePath(szModule);
				std::size_t found = modulePath.find_last_of("\\/");
				std::string moduleName = modulePath.substr(found + 1);

				if (moduleName == "DOOMEternalx64vk.exe") {
					std::string directoryStr = modulePath.substr(0, found);
					return directoryStr;
				}
			}
		}
	}

	return std::string(); // Return an empty string if the process is not found
}


//? this doesn't work anymore why? should look into it but have to release mod fast cause new update. will use alternate method...
//x using the game exe name as a reference => more robust.
//std::string FileOp::getGameDirectoryPath(const char* moduleName) {
//	static bool isFirstTime = true;
//	HMODULE hModules[1024];
//	DWORD cbNeeded;
//
//	int debugCounter = 0;
//	int debugCounter2 = 0;
//
//	logInfo("getGameDirectoryPath: moduleName: %s", moduleName);
//
//	// Get the list of module handles in the process
//	if (EnumProcessModules(GetCurrentProcess(), hModules, sizeof(hModules), &cbNeeded)) {
//		for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
//			char szModule[MAX_PATH];
//			debugCounter++;
//
//			// Get the module file name
//			if (GetModuleFileNameExA(GetCurrentProcess(), hModules[i], szModule, sizeof(szModule) / sizeof(char))) {
//				// Check if the module name matches the target module
//				if (strstr(szModule, moduleName) != nullptr) {
//					// Extract the directory from the full path
//					std::string fullPath(szModule);
//					std::size_t found = fullPath.find_last_of("\\/");
//					std::string directoryStr = fullPath.substr(0, found);
//
//					debugCounter2++;
//
//					// Append the INI filename to the directory
//					//std::string iniPath = directory + "\\BlackListFovMod.ini";
//					//m_iniFilePath = directory + "\\BlackListFovMod.ini";
//
//					logInfo("getGameDirectoryPath: found %s : %s directory is: %s", moduleName, szModule, directoryStr.c_str());
//					if (isFirstTime) {
//						logInfo("getGameDirectoryPath: found dir: %s  moduleName: %s (logging this only once!)", directoryStr.c_str(), moduleName);
//						isFirstTime = false;
//					}
//					//logInfo("acquireGameDirectoryPath: returning: %s ", directoryStr.c_str());
//
//					return directoryStr; // Stop searching after finding the module
//				}
//			}
//		}
//	}
//	logErr("getGameDirectoryPath: Failed to find game file: %s returning empty string (debugCounter: %d debugCounter2: %d)", moduleName, debugCounter, debugCounter2);
//	return std::string();
//
//}


//std::string FileOp::GetModuleDirectory() {
//    std::string fullPath = GetModulePath();
//    size_t pos = fullPath.find_last_of("\\/");
//    return (pos != std::string::npos) ? fullPath.substr(0, pos) : "";
//}


//bool  FileOp::isGameDirectoryValid() {
//
//	std::string gameDirectoryPathStr = getGameDirectoryPath(Config::GAME_FILE_NAME.c_str());
//	if (gameDirectoryPathStr.empty()) {
//		logErr("isGameDirectoryValid: game directory is not valid, can not proceed");
//		return false;
//	}
//	return true;
//
//}

bool  FileOp::isExistDirectory(std::string gameDir) {

	if (PathFileExistsA(gameDir.c_str())) {
		return true;
	}
	return false;


	/*std::string gameDirectoryPathStr = getGameDirectoryPath(Config::GAME_FILE_NAME.c_str());
	if (gameDirectoryPathStr.empty()) {
		logErr("isGameDirectoryValid: game directory is not valid, can not proceed");
		return false;
	}
	return true;*/

}

bool FileOp::isModDirectory() {

	//std::string gameDirectoryPathStr = getGameDirectoryPath(Config::GAME_FILE_NAME.c_str());
	std::string gameDirectoryPathStr = Config::getGameDirectoryStr();
	std::string modDirPathStr = gameDirectoryPathStr + "\\" + Config::MOD_FOLDER_NAME;
	if (PathFileExistsA(modDirPathStr.c_str())) {
		return true;		
	}
	return false;
}


bool FileOp::CreateModDirectoryV2() {

	//std::string gameDirectoryPathStr = getGameDirectoryPath(Config::GAME_FILE_NAME.c_str());
	std::string gameDirectoryPathStr = Config::getGameDirectoryStr();
	std::string modDirPathStr = gameDirectoryPathStr + "\\" + Config::MOD_FOLDER_NAME;

	bool createDirResult = CreateDirectoryA(modDirPathStr.c_str(), NULL) != 0;
	if (!createDirResult) {
		logErr("CreateModDirectoryV2: failed to create mod directory: %s", modDirPathStr.c_str());
		return false;
	}
	else {
		logInfo("CreateModDirectoryV2: succes creating mod directory: %s", modDirPathStr.c_str());
	}
	return true;
}



std::string FileOp::getMainModSettingsFilePath()
{
	//std::string gameDirectoryPathStr = getGameDirectoryPath(Config::GAME_FILE_NAME.c_str());
	std::string gameDirectoryPathStr = Config::getGameDirectoryStr();
	std::string modDirPathStr = gameDirectoryPathStr + "\\" + Config::MOD_FOLDER_NAME;

	if (modDirPathStr.empty()) {
		logErr("getMainModSettingsFilePath: modDirPathStr is empty returning empty str");
		return std::string();
	}
	return modDirPathStr + "\\" + Config::MOD_MAIN_SETTINGS_FILE_NAME;
}

//? not used atm.
std::string FileOp::getWeaponsSettingsFilePath()
{
	//std::string gameDirectoryPathStr = getGameDirectoryPath(Config::GAME_FILE_NAME.c_str());
	std::string gameDirectoryPathStr = Config::getGameDirectoryStr();
	std::string modDirPathStr = gameDirectoryPathStr + "\\" + Config::MOD_FOLDER_NAME;

	if (modDirPathStr.empty()) {
		logErr("getWeaponsSettingsFilePath: modDirPathStr is empty returning empty str");
		return std::string();
	}
	return modDirPathStr + "\\" + Config::MOD_WEAPON_SETTINGS_FILE_NAME;
}


std::string FileOp::getDllDirectory() {

	std::string resultStr;

	try
	{
		std::filesystem::path currentPath = std::filesystem::current_path();
		resultStr = currentPath.string();

		logInfo("getDllDirectory: resultStr: (%s)", resultStr.c_str());		

	}
	catch (const std::exception& ex)
	{
		logErr("getDllDirectory: exception error: %s returning empty str. Mod should not work contact mod author", ex.what());
	}

	return resultStr;

}


void FileOp::listGameDirectory() {

	try
	{
		std::filesystem::path currentPath = std::filesystem::current_path();
		std::string currentPathStr = currentPath.string();

		logInfo("llistGameDirectory: if you have any issue with the mod loading make sure there is not an existing mod that could conflict with this one in the game folder. Listing dir: (%s)", currentPathStr.c_str());

		for (const auto& entry : std::filesystem::directory_iterator(currentPath))
		{

			std::filesystem::path filePath = entry.path();
			//std::wstring fileName = filePath.filename().wstring();
			std::wstring fileNameToLowerWstr = K_Utils::WstrtoLower(filePath.filename().wstring());


			if (std::filesystem::is_directory(entry.status())) {
				// It's a directory
				logInfo("Found Directory: %ls in game directory", fileNameToLowerWstr.c_str());
			}
			else if (std::filesystem::is_regular_file(entry.status())) {
				// It's a file
				logInfo("Found File: %ls in game directory", fileNameToLowerWstr.c_str());
			}
			else {
				// It's something else (e.g., a symlink)
				logInfo("found Other: %ls in game directory", fileNameToLowerWstr.c_str());
			}
		}

	}
	catch (const std::exception& ex)
	{
		logErr("listGameDirectory: exception error: %s ", ex.what());
	}
}