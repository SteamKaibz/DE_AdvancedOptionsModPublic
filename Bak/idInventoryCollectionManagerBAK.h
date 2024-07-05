#pragma once

#pragma once
#include <Windows.h>
#include<iostream>
#include <vector>
#include <string>
#include "Common.h"
#include "Utils.h"
#include "Types.h"
#include "../Config/Config.h"
#include "PlayerInventory.h"
#include "idMapInstanceLocalManager.h"
#include "DE/GeneratedClasses.h"


//#include "Hud/HudAmmoData.h"
//#include "Scanner.h"





//struct InventoryItem {
//    unsigned int ID = 0; //! some items will have an ID of 0 and some will have same IDs keep that in mind
//    std::string Name = "unknown";
//    int Count = -1;
//};


class idInventoryCollectionManager
{
private:


    static __int64 m_getInventoryItemFuncAddr;

    static std::vector<unsigned int>m_ownedItemIds;

    static std::atomic<std::vector<unsigned int>*> m_ownedItemIdsPtr;

    //static std::vector<InventoryItem> m_inventoryItemsVec;

    //PlayerInventory m_playerInventory;

    //! __int64 __fastcall idInventoryCollection::GetInventoryItem_1D1D6A0(__int64 a1, int a2)
    typedef __int64(__fastcall* idInventoryCollection_GetInventoryItem)(__int64 a1, int a2);
    //static idInventoryCollection_GetInventoryItem pidInventoryCollection_GetInventoryItem;


public:


    static bool acquirreGetInventoryItemFuncAddr(__int64 getInventoryItemFuncAddr) {
        logDebug("acquirreGetInventoryItemFuncAddr");
        if (MemHelper::isBadReadPtr((void*)getInventoryItemFuncAddr)) {
            return false;
        }
        m_getInventoryItemFuncAddr = getInventoryItemFuncAddr;
        logInfo("acquirremGetInventoryItemFuncAddr: m_getInventoryItemFuncAddr is being set to %p", (void*)m_getInventoryItemFuncAddr);
        return true;
    }


    //! even if we don't use this anymore, i think it's good that we iterate through idInventoryCollection instead of caching items because some code is triggered by the loop and other code by the hooks and i don't want to have to use mutex, so yes the code is repeated but at least it's kind of safe imo.
    static idWeapon* getIdWeapon(ItemID itemId) {
        logDebug("getIdWeapon");

        idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

        if (pIdActor) {
            for (int i = 0; i < pIdActor->inventory.inventory.size; i++)
            {
                __int64 invItemAddr = idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
                if (!invItemAddr) {
                    logErr("getIdWeapon: found an invItemAddr == 0 returning 0");
                    return 0;
                }
                if ((ItemID)getItemIdV2((idInventoryItem*)invItemAddr) == itemId) {
                    return (idWeapon*)invItemAddr;
                }
            }
        }
        return 0;
    }


    //! this method compared to our previous version (commented) makes it less likely for the other thread (game) to acces the m_ownedItemIds when it's been cleared as here, we don't empty it we just swap it with the local one. It's not perfect though but should be good enough for our needs. The next step would be to use events so we know for sure that the inventory has been updated.
    static void updateOwnedItemsIds() {
        logDebug("updateOwnedItemsIds");

        std::vector<unsigned int> newOwnedItemIds;

        idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

        if (pIdActor) {
            for (int i = 0; i < pIdActor->inventory.inventory.size; i++)
            {
                __int64 invItemAddr = idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
                if (invItemAddr) {
                    newOwnedItemIds.push_back(getItemIdV2((idInventoryItem*)invItemAddr));
                }
            }
        }
        else {
            logWarn("updateOwnedItemsIds: failed because pIdActor is bad ptr");
        }

        //  replace vector with the new one
        m_ownedItemIds = std::move(newOwnedItemIds);
    }


    //static void updateOwnedItemsIds() {
    //    logDebug("updateOwnedItemsIds");

    //    m_ownedItemIds.clear();

    //    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

    //    if (pIdActor) {        
    //        for (int i = 0; i < pIdActor->inventory.inventory.size; i++)
    //        {
    //            __int64 invItemAddr = idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
    //            if (invItemAddr) {
    //                //logInfo("updateOwnedItemsIds: debug: invItemAddr is: %p and (__int64)&invItemAddr) and (__int64)&pIdActor->inventory is %p", (void*)invItemAddr, (void*)&pIdActor->inventory);
    //                //m_ownedItemIds.push_back(getItemId(invItemAddr));
    //                m_ownedItemIds.push_back(getItemIdV2((idInventoryItem*)invItemAddr));
    //                //logInfo("updateOwnedItemsIds: debug: found itemId: %X", getItemIdV2((idInventoryItem*)invItemAddr));
    //            }
    //        }
    //    }
    //    else {
    //        logWarn("updateOwnedItemsIds: failed because pIdActor is bad ptr");
    //    }
    //}



    static __int64 getItemAddress(ItemID itemId) {
        logDebug("getItemAddress");
        idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

        if (pIdActor) {

            for (int i = 0; i < pIdActor->inventory.inventory.size; i++)
            {
                __int64 invItemAddr = idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
                if (!invItemAddr) {
                    logErr("getItemAddress: found an invItemAddr with addr 0 looking for itemId: 0x%X returning 0", itemId);
                    return 0;
                }
                //if ((ItemID)getItemId(invItemAddr) == itemId) {   
                //m_ownedItemIds.push_back(getItemIdV2((idInventoryItem)(__int64)&invItemAddr));
                if ((ItemID)getItemIdV2((idInventoryItem*)invItemAddr) == itemId) {
                    //logInfo("getItemAddress: found itemId: 0x%X invItemAddr: %p", (unsigned int)itemId, (void*)invItemAddr);
                    return invItemAddr;
                }
            }
        }
        else {
            logWarn("getItemAddress: failed because idPlayerAdrr is bad ptr");
        }
        return 0;
    }


    static bool isItemOwned(ItemID itemId) {
        logDebug("isItemOwned");

        if (m_ownedItemIds.empty()) {
            logDebug("isItemOwned: m_ownedItemIds is empty !");
            return false;
        }
        unsigned int itemIdValue = static_cast<unsigned int>(itemId);
        for (unsigned int ownedItemId : m_ownedItemIds) {
            if (ownedItemId == itemIdValue) {
                return true;
            }
        }
        return false;
    }



    static bool isWeaponOwned(weaponSlot_t weaponIndex) {
        logDebug("isWeaponOwned");
        if (m_ownedItemIds.empty()) {
            logWarn("isWeaponOwned: m_ownedItemIds is empty!");
            return false; // Early return if the vector is empty
        }

        // Search for the weaponIndex in the map
        auto it = itemIdToWeaponSlotMap.begin();
        while (it != itemIdToWeaponSlotMap.end()) {
            if (it->second == weaponIndex) {
                // Find the corresponding ItemID
                ItemID itemId = it->first;

                // Check if it's in the m_ownedItemIds vector using std::find
                unsigned int itemIdValue = static_cast<unsigned int>(itemId);
                if (std::find(m_ownedItemIds.begin(), m_ownedItemIds.end(), itemIdValue) != m_ownedItemIds.end()) {
                    return true; // Found, the weapon is owned
                }
            }
            ++it;
        }

        return false; // Weapon not owned
    }





    static __int64 idInventoryCollection_getInventoryItemAddr(__int64 inventoryListStartAddr, int i) {
        logDebug("idInventoryCollection_getInventoryItemAddr");
        if (!m_getInventoryItemFuncAddr) {
            logErr("idInventoryCollection_getInventoryItemAddr: m_getInventoryItemFuncAddr is null: the mod can not function normally");
            return 0;
        }
        auto pGetInventory = reinterpret_cast<idInventoryCollection_GetInventoryItem>(m_getInventoryItemFuncAddr);
        return pGetInventory(inventoryListStartAddr, i);
    }



    static unsigned int getItemIdV2(idInventoryItem* inventoryItemPtr) {
        logDebug("getItemIdV2");
        unsigned int result = 0;
        auto decl = inventoryItemPtr->decl;
        if (decl) {
            result = decl->displayName.id; // this is a idStrId
        }
        return result;
    }


    static std::string getItemDebugHudString(std::string itemName, int itemCount) {
        logDebug("getItemDebugHudString");

        std::string itemCounStr = std::to_string(itemCount);
        return itemName + " " + itemCounStr;
    }




    //static bool isWeaponOwned(weaponSlot_t weaponIndex) {
    //    if (m_ownedItemIds.empty()) {
    //        logWarn("isWeaponOwned: m_ownedItemIds is empty !");
    //    }
    //    for (const auto& pair : itemIdToWeaponSlotMap) {
    //        if (pair.second == weaponIndex) {
    //            // Find the corresponding ItemID
    //            ItemID itemId = pair.first;

    //            // Check if it's in the m_ownedItemIds vector
    //            unsigned int itemIdValue = static_cast<unsigned int>(itemId);
    //            for (unsigned int ownedItemId : m_ownedItemIds) {
    //                if (ownedItemId == itemIdValue) {
    //                    return true;
    //                }
    //            }
    //        }
    //    }
    //    return false;
    //}


    //static unsigned int getItemId(__int64 inventoryItemAddr) {
    //    logDebug("getItemId");
    //    __int64 v2;
    //    unsigned int result = 0;

    //    v2 = *(uint64_t*)(inventoryItemAddr + 0x38);
    //    if (v2)
    //        result = *(unsigned int*)(v2 + 0x124); // this is a idStrId
    //    return result;
    //}

    /*static std::string getItemName(__int64 inventoryItemAddr) {
        logDebug("getItemName");

        try
        {
            __int64 itemDeclAdrr = *(__int64*)(inventoryItemAddr + 0x38);
            if (itemDeclAdrr) {
                __int64 itemNameStrAddr = *(__int64*)(itemDeclAdrr + 8);
                return std::string((const char*)(itemNameStrAddr));
            }
        }
        catch (const std::exception& ex)
        {
            logInfo("getItemName: %s", ex.what());
        }
        return "unknownItemName";
    }*/

    /*static int getItemQuantity(__int64 inventoryItemAddr) {
        logDebug("getItemQuantity");

        if (!MemHelper::isBadReadPtr((void*)inventoryItemAddr)) {
            unsigned int quantity = (unsigned int)(*(__int64(__fastcall**)(__int64))(*(uint64_t*)inventoryItemAddr + 0xD0i64))(inventoryItemAddr);
            return quantity;
        }
        return 0;
    }*/




    /*static void debugPrintInventoryItemsVec() {
        logInfo("debugPrintInventoryItemsVec: ");
        for (size_t i = 0; i < m_inventoryItemsVec.size(); i++)
        {
            logInfo("item name: %s item count: %d", m_inventoryItemsVec[i].Name.c_str(), m_inventoryItemsVec[i].Count);
        }
    }*/



    //void getOwnedItems()
    //{
    //    //std::cout << "getOwnedItems: reference: 7113 (shotgun) 8562(ar), 7404 (plasma), ssg(22668), rl(7732), bfg(20817), unmaker(11052), minigun(7982), ballista(8300), sword(23691), Hammer(10464) frag(9843) ice(276A)" << std::endl;
    //    static unsigned int lastInvItemsCount = -1;

    //    std::vector<uintptr_t>ownedItemPtrsVec{};


    //    try
    //    {
    //        //m_ownedItemIdsVec.clear();
    //        //m_WeaponsVec.clear();
    //        //m_ownedItemPtrsVec.clear();
    //        m_ownedItemIds.clear();

    //        if (isBadReadPtr((void*)m_idInventoryCollectionPtr)) {
    //            /*spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for m_idInventoryCollectionPtr: {:x} ", m_idInventoryCollectionPtr);*/
    //            std::cout << "getOwnedItems: ERROR 1 " << std::endl;
    //            return;
    //        }
    //        uintptr_t itemListPtr = *(uintptr_t*)m_idInventoryCollectionPtr;
    //        if (isBadReadPtr((void*)itemListPtr)) {
    //            std::cout << "getOwnedItems: ERROR 2 " << std::endl;

    //            //spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for itemListPtr: {:x} ", itemListPtr);
    //            return;
    //        }

    //        std::cout << "getOwnedItems: m_idInventoryCollectionPtr is:  " << std::hex << m_idInventoryCollectionPtr << std::endl;

    //        int inventoryItemsCount = getInventoryItemsCount();
    //        if (inventoryItemsCount != lastInvItemsCount) {
    //            lastInvItemsCount = inventoryItemsCount;
    //            std::cout << "getOwnedItems: inventoryItemsCount has changed to: " << std::dec << inventoryItemsCount << std::endl;
    //        }
    //        if (inventoryItemsCount == 0) {
    //            return;
    //        }


    //        std::cout << "" << std::endl; //! to make logging a bit cleaner

    //      

    //        uintptr_t itemPtr = itemListPtr + 0x8;
    //        for (size_t i = 0; i < inventoryItemsCount; i++)
    //        {
    //            //spdlog::debug("MemHelper::getOwnedWeapons: adding itemPtr: {:x} ", itemPtr);
    //            ownedItemPtrsVec.push_back(itemPtr);
    //            itemPtr += 0x20;
    //        }
    //        for (size_t i = 0; i < ownedItemPtrsVec.size(); i++)
    //        {
    //            if (!isBadReadPtr((void*)ownedItemPtrsVec[i])) {
    //                //uintptr_t itemDeclPtr = *(unsigned int**)(g_ownedItemPtrsVec[i] + 0x34);
    //                //std::cout << "getOwnedItems: g_ownedItemPtrsVec[i]: " << std::hex << g_ownedItemPtrsVec[i] << std::endl;
    //                uintptr_t itemDeclPtr = *(uintptr_t*)ownedItemPtrsVec[i] + 0x38;
    //                //std::cout << "getOwnedItems: itemDeclPtr: " << itemDeclPtr << std::endl;
    //                if (!isBadReadPtr((void*)itemDeclPtr)) {
    //                    uintptr_t itemIdAddr = *(uintptr_t*)itemDeclPtr + 0x34;

    //                    if (! isBadReadPtr((void*)itemIdAddr)) {
    //                        unsigned int itemId = *(unsigned int*)(itemIdAddr);

    //                        for (size_t i = 0; i < watchedItemsIdsVec.size(); i++)
    //                        {
    //                            if (itemId == watchedItemsIdsVec[i]) {
    //                                m_ownedItemIds.push_back(itemId);
    //                                std::cout << "getOwnedItems: found known item: " << getItemNameFromItemDeclId(itemId) << " and idDeclWeapon ptr is: " << std::hex << *(uintptr_t*)itemDeclPtr << std::endl;
    //                                break;
    //                            }
    //                        }
    //                    }
    //                }

    //                //std::cout << "getOwnedItems: itemIdAddr: " << itemIdAddr << std::endl;
    //                //uintptr_t itemStrPtrAddr = *(uintptr_t*)itemDeclPtr + 0x8;
    //                //std::cout << "getOwnedItems: itemStrPtrAddr: " << itemStrPtrAddr << std::endl;
    //                //uintptr_t itemStrAddr = *(uintptr_t*)itemStrPtrAddr;
    //                //std::cout << "getOwnedItems: itemStrAddr: " << itemStrAddr << std::endl;

    //                //std::cout << "getOwnedItems: found itemStr: " <<  *(char*)(itemStrAddr) << std::endl;
    //                //std::string itemStr = *(char*)(itemStrAddr);
    //                //unsigned int itemId = *(unsigned int*)(g_ownedItemPtrsVec[i] + 0x34);
    //                //std::string itemStr = *(std::string*)(g_ownedItemPtrsVec[i] + 0x8);
    //                //spdlog::debug("MemHelper::getOwnedWeapons: itemDeclPtr: {:x} ", itemDeclPtr);
    //                //std::cout << "getOwnedItems: found item id: " << itemId <<  std::endl;


    //                //std::string itemStr = getItemNameFromItemDeclId(itemId);
    //                //if (itemStr != "unknowItem") {
    //                //    //std::cout << "getOwnedItems: found known item id(decimal): " << std::dec << itemId << " corresponding str: " << getItemNameFromItemDeclId(itemId) << std::endl;
    //                //    g_ownedItemIds.push_back(itemId);
    //                //}              
    //                //std::cout << "getOwnedItems: found item id: " << itemId << " and str: " << itemStr << std::endl;
    //                //if (!isBadReadPtr((void*)itemDeclPtr)) {
    //                //    //unsigned int valAddr = *(uintptr_t*)itemDeclPtr + 0x34;
    //                //    uintptr_t valAddr = *(uintptr_t*)itemDeclPtr + 0x34;
    //                //    uintptr_t strAddr = *(uintptr_t*)itemDeclPtr + 0x8;
    //                //    //spdlog::debug("MemHelper::getOwnedWeapons: valAddr: {:x} ", valAddr);
    //                //    if (!isBadReadPtr((void*)valAddr)) {
    //                //        //unsigned int itemId = *(unsigned int*)valAddr;
    //                //        std::string itemStr = *(std::string*)strAddr;
    //                //        std::cout << "getOwnedItems: found item id: " << itemId  << " and str: " << itemStr << std::endl;
    //                //        /*if (isWeapon(itemId)) {
    //                //            spdlog::debug("MemHelper::getOwnedWeapons: adding weapon with id: {} ", itemId);
    //                //            m_WeaponsVec.push_back(itemId);
    //                //        }*/
    //                //    }
    //                //    else {
    //                //        std::cout << "getOwnedItems: ERROR 6 " << std::endl;
    //                //    }
    //                //}
    //                //else {
    //                //    //spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for itemDeclPtr: {:x} ", itemDeclPtr);
    //                //    std::cout << "getOwnedItems: ERROR 3 " << std::endl;

    //                //}
    //            }
    //            else {
    //                //spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for m_ownedItemPtrsVec[i]: {:x} ", m_ownedItemPtrsVec[i]);
    //                std::cout << "getOwnedItems: ERROR 4 " << std::endl;

    //            }
    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        //spdlog::error("MemHelper::getOwnedWeapons: exception: {} ", ex.what());
    //        std::cout << "getOwnedItems: ERROR 5 " << ex.what() << std::endl;

    //    }
    //}



    //int getInventoryItemsCount()
    //{
    //    try
    //    {
    //        __int64 idPlayerAdrr = ObjectLocator::getIdPlayerAddr();
    //        if (isBadReadPtr((void*)idPlayerAdrr)) {
    //            //spdlog::warn("MemHelper::getInventoryItemsCount: found bad ptr for m_idPlayerPtr: {:x} returning -1 ", m_idPlayerPtr);
    //            std::cout << "getInventoryItemsCount: ERROR bad ptr " << std::endl;
    //        }
    //        else {
    //            int count = *(unsigned int*)(idPlayerAdrr + m_idPlayerItemsCountOffset);
    //            if (count > m_maxItemsCount) {
    //                std::cout << "getInventoryItemsCount: ERROR items count is:  " << count << " returning 0" << std::endl;                   
    //            }
    //            else {
    //                return count;
    //            }
    //            //return *(uintptr_t*)(g_idPlayerPtr + idPlayerItemsCountOffset);
    //            //return *(uintptr_t*)(g_idPlayerPtr + idPlayerItemsCountOffset);
    //        }
    //    }
    //    catch (const std::exception& ex)
    //    {
    //        //spdlog::error("MemHelper::getInventoryItemsCount: exception ERROR: {} ", ex.what());
    //        std::cout << "getInventoryItemsCount: ex:  " << ex.what() << std::endl;
    //    }
    //    return 0;
    //}


   /* std::string getItemNameFromItemDeclId(unsigned int itemId)
    {
        if (itemId == 7113) {
            return "shotgun";
        }
        else if (itemId == 8562) {
            return "assaultRifle";
        }
        else if (itemId == 7404) {
            return "plasma";
        }
        else if (itemId == 7732) {
            return "rocketLauncher";
        }
        else if (itemId == 22668) {
            return "superShotgun";
        }
        else if (itemId == 8300) {
            return "ballista";
        }
        else if (itemId == 7982) {
            return "miniGun";
        }
        else if (itemId == 20817) {
            return "bfg";
        }
        else if (itemId == 11052) {
            return "unmaker";
        }
        else if (itemId == 23691) {
            return "crucible";
        }
        else if (itemId == 10464) {
            return "hammer";
        }
        else if (itemId == 9843) {
            return "frag nade";
        }
        else if (itemId == 0x276A) {
            return "ice nade";
        }
        else {
            return "unknowItem";
        }
    }*/



    //! afaik this is not what is creating the crash
        //static std::vector< HudAmmoDataV2> getHudAmmoDataVec_V2() {
        //    //std::vector< HudAmmoDataV2> hudAmmoDataVec;
        //    std::vector< HudAmmoDataV2> hudAmmoDataVec = HudAmmoDataContainer::getDefault();       

        //   /* HudAmmoDataV2 shellHudAmmoData;
        //    HudAmmoDataV2 bulletHudAmmoData;
        //    HudAmmoDataV2 rocketHudAmmoData;
        //    HudAmmoDataV2 celllHudAmmoData;

        //    bool isAmmoShellVisible = false;
        //    bool isAmmoBulletVisible = false;
        //    bool isAmmoRocketVisible = false;
        //    bool isAmmoCellVisible = false;*/

        //    std::vector<InventoryItem> itemsVec = getIdInventoryItems();
        //    for (size_t i = 0; i < itemsVec.size(); i++)
        //    {
        //        if (itemsVec[i].ID == (unsigned int)ItemID::AmmoShells) {
        //            //shellHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, itemsVec[i].Count);
        //            hudAmmoDataVec[0] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, itemsVec[i].Count);               
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBullets) {
        //            //bulletHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, itemsVec[i].Count);
        //            hudAmmoDataVec[1] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, itemsVec[i].Count);              
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoRockets) {
        //            //rocketHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, itemsVec[i].Count);
        //            hudAmmoDataVec[2] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, itemsVec[i].Count);               
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoCells) {
        //            //celllHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, itemsVec[i].Count);
        //            hudAmmoDataVec[3] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, itemsVec[i].Count);            
        //        }
        //    }
        //    //! this should order ammos:
        //    //if (isAmmoShellVisible) {
        //    //    //hudAmmoDataVec[0] = shellHudAmmoData;
        //    //    hudAmmoDataVec.push_back(shellHudAmmoData);
        //    //}
        //    //if (isAmmoBulletVisible) {
        //    //    //hudAmmoDataVec[1] = bulletHudAmmoData;
        //    //    hudAmmoDataVec.push_back(bulletHudAmmoData);
        //    //}
        //    //if (isAmmoRocketVisible) {
        //    //    //hudAmmoDataVec[2] = rocketHudAmmoData;
        //    //    hudAmmoDataVec.push_back(rocketHudAmmoData);
        //    //}
        //    //if (isAmmoCellVisible) {
        //    //    //hudAmmoDataVec[3] = celllHudAmmoData;
        //    //    hudAmmoDataVec.push_back(celllHudAmmoData);
        //    //}
        //    return hudAmmoDataVec;
        //}



        //static std::vector< HudAmmoDataV2> getHudAmmoDataVec() {
        //    std::vector< HudAmmoDataV2> hudAmmoDataVec;
        //    //std::vector< HudAmmoDataV2> hudAmmoDataVec = HudAmmoDataContainer::getDefault();
        //    HudAmmoDataV2 shellHudAmmoData;
        //    HudAmmoDataV2 bulletHudAmmoData;
        //    HudAmmoDataV2 rocketHudAmmoData;
        //    HudAmmoDataV2 celllHudAmmoData;

        //    bool isAmmoShellVisible = false;
        //    bool isAmmoBulletVisible = false;
        //    bool isAmmoRocketVisible = false;
        //    bool isAmmoCellVisible = false;

        //    std::vector<InventoryItem> itemsVec = getIdInventoryItems();
        //    for (size_t i = 0; i < itemsVec.size(); i++)
        //    {
        //        if (itemsVec[i].ID == (unsigned int)ItemID::Shotgun) {
        //           
        //            if (itemsVec[i].Count > 0) isAmmoShellVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::HeavyCannon) {
        //            if (itemsVec[i].Count > 0) isAmmoBulletVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::PlasmaRifle) {
        //            if (itemsVec[i].Count > 0) isAmmoCellVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::RocketLauncher) {
        //            if (itemsVec[i].Count > 0) isAmmoRocketVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::SuperShotgun) {
        //            if (itemsVec[i].Count > 0) isAmmoShellVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::Ballista) {
        //            if (itemsVec[i].Count > 0) isAmmoCellVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::MiniGun) {
        //            if (itemsVec[i].Count > 0) isAmmoBulletVisible = true;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoShells) {
        //            shellHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, itemsVec[i].Count);
        //            //hudAmmoDataVec[0] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, itemsVec[i].Count);               
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBullets) {
        //            bulletHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, itemsVec[i].Count);
        //            //hudAmmoDataVec[1] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, itemsVec[i].Count);              
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoRockets) {
        //            rocketHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, itemsVec[i].Count);
        //            //hudAmmoDataVec[2] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, itemsVec[i].Count);               
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoCells) {
        //            celllHudAmmoData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, itemsVec[i].Count);
        //            //hudAmmoDataVec[3] = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, itemsVec[i].Count);            
        //        }
        //    }
        //    //! this should order ammos:
        //    if (isAmmoShellVisible) {
        //        //hudAmmoDataVec[0] = shellHudAmmoData;
        //        hudAmmoDataVec.push_back(shellHudAmmoData);
        //    }
        //    if (isAmmoBulletVisible) {
        //        //hudAmmoDataVec[1] = bulletHudAmmoData;
        //        hudAmmoDataVec.push_back(bulletHudAmmoData);
        //    }
        //    if (isAmmoRocketVisible) {
        //        //hudAmmoDataVec[2] = rocketHudAmmoData;
        //        hudAmmoDataVec.push_back(rocketHudAmmoData);
        //    }
        //    if (isAmmoCellVisible) {
        //        //hudAmmoDataVec[3] = celllHudAmmoData;
        //        hudAmmoDataVec.push_back(celllHudAmmoData);
        //    }
        //    return hudAmmoDataVec;
        //}

        //static HudAmmoDataContainer getHudAmmoData() {
        //    HudAmmoDataContainer hudAmmoData;
        //    std::vector<InventoryItem> itemsVec = getIdInventoryItems();
        //    for (size_t i = 0; i < itemsVec.size(); i++)
        //    {
        //        if (itemsVec[i].ID == (unsigned int)ItemID::AmmoShells) {
        //            hudAmmoData.set(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, itemsVec[i].Count);
        //            //playerInventory.ShellAmmo = itemsVec[i].Count;
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBullets) {
        //            hudAmmoData.set(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, itemsVec[i].Count);
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoRockets) {
        //            hudAmmoData.set(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, itemsVec[i].Count);
        //        }
        //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoCells) {
        //            hudAmmoData.set(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, itemsVec[i].Count);
        //        }
        //    }
        //    return hudAmmoData;
        //}


};

std::vector<unsigned int>idInventoryCollectionManager::m_ownedItemIds{};
__int64 idInventoryCollectionManager::m_getInventoryItemFuncAddr = 0;
//std::vector<InventoryItem> idInventoryCollectionManager::m_inventoryItemsVec{ 0 };

//idInventoryCollectionManager::idInventoryCollection_GetInventoryItem idInventoryCollectionManager::pidInventoryCollection_GetInventoryItem = reinterpret_cast<idInventoryCollection_GetInventoryItem>(MemHelper::getFuncAddr(0x1D1D6A0));


