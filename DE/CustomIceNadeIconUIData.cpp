#include "CustomIceNadeIconUIData.h"


bool CustomIceNadeIconUIData::isIceNadeOnCoolDown() {
	return isIceOnCoolDown;
}

 void CustomIceNadeIconUIData::updateIsRenderingAllowed(bool isAllowed) {
	if (isRenderingAllowed != isAllowed) { //! just because 2 thread acces this...i'm being paranoid.
		isRenderingAllowed = isAllowed;
	}
}

void CustomIceNadeIconUIData::updateIsIceNadeCooldownStatus() {
	isIceOnCoolDown = (idPlayer_K::getIceNadeCount() == 0);
}

 void CustomIceNadeIconUIData::updateMaterials() {
	/*m_iceNadeIconUIData.extraBorderMrt = MaterialLib::getWhite();
	m_iceNadeIconUIData.borderMrt = MaterialLib::getWhite();
	m_iceNadeIconUIData.backgroundMrt = MaterialLib::getWhite();
	m_iceNadeIconUIData.iconMrt = MaterialLib::getWhite();*/

	//? settings all the materials to white to try to find crash origin
	extraBorderMrt = MaterialLib::getIceNadeExtraBorderMtr();
	borderMrt = MaterialLib::getIceNadeBorderMtr();
	backgroundMrt = MaterialLib::getIceNadeBackgroundMtr();
	iconMrt = MaterialLib::getIceGrenadeMtr();
}

 void CustomIceNadeIconUIData::updateCoords() {
	//auto fragIconSwfRect = GameHudColorsManager::getFragIconCoords();
	//auto fragIconSwfRect = idPlayer_K::getEquipmentIconCoords(Equipment_background_Id); // too big 
	auto fragIconSwfRect = idPlayer_K::getEquipmentIconCoords(Equipment_cooldown_Id); //! just perfect exactly the pos and size we used to get fromGameHudColorsManager::getFragIconCoords()
	//auto fragIconSwfRect = idPlayer_K::getEquipmentIconCoords(Equipment_icon_Id); 
	//logInfo("debug: updateCoords: just got frag icon coords");
	float rectWidth = fragIconSwfRect.br.x - fragIconSwfRect.tl.x;
	outerIconBounds.tl.x = m_iceNadeIconOffsetMul * rectWidth + fragIconSwfRect.tl.x;
	outerIconBounds.br.x = m_iceNadeIconOffsetMul * rectWidth + fragIconSwfRect.br.x;
	outerIconBounds.tl.y = fragIconSwfRect.tl.y;
	outerIconBounds.br.y = fragIconSwfRect.br.y;

	float iceContainerRectWidth = outerIconBounds.br.x - outerIconBounds.tl.x;
	float iceContainerRectHeight = outerIconBounds.br.y - outerIconBounds.tl.y;
	//float iconScale = .29f;
	innerIconBounds.tl.x = outerIconBounds.tl.x + m_starIconScale * iceContainerRectWidth;
	innerIconBounds.tl.y = outerIconBounds.tl.y + m_starIconScale * iceContainerRectHeight;
	innerIconBounds.br.x = outerIconBounds.br.x - m_starIconScale * iceContainerRectWidth;
	innerIconBounds.br.y = outerIconBounds.br.y - m_starIconScale * iceContainerRectHeight;
}

 void CustomIceNadeIconUIData::updateColors() {
	//! this shoud be before func not here:
	/*if (!idInventoryCollectionManager::isItemOwned(ItemID::IceBomb)) {
	return;
	}*/

	idColor baseIceIconColor;
	idColor baseIceBackGroundColor;
	//idColor baseBorderColor;			

	if (!isIceOnCoolDown) { //! if nade ready:
		//IniFileData::getOverrideIceGrenadeColor();	

		if (UserColorSet::isDefaultColorIceNadeArrow()) {
			baseIceIconColor = GameHudColorsManager::getCurrentProfileIceNadeIconColor();
			baseIceBackGroundColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();
			//baseBorderColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();

			iconColor = baseIceIconColor;
		}
		else { //! if custom user color
			baseIceIconColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeArrow_Color());
			baseIceBackGroundColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeArrow_Color());
			//baseBorderColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeArrow_Color());
			GameHudColorsManager::setIconWhiteBlendColor(baseIceIconColor, iconColor, m_abilityAvailableStarIconWhiteBlend);
		}

		/*GameHudColorsManager::setIconWhiteBlendColor(baseIceIconColor, m_iceNadeIconUIData.iconColor, m_abilityAvailableStarIconWhiteBlend);*/


	}
	else { //! if ice not available
		if (UserColorSet::isDefaultColorIceNadeCoolDownArrow()) {
			baseIceIconColor = colorDkGrey;
			baseIceBackGroundColor = colorDkGrey;
			//baseBorderColor = colorBlack;
		}
		else {
			baseIceIconColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeCooldownArrow_Color());
			baseIceBackGroundColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeCooldownArrow_Color());
			//baseBorderColor = *(idColor*)GameHudColorsManager::getCustomIdColor(UserColorSet::getIceNadeCooldownArrow_Color());
		}

		GameHudColorsManager::setAlpha(baseIceIconColor, iconColor, m_abilityDisabledStarIconAlpha);
	}

	GameHudColorsManager::setAlpha(baseIceBackGroundColor, backgroundColor, m_BackgroundAlpha);

	GameHudColorsManager::setAlpha(baseIceBackGroundColor, borderColor, m_BorderAlpha);

	GameHudColorsManager::setAlpha(baseIceBackGroundColor, extraBorderColor, m_ExtraBorderAlpha);


	//m_iceNadeIconUIData.backgroundColor = baseIceBackGroundColor;
}

 void CustomIceNadeIconUIData::updateCooldownTimeLeftStr() {
	if (!isIceOnCoolDown) {
		cooldownText = "00";
		return;
	}

	long long gameTime = idMapInstanceLocalManager::getGameTime_t();
	auto timers = idPlayer_K::getEquipmentTimers(equipmentIndex_t::ICE);
	int countdown = (int)((timers.equipmentRechargeTime - gameTime) / 1000000) + 1; //! we need to add 1 to make it look correct.
	if (countdown < 0) {
		countdown = 0; //! making sure we never show neg values.
	}
	if (countdown < 10) {
		cooldownText = "0" + std::to_string(countdown);
	}
	else {
		cooldownText = std::to_string(countdown);
	}
}
