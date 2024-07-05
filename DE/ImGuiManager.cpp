#include "ImGuiManager.h"
//#include "../ModSettings/ModSettingsManager.h"
//#include "../ModSettings/ModSettingsManager.cpp"


 bool ImGuiManager::m_isInitFlag = false;
 bool ImGuiManager::m_isOneInitAttempt = false;
 bool ImGuiManager::m_isUserForceOpenModMenu = false;
 

 
 void ImGuiManager::setIsInitFlag(bool isInitFlag) {
	 if (m_isInitFlag != isInitFlag) {
		 logInfo("setIsInitFlag: isInitFlag has changed to: %s", isInitFlag ? "true" : "false");
	 }
	 m_isInitFlag = isInitFlag;
 }


 bool ImGuiManager::isInitFlag() {
	 return m_isInitFlag;
 }

 void ImGuiManager::setInitAttempt() {
	 m_isOneInitAttempt = true;
 }

 bool ImGuiManager::isPreviousInitAttempt() {
	 return m_isOneInitAttempt;
 }

 void ImGuiManager::toggleForceOpenMenuState() {
	 m_isUserForceOpenModMenu = !m_isUserForceOpenModMenu;
	 logInfo("toggleForceOpenMenuState: setting m_isUserForceOpenModMenu to: %d", m_isUserForceOpenModMenu);
 }


 bool ImGuiManager::isUserForceOpenModMenu() {
	 return m_isUserForceOpenModMenu;
 }

 //bool ImGuiManager::isInitialized() {
   // return m_isInitialized;
//}

//void ImGuiManager::setIsInitialzed(bool isInitialized) {
   // m_isInitialized = isInitialized;
//}

 //void ImGuiManager::init() {
	// logInfo("initImgui: init process started..");
	// logInfo("ImGui Rendering backend: %s\n", U::RenderingBackendToStr());
	// MinHookManager::setInitializeStatus(MH_Initialize());

	// if (!(MinHookManager::getInitializeStatus() == MH_OK || MinHookManager::getInitializeStatus() == MH_ERROR_ALREADY_INITIALIZED)) {
	//	 auto statusStr = MH_StatusToString(MinHookManager::getInitializeStatus());
	//	 logErr("initImgui: Failed to initialize MinHook. minhook status is: %s \n", statusStr);
	// }
	// else {
	//	 H::Init();
	//	 m_isInitialized = true;
	// }
	// logErr("IMGuig failed to initialize many feature of the mod will not work please report to mod author with a log file.");
	// m_isInitialized =  false;
 //}



//ModSettings ImGuiManager::ImGuiModSettings;
//
//bool ImGuiManager::m_isShowModMenuUserRequest = false;
//
//bool ImGuiManager::m_isShowModMenu = false;
//
//bool ImGuiManager::m_isShowDebugWindow = false;
//
//unsigned int ImGuiManager::lastKeyPressed = -1;



//void ImGui::ShowModMenu(bool* p_open) {
//
//	IM_ASSERT(ImGui::GetCurrentContext() != NULL && "Missing dear imgui context. Refer to examples app!");
//
//	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10.0f, 10.0f)); // Set padding to 10 pixels on each side
//	ImGui::Begin("Settings");
//	ImGui::End();
//}


//void ImGuiManager::resetLastKeyPressed() {
//	lastKeyPressed = -1;
//}
//
//
//void ImGuiManager::update()
//{
//
//	ImGuiModSettings = ModSettingsManager::get();
//}





//? in those 2 funcs we're assigning a keyCode to a member but we are logging the arg so keep that in mind if you have an issue you can not figure out regarding keybinds.
//void ImGuiManager::assignNormalSpeedKeyCode(unsigned int keyCode) {
//	m_modSettings.normalSpeedKeyVkCode = keyCode;
//	std::string keyStr = keyCodeToString(keyCode);
//	if (isDuplicateKeyError()) {
//		logWarn("assignNormalSpeedKeyCode: keyStr: %s normalSpeedKeyVkCode (%u) and fastForwardKeyVkCode (%u) have same value, please change the binding of either key", keyStr.c_str(), normalSpeedKeyVkCode.load(), fastForwardKeyVkCode.load());
//	}
//	else {
//		logInfo("assignNormalSpeedKeyCode: NormalSpeedKeyCode is being assigned to: %s (key code: %u)", keyStr.c_str(), keyCode);
//	}
//
//}

//void ImGuiManager::assignFastForwardKeyCode(unsigned int keyCode) {
//	fastForwardKeyVkCode.store(keyCode);
//	std::string keyStr = keyCodeToString(keyCode);
//	if (isDuplicateKeyError()) {
//		logWarn("assignFastForwardKeyCode: keyStr: %s normalSpeedKeyVkCode (%u) and fastForwardKeyVkCode (%u) have same value, please change the binding of either key", keyStr.c_str(), normalSpeedKeyVkCode.load(), fastForwardKeyVkCode.load());
//	}
//	else {
//		logInfo("assignFastForwardKeyCode: NormalSpeedKeyCode is being assigned to: %s (key code: %u)", keyStr.c_str(), keyCode);
//	}
//}





//void ImGuiManager::userToggleisShowModMenuUserRequest()
//{
//	m_isShowModMenuUserRequest = !m_isShowModMenuUserRequest;
//	logInfo("debug: m_isShowModMenuUserRequest is now: %d", m_isShowModMenuUserRequest);
//}
//
//void ImGuiManager::toggleShowDebugWindow() {
//
//	m_isShowDebugWindow = !m_isShowDebugWindow;
//	logInfo("toggleShowDebugWindow: m_isShowDebugWindow is now: %d", m_isShowDebugWindow);
//
//}



//void ImGuiManager::updateV2() {
//	auto menuState = MenuStateManager::get();
//
//	if (menuState == inMenu) {
//
//		//! debug should have priority
//		if (m_isShowDebugWindow) {
//			m_isShowModMenu = false;
//			idCvarManager::setCvar("in_unlockMouseInMenus", "1");
//		}
//		else if (m_isShowModMenuUserRequest) {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "1");
//			m_isShowModMenu = true;
//		}
//		else {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "0");
//			m_isShowModMenu = false;
//		}
//	}
//	else if (menuState == NotInMenu) {
//		auto unlockMouseInMenusCvar = idCvarManager::getCvarPtr("in_unlockMouseInMenus");
//
//		if (m_isShowDebugWindow) {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "0");
//		}
//		else if (!unlockMouseInMenusCvar) {
//			logErr("update: unlockMouseInMenusCvar is bad ptr: can not handle mod menu gui");
//		}
//		else if (unlockMouseInMenusCvar->valueInteger != 1) {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "0");
//		}
//		m_isShowModMenu = false;
//	}
//	else {
//		auto menuStateStr = MenuStateManager::getMenuStateAsStr(menuState);
//		logWarn("update: menu state is: %s can not show imgui windows", menuStateStr.c_str());
//		m_isShowModMenu = false;
//		m_isShowDebugWindow = false;
//	}
//}

//void ImGuiManager::update()
//{
//	auto menuState = MenuStateManager::get();
//
//	if (menuState == inMenu) {
//
//		//! debug should have priority
//		if (m_isShowDebugWindow) {
//			m_isShowModMenu = false;
//			idCvarManager::setCvar("in_unlockMouseInMenus", "1");
//		}
//		else if (m_isShowModMenuUserRequest) {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "1");
//			m_isShowModMenu = true;
//		}
//		else {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "0");
//			m_isShowModMenu = false;
//		}
//	}
//	else if (menuState == NotInMenu) {
//		auto unlockMouseInMenusCvar = idCvarManager::getCvarPtr("in_unlockMouseInMenus");
//
//		if (m_isShowDebugWindow) {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "0");
//		}
//		else if (!unlockMouseInMenusCvar) {
//			logErr("update: unlockMouseInMenusCvar is bad ptr: can not handle mod menu gui");		}
//		else if (unlockMouseInMenusCvar->valueInteger != 1) {
//			idCvarManager::setCvar("in_unlockMouseInMenus", "0");
//		}	
//		m_isShowModMenu = false;
//	}
//	else {
//		auto menuStateStr = MenuStateManager::getMenuStateAsStr(menuState);
//		logWarn("update: menu state is: %s can not show imgui windows", menuStateStr.c_str());
//		m_isShowModMenu = false;
//		m_isShowDebugWindow = false;
//	}
//}

//bool ImGuiManager::getIsShowModMenu()
//{
//	return m_isShowModMenu;
//}
//
//bool ImGuiManager::getIsShowDebugWindow()
//{
//	return m_isShowDebugWindow;
//}
