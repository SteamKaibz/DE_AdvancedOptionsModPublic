//#pragma once
//
//#include <Windows.h>
//#include<iostream>
//#include <vector>
//#include <string>
//#include "CommonDE.h"
//#include "MemHelper.h"
//#include <map>
//#include "Config.h"
//#include "ObjectLocator.h"
//
//class idInventory
//{
//private:
//    uintptr_t m_idInventoryCollectionPtr = 0;
//    std::vector<unsigned int>m_idInventoryItemIdOffsets{ 0x38 , 0x34};
//    std::vector<unsigned int>m_idInventoryItemNameOffsets{ 0x38 , 0x8, 0};
//    const unsigned int m_itemListFirstOffset = 0x8;
//    const unsigned int m_itemSpacingtOffset = 0x20;
//    //uintptr_t m_idPlayerPtr = 0;
//    const uintptr_t m_idPlayerItemsCountOffset = 0x35E0;
//    const unsigned int m_maxItemsCount = 256; //! if we find a value > to that we assume there is an error. It happend before...
//   
//    const std::vector<unsigned int>watchedItemsIdsVec{ shotgunItemId, assaultRiffleItemId, plasmaItemId, superShotgunItemId, rocketLauncherItemId, bfgItemId, unmakerItemId, minigunItemId, balistaItemId, swordItemId, hammerItemId, fragGrenadeItemId, iceGrenadeItemId };
//    //std::map<int, unsigned int> m_weaponIndexIdMap;
//    std::vector<unsigned int>m_ownedItemIds{};
//
//
//    bool isOwnedItem(unsigned int itemId) {
//        for (size_t i = 0; i < m_ownedItemIds.size(); i++)
//        {
//            if (m_ownedItemIds[i] == itemId) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    int getInventoryItemsCount()
//    {
//        try
//        {
//            __int64 idPlayerPtr = ObjectLocator::getIdPlayerPtr();
//            if (MemHelper::isBadReadPtr((void*)idPlayerPtr)) {
//                //spdlog::debug("idInventory::getInventoryItemsCount: found bad ptr for m_idPlayerPtr: {:x} ", m_idPlayerPtr);
//            }
//            else {
//                unsigned int count = *(unsigned int*)(idPlayerPtr + m_idPlayerItemsCountOffset);
//                if (count > m_maxItemsCount) {
//                    //spdlog::debug("idInventory::getInventoryItemsCount: found bad ptr for m_idPlayerPtr: {:x} ", (m_idPlayerPtr + m_idPlayerItemsCountOffset));
//                }
//                else {
//                    return count;
//                }
//                //return *(uintptr_t*)(g_idPlayerPtr + idPlayerItemsCountOffset);
//                //return *(uintptr_t*)(g_idPlayerPtr + idPlayerItemsCountOffset);
//            }
//        }
//        catch (const std::exception& ex)
//        {
//            logErr("idInventory::getInventoryItemsCount:: exception ERROR: %s ", ex.what());
//        }
//        return 0;
//    }
//
//
//    std::string getItemNameFromItemDeclId(unsigned int itemId)
//    {
//        if (itemId == 7113) {
//            return "shotgun";
//        }
//        else if (itemId == 8562) {
//            return "assaultRifle";
//        }
//        else if (itemId == 7404) {
//            return "plasma";
//        }
//        else if (itemId == 7732) {
//            return "rocketLauncher";
//        }
//        else if (itemId == 22668) {
//            return "superShotgun";
//        }
//        else if (itemId == 8300) {
//            return "ballista";
//        }
//        else if (itemId == 7982) {
//            return "miniGun";
//        }
//        else if (itemId == 20817) {
//            return "bfg";
//        }
//        else if (itemId == 11052) {
//            return "unmaker";
//        }
//        else if (itemId == 23691) {
//            return "crucible";
//        }
//        else if (itemId == 10464) {
//            return "hammer";
//        }
//        else if (itemId == 9843) {
//            return "frag nade";
//        }
//        else if (itemId == 0x276A) {
//            return "ice nade";
//        }
//        else {
//            return "unknowItem";
//        }
//    }
//
//    unsigned int getWeaponIdFromIndex(int weaponIndex) {
//        switch (weaponIndex) {
//        case shotgunWeaponIndex:
//            return shotgunItemId;
//        case assaultRifleWeaponIndex:
//            return assaultRiffleItemId;
//        case plasmaWeaponIndex:
//            return plasmaItemId;
//        case rocketLauncherWeaponIndex:
//            return rocketLauncherItemId;
//        case superShotgunWeaponIndex:
//            return superShotgunItemId;
//        case ballistaWeaponIndex:
//            return balistaItemId;
//        case miniGunWeaponIndex:
//            return minigunItemId;
//        default:
//            return unknownItemId;
//            break;
//        }
//    }
//
//
//
//public:
//
//    bool isOwnedWeapon(int weaponIndex) {
//        unsigned int weaponId = getWeaponIdFromIndex(weaponIndex);
//        return isOwnedItem(weaponId);
//    }
//
//   /* bool isFragOwned() {
//        return isOwnedItem(fragGrenadeItemId);
//    }
//
//    bool isIceOwned() {
//        return isOwnedItem(iceGrenadeItemId);
//    }  */  
//
//    //! triggered when idPlayerProcessInputSACLHook is triggered
//    /*void acquire_idPlayerPtr(__int64 playerPtr) {
//        m_idPlayerPtr = (uintptr_t)playerPtr;
//    }*/
//
//    //! trigger when idInventoryCollectionGetInventoryItemHook is triggered
//    void acquire_idInventoryCollectionPtr(__int64 idInventoryCollectionPtr) {
//        static uintptr_t lastIdInventoryCollectionPtr = 0;
//
//        m_idInventoryCollectionPtr = (uintptr_t)idInventoryCollectionPtr;
//
//        if (m_idInventoryCollectionPtr != lastIdInventoryCollectionPtr) {
//            logInfo("acquire_idInventoryCollectionPtr: m_idInventoryCollectionPtr has changed to: %llx", m_idInventoryCollectionPtr);
//            lastIdInventoryCollectionPtr = m_idInventoryCollectionPtr;
//        }       
//    }    
//
//    //! only getting items that we care about that the player currently owns. for example at the start of campaing the slayer will not own all the weapons and grenade types.
//    void acquireWatchedOwnedItems()
//    {
//        //std::cout << "acquireWatchedOwnedItems: reference: 7113 (shotgun) 8562(ar), 7404 (plasma), ssg(22668), rl(7732), bfg(20817), unmaker(11052), minigun(7982), ballista(8300), sword(23691), Hammer(10464) frag(9843) ice(276A)" << std::endl;
//        static unsigned int lastInvItemsCount = -1;
//        std::vector<uintptr_t>ownedItemPtrsVec{};
//
//        try
//        {
//            m_ownedItemIds.clear();
//
//            if (MemHelper::isBadReadPtr((void*)m_idInventoryCollectionPtr)) {
//                //spdlog::debug("idInventory::acquireWatchedOwnedItems: found bad ptr for m_idInventoryCollectionPtr: {:x} ", m_idInventoryCollectionPtr);
//                return;
//            }
//            uintptr_t itemListPtr = *(uintptr_t*)m_idInventoryCollectionPtr;
//            if (MemHelper::isBadReadPtr((void*)itemListPtr)) {
//                //spdlog::debug("idInventory::acquireWatchedOwnedItems: found bad ptr for itemListPtr: {:x} ", itemListPtr);
//                return;
//            }
//
//            //spdlog::debug("idInventory::acquireWatchedOwnedItems: m_idInventoryCollectionPtr is:: {:x} ", m_idInventoryCollectionPtr);
//
//            int inventoryItemsCount = getInventoryItemsCount();
//            if (inventoryItemsCount != lastInvItemsCount) {
//                lastInvItemsCount = inventoryItemsCount;
//                //spdlog::debug("idInventory::acquireWatchedOwnedItems: inventoryItemsCount has changed to: {} ", inventoryItemsCount);
//            }
//            if (inventoryItemsCount == 0) {
//                return;
//            }
//            //spdlog::debug("");
//            uintptr_t itemPtr = itemListPtr + m_itemListFirstOffset;
//            for (size_t i = 0; i < inventoryItemsCount; i++)
//            {
//                //spdlog::debug("MemHelper::getOwnedWeapons: adding itemPtr: {:x} ", itemPtr);
//                ownedItemPtrsVec.push_back(itemPtr);
//                itemPtr += m_itemSpacingtOffset;
//            }
//
//            //debugPrintOwnedItems(ownedItemPtrsVec);
//
//            for (size_t i = 0; i < ownedItemPtrsVec.size(); i++)
//            {
//                if (!MemHelper::isBadReadPtr((void*)ownedItemPtrsVec[i])) {
//                    uintptr_t itemIdAddr = MemHelper::FindPtrAddress(ownedItemPtrsVec[i], m_idInventoryItemIdOffsets);               
//                    if (!MemHelper::isBadReadPtr((void*)itemIdAddr)) {
//                        unsigned int itemId = *(unsigned int*)(itemIdAddr);
//
//                        debugPrintItemInfo(ownedItemPtrsVec[i]);
//                        //debugPrintItemId(itemId);
//
//                        for (size_t i = 0; i < watchedItemsIdsVec.size(); i++)
//                        {
//                            if (itemId == watchedItemsIdsVec[i]) {
//                                m_ownedItemIds.push_back(itemId);
//                                //spdlog::debug("idInventory::acquireWatchedOwnedItems: found known item: {}  ", getItemNameFromItemDeclId(itemId));
//                                break;
//                            }
//                        }
//                    }
//                }
//                else {
//                    logWarn("idInventory::acquireWatchedOwnedItems: found bad ptr for m_ownedItemPtrsVec[i]: %p ", (void*)ownedItemPtrsVec[i]);
//                }
//            }
//            printWatchedOwnedItems(inventoryItemsCount); //! will only print if items count has changed.
//        }
//        catch (const std::exception& ex)
//        {
//            logErr("idInventory::acquireWatchedOwnedItems: exception: %s ", ex.what());
//        }
//    }
//
//    void printWatchedOwnedItems(int inventoryItemsCount)
//    {
//        static int lastInvItemsCount = -1;
//
//        if (inventoryItemsCount != lastInvItemsCount) {
//            lastInvItemsCount = inventoryItemsCount;
//            logInfo("");
//            logInfo("idInventory::printWatchedOwnedItems:");
//            logInfo("\ttotal owned items count: %d, watched owned items count: %zu  ", inventoryItemsCount, m_ownedItemIds.size());
//            for (size_t i = 0; i < m_ownedItemIds.size(); i++)
//            {
//                logInfo("\t%s, id: %d (hex: %X)", getItemNameFromItemDeclId(m_ownedItemIds[i]).c_str(), m_ownedItemIds[i], m_ownedItemIds[i]);
//            }            
//            logInfo("");
//        }       
//    }
//
//    void debugPrintOwnedItems(std::vector<uintptr_t>& ownedItemPtrsVec) {
//
//        static int lastInvItemsCount = -1;
//        logInfo("debugPrintOwnedItems: ownedItemPtrsVec size is: %zu", ownedItemPtrsVec.size());
//        for (size_t i = 0; i < ownedItemPtrsVec.size(); i++)
//        {
//            logInfo("%llx", ownedItemPtrsVec[i]);
//        }
//    }
//
//    void debugPrintItemInfo(uintptr_t itemPtr) {
//
//
//        logInfo("debugPrintItemInfo: itemPtr is: %p", (void*)itemPtr);
//
//
//
//
//        return;
//
//
//
//
//
//        try
//        {
//            uintptr_t itemIdAddr = MemHelper::FindPtrAddress(itemPtr, m_idInventoryItemIdOffsets);
//            uintptr_t itemNameAddr = MemHelper::FindPtrAddress(itemPtr, m_idInventoryItemNameOffsets);
//            logInfo("debugPrintItemInfo: itemNameAddr: %llx", itemNameAddr);
//
//
//            unsigned int itemId = *(unsigned int*)(itemIdAddr);
//            const char* itemName = (const char*)itemNameAddr;
//
//            logInfo("debugPrintItemInfo: found item with name: %s and with id: %u", itemName, itemId);
//        }
//        catch (const std::exception& ex)
//        {
//            logErr("debugPrintItemInfo: exception: %s ", ex.what());
//        }
//        
//    }
//
//
//    
//
//
//};
//
