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
#include "GeneratedClasses.h"
#include "idResourceManager.h"
#include "../ModSettings/modSettings.h"




//? the old version of this cls has been backed and commented in the Bak folder
class idInventoryCollectionManager
{
private:   

    ////! __int64 __fastcall idInventoryCollection::GetInventoryItem_1D1D6A0(__int64 a1, int a2)
    //typedef __int64(__fastcall* idInventoryCollection_GetInventoryItem)(__int64 a1, int a2);
    //static inline idInventoryCollection_GetInventoryItem m_getInventoryItemFp = nullptr;

   //static inline __int64 m_getInventoryItemFuncAddr = 0;

   //! maybe this is best..or not
   //static inline PlayerInventory m_playerInventory;

   //! this is a shitty way to prevent race conditions as these 2 are used by the game input system and i don't want to go fetch the whole inventory for each of its calls
   static inline bool m_isFragNadeOwned_GameHook = false;
   static inline bool m_isIceNadeOwned_GameHook = false;

  //!  only used by mod code. There are not the complete inventory of the slayer onlye items we're interested in.
   static inline std::vector<ItemRef> m_customInventoryVec;
   //static inline std::vector<Item_Reference> m_ownedItemsRefsModCodeVec;
   //static inline std::vector<unsigned long long> m_ownedItemsRefsModCodeVec;
   //? this is temporary until so we can test other things with the mod: (we should use our ItemRef enum instead)
   //static inline std::vector<unsigned long long> m_ownedItemsResourceIdsVec;
   /* static inline std::vector<unsigned long long> m_ownedItemIdsBuffer1;
    static inline std::vector<unsigned long long> m_ownedItemIdsBuffer2;
    static std::atomic<bool> m_useBuffer1;*/


public:


    static const int inline INVENTORY_UPDATE_INTERVAL_MS = 500;


    //! func for hooks to prevent race conds.
    static void updateOwnedItemsForHooks(__int64 idInventoryCollectionAddr);   
    static bool getCriticalIsFragNadeOwned();
    static bool getCriticalIsIceNadeOwned();




    static std::string getDebugStr();

    //static bool acquirreGetInventoryItemFuncAddr(__int64 getInventoryItemFuncAddr);

    static bool isDashAbilityOwned();

    static bool isFragNadeOwned();

    static bool isIceNadeOwned();
      





    static void updateCustomInventory();

    static bool isWeaponOwned(weaponSlot_t weaponIndex);

    static  std::string getCustomInventoryStr();

    static idInventoryItem* getidInventoryItemPtr(ItemRef item_ref);


    static ItemRef getItemRef(idInventoryItem* inventoryItemPtr);

    static ItemRef getItemRefForStr(const char* input);

    static const char* getStrForItemRef(ItemRef itemRef);

   


};



