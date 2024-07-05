#pragma once

#include <Windows.h>
#include <string>
#include "CommonDE.h"
//#include "BindString.h"
#include "MemHelper.h"
#include "../Config/Config.h"



/// <summary>
/// This is not used anymore as this is simply not the correct way to do it.
/// </summary>
//class StringChanger
//{
//
//
//private:
//
//	std::vector<unsigned int>m_useEquipmentBindStaticOffsets{ 0x0, 0x408 }; //! static ptr for this str are 2DF797F and 2E681D7 there are more statics ones i didn't write down but you can find them in CE if you scan for them.	
//	uintptr_t m_useEquipmentBindStrBasePtr = 0x04305888;
//	BindString m_useEquipmentBindStr = BindString(EquipmentLauncherStr, EquipmentLauncherStr.size(), FragGrenadeStr, m_useEquipmentBindStrBasePtr, m_useEquipmentBindStaticOffsets);
//
//	std::vector<unsigned int>m_missionInformationStrOffsets{ 0x0, 0x348 };
//	uintptr_t m_missionInfoBindStrBasePtr = 0x04305888;
//	BindString m_missionInfoBindStr = BindString(MissionInformationStr, MissionInformationStr.size(), IceGrenadeStr, m_missionInfoBindStrBasePtr, m_missionInformationStrOffsets);
//
//public:
//
//	void overwriteBindStrings()
//	{
//		overwriteString(m_useEquipmentBindStr);
//		overwriteString(m_missionInfoBindStr);
//	}
//
//
//
//	void overwriteString(BindString& bindString)
//	{
//		try
//		{
//			if (bindString.isOverwritten()) {
//				return;
//			}
//			/*else {
//				spdlog::debug("MemHelper::overwriteString:bindString.getOriginalStr() is: {}  bindString.isOverwritten() is: {} ", bindString.getOriginalStr(), bindString.isOverwritten());
//			}*/
//
//			uintptr_t basePtrAddr = MemHelper::getModuleBaseAddr() + bindString.getBasePtrOffset();
//			uintptr_t finalAddr = MemHelper::FindPtrAddress(basePtrAddr, bindString.getOffsetsVec());
//
//			size_t originalStrLength = bindString.getOriginalStrLength();
//			if (originalStrLength <= 0) {
//				logWarn("StringChanger::overwriteString: OriginalStrLength is %d returning ", originalStrLength);
//				return;
//			}
//			for (size_t i = 0; i < originalStrLength; i++)
//			{
//				if (MemHelper::isBadReadPtr((void*)finalAddr)) {
//					logWarn("StringChanger::overwriteString: found BadReadPtr for bindString : %s finalAddr: %X returning ", bindString.getOriginalStr().c_str(), finalAddr);
//					return;
//				}
//				if (i == originalStrLength - 1 || (i > (bindString.getNewStr().size() - 1))) {
//					DWORD old;
//					VirtualProtect((LPVOID)finalAddr, 1, PAGE_EXECUTE_READWRITE, &old);
//					*(char*)finalAddr = '\0';
//					VirtualProtect((LPVOID)finalAddr, 1, old, &old);
//				}
//				else {
//					DWORD old;
//					VirtualProtect((LPVOID)finalAddr, 1, PAGE_EXECUTE_READWRITE, &old);
//					*(char*)finalAddr = bindString.getNewStr()[i];
//					VirtualProtect((LPVOID)finalAddr, 1, old, &old);
//				}
//				finalAddr++;
//			}
//			logInfo("StringChanger::overwriteString: Succes ovewriting OriginalStr: %s with NewStr: %s bindString.setOverwritten() called ", bindString.getOriginalStr().c_str(), bindString.getNewStr().c_str());
//			bindString.setOverwritten();
//			/*spdlog::debug("StringChanger::overwriteString: Succes addenum: OriginalStr: {} bindString.isOverwritten() val is {} ", bindString.getOriginalStr(), bindString.isOverwritten());*/
//			return;
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("StringChanger::overwriteString: exception ERROR: %s returning ", ex.what());
//			return;
//		}
//	}
//
//};

