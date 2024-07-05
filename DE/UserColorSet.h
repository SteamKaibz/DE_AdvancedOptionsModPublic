#pragma once

#include "CommonDE.h"
#include "../ModSettings/modSettings.h"
//#include "GameHudColorsManager.h"




class UserColorSet
{

private:
	//UserColorSetType_t m_colorSetType;

    //static const int m_customNamedColorsIdOffset;

	static swfNamedColors_t m_bloodpunch1Available_Color;
	static swfNamedColors_t m_bloodpunch2Available_Color;
	static swfNamedColors_t m_desperatePunchAvailable_Color;

    static swfNamedColors_t m_fragNadeAvailable_Color;
    static swfNamedColors_t m_fragNadeCooldown_Color;

	static swfNamedColors_t m_iceNadeAvailable_Color;
    static swfNamedColors_t m_iceNadeCooldown_Color;

	static swfNamedColors_t m_radsuitMeterOveride_Color;


	static swfNamedColors_t m_dotCrosshairColorFeaturesDisabled_Color;

    static const bool m_AllowInvisibleColor;


    static uint64_t m_IceIconPulseFrequencyMs;
    static uint64_t m_lastIceIconPulseColorChangeMs;
    static bool m_isIcePulseColorChange;

    //static const swfNamedColors_t m_invisibleFlagColor; //! this is used as a lure so that our hook will set the color of the element to invisible when it sees this colorId

    

    static swfNamedColors_t getSwfNamedColorFromModSettings(int iniFileColorValInt);
	


public:

    /*static int getCustomNamedColorsOffsetStart() {
        return m_customNamedColorsIdOffset;
    }*/

    static unsigned int getCustomInvisibleColorUint();

   /* static swfNamedColors_t getAbsoluteOrangeFlagColorId() {
        return m_orangeForAllUiProfilesFlagColor;
    }*/

    //? this has a dangling ptr issue, leaving it here for documentation:
   /* static const char* getColorAsC_String(swfNamedColors_t color) {
        return getColorAsString(color).c_str();
    }*/

   

    static std::string getSwfNamedColorString(swfNamedColors_t color);



	static void Update();



	static swfNamedColors_t getBloodpunch_1_Color();

	static swfNamedColors_t getBloodpunch_2_Color();

    static swfNamedColors_t getDesperatePunchColor();
	

   

	static swfNamedColors_t getIceNadeArrow_Color();

    static swfNamedColors_t getIceNadeCooldownArrow_Color();

	static swfNamedColors_t getRadsuitMeter_Color();

    //static swfNamedColors_t getDotCrosshair_Color();

    //static swfNamedColors_t getDotCrosshairCoodown_Color();

    //static swfNamedColors_t getDotCrosshairFragReady_Color();

    //static swfNamedColors_t getDotCrosshairIceReady_Color();

    //static swfNamedColors_t getDotCrosshairBothNadesReady_Color();



    





	static bool isDefaultColor_Bloodpunch_1();

	static bool isDefaultColor_Bloodpunch_2();

    static bool isDefaultColor_DesperatePunch();

	static bool isDefaultColorIceNadeArrow();

    static bool isDefaultColorIceNadeCoolDownArrow();
   

	static bool isDefaultColor_Radsuit();


    //static bool isCrosshairCooldownFeatureEnabled();

    //static bool isCrosshairFragReadyFeatureEnabled();

    //static bool isCrosshairIceReadyFeatureEnabled();

    //static bool isCrosshairBothNadesReadyFeatureEnabled();
    /*static swfNamedColors_t convertIniFileColorIdtoCustomSwfNamedColor(int iniFileColorId) {
        swfNamedColors_t result = static_cast<swfNamedColors_t>(swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT + iniFileColorId);
        logInfo("convertIniFileColorIdtoCustomSwfNamedColor returning: %d for input iniFileColorId: %d", (int)result, iniFileColorId);
        return result;
    }*/

};

//const int UserColorSet::m_customNamedColorsIdOffset = 1000;


