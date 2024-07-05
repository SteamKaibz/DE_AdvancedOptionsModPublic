#include "playerSoundManager.h"


void playerSoundManager::playOutOfItemSound()
{
	idPlayer* playerPtr = idMapInstanceLocalManager::getIdPlayer();

	if (!playerPtr || !playerPtr->playerProps) return ;

	if (!m_playSoundFp) {

		__int64 vtbPtr = *(__int64*)playerPtr;
		__int64 playSoundPtrToFAdd = vtbPtr + UndocumentedOffsets::idPlayerPlaySoundVtbOffset;
		__int64 FAdd = *(__int64*)playSoundPtrToFAdd;
		m_playSoundFp = (idPlayerPlaySoundEventFp)FAdd;
		if (MemHelper::isBadReadPtr(m_playSoundFp)) {
			logErr("playOutOfItemSound: failed to acquire m_playSoundFp");
			m_playSoundFp = nullptr;
			return;
		}
	}

	idSoundEvent* soundEventPtr = (idSoundEvent *) playerPtr->playerProps->sounds.sndOutOfItems;
	logInfo("playOutOfItemSound: debug found soundEventPtr: %p", soundEventPtr);
	m_playSoundFp(playerPtr, soundEventPtr);

}


//void* playerSoundManager::getVtablePointer(idDeclPlayerProps* instance) {
//    // Cast the pointer to a pointer to a class with a vtable
//    void** vtablePtr = *(void***)instance;
//
//    // Dereference the first entry of the vtable to get the vtable pointer
//    void* vtable = *vtablePtr;
//
//    return vtable;
//}
