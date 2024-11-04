#pragma once

#include <chrono>
#include <windows.h>
#include <tlhelp32.h>
#include <mmsystem.h>
#include <VersionHelpers.h>
#include <vulkan/vulkan.h>
#include <intrin.h>  // For __cpuid

#include <iostream>
#include <wrl/client.h>
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

#include <Wbemidl.h> // for gpu info
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")

#include "../Config.h"
#include "../DE/idLib_Dynamic.h"



struct KeyInfo
{
    const char* name;
    unsigned int vkCode;
};



//! currated list by me.
//? removed the   {"NOT BOUND", 0}, entry as if the key is not bound user will never be able to open the mod menu.
inline const KeyInfo allowedKeyBindsKeyInfos[] = {
    {"MOUSE MIDDLE", VK_MBUTTON},
    {"MOUSE X1", VK_XBUTTON1},
    {"MOUSE X2", VK_XBUTTON2},
    {"TAB", VK_TAB},
    {"SHIFT", VK_SHIFT},
    {"CONTROL", VK_CONTROL},
    {"SPACE", VK_SPACE},
    {"END", VK_END},
    {"HOME", VK_HOME},
    {"ARROW LEFT", VK_LEFT},
    {"ARROW UP", VK_UP},
    {"ARROW RIGHT", VK_RIGHT},
    {"ARROW DOWN", VK_DOWN},
    {"INSERT", VK_INSERT},
    {"DELETE", VK_DELETE},
    {"0", '0'},
    {"1", '1'},
    {"2", '2'},
    {"3", '3'},
    {"4", '4'},
    {"5", '5'},
    {"6", '6'},
    {"7", '7'},
    {"8", '8'},
    {"9", '9'},
    {"A", 'A'},
    {"B", 'B'},
    {"C", 'C'},
    {"D", 'D'},
    {"E", 'E'},
    {"F", 'F'},
    {"G", 'G'},
    {"H", 'H'},
    {"I", 'I'},
    {"J", 'J'},
    {"K", 'K'},
    {"L", 'L'},
    {"M", 'M'},
    {"N", 'N'},
    {"O", 'O'},
    {"P", 'P'},
    {"Q", 'Q'},
    {"R", 'R'},
    {"S", 'S'},
    {"T", 'T'},
    {"U", 'U'},
    {"V", 'V'},
    {"W", 'W'},
    {"X", 'X'},
    {"Y", 'Y'},
    {"Z", 'Z'},
    {"NUMPAD0", VK_NUMPAD0},
    {"NUMPAD1", VK_NUMPAD1},
    {"NUMPAD2", VK_NUMPAD2},
    {"NUMPAD3", VK_NUMPAD3},
    {"NUMPAD4", VK_NUMPAD4},
    {"NUMPAD5", VK_NUMPAD5},
    {"NUMPAD6", VK_NUMPAD6},
    {"NUMPAD7", VK_NUMPAD7},
    {"NUMPAD8", VK_NUMPAD8},
    {"NUMPAD9", VK_NUMPAD9},
    {"F1", VK_F1},
    {"F2", VK_F2},
    {"F3", VK_F3},
    {"F4", VK_F4},
    {"F5", VK_F5},
    {"F6", VK_F6},
    {"F7", VK_F7},
    {"F8", VK_F8},
    {"F9", VK_F9},
    {"F10", VK_F10},
    {"F11", VK_F11},
    {"F12", VK_F12}
};




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

	static bool AreStringsEqual(const char* str1, const char* str2);

	static std::wstring WstrtoLower(const std::wstring& input);

	static std::string replaceDoubleScopeWithUnderscore(std::string input);

	static std::string intToHexString(__int64 decimalValue);

	static std::string ptrToHexString(void* addr);

	static std::string getBoolAsStr(bool isTrue);

    static std::string toStringWithPrecision(float value, int nDecimals);

	static std::string floatToStringWithoutTrailingZeros(float value);

	static bool caseInsensitiveCompare(const std::string& str1, const std::string& str2);

	static bool compareEventNames(const idEventDef* a, const idEventDef* b);

	static bool saveSetToFile(std::string fileName, std::set<std::string> StrSet);
	static bool saveVecToFile(std::string fileName, std::vector<std::string> StrVec);

	static void removeDuplicatesAndSort(const std::string& inputFilePath, const std::string& outputFilePath);

	static void sortStringsByName(const std::string& inputFilePath, const std::string& outputFilePath);

	static void fileRemoveDuplicates(const std::string& inputFilePath, const std::string& outputFilePath);

	static std::set<std::string> loadFileToSet(std::string inputFilePath);

	static RTL_OSVERSIONINFOW GetWindowsVersionInfo();

	static std::string GetWindowsVersion();

	static std::string getCpuInfoStr();

    static const char* getAllowedKeyName(unsigned int vkCode);

    static unsigned int convertKeyStrToVkCode(std::string keyStr, unsigned int defaultVKCode);

    static  std::string convertVkCodeToKeyStr(unsigned int vkCode);

	//static std::string getGPUInfo();

	//static int GetWindowsBuildNumber();

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











