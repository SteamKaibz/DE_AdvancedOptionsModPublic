//#pragma once
//#include <vector>
//#include "../DE/ObjectLocator.h"
//#include "../DE/idInventoryCollectionManager.h"
//
//
//
//
//class idInventoryManagerDebug {
//private:
//    //! __int64 __fastcall idInventoryCollection::GetInventoryItem_1D1D6A0(__int64 a1, int a2)
//    typedef __int64(__fastcall* idInventoryCollection_GetInventoryItem)(__int64 a1, int a2);
//    //static idInventoryCollection_GetInventoryItem pidInventoryCollection_GetInventoryItem;
//
//
//
//public:
//
//
//
//    
//
//
//    //static std::vector<std::string> debugGetPlayerInventoryAsVec() {
//    //    std::vector<InventoryItem> itemsVec = getIdInventoryItems();
//    //    std::vector<std::string> inventoryStrVec;
//    //    //PlayerInventory playerInventory;
//
//    //    inventoryStrVec.push_back("Player Inventory: ");
//
//    //    for (size_t i = 0; i < itemsVec.size(); i++)
//    //    {
//
//    //        if (itemsVec[i].ID == (unsigned int)ItemID::Shotgun) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("Shotgun", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::HeavyCannon) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("HeavyCannon", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::PlasmaRifle) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("PlasmaRifle", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::RocketLauncher) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("RocketLauncher", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::SuperShotgun) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("SuperShotgun", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::Ballista) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("Ballista", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::MiniGun) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("MiniGun", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::Bfg) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("Bfg", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::Crucible) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("Crucible", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::Hammer) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("Hammer", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoShells) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("AmmoShells", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBullets) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("AmmoBullets", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoCells) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("AmmoCells", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoRockets) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("AmmoRockets", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBfg) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("AmmoBfg", itemsVec[i].Count));
//    //        }
//    //        else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoFuel) {
//    //            inventoryStrVec.push_back(getItemDebugHudString("AmmoFuel", itemsVec[i].Count));
//    //        }
//    //    }
//    //    return inventoryStrVec;
//    //}
//
//    //? side note: keep in mind the listInventory console cmd will list inventory of an AI if one is targeted at this moment. Our code below here however, does NOT do that even if an AI is targeted.
//    static void printIdInventoryItemsInfo() {
//        logInfo("printIdInventoryItemsInfo called");
//        //m_inventoryItemsVec.clear();
//        //std::vector<InventoryItem> itemsVec;
//
//        __int64 idPlayerAdrr = ObjectLocator::getIdPlayerAdrr();
//        if (!MemHelper::isBadReadPtr((void*)idPlayerAdrr)) {
//            idPlayer_t* idPlayer = (idPlayer_t*)idPlayerAdrr;
//            //! we use the & here cause we want the addr of the ptr not the addr pointed to:
//            __int64 inventoryListStartAddr = (__int64)(&idPlayer->InventoryStructPtr);
//            int itemsCount = (int)idPlayer->InventoryItemsCount;
//            int itemsMaxCount = (int)idPlayer->InventoryItemsMaxCount;
//            logInfo("printIdInventoryItemsInfo: inventoryListStartAddr: %llX", inventoryListStartAddr);
//            logInfo("printIdInventoryItemsInfo: inventory count: %d", itemsCount);
//            logInfo("printIdInventoryItemsInfo: inventory max count: %d", itemsMaxCount);
//            logInfo("printIdInventoryItemsInfo: listing items: ");
//            for (int i = 0; i < itemsCount; i++)
//            {
//                //__int64 invItemAddr = pidInventoryCollection_GetInventoryItem(inventoryListStartAddr, i);
//                __int64 invItemAddr = idInventoryCollection_getInventoryItemAddr(inventoryListStartAddr, i);
//                std::string itemName = getItemName(invItemAddr);
//                int itemQuantity = getItemQuantity(invItemAddr);
//                unsigned int itemId = getItemId(invItemAddr);
//                //itemsVec.push_back(InventoryItem{ getItemId(invItemAddr), getItemName(invItemAddr), getItemQuantity(invItemAddr) });
//                logInfo("printIdInventoryItemsInfo item index: %d item addr: %llX item name: %s item quantity: %d item id: %X", i, invItemAddr, itemName.c_str(), itemQuantity, itemId);
//                //logInfo("item index: %d item addr: %llx item id: %x item name: %s item quantity: %d", i, invItemAddr, itemId, itemName.c_str(), itemQuantity);
//                //logInfo("item id: %x item name: %s", itemId, itemName.c_str());
//            }
//            //todo make sure you test the game in other languages to make sure the items have english names.
//            //debugPrintInventoryItemsVec();
//        }
//        else {
//            logWarn("printIdInventoryItemsInfo: failed because idPlayerAdrr is bad ptr");
//        }       
//    }
//
//
//    static __int64 idInventoryCollection_getInventoryItemAddr(__int64 inventoryListStartAddr, int i) {
//        auto pGetInventory = reinterpret_cast<idInventoryCollection_GetInventoryItem>(Scanner::GetInventoryItemAddr);
//        return pGetInventory(inventoryListStartAddr, i);
//    }
//
//
//
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
//    static std::string getItemDebugHudString(std::string itemName, int itemCount) {
//        std::string itemCounStr = std::to_string(itemCount);
//        return itemName + " " + itemCounStr;
//    }
//
//
//
//    //! might have to handle collectible cheats as some might give abilities that should reflect on the hud
//      //! some items do not have IDs so we dont get them (like hammer ammo, it's ok we have it in idPlayer)
//      //! this inventory is unreliable as for blood punch is not listed in TAG2 so it will only be used to get owned weapons + ammo pools
//      /*static PlayerInventory getPlayerInventory() {
//          std::vector<InventoryItem> itemsVec = getIdInventoryItems();
//          PlayerInventory playerInventory;
//
//          for (size_t i = 0; i < itemsVec.size(); i++)
//          {
//
//              if (itemsVec[i].ID == (unsigned int)ItemID::Shotgun) {
//                  playerInventory.Shotgun = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::HeavyCannon) {
//                  playerInventory.HeavyCannon = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::PlasmaRifle) {
//                  playerInventory.PlasmaRifle = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::RocketLauncher) {
//                  playerInventory.RocketLauncher = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::SuperShotgun) {
//                  playerInventory.SuperShotgun = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::Ballista) {
//                  playerInventory.Ballista = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::MiniGun) {
//                  playerInventory.MiniGun = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::Bfg) {
//                  playerInventory.Bfg = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::Crucible) {
//                  playerInventory.Crucible = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::Hammer) {
//                  playerInventory.Hammer = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoShells) {
//                  playerInventory.ShellAmmo = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBullets) {
//                  playerInventory.BulletAmmo = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoCells) {
//                  playerInventory.CellAmmo = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoRockets) {
//                  playerInventory.RocketAmmo = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoBfg) {
//                  playerInventory.BfgAmmo = itemsVec[i].Count;
//              }
//              else if (itemsVec[i].ID == (unsigned int)ItemID::AmmoFuel) {
//                  playerInventory.FuelAmmo = itemsVec[i].Count;
//              }
//          }
//          return playerInventory;
//      }*/
//
//
//
//
//
//
//
//};
//
//
//
//
//
