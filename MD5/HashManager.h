#pragma once


#include <windows.h>
#include <wincrypt.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <locale>
#include <codecvt>
#include "../Config/Config.h"
#include "../DE/MemHelper.h"
#include <shlwapi.h>
#include <sstream>
#include <iomanip>


class HashManager
{

private:

	static inline const DWORD BUFSIZE = 4096; // 4 KB buffer size
	static inline const DWORD HASHSIZE = 16;  // MD5 produces a 16-byte hash



public:


	static bool isMeathookModInGameFolder();

	static bool isPreviousModVersionInGameFolder();

	static std::string getMD5MatchFilePath(const std::vector<std::string>& md5List, const std::string& folderPath, std::string fileEtentionToCheck);

	//static bool CheckForMatchingMD5InFolder(const std::vector<std::string>& md5List, const std::string& folderPath);

	static bool GetFileMD5Hash(const std::string& filePath, std::string& md5HashStr);

};

