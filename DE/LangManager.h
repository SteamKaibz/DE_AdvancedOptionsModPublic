#pragma once
#include <cstdint>
#include "MemHelper.h"
#include "CommonDE.h"
#include "../Config/Config.h"

#include "LocalizedBindStringData.h"
#include "fastCvarManager.h"

//#include "Scanner.h"


class LangManager
{
	//todo we should have a static LocalizedBindStringData in members here as there is not point computing it everytime a request from another object is made.
private:

	//static inline __int64 m_sysLangPtrToPtr = 0;
	//const unsigned int m_languageStrOffset = 0x519C2C8;
	static inline GameLanguage m_gameLanguage = GameLanguage::Undefined;

	static inline LocalizedBindStringData m_LocalizedBindStringData; 


	static GameLanguage setGameLanguage(std::string inGameLanguageStr);

	static std::string GameLanguageToString(GameLanguage language);

	//! get current language from the game mem
	static bool acquireGameLanguage();



public:	
	

	//static bool acquirreSysLangFuncStartAddr(__int64 sysLangFuncStartAddr);

	static GameLanguage getGameLanguage();

	static void setLocalizedBindStringData();

	static LocalizedBindStringData& getLocalizedBindStringData();


};



