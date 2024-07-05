
#pragma once

#include <string>
#include <vector>
#include "MemHelper.h"
#include "../Config/Config.h"
#include "LocalizedBindStringData.h"

class ControllerLayout
{
public:
    ControllerLayout(std::string name, unsigned int ControllerLayoutOffset, int equipmentLauncherStrOffset, int missionInfoStrOffset);
    ControllerLayout(std::string name, unsigned int ControllerLayoutOffset, std::vector<int> stringsAddrOffsetsVec);
    void overwriteBindLabels(LocalizedBindStringData& localBindStringData, uintptr_t idStrListFirstPtr);
    std::string getLayoutName();
    unsigned int getControllerLayoutOffset();
    int getEquipmentLauncherStrOffset();
    int getMissionInfoStrOffset();

private:
    static inline std::string m_name = "";
    static inline unsigned int m_idStrOffset = 0;
    static inline int m_missionInfoStrPtrOffset = -1;
    static inline int m_equipmentLauncherStrPtrOffset = -1;
    static inline std::vector<int> m_stringAddrOffsetsVec;

    void overwriteBindLabel(uintptr_t idStrAddr, int bindStrOffset, std::u8string& replacementStr);
};














//#pragma once
//#include <string>
//
///// <summary>
///// ControllerLayouts are actually, in memory, a "list" of idStr objects, each idStr obj contains all the bind string labels for a specific in game layout (default, tactical, knucles...)
///// </summary>
//class ControllerLayout
//{
//private:
//	std::string m_name = "";
//	unsigned int m_idStrOffset = 0;				//! offset value from the first idStr in the list
//	int m_missionInfoStrPtrOffset = -1;			//! offset value from current idStr base
//	int m_equipmentLauncherStrPtrOffset = -1;		//! offset value from current idStr base
//	std::vector<int> m_stringAddrOffsetsVec;
//
//public:
//
//	ControllerLayout(std::string name, unsigned int ControllerLayoutOffset,  int equipmentLauncherStrOffset, int missionInfoStrOffset):m_name{ name }, m_idStrOffset{ ControllerLayoutOffset }, m_equipmentLauncherStrPtrOffset{ equipmentLauncherStrOffset }, m_missionInfoStrPtrOffset{ missionInfoStrOffset }
//	{
//
//	}
//
//	ControllerLayout(std::string name, unsigned int ControllerLayoutOffset, std::vector<int>stringsAddrOffsetsVec) : m_name{ name }, m_idStrOffset{ ControllerLayoutOffset }, m_stringAddrOffsetsVec{ stringsAddrOffsetsVec }
//	{
//
//	}
//
//	void overwriteBindLabels(LocalizedBindStringData& localBindStringData, uintptr_t idStrListFirstPtr) {
//		logDebug("overwriteBindLabels");
//
//		try
//		{
//			uintptr_t idStrAddr = *(uintptr_t*)(idStrListFirstPtr + m_idStrOffset);
//			if (MemHelper::isBadReadPtr((void*)idStrAddr)) {
//				logErr("overwriteBindLabels: found bad ptr for idStrAddr: %p can not overwrite bind string for controller layout: %s ", (void*)idStrAddr, m_name.c_str());
//				return;
//			}
//			overwriteBindLabel(idStrAddr, m_equipmentLauncherStrPtrOffset, localBindStringData.getEquipmentLauncherOverwriteStr());
//			overwriteBindLabel(idStrAddr, m_missionInfoStrPtrOffset, localBindStringData.getSwitchEquipmentOverwriteStr());
//			//uintptr_t existingStrPtr = idStrAddr + getEquipmentLauncherStrOffset();
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("overwriteBindLabels: exception error: %s ", ex.what());
//		}
//		
//	}
//
//	void overwriteBindLabel(uintptr_t idStrAddr, int bindStrOffset, std::u8string& replacementStr) {
//		logDebug("overwriteBindLabel");
//
//		//uintptr_t existingStrAddr = idStrAddr + bindStrOffset;
//		try
//		{
//			uintptr_t strAddr = *(uintptr_t*)(idStrAddr + bindStrOffset);
//			if (MemHelper::isBadReadPtr((void*)strAddr)) {
//				logErr("overwriteBindLabel: bad ptr for : %p can not overwrite bind string ", (void*)strAddr);
//				return;
//			}
//			std::string existingStr(reinterpret_cast<char const*>(strAddr));
//			logInfo("overwriteBindLabel: at address %p for controller layout: %s found existing str: %s (orginal str length: %zu, replacement str length: %zu) ", (void*)strAddr, m_name.c_str(), existingStr.c_str(), existingStr.size(), replacementStr.size());
//			std::string replacementStrFormatedForCopy(replacementStr.cbegin(), replacementStr.cend());
//			strcpy((char*)strAddr, replacementStrFormatedForCopy.c_str());
//			logInfo("overwriteBindLabel: succes overwriting original string: %s with: %s", existingStr.c_str(), replacementStrFormatedForCopy.c_str());
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("overwriteBindLabel: exception error: %s ", ex.what());
//		}
//		/*return false;*/
//		
//		//todo need to check length
//		//strcpy((char*)strAddr, replacementStr.c_str());
//
//	}
//
//	std::string getLayoutName() {
//		logDebug("getLayoutName");
//
//		return m_name;
//	}
//
//	unsigned int getControllerLayoutOffset() {
//		logDebug("getControllerLayoutOffset");
//		return m_idStrOffset;
//	}
//
//	int getEquipmentLauncherStrOffset() {
//		logDebug("getEquipmentLauncherStrOffset");
//		return m_equipmentLauncherStrPtrOffset;
//	}
//
//	int getMissionInfoStrOffset() {
//		logDebug("getMissionInfoStrOffset");
//		return m_missionInfoStrPtrOffset;
//	}
//
//	
//
//};
//
