#include "CustomIceNadeIconManager.h"

//CustomIceNadeIconUIData CustomIceNadeIconManager::m_iceNadeIconUIData;



 void CustomIceNadeIconManager::updateIsRenderingAllowed(bool isAllowed) {
	m_iceNadeIconUIData.updateIsRenderingAllowed(isAllowed);
}

 void CustomIceNadeIconManager::updateIsIceNadeCooldownStatus() {
	m_iceNadeIconUIData.updateIsIceNadeCooldownStatus();
}

 void CustomIceNadeIconManager::updateColors() {
	m_iceNadeIconUIData.updateColors();
}

 void CustomIceNadeIconManager::updateCoords() {
	m_iceNadeIconUIData.updateCoords();
}

 void CustomIceNadeIconManager::updateCooldownTimeLeftStr() {
	m_iceNadeIconUIData.updateCooldownTimeLeftStr();
}

 CustomIceNadeIconUIData CustomIceNadeIconManager::getData() {
	m_iceNadeIconUIData.updateMaterials(); //? this could be the answer to not crashing anymore....
	return m_iceNadeIconUIData;
}

// debugTimersData CustomIceNadeIconManager::getDebugTimersStrs() {
//	/*idHUD_WeaponInfo* idHud_WeaponInfo = (idHUD_WeaponInfo*)idHudManager::getIdHud_Element(HudElementName::WeaponInfo);
//	if (!idHud_WeaponInfo) {
//	m_iceNadeIconUIData.cooldownText = "XX";
//	return;
//	}
//	idHud_WeaponInfo->equipmentWidget.*/
//	auto timers = idPlayer_K::getEquipmentTimers(equipmentIndex_t::ICE);
//	debugTimersData data;
//	long long gameTime = idMapInstanceLocalManager::getGameTime_t();
//
//	data.gameTimeStr = std::to_string(gameTime);
//	data.RechargeDurationStr = std::to_string(timers.equipmentRechargeDuration);
//	data.RechargeTimeStr = std::to_string(timers.equipmentRechargeTime);
//	data.ReuseTimeStr = std::to_string(timers.equipmentReuseTime);
//	data.StartTimeStr = std::to_string(timers.equipmentRechargeStartTime);
//	int countdown = (int)((timers.equipmentRechargeTime - gameTime) / 1000000) + 1;
//	if (countdown < 0) {
//		countdown = 0;
//	}
//	data.countdownStr = std::to_string(countdown);
//	return data;
//}
