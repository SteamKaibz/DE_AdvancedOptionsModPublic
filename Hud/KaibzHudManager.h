#pragma once

#define NOMINMAX // for std::max

#include "Windows.h"
#include <string>
#include "../DE/GeneratedEnums.h"
#include "../K_Utils/K_Utils.h"
#include "../DE/idHudManager.h"
#include "../ModSettings/modSettings.h"
//#include "kaibzHudData.h";







class KaibzHudManager
{
private:


public:

	//! the health, armor value are floats, if for ex health is 110.01, on the hud it will/should display 111. But if the value is 110.000 i 'think' the value will be 110 but it's hard to test. but when you die the value as float is 0 and on the hud it's 0, and when the max value is reached the int and float are the same.
	static std::string getHudValueAsStr(float valueF, float maxValue);

	static int getIntVal(float valueF, float maxValue);
	

	static ImU32 getCustomCrosshairHealthAsImU32Color(float currentHealthValue, float MaxHealthValue, float currentArmorValue, float MaxArmorValue);

	static KaibzHudColor_t get3StagesCorlor(float currentValue, float MaxValue, KaibzHudColor_t normalColor);

	//static int getIceNadeCooldownTimeLeft();
	

	static float getIceNadeCooldownProgress();

	static KaibzHudData getData();

	//static KaibzHudData get();
	static std::string getDdgStrForImgui();
	static KaibzHudData getTestData();
	//static void updateData();

};

