#pragma once

//? atm the order and includs in this file is important to be able to build, we need to sanatize all this....

#include <windows.h>
#include <DbgHelp.h>
#include <thread>
#include <intrin.h>
#include <string>
#include <iostream>
#include "MinHook.h"
#include "intrin.h"
#include <sstream> //for std::stringstream 
#include <vector>
#include <cstring>
//#include "SWIP.h"


#include "Common/MemHelper.h"

#include "DE/WeaponSettings.h"
#include "DE/WeaponSwitcher.h"
#include "DE/PlayerStateChecker.h"
#include "DE/ButtonCheck.h"
//#include "DE/StringChanger.h"

//#include "DE/GameStateChecker.h"
#include "DE/LangManager.h"
#include "DE/BindLabelChanger.h"
//#include "DE/idResource.h"
#include "DE/idPlayer.h"
#include "DE/idCmd.h"
//#include "DE/idDebugHUDLocal.h"
//#include "DE/idConsoleLocal.h"
#include <stdarg.h>
//#include "Debug/SwfDebug.h"
#include "DE/idFontManager.h"
//#include "DE/SwfHud.h"
#include "DE/idHudEventManager.h"
#include "DE/GameHudColorsManager.h"
//#include "DE/Debug.h"

//#include "DE/HudManager.h"
//#include "Hud/HudManager.h"

#include "Common/Voice.h"
#include "Config.h"
#include "Common/FileWatcher.h"
#include "DE/idWeaponManager.h"
//#include "DE/idHUD_ReticleManager.h"
//#include "DE/SpriteInstanceManager.h"
#include "DE/ReticleScaleManager.h"
#include "DE/ReticleColorManager.h"
#include "DE/idSWFSpriteInstanceManager.h"
#include "DE/idDeclWeaponReticleManager.h"
#include "DE/idSWFWidgetManager.h"
#include "MinHookManager.h"
#include "DE/idConsoleLocalManager.h"
//#include "Hud/HudDataBuffer.h"
#include "DE/Debug.h"
#include "DE/idRenderModelGuiManager.h"
#include "DE/GameHudColorsManager.h"
#include "DE/MaterialLib.h"
#include "DE/MaterialDebug.h"
#include "DE/CustomIceNadeIconManager.h"
#include "DE/LoadingScreenManager.h"

#include "ImGui/console/console.hpp"
#include "ImGui/hooks/hooks.hpp"
#include "ImGui/utils/utils.hpp"
#include "ImGui/dependencies/minhook/MinHook.h"
#include "ImGui/ImGuiUserConfig.h"
#include "ImGui/dependencies/imgui/imconfig.h"

#include "DE/ImGuiManager.h"

#include "DE/modSettings.h"	

#include "DE/Scanner.h"
#include "HashManager.h"
#include "ImGui/menu/menu.hpp"
#include "DE/ColorManager.h"
#include "DE/idEventManager.h"
//#include "DE/CustomizedWeaponManager.h"
#include "DE/idDeclUIColorManager.h"
#include "DE/CustomCrosshairManager.h"
#include "DE/EquipmentManager.h"
#include "DE/playerSoundManager.h"
#include "DE/weaponFovManager.h"
#include "DE/idCmd.h"
//#include "DE/HudAmmoData.h"
#include"DE/Sigs.h"
//#include "Debug/idPlayerDebug.h"
//#include "Debug/idInventoryManagerDebug.h"
#include "DE/idFxManager.h"
//#include "Rtti/Rtti_Helper.h"
#include "DE/ReticleColorManager.h"
//#include "Debug/ReticleSettingsDebug.h"
#include "DE/GameInfoManager.h"
#include "DE/idHudManager.h"
#include "DE/idPlayerMetricsManager.h"
#include "DE/idLib_Dynamic.h"
#include "DE/idDebugManager.h"




#define GAME_VERSION_A


//#include "Asm/GetRBPValueWithRAxPreserved.asm"
//#include "DE/TypesGenerated.h"
//#include "DE/idSWFWidget_Hud_Reticle.h"


#if _WIN64 
#pragma comment(lib, "libMinHook.x64.lib")
#else
#pragma comment(lib, "libMinHook.x86.lib")
#endif


//extern "C" __int64 GetRBPValueWithRAxPreserved();


bool g_debugIsReadyToRenderIceNadeIcon = false;

PlayerState g_debug_lastPlayerState = PlayerState::undefined;

float g_debugScreenWidth = -1;
float g_debugScreenHeight = -1;

idPlayer* g_debugLastIdPlayerPtr = nullptr;

bool g_debugIsReticleHide = false;
bool g_debugIsInCinematic = false;
bool g_debugIsDemonPlayer = false;

std::string g_debugLastCurrentGameMode = "unknow Game Mode";
//int g_debugActiveReticleStyleInt = -90;

//! 10 seems fine.
//unsigned int g_sleepTimeMainLoopMs = 10;

std::string globalVariableString;

bool g_isEnableHook2Triggered = false;

bool g_isGameCrosshairHidden = false;

bool g_isDebugHudEnabled = false;

idVec4 g_iceNadeIconDebugVec4;
__int64 g_debugMaterialAddr = 0;


bool g_isGameInitialized = false;
bool g_isDllCalledByGame = false;


//! key pressed
uint64_t g_lastGetAsyncKeyPress = 0;

bool g_debugReticleScale = true;


//! matr debug:
static std::vector<std::string> matrNamesVec;

//unsigned int g_testIdNamedColorIndex = 94;

//unsigned int g_namedColorBlue = 94; // blue
//unsigned int g_namedColorDebug = 2;

//std::vector<int> pathHashesDebugVec;
//std::vector<spriteDebug> spriteDebugVec;
//int hashDebugIndex = 0;

//const int iceNadeSelected = 1;
//const int normalNadeSelected = 2;
//int nadeStatus = -1;

std::string g_plusSignStr = "+";

//? *****  looks like we have to be careful when instanciating those objects as, if one has a ctor that tries to writes to our console it will prevent the console from working.
HINSTANCE DllHandle;
HWND g_game_hWindow = NULL;
HMODULE customMeatHook_hMod;

bool g_isDllInitOk = true;
bool g_isCloseModRequestFlag = false;

WNDPROC wndproc_original = NULL;
MemHelper mem;
//BindHelper binderHelper;
//EquipmentLauncher eql;
//WeaponSettings ws;
//idInventory inv;
WeaponSwitcher switcher;
PlayerState playerState;
ButtonCheck buttonCheck;
//StringChanger stringChanger;
//IniFile iniFile;
//IniFileData iniFileData;
LangManager lang;
BindLabelChanger bindLabelChanger;
//Md5Check md5Check;
//ModStatus modStatus;
//idResource idRes;
//idDebugHUDLocal debugHud;
//idConsoleLocal id_ConsoleLocal;
//SwfDebug swfDebug;g
//SwfHud swfHud;
//idFont IdFont;
//? looks like we have to be careful when instanciating those objects as, if one has a ctor that tries to writes to our console it will prevent the console from working. *****


//static idColor colorCustom_main = idColor{ 1.00f, 1.00f, 0.00f, 1.00f };

//void loadModSettingsFromFile();



// Define a custom struct to represent a 128-bit integer-like structure
struct Int128 {
	int64_t high;
	int64_t low;
};




WNDPROC pOriginalWndProc = nullptr;


LRESULT CALLBACK HookedWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {


	if (uMsg == WM_KEYDOWN) {

		if (Config::isDevMode()) {
			if (wParam == VK_F1) {
				Beep(500, 500);
				idCmd::setGameSpeed(gameSpeed_K::defaultSpeed);		


				//idDeclUIColorManager::acquireDefaultColors();
			/*	logInfo("HookedWndProc: VK_F1 pressed");
				__int64 result = idResourceListManager::getResourceListFirstElementPtr("idDeclUIColor");
				logInfo("idDeclUIColor add: result: %p", (void*)result);*/
						
				//idCmd::executeCommandText_K2("activateConsole 1");
			}
			else if (wParam == VK_F2) {
				logInfo("HookedWndProc: VK_F2 pressed");
				Beep(500, 500);
				idCmd::setGameSpeed(gameSpeed_K::maxSpeed);


				/*idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
				if (idPlayerObj) {
					idHUD_HealthInfo* idHUD_HealthInfoPtr = (idHUD_HealthInfo*)idHudManager::getIdHud_Element(HudElementName::HealthInfo);
					if (!MemHelper::isBadReadPtr(idHUD_HealthInfoPtr)) {
						logInfo("idHUD_HealthInfoPtr: %p idHUD_HealthInfoPtr->healthDesc: %p", idHUD_HealthInfoPtr, &idHUD_HealthInfoPtr->healthDesc);
						
					}
				}*/
				



				//ColorManager::reapplySwfColors();

			}

			//? this is our default show mod key dont use it !!!!!!!	
			/*else if (wParam == VK_F3) {
				logInfo("HookedWndProc: VK_F3 pressed.");				
						
			}*/

			else if (wParam == VK_F4) {
				logInfo("HookedWndProc: VK_F4 pressed");				

				//idMapInstanceLocalManager::isAnyAiAliveInLevel();
				//idPlayer_K::autoManagePlayerSpeed();

				//playerSoundManager::playOutOfItemSound();
				
				
				/*std::string propsStr = playerPropsManager::getDebugStrV2();
				logInfo("propsStr: %s ", propsStr.c_str());*/

				/*idDeclUIColor*  currentColorProfilePtr = idDeclGlobalShellManager::getCurrentColorProfile();
				if (currentColorProfilePtr) {
					logInfo("currentColorProfilePtr: %p", currentColorProfilePtr);
				}*/

				/*__int64 idDeclGlobalShellResList = idResourceListManager::getIdResourceListForClsName("idDeclGlobalShell");
				logInfo("idDeclGlobalShell IdResourceList addr: %p", (void*)idDeclGlobalShellResList);

				__int64 idDeclGlobalShellResList_resourceList_t = idDeclGlobalShellResList + 8;
				__int64  result = idResourceListManager::getResource(idDeclGlobalShellResList_resourceList_t, 0);
				logInfo("idDeclGlobalShell res addr: %p", (void*)result);*/

				//? doesn't work it will get an idMaterial (?!)
				/*__int64 FindWithInheritanceResult = idDeclInfo::FindWithInheritance(idDeclGlobalShellResList, "idDeclGlobalShell", 1);
				logInfo("FindWithInheritanceResult: %p", (void*)FindWithInheritanceResult);*/

				//idDeclUIColorManager::debugLogCurrentColorProfileName(0);

				//Menu::debugLogHudColors();

			/*	std::string kaibzHudFlagsDbgStr =  modSettings::debuGetFlagString();
				logInfo("kaibzHudFlagsDbgStr: %s", kaibzHudFlagsDbgStr.c_str());*/


			/*	std::string customHudDbgStr = KaibzHudManager::getDdgStrForImgui();
				logInfo("customHudDbgStr: %s", customHudDbgStr.c_str());*/


				//idResourceListManager::debugLogPlayerDeclWeapons();


				//CustomizedWeaponManager::debugLogWeaponsVals();

				//idResourceListManager::debugLogPlayerDeclWeapons();
				/*idResourceListManager::getidDeclWeaponResourceListTest();
				idResourceListManager::getResourceVecForClsName("idDeclWeapon");*/

				//! works:
				//idEventManager::debugLogEventAddr(0x450);

				/*std::string dgbStr = idPlayer_K::getDbgStrForImgui();
				logInfo("dgbStr: %s", dgbStr.c_str());*/
										

			}

			
			else if (wParam == VK_F5) {
				logInfo("HookedWndProc: VK_F5 pressed");
				Beep(500, 500);
				Menu::bShowDebugWindow = !Menu::bShowDebugWindow;

				std::string mapInstanceDbgStr = idMapInstanceLocalManager::getDbgStrForImgui();
				logInfo("%s", mapInstanceDbgStr.c_str());
				
			}



			if (wParam == VK_F6) {
				logInfo("HookedWndProc: VK_F6 pressed");
				Beep(500, 500);
				//EquipmentManager::useEquipmentItem(equipmentType_t::EQUIPMENT_FRAG_GRENADE);
				EquipmentManager::switchEquipment(equipmentType_t::EQUIPMENT_FRAG_GRENADE);

				//! this works:
				//idHudEventManager::testSendHudEvent();


				//! this works
				//idDeclGlobalShellManager::disableNewCampaignPopUp();

				//void* entityPtr = idMapInstanceLocalManager::findEntity("intro_game_info_logic");
				//logInfo("entityPtr: %p", entityPtr);
				
				// idEventManager::testSendEvent();

			/*	eventsInfoGenerator eventGen;
				eventGen.dumpEventsListEnumToFile();*/


				//idEventManager::debug();

				/*__int64 idEventDefAddr = TypeInfoManager::getIdEventDefInterface();
				logInfo("idEventDefAddr : %p", (void*)idEventDefAddr);*/

				/*idFxManager::setDashEffect(true);*/

			}
			//else if (wParam == VK_F7) {
			//	logInfo("HookedWndProc: VK_F7 pressed");

			//	//EquipmentManager::useEquipmentItem(equipmentType_t::EQUIPMENT_ICE_BOMB);
			//	EquipmentManager::switchEquipment(equipmentType_t::EQUIPMENT_ICE_BOMB);


			//

			//}



			else if (wParam == VK_NUMPAD0) {
				//Beep(500, 500);
				logInfo("HookedWndProc: VK_NUMPAD0 pressed setting g_isCloseModRequestFlag to true");
				g_isCloseModRequestFlag = true;				
			}


			//! this is what you have to press to ouput the cls definitions if game updates someday as this will trigger when you press those keys whether the mod status is allgood or not:
			else if (wParam == VK_NUMPAD1 ) {
				//Beep(500, 100);
				logInfo("Debug: user just pressed  VK_NUMPAD1:");

							}


			else if (wParam == VK_NUMPAD2) {
				//Beep(500, 100);
				logInfo("HookedWndProc: VK_NUMPAD2 pressed ");

				//? many of those are old....
				__int64 engine_t = TypeInfoManager::get_engine_t();
				logInfo("engine_t: %p", (void*)engine_t);
				//idHudManager::debugPrintAllHud_ElementsAddr();
				idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();
				logInfo("idPlayer: %p", idPlayerObj);
				idMapInstanceLocalManager::debugPrintCurrentIdMapInstanceLocal();
				//idInventoryCollectionManager::debugPrintCustomInventory();
				//idInventoryCollectionManager::debugPrintPlayerCompleteInventory();
				//idInventoryCollectionManager::debugPrintNonCollectiblePlayerInventory();
				//idPlayer_K::debug_Id_Hud();
				//idPlayer_K::debug_hudFlagsBeforeDemon();
				//GameHudColorsManager::debugLogFragIconCoords();
				//idPlayer_K::debugPrintFragNadeCoordsFromWeaponInfoV2();
				//TypeInfoManager::getGlobalFontTable();		

				//idResourceListManager::debugPrintIdMaterial2ResourceListAddr();

				/*auto Material2ResourceAdd = idResourceListManager::getResourceListFirstElementPtr("idMaterial2");
				logInfo("ressource Material2ResourceAdd: %p", (void*)Material2ResourceAdd);

				auto iceMatAdd = idDeclInfo::getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_", 0);
				logInfo("iceMatAdd: %p", (void*)iceMatAdd);

				auto fuelMatAdd = idDeclInfo::getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_fuel_", 0);
				logInfo("fuelMatAdd: %p", (void*)fuelMatAdd);*/


				/*auto colorProfileListAddr = idDeclGlobalShellManager::getColorProfileColorsListAddr();
				logInfo("debug: colorProfileListAddr: %p", (void*)colorProfileListAddr);*/
			}

			else if (wParam == VK_NUMPAD3) {
				
				logInfo("HookedWndProc: VK_NUMPAD3 pressed ");				
				
				//idFontManager::setConsoleFont(idFontHash::eternal88);
			}

			else if (wParam == VK_NUMPAD4) {

				logInfo("HookedWndProc: VK_NUMPAD4 pressed ");

				
				/*uintptr_t resAddr = idResourceListManager::getIdResourceListForClsName("idFont");
				logInfo("resAddr: %p", (void*)resAddr);*/

			/*	idDebugHUDLocal* dbgHud = TypeInfoManager::getdebugHUD();
				logInfo("dbgHud: %p", dbgHud);*/

				//idFontManager::debugLogFonts();

				//idFontManager::setConsoleFont(idFontHash::idTacticA8);
				/*logWarn("!!!!!!crashing on purpose !!!!!");
				volatile int* tmp = nullptr;
				int tmp1 = *tmp;*/

			}

			else if (wParam == VK_NUMPAD5) {

				logInfo("HookedWndProc: VK_NUMPAD4 pressed ");


			}

		}		
	}
	return CallWindowProc(pOriginalWndProc, hwnd, uMsg, wParam, lParam);
}





//! This works great to prevent hud elements from rendering like the the equipment arrows or the right side of the hud. RenderSprite_4FEC90
typedef char(__fastcall* RenderSprite_t)(
	void* idSwf_a1,
	__int64 a2,
	idSWFSpriteInstance* spriteInstance_a3,
	__int64 a4,
	unsigned int a5,
	char a6);

// Pointers to the original function and the target function
RenderSprite_t p_RenderSprite_Original = nullptr;
RenderSprite_t p_RenderSprite_Target = nullptr;

// Hooked function definition
char __fastcall RenderSprite_Hook(
	void* idSwf_a1,
	__int64 a2,
	idSWFSpriteInstance* spriteInstance_a3,
	__int64 a4,
	unsigned int a5,
	char a6) {
	

	if (!modSettings::getIsUseDedicatedNadeKeys()) {
		return p_RenderSprite_Original(idSwf_a1, a2, spriteInstance_a3, a4, a5, a6);
	}

	if (spriteInstance_a3) {

		int fullPathHash = spriteInstance_a3->fullPathHash;

		if (fullPathHash == equipmentArrowSpriteId) {
			return 0;
		}

		else if (fullPathHash == equipmentBackerSpriteId) {
			return 0;
		}

		/*else if (fullPathHash == weaponInfoBgSpriteId) {
			return 0;
		}*/

		/*else if (GameHudColorsManager::isHudElementWeaponRelated(fullPathHash)) {
			return 0;
		}*/

	}
	


	return p_RenderSprite_Original(idSwf_a1, a2, spriteInstance_a3, a4, a5, a6);
}






//! this lets us set the fov we want in GK, battery use..
typedef void* (__fastcall* idPlayerFovLerp_t)(__int64 idPlayer_a1, float a2, float a3, char a4);
idPlayerFovLerp_t p_idPlayerFovLerp = nullptr;
idPlayerFovLerp_t p_idPlayerFovLerp_Target = nullptr;

void* __fastcall idPlayerFovLerp_Hook(__int64 idPlayer_a1, float lerpFOV_a2, float a3, char a4) {

	if (modSettings::getIsOverideInteractionFOV()) {
		lerpFOV_a2 = modSettings::getInteractionFOV();
	}

	return p_idPlayerFovLerp(idPlayer_a1, lerpFOV_a2, a3, a4);
}



//! this will trigger, once, everytime a battery in socket animation starts. so a good place to set the timsescale X2, X4...
//? the only thing is that could trigger for other animations, so we'll have to make sure that this specific anim is what we want...
//! void __fastcall idSyncEntity::StartSync_13CEF20(__int64 idSyncEntity_a1, __int64 idDeclAnimWeb_a2, __int64 idPlayer_a3, float a4, __int64 a5)
typedef void(__fastcall* StartSync_t)(__int64 idSyncEntity_a1, __int64 idDeclAnimWebPTR_a2, __int64 idPlayer_a3, float a4, __int64 a5);
StartSync_t p_StartSync_t = nullptr;
StartSync_t p_StartSync_t_Target = nullptr;

void __fastcall StartSync_t_Hook(__int64 idSyncEntity_a1, __int64 idDeclAnimWebPTR_a2, __int64 idPlayer_a3, float a4, __int64 a5) {

	if (modSettings::getIsSpeedUpBatterySocketAnimation() && !MemHelper::isBadReadPtr((void*)idDeclAnimWebPTR_a2)) {
		idResource* res = (idResource*)*(__int64*)idDeclAnimWebPTR_a2;
		std::string declName = res->name.str;
		if (declName == "animweb/interact/hub_battery_socket/hub_battery_socket_syncanimweb") {
			logInfo("StartSync_t_Hook batter interaction detected !");
			idCmd::setGameSpeed(gameSpeed_K::X2_Speed);
		}
		else {
			logInfo("StartSync_t_Hook: found sync animation we're not speeding up (atm) declName: %s ", declName.c_str());
		}
	}	
	return p_StartSync_t(idSyncEntity_a1, idDeclAnimWebPTR_a2, idPlayer_a3, a4, a5);
}


//! syncEnd_13D1960 this is triggered once when a sync animation endds like the battery in socket one
typedef char(__fastcall* syncEnd_t)(__int64 a1, __int64 a2, int a3, unsigned int a4, unsigned __int8 a5);
syncEnd_t p_syncEnd = nullptr;
syncEnd_t p_syncEnd_Target = nullptr;

char __fastcall syncEnd_Hook(__int64 a1, __int64 a2, int a3, unsigned int a4, unsigned __int8 a5) {

	logInfo("syncEnd_Hook: reseting timescale....");
	idCmd::setGameSpeed(gameSpeed_K::defaultSpeed);

	return p_syncEnd(a1, a2, a3, a4, a5);
}




//? Update 21/8/24: this is not working as intended because even if it does indeed prevents the find secret animation from playing it will also cause the bug where the hands hold an invisible weapon. The bug Will only happen AFTER you find the first secret which caused wrong assumption this mod feature was working as intended.
////! returning from this will disable custom animations like when finding secret or some specific items 
////! char __fastcall customAnimSmth_19DA8A0(__int64 idHands_a1, const char *str_a2, int a3, int a4, int a5)
//typedef char(__fastcall* customAnimSmth_t)(__int64 idHands_a1, const char* str_a2, int a3, int a4, int a5);
//customAnimSmth_t p_customAnimSmth_t = nullptr;
//customAnimSmth_t p_customAnimSmth_t_Target = nullptr;
//
//char __fastcall customAnimSmth_t_Hook(__int64 idHands_a1, const char* str_a2, int a3, int a4, int a5) {
//
//	if (modSettings::getIsSkipCustomAnimations()) {
//		return 0;
//	}
//	//logWarn("customAnimSmth_t_Hook returning 0");	
//
//	return p_customAnimSmth_t(idHands_a1, str_a2, a3, a4, a5);
//}


//? 21/8/24 no, not good either will create the bug for example when acquiring the grenade and trying to grab the monkey bar after that
//typedef __int64(__fastcall* AnimEvent_SetMovementDuringCustomAnim_t)(__int64 idHands_a1, __int64 a2, __int64 a3, bool isDisableMovement_a4);
//AnimEvent_SetMovementDuringCustomAnim_t p_AnimEvent_SetMovementDuringCustomAnim = nullptr;
//AnimEvent_SetMovementDuringCustomAnim_t p_AnimEvent_SetMovementDuringCustomAnim_Target = nullptr;
//
//__int64 __fastcall AnimEvent_SetMovementDuringCustomAnim_Hook(__int64 idHands_a1, __int64 a2, __int64 a3, bool isDisableMovement_a4) {
//
//	//! will not actually skip custom animation but at least player will be able to move once he finds a secret.
//	//! this system could be made better but it will do for now.
//	if (modSettings::getIsSkipCustomAnimations() && isDisableMovement_a4) {
//		isDisableMovement_a4 = false;
//	}
//
//	return p_AnimEvent_SetMovementDuringCustomAnim(idHands_a1, a2, a3, isDisableMovement_a4);
//}




typedef __int64(__fastcall* idHUDMenu_CurrencyConfirmation_t)(__int64 idHUDMenu_CurrencyConfirmation_a1, __int64 struct_a2);
idHUDMenu_CurrencyConfirmation_t p_idHUDMenu_CurrencyConfirmation_t = nullptr;
idHUDMenu_CurrencyConfirmation_t p_idHUDMenu_CurrencyConfirmation_t_Target = nullptr;

__int64 __fastcall idHUDMenu_CurrencyConfirmation_t_Hook(__int64 idHUDMenu_CurrencyConfirmation_a1, __int64 struct_a2) {
		
	if (modSettings::getIsDisableBatterySocketPopUp()) {
		idHudEventManager::send_HUD_EVENT_CURRENCY_CONFIRM((idHUDElement*)idHUDMenu_CurrencyConfirmation_a1);
	}	

	return p_idHUDMenu_CurrencyConfirmation_t(idHUDMenu_CurrencyConfirmation_a1, struct_a2);
}



//! this triggers continuously when in any menu, main menu or pause menu. 183F0A0
//? however the idMenu ptr will be different when in main menu or pause menu ofc.
typedef __int64(__fastcall* idMenu_Update)(__int64 idMenu, __int64 a2);
idMenu_Update pidMenu_Update = nullptr;
idMenu_Update pidMenu_UpdateTarget;

__int64 __fastcall idMenu_UpdateHook(__int64 idMenu, __int64 a2) {

	ImGuiManager::setIsInitFlag(true);

	PlayerStateChecker::updateLastMenuRefresh(); //! this is a hacky and not so good way to know that the game has been (may be) initialized	

	return pidMenu_Update(idMenu, a2);
}



typedef float(__fastcall* getFovTargetValMB)(idWeapon* idWeaponAddr_a1);
getFovTargetValMB pgetFovTargetValMB = nullptr;
getFovTargetValMB pgetFovTargetValMBTarget;

//! sig: 48 83 EC 38 48 83 B9 ? ? ? ? ? 4C 8B C1
float __fastcall getFovTargetValMB_Hook(idWeapon* idWeaponObj_a1) {

	idWeaponManager::acquirreCurrentIdWeapon(idWeaponObj_a1);
	/*ws.getCurrentlyEquippedIdWeaponAdrr(idWeaponAddr_a1);*/
	//static __int64* lastIdWeaponPtr = 0;
	/*if (idWeaponPtr_a1 != lastIdWeaponPtr) {
		lastIdWeaponPtr = idWeaponPtr_a1;
		logInfo("idWeaponPtr_a1 has changed and is now: %p ", idWeaponPtr_a1);
	}*/
	return pgetFovTargetValMB(idWeaponObj_a1);
}



//! SelectWeaponForSelectionGroup Hook: char __fastcall SelectWeaponForSelectionGroupHook(__int64 gui_a1, int x_a2)
typedef char(__fastcall* SelectWeaponForSelectionGroup)(__int64 a1, int a2);
SelectWeaponForSelectionGroup pSelectWeaponForSelectionGroup = nullptr;
SelectWeaponForSelectionGroup pSelectWeaponForSelectionGroupTarget;

//! this is triggered everytime user presses a dedicated weapon key
char __fastcall SelectWeaponForSelectionGroupHook(__int64 a1, int weaponIndex_a2) {

	/*static int lastA2debug = -1;
	if (a2 != lastA2debug) {
		lastA2debug = a2;
		logWarn("SelectWeaponForSelectionGroupHook: a2 has changed to: %d", a2);
	}*/

	if (modSettings::isImprovedWeaponSwitching()) {
		switcher.updateLastWeapKeyPress(weaponIndex_a2);
	}
	//binderHelper.updateLastWeapKeyPress(x_a2);

	return pSelectWeaponForSelectionGroup(a1, weaponIndex_a2);
}



//! bool __fastcall isKeyPressed_1AE54F0(__int64 gui_a1, __int64 x_a2)
typedef bool(__fastcall* isKeyPressed)(__int64 a1, __int64 a2);
isKeyPressed pisKeyPressed = nullptr;
isKeyPressed pisKeyPressedTarget;

bool __fastcall isKeyPressedHook(__int64 ptr, __int64 btnEnum) {
	

	if (!modSettings::getIsUseDedicatedNadeKeys()) {
		return pisKeyPressed(ptr, btnEnum);
	}

	/*if (idPlayer_K::getCurrentGrenadeType() == GrenadeType::Ice) {
		idPlayer_K::setGrenadeType(GrenadeType::Frag);
	}*/

	usercmdButton userCmdBtn = (usercmdButton)btnEnum;
	switch (userCmdBtn) {

		/*case usercmdButton::BUTTON_NONE: // not checking this cause NONE is the value of the default weapon btn to resend.
			break;	*/
			// afaik BUTTON_ZOOM is not triggered even when in scop of the HAR
			//case usercmdButton::BUTTON_ZOOM:
			//	if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_ZOOM)) {
			//		logInfo("BUTTON_ZOOM pressed");
			//		/*if (g_debugIsReticleTest) {
			//			if (idCmd::getReticleMode() != UI_ReticleMode::Full) {
			//				idCmd::setReticleMode(UI_ReticleMode::Full);
			//			}
			//		}*/
			//	}
			//	
			//	break;

	//! experimenting with disabling force weap switch system when melee key (BUTTON_ATTACK2) pressed
	case usercmdButton::BUTTON_ATTACK2:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_ATTACK2)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_ATTACK2);
		}
		break;

		//! we disable our for weap switch system if a key if change weap key press 
	case usercmdButton::BUTTON_CHANGEWEAPON:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CHANGEWEAPON)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_CHANGEWEAPON);
		}
		break;
	case usercmdButton::BUTTON_WEAP_NEXT:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_NEXT)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_NEXT);
		}
		break;
	case usercmdButton::BUTTON_WEAP_PREV:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_PREV)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_PREV);
		}
		break;
	case usercmdButton::BUTTON_SHOTGUN:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_ASSAULT_RIFFLE:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_PLASMA:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_RL:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_SUPER_SHOTGUN:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_BALISTA:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_MINIGUN:
		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
			return true;
		}
		break;
	case usercmdButton::BUTTON_BFG_UNMAKER:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG_UNMAKER)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_BFG_UNMAKER);
		}
		break;
	case usercmdButton::BUTTON_WEAP_9: //! no idea what this weapon is, don't think it exists.
		break;
	case usercmdButton::BUTTON_BFG:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_BFG);
		}
		break;
	case usercmdButton::BUTTON_WALK:
		break;
	case usercmdButton::BUTTON_DASH:
		break;	
		//! use equipment throws frag nade
	case usercmdButton::BUTTON_USE_EQUIPMENT:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) {
			EquipmentManager::useEquipmentItem(equipmentType_t::EQUIPMENT_FRAG_GRENADE);			
			return false;
		}
		break;
		//! switch equipment throws ice nade
	case usercmdButton::BUTTON_SWITCH_EQUIPMENT:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_SWITCH_EQUIPMENT)) {
			EquipmentManager::useEquipmentItem(equipmentType_t::EQUIPMENT_ICE_BOMB);
			return false;
		}	
		break;
	case usercmdButton::BUTTON_QUICK_3:
		break;
	case usercmdButton::BUTTON_INVENTORY:
		break;
	case usercmdButton::BUTTON_ACTIVATE_ABILITY:
		break;
	case usercmdButton::BUTTON_CRUCIBLE_HAMMER:
		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CRUCIBLE_HAMMER)) {
			switcher.disableEnumResend(usercmdButton::BUTTON_CRUCIBLE_HAMMER);
		}
		break;
	case usercmdButton::BUTTON_OBJECTIVES:
		//! not doing anything here as this key is back to being objective btn
		//if ((buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_SWITCH_EQUIPMENT))) {
		//	//logInfo("BUTTON_OBJECTIVES (Ice) pressed");
		//	return true;
		//}
		//return false;

		break;
	default:
		break;
	}

	return pisKeyPressed(ptr, btnEnum);
}


//! this is a BAK of snippet relevant code of previous pisKeyPressed that used the old method of triggering the throw of grenades:
//! 
//!	case usercmdButton::BUTTON_DASH:
//break;
////! use equipment throws frag nade
//case usercmdButton::BUTTON_USE_EQUIPMENT:
//	if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) {
//		idPlayer_K::setGrenadeType(GrenadeType::Frag);
//		//logInfo("BUTTON_USE_EQUIPMENT (Frag) pressed");
//		return true;
//	}
//
//	//else if ((buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_SWITCH_EQUIPMENT))) {
//	//	idPlayer_K::setGrenadeType(GrenadeType::Ice);
//	//	//logInfo("BUTTON_SWITCH_EQUIPMENT (Ice) pressed");
//	//	return true;
//	//}
//
//	//? putting this instead of above to fix the sound issue if user gives himself ice at the start
//	else if ((buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_SWITCH_EQUIPMENT))) {
//		//if (idInventoryCollectionManager::isIceNadeOwned()) {
//		if (idInventoryCollectionManager::getCriticalIsIceNadeOwned()) {
//			idPlayer_K::setGrenadeType(GrenadeType::Ice);
//			//logInfo("BUTTON_SWITCH_EQUIPMENT (Ice) pressed");
//			return true;
//		}
//	}
//
//
//	break;
//	//! switch equipment throws ice nade
//case usercmdButton::BUTTON_SWITCH_EQUIPMENT:
//	//! this works to make sure that nade selection will always stay on frag. 
//	//if (idPlayer_K::getSelectedGrenadeType() == GrenadeType::Ice && idInventoryCollectionManager::isFragNadeOwned()) {
//	if (idPlayer_K::getSelectedGrenadeType() == GrenadeType::Ice && idInventoryCollectionManager::getCriticalIsFragNadeOwned()) {
//		return true;
//	}
//
//	//? this doesn't work to ensure selection will always stay on frag
//	/*if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) {
//		idPlayer_K::setGrenadeType(GrenadeType::Frag);
//		logInfo("BUTTON_USE_EQUIPMENT pressed");
//		return true;
//	}*/
//
//	//! this false return works to make sure spamming the ice nade key will not switch back sometimes to frag type. This is the mode where pressing a nade btn will switch to its type if it available.
//	//return false; 
//
//	break;
//case usercmdButton::BUTTON_QUICK_3:



//! __int64 __fastcall BindsStrSet_35CEC0(__int64 *gui_a1, unsigned __int8 *x_a2)
typedef __int64(__fastcall* BindsStrSet)(__int64* a1, unsigned char* a2);
BindsStrSet pBindsStrSet = nullptr;
BindsStrSet pBindsStrSetTarget;

__int64 __fastcall BindsStrSetHook(__int64* a1, unsigned char* a2) {

	if (!modSettings::getIsUseDedicatedNadeKeys()) {
		return pBindsStrSet(a1, a2);
	}
	
	if (PlayerStateChecker::isInMenus()) {
		bindLabelChanger.overwriteDynamicBindLabels(a2, lang.getLocalizedBindStringData());
	}
	return pBindsStrSet(a1, a2);
}


//! char __fastcall idHUD_Reticle::SetActiveReticle_1576DD0(__int64 idHUD_Reticle_a1, unsigned int eticleIndex_a2,__int64 idDeclWeaponReticle_a3,unsigned __int8 a4) This is triggered many times per second and even if the hud crosshair is disabled in the game options.
typedef void(__fastcall* idHUD_Reticle_SetActiveReticle)(idHUD_Reticle* a1, unsigned int a2, idDeclWeaponReticle* a3, unsigned __int8 a4);
idHUD_Reticle_SetActiveReticle pidHUD_Reticle_SetActiveReticle = nullptr;
idHUD_Reticle_SetActiveReticle pidHUD_Reticle_SetActiveReticleTarget;


void __fastcall idHUD_Reticle_SetActiveReticleHook(idHUD_Reticle* idHUD_Reticle_a1, unsigned int reticleIndex_a2,  idDeclWeaponReticle* idDeclWeaponReticle_a3, unsigned __int8 a4) {	
	
	
	//! 29/4/24: still using this system from previous mod after all as our new customizedWeapon is extremely frustrating to use as some declweapons arbitrarily do not respect the reticule set rule and vary from weapon to weapon so...funk it!
	//return pidHUD_Reticle_SetActiveReticle(idHUD_Reticle_a1, reticleIndex_a2, idDeclWeaponReticle_a3, a4);
	//logInfo("idHUD_Reticle_SetActiveReticleHook Triggered");

	PlayerStateChecker::updateLastReticleRefresh(); 		

	idSWFWidget_Hud_Reticle* idSWFWidget_Hud_Reticle_v8 = 0i64;
	//unsigned int activeReticleStyle = *(unsigned int*)(idHUD_Reticle_a1 + 0x330);
	unsigned int activeReticleStyle = (unsigned int)idHUD_Reticle_a1->activeReticleStyle;

	//logInfo("idHUD_Reticle_SetActiveReticleHook: debug 3");

	
	if (reticleIndex_a2 > idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_MAX) {
		idSWFWidget_Hud_Reticle_v8 = 0i64;
	}
	else {
		idSWFWidget_Hud_Reticle_v8 = idHUD_Reticle_a1->reticles_ptr[reticleIndex_a2]; //! this is fine.	

	}

	//? !!!!!!!!! this will not work if user has chosen no crosshair in the game menu !!!!!!!!!
	//CustomCrosshairManager::acquireWeaponCoolDownStatus(idSWFWidget_Hud_Reticle_v8, idDeclWeaponReticle_a3);

	//logInfo("debug:  idSWFWidget_Hud_Reticle_v8 is %p ", idSWFWidget_Hud_Reticle_v8);
	//? idSWFWidget_Hud_Reticle_v8 will be null when the ingame reticle mode is set to None so the rest of this code will not trigger, obviously
	if (idSWFWidget_Hud_Reticle_v8) {		

		idSWFSpriteInstance* idSWFSpriteInstance_v17 = idSWFWidgetManager::getBoundSprite(idSWFWidget_Hud_Reticle_v8);

		//logInfo("idHUD_Reticle_SetActiveReticleHook: debug 5");

		//? this is the mistake we made we got the wrong spriteInstance and as a result, the scale was inconsistent, we were using this....
		//idSWFSpriteInstance* idSWFSpriteInstance_v17 = idSWFWidget_Hud_Reticle_v8->reticleSprite;
		//? ...instead of this: 
		//__int64 idSWFSpriteInstance_v17 = *(__int64*)(idSWFWidget_Hud_Reticle_v8 + 0x18);
		
		//! looks this work now:
		idSWFSpriteInstanceManager::setHitMarkerState((idHUD_Reticle*)idHUD_Reticle_a1, modSettings::getIsDisableHitMarker());

		//logInfo("idHUD_Reticle_SetActiveReticleHook: debug 6");


		//! this is how we manage to change the scale of the crosshair even when it's already displayed
		if (idDeclWeaponReticle_a3 && idSWFSpriteInstance_v17) {		


			//! from logs, even when the dot crosshair is set in the game menu, idDeclWeaponReticle_a3->style will have the value of the current weapon reticle style so we can use that to set crosshair color then?
			
			//logInfo("debug:  idHUD_Reticle_a1->activeReticleDecl: %p and idDeclWeaponReticle_a3: %p activeReticleStyle: %u reticleIndex_a2: %u", idHUD_Reticle_a1->activeReticleDecl, idDeclWeaponReticle_a3, activeReticleStyle, reticleIndex_a2);
			
			//! if the reticle scale needs to be changed cause user wants it changed, we trigger the sprite reload function
			if (ReticleScaleManager::updateScale(idDeclWeaponReticle_a3)) {
				idSWFSpriteInstanceManager::updateScale(idSWFSpriteInstance_v17, idDeclWeaponReticle_a3->reticleModelScale);
			}

			//! if game dot:
			if (activeReticleStyle == idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_DOT ) {

				if (modSettings::getIsUseImguiDotCrosshair()) {
					idSWFWidget_Hud_Reticle_v8->reticleSprite->namedColorId = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE;
				}
				else {					
					idSWFWidget_Hud_Reticle_v8->reticleSprite->namedColorId = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
				}				
				
				//? doesn't work to force disable dot:
				//idHUD_Reticle_a1->activeReticleStyle = idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_NONE;
					
				//? doesn't work to force disable dot:
				//reticleIndex_a2 = idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_NONE;

				//idDeclWeaponReticleManager::debugPrintCurrentDeclWeaponReticle(idDeclWeaponReticle_a3);
				//! this used to crash because of bad padding in our generated classes
				/*ReticleColorManager::updateDotColorV3(idSWFWidget_Hud_Reticle_v8, idDeclWeaponReticle_a3, idSWFSpriteInstance_v17);*/			

			}
		}
	}


	return pidHUD_Reticle_SetActiveReticle(idHUD_Reticle_a1, reticleIndex_a2, idDeclWeaponReticle_a3, a4);
}






//! this will hopefully let us change the color of ui elements at will
//! __int64 __fastcall convertIdDeclUIColorToidColor_Mb_4D5630(__int64 idDeclUIColor_a1, __int64 idColor_a2, int y_a3)
typedef idColor* (__fastcall* convertIdDeclUIColorToidColor)(__int64 idDeclUIColor_a1, idColor* idColor_a2, int colorId_a3);
convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColor = nullptr;
convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColorTarget;

idColor* __fastcall convertIdDeclUIColorToidColorHook(__int64 idDeclUIColor_a1, idColor* idColorPtr_a2, int colorId_a3) { //! there is a bak of the old version of this hook in debug.h
	
	//? we get this ptr with our own method as it can change when in main menu. but it's ok to use it for GameHudColorsManager as it only uses it when the player is in game
	//idDeclUIColorManager::updateCurrentIdDeclUIColorFromHook((idDeclUIColor*)idDeclUIColor_a1);

	//! by acequiring this address we always know where the color of a specifi elelment on the hud is. this is useful when user changes profile cause idDeclUIColor_a1 will change in that case and there are many color profiles.
	GameHudColorsManager::acquireIdDeclUIColorAddr(idDeclUIColor_a1);

	if (colorId_a3 == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT) {
		return pconvertIdDeclUIColorToidColor(idDeclUIColor_a1, idColorPtr_a2, colorId_a3);
	}

	//? would still need a check for the color above old make namedColor and SWF_CUSTOM_NAMED_COLOR_DEFAULT

	//! here in we check if colorId_a3> is not default  and if it's in bound:
	if ((colorId_a3 > swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT) && (colorId_a3 <= swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE)) {

		//logInfo("convertIdDeclUIColorToidColorHook: colorId_a3: %d", colorId_a3);

		*idColorPtr_a2 = *(idColor*)GameHudColorsManager::getCustomIdColor(colorId_a3);		
		return idColorPtr_a2;

	}

	return pconvertIdDeclUIColorToidColor(idDeclUIColor_a1, idColorPtr_a2, colorId_a3);
}


//! sig: 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 8B F2 48 8B F9
typedef void(__fastcall* setSpriteInstanceColor)(idSWFSpriteInstance* idSWFSpriteInstance_a1, unsigned int namedColorId_a2);
setSpriteInstanceColor psetSpriteInstanceColor = nullptr;
setSpriteInstanceColor psetSpriteInstanceColorTarget = nullptr;

void __fastcall setSpriteInstanceColorHook(idSWFSpriteInstance* idSWFSpriteInstance_a1, unsigned int namedColorId_a2) {
	

	//! this is used to get the addresses of all the sprites instances we are interested in. So at least, the frag icon instances so this should be UNcommented all the time. As those instances addresses are acquired when a level load or when the idCmd::reapplySwfColorsCmd is called.
	GameHudColorsManager::acquireMonitoredSpriteInstanceAddr(idSWFSpriteInstance_a1);

	
	//! 11/9/24 will log info about each sprite instance BUT will only do it once for each sprite instance ptr.	
	//GameHudColorsManager::debugLogUniqueSpriteInstance(idSWFSpriteInstance_a1);

	
	namedColorId_a2 = GameHudColorsManager::getColor(idSWFSpriteInstance_a1, namedColorId_a2);


	
	//! i used this to identify specific hud elements:
	//GameHudColorsManager::debugLogInstancesDefaultNamesColors(idSWFSpriteInstance_a1, namedColorId_a2);	

	//! this is good to test colors on arrow, bp, rad suit:
	//namedColorId_a2 = GameHudColorsManager::testColors(idSWFSpriteInstance_a1, namedColorId_a2);

	//! use this to refine search of hud elements based on their color:
	/*if (GameHudColorsManager::isSpriteColorIdBeingDebugged(namedColorId_a2)) {
		GameHudColorsManager::addSpriteInstanceAddrToDebugVec(idSWFSpriteInstance_a1);
	}*/

	//! using this just to identify clearly each element we have found previously and for which we have gotten an id
	/*if (GameHudColorsManager::isSpriteIdBeingDebugged(idSWFSpriteInstance_a1)) {
		GameHudColorsManager::addSpriteInstanceAddrToDebugVec(idSWFSpriteInstance_a1);
	}*/

	//! this is what you use when you want to find a specific element on the hud when debugging or investigating a specific sprite instance like the weapon hud big bar, so you can figure out its width and know how big our custom ammo text can be
	/*if (PlayerStateChecker::isPlaying()) {
		GameHudColorsManager::addSpriteInstanceAddrToDebugVec(idSWFSpriteInstance_a1);
	}*/


	//! we had an issue with this before when we forgot to add the isPlaying check which cause issue when trying to go back to default profile color.
	//if (PlayerStateChecker::isPlaying() && GameHudColorsManager::isSpriteInstanceOveridden(idSWFSpriteInstance_a1)) {
	//	return; //! This is what fixed our issue with for ex the rad suit not returning to original color if overide is disabled once the rad suit is empty.
	//	//!? this below is actually not a good idea and will create frustration:
	//	//namedColorId_a2 = SWF_NAMED_COLOR_INVALID; //
	//}

	//! this works keep that in mind:
	/*if (GameHudColorsManager::isEquipmentArrowSpriteInstance(idSWFSpriteInstance_a1)) {
		logInfo("setSpriteInstanceColorHook idSWFSpriteInstance_a1: %p", (void*)idSWFSpriteInstance_a1);
		GameHudColorsManager::setEquipmentArrowFlag(true);
	}
	else {
		GameHudColorsManager::setEquipmentArrowFlag(false);
	}*/

	//GameHudColorsManager::overideEquipmentArrowNamedColor(idSWFSpriteInstance_a1);


	//! ids which modify the hud: (if it doesn't look log all the ids again and look the ones above or below the value
	/*
		INFO| print: name: left, fullPathHash: -108148670, visIndex: 17, health smth


		*/

		//! this works !:
		//int hashId = *(int*)(idSWFSpriteInstance_a1 + 0x20);		
		////if (hashId == -904400581) { // equipment arrow : no change.....
		//if (hashId == -1637630621) { // equipment arrow
		//	namedColorId_a2 = g_namedColorBlue;
		//	logInfo("setSpriteInstanceColorHook found equipment arrow hash id");
		//	return psetSpriteInstanceColor(idSWFSpriteInstance_a1, namedColorId_a2);

		//}

		//if (PlayerStateChecker::isPlaying()) {
		//	//? add the visIndex to the log we never know
		//	if (!MemHelper::isBadReadPtr((void*)strAddr) && !MemHelper::isBadReadPtr((void*)(idSWFSpriteInstance_a1 + 0x20))) {
		//		unsigned int hashId = *(unsigned int*)(idSWFSpriteInstance_a1 + 0x20);
		//		int visIndex = *(int*)(idSWFSpriteInstance_a1 + 0x8);
		//		logInfo("setSpriteInstanceColorHook name: %s fullPathHash: %u visIndex: %d namedColorId_a2: %u", (const char*)strAddr, hashId, visIndex, namedColorId_a2);
		//	}

		//}		

	return psetSpriteInstanceColor(idSWFSpriteInstance_a1, namedColorId_a2);
}








//! this func, 4CAD00 is triggered 4 times per image rendered and will call hud_string_Print_Smth_4CB340 twice each call in theory we can print 2 strings each call or 1 string and many icons.
//! However i managed to make it render 8 strings in one call with no apparent perf loss but let's be conservative. 
//! So far it's working great to show text and strings with not apparent perf loss. Also it fades in and out automatically with menus which is nice. it needs debug_hud_string cmd to be active for it to work though.
typedef __int64(__fastcall* printOutlinedStringMB_func)(
	__int64 idRenderModelGui_a1PtrToPtr,
	int a2,
	__int64 a3,
	int a4,
	__int64 a5,
	char* a6,
	int a7,
	int a8
	);

//! all our previous test with this hook is 'backed' in dllmainDebug.h

printOutlinedStringMB_func pPrintOutlinedStringMB = nullptr;
printOutlinedStringMB_func pPrintOutlinedStringMB_target;

__int64 __fastcall printOutlinedStringMB_hook(
	__int64 idRenderModelGui_a1PtrToPtr,
	int a2,
	__int64 a3,
	int a4,
	__int64 a5,
	char* a6,
	int a7,
	int a8
) {

	

	
	idRenderModelGui* gui = (idRenderModelGui * )*(__int64*)idRenderModelGui_a1PtrToPtr;

	auto iceNadeIconData = CustomIceNadeIconManager::getData();
	iceNadeIconData.updateMaterials(); //? this could be the answer to the crashing when loading levels....fingers crossed...Might be a bit slower than before cause of matr fetching (?)...Update no more crash indeed so far.

	if (iceNadeIconData.isRenderingAllowed) {
		idRenderModelGuiManager::drawIceIcon(gui, iceNadeIconData);
	}

	
	return hudString::textForidCmd.size();


	//! this did not help to prevent the crash:
	/*if (!idPlayer_K::isAbilityIndicatorHudActive()) {
		logWarn("printOutlinedStringMB_hook player isAbilityIndicatorHudActive not active returning...");
		return 0;
	}*/

	//! this did not help to prevent the crash:
	//if (!a6) {
	//	//! trying to mimic what happens in the original func, hopeful that will help prevent the crash
	//	logWarn("printOutlinedStringMB_hook player !a6 => returning...");
	//	return 0;
	//}

	//logInfo("printOutlinedStringMB_hook: debug entering");

	//! disabling this for now for debugging
	//return hudString::textForidCmd.size(); //! 


	//? setting this just to find where the crash is:
	//return pPrintOutlinedStringMB(idRenderModelGui_a1PtrToPtr, a2, a3, a4, a5, a6, a7, a8);


	//logInfo("printOutlinedStringMB_hook debug: PlayerStateChecker::isPlaying(): %d, idInventoryCollectionManager::isItemOwned(ItemID::IceBomb): %d idPlayer_K::isPlayerDemon(): %d  idPlayer_K::isInCinematic: %d ", PlayerStateChecker::isPlaying(), idInventoryCollectionManager::isItemOwned(ItemID::IceBomb), idPlayer_K::isPlayerDemon(), idPlayer_K::isInCinematic());

	//! trying this to see if it could help with the crash when loading level
	//if (PlayerStateChecker::isGameLoading()) {
	////! this doesn't seem to help to prevent loading crash in campaign start save.
	////if (PlayerStateChecker::isGameLoading()) {
	//	logWarn("printOutlinedStringMB_hook player Game is Loading not drawing");

	//	logInfo("printOutlinedStringMB_hook: debug exiting");
	//	return hudString::textForidCmd.size(); //! 
	//}


	//? attempting this to fix crash, problem is this does the same as !PlayerStateChecker::isPlaying() so it's still not fixing the random crash we have when loading horde mode level. Update returning original function now, may be this will make things better(?)


	//? COmmenting this as i want to have the consistent crash again to check if the crash itself is related to text drawing
	//if (!LoadingScreenManager::isReadyToRenderIceIcon()) {
	//	//return 0;		
	//	return pPrintOutlinedStringMB(idRenderModelGui_a1PtrToPtr, a2, a3, a4, a5, a6, a7, a8);
	//}


	//? After all the tests and loging this seemed to prevent crash but i had one during a horde mode load, attempting the LoadingScreenManager method instead even if i'm not optimistic.
	//if (!PlayerStateChecker::isPlaying()) {		
	//	//logWarn("printOutlinedStringMB_hook player is not playing => not drawing");
	//	return 0; //! 
	//}


	//! trying to get rid of this cause the icon flickers...this deosn't seem related
	//if (!idRenderModelGuiManager::isRenderDrawCallAllowed()) {
	//	//logInfo("debug: printOutlinedStringMB_hook: flag not raised, returning");
	//	return 1; //! this is to make sure we only render the icon once per frame
	//}

	/*if (MemHelper::isBadReadPtr((void*)idRenderModelGui_a1PtrToPtr)) {
		logErr("printOutlinedStringMB_hook: idRenderModelGui_a1PtrToPtr is badptr...WTF??!!");
		return 1;
	}*/


	//! keep this:
//if (MaterialDebug::isMaterialDebugMode()) {
//	//logWarn("printOutlinedStringMB_hookisMaterialDebugMode is active");
//	idRenderModelGuiManager::debugDrawMaterialLibMatr(gui, MaterialDebug::getTestMtr(), MaterialDebug::getTestMaterialName());
//}

	//idRenderModelGuiManager::incrementRenderDrawCallCount(); // not using this atm
	//logInfo("debug: printOutlinedStringMB_hook:... just draw, setting lowering flag");

	//logInfo("printOutlinedStringMB_hook: debug exiting");

	//? dont forget we have removed comments that could be useful !!!!
//if (!idInventoryCollectionManager::isItemOwned(ItemID::IceBomb)) {
//	//logWarn("printOutlinedStringMB_hook ice bomb not owned not drawing");

//	//logInfo("printOutlinedStringMB_hook: debug exiting");
//	return hudString::textForidCmd.size(); //! not rendering ice icon if not owned. the value returned here is arbitrary.
//}

//if (idPlayer_K::isPlayerDemon() || idPlayer_K::isInCinematic()) {
//	//logWarn("printOutlinedStringMB_hook player is demon or in cinematic: not drawing");

//	//logInfo("printOutlinedStringMB_hook: debug exiting");
//	return hudString::textForidCmd.size(); //! don't want the ice nade to show when playing as demon
//}


//! this doesn't work:
//if (idPlayer_K::getCurrentActiveReticleInt() == -1) {
//	return 1; //? attempting to detect cinematic but that is not going to work i think.....
//}

	// not calling orignal func as we don't want to draw the debug string
	//return pPrintOutlinedStringMB(idRenderModelGui_a1PtrToPtr, a2, a3, a4, a5, a6, a7, a8);
}



//! __int64 idLib::Printf_35F240(const char *a1, ...)
typedef void(__cdecl* IdLib_Printf)(const char* a1, ...);
IdLib_Printf  pIdLib_Printf = nullptr;
IdLib_Printf  pIdLib_PrintfTarget;


void __cdecl IdLib_PrintfHook(const char* format, ...) {

	va_list args;
	va_start(args, format);

	char buffer[2048];
	int result = vsnprintf(buffer, sizeof(buffer), format, args); // Store the result of vsnprintf

	va_end(args);  // Call va_end after using va_list

	globalVariableString = std::string(buffer);
	logInfo("id console: %s", globalVariableString.c_str());


	return pIdLib_Printf(buffer);
	// Call the original function
	//return result; // Return the result of vsnprintf
}



//! hoping to make the perspective hud work again as atm elements of the hud interact with world geometry which is just wrong.
//! __int64 __fastcall idHud_PerspectiveSmth_1549D80(__int64 idHud_X_a1)
typedef __int64(__fastcall* idHud_PerspectiveSmth_t)(idHUDElement* idHUDElementPtr_a1);
idHud_PerspectiveSmth_t p_idHud_PerspectiveSmth_t = nullptr;
idHud_PerspectiveSmth_t p_idHud_PerspectiveSmth_t_Target = nullptr;

__int64 __fastcall idHud_PerspectiveSmth_t_Hook(idHUDElement* idHUDElementPtr_a1) {
	
	static void* lastDebugHudRenderModel = nullptr;

	if (idHUDElementPtr_a1) {
		idResource* resPtr = (idResource*)idHUDElementPtr_a1->decl;
		if (resPtr) {
			std::string idHUDElementNameStr = resPtr->name.str;
			//logInfo("idHud_PerspectiveSmth_t_Hook: found idHUDElement with name: %s", resPtr->name.str);

			idUIElement* idUIElementPtr = (idUIElement*)idHUDElementPtr_a1;

			/*if (idHUDElementNameStr == "debug") {

				lastDebugHudRenderModel = idUIElementPtr->swfObject.renderModel;
				logInfo("debug hud: idUIElementPtr: %p idUIElementPtr->swfObject.renderModel: %p", idUIElementPtr, lastDebugHudRenderModel);
			}*/


			if (idHUDElementNameStr == "hud_weaponinfo"){

				

				//idDeclHUDElement* declHudElemPtr = (idDeclHUDElement*)idHUDElementPtr_a1->decl;

				//declHudElemPtr->swfInfo.depthTest = true; // forcing to true....

				//logInfo("hud_weaponinfo : %p  decl: %p declHudElemPtr->swfInfo.depthTest: %d", idUIElementPtr, declHudElemPtr, declHudElemPtr->swfInfo.depthTest);


				//idDeclHUDElement* declHudElemPtr = (idDeclHUDElement*)idHUDElementPtr_a1->decl;

				
				//logInfo("idUIElementPtr for hud_weaponinfo: %p", idUIElementPtr);

				//? it is null :(
			/*	if (!idUIElementPtr->viewOrigin) {
					logWarn("idUIElementPtr->viewOrigin is nullptr...");
				}
				else {
					logInfo("idUIElementPtr->viewOrigin->x: %.3f", idUIElementPtr->viewOrigin->x);
					logInfo("idUIElementPtr->viewOrigin->y: %.3f", idUIElementPtr->viewOrigin->y);
					logInfo("idUIElementPtr->viewOrigin->z: %.3f", idUIElementPtr->viewOrigin->z);
				}*/
				
				
				//? if used weaponinfo wond't be rendered anymore you'll have to reload checkpoint
				//idUIElementPtr->swfObject.renderModel = nullptr;


				/*logInfo("custom model for hud_weaponinfo: %p", idUIElementPtr->swfObject.customModel);
				logInfo("guiModel for hud_weaponinfo: %p", idUIElementPtr->swfObject.guiModel);
				logInfo("renderModel for hud_weaponinfo: %p", idUIElementPtr->swfObject.renderModel);*/


				//? doesn't help
				//declHudElemPtr->swfInfo.perspectiveGUI = hudElementPerspective_t::PERSPECTIVE_NONE;

				//logInfo("perspectiveGUI for hud_weaponinfo: %d", (int)declHudElemPtr->swfInfo.perspectiveGUI);

				//? doesn't help
				//declHudElemPtr->swfInfo.customGUIModel = false;

				//? doesn't help
				//*(_QWORD*)(idHUDElementPtr_a1 + 0x18) = 0; //! making the custommodel null.

				//? doesn't help
				/*__int64 idSWF_v8 = *(_QWORD*)((char*)idHUDElementPtr_a1 + 0x10);
				if (idSWF_v8)
					*(float*)(idSWF_v8 + 0x38) = 0.5f;*/

			}
		}
	}

	return p_idHud_PerspectiveSmth_t(idHUDElementPtr_a1);
}



//! This let us know what key/button is pressed (even for controller but not the analog stick/triggers) and i suppose we could use it to send key press as well as we do in new collossus.
typedef __int64(__fastcall* idUsercmdGenLocalSendBtnPressMB_t)(__int64 idUsercmdGenLocal_a1, unsigned int devicneNumMB_a2, int keyNum_t_a3, unsigned __int8 isDown_a4);
idUsercmdGenLocalSendBtnPressMB_t p_idUsercmdGenLocalSendBtnPressMB_t = nullptr;
idUsercmdGenLocalSendBtnPressMB_t p_idUsercmdGenLocalSendBtnPressMB_t_Target = nullptr;

__int64 __fastcall idUsercmdGenLocalSendBtnPressMB_Hook(__int64 idUsercmdGenLocal_a1, unsigned int devicneNumMB_a2, int keyNum_t_a3, unsigned __int8 isDown_a4) {

	static int lastKeyNum_t_a3 = -1;
	static unsigned __int8 lastIsDown_a4 = 0;


	//todo this works, not using it atm but we might use it in the incoming rewrite of the mod
	/*if (keyNum_t_a3 != lastKeyNum_t_a3) {
		logInfo("keyNum_t_a3 has changed to: 0x%X (isDown_a4: %d)", keyNum_t_a3, isDown_a4);
		lastKeyNum_t_a3 = keyNum_t_a3;
	}

	if (isDown_a4 != lastIsDown_a4) {
		logInfo("isDown_a4 has changed to: %d",  isDown_a4);
		lastIsDown_a4 = isDown_a4;
	}*/
	
	return p_idUsercmdGenLocalSendBtnPressMB_t(idUsercmdGenLocal_a1, devicneNumMB_a2, keyNum_t_a3, isDown_a4);
}


//? i'm getting crash here, not sure if it's the hook itself or the newly modify draw function yet....
//! hooking this to hopefully render custom menus and may be custom hub not sure yet.
typedef __int64(__fastcall* perfMetrics_DrawGraphs_t)(_QWORD* a1, idRenderModelGui* gui_a2);


perfMetrics_DrawGraphs_t p_perfMetrics_DrawGraphs = nullptr;
perfMetrics_DrawGraphs_t p_perfMetrics_DrawGraphs_Target = nullptr;


__int64 __fastcall perfMetrics_DrawGraphs_Hook(_QWORD* a1, idRenderModelGui* gui_a2) {


	//swfRect_t dbgRect(50.0f, 50.0f, 100.0f, 100.0f);
	//idRenderModelGuiManager::drawSwfRectMaterial_V2(gui_a2, dbgRect, MaterialLib::getMaterialPtr("_white", 0), colorGreen);
	
	return p_perfMetrics_DrawGraphs(a1, gui_a2);
}


//! we used to hook this a loooong time ago and we had issues but using it again now, no issues at all and it doesn't crash when loading/unloading level. may be it's because the was get get the material before render, we'll have to look into that...
typedef void(__fastcall* idDebugHUDLocal_Render_t)(__int64 idDebugHUDLocal_a1, idRenderModelGui* gui_a2);
idDebugHUDLocal_Render_t p_Render_t = nullptr;
idDebugHUDLocal_Render_t p_Render_t_Target = nullptr;


void __fastcall idDebugHUDLocal_Render_Hook(__int64 idDebugHUDLocal_a1, idRenderModelGui* gui_a2) {
	
	/*swfRect_t dbgRect(50.0f, 50.0f, 100.0f, 100.0f);
	idMaterial2* material = MaterialLib::getMaterialPtr("_white", 0);
	idRenderModelGuiManager::drawSwfRectMaterial_V2(gui_a2, dbgRect, colorGreen, material);*/

	//std::string testStr = "Hello";
	//std::string testStr = "HelioA 115 191";
	//swfRect_t dbgRect(50.0f, 50.0f, 500.0f, 60.0f);
	//idRenderModelGuiManager::drawStringForRectHeigth_V2(gui_a2, dbgRect, testStr, idFontHash::eurostileconreg, colorWhite, false, textAlignment::left, true);


	idRenderModelGuiManager::debugDrawAllFonts(gui_a2);


	p_Render_t(idDebugHUDLocal_a1, gui_a2);
}











//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//? XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

























































//! __int64 __fastcall hud_drawPerspectiveSmth_1549A70(__int64 idHUDElementPtr_a1, __int64 a2, __int64 a3, __int64 a4)
//typedef __int64(__fastcall* hud_drawPerspectiveSmth_t)(idHUDElement* idHUDElementPtr_a1, __int64 a2, __int64 a3, __int64 a4);
//hud_drawPerspectiveSmth_t p_hud_drawPerspectiveSmth_t = nullptr;
//hud_drawPerspectiveSmth_t p_hud_drawPerspectiveSmth_t_Target = nullptr;
//
//__int64 __fastcall hud_drawPerspectiveSmth_t_Hook(idHUDElement* idHUDElementPtr_a1, __int64 a2, __int64 a3, __int64 a4) {
//
//
//
//
//	if (idHUDElementPtr_a1) {
//		idResource* resPtr = (idResource*)idHUDElementPtr_a1->decl;
//		if (resPtr) {
//			std::string idHUDElementNameStr = resPtr->name.str;
//			//logInfo("idHud_PerspectiveSmth_t_Hook: found idHUDElement with name: %s", resPtr->name.str);
//
//			/*idUIElement* idUIElementPtr = (idUIElement*)idHUDElementPtr_a1;			
//
//
//			__int64 idGUIComponentAddr = 0;
//
//			if (idGUIComponentPTR_a3) {
//				idGUIComponentAddr = *(__int64*)idGUIComponentPTR_a3;
//			}
//
//
//			logInfo("hud_drawPerspectiveSmth_1549A70: idHUDElementNameStr: %s for idHUDElementPtr_a1 : %p  a2: %p  idGUIComponentPTR_a3 is %p idGUIComponentAddr: %p", idHUDElementNameStr.c_str(), idUIElementPtr, (void*)a2, (void*)idGUIComponentPTR_a3, (void*)idGUIComponentAddr);*/
//
//
//
//			if (idHUDElementNameStr == "hud_weaponinfo") {
//				
//				idUIElement* idUIElementPtr = (idUIElement*)idHUDElementPtr_a1;
//
//				float f0 = *(float*)(a3);
//				float f1 = *(float*)(a3 + 4);
//				float f2 = *(float*)(a3 + 8);
//
//				logInfo("hud_drawPerspectiveSmth_1549A70: for hud_weaponinfo : %p  a3 is %p f0: %.3f f1: %.3f f2: %.3f", idUIElementPtr, (void*)a3, f0, f1, f2);
//
//				logInfo("hud_drawPerspectiveSmth_1549A70: forcing floats... ");
//			/*	*(float*)(a3 + 4) = 100.0f;
//				*(float*)(a3 + 8) = -1.0f;*/
//
//			}
//		}
//	}
//
//
//
//
//	
//	return p_hud_drawPerspectiveSmth_t(idHUDElementPtr_a1, a2, a3, a4);
//}




//? update 15/5/24 not using it anymore as we have a new way to handle dedicated nade keys so we don't need to check for owned items in the hook but i'll keep cause we never know.....
//! this is a func which is triggered all the time when in game and which could be a good candidate to get the current inventory. idInventoryCollection_Smth_1CFBB90(__int64 idInventoryCollection_a1, __int64 a2)
//typedef __int64(__fastcall* idInventoryCollection_Smth_t)(__int64 idInventoryCollection_a1, __int64 a2);
//idInventoryCollection_Smth_t p_idInventoryCollection_Smth = nullptr;
//idInventoryCollection_Smth_t p_idInventoryCollection_Smth_Target = nullptr;
//
//__int64 __fastcall idInventoryCollection_Smth_Hook(__int64 idInventoryCollection_a1, __int64 a2) {
//
//	static auto lastCallTime = std::chrono::steady_clock::now();
//
//
//	auto currentTime = std::chrono::steady_clock::now();
//	if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastCallTime).count() >= idInventoryCollectionManager::INVENTORY_UPDATE_INTERVAL_MS) {
//		idInventoryCollectionManager::updateOwnedItemsForHooks(idInventoryCollection_a1);
//
//		lastCallTime = currentTime;	
//	}
//	return p_idInventoryCollection_Smth(idInventoryCollection_a1, a2);
//}





//! checking if this is triggered only when hud should be rendered
//! char __fastcall idHUD_Reticle_UpdateWeaponInfo_Smth__1576A70(__int64 idHUD_Reticle_a1, _QWORD *a2)
//typedef char(__fastcall* idHUD_Reticle_UpdateWeaponInfo_Smth_t)(__int64 idHUD_Reticle_a1, _QWORD* a2);
//idHUD_Reticle_UpdateWeaponInfo_Smth_t p_idHUD_Reticle_UpdateWeaponInfo_Smth_t = nullptr;
//idHUD_Reticle_UpdateWeaponInfo_Smth_t p_idHUD_Reticle_UpdateWeaponInfo_Smth_t_Target = nullptr;
//
//char __fastcall idHUD_Reticle_UpdateWeaponInfo_Smth_Hook(__int64 idHUD_Reticle_a1, _QWORD* a2) {
//
//	//idPlayer_K::LastSlayerReticleUpdateTimeStampMs = EpochMillis();
//
//
//	return p_idHUD_Reticle_UpdateWeaponInfo_Smth_t(idHUD_Reticle_a1, a2);
//}


//! this is used mainly as a log func atm so not really that useful for release...
//! __int64 __fastcall idHands_handleEvents_21B7FC0(__int64 idHands_a1, __int64 struct_a2, idEventDef_K *a3, __int64 relatedToEventArgs_a4)
//typedef __int64(__fastcall* idHands_handleEvents_t)(__int64 idHands_a1, __int64 struct_a2, idEventDef* a3, __int64 relatedToEventArgs_a4);
//idHands_handleEvents_t p_idHands_handleEvents_t = nullptr;
//idHands_handleEvents_t p_idHands_handleEvents_t_Target = nullptr;
//
//__int64 __fastcall idHands_handleEvents_t_Hook(__int64 idHands_a1, __int64 struct_a2, idEventDef* idEventDef_a3, __int64 relatedToEventArgs_a4) {
//
//	static int lastIdEventNum = -1;
//
//	
//
//	//! commenting for now to see if we can get ALL the events from somehere else:
//	/*if (idEventDef_a3 && relatedToEventArgs_a4) {
//		if (idEventDef_a3->eventnum != lastIdEventNum) {
//			const char* eventNameCstr = idEventManager::GetEventNameForNum(idEventDef_a3->eventnum);
//			if (eventNameCstr) {
//				logWarn("idHands_handleEvents_t_Hook: eventnum has changed to: %s 0x%X THIS DOESNT LIST ALL EVENTS BTW", eventNameCstr, idEventDef_a3->eventnum);
//			}
//			else {
//				logWarn("idHands_handleEvents_t_Hook: eventnum has changed BUT COULD NOT FIND EVENT NAME FOR: 0x%X THIS DOESNT LIST ALL EVENTS BTW", idEventDef_a3->eventnum);
//			}			
//			lastIdEventNum = idEventDef_a3->eventnum;
//		}
//	}*/
//
//	return p_idHands_handleEvents_t(idHands_a1, struct_a2, idEventDef_a3, relatedToEventArgs_a4);
//}


//! this is used mainly as a log func atm so not really that useful for release...
//! __int64 __fastcall idSyncEntity_HandleEvents_MB_21925A0(unsigned int *a1, __int64 a2, idEventDef_K *a3, __int64 a4)
//typedef __int64(__fastcall* idSyncEntity_HandleEvents_t)(unsigned int* a1, __int64 a2, idEventDef* a3, __int64 a4);
//idSyncEntity_HandleEvents_t p_idSyncEntity_HandleEvents_t = nullptr;
//idSyncEntity_HandleEvents_t p_idSyncEntity_HandleEvents_t_Target = nullptr;
//
//__int64 __fastcall idSyncEntity_HandleEvents_t_Hook(unsigned int* a1, __int64 a2, idEventDef* idEventDef_a3, __int64 a4) {
//
//	static int lastIdEventNum = -1;
//
//	/*if (idEventDef_a3) {
//		if (idEventDef_a3->eventnum != lastIdEventNum) {
//			const char* eventNameCstr = idEventManager::GetEventNameForNum(idEventDef_a3->eventnum);
//			if (eventNameCstr) {
//				logWarn("idSyncEntity_HandleEvents_t_Hook: eventnum has changed to: %s 0x%X ", eventNameCstr, idEventDef_a3->eventnum);
//			}
//			else {
//				logWarn("idSyncEntity_HandleEvents_t_Hook: eventnum has changed BUT COULD NOT FIND EVENT NAME FOR: 0x%X ", idEventDef_a3->eventnum);
//			}
//			lastIdEventNum = idEventDef_a3->eventnum;
//		}
//	}*/
//
//
//	return p_idSyncEntity_HandleEvents_t(a1, a2, idEventDef_a3, a4);
//}



// ? nope.even when the battery in hole animation starts the output is still like : md6def / objects / doomslayer_armor / doomslayer_armor_set11.md6 and no ref to battery.
//! __int64 __fastcall idAnimated_HandleEvents_20DA540(__int64 *idAnimated_a1, __int64 a2, idEventDef_K *a3, __int64 a4)
//typedef __int64(__fastcall* idAnimated_HandleEvents_t)(__int64 idAnimated_a1, __int64 a2, idEventDef* idEventDef_a3, __int64 a4);
//idAnimated_HandleEvents_t p_idAnimated_HandleEvents_t = nullptr;
//idAnimated_HandleEvents_t p_idAnimated_HandleEvents_t_Target = nullptr;
//
//__int64 __fastcall idAnimated_HandleEvents_t_Hook(__int64 idAnimated_a1, __int64 a2, idEventDef* idEventDef_a3, __int64 a4) {
//
//	static int lastIdEventNum = -1;
//	static std::string last_mD6_Dec_Name = "";
//
//	__int64 add1 = __int64(idAnimated_a1 + 0x1A68);
//	if (MemHelper::isBadReadPtr((void*)(add1))) {
//		return p_idAnimated_HandleEvents_t(idAnimated_a1, a2, idEventDef_a3, a4);
//	}
//	__int64 add1Deref = *(__int64*)add1;
//	__int64 add2 = (add1Deref + 8i64);
//	if (MemHelper::isBadReadPtr((void*)(add2))) {
//		return p_idAnimated_HandleEvents_t(idAnimated_a1, a2, idEventDef_a3, a4);
//	}
//
//	__int64 idDeclMD6_Decl_Addr = *(__int64*)add2;
//	
//
//	//__int64 idDeclMD6_Decl_Addr = *(_QWORD*)(*(_QWORD*)(idAnimated_a1 + 0x1A68) + 8i64);
//	if (!MemHelper::isBadReadPtr((void*)idDeclMD6_Decl_Addr)) {
//		std::string mD6_Dec_Name = *(const char**)(idDeclMD6_Decl_Addr + 8);
//		if (mD6_Dec_Name != last_mD6_Dec_Name) {
//			logInfo("idAnimated_HandleEvents_t_Hook: mD6_Dec_Name has changed to: %s  decl addr: %p", mD6_Dec_Name.c_str(), (void*)idDeclMD6_Decl_Addr);
//			last_mD6_Dec_Name = mD6_Dec_Name;
//		}
//
//	}
//
//	
//
//	/*if (idEventDef_a3) {
//		if (idEventDef_a3->eventnum != lastIdEventNum) {
//			const char* eventNameCstr = idEventManager::GetEventNameForNum(idEventDef_a3->eventnum);
//			if (eventNameCstr) {
//				logWarn("idAnimated_HandleEvents_t_Hook: eventnum has changed to: %s 0x%X ", eventNameCstr, idEventDef_a3->eventnum);
//			}
//			else {
//				logWarn("idAnimated_HandleEvents_t_Hook: eventnum has changed BUT COULD NOT FIND EVENT NAME FOR: 0x%X ", idEventDef_a3->eventnum);
//			}
//			lastIdEventNum = idEventDef_a3->eventnum;
//		}
//	}*/
//
//	return p_idAnimated_HandleEvents_t(idAnimated_a1, a2, idEventDef_a3, a4);
//}


//? i could not get any events from this...weird.
//! bool __fastcall idEntity_HandleEvents_MB_20A9870(__int64 a1, __int64 a2)
//typedef bool(__fastcall* idEntity_HandleEvents_t)(__int64 a1, idEventDef* a2);
//idEntity_HandleEvents_t p_idEntity_HandleEvents_t = nullptr;
//idEntity_HandleEvents_t p_idEntity_HandleEvents_t_Target = nullptr;
//
//bool __fastcall idEntity_HandleEvents_t_Hook(__int64 idEntity_a1, idEventDef* idEventDef_a2) {
//	
//	static int lastIdEventNum = -1;
//
//	if (idEventDef_a2) {
//		if (idEventDef_a2->eventnum != lastIdEventNum) {
//			const char* eventNameCstr = idEventManager::GetEventNameForNum(idEventDef_a2->eventnum);
//			if (eventNameCstr) {
//				logWarn("idEntity_HandleEvents_t_Hook: eventnum has changed to: %s 0x%X ", eventNameCstr, idEventDef_a2->eventnum);
//			}
//			else {
//				logWarn("idEntity_HandleEvents_t_Hook: eventnum has changed BUT COULD NOT FIND EVENT NAME FOR: 0x%X ", idEventDef_a2->eventnum);
//			}
//			lastIdEventNum = idEventDef_a2->eventnum;
//		}
//	}
//
//	return p_idEntity_HandleEvents_t(idEntity_a1, idEventDef_a2);
//}

//? it doesn't work. either changing a2 or returning 0 or -1 from this func will create a graphic glitch until the animation is over. setting it to 1 will play the animation without the doll model.
//! void __fastcall idAnimWebHands::SetCustomAnimSelect_18D1940(__int64 idAnimWebHands_a1, int a2)
//typedef void(__fastcall* SetCustomAnimSelect_t)(__int64 idAnimWebHands_a1, int a2);
//SetCustomAnimSelect_t p_SetCustomAnimSelect_t = nullptr;
//SetCustomAnimSelect_t p_SetCustomAnimSelect_t_Target = nullptr;
//
//void __fastcall SetCustomAnimSelect_t_Hook(__int64 idAnimWebHands_a1, int a2) {
//
//	//logWarn("skipping custom anim...a2 was %.3f", (float)a2);
//	logWarn("skipping custom anim...chaning a2");
//	a2 = -1;
//
//	return p_SetCustomAnimSelect_t(idAnimWebHands_a1, a2);
//
//}

//? returning when it's the menus/currency_confirmation will simply prevent the pop up to display but you'll still be stuck.
//	//! void __fastcall idHudElement_Activate_MB_1C594C0(__int64 idHUDElement_a1, __int64 a2)
//typedef void(__fastcall* idHudElement_Activate_t)(__int64 idHUDElement_a1, __int64 a2);
//idHudElement_Activate_t p_idHudElement_Activate_t = nullptr;
//idHudElement_Activate_t p_idHudElement_Activate_t_Target = nullptr;
//
//void __fastcall idHudElement_Activate_t_Hook(__int64 idHUDElement_a1, __int64 a2) {
//	
//	//! log.
//	__int64 declElemPtr = (idHUDElement_a1 + 0xC8);
//	if (!MemHelper::isBadReadPtr((void*)declElemPtr)) {
//		__int64 declAddr = *(__int64*)declElemPtr;
//		if (!MemHelper::isBadReadPtr((void*)declAddr)) {
//			idResource* resPtr = (idResource*)declAddr;
//			if (!MemHelper::isBadReadPtr(&resPtr->name)) {
//				std::string declName = resPtr->name.str;
//				idHudManager::debugLogUniqueDeclName(declName, idHUDElement_a1);
//			}
//		}
//	}
//
//	/*__int64 declElemPtr = (idHUDElement_a1 + 0xC8);
//	if (!MemHelper::isBadReadPtr((void*)declElemPtr)) {
//		__int64 declAddr = *(__int64*)declElemPtr;
//		if (!MemHelper::isBadReadPtr((void*)declAddr)) {
//			idResource* resPtr = (idResource*)declAddr;
//			if (!MemHelper::isBadReadPtr(&resPtr->name)) {
//				std::string declName = resPtr->name.str;
//				if (declName == "menus/currency_confirmation") {
//					return;
//				}
//			}
//		}
//	}*/
//	
//
//	p_idHudElement_Activate_t(idHUDElement_a1, a2);
//}

//? cutting my teeths on this for soooo long....
//! bool __fastcall idBroadcastManager::ReleaseBroadcastEvent_489600(__int64 *a1, unsigned __int16 a2, int a3, _QWORD *a4)
//typedef bool(__fastcall* ReleaseBroadcastEvent_t)(__int64* a1, unsigned __int16 a2, int a3, _QWORD* a4);
//ReleaseBroadcastEvent_t p_ReleaseBroadcastEvent_t = nullptr;
//ReleaseBroadcastEvent_t p_ReleaseBroadcastEvent_t_Target = nullptr;
//
//bool __fastcall ReleaseBroadcastEvent_t_Hook(__int64* a1, unsigned __int16 a2, int a3, _QWORD* a4) {
//	static unsigned __int16 lasta2 = -1;
//	
//	//? not this will crash:
//	//idHudEventManager::onReleasedBroadcastEvent(a2);
//
//	/*if (a2 != lasta2) {
//		logInfo("ReleaseBroadcastEvent_t_Hook: hudEvent has changed to 0x%X", a2);
//		lasta2 = a2;
//	}*/
//	
//	return p_ReleaseBroadcastEvent_t(a1, a2, a3, a4);
//}


//! not useful to disable custom animations
////! void __fastcall idAnimWebPlayerSmth_B27CA0(__int64 idAnimWebPlayer_a1, __int64 idAnimStack_a2, __int64 a3, __int64 a4)
//typedef void(__fastcall* idAnimWebPlayerSmth_t)(__int64 idAnimWebPlayer_a1, __int64 idAnimStack_a2, __int64 a3, __int64 a4);
//idAnimWebPlayerSmth_t p_idAnimWebPlayerSmth_t = nullptr;
//idAnimWebPlayerSmth_t p_idAnimWebPlayerSmth_t_Target = nullptr;
//
//void __fastcall idAnimWebPlayerSmth_t_Hook(__int64 idAnimWebPlayer_a1, __int64 idAnimStack_a2, __int64 a3, __int64 a4) {
//
//	static __int64 lastDeclAddr = -1;
//
//	__int64 declAddr = *(_QWORD*)(idAnimWebPlayer_a1 + 0x358);
//	if (declAddr != lastDeclAddr) {
//		//logInfo("idAnimWebPlayerSmth_B27CA0: decl addr has changed to: %p", (void*)declAddr);
//		declAddr = lastDeclAddr;
//	}
//
//	p_idAnimWebPlayerSmth_t(idAnimWebPlayer_a1, idAnimStack_a2, a3, a4);
//}




//! we actually don't need this for the mod to work 
//! this is the func that prints not only the strings when using debug_hud_string sdfsdfsdfsdf but also other debug msg which seems to be disable for the game production build. 
//! i tried to use this func to render string directly before and it was a failure, instead i'm using it as a counter/indicator as this func will call (through other funcs) 4CAD00 which is the func we use to print text and icons
//! double __fastcall idHud_Debug_Print_Smth_1558D50(idHUD_Debug* idHudDebug_a1,idRenderModelGui* renderModelGui_a2,__int64* a3)

//typedef double(__fastcall* IdHudDebugPrint)(__int64* idHUD_Debug, __int64* idRenderModelGui, __int64*);
//IdHudDebugPrint pIdHudDebugPrint = nullptr;
//IdHudDebugPrint pIdHudDebugPrintTarget = nullptr;
//
//double __fastcall IdHudDebugPrintHook(__int64* idHUD_Debug_a1, __int64* idRenderModelGui_a2, __int64* a3) {
//
//	logDebug("IdHudDebugPrintHook");
//	//logInfo("debug IdHudDebugPrintHook");
//	//! this will let our printOutlinedStringMB_hook that it can render the ice icon once and then stop rendering it until this flag is raised again.
//	//idRenderModelGuiManager::resetRenderDrawCallCount(); // not using this atm
//	//logInfo("debug: IdHudDebugPrintHook:... raising render flag !");
//
//	//logInfo("IdHudDebugPrintHook: Triggered");
//
//	//HudTracker::curIndex = 0;
//
//	//return pIdHudDebugPrint(idHUD_Debug_a1, idRenderModelGui_a2, a3);
//
//	// idRenderModelGui* v114Ptr = (idRenderModelGui*)(rbp - 0x40);
//
//	//__int64 rbp = GetRBPValueWithRAxPreserved();
//	//__int64 RenderModelGui_Stack_v114 = rbp - 0x40;
//
//	//const char* strTest = "Hello";
//	////__int64 colorTestAddr = MemHelper::getAddr(0x387F138);
//	//__int64 colorWhiteAddr = MemHelper::getAddr(0x387F098);
//	//float floatTest = 1.0f;
//	//
//	//char FAKERenderModelGui_Stack_v114[1824];
//	//
//	//logInfo("IdHudDebugPrintHook: rbp %p", (void*)rbp);
//	//logInfo("IdHudDebugPrintHook: RenderModelGui_Stack_v114 %p", (void*)RenderModelGui_Stack_v114);
//	//logInfo("IdHudDebugPrintHook: colorTestAddr %p", (void*)colorWhiteAddr);
//	//logInfo("IdHudDebugPrintHook: (__int64)& colorTestAddr %p", (void*)(__int64)&colorWhiteAddr);
//
//	//static initRenderModelGuiMb pinitRenderModelGuiMb = reinterpret_cast<initRenderModelGuiMb>(MinHookManager::getInitRenderModelGuiMbFuncAdd());
//
//
//	//pinitRenderModelGuiMb((__int64)FAKERenderModelGui_Stack_v114, (__int64)idRenderModelGui_a2);
//
//	////? this will actually make the game crash:
//	////pinitRenderModelGuiMb(RenderModelGui_Stack_v114, (__int64) idRenderModelGui_a2);
//	//
//	//
//
//	//logInfo("IdHudDebugPrintHook: pinitRenderModelGuiMb %p", (void*)pinitRenderModelGuiMb);
//
//	//static SetFontAndPrintStringMB pSetFontAndPrintStringMB = reinterpret_cast<SetFontAndPrintStringMB>(MinHookManager::GetSetFontAndPrintStringMBFuncAdd());
//	//
//	//
//	////pSetFontAndPrintStringMB(RenderModelGui_Stack_v114, strTest, 0x65, 0x74, 1.0f, (__int64)&colorTestAddr, 0, 1, 0);
//	//
//	////! Doesn't crash but nothing on screen, may be check the values we get passed here in the original func and see if it works
//	////pSetFontAndPrintStringMB((__int64)FAKERenderModelGui_Stack_v114, strTest, 300, 300, 1.0f, (__int64)&colorTestAddr, 0, 1, 1);
//	//
//	//pSetFontAndPrintStringMB((__int64)idRenderModelGui_a2,  strTest, 300, 300, 1.0f, colorWhiteAddr, 0, 1, 0);
//
//	////? setting the colorTestAddr arg to 0 seem to crash the game
//	////pSetFontAndPrintStringMB((__int64)FAKERenderModelGui_Stack_v114, strTest, 0x65, 0x74, 1.0f, 0i64, 0, 1, 0);
//
//	////? nothing printed on screen here but not sure if it from the color or other args being the problem rather than the idRenderModelGui ptr
//	////pSetFontAndPrintStringMB((__int64)idRenderModelGui_a2, strTest, 0x65, 0x74, 1.0f, (__int64)&colorTestAddr, 0, 1, 0);
//
//	//logInfo("IdHudDebugPrintHook: pSetFontAndPrintStringMB %p", (void*)pSetFontAndPrintStringMB);
//
//
//
//	//return 0.0f; //? double check this......................................
//
//
//
//	return pIdHudDebugPrint(idHUD_Debug_a1, idRenderModelGui_a2, a3);
//}



// 
//! 17/10/23 i've been using this as a hook to add strings to the screen, but i managed to do it better in the debugHudString hook func 4CAD00, so this is not really necessary, and even if we have perf issue to display the stats or mod name on the name page it's not a big deal as those should be displayed in moments where perf in not important eg: end of level or main page. 
//! __int64 __fastcall idRenderModelGui::DrawString_6239F0(__int64 idMenuPtr_a1,float x_a2,float y_a3,char* text_a4,__int64 idColor_a5,char a6,float scale_a7)
//typedef __int64(__fastcall* idRenderModelGui_DrawString)(__int64 a1, float a2, float a3, const char* a4, __int64 a5, char a6, float a7);
//idRenderModelGui_DrawString pidRenderModelGui_DrawString = nullptr;
//idRenderModelGui_DrawString pidRenderModelGui_DrawStringTarget;
//
////!DrawString(idRenderModelGuiAdrr, x, y, text, (__int64)&idColor, forceColorMB 0, scale);
//__int64 __fastcall idRenderModelGui_DrawStringHook(__int64 gui_a1, float x_a2, float y_a3, const char* text_a4, __int64 idColor_a5, char a6, float scale_a7) {
//
//	
//
//	//text_a4 = "hello world";
//
//	
//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//
//
//	//! we don't want to write anything when the console is opened because the console uses the idRenderModelGui_DrawString to render text.
//	//if (idConsoleLocalManager::isRenderFpsCounter(scale_a7) ) {
//	//	HudElement::index = 0;
//	//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//	//}
//
//	//if ( idConsoleLocalManager::isConsoleOpened()) {
//	//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//	//}
//
//	
//
//
//
//	//text_a4 = "hello world";
//
//	//logInfo("idRenderModelGui_DrawStringHook: text_a4: %s, scale_a7: %.3f idColor_a5: %p", text_a4, scale_a7, (void*)idColor_a5);
//
//	//! this works
//	//idColor_a5 = (__int64)&colorRed;
//
//	//? *** START 7/3/23 0:42 this is what you have to uncomment when you're done with your test of DrawStretchPic hook for g_material test ****
//	////! this should hopefully prevent message in the console being unreadable
//	//if (id_ConsoleLocal.isConsoleOpened()) {
//	//	id_ConsoleLocal.setFont(idFontHash::defaultCourrierF8);
//	//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//	//}
//	//else {
//	//	id_ConsoleLocal.setFont(idFontHash::ttSuper98); //! numeral font
//	//	
//	//}
//
//	////! this should make sure to always show the FPS counter if user chooses it
//	////? hopefully it's the only string in the game that has this scale...If you ever seem some weird scale strings it will be because of this:
//	//if (id_ConsoleLocal.isRenderFpsCounter(scale_a7)) { 	
//	//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//	//}
//
//	//if (PlayerStateChecker::isPlaying() && id_ConsoleLocal.isRenderStringFlag()) {	
//	//	DrawStringHookArgs args = id_ConsoleLocal.getDrawStringHookArgsV2();		
//	//	strcpy((char*)text_a4, args.str.c_str());
//	//	x_a2 = args.x;
//	//	y_a3 = args.y;
//	//	idColor_a5 = (__int64)&args.IdColor;
//	//	scale_a7 = args.scale;
//	//}
//
//	//else { //? or return 1 or smth?		
//
//	//	//! attempting this if it false just uncomment the comment below
//	//	if (!id_ConsoleLocal.isRenderStretchedPicFlag()) {
//	//		strcpy((char*)text_a4, id_ConsoleLocal.getEmptyString().c_str());
//	//	}
//
//	//	//! this is what you want to uncomment if what is above fails
//	//	//strcpy((char*)text_a4, id_ConsoleLocal.getEmptyString().c_str());
//	//	 
//	//	//id_ConsoleLocal.raiseRenderStretchedPicFlag(); //? <= experiment........
//	//	//logInfo("idRenderModelGui_DrawStringHook else cond");
//	//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//	//}
//
//	//? *** END 7/3/23 0:42 this is what you have to uncomment when you're done with your test of DrawStretchPic hook for g_material test ****
//
//
//
//
//	//? (unsigned int*)(gui_a1 + 0x4D0) = colorPurple.PackColor(); // <= this doesn't work even with a6 set to 1 or 0.
//	//return 1;
//
//	/*std::string drawStringStrArg = text_a4;
//	logInfo("idRenderModelGui_DrawStringHook: drawStringStrArg: %s", drawStringStrArg.c_str());
//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);*/
//
//	//idRenderModelGui::isDrawStringTriggered = 1;
//
//
//	//! this absolutely has impoact on perf.
//	//consoleLocal.testDraw();
//
//	//! it "feels' like there is a perf cost to this, i guess it's manageable but there should be not perf cost so NO.
//	//consoleLocal.testCrosshairObject();
//
//	//return consoleLocal.getIdColorPackColorWhite();
//	//return 1;
//
//	//std::string drawStringStrArg = "+";
//	//strcpy((char*)text_a4, g_plusSignStr.c_str());
//	//strcpy((char*)text_a4, drawStringStrArg.c_str());
//
//
//
//	//std::string drawStringStrArg = text_a4;
//	//logInfo("idRenderModelGui_DrawStringHook: drawStringStrArg: %s", drawStringStrArg.c_str());
//	//logInfo("idRenderModelGui_DrawStringHook: gui_a1: %p", (void*)gui_a1);
//
//	//gui.acquirePtr(idMenuPtr_a1);
//
//	//LI("idRenderModelGui_DrawStringHook x= %.2f y= %.2f %s", x_a2, y_a3, text_a4);
//	//const char* plusCh = "+";
//	//const char* dotCh = ".";
//	//const char* plusCh = "AAAA";
//
//
//	//return pidRenderModelGui_DrawString(idMenuPtr_a1, 800.00, 102.00, dotCh, (__int64)&colorRed, 0, 3.0f);
//	//return pidRenderModelGui_DrawString(idMenuPtr_a1, 800.00, 102.00, dotCh, idColor_a5, a6, 3);
//	// 
//	return pidRenderModelGui_DrawString(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, scale_a7);
//}












//! could not make this work
// void __fastcall SetFontAndPrintStringMB__15A43B0(idRenderModelGui* a1,const char* a2,__int64 a3,__int64 a4,float a5,__int64 a6,int a7,char a8,unsigned int a9)
//typedef void(__fastcall* SetFontAndPrintStringMB)(__int64 a1, const char* a2, __int64 a3, __int64 a4, float a5, __int64 a6, int a7, char a8, unsigned int a9);
//SetFontAndPrintStringMB pSetFontAndPrintStringMB = nullptr;
//SetFontAndPrintStringMB pSetFontAndPrintStringMBTarget = nullptr;
//
//void __fastcall SetFontAndPrintStringMBHook(__int64 a1, const char* a2, __int64 a3, __int64 a4, float a5, __int64 a6, int a7, char a8, unsigned int a9) {
//
//	/*const char* helloStr = "hello";
//	a2 = helloStr;*/
//
//
//	//logInfo("a3: %p", (void*)a3);
//	//logInfo("a3(llx): %llx", a3);
//	//logInfo("a4: %p", (void*)a4);
//	//logInfo("a4(llx): %llx", a4);
//	//logInfo("a5: .3f%", a5);
//	//logInfo("a6: %p", (void*)a6);
//	//logInfo("a7: %d", a7);
//	//logInfo("a8: %c", a8);
//	//logInfo("a9: %u", a9);
//
//
//	//a3 = 0x65;
//	//a4 = 0x74;
//
//	return pSetFontAndPrintStringMB(a1, a2, a3, a4, a5, a6, a7, a8, a9);
//}



// __int64 __fastcall sub_4CA590(__int64 a1, __int64 a2)
//typedef __int64(__fastcall* initRenderModelGuiMb)(__int64 a1, __int64 a2);


//? don't mind this, this is usual bs from gepeto:
//typedef void(__fastcall* SetFontAndPrintStringMB)(
//	void* thisPointer,
//	const char* rdxArgument,
//	__int64* stackArg1,
//	int stackArg2,
//	int stackArg3,
//	char stackArg4,
//	int stackArg5
//	);
//
//SetFontAndPrintStringMB pSetFontAndPrintStringMB = nullptr;
//SetFontAndPrintStringMB pSetFontAndPrintStringMBTarget = nullptr;
//
//void __fastcall SetFontAndPrintStringMBHook(void* thisPointer,	const char* rdxArgument, __int64* stackArg1,	int stackArg2,	int stackArg3,	char stackArg4,	int stackArg5) {
//
//	/*const char* helloStr = "hello";
//	a2 = helloStr;*/
//
//	logInfo("thisPointer: %p", thisPointer);
//	logInfo("rdxArgument: %s", rdxArgument);
//	logInfo("stackArg1: %p", stackArg1);
//	logInfo("stackArg2: %d", stackArg2);
//	logInfo("stackArg3: %d", stackArg3);
//	logInfo("stackArg4: %c", stackArg4);
//	logInfo("stackArg5: %d", stackArg5);
//
//
//
//	//a3 = 0x65;
//	//a4 = 0x74;
//
//	return pSetFontAndPrintStringMB(thisPointer, rdxArgument, stackArg1, stackArg2, stackArg3, stackArg4, stackArg5);
//}


//! 
//! 622BB0. Not using this hook anymore as we call this func directly from other hook
//typedef void(__fastcall* DrawStretchPic_func)(
//	__int64 a1,
//	float* a2,
//	__int64 a3,
//	__int64 a4,
//	float* a5,
//	__int64 a6,
//	float a7
//	);
//
//DrawStretchPic_func pDrawStretchPic = nullptr;
//DrawStretchPic_func pDrawStretchPic_target;
//
//void __fastcall DrawStretchPic_hook(
//	__int64 a1,
//	float* a2,
//	__int64 a3,
//	__int64 a4,
//	float* a5,
//	__int64 a6,
//	float a7
//) {
//	//DebugManager::drawStretchPicCounter++;
//	//logInfo("DrawStretchPic_hook: drawStretchPicCounter: %d", DebugManager::drawStretchPicCounter);
//
//	// Call the original function
//	pDrawStretchPic(a1, a2, a3, a4, a5, a6, a7);
//}


//! (guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr). Not using this hook anymore as we call this func directly from other hook
//typedef void(__fastcall* idRenderModelGui_DrawStretchPic)(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 a11);
//static idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic;
//idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(MemHelper::getFuncAddr(0x498A10));



//? looks like we can not hook this func as everytime we do it modifies the func itself, probably cause ida decompile is wrong
//!__int64 __fastcall debug_hud_string_4CB340(idRenderModelGui* a1,float a2,__int64 a3,float a4,float* a5,_BYTE* a6,int a7,int a8){
//typedef __int64(__fastcall* debug_hud_string_func)(
//	__int64* idRenderModelGui_a1,
//	float a2,
//	__int64 a3,
//	float a4,
//	float* a5,
//	char* a6,
//	int a7,
//	int a8
//	);
//debug_hud_string_func pdebug_hud_string = nullptr;
//debug_hud_string_func pdebug_hud_string_target;
//
//__int64 __fastcall debug_hud_string_hook(
//	__int64* idRenderModelGui_a1,
//	float a2,
//	__int64 a3,
//	float a4,
//	float* a5,
//	char* a6,
//	int a7,
//	int a8
//) {
//	
//
//	idRenderModelGuiManager::drawAllNeededIconsTest((__int64)idRenderModelGui_a1);
//	/*for (size_t i = 0; i < 10; i++)
//	{
//
//		
//	}*/
//
//
//
//	//const char* potentialStr = (const char*)
//	//logInfo("debug_hud_string_hook: TRIGGERED resetting: current drawStretchPicCounter  current drawStretchPicCounter %d", DebugManager::drawStretchPicCounter);
//	DebugManager::drawStretchPicCounter = 0;
//	//logInfo("DrawStretchPic_hook: drawStretchPicCounter: %d", DebugManager::drawStretchPicCounter);
//	// Call the original function
//	return pdebug_hud_string(idRenderModelGui_a1, a2, a3, a4, a5, a6, a7, a8);
//}





////? not triggered.....
//typedef _int64(__fastcall* sub_544BB0_Type)(_QWORD* a1, __int64 a2, Int128* a3);
//
//sub_544BB0_Type pSub_544BB0 = nullptr;
//sub_544BB0_Type pSub_544BB0_Target;
//
//// Define the hook function
//_int64 __fastcall sub_544BB0_Hook(_QWORD* a1, __int64 a2, Int128* a3) {
//	// Your custom code here (you can modify or log function arguments before calling the original function)
//
//
//	logInfo("sub_544BB0_Hook triggered");
//	std::cerr << "sub_544BB0_Hook failed" << std::endl;
//	_int64 result = pSub_544BB0(a1, a2, a3); // Call the original function
//
//	// Your custom code here (you can modify the result or perform additional actions)
//
//	return result;
//}




//! afaik we don't need a hook here because we alredy use a function pointer to it in idInventoryCollectionManager.h
//__int64 __fastcall idInventoryCollection::GetInventoryItem_1D1D6A0(__int64 gui_a1, int x_a2)
//typedef __int64(__fastcall* idInventoryCollectionGetInventoryItem)(__int64 gui_a1, int x_a2);
//idInventoryCollectionGetInventoryItem pidInventoryCollectionGetInventoryItem = nullptr;
//idInventoryCollectionGetInventoryItem pidInventoryCollectionGetInventoryItemTarget;
//
//__int64 __fastcall idInventoryCollectionGetInventoryItemHook(__int64 idInventoryCollectionPtr, int x_a2) {
//
//	//mem.aquire_idInventoryCollectionPtr(idInventoryCollectionPtr);
//	//inv.acquire_idInventoryCollectionPtr(idInventoryCollectionPtr);
//
//	return pidInventoryCollectionGetInventoryItem(idInventoryCollectionPtr, x_a2);
//}



//typedef __int64(__fastcall* equipmentInfo)(__int64 gui_a1);
//equipmentInfo pEquipmentInfo = nullptr;
//equipmentInfo pEquipmentInfoTarget;
//
//__int64 __fastcall equipmentInfoHook(__int64 idHudWeaponInfoPtr) {
//
//	//switcher.aquire_idHudWeaponInfoPtr(idHudWeaponInfoPtr);
//	//mem.aquire_idHudWeaponInfoPtr(idHudWeaponInfoPtr); //! this is needed to force weapon switching
//	//! the arg here is a ptr to a idHud_WeaponInfo obj however it doesn't seem reliable to me to get the nade value. I'll use idplayer ptr + nade offset instead.
//
//	return pEquipmentInfo(idHudWeaponInfoPtr);
//}

//? not using this anymore as we use ptr scan to find cmdSystemPtr
//! __int64 __fastcall sub_461060(_QWORD *a1, unsigned int a2)
//typedef __int64(__fastcall* idCmdSystemSmth_461060)(__int64* cmdSystem_a1, unsigned int a2);
//idCmdSystemSmth_461060 pidCmdSystemSmth_461060 = nullptr;
//idCmdSystemSmth_461060 pidCmdSystemSmth_461060Target;
//
//__int64 __fastcall idCmdSystemSmth_461060_Hook(__int64* cmdSystem_a1, unsigned int a2) {
//
//	ObjectLocator::aquireCmdSystemLocalPtr(cmdSystem_a1);
//	/*static __int64* lastcmdSystemPtr = 0;
//	if (cmdSystem_a1 != lastcmdSystemPtr) {
//		lastcmdSystemPtr = cmdSystem_a1;
//		if (cmdSystem_a1 == 0) {
//			logWarn("cmdSystem_a1 == 0 WTF???!!!!!!");
//		}
//		else {
//			logInfo("cmdSystem_a1 ptr has changed and is now: %p ", cmdSystem_a1);
//		}
//	}*/
//	return pidCmdSystemSmth_461060(cmdSystem_a1, a2);
//}




//! NEW COLOSSUS CODE: game console log
//typedef void(__cdecl* IdLib_Printf)(const char* a1, ...);
//IdLib_Printf  pIdLib_Printf = nullptr;
//IdLib_Printf  pIdLib_PrintfTarget;
//
//
//void __cdecl IdLib_PrintfHook_1238530(const char* format, ...) {
//	va_list args;
//	va_start(args, format);
//
//	char buffer[2048];
//	int result = vsnprintf(buffer, sizeof(buffer), format, args);
//
//	va_end(args);
//
//	globalVariableString = std::string(buffer);
//
//	if (ModSettingsManager::getIsLogGameConsoleToLogFile()) {
//		logInfo("IdLib_Printf: %s", globalVariableString.c_str());
//	}
//
//	return pIdLib_Printf(buffer);
//}










//! this is an attempt to have the console still working, it doesn't work: update it didn't cause of wrong declaration check the working one.
//int __cdecl IdLib_PrintfHook(const char* format, ...) {
//	va_list args;
//	va_start(args, format);
//
//	char buffer[2048];
//	int result = vsnprintf(buffer, sizeof(buffer), format, args); // Store the result of vsnprintf
//
//	//va_end(args);  // Call va_end after using va_list
//
//	globalVariableString = std::string(buffer);
//	logInfo("id console: %s", globalVariableString.c_str());
//
//	// Call the original function
//	//return result; // Return the result of vsnprintf
//	return pIdLib_Printf(format, args);
//}





//! char __fastcall idInternalCVar::Set_371CD0(__int64 **a1, char *a2, char a3)
//typedef char(__fastcall* idInternalCVar_Set)(__int64** a1, char* a2, char a3);
//idInternalCVar_Set pidInternalCVar_Set = nullptr;
//idInternalCVar_Set pidInternalCVar_SetTarget;
//
//char __fastcall idInternalCVar_SetHook(__int64** a1, char* a2, char a3) {
//
//	//__int64* v5 = (*a1);
//
//
//	//? commenting this for now so we can see if we can get data from idlib func
//
//	//// Check if v5 is not null and if it points to a valid C-string (assuming it is)
//	//if (v5 && v5[5]) {
//	//	const char* cstring = reinterpret_cast<const char*>(v5[5]);
//
//	//	if (strncmp(cstring, "r_", 2) != 0) {
//	//		// Print only if it does not start with "r_"
//	//		logInfo("idInternalCVar_SetHook: v5[5]: %s and a2 is %s", cstring, a2);
//	//	}
//	//}
//	//else {
//	//	logWarn("idInternalCVar_SetHook: v5 is null or v5[5] is null.");
//	//}
//
//
//
//	return pidInternalCVar_Set(a1, a2, a3);
//}


//?  this is not triggered 
//! __int64 __fastcall SoundLangSmth_A8AE00(__int64 a1, const char *a2, const char *lang_a3)
//typedef __int64(__fastcall* SoundLangSmth_A8AE00)(__int64 a1, const char* a2, const char* lang_a3);
//SoundLangSmth_A8AE00 pSoundLangSmth_A8AE00 = nullptr;
//SoundLangSmth_A8AE00 pSoundLangSmth_A8AE00Target;
//
//__int64 SoundLangSmth_A8AE00Hook(__int64 a1, const char* a2, const char* lang_a3) {
//
//	logInfo("SoundLangSmth_A8AE00Hook has been triggered and lang_a3 is %s ", lang_a3);
//
//	return pSoundLangSmth_A8AE00(a1, a2, lang_a3);
//}




//? Especially not using this anymore as it has a wrong idPlayer pointer when map is loading, which was responsible for very hard to find crash...
//! char __fastcall idPlayer::ProcessInput_ServerAndClient_Local_1ABBDD0(__int64 gui_a1, char x_a2)
//typedef char(__fastcall* idPlayerProcessInputSACL)(__int64 a1, char a2);
//idPlayerProcessInputSACL pIdPlayerProcessInput = nullptr;
//idPlayerProcessInputSACL pIdPlayerProcessInputTarget;
//
//char __fastcall idPlayerProcessInputSACLHook(__int64 idPlayerPtr, char a2) {
//	//! as this is called (many times per seconds) only when player is in game it's a good way to find out if player is in menu or not and if we should disable the mod or not.
//		//binderHelper.updateIdplayerProcessInputTimeStamp();
//	//playerState.updateIdplayerProcessInputTimeStamp();
//	//PlayerStateChecker::updateLastInputProcess();
//
//	//mem.aquire_idPlayerPtr(idPlayerPtr);
//	//eql.aquire_idPlayerPtr(idPlayerPtr);
//
//	//inv.acquire_idPlayerPtr(idPlayerPtr);
//
//	ObjectLocator::aquireIdPlayerAddr(idPlayerPtr);
//
//
//	//mem.getCurrentlyEquippedWeaponIndex();
//
//
//	return pIdPlayerProcessInput(idPlayerPtr, a2);
//}








//? BAK do not delete!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!:
//bool __fastcall isKeyPressedHook(__int64 ptr, __int64 btnEnum) {
//
//	usercmdButton userCmdBtn = (usercmdButton)btnEnum;
//	switch (userCmdBtn)
//	{
//
//		/*case usercmdButton::BUTTON_NONE: // not checking this cause NONE is the value of the default weapon btn to resend.
//			break;	*/
//			// afaik BUTTON_ZOOM is not triggered even when in scop of the HAR
//			//case usercmdButton::BUTTON_ZOOM:
//			//	if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_ZOOM)) {
//			//		logInfo("BUTTON_ZOOM pressed");
//			//		/*if (g_debugIsReticleTest) {
//			//			if (idCmd::getReticleMode() != UI_ReticleMode::Full) {
//			//				idCmd::setReticleMode(UI_ReticleMode::Full);
//			//			}
//			//		}*/
//			//	}
//			//	
//			//	break;
//
//	case usercmdButton::BUTTON_CHANGEWEAPON:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CHANGEWEAPON)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_CHANGEWEAPON);
//		}
//		break;
//	case usercmdButton::BUTTON_WEAP_NEXT:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_NEXT)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_NEXT);
//		}
//		break;
//	case usercmdButton::BUTTON_WEAP_PREV:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_WEAP_PREV)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_WEAP_PREV);
//		}
//		break;
//	case usercmdButton::BUTTON_SHOTGUN:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_ASSAULT_RIFFLE:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_PLASMA:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_RL:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_SUPER_SHOTGUN:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_BALISTA:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_MINIGUN:
//		if (switcher.isWeaponBtnToResend(userCmdBtn)) {
//			return true;
//		}
//		break;
//	case usercmdButton::BUTTON_BFG_UNMAKER:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG_UNMAKER)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_BFG_UNMAKER);
//		}
//		break;
//	case usercmdButton::BUTTON_WEAP_9: //! no idea what this weapon is, don't think it exists.
//		break;
//	case usercmdButton::BUTTON_BFG:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_BFG)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_BFG);
//		}
//		break;
//	case usercmdButton::BUTTON_WALK:
//		break;
//	case usercmdButton::BUTTON_DASH:
//		break;
//	case usercmdButton::BUTTON_USE_EQUIPMENT:
//
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_USE_EQUIPMENT)) {
//			idPlayer_K::setGrenadeType(GrenadeType::Frag);
//			logInfo("BUTTON_USE_EQUIPMENT (Frag) pressed");
//			return true;
//		}
//		else if ((buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_OBJECTIVES))) {
//			idPlayer_K::setGrenadeType(GrenadeType::Ice);
//			logInfo("BUTTON_OBJECTIVES (Ice) pressed");
//			return true;
//		}
//
//		break;
//	case usercmdButton::BUTTON_SWITCH_EQUIPMENT:
//
//		//! this is what you want to comment out to prevent the frag to always be displayed/selected (good for debugging)
//		if (idPlayer_K::getCurrentGrenadeType() == GrenadeType::Ice) {
//			return true; //! forcing frag nade to always be selected so we can create our own ice icon + cooldown
//		}
//
//
//		break;
//	case usercmdButton::BUTTON_QUICK_3:
//		break;
//	case usercmdButton::BUTTON_INVENTORY:
//		break;
//	case usercmdButton::BUTTON_ACTIVATE_ABILITY:
//		break;
//	case usercmdButton::BUTTON_CRUCIBLE_HAMMER:
//		if (buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_CRUCIBLE_HAMMER)) {
//			switcher.disableEnumResend(usercmdButton::BUTTON_CRUCIBLE_HAMMER);
//		}
//		break;
//	case usercmdButton::BUTTON_OBJECTIVES:
//		//! this will make the switch equipment butn become show objective 
//		//if ((buttonCheck.isKeyPressedCustom(ptr, (__int64)usercmdButton::BUTTON_SWITCH_EQUIPMENT))) {
//		//	//logInfo("BUTTON_OBJECTIVES (Ice) pressed");
//		//	return true;
//		//}
//		//return false;
//
//		break;
//	default:
//		break;
//	}
//
//	return pisKeyPressed(ptr, btnEnum);
//}



//! void __fastcall BindCopyControllerStrSomething_1C335A0(__int64 gui_a1, unsigned __int8 *x_a2)
//typedef void(__fastcall* BindCopyControllerStrSomething)(__int64 gui_a1, unsigned __int8* x_a2);
//BindCopyControllerStrSomething pBindCopyControllerStrSomething = nullptr;
//BindCopyControllerStrSomething pBindCopyControllerStrSomethingTarget;
//
////! this will replace any string we need in the menu controller layouts screens
//void __fastcall pBindCopyControllerStrSomethingHook(__int64 gui_a1, unsigned __int8* x_a2) {
//
//	//std::string a2AsStr(reinterpret_cast<char const*>(x_a2));
//
//	//unsigned char stringTest[13] = "Frag Grenade";
//
//	//if (a2AsStr == "Equipment Launcher") {
//	//if (a2AsStr == EquipmentLauncherStr) {
//	//	//return pBindCopyControllerStrSomething(gui_a1, stringTest);
//	//	return pBindCopyControllerStrSomething(gui_a1, FragGrenadeCharArr);
//	//}
//	//else if (a2AsStr == MissionInformationStr) {
//	//	return pBindCopyControllerStrSomething(gui_a1, IceGrenadeCharArr);
//	//}
//	//else {
//	//	return pBindCopyControllerStrSomething(gui_a1, x_a2);
//	//}
//
//
//	return pBindCopyControllerStrSomething(gui_a1, x_a2);
//}




//! __int64 __fastcall idMaterial2_SomeInitFunc_464250(__int64 gui_a1)
//typedef __int64(__fastcall* idResourceSmth)(__int64 a1);
//idResourceSmth pidResourceSmth = nullptr;
//idResourceSmth pidResourceSmthTarget;
//
//__int64 __fastcall idResourceSmthHook(__int64 a1) {
//
//	/* debugHud.addResourcePtr(gui_a1);*/
//	idRes.addResourcePtr(a1);
//	return pidResourceSmth(a1);
//}


//! used to trigger the current game state: loading, main menu or ingame (in game doesn' necesserally mean playing)this func is triggered on map loading once.
// __int64 __fastcall idGameSystemLocal__MinimalGameCleanup_sub_CED020(	__int64 idGameSystemLocal_a1,	__int64 x_a2,	__int64* y_a3)
//typedef __int64(__fastcall* idGameSystemLocalMinimalGameCleanup)(__int64 idGameSystemLocal_a1, __int64 x_a2, __int64* y_a3);
//idGameSystemLocalMinimalGameCleanup pidGameSystemLocalMinimalGameCleanup = nullptr;
//idGameSystemLocalMinimalGameCleanup pidGameSystemLocalMinimalGameCleanupTarget;
//
//__int64 __fastcall idGameSystemLocalMinimalGameCleanupHook(__int64 idGameSystemLocal_a1, __int64 x_a2, __int64* y_a3) {
//
//	//logInfo("idGameSystemLocalMinimalGameCleanupHook....");
//	//x not using this here as it trigger the check of before this func is executed, but this func will modify the state at offset 44 of idGameSystemLocal_a1 so we'll check check this value manually in the main loop
//	//PlayerStateChecker::updateGameState(idGameSystemLocal_a1);
//	// 
//	//! using scanning instead atm to get IdGameSystemLocalAddr
//	//ObjectLocator::aquiredIdGameSystemLocalAddr(idGameSystemLocal_a1); //! adding this so we can aquire idGameSystemLocal from a function instead of a static addr so if the game is updated this should still work
//
//	return pidGameSystemLocalMinimalGameCleanup(idGameSystemLocal_a1, x_a2, y_a3);
//}





//! x_a2 will have a value of 15 when pause menu is active and value of 12 when the settings of the pause menu, and val of 0 when not in pause menu.
//! char __fastcall idHUDMenu_Screen_Pause::HandleActionMb_16003D0(__int64 idHUDMenu_Screen_Pause_a1, __int64 x_a2)
//typedef char(__fastcall* idHUDMenuScreenPause_HandleAction)(__int64 idHUDMenu_Screen_Pause_a1, __int64 x_a2);
//idHUDMenuScreenPause_HandleAction pidHUDMenuScreenPause_HandleAction = nullptr;
//idHUDMenuScreenPause_HandleAction pidHUDMenuScreenPause_HandleActionTarget;
//
//char __fastcall idHUDMenuScreenPause_HandleActionHook(__int64 idHUDMenu_Screen_Pause_a1, __int64 x_a2) {
//	//static unsigned int lasta2Val = -1;
//
//	//unsigned int a2Val = *(unsigned int*)x_a2;
//
//	//ObjectLocator::acquire_idHUDMenu_Screen_Pause_Addr(idHUDMenu_Screen_Pause_a1);
//
//	//logInfo("idHUDMenuScreenPause_HandleActionHook a2Val %u", a2Val);
//
//
//	/*if (a2Val != lasta2Val) {
//		logInfo("idHUDMenuScreenPause_HandleActionHook x_a2 has changed from %u to %u", lasta2Val, a2Val);
//		lasta2Val = a2Val;
//	}*/
//
//	return pidHUDMenuScreenPause_HandleAction(idHUDMenu_Screen_Pause_a1, x_a2);
//}



//! void __fastcall idDebugHUDLocal::Render(idDebugHUDLocal *idMenuPtr_a1, idRenderModelGuis *x_a2)
//! void __fastcall idDebugHUDLocal::Render_499690(__int64 idMenuPtr_a1, __int64 x_a2)
//typedef void(__fastcall* idDebugHUDLocal_Render)(__int64 a1, __int64 a2);
//idDebugHUDLocal_Render pidDebugHUDLocal_Render = nullptr;
//idDebugHUDLocal_Render pidDebugHUDLocal_RenderTarget;
//
//void __fastcall idDebugHUDLocal_RenderHook(__int64 idDebugHudAddr_a1, __int64 idRenderModelGuiAddr_a2) {
//
//	
//	/*if (g_isDebugHudEnabled && PlayerStateChecker::isPlaying()) {
//		debugHud.showMaterial(idRenderModelGuiAddr_a2);
//	}*/
//
//	//ObjectLocator::acquire_idDebugHUDAddr(idDebugHudAddr_a1);
//	//ObjectLocator::acquire_DebugHud_idRenderModelGuiAddr(idRenderModelGuiAddr_a2);
//	//debugHud.acquirePtrs(gui_a1, x_a2);
//
//
//	 
//	//? 24/3/23: this is the one you want to uncomment for the final version of this mod:
//	//debugHud.testCrosshairObject(); 
//	
//
//	//! using this at the exultia bridge will definitely lower performance like 102 fps insteae of 115
//	//debugHud.testDraw();
//
//	
//	//debugHud.testDraw();
//	//? this doesn't fixed the crash when going from loading menu <=> loading game
//	/*if (debugHud.isRenderAllowedTest) {
//		debugHud.testDraw(g_isCrossHairTest);
//	}*/
//	//debugHud.drawBox(g_isCrossHairTest);
//	//debugHud.debugGetMaterial();
//
//
//
//	return pidDebugHUDLocal_Render(idDebugHudAddr_a1, idRenderModelGuiAddr_a2);
//}


//! this func is trigger whether perf metrics is enabled or not in the settings so it's better than 48FE40
//! void **__fastcall showPerfMetricsSmth_48E580(__int64 a1, char a2)
//typedef void** (__fastcall* showPerfMetricsSmth)(__int64 a1, char a2);
//showPerfMetricsSmth pshowPerfMetricsSmth = nullptr;
//showPerfMetricsSmth pshowPerfMetricsSmthTarget;
//
//void** __fastcall showPerfMetricsSmthHook(__int64 idConsoleLocal, char a2){
//
//	ObjectLocator::acquire_idConsoleLocal(idConsoleLocal);
//
//	return pshowPerfMetricsSmth(idConsoleLocal, a2);
//}




//? not using this anymore cause it's not trigger if user does not use perf metrics.
//! this func is triggered when game is about to print performance metrics is it's enabled.
//! char __fastcall GetPerfMetricsStr_Smth_48FE40(__int64 idConsoleLocal, __int64 x_a2, float *y_a3)
typedef char(__fastcall* GetPerfMetricsStr)(__int64 idConsoleLocal, __int64 a2, float* a3);
GetPerfMetricsStr pGetPerfMetricsStr = nullptr;
GetPerfMetricsStr pGetPerfMetricsStrTarget;

char __fastcall GetPerfMetricsStrHook(__int64 idConsoleLocal, __int64 a2, float* a3) {

	//ObjectLocator::acquire_idConsoleLocal_And_idRenderModelGuiAddr(idConsoleLocal); //! modelgui ptr at gui_a1 + 0xD8

	//idRenderModelGui::isGetPerfMetricsStrTriggered = 1;

	//logInfo("debug bookmark 0");

	//! Not using this anymore:
	// triggering rendering of string first so user can still see framerate
	//id_ConsoleLocal.raiseRenderDrawStringFlag(); //! this will also reset most data in id_ConsoleLocal

	//! if GetPerfMetricsStrHook has been called we should now render the crosshair and other stretched pics
	//id_ConsoleLocal.setRenderStretchedPicFlag(true);

	//return 1; <= this doesn't reduce perf issue.

	//! i don't think this init smth would help even though i didn't test it cause it's a pain in the but to implement
	/*consoleLocal.initSmth(idConsoleLocal + 0x61E7A8, );
	consoleLocal.initSmth(idConsoleLocal + 0x61E7C8);*/

	//consoleLocal.testDraw();

	//consoleLocal.testCrosshairObject();
	//consoleLocal.testDraw();

	//return 1; // <= this doesn't reduce perf issue.


	return pGetPerfMetricsStr(idConsoleLocal, a2, a3);
}





//! void __fastcall RenderShape_4FDD30(__int64 gui_a1, __int64 x_a2, __int64 y_a3, __int64 text_a4, float *idColor_a5, float *a6)
//typedef void (__fastcall* RenderShape)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, float* a5, float* a6);
//RenderShape pRenderShape = nullptr;
//RenderShape pRenderShapeTarget;
//
//void __fastcall RenderShapeHook(__int64 a1, __int64 a2, __int64 a3, __int64 a4, float* a5, float* a6) {
//
//	/*if ((PlayerStateChecker::isPlaying())) {
//		if (swfDebug.isHudSwf(a1, swfDebug.swfWeaponinfoName)) {
//			swfDebug.logSwfHudElementInfos(a2, a2, a3, a4, a5, a6, swfDebug.swfWeaponinfoName);
//		}
//
//	}*/	
//
//	//? this actually works to only show the text of health and armor and rad suit and i suppose oxygen level.
//	/*if (swfHud.isHealthHud(a1)) {
//		return;
//	}*/
//
//	//? this works:
//	/*if (swfHud.isBloodPunchHud(a1)) {
//		return;
//	}*/
//
//	//swfDebug.changeEquipmentArrowColor(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//
//	//? this works and will will act only if gui_a1 is a swfWeaponinfoName
//	//swfHud.OverideEquipmentArrowColor(a1, a3, a4, a6);
//
//	
//	//? this works and will act only if gui_a1 is a swfBloodPunchName
//	//swfHud.OverrideBloodPunchIconColor(a1, a3, a4, a6);
//
//	/*if (swfHud.isEquipmentHud(gui_a1)) {
//		swfHud.OverideEquipmentArrowColor(gui_a1, y_a3, text_a4, idColor_a5, a6);
//		return pRenderShape(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//	}*/
//	
//
//		//swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfWeaponinfoName);
//
//		//if (*(float*)(idColor_a5 + 4) > 1780.0f) { //? temp way to decluter debug log
//		//	swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfWeaponinfoName);
//		//}
//		
//
//	//	//if (*(float*)(idColor_a5 + 4) > 1.0f) { //? temp way to decluter debug log
//	//	//	swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfWeaponinfoName);
//	//	//}
//
//	//	//swfDebug.OverideEquipmentArrowAndBarColors(gui_a1, text_a4, idColor_a5);
//	//	
//
//	//	return pRenderShape(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//	//}
//
//
//	//return;
//
//	//debug.modifyCrosshairColor(gui_a1, text_a4, idColor_a5);
//
//
//	//! could not do anything interesting with race car hud:
//	//if (swfDebug.isHudSwf(gui_a1, swfDebug.swfRaceCarHudinfoName)) {
//	//	swfDebug.modifyRaceCarHud(gui_a1, x_a2, y_a3, text_a4, idColor_a5); //! this doesn't work we can not change Y position.
//
//	//	//swfDebug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, swfDebug.swfRaceCarHudinfoName);
//	//	//swfDebug.modifyCrosshairColor(gui_a1, text_a4, idColor_a5);
//	//	return pRenderShape(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//	//}
//
//	
//	//return;
//
//	/*if (y_a3 == 0x1F73F0525C0) {
//		return;
//	}*/
//	
//	//debug.logRaceHudeInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//	//debug.modifyHudReticleVals(gui_a1, x_a2, text_a4); // this works aside from the xy change
//	//debug.modifyUnknown(gui_a1, y_a3); 
//	//debug.logHudReticleInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//	//debug.log_SWF_Data(gui_a1);
//	//debug.OverideEquipmentArrowAndBarColors(gui_a1, text_a4, idColor_a5);
//	//debug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, debug.swfReticuleName);
//	//debug.logSwfHudElementInfos(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6, debug.swfWeaponinfoName);
//	
//	//debug.saveHudReticleSwfAddr(gui_a1);
//	//debug.GetColorInfoFromRenderShape_Smth_4FDD30(text_a4);
//
//	//debug.saveRenderShapeidDeclSWFptr(gui_a1);
//
//	return pRenderShape(a1, a2, a3, a4, a5, a6);
//}


//! this func does calculation on the renderModelgui which is going to render the hud so let's try to use it:
//! void __fastcall Calls_idSWF_Render_1C09690(__int64 gui_a1, __int64 x_a2, __int64 *y_a3, char text_a4, char idColor_a5, char a6)
//typedef void(__fastcall* idSWF_Render_Caller)(__int64 gui_a1, __int64 x_a2, __int64* y_a3, char text_a4, char idColor_a5, char a6);
//idSWF_Render_Caller pidSWF_Render_Caller = nullptr;
//idSWF_Render_Caller pidSWF_Render_CallerTarget;
//
//void __fastcall idSWF_Render_CallerHook(__int64 gui_a1, __int64 x_a2, __int64* y_a3, char text_a4, char idColor_a5, char a6) {
//
//	//ObjectLocator::acquire_idSWF_idRenderModelGuiAddr(gui_a1);
//	
//	//? 1/2 the render gui Addr will be null, i'll try to stick with the render gui addr from idConsole
//	//ObjectLocator::acquire_idSWF_ATL_idRenderModelGuiAddr(x_a2);
//
//	//debug.crosshairTest(); // this doesn't work it draws nothing and huge perf impact
//
//	return pidSWF_Render_Caller(gui_a1, x_a2, y_a3, text_a4, idColor_a5, a6);
//}


//! trying to get material name so we can change color for elements we want
//! void __fastcall renderSWF_Smth_4FCF80(__int64 idDeclSWF_Ptr_a1,__int64 x_a2,float* y_a3,float* text_a4,__int64 idMaterial2_a5,unsigned int a6,char scale_a7)
//typedef void(__fastcall* renderSWF)(__int64 idDeclSWF_Ptr_a1, __int64 a2, float* a3, float* a4, __int64 idMaterial2_a5, unsigned int a6, char a7);
//renderSWF prenderSWF = nullptr;
//renderSWF prenderSWFTarget;
//
//void __fastcall renderSWFHook(__int64 idDeclSWF_Ptr_a1, __int64 a2, float* a3, float* a4, __int64 idMaterial2_a5, unsigned int a6, char a7) {
//
//	//? the matr here will always be stencil something, never grenade, flame or anything like that...
//	/*if (PlayerStateChecker::isPlaying()) {
//	
//		swfDebug.log_renderSWF_Smth_4FCF80_MatrName(idMaterial2_a5);
//
//	}*/
//	return prenderSWF(idDeclSWF_Ptr_a1, a2, a3, a4, idMaterial2_a5, a6, a7);
//}









//! void __fastcall idRenderModelGui::DrawStretchPic_498ED0(__int64 gui_a1,float x_a2,float y_a3,float text_a4,float idColor_a5,float a6,float scale_a7,float a8,float a9,float a10,__int64 a11)
//typedef void(__fastcall* idRenderModelGui_DrawStretchPic_498ED0)(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 a11);
//idRenderModelGui_DrawStretchPic_498ED0 pidRenderModelGui_DrawStretchPic_498ED0 = nullptr;
//idRenderModelGui_DrawStretchPic_498ED0 pidRenderModelGui_DrawStretchPic_498ED0Target;
//
////! guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr
//void __fastcall idRenderModelGui_DrawStretchPic_498ED0Hook(__int64 a1, float x, float y, float z, float w, float h, float a7, float a8, float a9, float a10, __int64 matr) {
//
//	//? apparently uncommenting this will make the idConsole totally white, haven't figured out why.
//	//if (id_ConsoleLocal.isConsoleOpened()) {
//	//	id_ConsoleLocal.setFont(idFontHash::defaultCourrierF8);
//	//	*(unsigned int*)(gui_a1 + 0x4D0) = colorWhite.PackColor(); //! set pic color	
//	//	//if (*(unsigned int*)(gui_a1 + 0x4D0) != colorWhite.PackColor()) {
//	//	//	*(unsigned int*)(gui_a1 + 0x4D0) = colorWhite.PackColor(); //! set pic color	
//	//	//}		
//	//	return pidRenderModelGui_DrawStretchPic_498ED0(gui_a1, x, y, z, w, h, scale_a7, a8, a9, a10, matr);
//	//}
//
//
//
//	//?
//	//? 7/3/23 0:42 this is what you have to uncomment when you're done with your test of DrawStretchPic hook for g_material test
//	//! by adding this if i was able to render more than the crosshair on the screen with perf metrics set to High:
//	//if (PlayerStateChecker::isPlaying() && !id_ConsoleLocal.isRenderStretchedPicFlag() && !id_ConsoleLocal.isRenderStringFlag() && !id_ConsoleLocal.isConsoleOpened()) {
//
//	//	*(unsigned int*)(a1 + 0x4D0) = colorInvisible.PackColor(); //! set pic color	
//	//	return pidRenderModelGui_DrawStretchPic_498ED0(a1, x, y, z, w, h, a7, a8, a9, a10, matr);
//	//}
//
//	////! draw crosshair
//	//if (PlayerStateChecker::isPlaying() && id_ConsoleLocal.isRenderStretchedPicFlag() ) {
//
//	//	auto args = id_ConsoleLocal.getdrawStretchHookPicArgs();		
//
//	//	*(unsigned int*)(a1 + 0x4D0) = args.packedColor; //! set pic color	
//	//	return pidRenderModelGui_DrawStretchPic_498ED0(a1, args.x, args.y, z, args.w, args.h, a7, a8, a9, a10, args.material);
//	//}
//	
//	return pidRenderModelGui_DrawStretchPic_498ED0(a1, x, y, z, w, h, a7, a8, a9, a10, matr);
//			
//}


//! this is used to hopefully intercet menus state, gamestate, game initialized and things like that
//! void __fastcall idBroadcastManager::ReleaseBroadcastEvent_4899C0(__int64 gui_a1, __int64 x_a2, __int64 y_a3)
//typedef void(__fastcall* idBroadcastManager_ReleaseBroadcastEvent)(__int64 a1, __int64 a2, __int64 a3);
//idBroadcastManager_ReleaseBroadcastEvent pidBroadcastManager_ReleaseBroadcastEvent = nullptr;
//idBroadcastManager_ReleaseBroadcastEvent pidBroadcastManager_ReleaseBroadcastEventTarget;
//
//void __fastcall idBroadcastManager_ReleaseBroadcastEventHook(__int64 a1, __int64 a2, __int64 a3) {
//
//	//! Handle events
//	idHudEventManager::onReleasedBroadcastEvent(a3);
//
//
//	return pidBroadcastManager_ReleaseBroadcastEvent(a1, a2, a3);
//}





//? BAK of WIP convertIdDeclUIColorToidColorHook:
////! this will hopefully let us change the color of ui elements at will
////! __int64 __fastcall convertIdDeclUIColorToidColor_Mb_4D5AF0(__int64 idDeclUIColor_a1, __int64 idColor_a2, int y_a3)
//typedef idColor* (__fastcall* convertIdDeclUIColorToidColor)(__int64 idDeclUIColor_a1, idColor* idColor_a2, int colorId_a3);
//convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColor = nullptr;
//convertIdDeclUIColorToidColor pconvertIdDeclUIColorToidColorTarget;
//
//idColor* __fastcall convertIdDeclUIColorToidColorHook(__int64 idDeclUIColor_a1, idColor* idColorPtr_a2, int colorId_a3) { //! there is a bak of the old version of this hook in debug.h
//
//	//! by acequiring this address we always know where the color of a specifi elelment on the hud is. this is useful when user changes profile cause idDeclUIColor_a1 will change in that case and there are many color profiles.
//	GameHudColorsManager::acquireIdDeclUIColorAddr(idDeclUIColor_a1);
//
//
//	if (colorId_a3 == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT) {
//		return pconvertIdDeclUIColorToidColor(idDeclUIColor_a1, idColorPtr_a2, colorId_a3);
//	}
//
//	//! here in we check if colorId_a3> is not default (by using > and not >=) and if it's in bound:
//	if ((colorId_a3 > UserColorSet::getCustomNamedColorsOffsetStart()) && (colorId_a3 < swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_MAX)) {
//		*idColorPtr_a2 = GameHudColorsManager::getCustomIdColor(colorId_a3);
//	}
//
//
//	if (colorId_a3 == UserColorSet::getAbsoluteOrangeFlagColorId()) {
//		logInfo("*idColorPtr_a2 = colorOrangeNonConstTest triggered...");
//
//
//		idColor colorOrangeLocal = idColor{ 1.00f, 0.50f, 0.00f, 1.00f };
//
//		*idColorPtr_a2 = colorOrangeLocal;
//		//*idColorPtr_a2 = colorOrangeNonConstTest; //! this works !!!!!!!!!!!!!
//		return idColorPtr_a2; //? important otherwise it doesn't work
//
//	}
//
//
//	return pconvertIdDeclUIColorToidColor(idDeclUIColor_a1, idColorPtr_a2, colorId_a3);
//}



