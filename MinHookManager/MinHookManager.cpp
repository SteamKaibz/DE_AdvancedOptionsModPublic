
#include "MinHookManager.h"










 MH_STATUS MinHookManager::getInitializeStatus() {
    return m_initializeStatus;
}

void  MinHookManager::setInitializeStatus(MH_STATUS status) {
    m_initializeStatus = status;
}



 bool  MinHookManager::setPrintOutlinedStringMBFuncAddr(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_printOutlinedStringMBFuncAddr = value;
    return true;
}

 uintptr_t  MinHookManager::GetPrintOutlinedStringMBFuncAddr() {
    return m_printOutlinedStringMBFuncAddr;
}





// bool  MinHookManager::setSetFontAndPrintStringMBFuncAdd(uintptr_t value) {
//    if (MemHelper::isBadReadPtr((void*)value)) {
//        return false;
//    }
//    m_setFontAndPrintStringMBFuncAdd = value;
//    return true;
//}
//
//uintptr_t  MinHookManager::GetSetFontAndPrintStringMBFuncAdd() {
//    return m_setFontAndPrintStringMBFuncAdd;
//}

bool  MinHookManager::setIdHud_Debug_Print_SmthFuncAddr(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_idHud_Debug_Print_SmthFuncAddr = value;
    return true;
}

uintptr_t  MinHookManager::GetIdHud_Debug_Print_SmthFuncAddr() {
    return m_idHud_Debug_Print_SmthFuncAddr;
}


uintptr_t  MinHookManager::getInitRenderModelGuiMbFuncAdd() {
    return m_initRenderModelGuiMbFuncAdd;
}

bool  MinHookManager::setInitRenderModelGuiMbFuncAdd(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_initRenderModelGuiMbFuncAdd = value;
    return true;
}


// Getter for m_idPLayerSelectWeaponForSelectionGroupAddr
uintptr_t  MinHookManager::GetIdPlayerSelectWeaponForSelectionGroupAddr() {
    return m_idPLayerSelectWeaponForSelectionGroupAddr;
}

// Setter for m_idPLayerSelectWeaponForSelectionGroupAddr
bool  MinHookManager::SetIdPlayerSelectWeaponForSelectionGroupAddr(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_idPLayerSelectWeaponForSelectionGroupAddr = value;
    return true;
}

// Getter for m_isKeyPressedAddr
 uintptr_t  MinHookManager::GetIsKeyPressedAddr() {
    return m_isKeyPressedAddr;
}

// Setter for m_isKeyPressedAddr
bool  MinHookManager::SetIsKeyPressedAddr(uintptr_t value) {

    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_isKeyPressedAddr = value;
    return true;
}

// Getter for m_idMenu_UpdateAddr
uintptr_t  MinHookManager::GetIdMenuUpdateAddr() {

    return m_idMenu_UpdateAddr;
}

// Setter for m_idMenu_UpdateAddr
bool  MinHookManager::SetIdMenuUpdateAddr(uintptr_t value) {

    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_idMenu_UpdateAddr = value;
    return true;
}

// Getter for m_pBindsStrSetAddr
uintptr_t  MinHookManager::GetPBindsStrSetAddr() {
    return m_pBindsStrSetAddr;
}

// Setter for m_pBindsStrSetAddr
 bool  MinHookManager::SetPBindsStrSetAddr(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_pBindsStrSetAddr = value;
    return true;
}

// Getter for m_setActiveReticleAddr
uintptr_t  MinHookManager::GetSetActiveReticleAddr() {

    return m_setActiveReticleAddr;
}

// Setter for m_setActiveReticleAddr
bool  MinHookManager::SetSetActiveReticleAddr(uintptr_t value) {

    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_setActiveReticleAddr = value;
    return true;
}

// Getter for m_convertIdDeclUIColorToidColorTargetAddr
uintptr_t  MinHookManager::GetConvertIdDeclUIColorToIdColorTargetAddr() {

    return m_convertIdDeclUIColorToidColorTargetAddr;
}

// Setter for m_convertIdDeclUIColorToidColorTargetAddr
bool  MinHookManager::SetConvertIdDeclUIColorToIdColorTargetAddr(uintptr_t value) {

    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_convertIdDeclUIColorToidColorTargetAddr = value;
    return true;
}

// Getter for m_setSpriteInstanceAddr
uintptr_t  MinHookManager::GetSetSpriteInstanceAddr() {

    return m_setSpriteInstanceAddr;
}

// Setter for m_setSpriteInstanceAddr
bool  MinHookManager::SetSetSpriteInstanceAddr(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_setSpriteInstanceAddr = value;
    return true;
}

// Getter for m_getFovTargetValAddr
uintptr_t  MinHookManager::GetGetFovTargetValAddr() {
    return m_getFovTargetValAddr;
}

// Setter for m_getFovTargetValAddr
bool  MinHookManager::SetGetFovTargetValAddr(uintptr_t value) {
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_getFovTargetValAddr = value;
    return true;
}

uintptr_t MinHookManager::GetCustomAnimSmthFuncAdd()
{
    return m_customAnimSmthFuncAdd;
}

bool MinHookManager::SetCustomAnimSmthFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_customAnimSmthFuncAdd = value;
    return true;
}


uintptr_t MinHookManager::GetIdInventoryCollectionSmthFuncAdd()
{
    return m_idInventoryCollectionSmthFuncAdd;
}

bool MinHookManager::SetIdInventoryCollectionSmthFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr(reinterpret_cast<void*>(value))) {
        return false;
    }
    m_idInventoryCollectionSmthFuncAdd = value;
    return true;
}


uintptr_t MinHookManager::GetIdHUDMenu_CurrencyConfirmationSmthFuncAdd()
{
    return m_idHUDMenu_CurrencyConfirmationSmthFuncAdd;
}

bool MinHookManager::SetIdHUDMenu_CurrencyConfirmationSmthFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr(reinterpret_cast<void*>(value))) {
        return false;
    }
    m_idHUDMenu_CurrencyConfirmationSmthFuncAdd = value;
    return true;
}


uintptr_t MinHookManager::GetStartSyncFuncAdd()
{
    return m_StartSyncFuncAdd;
}

bool MinHookManager::SetStartSyncFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr(reinterpret_cast<void*>(value))) {
        return false;
    }
    m_StartSyncFuncAdd = value;
    return true;
}


uintptr_t MinHookManager::GetIdPlayerFovLerpFuncAdd()
{
    return m_idPlayerFovLerpFuncAdd;
}

bool MinHookManager::SetIdPlayerFovLerpFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr(reinterpret_cast<void*>(value))) {
        return false;
    }
    m_idPlayerFovLerpFuncAdd = value;
    return true;
}


uintptr_t MinHookManager::GetSyncEndFuncAdd()
{
    return m_syncEndFuncAdd;
}

bool MinHookManager::SetSyncEndFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr(reinterpret_cast<void*>(value))) {
        return false;
    }
    m_syncEndFuncAdd = value;
    return true;
}

uintptr_t MinHookManager::GetRenderSpriteFuncAdd()
{
    return m_renderSpriteFuncAdd;
}

bool MinHookManager::SetRenderSpriteFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr(reinterpret_cast<void*>(value))) {
        return false;
    }
    m_renderSpriteFuncAdd = value;
    return true;
}


uintptr_t MinHookManager::GetConsoleLogFuncAdd()
{
    return m_consoleLogFuncAdd;
}

bool MinHookManager::SetConsoleLogFuncAdd(uintptr_t value)
{
    if (MemHelper::isBadReadPtr((void*)value)) {
        return false;
    }
    m_consoleLogFuncAdd = value;
    return true;
}