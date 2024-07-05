#include "TypeInfoManager.h"


 bool TypeInfoManager::acquireTypeInfoTools(__int64 typeInfoToolsPtr) {
	logDebug("acquireTypeInfoTools");
	if (MemHelper::isBadReadPtr((void*)typeInfoToolsPtr)) {
		logErr("acquireTypeInfoTools: failed to acquire TypeInfoTools (bad ptr): %p", (void*)typeInfoToolsPtr);
		m_typeInfoToolsPtrAddr = 0;
	}
	else {
		m_typeInfoToolsPtrAddr = typeInfoToolsPtr;
		m_idTypeInfoTools = (idTypeInfoTools*)*(__int64*)m_typeInfoToolsPtrAddr;
		logInfo("acquireTypeInfoTools: Succes acquirring m_typeInfoToolsPtrAddr: %p and m_idTypeInfoTools: %p", (void*)m_typeInfoToolsPtrAddr, m_idTypeInfoTools);
		return true;
	}
	return false;
}

  bool TypeInfoManager::acquirreFindClassInfoFuncPtr(__int64 funcAddr) {
	 logDebug("acquirreFindClassInfoFuncPtr");
	 if (!funcAddr) {
		 logErr("acquirreFindClassInfoFuncPtr: failed to acquire funcAddr");
		 m_findClassInfoFuncPtr = 0;
		 return false;
	 }
	 else {
		 m_findClassInfoFuncPtr = funcAddr;
		 logInfo("acquirreFindClassInfoFuncPtr: Succes acquirring funcAddr: %p", (void*)funcAddr);
	 }
	 return true;
 }


   bool TypeInfoManager::acquirreFindEnumInfoFuncPtr(__int64 funcAddr) {
	  logDebug("acquirreFindEnumInfoFuncPtr");
	  if (!funcAddr) {
		  logErr("acquirreFindEnumInfoFuncPtr: failed to acquire funcAddr");
		  m_findEnumInfoFuncPtr = 0;
		  return false;
	  }
	  else {
		  m_findEnumInfoFuncPtr = funcAddr;
		  logInfo("acquirreFindEnumInfoFuncPtr: Succes acquirring funcAddr: %p", (void*)funcAddr);
	  }
	  return true;
  }

   typeInfoGenerated_t* TypeInfoManager::getTypeInfoGenerated_t()
   {
	   if (MemHelper::isBadReadPtr(m_idTypeInfoTools)) {
		   logErr("getTypeInfoGenerated_t: m_idTypeInfoTools is bad ptr returning");
		   return nullptr;
	   }

	   if (!m_idTypeInfoTools->typeInfoGenerated) {
		   logErr("getTypeInfoGenerated_t: m_idTypeInfoTools->typeInfoGenerated is nullptr !");
		   return nullptr;
	   }

	   return m_idTypeInfoTools->typeInfoGenerated;
	   
   }

   classTypeInfo_t* TypeInfoManager::findClassInfo(const char* className) {
	   //logDebug("findClassInfo");

	   if (!className || !className[0]) {
		   logErr("findClassInfo: className is null returning nullptr");
		   return nullptr;
	   }

	   if (MemHelper::isBadReadPtr((void*)m_typeInfoToolsPtrAddr) || MemHelper::isBadReadPtr((void*)m_findClassInfoFuncPtr)) {
		   logErr("findClassInfo: can not execute, m_typeInfoToolsPtr or m_findClassInfoFuncPtr is badptr: m_typeInfoToolsPtr: %p , m_findClassInfoFuncPtr: %p", (void*)m_typeInfoToolsPtrAddr, (void*)m_findClassInfoFuncPtr);
		   return nullptr;
	   }
	   auto findClassInfoFunc = reinterpret_cast<pIdTypeInfoTools_FindClassInfo>(m_findClassInfoFuncPtr);
	   return (classTypeInfo_t*)findClassInfoFunc(*(__int64*)m_typeInfoToolsPtrAddr, className);
   }




//? because this func is mainly used to get an offset and because it's used like this for ex: int buildVersionInfoOffset = findClassField("engine_t", "buildVersionInfo")->offset; ofc it could crash...But it's ok as in a way we want the game to crash if there is an issue finding the field as we don't want a wrong offset, so 'ill leave it like that. (UPDATE AND CRASH IT JUST DID 12/5/24 for cvar system)
 classVariableInfo_t* TypeInfoManager::findClassField(const char* cname, const char* fieldname) {
	   auto playerclass = findClassInfo(cname);
	   if (!playerclass)
		   return nullptr;
	   auto headattr = playerclass->variables;
	   classVariableInfo_t* notarget_field = nullptr;
	   while (headattr && headattr->name) {
		   if (AreStringsEqual(headattr->name, fieldname)) {
			   return headattr;
		   }
		   ++headattr;
	   }
	   return nullptr;
 }

 /* classVariableInfo_t* TypeInfoManager::findClassFirstField(const char* cname) {
	 logDebug("findClassFirstField");
	 auto playerclass = findClassInfo(cname);
	 if (!playerclass)
		 return nullptr;
	 auto headattr = playerclass->variables;
	 if (headattr) {
		 return headattr;
	 }
	 return nullptr;
 }*/

   enumTypeInfo_t* TypeInfoManager::FindEnumInfo(const char* enumName) {
	  logDebug("FindEnumInfo");
	  if (MemHelper::isBadReadPtr((void*)m_typeInfoToolsPtrAddr) || MemHelper::isBadReadPtr((void*)m_findEnumInfoFuncPtr)) {
		  logErr("FindEnumInfo: can not execute, m_typeInfoToolsPtr or m_findEnumInfoFuncPtr is badptr: m_typeInfoToolsPtr: %p , m_findEnumInfoFuncPtr: %p", (void*)m_typeInfoToolsPtrAddr, (void*)m_findEnumInfoFuncPtr);
		  return nullptr;
	  }
	  auto findEnumInfoFunc = reinterpret_cast<pIdTypeInfoTools_FindEnumInfo>(m_findEnumInfoFuncPtr);
	  return (enumTypeInfo_t*)findEnumInfoFunc(*(__int64*)m_typeInfoToolsPtrAddr, enumName);
  }


    std::string TypeInfoManager::getEnumMemberName(const char* enumName, long long enumMemberVal) {
	   auto enumTypeInfo = FindEnumInfo(enumName);
	   if (!enumTypeInfo) {
		   logWarn("getEnumMemberName: failed to find EnumInfo for enumName: %s ", enumName);
		   return std::string();
	   }
	   for (auto eval = enumTypeInfo->values; eval && eval->name && eval->name[0]; eval++) {

		   if (eval->value == enumMemberVal) {
			   return std::string(eval->name);
		   }
	   }
	   return std::string();
   }

	__int64 TypeInfoManager::get_engine_t() {
		int maxEngine_t_VarInfoSeachMs = 60000;
		int debugAttemptCount = 0;

		if (!m_engine_tAddr) {
			if (!m_typeInfoToolsPtrAddr) {
				logErr("get_engine_t: Can not get get engine_t cause m_typeInfoToolsPtrAddr == 0 returning 0");
				return 0;
			}

			logInfo("waiting for typeInfoTools to find engine_t var info...");
			classVariableInfo_t* engine_tVarInfoPtr = findClassField("engine_t", "typeInfoTools");

			uint64_t searchStartMs = K_Utils::EpochMillis();

			while (!engine_tVarInfoPtr)
			{
				engine_tVarInfoPtr = findClassField("engine_t", "typeInfoTools");
				debugAttemptCount++;

				if (K_Utils::EpochMillis() - searchStartMs > maxEngine_t_VarInfoSeachMs) {
					int maxEngine_t_VarInfoSeachSec = maxEngine_t_VarInfoSeachMs / 1000;
					logErr("get_engine_t: TIMEOUT trying to find engine_t var info (%d seconds), mod can not work.", maxEngine_t_VarInfoSeachSec);
					return 0;					
				}
			}

			logInfo("get_engine_t: Succes getting engine_t var info at:  %p", engine_tVarInfoPtr);
			/*if (!engine_tVarInfoPtr) {
				logErr("get_engine_t engine_tVarInfoPtr is nullptr");
				return 0;
			}*/

			int offset = engine_tVarInfoPtr->offset;
			logInfo("get_engine_t: offset form findClassField: 0x%X and m_typeInfoToolsPtr is : %p", offset, (void*)m_typeInfoToolsPtrAddr);
			m_engine_tAddr = m_typeInfoToolsPtrAddr - offset;
			logInfo("get_engine_t: m_engine_tAddr: %p ", (void*)m_engine_tAddr);
		}
		return  m_engine_tAddr;
	}


	void TypeInfoManager::acquirreGameSystemLocalStateOffset() {

		if (m_typeInfoToolsPtrAddr != 0) {

			classVariableInfo_t* IdGameSystemLocalStateVarInfoPtr = findClassField("idGameSystemLocal", "state");
			if (!IdGameSystemLocalStateVarInfoPtr) {
				logErr("acquirreGameSystemLocalStateOffset: IdGameSystemLocalStateVarInfoPtr is nullptr, mod should not be running.");
				return;
			}
			m_cached_IdGameSystemLocalStateOffset = IdGameSystemLocalStateVarInfoPtr->offset;
			logInfo("acquirreGameSystemLocalStateOffset: 0x%X ", m_cached_IdGameSystemLocalStateOffset);
		}
		else {
			logErr("acquirreGameSystemLocalStateOffset: failed to find GameSystemLocal State Offset");
		}
	}



	int TypeInfoManager::getGameSystemLocalStateOffset() {
		if (!m_cached_IdGameSystemLocalStateOffset) {
			acquirreGameSystemLocalStateOffset();
		}
		return m_cached_IdGameSystemLocalStateOffset;
	}


	void TypeInfoManager::acquirreGameSystemLocalMapInstanceOffset() {
		logDebug("acquirreGameSystemLocalMapInstanceOffset");
		if (m_typeInfoToolsPtrAddr != 0) {

			classVariableInfo_t* IdGameSystemLocalMapInstanceVarInfoPtr = findClassField("idGameSystemLocal", "mapInstance");
			if (!IdGameSystemLocalMapInstanceVarInfoPtr) {
				logErr("acquirreGameSystemLocalMapInstanceOffset: IdGameSystemLocalMapInstanceVarInfoPtr is nullptr, mod should not be running.");
				return;
			}

			m_cached_IdGameSystemLocalMapInstanceOffset = IdGameSystemLocalMapInstanceVarInfoPtr->offset;
			logInfo("acquirreGameSystemLocalMapInstanceOffset: 0x%X ", m_cached_IdGameSystemLocalMapInstanceOffset);
		}
		else {
			logErr("acquirreGameSystemLocalMapInstanceOffset: failed to find GameSystemLocal MapInstance Offset");
		}
	}

	int TypeInfoManager::getGameSystemLocalMapInstanceOffset() {
		if (!m_cached_IdGameSystemLocalMapInstanceOffset) {
			acquirreGameSystemLocalMapInstanceOffset();
		}
		return m_cached_IdGameSystemLocalMapInstanceOffset;
	}


	__int64 TypeInfoManager::getCvarSystemPtrAddr() {
		__int64 engine_t = get_engine_t();
		if (engine_t) {
			classVariableInfo_t* cvarSystemForTransferVarInfoPtr = findClassField("engine_t", "cvarSystemForTransfer");
			if (!cvarSystemForTransferVarInfoPtr) {
				logErr("failed to get cvarSystemForTransferVarInfoPtr, mod might crash or not work at all");
				return 0;
			}			

			int cvarSystemOffset = cvarSystemForTransferVarInfoPtr->offset;
			__int64 result = engine_t + cvarSystemOffset;
			logInfo("getCvarSystemPtrAddr: found cvarSystemPtrAddr at: %p", (void*)result);
			return result;
		}
		logErr("getCvarSystemPtrAddr: engine_t is null, returning 0");
		return 0;
	}


	__int64 TypeInfoManager::getCmdSystemPtrAddr() {
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* cmdSystemVarInfoPtr = findClassField("engine_t", "cmdSystemForTransfer");
			if (!cmdSystemVarInfoPtr) {
				logErr("getCmdSystemPtrAddr: failed to get cmdSystemVarInfoPtr, mod should not be running !");
				return 0;
			}

			int cmdSystemOffset = cmdSystemVarInfoPtr->offset;
			__int64 result = engine_t + cmdSystemOffset;
			logInfo("getCmdSystemPtrAddr: found cmdSystemPtrAddr at: %p", (void*)result);
			return result;
		}
		logErr("getCmdSystemPtrAddr: engine_t is null, returning 0");
		return 0;
	}

	__int64 TypeInfoManager::getIdEventDefInterface() {
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* IdEventDefInterfaceVarInfo = findClassField("engine_t", "eventDefInterface");
			if (!IdEventDefInterfaceVarInfo) {
				logErr("getIdEventDefInterface: IdEventDefInterfaceVarInfo is nullptr, mod should not run");
				return 0;
			}

			int IdEventDefInterfaceOffset = IdEventDefInterfaceVarInfo->offset;
			__int64 result = engine_t + IdEventDefInterfaceOffset;
			logInfo("getIdEventDefInterface: found IdEventDefInterfaceAddr at: %p", (void*)result);
			return result;
		}
		logErr("getIdEventDefInterface: engine_t is null, returning 0");
		return 0;
	}

	__int64 TypeInfoManager::getIdBroadcastManager() {
		__int64 engine_t = get_engine_t();
		if (engine_t) {
			classVariableInfo_t* idBroadcastManagerVarInfoPtr = findClassField("engine_t", "broadcastManager");
			if (!idBroadcastManagerVarInfoPtr) {
				logErr("getIdBroadcastManager: idBroadcastManagerVarInfoPtr is nullptr");
				return 0;
			}

			int idBroadcastManagerOffset = idBroadcastManagerVarInfoPtr->offset;
			__int64 result = engine_t + idBroadcastManagerOffset;
			logInfo("getIdBroadcastManager: found result at: %p", (void*)result);
			return result;
		}
		logErr("getIdBroadcastManager: engine_t is null, returning 0");
		return 0;
	}



	__int64 TypeInfoManager::getidEngineVersionInfoPtrAddr() {
		logDebug("getidEngineVersionInfoPtrAddr");
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* engineVersionInfoVarInfo = findClassField("engine_t", "engineVersionInfo");
			if (!engineVersionInfoVarInfo) {
				logErr("getidEngineVersionInfoPtrAddr: engineVersionInfoVarInfo is nullptr");
				return 0;
			}

			int engineVersionInfoOffset = engineVersionInfoVarInfo->offset;
			__int64 result = engine_t + engineVersionInfoOffset;
			logInfo("getidEngineVersionInfoPtrAddr: found idEngineVersionInfoPtrAddr at: %p", (void*)result);
			return result;
		}
		logErr("getidEngineVersionInfoPtrAddr: engine_t is null, returning 0");
		return 0;
	}


	__int64 TypeInfoManager::getWin32VarsAddr() {

		__int64 engine_t = get_engine_t();

		if (engine_t) {

			classVariableInfo_t* Win32VarsVarInfo = findClassField("engine_t", "win32");
			if (!Win32VarsVarInfo) {
				logErr("getWin32VarsAddr: Win32VarsVarInfo is nullptr");
				return 0;
			}

			int Win32VarsVarOffset = Win32VarsVarInfo->offset;
			__int64 result = engine_t + Win32VarsVarOffset;
			logInfo("getWin32VarsAddr: foundWin32VarsAddr at: %p", (void*)result);
			return result;
		}

		logErr("getWin32VarsAddr: engine_t is null, returning 0");
		return 0;
	}


	__int64 TypeInfoManager::getIdBuildVersionInfoPtrAddr() {
		
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* buildVersionInfoVarInfo = findClassField("engine_t", "buildVersionInfo");
			if (!buildVersionInfoVarInfo) {
				logErr("getIdBuildVersionInfoPtrAddr: buildVersionInfoVarInfo is nullptr");
				return 0;
			}

			int buildVersionInfoOffset = buildVersionInfoVarInfo->offset;
			__int64 result = engine_t + buildVersionInfoOffset;
			logInfo("getIdBuildVersionInfoPtrAddr: found IdBuildVersionInfoPtrAddr at: %p", (void*)result);
			return result;
		}
		logErr("getIdBuildVersionInfoPtrAddr: engine_t is null, returning 0");
		return 0;
	}


	__int64 TypeInfoManager::getIdConsoleAddr() {
		logDebug("getIdConsoleAddr");
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* consoleVarInfo = findClassField("engine_t", "console");
			if (!consoleVarInfo) {
				logErr("getIdConsoleAddr: consoleVarInfo is nullptr");
				return 0;
			}

			int consoleOffset = consoleVarInfo->offset;
			__int64 idConsolePtr = engine_t + consoleOffset;
			if (!MemHelper::isBadReadPtr((void*)idConsolePtr)) {
				logInfo("getIdConsoleAddr: found idConsolePtr at: %p", (void*)idConsolePtr);
				__int64 idConsoleLocalAdd = *(__int64*)idConsolePtr;
				if (!MemHelper::isBadReadPtr((void*)idConsoleLocalAdd)) {
					logInfo("getIdConsoleAddr: found idConsoleLocalAdd at: %p", (void*)idConsoleLocalAdd);
					return idConsoleLocalAdd;
				}
			}
		}
		logErr("getIdConsoleAddr: engine_t is null or found bad ptr while searching for idConsoleLocal addr, returning 0");
		return 0;
	}


	__int64 TypeInfoManager::getIdDebugHudAddr() {
		logDebug("getIdDebugHudAddr");
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* debugHudVarInfo = findClassField("engine_t", "debugHUD");
			if (!debugHudVarInfo) {
				logErr("getIdDebugHudAddr : debugHudVarInfo is nullptr");
				return 0;
			}

			int debugHudOffset = debugHudVarInfo->offset;
			__int64 idDebugHudPtr = engine_t + debugHudOffset;
			if (!MemHelper::isBadReadPtr((void*)idDebugHudPtr)) {
				logInfo("getIdDebugHudAddr: found idDebugHudPtr at: %p", (void*)idDebugHudPtr);
				__int64 idDebugHud = *(__int64*)idDebugHudPtr;
				if (!MemHelper::isBadReadPtr((void*)idDebugHud)) {
					logInfo("getIdDebugHudAddr: found idDebugHud at: %p", (void*)idDebugHud);
					return idDebugHud;
				}
			}
		}
		logErr("getIdDebugHudAddr: engine_t is null or found bad ptr while searching for idDebugHud addr, returning 0");
		return 0;
	}





	__int64 TypeInfoManager::getGlobalFontTable() {
		logDebug("getGlobalFontTable");
		__int64 engine_t = get_engine_t();
		if (engine_t) {

			classVariableInfo_t* globalFontTableVarInfo = findClassField("engine_t", "globalFontTable");
			if (!globalFontTableVarInfo) {
				logErr("getGlobalFontTable: globalFontTableVarInfo is nullptr");
				return 0;
			}

			int globalFontTableOffset = globalFontTableVarInfo->offset;
			__int64 globalFontTabletPtr = engine_t + globalFontTableOffset;
			if (!MemHelper::isBadReadPtr((void*)globalFontTabletPtr)) {
				logInfo("getGlobalFontTable: found globalFontTabletPtr at: %p", (void*)globalFontTabletPtr);
				__int64 globalFontTable = *(__int64*)globalFontTabletPtr;
				if (!MemHelper::isBadReadPtr((void*)globalFontTable)) {
					logInfo("getGlobalFontTable: found globalFontTable at: %p", (void*)globalFontTable);
					return globalFontTable;
				}
			}
		}
		logErr("getGlobalFontTable: engine_t is null or found bad ptr while searching for globalFontTable addr, returning 0");
		return 0;
	}


	void TypeInfoManager::debugLog_typeInfoGenerated_t()
	{
		if (!m_idTypeInfoTools) {
			logErr("debugLog_typeInfoGenerated_t: m_idTypeInfoTools is nullptr !");
			return;
		}

		if (!m_idTypeInfoTools->typeInfoGenerated) {
			logErr("debugLog_typeInfoGenerated_t: m_idTypeInfoTools->typeInfoGenerated is nullptr !");
			return;
		}

		logInfo("debugLog_typeInfoGenerated_t: m_idTypeInfoTools->typeInfoGenerated: %p", m_idTypeInfoTools->typeInfoGenerated);
		logInfo("debugLog_typeInfoGenerated_t: m_idTypeInfoTools->typeInfoGenerated->enums: %p", m_idTypeInfoTools->typeInfoGenerated->enums);
		logInfo("debugLog_typeInfoGenerated_t:m_idTypeInfoTools->typeInfoGenerated->numEnums: %d", m_idTypeInfoTools->typeInfoGenerated->numEnums);
		
	}

	//! yiels no result for idMapInsance, idMapInstance_Interface, idMapInstanceLocal
	void  TypeInfoManager::debugListClassFields(const char* cname) {
		logInfo("debugListClassFields: listing class fields for classname: %s", cname);
		auto playerclass = findClassInfo(cname);
		if (!playerclass) {
			logWarn("cound not find any field for classname: %s", cname);
			return;
		}
		auto headattr = playerclass->variables;
		classVariableInfo_t* notarget_field = nullptr;
		while (headattr && headattr->name) {
			logInfo(headattr->name);
			++headattr;
		}
	}


	//void TypeInfoManager::debugPrintOffsets() {
	//	int iplayer_Hud_Offset = findClassField("idPlayer", "playerHud")->offset;
	//	logInfo("debugPrintOffsets: playerHud_Offset: %d", iplayer_Hud_Offset);
	//	int idPlayer_wantZoom_Offset = findClassField("idPlayer", "wantZoom")->offset;
	//	logInfo("debugPrintOffsets: idPlayer_wantZoom_Offset: %d", idPlayer_wantZoom_Offset);
	//	int idHUD_elements_Offset = findClassField("idHUD", "elements")->offset;
	//	logInfo("debugPrintOffsets: idHUD_elements_Offset: %d", idHUD_elements_Offset);
	//	int idHUD_pauseMenuIndex_Offset = findClassField("idHUD", "pauseMenuIndex")->offset;
	//	logInfo("debugPrintOffsets: idHUD_pauseMenuIndex_Offset: %d", idHUD_pauseMenuIndex_Offset);
	//}








	//! keeping this cause it caused a lot of mental pain and shows what a noob i am.
	__int64 TypeInfoManager::get_engine_t_EducationalEdition() {
		logDebug("get_engine_t_EducationalEdition");
		if (m_engine_tAddr == 0 && m_typeInfoToolsPtrAddr != 0) {
			int offset = findClassField("engine_t", "typeInfoTools")->offset;
			//int offsetInt = findClassField("engine_t", "typeInfoTools")->offset;		
			logInfo("get_engine_t: offset form findClassField: 0x%X and m_typeInfoToolsPtr is : %p", offset, (void*)m_typeInfoToolsPtrAddr);
			//logInfo("get_engine_t: offsetInt:  0x%X and m_typeInfoToolsPtr is : %p", offsetInt, m_typeInfoToolsPtr);
			//logInfo("get_engine_t: offsetInt: 0x%X", offsetInt);
			//logInfo("get_engine_t: m_typeInfoToolsAsAnInt64_Test: %p", (void*)m_typeInfoToolsAsAnInt64_Test);

			//? leaving this here so i never forget, and the log below. here engine_t_0_Ptr and engine_t_3 are wrong and all this is tied to pointer arithmetic. Basically just keep in mind that by m_typeInfoTools be a char pointer you know that adding 1 to it will move its addr by one, but a __int64 ptr of course adding 1 to it will move the address by 8 and that the offset is indicated the amount of bytes the new address should be. just to be clear the issues we had were nor related to the offset being an int or a int64. The reason why we didn't have much issues before when adding offsets to addresses is because we were doing arithmetic wit ADDRESSES and not POINTERS, THESE ARE 2 VERY DIFFERENT THINGS.


		/*	__int64* engine_t_0_Ptr = m_typeInfoToolsPtr - offset;
			__int64 engine_t_1 = (__int64)m_typeInfoToolsPtr - (__int64)offset;
			__int64 engine_t_2 = (__int64)m_typeInfoToolsPtr - offset;
			__int64 engine_t_3 = (__int64)(m_typeInfoToolsPtr - offset);
			__int64 engine_t_4 = (__int64)(m_typeInfoToolsCharPtr - offset);
			__int64 engine_t_5 = (__int64)m_typeInfoToolsCharPtr - offset;*/

			/*01:55 : 23.230       TypeInfoManager.h : 232   INFO | get_engine_t : offset : 0x120 and m_typeInfoToolsPtr is : 00007FF73F38EBA0
				01 : 55 : 23.230       TypeInfoManager.h : 246   INFO | get_engine_t : engine_t_0_Ptr : 00007FF73F38E2A0
				01 : 55 : 23.230       TypeInfoManager.h : 247   INFO | get_engine_t : engine_t_1 : 00007FF73F38EA80
				01 : 55 : 23.231       TypeInfoManager.h : 248   INFO | get_engine_t : engine_t_2 : 00007FF73F38EA80
				01 : 55 : 23.231       TypeInfoManager.h : 249   INFO | get_engine_t : engine_t_3 : 00007FF73F38E2A0
				01 : 55 : 23.231       TypeInfoManager.h : 250   INFO | get_engine_t : engine_t_4 : 00007FF73F38EA80
				01 : 55 : 23.232       TypeInfoManager.h : 251   INFO | get_engine_t : engine_t_5 : 00007FF73F38EA80*/

				/*	logInfo("get_engine_t: engine_t_0_Ptr: %p ", engine_t_0_Ptr); // wrong
					logInfo("get_engine_t: engine_t_1: %p ", (void*)engine_t_1); // good
					logInfo("get_engine_t: engine_t_2: %p ", (void*)engine_t_2); // good
					logInfo("get_engine_t: engine_t_3: %p ", (void*)engine_t_3); // wrong
					logInfo("get_engine_t: engine_t_4: %p ", (void*)engine_t_4); // good
					logInfo("get_engine_t: engine_t_5: %p ", (void*)engine_t_5);*/ // good


			m_engine_tAddr = m_typeInfoToolsPtrAddr - offset;
			logInfo("get_engine_t: m_engine_tAddr: %p ", (void*)m_engine_tAddr);
			return m_engine_tAddr;

			/*if (!MemHelper::isBadReadPtr((void*)m_engine_tAddr)) {
				return *(__int64*)m_engine_tAddr;
			}*/
			//logInfo("get_engine_t: m_engine_t: %p ", (void*)m_engine_t);
			//logInfo("get_engine_t: m_engine_t: %p", (void*)m_engine_t);
		}

		return 0;
	}