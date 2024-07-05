#pragma once
#include "../DE/GeneratedClasses.h"
#include "../DE/idDeclWeaponReticleManager.h"
#include "../DE/idSWFWidget_Hud_ReticleManager.h"


/// <summary>
/// 1/5/24 rendered by imgui and not the game renderer to improve performance.
/// </summary>
class CustomCrosshairManager {

private:

	static inline bool m_isWeaponCooldownFlag = false;	

public:


	//static void updateData(bool isSlayerActiveFlag, bool isGameSettingsHudEnabled);


	static void acquireWeaponCoolDownStatus(idSWFWidget_Hud_Reticle* idSWFWidget_Hud_ReticlePtr, idDeclWeaponReticle* declWeaponReticle);

	static bool getIsWeaponCooldownFlag();

};
