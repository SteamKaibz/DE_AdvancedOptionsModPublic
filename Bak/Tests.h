////#include "../DE/idDeclWeapon.h"
//#include "../DE/ObjectLocator.h"
////#include "../DE/idWeapon.h"
//#include "../DE/MemHelper.h"
//
//
//
//
//
//
//
//
//
//void debugDeclWeapons() {
//	bool isChanged = false;
//
//	static __int64 debugLastidWeaponAddr = -1;
//	static idDeclWeapon* debugLastidDeclWeaponPtr = 0;
//	static idDeclWeapon* debugLastidDeclWeaponOveride1Ptr = 0;
//	static idDeclWeapon* debugLastidDeclWeaponOveride2Ptr = 0;
//
//	__int64 idWeaponAddr = ObjectLocator::getCurrentIdWeaponAddr();
//	if (MemHelper::isBadReadPtr((void*)idWeaponAddr)) {
//		logErr("getCurrentIdWeaponAddr: idWeaponAddr is bad ptr: %p returning", (void*)idWeaponAddr);
//		return;
//	}
//
//	idWeapon* idWeaponObj = (idWeapon*)idWeaponAddr;
//
//	//! this will never be nullptr afaik this the base version of the weapon without any mods
//	idDeclWeapon* declWeaponPtr = idWeaponObj->getDeclWeaponOverride1();
//
//	//! this is the decl weapon for mod 
//	idDeclWeapon* declWeaponOveride1Ptr = idWeaponObj->getDeclWeaponOverride1();
//
//	//! this is the decl weapon for mod but it seems to generally be used when the weapon has some kind of zooming ability for ex for the shotgun both mods get overidden here but nothing happen at overide 1
//	idDeclWeapon* declWeaponOveride2Ptr = idWeaponObj->getDeclWeaponOverride2();
//
//
//	if (idWeaponAddr != debugLastidWeaponAddr) {
//		debugLastidWeaponAddr = idWeaponAddr;
//		logInfo("idWeaponAddr has changed");
//		isChanged = true;
//	}
//
//	if (declWeaponPtr != debugLastidDeclWeaponPtr) {
//		debugLastidDeclWeaponPtr = declWeaponPtr;
//		logInfo("declWeaponPtr has changed");
//		isChanged = true;
//	}
//
//	if (declWeaponOveride1Ptr != debugLastidDeclWeaponOveride1Ptr) {
//		debugLastidDeclWeaponOveride1Ptr = declWeaponOveride1Ptr;
//		logInfo("declWeaponOveride1Ptr has changed");
//		isChanged = true;
//	}
//
//	if (declWeaponOveride2Ptr != debugLastidDeclWeaponOveride2Ptr) {
//		debugLastidDeclWeaponOveride2Ptr = declWeaponOveride2Ptr;
//		logInfo("declWeaponOveride2Ptr has changed");
//		isChanged = true;
//	}
//
//	if (isChanged) {
//		idWeaponObj->print();
//	}
//}
//
////? from my test there is now way to figure out the actual slot see the log below this func. Just the fact the Har weapon slot found is 3 makes it unusable.
//void debugCurrentWeaponSlot() {
//	bool isChanged = false;
//
//	static __int64 debugLastidWeaponAddr = -1;
//	static idDeclWeapon* debugLastidDeclWeaponPtr = 0;
//	static idDeclWeapon* debugLastidDeclWeaponOveride1Ptr = 0;
//	static idDeclWeapon* debugLastidDeclWeaponOveride2Ptr = 0;
//
//	static int lastWeapSlot = -2;
//
//	__int64 idWeaponAddr = ObjectLocator::getCurrentIdWeaponAddr();
//	if (MemHelper::isBadReadPtr((void*)idWeaponAddr)) {
//		logErr("debugCurrentWeaponSlot: idWeaponAddr is bad ptr: %p returning", (void*)idWeaponAddr);
//		return;
//	}
//
//	idWeapon* idWeaponObj = (idWeapon*)idWeaponAddr;
//
//	//! this will never be nullptr afaik this the base version of the weapon without any mods
//	idDeclWeapon* declWeaponPtr = idWeaponObj->getDeclWeaponOverride1();
//
//	//! this is the decl weapon for mod 
//	idDeclWeapon* declWeaponOveride1Ptr = idWeaponObj->getDeclWeaponOverride1();
//
//	//! this is the decl weapon for mod but it seems to generally be used when the weapon has some kind of zooming ability for ex for the shotgun both mods get overidden here but nothing happen at overide 1
//	idDeclWeapon* declWeaponOveride2Ptr = idWeaponObj->getDeclWeaponOverride2();
//
//
//	if (idWeaponAddr != debugLastidWeaponAddr) {
//		debugLastidWeaponAddr = idWeaponAddr;
//		logInfo("idWeaponAddr has changed");
//
//
//		if (!MemHelper::isBadReadPtr(declWeaponPtr)) {
//			logInfo("declWeaponPtr weap slot: %d", declWeaponPtr->weaponSlot);
//		}
//		if (!MemHelper::isBadReadPtr(declWeaponOveride1Ptr)) {
//			logInfo("declWeaponOveride1Ptr weap slot: %d", declWeaponOveride1Ptr->weaponSlot);
//
//		}
//		if (!MemHelper::isBadReadPtr(declWeaponOveride2Ptr)) {
//			logInfo("declWeaponOveride2Ptr weap slot: %d", declWeaponOveride2Ptr->weaponSlot);
//
//		}
//
//
//		isChanged = true;
//	}
//
//	if (declWeaponPtr != debugLastidDeclWeaponPtr) {
//		debugLastidDeclWeaponPtr = declWeaponPtr;
//		//logInfo("declWeaponPtr has changed");
//		isChanged = true;
//	}
//
//	if (declWeaponOveride1Ptr != debugLastidDeclWeaponOveride1Ptr) {
//		debugLastidDeclWeaponOveride1Ptr = declWeaponOveride1Ptr;
//		//logInfo("declWeaponOveride1Ptr has changed");
//		isChanged = true;
//	}
//
//	if (declWeaponOveride2Ptr != debugLastidDeclWeaponOveride2Ptr) {
//		debugLastidDeclWeaponOveride2Ptr = declWeaponOveride2Ptr;
//		//logInfo("declWeaponOveride2Ptr has changed");
//		isChanged = true;
//	}
//
//	if (isChanged) {
//		idWeaponObj->print();
//	}
//
//}
//
//
///*
//01:50:31.193         ObjectLocator.h:51    INFO| currentIdWeaponAddr has changed to: 0000016243574010
//01:50:31.198              idPlayer.h:383   INFO| debugCurrentIdDeclWeaponAddr: idDeclWeaponAddr: had changed to 000001619F32B080
//01:50:31.272                 Tests.h:94    INFO| idWeaponAddr has changed
//01:50:31.272                 Tests.h:98    INFO| declWeaponPtr weap slot: 5
//01:50:31.273                 Tests.h:101   INFO| declWeaponOveride1Ptr weap slot: 5
//01:50:31.273                 Tests.h:105   INFO| declWeaponOveride2Ptr weap slot: 5
//01:50:31.273              idWeapon.h:52    INFO| idWeaponAddr: 0000016243574010
//01:50:31.274              idWeapon.h:54    INFO| idDeclWeapon:
//01:50:31.274          idDeclWeapon.h:74    INFO| idDeclWeapon: at address: 000001619F324450 has name: weapon/player/double_barrel resourceID: E1FC691592B659A1
//01:50:31.274              idWeapon.h:56    INFO| idDeclWeaponOverride1:
//01:50:31.275          idDeclWeapon.h:74    INFO| idDeclWeapon: at address: 000001619F32B080 has name: weapon/player/double_barrel_primary_lockon resourceID: D22740B4A48EB785
//01:50:31.275              idWeapon.h:58    INFO| idDeclWeaponOverride2:
//01:50:31.275          idDeclWeapon.h:74    INFO| idDeclWeapon: at address: 000001619F328C70 has name: weapon/player/double_barrel_meat_hook resourceID: D5DBD90A4F5DC108
//01:50:35.818         ObjectLocator.h:51    INFO| currentIdWeaponAddr has changed to: 000001623D00A160
//01:50:35.822              idPlayer.h:383   INFO| debugCurrentIdDeclWeaponAddr: idDeclWeaponAddr: had changed to 000001619F0BEA90
//01:50:35.864                 Tests.h:94    INFO| idWeaponAddr has changed
//01:50:35.864                 Tests.h:105   INFO| declWeaponOveride2Ptr weap slot: 3
//01:50:35.865              idWeapon.h:52    INFO| idWeaponAddr: 000001623D00A160
//01:50:35.865              idWeapon.h:54    INFO| idDeclWeapon:
//01:50:35.866          idDeclWeapon.h:74    INFO| idDeclWeapon: at address: 000001619F0BEA90 has name: weapon/player/heavy_cannon resourceID: B7820666379C5A35
//01:50:35.866              idWeapon.h:56    INFO| idDeclWeaponOverride1:
//01:50:35.866              idWeapon.h:58    INFO| idDeclWeaponOverride2:
//01:50:35.867          idDeclWeapon.h:74    INFO| idDeclWeapon: at address: 000001619F0C56C0 has name: weapon/player/heavy_cannon_bolt_action resourceID: 5018A62776EFD1F9
//01:50:35.867        WeaponSettings.h:314   INFO| WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: 000001619F0C56C0 with name: weapon/player/heavy_cannon_bolt_action is having its sensitivity_scale_controller set changed to: 1.00
//01:50:42.392    PlayerStateChecker.h:40    INFO| print: PlayerState is changing from inGameWithHudOn to inGameWithHudOff
//
//
//*/
//
//
//
//
////std::cout << (*(DWORD*)(mem.PatternScan("BlackDesert64.exe", idProcessInputFuncSig)) << std::endl;
//	//? Pattern Scan TEST doesnt work:
//	//const char* signature = "\x40\x55\x53\x56\x48\x8D\x6C\x24\x90\x48\x81\xEC\x70\x01\x00\x00\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x33\xC4\x48\x89\x45\x48";
//	////const char* signature = "\xA3\x00\x00\x00\x00\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\x6A\x00";
//	//const char* mask = "xxxxxxxxxxxxxxxxxxx????xxxxxxx";
//	////const char* mask = "x????x??????????x????xx?";
//
//	//logInfo("DllHandle value is ModMain:: %p", (void*)DllHandle);
//	////std::cout << "DllHandle value is ModMain: " << reinterpret_cast<uintptr_t>(DllHandle) << std::endl;
//	//uintptr_t foundAddress = mem.FindSignaturePattern(DllHandle, mem.getModuleBaseAddr(), signature, mask); // Start address can vary
//
//	//if (foundAddress) {
//	//	logInfo("idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 Pattern found at address: %p", (void*)foundAddress);
//	//	//std::cout << "idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 Pattern found at address :: 0x" << std::hex << foundAddress << std::endl;
//	//}
//	//else {
//	//	logInfo("idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 FAILED TO FIND ADDRESS");
//	//	//std::cerr << "idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 Pattern not found." << std::endl;
//	//}
//
//	//idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 sig
//	/*const BYTE myPattern[] = {
//				0x40, 0x55, 0x53, 0x56, 0x48, 0x8D, 0x6C, 0x24, 0x90, 0x48, 0x81, 0xEC, 0x70, 0x01, 0x00, 0x00,
//				0x48, 0x8B, 0x05, 0x00, 0x00, 0x00, 0x00,
//				0x48, 0x33, 0xC4, 0x48, 0x89, 0x45, 0x48
//	};*/
//
//
//	//mem.ScanMemoryPattern(myPattern, sizeof(myPattern));
//
//
//
//
//
//
//
//
////#include <windows.h>
////#include <iostream>
////
////// Function to search for a signature pattern in a process's memory
////uintptr_t FindSignaturePattern(HANDLE hProcess, uintptr_t startAddress, const char* signature, const char* mask) {
////    SIZE_T bytesRead;
////    MEMORY_BASIC_INFORMATION mbi;
////    char buffer[1024];
////
////    // Iterate through memory regions of the process
////    while (VirtualQueryEx(hProcess, (LPCVOID)startAddress, &mbi, sizeof(MEMORY_BASIC_INFORMATION))) {
////        if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS) {
////            // Read memory in the current region
////            if (ReadProcessMemory(hProcess, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead)) {
////                for (SIZE_T i = 0; i < bytesRead; i++) {
////                    bool found = true;
////                    for (SIZE_T j = 0; mask[j]; j++) {
////                        if (mask[j] != '?' && buffer[i + j] != signature[j]) {
////                            found = false;
////                            break;
////                        }
////                    }
////                    if (found) {
////                        // Calculate the address where the signature was found
////                        return (uintptr_t)mbi.BaseAddress + i;
////                    }
////                }
////            }
////        }
////        // Move to the next memory region
////        startAddress = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
////    }
////
////    return 0; // Signature not found
////}
////
////int main() {
////    // Assuming you already have a handle to the target process
////    HANDLE hProcess = ...;
////
////    // Signature and mask for your pattern
////    //? Sig for idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0
////    const char* signature = "\x40\x55\x53\x56\x48\x8D\x6C\x24\x90\x48\x81\xEC\x70\x01\x00\x00\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x33\xC4\x48\x89\x45\x48";
////    //const char* signature = "\xA3\x00\x00\x00\x00\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\x6A\x00";
////    const char* mask = "xxxxxxxxxxxxxxxxxxx????xxxxxxx";
////    //const char* mask = "x????x??????????x????xx?";
////
////    uintptr_t foundAddress = FindSignaturePattern(hProcess, 0x00400000, signature, mask); // Start address can vary
////
////    if (foundAddress) {
////        std::cout << "idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 Pattern found at address: 0x" << std::hex << foundAddress << std::endl;
////    }
////    else {
////        std::cerr << "idPlayer__ProcessInput_ServerAndClient_Local_1ABBDD0 Pattern not found." << std::endl;
////    }
////
////    // Close the process handle when done
////    CloseHandle(hProcess);
////
////    return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
////#pragma once
////
////#include <Windows.h>
////#include "MemHelper.h"
////#include "idColor.h"
////#include "Config.h"
////#include "ObjectLocator.h"
////#include "Rectangle.h"
////#include "Crosshair.h"
////#include "Game.h"
//////#include "HudElements.h"
////#include "../Hud/HudElements.h"
////
////
////class idRenderModelGui
////{
////private:
////	//__int64 m_idRenderModelGuiPtr = 0;
////
////
////	typedef __int64(__fastcall* idRenderModelGui_DrawString)(__int64 a1, float a2, float a3, const char* a4, __int64 a5, char a6, float a7);
////	static idRenderModelGui_DrawString m_pidRenderModelGui_DrawString;
////	//idRenderModelGui_DrawString m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x6239F0));
////
////	typedef void(__fastcall* idRenderModelGui_DrawStretchPic)(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 a11);
////	static idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic;
////	//idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(MemHelper::getFuncAddr(0x498ED0));
////
////	static float s1;
////	static float t1;
////	static float s2;
////	static float t2;
////
////
////public:
////
////
////	static bool isDrawStringTriggered;
////
////	static int DrawStringCounter;
////
////	static bool isGetPerfMetricsStrTriggered;
////
////	static int DrawStretchPic_498ED0_Counter;
////
////
////
////
////	static float getScreenWidth() {
////
////		/*if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
////			return 0;
////		}*/
////		return ((float)(*(int*)(MemHelper::getAddr(0x39AF8BC))));
////		//return ((float)(*(int*)(m_idRenderModelGuiPtr + 0x4568)));
////	}
////
////	static float getScreenHeigth() {
////		return ((float)(*(int*)(MemHelper::getAddr(0x39AF8C0))));
////		/*if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
////			return 0;
////		}
////		return ((float)(*(int*)(m_idRenderModelGuiPtr + 0x456C)));*/
////	}
////
////
////
////	
////
////	
////
////
////	static unsigned int getCurrentPackedColor(__int64 idRenderModelGuiAdr) {
////		if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdr)) {
////			logErr("getCurrentPackedColor: idRenderModelGuiAdrr is bad ptr returning colorWhite.PackColor()");
////			return colorWhite.PackColor();
////		}
////		return 	*(unsigned int*)(idRenderModelGuiAdr + 0x4D0);
////	}
////
////
////	static void setColor(__int64 idRenderModelGuiAdrr, const idColor& idColor) {
////		//__int64 idRenderModelGuiAdrr = ObjectLocator::get__DebugHud_idRenderModelGuiAddr();
////		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr();
////		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idSWF_idRenderModelGuiAddr();
////
////		if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
////			logErr("setColor: can not set color cause idRenderModelGuiAdrr is bad ptr");
////			return;
////		}
////		*(unsigned int*)(idRenderModelGuiAdrr + 0x4D0) = idColor.PackColor();
////	}
////
////	
////
////	static void drawDrawStretchPicBounds(__int64 idRenderModelGuiAdrr, idVec4 bounds, __int64 matPtr) {
////		//__int64 matPtr = MaterialLib::getRocketIconMtr();
////		//__int64 matPtr = MaterialLib::getWhite();
////		if (MemHelper::isBadReadPtr((void*)matPtr)) return;
////		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, bounds.x, bounds.y, 0.0, bounds.w, bounds.h, s1, t1, s2, t2, matPtr);
////	}
////
////	
////
////	//! this is used to inspect the materials in the MaterialLib
////	static void drawDebugMaterialCenter100x100(__int64 idRenderModelGuiAdrr, __int64 matr) {
////		setColor(idRenderModelGuiAdrr, colorWhite);
////		if (!MemHelper::isBadReadPtr((void*)matr)) {
////			//logInfo("drawDebugMaterialCenter100x100, matr is %p", (void*)matr);
////			pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, Game::getCenterX(), Game::getCenterY(), 0.0, 100, 100, s1, t1, s2, t2, matr);
////		}
////		else {
////			logErr("drawDebugMaterialCenter100x100: idRenderModelGuiAdrr is bad ptr: %p", (void*)matr);
////		}
////	}
////
////	static void drawDebugRect(__int64 idRenderModelGuiAdrr, idVec4 coords, idColor color) {
////		setColor(idRenderModelGuiAdrr, color);
////		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, coords.x, coords.y, 0.0, coords.w, coords.h, s1, t1, s2, t2, MaterialLib::getWhite());
////		/*else {
////			logErr("drawDebugRect: idRenderModelGuiAdrr is bad ptr: %p", (void*)matr);
////		}*/
////	}
////
////	static void drawIceNadeMatrElement(__int64 idRenderModelGuiAdrr, const idVec4 coords, const idColor& idColor, __int64 matr) {
////		/*unsigned int currentPackedColor = getCurrentPackedColor(idRenderModelGuiAdrr);*/
////		setColor(idRenderModelGuiAdrr, idColor);
////		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, coords.x, coords.y, 0.0, coords.w, coords.h, s1, t1, s2, t2, matr);
////	}
////
////	//! will draw the outline or the fill of a pip
////	static void drawPipRect(__int64 idRenderModelGuiAdrr, const idVec4 coords, const idColor& idColor) {
////		/*unsigned int currentPackedColor = getCurrentPackedColor(idRenderModelGuiAdrr);*/
////		setColor(idRenderModelGuiAdrr, idColor);
////		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, coords.x, coords.y, 0.0, coords.w, coords.h, s1, t1, s2, t2, MaterialLib::getWhite());
////	}
////
////	//! pic like nade icon which is not inverted on the x or y axis
////	void drawStretchedPic(__int64 idRenderModelGuiAdrr, idVec4 coords, const idColor& idColor, __int64 material) {
////		setColor(idRenderModelGuiAdrr, idColor);
////		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, coords.x, coords.y, 0.0, coords.w, coords.h, s1, t1, s2, t2, material);
////	}
////
////	//! will draw the pip and its outline
////	static void drawHudPip(__int64 idRenderModelGuiAdrr, const HudPip& hudPip) {
////		drawPipRect(idRenderModelGuiAdrr, hudPip.pipOutlineCoordsVec4, hudPip.outlineColor);
////		drawPipRect(idRenderModelGuiAdrr, hudPip.pipFillCoordsVec4, hudPip.fillColor);
////	}
////
////	
////
////	static void drawHudIcon(__int64 idRenderModelGuiAdrr, const HudIcon& hudIcon) {
////		setColor(idRenderModelGuiAdrr, hudIcon.color);
////		
////		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, hudIcon.iconContainerCoordsVec4.x, hudIcon.iconContainerCoordsVec4.y, 0.0, hudIcon.iconContainerCoordsVec4.w, hudIcon.iconContainerCoordsVec4.h, s1, t1, s2, t2, MaterialLib::get(hudIcon.id));
////		
////	}
////
////	static void drawHudText(__int64 idRenderModelGuiAdrr, const HudText& hudText) {
////		m_pidRenderModelGui_DrawString(idRenderModelGuiAdrr, hudText.coordinatesVec2.x, hudText.coordinatesVec2.y, hudText.text.c_str(), (__int64)&hudText.color, 0, hudText.fontScale);
////	}
////
////	
////
////	static void drawCustomIceNadeSprite(__int64 idRenderModelGuiAdrr, const HudEquipmentIce& iceSprite) {
////		drawIceNadeMatrElement(idRenderModelGuiAdrr, iceSprite.fillCoordsVec4, iceSprite.backgroundColor, MaterialLib::getIceNadeBackgroundMtr());
////		drawIceNadeMatrElement(idRenderModelGuiAdrr, iceSprite.borderCoordsVec4, iceSprite.backgroundColor, MaterialLib::getIceNadeBorderMtr());
////		drawIceNadeMatrElement(idRenderModelGuiAdrr, iceSprite.iconCoordsVec4, iceSprite.iconColor, MaterialLib::getIceGrenadeMtr());
////		if (iceSprite.isOnCoolDown()) {
////			drawHudText(idRenderModelGuiAdrr, iceSprite.hudCoolDownText);
////		}
////	}
////
////	//! text + ammo icon
////	static void drawCustomAmmoSprite(__int64 idRenderModelGuiAdrr, const HudAmmo& hudAmmo) {
////		//hudAmmo.print();
////
////
////		setColor(idRenderModelGuiAdrr, hudAmmo.hudAmmoText.color);
////		drawHudText(idRenderModelGuiAdrr, hudAmmo.hudAmmoText);
////		setColor(idRenderModelGuiAdrr, hudAmmo.ammoIcon.color);
////		drawHudIcon(idRenderModelGuiAdrr, hudAmmo.ammoIcon);
////		//drawHudIcon(idRenderModelGuiAdrr, hudAmmo.ammoIcon, hudAmmo.id);		
////
////	}
////
////	//! all ammos text + icons
////	static void drawCustomAmmosHud(__int64 idRenderModelGuiAdrr, const HudAmmos& hudAmmos) {
////		//logInfo("drawCustomAmmosHud hudAmmos.hudAmmosVec.size(): %zu", hudAmmos.hudAmmosVec.size());
////		//! size is 4 but for some reason it doesn't render anything atm
////		for (size_t i = 0; i < hudAmmos.hudAmmosVec.size(); i++)
////		{
////			//! afaik this is not what is creating the crash
////			drawCustomAmmoSprite(idRenderModelGuiAdrr, hudAmmos.hudAmmosVec[i]);
////		}
////	}
////};
////
////idRenderModelGui::idRenderModelGui_DrawString idRenderModelGui::m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x6239F0));
////
////idRenderModelGui::idRenderModelGui_DrawStretchPic  idRenderModelGui::pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(MemHelper::getFuncAddr(0x498ED0));
////
//////! these are the value to the image is not mirores on x or y:
////float idRenderModelGui::s1 = 0.0;
////float idRenderModelGui::t1 = 0.0;
////float idRenderModelGui::s2 = 1.0;
////float idRenderModelGui::t2 = 1.0;
////
////bool idRenderModelGui::isDrawStringTriggered = false;
////bool idRenderModelGui::isGetPerfMetricsStrTriggered = false;
////int idRenderModelGui::DrawStretchPic_498ED0_Counter = 0;
////int idRenderModelGui::DrawStringCounter = 0;