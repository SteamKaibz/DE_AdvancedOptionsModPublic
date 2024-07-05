#pragma once

#include "UtilsDE.h"
#include "../Config/Config.h"
#include "MemHelper.h"
#include "idGameSystemLocalManager.h"
#include "GeneratedClasses.h"
#include "idMapInstanceLocalManager.h"



class PlayerStateChecker
{

private:


	static inline PlayerState m_lastPlayerState = PlayerState::undefined;


	static inline uint64_t m_lastReticleRefreshMs = 0;
	static inline unsigned int const m_reticleRefreshTimeOutDelayMs = 100;

	

	static inline bool m_lastIsGameInitialized = false;
	static inline bool m_isGameInitialized = false;



	static inline std::string m_lastMenuNameStr = "undefined";

	static inline int m_lastMenuState = -10; //! abitraty value

	static inline const __int64 m_currentGameModeStrOffset = UndocumentedOffsets::CurrentGameModeOffset;

	

	

public:


	

	static std::string getDbgStrForImgui();

	static std::string getPlayerStateAsStr(PlayerState playerState);


	static PlayerState getPlayerState();

	static void updatePlayerState();


	static bool isGameLoading();

	//! meaning not in cutscene or uncontrollable
	static bool isPlayingAndActive();

	//! could be in cutscene or dead
	static bool isNotAbleToFight();

	static bool isInMainMenu();

	static bool isInMenus();

	
		
	//! we assume game is loaded when menu start refreshing. Not the best but it seems to work, so far....
	static bool isGameInitialized();	


	//! it will return true also if menu_dontpause cmd is set to 1.
	static PauseMenuState getPauseMenuState();

	
	
	static void updateLastReticleRefresh();

	static uint64_t getlastReticleRefreshMs();

	//! we assume that if a menu refresh that the game is initalized and the mod can work...
	static void updateLastMenuRefresh();



    
};


