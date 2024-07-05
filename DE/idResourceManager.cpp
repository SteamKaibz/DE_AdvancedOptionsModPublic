#include "idResourceManager.h"

 std::string idResourceManager::getDeclWeaponName(idDeclWeapon* idDeclWeaponPtr) {
    idResource* idResourceObj = (idResource*)idDeclWeaponPtr;
    if (MemHelper::isBadReadPtr(idResourceObj)) {
        logErr("getDeclWeaponName: bad ptr for idResourceObj: %p returning empty str", idResourceObj);
    }
    else if (MemHelper::isBadReadPtr(&idResourceObj->name) || MemHelper::isBadReadPtr(&idResourceObj->name.str)) {
        logErr("getDeclWeaponName:: bad ptr found for ->name or ->name.str derivedObjPtr addr: %p returning empty str", idResourceObj);
    }
    else {
        return std::string(idResourceObj->name.str);
    }
    return std::string();
}

 std::string idResourceManager::getDeclWeaponReticleName(idDeclWeaponReticle* idDeclWeaponReticlePtr) {
    idResource* idResourceObj = (idResource*)idDeclWeaponReticlePtr;
    if (MemHelper::isBadReadPtr(idResourceObj)) {
        logErr("getDeclWeaponReticleName: bad ptr for idResourceObj: %p returning empty str", idResourceObj);
    }
    else if (MemHelper::isBadReadPtr(&idResourceObj->name) || MemHelper::isBadReadPtr(&idResourceObj->name.str)) {
        logErr("getDeclWeaponReticleName:: bad ptr found for ->name or ->name.str derivedObjPtr addr: %p returning empty str", idResourceObj);
    }
    else {
        return std::string(idResourceObj->name.str);
    }
    return std::string();
}

 std::string idResourceManager::getDeclHudElementName(idDeclHUDElement* idDeclHUDElementPtr) {
    idResource* idResourceObj = (idResource*)idDeclHUDElementPtr;
    if (MemHelper::isBadReadPtr(idResourceObj)) {
        logErr("getDeclHudElementName: bad ptr for idResourceObj: %p returning empty str", idResourceObj);
    }
    else if (MemHelper::isBadReadPtr(&idResourceObj->name) || MemHelper::isBadReadPtr(&idResourceObj->name.str)) {
        logErr("getDeclHudElementName:: bad ptr found for ->name or ->name.str derivedObjPtr addr: %p returning empty str", idResourceObj);
    }
    else {
        return std::string(idResourceObj->name.str);
    }
    return std::string();
}

 std::string idResourceManager::getIdMaterial2Name(idMaterial2* matr) {
    idResource* idResourceObj = (idResource*)matr;
    if (MemHelper::isBadReadPtr(idResourceObj)) {
        logErr("getIdMaterial2Name: bad ptr for idResourceObj: %p returning empty str", idResourceObj);
    }
    else if (MemHelper::isBadReadPtr(&idResourceObj->name) || MemHelper::isBadReadPtr(&idResourceObj->name.str)) {
        logErr("getIdMaterial2Name:: bad ptr found for ->name or ->name.str derivedObjPtr addr: %p returning empty str", idResourceObj);
    }
    else {
        return std::string(idResourceObj->name.str);
    }
    return std::string();
}

 std::string idResourceManager::getidDeclInventoryName(idDeclInventory* decl) {
    idResource* idResourceObj = (idResource*)decl;
    if (MemHelper::isBadReadPtr(idResourceObj)) {
        logErr("getidDeclInventoryName: bad ptr for idResourceObj: %p returning empty str", idResourceObj);
    }
    else if (MemHelper::isBadReadPtr(&idResourceObj->name) || MemHelper::isBadReadPtr(&idResourceObj->name.str)) {
        logErr("getidDeclInventoryName:: bad ptr found for ->name or ->name.str derivedObjPtr addr: %p returning empty str", idResourceObj);
    }
    else {

        return std::string(idResourceObj->name.str);
    }
    return std::string();
}
