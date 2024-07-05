#include "ColorManager.h"


bool ColorManager::acquirreReapplySwfColorsFuncAddr(__int64 reapplySwfColorsFuncAddr) {
	if (MemHelper::isBadReadPtr((void*)reapplySwfColorsFuncAddr)) {
		logErr("acquirreReapplySwfColorsFuncAddr: failed because reapplySwfColorsFuncAddr is bad ptr: %p", (void*)reapplySwfColorsFuncAddr);
		return false;
	}
	reapplySwfColorsFp = reinterpret_cast<reapplySwfColors_t>(reapplySwfColorsFuncAddr);
	logInfo("acquirreReapplySwfColorsFuncAddr: reapplySwfColorsFp is being set: %p", reapplySwfColorsFp);
	return true;
}


void ColorManager::reapplySwfColors() {

	if (!reapplySwfColorsFp) {
		logErr("reapplySwfColorsCmd: can not ReapplySwfColors cause reapplySwfColorsFp is nullptr");
		return;
	}

	reapplySwfColorsFp();
	m_lastReapplySwfColorCallMs = EpochMillis();

}

void ColorManager::autoReapplySwfColors() {
	if (EpochMillis() - m_lastReapplySwfColorCallMs > m_autoReapplyColorFrequenceMs) {
		reapplySwfColors();		
	}
}

