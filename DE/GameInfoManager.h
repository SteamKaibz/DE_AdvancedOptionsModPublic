
#pragma once
#include <string>

#include "TypeInfoManager.h"
#include "idCvarManager.h"

//! custom made structure looking at the function that ouptuts the gpu info in the game console.
//! little chance this break on a future game update but anything can happen
struct gpuInfo_K {
    const char* VendorName = 0;
    char pad0[0x28];
    const char* Driver = 0;
    char pad1[0x28];
    const char* VK_API = 0;
};


class GameInfoManager {
private:
    static inline __int64 m_gpuInfoStartAddr = 0;
    //static inline const std::string m_lastKnownBuildVersion = "20230804-000051-white-wine";
    static inline const std::string m_lastKnownBuildVersion = "20240722-204955-eggplant-purple";
    //static inline __int64 m_idBuildVersionNamePtrAdd = 0;
    //static inline std::string m_buildVersionStr = "Game buildVersion not found";

public:
   static bool acquireGpuInfoVar(__int64 Addr);
    //static bool isNewGameUpdateReleased();
    //static std::string getExpectedBuildVersionStr();
    //static bool acquirreBuildStrPtrAdd(__int64** ptrAdd);
    static std::string getBuildVersionStr();
    static std::string getGpuInfoStr();
    //static std::string getGameVersion_K();

};





