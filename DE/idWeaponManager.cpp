#include "idWeaponManager.h"

//! from hook

 void idWeaponManager::acquirreCurrentIdWeapon(idWeapon* idWeaponObj) {

	if (!idWeaponObj) {
		logErr("acquirreCurrentIdWeapon: got null idWeaponAddr from hook (?!)");
		return;
	}

	/*static idWeapon_chargeState_t dbg_chargeState = idWeapon_chargeState_t::CHARGE_STATE_NONE;
	if (idWeaponObj->chargeParms.chargeState != dbg_chargeState) {
		logInfo("acquirreCurrentIdWeapon: dbg: chargeState has changed to: %d", idWeaponObj->chargeParms.chargeState);
		dbg_chargeState = idWeaponObj->chargeParms.chargeState;
	}*/

	m_cachedIsCurWeaponOnCooldown = (idWeaponObj->chargeParms.chargeState == CHARGE_STATE_COOLING);
	m_cachedCurWeaponSlot = idInventoryItemManager::getWeaponSlot(idWeaponObj);

	m_lastIdWeaponGetMs = K_Utils::EpochMillis();	

 }



 weaponSlot_t idWeaponManager::getCurWeaponSlot() {
	if (K_Utils::EpochMillis() - m_lastIdWeaponGetMs > m_idWeaponGetTimeoutMs) {
		if (!m_isWeaponUndefinedWarning) {
			logWarn("getCurWeaponSlot: m_lastIdWeaponGetMs is too old returning weaponSlot_t::UNDEFINED");
			m_isWeaponUndefinedWarning = true;
		}
		return weaponSlot_t::UNDEFINED;
	}
	m_isWeaponUndefinedWarning = false;
	//return idInventoryItemManager::getWeaponSlot(m_currentIdWeapon);
	return m_cachedCurWeaponSlot;
 }


 bool idWeaponManager::getIsCurrentWeaponOnCooldown()
 {
	 if (K_Utils::EpochMillis() - m_lastIdWeaponGetMs > m_idWeaponGetTimeoutMs) {
		 //! data is too old, returning false which will cause any indicator to show weapon not on cooldown. Not good, but better than the alternative imo.
		 return false;
	 }

	 return m_cachedIsCurWeaponOnCooldown;	 
 }





