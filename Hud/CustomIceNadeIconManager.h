#pragma once

#include <string>

#include "../DE/idLib.h"
#include "../DE/idColor.h"
#include "CustomIceNadeIconUIData.h"
#include "../DE/GameHudColorsManager.h"
#include "../DE/idMapInstanceLocalManager.h"
#include "../DE/idPlayer.h"
#include "../DE/MaterialLib.h"
#include "../DE/UserColorSet.h"


struct debugTimersData {
	std::string gameTimeStr;
	std::string StartTimeStr;
	std::string  RechargeDurationStr;
	std::string  RechargeTimeStr;
	std::string  ReuseTimeStr;
	std::string countdownStr;
};



class CustomIceNadeIconManager {

private:

	//! i'm usure about this being a ref for the hook or copying it in the hook...i guess we could see the perf but i'm not sure we'll see a diff on our machine but may be some people would, like the ones with old cpus(?)
	static inline CustomIceNadeIconUIData m_iceNadeIconUIData;
	

	static inline idPlayer_equipmentInfo_t_itemData_t m_timersData;

	//! when this function triggers, it will call our IdHudDebugPrintHook that draws our custom ice nade icon 4 times per image rendered, which is overkill as we don't want our icon drawn 3 times for nothing so that flag allow us to skip those 3 render calls hopefully.
	
	

public:
	
	static void updateIsRenderingAllowed(bool isAllowed);

	static void updateIsIceNadeCooldownStatus();

	static void updateColors();

	static void updateCoords();

	static void updateCooldownTimeLeftStr();


	static CustomIceNadeIconUIData getData();


	//static debugTimersData getDebugTimersStrs();



	//! i guess those should be triggered in main loop as we want the less computing possible in the hook, now when do we trigger it, should be at least when data changes, when changing state from menu to ingame, when ini reloading, when res changes, and as a safety, every second...
	
	/*static bool isIceNadeOnCoolDown() {
		return m_iceNadeIconUIData.isIceOnCoolDown;
	}

	static void updateIsRenderingAllowed(bool isAllowed) {
		m_iceNadeIconUIData.isRenderingAllowed = isAllowed;
	}*/

	

	

	//! will have to trigger updateIceNadeCooldownStatus (yes this is state but don't want to have the hook trigger idPlayer_K::getIceNadeCount() > 0.
	//static void updateColors() {
	//	//! this shoud be before func not here:
	//	/*if (!idInventoryCollectionManager::isItemOwned(ItemID::IceBomb)) {
	//		return;
	//	}*/

	//	idColor baseIceIconColor;
	//	idColor baseIceBackGroundColor;
	//	//idColor baseBorderColor;			

	//	if (! m_iceNadeIconUIData.isIceOnCoolDown) { //! if nade ready:
	//		//IniFileData::getOverrideIceGrenadeColor();	

	//		if (UserColorSet::isDefaultColorIceNadeArrow()) {
	//			baseIceIconColor = GameHudColorsManager::getCurrentProfileIceNadeIconColor();
	//			baseIceBackGroundColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();
	//			//baseBorderColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();

	//			m_iceNadeIconUIData.iconColor = baseIceIconColor;
	//		}
	//		else { //! if custom user color
	//			baseIceIconColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeArrow_Color());
	//			baseIceBackGroundColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeArrow_Color());
	//			//baseBorderColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeArrow_Color());
	//			GameHudColorsManager::setIconWhiteBlendColor(baseIceIconColor, m_iceNadeIconUIData.iconColor, m_abilityAvailableStarIconWhiteBlend);
	//		}

	//		/*GameHudColorsManager::setIconWhiteBlendColor(baseIceIconColor, m_iceNadeIconUIData.iconColor, m_abilityAvailableStarIconWhiteBlend);*/

	//		
	//	}
	//	else { //! if ice not available
	//		if (UserColorSet::isDefaultColorIceNadeCoolDownArrow()) {
	//			baseIceIconColor = colorDkGrey;
	//			baseIceBackGroundColor = colorDkGrey;
	//			//baseBorderColor = colorBlack;
	//		}
	//		else {
	//			baseIceIconColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeCooldownArrow_Color());
	//			baseIceBackGroundColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeCooldownArrow_Color());
	//			//baseBorderColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeCooldownArrow_Color());
	//		}

	//		GameHudColorsManager::setAlpha(baseIceIconColor, m_iceNadeIconUIData.iconColor, m_abilityDisabledStarIconAlpha);
	//	}

	//	GameHudColorsManager::setAlpha(baseIceBackGroundColor, m_iceNadeIconUIData.backgroundColor, m_BackgroundAlpha);

	//	GameHudColorsManager::setAlpha(baseIceBackGroundColor, m_iceNadeIconUIData.borderColor, m_BorderAlpha);

	//	GameHudColorsManager::setAlpha(baseIceBackGroundColor, m_iceNadeIconUIData.extraBorderColor, m_ExtraBorderAlpha);

	//	
	//	//m_iceNadeIconUIData.backgroundColor = baseIceBackGroundColor;
	//}



	



	//	long long gameTime = idMapInstanceLocalManager::getGameTime_t();
	//	auto timers = idPlayer_K::getEquipmentTimers(equipmentIndex_t::ICE);
	//	int countdown = (int)((timers.equipmentRechargeTime - gameTime) / 1000000) + 1; //! we need to add 1 to make it look correct.
	//	if (countdown < 0) {
	//		countdown = 0; //! making sure we never show neg values.
	//	}
	//	if (countdown < 10) {
	//		m_iceNadeIconUIData.cooldownText = "0" + std::to_string(countdown);
	//	}
	//	else {
	//		m_iceNadeIconUIData.cooldownText = std::to_string(countdown);
	//	}	
	//}


	

	

	//! methods to use by printOutlinedStringMB_hook:
	
	/*static bool isIceNadeOwned() {

	}

	static bool isIceOnCoolDown() {

	}*/


};


 //const float CustomIceNadeIconManager::m_starIconScale = .27f; // was .27 the lower the val the bigger the icon
 //const float CustomIceNadeIconManager::m_abilityAvailableStarIconWhiteBlend = .40f; // was .45
 //const float CustomIceNadeIconManager::m_abilityDisabledStarIconAlpha = .35f; // more than 35 seems too much
 //const float CustomIceNadeIconManager::m_iceNadeIconOffsetMul = .68f; // was .675f
 //const float CustomIceNadeIconManager::m_ExtraBorderAlpha = .1f;
 //const float CustomIceNadeIconManager::m_BorderAlpha = 1.0f;
 //const float CustomIceNadeIconManager::m_BackgroundAlpha = .3f;

 //idPlayer_equipmentInfo_t_itemData_t CustomIceNadeIconManager::m_timersData;

