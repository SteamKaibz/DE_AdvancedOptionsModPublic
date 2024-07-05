#include "UserColorSet.h"


swfNamedColors_t UserColorSet::m_bloodpunch1Available_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideBloodPunchColor1);
swfNamedColors_t UserColorSet::m_bloodpunch2Available_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideBloodPunchColor2);
swfNamedColors_t UserColorSet::m_desperatePunchAvailable_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideDesperatePunchColor);

swfNamedColors_t UserColorSet::m_fragNadeAvailable_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideFragGrenadeAvailable_Color);

swfNamedColors_t UserColorSet::m_fragNadeCooldown_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideFragGrenadeCooldown_Color);

swfNamedColors_t UserColorSet::m_iceNadeAvailable_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideIceGrenadeAvailable_Color);
swfNamedColors_t UserColorSet::m_iceNadeCooldown_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideIceGrenadeCoolDown_Color);

swfNamedColors_t UserColorSet::m_radsuitMeterOveride_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideRadMeterColor);

//swfNamedColors_t UserColorSet::m_dotCrosshair_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideDotReticleColor);
//swfNamedColors_t UserColorSet::m_dotCrosshairCooldown_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideDotReticleCooldownColor);
//
//swfNamedColors_t UserColorSet::m_dotCrosshairFragReady_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideDotReticleFragNadeReadyColor);
//swfNamedColors_t UserColorSet::m_dotCrosshairIceReady_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideDotReticleIceNadeReadyColor);
//swfNamedColors_t UserColorSet::m_dotCrosshairBothNadesReady_Color = (swfNamedColors_t)(modSettingsDefault::g_defaultOverrideDotReticleBothNadesReadyColor);
//
//swfNamedColors_t UserColorSet::m_dotCrosshairColorFeaturesDisabled_Color = (swfNamedColors_t)(modSettingsDefault::g_DotColorFeatureDisabledColor);


const bool UserColorSet::m_AllowInvisibleColor = true;

uint64_t UserColorSet::m_lastIceIconPulseColorChangeMs = 0;
uint64_t UserColorSet::m_IceIconPulseFrequencyMs = 300;
bool UserColorSet::m_isIcePulseColorChange = false;
//const swfNamedColors_t UserColorSet::m_invisibleFlagColor = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE;
//const swfNamedColors_t UserColorSet::m_orangeForAllUiProfilesFlagColor = swfNamedColors_t::SWF_NAMED_COLOR_INVASION_YELLOW;



 swfNamedColors_t UserColorSet::getSwfNamedColorFromModSettings(int iniFileColorValInt) {


    //! sanity check. Also not letting user use invisible color.

    /*  if (iniFileColorValInt == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE) {
    logInfo("getSwfNamedColorFromIniFileColorId: found invisible color overwritting the default color...");
    return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
    }*/

    //! if out of range or invisible set default
    if (iniFileColorValInt < swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT || iniFileColorValInt >= swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE) {
        logWarn("getSwfNamedColorFromModSettings: found iniFileColorValInt out of bound: %d setting default color", iniFileColorValInt);
        return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
    }
    //int result = SWF_CUSTOM_NAMED_COLOR_DEFAULT + iniFileColorValInt;
    //int result = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT + iniFileColorValInt;
    logInfo("getSwfNamedColorFromModSettings: returning swfNamedColors_t: %d (int) ", iniFileColorValInt);
    return (swfNamedColors_t)iniFileColorValInt;
}

unsigned int UserColorSet::getCustomInvisibleColorUint() {
    logDebug("getCustomInvisibleColorUint");
    return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE;
}

 std::string UserColorSet::getSwfNamedColorString(swfNamedColors_t color) {

    switch (color) {
    case SWF_CUSTOM_NAMED_COLOR_DEFAULT:
        return "SWF_CUSTOM_NAMED_COLOR_DEFAULT";
    case SWF_CUSTOM_NAMED_COLOR_RED:
        return "SWF_CUSTOM_NAMED_COLOR_RED";
    case SWF_CUSTOM_NAMED_COLOR_GREEN:
        return "SWF_CUSTOM_NAMED_COLOR_GREEN";
    case SWF_CUSTOM_NAMED_COLOR_BLUE:
        return "SWF_CUSTOM_NAMED_COLOR_BLUE";
    case SWF_CUSTOM_NAMED_COLOR_YELLOW:
        return "SWF_CUSTOM_NAMED_COLOR_YELLOW";
    case SWF_CUSTOM_NAMED_COLOR_MAGENTA:
        return "SWF_CUSTOM_NAMED_COLOR_MAGENTA";
    case SWF_CUSTOM_NAMED_COLOR_CYAN:
        return "SWF_CUSTOM_NAMED_COLOR_CYAN";
    case SWF_CUSTOM_NAMED_COLOR_ORANGE:
        return "SWF_CUSTOM_NAMED_COLOR_ORANGE";
    case SWF_CUSTOM_NAMED_COLOR_PURPLE:
        return "SWF_CUSTOM_NAMED_COLOR_PURPLE";
    case SWF_CUSTOM_NAMED_COLOR_PINK:
        return "SWF_CUSTOM_NAMED_COLOR_PINK";
    case SWF_CUSTOM_NAMED_COLOR_BROWN:
        return "SWF_CUSTOM_NAMED_COLOR_BROWN";
    case SWF_CUSTOM_NAMED_COLOR_WHITE:
        return "SWF_CUSTOM_NAMED_COLOR_WHITE";
    case SWF_CUSTOM_NAMED_COLOR_LIGHTGREY:
        return "SWF_CUSTOM_NAMED_COLOR_LIGHTGREY";
    case SWF_CUSTOM_NAMED_COLOR_MIDGREY:
        return "SWF_CUSTOM_NAMED_COLOR_MIDGREY";
    case SWF_CUSTOM_NAMED_COLOR_DARKGREY:
        return "SWF_CUSTOM_NAMED_COLOR_DARKGREY";
    case SWF_CUSTOM_NAMED_COLOR_BLACK:
        return "SWF_CUSTOM_NAMED_COLOR_BLACK";
    case SWF_CUSTOM_NAMED_COLOR_LIGHTBLUE:
        return "SWF_CUSTOM_NAMED_COLOR_LIGHTBLUE";
    case SWF_CUSTOM_NAMED_COLOR_DARKBLUE:
        return "SWF_CUSTOM_NAMED_COLOR_DARKBLUE";
    case SWF_CUSTOM_NAMED_COLOR_LIGHTGREEN:
        return "SWF_CUSTOM_NAMED_COLOR_LIGHTGREEN";
    case SWF_CUSTOM_NAMED_COLOR_DARKGREEN:
        return "SWF_CUSTOM_NAMED_COLOR_DARKGREEN";
    case SWF_CUSTOM_NAMED_COLOR_LIGHTRED:
        return "SWF_CUSTOM_NAMED_COLOR_LIGHTRED";
    case SWF_CUSTOM_NAMED_COLOR_LIGHTYELLOW:
        return "SWF_CUSTOM_NAMED_COLOR_LIGHTYELLOW";
    case SWF_CUSTOM_NAMED_COLOR_DARKPURPLE:
        return "SWF_CUSTOM_NAMED_COLOR_DARKPURPLE";
    case SWF_CUSTOM_NAMED_COLOR_LIGHTPINK:
        return "SWF_CUSTOM_NAMED_COLOR_LIGHTPINK";
    case SWF_CUSTOM_NAMED_COLOR_DARKBROWN:
        return "SWF_CUSTOM_NAMED_COLOR_DARKBROWN";
    case SWF_CUSTOM_NAMED_COLOR_INVISIBLE:
        return "SWF_CUSTOM_NAMED_COLOR_INVISIBLE";
    default:
        return "Unknown color";
    }
}

 void UserColorSet::Update() {
    logDebug("Update");

    m_bloodpunch1Available_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideBloodPunchColor1());
    logInfo("m_bloodpunch1Available_Color: %s (%d)", getSwfNamedColorString(m_bloodpunch1Available_Color).c_str(), m_bloodpunch1Available_Color);

    m_bloodpunch2Available_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideBloodPunchColor2());
    logInfo("m_bloodpunch2Available_Color: %s (%d)", getSwfNamedColorString(m_bloodpunch2Available_Color).c_str(), m_bloodpunch2Available_Color);

    m_desperatePunchAvailable_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideDesperatePunchColor());
    logInfo("m_desperatePunchAvailable_Color: %s (%d)", getSwfNamedColorString(m_desperatePunchAvailable_Color).c_str(), m_desperatePunchAvailable_Color);

    m_fragNadeAvailable_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideFragGrenadeColor());
    logInfo("m_fragNadeAvailable_Color: %s (%d)", getSwfNamedColorString(m_fragNadeAvailable_Color).c_str(), m_fragNadeAvailable_Color);

    m_fragNadeCooldown_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideFragGrenadeCooldownColor());
    logInfo("m_fragNadeCooldown_Color: %s (%d)", getSwfNamedColorString(m_fragNadeCooldown_Color).c_str(), m_fragNadeCooldown_Color);

    m_iceNadeAvailable_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideIceGrenadeColor());
    logInfo("m_iceNadeAvailable_Color: %s (%d)", getSwfNamedColorString(m_iceNadeAvailable_Color).c_str(), m_iceNadeAvailable_Color);

    //x iceNadeCooldown icon is the only icon which is allowed by us to be invisible.
    m_iceNadeCooldown_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideIceGrenadeCooldownColor());
    logInfo("m_iceNadeCooldown_Color: %s (%d)", getSwfNamedColorString(m_iceNadeCooldown_Color).c_str(), m_iceNadeCooldown_Color);

    m_radsuitMeterOveride_Color = getSwfNamedColorFromModSettings(modSettings::getOverrideRadMeterColor());
    logInfo("m_radsuitMeterOveride_Color: %s (%d)", getSwfNamedColorString(m_radsuitMeterOveride_Color).c_str(), m_radsuitMeterOveride_Color);

    /*m_dotCrosshair_Color = getSwfNamedColorFromIniFileColorId(modSettings::getOverrideReticleColor());
    logInfo("m_dotCrosshair_Color: %s (%d)", getSwfNamedColorString(m_dotCrosshair_Color).c_str(), m_dotCrosshair_Color);

    m_dotCrosshairCooldown_Color = getSwfNamedColorFromIniFileColorId(modSettings::getOVerrideReticleCooldownColor());
    logInfo("m_dotCrosshairCooldown_Color: %s (%d)", getSwfNamedColorString(m_dotCrosshairCooldown_Color).c_str(), m_dotCrosshairCooldown_Color);

    m_dotCrosshairFragReady_Color = getSwfNamedColorFromIniFileColorId(modSettings::getOverrideDotReticleFragNadeReadyColor());
    logInfo("m_dotCrosshairFragReady_Color: %s (%d)", getSwfNamedColorString(m_dotCrosshairFragReady_Color).c_str(), m_dotCrosshairFragReady_Color);

    m_dotCrosshairIceReady_Color = getSwfNamedColorFromIniFileColorId(modSettings::getOverrideDotReticleIceNadeReadyColor());
    logInfo("m_dotCrosshairIceReady_Color: %s (%d)", getSwfNamedColorString(m_dotCrosshairIceReady_Color).c_str(), m_dotCrosshairIceReady_Color);

    m_dotCrosshairBothNadesReady_Color = getSwfNamedColorFromIniFileColorId(modSettings::getOverrideDotReticleBothNadeReadyColor());
    logInfo("m_dotCrosshairBothNadesReady_Color: %s (%d)", getSwfNamedColorString(m_dotCrosshairBothNadesReady_Color).c_str(), m_dotCrosshairBothNadesReady_Color);*/


}

 swfNamedColors_t UserColorSet::getBloodpunch_1_Color() {
    logDebug("getBloodpunch_1_Color");
    //logInfo("getBloodpunch_1_Color returning %d", m_bloodpunch1Available_Color);
    return m_bloodpunch1Available_Color;
}

 swfNamedColors_t UserColorSet::getBloodpunch_2_Color() {
   
    //logInfo("getBloodpunch_2_Color returning: %d", m_bloodpunch2Available_Color);
    return m_bloodpunch2Available_Color;
}

 swfNamedColors_t UserColorSet::getDesperatePunchColor() {
    return m_desperatePunchAvailable_Color;
}

 swfNamedColors_t UserColorSet::getIceNadeArrow_Color() {
    logDebug("getIceNadeArrow_Color");
    return m_iceNadeAvailable_Color;
    //if (IniFileData::getIsIceNadeIconPulse()) {
    //    if (EpochMillis() - m_lastIceIconPulseColorChangeMs > m_IceIconPulseFrequencyMs) {
    //        m_lastIceIconPulseColorChangeMs = EpochMillis();
    //        if (m_iceNadeAvailable_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_WHITE) {
    //        //if (m_iceNadeAvailable_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_BLACK) {
    //            m_iceNadeAvailable_Color = (swfNamedColors_t)IniFileData::getOverrideIceGrenadeColor();
    //        }
    //        else {
    //            m_iceNadeAvailable_Color = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_WHITE;
    //            //m_iceNadeAvailable_Color = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_BLACK;
    //        }
    //    }
    //}
    //logInfo("getIceNadeArrow_Color: m_iceNadeAvailable_Color is: %d", (int)m_iceNadeAvailable_Color);
    return m_iceNadeAvailable_Color;
}

 swfNamedColors_t UserColorSet::getIceNadeCooldownArrow_Color() {
    logDebug("getIceNadeCooldownArrow_Color");
    //logInfo("getIceNadeCooldownArrow_Color: m_iceNadeCooldown_Color: %d", (int)m_iceNadeCooldown_Color);
    return m_iceNadeCooldown_Color;
}

 swfNamedColors_t UserColorSet::getRadsuitMeter_Color() {

    return m_radsuitMeterOveride_Color;
}

 /*swfNamedColors_t UserColorSet::getDotCrosshair_Color() {
    logDebug("getDotCrosshair_Color");
    return m_dotCrosshair_Color;
}

 swfNamedColors_t UserColorSet::getDotCrosshairCoodown_Color() {
    logDebug("getDotCrosshairCoodown_Color");
    return m_dotCrosshairCooldown_Color;
}

 swfNamedColors_t UserColorSet::getDotCrosshairFragReady_Color() {
    logDebug("getDotCrosshairFragReady_Color");
    return m_dotCrosshairFragReady_Color;
}

 swfNamedColors_t UserColorSet::getDotCrosshairIceReady_Color() {
    logDebug("m_dotCrosshairIceReady_Color");
    return m_dotCrosshairIceReady_Color;
}

 swfNamedColors_t UserColorSet::getDotCrosshairBothNadesReady_Color() {
    logDebug("getDotCrosshairBothNadesReady_Color");
    return m_dotCrosshairBothNadesReady_Color;
}*/

 bool UserColorSet::isDefaultColor_Bloodpunch_1() {
    //logDebug("isDefaultColor_Bloodpunch_1");
    //bool result = m_bloodpunch1Available_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
    //logInfo("isDefaultColor_Bloodpunch_1: %d", result);
    return m_bloodpunch1Available_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
}

 bool UserColorSet::isDefaultColor_Bloodpunch_2() {
    return m_bloodpunch2Available_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
}

 bool UserColorSet::isDefaultColor_DesperatePunch() {
    return m_desperatePunchAvailable_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
}

 bool UserColorSet::isDefaultColorIceNadeArrow() {
    return m_iceNadeAvailable_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
}

 bool UserColorSet::isDefaultColorIceNadeCoolDownArrow() {
    return m_iceNadeCooldown_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
}

 bool UserColorSet::isDefaultColor_Radsuit() {
     //logInfo("isDefaultColor_Radsuit: m_radsuitMeterOveride_Color: %u", m_radsuitMeterOveride_Color);
    return m_radsuitMeterOveride_Color == swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
}

 /*bool UserColorSet::isCrosshairCooldownFeatureEnabled() {
    return m_dotCrosshairCooldown_Color != m_dotCrosshairColorFeaturesDisabled_Color;
}*/

// bool UserColorSet::isCrosshairFragReadyFeatureEnabled() {
//    /* bool result =  m_dotCrosshairFragReady_Color != m_dotCrosshairColorFeaturesDisabled_Color;
//    logInfo("debug: isCrosshairFragReadyFeatureEnabled: %d ", result);*/
//    return  m_dotCrosshairFragReady_Color != m_dotCrosshairColorFeaturesDisabled_Color;
//}
//
// bool UserColorSet::isCrosshairIceReadyFeatureEnabled() {
//    /*bool result = m_dotCrosshairIceReady_Color != m_dotCrosshairColorFeaturesDisabled_Color;
//    logInfo("debug: isCrosshairIceReadyFeatureEnabled: %d ", result);*/
//    return m_dotCrosshairIceReady_Color != m_dotCrosshairColorFeaturesDisabled_Color;
//}
//
// bool UserColorSet::isCrosshairBothNadesReadyFeatureEnabled() {
//    /* bool result = m_dotCrosshairBothNadesReady_Color != m_dotCrosshairColorFeaturesDisabled_Color;
//    logInfo("debug: isCrosshairBothNadesReadyFeatureEnabled: %d ", result);*/
//    return m_dotCrosshairBothNadesReady_Color != m_dotCrosshairColorFeaturesDisabled_Color;
//}
