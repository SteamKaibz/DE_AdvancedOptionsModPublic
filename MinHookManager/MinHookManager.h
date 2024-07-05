#pragma once

#include <windows.h>
#include <cstdint>

#include "MinHook.h"
#include "../DE/MemHelper.h"


class MinHookManager {

private:
    static inline MH_STATUS m_initializeStatus = MH_UNKNOWN;

    static inline uintptr_t m_idPLayerSelectWeaponForSelectionGroupAddr = 0;
    static inline uintptr_t m_isKeyPressedAddr = 0;
    //! try to replace this, we don't really need it:
    static inline uintptr_t m_idMenu_UpdateAddr = 0;
    static inline uintptr_t m_pBindsStrSetAddr = 0;
    //! try to replace this, we don't really need it:
    static inline uintptr_t m_setActiveReticleAddr = 0;
    static inline uintptr_t m_convertIdDeclUIColorToidColorTargetAddr = 0;
    static inline uintptr_t m_setSpriteInstanceAddr = 0;
    static inline uintptr_t m_getFovTargetValAddr = 0;
    static inline uintptr_t m_idHud_Debug_Print_SmthFuncAddr = 0;
    static inline uintptr_t m_printOutlinedStringMBFuncAddr = 0;
    //! this is a func used inside one of the hooks:
    static inline uintptr_t m_initRenderModelGuiMbFuncAdd = 0;
    static inline uintptr_t m_setFontAndPrintStringMBFuncAdd = 0;
    static inline uintptr_t m_customAnimSmthFuncAdd = 0;
    static inline uintptr_t m_idInventoryCollectionSmthFuncAdd = 0;
    static inline uintptr_t m_idHUDMenu_CurrencyConfirmationSmthFuncAdd = 0;
    static inline uintptr_t m_StartSyncFuncAdd = 0;
    static inline uintptr_t m_idPlayerFovLerpFuncAdd = 0;
    static inline uintptr_t m_syncEndFuncAdd = 0;
    static inline uintptr_t m_renderSpriteFuncAdd = 0;
    static inline uintptr_t m_UseEquipmentItemFuncAdd = 0;
    static inline uintptr_t m_consoleLogFuncAdd = 0;



public:
    
    //? you can do that
   //static  MH_STATUS getGlobalMinHookStatus();

    static MH_STATUS getInitializeStatus();

    static void setInitializeStatus(MH_STATUS status);


    static uintptr_t GetPrintOutlinedStringMBFuncAddr();
    static bool setPrintOutlinedStringMBFuncAddr(uintptr_t value);


    //static uintptr_t GetSetFontAndPrintStringMBFuncAdd();
    //static bool setSetFontAndPrintStringMBFuncAdd(uintptr_t value);

    static uintptr_t GetIdHud_Debug_Print_SmthFuncAddr();
    static bool setIdHud_Debug_Print_SmthFuncAddr(uintptr_t value);

    static uintptr_t getInitRenderModelGuiMbFuncAdd();
    static bool setInitRenderModelGuiMbFuncAdd(uintptr_t value);

    static uintptr_t GetIdPlayerSelectWeaponForSelectionGroupAddr();
    static bool SetIdPlayerSelectWeaponForSelectionGroupAddr(uintptr_t value);

    static uintptr_t GetIsKeyPressedAddr();
    static bool SetIsKeyPressedAddr(uintptr_t value);

    static uintptr_t GetIdMenuUpdateAddr();
    static bool SetIdMenuUpdateAddr(uintptr_t value);

    static uintptr_t GetPBindsStrSetAddr();
    static bool SetPBindsStrSetAddr(uintptr_t value);

    static uintptr_t GetSetActiveReticleAddr();
    static bool SetSetActiveReticleAddr(uintptr_t value);

    static uintptr_t GetConvertIdDeclUIColorToIdColorTargetAddr();
    static bool SetConvertIdDeclUIColorToIdColorTargetAddr(uintptr_t value);

    static uintptr_t GetSetSpriteInstanceAddr();
    static bool SetSetSpriteInstanceAddr(uintptr_t value);

    static uintptr_t GetGetFovTargetValAddr();
    static bool SetGetFovTargetValAddr(uintptr_t value);

    static uintptr_t GetCustomAnimSmthFuncAdd();
    static bool SetCustomAnimSmthFuncAdd(uintptr_t value);

    static uintptr_t GetIdInventoryCollectionSmthFuncAdd();
    static bool SetIdInventoryCollectionSmthFuncAdd(uintptr_t value);

    static uintptr_t GetIdHUDMenu_CurrencyConfirmationSmthFuncAdd();
    static bool SetIdHUDMenu_CurrencyConfirmationSmthFuncAdd(uintptr_t value);

    static uintptr_t GetStartSyncFuncAdd();
    static bool SetStartSyncFuncAdd(uintptr_t value);

    static uintptr_t GetIdPlayerFovLerpFuncAdd();
    static bool SetIdPlayerFovLerpFuncAdd(uintptr_t value);

    static uintptr_t GetSyncEndFuncAdd();
    static bool SetSyncEndFuncAdd(uintptr_t value);

    static uintptr_t GetRenderSpriteFuncAdd();
    static bool SetRenderSpriteFuncAdd(uintptr_t value);

    static uintptr_t GetConsoleLogFuncAdd();
    static bool SetConsoleLogFuncAdd(uintptr_t value);

   

};


