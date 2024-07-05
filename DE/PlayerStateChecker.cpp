#include "PlayerStateChecker.h"



std::string PlayerStateChecker::getDbgStrForImgui() {

	return "\nPlayerStateChecker: PlayerState: " + PlayerStateChecker::getPlayerStateAsStr(m_lastPlayerState);
}

 std::string PlayerStateChecker::getPlayerStateAsStr(PlayerState playerState) {

	 switch (playerState)
	 {
	 case PlayerState::undefined:
		 return "undefined";
	 case PlayerState::unknown:
		 return "unknown";
	 case PlayerState::inMainMenu:
		 return "inMainMenu";
	 case PlayerState::inLoadingScreen:
		 return "inLoadingScreen";
	 case PlayerState::inPauseMenu:
		 return "inPauseMenu";
	 case PlayerState::inGameNotAbleToFight:
		 return "inGameNotAbleToFight ('could' be in cutscene)";
	 case PlayerState::inGameReticleActive:
		 return "inGameReticleActive";
	 default:
		 return "Could not find state (?!)";
	 }

}

 PlayerState PlayerStateChecker::getPlayerState() {
	return m_lastPlayerState;
}

 void PlayerStateChecker::updatePlayerState() {
	 static PlayerState lastPlayerState = PlayerState::undefined;
	PlayerState playerState = PlayerState::unknown;
	//updateGameState();
	//getMenuInfo();

	GameState currentGameState = idGameSystemLocalManager::getCurrentState();

	if (currentGameState == GameState::unknown || currentGameState == GameState::undefined) {
		playerState = PlayerState::unknown;
	}
	else if (currentGameState == GameState::loading) {
		playerState = PlayerState::inLoadingScreen;
	}
	else if (currentGameState == GameState::inMainMenu) {
		playerState = PlayerState::inMainMenu;
	}
	else if (currentGameState == GameState::levelLoaded) {
		//logInfo("updatePlayerState: here !!!!!");
		PauseMenuState pauseMenuState = getPauseMenuState();
		if (pauseMenuState == PauseMenuState::opened) {
			playerState = PlayerState::inPauseMenu;
		}
		else if (pauseMenuState == PauseMenuState::unknown) {
			playerState = PlayerState::unknown;
		}
		else if ((EpochMillis() - m_lastReticleRefreshMs) < m_reticleRefreshTimeOutDelayMs) {
			playerState = PlayerState::inGameReticleActive;
		}
		else {
			playerState = PlayerState::inGameNotAbleToFight;
		}
	}
	/*else if ((EpochMillis() - m_lastInputProcessMs) < m_inputProcessTimeOutDelayMs) {
	playerState = PlayerState::inGameWithHudOff;
	}*/
	/*else {
	playerState = PlayerState::unknown;
	}*/

	if (playerState != m_lastPlayerState) {

		std::string previousStateStr = getPlayerStateAsStr(m_lastPlayerState);
		std::string currentStateStr = getPlayerStateAsStr(playerState);

		logInfo("updatePlayerState:PlayerState is changing from %s to %s", previousStateStr.c_str(), currentStateStr.c_str());		
		m_lastPlayerState = playerState;
	}
}

 bool PlayerStateChecker::isGameLoading() {
	//updatePlayerState();
	return m_lastPlayerState == PlayerState::inLoadingScreen;
}

//! meaning not in cutscene or uncontrollable
 bool PlayerStateChecker::isPlayingAndActive() {
	//updatePlayerState();
	return m_lastPlayerState == PlayerState::inGameReticleActive;
}

 bool PlayerStateChecker::isNotAbleToFight() {
	 return m_lastPlayerState == PlayerState::inGameNotAbleToFight;
 }
 
 bool PlayerStateChecker::isInMainMenu() {
	 return m_lastPlayerState == PlayerState::inMainMenu;
 }

 bool PlayerStateChecker::isInMenus() {
	//logInfo("isInMenus: m_lastPlayerState is: %d", (int)m_lastPlayerState);
	//updatePlayerState();
	return m_lastPlayerState == PlayerState::inPauseMenu || m_lastPlayerState == PlayerState::inMainMenu;
}

//! meaning playing or in cutscenes

// bool PlayerStateChecker::isInGame() {
//	return m_lastPlayerState == PlayerState::inGameAndActive || m_lastPlayerState == PlayerState::inGameNotAbleToFight;
//}

//! we assume game is loaded when menu start refreshing. Not the best but it seems to work, so far....

 bool PlayerStateChecker::isGameInitialized() {
	static bool isFirstTime = true;

	if (isFirstTime) {
		logInfo("m_isGameInitialized : %s", m_isGameInitialized ? "true" : "false");
		isFirstTime = false;
	}
	else if (m_isGameInitialized != m_lastIsGameInitialized) {
		m_lastIsGameInitialized = m_isGameInitialized;
		logInfo("m_isGameInitialized has changed and is now: %s", m_isGameInitialized ? "true" : "false");
	}
	return m_isGameInitialized;
}

//! it will return true also if menu_dontpause cmd is set to 1.

 PauseMenuState PlayerStateChecker::getPauseMenuState() {

	static PauseMenuState lastpauseMenuSateDebug = PauseMenuState::undefined;

	PauseMenuState pauseMenuSate = PauseMenuState::unknown;
	idPlayer* idPlayerObj = idMapInstanceLocalManager::getIdPlayer();


	if (idPlayerObj) {
		//idPlayer_t* idPlayer = (idPlayer_t*)IdPlayerAdrr;
		//! isInPauseMenu a byte but each bit is set independently and the one we want is the 4th one and 8 is 00001000
		//if ((idPlayer->isInPauseMenu & 0x8) != 0) { 
		//logInfo("getPauseMenuState: &idPlayer->isInPauseMenu is : %p and idPlayer->isInPauseMenu val: %d", &idPlayer->isInPauseMenu, idPlayer->isInPauseMenu);
		//if (idPlayerObj->isInPauseMenu) {
		if (idPlayerObj->playerHud.gameWasPaused) {
			pauseMenuSate = PauseMenuState::opened;
		}
		else {
			pauseMenuSate = PauseMenuState::closed;
		}
		//unsigned int isPauseMenuOpened = *(unsigned int*)(idHUDMenu_Screen_Pause_Addr + 0xB8);
		//return isPauseMenuOpened;
	}
	/*else {
	logWarn("isPauseMenuOpened: IdPlayerAdrr is bad ptr: %llx returning false", IdPlayerAdrr);
	}*/

	if (lastpauseMenuSateDebug != pauseMenuSate) {
		lastpauseMenuSateDebug = pauseMenuSate;
		logInfo("getPauseMenuState: pauseMenuSate has changed to: %d", (int)pauseMenuSate);
	}
	return pauseMenuSate;
}

 void PlayerStateChecker::updateLastReticleRefresh() {
	m_lastReticleRefreshMs = EpochMillis();
	//updatePlayerState();
}

 uint64_t PlayerStateChecker::getlastReticleRefreshMs() {
	 return m_lastReticleRefreshMs;
 }


//! we assume that if a menu refresh that the game is initalized and the mod can work...

 void PlayerStateChecker::updateLastMenuRefresh() {
	m_isGameInitialized = true;
	//m_lastMenuRefreshMs = EpochMillis();
	//updatePlayerState();
}

 //? i would rather not user this cause of the static ptr, i will break for sure next update.
 // std::string PlayerStateChecker::getCurrentGameModeStr() {
//	auto currentGameModeStrAdd = MemHelper::getAddr(m_currentGameModeStrOffset);
//	if (MemHelper::isBadReadPtr((void*)currentGameModeStrAdd)) return "unknowGameMode: currentGameModeStrAdd is bad ptr";
//	return std::string((const char*)currentGameModeStrAdd);
//
//}
