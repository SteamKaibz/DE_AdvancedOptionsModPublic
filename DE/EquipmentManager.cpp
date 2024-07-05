#include "EquipmentManager.h"

bool EquipmentManager::acquireUseEquipmentItemFp(__int64 fAdd)
{
	if (MemHelper::isBadReadPtr((void*)fAdd)) {
		logErr("acquireUseEquipmentItemFp: fAdd is bad ptr: %p", (void*)fAdd);
		m_UseEquipmentItemFp = nullptr;
		return false;
	}

	m_UseEquipmentItemFp = (UseEquipmentItemFp)fAdd;
	logInfo("acquireUseEquipmentItemFp: m_UseEquipmentItemFp set to %p", m_UseEquipmentItemFp);
	return true;
	
}

bool EquipmentManager::acquireSwitchEquipmentItemFp(__int64 fAdd)
{
	if (MemHelper::isBadReadPtr((void*)fAdd)) {
		logErr("acquireSwitchEquipmentItemFp: fAdd is bad ptr: %p", (void*)fAdd);
		m_SwitchEquipmentItemFp = nullptr;
		return false;
	}

	m_SwitchEquipmentItemFp = (SwitchEquipmentItemFp)fAdd;
	logInfo("acquireSwitchEquipmentItemFp: m_SwitchEquipmentItemFp set to %p: ", m_SwitchEquipmentItemFp);
	return true;
}



void EquipmentManager::switchEquipment(equipmentType_t equipmentType) {
	if (!m_SwitchEquipmentItemFp) {
		logErr("switchEquipment: m_SwitchEquipmentItemFp is nullptr");
		return;
	}

	idPlayer* idPlayerPtr = idMapInstanceLocalManager::getIdPlayer();
	if (!idPlayerPtr) {
		logWarn("switchEquipment: idPlayerPtr is nullptr");
		return;
	}

	m_SwitchEquipmentItemFp(idPlayerPtr, equipmentType);
}


void EquipmentManager::useEquipmentItem(equipmentType_t equipmentType)
{
	if (!m_UseEquipmentItemFp) {
		logErr("useEquipmentItem: m_UseEquipmentItemFp is nullptr ");
		return;
	}

	idPlayer* idPlayerPtr = idMapInstanceLocalManager::getIdPlayer();

	if (!idPlayerPtr) {
		logWarn("useEquipmentItem: idPlayerPtr is nullptr");
		return;
	}

	/*idHUD_AbilityIndicators* idHUD_AbilityIndicatorsPtr = (idHUD_AbilityIndicators*)idHudManager::getIdHud_Element(HudElementName::AbilityIndicators);*/

	/*if (idHUD_AbilityIndicatorsPtr) {

		if (equipmentType == equipmentType_t::EQUIPMENT_FRAG_GRENADE) {

			if ((int)idHUD_AbilityIndicatorsPtr->grenadeCharge < 1) {
				playerSoundManager::playOutOfItemSound();
			}
		}
		else if (equipmentType == equipmentType_t::EQUIPMENT_ICE_BOMB) {
			if ((int)idHUD_AbilityIndicatorsPtr->iceGrenadeCharge < 1) {
				playerSoundManager::playOutOfItemSound();
			}
		}
	}*/

	//! the 2 zeros at the end are because that's the way it's used in processInput in ida
	if (!m_UseEquipmentItemFp(idPlayerPtr, playerPropsManager::getEquipmentDecl(equipmentType), 0, 0)) {
		playerSoundManager::playOutOfItemSound();
	}

	//logInfo("useEquipmentItem: debug: m_UseEquipmentItemFp result: for equipmentType: %d : %d", equipmentType, result);
}

