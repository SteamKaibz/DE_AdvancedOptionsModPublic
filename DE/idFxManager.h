#pragma once
#include "idInventoryManager.h"
#include "Patcher.h"
#include "Sigs.h"


class idFxManager
{
private:

	static inline __int64 m_toggleDashEffectInstructionAddr = 0;

	static inline const std::vector<unsigned char> dashEffectONVec = { 0x84 };
	static inline const std::vector<unsigned char> dashEffectOFFVec = { 0x85 };

public:

	static bool acquireToggleDashEffectInstructionAddr(__int64 addr);

	static bool setDashEffect(bool isOn);
	//! we only disable the dash we do not re-enable it to make sure we don't assigne a ptr that could crash the game. User can still reenable the dash by reloading the level/save
	//static void disableDashFx();

	


};


