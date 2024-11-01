#include "idMapInstanceLocalManager.h"

 bool idMapInstanceLocalManager::acquirreIdGameSystemLocalPtrAdrr(__int64 idGameSystemLocalPtrAdrr) {
	if (MemHelper::isBadReadPtr((void*)idGameSystemLocalPtrAdrr)) {
		return false;
	}
	m_idGameSystemLocalAdrr = idGameSystemLocalPtrAdrr;
	logInfo("acquirreIdGameSystemLocalPtrAdrr: m_idGameSystemLocalAdrr set to %p", (void*)m_idGameSystemLocalAdrr);
	return true;
 }


 __int64 idMapInstanceLocalManager::getIdMapInstanceLocalPtP() {

	if (m_idMapInstanceLocalPtP) { //! this is going to be true 99% of the time.
		 return m_idMapInstanceLocalPtP;
    }

	if (!m_idGameSystemLocalMapInstanceOffset) {
		m_idGameSystemLocalMapInstanceOffset = TypeInfoManager::getGameSystemLocalMapInstanceOffset();
		logInfo("getIdMapInstanceLocalPtP: m_idGameSystemLocalMapInstanceOffset is being set to: 0x%X", m_idGameSystemLocalMapInstanceOffset);
	}
	//int idMapInstanceOffset = TypeInfoManager::getGameSystemLocalMapInstanceOffset();
	//! we could just check for !0 here (?)
	if (!m_idGameSystemLocalAdrr) {
	//if (MemHelper::isBadReadPtr((void*)m_idGameSystemLocalAdrr)) {
		logErr("getIdMapInstanceLocalPtP: failed to compute currentIdMapInstanceLocalPtr cause idGameSystemLocalPtrAdrr null");
	}
	else if (!m_idGameSystemLocalMapInstanceOffset) {
		logErr("getIdMapInstanceLocalPtP: failed to compute currentIdMapInstanceLocalPtr cause m_idGameSystemLocalMapInstanceOffset == 0");
	}
	else {
		m_idMapInstanceLocalPtP = m_idGameSystemLocalAdrr + m_idGameSystemLocalMapInstanceOffset;
		//__int64 currentIdMapInstanceLocalPtr = m_idGameSystemLocalAdrr + m_idGameSystemLocalMapInstanceOffset;
		return  m_idMapInstanceLocalPtP;
		//return currentIdMapInstanceLocalPtr;
	}
	return 0;
 }

 __int64 idMapInstanceLocalManager::getIdMapInstanceLocal() {

	 __int64 currentidMapInstanceLocalPtP = getIdMapInstanceLocalPtP();
	 if (!currentidMapInstanceLocalPtP) {
		 logErr("getIdMapInstanceLocal: currentidMapInstanceLocalPtP is null");
		 return 0;
	 }

	 __int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtP;
	 if (MemHelper::isBadReadPtr((void*)idMapInstanceLocal)) {
		 logWarn("getIdMapInstanceLocal: idMapInstanceLocal is bad ptr: %p returning 0", (void*)idMapInstanceLocal);
		 return 0;
	 }

	 return idMapInstanceLocal;
 }


 
 bool idMapInstanceLocalManager::acquireIdGlobalEncounterManagerOffset(__int64 addr)
 {
	 if (MemHelper::isBadReadPtr((void*)addr)) {
		 logErr("acquireIdGlobalEncounterManagerOffset: addr is bad ptr: %p", (void*)addr);
		 return false;
	 }
	 m_idGlobalEncounterManager_Offset = *(int*)addr;
	 if (m_idGlobalEncounterManager_Offset <= 0) {
		 logErr("acquireIdGlobalEncounterManagerOffset:m_idGlobalEncounterManager_Offset is <= 0: %d (dec) this is wrong.", m_idGlobalEncounterManager_Offset);
		 m_idGlobalEncounterManager_Offset = 0;
		 return false;
	 }
	 logInfo("acquireIdGlobalEncounterManagerOffset: m_idGlobalEncounterManager_Offset set to: 0x%X", m_idGlobalEncounterManager_Offset);
	 return true;	
 }




 //todo refactor
 std::string idMapInstanceLocalManager::getCurrentMapNameStr()
 {
	 if (!m_getCurrentMapNameFp) {

		 logInfo("getCurrentMapNameStr: m_idMapInstanceLocalPtP: %p", (void*)m_idMapInstanceLocalPtP);
		 if (!m_idMapInstanceLocalPtP) {
			 logErr("getCurrentMapNameStr: m_idMapInstanceLocalPtP is null");
			 return std::string();
		 }

		 __int64 idMapInstanceLocalAddr = *(__int64*)m_idMapInstanceLocalPtP;
		 if (!idMapInstanceLocalAddr) {
			 logErr("getCurrentMapNameStr: idMapInstanceLocalAddr is null");
			 return std::string();
		 }

		 __int64 idMapInstanceLocalAddrVtb = *(__int64*)idMapInstanceLocalAddr;
		 if (!idMapInstanceLocalAddrVtb) {
			 logErr("getCurrentMapNameStr: idMapInstanceLocalAddrVtb is null");
			 return std::string();
		 }

		 __int64 getCurrentMapNameFPtP = idMapInstanceLocalAddrVtb + GameOffsets::IdMapInstanceVtb_GetCurrentMapName;
		 if (!getCurrentMapNameFPtP) {
			 logErr("getCurrentMapNameStr: getCurrentMapNameFPtP is null");
			 return std::string();
		 }

		 m_getCurrentMapNameFp = (idMapInstance_getCurrentMapNameFp) * (__int64*)getCurrentMapNameFPtP;
		 logInfo("getCurrentMapNameStr: m_getCurrentMapNameFp is being set to: %p", (void*)m_getCurrentMapNameFp);
	 }

	 if (!m_getCurrentMapNameFp) {
		 logErr("getCurrentMapNameStr: failed to acquire m_getCurrentMapNameFp can not get data");
		 return std::string();
	 }	 

	 __int64 idMapInstanceLocal = getIdMapInstanceLocal();
	 if (!idMapInstanceLocal) {
		 return  std::string();
	 }

	 std::string curMapName = m_getCurrentMapNameFp(idMapInstanceLocal);
	 //logInfo("getCurrentMapNameStr: curMapName %s", curMapName.c_str());
	 return curMapName;
	
 }



 idGlobalEncounterManager* idMapInstanceLocalManager::getidMapInstanceLocalManagerPtr() {
	 __int64 idMapInstanceLocal = getIdMapInstanceLocal();
	 if (!idMapInstanceLocal) {
		 logWarn("isEncounterActive: idMapInstanceLocal is null returning true to prevent issues.");
		 return  nullptr;
	 }

	 //! mod should would have closed if m_idGlobalEncounterManager_Offset is not valid so this should be safe
	 idGlobalEncounterManager* globalEncounterManager =  (idGlobalEncounterManager * )(idMapInstanceLocal + m_idGlobalEncounterManager_Offset);
	 if (MemHelper::isBadReadPtr((void*)globalEncounterManager)) {
		 logWarn("isEncounterActive: globalEncounterManager is bad ptr ");
		 return nullptr;
	 }

	 return globalEncounterManager;
 }
 
 int idMapInstanceLocalManager::getCurrentGlobalEncounterID() {

	 idGlobalEncounterManager* manager = getidMapInstanceLocalManagerPtr();
	 if (!manager) {
		 //! if there is an error we let the system think there is an encounter (at least this will work for the player faster in hub mod system)
		 return m_globalEncounterID_ERROR;
	 }

	 return manager->currentGlobalEncounterID;
 }


 //! looks like in a level the currentGlobalEncounterID values start a 0 and up, for ex in the dlc1 first level the first id is 0 and that threw me off a bit cause i thought the system didnt work.
 bool idMapInstanceLocalManager::isEncounterActive() {	 

	 return (getCurrentGlobalEncounterID() != m_globalEncounterID_None);
 }



 std::string idMapInstanceLocalManager::getDbgStrForImgui() {

	 __int64 mapInstanceLocal = getIdMapInstanceLocal();
	 std::string resultStr = "idMapInstanceLocal DBG: IdMapInstanceLocal: ";
	 resultStr += K_Utils::ptrToHexString((void*)mapInstanceLocal) + "\n";;

	 resultStr += "\t";
	 resultStr += "Current map: ";
	 resultStr += getCurrentMapNameStr();
	 resultStr += "\n";

	 resultStr += "\t";

	 idGlobalEncounterManager* globalEncounterManager = getidMapInstanceLocalManagerPtr();
	 if (!globalEncounterManager) {
		 resultStr += "globalEncounterManager is NULL PTR !\n";
	 }
	 else {
		 resultStr += "globalEncounterManager ptr: " + K_Utils::ptrToHexString(globalEncounterManager);
		 resultStr += " currentGlobalEncounterID: " + std::to_string(globalEncounterManager->currentGlobalEncounterID);
		 resultStr += "\n";
	 }
		 
	/* resultStr += "Encounter is Active (Ai is spawned in level)";

	 if (isEncounterActive()) {
		 resultStr += "Encounter is Active (Ai is spawned in level)";
	 }
	 else {
		 resultStr += "NO Encounter Active (No Ai is spawned in level)";
	 }
	 resultStr += "\n";*/

	
	 return resultStr;
 }


//! this is used to find idPlayer ptr offset in GameLocal
//! ida: return idPlayer::CastTo_2125F50(*(_QWORD *)(idGameLocal_a1 + 8i64 * a2 + 0x1AF8));
 //? using a static ptr for now, if game gets updated we'll just have to find it again.
 /*bool idMapInstanceLocalManager::acquireIdPlayerOffsetInstructionAddr(uintptr_t OffsetAddr) {
	logDebug("acquireIdPlayerOffsetInstructionAddr");
	if (OffsetAddr) {
		m_getIdPlayer_1_Offset = *(int*)OffsetAddr;
		logInfo("idMapInstanceLocalManager: acquiring IdPlayer_1_Offset: 0x%X", m_getIdPlayer_1_Offset);
		return true;
	}
	else {
		logErr("idMapInstanceLocalManager: Failed to acquire IdPlayerOffset cause OffsetAddr is null: mod can not work");
		return false;
	}
}*/


 idPlayer* idMapInstanceLocalManager::getIdPlayer() {
	static bool isFirstTime = true;
	static  idPlayer* lastIdPlayer = nullptr;
	idPlayer* IdPlayer = nullptr;

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtP();
	if (!currentidMapInstanceLocalPtr) {
		logErr("getIdPlayer: currentidMapInstanceLocalPtr is null ptr something is VERY Wrong mod should not be running ");
		return nullptr;
	}
	
	/*if (!m_getIdPlayer_1_Offset) {
		logWarn("getIdPlayer: could not find idPlayer cause m_getIdPlayer_1_Offset == 0 ");
		return nullptr;
	}*/
	__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr;
	if (MemHelper::isBadReadPtr((void*)idMapInstanceLocal)) {
		logWarn("getIdPlayer: idMapInstanceLocal is bad ptr: %p returning", (void*)idMapInstanceLocal);
		return nullptr;
	}
	__int64* idPlayerPtrAddr = (__int64*)(idMapInstanceLocal + GameOffsets::IdPlayer_1_Offset);
	if (MemHelper::isBadReadPtr(idPlayerPtrAddr)) {
		logWarn("getIdPlayer: idPlayerPtrAddr is bad ptr: %p may be map is not loaded yet or player in main menu (?)", idPlayerPtrAddr);
		return nullptr;
	}

	IdPlayer = (idPlayer*)*(__int64*)idPlayerPtrAddr;

	if (isFirstTime) {
		logInfo("getIdPlayer: (first get) idPlayer: %p (idPlayerPtrAddr: %p)", IdPlayer, idPlayerPtrAddr);
		lastIdPlayer = IdPlayer;
		isFirstTime = false;
	}
	else if (lastIdPlayer != IdPlayer) {
		lastIdPlayer = IdPlayer;
		logInfo("getIdPlayer: idPlayer has changed to:  %p (idPlayerPtrAddr: %p)", IdPlayer, idPlayerPtrAddr);
	}
	return IdPlayer;
}

 void idMapInstanceLocalManager::debugPrintCurrentIdMapInstanceLocal() {
	logDebug("debugPrintCurrentIdMapInstanceLocal");
	idPlayer* idPlayerObj = nullptr;

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtP();
	if (MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
		logWarn("debugPrintCurrentIdMapInstanceLocal: could not find idPlayer cause currentidMapInstanceLocalPtr is bad ptr: %p", (void*)currentidMapInstanceLocalPtr);
		return;
	}
	__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr;
	if (MemHelper::isBadReadPtr((void*)idMapInstanceLocal)) {
		logWarn("debugPrintCurrentIdMapInstanceLocal: idMapInstanceLocal is bad ptr: %p returning", (void*)idMapInstanceLocal);
		return;
	}
	logInfo("debugPrintCurrentIdMapInstanceLocal: idMapInstanceLocal: %p", (void*)idMapInstanceLocal);

}

 long long idMapInstanceLocalManager::getGameTime_t() {

	int a3 = 1; //! afaik it's always 1

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtP();
	if (MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
		logWarn("getGameTime_t: could not find idPlayer cause currentidMapInstanceLocalPtr is bad ptr: %p", (void*)currentidMapInstanceLocalPtr);
		return 0;
	}
	__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr;
	__int64 gameTimeManagerLocalPtr = idMapInstanceLocal + m_undocumentedIdGameTimeManagerLocalOffset;
	auto v3 = *(__int64*)(gameTimeManagerLocalPtr + 0x10);
	//if (idCmd::isGameTimeScalingEnabled()) {
	if (fastCvarManager::isGameTimeScalingEnabled()) {
		return *(__int64*)(v3 + 0x48i64 * a3 + 0x18);
	}
	else {
		return *(__int64*)(v3 + 0x18);
	}
	/*if (*((_DWORD*)g_enableGameTimeScaling_6B13240 + 2))
	*a2 = *(_QWORD*)(v3 + 0x48i64 * a3 + 0x18);
	else
	*a2 = *(_QWORD*)(v3 + 0x18);
	return a2;*/
}

 void* idMapInstanceLocalManager::findEntity(const char* name) {

	_int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtP();
	if (!MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
		__int64 idMapInstanceLocalAddr = *(__int64*)currentidMapInstanceLocalPtr;

		//void* gamloc = (void*)m_idGameLocalAddr; <= This crashes
		void* gamloc = (void*)idMapInstanceLocalAddr;

		void* vftbl = reinterpret_cast<void**>(gamloc)[0];

		void* findentity_func = (((char*)vftbl) + 0x78);
		findentity_func = *(void**)findentity_func;

		return reinterpret_cast<void* (*)(void*, const char*)>(findentity_func)(gamloc, name);
	}
	else {
		logWarn("findEntity: could not find entity: %s cause currentidMapInstanceLocalPtr is bad ptr", name);
	}
	return nullptr;
}

//! this could potentially be slow or slower than the alternative GetPlayer method

 void* idMapInstanceLocalManager::getIdPlayer_1_WithEntityFinder() {
	logDebug("getIdPlayer_1_WithEntityFinder");
	return findEntity("player1");
}


 /*bool idMapInstanceLocalManager::acquireAiCountPtrOffset(__int64 addr)
{
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquireAiCountPtrOffset: addr is bad ptr: %p", (void*)addr);
		return false;
	}

	m_AiCountPtr_Offset = *(int*)addr;
	logInfo("acquireAiCountPtrOffset: m_AiCountPtr_Offset set to: 0x%X", m_AiCountPtr_Offset);
	return true;
}*/


//bool idMapInstanceLocalManager::isAnyAiAliveInLevel() {

   // if (m_AiCountPtr_Offset <= 0) {
   //	 logErr("isAnyAiAliveInLevel m_AiCountPtr_Offset is <= 0 returning true to prevent player speed issues...");
   //	 return true;
   // }

   // __int64 idMapInstanceLocal = getIdMapInstanceLocal();
   // if (!idMapInstanceLocal) {
   //	 logErr("isAnyAiAliveInLevel idMapInstanceLocal is null returnin true");
   //	 return true;
   // }

   // __int64 aiEntitiesListPtP = idMapInstanceLocal + m_AiCountPtr_Offset;
   // logInfo("isAnyAiAliveInLevel: aiEntitiesListPtP: %p", (void*)aiEntitiesListPtP);

   // if (MemHelper::isBadReadPtr((void*)aiEntitiesListPtP)) {
   //	 logErr("isAnyAiAliveInLevel aiEntitiesListPtP is null returnin true");
   //	 return true;
   // }

   // idList* aiEntitiesIdList = (idList*) (*(__int64*)aiEntitiesListPtP);
   // if (!aiEntitiesIdList) {
   //	 logErr("isAnyAiAliveInLevel aiEntitiesIdList is null returnin true");
   //	 return true;	 
   // }

   // logInfo("isAnyAiAliveInLevel: cur spawned AI is: %d", aiEntitiesIdList->num);

   // //todo get rid of this:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   // return true;

//}
