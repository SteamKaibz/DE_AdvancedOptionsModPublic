#pragma once
#include "../Config.h"
#include "MemHelper.h"
#include "idInventoryItemManager.h"
#include <../Common/K_Utils.h>

class idWeaponManager {
private:

	//static inline idWeapon* m_currentIdWeapon = nullptr;
	static inline uint64_t m_lastIdWeaponGetMs = 0;
	static inline const int m_idWeaponGetTimeoutMs = 100;
	static inline bool m_isWeaponUndefinedWarning = false; //! only used for loging 

	//! caching those is not the best, and it could be improved but it should do for now as the hook, from which we get data is called often enough. Also, this method is crash safe.
	static inline bool m_cachedIsCurWeaponOnCooldown = false;
	static inline weaponSlot_t m_cachedCurWeaponSlot = weaponSlot_t::UNDEFINED;

public:

	//! from hook
	static void acquirreCurrentIdWeapon(idWeapon* idWeaponObj);

	//static idWeapon* getCurrentlyEquippedIdWeapon();

	static weaponSlot_t getCurWeaponSlot();

	static bool getIsCurrentWeaponOnCooldown();

	//static std::string getDbgStr();



};
