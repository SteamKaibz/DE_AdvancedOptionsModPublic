#include "GameVersionInfoManager.h"

bool GameVersionInfoManager::isNewGameUpdateReleased() {
    return getBuildVersionStr() != m_lastKnownBuildVersion;
}

std::string GameVersionInfoManager::getExpectedBuildVersionStr() {
    return m_lastKnownBuildVersion;
}

//bool GameVersionInfoManager::acquirreBuildStrPtrAdd(__int64** ptrAdd) {
//    if (ptrAdd == nullptr || *ptrAdd == nullptr) {
//        logErr("acquirreBuildStrPtrAdd: Invalid pointer.");
//        m_buildVersionStr = "null ptr for buildVersionStrPtP";
//        return false;
//    }
//    __int64* buildVersionStrPtr = *ptrAdd;
//    if (MemHelper::isBadReadPtr(buildVersionStrPtr)) {
//        logErr("acquirreBuildStrPtrAdd: Invalid memory location.");
//        m_buildVersionStr = "bad ptr for buildVersionStrPtr";
//        return false;
//    }
//    m_buildVersionStr = *(const char**)buildVersionStrPtr;
//    logInfo("acquirreBuildStrPtrAdd: m_buildVersionStr has been set to: %s", m_buildVersionStr.c_str());
//    return true;
//}

std::string GameVersionInfoManager::getBuildVersionStr() {
    std::string buildStr = idCvarManager::getCvarString("build_binaryName");
    return buildStr;
}

//__int64 GameVersionInfoManager::m_idBuildVersionNamePtrAdd = 0;
//std::string GameVersionInfoManager::m_buildVersionStr = "Game buildVersion not found";
//const std::string GameVersionInfoManager::m_lastKnownBuildVersion = "20230804-000051-white-wine";
