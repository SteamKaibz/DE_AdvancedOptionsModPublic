#include "LoadingScreenManager.h"

 bool LoadingScreenManager::acquirreloadingScreenStructAddr(__int64 addr) {
	logDebug("acquirreloadingScreenStructAddr");
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquirreloadingScreenStructAddr: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	m_loadingScreenStructAddr = addr;
	m_loadScreenInfoPtr = (LoadScreenInfo*)*(__int64*)m_loadingScreenStructAddr;
	logInfo("acquirreloadingScreenStructAddr: m_loadingScreenStructAddr is being set to : %p m_loadScreenInfoPtr is now: %p ", (void*)m_loadingScreenStructAddr, m_loadScreenInfoPtr);
	return true;
}

 bool LoadingScreenManager::isReadyToRenderIceIcon() {
	if (!m_loadScreenInfoPtr) {
		return false;
	}
	return !m_loadScreenInfoPtr->isInLoadingScreen && m_loadScreenInfoPtr->isLoadingComplete;
}

 float LoadingScreenManager::roundToDecimalPlaces(float value, int decimalPlaces) {
	float multiplier = (float)std::pow(10.0f, decimalPlaces);
	return std::round(value * multiplier) / multiplier;
}

 void LoadingScreenManager::printLoadScreenDataChange() {
	if (MemHelper::isBadReadPtr(m_loadScreenInfoPtr)) {
		return;
	}
	std::string changesStr = "changes ???";
	bool ischange = false;
	float currentLoadPrct = roundToDecimalPlaces(m_loadScreenInfoPtr->LoadPercentage, 3);

	if (m_debug_isFirtTime) {
		changesStr = "FirstTime: ";
		m_debug_isFirtTime = false;

		m_debug_lastLoadPercentage = currentLoadPrct;
		m_debug_lastisInLoadingScreen = m_loadScreenInfoPtr->isInLoadingScreen;
		m_debug_lastisLoadingComplete = m_loadScreenInfoPtr->isLoadingComplete;
		ischange = true;
	}

	else if (currentLoadPrct != m_debug_lastLoadPercentage) {
		m_debug_lastLoadPercentage = currentLoadPrct;
		changesStr = " LoadPercentage has changed to " + std::to_string(currentLoadPrct);
		ischange = true;
	}
	else if (m_loadScreenInfoPtr->isInLoadingScreen != m_debug_lastisInLoadingScreen) {
		m_debug_lastisInLoadingScreen = m_loadScreenInfoPtr->isInLoadingScreen;
		changesStr = " isInLoadingScreen has changed to %d" + std::to_string(m_loadScreenInfoPtr->isInLoadingScreen);
		ischange = true;
	}
	else if (m_loadScreenInfoPtr->isLoadingComplete != m_debug_lastisLoadingComplete) {
		m_debug_lastisLoadingComplete = m_loadScreenInfoPtr->isLoadingComplete;
		changesStr = "isLoadingComplete has changed to " + std::to_string(m_loadScreenInfoPtr->isLoadingComplete);
		ischange = true;
	}
	if (ischange) {
		logInfo("Loading Screen: %s : LoadPercentage: %.2f  isInLoadingScreen: %d,  isLoadingComplete: %d", changesStr.c_str(), currentLoadPrct, m_loadScreenInfoPtr->isInLoadingScreen, m_loadScreenInfoPtr->isLoadingComplete);
	}


}

 void LoadingScreenManager::debugPrintLoadScreenInfo() {
	if (MemHelper::isBadReadPtr(m_loadScreenInfoPtr)) {
		logWarn("debugPrintLoadScreenInfo: m_loadScreenInfoPtr is Bad ptr: %p can not print data", m_loadScreenInfoPtr);
		return;
	}
	logInfo("debugPrintLoadScreenInfo: LoadPercentage: %.2f  isInLoadingScreen: %d,  isLoadingComplete: %d", m_loadScreenInfoPtr->LoadPercentage, m_loadScreenInfoPtr->isInLoadingScreen, m_loadScreenInfoPtr->isLoadingComplete);
}
