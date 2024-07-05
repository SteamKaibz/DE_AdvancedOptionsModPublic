#include "WeaponSwitcher.h"

 void WeaponSwitcher::updateIdplayerProcessInputTimeStamp()
{
    logDebug("updateIdplayerProcessInputTimeStamp");

    m_lastIdplayerProcessInputTimeStampMs = EpochMillis();
}

 bool WeaponSwitcher::isPlayerInGame()
{
    logDebug("isPlayerInGame");
    return ((EpochMillis() - m_lastIdplayerProcessInputTimeStampMs) < m_IdplayerProcessInputMaxTimeNoDataMs);
}

//! this should be triggered by SelectWeaponForSelectionGroupHook which itself is trigger when user presses a weapon key

 void WeaponSwitcher::updateLastWeapKeyPress(int weaponIndex)
{
    logDebug("updateLastWeapKeyPress");

    // debug: 
    //static int lastWeaponIndex = -2;
    //static weaponSlot_t lastUserRequestedWeaponIndex = weaponSlot_t::UNDEFINED;


    m_lastWeaponInputPressMs = EpochMillis();

    m_UserRequestedWeaponIndex = (weaponSlot_t)weaponIndex;

    //? this should be triggered before SelectWeaponForSelectionGroupHook debug log because...it's from our hook so ofc it happens first
    /*if (weaponIndex != lastWeaponIndex) {
    lastWeaponIndex = weaponIndex;
    logInfo("updateLastWeapKeyPress: weapon Key pressed has changed to: %d ", weaponIndex);
    }*/

    /* if (m_UserRequestedWeaponIndex != lastUserRequestedWeaponIndex) {
    lastUserRequestedWeaponIndex = m_UserRequestedWeaponIndex;
    logInfo("updateLastWeapKeyPress: m_UserRequestedWeaponIndex:  has changed to: %d ", (int)m_UserRequestedWeaponIndex);
    }*/

}

 bool WeaponSwitcher::isRequestedWeaponMonitored()
{
    logDebug("isRequestedWeaponMonitored");

    //return ((weaponIndex >= m_monitoredWeaponMinIndex) && (weaponIndex <= m_monitoredWeaponMaxIndex));
    return isWeaponSlotMonitored(m_UserRequestedWeaponIndex);
}

 bool WeaponSwitcher::isWeaponSlotMonitored(weaponSlot_t weaponSlot) {
    logDebug("isWeaponSlotMonitored");

    switch (weaponSlot) {
    case weaponSlot_t::SHOTGUN:
    case weaponSlot_t::HAR:
    case weaponSlot_t::PLASMA:
    case weaponSlot_t::ROCKET:
    case weaponSlot_t::SSG:
    case weaponSlot_t::BALLISTA:
    case weaponSlot_t::CHAINGUN:
    case weaponSlot_t::BFG_UNMAYKR:
        return true;
    default:
        return false;
    }
}

//! this is a bit of a mess, will need refactor

 void WeaponSwitcher::checkWeaponSwitchV2() {

    //logInfo("checkWeaponSwitch called");



    static weaponSlot_t lastCurrentWeaponSlot = weaponSlot_t::UNDEFINED;

    uint64_t epochNowMs = EpochMillis();


    //! strangly enough idPlayer_K::getcurrentWeaponSlotIndex is 'faster to get the current slot by 100ms but that's ofc because of polling rate and when the idWeaponManager hook is triggered by the game, but idWeaponManager is good enough
    // idWeaponManager::getCurWeaponSlot();

    weaponSlot_t currentWeaponSlot = idWeaponManager::getCurWeaponSlot();
    //weaponSlot_t currentWeaponSlot = idPlayer_K::getcurrentWeaponSlotIndex();

    /* if (currentWeaponSlot != lastCurrentWeaponSlot) {
    lastCurrentWeaponSlot = currentWeaponSlot;
    logInfo("checkWeaponSwitchV2 currentWeaponSlot has changed to %d", currentWeaponSlot);
    }*/

    if (!((epochNowMs - m_lastWeaponInputPressMs) > m_weaponSwitchCheckDelayMinMs && (epochNowMs - m_lastWeaponInputPressMs) < m_weaponSwitchCheckDelayMaxMs)) {
        // If the condition is NOT true, return from the function here
        return; //! return if too soon or too late
    }
    //logInfo("checkWeaponSwitchV2 check started....");

    if (!isWeaponSlotMonitored(currentWeaponSlot)) {
        return;
    }
    if (!isRequestedWeaponMonitored()) {
        return;
    }
    if (!idInventoryCollectionManager::isWeaponOwned(m_UserRequestedWeaponIndex)) {
        //if (!idInventoryCollectionManager::debug_isWeaponOwned(m_UserRequestedWeaponIndex)) {
        return;
    }
    if (currentWeaponSlot != m_UserRequestedWeaponIndex) {

        logInfo("checkWeaponSwitch: Force weapon switch triggered. m_UserRequestedWeaponIndex: %d currentWeaponSlot index: %d ", m_UserRequestedWeaponIndex, (int)currentWeaponSlot);

        setWeaponEnumToResend();

        if (modSettings::isImprovedWeaponSwitchingBeep()) {
            playWeaponSwitchOverideSound();
            //? not sure about using thread for beep...it's a debug tool anyway so keep it sync.
            //playWeaponSwitchOverideSoundAsync();
        }
    }
}

 void WeaponSwitcher::setWeaponEnumToResend() {
    logDebug("setWeaponEnumToResend");

    //spdlog::warn("WeaponSwitcher::setWeaponEnumToResend requestedWeaponIndex {}", requestedWeaponIndex);
    //logInfo("setWeaponEnumToResend: m_UserRequestedWeaponIndex is: %d ", m_UserRequestedWeaponIndex);

    switch (m_UserRequestedWeaponIndex)
    {
    case weaponSlot_t::SHOTGUN:
        m_weaponBtnToResend = usercmdButton::BUTTON_SHOTGUN;
        break;
    case weaponSlot_t::HAR:
        m_weaponBtnToResend = usercmdButton::BUTTON_ASSAULT_RIFFLE;
        break;
    case weaponSlot_t::PLASMA:
        m_weaponBtnToResend = usercmdButton::BUTTON_PLASMA;
        break;
    case weaponSlot_t::ROCKET:
        m_weaponBtnToResend = usercmdButton::BUTTON_RL;
        break;
    case weaponSlot_t::SSG:
        m_weaponBtnToResend = usercmdButton::BUTTON_SUPER_SHOTGUN;
        break;
    case weaponSlot_t::BALLISTA:
        m_weaponBtnToResend = usercmdButton::BUTTON_BALISTA;
        break;
    case weaponSlot_t::CHAINGUN:
        m_weaponBtnToResend = usercmdButton::BUTTON_MINIGUN;
        break;
        //? not using this one cause the key is a toggle it could actually create issues
        /* case weaponSlot_t::BFG_UNMAYKR:
        m_weaponBtnToResend = usercmdButton::BUTTON_BFG_UNMAKER;
        break;*/
        /*case weaponSlot_t::WEAPON_9:
        break;
        case weaponSlot_t::CRUCIBLE_HAMMER:
        break;
        case weaponSlot_t::MAX_WEAPON_SLOT:
        break;*/
    default:
        m_weaponBtnToResend = usercmdButton::BUTTON_NONE;
        break;
    }
    /*if (m_weaponBtnToResend != m_lastWeaponBtnToResend) {
    m_lastWeaponBtnToResend = m_weaponBtnToResend;
    logInfo("setWeaponEnumToResend m_weaponBtnToResend has changed to %llX (hex)", (__int64)m_weaponBtnToResend);
    }*/


    if (m_weaponBtnToResend != m_lastWeaponBtnToResend) {
        m_lastWeaponBtnToResend = m_weaponBtnToResend;
        logInfo("setWeaponEnumToResend m_weaponBtnToResend has changed to: %s", enumToString(m_weaponBtnToResend).c_str());
    }
}

 std::string WeaponSwitcher::enumToString(usercmdButton button) {
    logDebug("enumToString");

    switch (button) {
    case usercmdButton::BUTTON_WEAP_0: return "BUTTON_WEAP_0";
    case usercmdButton::BUTTON_SHOTGUN: return "BUTTON_SHOTGUN";
    case usercmdButton::BUTTON_ASSAULT_RIFFLE: return "BUTTON_ASSAULT_RIFFLE";
    case usercmdButton::BUTTON_PLASMA: return "BUTTON_PLASMA";
    case usercmdButton::BUTTON_RL: return "BUTTON_RL";
    case usercmdButton::BUTTON_SUPER_SHOTGUN: return "BUTTON_SUPER_SHOTGUN";
    case usercmdButton::BUTTON_BALISTA: return "BUTTON_BALISTA";
    case usercmdButton::BUTTON_MINIGUN: return "BUTTON_MINIGUN";
    case usercmdButton::BUTTON_BFG_UNMAKER: return "BUTTON_BFG_UNMAKER";
    case usercmdButton::BUTTON_WEAP_9: return "BUTTON_WEAP_9";
    case usercmdButton::BUTTON_BFG: return "BUTTON_BFG";
    case usercmdButton::BUTTON_WALK: return "BUTTON_WALK";
    case usercmdButton::BUTTON_DASH: return "BUTTON_DASH";
    case usercmdButton::BUTTON_USE_EQUIPMENT: return "BUTTON_USE_EQUIPMENT";
    case usercmdButton::BUTTON_SWITCH_EQUIPMENT: return "BUTTON_SWITCH_EQUIPMENT";
    case usercmdButton::BUTTON_QUICK_1: return "BUTTON_QUICK_1";
    case usercmdButton::BUTTON_QUICK_2: return "BUTTON_QUICK_2";
    case usercmdButton::BUTTON_QUICK_3: return "BUTTON_QUICK_3";
    case usercmdButton::BUTTON_CRUCIBLE_HAMMER: return "BUTTON_CRUCIBLE_HAMMER";
    case usercmdButton::BUTTON_OBJECTIVES: return "BUTTON_OBJECTIVES";
    default: return "Unknown Button";
    }
}

/// <summary>
/// this doesn't just return a bool it also sets m_weaponBtnToResend to none so we only send weapon once until another order to send is decided by the algo.
/// </summary>
/// <param name="weaponBtn"></param>
/// <returns></returns>

 bool WeaponSwitcher::isWeaponBtnToResend(usercmdButton weaponBtn)
{

    if (weaponBtn == m_weaponBtnToResend) {
        m_weaponBtnToResend = usercmdButton::BUTTON_NONE;
        //spdlog::warn("WeaponSwitcher::isWeaponBtnToResend returning true for {:x} and setting m_weaponBtnToResend to BUTTON_NONE", (__int64)(weaponBtn));
        /*if (Config::getVersion() == ModDebugVersion::modeDebugConsole || Config::getVersion() == ModDebugVersion::modDebugFileLog) {
        Beep(1500, 50);
        }*/
        return true;
    }
    return false;
}

 void WeaponSwitcher::disableEnumResend(usercmdButton btn)
{

    //logInfo("WeaponSwitcher::disableEnumResend() triggered by button enum: %llx", (__int64)(btn));
    //! hopefully this should do the trick to disable the resend of btn until next trigger.
    m_lastWeaponInputPressMs = 0;
}
