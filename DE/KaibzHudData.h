#pragma once
#include <string>
#include "idLib_Dynamic.h"
#include "../ImGui/dependencies/imgui/imgui.h"
#include "../DE/CommonDE.h"
#include "enumsCustom.h"


class KaibzHudData {

public:
	const int hudNumberMaxValue = 999;
	const std::string hudNumberMaxValueStr = "999";

	//! if >0 || infinite =>  user color otherwise: greyed out.
	//? you can have zero but if is infinite it should be colored
	int extraLives = 0;
	KaibzHudColor_t extraLivesColor = KaibzHudColor_t::disabledColor;

	//! 0 => grey  1 => user color 1, 2 => user color 2, 3(desp punch) => user color 3 
	int bloodPunchCount = 0; //todo could have option to show them as float on hud ?
	bool isDesperatePunchReady = false; //! get it from idPlayer_K::isDesperatePunchAvailable()
	//bool isBloodPunchFlash = false;
	KaibzHudColor_t bloodPunchColor = KaibzHudColor_t::disabledColor;

	//! maxed, normal, low, critical. max and normal could be set by user, the other would be from customisable warning and critical colors.
	int health = 0;
	std::string healthStr = "0";
	KaibzHudColor_t healthColor = KaibzHudColor_t::disabledColor;
	//HealthState_K healthState = HealthState_K::normal;

	//! maxed, normal defined by user 
	int armor = 0;
	std::string armorStr = "0";
	KaibzHudColor_t armorColor = KaibzHudColor_t::disabledColor;
	//ArmorState armorState = ArmorState::normal;	

	//! normal color defined by user + warning and critical color 
	bool isRadsuitEquipped = false;
	KaibzHudColor_t radsuitColor = KaibzHudColor_t::disabledColor;
	//MeterState_K radsuitState = MeterState_K::normal; //! the warning, max and potentially critical colors will all be the same for each element


	//! normal color defined by user + warning and critical color 
	bool isOxygenEquipped = false;
	KaibzHudColor_t oxygenColor = KaibzHudColor_t::disabledColor;
	//MeterState_K oxygenState = MeterState_K::normal;


	//! normal color defined by user + low (warning or critical?) color. if is infinite set it to 999.
	int ammo = 0;
	std::string ammoStr = "0";
	KaibzHudColor_t ammoColor = KaibzHudColor_t::disabledColor;
	bool isInfinite = false;
	//AmmoState_K ammoState = AmmoState_K::normal;		


	//! if we own the crucible and the hammer, the hammer has priority to be shown it seems. 
	bool isHammerShownOnHud = false;
	int hammerCharges = 0;
	//bool isHammerFlash = false; //! used to trigger a hud flash
	KaibzHudColor_t hammerColor = KaibzHudColor_t::disabledColor;

	bool isCrucibleShownOnHud = false;
	int crucibleCharges = 0;
	KaibzHudColor_t crucibleColor = KaibzHudColor_t::disabledColor;

	//! We don't care if we own the equipments or not, we just check the charges and show them as greyed even if we don't own them.
	int flamebelchCharges = 0;
	KaibzHudColor_t flamebelchColor = KaibzHudColor_t::disabledColor;

	int fuelCharges = 0;
	KaibzHudColor_t fuelColor = KaibzHudColor_t::disabledColor;



	bool isFragSelected = true;

	int fragCharges = 0;
	//bool isFragFlash = false;
	KaibzHudColor_t fragColor = KaibzHudColor_t::disabledColor;


	int iceCharges = 0;
	//bool isIceFlash = false;
	float iceNadeCooldownProgress = 0;
	KaibzHudColor_t iceColor = KaibzHudColor_t::disabledColor;

	bool isHudFlash = false;
	ImU32 hudFlashColor = modSettingsDefault::g_defaultkaibzHudWhiteColorImU32;

	ImU32 crosshairHealthColorImU32 = modSettingsDefault::g_defaultkaibzHudDisabledColorImU32;

};
