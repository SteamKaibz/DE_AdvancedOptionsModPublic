#pragma once


#include "MemHelper.h"
#include "TypeInfoManager.h"




class idGameSystemLocalManager {

private:

	static inline __int64 m_idGameSystemLocalAdrr = 0;
	static inline GameState m_lastGameState = GameState::undefined;




public:

	static bool acquireIdGameSystemLocalAddr(__int64 idGameSystemLocalAddr);

	static __int64 getIdGameSystemLocalAddr();

	static GameState getCurrentState();

	static std::string getStateString(GameState state);

	//static 

};

