
#pragma once
#include <string>

#include "TypeInfoManager.h"
#include "idCvarManager.h"




class GameVersionInfoManager {
private:
    static inline const std::string m_lastKnownBuildVersion = "20230804-000051-white-wine";
    //static inline __int64 m_idBuildVersionNamePtrAdd = 0;
    //static inline std::string m_buildVersionStr = "Game buildVersion not found";

public:
    static bool isNewGameUpdateReleased();
    static std::string getExpectedBuildVersionStr();
    //static bool acquirreBuildStrPtrAdd(__int64** ptrAdd);
    static std::string getBuildVersionStr();
};





