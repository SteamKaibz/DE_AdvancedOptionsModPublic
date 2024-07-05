#include "idCmd.h"



bool idCmd::acquireIdCmdSystemLocalPtr(__int64 idCmdSystemLocalPtr) {
	if (MemHelper::isBadReadPtr((void*)idCmdSystemLocalPtr)) {
		logErr("acquireIdCmdSystemLocalPtr: failed to acquire idCmdSystemLocalPtr (bad ptr): %p", (void*)idCmdSystemLocalPtr);
		m_idCmdSystemLocal = 0;
		return false;
	}

	m_idCmdSystemLocal = *(__int64*)idCmdSystemLocalPtr;
	if (MemHelper::isBadReadPtr((void*)m_idCmdSystemLocal)) {
		logErr("acquireIdCmdSystemLocalPtr: failed to  acquire m_idCmdSystemLocal (bad ptr): %p", (void*)m_idCmdSystemLocal);
		m_idCmdSystemLocal = 0;
		return false;
	}

	logInfo("acquireIdCmdSystemLocalPtr: Succes acquirring m_idCmdSystemLocal: %p", (void*)m_idCmdSystemLocal);
	return true;
}


bool idCmd::acquirreExecuteCommandTextFuncPtr() {
	if (!m_idCmdSystemLocal) {
		logErr("executeCommandText: m_idCmdSystemLocal is null can not execute");
		return false;
	}

	__int64 vtblAddr = *(__int64*)m_idCmdSystemLocal;
	__int64 cmdExecuteFuncAddr = *(__int64*)(vtblAddr + UndocumentedOffsets::CmdExecuteFuncAddrOffset);
	//__int64 cmdExecuteFuncAddr = *(__int64*)(vtblAddr + 0x40);
	m_idCmdSystemLocal_ExecuteFp = reinterpret_cast<idCmdSystemLocal_Execute_t>(cmdExecuteFuncAddr);
	logInfo("acquirreExecuteCommandTextFuncPtr: m_idCmdSystemLocal_ExecuteFp set to %p", m_idCmdSystemLocal_ExecuteFp);
	return true;
}



uintptr_t idCmd::executeCommandText(const char* txt) {
	
	if (!m_idCmdSystemLocal || !m_idCmdSystemLocal_ExecuteFp) {
		logErr("executeCommandText: Error can not execute");
		return 0;
	}

	return m_idCmdSystemLocal_ExecuteFp((idCmdSystemLocal*)m_idCmdSystemLocal, txt);

}




void idCmd::setGameSpeed(gameSpeed_K gameSpeed) {
	if (gameSpeed == gameSpeed_K::maxSpeed) {
		executeCommandText("timescale 10"); //! by default max is 10.
	}
	else if (gameSpeed == gameSpeed_K::X2_Speed) {
		executeCommandText("timescale 2");
	}
	else if (gameSpeed == gameSpeed_K::defaultSpeed) {
		executeCommandText("timescale 1"); 
	}
	else {
		logErr("setGameSpeed failed to find gameSpeed: %d can not execute cmd", (int)gameSpeed);
	}
}


 void idCmd::setReticleMode(UI_ReticleMode mode) {

	if (mode == UI_ReticleMode::None) {
		executeCommandText("g_reticleMode 2");
	}
	else if (mode == UI_ReticleMode::Dot) {
		executeCommandText("g_reticleMode 1");
	}
	else if (mode == UI_ReticleMode::Full) {
		executeCommandText("g_reticleMode 0");
	}
	else {
		logWarn("setReticleMode: found undefined mode of reticle mode ?!");
	}

}


 void idCmd::showEquipmentInfo(bool isTrue) {

	logInfo("Setting showEquipmentInfo to: %d ", isTrue);
	if (isTrue) {
		executeCommandText("g_setting_equipment_info 1");
	}
	else {
		executeCommandText("g_setting_equipment_info 0");
	}
}

//! this is slow (i assmue) but it's ok cause triggered only when user changes ini file
 void idCmd::skipHudBtnsCallOut(bool isTrue) {

	logInfo("Setting skipHudBtnsCallOut to: %d ", isTrue);
	if (isTrue) {
		executeCommandText("swf_skipHudButtonCallouts 1");
	}
	else {
		executeCommandText("swf_skipHudButtonCallouts 0");
	}
 }

 void idCmd::showTestMaterial(std::string materialNameStr) {
	std::string cmdStr = "g_testMaterial " + materialNameStr;
	executeCommandText(cmdStr.c_str());
 }

//! making sure debug_hud_string cmd is active so the custom ice icon can be rendere, and may be latter donw the road a whole hud. this cmd basically activates the Debug_hud so it can render. 
 void idCmd::forceDebug_hud_string() {
	std::string cmdStr = "debug_hud_string " + hudString::textForidCmd;
	executeCommandText(cmdStr.c_str());
 }


//! this works but changing it will not update the scale if it's changed through the ini file
 void idCmd::setReticleOverride(reticleStyle_t reticleStyle) {
	std::string cmd = "hud_reticle_styleOverride " + std::to_string(static_cast<int>(reticleStyle));
	logInfo("setReticleOverride: reticleStyle: %d", (int)reticleStyle);
	executeCommandText(cmd.c_str());
 }


 void idCmd::setMinMaxFov(bool isUnlockedFovInMenu) {
	 if (isUnlockedFovInMenu) {		
		 executeCommandText("ui_settings_video_fovMin 70");
		 executeCommandText("ui_settings_video_fovMax 150");
	 }
	 else {
		 executeCommandText("ui_settings_video_fovMin 90");
		 executeCommandText("ui_settings_video_fovMax 120");

		 float currentFovF = idCvarManager::getCvarFloat("g_fov");
		 if (currentFovF > 120.0f) {
			 idCvarManager::setCvar("g_fov", "120");
			 logInfo("setMinMaxFov: current fov is over max value, setting it to 120");
		 }
		 else if (currentFovF < 90.0f) {
			 idCvarManager::setCvar("g_fov", "90");
			 logInfo("setMinMaxFov: current fov is below min value, setting it to 90");
		 }
	 }
 }



//! this is slow (i assmue) but it's ok cause triggered only when user is out of mod menu

 void idCmd::setHandsFov(int iniFileValue) {
	
	std::string valAsStr = getHandsFovFloatValAsStr(iniFileValue);
	logInfo("Setting hands fov to: %s ", valAsStr.c_str());
	executeCommandText(valAsStr.c_str());

	//return m_pIdCvar_Set((__m128i***)m_handsFovScale_SideNotificationOffset, valAsStr.c_str(), 4);
 }


 std::string idCmd::getHandsFovFloatValAsStr(int iniFileValue) { //! 1 - 100
	logDebug("getHandsFovFloatValAsStr: iniFileValue: %d", iniFileValue);
	if (iniFileValue <= 0) {
		iniFileValue = 0; //! default value 
	}
	else if (iniFileValue > 100) {
		iniFileValue = 100;
	}

	float floatVal = (float)iniFileValue / (float)100;
	if (iniFileValue == 0) {
		floatVal = 0.f;
	}
	else if (floatVal > 0.95f) {
		floatVal = 0.95f;
	}
	else if (floatVal < 0.1f) { //! there are issues if val is like 0.02 so 0.1 is a good base.
		floatVal = 0.1f;
	}
	std::string valAsStr = std::to_string(floatVal);
	valAsStr = "hands_fovScale " + valAsStr;
	logInfo("getHandsFovFloatValAsStr: iniFileValue: %d  converted value as floatStr:  %s ", iniFileValue, valAsStr.c_str());
	return valAsStr;
 }



 void idCmd::SetInMouseEnabled(bool isEnable) {
	 if(isEnable) {
		 executeCommandText("in_mouse 1");
		 logInfo("SetInMouseEnabled: debug setting in_mouse 1");
	 }
	 else {
		 executeCommandText("in_mouse 0");
		 logInfo("SetInMouseEnabled: debug setting in_mouse 0");

	 }
 }


 void idCmd::ToggleMainMenu() {
	 executeCommandText("ToggleMainMenu");
 }


 void idCmd::setAntiAliasingState(bool isDisableAA) {	
	
	 antialiasingLevel curAALevel = fastCvarManager::getCurAntiAliasLevel();

	 if (isDisableAA) {

		 logInfo("setAntiAliasingState: curAALevel is %d setting it to DISABLED (0) ", (int)curAALevel);
		 executeCommandText("r_antialiasing 0");
	 }

	 else  {
		 //? only setting AA if it was disabled before and setting it to cvar default to prevent any issue.
		 if (curAALevel <= antialiasingLevel::DISABLED) {
			 logInfo("setAntiAliasingState: curAALevel is DISABLED (0) setting it to TEMPORAL_SSA_X32 (1) ");
			 executeCommandText("r_antialiasing 1");
		 }			 
	 }

	/* logInfo("setAliasingLevel: attempting to set AA to level: %d", (int)level);

	 if (level == antialiasingLevel::DISABLED) {
		 executeCommandText("r_antialiasing 0");
	 }
	 else if (level == antialiasingLevel::TEMPORAL_SSA_X32) {
		 executeCommandText("r_antialiasing 1");
	 }
	 else if (level == antialiasingLevel::NVIDIA_DLSS) {
		 executeCommandText("r_antialiasing 2");
	 }
	 else {
		 logErr("setAliasingLevel: attempting to set AA level to unknown level: %d", (int)level);
	 }*/

 }

 void idCmd::setMouseSmoothing(bool isDisabled) {
	 if (isDisabled) {
		 executeCommandText("m_smoothing 0");
	 }
	 else {
		 executeCommandText("m_smoothing 1");
	 }
 }

 void idCmd::setHdrBloom(bool isDisabled) {
	 if (isDisabled) {
		 executeCommandText("r_hdrBloom 0");
	 }
	 else {
		 executeCommandText("r_hdrBloom 1");
	 }
 }


 void idCmd::setDecalLifetimeMultiplier(int value) {
	 if (value < 1) {
		 value = 1;
	 }
	 else if (value > 5) {
		 value = 5;
	 }

	 std::string cmdStr = "r_decalLifetimeMultiplier ";
	 cmdStr += std::to_string(value);

	 executeCommandText(cmdStr.c_str());
 }


 void idCmd::setDesaturate(float value) {
	 if (value < 0.0f) {
		 value = 0.0f;
	 }
	 else if (value > 1.0f) {
		 value = 1.0f;
	 }

	 std::string cmdStr = "r_desaturate ";
	 cmdStr += std::to_string(value);

	 executeCommandText(cmdStr.c_str());
 }


 void idCmd::setIsForceAiHaste(bool isForceAiHaste) {

	 float value = -1.0f; //! default

	 if (isForceAiHaste) {
		 value = 2.0f; //! value zeroMaster used.
	 }
	
	 std::string cmdStr = "ai_haste_overrideRate ";
	 cmdStr += std::to_string(value);

	 logInfo("setIsForceAiHaste: debug, isForceAiHaste is: %d cmdStr: %s", isForceAiHaste, cmdStr.c_str());

	 executeCommandText(cmdStr.c_str());
 }



 // uintptr_t idCmd::executeCommandText_K2(const char* txt) {
//
//	try
//	{
//		if (!m_cmdSystemLocalAddrPtrAddr) {
//			m_cmdSystemLocalAddrPtrAddr = TypeInfoManager::getCmdSystemPtrAddr();
//		}
//
//		if (MemHelper::isBadReadPtr((void*)m_cmdSystemLocalAddrPtrAddr)) {
//			logErr("executeCommandText_K2:m_cmdSystemLocalAddrPtrAddr is bad ptr can not execute command");
//			return 0; //?
//		}
//		__int64 cmdSystemAddr = *(__int64*)m_cmdSystemLocalAddrPtrAddr;
//		if (!m_executeCmdFuncAddr) {
//			__int64 vtblAddr = *(__int64*)cmdSystemAddr;
//			m_executeCmdFuncAddr = *(__int64*)(vtblAddr + 0x40);
//		}
//
//		return m_idCmdSystemLocal_ExecuteFp((idCmdSystemLocal*)cmdSystemAddr, txt);
//		/*auto cmdSys = reinterpret_cast<idCmdSystemLocal_K>(m_executeCmdFuncAddr);
//		return cmdSys((idCmdSystemLocal*)cmdSystemAddr, txt);*/
//	}
//	catch (const std::exception& ex)
//	{
//		logErr("executeCommandText_K2: ERROR: %s ", ex.what());
//	}
//	return 0;
//}

 //! CVARS:

// void idCmd::PrintCvarFindAddrTest(const char* name) {
//
//	try
//	{
//		if (!m_cvarSystemLocalPtrAddr) {
//			m_cvarSystemLocalPtrAddr = TypeInfoManager::getCvarSystemPtrAddr();
//			logInfo("PrintCvarFindAddrTest: m_cvarSystemLocalPtrAddr is now: %p", (void*)m_cvarSystemLocalPtrAddr);
//		}
//
//		if (MemHelper::isBadReadPtr((void*)m_cvarSystemLocalPtrAddr)) {
//			logErr("CvarFindAddrTest: m_cvarSystemLocalPtrAddr is bad ptr returning 0");
//			return;
//		}
//		//__int64 cvarSystemPtr = ObjectLocator::getCvarSystemLocatPtr();
//		//logInfo("PrintCvarFindAddrTest: cvarSystemPtr is: %p", (void*)cvarSystemPtr);
//		__int64 cvarSystemAddr = *(__int64*)m_cvarSystemLocalPtrAddr;
//		__int64 vtblAddr = *(__int64*)cvarSystemAddr;
//		logInfo("PrintCvarFindAddrTest: vtblAddr is: %p", (void*)vtblAddr);
//		__int64 funcAddr = *(__int64*)(vtblAddr + 0x20);
//		logInfo("PrintCvarFindAddrTest: funcAddr is: %p", (void*)funcAddr);
//
//		//logWarn("PrintCvarFindAddrTest: RETURNING FOR NO CRASH....");
//		//return ; //? don't forget this
//
//		auto cvarSys = reinterpret_cast<CvarFindAddrTest>(funcAddr);
//		//auto result = cvarSys((__int64*)cvarSystemAddr, name);
//		idCVar* cvarPtr = (idCVar*)(cvarSys((__int64*)cvarSystemAddr, name));
//		logInfo("CvarFindAddrTest: cvarPtr->data->valueInteger: %d", cvarPtr->data->valueInteger);
//		//logInfo("CvarFindAddrTest: addr result: %p", (void*)result);
//	}
//	catch (const std::exception& ex)
//	{
//		logErr("PrintCvarFindAddrTest: ERROR: %s ", ex.what());
//	}
//
//}

// idCVar* idCmd::getCvarPtr(const char* txt) {
//	logDebug("getCvarPtr");
//
//	try
//	{
//		if (!m_cvarSystemLocalPtrAddr) {
//			m_cvarSystemLocalPtrAddr = TypeInfoManager::getCvarSystemPtrAddr();
//			logInfo("getCvarPtr: m_cvarSystemLocalPtrAddr is now: %p", (void*)m_cvarSystemLocalPtrAddr);
//		}
//
//		if (MemHelper::isBadReadPtr((void*)m_cvarSystemLocalPtrAddr)) {
//			logErr("getCvar: ObjectLocator::getCvarSystemLocalPtr() is bad ptr: %p returning 0", (void*)m_cvarSystemLocalPtrAddr);
//			return 0;
//		}
//		__int64 cvarSystemAddr = *(__int64*)m_cvarSystemLocalPtrAddr;
//		if (!m_findCvarFuncAddr) {
//			//__int64 cvarSystemPtr = ObjectLocator::getCvarSystemLocatPtr();
//		//logInfo("getCvar: cvarSystemPtr is: %p", (void*)cvarSystemPtr);				
//			__int64 vtblAddr = *(__int64*)cvarSystemAddr;
//			//logInfo("getCvar: vtblAddr is: %p", (void*)vtblAddr);
//			m_findCvarFuncAddr = *(__int64*)(vtblAddr + 0x20);			
//			//logInfo("getCvar: funcAddr is: %p", (void*)funcAddr);
//		}
//		auto cvarSys = reinterpret_cast<CvarFindAddrTest>(m_findCvarFuncAddr);
//		return (idCVar*)(cvarSys((__int64*)cvarSystemAddr, txt));
//		//idCVar* cvarPtr = (idCVar*)(cvarSys((__int64*)cvarSystemAddr, txt));
//		//return
//			//logInfo("getCvar: cvarPtr->data->valueInteger: %d", cvarPtr->data->valueInteger);
//	}
//	catch (const std::exception& ex)
//	{
//		logErr("getCvarPtr: ERROR: %s ", ex.what());
//	}
//	return nullptr;
//}

// int idCmd::getCvarInt(const char* txt) {
//	logDebug("getCvarInt");
//
//	idCVar* cvarPtr = (idCVar*)getCvarPtr(txt);
//	return cvarPtr->data->valueInteger;
//}




 /*UI_ReticleMode idCmd::getReticleMode() {
	logDebug("getReticleMode");

	if (!m_cached_GetReticleModeCvarPtr) {
		m_cached_GetReticleModeCvarPtr = (idCVar*)getCvarPtr("g_reticleMode");
		logInfo("getReticleMode: getReticleModem_cached_GetReticleModeCvarPtr has been set to: %p", m_cached_GetReticleModeCvarPtr);
	}
	if (!m_cached_GetReticleModeCvarPtr) {
		logErr("getReticleMode: getReticleMode: failed to find GetReticleModeCvarPtr");
		return UI_ReticleMode::Unknown;
	}

	return (UI_ReticleMode)m_cached_GetReticleModeCvarPtr->data->valueInteger;
}*/

// bool idCmd::isGameTimeScalingEnabled() {
//	logDebug("isGameTimeScalingEnabled");
//	if (!m_cached_isGameTimeScalingEnabledPtr) {
//		m_cached_isGameTimeScalingEnabledPtr = (idCVar*)getCvarPtr("g_enableGameTimeScaling");
//		logInfo("isGameTimeScalingEnabled: isGameTimeScalingEnabled has been set to: %p", m_cached_isGameTimeScalingEnabledPtr);
//	}
//	if (!m_cached_isGameTimeScalingEnabledPtr) {
//		logErr("isGameTimeScalingEnabled: failed to find g_enableGameTimeScaling cvar ptr");
//		return true; //? returning true cause it is by default but this is not ideal obviously.
//	}
//	return (bool)m_cached_isGameTimeScalingEnabledPtr->data->valueInteger;
//}
