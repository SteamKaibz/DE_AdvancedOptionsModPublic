#include "idMapInstanceLocalManager.h"

 bool idMapInstanceLocalManager::acquirreIdGameSystemLocalPtrAdrr(__int64 idGameSystemLocalPtrAdrr) {
	if (MemHelper::isBadReadPtr((void*)idGameSystemLocalPtrAdrr)) {
		return false;
	}
	m_idGameSystemLocalAdrr = idGameSystemLocalPtrAdrr;
	logInfo("acquirreIdGameSystemLocalPtrAdrr: m_idGameSystemLocalAdrr set to %p", (void*)m_idGameSystemLocalAdrr);
	return true;
}

 __int64 idMapInstanceLocalManager::getIdMapInstanceLocalPtr() {

	if (m_idMapInstanceLocalPtr) { //! this is going to be true 99% of the time.
		 return m_idMapInstanceLocalPtr;
    }

	if (!m_idGameSystemLocalMapInstanceOffset) {
		m_idGameSystemLocalMapInstanceOffset = TypeInfoManager::getGameSystemLocalMapInstanceOffset();
		logInfo("getIdMapInstanceLocalPtr: m_idGameSystemLocalMapInstanceOffset is being set to: 0x%X", m_idGameSystemLocalMapInstanceOffset);
	}
	//int idMapInstanceOffset = TypeInfoManager::getGameSystemLocalMapInstanceOffset();
	//! we could just check for !0 here (?)
	if (!m_idGameSystemLocalAdrr) {
	//if (MemHelper::isBadReadPtr((void*)m_idGameSystemLocalAdrr)) {
		logErr("getIdMapInstanceLocalPtr: failed to compute currentIdMapInstanceLocalPtr cause idGameSystemLocalPtrAdrr null");
	}
	else if (!m_idGameSystemLocalMapInstanceOffset) {
		logErr("getIdMapInstanceLocalPtr: failed to compute currentIdMapInstanceLocalPtr cause m_idGameSystemLocalMapInstanceOffset == 0");
	}
	else {
		m_idMapInstanceLocalPtr = m_idGameSystemLocalAdrr + m_idGameSystemLocalMapInstanceOffset;
		//__int64 currentIdMapInstanceLocalPtr = m_idGameSystemLocalAdrr + m_idGameSystemLocalMapInstanceOffset;
		return  m_idMapInstanceLocalPtr;
		//return currentIdMapInstanceLocalPtr;
	}
	return 0;
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

 /*char* idMapInstanceLocalManager::getIdPlayerCharPtr() {
	logDebug("getIdPlayerCharPtr");
	char* idPlayerCharPtr = nullptr;

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtr();
	if (MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
		logWarn("getIdPlayerCharPtr: could not find idPlayer cause currentidMapInstanceLocalPtr is bad ptr: %p", (void*)currentidMapInstanceLocalPtr);
		return idPlayerCharPtr;
	}
	if (!m_getIdPlayer_1_Offset) {
		logErr("getIdPlayerCharPtr: could not find idPlayer cause m_getIdPlayer_1_Offset == 0 ");
		return nullptr;
	}
	__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr;
	if (MemHelper::isBadReadPtr((void*)idMapInstanceLocal)) {
		logWarn("getIdPlayerCharPtr: idMapInstanceLocal is bad ptr: %p returning", (void*)idMapInstanceLocal);
		return idPlayerCharPtr;
	}
	__int64* idPlayerPtrAddr = (__int64*)(idMapInstanceLocal + m_getIdPlayer_1_Offset);
	if (MemHelper::isBadReadPtr(idPlayerPtrAddr)) {
		logWarn("getIdPlayerCharPtr: idPlayerPtrAddr is bad ptr: %p may be map is not loaded yet or player in main menu (?)", idPlayerPtrAddr);
		return idPlayerCharPtr;
	}
	idPlayerCharPtr = (char*)*(__int64*)idPlayerPtrAddr;
	if (m_lastIdPlayerCharPtr != idPlayerCharPtr) {
		m_lastIdPlayerCharPtr = idPlayerCharPtr;
		logInfo("getIdPlayerCharPtr: idPlayerCharPtr has changed to:  %p (idPlayerPtrAddr: %p)", idPlayerCharPtr, idPlayerPtrAddr);
	}
	return idPlayerCharPtr;
}*/

 idPlayer* idMapInstanceLocalManager::getIdPlayer() {
	static bool isFirstTime = true;
	static  idPlayer* lastIdPlayer = nullptr;
	idPlayer* IdPlayer = nullptr;

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtr();
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
	__int64* idPlayerPtrAddr = (__int64*)(idMapInstanceLocal + UndocumentedOffsets::IdPlayer_1_Offset);
	if (MemHelper::isBadReadPtr(idPlayerPtrAddr)) {
		logWarn("getIdPlayer: idPlayerPtrAddr is bad ptr: %p may be map is not loaded yet or player in main menu (?)", idPlayerPtrAddr);
		return nullptr;
	}

	IdPlayer = (idPlayer*)*(__int64*)idPlayerPtrAddr;

	if (isFirstTime) {
		logInfo("getIdPlayer: (first get) idPlayer: %p (idPlayerPtr: %p)", IdPlayer, idPlayerPtrAddr);
		lastIdPlayer = IdPlayer;
		isFirstTime = false;
	}
	else if (lastIdPlayer != IdPlayer) {
		lastIdPlayer = IdPlayer;
		logInfo("getIdPlayer: idPlayer has changed to:  %p (idPlayerPtr: %p)", IdPlayer, idPlayerPtrAddr);
	}
	return IdPlayer;
}

 void idMapInstanceLocalManager::debugPrintCurrentIdMapInstanceLocal() {
	logDebug("debugPrintCurrentIdMapInstanceLocal");
	idPlayer* idPlayerObj = nullptr;

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtr();
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

	__int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtr();
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

	_int64 currentidMapInstanceLocalPtr = getIdMapInstanceLocalPtr();
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
