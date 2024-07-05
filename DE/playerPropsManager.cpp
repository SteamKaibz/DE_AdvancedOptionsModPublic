#include "playerPropsManager.h"




idDeclInventory* playerPropsManager::getEquipmentDecl(equipmentType_t equipmentType) {
    

    idPlayer* playerPtr = idMapInstanceLocalManager::getIdPlayer();
    if (playerPtr) {


        idList* validEquipmentList = (idList*)&playerPtr->playerProps->validEquipmentList;

        if (!validEquipmentList) {
           
            return nullptr;
        }       

        idDeclPlayerProps_validEquipmentEntry_t* equipmentEntrPtr = (idDeclPlayerProps_validEquipmentEntry_t*)validEquipmentList->list;


        for (size_t i = 0; i < validEquipmentList->num; i++)
        {
            if (equipmentEntrPtr->type == equipmentType) {               
                return (idDeclInventory*)equipmentEntrPtr->item;
            }  
            equipmentEntrPtr++;
        }

        logWarn("getEquipmentDecl: failed to get decl for equipmentType: %d", equipmentType);
       
    }
   
    return nullptr;

}


std::string playerPropsManager::getDebugStrV2()
{

    std::string resultStr = "Player Props Manager: NO DATA";

    idPlayer* playerPtr = idMapInstanceLocalManager::getIdPlayer();;

    if (playerPtr) {

        idList* validEquipmentList = (idList*)&playerPtr->playerProps->validEquipmentList;

        if (!validEquipmentList) {
            resultStr += " validEquipmentList is bad ptr can not proceed.";
            return resultStr;
        }

        logInfo("getDebugStrV2: validEquipmentList->list: %p, validEquipmentList->num: %d", validEquipmentList->list, validEquipmentList->num);

        idDeclPlayerProps_validEquipmentEntry_t* equipmentEntrPtr = (idDeclPlayerProps_validEquipmentEntry_t*)validEquipmentList->list;

        resultStr = "Equipment Info: ";

        for (size_t i = 0; i < validEquipmentList->num; i++)
        {
            idResource* resource = (idResource*)equipmentEntrPtr->item;

            std::string entrStr = "entry: " + std::to_string(i) + " at addr: " + K_Utils::ptrToHexString(resource);
            entrStr += " res name: ";
            entrStr += resource->name.str;
            entrStr += " selectable: " + std::to_string(equipmentEntrPtr->selectable);
            entrStr += " type: " + std::to_string((int)equipmentEntrPtr->type);

            resultStr += "\n" + entrStr;

            equipmentEntrPtr++;
        }
    }
       

    return resultStr;

}


