#include "idSWFSpriteInstanceManager.h"

 bool idSWFSpriteInstanceManager::acquireUpdateSpriteInstanceColorFuncAdd(__int64 funcAddr) {
	if (MemHelper::isBadReadPtr((void*)funcAddr)) {
		return false;
	}
	m_updateSpriteInstanceColorFuncAdd = funcAddr;
	logInfo("acquireUpdateSpriteInstanceColorFuncAdd is being set: %p", (void*)m_updateSpriteInstanceColorFuncAdd);
	return true;
}

 swfRect_t idSWFSpriteInstanceManager::getBounds(idSWFSpriteInstance* thiz) {
	//logInfo("debug: getBounds called");
	if (!MemHelper::isBadReadPtr((void*)thiz)) {
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)thiz;
		return spriteInstance->bounds;
	}
	logWarn("getBounds: returning empty swfRect_t");
	return swfRect_t();
}

 void idSWFSpriteInstanceManager::debugPrintCoords(idSWFSpriteInstance* thiz) {
	if (!MemHelper::isBadReadPtr((void*)thiz)) {
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)thiz;

		swfRect_t bounds = spriteInstance->bounds;
		logInfo("debugPrintCoords: brx %.2f bry %.2f tlx %.2f tly %.2f", bounds.br.x, bounds.br.y, bounds.tl.x, bounds.tl.y);
		//? one of those might cause a crash when reloading a level afaik
		/*logInfo("getFragBorderCoords: m_fragCoolDownFillGlowSpriteAddr is: %p", (void*)m_fragCoolDownFillGlowSpriteAddr);
		idVec4 coords = spriteInstance->getCoords();
		coords.printMsg("getFragBorderCoords: coords: ");
		spriteInstance->print();*/
		/*if (spriteInstance->isCoordsPotentialError()) {
		logWarn("getFragBorderCoords potential error detected: ice nade custom might not be displayed !!!");
		}*/
		//return spriteInstance->getCoords();
	}
	else {
		logErr("debugPrintCoords: bad ptr");

	}
}

 void idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstance* thiz, swfNamedColors_t swfColorId) {
	if (!thiz) {
		logErr("updateSpriteInstanceColor thiz is null can not update color");
		return;
	}
	if (!m_updateSpriteInstanceColorFuncAdd) {
		logErr("updateSpriteInstanceColor: can not updateSpriteInstanceColor cause m_updateSpriteInstanceColorFuncAdd is null");
		return;
	}
	if (swfColorId == swfNamedColors_t::SWF_NAMED_COLOR_INVALID) {
		return;
	}
	logInfo("updateSpriteInstanceColor, updating color to color id : %d", swfColorId);
	auto updateSpriteInstanceColorFunc = reinterpret_cast<pUpdateSpriteInstanceColor>(m_updateSpriteInstanceColorFuncAdd);

	return updateSpriteInstanceColorFunc(thiz, swfColorId);
}

 void idSWFSpriteInstanceManager::setHitMarkerState(idHUD_Reticle* idHUD_Reticle, HitMarkerState state) {
	//logInfo("setHitMarkerState: debug 1");
	if (!idHUD_Reticle) {
		logErr("setHitMarkerState: idHUD_Reticle is nullptr, can not change hit marker setting");
		return;
	}
	//logInfo("setHitMarkerState: debug 2");

	//logInfo("setHitMarkerState: debug: &idHUD_Reticle->hitFlashSpr: %p", (void*)&idHUD_Reticle->hitFlashSpr);
	//! maybe overkill but i've been hurt before. let's check if the perf is good enough.
	if (MemHelper::isBadReadPtr((void*)&idHUD_Reticle->hitFlashSpr)) return;

	//logInfo("setHitMarkerState: debug 3");

	idSWFCachedSpriteInstance* cachedSpriteInstance = (idSWFCachedSpriteInstance*)&idHUD_Reticle->hitFlashSpr;
	//logInfo("setHitMarkerState: debug: void*)&cachedSpriteInstance->SpriteInstance): %p and cachedSpriteInstance->SpriteInstance: %p", (void*)&cachedSpriteInstance->SpriteInstance, cachedSpriteInstance->SpriteInstance);
	//logInfo("setHitMarkerState: debug 4");

	if (MemHelper::isBadReadPtr((void*)&cachedSpriteInstance->SpriteInstance)) return;

	//logInfo("setHitMarkerState: debug 5");

	idSWFSpriteInstance* spriteInstance = cachedSpriteInstance->SpriteInstance;

	//logInfo("setHitMarkerState: debug 6");

	//logInfo("setHitMarkerState: debug: &spriteInstance->spriteFlags: %p ", (void*)&spriteInstance->spriteFlags);
	if (MemHelper::isBadReadPtr((void*)&spriteInstance->spriteFlags)) return;

	//logInfo("setHitMarkerState: debug 7");

	if (spriteInstance->spriteFlags != (int)state) {
		//logInfo("setHitMarkerState: debug 8");
		spriteInstance->spriteFlags = (int)state;
		logInfo("setHitMarkerState: spriteFlags has changed to: %d", spriteInstance->spriteFlags);
	}
	//logInfo("setHitMarkerState: debug 9");


}

//! check made in hook for idSWFSpriteInstance exists

 bool idSWFSpriteInstanceManager::updateScale(idSWFSpriteInstance* idSWFSpriteInstance, float reticleScaleF) {
	if (!m_pSetSpriteInstanceScale) {
		logErr("updateScale: can not upscale: m_pSetSpriteInstanceScale is null");
		return false;
	}
	if (idSWFSpriteInstance) {
		logInfo("updating idSWFSpriteInstance: %p crosshair scale", (void*)idSWFSpriteInstance);
		m_pSetSpriteInstanceScale(idSWFSpriteInstance, reticleScaleF, reticleScaleF);
		return true;
	}
	else {
		logErr("updateScale: idSWFSpriteInstance is null can not update scale");
	}
	return false;
}

 bool idSWFSpriteInstanceManager::acquirreSetSpriteInstanceScaleFpAdd(__int64 funcPtrAdd) {
	if (MemHelper::isBadReadPtr((void*)funcPtrAdd)) {
		logErr("acquirreSetSpriteInstanceScaleFpAdd: failed to acquirre fp: %p", (void*)(funcPtrAdd));
		return false;
	}
	m_pSetSpriteInstanceScale = reinterpret_cast<pSetSpriteInstanceScale>(funcPtrAdd);

	logInfo("acquirreSetSpriteInstanceScaleFpAdd: just acquirred SetSpriteInstanceScale func ptr: %p", (void*)funcPtrAdd);
	return true;
}

//! the reason why we have to do it that way is because and idList is always going to be a list of __int64* but in the this case for ex, the idList is a list of swfDisplayEntry_t and a swfDisplayEntry_t has a size of 64 bytes, so it's just easier to do it this way:

 std::vector<idSWFSpriteInstance*> idSWFSpriteInstanceManager::getSpriteInstancesPtrVecFromDisplayEntry(idSWFSpriteInstance* spriteInstance) {

	//std::vector<swfDisplayEntry_t*> entriesPtrsVec;
	std::vector<idSWFSpriteInstance*> spriteInstancesVec;

	if (MemHelper::isBadReadPtr(spriteInstance)) {
		logWarn("getSpriteInstancesPtrVecFromDisplayEntry: spriteInstance is bad ptr returning empty vec");
		return spriteInstancesVec;
	}

	//logInfo("getSpriteInstancesPtrVecFromDisplayEntry: spriteInstance at %p spriteInstance->displayList.num: %d ", spriteInstance, spriteInstance->displayList.num);
	if (spriteInstance->displayList.num > 0) {

		//swfDisplayEntry_t* displayEntry = (swfDisplayEntry_t*)&spriteInstance->displayList.list;
		swfDisplayEntry_t* displayEntry = (swfDisplayEntry_t*)spriteInstance->displayList.list;

		for (size_t i = 0; i < spriteInstance->displayList.num; i++)
		{
			//logInfo("getSpriteInstancesPtrVecFromDisplayEntry: debug: displayEntry: %p &displayEntry: %p, displayEntry->spriteInstance: %p and &displayEntry->spriteInstance: %p", displayEntry, &displayEntry, displayEntry->spriteInstance, &displayEntry->spriteInstance);
			spriteInstancesVec.push_back(displayEntry->spriteInstance);
			displayEntry++; // this should increment by the size of swfDisplayEntry_t (right?)
		}
		/*logInfo("getSpriteInstancesPtrVecFromDisplayEntry: found thoses swfDisplayEntry_t pointers:");
		for (size_t i = 0; i < spriteInstancesVec.size(); i++)
		{
		logInfo("%p", spriteInstancesVec[i]);
		}*/
	}

	return spriteInstancesVec;
}

 void idSWFSpriteInstanceManager::debugPrintfullPathHashForColorId(idSWFSpriteInstance* spriteInstance, swfNamedColors_t colorId) {
	if (MemHelper::isBadReadPtr(spriteInstance)) {
		//logWarn("debugLogInstancesDefaultNamesColors: bad ptr: %p", (void*)spriteInstanceAddr);
		return;
	}
	//idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
	if (spriteInstance->namedColorId == (int)colorId) {
		logInfo("debugPrintfullPathHashForColorId: found a sprite instance with colorid: %d fullPathHash: 0x%X (%d) and name: %s", (int)colorId, spriteInstance->fullPathHash, spriteInstance->fullPathHash, spriteInstance->name.str);
	}
}

 void idSWFSpriteInstanceManager::debugPrintSpriteInstanceMaterialOverrideNameForColorId(__int64 spriteInstanceAddr, int colorId) {

	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
	if (MemHelper::isBadReadPtr((void*)spriteInstance)) {
		logErr("debugPrintSpriteInstanceMaterialNameForColorId: idSWFSpriteInstance is bad ptr: %p", spriteInstance);
		return;
	}
	if (spriteInstance->namedColorId == (int)colorId) {
		if (!MemHelper::isBadReadPtr(spriteInstance->materialOverride)) {
			logInfo("debugPrintSpriteInstanceMaterialNameForColorId:  spriteInstance: %s has a material name: %s", spriteInstance->name, idResourceManager::getIdMaterial2Name(spriteInstance->materialOverride).c_str());
			return;
		}
		else {
			logInfo("debugPrintSpriteInstanceMaterialOverrideNameForColorId: spriteInstance: %s doesnt' have a materialOverride", spriteInstance->name);
		}
	}

}

 bool idSWFSpriteInstanceManager::debugPrintSpriteInstanceMaterialName(idSWFSpriteInstance* idSWFSpriteInstance) {
	if (MemHelper::isBadReadPtr((void*)idSWFSpriteInstance)) {
		logErr("debugPrintSpriteInstanceMaterialName: idSWFSpriteInstance is bad ptr: %p", idSWFSpriteInstance);
	}
	else if (!MemHelper::isBadReadPtr(idSWFSpriteInstance->materialOverride)) {
		logInfo("debugPrintSpriteInstanceMaterialName: material name: %s", idResourceManager::getIdMaterial2Name(idSWFSpriteInstance->materialOverride).c_str());
		return true;
	}
	return false;
}

 void idSWFSpriteInstanceManager::debugPrintSpriteInstanceDisplayList(idSWFSpriteInstance* idSWFSpriteInstanceObj) {

	//static std::vector<std::string> matrNamesVec;

	if (MemHelper::isBadReadPtr((void*)idSWFSpriteInstanceObj)) {
		logErr("debugPrintSpriteInstanceDisplayList: idSWFSpriteInstanceObj is bad ptr: %p", idSWFSpriteInstanceObj);
		return;
	}
	logInfo("debugPrintSpriteInstanceDisplayList: idSWFSpriteInstanceObj add: %p idSWFSpriteInstance->displayList.list: %p displayList.num: %d", idSWFSpriteInstanceObj, idSWFSpriteInstanceObj->displayList.list, idSWFSpriteInstanceObj->displayList.num);
	if (idSWFSpriteInstanceObj->displayList.num > 0) {
		for (size_t i = 0; i < idSWFSpriteInstanceObj->displayList.num; i++)
		{
			swfDisplayEntry_t* displayEntry = (swfDisplayEntry_t*)&idSWFSpriteInstanceObj->displayList.list[i];
			if (!MemHelper::isBadReadPtr((void*)displayEntry)) {
				auto spriteInstance = displayEntry->spriteInstance;
				std::string sname = std::string(spriteInstance->name.str);
				auto rect = spriteInstance->bounds;
				logInfo("debugPrintSpriteInstanceDisplayList: found sprite instance: %s with hash: 0x%X (%d) rect: %.2f %.2f %.2f %.2f isVisible: %d", sname.c_str(), spriteInstance->fullPathHash, spriteInstance->fullPathHash, spriteInstance->isVisible);
			}
			else {
				logWarn("debugPrintSpriteInstanceDisplayList: displayEntry is bad ptr: %p", displayEntry);
			}
		}
	}
	else {
		logWarn("debugPrintSpriteInstanceDisplayList: idSWFSpriteInstance->displayList.num is 0");
	}


}

/*

19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name cooldown2 hash: 456271084
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name cooldown hash: 1452392179
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name equipment hash: 929754470
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name weaponInfo hash: -938331194
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name hudElement hash: -2107815822
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name _root hash: 91240897

*/
//! from my logs those values do not change for the nade icon whether you're in a menu or not or if the hud element is disabled in the settings or if in cinematic

 void idSWFSpriteInstanceManager::debugPrintSpriteInstanceInfo(idSWFSpriteInstance* spriteInstance) {
	static bool isFirstTime = true;
	static idSWFSpriteInstance* lastspriteInstance = 0;
	static bool lastisPlaying = false;
	static bool lastIsVisible = false;
	static bool lastVisibilityRestricted = false;
	static bool lastfirstRun = false;
	static int lastSpriteFlags = false;
	static int lastnamedColorId = -99;
	bool isChanged = false;


	if (MemHelper::isBadReadPtr(spriteInstance)) {
		logWarn("debugPrintSpriteInstanceInfo: spriteInstance is bad ptr: %p", spriteInstance);
		return;
	}


	//idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAdd;

	//! this will crash at some point
	//while (true)
	//{			
	//	//logInfo("debugPrintSpriteInstanceInfo: %X", spriteInstance->fullPathHash);
	//	//idSWFSpriteInstance* spriteInstanceParent = spriteInstance->parent;
	//	spriteInstance = spriteInstance->parent;
	//	if (!spriteInstance) break;
	//	logInfo("debugPrintSpriteInstanceInfo: fount parent with name %s hash: %d", spriteInstance->name.str, spriteInstance->fullPathHash);			
	//}

	/*if (spriteInstanceParent) {
	logInfo("debugPrintSpriteInstanceInfo: parent name %s", spriteInstanceParent->name.str);
	logInfo("debugPrintSpriteInstanceInfo: parent isVisible %d", spriteInstanceParent->isVisible);
	logInfo("debugPrintSpriteInstanceInfo: parent visibilityRestricted %d", spriteInstanceParent->visibilityRestricted);
	}*/

	if (isFirstTime) {
		logInfo("debugPrintSpriteInstanceInfo FirstTime logging for spriteInstance: %s", spriteInstance->name.str);
		logInfo("debugPrintSpriteInstanceInfo: Addr: %p ", spriteInstance);
		lastspriteInstance = spriteInstance;
		logInfo("debugPrintSpriteInstanceInfo: isPlayingAndActive: %d ", spriteInstance->isPlaying);
		lastisPlaying = spriteInstance->isPlaying;
		logInfo("debugPrintSpriteInstanceInfo: isVisible: %d  ", spriteInstance->isVisible);
		lastIsVisible = spriteInstance->isVisible;
		logInfo("debugPrintSpriteInstanceInfo: visibilityRestricted: %d  ", spriteInstance->visibilityRestricted);
		lastVisibilityRestricted = spriteInstance->visibilityRestricted;
		logInfo("debugPrintSpriteInstanceInfo: firstRun: %d  ", spriteInstance->firstRun);
		lastfirstRun = spriteInstance->firstRun;
		logInfo("debugPrintSpriteInstanceInfo: spriteFlags: %d  ", spriteInstance->spriteFlags);
		lastSpriteFlags = spriteInstance->spriteFlags;
		logInfo("debugPrintSpriteInstanceInfo: namedColorId: %d  ", spriteInstance->namedColorId);
		lastnamedColorId = spriteInstance->namedColorId;
		isFirstTime = false;
		return;
	}
	if (spriteInstance != lastspriteInstance) {
		lastspriteInstance = spriteInstance;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: spriteInstance has changed to: %p ", lastspriteInstance);
	}
	if (spriteInstance->isPlaying != lastisPlaying) {
		lastisPlaying = spriteInstance->isPlaying;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: isPlayingAndActive had changed to: %d ", lastisPlaying);
	}
	if (spriteInstance->isVisible != lastIsVisible) {
		lastIsVisible = spriteInstance->isVisible;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: isVisible had changed to: %d ", lastIsVisible);
	}
	if (spriteInstance->visibilityRestricted != lastVisibilityRestricted) {
		lastVisibilityRestricted = spriteInstance->visibilityRestricted;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: visibilityRestricted had changed to: %d ", lastVisibilityRestricted);
	}
	if (spriteInstance->firstRun != lastfirstRun) {
		lastfirstRun = spriteInstance->firstRun;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: firstRun had changed to: %d ", lastfirstRun);
	}
	if (spriteInstance->spriteFlags != lastSpriteFlags) {
		lastSpriteFlags = spriteInstance->spriteFlags;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: spriteFlags had changed to: %d ", lastSpriteFlags);
	}
	if (spriteInstance->namedColorId != lastnamedColorId) {
		lastnamedColorId = spriteInstance->namedColorId;
		isChanged = true;
		logInfo("debugPrintSpriteInstanceInfo: namedColorId had changed to: %d ", lastnamedColorId);
	}

}
