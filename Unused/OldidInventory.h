//#pragma once
//#include <Windows.h>
//#include<iostream>
//#include <vector>
//#include <string>
//#include "Common.h"
//#include "Utils.h"
//#include "ObjectLocator.h"
//#include "Types.h"
//#include "Config.h"
//#include "PlayerInventory.h"
//#include "MemHelper.h"
//
//
//
//struct InventoryItem {
//    std::string Name = "unknown";
//    int Count = -1;
//};
//
///// <summary>
///// this contains items (weapons and grenades) currently owned by the player. Other classes will use this class to get items, that way it prevents having many classes reading the memory to get items info.
///// </summary>
//class idInventoryCollectionManager
//{
//private:
//    //uintptr_t m_idInventoryCollectionPtr = 0;
//    ////__int64 m_idPlayerPtr = 0;
//    //const uintptr_t m_idPlayerItemsCountOffset = 0x35E0;
//    //const int m_maxItemsCount = 512; //! if we find a value > to that we assume there is an error. And it happend before...
//    ////WeaponsVec.clear();
//    //const std::vector<unsigned int>watchedItemsIdsVec{ shotgunItemId, assaultRiffleItemId, plasmaItemId, superShotgunItemId, rocketLauncherItemId, bfgItemId, unmakerItemId, minigunItemId, balistaItemId, swordItemId, hammerItemId, fragGrenadeItemId, iceGrenadeItemId };
//    //std::vector<unsigned int>m_ownedItemIds{};
//
//
//    static std::vector<InventoryItem> m_inventoryItemsVec;
//
//    //! bool __fastcall idPlayer::UseEquipmentItem_A5F3D90(__int64 *idPlayer_a1, __int64 idDeclThrowable_a2, char a3, int a4)
//    typedef bool(__fastcall* idPlayer_UseEquipmentItem)(__int64* idPlayer_a1, __int64 idDeclThrowable_a2, char a3, int a4);
//    static idPlayer_UseEquipmentItem p_idPlayer_UseEquipmentItem;
//    //static idPlayer_UseEquipmentItem p_idPlayer_UseEquipmentItem = reinterpret_cast<idPlayer_UseEquipmentItem>(getFuncAddr(0xA5F3D90));
//
//    //! __int64 __fastcall idInventoryCollection::GetInventoryItem_1D1D6A0(__int64 a1, int a2)
//    typedef __int64(__fastcall* idInventoryCollection_GetInventoryItem)(__int64 a1, int a2);
//    static idInventoryCollection_GetInventoryItem pidInventoryCollection_GetInventoryItem;
//
//
//    static unsigned int getItemId(__int64 inventoryItemAddr) {
//        __int64 v2;
//        unsigned int result = 0;
//
//        v2 = *(uint64_t*)(inventoryItemAddr + 0x38);
//        if (v2)
//            result = *(unsigned int*)(v2 + 0x124);
//        return result;
//    }
//
//    static std::string getItemName(__int64 inventoryItemAddr) {
//        try
//        {
//            __int64 itemDeclAdrr = *(__int64*)(inventoryItemAddr + 0x38);
//            if (itemDeclAdrr) {
//                __int64 itemNameStrAddr = *(__int64*)(itemDeclAdrr + 8);
//                return std::string((const char*)(itemNameStrAddr));
//            }
//        }
//        catch (const std::exception& ex)
//        {
//            logInfo("getItemName: %s", ex.what());
//        }
//        return "unknownItemName";
//    }
//
//    static int getItemQuantity(__int64 inventoryItemAddr) {
//        if (!MemHelper::isBadReadPtr((void*)inventoryItemAddr)) {
//            unsigned int quantity = (unsigned int)(*(__int64(__fastcall**)(__int64))(*(uint64_t*)inventoryItemAddr + 0xD0i64))(inventoryItemAddr);
//            return quantity;
//        }
//        return 0;
//    }
//
//    //? side note: keep in mind the listInventory console cmd will list inventory of an AI if one is targeted at this moment.
//    //! Our code here however does not do that even if an AI is targeted.
//    static void getIdInventoryItems() {
//
//        m_inventoryItemsVec.clear();
//
//        __int64 idPlayerAdrr = ObjectLocator::getIdPlayerAdrr();
//        if (!MemHelper::isBadReadPtr((void*)idPlayerAdrr)) {
//            idPlayer_t* idPlayer = (idPlayer_t*)idPlayerAdrr;
//            //! we use the & here cause we want the addr of the ptr not the addr pointed to:
//            __int64 inventoryListStartAddr = (__int64)(&idPlayer->InventoryStructPtr);
//            int itemsCount = (int)idPlayer->InventoryItemsCount;
//            int itemsMaxCount = (int)idPlayer->InventoryItemsMaxCount;
//            /* logInfo("getIdInventoryItems: inventoryListStartAddr: %llx", inventoryListStartAddr);
//             logInfo("getIdInventoryItems: inventory count: %d", itemsCount);
//             logInfo("getIdInventoryItems: inventory max count: %d", itemsMaxCount);
//             logInfo("getIdInventoryItems: listing items addr: ");*/
//            for (int i = 0; i < itemsCount; i++)
//            {
//                __int64 invItemAddr = pidInventoryCollection_GetInventoryItem(inventoryListStartAddr, i);
//                std::string itemName = getItemName(invItemAddr);
//                int itemQuantity = getItemQuantity(invItemAddr);
//                unsigned int itemId = getItemId(invItemAddr);
//                m_inventoryItemsVec.push_back(InventoryItem{ getItemName(invItemAddr), getItemQuantity(invItemAddr) });
//                logInfo("item index: %d item addr: %llx item id: %u item name: %s item quantity: %d", i, invItemAddr, itemId, itemName.c_str(), itemQuantity);
//            }
//            //todo make sure you test the game in other languages to make sure the items have english names.
//            debugPrintInventoryItemsVec();
//        }
//        else {
//            logWarn("getIdInventoryItems: failed because idPlayerAdrr is bad ptr");
//        }
//    }
//
//
//public:
//
//    //! this actually works, the only issus is that it doesn't trigger the "empty" shound when equipment is recharging.
//    static void testThrowNade(int type) {
//        __int64 idPlayerPtr = ObjectLocator::getIdPlayerAdrr();
//        //__int64 nadeType = 1;
//
//        if (!MemHelper::isBadReadPtr((void*)idPlayerPtr)) {
//            __int64 throwableDecl = *(uint64_t*)(*(uint64_t*)(*(uint64_t*)(idPlayerPtr + 0x2F510) + 0x840i64) + 0x10 * (__int64)type);
//            if (!MemHelper::isBadReadPtr((void*)throwableDecl)) {
//                p_idPlayer_UseEquipmentItem((__int64*)idPlayerPtr, throwableDecl, 0, 0);
//            }
//            else {
//                logWarn("testThrowNade: badptr throwableDecl :  %p", (void*)throwableDecl);
//            }
//        }
//        else {
//            logWarn("testThrowNade: badptr idPlayerPtr:  %p", (void*)idPlayerPtr);
//        }
//    }
//
//    //? might have to handle collectible cheats as some might give abilities that should reflect on the hud
//    static PlayerInventory getPlayerInventory() {
//        getIdInventoryItems();
//        PlayerInventory playerInventory;
//
//        for (size_t i = 0; i < m_inventoryItemsVec.size(); i++)
//        {
//            if (m_inventoryItemsVec[i].Name == "weapon/player/fists") {
//                playerInventory.Fists = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/fist") {
//                playerInventory.FistsAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/fists_berserk") {
//                playerInventory.BerserkFists = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/fists_doom5melee") {
//                playerInventory.Doom5MeleeFists = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/fists_swim") {
//                playerInventory.SwimFists = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/pointing_arm") {
//                playerInventory.PointingArm = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/doomblade") {
//                playerInventory.DoomBlade = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "equipmentlauncher/equipmentlauncherleft") {
//                playerInventory.LeftEquipementLauncher = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "extra_life") {
//                playerInventory.ExtraLife = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "jumpboots/base") {
//                playerInventory.JumpBoots = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "abilities/environmentsuit") {
//                playerInventory.EnvironmentSuit = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "abilities/grapplegloves") {
//                playerInventory.GrappleGloves = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/shotgun") {
//                playerInventory.Shotgun = m_inventoryItemsVec[i].Count; //? keep in mind count here is not ammo but weapon count
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/shells") {
//                playerInventory.ShellAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/chainsaw") {
//                playerInventory.ChainsawEquipement = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/fuel") {
//                playerInventory.FluelAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/heavy_cannon") {
//                playerInventory.HeavyCannon = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/bullets") {
//                playerInventory.BulletAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "equipment/frag_grenade") { //! this doesnt have nade counts
//                playerInventory.FragGrenade = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "equipment/flame_belch") {  //! this doesnt have flame count
//                playerInventory.FlameBelch = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "abilities/blood_punch") {
//                playerInventory.BloodPunchAbility = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ability_dash") {
//                playerInventory.DashAbility = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/plasma_rifle") {
//                playerInventory.PlasmaRifle = m_inventoryItemsVec[i].Count; //? gun count, not ammo.
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/cells") {
//                playerInventory.CellAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "equipment/ice_bomb") { //? not nades count but equipment count.
//                playerInventory.IceGrenadeEquipment = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/rocket_launcher") {
//                playerInventory.RocketLauncher = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/rockets") {
//                playerInventory.RocketAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "actormodifier/sp/demon/revenant") {
//                playerInventory.RevenantModifier = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/double_barrel") {
//                playerInventory.SuperShotgun = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/player/doomblade") {
//                playerInventory.DoomBladeAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/gauss_rifle") {
//                playerInventory.Ballista = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/chaingun") {
//                playerInventory.MiniGun = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/bfg") {
//                playerInventory.Bfg = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/bfg") {
//                playerInventory.BfgAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/crucible") {
//                playerInventory.Crucible = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/crucible") {
//                playerInventory.CrucibleAmmo = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/unmaykr") {
//                playerInventory.Unmaykr = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "weapon/player/hammer") {
//                playerInventory.Hammer = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "ammo/sharedammopool/hammer") {
//                playerInventory.HammerAmmo = m_inventoryItemsVec[i].Count; //? afaik this value will be wrong we'll get it somewhere else.
//            }
//            else if (m_inventoryItemsVec[i].Name == "map_objects/dive_suit_damage_decreases_oxygen") {
//                playerInventory.OxygentSuit = m_inventoryItemsVec[i].Count;
//            }
//            else if (m_inventoryItemsVec[i].Name == "map_objects/rad_shield_damage_decreases_shield") {
//                playerInventory.RadSuit = m_inventoryItemsVec[i].Count;
//            }
//        }
//        return playerInventory;
//    }
//
//
//    static void debugPrintInventoryItemsVec() {
//        logInfo("debugPrintInventoryItemsVec: ");
//        for (size_t i = 0; i < m_inventoryItemsVec.size(); i++)
//        {
//            logInfo("item name: %s item count: %d", m_inventoryItemsVec[i].Name.c_str(), m_inventoryItemsVec[i].Count);
//        }
//    }
//
//    //todo could be nice to look into ida when the code gets items and checks if idPlayer is valid or not, i'm pretty sure i saw something like that with a relation to gamelocal
//    static void debugGetOwnedItems() {
//
//        //? we still want to hook the inventory removed func as we HAVE to know if for any reason a player manage to remove a weapon and get the inventory right.
//        __int64 idPlayerAdrr = ObjectLocator::getIdPlayerAdrr();
//        if (!MemHelper::isBadReadPtr((void*)idPlayerAdrr)) {
//            idPlayer_t* idPlayer = (idPlayer_t*)idPlayerAdrr;
//            //! we use the & here cause we want the addr of the ptr not the addr pointed to:
//            __int64 inventoryListStartAddr = (__int64)(&idPlayer->InventoryStructPtr);
//            int itemsCount = (int)idPlayer->InventoryItemsCount;
//            int itemsMaxCount = (int)idPlayer->InventoryItemsMaxCount;
//            logInfo("debugGetOwnedItems: inventoryListStartAddr: %llx", inventoryListStartAddr);
//            logInfo("debugGetOwnedItems: inventory count: %d", itemsCount);
//            logInfo("debugGetOwnedItems: inventory max count: %d", itemsMaxCount);
//            logInfo("debugGetOwnedItems: listing items addr: ");
//            for (int i = 0; i < itemsCount; i++)
//            {
//                __int64 invItemAddr = pidInventoryCollection_GetInventoryItem(inventoryListStartAddr, i);
//                std::string itemName = getItemName(invItemAddr);
//                int itemQuantity = getItemQuantity(invItemAddr);
//                logInfo("item index: %d item addr: %llx item name: %s item quantity: %d", i, invItemAddr, itemName.c_str(), itemQuantity);
//            }
//            //todo make sure you test the game in other languages to make sure the items have english names.
//        }
//    }
//
//
//    //void getOwnedItems()
//    //{
//    //    //std::cout << "getOwnedItems: reference: 7113 (shotgun) 8562(ar), 7404 (plasma), ssg(22668), rl(7732), bfg(20817), unmaker(11052), minigun(7982), ballista(8300), sword(23691), Hammer(10464) frag(9843) ice(276A)" << std::endl;
//    //    static unsigned int lastInvItemsCount = -1;
//
//    //    std::vector<uintptr_t>ownedItemPtrsVec{};
//
//
//    //    try
//    //    {
//    //        //m_ownedItemIdsVec.clear();
//    //        //m_WeaponsVec.clear();
//    //        //m_ownedItemPtrsVec.clear();
//    //        m_ownedItemIds.clear();
//
//    //        if (isBadReadPtr((void*)m_idInventoryCollectionPtr)) {
//    //            /*spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for m_idInventoryCollectionPtr: {:x} ", m_idInventoryCollectionPtr);*/
//    //            std::cout << "getOwnedItems: ERROR 1 " << std::endl;
//    //            return;
//    //        }
//    //        uintptr_t itemListPtr = *(uintptr_t*)m_idInventoryCollectionPtr;
//    //        if (isBadReadPtr((void*)itemListPtr)) {
//    //            std::cout << "getOwnedItems: ERROR 2 " << std::endl;
//
//    //            //spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for itemListPtr: {:x} ", itemListPtr);
//    //            return;
//    //        }
//
//    //        std::cout << "getOwnedItems: m_idInventoryCollectionPtr is:  " << std::hex << m_idInventoryCollectionPtr << std::endl;
//
//    //        int inventoryItemsCount = getInventoryItemsCount();
//    //        if (inventoryItemsCount != lastInvItemsCount) {
//    //            lastInvItemsCount = inventoryItemsCount;
//    //            std::cout << "getOwnedItems: inventoryItemsCount has changed to: " << std::dec << inventoryItemsCount << std::endl;
//    //        }
//    //        if (inventoryItemsCount == 0) {
//    //            return;
//    //        }
//
//
//    //        std::cout << "" << std::endl; //! to make logging a bit cleaner
//
//    //      
//
//    //        uintptr_t itemPtr = itemListPtr + 0x8;
//    //        for (size_t i = 0; i < inventoryItemsCount; i++)
//    //        {
//    //            //spdlog::debug("MemHelper::getOwnedWeapons: adding itemPtr: {:x} ", itemPtr);
//    //            ownedItemPtrsVec.push_back(itemPtr);
//    //            itemPtr += 0x20;
//    //        }
//    //        for (size_t i = 0; i < ownedItemPtrsVec.size(); i++)
//    //        {
//    //            if (!isBadReadPtr((void*)ownedItemPtrsVec[i])) {
//    //                //uintptr_t itemDeclPtr = *(unsigned int**)(g_ownedItemPtrsVec[i] + 0x34);
//    //                //std::cout << "getOwnedItems: g_ownedItemPtrsVec[i]: " << std::hex << g_ownedItemPtrsVec[i] << std::endl;
//    //                uintptr_t itemDeclPtr = *(uintptr_t*)ownedItemPtrsVec[i] + 0x38;
//    //                //std::cout << "getOwnedItems: itemDeclPtr: " << itemDeclPtr << std::endl;
//    //                if (!isBadReadPtr((void*)itemDeclPtr)) {
//    //                    uintptr_t itemIdAddr = *(uintptr_t*)itemDeclPtr + 0x34;
//
//    //                    if (! isBadReadPtr((void*)itemIdAddr)) {
//    //                        unsigned int itemId = *(unsigned int*)(itemIdAddr);
//
//    //                        for (size_t i = 0; i < watchedItemsIdsVec.size(); i++)
//    //                        {
//    //                            if (itemId == watchedItemsIdsVec[i]) {
//    //                                m_ownedItemIds.push_back(itemId);
//    //                                std::cout << "getOwnedItems: found known item: " << getItemNameFromItemDeclId(itemId) << " and idDeclWeapon ptr is: " << std::hex << *(uintptr_t*)itemDeclPtr << std::endl;
//    //                                break;
//    //                            }
//    //                        }
//    //                    }
//    //                }
//
//    //                //std::cout << "getOwnedItems: itemIdAddr: " << itemIdAddr << std::endl;
//    //                //uintptr_t itemStrPtrAddr = *(uintptr_t*)itemDeclPtr + 0x8;
//    //                //std::cout << "getOwnedItems: itemStrPtrAddr: " << itemStrPtrAddr << std::endl;
//    //                //uintptr_t itemStrAddr = *(uintptr_t*)itemStrPtrAddr;
//    //                //std::cout << "getOwnedItems: itemStrAddr: " << itemStrAddr << std::endl;
//
//    //                //std::cout << "getOwnedItems: found itemStr: " <<  *(char*)(itemStrAddr) << std::endl;
//    //                //std::string itemStr = *(char*)(itemStrAddr);
//    //                //unsigned int itemId = *(unsigned int*)(g_ownedItemPtrsVec[i] + 0x34);
//    //                //std::string itemStr = *(std::string*)(g_ownedItemPtrsVec[i] + 0x8);
//    //                //spdlog::debug("MemHelper::getOwnedWeapons: itemDeclPtr: {:x} ", itemDeclPtr);
//    //                //std::cout << "getOwnedItems: found item id: " << itemId <<  std::endl;
//
//
//    //                //std::string itemStr = getItemNameFromItemDeclId(itemId);
//    //                //if (itemStr != "unknowItem") {
//    //                //    //std::cout << "getOwnedItems: found known item id(decimal): " << std::dec << itemId << " corresponding str: " << getItemNameFromItemDeclId(itemId) << std::endl;
//    //                //    g_ownedItemIds.push_back(itemId);
//    //                //}              
//    //                //std::cout << "getOwnedItems: found item id: " << itemId << " and str: " << itemStr << std::endl;
//    //                //if (!isBadReadPtr((void*)itemDeclPtr)) {
//    //                //    //unsigned int valAddr = *(uintptr_t*)itemDeclPtr + 0x34;
//    //                //    uintptr_t valAddr = *(uintptr_t*)itemDeclPtr + 0x34;
//    //                //    uintptr_t strAddr = *(uintptr_t*)itemDeclPtr + 0x8;
//    //                //    //spdlog::debug("MemHelper::getOwnedWeapons: valAddr: {:x} ", valAddr);
//    //                //    if (!isBadReadPtr((void*)valAddr)) {
//    //                //        //unsigned int itemId = *(unsigned int*)valAddr;
//    //                //        std::string itemStr = *(std::string*)strAddr;
//    //                //        std::cout << "getOwnedItems: found item id: " << itemId  << " and str: " << itemStr << std::endl;
//    //                //        /*if (isWeapon(itemId)) {
//    //                //            spdlog::debug("MemHelper::getOwnedWeapons: adding weapon with id: {} ", itemId);
//    //                //            m_WeaponsVec.push_back(itemId);
//    //                //        }*/
//    //                //    }
//    //                //    else {
//    //                //        std::cout << "getOwnedItems: ERROR 6 " << std::endl;
//    //                //    }
//    //                //}
//    //                //else {
//    //                //    //spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for itemDeclPtr: {:x} ", itemDeclPtr);
//    //                //    std::cout << "getOwnedItems: ERROR 3 " << std::endl;
//
//    //                //}
//    //            }
//    //            else {
//    //                //spdlog::debug("MemHelper::getOwnedWeapons: found bad ptr for m_ownedItemPtrsVec[i]: {:x} ", m_ownedItemPtrsVec[i]);
//    //                std::cout << "getOwnedItems: ERROR 4 " << std::endl;
//
//    //            }
//    //        }
//    //    }
//    //    catch (const std::exception& ex)
//    //    {
//    //        //spdlog::error("MemHelper::getOwnedWeapons: exception: {} ", ex.what());
//    //        std::cout << "getOwnedItems: ERROR 5 " << ex.what() << std::endl;
//
//    //    }
//    //}
//
//
//
//    //int getInventoryItemsCount()
//    //{
//    //    try
//    //    {
//    //        __int64 idPlayerAdrr = ObjectLocator::getIdPlayerAddr();
//    //        if (isBadReadPtr((void*)idPlayerAdrr)) {
//    //            //spdlog::warn("MemHelper::getInventoryItemsCount: found bad ptr for m_idPlayerPtr: {:x} returning -1 ", m_idPlayerPtr);
//    //            std::cout << "getInventoryItemsCount: ERROR bad ptr " << std::endl;
//    //        }
//    //        else {
//    //            int count = *(unsigned int*)(idPlayerAdrr + m_idPlayerItemsCountOffset);
//    //            if (count > m_maxItemsCount) {
//    //                std::cout << "getInventoryItemsCount: ERROR items count is:  " << count << " returning 0" << std::endl;                   
//    //            }
//    //            else {
//    //                return count;
//    //            }
//    //            //return *(uintptr_t*)(g_idPlayerPtr + idPlayerItemsCountOffset);
//    //            //return *(uintptr_t*)(g_idPlayerPtr + idPlayerItemsCountOffset);
//    //        }
//    //    }
//    //    catch (const std::exception& ex)
//    //    {
//    //        //spdlog::error("MemHelper::getInventoryItemsCount: exception ERROR: {} ", ex.what());
//    //        std::cout << "getInventoryItemsCount: ex:  " << ex.what() << std::endl;
//    //    }
//    //    return 0;
//    //}
//
//
//   /* std::string getItemNameFromItemDeclId(unsigned int itemId)
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
//    }*/
//
//
//};
//
//std::vector<InventoryItem> idInventoryCollectionManager::m_inventoryItemsVec{ 0 };
//
//idInventoryCollectionManager::idPlayer_UseEquipmentItem idInventoryCollectionManager::p_idPlayer_UseEquipmentItem = reinterpret_cast<idPlayer_UseEquipmentItem>(MemHelper::getFuncAddr(0xA5F3D90));
//
//idInventoryCollectionManager::idInventoryCollection_GetInventoryItem idInventoryCollectionManager::pidInventoryCollection_GetInventoryItem = reinterpret_cast<idInventoryCollection_GetInventoryItem>(MemHelper::getFuncAddr(0x1D1D6A0));