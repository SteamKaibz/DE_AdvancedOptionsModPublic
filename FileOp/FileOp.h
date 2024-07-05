#pragma once

#include <Windows.h>
#include <filesystem> //C++ 17
#include <string>
#include <Shlwapi.h> // For PathFileExists and PathAppend
#pragma comment(lib, "Shlwapi.lib")
#include <Psapi.h>
#include "../Config/Config.h"
#include "../K_Utils/K_Utils.h"




class FileOp
{
private:

	//static std::string m_gameDirectoryPathStr;

	//static std::string m_modDirectoryPathStr;

	//static const std::string m_modDirectoryName;
	//static const std::string m_modSettingsFileName;
	static std::string m_modSettingsFilePath;
	//static const char* m_gameFileName;


public:

	//static std::string GetModulePath();

	//static bool acquireGameDirectoryPath(const char* moduleName);

	//static std::string GetModuleDirectory();

	static bool isGameDirectoryValid();

	static bool isModDirectory();

	static bool CreateModDirectoryV2();

	//static bool CreateModDirectory();

	static std::string getMainModSettingsFilePath();

	static std::string getWeaponsSettingsFilePath();

	static void listModDirectory();

	static std::string getGameDirectoryPath(const char* moduleName);

	//static bool isPreviousModVersionInGameFolder();

};

