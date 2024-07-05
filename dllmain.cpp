//#include <windows.h>

//? atm the order and includs in this file is important to be able to build, we need to sanatis


#include "stdafx.h"
#include "Common.h"
#include "SWIP.h"
#include "Utils.h"
#include "dllmain.h"

//#include "spdlog/spdlog.h"
//#include "spdlog/sinks/basic_file_sink.h"

//#include <iostream>
#include "DE/idCmd.h"
//#include "DE/HudAmmoData.h"
#include"DE/Sigs.h"
//#include "Debug/idPlayerDebug.h"
//#include "Debug/idInventoryManagerDebug.h"
#include "DE/idFxManager.h"
#include "Rtti/Rtti_Helper.h"
#include "DE/ReticleColorManager.h"
//#include "Debug/ReticleSettingsDebug.h"
#include "DE/GameVersionInfoManager.h"
#include "DE/idHudManager.h"
#include "DE/idPlayerMetricsManager.h"
#include "DE/GeneratedClasses.h"
#include "TypeGenerator/ClassDefFileGenerator.h"
#include "TypeGenerator/EnumsDefFileGenerator.h"
#include "DE/idDebugManager.h"
#include "ImGui/ImGuiUserConfig.h"
#include "ImGui/dependencies/imgui/imconfig.h"







typedef BOOL(WINAPI* ORIG_FUNCTION_AlphaBlend)(HDC, int, int, int, int, HDC, int, int, int, int, BLENDFUNCTION);
//ORIG_FUNCTION_AlphaBlend orig_AlphaBlend ;
ORIG_FUNCTION_AlphaBlend orig_AlphaBlend = nullptr;

BOOL WINAPI AlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn)
{
	//? attempting this to get rid of warning

	if (orig_AlphaBlend)
	{
		return orig_AlphaBlend(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, ftn);
	}
	else
	{
		// Handle error: Original function pointer not initialized
		// For example:
		return FALSE;
	}

	//! this works though !!!!!
	// Call the original AlphaBlend function
	//return orig_AlphaBlend(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, ftn);
}



typedef BOOL(WINAPI* ORIG_FUNCTION_GradientFill)(HDC, PTRIVERTEX, ULONG, PVOID, ULONG, ULONG);
ORIG_FUNCTION_GradientFill orig_GradientFill;
BOOL WINAPI GradientFill(HDC hdc, PTRIVERTEX pVertex, ULONG dwNumVertex, PVOID pMesh, ULONG dwNumMesh, ULONG dwMode)
{
	return (orig_GradientFill)(hdc, pVertex, dwNumVertex, pMesh, dwNumMesh, dwMode);
}

typedef BOOL(WINAPI* ORIG_FUNCTION_TransparentBlt)(HDC, int, int, int, int, HDC, int, int, int, int, UINT);
ORIG_FUNCTION_TransparentBlt orig_TransparentBlt;
BOOL WINAPI TransparentBlt(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, UINT crTransparent)
{
	return (orig_TransparentBlt)(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, crTransparent);
}



void DllInit()
{

	HMODULE hOriginalDll = LoadLibraryW(L"msimg32.dll");	
	if (hOriginalDll) {
		orig_AlphaBlend = (ORIG_FUNCTION_AlphaBlend)GetProcAddress(hOriginalDll, "AlphaBlend");
		orig_GradientFill = (ORIG_FUNCTION_GradientFill)GetProcAddress(hOriginalDll, "GradientFill");
		orig_TransparentBlt = (ORIG_FUNCTION_TransparentBlt)GetProcAddress(hOriginalDll, "TransparentBlt");
	}
	else {
		logErr("DllInit: hOriginalDll is nullptr, mod should not be working...");
		g_isDllInitOk = false;
	}
	
}


void DisableWndProcHook(HWND hwnd) {
	SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)pOriginalWndProc);
}


bool IsExpectedExecutable(const std::wstring& expectedFilename) {
	// Get the filename of the current process
	wchar_t filename[MAX_PATH];
	GetModuleFileNameW(nullptr, filename, MAX_PATH);

	// Compare the filename against the expected filename
	std::wstring currentFilename = filename;
	if (currentFilename.find(expectedFilename) != std::wstring::npos) {
		return true;  // Current executable matches the expected one
	}
	else {
		return false; // Current executable does not match the expected one
	}
}



bool isDoomEternalCaller() {
	std::wstring expectedFilename = L"DOOMEternalx64vk.exe";

	if (!IsExpectedExecutable(expectedFilename)) {
		return false;
	}
	return true;
	/*else {
		MessageBox(nullptr, L"OK found DOOMEternalx64vk.exe.", L"Error", MB_OK | MB_ICONERROR);
	}*/
}


bool findGameWindow(std::string windowClassName) {
	//HWND hWindow = NULL;
	uint64_t waitStartMs = K_Utils::EpochMillis();
	uint64_t timeoutMs = 60000;


	logInfo("findGameWindow: searching for window Class Name: %s ... (timeout set to %I64u milliseconds)", windowClassName.c_str(), timeoutMs);

	while (g_game_hWindow == NULL)
	{
		g_game_hWindow = FindWindowA(windowClassName.c_str(), NULL);
		Sleep(20);

		if ((K_Utils::EpochMillis() - waitStartMs) > timeoutMs) {
			logErr("findGameWindow: ERROR: timeout reached !");
			break;
		}
	}

	if (g_game_hWindow == NULL) {
		logErr("findGameWindow: failed to find window Class Name: %s (g_game_hWindow is now set to NULL)", windowClassName.c_str());
		return false;
	}

	char windowTitle[256]; // Buffer to store the window title
	GetWindowTextA(g_game_hWindow, windowTitle, sizeof(windowTitle)); // Retrieve the window title
	logInfo("findGameWindow: Successfully found Window with Class name: %s, Window Title: %s g_game_hWindow: %p", windowClassName.c_str(), windowTitle, g_game_hWindow);

	//gameStateManager::acquireGameWindowHandle(g_game_hWindow);

	return true;
}


//std::string getGameDirectoryPath(const char* moduleName) {
//	HMODULE hModules[1024];
//	DWORD cbNeeded;
//
//	// Get the list of module handles in the process
//	if (EnumProcessModules(GetCurrentProcess(), hModules, sizeof(hModules), &cbNeeded)) {
//		for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
//			char szModule[MAX_PATH];
//
//			// Get the module file name
//			if (GetModuleFileNameExA(GetCurrentProcess(), hModules[i], szModule, sizeof(szModule) / sizeof(char))) {
//				// Check if the module name matches the target module
//				if (strstr(szModule, moduleName) != nullptr) {
//					// Extract the directory from the full path
//					std::string fullPath(szModule);
//					std::size_t found = fullPath.find_last_of("\\/");
//					std::string directoryStr = fullPath.substr(0, found);
//
//					// Append the INI filename to the directory
//					//std::string iniPath = directory + "\\BlackListFovMod.ini";
//					//m_iniFilePath = directory + "\\BlackListFovMod.ini";
//
//					logInfo("getGameDirectoryPath: found path for %s : %s directory is: %s", moduleName, szModule, directoryStr.c_str());
//					//logInfo("acquireGameDirectoryPath: returning: %s ", directoryStr.c_str());
//
//					return directoryStr; // Stop searching after finding the module
//				}
//			}
//		}
//	}
//	logErr("getGameDirectoryPath: Failed to find game file: %s returning empty string", moduleName);
//	return std::string();
//
//}




void initImguiV2() {
	static bool isFirsTimeUseImguiCheck = true;


	if (!modSettings::getIsUseImgui()) {
		if (isFirsTimeUseImguiCheck) {
			logWarn("");
			logWarn("!!! user has disabled imgui in the json file, the mod menu, custom hud/crosshair will be disabled !!!!");
			logWarn("!!! user has disabled imgui in the json file, the mod menu, custom hud/crosshair will be disabled !!!!");
			logWarn("!!! user has disabled imgui in the json file, the mod menu, custom hud/crosshair will be disabled !!!!");
			logWarn("");
		}		
		isFirsTimeUseImguiCheck = false;
		return;
	}
	

	if (!ImGuiManager::isInitFlag()) return;

	if (ImGuiManager::isPreviousInitAttempt()) return;

	logInfo("initImguiV2: init process started..");
	U::SetRenderingBackend(VULKAN); //? i just moved this here, it should still work but if issue, check it.
	logInfo("ImGui Rendering backend: %s\n", U::RenderingBackendToStr());
	MinHookManager::setInitializeStatus(MH_Initialize());

	if (!(MinHookManager::getInitializeStatus() == MH_OK || MinHookManager::getInitializeStatus() == MH_ERROR_ALREADY_INITIALIZED)) {
		auto statusStr = MH_StatusToString(MinHookManager::getInitializeStatus());
		logErr("initImguiV2: Failed to initialize MinHook. minhook status is: %s the mod will not work as it should please report to mod author with a log file.\n", statusStr);
	}
	else {
		logInfo("initImguiV2: calling H::Init()");
		H::Init();
	}
	ImGuiManager::setInitAttempt();

}






void modInit() {

	static bool isFirstTimeInit = true;

	//! init only once.
	if (!isFirstTimeInit) return;

	logInfo("modInit called");


	//MaterialLib::init();
	
	//! not setting font here not only because for some reason in the log:  ERR| set: m_monoSpaceFontAddr is bad ptr can not set font but also because we don't need it as we just use the default font anyway, until may be someday we decide to implement stats. Update found a better way to get monoSpaceFontAddr check the func.
	//! Update: not sure we need this anymore, at least atm.
	idFontManager::init();

	//! ensuring we can draw icons on the game's hud
	idCmd::forceDebug_hud_string();

	//! making sure user can use the mouse if a previous session with a crash when in mod menu happened.
	idCmd::SetInMouseEnabled(true);

	//! create default weapons for vec
	WeaponSettings::initWeapons();

	modSettings::apply();	

	
	//! get all the idDeclUIColor from all color profiles so we can restore original colors of the hud
	//idDeclUIColorManager::acquireDefaultColors();

	//! attempting to overwrite controller static bind strings only once and only when not in game and once menu is levelLoaded.
	if (modSettings::getIsUseDedicatedNadeKeys()) {
		if (!bindLabelChanger.isControllerStaticStringsOverwriteAttempt()) {
			//if (EpochMillis() - lastStringOverwriteAttempMs > 1000 && GameStateChecker::isMainMenuLoaded()) {
				//mem.overwriteBindStrings(); //! will only try to overwrite if not already overwritten
				//stringChanger.overwriteBindStrings();
			bindLabelChanger.overwriteControllerLabels(lang.getLocalizedBindStringData());
			//lastStringOverwriteAttempMs = EpochMillis();
		}
	}	



	if (GameVersionInfoManager::isNewGameUpdateReleased()) {
		logWarn("This version of the game: %s is different than the version the mod was made for: %s, mod 'may' not work as attended or not work at all.", GameVersionInfoManager::getBuildVersionStr().c_str(), GameVersionInfoManager::getExpectedBuildVersionStr().c_str());

	}
	else {
		logInfo("Game build Version is the one this mod was designed for: %s", GameVersionInfoManager::getBuildVersionStr().c_str());
	}


	isFirstTimeInit = false;
	
}

//! new version
bool InitializeHooks() {

	if (MinHookManager::getInitializeStatus() != MH_OK) {
		std::string MH_StatusStr = MH_StatusToString(MinHookManager::getInitializeStatus());
		logInfo("InitializeHooks: MH_StatusStr is %s calling MH_Initialize()", MH_StatusStr.c_str());
		MinHookManager::setInitializeStatus(MH_Initialize());
		
	}
	if (MinHookManager::getInitializeStatus() != MH_OK)
	{
		std::string MH_StatusStr = MH_StatusToString(MinHookManager::getInitializeStatus());
		logErr("Failed to initialize MinHook. minhook status is: %s \n", MH_StatusStr.c_str());
		return false;
	}
	else {
		logInfo("InitializeHooks: minhook status is: MH_OK ");
	}


	pgetFovTargetValMBTarget = reinterpret_cast<getFovTargetValMB>(MinHookManager::GetGetFovTargetValAddr());
	if (MH_CreateHook(reinterpret_cast<void**>(pgetFovTargetValMBTarget), &getFovTargetValMB_Hook, reinterpret_cast<void**>(&pgetFovTargetValMB)) != MH_OK) {
		logErr("failed to create pgetFovTargetValMBTarget");
		return false;
	}


	pSelectWeaponForSelectionGroupTarget = reinterpret_cast<SelectWeaponForSelectionGroup>(MinHookManager::GetIdPlayerSelectWeaponForSelectionGroupAddr());	
	if (MH_CreateHook(reinterpret_cast<void**>(pSelectWeaponForSelectionGroupTarget), &SelectWeaponForSelectionGroupHook, reinterpret_cast<void**>(&pSelectWeaponForSelectionGroup)) != MH_OK) {
		logErr("failed to create pSelectWeaponForSelectionGroupTarget");
		return false;
	}


	pisKeyPressedTarget = reinterpret_cast<isKeyPressed>(MinHookManager::GetIsKeyPressedAddr());	
	if (MH_CreateHook(reinterpret_cast<void**>(pisKeyPressedTarget), &isKeyPressedHook, reinterpret_cast<void**>(&pisKeyPressed)) != MH_OK) {
		logErr("failed to create pisKeyPressedTarget");
		return false;
	}


	pidMenu_UpdateTarget = reinterpret_cast<idMenu_Update>(MinHookManager::GetIdMenuUpdateAddr());	
	if (MH_CreateHook(reinterpret_cast<void**>(pidMenu_UpdateTarget), &idMenu_UpdateHook, reinterpret_cast<void**>(&pidMenu_Update)) != MH_OK) {
		logErr("failed to create pidMenu_UpdateTarget");
		return false;
	}


	pBindsStrSetTarget = reinterpret_cast<BindsStrSet>(MinHookManager::GetPBindsStrSetAddr());
	if (MH_CreateHook(reinterpret_cast<void**>(pBindsStrSetTarget), &BindsStrSetHook, reinterpret_cast<void**>(&pBindsStrSet)) != MH_OK) {
		logErr("failed to create pBindsStrSetTarget");
		return false;
	}

	pidHUD_Reticle_SetActiveReticleTarget = reinterpret_cast<idHUD_Reticle_SetActiveReticle>(MinHookManager::GetSetActiveReticleAddr());
	if (MH_CreateHook(reinterpret_cast<void**>(pidHUD_Reticle_SetActiveReticleTarget), &idHUD_Reticle_SetActiveReticleHook, reinterpret_cast<void**>(&pidHUD_Reticle_SetActiveReticle)) != MH_OK) {
		logErr("failed to create pidHUD_Reticle_SetActiveReticleTarget");
		return false;
	}

	pconvertIdDeclUIColorToidColorTarget = reinterpret_cast<convertIdDeclUIColorToidColor>(MinHookManager::GetConvertIdDeclUIColorToIdColorTargetAddr());	
	if (MH_CreateHook(reinterpret_cast<void**>(pconvertIdDeclUIColorToidColorTarget), &convertIdDeclUIColorToidColorHook, reinterpret_cast<void**>(&pconvertIdDeclUIColorToidColor)) != MH_OK) {
		logErr("failed to create pconvertIdDeclUIColorToidColorTarget");
		return false;
	}

	

	psetSpriteInstanceColorTarget = reinterpret_cast<setSpriteInstanceColor>(MinHookManager::GetSetSpriteInstanceAddr());
	if (MH_CreateHook(reinterpret_cast<void**>(psetSpriteInstanceColorTarget), &setSpriteInstanceColorHook, reinterpret_cast<void**>(&psetSpriteInstanceColor)) != MH_OK) {
		logErr("failed to create psetSpriteInstanceColorTarget");
		return false;
	}


	pPrintOutlinedStringMB_target = reinterpret_cast<printOutlinedStringMB_func>(MinHookManager::GetPrintOutlinedStringMBFuncAddr());
	//pPrintOutlinedStringMB_target = reinterpret_cast<printOutlinedStringMB_func>(MemHelper::getFuncAddr(0x4CAD00));
	if (MH_CreateHook(reinterpret_cast<void**>(pPrintOutlinedStringMB_target), &printOutlinedStringMB_hook, reinterpret_cast<void**>(&pPrintOutlinedStringMB)) != MH_OK) {
		logErr("failed to create pPrintOutlinedStringMB_target");
		return false;
	}	



	/*p_idInventoryCollection_Smth_Target = reinterpret_cast<idInventoryCollection_Smth_t>(MinHookManager::GetIdInventoryCollectionSmthFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_idInventoryCollection_Smth_Target), &idInventoryCollection_Smth_Hook, reinterpret_cast<void**>(&p_idInventoryCollection_Smth)) != MH_OK) {
		logErr("Failed to create idInventoryCollection_Smth hook.");
		return false;
	}*/
		

	p_customAnimSmth_t_Target = reinterpret_cast<customAnimSmth_t>(MinHookManager::GetCustomAnimSmthFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_customAnimSmth_t_Target), &customAnimSmth_t_Hook, reinterpret_cast<void**>(&p_customAnimSmth_t)) != MH_OK) {
		logErr("Failed to create p_customAnimSmth_t_Target hook.");
		return false;
	}
	

	p_idHUDMenu_CurrencyConfirmation_t_Target = reinterpret_cast<idHUDMenu_CurrencyConfirmation_t>(MinHookManager::GetIdHUDMenu_CurrencyConfirmationSmthFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_idHUDMenu_CurrencyConfirmation_t_Target), &idHUDMenu_CurrencyConfirmation_t_Hook, reinterpret_cast<void**>(&p_idHUDMenu_CurrencyConfirmation_t)) != MH_OK) {
		logErr("Failed to create p_idHUDMenu_CurrencyConfirmation_t_Target hook.");
		return false;
	}	
	


	p_StartSync_t_Target = reinterpret_cast<StartSync_t>(MinHookManager::GetStartSyncFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_StartSync_t_Target), &StartSync_t_Hook, reinterpret_cast<void**>(&p_StartSync_t)) != MH_OK) {
		logErr("Failed to create p_StartSync_t_Target hook.");
		return false;
	}


	p_idPlayerFovLerp_Target = reinterpret_cast<idPlayerFovLerp_t>(MinHookManager::GetIdPlayerFovLerpFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_idPlayerFovLerp_Target), &idPlayerFovLerp_Hook, reinterpret_cast<void**>(&p_idPlayerFovLerp)) != MH_OK) {
		logErr("Failed to create p_idPlayerFovLerp_Target hook.");
		return false;
	}


	p_syncEnd_Target = reinterpret_cast<syncEnd_t>(MinHookManager::GetSyncEndFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_syncEnd_Target), &syncEnd_Hook, reinterpret_cast<void**>(&p_syncEnd)) != MH_OK) {
		logErr("Failed to create p_syncEnd_Target hook.");
		return false;
	}


	p_RenderSprite_Target = reinterpret_cast<RenderSprite_t>(MinHookManager::GetRenderSpriteFuncAdd());
	if (MH_CreateHook(reinterpret_cast<void**>(p_RenderSprite_Target), &RenderSprite_Hook, reinterpret_cast<void**>(&p_RenderSprite_Original)) != MH_OK) {
		logErr("Failed to create RenderSprite hook.");
		return false;
	}


	p_idHud_PerspectiveSmth_t_Target = reinterpret_cast<idHud_PerspectiveSmth_t>(MemHelper::getFuncAddr(0x1549D80));
	if (MH_CreateHook(reinterpret_cast<void**>(p_idHud_PerspectiveSmth_t_Target), &idHud_PerspectiveSmth_t_Hook, reinterpret_cast<void**>(&p_idHud_PerspectiveSmth_t)) != MH_OK) {
		logErr("Failed to create p_idHud_PerspectiveSmth_t_Target hook.");
		return false;
	}

	
	p_hud_drawPerspectiveSmth_t_Target = reinterpret_cast<hud_drawPerspectiveSmth_t>(MemHelper::getFuncAddr(0x1549A70));
	if (MH_CreateHook(reinterpret_cast<void**>(p_hud_drawPerspectiveSmth_t_Target), &hud_drawPerspectiveSmth_t_Hook, reinterpret_cast<void**>(&p_hud_drawPerspectiveSmth_t)) != MH_OK) {
		logErr("Failed to create p_hud_drawPerspectiveSmth_t_Target hook.");
		return false;
	}



	//? this can only be changed by restarting the game mod, as this hook is only enabled in debug mode and if user enables it in menu
	if ((Config::get() != ModConfig::nexusRelease) && modSettings::isLogConsoleToLogFile()) {

		pIdLib_PrintfTarget = reinterpret_cast<IdLib_Printf>(MinHookManager::GetConsoleLogFuncAdd());
		if (MH_CreateHook(reinterpret_cast<void**>(pIdLib_PrintfTarget), &IdLib_PrintfHook, reinterpret_cast<void**>(&pIdLib_Printf)) != MH_OK) {
			logErr("Failed to create pIdLib_Printf hook.");
			return false;
		}
	}

	


	//? keep thoses we never know:
	/*p_idSyncEntity_HandleEvents_t_Target = reinterpret_cast<idSyncEntity_HandleEvents_t>(MemHelper::getFuncAddr(0x21925A0));
	if (MH_CreateHook(reinterpret_cast<void**>(p_idSyncEntity_HandleEvents_t_Target), &idSyncEntity_HandleEvents_t_Hook, reinterpret_cast<void**>(&p_idSyncEntity_HandleEvents_t)) != MH_OK) {
		logErr("Failed to create p_idSyncEntity_HandleEvents_t_Target hook.");
		return false;
	}*/


	/*p_idHands_handleEvents_t_Target = reinterpret_cast<idHands_handleEvents_t>(MemHelper::getFuncAddr(0x21B7FC0));
	if (MH_CreateHook(reinterpret_cast<void**>(p_idHands_handleEvents_t_Target), &idHands_handleEvents_t_Hook, reinterpret_cast<void**>(&p_idHands_handleEvents_t)) != MH_OK) {
		logErr("Failed to create p_idHands_handleEvents_t_Target hook.");
		return false;
	}*/

	


	pOriginalWndProc = (WNDPROC)SetWindowLongPtr(g_game_hWindow, GWLP_WNDPROC, (LONG_PTR)&HookedWndProc);


	Sleep(100); // just in case.

	// Enable all hooks at once
	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		logErr("InitializeHooks: MH_EnableHook(MH_ALL_HOOKS) failed.");
		return false;
	}

	logInfo("All Hooks successfully created and enabled.\n");
	return true;

}




DWORD __stdcall EjectThread(LPVOID lpParameter) {
	Sleep(100);
	FreeLibraryAndExitThread(DllHandle, 0);
}



//? Reminder: the way to load this dll with xenos is simply to change the output name to smth like somedll.dll.
DWORD WINAPI ModMain() {


	//? attempting to close the mod if/when idlauncher triggers msimg32.dll 
	if (!mem.isGameFileNameValid()) {
		CreateThread(0, 0, EjectThread, 0, 0, 0);
		return 0;
	}
	

	//? if you want to enable/ disable the console just comment/uncomment the DISABLE_LOGGING_CONSOLE line in console.cpp. i haven't tested with imgui so it migth create issues...
	Console::Enable();
   
	
	//! even though we managed to find a way to change a file logging level at runtime, because the mod will have a release and debug version we don't have to get any "version" from the json settings file.
	//? IF YOU EVER UPDATE THE OLD MOD VERSION MAKE SURE TO ADD ITS MD5 TO THE LIST OF CONFLICTING MODS TO CHECK FOR
	Config::set(ModConfig::dev); // nexusRelease, nexusDebug, dev

	Config::printHeaderInLogFile();

	if (HashManager::isPreviousModVersionInGameFolder()) {
		TTS::addToQueue(L"ERROR. Found previous version of this mod in the game folder, please check the log file.");
		TTS::sayAllInQueue(); //! make sure this is called before the isHookError check
		CreateThread(0, 0, EjectThread, 0, 0, 0);
		return 0;
	}

	if (!g_isDllInitOk) {
		logErr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		logErr("DllInit failed...Mod 'should' not work.");
		logErr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	
	FileOp::listModDirectory();


	if (HashManager::isMeathookModInGameFolder()) {
		logWarn("********************************************************************************************");
		logWarn("User is using meathook mod (logging this for debug purposes in case of conflict/crash/freeze )");
		logWarn("********************************************************************************************");
	}	

	if (!Config::isModError() && FileOp::isGameDirectoryValid()) {

		if (!FileOp::isModDirectory()) {
			if (!FileOp::CreateModDirectoryV2()) {
				Config::setModError("initModDirectory failed to create mod directory, mod can not work");
			}
		}

		if (!Config::isModError()) {
			modSettings::loadSettings();
			modSettings::saveSettings();
		}		
	}


	//? this actually works even if we don't need it atm. KEEP IT
	/*logInfo("attempting to change Config mid func let's see it if works....");
	blablaConfig::set(ModConfig::nexusRelease);
	logWarn("config should now be nexusRelease and you should see this message.");
	logInfo("config should now be nexusRelease and you should NOT see this message.");*/



	if (!Config::isModError()) {
		if (!findGameWindow(Config::GAME_WINDOW_CLASS_NAME)) {
			Config::setModError("Could not find game window, mod will not work");
		}
	}

	if (!Config::isModError()) {
		uintptr_t mainModuleAddr = MemHelper::getModuleBaseAddr();
		if (mainModuleAddr == NULL) {
			Config::setModError("Module base address is: NULL: mod can not work.");
		}
		else {
			logInfo("Module base address is: %p", (void*)mainModuleAddr);
		}
	}
	


	if (!Config::isModError()) {
		if (!Scanner::scanForAddrs()) {
			Config::setModError("Functions/structs scanning process failed mod can not work.");
		}
	}


	if (!Config::isModError()) {
		if (!InitializeHooks()) {
			Config::setModError("Failed to initalize minhook, mod can not work.");
		}
	}

	
	/*if (!Config::isModError()) {
		if (GameVersionInfoManager::isNewGameUpdateReleased()) {
			logWarn("This version of the game: %s is newer than the version the mod was made for, mod 'may' not work as attended or not work at all.", GameVersionInfoManager::getBuildVersionStr().c_str());

		}
		else {
			logInfo("Game build Version is as expected: %s", GameVersionInfoManager::getBuildVersionStr().c_str());
		}
	}*/


	/*if (Config::get() != ModConfig::nexusRelease) {

		logInfo("Listing Running processes to check for potential conflicts. (Keep in mind that any of those could conflict with this mod but it's up to you to experiment and temporarily disable/quite some of those applications to see if it will help with the issues you are currently having with the mod. You can open the task manager and check where each of this process is located)");
		logInfo("**** Listing Processes ****");

		std::unordered_set<std::string> runningProcessesSet = K_Utils::GetUniqueRunningProcessesSet();
		int counter = 0;
		for (const auto& process : runningProcessesSet)
		{
			if (process == ConflictingApps::MsiAfterBurnerProcessName) {
				logWarn("%s is an application that might make the mod crash/freeze.", process.c_str());
			}
			else {
				logInfo("%s", process.c_str());
			}
			counter++;
		}
		logInfo("**** Done listing %d processes. *****", counter);
	}*/


	if (!Config::isModError()) {
		if (Config::get() != ModConfig::nexusRelease) {
			TTS::addToQueue(L"Mod Load Succes !");
		}
			
	}
	else {
		TTS::addToQueue(L"Mod Error, check the mod log file in the game folder");
	}

	



	bool isFirstTimeStatusLog = true;
	static int loopSleepMs = 10;

	bool lastIsPlayerInGame = false;
	uint64_t lastOwnedItemsGetMs = 0;
	uint64_t lastStringOverwriteAttempMs = 0;
	uint64_t lastGetAsyncKeyPressMs = 0;
	uint64_t lastIniFileReloadMs = 0;
	uint64_t lastDeclWeaponOverwriteMs = 0;
	uint64_t lastGameTimeDebugMs = 0;
	uint64_t lastcustomUICoordsCheckMs = 0;
	uint64_t lastcolorReloadMs = 0;
	uint64_t lastWeaponSwitchCheckMs = 0;
	uint64_t lastIdInventoryGetMs = 0;
	uint64_t lastWeaponSettingCheckMs = 0;
	uint64_t lastHudColorsUpdateCheckMs = 0;
	uint64_t lastImmersiveCrosshairCheckMs = 0;
	uint64_t lastCrosshairScaleCheckMs = 0;
	uint64_t lastCrosshairInScropCheckMs = 0;
	uint64_t lastinGameReticleModeCheckMs = 0;
	uint64_t lastPulseColorUpdateMs = 0;
	uint64_t lastFXCheckMs = 0;
	uint64_t lastIniFileWatcherCheckMs = 0;
	uint64_t lastDebugWarningMs = 0;
	uint64_t lastFragIconBlinkTestMs = 0;
	uint64_t lastCustomIceNadeIconCheckMs = 0;
	uint64_t lastIceIconCoordsUpdateCheckMs = 0;
	uint64_t lastForceDebugStringCheckMs = 0;
	uint64_t lastIsDemonPlayerCheckMs = 0;
	uint64_t lastGameModeCheckMs = 0;
	uint64_t lastIsReticleHideCheckkMs = 0;
	uint64_t lastIsInCinematicCheckkMs = 0;
	uint64_t lastIdPlayerCheckMs = 0;
	uint64_t lastHudDebugMs = 0;
	uint64_t lastScreenResCheckMs = 0;
	uint64_t lastCustomHudcheckMs = 0;
	uint64_t lastFragSelectedCheckMs = 0;
	uint64_t lastAACheckMs = 0;
	
	//uint64_t lastCurrentActiveReticleCheckMs = 0;
	bool wasPlayerInMenu = false;

	bool debugIsFragNadeIconToggle = false;

	uint64_t lastPlayerFlagUpdateMs = 0;
	//! in game, not a demon, not in cutscene, not dead.
	bool isSlayerActiveFlag = false ;
	//! in game, playing as a demon not dead
	bool isDemonActiveFlag = false;
	//! same above but can be in cutscene
	bool isSlayerInTheWorldFlag = false;

	//! this corresponds to the game seetings hud croshair only or Full
	bool isGameSettingsHudEnabled = false;

	//! the equipment info from UI game settings
	bool isEquipmentInfoEnabled = false;;

	bool isInScope = false;

	bool isFragNadeOwned = false;
	bool isIceNadeOwned = false;

	bool last_bShowMenu = false; //! mod menu




	while (true) {


		if (isFirstTimeStatusLog) {
			logInfo("FirstTimeStatusLog:");
			logInfo("main loop Sleep Ms: %d", loopSleepMs);
			logInfo("isModError: %s", Config::isModError() ? "true" : "false");

			isFirstTimeStatusLog = false;
		}

		//? trying this to check if we can use it to know if game is initialized and mod can "start"
		//PlayerStateChecker::updateGameState();

		Sleep(loopSleepMs); //! having a long sleep here will not haVK_NUMPADve influence on the hooks which is great. 		

		TTS::sayAllInQueue(); //! make sure this is called before the isHookError check



		if (Config::isModError()) {
			if (g_isCloseModRequestFlag) {
				logInfo("DEBUG: setting g_isCloseModRequestFlag to true...");
				break;
			}
			/*if (Config::isDevMode() && GetAsyncKeyState(VK_NUMPAD0) && ((EpochMillis() - g_lastGetAsyncKeyPress) > 500)) {
				g_lastGetAsyncKeyPress = EpochMillis();
				logInfo("DEBUG: user just pressed  VK_NUMPAD0: attempting to Unload Mod...");
				break;
			}*/
			continue;   //! keep the mod running so it can output some msg to console/file      
		}		



		//! atm initialized state is set in idMenu_UpdateHook
		if (!PlayerStateChecker::isGameInitialized()) {
			//logInfo("main loop: ! PlayerStateChecker::isGameInitialized()");
			continue;	//! if the mod has levelLoaded succesfully, we don't do anything until the game is levelLoaded.
		}


		//! the hook will make sure the init only happen if menu update has been called once and if we haven't tried init imgui before 
		initImguiV2();


		modInit();	//! <= this will execute only once whatever happen.	



		//! haven't seen any crash in horde mod, since then but let's be vigilent...
		//x unfortunately this will not help with the random crash of loading horde mode level
		bool isReadyToRenderIceIcon = LoadingScreenManager::isReadyToRenderIceIcon();
		if (isReadyToRenderIceIcon != g_debugIsReadyToRenderIceNadeIcon) {
			g_debugIsReadyToRenderIceNadeIcon = isReadyToRenderIceIcon;
			logInfo("isReadyToRenderIceIcon has changed to: %d", isReadyToRenderIceIcon);
		}

		//LoadingScreenManager::printLoadScreenDataChange();

		PlayerStateChecker::updatePlayerState();

		
		if (PlayerStateChecker::isGameLoading()) {
			//logInfo(" main loop: PlayerStateChecker::isGameLoading())");
			//? this is horrible....
			idPlayer_K::resetLastBloodPunchCount(); // to make sure it updates the colors when player spawns
			idPlayer_K::resetLastIceGrenadeCount(); // to make sure it updates the colors when player spawns
			idPlayer_K::resetLastFragGrenadeCount();
			//logInfo("Game is loading....resetting inventory count");
			//switcher.resetInventoryCount();
			continue; //! not doing anything while game loads as this is too prone to crashes.
		}		


		if (EpochMillis() - lastAACheckMs > 1000) {

			idCmd::setAntiAliasingState(modSettings::getIsDisableAA());

			lastAACheckMs = EpochMillis();
		}

		



		if (PlayerStateChecker::isPlayingAndActive()) { //? means not in cutscene too


			if ((EpochMillis() - lastPlayerFlagUpdateMs) > 200) {

				//logInfo("PlayerStateChecker::isPlayingAndActive() .......");

				//? not sure if those 2 are necessary after all...
				isSlayerActiveFlag = idPlayer_K::isSlayerActiveFlag();
				isDemonActiveFlag = idPlayer_K::isDemonActiveFlag();
				isSlayerInTheWorldFlag = idPlayer_K::isSlayerInTheWorldFlag();

				isFragNadeOwned = idInventoryCollectionManager::isFragNadeOwned();
				isIceNadeOwned = idInventoryCollectionManager::isIceNadeOwned();

				isGameSettingsHudEnabled = fastCvarManager::getIsShowHudEnabled();
				isEquipmentInfoEnabled = fastCvarManager::getIsEquipmentInfoEnabled();

				isInScope = idPlayer_K::isInScope();


				lastPlayerFlagUpdateMs = EpochMillis();
			}


			if (modSettings::isImprovedWeaponSwitching() && isSlayerActiveFlag && (EpochMillis() - lastWeaponSwitchCheckMs) > 100) {
				lastWeaponSwitchCheckMs = EpochMillis();
				switcher.checkWeaponSwitchV2();
			}

			//! Not using this anymore as we modify DeclWeapons in the Resource we found:
			//if (EpochMillis() - lastWeaponSettingCheckMs > 300) { //! every 500 ms
			//	lastWeaponSettingCheckMs = EpochMillis();
			//	//ws.checkCurrentlyEquippedIdWeapon();
			//}

			//! this is used to check if a weapon or a nade is owned. 500ms should be good enough.
			if (EpochMillis() - lastIdInventoryGetMs > 400 && isSlayerInTheWorldFlag) {				
				idInventoryCollectionManager::updateCustomInventory();
				lastIdInventoryGetMs = EpochMillis();
				//idInventoryCollectionManager::updateOwnedItemsIds();
			}


			//! custom Hud			
			if (EpochMillis() - lastCustomHudcheckMs > 200) {

				//logInfo("hello?????: isSlayerActiveFlag: %d", isSlayerActiveFlag);

				Menu::bShowKaibzCrosshairWindow = modSettings::getIsUseImguiDotCrosshair() && (isSlayerActiveFlag || isDemonActiveFlag);			

				Menu::bShowKaibzHudWindow = modSettings::getIsUseKaibzHud() && (isSlayerActiveFlag || isDemonActiveFlag);		

				lastCustomHudcheckMs = EpochMillis();
			}

			//? it doesn't work.....
			// enforcing frag just to be absolutely sure there is no way ice can be selected when dedicated nade key is enabled
			if (EpochMillis() - lastFragSelectedCheckMs > 1000) {

				if (modSettings::getIsUseDedicatedNadeKeys() && idPlayer_K::getSelectedGrenadeType() == equipmentType_t::EQUIPMENT_ICE_BOMB) {

					logInfo("idPlayer_K::setGrenadeType(GrenadeType::Frag); trig....");
					EquipmentManager::switchEquipment(equipmentType_t::EQUIPMENT_FRAG_GRENADE);
				}

				lastFragSelectedCheckMs = EpochMillis();
			}

			
			

			//! Game hud Ice Nade Icon:			
			if (EpochMillis() - lastCustomIceNadeIconCheckMs > 200) {		

				//logInfo("isFragNadeOwned in lskdjf is: %d and isIceNadeOwned: %d", isFragNadeOwned, isIceNadeOwned);
				//! we don't render if frag is not owned cause if player uses console to give himself ice and not frag at game start it will show double ice icon and as a side note when using the ice in that config the icon shows up while reloading and then disappears, certainly cause it's not meant to be this way.
				if (!isSlayerActiveFlag || !isIceNadeOwned || !isFragNadeOwned || !isEquipmentInfoEnabled || !isGameSettingsHudEnabled || ! modSettings::getIsUseDedicatedNadeKeys()) {

					CustomIceNadeIconManager::updateIsRenderingAllowed(false);
				}
				else {
					CustomIceNadeIconManager::updateIsRenderingAllowed(true);
				}

				if (idRenderModelGuiManager::getScreenWidth() != g_debugScreenWidth || idRenderModelGuiManager::getScreenHeight() != g_debugScreenHeight) {

					g_debugScreenWidth = idRenderModelGuiManager::getScreenWidth();
					g_debugScreenHeight = idRenderModelGuiManager::getScreenHeight();
					logInfo("Screen Resolution has changed: width: %.2f height:  %.2f updating ice icon coords", g_debugScreenWidth, g_debugScreenHeight);

					CustomIceNadeIconManager::updateCoords();
				}
				//! may be overkill but safety first.
				else if (PlayerStateChecker::getPlayerState() != g_debug_lastPlayerState || (EpochMillis() - lastIceIconCoordsUpdateCheckMs) > 1000) {
					lastIceIconCoordsUpdateCheckMs = EpochMillis();
					g_debug_lastPlayerState = PlayerStateChecker::getPlayerState();

					CustomIceNadeIconManager::updateCoords();
				}

				//? order matters here		
				CustomIceNadeIconManager::updateIsIceNadeCooldownStatus();
				CustomIceNadeIconManager::updateColors();
				//CustomIceNadeIconManager::updateMaterials();
				CustomIceNadeIconManager::updateCooldownTimeLeftStr(); // will only update data is ice on cooldown

				lastCustomIceNadeIconCheckMs = EpochMillis();
			}



			//! making sure the debugHud is active even if user tries to disable the debug string somehow through console cmd.
			if (EpochMillis() - lastForceDebugStringCheckMs > 5000) {
				lastForceDebugStringCheckMs = EpochMillis();
				idCmd::forceDebug_hud_string();
			}



			if (EpochMillis() - lastHudColorsUpdateCheckMs > 200 && !idPlayer_K::isPlayerDemon()) {
				//! i know it's not elegant but i'd rather be sure that i triggers for now		
				

				ColorManager::reapplySwfColors();
				
				//if (idPlayer_K::isBloodPunchCountChanged()) {
				//	ColorManager::reapplySwfColors();
				//}

				//else if (isIceNadeOwned && idPlayer_K::isIceNadeCountChanged()) {
				//	ColorManager::reapplySwfColors();
				//}

				//else if (isFragNadeOwned && idPlayer_K::isFragNadeCountChanged()) {
				//	ColorManager::reapplySwfColors();
				//}
				////else if (isIceNadeOwned && idPlayer_K::isHudSelectedGrenadeChanged()) {
				//else if (isIceNadeOwned) {
				//	ColorManager::reapplySwfColors();
				//}
				//! the dot color update could may be be done in the idHUD_Reticle_SetActiveReticleHook but it just works fine this way, and may puts less "stress" on the hook function .

				//? commenting this for now while testing V3:
				//ReticleColorManager::updateDotColorV2();

				//ReticleColorManager::debugUpdateDotColor();				

				//! reaapplying swf colors every seconds or so to make sure the hud is updated as i noticed, rarely the grenade arrow being not always accurate. This function will not callreapplySwfColorsCmd all the time but has an internal check with epochmillis:
				//ColorManager::autoReapplySwfColors(); //! <= on a timer

				lastHudColorsUpdateCheckMs = EpochMillis();
			}



			//! this is not great but this is a way to make sure user will see a crosshair in the immersive weapons ads otherwiser he might think the feature is broken because there are no crosshair anywhere and think that this feature need the None crosshair mode to work. We can't just do a check in the iniFile load cause user can change the in game Crosshair mode at any tim
			if (EpochMillis() - lastinGameReticleModeCheckMs > 300) {
				lastinGameReticleModeCheckMs = EpochMillis();

				if (!idPlayer_K::isPlayerDemon() && modSettings::isImmersiveCrosshairModeEnabled()) {
					//if (idCmd::getReticleMode() == UI_ReticleMode::None) {
					if (fastCvarManager::getReticleMode() == UI_ReticleMode::None) {
						idCmd::setReticleMode(UI_ReticleMode::Full);
						logInfo("mod main loop: forcing UI_ReticleMode::Full because immersive crosshair is on");
					}
				}
			}
		}

		//! trying a pure else to see if it fixes the issue with the ice nade icon showing in pause menus like the pop up for the insert battery cell:
		else {
			CustomIceNadeIconManager::updateIsRenderingAllowed(false);

			Menu::bShowKaibzCrosshairWindow = false;
			Menu::bShowKaibzHudWindow = false;
		}

		//x in cutscene or technically the reticle update func stops being triggered which means the crosshair should not be drawn, so slayer is not ready to fight. (doesn't matter what crosshair setting from the game menu)
		//else if (PlayerStateChecker::isNotAbleToFight()) {

		//	//! this should prevent the bug of the ice nade showing in cutscenes and while dead.
		//	CustomIceNadeIconManager::updateIsRenderingAllowed(false);
		//}

	


		//? !!!!!!!!!!!!!     CRITICAL    !!!!!!!!!!!!!!!!!!!!!!!!
		if (g_isCloseModRequestFlag) {
			logInfo("DEBUG: loop: setting g_isCloseModRequestFlag is true, attempting to Unload Mod...");
			break;
		}			
			
	}



	(logWarn("mod is closing, forcing in_mouse to 1 to prevent mouse being disabled next time game is launched "));
	idCmd::SetInMouseEnabled(true);


	//? disabling this as H::Free(); will disable minhook globally and if we leave disableHooks(); it seems to create a conflict and mod can not be unloaded completely which create issue for testing the mod when using Xenos.
	//disableHooks();
	

	H::bShuttingDown = true;	
	
	H::Free();

	DisableWndProcHook(g_game_hWindow);
	
	MH_STATUS mhStatus = MH_Uninitialize();
	auto mhStatusCstr = MH_StatusToString(mhStatus);
	logInfo("quitting mod debug: mhStatusCstr: %s", mhStatusCstr);

	K_Utils::PlayModUnloadedBeeps();
	logInfo("attemting to exit mod...");
	CreateThread(0, 0, EjectThread, 0, 0, 0);	
	return 0;

	
}



DWORD WINAPI OnProcessDetach(LPVOID lpParam) {
	
	Console::Hide();	
	return 0;
}



extern "C" BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);


	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {

		
		DllHandle = hModule;
		DllInit();
		DisableThreadLibraryCalls(hModule);
		

		HANDLE hHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ModMain, DllHandle, 0, NULL);
		if (hHandle != NULL) {
			CloseHandle(hHandle);
		}
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH && !lpReserved) {
		OnProcessDetach(NULL);
	}

	return TRUE;











   // switch (ul_reason_for_call)
   // {
   //     case DLL_PROCESS_ATTACH:
			//DllHandle = hModule;
			////std::cout << "DllHandle value is DllMain: " << reinterpret_cast<uintptr_t>(DllHandle) << std::endl;
   //         DisableThreadLibraryCalls(hModule);

			//U::SetRenderingBackend(VULKAN);
   //         //InitInstance();
			//CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ModMain, DllHandle, 0, nullptr);
   //         break;

   //     case DLL_PROCESS_DETACH:
   //         break;
   // }

   // return TRUE;
}

//DWORD WINAPI OnProcessAttach(LPVOID lpParam) {
//	Console::Alloc();
//	LOG("[+] Rendering backend: %s\n", U::RenderingBackendToStr());
//	if (U::GetRenderingBackend() == NONE) {
//		LOG("[!] Looks like you forgot to set a backend. Will unload after pressing enter...");
//		std::cin.get();
//
//		FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(lpParam), 0);
//		return 0;
//	}
//
//	MH_Initialize();
//	H::Init();
//
//	return 0;
//}

