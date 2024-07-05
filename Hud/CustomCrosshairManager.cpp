#include "CustomCrosshairManager.h"




 void CustomCrosshairManager::acquireWeaponCoolDownStatus(idSWFWidget_Hud_Reticle* idSWFWidget_Hud_ReticlePtr, idDeclWeaponReticle* declWeaponReticle) {

	if (!idSWFWidget_Hud_ReticlePtr || !declWeaponReticle) {
		m_isWeaponCooldownFlag = false;
		return;
	}

	//bool isReticleCoolDown = idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_ReticlePtr);
	//bool isMeathook = idDeclWeaponReticleManager::isMeatHookDeclWeaponReticle(declWeaponReticle);
	//bool isStickies = idDeclWeaponReticleManager::isShotgunDeclWeaponStickyReticle(declWeaponReticle);

	if (idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_ReticlePtr)) {
		if (idDeclWeaponReticleManager::isMeatHookDeclWeaponReticle(declWeaponReticle) || idDeclWeaponReticleManager::isShotgunDeclWeaponStickyReticle(declWeaponReticle)) {
			m_isWeaponCooldownFlag = true;
			return;
		}
	}

	m_isWeaponCooldownFlag = false;
}

 bool CustomCrosshairManager::getIsWeaponCooldownFlag()
 {
	 return m_isWeaponCooldownFlag;
 }
