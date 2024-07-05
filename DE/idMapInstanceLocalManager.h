#pragma once
#include "MemHelper.h"
#include "TypeInfoManager.h"
#include "GeneratedClasses.h"
#include "idCmd.h"
#include "fastCvarManager.h"



//! Also called gameLocal but using idMapInstance so there is less potential confusion with idGameSystemLocal 

class idMapInstanceLocalManager {


private:



	static inline __int64 m_idGameSystemLocalAdrr = 0;
	static inline int m_idGameSystemLocalMapInstanceOffset = 0;	
	static inline __int64 m_idMapInstanceLocalPtr = 0;


	static inline char* m_lastIdPlayerCharPtr = nullptr;
	//static inline int m_getIdPlayer_1_Offset = 0;  //! hard coded value in code we get with scan
	static inline const __int64 m_undocumentedIdGameTimeManagerLocalOffset = UndocumentedOffsets::IdGameTimeManagerLocalOffset;//ida: GetGameMs_D06DD0



public:

	static bool acquirreIdGameSystemLocalPtrAdrr(__int64 idGameSystemLocalPtrAdrr);

	static __int64 getIdMapInstanceLocalPtr();


	//! this is used to find idPlayer ptr offset in GameLocal
	//! ida: return idPlayer::CastTo_2125F50(*(_QWORD *)(idGameLocal_a1 + 8i64 * a2 + 0x1AF8));
	//static bool acquireIdPlayerOffsetInstructionAddr(uintptr_t OffsetAddr);


	//static char* getIdPlayerCharPtr();
	
	/*static idPlayer_t* getIdPlayerPtr() {
		logDebug("getIdPlayerPtr");
		idPlayer_t* idPlayer = nullptr;

		__int64 currentidMapInstanceLocalPtr = getComputedCurrentIdMapInstanceLocalPtr();
		if (MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
			logWarn("getIdPlayerPtr: could not find idPlayer cause currentidMapInstanceLocalPtr is bad ptr: %p", (void*)currentidMapInstanceLocalPtr);
			return idPlayer;			
		}
		if (!m_getIdPlayer_1_Offset) {
			logWarn("getIdPlayerPtr: could not find idPlayer cause m_getIdPlayer_1_Offset == 0 ");
			return idPlayer;
		}
		__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr;
		if (MemHelper::isBadReadPtr((void*)idMapInstanceLocal)) {
			logWarn("getIdPlayerPtr: idMapInstanceLocal is bad ptr: %p returning", (void*)idMapInstanceLocal);
			return idPlayer;
		}
		__int64* idPlayerPtrAddr = (__int64*)(idMapInstanceLocal + m_getIdPlayer_1_Offset);
		if (MemHelper::isBadReadPtr(idPlayerPtrAddr)) {
			logWarn("getIdPlayerPtr: idPlayerPtrAddr is bad ptr: %p may be map is not loaded yet or player in main menu (?)", idPlayerPtrAddr);
			return idPlayer;
		}		
		idPlayer = (idPlayer_t*)*(__int64*)idPlayerPtrAddr;
		if (m_lastIdPlayer_t != idPlayer) {
			m_lastIdPlayer_t = idPlayer;
			logInfo("getIdPlayerPtr: idPlayer has changed to:  %p (idPlayerPtr: %p)", idPlayer, idPlayerPtrAddr);
		}
		return idPlayer;
	}*/


	static idPlayer* getIdPlayer();


	static void debugPrintCurrentIdMapInstanceLocal();

	static long long getGameTime_t();



	/*static idPlayer_t* getIdPlayerPtr() {		
		__int64 currentidMapInstanceLocalPtr = getComputedCurrentIdMapInstanceLocalPtr();
		if (MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
			logWarn("getIdPlayerPtr: could not find idPlayer cause currentidMapInstanceLocalPtr is bad ptr: %p", (void*)currentidMapInstanceLocalPtr);
			return 0;
		}
		if (!m_getIdPlayer_1_Offset) {
			logWarn("getIdPlayerPtr: could not find idPlayer cause m_getIdPlayer_1_Offset == 0 ");
			return 0;
		}
		__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr; 
		__int64* idPlayerPtr = (__int64*)(idMapInstanceLocal + m_getIdPlayer_1_Offset);
		if (MemHelper::isBadReadPtr(idPlayerPtr)) {
			logWarn("getIdPlayerPtr: idPlayerPtr is bad ptr: %p may be map is not loaded yet or player in main menu (?)", idPlayerPtr);
			return 0;
		}
		else {
			idPlayer_t* idPlayer = (idPlayer_t*)*(__int64*)idPlayerPtr;
			logInfo("getIdPlayerPtr: succes getting idPlayerPtr %p and idPlayer:  %p", idPlayerPtr, idPlayer);
			return idPlayer;
		}

	}*/

	//! we're only (so far) insterested in player1 (local player)
	//? we assume we will always and only get player at index 0 which i assume is player1. Checking in CE a2 which is the player index is 0.
	//static idPlayer_t* debugGetIdPlayerPtr() {
	//	/*__int64 __fastcall idGameLocal__GetPlayer_D1F580(__int64 idGameLocal_a1, int a2)
	//	{
	//	  if ( (unsigned int)a2 > 0xB )
	//		return 0i64;
	//	  else
	//		return idPlayer::CastTo_2125F50(*(_QWORD *)(idGameLocal_a1 + 8i64 * a2 + 0x1AF8));
	//	}*/
	//	__int64 currentidMapInstanceLocalPtr = getComputedCurrentIdMapInstanceLocalPtr();
	//	if (MemHelper::isBadReadPtr((void*)currentidMapInstanceLocalPtr)) {
	//		logWarn("debugGetIdPlayerPtr: could not find idPlayer cause currentidMapInstanceLocalPtr is bad ptr: %p", (void*)currentidMapInstanceLocalPtr);
	//		return 0;
	//	}
	//	if (!m_getIdPlayer_1_Offset) {
	//		logWarn("debugGetIdPlayerPtr: could not find idPlayer cause m_getIdPlayer_1_Offset == 0 ");
	//		return 0;
	//	}		

	//	__int64 idMapInstanceLocal = *(__int64*)currentidMapInstanceLocalPtr; // modified what is below to this but it should work. . .		
	//	//__int64 gameLocal = *(__int64*)m_gameLocalPtr; //! this works			
	//	//__int64* idPlayerPtr = (__int64*)(gameLocal + 8 + m_getIdPlayer_1_Offset);
	//	__int64* idPlayerPtr = (__int64*)(idMapInstanceLocal + m_getIdPlayer_1_Offset);
	//	if (MemHelper::isBadReadPtr(idPlayerPtr)) {
	//		logWarn("debugGetIdPlayerPtr: idPlayerPtr is bad ptr: %p may be map is not loaded yet or player in main menu (?)", idPlayerPtr);
	//		return 0;
	//	}
	//	else {
	//		idPlayer_t* idPlayer = (idPlayer_t*)*(__int64*)idPlayerPtr;
	//		logInfo("debugGetIdPlayerPtr: succes getting idPlayerPtr %p and idPlayer:  %p", idPlayerPtr, idPlayer);
	//		return idPlayer;
	//	}

	//}


	static void* findEntity(const char* name);

	//! this could potentially be slow or slower than the alternative GetPlayer method
	static void* getIdPlayer_1_WithEntityFinder();



};


