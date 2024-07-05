#include "idSWFWidgetManager.h"

 idSWFSpriteInstance* idSWFWidgetManager::getBoundSprite(idSWFWidget_Hud_Reticle* swfHudReticlePtr) {
	if (!swfHudReticlePtr) {
		logErr("getBoundSprite: swfHudReticlePtr is nullptr returning nullptr");
		return nullptr;
	}
	idSWFWidget* idSWFWidgetPtr = (idSWFWidget*)swfHudReticlePtr;
	return idSWFWidgetPtr->boundSprite;
}
