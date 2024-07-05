#pragma once
#include "CommonDE.h"
#include <string>

class LocalizedBindStringData
{
private:
	GameLanguage m_lang = GameLanguage::English;
	std::u8string m_equipmentLauncherOverwriteStr = FragGrenadeEnglishStr;
	//std::u8string m_missionInformationOverwriteStr = IceGrenadeEnglishStr;
	std::u8string m_switchEquipmentOverwriteStr = IceGrenadeEnglishStr;

public:

	LocalizedBindStringData(){}

	LocalizedBindStringData(GameLanguage lang, std::u8string equipmentLauncherOverwriteStr, std::u8string switchEquipmentOverwriteStr): m_lang{ lang }, m_equipmentLauncherOverwriteStr{ equipmentLauncherOverwriteStr }, m_switchEquipmentOverwriteStr{ switchEquipmentOverwriteStr }
	{

	}

	std::u8string& getEquipmentLauncherOverwriteStr();

	

	std::u8string& getSwitchEquipmentOverwriteStr();

};



// whole class bak before modif

//#pragma once
//#include "CommonDE.h"
//#include <string>
//
//class LocalizedBindStringData
//{
//private:
//	GameLanguage m_lang = GameLanguage::English;
//	std::u8string m_equipmentLauncherOverwriteStr = FragGrenadeEnglishStr;
//	std::u8string m_missionInformationOverwriteStr = IceGrenadeEnglishStr;
//	std::u8string m_switchEquipmentOverwriteStr = IceGrenadeEnglishStr;
//
//public:
//
//	LocalizedBindStringData() {}
//
//	LocalizedBindStringData(GameLanguage lang, std::u8string equipmentLauncherOverwriteStr, std::u8string missionInformationOverwriteStr) : m_lang{ lang }, m_equipmentLauncherOverwriteStr{ equipmentLauncherOverwriteStr }, m_missionInformationOverwriteStr{ missionInformationOverwriteStr }
//	{
//
//	}
//	std::u8string& getEquipmentLauncherOverwriteStr() {
//		return m_equipmentLauncherOverwriteStr;
//	}
//
//	std::u8string& getMissionInformationOverwriteStr() {
//		return m_missionInformationOverwriteStr;
//	}
//
//	std::u8string& getSwitchEquipmentOverwriteStr() {
//		return m_swi;
//	}
//
//};



