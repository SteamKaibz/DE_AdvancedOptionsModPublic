//#pragma once
//
//#include <vector>
//#include <string>
//#include "Config.h"
//#include "ReclassTypes.h"
//#include "IniConfig.h"
//
////! used to figure out the hash of all the hud's elements so we can identify/change them easily
//struct spriteDebug {
//	int fullPathHash = 0;
//	int visIndex = 0;
//	std::string name = "unknown";
//
//	void print() {
//		logInfo("print: name: %s, fullPathHash: %d, visIndex: %d, ", name.c_str(), fullPathHash, visIndex);
//	}
//};
//
////! basically a hasid/sprite instance map
////struct SpriteIdData {
////	int fullPathHash = 0;
////	__int64 address = 0;
////};
//
///// <summary>
///// ued mainly to change the colors of the game's hud elements my modifying each element's idSWFSpriteInstance
///// </summary>
////! if i understand correctly a hud element must NOT be overiden when a level load, otherwise i will not be able to restore the hud element to its default profile state colors by reaaplying the colors, the hud element itself will need to be updated by the game, like gaining bp points for ex, at least it seems that way so far, you can reproduce by loading the mod, enable the overide of a hud elelment, reload a level, you should not be able to restore the default color, but if you have the overide disabled and you reload the level you should be able to switch back and forth...May be i could fix it by disabling the return in setSpriteInstanceColorHook if we are not in game. Update indeed that did the trick.
//class GameHudColorsManager {
//private:
//	static __int64 m_currentEquipmentArrowSpriteInstanceAddr;
//	static __int64 m_EquipmentBackerSpriteInstanceAddr; //! backer is the thin green/blue bar right side of frag/ice nade icon
//
//	static __int64 m_healthIconOuterSpriteAddr;
//	static __int64 m_healthIconBgSpriteAddr;
//	static __int64 m_healthTextSpriteIdAddr;
//	static __int64 m_healthPipsOutlineSpriteIdAddr;
//	static __int64 m_healthPipsGradientBottomSpriteAddr;
//	static __int64 m_healthPipsGradientTopSpriteAddr;
//	static __int64 m_healthBgLeftLeftSpriteAddr;
//	static __int64 m_healthRightSideMiddleMiddleSpriteAddr;
//	static __int64 m_healthRightSideRightRightSpriteAddr;
//	static __int64 m_healthGlowSpriteIdSpriteAddr;
//	static __int64 m_healthPulseLoopSpriteAddr;
//	static __int64 m_healthBottomAdornmentSpriteAddr;
//	static __int64 m_healthRightSideAddAmountSpriteAddr;
//	static __int64 m_healthrightSideRightborderSpriteAddr;
//
//	static __int64 m_armorBarGradientSpriteAddr;
//	static __int64 m_armorBarBaseSpriteAddr;
//	static __int64 m_armorRightSideSpriteAddr;
//	static __int64 m_armorTextSpriteAddr;
//	static __int64 m_armorIconSpritAddr;
//	static __int64 m_armorIconGlowSpriteAddr;
//	static __int64 m_armorInfoSpriteAddr;
//	static __int64 m_armorBgSpriteAddr;
//
//	static __int64 m_weaponInfoCoolDownSpriteAddr;
//	static __int64 m_weaponInfoBgModlessSpriteAddr;
//	static __int64 m_weaponInfoTextSpriteAddr;
//	static __int64 m_weaponInfoBgSpriteAddr; //! this should be the one we want for bg
//
//	static __int64 m_bloodPunchBgPulseSpriteAddr;
//	static __int64 m_bloodPunchChargeGlowBgSpriteAddr;
//	static __int64 m_bloodPunchBgImgSpriteAddr;
//	static __int64 m_bloodPunchBorderImgSpriteAddr;
//	static __int64 m_bloodPunchIconOnSpriteAddr;
//	static __int64 m_bloodPunchIconOffSpriteAddr;
//	static __int64 m_bloodPunchReadyFlashSpriteAddr;
//	static __int64 m_bloodPunchFillRightGlowSpriteAddr;
//	static __int64 m_bloodPunchFillRightImgSpriteAddr;
//	static __int64 m_bloodPunchFillLeftGlowSpriteAddr;
//	static __int64 m_bloodPunchFillLeftImgSpriteAddr;
//	static __int64 m_bloodPunchTextSpriteAddr;
//	static __int64 m_bloodPunchBindKbmSpriteAddr;
//	static __int64 m_bloodPunchBindJoySpriteAddr;
//
//	static __int64 m_bloodPunchChargeBgSpriteAddr;
//	static __int64 m_bloodPunchImgImgSpriteAddr;
//
//	static std::vector<int32_t>bloodPunchSpriteIdsVec;
//
//	static __int64 m_radSuitBarGradientSpriteAddr;
//	static __int64 m_radSuitBarBaseSpriteAddr;
//	static __int64 m_radSuitRightSideSpriteAddr;
//	static __int64 m_radSuitTextSpriteAddr;
//	static __int64 m_radSuitIconImgSpriteAddr;
//	static __int64 m_radSuitGlowImgSpriteAddr;
//	static __int64 m_radSuitBgSpriteAddr;
//	static __int64 m_radSuitBgPulseSpriteAddr;
//
//
//	static std::vector<int32_t>radSuitSpriteIdsVec;
//
//
//	static unsigned int m_testIdNamedColorIndex; //text
//	static unsigned int m_namedColorBlue; // blue
//
//	static std::vector<spriteDebug> m_spriteDebugVec;
//	static int m_hashDebugIndex;
//
//	static bool m_isEquipmentFlag;
//
//
//	static std::vector<__int64> m_spriteInstanceAddressesVec;
//	static int m_debugIndex; //used to check and modify each element 1 by 1 so we can identify who they are
//
//	static std::vector<int> m_spriteHashIdDebugVec;
//	//static int m_hashIddebugIndex;
//	//static const int m_invisibleNamedColor;
//
//	static std::vector<unsigned int> m_debugColorIdVec;
//
//	static int m_debugNamedColorIndex;
//
//	static __int32 m_invisibleFlagColorId; //! this is used as a lure so that our hook will set the color of the element to invisible when it sees this colorId
//
//public:
//
//	static __int32 getinvisibleFlagColorId() {
//		return m_invisibleFlagColorId;
//	}
//
//	//todo we need to design a system that calls forceUpdateHudElementsColors everytime a displayed hud element has changed
//	//! this is needed because some elements like the arrow of equipment are never changed by the game, but in our case it will be a way to updateColor all the colors that need to be updated.
//	static void forceUpdateHudElementsColors() {
//		logInfo("forceUpdateHudElementsColors called");
//		idCmd::reapplySwfColors();
//	}
//
//	//! will return overridden color or original color depending if each mod's feature is enabled or not
//	static unsigned int getColor(__int64 spriteInstanceAddr, unsigned int namedColorId) {
//		if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//			logErr("getColor: bad ptr: %p This should not happen...", (void*)spriteInstanceAddr);
//			return namedColorId;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		int fullPathHash = spriteInstance->fullPathHash;
//
//		if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {
//			if (IniConfig::isEquipmentArrowColorOveride()) {
//				//return SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_DEAD; // this is too purple when demon profile
//				//return SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_GRADIENT_DEAD; //good for default but bad for demon again
//				//return SWF_NAMED_COLOR_RETICLE_COOLDOWN_GLOW; //good for default but bad for demon again
//				//return SWF_NAMED_COLOR_DEMON_HUD_BACKER; //this is the darkest color so far in any profile
//				//return SWF_NAMED_COLOR_DEMON_HUD_ICON_COOLDOWN; //this is black that looks perfect. 
//				return getinvisibleFlagColorId(); //this will be used to make element invisible if we want to...
//			}
//			return getOriginalColor(fullPathHash);
//		}
//		for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
//		{
//			if (fullPathHash == bloodPunchSpriteIdsVec[i]) {
//				//logInfo("getColor: BloodPunchColor sprite DETECTED");
//				if (IniConfig::isBloodPunchColorOveride()) {
//					//logInfo("getOverriddenColor: BloodPunchColor returned....");
//					return SWF_NAMED_COLOR_DEMON_HUD_ICON_COOLDOWN;
//				}
//				return getOriginalColor(fullPathHash);
//			}
//		}
//		for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
//		{
//			if (fullPathHash == radSuitSpriteIdsVec[i]) {
//				if (IniConfig::isRadSuitColorOveride()) {
//					return SWF_NAMED_COLOR_WEAPON_BALLISTA;
//				}
//				return getOriginalColor(fullPathHash);
//			}
//		}
//		//return getOriginalColor(fullPathHash); // <= this was a mistake as it made the whole hud green
//		return namedColorId;
//	}
//
//
//	static unsigned int getOriginalColor(int spriteId) {
//		if (spriteId == 1400953715 || spriteId == 337295309 || spriteId == -1436734126 || spriteId == -1651990978 || spriteId == -1695464456 || spriteId == 841051668 || spriteId == -1642539358) {
//			return SWF_NAMED_COLOR_UI_RADIATION;
//		}
//		else if (spriteId == 247756417) {
//			return SWF_NAMED_COLOR_UI_RADIATION_GRADIENT;
//		}
//		else if (spriteId == -2014894865) {
//			return SWF_NAMED_COLOR_HUD_EQUIPMENT_FRAG; //! this is not accurate as it could also be color ice but that will do...
//		}
//		else if (spriteId == -1637630621 || spriteId == 1200615612 || spriteId == -1614698948 || spriteId == 1430400401 || spriteId == -370399847 || spriteId == 348013304) {
//			return SWF_NAMED_COLOR_HUD_TEXT;
//		}
//		else if (spriteId == 1656191230 || spriteId == 1334139029 || spriteId == -2114214347) {
//			return SWF_NAMED_COLOR_DASH_GLOW;
//		}
//		else if (spriteId == -1700059271 || spriteId == 2038383566) {
//			return SWF_NAMED_COLOR_DASH_BASE;
//		}
//		else if (spriteId == 1938093377 || spriteId == -216838433 || spriteId == -6992847 || spriteId == -1035373996 || spriteId == -33397220) {
//			return SWF_NAMED_COLOR_HUD_HEADER;
//		}
//		logWarn("getOriginalColor: could not find match, returning SWF_NAMED_COLOR_HUD_BASE, how could that happen?");
//		return SWF_NAMED_COLOR_HUD_BASE;
//	}
//
//
//	static unsigned int debugLogInstancesDefaultNamesColors(__int64 spriteInstanceAddr, unsigned int namedColorId) {
//		if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//			logWarn("debugLogInstancesDefaultNamesColors: bad ptr: %p", (void*)spriteInstanceAddr);
//			return namedColorId;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		int fullPathHash = spriteInstance->fullPathHash;
//
//		if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {
//			logInfo("debugLogInstancesDefaultNamesColors: equipment: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
//			return namedColorId;
//		}
//		for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
//		{
//			if (fullPathHash == bloodPunchSpriteIdsVec[i]) {
//				logInfo("debugLogInstancesDefaultNamesColors: bloodPunch: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
//				return namedColorId;
//			}
//		}
//		for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
//		{
//			if (fullPathHash == radSuitSpriteIdsVec[i]) {
//				logInfo("debugLogInstancesDefaultNamesColors: radSuit: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
//				return namedColorId;
//			}
//		}
//		return namedColorId;
//	}
//
//
//	static unsigned int testColors(__int64 spriteInstanceAddr, unsigned int namedColorId) {
//
//		if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//			logWarn("testColors: bad ptr: %p", (void*)spriteInstanceAddr);
//			return namedColorId;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		int fullPathHash = spriteInstance->fullPathHash;
//
//		if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {
//			//logInfo("testColors: equipment: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
//			return m_debugNamedColorIndex;
//		}
//		for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
//		{
//			if (fullPathHash == bloodPunchSpriteIdsVec[i]) {
//				//logInfo("testColors: bloodPunch: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
//				return m_debugNamedColorIndex;
//			}
//		}
//		for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
//		{
//			if (fullPathHash == radSuitSpriteIdsVec[i]) {
//				//logInfo("testColors: radSuit: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
//				return m_debugNamedColorIndex;
//			}
//		}
//		return namedColorId;
//	}
//
//	static bool isEquipmentArrow(__int64 spriteInstanceAddr) {
//		if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//			logWarn("isEquipmentArrow:  bad ptr: %p", (void*)spriteInstanceAddr);
//			return false;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		int fullPathHash = spriteInstance->fullPathHash;
//		if (fullPathHash == equipmentArrowSpriteId) {
//			return true;
//		}
//		return false;
//	}
//
//
//	static unsigned int changeTestColor() {
//		m_debugNamedColorIndex++;
//		if (m_debugNamedColorIndex < 0) {
//			m_debugNamedColorIndex = 0;
//		}
//		if (m_debugNamedColorIndex > 269) {
//			m_debugNamedColorIndex = 0;
//		}
//		logInfo("changeTestColor m_debugNamedColorIndex: %d", m_debugNamedColorIndex);
//		return m_debugNamedColorIndex;
//	}
//
//	static void setRadSuitHudColor(const idColor color) {
//		std::vector<__int64>addrs = { m_radSuitBarGradientSpriteAddr, m_radSuitBarBaseSpriteAddr ,m_radSuitRightSideSpriteAddr , m_radSuitTextSpriteAddr , m_radSuitIconImgSpriteAddr ,m_radSuitGlowImgSpriteAddr , m_radSuitBgSpriteAddr, m_radSuitBgPulseSpriteAddr };
//		for (size_t i = 0; i < addrs.size(); i++)
//		{
//			if (!MemHelper::isBadReadPtr((void*)addrs[i])) {
//				setSpriteColor(addrs[i], color);
//			}
//		}
//	}
//
//	//? this is not used anymore
//	static void setBloodPunchHudColor(const idColor color, bool isFlashAllowed) {
//		std::vector<__int64>addrs = { m_bloodPunchBgPulseSpriteAddr, m_bloodPunchChargeGlowBgSpriteAddr ,m_bloodPunchBgImgSpriteAddr,  m_bloodPunchReadyFlashSpriteAddr, m_bloodPunchBorderImgSpriteAddr,m_bloodPunchIconOnSpriteAddr, m_bloodPunchIconOffSpriteAddr, m_bloodPunchFillRightGlowSpriteAddr, m_bloodPunchFillRightImgSpriteAddr, m_bloodPunchFillLeftGlowSpriteAddr, m_bloodPunchFillLeftImgSpriteAddr, m_bloodPunchTextSpriteAddr, m_bloodPunchBindKbmSpriteAddr,  m_bloodPunchBindJoySpriteAddr, m_bloodPunchBindKbmSpriteAddr, m_bloodPunchBindJoySpriteAddr };
//		/*if (isFlashAllowed) {
//			addrs.push_back(m_bloodPunchReadyFlashSpriteAddr);sdf
//		}*/
//		for (size_t i = 0; i < addrs.size(); i++)
//		{
//			if (!MemHelper::isBadReadPtr((void*)addrs[i])) {
//
//				//if ((addrs[i] == m_bloodPunchReadyFlashSpriteAddr) && !isFlashAllowed) { //? doesn't work
//				//	setSpriteColor(addrs[i], colorInvisible);
//				//}
//				if ((addrs[i] == m_bloodPunchBgPulseSpriteAddr) && !isFlashAllowed) {//! this works
//					setSpriteColor(addrs[i], colorInvisible);
//				}
//				else if ((addrs[i] == m_bloodPunchChargeGlowBgSpriteAddr) && !isFlashAllowed) { //! this works
//					setSpriteColor(addrs[i], colorInvisible);
//				}
//				else if ((addrs[i] == m_bloodPunchBorderImgSpriteAddr) && !isFlashAllowed) { //! this works
//					setSpriteColor(addrs[i], colorInvisible);
//				}
//				//else if ((addrs[i] == m_bloodPunchBgImgSpriteAddr) && !isFlashAllowed) {// doesn't work
//				//	setSpriteColor(addrs[i], colorInvisible);
//				//}
//				/*else if ((addrs[i] == m_bloodPunchIconOnSpriteAddr) && !isFlashAllowed) { // doesn't work
//					setSpriteColor(addrs[i], colorInvisible);
//				}*/
//				/*else if ((addrs[i] == m_bloodPunchFillRightGlowSpriteAddr) && !isFlashAllowed) {  // doesn't work
//					setSpriteColor(addrs[i], colorInvisible);
//				}*/
//				else {
//					setSpriteColor(addrs[i], color);
//				}
//			}
//		}
//	}
//
//
//
//	//! basically removes the bg element. Doesn't look amazing without it though.
//	static void decluterWeaponInfo() {
//		std::vector<__int64>addrs = { m_weaponInfoCoolDownSpriteAddr, m_weaponInfoBgModlessSpriteAddr, m_weaponInfoBgSpriteAddr };
//		for (size_t i = 0; i < addrs.size(); i++)
//		{
//			if (!MemHelper::isBadReadPtr((void*)addrs[i])) {
//				setSpriteColor(addrs[i], colorInvisible);
//			}
//		}
//	}
//
//
//	//! this is actually text + icon but i think it looks not great, just use the hook method of render shape.
//	static void setArmorHudToTextOnly() {
//		std::vector<__int64>addrs = { m_armorBarGradientSpriteAddr, m_armorBarBaseSpriteAddr ,m_armorRightSideSpriteAddr, m_armorIconGlowSpriteAddr, m_armorInfoSpriteAddr, m_armorBgSpriteAddr };
//		for (size_t i = 0; i < addrs.size(); i++)
//		{
//			if (!MemHelper::isBadReadPtr((void*)addrs[i])) {
//				setSpriteColor(addrs[i], colorInvisible);
//			}
//		}
//	}
//
//	//! this is actually text + icon but i think it looks not great, just use the hook method of render shape.
//	static void setHealthHudToTextOnly() {
//		std::vector<__int64>addrs = { m_healthIconBgSpriteAddr, m_healthPipsOutlineSpriteIdAddr, m_healthPipsGradientBottomSpriteAddr, m_healthPipsGradientTopSpriteAddr, m_healthBgLeftLeftSpriteAddr , m_healthRightSideMiddleMiddleSpriteAddr ,m_healthRightSideRightRightSpriteAddr, m_healthGlowSpriteIdSpriteAddr, m_healthPulseLoopSpriteAddr, m_healthBottomAdornmentSpriteAddr, m_healthRightSideAddAmountSpriteAddr, m_healthrightSideRightborderSpriteAddr };
//		for (size_t i = 0; i < addrs.size(); i++)
//		{
//			if (!MemHelper::isBadReadPtr((void*)addrs[i])) {
//				setSpriteColor(addrs[i], colorInvisible);
//			}
//		}
//	}
//
//
//	//? this is not used anymore:
//	static void acquireMonitoredSpriteInstanceAddr(__int64 addr) {
//		if (MemHelper::isBadReadPtr((void*)addr)) {
//			logErr("acquireMonitoredSpriteInstanceAddr found bad ptr for addr: %p returning", (void*)addr);
//			return;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)addr;
//		int fullPathHash = spriteInstance->fullPathHash;
//		switch (fullPathHash)
//		{
//		case equipmentArrowSpriteId:
//			m_currentEquipmentArrowSpriteInstanceAddr = addr;
//			break;
//		case equipmentBackerSpriteId:
//			m_EquipmentBackerSpriteInstanceAddr = addr;
//			break;
//		case healthIconOuterSpriteId:
//			m_healthIconOuterSpriteAddr = addr;
//			break;
//		case healthIconBgSpriteId:
//			m_healthIconBgSpriteAddr = addr;
//			break;
//		case healthTextSpriteId:
//			m_healthTextSpriteIdAddr = addr;
//			break;
//		case healthPipsOutlineSpriteId:
//			m_healthPipsOutlineSpriteIdAddr = addr;
//			break;
//		case healthPipsGradientBottomSpriteId:
//			m_healthPipsGradientBottomSpriteAddr = addr;
//			break;
//		case healthPipsGradientTopSpriteId:
//			m_healthPipsGradientTopSpriteAddr = addr;
//			break;
//		case healthBottomAdornmentSpriteId:
//			m_healthBottomAdornmentSpriteAddr = addr;
//			break;
//		case healthPulseLoopSpriteId:
//			m_healthPulseLoopSpriteAddr = addr;
//			break;
//		case healthGlowSpriteId:
//			m_healthGlowSpriteIdSpriteAddr = addr;
//			break;
//		case healthRightSideRightRightSpriteId:
//			m_healthRightSideRightRightSpriteAddr = addr;
//			break;
//		case healthRightSideMiddleMiddleSpriteId:
//			m_healthRightSideMiddleMiddleSpriteAddr = addr;
//			break;
//		case healthRightSideAddAmountSpriteId:
//			m_healthRightSideAddAmountSpriteAddr = addr;
//			break;
//		case healthrightSideRightborderSpriteId:
//			m_healthrightSideRightborderSpriteAddr = addr;
//			break;
//		case armorBarGradientSpriteId:
//			m_armorBarGradientSpriteAddr = addr;
//			break;
//		case armorBarBaseSpriteId:
//			m_armorBarBaseSpriteAddr = addr;
//			break;
//		case armorRightSideSpriteId:
//			m_armorRightSideSpriteAddr = addr;
//			break;
//		case armorTextSpriteId:
//			m_armorTextSpriteAddr = addr;
//			break;
//		case armorIconSpriteId:
//			m_armorIconSpritAddr = addr;
//			break;
//		case armorIconGlowSpriteId:
//			m_armorIconGlowSpriteAddr = addr;
//			break;
//		case armorInfoSpriteId:
//			m_armorInfoSpriteAddr = addr;
//			break;
//		case armorBgSpriteId:
//			m_armorBgSpriteAddr = addr;
//			break;
//		case weaponInfoBgModlessSpriteId:
//			m_weaponInfoBgModlessSpriteAddr = addr;
//			break;
//		case weaponInfoTextSpriteId:
//			m_weaponInfoTextSpriteAddr = addr;
//			break;
//		case weaponInfoBgSpriteId:
//			m_weaponInfoBgSpriteAddr = addr;
//			break;
//		case bloodPunchBgPulseSpriteId:
//			m_bloodPunchBgPulseSpriteAddr = addr;
//			break;
//		case bloodPunchChargeGlowBgSpriteId:
//			m_bloodPunchChargeGlowBgSpriteAddr = addr;
//			break;
//		case bloodPunchBgImgSpriteId:
//			m_bloodPunchBgImgSpriteAddr = addr;
//			break;
//		case bloodPunchBorderImgSpriteId:
//			m_bloodPunchBorderImgSpriteAddr = addr;
//			break;
//		case bloodPunchIconOnSpriteId:
//			m_bloodPunchIconOnSpriteAddr = addr;
//			break;
//		case bloodPunchIconOffSpriteId:
//			m_bloodPunchIconOffSpriteAddr = addr;
//			break;
//		case bloodPunchReadyFlashSpriteId:
//			m_bloodPunchReadyFlashSpriteAddr = addr;
//			break;
//		case bloodPunchFillRightGlowSpriteId:
//			m_bloodPunchFillRightGlowSpriteAddr = addr;
//			break;
//		case bloodPunchFillRightImgSpriteId:
//			m_bloodPunchFillRightImgSpriteAddr = addr;
//			break;
//		case bloodPunchFillLeftGlowSpriteId:
//			m_bloodPunchFillLeftGlowSpriteAddr = addr;
//			break;
//		case bloodPunchFillLeftImgSpriteId:
//			m_bloodPunchFillLeftImgSpriteAddr = addr;
//			break;
//		case bloodPunchTextSpriteId:
//			m_bloodPunchTextSpriteAddr = addr;
//			break;
//		case bloodPunchBindKbmSpriteId:
//			m_bloodPunchBindKbmSpriteAddr = addr;
//			break;
//		case bloodPunchBindJoySpriteId:
//			m_bloodPunchBindJoySpriteAddr = addr;
//			break;
//		case radSuitBarGradientSpriteId:
//			m_radSuitBarGradientSpriteAddr = addr;
//			break;
//		case radSuitBarBaseSpriteId:
//			m_radSuitBarBaseSpriteAddr = addr;
//			break;
//		case radSuitRightSideSpriteId:
//			m_radSuitRightSideSpriteAddr = addr;
//			break;
//		case radSuitTextSpriteId:
//			m_radSuitTextSpriteAddr = addr;
//			break;
//		case radSuitIconImgSpriteId:
//			m_radSuitIconImgSpriteAddr = addr;
//			break;
//		case radSuitGlowImgSpriteId:
//			m_radSuitGlowImgSpriteAddr = addr;
//			break;
//		case radSuitBgSpriteId:
//			m_radSuitBgSpriteAddr = addr;
//			break;
//		case radSuitBgPulseSpriteId:
//			m_radSuitBgPulseSpriteAddr = addr;
//			break;
//		case bloodPunchChargeBgSpriteId:
//			m_bloodPunchChargeBgSpriteAddr = addr;
//			break;
//		case bloodPunchImgImgSpriteId:
//			m_bloodPunchImgImgSpriteAddr = addr;
//			break;
//		default:
//			break;
//		}
//	}
//	//static __int64 m_bloodPunchChargeBgSpriteAddr;
//	//static __int64 m_bloodPunchImgImgSpriteAddr;
//
//	/*
//
//	*/
//
//	//? this is not used anymore:
//	//! detecting sprites we overide so the game can not change its color but only when game is not loading !
//	static bool isSpriteInstanceOveridden(__int64 addr) {
//		if (MemHelper::isBadReadPtr((void*)addr)) {
//			logErr("isSpriteInstanceOveridden found bad ptr for addr: %p returning false", (void*)addr);
//			return false;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)addr;
//		int fullPathHash = spriteInstance->fullPathHash;
//
//		if (IniConfig::isEquipmentArrowColorOveride()) {
//			if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {
//				return true;
//			}
//		}
//
//		if (IniConfig::isBloodPunchColorOveride()) {
//			for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
//			{
//				if (fullPathHash == bloodPunchSpriteIdsVec[i]) return true;
//			}
//		}
//		if (IniConfig::isRadSuitColorOveride()) {
//			for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
//			{
//				if (fullPathHash == radSuitSpriteIdsVec[i]) return true;
//			}
//		}
//		return false;
//	}
//
//
//
//
//
//	//! sets colors of arrow and backer
//	/*static void setEquipmentAltNadeColor(const idColor& color) {
//		setEquipmentBackerColor(color);
//		setEquipmentArrowColor(color);
//	}*/
//
//
//	//static void setEquipmentBackerColor(const idColor& color) {
//	//	//logInfo("setEquipmentBackerColor called");
//	//	setSpriteColor(m_EquipmentBackerSpriteInstanceAddr, color);
//	//}
//
//
//	//static void setEquipmentArrowColor(const idColor& color) {
//	//	//! for this func to work the sprite instance addr needs to be aquired which is done on level load.		
//	//	setSpriteColor(m_currentEquipmentArrowSpriteInstanceAddr, color);
//	//}
//
//	//! using this atm for debugging to show the bounds of hud elements and if it can be usefull do display text over them
//	static idVec4_Bounds getEquipmentArrowBounds() {
//		if (!MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSpriteInstanceAddr)) {
//			idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSpriteInstanceAddr;
//			return spriteInstance->getBounds();
//		}
//		//logErr("getEquipmentArrowBounds: could not get bounds, return default vec4");
//		return idVec4_Bounds();
//	}
//
//	static idVec4_Bounds getEquipmentBackerBounds() {
//		if (!MemHelper::isBadReadPtr((void*)m_EquipmentBackerSpriteInstanceAddr)) {
//			idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_EquipmentBackerSpriteInstanceAddr;
//			return spriteInstance->getBounds();
//		}
//		//logErr("getEquipmentArrowBounds: could not get bounds, return default vec4");
//		return idVec4_Bounds();
//	}
//
//
//
//	//static idVec4_Bounds getSpriteBounds(int spriteHashId) {
//	//	if (!MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSpriteInstanceAddr)) {
//	//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSpriteInstanceAddr;
//	//		return spriteInstance->getBounds();
//	//	}
//	//	//logErr("getEquipmentArrowBounds: could not get bounds, return default vec4");
//	//	return idVec4_Bounds();
//	//}
//
//
//
//
//	//? this is not used anymore: (too many potential crashes)
//	static void setSpriteColor(__int64 spriteInstanceAddr, const idColor& color) {
//		if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//			logWarn("setSpriteColor: can not set color cause spriteInstanceAddr is bad ptr: %p", (void*)spriteInstanceAddr);
//			//idCmd::testCallReapplySwfColors();			
//			return;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		if (spriteInstance->listNum > 0) {
//
//			//uintptr_t displayListAddr = *(uintptr_t*)spriteInstance->displayList;
//			//logInfo("setSpriteColor setting color....");
//			//! code adapted from ida: setSpriteInstanceColor_Smth_52F750
//			int counter_v8 = 0;
//			__int64 v12 = 0;
//
//			do
//			{
//				//uintptr_t displayList_v16 = *(uintptr_t*)spriteInstance->displayList;// displayeList is at offset 0x70 in spriteInstance
//				uintptr_t displayList_v16 = (uintptr_t)spriteInstance->displayList;// displayeList is at offset 0x70 in spriteInstance
//				v12 += 0x40;
//				++counter_v8;
//				*(float*)(v12 + displayList_v16 - 0x34) = color.r;
//				*(float*)(v12 + displayList_v16 - 0x30) = color.g;
//				*(float*)(v12 + displayList_v16 - 0x2C) = color.b;
//				*(float*)(v12 + displayList_v16 - 0x28) = color.a;
//
//			} while (counter_v8 < spriteInstance->listNum);
//		}
//	}
//
//
//
//	//! Debug:
//
//	//? afaik this doesn't work 
//	static void debugMoveEquipmentArrowRight() {
//		if (!MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSpriteInstanceAddr)) {
//			idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSpriteInstanceAddr;
//			spriteInstance->debugMoveRight();
//		}
//		else {
//			logWarn("debugMoveEquipmentArrowRight: m_currentEquipmentArrowSpriteInstanceAddr is bad ptr: %p", (void*)m_currentEquipmentArrowSpriteInstanceAddr);
//		}
//	}
//
//	//! used in setSpriteInstanceColorHook 
//	static void addSpriteInstanceAddrToDebugVec(__int64 addr) {
//		for (size_t i = 0; i < m_spriteInstanceAddressesVec.size(); i++)
//		{
//			if (m_spriteInstanceAddressesVec[i] == addr) return;
//		}
//		//logInfo("addSpriteInstanceAddrToDebugVec adding sprite addr to m_spriteInstanceAddressesVec...");
//		m_spriteInstanceAddressesVec.push_back(addr);
//	}
//
//	//! this is used to debug the hud elements for which we already have gotten ids but don't know exactly what they are:
//	static bool isSpriteIdBeingDebugged(__int64 spriteInstanceAddr) {
//		if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//			logErr("isSpriteIdBeingDebugged found bad ptr for addr: %p returning false", (void*)spriteInstanceAddr);
//			return false;
//		}
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		for (size_t i = 0; i < m_spriteHashIdDebugVec.size(); i++)
//		{
//			if (m_spriteHashIdDebugVec[i] == spriteInstance->fullPathHash) {
//				//logInfo("isSpriteIdBeingDebugged:returning true");
//				return true;
//			}
//		}
//		return false;
//	}
//
//	static bool isSpriteColorIdBeingDebugged(unsigned int namedColorId) {
//		for (size_t i = 0; i < m_debugColorIdVec.size(); i++)
//		{
//			if (m_debugColorIdVec[i] == namedColorId) return true;
//		}
//		return false;
//	}
//
//
//
//
//
//	//! this is used to debug the hud elements globally
//	static void debugChangeNextHudElementColorToBlue() {
//		m_debugIndex++;
//		if (m_debugIndex >= m_spriteInstanceAddressesVec.size()) {
//			m_debugIndex = m_spriteInstanceAddressesVec.size() - 1;
//		}
//		if (m_debugIndex < 0) {
//			m_debugIndex = 0;
//		}
//		if (m_spriteInstanceAddressesVec.size() > 0 && (m_debugIndex >= 0)) {
//			__int64 spriteAddr = m_spriteInstanceAddressesVec[m_debugIndex];
//			idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteAddr;
//			logInfo("index: %d setting sprite with addr: %p to BLUE", m_debugIndex, (void*)spriteAddr);
//			spriteInstance->print();
//			setSpriteColor(spriteAddr, colorBlue);
//		}
//
//	}
//
//
//	static void debugChangePrevHudElementColorToRed() {
//		m_debugIndex--;
//		if (m_debugIndex < 0) {
//			m_debugIndex = 0;
//		}
//		if (m_debugIndex >= m_spriteInstanceAddressesVec.size()) {
//			m_debugIndex = m_spriteInstanceAddressesVec.size() - 1;
//		}
//		if (m_spriteInstanceAddressesVec.size() > 0 && (m_debugIndex >= 0)) {
//			__int64 spriteAddr = m_spriteInstanceAddressesVec[m_debugIndex];
//			idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteAddr;
//			logInfo("index: %d setting sprite with addr: %p to RED", m_debugIndex, (void*)spriteAddr);
//			spriteInstance->print();
//			setSpriteColor(spriteAddr, colorRed);
//		}
//	}
//
//
//	static void debugLogSpriteInstance(__int64 spriteInstanceAddr) {
//		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//		spriteInstance->print();
//	}
//
//
//	static bool isAlreadyInpathHashesDebugVec(int hashId) {
//		for (size_t i = 0; i < m_spriteDebugVec.size(); i++)
//		{
//			if (m_spriteDebugVec[i].fullPathHash == hashId) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	//! this works:
//	//static void setEquipmentArrowColorToInvisible() {
//
//	//	if (MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSprintInstanceAddr)) {
//	//		logWarn("setEquipmentArrowColorToInvisible can not set color cause m_currentEquipmentArrowSprintInstanceAddr is bad ptr: %p", (void*)m_currentEquipmentArrowSprintInstanceAddr);
//	//		return;
//	//	}
//
//	//	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSprintInstanceAddr;
//	//	logInfo("setEquipmentArrowColorToInvisible spriteInstance:  %p", (void*)spriteInstance);
//
//
//	//	logInfo("setEquipmentArrowColorToInvisible fullPathHash:  %d", spriteInstance->fullPathHash);
//
//	//	/*if (spriteInstance->fullPathHash != equipmentArrowSpriteInstanceHashId) {
//	//		
//	//	}*/
//	//		
//	//	int displayListNum = (spriteInstance->listNum);
//	//	//int displayListNum = *(int*)(spriteInstance->displayList[8]);
//
//	//	logInfo("setEquipmentArrowColorToInvisible displayListNum %d", displayListNum);
//
//	//	//? this will actually dereference twice so it's not good:
//	//	/*uintptr_t displayListAddr = *(uintptr_t*)spriteInstance->displayList;
//	//	logInfo("setEquipmentArrowColorToInvisible displayListAddr: %p", (void*)displayListAddr);*/
//
//
//	//	if (displayListNum > 0) {
//
//	//		//uintptr_t displayListAddr = *(uintptr_t*)spriteInstance->displayList;
//	//		logInfo("setEquipmentArrowColorToInvisible spriteInstance->displayList: %p", (void*)spriteInstance->displayList);
//
//
//	//		int counter_v8 = 0;
//	//		__int64 v12 = 0;
//
//	//		do
//	//		{
//	//			//uintptr_t displayList_v16 = *(uintptr_t*)spriteInstance->displayList;// displayeList is at offset 0x70 in spriteInstance
//	//			uintptr_t displayList_v16 = (uintptr_t)spriteInstance->displayList;// displayeList is at offset 0x70 in spriteInstance
//	//			v12 += 0x40;
//	//			++counter_v8;
//	//			*(float*)(v12 + displayList_v16 - 0x34) = colorInvisible.r;
//	//			*(float*)(v12 + displayList_v16 - 0x30) = colorInvisible.g;
//	//			*(float*)(v12 + displayList_v16 - 0x2C) = colorInvisible.b;
//	//			*(float*)(v12 + displayList_v16 - 0x28) = colorInvisible.a;
//
//	//			//! this will set color to blue instead of invisible may be wrong order in the float(?)
//	//			/**(float*)(v12 + displayList_v16 - 0x34) = colorInvisible.a;
//	//			*(float*)(v12 + displayList_v16 - 0x30) = colorInvisible.b;
//	//			*(float*)(v12 + displayList_v16 - 0x2C) = colorInvisible.g;
//	//			*(float*)(v12 + displayList_v16 - 0x28) = colorInvisible.r;*/
//	//		} while (counter_v8 < spriteInstance->listNum);
//	//		//} while (counter_v8 < *(int*)spriteInstance->displayList[8]);
//	//	}
//	//}
//
//	/*static void setEquipmentArrowFlag(bool isFlag) {
//		m_isEquipmentFlag = isFlag;
//	}
//
//	static bool isEquipmentArrowFlag() {
//		return m_isEquipmentFlag;
//	}*/
//
//	//static bool isEquipmentArrowOverideColor(int colorId) {
//	//	//if (colorId == SWF_NAMED_COLOR_HUD_TEXT) { //! this works so that's fucking that
//	//	if (colorId == SWF_NAMED_COLOR_DOOR_LOCK_RED) {
//	//		logInfo("isEquipmentArrowOverideColor called...");
//	//		return true;
//	//	}
//	//	return false;
//	//}
//
//	//static __int64 overideIdColor(__int64 idColorAddr, const idColor& overideidColor) {
//
//	//	logInfo("overideIdColor called...");
//
//
//
//
//
//	//	//? this doesn't fucking work:
//	///*	*(idColor*)idColorAddr = overideidColor;
//	//	return (__int64)&overideidColor;*/
//
//
//
//	//	//if (colorId == SWF_NAMED_COLOR_INVISIBLE_K) {
//	//	//	*(idColor*)idColorAddr = colorInvisible;
//	//	//	return (__int64)&colorInvisible;
//	//	//	//*(idColor*)idColorAddr = *(_OWORD*)(idDeclUIColor_a1 + 0x90);
//	//	//}
//	//}
//
//
//
//	//static void overideEquipmentArrowNamedColor(__int64 sprintInstanceAddr) {
//	//	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)sprintInstanceAddr;
//	//	if (spriteInstance->fullPathHash == equipmentArrowSpriteInstanceHashId) {
//	//		
//
//
//	//		//spriteInstance->namedColorId = m_invisibleNamedColor;
//	//		spriteInstance->namedColorId = (int)SWF_NAMED_COLOR_DOOR_LOCK_RED;
//	//		logWarn("overideEquipmentArrowNamedColor: m_invisibleNamedColor is: %d spriteInstance->namedColorId is now %d", (int)SWF_NAMED_COLOR_DOOR_LOCK_RED, spriteInstance->namedColorId);
//
//	//		//logInfo("overideEquipmentArrowColor: sprintInstanceAddr: %p  spriteInstance->rare is: %p", (void*)sprintInstanceAddr,(void*)spriteInstance->rare);
//	//		//? there is not rare instance for the equipment arrow and i suspect same for most too :(
//	//		/*if (!MemHelper::isBadReadPtr(spriteInstance->rare)) {
//	//			logInfo("overideEquipmentArrowColor: found equipmentArrowSpriteInstanceHashId current alphaOverride: %.2f", spriteInstance->rare->alphaOverride);				
//	//		}
//	//		else {
//	//			logWarn("overideEquipmentArrowColor: found bad ptr for spriteInstance->rare");
//	//		}	*/		
//	//	}
//	//}
//
//	//static void setColor()
//
//
////! this is a named color that doesn't exist but we'll use it as a flag in the function(s) we hook
////const int GameHudColorsManager::m_invisibleNamedColor = (int)SWF_NAMED_COLOR_DOOR_LOCK_RED;
//
//
//
//
//
//	//static void acquireEquipmentArrowSprintInstanceAddr(__int64 addr) {
//	//	logInfo("acquireEquipmentArrowSprintInstanceAddr acquiring: %p", (void*)addr);
//	//	m_currentEquipmentArrowSpriteInstanceAddr = addr;
//	//}
//
//	//static bool isEquipmentArrowSpriteInstance(__int64 sprintInstanceAddr) {
//	//	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)sprintInstanceAddr;
//	//	//logInfo("isEquipmentArrowSpriteInstance debug: spriteInstance->fullPathHash: %d", spriteInstance->fullPathHash);
//	//	if (spriteInstance->fullPathHash == equipmentArrowSpriteId) {
//	//		return true;
//	//	}
//	//	return false;
//	//}
//
//
//	//! this works but we need a more general method that applies to many sprites this was just a test
//	//static void setEquipmentArrowColor(const idColor& color) {
//	//	if (MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSprintInstanceAddr)) {
//	//		logWarn("setEquipmentArrowColor: can not set color cause m_currentEquipmentArrowSprintInstanceAddr is bad ptr: %p", (void*)m_currentEquipmentArrowSprintInstanceAddr);
//	//		idCmd::testCallReapplySwfColors();
//	//		//todo may be we should test again if m_currentEquipmentArrowSprintInstanceAddr is badptr or we should find a way to find this spriteInstance ourselves....
//	//		return;
//	//	}
//	//	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSprintInstanceAddr;
//	//	if (spriteInstance->listNum > 0) {
//
//	//		//uintptr_t displayListAddr = *(uintptr_t*)spriteInstance->displayList;
//	//		//logInfo("setEquipmentArrowColorToInvisible spriteInstance->displayList: %p", (void*)spriteInstance->displayList);
//	//		//! code adapted from ida: setSpriteInstanceColor_Smth_52F750
//	//		int counter_v8 = 0;
//	//		__int64 v12 = 0;
//
//	//		do
//	//		{
//	//			//uintptr_t displayList_v16 = *(uintptr_t*)spriteInstance->displayList;// displayeList is at offset 0x70 in spriteInstance
//	//			uintptr_t displayList_v16 = (uintptr_t)spriteInstance->displayList;// displayeList is at offset 0x70 in spriteInstance
//	//			v12 += 0x40;
//	//			++counter_v8;
//	//			*(float*)(v12 + displayList_v16 - 0x34) = color.r;
//	//			*(float*)(v12 + displayList_v16 - 0x30) = color.g;
//	//			*(float*)(v12 + displayList_v16 - 0x2C) = color.b;
//	//			*(float*)(v12 + displayList_v16 - 0x28) = color.a;
//	//		
//	//		} while (counter_v8 < spriteInstance->listNum);
//	//	}
//	//}
//
//
//
//
//
//};
//
//bool GameHudColorsManager::m_isEquipmentFlag = false;
//__int64 GameHudColorsManager::m_currentEquipmentArrowSpriteInstanceAddr = 0;
//__int64 GameHudColorsManager::m_EquipmentBackerSpriteInstanceAddr = 0;
//
//__int64  GameHudColorsManager::m_healthIconOuterSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthIconBgSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthTextSpriteIdAddr = 0;
//__int64  GameHudColorsManager::m_healthPipsOutlineSpriteIdAddr = 0;
//__int64  GameHudColorsManager::m_healthPipsGradientBottomSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthPipsGradientTopSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthBgLeftLeftSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthRightSideMiddleMiddleSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthRightSideRightRightSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthGlowSpriteIdSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthPulseLoopSpriteAddr = 0;
//__int64  GameHudColorsManager::m_healthBottomAdornmentSpriteAddr = 0;
//__int64 GameHudColorsManager::m_healthRightSideAddAmountSpriteAddr = 0;
//__int64 GameHudColorsManager::m_healthrightSideRightborderSpriteAddr = 0;
//
//__int64 GameHudColorsManager::m_armorBarGradientSpriteAddr = 0;
//__int64 GameHudColorsManager::m_armorBarBaseSpriteAddr = 0;
//__int64 GameHudColorsManager::m_armorRightSideSpriteAddr = 0;
//__int64 GameHudColorsManager::m_armorTextSpriteAddr = 0;
//__int64 GameHudColorsManager::m_armorIconSpritAddr = 0;
//__int64 GameHudColorsManager::m_armorIconGlowSpriteAddr = 0;
//__int64 GameHudColorsManager::m_armorInfoSpriteAddr = 0;
//__int64 GameHudColorsManager::m_armorBgSpriteAddr = 0;
//
//__int64 GameHudColorsManager::m_weaponInfoCoolDownSpriteAddr = 0;
//__int64 GameHudColorsManager::m_weaponInfoBgModlessSpriteAddr = 0;
//__int64 GameHudColorsManager::m_weaponInfoTextSpriteAddr = 0;
//__int64 GameHudColorsManager::m_weaponInfoBgSpriteAddr = 0;
//
//__int64 GameHudColorsManager::m_bloodPunchBgPulseSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchChargeGlowBgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchBgImgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchBorderImgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchIconOnSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchIconOffSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchReadyFlashSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchFillRightGlowSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchFillRightImgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchFillLeftGlowSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchFillLeftImgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchTextSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchBindKbmSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchBindJoySpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchChargeBgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_bloodPunchImgImgSpriteAddr = 0;
//
//__int64 GameHudColorsManager::m_radSuitBarGradientSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitBarBaseSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitRightSideSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitTextSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitIconImgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitGlowImgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitBgSpriteAddr = 0;
//__int64 GameHudColorsManager::m_radSuitBgPulseSpriteAddr = 0;
////__int64 GameHudColorsManager::m_radSuitChargeBgSpriteAddr = 0;
////__int64 GameHudColorsManager::m_radSuitImgImgSpriteAddr = 0;
//
//std::vector<__int64> GameHudColorsManager::m_spriteInstanceAddressesVec;
//int GameHudColorsManager::m_debugIndex = 0;
//
//
////std::vector<int> GameHudColorsManager::m_spriteHashIdDebugVec = { -108148670,-955715598, -1170972450, -1213354124, 331208024, 602032450, -682387167 };
//
////std::vector<unsigned int> GameHudColorsManager::m_debugColorIdVec = { SWF_NAMED_COLOR_UI_HEALTH, SWF_NAMED_COLOR_UI_HEALTH_GRADIENT ,SWF_NAMED_COLOR_UI_HEALTH_LOW ,SWF_NAMED_COLOR_UI_HEALTH_REALLY_LOW };
//
////std::vector<unsigned int> GameHudColorsManager::m_debugColorIdVec = { SWF_NAMED_COLOR_UI_RADIATION, SWF_NAMED_COLOR_UI_RADIATION_GRADIENT };
//
//std::vector<unsigned int> GameHudColorsManager::m_debugColorIdVec = { SWF_NAMED_COLOR_HUD_BASE, SWF_NAMED_COLOR_HUD_TEXT, SWF_NAMED_COLOR_HUD_HEADER, SWF_NAMED_COLOR_DASH_BASE, SWF_NAMED_COLOR_DASH_GLOW };
//
////std::vector<int32_t> GameHudColorsManager::bloodPunchSpriteIdsVec = { bloodPunchBgPulseSpriteId , bloodPunchChargeGlowBgSpriteId, bloodPunchBgImgSpriteId, bloodPunchBorderImgSpriteId, bloodPunchIconOnSpriteId, bloodPunchIconOffSpriteId, bloodPunchReadyFlashSpriteId, bloodPunchFillRightGlowSpriteId, bloodPunchFillRightImgSpriteId ,bloodPunchFillLeftGlowSpriteId , bloodPunchFillLeftImgSpriteId , bloodPunchTextSpriteId, bloodPunchBindKbmSpriteId, bloodPunchBindJoySpriteId, bloodPunchChargeBgSpriteId , bloodPunchImgImgSpriteId, bloodPunchBgBaseSpriteId };
//
////! trying without the bloodPunchReadyFlashSpriteId which has several colors....
//std::vector<int32_t> GameHudColorsManager::bloodPunchSpriteIdsVec = { bloodPunchBgPulseSpriteId , bloodPunchChargeGlowBgSpriteId, bloodPunchBgImgSpriteId, bloodPunchBorderImgSpriteId, bloodPunchIconOnSpriteId, bloodPunchIconOffSpriteId, bloodPunchFillRightGlowSpriteId, bloodPunchFillRightImgSpriteId ,bloodPunchFillLeftGlowSpriteId , bloodPunchFillLeftImgSpriteId , bloodPunchTextSpriteId, bloodPunchBindKbmSpriteId, bloodPunchBindJoySpriteId, bloodPunchChargeBgSpriteId , bloodPunchImgImgSpriteId, bloodPunchBgBaseSpriteId };
//
//
//std::vector<int32_t> GameHudColorsManager::radSuitSpriteIdsVec = { radSuitBarGradientSpriteId, radSuitBarBaseSpriteId ,radSuitRightSideSpriteId ,radSuitTextSpriteId ,radSuitIconImgSpriteId , radSuitGlowImgSpriteId ,radSuitBgSpriteId , radSuitBgPulseSpriteId };
//
//int GameHudColorsManager::m_debugNamedColorIndex = -1;
//
//__int32 GameHudColorsManager::m_invisibleFlagColorId = SWF_NAMED_COLOR_INVASION_RED;
//
///*
//*/
