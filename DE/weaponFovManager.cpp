#include "weaponFovManager.h"


void weaponFovManager::update()
{
	weaponSlot_t currentWeaponSlot = idWeaponManager::getCurWeaponSlot();

	int targetWeaponFov = m_defaultWeaponFov;

	switch (currentWeaponSlot)
	{
	/*case weaponSlot_t::UNDEFINED:
		break;*/
	case weaponSlot_t::SHOTGUN:
		targetWeaponFov = modSettings::HandsFOVShotgun;
		break;
	case weaponSlot_t::HAR:
		targetWeaponFov = modSettings::HandsFOVHAR;
		break;
	case weaponSlot_t::PLASMA:
		targetWeaponFov = modSettings::HandsFOVPlasma;
		break;
	case weaponSlot_t::ROCKET:
		targetWeaponFov = modSettings::HandsFOVRocket;
		break;
	case weaponSlot_t::SSG:
		targetWeaponFov = modSettings::HandsFOVSSG;
		break;
	case weaponSlot_t::BALLISTA:
		targetWeaponFov = modSettings::HandsFOVBallista;
		break;
	case weaponSlot_t::CHAINGUN:
		targetWeaponFov = modSettings::HandsFOVChaingun;
		break;
	case weaponSlot_t::BFG_UNMAYKR:
		targetWeaponFov = modSettings::HandsFOVBFGUnmaykr;
		break;
	case weaponSlot_t::WEAPON_9:
		targetWeaponFov = modSettings::HandsFOVWeapon9;
		break;
	case weaponSlot_t::CRUCIBLE_HAMMER:
		targetWeaponFov = modSettings::HandsFOVCrucibleHammer;
		break;	
	}

	setCurWeaponFov(targetWeaponFov);
}


float weaponFovManager::lerp(float a, float b, float t) {
	return a + t * (b - a);
}


//? doesn't work it way too visible
//void weaponFovManager::setCurWeaponFov(int weaponFov) {
//	static float curWeaponFovF = fastCvarManager::getCurHands_fovScale();
//	float targetWeaponFov = static_cast<float>(weaponFov);
//
//	// Calculate the interpolated FOV value
//	float lerpSpeed = 0.9f; // Adjust this value to control the speed of the transition
//	curWeaponFovF = lerp(curWeaponFovF, targetWeaponFov, lerpSpeed);
//
//	// Update the FOV only if there is a noticeable difference
//	if (fabs(curWeaponFovF - targetWeaponFov) > 0.01f) {
//		logInfo("setCurWeaponFov: (int)curWeaponFovF is: %d updating it to: %d", static_cast<int>(curWeaponFovF), weaponFov);
//		idCmd::setHandsFov(static_cast<int>(curWeaponFovF));
//	}
//}


void weaponFovManager::setCurWeaponFov(int weaponFov)
{
	float curWeaponFovF = fastCvarManager::getCurHands_fovScale();

	//logInfo("setCurWeaponFov: weaponFov: %d curWeaponFovF: %.3f", weaponFov, curWeaponFovF);

	int curWeaponFovFormated = (int)(curWeaponFovF * 100);

	//if (curWeaponFovF != (float)weaponFov) {
	if (weaponFov > 0 && weaponFov < 10 && curWeaponFovFormated != 10) {

		//logInfo("setCurWeaponFov: forcing weapon fov to: 10 to prevent issues");
		idCmd::setHandsFov(10);
	}

	else if ((weaponFov >= 10) && (curWeaponFovFormated != weaponFov)) {
		
		//logInfo("setCurWeaponFov: curWeaponFovFormated is: %d updating it to: %d", curWeaponFovFormated, weaponFov);
		idCmd::setHandsFov(weaponFov);
	}
}


