//#pragma once
//
//#include "../DE/CommonDE.h"
//#include "../DE/MemHelper.h"
//#include "../DE/ObjectLocator.h"
//#include "../DE/Config.h"
//
//
////? not using this anymore not only because we found a much efficient method but because those ids for nade types or weapons are not reliable because some mods can modify them like the Gameplay Qol mod: 
//class EquipmentLauncher
//{
//private:
//	const unsigned int m_fragTypeId = 9843;
//	const unsigned int m_iceTypeId = 0x276A;
//
//	bool m_isFragThrowRequestFlag = false;
//	bool m_isIceThrowRequestFlag = false;
//
//	bool m_isFragOwned = false;
//	bool m_isIceOwned = false;
//
//	NadeStatus m_nadeStatus = NadeStatus::unknownNade;
//
//	//__int64 m_idHud_WeaponInfoPtr = 0;
//	//__int64 m_idPlayerPtr = 0;
//
//	const int m_normalNadeSelected = 0; //! val in memory
//	const int m_iceNadeSelected = 1;	//! val in memory
//
//	
//	//todo we have to check if the get nade status has error and disable the mod if that is the case
//
//public:
//
//	void enableFragRequestFlag() {
//		m_isFragThrowRequestFlag = true;
//	}
//
//	void disableFragRequestFlag() {
//		m_isFragThrowRequestFlag = false;
//	}
//
//	bool isFragRequestFlag() {
//		return m_isFragThrowRequestFlag;
//	}
//
//	/*bool isFragOwned() {
//		return m_isFragOwned;
//	}*/
//
//	bool isFragSelected() {
//		return m_nadeStatus == NadeStatus::fragNade;
//	}
//
//
//	void enableIceRequestFlag() {
//		m_isIceThrowRequestFlag = true;
//	}
//
//	void disableIceRequestFlag() {
//		m_isIceThrowRequestFlag = false;
//	}
//
//	bool isIceRequestFlag() {
//		return m_isIceThrowRequestFlag;
//	}
//
//	/*bool isIceOwned() {
//		return m_isIceOwned;
//	}*/
//
//	bool isIceSelected() {
//		return m_nadeStatus == NadeStatus::iceNade;
//	}
//
//	//! we use state for nade status cause it will be call once in the enum that check for the throw nade btn and that is enough
//	void updateNadeStatus() {
//		static NadeStatus lastNadeStatus = NadeStatus::unknownNade;
//		try
//		{
//			__int64 idPlayerPtr = ObjectLocator::getIdPlayerPtr();
//
//			if (MemHelper::isBadReadPtr((void*)(idPlayerPtr))) {
//				logWarn(" updateNadeStatus: m_idPlayerPtr is BadReadPtr: %p", (void*)idPlayerPtr);
//				//spdlog::warn("EquipmentLauncher::updateNadeStatus: m_idPlayerPtr is BadReadPtr: {:x} ", m_idPlayerPtr);
//				m_nadeStatus = NadeStatus::unknownNade;
//			}
//			else if ((MemHelper::isBadReadPtr((void*)(idPlayerPtr + idPlayerNadeStatusOffset)))) {
//				logWarn("EquipmentLauncher::updateNadeStatus: m_idPlayerPtr + idPlayerNadeStatusOffset is BadReadPtr: %p ", (void*)(idPlayerPtr + idPlayerNadeStatusOffset));
//				m_nadeStatus = NadeStatus::unknownNade;
//			}
//			else {
//				int nadeStatus = *(int*)(idPlayerPtr + idPlayerNadeStatusOffset);
//				//spdlog::warn("EquipmentLauncher::updateNadeStatus: nadeStatus: {} ", nadeStatus);
//				if (nadeStatus == m_iceNadeSelected) {
//					m_nadeStatus = NadeStatus::iceNade;
//					//spdlog::warn("MemHelper::getNadeStatus: ICE Nade ");
//
//				}
//				else if (nadeStatus == m_normalNadeSelected) {
//					m_nadeStatus = NadeStatus::fragNade;
//					//spdlog::warn("MemHelper::getNadeStatus: NORMAL Nade ");
//				}
//				else {
//					m_nadeStatus = NadeStatus::unknownNade;
//				}
//			}
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("EquipmentLauncher::updateNadeStatus: exception Error: %s ", ex.what());
//			m_nadeStatus = NadeStatus::unknownNade;
//		}
//		if (lastNadeStatus != m_nadeStatus) {
//			lastNadeStatus = m_nadeStatus;
//			printNadeStatusChange();
//		}
//	}
//
//	void printNadeStatusChange()
//	{
//		switch (m_nadeStatus)
//		{
//		case undefinedNade:
//			logWarn("EquipmentLauncher::printNadeStatusChange(): undefinedNade");
//			break;
//		case iceNade:
//			logInfo("EquipmentLauncher::printNadeStatusChange(): iceNade");
//			break;
//		case fragNade:
//			logInfo("EquipmentLauncher::printNadeStatusChange(): normalNade");
//			break;
//		/*case badPtrNade:
//			spdlog::error("EquipmentLauncher::printNadeStatusChange(): badPtrNade");
//			break;*/
//		case unknownNade:
//			logWarn("EquipmentLauncher::printNadeStatusChange(): unknownNade");
//			break;
//		/*case errorNade:
//			spdlog::error("EquipmentLauncher::printNadeStatusChange(): errorNade");
//			break;
//		case MAX_NADE_STATUS:
//			spdlog::error("EquipmentLauncher::printNadeStatusChange(): MAX_NADE_STATUS");
//			break;*/
//		default:
//			logErr("EquipmentLauncher::printNadeStatusChange(): default case, how could this happen??");
//			break;
//		}
//	}
//
//	//void updateOwnedGrenades(std::vector<unsigned int> ownedItemsIdsVec) {
//	//	m_isFragOwned = false;
//	//	m_isIceOwned = false;
//
//	//	for (size_t i = 0; i < ownedItemsIdsVec.size(); i++)
//	//	{
//	//		if (ownedItemsIdsVec[i] == m_fragTypeId) {
//	//			m_isFragOwned = true;
//	//		}
//	//		else if (ownedItemsIdsVec[i] == m_iceTypeId) {
//	//			m_isIceOwned = true;
//	//		}
//	//		if (m_isFragOwned == true && m_isIceOwned == true) {
//	//			//spdlog::debug("EquipmentLauncher::updateOwnedGrenades(): found both grenades types");
//	//			break;
//	//		}
//	//	}
//	//}
//
//	//void reset() {
//	//	m_isFragThrowRequestFlag = false;
//	//	m_isIceThrowRequestFlag = false;
//	//	m_nadeStatus = NadeStatus::undefinedNade;
//	//	/*m_isFragOwned = false;
//	//	m_isIceOwned = false;*/
//	//}
//
//
//	//void aquire_idHudWeaponInfoPtr(const __int64 idHud_WeaponInfoPtr)
//	//{//! this is trigger when the hook is triggered but the hook trigger will depend if the hud is disable or not.
//	//	try
//	//	{
//	//		if (MemHelper::isBadReadPtr((void*)(idHud_WeaponInfoPtr)) || (MemHelper::isBadReadPtr((void*)(idHud_WeaponInfoPtr + MemHelper::idHudWeaponInfoNadeStatusOffset)))) {
//	//			spdlog::warn("EquipmentLauncher::aquire_idHudWeaponInfoPtr: found BadReadPtr for idHud_WeaponInfoPtr: {:x} ", idHud_WeaponInfoPtr);
//	//		}
//	//	}
//	//	catch (const std::exception& ex)
//	//	{
//	//		spdlog::error("EquipmentLauncher::aquire_idHudWeaponInfoPtr: exception Error: {} setting m_idHud_WeaponInfoPtr to 0.", ex.what());
//	//		m_idHud_WeaponInfoPtr = 0;
//	//	}
//	//	if (m_idHud_WeaponInfoPtr != idHud_WeaponInfoPtr) {
//	//		m_idHud_WeaponInfoPtr = idHud_WeaponInfoPtr;
//	//		spdlog::info("EquipmentLauncher::aquire_idHudWeaponInfoPtr: idHud_WeaponInfoPtr has changed and is now: {:x} ", idHud_WeaponInfoPtr);
//	//	}
//	//}
//
//	/*void aquire_idPlayerPtr(const __int64 idPlayerPtr)
//	{
//		try
//		{
//
//			if (MemHelper::isBadReadPtr((void*)(idPlayerPtr))) {
//				logWarn("EquipmentLauncher::aquire_idPlayerPtr: found BadReadPtr for idPlayerPtr: %p setting m_idPlayerPtr to 0", (void*)idPlayerPtr);
//				m_idPlayerPtr = 0;
//			}
//			else {
//				if (m_idPlayerPtr != idPlayerPtr) {
//					m_idPlayerPtr = idPlayerPtr;
//					logInfo("EquipmentLauncher::aquire_idPlayerPtr: m_idPlayerPtr has changed and is now: %p ", (void*)m_idPlayerPtr);
//				}
//			}
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("EquipmentLauncher::aquire_idPlayerPtr: exception Error: %s setting m_idPlayerPtr to 0.", ex.what());
//			m_idPlayerPtr = 0;
//		}		
//	}*/
//
//
//
//};
//
