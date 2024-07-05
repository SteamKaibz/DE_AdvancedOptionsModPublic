#include "idWeaponManager.h"

//! from hook

 void idWeaponManager::acquirreCurrentIdWeapon(idWeapon* idWeaponObj) {

	if (!idWeaponObj) {
		logErr("acquirreCurrentIdWeapon: got null idWeaponAddr (?!)");
		return;
	}

	m_lastIdWeaponGetMs = EpochMillis();
	//if (idWeaponObj != m_currentIdWeapon) {
	//	//idWeapon* currentIdWeapon = (idWeapon*)idWeaponAddr;
	//	m_lastIdWeaponGetMs = EpochMillis();
	//	/*int curWeaponSlot = (int)getCurWeaponSlot();
	//	logInfo("acquirreCurrentIdWeapon: equipped idWeapon has changed to %p and weapon slot is now: %d", idWeaponObj, curWeaponSlot);*/
	//}
	m_currentIdWeapon = idWeaponObj;
}

 idWeapon* idWeaponManager::getCurrentlyEquippedIdWeapon() {
	if (MemHelper::isBadReadPtr(m_currentIdWeapon)) {
		return nullptr;
	}
	return m_currentIdWeapon;
}

 weaponSlot_t idWeaponManager::getCurWeaponSlot() {
	if (EpochMillis() - m_lastIdWeaponGetMs > m_idWeaponGetTimeoutMs) {
		if (!m_isWeaponUndefinedWarning) {
			logWarn("m_lastIdWeaponGetMs is too old returning weaponSlot_t::UNDEFINED");
			m_isWeaponUndefinedWarning = true;
		}
		return weaponSlot_t::UNDEFINED;
	}
	m_isWeaponUndefinedWarning = false;
	return idInventoryItemManager::getWeaponSlot(m_currentIdWeapon);
}

 //std::string idWeaponManager::getDbgStr() {
	// std::string result = "idWeaponManager: ";

	// if (MemHelper::isBadReadPtr(m_currentIdWeapon)) {
	//	 result += " m_currentIdWeapon is bad ptr";
	//	 return result;
	// }
	//


 //}
