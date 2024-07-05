#include "HashManager.h"



bool HashManager::isMeathookModInGameFolder() {
    logInfo("Checking for Meathook Mod in game folder...");
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::string currentPathStr = currentPath.string();

    logInfo("isMeathookModInGameFolder: debug currentPathStr: %s", currentPathStr.c_str());

    std::string meathHookModFilePathStr = HashManager::getMD5MatchFilePath(Hashes::MeathookModHashes, currentPathStr, Hashes::MeathookModFileExtension);
    if (meathHookModFilePathStr.empty()) {
        return false;
    }
    return true;
}

bool HashManager::isPreviousModVersionInGameFolder() {

    logInfo("Checking for previous mod versions in game folder...");
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::string currentPathStr = currentPath.string();

    std::string conflictingModPathStr = HashManager::getMD5MatchFilePath(Hashes::PreviousModVersionsHashes, currentPathStr, Hashes::PreviousModsVesionsFileExtension);

    if (conflictingModPathStr.empty()) {
        logInfo("isPreviousModVersionInGameFolder: Found no previous version of this mod in the game folder. All good.");
        return false;
    }

    logErr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    logErr("Found previous version of this mod in the game folder, as a result this mod will now close. Please close the game and delete: %s and start the game again", conflictingModPathStr.c_str());
    logErr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    return true;
}


std::string HashManager::getMD5MatchFilePath(const std::vector<std::string>& md5List, const std::string& folderPath, std::string fileEtentionToCheck)
{
    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        std::string fileExtension = entry.path().extension().string();
        std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

        if (fileExtension == fileEtentionToCheck)
        {          

            std::string filePath = entry.path().string();
            std::string fileHash;

            //logInfo("getMD5MatchFilePath: debug: checking file: %s", filePath.c_str());

            if (GetFileMD5Hash(filePath, fileHash))
            {
                for (const auto& md5 : md5List)
                {
                    if (fileHash == md5)
                    {                       
                        return filePath;
                    }
                }
            }
        }
    }
    
    return std::string();
}

bool HashManager::GetFileMD5Hash(const std::string& filePath, std::string& md5HashStr)
{
    HCRYPTPROV hCryptProv = NULL;
    HCRYPTHASH hHash = NULL;
    DWORD hashSize = 0;
    BYTE data[BUFSIZE];
    std::ifstream file(filePath, std::ios::binary);

    if (!file)
    {
        logErr("Failed to open file: %s", filePath.c_str());
        return false;
    }

    if (!CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
    {
        logErr("CryptAcquireContext failed with error code: %d", GetLastError());
        return false;
    }

    if (!CryptCreateHash(hCryptProv, CALG_MD5, 0, 0, &hHash))
    {
        logErr("CryptCreateHash failed with error code: %d", GetLastError());
        CryptReleaseContext(hCryptProv, 0);
        return false;
    }

    while (file)
    {
        file.read((char*)data, BUFSIZE);
        std::streamsize streamSize = file.gcount();
        unsigned long cbRead = static_cast<unsigned long>(streamSize);
        if (!CryptHashData(hHash, data, cbRead, 0))
        {
            logErr("CryptHashData failed with error code: %d", GetLastError());
            CryptDestroyHash(hHash);
            CryptReleaseContext(hCryptProv, 0);
            return false;
        }
    }

    hashSize = HASHSIZE;
    BYTE hashValue[16]; // MD5 produces a 16-byte hash
    if (!CryptGetHashParam(hHash, HP_HASHVAL, hashValue, &hashSize, 0))
    {
        logErr("CryptGetHashParam failed with error code: %d", GetLastError());
        CryptDestroyHash(hHash);
        CryptReleaseContext(hCryptProv, 0);
        return false;
    }

    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i < 16; ++i)
    {
        ss << std::setw(2) << static_cast<unsigned int>(hashValue[i]);
    }

    md5HashStr = ss.str();

    CryptDestroyHash(hHash);
    CryptReleaseContext(hCryptProv, 0);

    return true;
}