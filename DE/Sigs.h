#pragma once

//! Signatures of Ida functions that can be used with pattern scanning:

 //? this pattern with no space will not work and find wrong results, good to know and remember...
    //static const char consoleUnlockCEScriptSig[] = "4C8B0EBA01000000488BCE448BF041FF51??8D";

static const char idGameLocalSig[] = "48 8B 0D ?? ?? ?? ?? 48 85 C9 74 0E 48 8B 01 FF 90 ?? ?? ?? ?? 0F B6 D0";

static const char getIdPlayerFuncSig[] = "48 8B C1 83 FA 0B";

static const char SoundLangSmthSig[] = "40 55 53 56 57 41 54 41 56 41 57 48 8D 6C 24 A0 48 81 EC 60 01 00 00 48 8B 05";
static const char idPlayerProcessInputSig[] = "40 55 53 56 48 8D 6C 24 90 48 81 EC 70 01 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 48";
static const char idPLayerSelectWeaponForSelectionGroupSig[] = "89 54 24 10 55 41 54 41 56 48 83 EC 60";
static const char isKeyPressedSig[] = "33 C0 44 8B C0 38 81 A1 00 00 00 75 07 4C 8B 81 A8 00 00 00 4C 85 C2 74 11";
static const char idGameSystemLocalMinimalGameCleanupSig[] = "48 89 5C 24 20 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 A0 58 FB FF";
static const char idMenu_UpdateSig[] = "40 55 56 41 56 48 8B EC 48 83 EC 50 4C 8B F2";
static const char pBindsStrSetSig[] = "48 89 5C 24 18 48 89 74 24 20 41 56 48 83 EC 50 0F B6 02";
static const char setActiveReticleSig[] = "41 54 41 55 41 57 48 81 EC D0 02 00 00 48 8B 05";
static const char idBroadcastManager_ReleaseBroadcastEventSig[] = "48 89 5C 24 18 48 89 6C 24 20 57 48 83 EC 20 48 8B 01 49 8B E8 0F B7 DA";
static const char convertIdDeclUIColorToidColorTargetSig[] = "41 81 F8 0C 01 00 00";

static const char setSpriteInstanceSig[] = "48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 8B F2 48 8B F9";
static const char showPerfMetricsSmthSig[] = "40 55 53 56 48 8D 6C 24 B9 48 81 EC B0 00 00 00 48 8B 01";

//! this will fail once patched with DE Injector
static const char consoleUnlockCEScriptWithSpacesSig[] = "4C 8B 0E BA 01 00 00 00 48 8B CE 44 8B F0 41 FF 51 ?? 8D";

//! scanning for the instruction after the unlock console to hopefully be more consistent
static const char consoleUnlockAltSig[] = "48 8B CE 44 8B F0 41 FF 51";

//! doesn't work:
//static const char consoleBindUnlockCEScriptWithSpacesSig[] = "4C 8B 0F 4? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 41 FF 51 ?? 4C ?? ?? ??";
//"4C8B0F4?????????????????????41FF51??4C??????"


static const char idInternalCVar_SetSig[] = "48 89 5C 24 08 57 48 83 EC 20 48 8B FA 48 8B D9 45 84 C0 75 7F";

////! i'm really not sure about this one but i struggled too much to find the language in the code...(47 bytes)
//static const char languageStaticAddrSig[] = "80 1D 51 EC F7 7F 00 00 48 02 C3 EE F7 7F 00 00 0E 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00";

static const char idLibPrintfSig[] = "48 89 4C 24 08 48 89 54 24 10 4C 89 44 24 18 4C 89 4C 24 20 48 83 EC 28 BA 01 00 00 00";

static const char idCmdSystemLocalExecuteCommandTextSig[] = "40 53 B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 2B E0 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 84 24 ?? ?? ?? ?? 48 8B D9 48 8D 4C 24 20 E8 ?? ?? ?? ?? 48 8B 03";

static const char idCmdSystemSmth_461060_Sig[] = "40 53 56 57 41 54 41 55 41 57 B8";

static const char reapplySwfColorsSig[] = "40 53 48 83 EC 20 8B 15 ?? ?? ?? ?? 33 DB";

static const char GetInventoryItemSig[] = "48 83 EC 28 85 D2 78 4F";

static const char GetFovTargetValSig[] = "48 83 EC 38 48 83 B9 58 01 00 00 00";

static const char findCvarSystemSig[] = "48 8B 0D ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? C7 44 24 34 00 00 80 3F";

static const char findCmdSystemSig[] = "48 8B 0D ?? ?? ?? ?? 48 8B 01 FF 50 ?? 85 C0 74 22";

static const char findSysLangSig[] = "48 8B 05 ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? 33 DB";

static const char findIdStringBigListSig[] = "48 8B 8C 3E ?? ?? ?? ?? 48 85 C9 74 0C";

static const char findidGameSystemLocalSig[] = "48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8D 4D 68 E8 ?? ?? ?? ?? 48 8D 15";

static const char idResourceListForClassNameSig[] = "48 89 5C 24 08 57 48 83 EC 20 48 8B 1D ?? ?? ?? ?? 48 8B F9 48 85 DB 74 24";

static const char getResourceFpSig[] = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 48 63 EA 4C 8B F1";

static const char maxSwfNamedColorsSig[] = "81 FA 0D 01 00 00";

//! this should help when using xenos as code will be modified and would make the scan fail so will implement a is patch needed check
static const char maxSwfNamedColorsV2Sig[] = "0F 87 F7 00 00 00 E8";

static const char GetidPlayerIntMidFuncSig[] = "48 63 CA 48 8B 8C C8 ?? ?? ?? ?? E9";

static const char GetTypeInfoToolsSig[] = "48 8B 0D ?? ?? ?? ?? 4C 8D 0D ?? ?? ?? ?? 41 0F B7 5C 24 06";

static const char FindClassInfoFuncPtrSig[] = "48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 4C 89 74 24 20 41 57 48 83 EC 20 4C 8B F2";
static const char FindEnumInfoFuncPtrSig[] = "48 89 5C 24 20 41 56 48 83 EC 20 48 8B D9 33 C0";

static const char BuildInformationStrSig[] = "48 8B 05 ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? 4C 8B 00 E9 36 01 00 00";

static const char SpriteInstanceSetScaleFuncSig[] = "40 53 48 83 EC 30 0F 29 74 24 20 48 8B D9 0F 28 F2";

static const char SpriteInstanceUpdateColorFuncSig[] = "48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 8B F2 48 8B F9";

static const char initRenderModelGuiMbFuncSig[] = "66 0F 6F 05 ?? ?? ?? ?? 48 8D 41 70";

static const char idHud_Debug_Print_SmthFuncSig[] = "48 89 5C 24 18 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 60 B8 FF FF";

static const char SetFontAndPrintStringMBFuncSig[] = "48 89 5C 24 08 48 89 6C 24 10 56 48 83 EC 60";

//static const char idRenderModelGui_DrawStringFuncSig[] = "F3 0F 11 54 24 18 56 41 56 41 57 48 81 EC 20 01 00 00 4C 8B BC 24 60 01 00 00 4C 8B F1 0F 29 BC 24 F0 00 00 00 49 8B CF 44 0F 29 7C 24 70 49 8B F1 0F 28 FA 44 0F 28 F9 E8 ?? ?? ?? ?? 41 89 86 D0 04 00 00";


//? this is where and when i realized that PySigMaker is much better than SigMakerEx at creating good sigs, so if a previous sig fails in the future just use PySigMaker

//static const char monoSpaceFontAddrSig[] = "48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 85 C0 0F 84 84 01 00 00";
static const char monoSpaceFontAddrSig[] = "48 8B 0D ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 80 BF";

//static const char fontSetInSetUpMonoSpaceFontSig[] = "48 8B B8 F8 00 00 00 48 8B CF";
static const char fontSetInSetUpMonoSpaceFontSig[] = "48 8B B8 ? ? ? ? 48 8B CF E8 ? ? ? ? 48 8B CF 48 8B D8";



static const char fontSetInDrawStringSig[] = "41 89 86 ? ? ? ? B8 ? ? ? ? E9";

//static const char fontSetInConsoleHistorySig[] = "48 8B B0 F8 00 00 00";
static const char fontSetInConsoleHistorySig[] = "48 8B B0 ? ? ? ? 48 8B CE E8 ? ? ? ? 3B 05";


static const char idDeclInfoTemplate_idMaterial2Sig[] = "48 8D 05 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 81 ? ? ? ? 4C 8B C1";

static const char idDeclInfo_FindWithInheritanceFuncSig[] = "40 55 56 57 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 89 44 24";

static const char idRenderModelGui_DrawStretchPic_498A10_FuncSig[] = "48 8B C4 48 81 EC ? ? ? ? F3 0F 10 AC 24 ? ? ? ? 4C 8D 4C 24 ? 0F 29 70 E8 4C 8D 44 24 ? F3 0F 10 B4 24 ? ? ? ? 48 8D 54 24 ? F3 0F 11 58";

static const char idRenderModelGui_DrawString_623530FuncSig[] = "F3 0F 11 54 24 ? 56 41 56 41 57 48 81 EC ? ? ? ? 4C 8B BC 24 ? ? ? ? 4C 8B F1 0F 29 BC 24 ? ? ? ? 49 8B CF 44 0F 29 7C 24 ? 49 8B F1 0F 28 FA 44 0F 28 F9 E8 ? ? ? ? 41 89 86";

static const char printOutlinedStringMBSig[] = "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 56 41 57 48 81 EC ? ? ? ? F3 0F 10 05 ? ? ? ? 4C 8B F9";

static const char smallCharWidthSig[] = "F3 0F 11 05 ? ? ? ? 48 8B B8";

static const char smallCharHeightSig[] = "F3 0F 11 0D ? ? ? ? 0F B6 43 04";

static const char useScaleSig[] = "F3 0F 11 15 ? ? ? ? E8 ? ? ? ? 48 8B CF";

static const char getGlyphDataFuncSig[] = "89 54 24 10 53 48 83 EC 20 48 8B D9 48 8B 49 58";

//static const char globalDeclSig[] = "48 8B 0D ? ? ? ? 44 8D 40 01 45 33 C9";
static const char globalDeclSig[] = "48 8B 05 ? ? ? ? 48 85 C0 75 70";

static const char getScreenWidthLocatorSig[] = "89 05 ? ? ? ? 8B 05 ? ? ? ? 89 05 ? ? ? ? 48 83 C4 28 C3 89 05";

static const char getScreenHeightLocatorSig[] = "89 05 ? ? ? ? 48 83 C4 28 C3 89 05";

static const char idLoadScreenInfoSig[] = "48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8D 4D D0 E8";

static const char idMaterial2_WhiteSig[] = "48 8B 05 ? ? ? ? F3 0F 11 74 24 ? 48 89 44 24";

static const char dashEffectToggleSig[] = "0F 84 ? ? ? ? 48 8B CE E8 ? ? ? ? 84 C0 75 58";

static const char broadcastHudEvent2ArgsSig[] = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 41 0F B7 F0";

static const char isWorldMenuAtIndexActiveFaddrSig[] = "48 89 5C 24 ? 57 48 83 EC 20 48 63 DA 48 8B F9 8B D3 E8 ? ? ? ? 48 85 C0 74 12";
static const char skipCustomAnimFpSig[] = "44 89 4C 24 ? 44 89 44 24 ? 48 89 54 24 ? 53 55";

static const char idInventoryCollectionSmthFpSig[] = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 33 FF 48 8B EA 4C 8B F1 39 79 08 7E 5F";

static const char idHUDMenu_CurrencyConfirmationSmthFpSig[] = "4C 8B DC 55 49 8D AB ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 49 89 5B 18 49 89 73 F0 48 8B F1";

static const char p_StartSyncFpSig[] = "40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? B8 ? ? ? ? E8 ? ? ? ? 48 2B E0 44 0F 29 8C 24";

static const char idPlayerFovLerpFpSig[] = "40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B D9 83 78 08 5A";

static const char syncEndFpSig[] = "48 8B C4 57 41 55 41 56";

static const char RenderSpriteFpSig[] = "40 55 56 57 41 55 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 89 4D 00";

static const char UseEquipmentItemFpSig[] = "40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 0F 48 83 B9";

static const char SwitchEquipmentItemFpSig[] = "85 D2 0F 88 ? ? ? ? 55";

static const char consoleLogFpSig[] = "48 89 4C 24 ? 48 89 54 24 ? 4C 89 44 24 ? 4C 89 4C 24 ? 48 83 EC 28 BA ? ? ? ? 4C 8D 4C 24 ? 4C 8B C1 8B CA";











//! fails:
//static const char getTypeInfoToolsTestSig[] = "48 8D 15 64 75 72 61 74 69 6F 6E 5F 74 48 8B 0D";
//! fails:
//static const char getTypeInfoToolsTestSig[] = "48 8D 15 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 48 8B 0D";




/*

material White
result: matches @ 0x4CA7F9, sig direct: 48 8B 05 ? ? ? ? F3 0F 11 74 24 ? 48 89 44 24

idLoadScreenThread_2AF89A0:
result: matches @ 0xAC9A2A, sig direct: 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8D 4D D0 E8

screenHeight
result: matches @ 0x9A65C5, sig direct: 89 05 ? ? ? ? 48 83 C4 28 C3 89 05

screenWidht 
result: matches @ 0x9A65B9, sig direct: 89 05 ? ? ? ? 8B 05 ? ? ? ? 89 05 ? ? ? ? 48 83 C4 28 C3 89 05


idDeclGlobalShell
result: matches @ 0x4D0FA6, sig direct: 48 8B 05 ? ? ? ? 48 85 C0 75 70

idFont8GetGlyph_4CC330(__int64 a1, __int64 a2):
result: matches @ 0x4CC330, sig direct: 89 54 24 10 53 48 83 EC 20 48 8B D9 48 8B 49 58

useScale_MB_3959A94:
result: matches @ 0x624467, sig direct: F3 0F 11 15 ? ? ? ? E8 ? ? ? ? 48 8B CF

smallCharHeight_551BCF4:
result: matches @ 0x624450, sig direct: F3 0F 11 0D ? ? ? ? 0F B6 43 04

smallCharWidth_551BCF0:
result: matches @ 0x624406, sig direct: F3 0F 11 05 ? ? ? ? 48 8B B8

printOutlinedStringMB_4CAD00
result: matches @ 0x4CAD00, sig direct: 48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 56 41 57 48 81 EC ? ? ? ? F3 0F 10 05 ? ? ? ? 4C 8B F9

idRenderModelGui::DrawString_623530
matches @ 0x623530, sig direct: F3 0F 11 54 24 ? 56 41 56 41 57 48 81 EC ? ? ? ? 4C 8B BC 24 ? ? ? ? 4C 8B F1 0F 29 BC 24 ? ? ? ? 49 8B CF 44 0F 29 7C 24 ? 49 8B F1 0F 28 FA 44 0F 28 F9 E8 ? ? ? ? 41 89 86

idRenderModelGui::DrawStretchPic_498A10 post denuvo
PySigMaker:
result: matches @ 0x498A10, sig direct: 48 8B C4 48 81 EC ? ? ? ? F3 0F 10 AC 24 ? ? ? ? 4C 8D 4C 24 ? 0F 29 70 E8 4C 8D 44 24 ? F3 0F 10 B4 24 ? ? ? ? 48 8D 54 24 ? F3 0F 11 58


idDeclInfo::FindWithInheritance_46FEF0(idResourceList *a1, const char *a2, unsigned int a3)
PySigMaker:
result: matches @ 0x46FEF0, sig direct: 40 55 56 57 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 44 89 44 24


dDeclInfoTemplate_idMaterial2_5B56560
PySigMaker:
result: matches @ 0x8EA560, sig direct: 48 8D 05 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 81 ? ? ? ? 4C 8B C1


monospaceFont addr post denuvo
SigMakerEx: Finding signature for 000000004D00AA.
Address SIG: 0x000000004D00AA, 21 bytes 8, wildcards.
This is the one found by pySigMaker which seems better to me as it will find it even if we change the offset of the font:
IDA: "48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 85 C0 0F 84 84 01 00 00"
PySigMaker:
result: matches @ 0x4D00AA, sig direct: 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 80 BF


(monospaceFont + 0xF8) in SetupMonospaceFont
SigMakerEx: Finding signature for 0000000062440E.
Address SIG: 0x0000000062440E, 10 bytes 0, wildcards.
IDA: "48 8B B8 F8 00 00 00 48 8B CF"
PySigMaker:
result: matches @ 0x62440E, sig direct: 48 8B B8 ? ? ? ? 48 8B CF E8 ? ? ? ? 48 8B CF 48 8B D8


monospaceFont + 0xF8 in idRenderModelGui_DrawString
SigMakerEx: Finding signature for 0000000062366C.
Address SIG: 0x0000000062366C, 452 bytes 76, wildcards.
IDA: "48 8B A8 F8 00 00 00 48 8B CD E8 ?? ?? ?? ?? 3B 05 ?? ?? ?? ?? 75 10 48 8B CD E8 ?? ?? ?? ?? 3B 05 ?? ?? ?? ?? 74 0D F3 0F 10 05 ?? ?? ?? ?? E8 ?? ?? ?? ?? F3 44 0F 10 2D ?? ?? ?? ?? 8B D3 48 8B CD F3 44 0F 58 EF E8 ?? ?? ?? ?? F3 44 0F 10 0D ?? ?? ?? ?? 4C 8B C0 41 0F 28 F9 F3 44 0F 59 0D ?? ?? ?? ?? 0F B7 48 08 0F B7 50 06 0F B6 38 0F B6 58 01 F3 0F 59 FE 8D 04 3A 66 44 0F 6E D9 66 44 0F 6E D0 8D 04 19 66 44 0F 6E C0 48 8B CD 41 0F BE 40 02 66 44 0F 6E E2 45 0F 5B E4 66 0F 6E F0 41 0F B6 40 04 F3 45 0F 5C E6 45 0F 5B DB F3 44 0F 59 25 ?? ?? ?? ?? 66 0F 6E C0 F3 45 0F 5C DE 41 0F BE 40 03 0F 5B C0 F3 44 0F 59 1D ?? ?? ?? ?? F3 44 0F 5C C8 66 0F 6E C0 45 0F 5B D2 45 0F 5B C0 0F 5B C0 F3 45 0F 59 CE F3 45 0F 58 D6 0F 5B F6 F3 44 0F 59 15 ?? ?? ?? ?? F3 44 0F 58 C8 F3 45 0F 58 C6 F3 0F 59 F7 F3 44 0F 59 CF F3 44 0F 59 05 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 89 44 24 50 F3 44 0F 5C EE F3 44 0F 11 44 24 48 F3 45 0F 58 CF F3 44 0F 11 54 24 40 49 8B CE F3 44 0F 11 5C 24 38 66 0F 6E DB 0F 5B DB 66 0F 6E C7 41 0F 28 D5 F3 0F 58 1D ?? ?? ?? ?? 0F 5B C0 F3 44 0F 11 64 24 30 41 0F 28 C9 F3 0F 58 05 ?? ?? ?? ?? F3 0F 59 DF F3 0F 11 5C 24 28 0F 57 DB F3 0F 59 C7 F3 0F 11 44 24 20 E8 ?? ?? ?? ?? F3 0F 10 05 ?? ?? ?? ?? B8 01 00 00 00 F3 0F 10 B4 24 70 01 00 00 F3 0F 10 BC 24 50 01 00 00 F3 0F 59 C6 F3 44 0F 58 F8 48 03 F0 0F B6 16 84 D2 0F 85 D1 FD FF FF"
PySigMaker: but will have to add 30 bytes to get to the F8 value
result: matches @ 0x623651, sig direct: 41 89 86 ? ? ? ? B8 ? ? ? ? E9

monospaceFont + 0xF8 in Console History related func
SigMakerEx: Finding signature for 000000006222C9.
Address SIG: 0x000000006222C9, 7 bytes 0, wildcards.
IDA: "48 8B B0 F8 00 00 00"
pySigMaker:
result: matches @ 0x6222C9, sig direct: 48 8B B0 ? ? ? ? 48 8B CE E8 ? ? ? ? 3B 05



idRenderModelGui__DrawString_623530 post Denuvo
SigMakerEx: Finding signature for 00000000623530.
Address SIG: 0x00000000623530, 68 bytes 4, wildcards.
IDA: "F3 0F 11 54 24 18 56 41 56 41 57 48 81 EC 20 01 00 00 4C 8B BC 24 60 01 00 00 4C 8B F1 0F 29 BC 24 F0 00 00 00 49 8B CF 44 0F 29 7C 24 70 49 8B F1 0F 28 FA 44 0F 28 F9 E8 ?? ?? ?? ?? 41 89 86 D0 04 00 00"

SetFontAndPrintStringMB__15A43B0
SigMakerEx: Finding signature for 000000015A43B0. 
Address SIG: 0x000000015A43B0, 15 bytes 0, wildcards.
IDA: "48 89 5C 24 08 48 89 6C 24 10 56 48 83 EC 60"


double __fastcall idHud_Debug_Print_Smth_1558D50 post denuvo
SigMakerEx: Finding signature for 00000001558D50.
Address SIG: 0x00000001558D50, 24 bytes 0, wildcards.
IDA: "48 89 5C 24 18 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 60 B8 FF FF"

func that seem to init renderModelGui called in idHud_Debug_Print_Smth_1558D50 post denuvo
SigMakerEx: Finding signature for 000000004CA590.
Address SIG: 0x000000004CA590, 12 bytes 4, wildcards.
IDA: "66 0F 6F 05 ?? ?? ?? ?? 48 8D 41 70"

spriteInstanceUpdateColor post denuvo
SigMakerEx: Finding signature for 0000000052F290.
Address SIG: 0x0000000052F290, 20 bytes 0, wildcards.
IDA: "48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 8B F2 48 8B F9"
"\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x48\x83\xEC\x30\x8B\xF2\x48\x8B\xF9", "xxxxxxxxxxxxxxxxxxxx"

FindEnumInfo  Post denuvo
SigMakerEx: Finding signature for 00000000411820.
Address SIG: 0x00000000411820, 16 bytes 0, wildcards.
IDA: "48 89 5C 24 20 41 56 48 83 EC 20 48 8B D9 33 C0"
"\x48\x89\x5C\x24\x20\x41\x56\x48\x83\xEC\x20\x48\x8B\xD9\x33\xC0", "xxxxxxxxxxxxxxxx"

 post Max Named Colors IDS Post Denuvo
SigMakerEx: Finding signature for 0000000052F2AA.
Address SIG: 0x0000000052F2AA, 7 bytes 0, wildcards.
IDA: "0F 87 F7 00 00 00 E8"
"\x0F\x87\xF7\x00\x00\x00\xE8", "xxxxxxx"

sprite scale update post denuvo
SigMakerEx: Finding signature for 0000000052F670.
Address SIG: 0x0000000052F670, 17 bytes 0, wildcards.
IDA: "40 53 48 83 EC 30 0F 29 74 24 20 48 8B D9 0F 28 F2"
"\x40\x53\x48\x83\xEC\x30\x0F\x29\x74\x24\x20\x48\x8B\xD9\x0F\x28\xF2", "xxxxxxxxxxxxxxxxx"

New Sig for console unrestrict, following instruction
SigMakerEx: Finding signature for 00000000494205.
Address SIG: 0x00000000494205, 9 bytes 0, wildcards.
IDA: "48 8B CE 44 8B F0 41 FF 51"
"\x48\x8B\xCE\x44\x8B\xF0\x41\xFF\x51", "xxxxxxxxx"

Build Info Name post denuvo
SigMakerEx: Finding signature for 0000000048A45D.
Address SIG: 0x0000000048A45D, 22 bytes 8, wildcards.
IDA: "48 8B 05 ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? 4C 8B 00 E9 36 01 00 00"
"\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x8D\x15\xCC\xCC\xCC\xCC\x4C\x8B\x00\xE9\x36\x01\x00\x00", "xxx????xxx????xxxxxxxx"

idTypeInfoTools__FindClassInfo_4104A0 post denuvo
SigMakerEx: Finding signature for 000000004104A0.
Address SIG: 0x000000004104A0, 29 bytes 0, wildcards.
IDA: "48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 4C 89 74 24 20 41 57 48 83 EC 20 4C 8B F2"
"\x48\x89\x5C\x24\x08\x48\x89\x74\x24\x10\x48\x89\x7C\x24\x18\x4C\x89\x74\x24\x20\x41\x57\x48\x83\xEC\x20\x4C\x8B\xF2", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

idTypeInfoTools post denuvo
SigMakerEx: Finding signature for 00000000B39265.
Address SIG: 0x00000000B39265, 20 bytes 8, wildcards.
IDA: "48 8B 0D ?? ?? ?? ?? 4C 8D 0D ?? ?? ?? ?? 41 0F B7 5C 24 06"
"\x48\x8B\x0D\xCC\xCC\xCC\xCC\x4C\x8D\x0D\xCC\xCC\xCC\xCC\x41\x0F\xB7\x5C\x24\x06", "xxx????xxx????xxxxxx"

Helper offset to find idPlayer
SigMakerEx: Finding signature for 00000000D1F588.
Address SIG: 0x00000000D1F588, 12 bytes 4, wildcards.
IDA: "48 63 CA 48 8B 8C C8 ?? ?? ?? ?? E9"
"\x48\x63\xCA\x48\x8B\x8C\xC8\xCC\xCC\xCC\xCC\xE9", "xxxxxxx????x"


Max Named Colors IDS Post Denuvo
SigMakerEx: Finding signature for 0000000052F2A4.
Address SIG: 0x0000000052F2A4, 6 bytes 0, wildcards.
IDA: "81 FA 0D 01 00 00"
"\x81\xFA\x0D\x01\x00\x00", "xxxxxx"

IdGameLocal::GetPlayer(int player)
SigMakerEx: Finding signature for 00000000D1F580.
Address SIG: 0x00000000D1F580, 6 bytes 0, wildcards.
IDA: "48 8B C1 83 FA 0B"
"\x48\x8B\xC1\x83\xFA\x0B", "xxxxxx"

Gamelocal post denuvo SigMakerEx: Finding signature for 00000000B695D0.
Address SIG: 0x00000000B695D0, 24 bytes 8, wildcards.
IDA: "48 8B 0D ?? ?? ?? ?? 48 85 C9 74 0E 48 8B 01 FF 90 ?? ?? ?? ?? 0F B6 D0"
"\x48\x8B\x0D\xCC\xCC\xCC\xCC\x48\x85\xC9\x74\x0E\x48\x8B\x01\xFF\x90\xCC\xCC\xCC\xCC\x0F\xB6\xD0", "xxx????xxxxxxxxxx????xxx"

idResourceForClassname  post denuvo
SigMakerEx: Finding signature for 00000000A50B20.
Address SIG: 0x00000000A50B20, 25 bytes 4, wildcards.
IDA: "48 89 5C 24 08 57 48 83 EC 20 48 8B 1D ?? ?? ?? ?? 48 8B F9 48 85 DB 74 24"
"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x48\x8B\x1D\xCC\xCC\xCC\xCC\x48\x8B\xF9\x48\x85\xDB\x74\x24", "xxxxxxxxxxxxx????xxxxxxxx"


idGameSystemLocal location post denuvo
SigMakerEx: Finding signature for 00000000AC994B.
Address SIG: 0x00000000AC994B, 24 bytes 12, wildcards.
IDA: "48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8D 4D 68 E8 ?? ?? ?? ?? 48 8D 15"
"\x48\x8D\x0D\xCC\xCC\xCC\xCC\xE8\xCC\xCC\xCC\xCC\x48\x8D\x4D\x68\xE8\xCC\xCC\xCC\xCC\x48\x8D\x15", "xxx????x????xxxxx????xxx"

hard coded idString list post denuvo
SigMakerEx: Finding signature for 000000017020D6.
Address SIG: 0x000000017020D6, 13 bytes 4, wildcards.
IDA: "48 8B 8C 3E ?? ?? ?? ?? 48 85 C9 74 0C"
"\x48\x8B\x8C\x3E\xCC\xCC\xCC\xCC\x48\x85\xC9\x74\x0C", "xxxx????xxxxx"

cmdSystem post denuvo
SigMakerEx: Finding signature for 00000000371D31.
Address SIG: 0x00000000371D31, 17 bytes 5, wildcards.
IDA: "48 8B 0D ?? ?? ?? ?? 48 8B 01 FF 50 ?? 85 C0 74 22"
"\x48\x8B\x0D\xCC\xCC\xCC\xCC\x48\x8B\x01\xFF\x50\xCC\x85\xC0\x74\x22", "xxx????xxxxx?xxxx"


syslang Post Denuvo
SigMakerEx: Finding signature for 000000009B0526.
Address SIG: 0x000000009B0526, 16 bytes 8, wildcards.
IDA: "48 8B 05 ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? 33 DB"
"\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x8D\x15\xCC\xCC\xCC\xCC\x33\xDB", "xxx????xxx????xx"


CvarSystem Post Denuvo
SigMakerEx: Finding signature for 00000000AD4D27.
Address SIG: 0x00000000AD4D27, 22 bytes 8, wildcards.
IDA: "48 8B 0D ?? ?? ?? ?? 48 8D 15 ?? ?? ?? ?? C7 44 24 34 00 00 80 3F"
"\x48\x8B\x0D\xCC\xCC\xCC\xCC\x48\x8D\x15\xCC\xCC\xCC\xCC\xC7\x44\x24\x34\x00\x00\x80\x3F", "xxx????xxx????xxxxxxxx"


SigMakerEx: Finding signature for 00000000544BB0.
Address SIG: 0x00000000544BB0, 31 bytes 0, wildcards.
IDA: "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 20 48 8D B9"
"\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x83\xEC\x20\x48\x8D\xB9", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

GetFovTargetValMb (post denuvo)
SigMakerEx: Finding signature for 00000001D2F860.
Address SIG: 0x00000001D2F860, 12 bytes 0, wildcards.
IDA: "48 83 EC 38 48 83 B9 58 01 00 00 00"
"\x48\x83\xEC\x38\x48\x83\xB9\x58\x01\x00\x00\x00", "xxxxxxxxxxxx"

idInventoryCollection::GetInventoryItem_1CFCA30 (post denuvo)
SigMakerEx: Finding signature for 00000001CFCA30.
Address SIG: 0x00000001CFCA30, 8 bytes 0, wildcards.
IDA: "48 83 EC 28 85 D2 78 4F"
"\x48\x83\xEC\x28\x85\xD2\x78\x4F", "xxxxxxxx"


reapplySwfColors_Mb_4F56D0 (denuvo inside) and 4F5210 post denuvo
SigMakerEx: Finding signature for 000000004F56D0.
Address SIG: 0x000000004F56D0, 14 bytes 4, wildcards.
IDA: "40 53 48 83 EC 20 8B 15 ?? ?? ?? ?? 33 DB"
"\x40\x53\x48\x83\xEC\x20\x8B\x15\xCC\xCC\xCC\xCC\x33\xDB", "xxxxxxxx????xx"

(Post denuvo func that contains cmdSystem in a1)
SigMakerEx: Finding signature for 00000000461060.
Address SIG: 0x00000000461060, 11 bytes 0, wildcards.
IDA: "40 53 56 57 41 54 41 55 41 57 B8"
"\x40\x53\x56\x57\x41\x54\x41\x55\x41\x57\xB8", "xxxxxxxxxxx"


_ZN16idCmdSystemLocal18ExecuteCommandTextEPKc
SigMakerEx: Finding signature for 000000004157E0.
Address SIG: 0x000000004157E0, 49 bytes 20, wildcards.
IDA: "40 53 B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 2B E0 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 84 24 ?? ?? ?? ?? 48 8B D9 48 8D 4C 24 20 E8 ?? ?? ?? ?? 48 8B 03"
"\x40\x53\xB8\xCC\xCC\xCC\xCC\xE8\xCC\xCC\xCC\xCC\x48\x2B\xE0\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x33\xC4\x48\x89\x84\x24\xCC\xCC\xCC\xCC\x48\x8B\xD9\x48\x8D\x4C\x24\x20\xE8\xCC\xCC\xCC\xCC\x48\x8B\x03", "xxx????x????xxxxxx????xxxxxxx????xxxxxxxxx????xxx"



SigMakerEx: Finding signature for 0000000035F240.
Address SIG: 0x0000000035F240, 29 bytes 0, wildcards.
IDA: "48 89 4C 24 08 48 89 54 24 10 4C 89 44 24 18 4C 89 4C 24 20 48 83 EC 28 BA 01 00 00 00"
"\x48\x89\x4C\x24\x08\x48\x89\x54\x24\x10\x4C\x89\x44\x24\x18\x4C\x89\x4C\x24\x20\x48\x83\xEC\x28\xBA\x01\x00\x00\x00", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"


SigMakerEx: Finding signature for 00000000371CD0.
Address SIG: 0x00000000371CD0, 21 bytes 0, wildcards.
IDA: "48 89 5C 24 08 57 48 83 EC 20 48 8B FA 48 8B D9 45 84 C0 75 7F"
"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x48\x8B\xFA\x48\x8B\xD9\x45\x84\xC0\x75\x7F", "xxxxxxxxxxxxxxxxxxxxx"


SigMakerEx: Finding signature for 00000000A8AE00.
Address SIG: 0x00000000A8AE00, 26 bytes 0, wildcards.
IDA: "40 55 53 56 57 41 54 41 56 41 57 48 8D 6C 24 A0 48 81 EC 60 01 00 00 48 8B 05"
"\x40\x55\x53\x56\x57\x41\x54\x41\x56\x41\x57\x48\x8D\x6C\x24\xA0\x48\x81\xEC\x60\x01\x00\x00\x48\x8B\x05", "xxxxxxxxxxxxxxxxxxxxxxxxxx"

sys_lang cvar func
SigMakerEx: Finding signature for 0000000017F460.
Address SIG: 0x0000000017F460, 13 bytes 4, wildcards.
IDA: "48 8D 0D ?? ?? ?? ?? 4C 89 44 24 20 E8"
"\x48\x8D\x0D\xCC\xCC\xCC\xCC\x4C\x89\x44\x24\x20\xE8", "xxx????xxxxxx"


console unlock:
SigMakerEx: Finding signature for 000000004946BD.
Address SIG: 0x000000004946BD, 14 bytes 0, wildcards.
IDA: "4C 8B 0E BA 01 00 00 00 48 8B CE 44 8B F0"
"\x4C\x8B\x0E\xBA\x01\x00\x00\x00\x48\x8B\xCE\x44\x8B\xF0", "xxxxxxxxxxxxxx"



idCmd:

SigMakerEx: Finding signature for 000000003721A0.
Address SIG: 0x000000003721A0, 21 bytes 0, wildcards.
IDA: "48 89 5C 24 08 57 48 83 EC 20 48 8B FA 48 8B D9 45 84 C0 75 7F"
"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x48\x8B\xFA\x48\x8B\xD9\x45\x84\xC0\x75\x7F", "xxxxxxxxxxxxxxxxxxxxx"

SigMakerEx: Finding signature for 000000004F56D0.
Address SIG: 0x000000004F56D0, 14 bytes 4, wildcards.
IDA: "40 53 48 83 EC 20 8B 15 ?? ?? ?? ?? 33 DB"
"\x40\x53\x48\x83\xEC\x20\x8B\x15\xCC\xCC\xCC\xCC\x33\xDB", "xxxxxxxx????xx"






*/