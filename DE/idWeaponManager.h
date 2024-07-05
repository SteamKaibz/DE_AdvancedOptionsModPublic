#pragma once
#include "../Config/Config.h"
#include "MemHelper.h"
#include "idInventoryItemManager.h"

class idWeaponManager {
private:

	static inline idWeapon* m_currentIdWeapon = nullptr;
	static inline uint64_t m_lastIdWeaponGetMs = 0;
	static inline const int m_idWeaponGetTimeoutMs = 100;
	static inline bool m_isWeaponUndefinedWarning = false;

public:

	//! from hook
	static void acquirreCurrentIdWeapon(idWeapon* idWeaponObj);

	static idWeapon* getCurrentlyEquippedIdWeapon();

	static weaponSlot_t getCurWeaponSlot();

	//static std::string getDbgStr();



};
