//#include "ReticleColorManager.h"
//
//
//
//
// void ReticleColorManager::updateDotColorV3(idSWFWidget_Hud_Reticle* idSWFWidget_Hud_ReticlePtr, idDeclWeaponReticle* declWeaponReticle, idSWFSpriteInstance* idSWFSpriteInstancePtr) {
//    //logInfo("debug updateDotColorV3 ");      
//
//
//    if (idPlayer_K::isPlayerDemon()) return;
//
//    if (!idSWFWidget_Hud_ReticlePtr || !idSWFSpriteInstancePtr || !declWeaponReticle) return;
//
//
//    if (idDeclWeaponReticleManager::isMeatHookDeclWeaponReticle(declWeaponReticle) && idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_ReticlePtr) && UserColorSet::isCrosshairCooldownFeatureEnabled()) {
//
//        //logInfo("debug updateDotColorV3 1");
//
//        //logInfo("debug isMeatHookReticle detected");
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshairCoodown_Color()) {
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshairCoodown_Color();
//            idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshairCoodown_Color());
//        }
//        /*if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshairCoodown_Color()) {
//        idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshairCoodown_Color();
//        idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshairCoodown_Color());
//        }*/
//        return;
//    }
//    else if (idDeclWeaponReticleManager::isShotgunDeclWeaponStickyReticle(declWeaponReticle) && idSWFWidget_Hud_ReticleManager::isReticleCoolDown(idSWFWidget_Hud_ReticlePtr) && UserColorSet::isCrosshairCooldownFeatureEnabled()) {
//        //logInfo("debug updateDotColorV3 2");
//
//        //logInfo("debug ShotgunStickyReticle detected");
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshairCoodown_Color()) {
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshairCoodown_Color();
//            idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshairCoodown_Color());
//        }
//        return;
//    }
//    else if (idInventoryCollectionManager::isFragNadeOwned() && idInventoryCollectionManager::isIceNadeOwned() && idPlayer_K::getFragNadeCount() && idPlayer_K::getIceNadeCount() && UserColorSet::isCrosshairBothNadesReadyFeatureEnabled()) {
//        //logInfo("debug updateDotColorV3 3");
//
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshairBothNadesReady_Color()) {
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshairBothNadesReady_Color();
//            idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshairBothNadesReady_Color());
//        }
//        return;
//    }
//    else if (idInventoryCollectionManager::isIceNadeOwned() && idPlayer_K::getIceNadeCount() && UserColorSet::isCrosshairIceReadyFeatureEnabled()) {
//        //logInfo("debug updateDotColorV3 4");
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshairIceReady_Color()) {
//
//
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshairIceReady_Color();
//            idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshairIceReady_Color());
//        }
//        return;
//    }
//    else if (idInventoryCollectionManager::isFragNadeOwned() && idPlayer_K::getFragNadeCount() && UserColorSet::isCrosshairFragReadyFeatureEnabled()) {
//        //logInfo("debug updateDotColorV3 5");
//
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshairFragReady_Color()) {
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshairFragReady_Color();
//            idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshairFragReady_Color());
//        }
//        return;
//    }
//
//
//    if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != UserColorSet::getDotCrosshair_Color()) {
//        //logInfo("debug updateDotColorV3 6");
//        idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = UserColorSet::getDotCrosshair_Color();
//        idSWFSpriteInstanceManager::updateSpriteInstanceColor(idSWFSpriteInstancePtr, UserColorSet::getDotCrosshair_Color());
//    }
//
//    /* logInfo("debug updateDotColorV3 frag color: %d ice color: %d both nades color: %d", UserColorSet::getDotCrosshairFragReady_Color(), UserColorSet::getDotCrosshairIceReady_Color(), UserColorSet::getDotCrosshairBothNadesReady_Color());*/
//
//
//
//
//    //? idSWFWidget_Hud_Reticle + 1BC should be chargeCooldown
//    char* chargeCooldownPtr = (char*)idSWFWidget_Hud_ReticlePtr + 0x1BC;
//    if (MemHelper::isBadReadPtr(chargeCooldownPtr)) {
//        logErr("updateDotColorV3: chargeCooldownPtr is bad ptr: %p", chargeCooldownPtr);
//        return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
//    }
//
//    //! gepeto suggestion
//    if (typeid(*reinterpret_cast<float*>(chargeCooldownPtr)) != typeid(float)) {
//        logErr("updateDotColorV3: chargeCooldownPtr does not point to a float");
//        return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
//        
//      
//    }
//    /*else {
//        logErr("updateDotColorV3: chargeCooldownPtr does not point to a float");
//        return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
//    }*/
//
//    float chargeCooldownF = *(float*)chargeCooldownPtr;
//    //logInfo("chargeCooldownF: %.3f", chargeCooldownF);
//
//    /*logInfo("updateDotColorV3: idSWFWidget_Hud_ReticlePtr: %p &idSWFWidget_Hud_ReticlePtr->reticleSprite: %p idSWFWidget_Hud_ReticlePtr->reticleSprite: %p and &idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId: %p ", idSWFWidget_Hud_ReticlePtr, (void*)&idSWFWidget_Hud_ReticlePtr->reticleSprite, idSWFWidget_Hud_ReticlePtr->reticleSprite, (void*)&idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId);*/
//
//    if (MemHelper::isBadReadPtr((void*)&idSWFWidget_Hud_ReticlePtr->reticleSprite)) {
//        logErr("bad ptr for &idSWFWidget_Hud_ReticlePtr->reticleSprite: %p", (void*)&idSWFWidget_Hud_ReticlePtr->reticleSprite);
//        return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
//    }
//
//    if (MemHelper::isBadReadPtr((void*)&idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId)) {
//        logErr("bad ptr for &idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId: %p", (void*)&idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId);
//        return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
//    }
//
//    if (chargeCooldownF < 1.0f) {
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED) {
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED;
//            return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED;
//        }
//    }
//    else {
//        if (idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT) {
//            idSWFWidget_Hud_ReticlePtr->reticleSprite->namedColorId = swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
//            return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
//        }           
//    }
//    return swfNamedColors_t::SWF_NAMED_COLOR_INVALID;
//    logInfo("updateDotColorV3: chargeCooldownF: %.3f ", chargeCooldownF);
//
//
//
//    /* if(idDeclWeaponReticlePtr->style == idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_DB_SHOTGUN_MEATHOOK && )*/
//}
//
// /*void ReticleColorManager::setDotColor(swfNamedColors_t swfNamedColor) {
//    logDebug("setDotColor");
//    idSWFWidget_Hud_Reticle* idSWFWidget_Hud_Reticle_Dot = idHUD_ReticleManager::getidSWFWidget_Hud_Reticle_Dot();
//    if (MemHelper::isBadReadPtr(idSWFWidget_Hud_Reticle_Dot)) {
//        logErr("setDotColor dSWFWidget_Hud_Reticle_Dot is badPtr");
//        return;
//    }
//    logInfo("setDotColor: setting color: %s", UserColorSet::getSwfNamedColorString(swfNamedColor).c_str());
//    idSWFWidget_Hud_Reticle_Dot->setReticleColorId((int)swfNamedColor);
//}*/
//
//
// static idSWFWidget_Hud_Reticle* getidSWFWidget_Hud_Reticle_Dot() {
//		logDebug("getidSWFWidget_Hud_Reticle_Dot");
//		//! choosing not to inherit from idHudManager cause the game cls structure doens't work this way
//		//char* idHud_Reticle = idHudManager::getIdHUD_ReticlePtr();
//		char* idHud_Reticle = idHudManager::getIdHud_Element(HudElementName::Reticle);
//		logDebug("getidSWFWidget_Hud_Reticle_Dot: debug:idHud_Reticle: %p", idHud_Reticle);
//
//		if (MemHelper::isBadReadPtr(idHud_Reticle)) {
//			logErr("getidSWFWidget_Hud_Reticle_Dot: idHud_Reticle is bad ptr: %p", idHud_Reticle);
//			return nullptr;
//		}
//		//todo this hard coded offset must go away
//		char* idSWFWidget_Hud_ReticlePtr_DotPtr = idHud_Reticle + 0x210;
//		logDebug("getidSWFWidget_Hud_Reticle_Dot: debug:idSWFWidget_Hud_ReticlePtr_DotPtr: %p", idSWFWidget_Hud_ReticlePtr_DotPtr);
//		if (MemHelper::isBadReadPtr(idSWFWidget_Hud_ReticlePtr_DotPtr)) {
//			logErr("getidSWFWidget_Hud_Reticle_Dot: idSWFWidget_Hud_ReticlePtr_DotPtr is bad ptr: %p",  idSWFWidget_Hud_ReticlePtr_DotPtr);
//			return nullptr;
//		}
//		idSWFWidget_Hud_Reticle* idSWFWidget_Hud_Reticle_Dot = (idSWFWidget_Hud_Reticle*)*(__int64*)idSWFWidget_Hud_ReticlePtr_DotPtr;
//		logDebug("getidSWFWidget_Hud_Reticle_Dot: debug: idSWFWidget_Hud_Reticle_Dot: %p", idSWFWidget_Hud_Reticle_Dot);
//		logDebug("getidSWFWidget_Hud_Reticle_Dot about to return");
//		return idSWFWidget_Hud_Reticle_Dot;
//
//	}
