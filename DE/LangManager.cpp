#include "LangManager.h"

 GameLanguage LangManager::setGameLanguage(std::string inGameLanguageStr) {
	logDebug("setGameLanguage");

	if (inGameLanguageStr == EnglishLangStr) {
		return GameLanguage::English;
	}
	else if (inGameLanguageStr == FrenchLangStr) {
		return GameLanguage::French;
	}
	else if (inGameLanguageStr == GermanLangStr) {
		return GameLanguage::German;
	}
	else if (inGameLanguageStr == ItalianLangStr) {
		return GameLanguage::Italian;
	}
	else if (inGameLanguageStr == JapaneseLangStr) {
		return GameLanguage::Japanese;
	}
	else if (inGameLanguageStr == PolishLangStr) {
		return GameLanguage::Polish;
	}
	else if (inGameLanguageStr == PortugueseLangStr) {
		return GameLanguage::Portuguese;
	}
	else if (inGameLanguageStr == RussianLangStr) {
		return GameLanguage::Russian;
	}
	else if (inGameLanguageStr == SpanishSpainLangStr || inGameLanguageStr == SpanishMexicoLangStr) {
		return GameLanguage::Spanish;
	}
	else {
		return GameLanguage::English;
	}
}



 std::string LangManager::GameLanguageToString(GameLanguage language)
 {
	 switch (language)
	 {
	 case GameLanguage::Undefined: return "Undefined";
	 case GameLanguage::English: return "English";
	 case GameLanguage::French: return "French";
	 case GameLanguage::German: return "German";
	 case GameLanguage::Italian: return "Italian";
	 case GameLanguage::Japanese: return "Japanese";
	 case GameLanguage::Polish: return "Polish";
	 case GameLanguage::Portuguese: return "Portuguese";
	 case GameLanguage::Russian: return "Russian";
	 case GameLanguage::Spanish: return "Spanish";
	 default: return "Unknown";
	 }
 }


//! get current language from the game mem
 bool LangManager::acquireGameLanguage() {

	 try
	 {
		 m_gameLanguage = GameLanguage::English;

		 std::string languageStr = fastCvarManager::getLang();
		 m_gameLanguage = setGameLanguage(languageStr);

		 std::string enumToStr = GameLanguageToString(m_gameLanguage);
		 logInfo("m_gameLanguage enum: %s languageStr was: %s ", enumToStr.c_str(), languageStr.c_str());

	 }
	 catch (const std::exception& ex)
	 {
		 logErr("acquireGameLanguage: exception error: %s ", ex.what());
		 return false;
		 //logErr("acquireGameLanguage: exception error, %s", ex.what());
	 }

	 return true;
 }



 //! BAK
// bool LangManager::acquireGameLanguage() {
//
//	try
//	{
//		m_gameLanguage = GameLanguage::English;
//		//uintptr_t languageInfoStrPtr = Scanner::getLanguageStrAddr();
//		//uintptr_t sysLangPtrToPtr = ObjectLocator::getSysLangPtr();
//		//uintptr_t sysLangPtrToPtr = ObjectLocator::getSysLangPtr();
//		if (MemHelper::isBadReadPtr((void*)m_sysLangPtrToPtr)) {
//			logErr("acquireGameLanguage: found bad ptr for m_sysLangPtrToPtr: %p ", (void*)m_sysLangPtrToPtr);
//			return false;
//		}
//		uintptr_t sysLangPtr = *(uintptr_t*)m_sysLangPtrToPtr;
//		if (MemHelper::isBadReadPtr((void*)sysLangPtr)) {
//			logErr("acquireGameLanguage: found bad ptr for sysLangPtr: %p ", (void*)sysLangPtr);
//			return false;
//		}
//		uintptr_t sysLangAddr = *(uintptr_t*)sysLangPtr;
//		if (MemHelper::isBadReadPtr((void*)sysLangAddr)) {
//			logErr("acquireGameLanguage: found bad ptr for sysLangAddr: %p ", (void*)sysLangAddr);
//			return false;
//		}
//		std::string languageStr(reinterpret_cast<char const*>(sysLangAddr));
//		m_gameLanguage = setGameLanguage(languageStr);
//		logInfo("m_gameLanguage enum: %d setting the game to: %s ", (int)m_gameLanguage, languageStr.c_str());
//
//
//		//uintptr_t languageInfoStrPtr = MemHelper::getModuleBaseAddr() + languageStrOffset;
//		//if (!MemHelper::isBadReadPtr((void*)sysLangPtr)) {
//		//	std::string languageInfoStr(reinterpret_cast<char const*>(languageInfoStrPtr));
//		//	m_gameLanguage = setGameLanguage(languageInfoStr);
//		//	//logInfo("acquireGameLanguage: languageInfoStr: %s, GameLanguage enum: %d", languageInfoStr.c_str(), (int)m_gameLanguage);
//		//	
//		//	/*std::cout << "acquireGameLanguage: languageInfoStr:" << languageInfoStr << " GameLanguage enum: " << (int)m_gameLanguage << std::endl;*/
//
//		//}
//		//else {
//		//	logErr("acquireGameLanguage: found bad ptr for addr: %p ", (void*)languageInfoStrPtr);
//		//	//logErr("acquireGameLanguage: BAD PTR ERROR, could not find languageInfoStrPtr. Language now should be set to default (English). GameLanguage enum: %d", (int)m_gameLanguage);
//		//}
//	}
//	catch (const std::exception& ex)
//	{
//		logErr("acquireGameLanguage: exception error: %s ", ex.what());
//		return false;
//		//logErr("acquireGameLanguage: exception error, %s", ex.what());
//	}
//
//	return true;
//}

  /*bool LangManager::acquirreSysLangFuncStartAddr(__int64 sysLangFuncStartAddr) {
	 logDebug("acquirreSysLangFuncStartAddr");
	 if (MemHelper::isBadReadPtr((void*)sysLangFuncStartAddr)) {
		 return false;
	 }
	 m_sysLangPtrToPtr = sysLangFuncStartAddr;
	 logInfo("acquirreSysLangFuncStartAddr: m_sysLangPtrToPtr is being set to : %p ", (void*)m_sysLangPtrToPtr);
	 return true;
 }*/

  GameLanguage LangManager::getGameLanguage() {
	 logDebug("getGameLanguage");
	 return m_gameLanguage;
 }

  void LangManager::setLocalizedBindStringData() {
	 logDebug("setLocalizedBindStringData");
	 std::u8string localizeFragGrenadeStr = u8"undefined";
	 std::u8string localizeIceGrenadeStr = u8"undefined";

	 switch (m_gameLanguage)
	 {
	 case GameLanguage::English:
		 localizeFragGrenadeStr = FragGrenadeEnglishStr;
		 localizeIceGrenadeStr = IceGrenadeEnglishStr;
		 break;
	 case GameLanguage::French:
		 localizeFragGrenadeStr = FragGrenadeFrenchStr;
		 localizeIceGrenadeStr = IceGrenadeFrenchStr;
		 break;
	 case GameLanguage::German:
		 localizeFragGrenadeStr = FragGrenadeGermanStr;
		 localizeIceGrenadeStr = IceGrenadeGermanStr;
		 break;
	 case GameLanguage::Italian:
		 localizeFragGrenadeStr = FragGrenadeItalianStr;
		 localizeIceGrenadeStr = IceGrenadeItalianStr;
		 break;
	 case GameLanguage::Japanese:
		 localizeFragGrenadeStr = FragGrenadeJapanStr;
		 localizeIceGrenadeStr = IceGrenadeJapanStr;
		 break;
	 case GameLanguage::Polish:
		 localizeFragGrenadeStr = FragGrenadePolishStr;
		 localizeIceGrenadeStr = IceGrenadePolishStr;
		 break;
	 case GameLanguage::Portuguese:
		 localizeFragGrenadeStr = FragGrenadePortugeseStr;
		 localizeIceGrenadeStr = IceGrenadePortugeseStr;
		 break;
	 case GameLanguage::Russian:
		 localizeFragGrenadeStr = FragGrenadeRussianStr;
		 localizeIceGrenadeStr = IceGrenadeRussianStr;
		 break;
	 case GameLanguage::Spanish:
		 localizeFragGrenadeStr = FragGrenadeSpanishStr;
		 localizeIceGrenadeStr = IceGrenadeSpanishStr;
		 break;
	 default:
		 //! default: english data (for korean, chinesse...)
		 localizeFragGrenadeStr = FragGrenadeEnglishStr;
		 localizeIceGrenadeStr = IceGrenadeEnglishStr;
		 break;
	 }
	 m_LocalizedBindStringData = LocalizedBindStringData(m_gameLanguage, localizeFragGrenadeStr, localizeIceGrenadeStr);
 }

  LocalizedBindStringData& LangManager::getLocalizedBindStringData() {
	 logDebug("getLocalizedBindStringData");
	 if (m_gameLanguage == GameLanguage::Undefined) {
		 if (!acquireGameLanguage()) {
			 logWarn("Failed to acquire game language, setting lang to English");
		 }
		 //acquireGameLanguage();
		 setLocalizedBindStringData();
	 }
	 return m_LocalizedBindStringData;
 }
