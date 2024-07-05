#pragma once
#include "GeneratedClasses.h"
#include "MemHelper.h"
#include "idMapInstanceLocalManager.h"
#include "playerPropsManager.h"
#include "idHudManager.h"
#include "playerSoundManager.h"




typedef bool(__fastcall* UseEquipmentItemFp)(
    idPlayer* idPlayer_a1,
    idDeclInventory* idDeclInventory_a2,
    char a3,
    int forceEquipSlot_a4
    );


typedef void(__fastcall* SwitchEquipmentItemFp)(idPlayer* idPlayer_a1, equipmentType_t equipmentType);

/// <summary>
/// this should let us directly throw frag or ice nade AND trigger the no item sound if not item is available
/// </summary>
class EquipmentManager
{

private:

    static inline UseEquipmentItemFp m_UseEquipmentItemFp = nullptr;
    static inline SwitchEquipmentItemFp m_SwitchEquipmentItemFp = nullptr;

public:

    static bool acquireUseEquipmentItemFp(__int64 fAdd);

    static bool acquireSwitchEquipmentItemFp(__int64 fAdd);
    
    static void switchEquipment(equipmentType_t equipmentType);

    static void useEquipmentItem(equipmentType_t equipmentType);
    //idDeclInventory* getPlayerProps();



};

