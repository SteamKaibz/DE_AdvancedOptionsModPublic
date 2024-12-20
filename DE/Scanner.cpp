#include "Scanner.h"





 bool Scanner::scanForAddrs() {

	 logInfo("scanForAddrs: Pattern Scans for %s Started...", Config::getCurrentModuleNameStrToLower().c_str());	

	//! TYPEINFO
	if (!TypeInfoManager::acquireTypeInfoTools(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("GetTypeInfoToolsSig", GetTypeInfoToolsSig)), 3, 7))) {
		logErr("scanForAddrs failed for GetTypeInfoToolsSig");
		return false;
	}

	if (!TypeInfoManager::acquirreFindClassInfoFuncPtr((uintptr_t)MemHelper::ModulePatternScan("FindClassInfoFuncPtrSig", FindClassInfoFuncPtrSig))) {
		logErr("scanForAddrs failed for FindClassInfoFuncPtrSig");
		return false;
	}

	if (!TypeInfoManager::acquirreFindEnumInfoFuncPtr((uintptr_t)MemHelper::ModulePatternScan("FindEnumInfoFuncPtrSig", FindEnumInfoFuncPtrSig))) {
		logErr("scanForAddrs failed for FindEnumInfoFuncPtrSig");
		return false;
	}


	//? getCvarSystemPtrAddr will call get_engine_t(), which itself will make sure we wait long enough for typeinfo tool to be initiallized.
	//! CVAR.
	if (!idCvarManager::acquireIdCVarSystemLocalPtr(TypeInfoManager::getCvarSystemPtrAddr())) {
		logErr("scanForAddrs failed for acquireIdCVarSystemLocalPtr");
		return false;
	}
	//? order is important here. Obviously.
	if (!idCvarManager::acquireFindInternalFuncPtr()) {
		logErr("scanForAddrs failed for acquireFindInternalFuncPtr");
		return false;
	}

		
	
	//? not using this, not safe enough, will use execute command instead
	/*if (!idCvarManager::acquireSetInternalFuncAddr((uintptr_t)MemHelper::ModulePatternScan("idInternalCVar_SetSig", idInternalCVar_SetSig))) {
		logErr("scanForAddrs failed for idInternalCVarSetSig");
		return false;
	}*/


	//? this is not technically a scan, but i'll put it here for now...Meaning it will stay here forever surely.
	if (!fastCvarManager::cacheCriticalCvars()) {
		logErr("scanForAddrs failed for cacheCriticalCvars");
		return false;
	}


	//! CMD
	if (!idCmd::acquireIdCmdSystemLocalPtr(TypeInfoManager::getCmdSystemPtrAddr())) {
		logErr("scanForAddrs failed for acquireIdCmdSystemLocalPtr");
		return false;
	}
	if (!idCmd::acquirreExecuteCommandTextFuncPtr()) { //? order is important here.
		logErr("scanForAddrs failed for acquirreExecuteCommandTextFuncPtr");
		return false;
	}


	if (!idGameSystemLocalManager::acquireIdGameSystemLocalAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("findidGameSystemLocalSig", findidGameSystemLocalSig)), 3, 7))) {
		logErr("scanForAddrs failed for findidGameSystemLocalSig");
		return false;
	}

	if (!idMapInstanceLocalManager::acquirreIdGameSystemLocalPtrAdrr(idGameSystemLocalManager::getIdGameSystemLocalAddr())) {
		logErr("scanForAddrs failed for acquirreIdGameSystemLocalPtrAdrr");
		return false;
	}


	char* idGlobalEncounterManagerInstructionAddr = (char*)(MemHelper::ModulePatternScan("idMapInstanceLocal_idGlobalEncounterManagerSig", idMapInstanceLocal_idGlobalEncounterManagerSig));
	idGlobalEncounterManagerInstructionAddr += 3;
	if (!idMapInstanceLocalManager::acquireIdGlobalEncounterManagerOffset((uintptr_t)idGlobalEncounterManagerInstructionAddr)) {
		logErr("scanForAddrs failed for idMapInstanceLocal_idGlobalEncounterManagerSig");
		return false;

	}	


	if (!idEventManager::acquireIdEventDefInterfaceLocal(TypeInfoManager::getIdEventDefInterface())) {
		logErr("scanForAddrs failed for acquireIdEventDefInterfaceLocal");
		return false;
	}


	if (!idHudEventManager::acquireBroadcastManager(TypeInfoManager::getIdBroadcastManager())) {
		logErr("scanForAddrs failed for acquireBroadcastManager");
		return false;
	}

	if (!idHudEventManager::acquireBroadcastHudEventFp((uintptr_t)MemHelper::ModulePatternScan("broadcastHudEvent2ArgsSig", broadcastHudEvent2ArgsSig))) {
		logErr("scanForAddrs failed for broadcastHudEvent2ArgsSig");
		return false;
	}

	//if (! winFocusManager::acquireWin32Vars(TypeInfoManager::getWin32VarsAddr())) {
	//	logErr("scanForAddrs failed for acquireWin32Vars");
	//	return false;
	//}



	//? We had to find another way to get idDeclGlobalShell this was just VERY inefficient
	/*qsdfif (!idDeclGlobalShellManager::acquireGlobalDeclAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("globalDeclSig", globalDeclSig)), 3, 7)))
	{
		logErr("scanForAddrs failed for globalDeclSig");
		return false;
	}*/


	//? getting this statically for now.
	/*qsdfqsfif (!idMapInstanceLocalManager::acquireIdPlayerOffsetInstructionAddr(((uintptr_t)MemHelper::ModulePatternScan("GetidPlayerIntMidFuncSig", GetidPlayerIntMidFuncSig) + 7))) {
		logErr("scanForAddrs failed for GetidPlayerIntMidFuncSig");
		return false;
	}*/

	if (!LoadingScreenManager::acquirreloadingScreenStructAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("idLoadScreenInfoSig", idLoadScreenInfoSig)), 3, 7))) {
		logErr("scanForAddrs failed for idLoadScreenInfoSig");
		return false;
	}

	/*if (!Patcher::patch("UnrestrictIdConsole", ((uintptr_t)MemHelper::PatternScan(doomEternalExeName.c_str(), consoleUnlockCEScriptWithSpacesSig) + 4), UnrestrictIdConsoleNewInstructionVec)) {
		anyScanFailed = true;
	}*/

	//? func above crashed the game since we installed DoomEternal Injector, trying this instead Update mod still crash, but might be related to something else
	/*if (!Patcher::patchIfNeeded("UnrestrictIdConsole", ((uintptr_t)MemHelper::PatternScan(doomEternalExeName.c_str(), consoleUnlockCEScriptWithSpacesSig) + 4), UnrestrictIdConsoleNewInstructionVec)) {
		anyScanFailed = true;
	}*/


	static const std::vector<unsigned char> UnrestrictIdConsoleNewInstructionVec = { 0x00 };
	static const std::vector<unsigned char> UnrestrictIdConsoleBindsNewInstructionVec = { 0x00 };

	if (!Patcher::patchIfNeeded("UnrestrictIdConsole", ((uintptr_t)MemHelper::ModulePatternScan("consoleUnlockAltSig", consoleUnlockAltSig) - 4), UnrestrictIdConsoleNewInstructionVec)) {
		logErr("scanForAddrs failed for consoleUnlockAltSig");
		return false;
	}


	//static const std::vector<unsigned char> RestrictIdConsoleNewInstructionVec = { 0x01 };
	static const std::vector<unsigned char> UnlockMaxNamedIdColorsPatchNewInstructionVec = { 0x02 };

	if (!Patcher::patchIfNeeded("UnlockMaxNamedIdColors", ((uintptr_t)MemHelper::ModulePatternScan("maxSwfNamedColorsV2Sig", maxSwfNamedColorsV2Sig) - 3), UnlockMaxNamedIdColorsPatchNewInstructionVec)) {
		logErr("scanForAddrs failed for UnlockMaxNamedIdColors");
		return false;
	}


	/*if (!Patcher::patch("UnlockMaxNamedIdColors", ((uintptr_t)MemHelper::PatternScan(doomEternalExeName.c_str(), maxSwfNamedColorsSig) + 3), UnlockMaxNamedIdColorsPatchNewInstructionVec)) {
		anyScanFailed = true;
	}*/
		

	if (!idRenderModelGuiManager::acquirreSmallCharWidhtAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("smallCharWidthSig", smallCharWidthSig)), 4, 8))) {
		logErr("scanForAddrs failed for smallCharWidthSig");
		return false;
	}

	if (!idRenderModelGuiManager::acquirreSmallCharHeightAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("smallCharHeightSig", smallCharHeightSig)), 4, 8))) {
		logErr("scanForAddrs failed for smallCharHeightSig");
		return false;
	}

	if (!idRenderModelGuiManager::acquirreUseScaleAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("useScaleSig", useScaleSig)), 4, 8))) {
		logErr("scanForAddrs failed for useScaleSig");
		return false;
	}

	if (!idRenderModelGuiManager::acquirreScreenWidthAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("getScreenWidthLocatorSig", getScreenWidthLocatorSig)), 2, 6))) {
		logErr("scanForAddrs failed for getScreenWidthLocatorSig");
		return false;
	}

	if (!idRenderModelGuiManager::acquirreScreenHeight(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("getScreenHeightLocatorSig", getScreenHeightLocatorSig)), 2, 6))) {
		logErr("scanForAddrs failed for getScreenHeightLocatorSig");
		return false;
	}

	/*if(idRenderModelGuiManager::acquirepackedColorMemberOffset((uintptr_t)MemHelper::ModulePatternScan("renderModelGuiPackecColorOffsetSig", renderModelGuiPackecColorOffsetSig)))*/

	/*if (!idHudEventManager::acquireBroadcastHudEventFp((uintptr_t)MemHelper::ModulePatternScan("broadcastHudEvent2ArgsSig", broadcastHudEvent2ArgsSig))) {
		logErr("scanForAddrs failed for broadcastHudEvent2ArgsSig");
		return false;
	}*/



	/*if (!idRenderModelGuiManager::acquireStaticWhiteMaterialAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("idMaterial2_WhiteSig", idMaterial2_WhiteSig)), 3, 7))) {
		logErr("scanForAddrs failed for idMaterial2_WhiteSig");
		return false;
	}*/

	//! don't need that anymore as we found it in engine_t as a idDeclGlobalFontTable* globalFontTable;
	/*if (!idFontManager::acquirreMonospaceFontAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("monoSpaceFontAddrSig", monoSpaceFontAddrSig)), 3, 7))) {
		anyScanFailed = true;
	}*/

	//! 2/11/24 we should not need those with our new methods to draw on screen
	/*if (!idFontManager::acquirreSetMonospaceFondOffsetAddr(MemHelper::ModulePatternScan("fontSetInSetUpMonoSpaceFontSig", fontSetInSetUpMonoSpaceFontSig) + 3)) {
		logErr("scanForAddrs failed for fontSetInSetUpMonoSpaceFontSig");
		return false;
	}*/	

	/*if (!idFontManager::acquirreDrawStringFontOffsetAddr(MemHelper::ModulePatternScan("fontSetInDrawStringSig", fontSetInDrawStringSig) + 30)) {
		logErr("scanForAddrs failed for fontSetInDrawStringSig");
		return false;
	}*/


	/*if (!idFontManager::acquirreConsoleHistoryFontOffsetAddr(MemHelper::ModulePatternScan("fontSetInConsoleHistorySig", fontSetInConsoleHistorySig) + 3)) {
		logErr("scanForAddrs failed for fontSetInConsoleHistorySig");
		return false;
	}*/


	//std::string getGlyphDataFuncSig = "89 54 24 10 53 48 83 EC 20 48 8B D9 48 8B 49 58";
	/*if (Config::isSandboxModule()) {
		getGlyphDataFuncSig = "89 54 24 10 57 48 83 EC 30 48 8B F9 48 8B 49 58";
	}	*/
	//if (!idFontManager::acquirreIdFontGetGlyphDataFuncAddr((uintptr_t)MemHelper::ModulePatternScan("getGlyphDataFuncSig", getGlyphDataFuncSig))) {
	if (!idFontManager::acquirreIdFontGetGlyphDataFuncPtr((uintptr_t)MemHelper::ModulePatternScan("getGlyphDataFuncSig", getGlyphDataFuncSig))) {
		logErr("scanForAddrs failed for getGlyphDataFuncSig");
		return false;
	}


	if (!idRenderModelGuiManager::acquirreDrawStringFuncAdd((uintptr_t)MemHelper::ModulePatternScan("idRenderModelGui_DrawString_623530FuncSig", idRenderModelGui_DrawString_623530FuncSig))) {
		logErr("scanForAddrs failed for idRenderModelGui_DrawString_623530FuncSig");
		return false;
	}

	if (!idRenderModelGuiManager::acquirreDrawStretchPicFuncAdd((uintptr_t)MemHelper::ModulePatternScan("idRenderModelGui_DrawStretchPic_498A10_FuncSig", idRenderModelGui_DrawStretchPic_498A10_FuncSig))) {
		logErr("scanForAddrs failed for idRenderModelGui_DrawStretchPic_498A10_FuncSig");
		return false;
	}


	if (!EquipmentManager::acquireUseEquipmentItemFp((uintptr_t)MemHelper::ModulePatternScan("UseEquipmentItemFpSig", UseEquipmentItemFpSig))) {
		logErr("scanForAddrs failed for UseEquipmentItemFpSig");
		return false;
	}

	if (!EquipmentManager::acquireSwitchEquipmentItemFp((uintptr_t)MemHelper::ModulePatternScan("SwitchEquipmentItemFpSig", SwitchEquipmentItemFpSig))) {
		logErr("scanForAddrs failed for SwitchEquipmentItemFpSig");
		return false;
	}

	
	


	/*InitRenderModelGuiMbFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("initRenderModelGuiMbFuncSig", initRenderModelGuiMbFuncSig);
	if (MemHelper::isBadReadPtr((void*)InitRenderModelGuiMbFuncAdd)) {
		logErr("scanForAddrs failed for initRenderModelGuiMbFuncSig");
		return false;
	}*/
	/*if (!MinHookManager::setInitRenderModelGuiMbFuncAdd((uintptr_t)MemHelper::ModulePatternScan("initRenderModelGuiMbFuncSig", initRenderModelGuiMbFuncSig))) {
		logErr("scanForAddrs failed for initRenderModelGuiMbFuncSig");
		return false;
	}*/

	/*SetIdHud_Debug_Print_SmthFuncAddr = (uintptr_t)MemHelper::ModulePatternScan("idHud_Debug_Print_SmthFuncSig", idHud_Debug_Print_SmthFuncSig);
	if (MemHelper::isBadReadPtr((void*)SetIdHud_Debug_Print_SmthFuncAddr)) {
		logErr("scanForAddrs failed for idHud_Debug_Print_SmthFuncSig");
		return false;
	}*/
	/*if (!MinHookManager::setIdHud_Debug_Print_SmthFuncAddr((uintptr_t)MemHelper::ModulePatternScan("idHud_Debug_Print_SmthFuncSig", idHud_Debug_Print_SmthFuncSig))) {
		logErr("scanForAddrs failed for idHud_Debug_Print_SmthFuncSig");
		return false;
	}*/

	/*if (!MinHookManager::setSetFontAndPrintStringMBFuncAdd((uintptr_t)MemHelper::ModulePatternScan("SetFontAndPrintStringMBFuncSig", SetFontAndPrintStringMBFuncSig))) {
		logErr("scanForAddrs failed for SetFontAndPrintStringMBFuncSig");
		return false;
	}*/

	IdPlayerSelectWeaponForSelectionGroupAddr = (uintptr_t)MemHelper::ModulePatternScan("idPLayerSelectWeaponForSelectionGroupSig", idPLayerSelectWeaponForSelectionGroupSig);
	if (MemHelper::isBadReadPtr((void*)IdPlayerSelectWeaponForSelectionGroupAddr)) {
		logErr("scanForAddrs failed for idPLayerSelectWeaponForSelectionGroupSig");
		return false;
	}
	/*if (!MinHookManager::SetIdPlayerSelectWeaponForSelectionGroupAddr((uintptr_t)MemHelper::ModulePatternScan("idPLayerSelectWeaponForSelectionGroupSig", idPLayerSelectWeaponForSelectionGroupSig))) {
		logErr("scanForAddrs failed for idPLayerSelectWeaponForSelectionGroupSig");
		return false;
	}*/

	GetIsKeyPressedAddr = (uintptr_t)MemHelper::ModulePatternScan("isKeyPressedSig", isKeyPressedSig);
	if (MemHelper::isBadReadPtr((void*)GetIsKeyPressedAddr)) {
		logErr("scanForAddrs failed for isKeyPressedSig");
		return false;
	}
	/*if (!MinHookManager::SetIsKeyPressedAddr((uintptr_t)MemHelper::ModulePatternScan("isKeyPressedSig", isKeyPressedSig))) {
		logErr("scanForAddrs failed for isKeyPressedSig");
		return false;
	}*/

	GetIdMenuUpdateAddr = (uintptr_t)MemHelper::ModulePatternScan("idMenu_UpdateSig", idMenu_UpdateSig);
	if (MemHelper::isBadReadPtr((void*)GetIdMenuUpdateAddr)) {
		logErr("scanForAddrs failed for idMenu_UpdateSig");
		return false;
	}
	/*if (!MinHookManager::SetIdMenuUpdateAddr((uintptr_t)MemHelper::ModulePatternScan("idMenu_UpdateSig", idMenu_UpdateSig))) {
		logErr("scanForAddrs failed for idMenu_UpdateSig");
		return false;
	}*/

	GetPBindsStrSetAddr = (uintptr_t)MemHelper::ModulePatternScan("pBindsStrSetSig", pBindsStrSetSig);
	if (MemHelper::isBadReadPtr((void*)GetPBindsStrSetAddr)) {
		logErr("scanForAddrs failed for pBindsStrSetSig");
		return false;
	}
	/*if (!MinHookManager::SetPBindsStrSetAddr((uintptr_t)MemHelper::ModulePatternScan("pBindsStrSetSig", pBindsStrSetSig))) {
		logErr("scanForAddrs failed for pBindsStrSetSig");
		return false;
	}*/

	GetSetActiveReticleAddr = (uintptr_t)MemHelper::ModulePatternScan("setActiveReticleSig", setActiveReticleSig);
	if (MemHelper::isBadReadPtr((void*)GetSetActiveReticleAddr)) {
		logErr("scanForAddrs failed for setActiveReticleSig");
		return false;
	}

	/*if (!MinHookManager::SetSetActiveReticleAddr((uintptr_t)MemHelper::ModulePatternScan("setActiveReticleSig", setActiveReticleSig))) {
		logErr("scanForAddrs failed for setActiveReticleSig");
		return false;
	}*/

	GetConvertIdDeclUIColorToIdColorTargetAddr = (uintptr_t)MemHelper::ModulePatternScan("convertIdDeclUIColorToidColorTargetSig", convertIdDeclUIColorToidColorTargetSig);
	if (MemHelper::isBadReadPtr((void*)GetConvertIdDeclUIColorToIdColorTargetAddr)) {
		logErr("scanForAddrs failed for convertIdDeclUIColorToidColorTargetSig");
		return false;
	}
	/*if (!MinHookManager::SetConvertIdDeclUIColorToIdColorTargetAddr((uintptr_t)MemHelper::ModulePatternScan("convertIdDeclUIColorToidColorTargetSig", convertIdDeclUIColorToidColorTargetSig))) {
		logErr("scanForAddrs failed for convertIdDeclUIColorToidColorTargetSig");
		return false;
	}*/

	SetSpriteInstanceAddr = (uintptr_t)MemHelper::ModulePatternScan("setSpriteInstanceSig", setSpriteInstanceSig);
	if (MemHelper::isBadReadPtr((void*)SetSpriteInstanceAddr)) {
		logErr("scanForAddrs failed for setSpriteInstanceSig");
		return false;
	}
	/*if (!MinHookManager::SetSetSpriteInstanceAddr((uintptr_t)MemHelper::ModulePatternScan("setSpriteInstanceSig", setSpriteInstanceSig))) {

		logErr("scanForAddrs failed for setSpriteInstanceSig");
		return false;
	}*/

	SetGetFovTargetValAddr = (uintptr_t)MemHelper::ModulePatternScan("GetFovTargetValSig", GetFovTargetValSig);
	if (MemHelper::isBadReadPtr((void*)SetGetFovTargetValAddr)) {
		logErr("scanForAddrs failed for GetFovTargetValSig");
		return false;
	}
	/*if (!MinHookManager::SetGetFovTargetValAddr((uintptr_t)MemHelper::ModulePatternScan("GetFovTargetValSig", GetFovTargetValSig))) {
		logErr("scanForAddrs failed for GetFovTargetValSig");
		return false;
	}*/

	PrintOutlinedStringMBFuncAddr = (uintptr_t)MemHelper::ModulePatternScan("printOutlinedStringMBSig", printOutlinedStringMBSig);
	if (MemHelper::isBadReadPtr((void*)PrintOutlinedStringMBFuncAddr)) {
		logErr("scanForAddrs failed for printOutlinedStringMBSig");
		return false;
	}
	/*if (!MinHookManager::setPrintOutlinedStringMBFuncAddr((uintptr_t)MemHelper::ModulePatternScan("printOutlinedStringMBSig", printOutlinedStringMBSig))) {
		logErr("scanForAddrs failed for printOutlinedStringMBSig");
		return false;
	}*/

	//? not good enough
	/*if (!MinHookManager::SetCustomAnimSmthFuncAdd((uintptr_t)MemHelper::ModulePatternScan("skipCustomAnimFpSig", skipCustomAnimFpSig))) {
		logErr("scanForAddrs failed for skipCustomAnimFpSig");
		return false;
	}*/
	//? not good enough
	//if (!MinHookManager::Set_SetMovementDuringCustomAnimFAdd((uintptr_t)MemHelper::ModulePatternScan("setMovementDuringCustomAnimFpSig", setMovementDuringCustomAnimFpSig))) {
	//	logErr("scanForAddrs failed for setMovementDuringCustomAnimFpSig");
	//	return false;
	//}

	IdInventoryCollectionSmthFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("idInventoryCollectionSmthFpSig", idInventoryCollectionSmthFpSig);
	if (MemHelper::isBadReadPtr((void*)IdInventoryCollectionSmthFuncAdd)) {
		logErr("scanForAddrs failed for idInventoryCollectionSmthFpSig");
		return false;
	}
	/*if (!MinHookManager::SetIdInventoryCollectionSmthFuncAdd((uintptr_t)MemHelper::ModulePatternScan("idInventoryCollectionSmthFpSig", idInventoryCollectionSmthFpSig))) {
		logErr("scanForAddrs failed for idInventoryCollectionSmthFpSig");
		return false;
	}*/

	IdHUDMenu_CurrencyConfirmationSmthFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("idHUDMenu_CurrencyConfirmationSmthFpSig", idHUDMenu_CurrencyConfirmationSmthFpSig);
	if (MemHelper::isBadReadPtr((void*)IdHUDMenu_CurrencyConfirmationSmthFuncAdd)) {
		logErr("scanForAddrs failed for idHUDMenu_CurrencyConfirmationSmthFpSig");
		return false;
	}
	/*if (!MinHookManager::SetIdHUDMenu_CurrencyConfirmationSmthFuncAdd((uintptr_t)MemHelper::ModulePatternScan("idHUDMenu_CurrencyConfirmationSmthFpSig", idHUDMenu_CurrencyConfirmationSmthFpSig))) {
		logErr("scanForAddrs failed for idHUDMenu_CurrencyConfirmationSmthFpSig");
		return false;
	}*/

	StartSyncFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("p_StartSyncFpSig", p_StartSyncFpSig);
	if (MemHelper::isBadReadPtr((void*)StartSyncFuncAdd)) {
		logErr("scanForAddrs failed for p_StartSyncFpSig");
		return false;
	}
	/*if (!MinHookManager::SetStartSyncFuncAdd((uintptr_t)MemHelper::ModulePatternScan("p_StartSyncFpSig", p_StartSyncFpSig))) {
		logErr("scanForAddrs failed for p_StartSyncFpSig");
		return false;
	}*/

	IdPlayerFovLerpFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("idPlayerFovLerpFpSig", idPlayerFovLerpFpSig);
	if (MemHelper::isBadReadPtr((void*)IdPlayerFovLerpFuncAdd)) {
		logErr("scanForAddrs failed for idPlayerFovLerpFpSig");
		return false;
	}
	/*if (!MinHookManager::SetIdPlayerFovLerpFuncAdd((uintptr_t)MemHelper::ModulePatternScan("idPlayerFovLerpFpSig", idPlayerFovLerpFpSig))) {
		logErr("scanForAddrs failed for idPlayerFovLerpFpSig");
		return false;
	}*/

	SyncEndFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("syncEndFpSig", syncEndFpSig);
	if (MemHelper::isBadReadPtr((void*)SyncEndFuncAdd)) {
		logErr("scanForAddrs failed for syncEndFpSig");
		return false;
	}
	/*if (!MinHookManager::SetSyncEndFuncAdd((uintptr_t)MemHelper::ModulePatternScan("syncEndFpSig", syncEndFpSig))) {
		logErr("scanForAddrs failed for syncEndFpSig");
		return false;
	}*/

	RenderSpriteFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("RenderSpriteFpSig", RenderSpriteFpSig);
	if (MemHelper::isBadReadPtr((void*)RenderSpriteFuncAdd)) {
		logErr("scanForAddrs failed for RenderSpriteFpSig");
		return false;
	}
	/*if (!MinHookManager::SetRenderSpriteFuncAdd((uintptr_t)MemHelper::ModulePatternScan("RenderSpriteFpSig", RenderSpriteFpSig))) {
		logErr("scanForAddrs failed for RenderSpriteFpSig");
		return false;
	}*/

	IdUsercmdGenLocalSendBtnPressFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("SetIdUsercmdGenLocalSendBtnPressFpSig", IdUsercmdGenLocalSendBtnPressFpSig);
	if (MemHelper::isBadReadPtr((void*)IdUsercmdGenLocalSendBtnPressFuncAdd)) {
		logErr("scanForAddrs failed for IdUsercmdGenLocalSendBtnPressFpSig");
		return false;
	}


	PerfMetrics_DrawGraphsFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("PerfMetrics_DrawGraphsFpSig", PerfMetrics_DrawGraphsFpSig);
	if (MemHelper::isBadReadPtr((void*)PerfMetrics_DrawGraphsFuncAdd)) {
		logErr("scanForAddrs failed for PerfMetrics_DrawGraphsFpSig");
		return false;
	}

	IdDebugHUDLocal_RenderFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("idDebugHUDLocal_RenderFpSig", idDebugHUDLocal_RenderFpSig);
	if (MemHelper::isBadReadPtr((void*)IdDebugHUDLocal_RenderFuncAdd)) {
		logErr("scanForAddrs failed for idDebugHUDLocal_RenderFpSig");
		return false;
	}


	/*if (!MinHookManager::SetIdUsercmdGenLocalSendBtnPressFuncAdd((uintptr_t)MemHelper::ModulePatternScan("SetIdUsercmdGenLocalSendBtnPressFpSig", IdUsercmdGenLocalSendBtnPressFpSig))) {
		logErr("scanForAddrs failed for IdUsercmdGenLocalSendBtnPressFpSig");
		return false;
	}*/

	ConsoleLogFuncAdd = (uintptr_t)MemHelper::ModulePatternScan("consoleLogFpSig", consoleLogFpSig);
	if (MemHelper::isBadReadPtr((void*)ConsoleLogFuncAdd)) {
		logErr("scanForAddrs failed for consoleLogFpSig");
		return false;
	}
	/*if (!MinHookManager::SetConsoleLogFuncAdd((uintptr_t)MemHelper::ModulePatternScan("consoleLogFpSig", consoleLogFpSig))) {
		logErr("scanForAddrs failed for consoleLogFpSig");
		return false;
	}*/

	//! MINHOOK SCAN END






	if (!ColorManager::acquirreReapplySwfColorsFuncAddr((uintptr_t)MemHelper::ModulePatternScan("reapplySwfColorsSig", reapplySwfColorsSig))) {
		logErr("scanForAddrs failed for reapplySwfColorsSig");
		return false;
	}

	/*if (!idInventoryCollectionManager::acquirreGetInventoryItemFuncAddr((uintptr_t)MemHelper::ModulePatternScan("GetInventoryItemSig", GetInventoryItemSig))) {
		logErr("scanForAddrs failed for GetInventoryItemSig");
		return false;
	}*/

	if (!idResourceListManager::acquirreResourceListForClassNameAddr((uintptr_t)MemHelper::ModulePatternScan("idResourceListForClassNameSig", idResourceListForClassNameSig))) {
		logErr("scanForAddrs failed for idResourceListForClassNameSig");
		return false;
	}

	if (!idResourceListManager::acquireGetResourceFp((uintptr_t)MemHelper::ModulePatternScan("getResourceFpSig", getResourceFpSig))) {
		logErr("scanForAddrs failed for getResourceFpSig");
		return false;
	}

	
	if (!idFontManager::init(TypeInfoManager::getGlobalFontTable())) { //! 3/11/24 this need to happen afte resList func has been set
		logErr("scanForAddrs failed for init");
		return false;
	}


	//? not needed anymore we're using a cvar
	/*if (!LangManager::acquirreSysLangFuncStartAddr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("findSysLangSig", findSysLangSig)), 3, 7))) {
		logErr("scanForAddrs failed for findSysLangSig");
		return false;
	}*/

	if (!idDeclInfo::acquirreIdDeclInfoTemplate_idMaterial2Ptr(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("idDeclInfoTemplate_idMaterial2Sig", idDeclInfoTemplate_idMaterial2Sig)), 3, 7))) {
		logErr("scanForAddrs failed for idDeclInfoTemplate_idMaterial2Sig");
		return false;
	}

	if (!idDeclInfo::acquirreIdDeclInfo_FindWithInheritanceFuncPtr((uintptr_t)MemHelper::ModulePatternScan("idDeclInfo_FindWithInheritanceFuncSig", idDeclInfo_FindWithInheritanceFuncSig))) {
		logErr("scanForAddrs failed for idDeclInfo_FindWithInheritanceFuncSig");
		return false;
	}

	if (!BindLabelChanger::acquirreIdStringBigListOffset(MemHelper::FindHardcodedOffset((uintptr_t)MemHelper::ModulePatternScan("findIdStringBigListSig", findIdStringBigListSig), 4))) {
		logErr("scanForAddrs failed for findIdStringBigListSig");
		return false;
	}


	if (!GameInfoManager::acquireGpuInfoVar(MemHelper::FindPtrFromRelativeOffset(((uintptr_t)MemHelper::ModulePatternScan("GpuInfoStartSig", GpuInfoStartSig)), 3, 7))) {
		logErr("scanForAddrs failed for GpuInfoStartSig");
		return false;
	}
	

	//? don't need this thers is a cvar for it
	/*qsdfif (!GameInfoManager::acquirreBuildStrPtrAdd((__int64**)MemHelper::FindPtrFromRelativeOffset((uintptr_t)MemHelper::ModulePatternScan("BuildInformationStrSig", BuildInformationStrSig), 3, 7))) {
		logErr("scanForAddrs failed for BuildInformationStrSig");
		return false;
	}*/


	if (!idSWFSpriteInstanceManager::acquirreSetSpriteInstanceScaleFpAdd((uintptr_t)MemHelper::ModulePatternScan("SpriteInstanceSetScaleFuncSig", SpriteInstanceSetScaleFuncSig))) {
		logErr("scanForAddrs failed for SpriteInstanceSetScaleFuncSig");
		return false;
	}

	if (!idSWFSpriteInstanceManager::acquireUpdateSpriteInstanceColorFuncAdd((uintptr_t)MemHelper::ModulePatternScan("SpriteInstanceUpdateColorFuncSig", SpriteInstanceUpdateColorFuncSig))) {
		logErr("scanForAddrs failed for SpriteInstanceUpdateColorFuncSig");
		return false;
	}

	if (!idFxManager::acquireToggleDashEffectInstructionAddr((uintptr_t)MemHelper::ModulePatternScan("dashEffectToggleSig", dashEffectToggleSig) + 1)) {
		logErr("scanForAddrs failed for dashEffectToggleSig");
		return false;
	}


	if (!idHudManager::acquireIsWorldMenuAtIndexActiveFuncAddr((uintptr_t)MemHelper::ModulePatternScan("isWorldMenuAtIndexActiveFaddrSig", isWorldMenuAtIndexActiveFaddrSig))) {
		logErr("scanForAddrs failed for isWorldMenuAtIndexActiveFaddrSig");
		return false;
	}



	logInfo("scanForAddrs: all Pattern Scans were Sucessful !");
	return true;
}
