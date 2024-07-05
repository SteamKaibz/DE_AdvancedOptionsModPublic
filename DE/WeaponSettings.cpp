#include "WeaponSettings.h"

/// <summary>
/// this are the settings that only for max fov and normal sensitivity for both shotguns mods
/// </summary>

 void WeaponSettings::initWeapons() {

	 if (m_isInitialized) return;
	
	m_customWeaponsVec.push_back(CustomWeapon(WeaponIdStr::g_shotGunStickiesNameIdStr, modSettingsDefault::g_overideShotGunzoomedFOV, modSettingsDefault::g_overideShotGunzoomedHandsFov, modSettingsDefault::g_weaponMaxSensitivity, modSettingsDefault::g_weaponMaxSensitivity));

	m_customWeaponsVec.push_back(CustomWeapon(WeaponIdStr::g_shotGunFullAutoNameIdStr, modSettingsDefault::g_overideShotGunzoomedFOV, modSettingsDefault::g_overideShotGunzoomedHandsFov, modSettingsDefault::g_weaponMaxSensitivity, modSettingsDefault::g_weaponMaxSensitivity));

	//! by default we don't modify arbalest and bolt settings it's up to the user to change that:
	m_customWeaponsVec.push_back(CustomWeapon(WeaponIdStr::g_heavyCannonBoltNameIdStr, modSettingsDefault::g_defaultPrecisionBoltzoomedFOV, modSettingsDefault::g_defaultPrecisionBoltzoomedHandsFOV, modSettingsDefault::g_defaultPrecisionBoltControllerSens, modSettingsDefault::g_defaultPrecisionBoltMouseSens));

	m_customWeaponsVec.push_back(CustomWeapon(WeaponIdStr::g_balistaArbalesteNameIdStr, modSettingsDefault::g_defaultBallistaArbalestezoomedFOV, modSettingsDefault::g_defaultBallistaArbalestezoomedHandsFOV, modSettingsDefault::g_defaultBallistaArbalesteControllerSens, modSettingsDefault::g_defaultBallistaArbalesteMouseSens));

	m_isInitialized = true;

}



void WeaponSettings::overwriteDeclWeaponsWithUserSettings() {
	if (!m_isInitialized) {
		logErr("overwriteDeclWeaponsWithUserSettings: func called before weapons were initialized, this will not work...initWeapons() must be called once before overwriteDeclWeaponsWithUserSettings can ever be called");
	}

	 updateFromModSettings();


	 unsigned int declCount = 0;
	 unsigned int weaponOverrideCount = 0;
	 logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSettings() called");
	 uintptr_t declWeaponPtr = idResourceListManager::getResourceListFirstElementPtr("idDeclWeapon");
	 //while (!MemHelper::isBadReadPtr((void*)declWeaponPtr))
	 while (declCount <= m_declWeaponMaxIndex)
	 {

		 if (MemHelper::isBadReadPtr((void*)declWeaponPtr)) {
			 logWarn("overwriteDeclWeaponsWithUserSettings: declWeaponPtr is bad ptr: %p, breaking  ", (void*)declWeaponPtr);
			 break;
		 }		

		 //logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSetting: declWeaponPtr: %p", (void*)declWeaponPtr);
		 uintptr_t declWeaponAddr = *(uintptr_t*)declWeaponPtr;
		 //logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSetting: declWeaponAddr: %p", (void*)declWeaponPtr);
		 if (MemHelper::isBadReadPtr((void*)declWeaponAddr)) {
			 logWarn("overwriteDeclWeaponsWithUserSettings: declWeaponAddr is bad ptr: %p, breaking  ", (void*)declWeaponAddr);
			 break;
		 }
		 //logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSetting: before cast");
		 idDeclWeapon* declWeapon = (idDeclWeapon*)declWeaponAddr;
		 //logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSetting: after cast");

		 //logInfo("overwriteDeclWeaponsWithUserSetting: m_customWeaponsVec.size() is %zu", m_customWeaponsVec.size());
		 if (idResourceManager::getDeclWeaponName(declWeapon).empty()) {
			 //if (declWeapon->getNameStr().empty()) {
			 logWarn("overwriteDeclWeaponsWithUserSetting declWeapon->getNameStr().empty() Triggered Could this cause a crash?");
			 break;
		 }
		

		 for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
		 {

			 //logInfo("overwriteDeclWeaponsWithUserSetting: declWeapon->name: %s m_customWeaponsVec[i].getName() is %s", declWeapon->name, m_customWeaponsVec[i].getName());

			 //if (declWeapon->name != NULL && declWeapon->getNameStr() == m_customWeaponsVec[i].getNameStr()) {
			 if (!idResourceManager::getDeclWeaponName(declWeapon).empty() && idResourceManager::getDeclWeaponName(declWeapon) == m_customWeaponsVec[i].getNameStr()) {
				 weaponOverrideCount += checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
			 }

			 /*if (declWeapon->name != NULL && (strcmp(declWeapon->name, m_customWeaponsVec[i].getName()) == 0)) {
			 weaponOverrideCount += checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
			 }*/
			 //? YOU CAN NOT COMPARE PTRS TO CHECK FOR STR VALUES !!!!!!!!!!
			 //if (declWeapon->name == m_customWeaponsVec[i].getName()) {
			 //	
			 //	//if (!isDeclWeaponModifiableByUser(declWeapon->name)) continue;
			 //	checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
			 //}
			 //if (strcmp(declWeapon->name, m_customWeaponsVec[i].getName()) == 0) {
			 //	//if (declWeaponOveride2Ptr->name == m_customWeaponsVec[i].getName()) {
			 //	checkDeclWeaponForOverwrite(m_customWeaponsVec[i], declWeapon);
			 //}
		 }
		 //! each resource in the list is separated by 0x18
		 declWeaponPtr += 0x18;
		 declCount++;
		 //logInfo("overwriteDeclWeaponsWithUserSettings: still in the loop: declCount: %d", declCount);
	 }
	 logInfo("WeaponSettings::overwriteDeclWeaponsWithUserSettings() %d declWeapons were found in the list. weaponOverrideCount: %d", declCount, weaponOverrideCount);
 }

  int WeaponSettings::checkDeclWeaponForOverwrite(CustomWeapon& customWeapon, idDeclWeapon* declWeaponPtr) {

	 unsigned int changesCount = 0;


	 /*logWarn("checkDeclWeaponForOverwrite: NOT DOING ANYTHING JUST DEBUG: declWeaponPtr: %p", (void*)declWeaponPtr);
	 return;*/

	 if (MemHelper::isBadReadPtr((void*)declWeaponPtr)) {
		 //idDeclWeapon* declWeaponPtr = (idDeclWeapon*)idDeclWeaponAddr;
		 logWarn("checkDeclWeaponForOverwrite: bad ptr for %p can not check weapon !", (void*)declWeaponPtr);
		 return changesCount;
	 }
	 logInfo("checkDeclWeaponForOverwrite declWeaponPtr: %p declWeapon name: %s ", (void*)declWeaponPtr, idResourceManager::getDeclWeaponName(declWeaponPtr).c_str());

	 //if (declWeaponPtr->zoomedFOV != customWeapon.getZoomedFov()) {
	 if (declWeaponPtr->ironSightZoom.zoomedFOV != customWeapon.getZoomedFov()) {
		 logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its zoomedFOV set changed to: %.2f", (void*)declWeaponPtr, idResourceManager::getDeclWeaponName(declWeaponPtr).c_str(), customWeapon.getZoomedFov());
		 declWeaponPtr->ironSightZoom.zoomedFOV = customWeapon.getZoomedFov();
		 changesCount++;
	 }
	 //if (declWeaponPtr->zoomedHandsFOV != customWeapon.getzoomedHandsFOV()) {
	 if (declWeaponPtr->ironSightZoom.zoomedHandsFOV != customWeapon.getzoomedHandsFOV()) {
		 logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its zoomedHandsFOV set changed to: %.2f", (void*)declWeaponPtr, idResourceManager::getDeclWeaponName(declWeaponPtr).c_str(), customWeapon.getzoomedHandsFOV());
		 declWeaponPtr->ironSightZoom.zoomedHandsFOV = customWeapon.getzoomedHandsFOV();
		 changesCount++;
	 }
	 //if (declWeaponPtr->sensitivity_scale_controller != customWeapon.getControllerSens()) {
	 if (declWeaponPtr->ironSightZoom.sensitivity_scale_controller != customWeapon.getControllerSens()) {
		 logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its sensitivity_scale_controller set changed to: %.2f", (void*)declWeaponPtr, idResourceManager::getDeclWeaponName(declWeaponPtr).c_str(), customWeapon.getControllerSens());
		 declWeaponPtr->ironSightZoom.sensitivity_scale_controller = customWeapon.getControllerSens();
		 changesCount++;
	 }
	 //if (declWeaponPtr->sensitivity_scale_mouse != customWeapon.getMouseSens()) {
	 if (declWeaponPtr->ironSightZoom.sensitivity_scale_mouse != customWeapon.getMouseSens()) {
		 logInfo("WeaponSettings::checkDeclWeaponForOverwrite: idDeclWeapon: %p with name: %s is having its sensitivity_scale_mouse set changed to: %.2f", (void*)declWeaponPtr, idResourceManager::getDeclWeaponName(declWeaponPtr).c_str(), customWeapon.getMouseSens());
		 declWeaponPtr->ironSightZoom.sensitivity_scale_mouse = customWeapon.getMouseSens();
		 changesCount++;
	 }
	 return changesCount;
	 //else {
	 //	logWarn("WeaponSettings::checkDeclWeaponForOverwrite: Bad ptr for idDeclWeaponAddr: %p ", (void*)idDeclWeaponAddr);
	 //	//todo this should return a bool that let us know that the customizing went wrong and that it has to be done again later.
	 //	return false;
	 //}
	 //logInfo("checkDeclWeaponForOverwrite exiting.. ");
 }

  bool WeaponSettings::isDeclWeaponModifiableByUser(std::string declWeaponNameStr) {
	 logDebug("isDeclWeaponModifiableByUser");

	 for (size_t i = 0; i < m_customizableWeaponsNamesStrVec.size(); i++) {
		 if (declWeaponNameStr == m_customizableWeaponsNamesStrVec[i]) {
			 return true;
		 }
	 }
	 return false;
 }

  void WeaponSettings::updateFromModSettings() {

	 for (size_t i = 0; i < m_customWeaponsVec.size(); i++)
	 {
		 if (m_customWeaponsVec[i].getNameStr() == WeaponIdStr::g_heavyCannonBoltNameIdStr) {
			 m_customWeaponsVec[i].setMouseSens(modSettings::getAssaultRiflePrecisionBoltMouseSens());
			 logInfo("updateFromModSettings: debug: heavyCannonBolt mouse sens set to: %.3f ", modSettings::getAssaultRiflePrecisionBoltMouseSens());
			 m_customWeaponsVec[i].setControllerSens( modSettings::getAssaultRiflePrecisionBoltControllerSens());
		 }
		 else if (m_customWeaponsVec[i].getNameStr() == WeaponIdStr::g_balistaArbalesteNameIdStr) {
			 if (modSettings::isRemoveBalistaZoom()) {
				 m_customWeaponsVec[i].setZoomedFov(modSettingsDefault::g_overideBalistaArbalestZoomedFOV);
				 m_customWeaponsVec[i].setzoomedHandsFOV(modSettingsDefault::g_overideBalistaArbalestZoomedHandsFov);
			 }
			 else {
				 m_customWeaponsVec[i].setZoomedFov(modSettingsDefault::g_defaultBallistaArbalestezoomedFOV);
				 m_customWeaponsVec[i].setzoomedHandsFOV(modSettingsDefault::g_defaultBallistaArbalestezoomedHandsFOV);
			 }
			 m_customWeaponsVec[i].setMouseSens(modSettings::getBallistaArbalestMouseSens());
			 m_customWeaponsVec[i].setControllerSens(modSettings::getBallistaArbalestControllerSens());
		 }
		 else if (m_customWeaponsVec[i].getNameStr() == WeaponIdStr::g_shotGunFullAutoNameIdStr) {
			 if (modSettings::isOverideShotgunConfig()) {
				 m_customWeaponsVec[i] = m_shotGunFullAutoOveride;
			 }
			 else {
				 m_customWeaponsVec[i] = m_shotGunFullAutoDefault;
			 }
		 }
		 else if (m_customWeaponsVec[i].getNameStr() == WeaponIdStr::g_shotGunStickiesNameIdStr) {
			 if (modSettings::isOverideShotgunConfig()) {
				 m_customWeaponsVec[i] = m_shotGunStickyOveride;
			 }
			 else {
				 m_customWeaponsVec[i] = m_shotGunStickyDefault;
			 }
		 }
	 }
 }
