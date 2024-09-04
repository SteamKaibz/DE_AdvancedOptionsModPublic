#pragma once

#include "idLib_Dynamic.h"
#include "idWeaponManager.h"
#include "fastCvarManager.h"
#include "idCmd.h"
#include "modSettings.h"	




/// <summary>
/// Has its own class as it can not be included in Weapon settings because we can not reliably set the weapon fov in the decl weapons for all weapons. so instead we poll to check cur weapon and apply the fov using mod settings.
/// </summary>
class weaponFovManager
{

private:

	static inline int m_defaultWeaponFov = 0;

public:

	static void update();
	static float lerp(float a, float b, float t);
	static void setCurWeaponFov(int weaponFov);
};

