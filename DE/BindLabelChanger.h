
#pragma once
#include <vector>
#include "ControllerLayout.h"
#include "MemHelper.h"
#include "../Config/Config.h"
#include "LocalizedBindStringData.h"

class BindLabelChanger
{
private:
    static inline __int64 m_idStringBigAddrStart = 0;
    static inline std::vector<ControllerLayout> m_controllerLayouts;
    static inline std::vector<std::string> m_localizedGrenadStrsVec;
    static inline bool m_isEquipmentLauncherFlag = false;
    static inline bool m_isSwitchEquipmentFlag = false;
    static inline bool m_isOverwriteControllerBindStrAttempt = false;

    static void createControllerLayoutsVec();

public:
    BindLabelChanger();

    static bool acquirreIdStringBigListOffset(int offset);

    static void overwriteControllerLabels(LocalizedBindStringData localizedOverwriteData);

    static void overwriteDynamicBindLabels(unsigned char* strPtr, LocalizedBindStringData localizedOverwriteData);

    static bool isControllerStaticStringsOverwriteAttempt();
};















//#pragma once
//#include <vector>
//#include "ControllerLayout.h"
//#include "MemHelper.h"
//#include "../Config/Config.h"
//
//
///// <summary>
///// This is what overwrites the mission information and Equipment Launcher so they correspong to Frag Grenade and Ice Grenade not only in english but in any language supported by the game. In memory the data is actually a list of IdStr. Each IdStr corresponds to a controller layout and contains a list of strings that represent the label of each button on the controller. 
///// </summary>
//class BindLabelChanger
//{ 
//
//private:
//	
//	//? hopefully we'll do something better next refactor:
//	static __int64 m_idStringBigAddrStart;
//	//unsigned int m_idStringListBaseOffset = 0x6B94670; //old offset with denuvo
//	std::vector<ControllerLayout> m_controllerLayouts;
//	std::vector<std::string> m_localizedGrenadStrsVec;
//
//	bool m_isEquipmentLauncherFlag = false;
//	//bool m_isMissionInformationFlag = false;
//	bool m_isSwitchEquipmentFlag = false;
//
//	//! it's no use to keep overwriting those static stings if we failed the first time.
//	bool m_isOverwriteControllerBindStrAttempt = false;
//
//
//	//! the offset for the 2 str are actually offsets to pointers to str and not addrres to str.
//	void createControllerLayoutsVec() {
//		logDebug("createControllerLayoutsVec");
//
//		m_controllerLayouts.clear(); //! not necessary, just safety in case it's called twice.
//		//! base offset, equipment launcher offset, switch equipment offset:
//		//m_controllerLayouts.push_back(ControllerLayout("Default", 0, std::vector<int>{0xD8, 0x2E8}));
//		m_controllerLayouts.push_back(ControllerLayout("Default", 0, 0xC8, 0x308)); 
//		//m_controllerLayouts.push_back(ControllerLayout("Classic", 0x18, std::vector<int>{0x108, 0x2E8}));
//		m_controllerLayouts.push_back(ControllerLayout("Classic", 0x18, 0xF8, 0x308));
//		//m_controllerLayouts.push_back(ControllerLayout("Knucles", 0x30, std::vector<int>{0xD8, 0x138}));
//		m_controllerLayouts.push_back(ControllerLayout("Knucles", 0x30, 0xC8, 0x308));
//		//m_controllerLayouts.push_back(ControllerLayout("Mirrored", 0x48, std::vector<int>{0x108, 0x2E8}));
//		m_controllerLayouts.push_back(ControllerLayout("Mirrored", 0x48, 0xF8, 0x308));
//		//m_controllerLayouts.push_back(ControllerLayout("Strafe", 0x60, std::vector<int>{0x108, 0x2E8}));
//		m_controllerLayouts.push_back(ControllerLayout("Strafe", 0x60, 0xF8, 0x308));
//		//m_controllerLayouts.push_back(ControllerLayout("Tactical", 0x78, std::vector<int>{0x168, 0x2E8}));
//		m_controllerLayouts.push_back(ControllerLayout("Tactical", 0x78, 0x158, 0x308));
//		//! the last layout (custom) is handled another way cause it's customizable by the user so the data is handled differently by the game.
//	}	
//
//	
//	
//	
//
//public:
//
//	BindLabelChanger()
//	{
//		createControllerLayoutsVec();
//	}
//
//	static bool acquirreIdStringBigListOffset(int offset) {
//		logDebug("acquirreIdStringBigListOffset");
//
//		if (offset <= 0) { // < cause neg offset would be out of game memory for sure
//			logWarn("acquirreIdStringBigListOffset: idStringBigListOffset <= 0, setting m_idStringBigListAddr to 0 so it triggers bad ptr ");
//			return false;
//			//m_idStringBigListAddr = 0;
//		}
//		else {
//			m_idStringBigAddrStart = MemHelper::getModuleBaseAddr() + offset;
//			logInfo("acquirreIdStringBigListOffset: m_idStringBigAddrStart: %p", (void*)m_idStringBigAddrStart);
//			if (!MemHelper::isBadReadPtr((void*)m_idStringBigAddrStart)) {
//				return true;
//			}			
//		}
//		return false;
//		
//
//	}
//
//	//! this will overwrite all the static bind labels str for all controller layout exect the custom one.
//	void overwriteControllerLabels(LocalizedBindStringData localizedOverwriteData) {
//		logDebug("overwriteControllerLabels");
//
//	
//		if (MemHelper::isBadReadPtr((void*)m_idStringBigAddrStart)) {
//			logErr("overwriteControllerLabels: found bad ptr for addr: %p can not overwrite controller labels strings.", (void*)m_idStringBigAddrStart);
//			return;
//		}		
//
//		logInfo("overwriteControllerLabels:  m_idStringBigAddrStart: %p. Attempting to Overwrite Bind labels...", (void*)m_idStringBigAddrStart);
//		for (size_t i = 0; i < m_controllerLayouts.size(); i++)
//		{
//			uintptr_t idStrAddr = *(uintptr_t*)(m_idStringBigAddrStart + m_controllerLayouts[i].getControllerLayoutOffset());
//			if (MemHelper::isBadReadPtr((void*)idStrAddr)) {
//				logErr("overwriteControllerLabels: found bad ptr for idStrAddr: %p can not overwrite bind strings for controller layout: %s", (void*)idStrAddr, m_controllerLayouts[i].getLayoutName().c_str());
//				continue;
//			}
//			m_controllerLayouts[i].overwriteBindLabels(localizedOverwriteData, m_idStringBigAddrStart);
//		}
//
//		m_isOverwriteControllerBindStrAttempt = true;
//	}
//
//	/*
//	
//	19:10:59.677      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: Creuset / Marteau sentinelle
//	19:10:59.677      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: #str_bind_slayer_quick0
//	19:10:59.677      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: #str_bind_slayer_quick0_CONTROLLER
//	19:10:59.677      BindLabelChanger.h:112   INFO| m_isSwitchEquipmentFlag detected overwriting...
//	19:10:59.678      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: Changer d’équipement
//	19:10:59.678      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: #str_bind_slayer_dash
//	....
//	19:11:06.804      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: Changer de module d’arme
//	19:11:06.804      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: #str_bind_slayer_quick0
//	19:11:06.805      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: Changer d’équipement
//	19:11:06.805      BindLabelChanger.h:112   INFO| m_isSwitchEquipmentFlag detected overwriting...
//	19:11:06.805      BindLabelChanger.h:104   INFO| overwriteDynamicBindLabels: str: #str_bind_slayer_weapnext
//
//	*/
//	//? this func is backed up below just in case
//	void overwriteDynamicBindLabels(unsigned char* strPtr, LocalizedBindStringData localizedOverwriteData) {
//		logDebug("overwriteDynamicBindLabels");
//
//		//logInfo("overwriteDynamicBindLabels triggered");
//		try
//		{
//			std::string str(reinterpret_cast<char const*>(strPtr));
//			//logInfo("overwriteDynamicBindLabels: str: %s", str.c_str());
//			if (m_isEquipmentLauncherFlag && str != EquipmentLauncherControllerFlagStr) {
//				//logInfo("m_isEquipmentLauncherFlag Bind detected overwriting...");
//				std::string replacementStrFormatedForCopy(localizedOverwriteData.getEquipmentLauncherOverwriteStr().cbegin(), localizedOverwriteData.getEquipmentLauncherOverwriteStr().cend());
//				strcpy((char*)strPtr, replacementStrFormatedForCopy.c_str());
//				m_isEquipmentLauncherFlag = false;
//			}
//			else if (m_isSwitchEquipmentFlag && str != SwitchEquipmentControllerFlagStr) {
//				//logInfo("m_isSwitchEquipmentFlag Bind detected overwriting...");
//				std::string replacementStrFormatedForCopy(localizedOverwriteData.getSwitchEquipmentOverwriteStr().cbegin(), localizedOverwriteData.getSwitchEquipmentOverwriteStr().cend());
//				strcpy((char*)strPtr, replacementStrFormatedForCopy.c_str());
//				m_isSwitchEquipmentFlag = false;
//			}
//			else if (str == EquipmentLauncherFlagStr) {
//				//logInfo("setting m_isEquipmentLauncherFlag to true");
//				m_isEquipmentLauncherFlag = true;
//			}
//			else if (str == SwitchEquipmentFlagStr) {
//				//logInfo("setting SwitchEquipmentFlagStr to true");
//				m_isSwitchEquipmentFlag = true;
//			}
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("overwriteDynamicBindLabels: exception error: %s (resseting flags)", ex.what());
//			m_isEquipmentLauncherFlag = false;
//			m_isSwitchEquipmentFlag = false;
//		}
//	}
//
//	bool isControllerStaticStringsOverwriteAttempt() {
//		logDebug("isControllerStaticStringsOverwriteAttempt");
//		return m_isOverwriteControllerBindStrAttempt;
//	}
//	
//};
//
//__int64 BindLabelChanger::m_idStringBigAddrStart = 0;
//
