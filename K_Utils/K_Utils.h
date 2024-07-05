#pragma once

#include <chrono>
#include <windows.h>
#include <tlhelp32.h>
#include <mmsystem.h>
//#include "resource1.h"
//#include "resource.h"
#include <string>
#include <locale>
#include <codecvt>
#include <thread>
#include <string_view>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <filesystem>
#include <regex>
#include <unordered_set>


#include "../Config/Config.h"
#include "../DE/GeneratedClasses.h"




class K_Utils {

public:
	bool IsBitSet(int value, int bitPosition);
	static uint64_t EpochMillis();

	static std::string unicode_to_utf8(wchar_t* wide_string);

	static std::string getBuildDate();

	static void PlayModLoadSuccesBeeps(); 
	static void PlayModLoadFailBeeps();
	static void PlayModUnloadedBeeps();

	static void PlayFileGeneratedBeeps();

	static void PlayModeFileLoadedBeeps();

	static std::wstring StandardKeyToStringW(DWORD VKey);

	static std::string wide_to_narrow(const std::wstring& wide_str);

	static std::wstring WstrtoLower(const std::wstring& input);

	static std::string replaceDoubleScopeWithUnderscore(std::string input);

	static std::string intToHexString(__int64 decimalValue);

	static std::string ptrToHexString(void* addr);

	static std::string getBoolAsStr(bool isTrue);

	static std::string floatToStringWithoutTrailingZeros(float value);

	static bool caseInsensitiveCompare(const std::string& str1, const std::string& str2);

	static bool compareEventNames(const idEventDef* a, const idEventDef* b);

	static bool saveSetToFile(std::string fileName, std::set<std::string> StrSet);
	static bool saveVecToFile(std::string fileName, std::vector<std::string> StrVec);

	static void removeDuplicatesAndSort(const std::string& inputFilePath, const std::string& outputFilePath);

	static void sortStringsByName(const std::string& inputFilePath, const std::string& outputFilePath);

	static void fileRemoveDuplicates(const std::string& inputFilePath, const std::string& outputFilePath);

	static std::set<std::string> loadFileToSet(std::string inputFilePath);

	//static std::string WideCharToMultiByte_K(const wchar_t* wideStr);

	//static std::unordered_set<std::string> GetUniqueRunningProcessesSet();


	//static bool IsProcessRunning(const std::string& processName);


};




//static bool areCStrsEqual(const char* str1, const char* str2) {
//	while (*str1 && (*str1 == *str2)) {
//		++str1;
//		++str2;
//	}
//	return (*str1 == *str2); // Return true if both strings have the same null character.
//}











