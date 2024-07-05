#include "idInventoryManager.h"




std::string idInventoryCollectionManager::getDebugStr()
{
    std::string resultStr = "idInventoryCollectionManager: Debug:\n";

    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

    if (pIdActor) {       
        resultStr += "\t inventory addr: " + K_Utils::ptrToHexString(&pIdActor->inventory) + "\n";
        resultStr += "\t inventory num: " + std::to_string(pIdActor->inventory.inventory.num) + "\n";   

        resultStr += "\t Is GameHook Frag Nade Owned:" + std::to_string(m_isFragNadeOwned_GameHook) + "\n";
        resultStr += "\t Is GameHook Ice Nade Owned:" + std::to_string(m_isIceNadeOwned_GameHook) + "\n";


        resultStr += "\t Is Frag Nade Owned:" + std::to_string(isFragNadeOwned()) + "\n";
        resultStr += "\t Is Ice Nade Owned:" + std::to_string(isIceNadeOwned()) + "\n";
        resultStr += "\t IsDashAbilityOwned:" + std::to_string(isDashAbilityOwned()) +  " IsDisabledDashBlur from settings: "  + std::to_string(modSettings::getIsDisabledDashBlurEffect()) + "\n";


        resultStr += getCustomInventoryStr();

    }
    else {
        resultStr += "\t Failed to get IdActor can not get data\n";
    }

    return resultStr;
}


//bool idInventoryCollectionManager::acquirreGetInventoryItemFuncAddr(__int64 getInventoryItemFuncAddr) {
//    logDebug("acquirreGetInventoryItemFuncAddr");
//    if (MemHelper::isBadReadPtr((void*)getInventoryItemFuncAddr)) {
//        return false;
//    }
//    m_getInventoryItemFp = reinterpret_cast<idInventoryCollection_GetInventoryItem>(getInventoryItemFuncAddr);
//    logInfo("acquirremGetInventoryItemFuncAddr: m_getInventoryItemFp is set to %p", m_getInventoryItemFp);
//    return true;
//
//}




 //! This is basically current inventory but only for code in the hooks. our mod loop will manage its own inventory data to prevent race conditions. atm call from idInventoryCollection_Smth_1CFBB90(__int64 idInventoryCollection_a1, __int64 a2))
 //! to make sure you have nades you want to make sure you have Item_ResourceID::THROWABLE_PLAYER_ICE_BOMB and THROWABLE_PLAYER_FRAG_GRENADE
 void idInventoryCollectionManager::updateOwnedItemsForHooks(__int64 idInventoryCollectionAddr) {

     bool isFragNadeFound = false;
     bool isIceNadeFound = false;

     idInventoryCollection* playerInv = (idInventoryCollection*)idInventoryCollectionAddr;   

     idManagedClassPtr_idEntity* managedEntityPtr = (idManagedClassPtr_idEntity*)playerInv->inventory.list;

     for (int i = 0; i < playerInv->inventory.num; i++)
     {

         if (isFragNadeFound && isIceNadeFound) break;

         //! it's important to check this even more as if we remove an item through cmd this will be null.
         if (managedEntityPtr->entity_ptr) { 
             idInventoryItem* invItem = (idInventoryItem*)managedEntityPtr->entity_ptr;
             if (invItem) {
                 ItemRef itemRef = getItemRef(invItem);
                 if (itemRef == ItemRef::THROWABLE_PLAYER_FRAG_GRENADE) {
                     isFragNadeFound = true;
                 }
                 else if (itemRef == ItemRef::THROWABLE_PLAYER_ICE_BOMB) {
                     isIceNadeFound = true;
                 }
             }
         }

         managedEntityPtr++;         
     }

     m_isFragNadeOwned_GameHook = isFragNadeFound;
     m_isIceNadeOwned_GameHook = isIceNadeFound;
 }

 bool idInventoryCollectionManager::getCriticalIsFragNadeOwned()
 {
     return m_isFragNadeOwned_GameHook;
 }

 bool idInventoryCollectionManager::getCriticalIsIceNadeOwned()
 {
     return m_isIceNadeOwned_GameHook;
 }


 ItemRef idInventoryCollectionManager::getItemRef(idInventoryItem* inventoryItemPtr) {

     ItemRef result = ItemRef::UNKNOWN;

     idDeclInventory* decl = inventoryItemPtr->decl;
     if (decl) {
         idResource* resource = (idResource*)decl;
         if (resource->name.str) {
             result = getItemRefForStr(resource->name.str);
            /* const char* resultCStr = getStrForItemRef(result);
             logInfo("getItemRef: result was: %s (int %d)", resultCStr, (int)result);*/
         }
     }
     return result;
 }

 //? this will handle A VERY SMALL SUBSET OF THE ITEMS DONT FORGET THAT
 ItemRef idInventoryCollectionManager::getItemRefForStr(const char* input) {
     if (strcmp(input, "weapon/player/shotgun") == 0) {
         return ItemRef::WEAPON_PLAYER_SHOTGUN;
     }     
     if (strcmp(input, "weapon/player/heavy_cannon") == 0) {
         return ItemRef::WEAPON_PLAYER_HEAVY_CANNON;
     }    
     if (strcmp(input, "weapon/player/plasma_rifle") == 0) {
         return ItemRef::WEAPON_PLAYER_PLASMA_RIFLE;
     }    
     if (strcmp(input, "weapon/player/rocket_launcher") == 0) {
         return ItemRef::WEAPON_PLAYER_ROCKET_LAUNCHER;
     }     
     if (strcmp(input, "weapon/player/double_barrel") == 0) {
         return ItemRef::WEAPON_PLAYER_DOUBLE_BARREL;
     }     
     if (strcmp(input, "weapon/player/gauss_rifle") == 0) {
         return ItemRef::WEAPON_PLAYER_GAUSS_RIFLE;
     }    
     if (strcmp(input, "weapon/player/chaingun") == 0) {
         return ItemRef::WEAPON_PLAYER_CHAINGUN;
     }    
     if (strcmp(input, "weapon/player/bfg") == 0) {
         return ItemRef::WEAPON_PLAYER_BFG;
     }    
     if (strcmp(input, "weapon/player/unmaykr") == 0) {
         return ItemRef::WEAPON_PLAYER_UNMAYKR;
     }
     if (strcmp(input, "weapon/player/crucible") == 0) {
         return ItemRef::WEAPON_PLAYER_CRUCIBLE;
     }
     if (strcmp(input, "weapon/player/hammer") == 0) {
         return ItemRef::WEAPON_PLAYER_HAMMER;
     }
     if (strcmp(input, "throwable/player/frag_grenade") == 0) {
         return ItemRef::THROWABLE_PLAYER_FRAG_GRENADE;
     }
     if (strcmp(input, "throwable/player/ice_bomb") == 0) {
         return ItemRef::THROWABLE_PLAYER_ICE_BOMB;
     }

     if (strcmp(input, "ability_dash") == 0) {
         return ItemRef::ABILITY_DASH;
     }

     return ItemRef::UNKNOWN; // Return UNKNOWN if no match is found
 }


 //? this will not handle ALL the items the slayer has and not all the ItemRef !!!
 const char* idInventoryCollectionManager::getStrForItemRef(ItemRef itemRef) {
     switch (itemRef) {
     case ItemRef::WEAPON_PLAYER_SHOTGUN:
         return "weapon/player/shotgun";
     case ItemRef::WEAPON_PLAYER_HEAVY_CANNON:
         return "weapon/player/heavy_cannon";
     case ItemRef::WEAPON_PLAYER_PLASMA_RIFLE:
         return "weapon/player/plasma_rifle";
     case ItemRef::WEAPON_PLAYER_ROCKET_LAUNCHER:
         return "weapon/player/rocket_launcher";
     case ItemRef::WEAPON_PLAYER_DOUBLE_BARREL:
         return "weapon/player/double_barrel";
     case ItemRef::WEAPON_PLAYER_GAUSS_RIFLE:
         return "weapon/player/gauss_rifle";
     case ItemRef::WEAPON_PLAYER_CHAINGUN:
         return "weapon/player/chaingun";
     case ItemRef::WEAPON_PLAYER_BFG:
         return "weapon/player/bfg";
     case ItemRef::WEAPON_PLAYER_UNMAYKR:
         return "weapon/player/unmaykr";
     case ItemRef::WEAPON_PLAYER_CRUCIBLE:
         return "weapon/player/crucible";
     case ItemRef::WEAPON_PLAYER_HAMMER:
         return "weapon/player/hammer";
     case ItemRef::THROWABLE_PLAYER_FRAG_GRENADE:
         return "throwable/player/frag_grenade";
     case ItemRef::THROWABLE_PLAYER_ICE_BOMB:
         return "throwable/player/ice_bomb";
     case ItemRef::ABILITY_DASH:        
         return "ability_dash";
     default:
         return "UNKNOWN";
     }
 }





  //? !!!!!!!!  this will handle A VERY SMALL SUBSET OF THE ITEMS DONT FORGET THAT !!!!!!!!!!!!!!!!!
 void idInventoryCollectionManager::updateCustomInventory() {      //! this is used by our mod code only
    
     m_customInventoryVec.clear();
    
     idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

     if (pIdActor) {

         idInventoryCollection* playerInv = &pIdActor->inventory;
         idManagedClassPtr_idEntity* managedEntityPtr = (idManagedClassPtr_idEntity*)playerInv->inventory.list;

         for (int i = 0; i < playerInv->inventory.num; i++)
         {
             //! it's important to check this even more as if we remove an item through cmd this will be null.
             if (managedEntityPtr->entity_ptr) {
                 idInventoryItem* invItem = (idInventoryItem*)managedEntityPtr->entity_ptr;
                 if (invItem) {
                     ItemRef itemRef = getItemRef(invItem);
                     if (itemRef != ItemRef::UNKNOWN) {
                         m_customInventoryVec.push_back(itemRef);
                     }
                 }
             }
             managedEntityPtr++;
         }
     }
     else {
         logWarn("updateCustomInventory: failed because pIdActor is bad ptr");
         return;
     }
 }


 bool idInventoryCollectionManager::isDashAbilityOwned() {
     
     for (ItemRef itemref : m_customInventoryVec) {
         if (itemref == ItemRef::ABILITY_DASH) {
             return true;
         }
     }
     return false;
 }

 bool idInventoryCollectionManager::isFragNadeOwned() {
    
     for (ItemRef itemref : m_customInventoryVec) {
         if (itemref == ItemRef::THROWABLE_PLAYER_FRAG_GRENADE) {
             return true;
         }
     }
     return false;
 }

 bool idInventoryCollectionManager::isIceNadeOwned() {
     for (ItemRef itemref : m_customInventoryVec) {
         if (itemref == ItemRef::THROWABLE_PLAYER_ICE_BOMB) {
             return true;
         }
     }
     return false;
 }


 //! WEAPONS
bool idInventoryCollectionManager::isWeaponOwned(weaponSlot_t weaponIndex) {

    if (weaponIndex == weaponSlot_t::UNDEFINED) return false;

    for (size_t i = 0; i < m_customInventoryVec.size(); i++)
    {
        
        if (m_customInventoryVec[i] == ItemRef::WEAPON_PLAYER_BFG && weaponIndex == weaponSlot_t::BFG_UNMAYKR) {
            return true;
        }
        if (m_customInventoryVec[i] == ItemRef::WEAPON_PLAYER_UNMAYKR && weaponIndex == weaponSlot_t::BFG_UNMAYKR) {
            return true;
        }
        if (m_customInventoryVec[i] == ItemRef::WEAPON_PLAYER_CRUCIBLE && weaponIndex == weaponSlot_t::CRUCIBLE_HAMMER) {
            return true;
        }
        if (m_customInventoryVec[i] == ItemRef::WEAPON_PLAYER_HAMMER && weaponIndex == weaponSlot_t::CRUCIBLE_HAMMER) {
            return true;
        }      

        if ((int)m_customInventoryVec[i] == (int)weaponIndex) {
            return true;
        }
    }
    return false;
}


//! custom inventory cause we only list the items we're interested in for the mod
std::string idInventoryCollectionManager::getCustomInventoryStr() {
    
    std::string result = "CUSTOM Inventory: (items count: " + std::to_string(m_customInventoryVec.size()) + ")\n";

    for (size_t i = 0; i < m_customInventoryVec.size(); i++)       
    {
        std::string itemStr = getStrForItemRef(m_customInventoryVec[i]);
        std::string itemLineStr = "\t" + itemStr + "\n";
        result += itemLineStr;
    }

    return result;

}




 
idInventoryItem* idInventoryCollectionManager::getidInventoryItemPtr(ItemRef item_ref) {

    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

    if (pIdActor) {

        idInventoryCollection* playerInv = &pIdActor->inventory;
        idManagedClassPtr_idEntity* managedEntityPtr = (idManagedClassPtr_idEntity*)playerInv->inventory.list;

        for (int i = 0; i < playerInv->inventory.num; i++)
        {
            //! it's important to check this even more as if we remove an item through cmd this will be null.
            if (managedEntityPtr->entity_ptr) {
                idInventoryItem* invItem = (idInventoryItem*)managedEntityPtr->entity_ptr;
                if (invItem) {
                    ItemRef itemRef = getItemRef(invItem);
                    if (itemRef == item_ref) {
                        return invItem;
                    }
                }
            }
            managedEntityPtr++;
        }
    }

    return nullptr;   
}







//idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();

   //if (pIdActor) {

   //    for (int i = 0; i < pIdActor->inventory.inventory.num; i++)
   //    {
   //        idInventoryItem* inventoryItem = (idInventoryItem*) m_getInventoryItemFp((__int64)&pIdActor->inventory, i);
   //        if (!inventoryItem) {
   //            std::string itemName = Item_ResourceID_ToString(itemId);
   //            logErr("getItemAddress: found an invItemAddr with addr 0 looking for itemId: 0x%llX (%s) returning 0", (unsigned long long)itemId, itemName.c_str());
   //            return 0;
   //        }
   //        if (getItemIdV2(inventoryItem) == (unsigned long long)itemId) {
   //            return (__int64)inventoryItem;
   //        }
   //        //if ((ItemID)getItemId(invItemAddr) == itemId) {   
   //        //m_ownedItemIds.push_back(getItemIdV2((idInventoryItem)(__int64)&invItemAddr));
   //        //if ((ItemID)getItemIdV2((idInventoryItem*)invItemAddr) == itemId) {
   //        //    //logInfo("getItemAddress: found itemId: 0x%X invItemAddr: %p", (unsigned int)itemId, (void*)invItemAddr);
   //        //    return invItemAddr;
   //        //}
   //    }
   //}
   //else {
   //    logWarn("getItemAddress: failed because idPlayerAdrr is bad ptr");
   //}
   //return 0;


//
////? got many crashes because of this, because it had the wrong order in the log so the id and the str were switched and it just crashed. Keeping this comment for documentation.
////! printing all the items owned
//
// void idInventoryCollectionManager::debugPrintPlayerCompleteInventory() {
//
//
//    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();
//
//    if (pIdActor) {
//        logInfo("debugPrintPlayerCompleteInventory: (items count: %u)", pIdActor->inventory.inventory.num);
//        for (int i = 0; i < pIdActor->inventory.inventory.num; i++)
//        {
//            idInventoryItem* inventoryItem = (idInventoryItem*)idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
//            //logInfo("debugPrintPlayerCompleteInventory: inventoryItem: %p", inventoryItem);
//            if (!MemHelper::isBadReadPtr(inventoryItem) && !MemHelper::isBadReadPtr(&inventoryItem->decl)) {
//                auto decl = inventoryItem->decl;
//                //logInfo("debugPrintPlayerCompleteInventory: decl: %p", decl);
//                if (!MemHelper::isBadReadPtr(decl) && !MemHelper::isBadReadPtr(&decl->displayName.id)) {
//                    auto id = decl->displayName.id; // this is a idStrId
//                    idResource* resource = (idResource*)decl;
//                    auto name = std::string(resource->name.str);
//                    auto resourceId = resource->resourceID;
//                    //logInfo("inventoryItem: %p decl: %p id: 0x%X", inventoryItem, decl, id);
//                    //auto nameStr = idResourceManager::getidDeclInventoryName(decl);
//                    logInfo("name: %s, displayName.id: 0x%X, inventoryItem addr: %p resourceID: %llX ", name.c_str(), id, inventoryItem, resourceId);
//                    //logInfo("name: %s, id: 0x%X, inventoryItemAddr: %p decl: %p ", name.c_str(), id, inventoryItem, decl);
//                }
//            }
//        }
//    }
//    else {
//        logWarn("debugPrintPlayerCompleteInventory: failed because pIdActor is bad ptr");
//        return;
//    }
//
//
//}
//
// void idInventoryCollectionManager::debugPrintNonCollectiblePlayerInventory() {
//    logInfo("debugPrintNonCollectiblePlayerInventory: ");
//
//    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();
//
//    if (pIdActor) {
//        logInfo("debugPrintNonCollectiblePlayerInventory: (items count: %u)", pIdActor->inventory.inventory.num);
//        for (int i = 0; i < pIdActor->inventory.inventory.num; i++)
//        {
//            idInventoryItem* inventoryItem = (idInventoryItem*)idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
//            //logInfo("debugPrintPlayerCompleteInventory: inventoryItem: %p", inventoryItem);
//            if (!MemHelper::isBadReadPtr(inventoryItem) && !MemHelper::isBadReadPtr(&inventoryItem->decl)) {
//                auto decl = inventoryItem->decl;
//                //logInfo("debugPrintPlayerCompleteInventory: decl: %p", decl);
//                if (!MemHelper::isBadReadPtr(decl) && !MemHelper::isBadReadPtr(&decl->displayName.id)) {
//                    auto id = decl->displayName.id; // this is a idStrId
//                    idResource* resource = (idResource*)decl;
//                    auto name = std::string(resource->name.str);
//                    auto resourceId = resource->resourceID;
//                    if (name.starts_with("collectible")) {
//                        continue;
//                    }
//                    //logInfo("inventoryItem: %p decl: %p id: 0x%X", inventoryItem, decl, id);
//                    //auto nameStr = idResourceManager::getidDeclInventoryName(decl);
//                    logInfo("name: %s, resourceID: 0x%llX ", name.c_str(), resourceId);
//
//                }
//            }
//        }
//    }
//    else {
//        logWarn("debugPrintNonCollectiblePlayerInventory: failed because pIdActor is bad ptr");
//        return;
//    }
//
//
//}


 // bool idInventoryCollectionManager::isItemOwned(Item_ResourceID itemId) {
//    logDebug("isItemOwned");
//
//    // Decide which buffer to read from
//    const std::vector<unsigned long long>& readBuffer = m_useBuffer1.load() ? m_ownedItemIdsBuffer1 : m_ownedItemIdsBuffer2;
//
//    if (readBuffer.empty()) {
//        logWarn("isItemOwned: readBuffer is empty returning false");
//        return false;
//    }
//    unsigned long long itemIdValue = static_cast<unsigned long long>(itemId);
//    for (unsigned long long ownedItemId : readBuffer) {
//        if (ownedItemId == itemIdValue) {
//            return true;
//        }
//    }
//    return false;
//}








//! this is atm call on a timer every 200ms. This method compared to our previous version (commented) makes it less likely for the other thread (game) to acces the m_ownedItemIds when it's been cleared as here, we don't empty it we just swap it with the local one. It's not perfect though but should be good enough for our needs. The next step would be to use events so we know for sure that the inventory has been updated.
// void idInventoryCollectionManager::updateOwnedItemsIds() {
//
//    // Decide which buffer to write to
//   /* std::vector<unsigned long long>& writeBuffer = m_useBuffer1.load() ? m_ownedItemIdsBuffer2 : m_ownedItemIdsBuffer1;
//    writeBuffer.clear();*/
//
//     m_ownedItemsResourceIdsVec.clear();
//
//    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();
//
//    if (pIdActor) {
//        for (int i = 0; i < pIdActor->inventory.inventory.num; i++)
//        {
//            idInventoryItem* invItem = (idInventoryItem*)idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
//            if (!MemHelper::isBadReadPtr(invItem)) {
//                auto itemId = getItemIdV2(invItem);
//                if (itemId != 0) {
//                    m_ownedItemsResourceIdsVec.push_back(itemId);
//                    //writeBuffer.push_back(getItemIdV2((idInventoryItem*)invItemAddr));
//                }
//            }
//        }
//    }
//    else {
//        logWarn("updateOwnedItemsIds: failed because pIdActor is bad ptr");
//        return;
//    }
//
//    // Atomically swap the buffer indicator
//    //m_useBuffer1.store(!m_useBuffer1.load());
//}

// __int64 idInventoryCollectionManager::getItemAddress(Item_ResourceID itemId) {
//    idActor* pIdActor = (idActor*)idMapInstanceLocalManager::getIdPlayer();
//
//    if (pIdActor) {
//
//        for (int i = 0; i < pIdActor->inventory.inventory.num; i++)
//        {
//            idInventoryItem* inventoryItem = (idInventoryItem*)idInventoryCollection_getInventoryItemAddr((__int64)&pIdActor->inventory, i);
//            if (!inventoryItem) {
//                std::string itemName = Item_ResourceID_ToString(itemId);
//                logErr("getItemAddress: found an invItemAddr with addr 0 looking for itemId: 0x%llX (%s) returning 0", (unsigned long long)itemId, itemName.c_str());
//                return 0;
//            }
//            if (getItemIdV2(inventoryItem) == (unsigned long long)itemId) {
//                return (__int64)inventoryItem;
//            }
//            //if ((ItemID)getItemId(invItemAddr) == itemId) {   
//            //m_ownedItemIds.push_back(getItemIdV2((idInventoryItem)(__int64)&invItemAddr));
//            //if ((ItemID)getItemIdV2((idInventoryItem*)invItemAddr) == itemId) {
//            //    //logInfo("getItemAddress: found itemId: 0x%X invItemAddr: %p", (unsigned int)itemId, (void*)invItemAddr);
//            //    return invItemAddr;
//            //}
//        }
//    }
//    else {
//        logWarn("getItemAddress: failed because idPlayerAdrr is bad ptr");
//    }
//    return 0;
//}





// bool idInventoryCollectionManager::debug_isWeaponOwned(weaponSlot_t weaponIndex) {
//    logDebug("debug_isWeaponOwned");
//
//    // Decide which buffer to read from
//   /* const std::vector<unsigned long long>& readBuffer = m_useBuffer1.load() ? m_ownedItemIdsBuffer1 : m_ownedItemIdsBuffer2;*/
//
//
//    //if (readBuffer.empty()) {
//    //    logWarn("debug_isWeaponOwned: readBuffer is empty returning false");
//    //    return false; // Early return if the vector is empty
//    //}
//
//    bool isOwned = false;
//
//    for (size_t i = 0; i < m_ownedItemsResourceIdsVec.size(); i++)
//    {
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_SHOTGUN && weaponIndex == weaponSlot_t::SHOTGUN) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_HEAVY_CANNON && weaponIndex == weaponSlot_t::HAR) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_PLASMA_RIFLE && weaponIndex == weaponSlot_t::PLASMA) {
//            isOwned = true;
//            break;
//        }
//        else if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_ROCKET_LAUNCHER && weaponIndex == weaponSlot_t::ROCKET) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_DOUBLE_BARREL && weaponIndex == weaponSlot_t::SSG) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_GAUSS_RIFLE && weaponIndex == weaponSlot_t::BALLISTA) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_CHAINGUN && weaponIndex == weaponSlot_t::CHAINGUN) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_BFG && weaponIndex == weaponSlot_t::BFG_UNMAYKR) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_UNMAYKR && weaponIndex == weaponSlot_t::BFG_UNMAYKR) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_CRUCIBLE && weaponIndex == weaponSlot_t::CRUCIBLE_HAMMER) {
//            isOwned = true;
//            break;
//        }
//        if (m_ownedItemsRefsModCodeVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_HAMMER && weaponIndex == weaponSlot_t::CRUCIBLE_HAMMER) {
//            isOwned = true;
//            break;
//        }
//    }
//    if (isOwned) {
//        logInfo("debug_isWeaponOwned: weapon: %d is owned !!!", (int)weaponIndex);
//        return true;
//    }
//    else {
//        logInfo("debug_isWeaponOwned: weapon: %d is NOT owned", (int)weaponIndex);
//        return false;
//    }
//    //return false;
//}



/*bool idInventoryCollectionManager::isWeaponOwned(weaponSlot_t weaponIndex) {


    for (size_t i = 0; i < m_ownedItemsResourceIdsVec.size(); i++)
    {
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_SHOTGUN && weaponIndex == weaponSlot_t::SHOTGUN) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_HEAVY_CANNON && weaponIndex == weaponSlot_t::HAR) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_PLASMA_RIFLE && weaponIndex == weaponSlot_t::PLASMA) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_ROCKET_LAUNCHER && weaponIndex == weaponSlot_t::ROCKET) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_DOUBLE_BARREL && weaponIndex == weaponSlot_t::SSG) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_GAUSS_RIFLE && weaponIndex == weaponSlot_t::BALLISTA) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_CHAINGUN && weaponIndex == weaponSlot_t::CHAINGUN) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_BFG && weaponIndex == weaponSlot_t::BFG_UNMAYKR) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_UNMAYKR && weaponIndex == weaponSlot_t::BFG_UNMAYKR) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_CRUCIBLE && weaponIndex == weaponSlot_t::CRUCIBLE_HAMMER) {
            return true;
        }
        if (m_ownedItemsResourceIdsVec[i] == (unsigned long long)Item_ResourceID::WEAPON_PLAYER_HAMMER && weaponIndex == weaponSlot_t::CRUCIBLE_HAMMER) {
            return true;
        }


    }
    return false;
}*/







/*

 resource->resourceID: 14970210bb43503d name: weapon/player/fists
 resource->resourceID: 7cdacd0906c3d2ac name: ammo/sharedammopool/fist
 resource->resourceID: 1dfd28e6b4142bff name: weapon/player/fists_berserk
 resource->resourceID: 38cd385da246588d name: weapon/player/fists_doom5melee
 resource->resourceID: 93c512aed91ce8e2 name: weapon/player/fists_swim
 resource->resourceID: d99b2c4f1d0e392d name: weapon/player/pointing_arm
 resource->resourceID: f540ef201c44a090 name: weapon/player/doomblade
 resource->resourceID: 66b37c9f10bc1b6a name: equipmentlauncher/equipmentlauncherleft
 resource->resourceID: f7775862d5108314 name: extra_life
 resource->resourceID: c5350be1fb9b3462 name: jumpboots/base
 resource->resourceID: c4fecae8620d6422 name: abilities/environmentsuit
 resource->resourceID: 492e14a8101068d3 name: abilities/grapplegloves
 resource->resourceID: 11e81ec2ae351302 name: weapon/player/shotgun
 resource->resourceID: 4fc1662ce66881ac name: ammo/sharedammopool/shells
 resource->resourceID: 479b5d2e771c61d0 name: weapon/player/chainsaw
 resource->resourceID: b6f6bacd01e64e2f name: ammo/sharedammopool/fuel
 resource->resourceID: b7820666379c5a35 name: weapon/player/heavy_cannon
 resource->resourceID: 622277586d6479c6 name: ammo/sharedammopool/bullets
 resource->resourceID: 743c9c82713b45ce name: equipment/frag_grenade
 resource->resourceID: a04abbf5a4ffe0e1 name: throwable/player/frag_grenade
 resource->resourceID: 2a9d2a16b911212a name: collectible/cheats/infinite_extra_lives
 resource->resourceID: 673924f05fe3c6ff name: equipment/flame_belch
 resource->resourceID: 4553971c46781f26 name: weapon/player/equipment_flame_belch
 resource->resourceID: f47168a0751a007c name: abilities/blood_punch
 resource->resourceID: 469037a0886515cb name: collectible/toys/arachnotron
 resource->resourceID: fc27cee0e5949476 name: ability_dash
 resource->resourceID: f2fae14a4faf53bb name: weapon/player/plasma_rifle
 resource->resourceID: b498a965a91a24cd name: ammo/sharedammopool/cells
 resource->resourceID: 1f2c8735616f1b78 name: equipment/ice_bomb
 resource->resourceID: 263f332e79c7a3c7 name: collectible/toys/gargoyle
 resource->resourceID: 4d5f4e10c75dc200 name: actormodifier/sp/demon/revenant
 resource->resourceID: e1fc691592b659a1 name: weapon/player/double_barrel
 resource->resourceID: 191a2b562bac978f name: collectible/toys/soldier_blaster
 resource->resourceID: fec86365d066a19f name: collectible/toys/lost_soul
 resource->resourceID: b798727caa642da4 name: collectible/cheats/silver_bullet_mode
 resource->resourceID: 679a81e6cbf22298 name: collectible/albums/album_03
 resource->resourceID: efc9d92b68567daa name: collectible/toys/hellknight
 resource->resourceID: 9563c9f4e598a51f name: ammo/player/doomblade
 resource->resourceID: 42f622cc2b4506c4 name: weapon/player/gauss_rifle
 resource->resourceID: 620cf38481e9b7fe name: collectible/toys/soldier_shield
 resource->resourceID: b52fd28d427993ed name: collectible/cheats/infinite_ammo
 resource->resourceID: 719931c4147bba87 name: weapon/player/chaingun
 resource->resourceID: 876f176277a03ac1 name: collectible/albums/album_04
 resource->resourceID: 6fcf6823f342dea5 name: collectible/toys/zombie_tier_3
 resource->resourceID: 337e3a3ca2210081 name: collectible/toys/cueball
 resource->resourceID: e234a4e8f8d533f0 name: collectible/albums/album_06
 resource->resourceID: 645631c5c67531ea name: weapon/player/bfg
 resource->resourceID: 803c7bc2cd849430 name: ammo/sharedammopool/bfg
 resource->resourceID: 570e615188a1d987 name: collectible/toys/prowler
 resource->resourceID: 3afc61f9bc4356b name: collectible/cheats/infinite_onslaught
 resource->resourceID: 210d3e68233320d6 name: collectible/albums/album_08
 resource->resourceID: e019c8517c36fced name: collectible/toys/carcass
 resource->resourceID: 24b4723b2afb6784 name: collectible/albums/album_09
 resource->resourceID: 92bb8b29d9eaa9cd name: collectible/toys/pinky
 resource->resourceID: b9159400a9c05449 name: collectible/albums/album_10
 resource->resourceID: f472395d409c5253 name: collectible/cheats/infinite_overdrive
 resource->resourceID: d9ba4db5466d68e1 name: collectible/albums/album_11
 resource->resourceID: 7163d1cc7530330e name: weapon/player/crucible
 resource->resourceID: 6ac8e29263a449f1 name: ammo/sharedammopool/crucible
 resource->resourceID: 92c22b78bf2bb27f name: collectible/toys/gladiator
 resource->resourceID: 23dfd071ed5adf3b name: collectible/toys/doom_hunter
 resource->resourceID: 7999d66085071dcf name: collectible/albums/album_12
 resource->resourceID: db3e333fe6f29b41 name: collectible/albums/album_13
 resource->resourceID: 68761467d3201184 name: collectible/albums/album_15
 resource->resourceID: c7408ef9137ca020 name: collectible/albums/album_16
 resource->resourceID: a1faf71b99afdf28 name: collectible/toys/pinky_spectre
 resource->resourceID: 2c67ac2c2ea61869 name: collectible/toys/maykr_drone
 resource->resourceID: 50446fe6782e63fd name: collectible/cheats/infinite_berserk
 resource->resourceID: ccdb4a724d9b9412 name: weapon/player/unmaykr
 resource->resourceID: 261dea0e39f9b6cf name: throwable/player/ice_bomb
 resource->resourceID: a90b43917c2d2571 name: weapon/player/rocket_launcher
 resource->resourceID: 68d1ca125710f5c1 name: ammo/sharedammopool/rockets


*/


/*

namespace WeaponIdStr {
    //! using strings for id is not great but at least i'll be sure:
    static std::string g_shotGunBaseNameIdStr = "weapon/player/shotgun";
    static std::string g_shotGunStickiesNameIdStr = "weapon/player/shotgun_secondary_pop_rockets";
    static std::string g_shotGunFullAutoNameIdStr = "weapon/player/shotgun_secondary_full_auto";
    static std::string g_heavyCannonNameIdStr = "weapon/player/heavy_cannon";
    static std::string g_heavyCannonBoltNameIdStr = "weapon/player/heavy_cannon_bolt_action";
    static std::string g_heavyCannonDetonateNameIdStr = "weapon/player/heavy_cannon_burst_detonate_mastery";
    static std::string g_plasmaNameIdStr = "weapon/player/plasma_rifle";
    static std::string g_plasmaAoeNameIdStr = "weapon/player/plasma_rifle_secondary_aoe";
    static std::string g_plasmaMicroWaveNameIdStr = "weapon/player/plasma_rifle_secondary_microwave";
    static std::string g_rocketLauncherNameIdStr = "weapon/player/rocket_launcher";
    static std::string g_rocketLauncherDetonateNameIdStr = "weapon/player/rocket_launcher_detonate";
    static std::string g_rocketLauncherLockOnNameIdStr = "weapon/player/rocket_launcher_lock_mod_mastery";
    static std::string g_superShotGunOnNameIdStr = "weapon/player/double_barrel";
    static std::string g_superShotGunPrimaryOnNameIdStr = "weapon/player/double_barrel_primary_lockon";
    static std::string g_superShotGunMeathookNameIdStr = "weapon/player/double_barrel_meat_hook";
    static std::string g_balistaNameIdStr = "weapon/player/gauss_rifle";
    static std::string g_balistaArbalesteNameIdStr = "weapon/player/gauss_rifle_ballista";
    static std::string g_balistaDestroyerBladeNameIdStr = "weapon/player/gauss_rifle_destroyer";
    static std::string g_chaingunNameIdStr = "weapon/player/chaingun";
    static std::string g_chaingunShielNameIdStr = "weapon/player/chaingun_energy_shell";
    static std::string g_chaingunShielPrimaryNameIdStr = "weapon/player/chaingun_energy_shell_primary";
    static std::string g_chaingunTurretPrimaryNameIdStr = "weapon/player/chaingun_turret_primary";
    static std::string g_chaingunTurretSecondaryNameIdStr = "weapon/player/chaingun_turret_secondary";
    static std::string g_bfgNameIdStr = "weapon/player/bfg";
    static std::string g_bfgSphereBurnNameIdStr = "weapon/player/bfg_charge_sphere_burn";
    static std::string g_unmaykrNameIdStr = "weapon/player/unmaykr";
    static std::string g_crucibleNameIdStr = "weapon/player/crucible";
    static std::string g_hammerNameIdStr = "weapon/player/hammer";
}


*/