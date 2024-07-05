#pragma once
#include <Windows.h>
#include <string>
#include "CommonDE.h"
#include "UtilsDE.h"
#include <vector>
#include <chrono>
#include "../Config/Config.h"
#include <queue>
//#include "Weapon.h"
//#include "idInventory.h"
#include "../ModSettings/modSettings.h"	
#include "idInventoryManager.h"
#include "idPlayer.h"
#include "idWeaponManager.h"


class WeaponSwitcher
{

private:

    //__int64 m_idHud_WeaponInfoPtr = 0;
    //static const uintptr_t Hud_WeaponInfoPtr_idDeclWeaponOffset = 0x100;
    uintptr_t  m_lastEquippedWeaponBaseAddr = -1;
    uintptr_t  m_lastCurrentWeaponDataAddr = 1;
    //static const uintptr_t currentlyEquippedWeaponDataOffset = 0x34;


    uint64_t m_lastIdplayerProcessInputTimeStampMs = 0;
    const UINT m_IdplayerProcessInputMaxTimeNoDataMs = 500; //! if no data from the func from half a seconds it means we're not ingame
    uint64_t m_lastWeaponInputPressMs = 0;
    weaponSlot_t m_UserRequestedWeaponIndex = weaponSlot_t::UNDEFINED;
    const int m_monitoredWeaponMinIndex = 1; //!  shotgun
    const int m_monitoredWeaponMaxIndex = 7; //!  minigun
    const unsigned int m_weaponSwitchCheckDelayMinMs = 300; // was 300
    const unsigned int m_weaponSwitchCheckDelayMaxMs = 600; // was 600
    usercmdButton m_weaponBtnToResend = usercmdButton::BUTTON_NONE;
    usercmdButton m_lastWeaponBtnToResend = usercmdButton::BUTTON_NONE;

    //int32_t m_lastInventoryItemsCount = 0;
    //PlayerInventory m_playerInventory;
    uint64_t m_lastInventoryGetMs = 0;
    //const unsigned int m_inventoryGetDelayMs = 6000;  //? each minute to not clutter the log for now...

    PlayerState m_lastPlayerState = PlayerState::unknown;

    //ItemID m_lastWeaponItemId = ItemID::Unknown;

    std::vector<std::string>m_monitoredWeaponsBaseNamesVec = { WeaponIdStr::g_shotGunBaseNameIdStr , WeaponIdStr::g_heavyCannonNameIdStr, WeaponIdStr::g_plasmaNameIdStr, WeaponIdStr::g_rocketLauncherNameIdStr, WeaponIdStr::g_superShotGunOnNameIdStr, WeaponIdStr::g_balistaNameIdStr };


public:

    /*void aquire_idHudWeaponInfoPtr(const __int64 idHud_WeaponInfoPtr)
    {       
        if (m_idHud_WeaponInfoPtr != idHud_WeaponInfoPtr) {
            m_idHud_WeaponInfoPtr = idHud_WeaponInfoPtr;
            logWarn("WeaponSwitcher::aquire_idHudWeaponInfoPtr: idHud_WeaponInfoPtr has changed and is now: %p ", (void*)idHud_WeaponInfoPtr);
        }
    }*/





    //Weapon GetcurrentlyEquippedWeapon()
    //{
    //    try
    //    {
    //        uintptr_t baseAddr = m_idHud_WeaponInfoPtr + Hud_WeaponInfoPtr_idDeclWeaponOffset;
    //        if (MemHelper::isBadReadPtr((void*)baseAddr)) {
    //            if (baseAddr != m_lastEquippedWeaponBaseAddr) {
    //                m_lastEquippedWeaponBaseAddr = baseAddr;
    //                logWarn("WeaponSwitcher::GetcurrentlyEquippedWeapon: found BadReadPtr for baseAddr: %p ", (void*)baseAddr);
    //            }
    //            //return m_currentWeaponIndexErrorVal;	
    //        }
    //        else {
    //            uintptr_t currentWeaponDataAddr = *(uintptr_t*)baseAddr + currentlyEquippedWeaponDataOffset;

    //            if (MemHelper::isBadReadPtr((void*)currentWeaponDataAddr)) {
    //                if (currentWeaponDataAddr != m_lastCurrentWeaponDataAddr) { //todo we should create a weapon object here....
    //                    m_lastCurrentWeaponDataAddr = currentWeaponDataAddr;
    //                    logWarn("WeaponSwitcher::GetcurrentlyEquippedWeapon: found BadReadPtr for currentWeaponDataAddr: %p ", (void*)currentWeaponDataAddr);
    //                }
    //            }
    //            else {
    //                //! we need weaponDataInt and not a WeaponData enum because we want to know the value if it's something we have not seen before as some weapon can be hands, suit, berzerk....
    //                return Weapon(*(unsigned int*)currentWeaponDataAddr);
    //            }
    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        logErr("WeaponSwitcher::GetcurrenlyEquippedWeapon: exception: %s ", ex.what());
    //    }
    //    return Weapon(unvalidWeapon);
    //    //return m_currentWeaponIndexErrorVal;
    //}



    void updateIdplayerProcessInputTimeStamp();

    bool isPlayerInGame();

    //! this should be triggered by SelectWeaponForSelectionGroupHook which itself is trigger when user presses a weapon key
    void updateLastWeapKeyPress(int weaponIndex);

    bool isRequestedWeaponMonitored();

    bool isWeaponSlotMonitored(weaponSlot_t weaponSlot);

    

    //bool isCurrentWeaponMonitored(idWeapon* idWeaponObj) {
    //    // Check if idWeaponObj is a null pointer
    //    if (idWeaponObj == nullptr) {
    //        logWarn("isCurrentWeaponMonitored: idWeaponObj is nullPtr returning false");
    //        return false;
    //    }

    //    // Ensure that idWeaponObj is a valid object
    //    try {
    //        const char* weaponName = idWeaponObj->getName();

    //        for (size_t i = 0; i < m_monitoredWeaponsBaseNamesVec.size(); i++) {

    //            // Check if the weapon name matches a monitored name
    //            if (weaponName != nullptr && strcmp(weaponName, m_monitoredWeaponsBaseNamesVec[i]) == 0) {
    //                return true;
    //            }
    //        }
    //    }
    //    catch (...) {
    //        logWarn("isCurrentWeaponMonitored: catch, how did that happen?");
    //        // Handle exceptions that may occur due to invalid memory access
    //        // You can log an error message or take appropriate action here
    //    }

    //    return false;
    //}

   /* bool isCurrentWeaponMonitored(idWeapon* idWeaponObj) {
        
        for (size_t i = 0; i < m_monitoredWeaponsBaseNamesVec.size(); i++)
        {
            if (strcmp(idWeaponObj->getName(), m_monitoredWeaponsBaseNamesVec[i]) == 0) {
                return true;
            }            
        }
        return false;

    }*/

    /*bool isEquippedWeaponMonitored(ItemID equippedWeaponItemID) {
        logDebug("isEquippedWeaponMonitored");

        if (equippedWeaponItemID == ItemID::Shotgun) {
            return true;
        }
        if (equippedWeaponItemID == ItemID::HeavyCannon) {
            return true;
        }
        if (equippedWeaponItemID == ItemID::PlasmaRifle) {
            return true;
        }
        if (equippedWeaponItemID == ItemID::RocketLauncher) {
            return true;
        }
        if (equippedWeaponItemID == ItemID::SuperShotgun) {
            return true;
        }
        if (equippedWeaponItemID == ItemID::Ballista) {
            return true;
        }
        if (equippedWeaponItemID == ItemID::MiniGun) {
            return true;
        }
        return false;
    }*/

    //int getWeaponSlotIndex(idWeapon* idWeaponObj) {
    //   /* if (idWeaponObj->getName() == ItemID::Shotgun) {
    //        return 1;
    //    }
    //    if (equippedWeaponItemID == ItemID::HeavyCannon) {
    //        return 2;
    //    }
    //    if (equippedWeaponItemID == ItemID::PlasmaRifle) {
    //        return 3;
    //    }
    //    if (equippedWeaponItemID == ItemID::RocketLauncher) {
    //        return 4;
    //    }
    //    if (equippedWeaponItemID == ItemID::SuperShotgun) {
    //        return 5;
    //    }
    //    if (equippedWeaponItemID == ItemID::Ballista) {
    //        return 6;
    //    }
    //    if (equippedWeaponItemID == ItemID::MiniGun) {
    //        return 7;
    //    }
    //    return -1;*/
    //}

    /*int getCurrentlyEquippedWeaponIndex(ItemID equippedWeaponItemID) {
        if (equippedWeaponItemID == ItemID::Shotgun) {
            return 1;
        }
        if (equippedWeaponItemID == ItemID::HeavyCannon) {
            return 2;
        }
        if (equippedWeaponItemID == ItemID::PlasmaRifle) {
            return 3;
        }
        if (equippedWeaponItemID == ItemID::RocketLauncher) {
            return 4;
        }
        if (equippedWeaponItemID == ItemID::SuperShotgun) {
            return 5;
        }
        if (equippedWeaponItemID == ItemID::Ballista) {
            return 6;
        }
        if (equippedWeaponItemID == ItemID::MiniGun) {
            return 7;
        }
        return -1;
    }*/

    ////! that's one way to trigger reset only once when game is loading.
    //void checkForInventoryCountReset(PlayerState currentPlayerState) {
    //    if (currentPlayerState != m_lastPlayerState) {
    //        if (currentPlayerState == PlayerState::inLoadingScreen) {
    //            resetInventoryCount();
    //        }
    //        m_lastPlayerState = currentPlayerState;
    //    }
    //}

    /*void resetInventoryCount() {
        if (m_lastInventoryItemsCount != 0) {
            m_lastInventoryItemsCount = 0;
            logInfo("Player Inventory count has been reset");
        }
        
    }*/
 
    //void checkWeaponSwitch(IniFileData& iniFileData){
    //   

    //    int currentWeaponIndex = getCurrentlyEquippedWeaponIndex(currentWeaponItemID);
    //    if (currentWeaponIndex == -1) return; //! if not monitored weapon

    //    //! getting inventory count if count has changed or time has passed.
    //    if (m_lastInventoryItemsCount != idPlayer_K::getInventoryCount() || ((EpochMillis() - m_lastInventoryGetMs) > m_inventoryGetDelayMs)) {           
    //        m_playerInventory = idInventoryCollectionManager::getPlayerInventory();
    //        if (Config::isAuthorDebugMode()) {
    //            logInfo("player InventoryCount is now:  %d ", (int)idPlayer_K::getInventoryCount());
    //        }
    //        m_lastInventoryGetMs = EpochMillis();
    //        m_lastInventoryItemsCount = idPlayer_K::getInventoryCount();
    //    }
    //    //auto playerInventory = idInventoryCollectionManager::getPlayerInventory();        
    //    
    //    if (isRequestedWeaponMonitored(m_UserRequestedWeaponIndex) && (m_playerInventory.isWeaponOwned(m_UserRequestedWeaponIndex)) && currentWeaponIndex != m_UserRequestedWeaponIndex) {
    //        uint64_t epochNowMs = EpochMillis();
    //        //spdlog::info("WeaponSwitcher::checkWeaponSwitch  currentWeapon.getIndex() {}", currentWeapon.getIndex());
    //        if (((epochNowMs - m_lastWeaponInputPressMs) > m_weaponSwitchCheckDelayMinMs) && ((epochNowMs - m_lastWeaponInputPressMs) < m_weaponSwitchCheckDelayMaxMs)) {
    //            if (Config::isAuthorDebugMode()) {
    //                logInfo("checkWeaponSwitch: force weapon switch triggered. Requested weapon index: %d currentWeaponIndex index: %d ", m_UserRequestedWeaponIndex, currentWeaponIndex);
    //            }
    //            setWeaponEnumToResend(m_UserRequestedWeaponIndex);
    //            if (iniFileData.isImprovedWeaponSwitchingBeep()) {
    //                playWeaponSwitchOverideSound();
    //                //? not sure about using thread for beep...it's a debug tool anyway so keep it sync.
    //                //playWeaponSwitchOverideSoundAsync();
    //            }
    //            
    //            //resendLastWeaponUserInput(getWeaponUserInputIndex(m_UserRequestedWeaponIndex));
    //            //resendLastWeapKeyTest();
    //            //m_isWeaponSwitchFixNeeded = false;
    //        }
    //    }
    //}

   //! this is a bit of a mess, will need refactor
    void checkWeaponSwitchV2();

    //? temp bak:
    //void checkWeaponSwitchV2() {
    //    //logInfo("checkWeaponSwitch called");

    //    weaponSlot_t currentWeaponSlot = idPlayer_K::getcurrentWeaponSlotIndex();

    //    if (!isWeaponSlotMonitored(currentWeaponSlot)) {
    //        return;
    //    }
    //    if (!isRequestedWeaponMonitored()) {
    //        return;
    //    }
    //    if (!idInventoryCollectionManager::isWeaponOwned(m_UserRequestedWeaponIndex)) {
    //        return;
    //    }

    //    if (currentWeaponSlot != m_UserRequestedWeaponIndex) {
    //        uint64_t epochNowMs = EpochMillis();
    //        //spdlog::info("WeaponSwitcher::checkWeaponSwitch  currentWeapon.getIndex() {}", currentWeapon.getIndex());
    //        if (((epochNowMs - m_lastWeaponInputPressMs) > m_weaponSwitchCheckDelayMinMs) && ((epochNowMs - m_lastWeaponInputPressMs) < m_weaponSwitchCheckDelayMaxMs)) {
    //            logInfo("checkWeaponSwitch: force weapon switch triggered. Requested weapon index: %d currentWeaponSlot index: %d ", m_UserRequestedWeaponIndex, (int)currentWeaponSlot);

    //            setWeaponEnumToResend();

    //            if (IniFileData::isImprovedWeaponSwitchingBeep()) {
    //                playWeaponSwitchOverideSound();
    //                //? not sure about using thread for beep...it's a debug tool anyway so keep it sync.
    //                //playWeaponSwitchOverideSoundAsync();
    //            }

    //            //resendLastWeaponUserInput(getWeaponUserInputIndex(m_UserRequestedWeaponIndex));
    //            //resendLastWeapKeyTest();
    //            //m_isWeaponSwitchFixNeeded = false;
    //        }
    //    }
    //}
   

    void setWeaponEnumToResend();


    std::string enumToString(usercmdButton button);

    /// <summary>
    /// this doesn't just return a bool it also sets m_weaponBtnToResend to none so we only send weapon once until another order to send is decided by the algo.
    /// </summary>
    /// <param name="weaponBtn"></param>
    /// <returns></returns>
    bool isWeaponBtnToResend(usercmdButton weaponBtn);

    void disableEnumResend(usercmdButton btn);



    //ItemID getCurrentWeaponItemID() {
    //    auto currentWeaponItemId = ItemID::Unknown;
    //    try
    //    {   //! this IdDeclWeaponAddr is not the one which pointer changes when mod changes (that would be getCurrentIdWeaponAddr() + 0x3708 but at the start of the game when no mod exist getCurrentIdWeaponAddr() + 0x3708 should be bad ptr). We get the current weapon id not from idPlayer cause the way we get it in ObjectLocator is more reliable, but it sure could be in idplayer but i would have to reverse more...
    //        __int64 CurrentIdDeclWeaponAddr = ObjectLocator::getCurrentIdWeaponAddr() + 0x38;
    //        //__int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();

    //        if (!MemHelper::isBadReadPtr((void*)CurrentIdDeclWeaponAddr)) {

    //            //__int64 equipped_idDeclWeaponAddr = *(__int64*)(idPlayerAddr + 0x7188);
    //            __int64 idDeclWeaponPtr = *(__int64*)(CurrentIdDeclWeaponAddr);
    //            //if (!MemHelper::isBadReadPtr((void*)equipped_idDeclWeaponAddr)) {
    //            if (!MemHelper::isBadReadPtr((void*)idDeclWeaponPtr)) {
    //                idDeclWeapon* equipped_idDeclWeapon = (idDeclWeapon*)idDeclWeaponPtr;
    //                //idDeclWeapon_t* equipped_idDeclWeapon = (idDeclWeapon_t*)equipped_idDeclWeaponAddr;                    
    //                //x the other id which would be the one at offset 0x34 would be 7113 at the start of the game for the shotgun when no mod has been installed...let's see if it's the same at the end of the game...i confirm it's also 7113. so i suppose we could use that instead of ItemID but, if it works as it is then....                    
    //                currentWeaponItemId =  convertToItemID(equipped_idDeclWeapon->resourceID);
    //                /* logInfo("setGrenadeType: idPlayerPtr is %p idPlayerPtr->EquippedGrenadeType is: %d", idPlayerPtr,(int)idPlayerPtr->EquippedGrenadeType);*/
    //            }
    //            else {
    //                logErr("getCurrentWeaponItemID: can not getCurrentWeaponItemID because equipped_idDeclWeaponAddr is bad ptr");
    //            }
    //        }
    //        else {
    //            logWarn("getCurrentWeaponItemID: can not getCurrentWeaponItemID because CurrentIdDeclWeaponAddr + 0x38 is bad ptr");
    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        logErr("getCurrentWeaponItemID: ERROR: %s ", ex.what());
    //    }
    //    if ((currentWeaponItemId != m_lastWeaponItemId)) {
    //        m_lastWeaponItemId = currentWeaponItemId;
    //        printWeaponNameFromIdInfo(currentWeaponItemId);
    //    }
    //    return currentWeaponItemId;
    //    //return ItemID::Unknown;
    //}

    /*void printWeaponNameFromIdInfo(ItemID itemId) {
        logDebug("printWeaponNameFromIdInfo");

        switch (itemId)
        {
        case ItemID::Unknown:
            logInfo("Currently equipped Weapon has changed and is now...Unknown?!");
            break;
        case ItemID::Shotgun:
            logInfo("Currently equipped Weapon has changed and is now Shotgun");
            break;
        case ItemID::HeavyCannon:
            logInfo("Currently equipped Weapon has changed and is now HeavyCannon");
            break;
        case ItemID::PlasmaRifle:
            logInfo("Currently equipped Weapon has changed and is now PlasmaRifle");
            break;
        case ItemID::RocketLauncher:
            logInfo("Currently equipped Weapon has changed and is now RocketLauncher");
            break;
        case ItemID::SuperShotgun:
            logInfo("Currently equipped Weapon has changed and is now SuperShotgun");
            break;
        case ItemID::Ballista:
            logInfo("Currently equipped Weapon has changed and is now Ballista");
            break;
        case ItemID::MiniGun:
            logInfo("Currently equipped Weapon has changed and is now MiniGun");
            break;
        case ItemID::Bfg:
            logInfo("Currently equipped Weapon has changed and is now Bfg");
            break;
        case ItemID::Unmaykr:
            logInfo("Currently equipped Weapon has changed and is now Unmaykr");
            break;
        case ItemID::Crucible:
            logInfo("Currently equipped Weapon has changed and is now Crucible");
            break;
        case ItemID::Hammer:
            logInfo("Currently equipped Weapon has changed and is now Hammer");
            break;       
        default:
            logInfo("Currently equipped Weapon has changed and is now..default?!");
            break;
        }
    }*/


    /* ItemID convertToItemID(uint64_t idDeclWeaponID) {
         logDebug("convertToItemID");

        if (idDeclWeaponID == (uint64_t)ItemID::Shotgun) {
            return ItemID::Shotgun;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::HeavyCannon) {
            return ItemID::HeavyCannon;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::PlasmaRifle) {
            return ItemID::PlasmaRifle;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::RocketLauncher) {
            return ItemID::RocketLauncher;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::SuperShotgun) {
            return ItemID::SuperShotgun;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::Ballista) {
            return ItemID::Ballista;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::MiniGun) {
            return ItemID::MiniGun;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::Bfg) {
            return ItemID::Bfg;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::Unmaykr) {
            return ItemID::Unmaykr;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::Crucible) {
            return ItemID::Crucible;
        }
        else if (idDeclWeaponID == (uint64_t)ItemID::Hammer) {
            return ItemID::Hammer;
        }
        else {
            return ItemID::Unknown;
        }
    }*/

};

