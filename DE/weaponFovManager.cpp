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

//! don't need this after all, changing fov often enough, is enough. beside lerping would look bad...
float weaponFovManager::lerp(float a, float b, float t) {
	return a + t * (b - a);
}


//? doesn't work it way too visible
//void weaponFovManager::setCurWeaponFov(int desiredWeaponFov) {
//	static float curWeaponFovF = fastCvarManager::getCurHands_fovScale();
//	float targetWeaponFov = static_cast<float>(desiredWeaponFov);
//
//	// Calculate the interpolated FOV value
//	float lerpSpeed = 0.9f; // Adjust this value to control the speed of the transition
//	curWeaponFovF = lerp(curWeaponFovF, targetWeaponFov, lerpSpeed);
//
//	// Update the FOV only if there is a noticeable difference
//	if (fabs(curWeaponFovF - targetWeaponFov) > 0.01f) {
//		logInfo("setCurWeaponFov: (int)curWeaponFovF is: %d updating it to: %d", static_cast<int>(curWeaponFovF), desiredWeaponFov);
//		idCmd::setHandsFov(static_cast<int>(curWeaponFovF));
//	}
//}

//! this looks like a mess, but because weapon fov at 0 is not 0 but default fov, it makes everything a bit confusing.
void weaponFovManager::setCurWeaponFov(int desiredWeaponFov)
{
	float curWeaponFovF = fastCvarManager::getCurHands_fovScale();

	//logInfo("setCurWeaponFov: desiredWeaponFov: %d curWeaponFovF: %.3f", desiredWeaponFov, curWeaponFovF);

	int curWeaponFovFormated = (int)(curWeaponFovF * 100);

	//if (curWeaponFovF != (float)desiredWeaponFov) {
	if (desiredWeaponFov > 0 && desiredWeaponFov < 10 && curWeaponFovFormated != 10) {

		//logInfo("setCurWeaponFov: forcing weapon fov to: 10 to prevent issues");
		idCmd::setHandsFov(10);
	}

	else if ((desiredWeaponFov >= 10) && (curWeaponFovFormated != desiredWeaponFov)) {
		
		//logInfo("setCurWeaponFov: curWeaponFovFormated is: %d updating it to: %d", curWeaponFovFormated, desiredWeaponFov);
		idCmd::setHandsFov(desiredWeaponFov);
	}

	else if (desiredWeaponFov == 0 && curWeaponFovFormated != 0) {
		idCmd::setHandsFov(desiredWeaponFov);
	}
}


