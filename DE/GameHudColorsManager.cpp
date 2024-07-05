#include "GameHudColorsManager.h"

//! this is trigger in convertIdDeclUIColorToidColorHook
void GameHudColorsManager::acquireIdDeclUIColorAddr(__int64 IdDeclUIColorAddr) {
	static  __int64 lastIdDeclUIColorAddr = -1;

	if (IdDeclUIColorAddr != lastIdDeclUIColorAddr) {
		lastIdDeclUIColorAddr = IdDeclUIColorAddr;
		logInfo("acquireIdDeclUIColorAddr: IdDeclUIColorAddr has changed to %p", (void*)IdDeclUIColorAddr);
	}

	m_currentIdDeclUIColor = IdDeclUIColorAddr;
}


//! color manipulation to make sure the ice icon will pop whatever color user chooses:
idColor GameHudColorsManager::blendWithWhite(const idColor& color, float blendFactor) {
	idColor result;

	result.r = color.r + (1.0f - color.r) * blendFactor;
	result.g = color.g + (1.0f - color.g) * blendFactor;
	result.b = color.b + (1.0f - color.b) * blendFactor;
	result.a = color.a; // Assuming you want to keep the original alpha value

	return result;
}

//! computing colors for custom equipment icon, like the ice nade custom icon	

void GameHudColorsManager::setAlpha(const idColor& baseColor, idColor& destColor, float alphaF) {
	destColor.r = baseColor.r;
	destColor.g = baseColor.g;
	destColor.b = baseColor.b;
	destColor.a = alphaF;
}

 void GameHudColorsManager::setIconWhiteBlendColor(const idColor& baseColor, idColor& destColor, float blendFactor) {
	destColor.r = baseColor.r + (1.0f - baseColor.r) * blendFactor;
	destColor.g = baseColor.g + (1.0f - baseColor.g) * blendFactor;
	destColor.b = baseColor.b + (1.0f - baseColor.b) * blendFactor;
	destColor.a = 1.0f;
}


//! lowered alpha
void GameHudColorsManager::setIconExtraBorderColor(const idColor& baseColor, idColor& destColor) {

	destColor.r = baseColor.r;
	destColor.g = baseColor.g;
	destColor.b = baseColor.b;
	destColor.a = .1f;

}

void GameHudColorsManager::setIconBackgroundColor(const idColor& baseColor, idColor& destColor) {

	destColor.r = baseColor.r;
	destColor.g = baseColor.g;
	destColor.b = baseColor.b;
	destColor.a = .3f;
}




//? it's good to minimise to the maximum the use of function in hooks as one func could be called twice at the same time in the hook and in the mod main loop (?)
const idColor* GameHudColorsManager::getCustomIdColor(int namedColorId) {
	logDebug("getCustomIdColor");
	swfNamedColors_t swfNamedColor = static_cast<swfNamedColors_t>(namedColorId);

	switch (swfNamedColor) {
	case SWF_CUSTOM_NAMED_COLOR_RED:		
		//logInfo("return &colorCustom1 triggered...");
		//return Menu::getCustomColorTest();
		return &colorRed;
	case SWF_CUSTOM_NAMED_COLOR_GREEN:
		return &colorGreen;
	case SWF_CUSTOM_NAMED_COLOR_BLUE:
		return &colorBlue;
	case SWF_CUSTOM_NAMED_COLOR_YELLOW:
		return &colorYellow;
	case SWF_CUSTOM_NAMED_COLOR_MAGENTA:
		return &colorMagenta;
	case SWF_CUSTOM_NAMED_COLOR_CYAN:
		return &colorCyan;
	case SWF_CUSTOM_NAMED_COLOR_ORANGE:
		return &colorOrange;
	case SWF_CUSTOM_NAMED_COLOR_PURPLE:
		return &colorPurple;
	case SWF_CUSTOM_NAMED_COLOR_PINK:
		return &colorPink;
	case SWF_CUSTOM_NAMED_COLOR_BROWN:
		return &colorBrown;
	case SWF_CUSTOM_NAMED_COLOR_WHITE:
		return &colorWhite;
	case SWF_CUSTOM_NAMED_COLOR_LIGHTGREY:
		return &colorLtGrey;
	case SWF_CUSTOM_NAMED_COLOR_MIDGREY:
		return &colorMdGrey;
	case SWF_CUSTOM_NAMED_COLOR_DARKGREY:
		return &colorDkGrey;
	case SWF_CUSTOM_NAMED_COLOR_BLACK:
		return &colorBlack;
	case SWF_CUSTOM_NAMED_COLOR_LIGHTBLUE:
		return &colorLightBlue;
	case SWF_CUSTOM_NAMED_COLOR_DARKBLUE:
		return &colorDarkBlue;
	case SWF_CUSTOM_NAMED_COLOR_LIGHTGREEN:
		return &colorLightGreen;
	case SWF_CUSTOM_NAMED_COLOR_DARKGREEN:
		return &colorDarkGreen;
	case SWF_CUSTOM_NAMED_COLOR_LIGHTRED:
		return &colorLightRed;
	case SWF_CUSTOM_NAMED_COLOR_LIGHTYELLOW:
		return &colorLightYellow;
	case SWF_CUSTOM_NAMED_COLOR_DARKPURPLE:
		return &colorDarkPurple;
	case SWF_CUSTOM_NAMED_COLOR_LIGHTPINK:
		return &colorLightPink;
	case SWF_CUSTOM_NAMED_COLOR_DARKBROWN:
		return &colorDarkBrown;
	case SWF_CUSTOM_NAMED_COLOR_INVISIBLE:
		return &colorInvisible;
	default:
		logErr("getCustomIdColor: default case, How did this happen?! Returning color red, bad results are expected...");
		return &colorRed;
	}
}


bool GameHudColorsManager::isUserColorCustom(swfNamedColors_t userColorId) {
	return ((userColorId > swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT) && (userColorId <= swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE));
}







idColor GameHudColorsManager::getCurrentProfileFragNadeIconColor() {
	logDebug("getCurrentProfileFragNadeIconColor");

	if (!MemHelper::isBadReadPtr((void*)m_currentIdDeclUIColor)) {
		idDeclUIColor* declUIColorPtr = (idDeclUIColor*)m_currentIdDeclUIColor;
		return declUIColorPtr->hudEquipmentFragIcon.color;
	}
	logWarn("getCurrentProfileFragNadeIconColor could not find color, returning default");
	return m_defaultFragNadeIconColor;
}

idColor GameHudColorsManager::getCurrentProfileFragNadeBackgroundColor() {
	logDebug("getCurrentProfileFragNadeBackgroundColor");

	if (!MemHelper::isBadReadPtr((void*)m_currentIdDeclUIColor)) {
		idDeclUIColor* declUIColorPtr = (idDeclUIColor*)m_currentIdDeclUIColor;
		return declUIColorPtr->hudEquipmentFrag.color;
	}
	logWarn("getCurrentProfileFragNadeBackgroundColor could not find color, returning default");
	return m_defaultFragNadeBackgroundColor;
}


//! the reason why the color would change is because user might change the color profile
 idColor GameHudColorsManager::getCurrentProfileIceNadeIconColor() {
	logDebug("getCurrentProfileIceNadeIconColor");

	if (!MemHelper::isBadReadPtr((void*)m_currentIdDeclUIColor)) {
		//logWarn("getCurrentProfileIceNadeIconColor triggered...");
		idDeclUIColor* declUIColorPtr = (idDeclUIColor*)m_currentIdDeclUIColor;
		return declUIColorPtr->hudEquipmentCyroIcon.color;
		//return *(idColor*)(m_currentIdDeclUIColor + 0x1210);
	}
	logWarn("getCurrentProfileIceNadeIconColor could not find color, returning default");
	return m_defaultIceNadeIconColor;
}


 idColor GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor() {
	logDebug("getCurrentProfileIceNadeBackgroundColor");

	if (!MemHelper::isBadReadPtr((void*)m_currentIdDeclUIColor)) {
		idDeclUIColor* declUIColorPtr = (idDeclUIColor*)m_currentIdDeclUIColor;
		return declUIColorPtr->hudEquipmentCyro.color;
		//return declUIColorPtr.hudEquipmentCyro;
		//return *(idColor*)(m_currentIdDeclUIColor + 0x11FC);
	}
	logWarn("getCurrentProfileIceNadeBackgroundColor could not find color, returning default");
	return m_defaultIceNadeBackgroundColor;
}


 bool GameHudColorsManager::isHudElementWeaponRelated(int fullPathHash) {
	return(fullPathHash == weaponInfoBgModlessSpriteId || fullPathHash == weaponInfoTextSpriteId || fullPathHash == weaponInfoAmmoIconSpriteId || fullPathHash == weaponInfoBgSpriteId || fullPathHash == weaponInfoModIconId);
}

 bool GameHudColorsManager::isHudElementFragNade(int fullPathHash) {
	return (fullPathHash == fragCoolDownFillGlowSpriteId || fullPathHash == fragCoolDownInnerFillSpriteId || fullPathHash == fragCoolDownFillFillSpriteId || fullPathHash == fragIconSpriteId || fullPathHash == Equipment_background_Id || fullPathHash == Equipment_ready_flash_Id || fullPathHash == Equipment_cooldown_Id || fullPathHash == Equipment_icon_Id || fullPathHash == Equipment_switchedFlash_Id);
}

//! new method to hopefully detect frag icon better, especially at the start of the game
 bool GameHudColorsManager::isHudElementFragNadeBackGround(int fullPathHash) {
	for (size_t i = 0; i < m_HudEquipmentFragHashIdsVec.size(); i++)
	{
		if (fullPathHash == m_HudEquipmentFragHashIdsVec[i]) return true;
	}
	return false;
}

 bool GameHudColorsManager::isHudElementFragNadeIcon(int fullPathHash) {
	for (size_t i = 0; i < m_HudEquipmentFragIconHashIdsVec.size(); i++)
	{
		if (fullPathHash == m_HudEquipmentFragIconHashIdsVec[i]) return true;
	}
	return false;

}

 bool GameHudColorsManager::isHudElementFuelIcon(int fullPathHash) {
	return (fullPathHash == fuelRechargeInnerFillSpriteId || fullPathHash == fuelPipFillSpriteId || fullPathHash == fuelPipInnerFillSpriteId || fullPathHash == fuelIconSpriteId);
}

//! ex: is the element purple if the balistat wepon is equipped or is it other color because the weapon is low ammo or empty
 bool GameHudColorsManager::isHudElementWeaponColor(int namedColorId) {
	return ((namedColorId >= (int)SWF_NAMED_COLOR_WEAPON_SHOTGUN && namedColorId <= (int)SWF_NAMED_COLOR_WEAPON_UNMAYKR) || (namedColorId >= (int)SWF_NAMED_COLOR_WEAPON_SHOTGUN_FULL && namedColorId <= (int)SWF_NAMED_COLOR_WEAPON_UNMAYKR_FULL));
}

//todo we need to design a system that calls forceUpdateHudElementsColors everytime a displayed hud element has changed. Update, do we?
//! this is needed because some elements like the arrow of equipment are never changed by the game, but in our case it will be a way to updateColor all the colors that need to be updated.
 void GameHudColorsManager::forceUpdateHudElementsColors() {
	//logDebug("forceUpdateHudElementsColors");
	ColorManager::reapplySwfColors();
}






//! this func shoulg get trigger everytime reapplyswfcolors is called
//! will return overridden color or original color depending if each mod's feature is enabled or not
//! this func is triggered in setSpriteInstanceColor hook
 unsigned int GameHudColorsManager::getColor(__int64 spriteInstanceAddr, unsigned int namedColorId) {


	if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
		logErr("getColor: bad ptr: %p This should not happen...", (void*)spriteInstanceAddr);
		return namedColorId;
	}
	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
	int fullPathHash = spriteInstance->fullPathHash;


	//! dbg:
	/*if (fullPathHash == equipmentArrowSpriteId) {
		logInfo("getColor: debug: found equipmentArrowSpriteId, namedColorId: 0x%X spriteInstanceAddr: %p", namedColorId, (void*)spriteInstanceAddr);
	}

	if (fullPathHash == equipmentBackerSpriteId) {
		logInfo("getColor: debug: found equipmentBackerSpriteId, namedColorId: 0x%X spriteInstanceAddr: %p", namedColorId, (void*)spriteInstanceAddr);
	}*/



	if (modSettings::getOverrideFuel3PipsColor() != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT && isHudElementFuelIcon(fullPathHash)) {
		
		int chainsawAmmo = idPlayer_K::getChainsawAmmo();
		if (chainsawAmmo >= 3) {
			return modSettings::getOverrideFuel3PipsColor();
		}
		else if (chainsawAmmo < 1) {
			return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_LIGHTGREY;
		}
		return namedColorId;
	}


	if (!modSettings::getIsWeaponBarColored() && isHudElementWeaponRelated(fullPathHash)) {
		if (isHudElementWeaponColor(namedColorId)) {
			//return UserColorSet::getIceNadeArrow_Color();
			return swfNamedColors_t::SWF_NAMED_COLOR_WHITE;
		}
		return namedColorId;
	}



	//! indeed this works much better than the method below
	if (isHudElementFragNadeBackGround(fullPathHash)) {

		if (modSettings::getOverrideFragGrenadeColor() != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT && idPlayer_K::getFragNadeCount() > 0) {
			return modSettings::getOverrideFragGrenadeColor();
		}
		else if (modSettings::getOverrideFragGrenadeCooldownColor() != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT && idPlayer_K::getFragNadeCount() == 0) {
			return modSettings::getOverrideFragGrenadeCooldownColor();
		}
		return namedColorId;
	}

	if (isHudElementFragNadeIcon(fullPathHash)) {
		if (modSettings::getOverrideFragGrenadeColor() != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT && idPlayer_K::getFragNadeCount() > 0) {
			return modSettings::getOverrideFragGrenadeColor();
		}
		else if (modSettings::getOverrideFragGrenadeCooldownColor() != swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT && idPlayer_K::getFragNadeCount() == 0) {
			return modSettings::getOverrideFragGrenadeCooldownColor();
		}
		return namedColorId;
	}



	//? 1/5/24: should not need this anymore as we simply prevent them to render
	////! at start of the game when slayer does not own nades, their count value will be one be careful !
	//if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {		
	//	

	//	//! we don't show the arrow anymore in this mod as we have replaced it with a custom ice nade icon
	//	return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_INVISIBLE;
	//}

	static unsigned int namedColorIdBpDbg = -1;

	for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
	{
		if (fullPathHash == bloodPunchSpriteIdsVec[i]) {
			
			if (!UserColorSet::isDefaultColor_DesperatePunch() && idPlayer_K::isDesperatePunchAvailable()) {
				return UserColorSet::getDesperatePunchColor();
			}
			else if (!UserColorSet::isDefaultColor_Bloodpunch_1() && idPlayer_K::getBloodPunchCountInt() == 1) {
				return UserColorSet::getBloodpunch_1_Color();
			}
			else if (!UserColorSet::isDefaultColor_Bloodpunch_2() && idPlayer_K::getBloodPunchCountInt() == 2) {
				//logInfo("bp color icon debug: returning : getBloodpunch_2_Color: %u", UserColorSet::getBloodpunch_2_Color());
				return UserColorSet::getBloodpunch_2_Color();				
			}
			//logInfo("bp color icon debug: returning :namedColorId: %u", namedColorId);
			
			//! this is the answer to the bug when setting default color for bp which is not registered
			return getOriginalColor(fullPathHash);

			//? trying this: doent work either
			//return swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
			
			//? this is 301 when it should be default color...i don't get it...
			//return namedColorId;
			
		}
	}


	for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
	{

		if (fullPathHash == radSuitSpriteIdsVec[i]) {
			if (!UserColorSet::isDefaultColor_Radsuit()) {
				return UserColorSet::getRadsuitMeter_Color();				
			}
			return getOriginalColor(fullPathHash);
		}
		//! there is not 'low health state for the radmeter so we don't have to handle it
		//if (fullPathHash == radSuitSpriteIdsVec[i]) {
		//	if (!UserColorSet::isDefaultColor_Radsuit()) {
		//		//logInfo("debug: ! isDefaultColor_Radsuit namedColorId is %u", namedColorId);
		//		//! doing this so we still have the rad metter show as red color when rad suit is low:
		//		if (namedColorId == swfNamedColors_t::SWF_NAMED_COLOR_UI_RADIATION || namedColorId == swfNamedColors_t::SWF_NAMED_COLOR_UI_RADIATION_GRADIENT) {
		//			//logInfo("debug: UserColorSet::getRadsuitMeter_Color namedColorId is %u", namedColorId);
		//			return UserColorSet::getRadsuitMeter_Color();
		//		}
		//	}
		//	//! we don't need getOriginalColor because returning namedColorId will do just that. Update will it really?
		//	//logInfo("debug:  getOriginalColor(fullPathHash) namedColorId is %u", namedColorId);
		//	return getOriginalColor(fullPathHash);
		//	//return namedColorId;
		//}
	}
	//return getOriginalColor(fullPathHash); // <= this was a mistake as it made the whole hud green
	//! this should set the hud element to its default color, right(?!)
	return namedColorId;


}




//! carefull with that test it to make sure it works
 __int32 GameHudColorsManager::getOriginalColorAlt(int spriteId) {
	logDebug("getOriginalColorAlt");
	if (spriteId == radSuitBgSpriteId || spriteId == radSuitBgPulseSpriteId || spriteId == radSuitGlowImgSpriteId || spriteId == radSuitIconImgSpriteId || spriteId == radSuitRightSideSpriteId || spriteId == radSuitTextSpriteId || spriteId == radSuitBarBaseSpriteId) {
		return SWF_NAMED_COLOR_UI_RADIATION;
	}
	else if (spriteId == radSuitBarGradientSpriteId) {
		return SWF_NAMED_COLOR_UI_RADIATION_GRADIENT;
	}
	else if (spriteId == equipmentBackerSpriteId) {
		return SWF_NAMED_COLOR_HUD_EQUIPMENT_FRAG; //? this is not accurate as it could also be color ice but that will do...
	}
	else if (spriteId == equipmentArrowSpriteId || spriteId == bloodPunchIconOnSpriteId || spriteId == bloodPunchIconOffSpriteId || spriteId == bloodPunchTextSpriteId || spriteId == bloodPunchBindKbmSpriteId || spriteId == bloodPunchBindJoySpriteId) {
		return SWF_NAMED_COLOR_HUD_TEXT;
	}
	else if (spriteId == bloodPunchImgImgSpriteId || spriteId == bloodPunchBgPulseSpriteId || spriteId == bloodPunchChargeBgSpriteId) {
		return SWF_NAMED_COLOR_DASH_GLOW;
	}
	else if (spriteId == bloodPunchChargeGlowBgSpriteId || spriteId == bloodPunchBgImgSpriteId || spriteId == bloodPunchFillRightGlowSpriteId || spriteId == bloodPunchFillLeftGlowSpriteId) {
		return SWF_NAMED_COLOR_DASH_BASE;
	}
	else if (spriteId == armorInfoSpriteId || spriteId == healthPulseLoopSpriteId || spriteId == healthGlowSpriteId || spriteId == healthRightSideRightRightSpriteId || spriteId == healthRightSideMiddleMiddleSpriteId || spriteId == healthRightSideAddAmountSpriteId || spriteId == healthrightSideRightborderSpriteId) {
		return SWF_NAMED_COLOR_HUD_HEADER;
	}
	logWarn("getOriginalColor: could not find match, returning SWF_NAMED_COLOR_HUD_BASE, how could that happen?");
	return SWF_NAMED_COLOR_HUD_BASE;
}



 __int32 GameHudColorsManager::getOriginalColor(int spriteId) {
	logDebug("getOriginalColor");

	if (spriteId == 1400953715 || spriteId == 337295309 || spriteId == -1436734126 || spriteId == -1651990978 || spriteId == -1695464456 || spriteId == 841051668 || spriteId == -1642539358) {
		return SWF_NAMED_COLOR_UI_RADIATION;
	}
	else if (spriteId == 247756417) {
		return SWF_NAMED_COLOR_UI_RADIATION_GRADIENT;
	}
	else if (spriteId == -2014894865) {
		return SWF_NAMED_COLOR_HUD_EQUIPMENT_FRAG; //? this is not accurate as it could also be color ice but that will do...
	}
	else if (spriteId == -1637630621 || spriteId == 1200615612 || spriteId == -1614698948 || spriteId == 1430400401 || spriteId == -370399847 || spriteId == 348013304) {
		return SWF_NAMED_COLOR_HUD_TEXT;
	}
	else if (spriteId == 1656191230 || spriteId == 1334139029 || spriteId == -2114214347) {
		return SWF_NAMED_COLOR_DASH_GLOW;
	}
	else if (spriteId == -1700059271 || spriteId == 2038383566) {
		return SWF_NAMED_COLOR_DASH_BASE;
	}
	else if (spriteId == 1938093377 || spriteId == -216838433 || spriteId == -6992847 || spriteId == -1035373996 || spriteId == -33397220) {
		return SWF_NAMED_COLOR_HUD_HEADER;
	}
	logDebug("getOriginalColor: could not find match, returning SWF_NAMED_COLOR_HUD_BASE");
	return SWF_NAMED_COLOR_HUD_BASE;
}







 bool GameHudColorsManager::isEquipmentArrow(__int64 spriteInstanceAddr) {
	logDebug("isEquipmentArrow");

	if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
		logWarn("isEquipmentArrow:  bad ptr: %p", (void*)spriteInstanceAddr);
		return false;
	}
	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
	int fullPathHash = spriteInstance->fullPathHash;
	if (fullPathHash == equipmentArrowSpriteId) {
		return true;
	}
	return false;
}


/*static unsigned int changeTestColor() {
	logDebug("changeTestColor");

	m_debugNamedColorIndex++;
	if (m_debugNamedColorIndex < 0) {
		m_debugNamedColorIndex = 0;
	}
	if (m_debugNamedColorIndex > 269) {
		m_debugNamedColorIndex = 0;
	}
	logInfo("changeTestColor m_debugNamedColorIndex: %d", m_debugNamedColorIndex);
	return m_debugNamedColorIndex;
}*/






 void GameHudColorsManager::acquireMonitoredSpriteInstanceAddr(__int64 addr) {
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquireMonitoredSpriteInstanceAddr found bad ptr for addr: %p returning", (void*)addr);
		return;
	}
	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)addr;
	int fullPathHash = spriteInstance->fullPathHash;
	switch (fullPathHash)
	{
	case equipmentArrowSpriteId:
		m_currentEquipmentArrowSpriteInstanceAddr = addr;
		break;
	case equipmentBackerSpriteId:
		m_EquipmentBackerSpriteInstanceAddr = addr;
		break;
	case healthIconOuterSpriteId:
		m_healthIconOuterSpriteAddr = addr;
		break;
	case healthIconBgSpriteId:
		m_healthIconBgSpriteAddr = addr;
		break;
	case healthTextSpriteId:
		m_healthTextSpriteIdAddr = addr;
		break;
	case healthPipsOutlineSpriteId:
		m_healthPipsOutlineSpriteIdAddr = addr;
		break;
	case healthPipsGradientBottomSpriteId:
		m_healthPipsGradientBottomSpriteAddr = addr;
		break;
	case healthPipsGradientTopSpriteId:
		m_healthPipsGradientTopSpriteAddr = addr;
		break;
	case healthBottomAdornmentSpriteId:
		m_healthBottomAdornmentSpriteAddr = addr;
		break;
	case healthPulseLoopSpriteId:
		m_healthPulseLoopSpriteAddr = addr;
		break;
	case healthGlowSpriteId:
		m_healthGlowSpriteIdSpriteAddr = addr;
		break;
	case healthRightSideRightRightSpriteId:
		m_healthRightSideRightRightSpriteAddr = addr;
		break;
	case healthRightSideMiddleMiddleSpriteId:
		m_healthRightSideMiddleMiddleSpriteAddr = addr;
		break;
	case healthRightSideAddAmountSpriteId:
		m_healthRightSideAddAmountSpriteAddr = addr;
		break;
	case healthrightSideRightborderSpriteId:
		m_healthrightSideRightborderSpriteAddr = addr;
		break;
	case armorBarGradientSpriteId:
		m_armorBarGradientSpriteAddr = addr;
		break;
	case armorBarBaseSpriteId:
		m_armorBarBaseSpriteAddr = addr;
		break;
	case armorRightSideSpriteId:
		m_armorRightSideSpriteAddr = addr;
		break;
	case armorTextSpriteId:
		m_armorTextSpriteAddr = addr;
		break;
	case armorIconSpriteId:
		m_armorIconSpritAddr = addr;
		break;
	case armorIconGlowSpriteId:
		m_armorIconGlowSpriteAddr = addr;
		break;
	case armorInfoSpriteId:
		m_armorInfoSpriteAddr = addr;
		break;
	case armorBgSpriteId:
		m_armorBgSpriteAddr = addr;
		break;
	case weaponInfoBgModlessSpriteId:
		m_weaponInfoBgModlessSpriteAddr = addr;
		break;
	case weaponInfoTextSpriteId:
		m_weaponInfoTextSpriteAddr = addr;
		break;
	case weaponInfoBgSpriteId: //! this is the big container bar
		m_weaponInfoBgSpriteAddr = addr;
		break;
	case bloodPunchBgPulseSpriteId:
		m_bloodPunchBgPulseSpriteAddr = addr;
		break;
	case bloodPunchChargeGlowBgSpriteId:
		m_bloodPunchChargeGlowBgSpriteAddr = addr;
		break;
	case bloodPunchBgImgSpriteId:
		m_bloodPunchBgImgSpriteAddr = addr;
		break;
	case bloodPunchBorderImgSpriteId:
		m_bloodPunchBorderImgSpriteAddr = addr;
		break;
	case bloodPunchIconOnSpriteId:
		m_bloodPunchIconOnSpriteAddr = addr;
		break;
	case bloodPunchIconOffSpriteId:
		m_bloodPunchIconOffSpriteAddr = addr;
		break;
	case bloodPunchReadyFlashSpriteId:
		m_bloodPunchReadyFlashSpriteAddr = addr;
		break;
	case bloodPunchFillRightGlowSpriteId:
		m_bloodPunchFillRightGlowSpriteAddr = addr;
		break;
	case bloodPunchFillRightImgSpriteId:
		m_bloodPunchFillRightImgSpriteAddr = addr;
		break;
	case bloodPunchFillLeftGlowSpriteId:
		m_bloodPunchFillLeftGlowSpriteAddr = addr;
		break;
	case bloodPunchFillLeftImgSpriteId:
		m_bloodPunchFillLeftImgSpriteAddr = addr;
		break;
	case bloodPunchTextSpriteId:
		m_bloodPunchTextSpriteAddr = addr;
		break;
	case bloodPunchBindKbmSpriteId:
		m_bloodPunchBindKbmSpriteAddr = addr;
		break;
	case bloodPunchBindJoySpriteId:
		m_bloodPunchBindJoySpriteAddr = addr;
		break;
	case radSuitBarGradientSpriteId:
		m_radSuitBarGradientSpriteAddr = addr;
		break;
	case radSuitBarBaseSpriteId:
		m_radSuitBarBaseSpriteAddr = addr;
		break;
	case radSuitRightSideSpriteId:
		m_radSuitRightSideSpriteAddr = addr;
		break;
	case radSuitTextSpriteId:
		m_radSuitTextSpriteAddr = addr;
		break;
	case radSuitIconImgSpriteId:
		m_radSuitIconImgSpriteAddr = addr;
		break;
	case radSuitGlowImgSpriteId:
		m_radSuitGlowImgSpriteAddr = addr;
		break;
	case radSuitBgSpriteId:
		m_radSuitBgSpriteAddr = addr;
		break;
	case radSuitBgPulseSpriteId:
		m_radSuitBgPulseSpriteAddr = addr;
		break;
	case bloodPunchChargeBgSpriteId:
		m_bloodPunchChargeBgSpriteAddr = addr;
		break;
	case bloodPunchImgImgSpriteId:
		m_bloodPunchImgImgSpriteAddr = addr;
		break;
	case fragCoolDownFillGlowSpriteId:
		m_fragCoolDownFillGlowSpriteAddr = addr;
		break;
	case equipmentSpriteId:
		m_debug_EquipmentSpriteInstanceAddr = addr;
		break;
		/*case weaponInfoBigBarSpriteId:
			m_weaponInfoBigBarSpriteAddr;*/
	default:
		break;
	}
}



//static void debugPrintFragIconSpriteInstanceInfo() {
//	//idSWFSpriteInstanceManager::debugPrintSpriteInstanceInfo(m_debug_fragIconSpriteAddr);
//	//idSWFSpriteInstanceManager::debugPrintSpriteInstanceInfo(m_fragCoolDownFillGlowSpriteAddr);
//	idSWFSpriteInstanceManager::debugPrintSpriteInstanceInfo(m_debug_EquipmentSpriteInstanceAddr);
//}



//? ok so this will crash at some point during horde mode start at least
/*static void debugPrintFragIconSpriteInstanceInfo() {

	idSWFSpriteInstance* equipmentSpriteInstance = idSWFSpriteInstanceManager::FindParent(m_fragCoolDownFillGlowSpriteAddr, equipmentSpriteId);
	if (MemHelper::isBadReadPtr(equipmentSpriteInstance)) {
		logWarn("debugPrintFragIconSpriteInstanceInfo: failed to find equipmentSpriteInstance, found: %p", equipmentSpriteInstance);
		return;
	}
	idSWFSpriteInstanceManager::debugPrintSpriteInstanceInfo(equipmentSpriteInstance);

}*/





 swfRect_t GameHudColorsManager::getFragIconCoords() {
	if (!m_fragCoolDownFillGlowSpriteAddr) {
		logWarn("getFragIconCoords: m_fragCoolDownFillGlowSpriteAddr is null returning empty  swfRect_t");
		return swfRect_t();
	}
	/*if (MemHelper::isBadReadPtr((void*)m_fragCoolDownFillGlowSpriteAddr)) {
		logWarn("getFragIconCoords: m_fragCoolDownFillGlowSpriteAddr is bad ptr returning empty swfRect_t");
		return swfRect_t();
	}*/
	return idSWFSpriteInstanceManager::getBounds((idSWFSpriteInstance*)m_fragCoolDownFillGlowSpriteAddr);
}



//! using this atm for debugging to show the bounds of hud elements and if it can be usefull do display text over them
 swfRect_t GameHudColorsManager::getEquipmentArrowBounds() {
	if (!MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSpriteInstanceAddr)) {
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSpriteInstanceAddr;
		return spriteInstance->bounds;
	}
	//logErr("getEquipmentArrowBounds: could not get bounds, return default vec4");
	return swfRect_t();
}

 swfRect_t GameHudColorsManager::getEquipmentBackerBounds() {
	if (!MemHelper::isBadReadPtr((void*)m_EquipmentBackerSpriteInstanceAddr)) {
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_EquipmentBackerSpriteInstanceAddr;
		return spriteInstance->bounds;
	}
	//logErr("getEquipmentArrowBounds: could not get bounds, return default vec4");
	return swfRect_t();
}

 swfRect_t GameHudColorsManager::getSpriteBounds(int spriteHashId) {
	if (!MemHelper::isBadReadPtr((void*)m_currentEquipmentArrowSpriteInstanceAddr)) {
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_currentEquipmentArrowSpriteInstanceAddr;
		return spriteInstance->bounds;
	}
	//logErr("getEquipmentArrowBounds: could not get bounds, return default vec4");
	return swfRect_t();
}





//! DEBUG:	





 unsigned int GameHudColorsManager::debugLogInstancesDefaultNamesColors(__int64 spriteInstanceAddr, unsigned int namedColorId) {
	logDebug("debugLogInstancesDefaultNamesColors");

	if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
		logWarn("debugLogInstancesDefaultNamesColors: bad ptr: %p", (void*)spriteInstanceAddr);
		return namedColorId;
	}
	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
	int fullPathHash = spriteInstance->fullPathHash;

	if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {
		logInfo("debugLogInstancesDefaultNamesColors: equipment: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
		return namedColorId;
	}
	for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
	{
		if (fullPathHash == bloodPunchSpriteIdsVec[i]) {
			logInfo("debugLogInstancesDefaultNamesColors: bloodPunch: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
			return namedColorId;
		}
	}
	for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
	{
		if (fullPathHash == radSuitSpriteIdsVec[i]) {
			logInfo("debugLogInstancesDefaultNamesColors: radSuit: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
			return namedColorId;
		}
	}
	return namedColorId;
}


 unsigned int GameHudColorsManager::testColors(__int64 spriteInstanceAddr, unsigned int namedColorId) {
	logDebug("testColors");

	if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
		logWarn("testColors: bad ptr: %p", (void*)spriteInstanceAddr);
		return namedColorId;
	}
	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
	int fullPathHash = spriteInstance->fullPathHash;

	if (fullPathHash == equipmentArrowSpriteId || fullPathHash == equipmentBackerSpriteId) {
		//logInfo("testColors: equipment: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
		return m_debugNamedColorIndex;
	}
	for (size_t i = 0; i < bloodPunchSpriteIdsVec.size(); i++)
	{
		if (fullPathHash == bloodPunchSpriteIdsVec[i]) {
			//logInfo("testColors: bloodPunch: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
			return m_debugNamedColorIndex;
		}
	}
	for (size_t i = 0; i < radSuitSpriteIdsVec.size(); i++)
	{
		if (fullPathHash == radSuitSpriteIdsVec[i]) {
			//logInfo("testColors: radSuit: fullPathHash: %d namedColor: %u", fullPathHash, namedColorId);
			return m_debugNamedColorIndex;
		}
	}
	return namedColorId;
}



 void GameHudColorsManager::debugLogFragIconCoords() {
	if (!MemHelper::isBadReadPtr((void*)m_fragCoolDownFillGlowSpriteAddr)) {
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)m_fragCoolDownFillGlowSpriteAddr;
		if (!MemHelper::isBadReadPtr(spriteInstance)) {
			auto rect = spriteInstance->bounds;
			std::string name = std::string(spriteInstance->name.str);
			logInfo("debugLogFragIconCoords: spriteInstance name %s, hash: %X (dec: %d) rect: % .2f % .2f % .2f % .2f", name.c_str(), spriteInstance->fullPathHash, spriteInstance->fullPathHash, rect.tl.x, rect.tl.y, rect.br.x, rect.br.y);
		}
		else {
			logWarn("debugLogFragIconCoords: spriteInstance is bad ptr: %p", spriteInstance);
		}
	}
	else {
		logWarn("debugLogFragIconCoords: m_fragCoolDownFillGlowSpriteAddr is bad ptr: %p", (void*)m_fragCoolDownFillGlowSpriteAddr);
	}
}


//! used in setSpriteInstanceColorHook 
 void GameHudColorsManager::addSpriteInstanceAddrToDebugVec(__int64 addr) {
	for (size_t i = 0; i < m_debugSpriteInstanceAddressesVec.size(); i++)
	{
		if (m_debugSpriteInstanceAddressesVec[i] == addr) return;
	}
	//logInfo("addSpriteInstanceAddrToDebugVec adding sprite addr to m_spriteInstanceAddressesVec...");
	m_debugSpriteInstanceAddressesVec.push_back(addr);
}

//! this is used to debug the hud elements for which we already have gotten ids but don't know exactly what they are:
// bool GameHudColorsManager::isSpriteIdBeingDebugged(__int64 spriteInstanceAddr) {
//	if (MemHelper::isBadReadPtr((void*)spriteInstanceAddr)) {
//		logErr("isSpriteIdBeingDebugged found bad ptr for addr: %p returning false", (void*)spriteInstanceAddr);
//		return false;
//	}
//	idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAddr;
//	for (size_t i = 0; i < m_spriteHashIdDebugVec.size(); i++)
//	{
//		if (m_spriteHashIdDebugVec[i] == spriteInstance->fullPathHash) {
//			//logInfo("isSpriteIdBeingDebugged:returning true");
//			return true;
//		}
//	}
//	return false;
//}

 bool GameHudColorsManager::isSpriteColorIdBeingDebugged(unsigned int namedColorId) {
	for (size_t i = 0; i < m_debugColorIdVec.size(); i++)
	{
		if (m_debugColorIdVec[i] == namedColorId) return true;
	}
	return false;
}
