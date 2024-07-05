#include "idGameSystemLocalManager.h"

 bool idGameSystemLocalManager::acquireIdGameSystemLocalAddr(__int64 idGameSystemLocalAddr) {
	logDebug("acquireIdGameSystemLocalAddr");
	if (MemHelper::isBadReadPtr((void*)idGameSystemLocalAddr)) {
		logErr("acquireIdGameSystemLocalAddr: failed to acquire idGameSystemLocalAddr (bad ptr): %p", (void*)idGameSystemLocalAddr);
		m_idGameSystemLocalAdrr = 0;

	}
	else {

		m_idGameSystemLocalAdrr = idGameSystemLocalAddr;
		logInfo("acquireIdGameSystemLocal: Succes acquirring idGameSystemLocalAddr: %p", (void*)m_idGameSystemLocalAdrr);
		return true;

	}
	return false;
}

 __int64 idGameSystemLocalManager::getIdGameSystemLocalAddr() {
	logDebug("getIdGameSystemLocalAddr");
	return m_idGameSystemLocalAdrr;
}

 GameState idGameSystemLocalManager::getCurrentState() {
	logDebug("getCurrentState");

	//logInfo("getCurrentState called");

	int stateOffset = TypeInfoManager::getGameSystemLocalStateOffset();
	GameState state = GameState::unknown;

	if (MemHelper::isBadReadPtr((void*)m_idGameSystemLocalAdrr)) {
		logErr("getCurrentState: can not get current state cause m_idGameSystemLocalAdrr is bad ptr %p", (void*)m_idGameSystemLocalAdrr);
	}
	else if (!stateOffset) {
		logErr("getCurrentState: can not get current state cause stateOffset == 0");
	}
	else {
		int stateInt = *(int*)(m_idGameSystemLocalAdrr + stateOffset);
		//__int64 stateAddress = m_idGameSystemLocalAdrr + stateOffset;
		//logInfo("getCurrentState: m_idGameSystemLocalAdrr: %p stateAddress: %p stateOffset: 0x%X stateInt: %d", (void*)m_idGameSystemLocalAdrr, (void*)stateAddress, stateOffset,  stateInt);

		//? see this...DONT EVERY FORGET. local variable defined in the else statement, this is a different state var that...So ofc the state defined at the start of the getCurrentState function would never change... Leaving this here for documentation.
		//GameState state = (GameState)stateInt;

		state = (GameState)stateInt; //! this is the corrected version.

		//logInfo("getCurrentState: state: %d and stateInt: %d", (int)state, stateInt);
		//GameState state = (GameState) *(int*)(m_idGameSystemLocalAdrr + stateOffset);
	}

	if (state != m_lastGameState) {
		logInfo("getCurrentState: state has changed from: %s to %s", getStateString(m_lastGameState).c_str(), getStateString(state).c_str());
		m_lastGameState = state;
	}
	return state;
}

 std::string idGameSystemLocalManager::getStateString(GameState state) {
	logDebug("getStateString");

	switch (state) {
	case GameState::undefined:
		return "undefined";
	case GameState::unknown:
		return "unknown";
	case GameState::inMainMenu:
		return "inMainMenu";
	case GameState::loading:
		return "loading";
	case GameState::levelLoaded:
		return "levelLoaded";
	default:
		return "invalid (?!)";
	}
}
