#include "idFxManager.h"


//! we only disable the dash we do not re-enable it to make sure we don't assigne a ptr that could crash the game. User can still reenable the dash by reloading the level/save



bool idFxManager::acquireToggleDashEffectInstructionAddr(__int64 addr)
{
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquireToggleDashEffectInstructionAddr: bad ptr: %p ", (void*)addr);
		m_toggleDashEffectInstructionAddr = 0; //! not necessary but safety first.
		return false;
	}
	m_toggleDashEffectInstructionAddr = addr;
	logInfo("acquireToggleDashEffectInstructionAddr: m_toggleDashEffectInstructionAddr set to %p", (void*)m_toggleDashEffectInstructionAddr);
	return true;
}

bool idFxManager::setDashEffect(bool isSetOn) {
	bool isSucces = false;

	if (!m_toggleDashEffectInstructionAddr) {
		logErr("setDashEffect: can not set effect cause m_toggleDashEffectInstructionAddr is null, Mod should not be running anyway");
		return false;
	}

	if (isSetOn) {
		if (Patcher::patchIfNeeded("dashEffectON", m_toggleDashEffectInstructionAddr, dashEffectONVec)) {
			isSucces = true;
		}
	}
	else {
		if (Patcher::patchIfNeeded("dashEffectOFF", m_toggleDashEffectInstructionAddr, dashEffectOFFVec)) {
			isSucces = true;
		}		
	}

	if (isSucces) {
		logInfo("setDashEffect: Succes setting dash effect to: %s", isSetOn ? "Enabled" : "Disabled");
	}
	else {
		logErr("setDashEffect: FAILED to set dash effect to: %s", isSetOn ? "Enabled" : "Disabled");
	}

	return isSucces;
}


//! old way to do it by nopping ptr which was not ideal.
//void idFxManager::disableDashFx() {
//
//	if (!idInventoryCollectionManager::isDashAbilityOwned()) {
//		logWarn("disableDashFx isDashAbilityOwned is false (?!)");
//		return;
//	}
//
//	idInventoryItem* dashAbilityItem = idInventoryCollectionManager::getidInventoryItemPtr(ItemRef::ABILITY_DASH);
//	if (!dashAbilityItem) {
//		logErr("disableDashFx : dashAbilityItem is nullptr");
//		return;
//	}
//
//	idDeclAbility_Dash* idDeclAbility_Dash_Ptr = (idDeclAbility_Dash *) dashAbilityItem->decl;
//	if (idDeclAbility_Dash_Ptr->fxDecl) {
//		logInfo("disableDashFx: Disabling Dash FX. Please restart the game if you want to enable it again. dashAbilityItem: %p idDeclAbility_Dash_Ptr: %p fxDecl: %p", dashAbilityItem, idDeclAbility_Dash_Ptr, &idDeclAbility_Dash_Ptr->fxDecl);
//		logWarn("disableDashFx: NOT ACTUALLY DISABLING FOR DEBUG PURPOSE !!!!!!");		
//		//idDeclAbility_Dash_Ptr->fxDecl = nullptr;
//	}
//}
//


// void idFxManager::disableDashFx() {
//	if (!idInventoryCollectionManager::isDashAbilityOwned()) {
//		return;
//	}
//	__int64 dashAbilityItemAddr = idInventoryCollectionManager::getItemAddress(Item_ResourceID::ABILITY_DASH);
//	//logInfo("disableDashFx: dashAbilityItemAddr: %p", (void*)dashAbilityItemAddr);
//	if (MemHelper::isBadReadPtr((void*)dashAbilityItemAddr)) {
//		logWarn("Can not disableDash cause dashAbilityItemAddr is bad ptr: %p may be cause player does not own the dash ability (yet)", (void*)dashAbilityItemAddr);
//		return;
//	}
//	//? again made the mistake of doing *(__int64*)dashAbilityItemAddr + 0x38 instead of *(__int64*)(dashAbilityItemAddr + 0x38)..there is a reason why we have types !!!!!!!
//	__int64 declDashAbilityAddr = *(__int64*)(dashAbilityItemAddr + 0x38);
//	//logInfo("disableDashFx: declDashAbilityAddr: %p", (void*)declDashAbilityAddr);
//	if (MemHelper::isBadReadPtr((void*)declDashAbilityAddr)) {
//		logWarn("Can not disableDash cause declDashAbilityAddr is bad ptr, OR it might already be disabled.");
//		return;
//	}
//	idDeclAbility_Dash* idDeclAbility_Dash_Ptr = (idDeclAbility_Dash*)declDashAbilityAddr;
//	//if (idDeclAbility_Dash_Ptr->screenShakeDeclPtr_fxDecl) {
//	if (idDeclAbility_Dash_Ptr->fxDecl) {
//		logInfo("disableDashFx: Disabling Dash FX. Please restart the game if you want to enable it again. Ptr_fxDecl addr: %p", &idDeclAbility_Dash_Ptr->fxDecl);
//		//idDeclAbility_Dash_Ptr->screenShakeDeclPtr_fxDecl = nullptr;
//		idDeclAbility_Dash_Ptr->fxDecl = nullptr;
//	}
//}
