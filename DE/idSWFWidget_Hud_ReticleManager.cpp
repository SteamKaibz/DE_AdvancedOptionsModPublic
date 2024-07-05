#include "idSWFWidget_Hud_ReticleManager.h"

 bool idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_Reticle* swfReticlePtr) {
	logDebug("isReticleCoolDown");
	if (MemHelper::isBadReadPtr(swfReticlePtr)) {
		logErr("isReticleCoolDown: swfReticlePtr is bad ptr: %p returning false", swfReticlePtr);
		return false;
	}
	return swfReticlePtr->currentData.chargeCooldown < 1.0f;
}
