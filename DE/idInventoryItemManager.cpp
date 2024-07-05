#include "idInventoryItemManager.h"

 weaponSlot_t idInventoryItemManager::getWeaponSlot(idWeapon* idWeaponObj) {
	if (MemHelper::isBadReadPtr(idWeaponObj)) {
		return weaponSlot_t::UNDEFINED;
	}
	idInventoryItem* invItemPtr = (idInventoryItem*)idWeaponObj;
	idDeclWeapon* declWeaponPtr = (idDeclWeapon*)invItemPtr->decl;
	if (MemHelper::isBadReadPtr(declWeaponPtr)) {
		logErr("getWeaponSlot : bad ptr for declWeaponPtr");
		return weaponSlot_t::UNDEFINED;
	}
	//logInfo("getWeaponSlot: returning: %d", declWeaponPtr->weaponSelectionGroup);
	return (weaponSlot_t)declWeaponPtr->weaponSelectionGroup;
}
