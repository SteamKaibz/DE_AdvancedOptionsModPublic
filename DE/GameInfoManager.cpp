#include "GameInfoManager.h"



bool GameInfoManager::acquireGpuInfoVar(__int64 Addr) {

    if (MemHelper::isBadReadPtr((void*)Addr)) {
        logErr("acquireGpuInfoVar: Addr is bad ptr: %p", (void*)Addr);
        return false;
    }

    m_gpuInfoStartAddr = Addr;
    logInfo("m_gpuInfoStartAddr set to: %p", (void*)m_gpuInfoStartAddr);
    return true;
}



//bool GameInfoManager::acquirreBuildStrPtrAdd(__int64** ptrAdd) {
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

std::string GameInfoManager::getBuildVersionStr() {
    std::string buildStr = idCvarManager::getCvarString("build_binaryName");
    return buildStr;
}

std::string GameInfoManager::getGpuInfoStr()
{
    if (!m_gpuInfoStartAddr) {
        return "FAILED TO GET GPU INFO";
    }

    gpuInfo_K* gpuInfoPtr = (gpuInfo_K*)m_gpuInfoStartAddr;
    std::string vendorStr = gpuInfoPtr->VendorName;
    std::string gpdDriver = gpuInfoPtr->Driver;
    std::string vulkanApiVersion = gpuInfoPtr->VK_API;

    std::string resultStr = "Vendor: " + vendorStr + " Gpu Driver: " + gpdDriver + " Vulkan Api Version: " + vulkanApiVersion;
    //logInfo("getGpuInfoStr: vendorStr: %s gpdDriver %s vulkanApiVersion %s", vendorStr.c_str(), gpdDriver.c_str(), vulkanApiVersion.c_str());
   
    return resultStr;
}


//std::string GameInfoManager::getGameVersion_K() {
//
//	std::string gameBuildStr = idCvarManager::getCvarString("build_binaryName");
//	std::string exeName = MemHelper::GetGameExeNameToLower();
//
//	if (exeName == Config::DE_VANILLA_MODULE_NAME_TOLOWER) {
//		if (gameBuildStr == "20240722-204955-eggplant-purple") {
//			return "Vanilla_V1";
//		}
//		return "Vanilla_???";
//	}
//
//	else if (exeName == Config::DE_SANDBOX_MODULE_NAME_TOLOWER) {
//		if (gameBuildStr == "20240822-095543-coral-blue") {
//			return "Sandbox_V2";
//		}
//		return "Sandbox_???";
//	}
//	return "Unknown_Version";
//}

//__int64 GameInfoManager::m_idBuildVersionNamePtrAdd = 0;
//std::string GameInfoManager::m_buildVersionStr = "Game buildVersion not found";
//const std::string GameInfoManager::m_lastKnownBuildVersion = "20230804-000051-white-wine";
