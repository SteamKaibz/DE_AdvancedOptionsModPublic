#include "CustomCrosshairManager.h"








//void CustomCrosshairManager::updateWeaponCooldownFlag(weaponSlot_t weaponSlot, bool isCooldownActive) {
//
//	/*if (!isCooldownActive) {
//		m_isWeaponCooldownFlag = false;
//		return;
//	}*/
//
//	if (isCooldownActive && (weaponSlot == weaponSlot_t::SSG || weaponSlot == weaponSlot_t::SHOTGUN)) {
//		m_isWeaponCooldownFlag = true;
//		return;
//	}
//
//	m_isWeaponCooldownFlag = false;
//
//}

//? 9/9/24 this doesn't work if the reticle is set to off in the game....
// void CustomCrosshairManager::acquireWeaponCoolDownStatus(idSWFWidget_Hud_Reticle* idSWFWidget_Hud_ReticlePtr, idDeclWeaponReticle* declWeaponReticle) {
//
//	 
//	/* if (!idSWFWidget_Hud_ReticlePtr) {
//		 logInfo("acquireWeaponCoolDownStatus: dbg: idSWFWidget_Hud_ReticlePtr null");
//	 }
//	 if (!declWeaponReticle) {
//		 logInfo("acquireWeaponCoolDownStatus: dbg: declWeaponReticle null");
//	 } */
//
//
//	if (!idSWFWidget_Hud_ReticlePtr || !declWeaponReticle) {
//		m_isWeaponCooldownFlag = false;
//		return;
//	}
//
//	//bool isReticleCoolDown = idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_ReticlePtr);
//	//bool isMeathook = idDeclWeaponReticleManager::isMeatHookDeclWeaponReticle(declWeaponReticle);
//	//bool isStickies = idDeclWeaponReticleManager::isShotgunDeclWeaponStickyReticle(declWeaponReticle);
//
//	if (idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_ReticlePtr)) {
//		if (idDeclWeaponReticleManager::isMeatHookDeclWeaponReticle(declWeaponReticle) || idDeclWeaponReticleManager::isShotgunDeclWeaponStickyReticle(declWeaponReticle)) {
//			m_isWeaponCooldownFlag = true;
//			return;
//		}
//	}
//
//	m_isWeaponCooldownFlag = false;
//}


