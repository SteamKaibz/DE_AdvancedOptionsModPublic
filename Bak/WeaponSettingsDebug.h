//#pragma once
//
//#pragma once
//
//
//#include <Windows.h>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include<iostream>
//#include "../DE/CommonDE.h"
//#include "../DE/CustomWeapon.h"
//#include "../DE/ObjectLocator.h"
//#include "../DE/Types.h"
//#include "../DE/idWeapon.h"
//#include "../DE/idResource.h"
//#include "../IniFile/IniFileData.h"
////#include "MemHelper.h"
////#include "CustomWeapon.h"
////#include "idDeclWeapon.h"
////#include "IniFile/IniFileData.h"
//////#include "IniFileData.h"
////#include "CommonDE.h"
////#include "idInventoryManager.h"
////#include "idWeapon.h"
////#include "../Debug/Tests.h"
////#include "idResource.h"
//
//
//
///// <summary>
///// changing fov, mouse and controller sens for specific weapons, ex disable the fov and sens change for the shogun secondaries
///// </summary>
//class WeaponSettingsDebug
//{
//private:
//	//__int64 m_idWeaponPtr = 0;
//	//__int64 m_idDeclWeaponAddr = 0;
//
//	//! discarded m_isInitialized cause it'not a guarantee weapons will be overwritten for good.
//	//bool m_isInitialized = false; 
//
//	std::vector<const char*>m_customizableWeaponsNames{ g_shotGunStickiesNameIdStr , g_shotGunFullAutoNameIdStr ,g_heavyCannonBoltNameIdStr ,g_heavyCannonDetonateNameIdStr, g_balistaNameIdStr, g_balistaArbalesteNameIdStr, g_balistaDestroyerBladeNameIdStr };
//
//	uintptr_t m_idDeclWeaponStructBaseAddr = 0;
//	//lsiikdjf
//	//const unsigned int m_idDeclWeaponStructBaseAddrOffset = 0x06BE3E08; //! "DOOMEternalx64vk.exe"+06BE3E08
//	//! more offsets of other weapons in reminder file.
//	//std::vector<unsigned int>m_idDeclWeaponShotgunStickyOffsetsVec{ 0x40, 0x58, 0x0 };
//	//std::vector<unsigned int>m_idDeclWeaponShotgunFullAutoOffsetsVec{ 0x40, 0x70, 0x0 };
//	//std::vector<unsigned int>m_idDeclWeaponPrecisionBoldOffsetsVec{ 0x40, 0x298, 0x0 };
//	//std::vector<unsigned int>m_idDeclWeaponBallistaArbalesteOffsetsVec{ 0x40, 0x238, 0x0 };
//
//	//const unsigned int m_idDeclWeaponPtrOffset = 0x3708;
//	//const unsigned int m_idDeclWeaponIdOffset = 0x34;
//	//const unsigned int m_idDeclWeaponFov1_Offset = 0x1700;
//	//const unsigned int m_idDeclWeaponFov2_Offset = 0x1704;
//	//const unsigned int m_idDeclWeaponControllerSens_Offset = 0x170C;
//	//const unsigned int m_idDeclWeaponMouseSens_Offset = 0x1710;
//
//
//	CustomWeapon m_shotGunStickyDefault = CustomWeapon(g_shotGunStickiesNameIdStr, g_defaultShotGunStickyzoomedFOV, g_defaultShotGunStickyzoomedHandsFOV, g_defaultShotGunStickyControllerSens, g_defaultShotGunStickyMouseSens);
//
//	CustomWeapon m_shotGunFullAutoDefault = CustomWeapon(g_shotGunFullAutoNameIdStr, g_defaultShotGunFullAutoZoomedFov, g_defaultShotGunFullAutozoomedHandsFov, g_defaultShotGunFullAutoControllerSens, g_defaultShotGunFullAutoMouseSens);
//
//	CustomWeapon m_shotGunStickyOveride = CustomWeapon(g_shotGunStickiesNameIdStr, g_overideShotGunzoomedFOV, g_overideShotGunzoomedHandsFov, g_weaponMaxSensitivity, g_weaponMaxSensitivity);
//
//	CustomWeapon m_shotGunFullAutoOveride = CustomWeapon(g_shotGunFullAutoNameIdStr, g_overideShotGunzoomedFOV, g_overideShotGunzoomedHandsFov, g_weaponMaxSensitivity, g_weaponMaxSensitivity);
//	/*CustomWeapon m_shotGunStickyDefault = CustomWeapon(declWeaponModId::shotgunStickyBombsId, g_defaultShotGunStickyzoomedFOV, g_defaultShotGunStickyzoomedHandsFOV, g_defaultShotGunStickyControllerSens, g_defaultShotGunStickyMouseSens);
//	CustomWeapon m_shotGunFullAutoDefault = CustomWeapon(declWeaponModId::shotgunFullAutoId, g_defaultShotGunFullAutoZoomedFov, g_defaultShotGunFullAutozoomedHandsFov, g_defaultShotGunFullAutoControllerSens, g_defaultShotGunFullAutoMouseSens);
//
//	CustomWeapon m_shotGunStickyOveride = CustomWeapon(declWeaponModId::shotgunStickyBombsId, overideShotGunFov1, overideShotGunFov2, g_weaponMaxSensitivity, g_weaponMaxSensitivity);
//	CustomWeapon m_shotGunFullAutoOveride = CustomWeapon(declWeaponModId::shotgunFullAutoId, overideShotGunFov1, overideShotGunFov2, g_weaponMaxSensitivity, g_weaponMaxSensitivity);*/
//
//	std::vector<CustomWeapon>m_customWeaponsVec{};
//
//	//__int64 m_lastIdWeaponAddr = 0;
//	//__int64 m_lastIdDeclWeaponAddr = 0;
//
//
//	/// <summary>
//	/// this are the settings that only for max fov and normal sensitivity for both shotguns mods
//	/// </summary>
//	void createDefaultCustomWeapons() {
//		//m_customWeaponsVec.clear();
//
//		//LOG_F(INFO, "I'm hungry for some %.3f!", 3.14159);
//
//		m_customWeaponsVec.push_back(CustomWeapon(g_shotGunStickiesNameIdStr, g_overideShotGunzoomedFOV, g_overideShotGunzoomedHandsFov, g_weaponMaxSensitivity, g_weaponMaxSensitivity));
//
//		m_customWeaponsVec.push_back(CustomWeapon(g_shotGunFullAutoNameIdStr, g_overideShotGunzoomedFOV, g_overideShotGunzoomedHandsFov, g_weaponMaxSensitivity, g_weaponMaxSensitivity));
//
//		//! by default we don't modify arbalest and bolt settings it's up to the user to change that:
//		m_customWeaponsVec.push_back(CustomWeapon(g_heavyCannonBoltNameIdStr, g_defaultPrecisionBoltzoomedFOV, g_defaultPrecisionBoltzoomedHandsFOV, g_defaultPrecisionBoltControllerSens, g_defaultPrecisionBoltMouseSens));
//
//		m_customWeaponsVec.push_back(CustomWeapon(g_balistaArbalesteNameIdStr, g_defaultBallistaArbalestezoomedFOV, g_defaultBallistaArbalestezoomedHandsFOV, g_defaultBallistaArbalesteControllerSens, g_defaultBallistaArbalesteMouseSens));
//	}
//
//	/*void createTestCustomWeapons() {
//		m_customWeaponsVec.clear();
//
//		m_customWeaponsVec.push_back(CustomWeapon(declWeaponModId::shotgunStickyBombsId, overideShotGunFov1, overideShotGunFov2, g_weaponMaxSensitivity, g_weaponMaxSensitivity));
//		m_customWeaponsVec.push_back(CustomWeapon(declWeaponModId::shotgunFullAutoId, overideShotGunFov1, overideShotGunFov2, g_weaponMaxSensitivity, g_weaponMaxSensitivity));
//		m_customWeaponsVec.push_back(CustomWeapon(declWeaponModId::precisionBoltId, g_defaultPrecisionBoltzoomedFOV, g_defaultPrecisionBoltzoomedHandsFOV, g_defaultPrecisionBoltControllerSens, .9f));
//		m_customWeaponsVec.push_back(CustomWeapon(declWeaponModId::balistaArbalesteId, g_defaultBallistaArbalestezoomedFOV, g_defaultBallistaArbalestezoomedHandsFOV, g_defaultBallistaArbalesteControllerSens, 1.0f));
//	}*/
//
//
//
//	//! this is what we used to do to overwrite weapons like disable the zoom on the shogun stickies:
//	//bool overwriteDeclWeapon_V2(CustomWeapon& customWeapon, std::vector<InventoryItem>& declWeponsInvItemsVec) {
//	//	uintptr_t idDeclWeaponAddr = get_idDeclWeaponAddr(get_idDeclWeaponStructBaseAddr(), getOffsetsVec(customWeapon.getId()));
//	//	logInfo("checkDeclWeaponForOverwrite: idDeclWeaponAddr: (hex) %p ", (void*)idDeclWeaponAddr);
//
//	//	if (!MemHelper::isBadReadPtr((void*)idDeclWeaponAddr)) {
//	//		idDeclWeapon* declWeaponPtr = (idDeclWeapon*)idDeclWeaponAddr;
//	//		logInfo("WeaponSettings::checkDeclWeaponForOverwrite: attempting to customize idDeclWeapon with id: %d ", declWeaponPtr->Id);
//	//		if (declWeaponPtr->fov1 != customWeapon.getZoomedFov()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its getZoomedFov set changed to: %.2f", declWeaponPtr->Id, customWeapon.getZoomedFov());
//	//			declWeaponPtr->fov1 = customWeapon.getZoomedFov();
//	//		}
//	//		if (declWeaponPtr->fov2 != customWeapon.getzoomedHandsFOV()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its getzoomedHandsFOV set changed to: %.2f", declWeaponPtr->Id, customWeapon.getzoomedHandsFOV());
//	//			declWeaponPtr->fov2 = customWeapon.getzoomedHandsFOV();
//	//		}
//	//		if (declWeaponPtr->controllerSensScalling != customWeapon.getControllerSens()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its controllerSensScalling set changed to: %.2f", declWeaponPtr->Id, customWeapon.getControllerSens());
//	//			declWeaponPtr->controllerSensScalling = customWeapon.getControllerSens();
//	//		}
//	//		if (declWeaponPtr->mouseSensScalling != customWeapon.getMouseSens()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its mouseSensScalling set changed to: %.2f", declWeaponPtr->Id, customWeapon.getMouseSens());
//	//			declWeaponPtr->mouseSensScalling = customWeapon.getMouseSens();
//	//		}
//	//		return true;
//	//	}
//	//	else {
//	//		logWarn("WeaponSettings::checkDeclWeaponForOverwrite: Bad ptr for idDeclWeaponAddr: %p ", (void*)idDeclWeaponAddr);
//	//		//todo this should return a bool that let us know that the customizing went wrong and that it has to be done again later.
//	//		return false;
//	//	}
//	//}
//
//	//bool isWeaponOverwriteNeeded(CustomWeapon& customWeapon) {
//	//	uintptr_t idDeclWeaponAddr = get_idDeclWeaponAddr(get_idDeclWeaponStructBaseAddr(), getOffsetsVec(customWeapon.getId()));
//	//	if (!MemHelper::isBadReadPtr((void*)idDeclWeaponAddr)) {
//	//		idDeclWeapon* declWeaponPtr = (idDeclWeapon*)idDeclWeaponAddr;
//	//		if (declWeaponPtr->fov1 != customWeapon.getZoomedFov()) {
//	//			return true;
//	//		}
//	//		if (declWeaponPtr->fov2 != customWeapon.getzoomedHandsFOV()) {
//	//			return true;
//	//		}
//	//		if (declWeaponPtr->controllerSensScalling != customWeapon.getControllerSens()) {
//	//			return true;
//	//		}
//	//		if (declWeaponPtr->mouseSensScalling != customWeapon.getMouseSens()) {
//	//			return true;
//	//		}
//	//		return false;
//	//	}
//	//	else {
//	//		return true; //! we return true if bad ptr but does that really mean an overwrite is needed?....
//	//	}
//	//}
//
//
//	//bool checkDeclWeaponForOverwrite(CustomWeapon& customWeapon) {
//	//	uintptr_t idDeclWeaponAddr = get_idDeclWeaponAddr(get_idDeclWeaponStructBaseAddr(), getOffsetsVec(customWeapon.getId()));
//	//	logInfo("checkDeclWeaponForOverwrite: idDeclWeaponAddr: (hex) %p ", (void*)idDeclWeaponAddr);	
//
//	//	if (!MemHelper::isBadReadPtr((void*)idDeclWeaponAddr)) {
//	//		idDeclWeapon* declWeaponPtr = (idDeclWeapon*)idDeclWeaponAddr;
//	//		logInfo("WeaponSettings::checkDeclWeaponForOverwrite: attempting to customize idDeclWeapon with id: %d ", declWeaponPtr->Id);
//	//		if (declWeaponPtr->fov1 != customWeapon.getZoomedFov()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its getZoomedFov set changed to: %.2f", declWeaponPtr->Id, customWeapon.getZoomedFov());
//	//			declWeaponPtr->fov1 = customWeapon.getZoomedFov();
//	//		}
//	//		if (declWeaponPtr->fov2 != customWeapon.getzoomedHandsFOV()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its getzoomedHandsFOV set changed to: %.2f", declWeaponPtr->Id, customWeapon.getzoomedHandsFOV());				
//	//			declWeaponPtr->fov2 = customWeapon.getzoomedHandsFOV();
//	//		}
//	//		if (declWeaponPtr->controllerSensScalling != customWeapon.getControllerSens()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its controllerSensScalling set changed to: %.2f", declWeaponPtr->Id, customWeapon.getControllerSens());				
//	//			declWeaponPtr->controllerSensScalling = customWeapon.getControllerSens();
//	//		}
//	//		if (declWeaponPtr->mouseSensScalling != customWeapon.getMouseSens()) {
//	//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon with id: %d is having its mouseSensScalling set changed to: %.2f", declWeaponPtr->Id, customWeapon.getMouseSens());				
//	//			declWeaponPtr->mouseSensScalling = customWeapon.getMouseSens();
//	//		}
//	//		return true;
//	//	}
//	//	else {
//	//		logWarn("WeaponSettings::checkDeclWeaponForOverwrite: Bad ptr for idDeclWeaponAddr: %p ", (void*)idDeclWeaponAddr);
//	//		//todo this should return a bool that let us know that the customizing went wrong and that it has to be done again later.
//	//		return false;
//	//	}
//	//}
//
//	//! we should not need this anymore:
//	/*std::vector<unsigned int>& getOffsetsVec(declWeaponModId weaponId) {
//		if (weaponId == declWeaponModId::shotgunStickyBombsId) {
//			return m_idDeclWeaponShotgunStickyOffsetsVec;
//		}
//		else if (weaponId == declWeaponModId::shotgunFullAutoId) {
//			return m_idDeclWeaponShotgunFullAutoOffsetsVec;
//		}
//		else if (weaponId == declWeaponModId::precisionBoltId) {
//			return m_idDeclWeaponPrecisionBoldOffsetsVec;
//		}
//		else if (weaponId == declWeaponModId::balistaArbalesteId) {
//			return m_idDeclWeaponBallistaArbalesteOffsetsVec;
//		}
//		else {
//			logWarn("WeaponSettings::getOffsetsVec: weaponId: %d HOW DID THAT HAPPEN???!!!", (int)weaponId);
//			return m_idDeclWeaponShotgunStickyOffsetsVec;
//		}
//	}*/
//	////! we should not need this anymore:
//	//uintptr_t get_idDeclWeaponStructBaseAddr() {
//	//	return (MemHelper::getModuleBaseAddr() + m_idDeclWeaponStructBaseAddrOffset);
//	//}
//	////! we should not need this anymore:
//	//uintptr_t get_idDeclWeaponAddr(uintptr_t idDeclWeaponStructBaseAddr, std::vector<unsigned int>& offsetsVec) {
//	//	return  MemHelper::FindPtrAddress(idDeclWeaponStructBaseAddr, offsetsVec);
//	//}
//
//
//public:
//
//	//? be carefull when you call the ctor as the game might not be initialized yet(?)
//	WeaponSettingsDebug()
//	{//! if this ctor is used it means the ini file is either default or that ini file doesn't not exist or can not be created or that data from ini file is corrupted or invalid.
//		createDefaultCustomWeapons();
//		//createTestCustomWeapons(); //? tremove this as soon as test is done and uncomment the one above
//	}
//
//
//
//
//
//	void checkCurrentlyEquippedIdWeapon() {
//		//bool isChanged = false;
//
//		/*static __int64 debugLastidWeaponAddr = -1;
//		static idDeclWeapon* debugLastidDeclWeaponPtr = 0;
//		static idDeclWeapon* debugLastidDeclWeaponOveride1Ptr = 0;
//		static idDeclWeapon* debugLastidDeclWeaponOveride2Ptr = 0;*/
//
//		__int64 idWeaponAddr = ObjectLocator::getCurrentIdWeaponAddr();
//		if (MemHelper::isBadReadPtr((void*)idWeaponAddr)) {
//			logErr("checkCurrentlyEquippedIdWeapon: idWeaponAddr is bad ptr: %p returning", (void*)idWeaponAddr);
//			return;
//		}
//
//		idWeapon* idWeaponObj = (idWeapon*)idWeaponAddr;
//
//		//idDeclWeapon* declWeaponPtr = idWeaponObj->getDeclWeaponOverride1();
//
//		//idDeclWeapon* declWeaponOveride1Ptr = idWeaponObj->getDeclWeaponOverride1();
//		/*if (MemHelper::isBadReadPtr(declWeaponOveride1Ptr)) {
//			logWarn("checkCurrentlyEquippedIdWeapon: declWeaponOveride1Ptr is bad ptr: %p ", (void*)declWeaponOveride1Ptr);
//		}*/
//		idDeclWeapon* declWeaponOveride2Ptr = idWeaponObj->getDeclWeaponOverride2();
//
//
//		/*if (idWeaponAddr != debugLastidWeaponAddr) {
//			debugLastidWeaponAddr = idWeaponAddr;
//			logInfo("idWeaponAddr has changed");
//			isChanged = true;
//		}*/
//
//		/*if (declWeaponPtr != debugLastidDeclWeaponPtr) {
//			debugLastidDeclWeaponPtr = declWeaponPtr;
//			logInfo("declWeaponPtr has changed");
//			isChanged = true;
//		}
//
//		if (declWeaponOveride1Ptr != debugLastidDeclWeaponOveride1Ptr) {
//			debugLastidDeclWeaponOveride1Ptr = declWeaponOveride1Ptr;
//			logInfo("declWeaponOveride1Ptr has changed");
//			isChanged = true;
//		}*/
//
//		/*if (declWeaponOveride2Ptr != debugLastidDeclWeaponOveride2Ptr) {
//			debugLastidDeclWeaponOveride2Ptr = declWeaponOveride2Ptr;
//			logInfo("declWeaponOveride2Ptr has changed");
//			isChanged = true;
//		}*/
//
//		/*if (isChanged) {
//			idWeaponObj->print();
//		}*/
//
//		//debugCurrentWeaponSlot();
//
//		//logInfo("debug: declWeaponPtr->Id is %d", (int)declWeaponPtr->Id);		
//
//		if (MemHelper::isBadReadPtr((void*)declWeaponOveride2Ptr)) {
//			//logWarn("checkCurrentlyEquippedIdWeapon: declWeaponOveride2Ptr is bad ptr: %p returning ", (void*)declWeaponOveride2Ptr);
//			//! we return here cause weapon customization only happens on declWeaponOveride2Ptr surely because they all those weapons have zoom(?)
//			return;
//		}
//		if (!isDeclWeaponModifiableByUser(declWeaponOveride2Ptr->name)) return;
//		for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
//		{
//			if (strcmp(declWeaponOveride2Ptr->name, m_customWeaponsVec[i].getName()) == 0) {
//				//if (declWeaponOveride2Ptr->name == m_customWeaponsVec[i].getName()) {
//				checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeaponOveride2Ptr);
//			}
//		}
//	}
//
//
//	void overwriteDeclWeaponsWithUserSettings() {
//		updateWeaponsSettingsFromIniFile();
//
//		/*logInfo("overwriteDeclWeaponsWithUserSetting: current customs weapons info:");
//		for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
//		{
//			m_customWeaponsVec[i].print();
//		}*/
//
//		int count = 0;
//		logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSettings() called");
//		uintptr_t declWeaponPtr = idResource::getResourceListFirstElementPtr("idDeclWeapon");
//		while (!MemHelper::isBadReadPtr((void*)declWeaponPtr))
//		{
//			//logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSetting: declWeaponPtr: %p", (void*)declWeaponPtr);
//			uintptr_t declWeaponAddr = *(uintptr_t*)declWeaponPtr;
//			if (MemHelper::isBadReadPtr((void*)declWeaponAddr)) {
//				/*logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSetting: bad ptr for: declWeaponAddr: %p ", (void*)declWeaponAddr);*/
//				//logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSettings() %d declWeapons were found in the list", count);
//				break;
//			}
//			idDeclWeapon* declWeapon = (idDeclWeapon*)declWeaponAddr;
//
//
//			for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
//			{
//				//logInfo("overwriteDeclWeaponsWithUserSetting: declWeapon->name: %s m_customWeaponsVec[i].getName() is %s", declWeapon->name, m_customWeaponsVec[i].getName());
//
//				if (strcmp(declWeapon->name, m_customWeaponsVec[i].getName()) == 0) {
//					checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
//				}
//				//? YOU CAN NOT COMPARE PTRS TO CHECK FOR STR VALUES !!!!!!!!!!
//				//if (declWeapon->name == m_customWeaponsVec[i].getName()) {
//				//	
//				//	//if (!isDeclWeaponModifiableByUser(declWeapon->name)) continue;
//				//	checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
//				//}
//				//if (strcmp(declWeapon->name, m_customWeaponsVec[i].getName()) == 0) {
//				//	//if (declWeaponOveride2Ptr->name == m_customWeaponsVec[i].getName()) {
//				//	checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
//				//}
//			}
//			//! each resource in the list is separated by 0x18
//			declWeaponPtr += 0x18;
//			count++;
//		}
//		logWarn("WeaponSettings::overwriteDeclWeaponsWithUserSettings() %d declWeapons were found in the list", count);
//	}
//
//
//	void checkDeclWeaponForOverwrite(CustomWeapon& customWeapon, idDeclWeapon* declWeaponPtr) {
//		logInfo("checkDeclWeaponForOverwrite declWeaponPtr: %p", (void*)declWeaponPtr);
//		if (MemHelper::isBadReadPtr((void*)declWeaponPtr)) {
//			//idDeclWeapon* declWeaponPtr = (idDeclWeapon*)idDeclWeaponAddr;
//			logWarn("checkDeclWeaponForOverwrite: bad ptr for %p can not check weapon !", (void*)declWeaponPtr);
//			return;
//		}
//
//		if (declWeaponPtr->zoomedFOV != customWeapon.getZoomedFov()) {
//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its zoomedFOV set changed to: %.2f", (void*)declWeaponPtr, declWeaponPtr->name, customWeapon.getZoomedFov());
//			declWeaponPtr->zoomedFOV = customWeapon.getZoomedFov();
//		}
//		if (declWeaponPtr->zoomedHandsFOV != customWeapon.getzoomedHandsFOV()) {
//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its zoomedHandsFOV set changed to: %.2f", (void*)declWeaponPtr, declWeaponPtr->name, customWeapon.getzoomedHandsFOV());
//			declWeaponPtr->zoomedHandsFOV = customWeapon.getzoomedHandsFOV();
//		}
//		if (declWeaponPtr->sensitivity_scale_controller != customWeapon.getControllerSens()) {
//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its sensitivity_scale_controller set changed to: %.2f", (void*)declWeaponPtr, declWeaponPtr->name, customWeapon.getControllerSens());
//			declWeaponPtr->sensitivity_scale_controller = customWeapon.getControllerSens();
//		}
//		if (declWeaponPtr->sensitivity_scale_mouse != customWeapon.getMouseSens()) {
//			logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its sensitivity_scale_mouse set changed to: %.2f", (void*)declWeaponPtr, declWeaponPtr->name, customWeapon.getMouseSens());
//			declWeaponPtr->sensitivity_scale_mouse = customWeapon.getMouseSens();
//		}
//		//else {
//		//	logWarn("WeaponSettings::checkDeclWeaponForOverwrite: Bad ptr for idDeclWeaponAddr: %p ", (void*)idDeclWeaponAddr);
//		//	//todo this should return a bool that let us know that the customizing went wrong and that it has to be done again later.
//		//	return false;
//		//}
//	}
//
//	//? this will have to be modified if you ever let user set settings for other weapons
//	//bool isDeclWeaponModifiableByUser(int32_t declWeaponId) {
//	//	bool result =  (declWeaponId == (int32_t)declWeaponModId::shotgunFullAutoId) || (declWeaponId == (int32_t)declWeaponModId::shotgunStickyBombsId) || (declWeaponId == (int32_t)declWeaponModId::precisionBoltId) || (declWeaponId == (int32_t)declWeaponModId::balistaArbalesteId);
//	//	//logInfo("isDeclWeaponModifiableByUser: returning %d", result);
//	//	return result;
//	//}
//
//	bool isDeclWeaponModifiableByUser(const char* declWeaponName) {
//		for (size_t i = 0; i < m_customizableWeaponsNames.size(); i++) {
//			// Use strcmp to compare the content of the strings
//			if (strcmp(declWeaponName, m_customizableWeaponsNames[i]) == 0) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void updateWeaponsSettingsFromIniFile() {
//		logInfo("WeaponSettings::updateWeaponsSettingsFromIniFile()...");
//
//		for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
//		{
//			if (m_customWeaponsVec[i].getName() == g_heavyCannonBoltNameIdStr) {
//				m_customWeaponsVec[i].setMouseSens(IniFileData::getAssaultRiflePrecisionBoltMouseSens());
//				m_customWeaponsVec[i].setControllerSens(IniFileData::getAssaultRiflePrecisionBoltControllerSens());
//			}
//			else if (m_customWeaponsVec[i].getName() == g_balistaArbalesteNameIdStr) {
//				m_customWeaponsVec[i].setMouseSens(IniFileData::getBallistaArbalestMouseSens());
//				m_customWeaponsVec[i].setControllerSens(IniFileData::getBallistaArbalestControllerSens());
//			}
//			else if (m_customWeaponsVec[i].getName() == g_shotGunFullAutoNameIdStr) {
//				if (IniFileData::isOverideShotgunConfig()) {
//					m_customWeaponsVec[i] = m_shotGunFullAutoOveride;
//				}
//				else {
//					m_customWeaponsVec[i] = m_shotGunFullAutoDefault;
//				}
//			}
//			else if (m_customWeaponsVec[i].getName() == g_shotGunStickiesNameIdStr) {
//				if (IniFileData::isOverideShotgunConfig()) {
//					m_customWeaponsVec[i] = m_shotGunStickyOveride;
//				}
//				else {
//					m_customWeaponsVec[i] = m_shotGunStickyDefault;
//				}
//			}
//		}
//	}
//
//	//? makes these 2 funcs private:
//
//	//! this method is more of a way to prevent cluttering of the log window or file:
//	/*bool isDeclWeaponsOverwriteNeeded() {
//		for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
//		{
//			if (isWeaponOverwriteNeeded(m_customWeaponsVec[i])) {
//				return true;
//			}
//		}
//		return false;
//	}*/
//
//
//
//
//	//WeaponSettings(std::vector<CustomWeapon> customWeaponsVecFromIniFile)
//	//{//! this will be used everytime user changes the ini file
//	//	m_customWeaponsVec = customWeaponsVecFromIniFile;
//	//	//overwriteDeclWeapons();
//	//}
//
//
//
//
//
//
//
//
//
//};
//
