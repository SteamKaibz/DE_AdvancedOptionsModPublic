//#pragma once
//#include "../DE/MemHelper.h"
//#include "../DE/ObjectLocator.h"
//
//
//
//
////! check libreoffice notes from 21/9/23 for more context
//class idPlayerWhichHasWrongOffsetsInCEButNotHere_t
//{
//public:
//    char pad_0000[88]; //0x0000
//    char NameStrPtr[8]; //0x0058
//    char pad_0060[13688]; //0x0060
//    void* InventoryStructPtr; //0x35D8
//    int32_t InventoryItemsCount; //0x35E0
//    int32_t InventoryItemsMaxCount; //0x35E4
//    char pad_35E8[13848]; //0x35E8
//    int32_t IsWeaponMod; //0x6C00
//    char pad_6C04[836]; //0x6C04
//    int32_t EquippedGrenadeType; //0x6F48
//    char pad_6F4C[68]; //0x6F4C
//    int32_t FragNadeCount; //0x6F90
//    char pad_6F94[36]; //0x6F94
//    int32_t IceNadeCount; //0x6FB8
//    char pad_6FBC[36]; //0x6FBC
//    int32_t IsFlameBelchAvailable; //0x6FE0
//    char pad_6FE4[340]; //0x6FE4
//    int32_t idSpawnId_spawnId; //0x7138
//    int32_t idSpawnId_serializedSpawnId; //0x713C
//    char pad_7140[24]; //0x7140
//    int32_t pendingQuickWeaponSlot; //0x7158
//    int32_t changeWeaponInstantly; //0x715C
//    int32_t lastWeaponSlot; //0x7160
//    char pad_7164[4]; //0x7164
//    int32_t idSpawnId_prevWeapon; //0x7168
//    int32_t idSpawnId_prevWeaponSerialized; //0x716C
//    void* idWeaponPtr_PrevWeapon; //0x7170
//    void* idManagedClass_Next; //0x7178
//    void* idManagedClassPtr_Prev; //0x7180
//    void* idDeclWeaponPtr_CurrentDeclWeaponIfNotDemon; //0x7188
//    char pad_7190[360]; //0x7190
//    int16_t N00000EAE; //0x72F8
//    int32_t cycleWeaponWait; //0x72FA
//    char pad_72FE[274]; //0x72FE
//    int64_t WantZoom; //0x7410
//    char pad_7418[4232]; //0x7418
//    int32_t N000010E3; //0x84A0
//    int8_t N00009CBA; //0x84A4
//    int8_t hideReticle; //0x84A5
//    int8_t hideHudForCinematic; //0x84A6
//    int8_t bringUpObjectivesPushed; //0x84A7
//    char pad_84A8[122984]; //0x84A8
//    float BloodPunch; //0x26510
//    char pad_26514[68892]; //0x26514
//    float MaxHealth; //0x37230
//    char pad_37234[20]; //0x37234
//    float N00006E9F; //0x37248
//    char pad_3724C[4]; //0x3724C
//    float unknown; //0x37250
//    char pad_37254[4]; //0x37254
//    float N00006EA1; //0x37258
//    float Health; //0x3725C
//    char pad_37260[160]; //0x37260
//    float MaxArmorMb; //0x37300
//    char pad_37304[4]; //0x37304
//    float LowArmorValMb; //0x37308
//    float Armor; //0x3730C
//    char pad_37310[65552]; //0x37310
//    idHUD_WeaponInfo* idHUD_WeaponInfoPtr; //? 0x47320 will have to update this next reclass
//    char pad_47328[8]; //0x47328
//    idHUD_Reticle* idHUD_ReticlePtr; //? 0x47330  0x47320 will have to update this next reclass
//    char pad_47338[896]; //0x47338
//    int32_t N00008F2F; //0x476B8
//    int8_t isInPauseMenu; //0x476BC
//    int8_t inScope; //0x476BD
//    int8_t prevShowMenuVisibilityMask; //0x476BE
//    int8_t requestAntialiasingFlush; //0x476BF
//    char pad_476C0[7448]; //0x476C0
//    int32_t N000092D3; //0x493D8
//    int32_t IsDemonInt; //0x493DC
//    char pad_493E0[20048]; //0x493E0
//}; //Size: 0x4E230
//
//
//static void debug_printWeaponCoolDownValOfDotReticle() {
//    logInfo("debug_printWeaponCoolDownValOfDotReticle called ");
//    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
//    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
//        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
//        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot) {
//
//            idHUDEvent_ReticleDataUpdate_idReticleData_t* reticleDataPtr = (idHUDEvent_ReticleDataUpdate_idReticleData_t*)&idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData;
//
//
//            //! the cooldown will always be 0 whether the meathook is recharging or not but the chargeCooldown will be 1.0 when the meathook is ready to be used.
//            logInfo("debug_printWeaponCoolDownValOfDotReticle: chargeCooldown: %.2f  cooldown: %.2f", reticleDataPtr->chargeCooldown, reticleDataPtr->cooldown);
//
//           /* logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idSWFWidget_Hud_ReticlePtr_Dot address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot);
//
//            logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData);*/
//
//        }
//
//    }
//}
//
//
//static void debug_printidSWFWidget_Hud_ReticlePtr_DotAddr() {
//    logInfo("debug_printidSWFWidget_Hud_ReticlePtr_DotAddr called");
//    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
//    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
//        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
//        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot) {
//            logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idSWFWidget_Hud_ReticlePtr_Dot address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot);
//            
//            logInfo("printidSWFWidget_Hud_ReticlePtr_DotAddr: idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->idHUDEvent_ReticleDataUpdate_idReticleData_t_currentData);
//
//        }
//        
//    }
//}
//
//static void debug_resetDotReticleColotToDefault() {
//    logInfo("debug_resetDotReticleColotToDefault called ");
//
//    //! value of namedColorId by default is: 4294967295
//    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
//    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
//        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
//        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite) {
//
//            idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId = SWF_NAMED_COLOR_WHITE;
//
//            //! this doesn't reset the color to white:
//           /* idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId = -1;*/
//
//            //! this will not work either to restore white color to dot:
//            //idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId = 4294967295;
//        }
//    }
//}
//
//static void debug_printDotReticleColor_namedColorId_Test() {
//    logInfo("debug_printDotReticleColor_namedColorId_Test called");
//    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
//    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
//        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
//        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite) {
//            int namedColorId = idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId;
//            logInfo("printDotReticleColor_namedColorId_Test: namedColorId address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId);
//            //! this prints: 2147483647
//            logInfo("printDotReticleColor_namedColorId_Test INT_MAX: %d\n", INT_MAX);
//            //! this prints: -1
//            logInfo("printDotReticleColor_namedColorId_Test 4294967295: %d\n", 4294967295);
//            //! this prints: -1
//            logInfo("printDotReticleColor_namedColorId_Test: namedColorId val: %d", namedColorId);
//
//            //! this is true when value is 4294967295 is memory:
//            if (namedColorId == -1) {
//                logInfo("printDotReticleColor_namedColorId_Test: yes namedColorId == -1", namedColorId);
//            }
//            else {
//                logInfo("printDotReticleColor_namedColorId_Test: NO. namedColorId is not == -1", namedColorId);
//            }
//        }
//    }
//}
//
////! reapplySwfColorsCmd must be called after this to reflect on the hud
//static void debug_changeDotReticleColorTest() {
//    static bool isToggle = false;
//    logInfo("debug_changeDotReticleColorTest called");
//    __int64 idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
//    if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
//        idPlayer_t* idPlayerPtr = (idPlayer_t*)idPlayerAddr;
//        if (idPlayerPtr->idHUD_ReticlePtr && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot && idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite) {
//            int namedColorId = idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId;
//            printf("changeDotReticleColorTest INT_MAX: %d\n", INT_MAX);
//            logInfo("changeDotReticleColorTest: namedColorId val: %d", namedColorId);
//            /* logInfo("changeDotReticleColorTest: idHUD_ReticlePtr address: %p", &idPlayerPtr->idHUD_ReticlePtr);
//             logInfo("changeDotReticleColorTest: idSWFWidget_Hud_ReticlePtr_Dot address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot);
//             logInfo("changeDotReticleColorTest: reticleSprite address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite);
//             logInfo("changeDotReticleColorTest: namedColorId address: %p", &idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId);*/
//
//
//            int namedColorIdNew = 0;
//            if (isToggle) {
//                namedColorIdNew = 247;
//            }
//            else {
//                namedColorIdNew = 95;
//            }
//            isToggle = !isToggle;
//
//            logInfo("changeDotReticleColorTest: changing namedColorId val to: %d", namedColorIdNew);
//            idPlayerPtr->idHUD_ReticlePtr->idSWFWidget_Hud_ReticlePtr_Dot->reticleSprite->namedColorId = namedColorIdNew;
//
//        }
//    }
//}
