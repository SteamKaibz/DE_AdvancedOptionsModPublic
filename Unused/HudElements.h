//! not using this atm, may be if we ever implement a custom hud we'll come back to it


//#pragma once
////#include "ReclassTypes.h"
////#include "idColor.h"
////#include "Game.h"
//#include "HudColor.h"
////#include "GameHudColorsManager.h"
////#include "../DE/ReclassTypes.h"
//#include "../DE/idPlayer.h"
//#include "../DE/GameHudColorsManager.h"
//#include "HudAmmoData.h"
//
//
//
//class HudUtils {
//
//public:
//	//! used to adjust the position of the pips relative to the icon (like the nade icon)
//	static idVec2 getPipsPosOffsetsPrct(hudSpriteId_t hudId) {
//		switch (hudId)
//		{
//		case HUD_SPRITE_ID_UNKNOWN:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_FLAMEBELCH:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_FUEL:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_FRAG:
//			return idVec2(-.55f, 0.15f);
//		case HUD_SPRITE_ID_ICE:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_CRUCIBLE:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_HAMMER:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_BLOODPUNCH:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_DASH:
//			return idVec2(0, 0);
//		case HUD_SPRITE_ID_MAX:
//			return idVec2(0, 0);
//		default:
//			return idVec2(0, 0);
//		}
//	}
//};
//
///// <summary>
///// an icon is like the nade icon which should have a coordinates, color, material....
///// </summary>
//struct HudIcon {
//public:
//	hudSpriteId_t id = hudSpriteId_t::HUD_SPRITE_ID_UNKNOWN;
//	idVec4 iconContainerCoordsVec4; //! icon coordinates
//	//__int64 materialAddr = 0; //? may be we don't need material here, just the id will let the renderer know what material to use?
//	//idColor colorActivated = colorWhite;
//	//idColor colorDeactivated = colorMdGrey;
//	//idColor colorDeactivated = colorFragIconDeactivated; //? just a test creat a func to get colors instead
//	//idColor colorCurrent = colorWhite;
//	idColor color = colorWhite;
//	bool isInvertedX = false;
//	bool isInvertedY = false;
//
//	HudIcon(idVec4& _coordinatesVec4, hudSpriteId_t _id) : iconContainerCoordsVec4{ _coordinatesVec4 }, id{_id}
//	{
//		//colorActivated = HudColor::getDefaultIdcolor(id);
//	}
//
//	//void updateCoordinates() { //! we assume icon will fill the whote area
//	//	iconContainerCoordsVec4.x = coordinates.x;
//	//	iconContainerCoordsVec4.y = coordinates.y;
//	//	iconContainerCoordsVec4.w = coordinates.w;
//	//	iconContainerCoordsVec4.h = coordinates.h;
//	//}
//
//	void updateCoords(idVec4 coordsVec4) {
//		iconContainerCoordsVec4 = coordsVec4;
//	}
//
//	void updateColor(idColor _color) {
//		//colorCurrent = color;
//		color = _color;
//	}
//
//	//void updateColor(int val) {
//	//	if (id == hudSpriteId_t::HUD_SPRITE_ID_ICE) {
//	//		if (val > 0) {
//	//			colorCurrent = colorIceNadeDeactivatedIcon; //? just a test creat a func to get colors instead
//	//			//colorCurrent = colorIconDeactivated;
//	//		}
//	//		else {
//	//			colorCurrent = colorActivated;
//	//		}
//	//	}
//	//	else if (id == HUD_SPRITE_ID_AMMOS_SHELL || id == HUD_SPRITE_ID_AMMOS_BULLET || id == HUD_SPRITE_ID_AMMOS_ROCKET || id == HUD_SPRITE_ID_AMMOS_CELL || id == HUD_SPRITE_ID_AMMOS_UNKNOWN) {
//	//		colorCurrent = GameHudColorsManager::getCurrentAmmoColor(id);
//	//	}
//	//}
//
//	void updateId(hudSpriteId_t _id) {
//		id = _id;
//	}
//
//	//idColor computeColor(int val) {
//	//	if (id == hudSpriteId_t::HUD_SPRITE_ID_ICE) {
//	//		if (val > 0) {
//	//			return colorIceNadeDeactivatedIcon; 
//	//			//colorCurrent = colorIconDeactivated;
//	//		}
//	//		else {
//	//			return colorActivated;
//	//		}
//	//	}
//	//}
//};
//
///// <summary>
///// Container of text for the hud, it's material should always be _white. (doesn't mean the color will be white btw)
///// </summary>
//struct HudText {
//public:
//	hudSpriteId_t id = hudSpriteId_t::HUD_SPRITE_ID_UNKNOWN;
//	//hudTextType_t textType = hudTextType_t::HUD_TEXT_TYPE_COOLDOWN;
//	//hudTestAlignment_t alignment = hudTestAlignment_t::HUD_TEXT_ALIGNEMENT_CENTER;
//	idVec4 containerCoordsVec4;
//	idVec2 coordinatesVec2;
//	float fontScale = 1;
//	uint64_t textIntVal = 0;
//	std::string text = "";
//	//idColor color = colorWhite;
//	idColor color = colorWhite;
//	//idColor colorDeactivated = colorInvisible;
//
//	HudText(idVec4 _coordinatesVec4, hudSpriteId_t _id, std::string defaultText = "") : containerCoordsVec4{_coordinatesVec4}, id{_id}, text{ defaultText }
//	{
//		
//	}
//
//
//	/*void updateCoords(idVec4 _coordinatesVec4) {
//		containerCoordsVec4 = _coordinatesVec4;
//		updateSizes();
//	}*/
//	//void updateText(float txtFloat) {
//	//	//float f = 3.14159;
//	//	std::string text = std::to_string(txtFloat);
//	//	size_t pos = text.find('.');
//	//	if (pos != std::string::npos && text.length() >= pos + 2) {
//	//		text = text.substr(0, pos + 2);
//	//	}
//	//	updateSizes();
//	//}
//
//	void updateId(hudSpriteId_t _id) {
//		id = _id;
//	}
//
//	//void update(uint64_t textInt) {
//	//	textIntVal = textInt;
//	//	//! instead of making text invisible we don't render it
//	//	/*if (textIntVal < 1) {
//	//		color = colorInvisible;
//	//	}
//	//	else {
//	//		color = colorWhite;
//	//	}*/
//
//	//	//logInfo("HudText::updateColor triggered id is %d", (int)id);
//
//	//	if (id == HUD_SPRITE_ID_ICE) {
//	//		text = std::to_string(textInt);
//	//	}
//	//	else if (id == HUD_SPRITE_ID_AMMOS_SHELL || id == HUD_SPRITE_ID_AMMOS_BULLET || id == HUD_SPRITE_ID_AMMOS_ROCKET || id == HUD_SPRITE_ID_AMMOS_CELL || id == HUD_SPRITE_ID_AMMOS_UNKNOWN) {
//	//		text = getText(textInt); //! this should add padding so the text is always close to the icon, in theory.
//	//	}
//	//	else {
//	//		text = std::to_string(textInt);
//	//	}
//	//	updateSizes();
//	//}
//
//	std::string getText(int textIntVal) {
//		//int textIntVal = 1;
//		int fixed_length = 3;
//
//		std::stringstream ss;
//		ss << std::setw(fixed_length) << std::setfill(' ') << textIntVal;
//
//		//logInfo("getText str size is: %zu ", ss.str().size());
//		return ss.str();
//	/*	std::string text = ss.str();
//		std::cout << "Text: " << text << std::endl;*/
//	}
//
//	/*void updateText(std::string _text) {
//		text = _text;
//		updateSizes();
//	}*/
//
//	void updateColor(idColor id_color) {
//		//coordinatesVec2.set(x, y);
//		//fontScale = font_scale;
//		//text = _text;
//		color = id_color;
//	}
//
//
//	//void updateSizes() { //? we need text content first to compute str length
//	//	writeTextCenteredV2();
//
//	//	//if (textType == hudTextType_t::HUD_TEXT_TYPE_COUNT) { //! count is assumed to be bottom right and 1 char length max !!!!
//
//	//	//	fontScale = Game::getFontScaleFromWidth(iconCoordsVec4.w / 2, text.size());
//	//	//	coordinatesVec2.x = iconCoordsVec4.x + iconCoordsVec4.w / 2;
//	//	//	coordinatesVec2.y = iconCoordsVec4.y; //? will need to change this surely
//
//	//	//	/*coordinatesVec2.x = iconCoordsVec4.x + (2 * iconCoordsVec4.w / 3);
//	//	//	coordinatesVec2.y = iconCoordsVec4.y + (2 * iconCoordsVec4.w / 3);
//	//	//	float lengthMax = (iconCoordsVec4.w / 3);
//	//	//	fontScale = lengthMax / Game::getSmallCharWidth(); */
//
//	//	//}
//	//	//else if (textType == hudTextType_t::HUD_TEXT_TYPE_COOLDOWN) {
//	//	//	
//	//	//	//writeTextStartingBottomLeft();		
//	//	//	//writeTextCentered();
//	//	//	writeTextCenteredV2();
//	//	//}
//	//}
//
//	//! this code will write text exactly a x,y meaning the number's borrom left will start being written at this location whatever the scale is
//	//void writeTextStartingBottomLeft() {
//	//	fontScale = Game::getFontScaleFromWidth(containerCoordsVec4.w, text.size());
//	//	float text_x_Offset = ttSuper98_text_x_Offset_base * fontScale;
//	//	coordinatesVec2.x = containerCoordsVec4.x + text_x_Offset;
//	//	coordinatesVec2.y = containerCoordsVec4.y - (Game::getSmallCharHeight() - (ttSuper98_text_y_Offset_base * fontScale));
//	//	//! failed attempts here, keep them:
//	//		//coordinatesVec2.y = iconCoordsVec4.y;
//	//		//coordinatesVec2.y = iconCoordsVec4.y - (Game::getSmallCharHeight());
//	//		//coordinatesVec2.y = iconCoordsVec4.y - (40.57 - (ttSuper98_text_y_Offset_base * fontScale));
//	//		//coordinatesVec2.y = iconCoordsVec4.y - (28 - (ttSuper98_text_y_Offset_base * fontScale)); 
//	//		//coordinatesVec2.y = iconCoordsVec4.y - (ttSuper98_text_y_Offset_base * fontScale); //! this doesn't work with scaling
//	//}
//
//	//! centered in the x,y,w,h with a bit of spacing
//	//? the text can never be higer than 2 chars for equipment ice nade cooldown
//	//void writeTextCentered() {
//	//	//unsigned int textSize = text.size();
//	//	//if (textSize < 2) textSize = 2; // otherwise the text becomes too big i feel when lower than 10
//	//	 //! harcoding string size to 2, so when lower than 10, then number doesn't become enormous
//	//	float desiredTextWidth = iconCoordsVec4.w - (iconCoordsVec4.w * 0.5);//! hardcoding this for now.
//	//	fontScale = Game::getFontScaleFromWidth(desiredTextWidth - 2 * getSpacingCentered(2, desiredTextWidth), 2);
//	//	//fontScale = Game::getFontScaleFromWidth(iconCoordsVec4.w - 2 * getSpacingCentered(2), 2);
//	//	float text_x_Offset = ttSuper98_text_x_Offset_base * fontScale; //! this is the offset to get the char to start at x.
//	//	//text_x_Offset += iconCoordsVec4.w - (float)Game::GetStringWidthInPixels(text.c_str(), fontScale) / 2;
//	//	//coordinatesVec2.x = iconCoordsVec4.x + text_x_Offset;
//	//	//coordinatesVec2.x = iconCoordsVec4.x + text_x_Offset + (iconCoordsVec4.w - (float)Game::GetStringWidthInPixels(text.c_str()) / 2);
//	//	if (text.size() < 2) {
//	//		coordinatesVec2.x = iconCoordsVec4.x + text_x_Offset + getSpacingCentered(1, desiredTextWidth);
//	//	}
//	//	else {
//	//		coordinatesVec2.x = iconCoordsVec4.x + text_x_Offset + getSpacingCentered(2, desiredTextWidth);
//	//	}		
//	//	coordinatesVec2.y = iconCoordsVec4.y - (Game::getSmallCharHeight() - (ttSuper98_text_y_Offset_base * fontScale)) + (iconCoordsVec4.h - getSpacingCentered_Y_());
//	//}
//
//	//! most of those values were found though trial an error
//	void writeTextCenteredV2() {		
//		float desiredTextWidth = determineTextWidth();
//		//float desiredTextWidth = containerCoordsVec4.w - (containerCoordsVec4.w * 0.7f);//! hardcoding this 0.7 val.
//		fontScale = Game::getFontScaleFromWidth(desiredTextWidth - 2 * getSpacingCentered_X(2, desiredTextWidth), determineTextSize());
//		
//		//fontScale = Game::getFontScaleFromWidth(desiredTextWidth - 2 * getSpacingCentered(2, desiredTextWidth), 2);
//		float textWidth = (float)Game::GetStringWidthInPixels(text.c_str(), fontScale);
//		float text_x_Offset = ttSuper98_text_x_Offset_base * fontScale; //! this is the offset to get the char to start at x.		
//		
//		coordinatesVec2.x = containerCoordsVec4.x + (containerCoordsVec4.w / 2 - textWidth / 2) + text_x_Offset;
//		//if (text.size() < 2) {
//		//	coordinatesVec2.x = containerCoordsVec4.x + (containerCoordsVec4.w / 2 - textWidth / 2) + text_x_Offset;
//		//	//coordinatesVec2.x = iconCoordsVec4.x + text_x_Offset + getSpacingCentered(1, desiredTextWidth);
//		//}
//		//else {
//		//	coordinatesVec2.x = containerCoordsVec4.x + (containerCoordsVec4.w / 2 - textWidth / 2) + text_x_Offset;
//		//	//coordinatesVec2.x = iconCoordsVec4.x + text_x_Offset + getSpacingCentered(2, desiredTextWidth);
//		//}
//		coordinatesVec2.y = containerCoordsVec4.y - (Game::getSmallCharHeight() - (ttSuper98_text_y_Offset_base * fontScale)) + (containerCoordsVec4.h - getSpacingCentered_Y_());
//		 
//		//logInfo("writeTextCenteredV2: text: %s fontScale: %.2f x: %.2f, y: %.2f", text.c_str(), fontScale, coordinatesVec2.x, coordinatesVec2.y);
//	}
//
//	//! how wide we want the text to be inside its container
//	float determineTextWidth() {
//		if (id == HUD_SPRITE_ID_ICE) {
//			return containerCoordsVec4.w - (containerCoordsVec4.w * 0.7f);
//		}
//		else if (id == HUD_SPRITE_ID_AMMOS_SHELL || id == HUD_SPRITE_ID_AMMOS_BULLET || id == HUD_SPRITE_ID_AMMOS_ROCKET || id == HUD_SPRITE_ID_AMMOS_CELL || id == HUD_SPRITE_ID_AMMOS_UNKNOWN) {
//			return containerCoordsVec4.w - (containerCoordsVec4.w * 0.2f);
//		}
//		else {
//			return containerCoordsVec4.w - (containerCoordsVec4.w * 0.1f);
//		}
//	}
//
//	//! this exists because we want the text to keep the same font size whether a value is 999 or 1
//	unsigned int determineTextSize() {
//		if (id == HUD_SPRITE_ID_ICE) {
//			return 2; 
//		}
//		else if (id == HUD_SPRITE_ID_AMMOS_SHELL || id == HUD_SPRITE_ID_AMMOS_BULLET || id == HUD_SPRITE_ID_AMMOS_ROCKET || id == HUD_SPRITE_ID_AMMOS_CELL || id == HUD_SPRITE_ID_AMMOS_UNKNOWN) {
//			return 3;
//		}		
//		return (unsigned int) text.size();
//	}
//
//	float getSpacingCentered_X(int charsCount, float desiredTextWidth) {
//		if (id == HUD_SPRITE_ID_ICE) {
//			if (charsCount > 1) {
//				return (float)(desiredTextWidth * float(33 / 100)); //! for 2 chars
//			}
//			else {
//				return (float)(desiredTextWidth * float(80 / 100));
//			}
//		}
//		else if (id == HUD_SPRITE_ID_AMMOS_SHELL || id == HUD_SPRITE_ID_AMMOS_BULLET || id == HUD_SPRITE_ID_AMMOS_ROCKET || id == HUD_SPRITE_ID_AMMOS_CELL || id == HUD_SPRITE_ID_AMMOS_UNKNOWN) {
//			return (float)(desiredTextWidth * float(50 / 100));
//		}
//		return (float)(desiredTextWidth * float(10 / 100)); //! arbitrary val not tested.		
//	}
//
//	
//	float getSpacingCentered_Y_() {
//		if (id == HUD_SPRITE_ID_ICE) {
//			return (float)(containerCoordsVec4.h * 35 / 100);
//		}
//		else if (id == HUD_SPRITE_ID_AMMOS_SHELL || id == HUD_SPRITE_ID_AMMOS_BULLET || id == HUD_SPRITE_ID_AMMOS_ROCKET || id == HUD_SPRITE_ID_AMMOS_CELL) {
//			return (float)(containerCoordsVec4.h * 35 / 100); //! the bigger this is the higher the text should be
//		}
//		return (float)(containerCoordsVec4.h * 35 / 100);
//	}
//	
//
//};
//
//class HudPip {
//public:
//	idVec4 pipOutlineCoordsVec4;
//	idVec4 pipFillCoordsVec4;
//	idColor outlineColor = colorBlack;
//	idColor fillColor = colorWhite;
//
//	HudPip(idVec4 rect, idColor _fillColor):pipOutlineCoordsVec4{rect}, fillColor{ _fillColor }
//	{
//		pipOutlineCoordsVec4 = rect;
//		pipFillCoordsVec4.x = pipOutlineCoordsVec4.x + 1.0f;
//		pipFillCoordsVec4.y = pipOutlineCoordsVec4.y + 1.0f;
//		pipFillCoordsVec4.w = pipOutlineCoordsVec4.w - 2.0f;
//		pipFillCoordsVec4.h = pipOutlineCoordsVec4.h - 2.0f;
//	}
//};
//
//
////! little squares on the side of the icon that show how many abilities are ready
////class HudPipsContainer {
////public:
////	hudSpriteId_t id = hudSpriteId_t::HUD_SPRITE_ID_UNKNOWN;
////	idVec4 pipsBoundsCoordsVec4; // bounds of the whole struture that encases the pips
////	int count = -1; //! how many pips shoud be displayed
////	idColor pipsColor = colorWhite; //! color for all pips
////	idColor pipsDeactivatedColor = colorDkGrey; //! color for non active pips
////	std::vector<HudPip>PipsVec;
////	const float pipVertSpacingPrct = .20f; //! percentage of the main icon (like nade) height to space each pip icon
////	//const float pipVertSpacingPrct = .3f; //! percentage of a pip size for spacing
////	//const float pipHorSpacingPrct = .1f; //! percentage of the main icon (like nade) on how far the pips will be from icon on x axis
////	const int maxPipCount = 3; //! that should be the max for any ability in the game.
////	
////
////	HudPipsContainer(idVec4 _coordinatesVec4, hudSpriteId_t hudId): pipsBoundsCoordsVec4{ _coordinatesVec4 }, id{hudId}
////	{
////		pipsColor = HudColor::getIdcolor(hudId);
////		//pipsColor = HgetPipsColor(hudId);
////	}
////
////	void updateCount(unsigned int totalPipsCount, unsigned int activePipsCount) {
////		if (totalPipsCount != count) {
////			count = totalPipsCount;
////			PipsVec.clear();
////
////			//! this made the icon a bit too big
////			/*float pipVertSpacing = pipsBoundsCoordsVec4.h * pipVertSpacingPrct;
////			float pipHeight = (pipsBoundsCoordsVec4.h - 2 * pipVertSpacing) / maxPipCount;*/
////
////			float pipVertSpacing = pipsBoundsCoordsVec4.w * pipVertSpacingPrct; //! using widht as a base
////			float pipSize = pipsBoundsCoordsVec4.w; //! pips are square shapes
////
////			//logInfo("updateCount: pipSize: %.2f, pipVertSpacing: %.2f", pipSize, pipVertSpacing);
////
////			idVec2 OffsetsVec2 = HudUtils::getPipsPosOffsetsPrct(id);
////			float x = pipsBoundsCoordsVec4.x + OffsetsVec2.x * pipsBoundsCoordsVec4.w;
////			//float y = pipsBoundsCoordsVec4.y + pipsBoundsCoordsVec4.h ; //! we start bottom left
////			float y = pipsBoundsCoordsVec4.y + OffsetsVec2.y * pipsBoundsCoordsVec4.h; //! we start top left + offset
////
////			for (size_t i = 0; i < totalPipsCount; i++)
////			{
////				idVec4 rect = idVec4(x, y , pipSize, pipSize);
////				//idVec4 rect = idVec4(x, y - pipSize, pipSize, pipSize);
////				//idVec4 rect = idVec4(x, y - pipHeight, pipsBoundsCoordsVec4.w, pipHeight);
////				if (activePipsCount == 0) {
////					PipsVec.push_back(HudPip(rect, pipsDeactivatedColor));
////				}
////				else if (i >= (activePipsCount )) {
////					PipsVec.push_back(HudPip(rect, pipsDeactivatedColor));
////
////				}
////				else {
////					PipsVec.push_back(HudPip(rect, pipsColor));
////									}
////				y += (pipSize + pipVertSpacing);
////				//y -= (pipSize + pipVertSpacing);
////			}
////		}
////	}
////};
//
//
///// <summary>
///// an icon + text + potential pips like the frag and the potential text for it's cooldown and pips for count
///// </summary>
//class HudEquipmentSprite {
//
//public:
//	hudSpriteId_t id = hudSpriteId_t::HUD_SPRITE_ID_UNKNOWN;
//	idVec4 iconContainerCoordsVec4; //! square shape
//	idVec4 pipIconsContainerCoordsVec4; 
//	HudIcon hudIcon = HudIcon(iconContainerCoordsVec4, id);
//	//! not using text for count anymore, it doesn't work graphically
//	//HudText hudCountText = HudText(iconContainerCoordsVec4, hudTextType_t::HUD_TEXT_TYPE_COUNT);
//	HudText hudCoolDownText = HudText(iconContainerCoordsVec4, id);
//	//HudPipsContainer PipsContainer = HudPipsContainer(pipIconsContainerCoordsVec4, id);
//	std::string text = "?";
//	bool isOnCoolDown = false;
//	idColor pipsColor = colorWhite;	
//	//bool isPipsVisible = false; //! can be false because it never has pips or because pips should not be shown atm.
//	//unsigned int pipsCount = 0;
//	const float pipSizePcrt = 0.22f; //! pip struct width compared to icon
//	//const float pipSizePcrt = 0.15f; //! pip struct width compared to icon: a bit too small compared to game race hud
//
//
//	HudEquipmentSprite(idVec4 _coordinatesVec4, hudSpriteId_t hud_id) : iconContainerCoordsVec4{ _coordinatesVec4 }, id { hud_id }
//	{
//		updateCoords(_coordinatesVec4);
//	}
//	/*void updateCoords(idVec4 _coordinatesVec4) {
//		updateCoords(_coordinatesVec4);
//
//	}*/
//
//	void updateData(unsigned int totalPipsCount, unsigned int activePipsCount, int coolDownInt) {
//
//		PipsContainer.updateCount(totalPipsCount, activePipsCount);
//		hudCoolDownText.update(coolDownInt);
//		hudIcon.updateColor(coolDownInt);
//	}
//	
//	
//	void updateCoords(idVec4 _coordinatesVec4) {
//		iconContainerCoordsVec4 = _coordinatesVec4; //! not sure if we need this but keep it for now.
//		computePipContainerCoords(_coordinatesVec4);
//		hudIcon.updateCoords(_coordinatesVec4); //! we don't need to updateColor the icon coord atm cause it fills all the space of it parent
//		hudCoolDownText.updateCoords(_coordinatesVec4);
//	}
//
//	void computePipContainerCoords(idVec4 _coordinatesVec4) {
//		pipIconsContainerCoordsVec4.x = _coordinatesVec4.x + _coordinatesVec4.w;
//		pipIconsContainerCoordsVec4.y = _coordinatesVec4.y;
//		pipIconsContainerCoordsVec4.w = _coordinatesVec4.w * pipSizePcrt;
//		pipIconsContainerCoordsVec4.h = _coordinatesVec4.h ;
//		//logInfo("computePipContainerCoords pipIconsContainerCoordsVec4.w is: %.2f pipIconsContainerCoordsVec4.h is: %.2f", pipIconsContainerCoordsVec4.w, pipIconsContainerCoordsVec4.h);
//
//	}
//
//	idColor getIconColor(int coolDownInt) {
//		if (id == hudSpriteId_t::HUD_SPRITE_ID_ICE) {
//			if (coolDownInt > 0) {
//				return colorIceNadeDeactivatedIcon; 
//				//colorCurrent = colorIconDeactivated;
//			}
//			else {
//				return colorActivated;
//			}
//		}
//	}
//
//	bool isCoolDownText() const {
//		return hudCoolDownText.textIntVal > 0;
//	}
//
//	//void updatePipsCount(unsigned int count) {
//	//	/*if (count > 0) {
//	//		isPipsVisible = true;
//	//	}
//	//	else {
//	//		isPipsVisible = false;
//	//	}*/
//	//	//pipsCount = count;
//	//	PipsContainer.updateCount(count);
//	//}
//
//	/*void updateCoolDownText(int timeleftSecs) {
//		hudCoolDownText.updateText(timeleftSecs);
//	}*/
//
//
//	//void updateCountFloat(float count) {
//	//	//hudCountText.updateText(count);
//	//}
//	//void updateCountInt(int count) {
//	//	//hudCountText.updateText(count);
//	//}
//};
//
////! Keep in mind doesn't have a HudIcon so its colors update process might be a bit confusing
//class HudEquipmentIce {
//public:
//	hudSpriteId_t id = hudSpriteId_t::HUD_SPRITE_ID_ICE; //! we need that for hudtext size, check HudText for more info
//	idVec4 borderCoordsVec4; //! the oriented rectangle shape
//	idVec4 iconCoordsVec4; //! the actual ice icon 
//	idVec4 fillCoordsVec4; //! the background of the icon
//	HudText hudCoolDownText = HudText(iconCoordsVec4, id);
//	uint64_t cooldownInSec = 0;
//	idColor iconColor = colorWhite;
//	idColor backgroundColor = colorRed;	
//
//	HudEquipmentIce()
//	{
//
//	}
//
//	HudEquipmentIce(idVec4 coords, idColor _iconColor, idColor bgColor): iconColor{ _iconColor }, backgroundColor{ bgColor }
//	{
//		//idVec4 fragBorderCoordsVec4 = GameHudColorsManager::getFragBorderCoords();
//		updateCoords(coords);
//		updateColors();
//		//updatePosAndColors(GameHudColorsManager::getFragBorderCoords());
//	}
//
//	bool isOnCoolDown() const {
//		return cooldownInSec != 0;
//	}
//
//	/*void updateData(unsigned int cooldownSec) {
//		cooldownInSec = cooldownSec;
//		updateColors();
//		hudCoolDownText.updateColor(cooldownSec);
//	}*/
//
//	
//	//void updateDataV2(uint64_t coolDownEndMicros) {
//	//	if (idPlayer::getIceNadeCoolDownEndMicros() > Game::getGameTime()) {
//	//		//! we add 1 because cause we divide integers the 0.99999 to 0 becomes 0 so we are off by 1 second otherwise.
//	//		cooldownInSec = (uint64_t)(idPlayer::getIceNadeCoolDownEndMicros() - Game::getGameTime()) / 1000000 + 1;
//	//	}
//	//	else {
//	//		cooldownInSec = 0;
//	//	}
//	//	updateColors();
//	//	hudCoolDownText.update(cooldownInSec);
//	//}
//
//	/*void updateText(unsigned int cooldownSec) {
//		hudCoolDownText.updateColor(cooldownSec);
//	}*/
//
//	//! only the icon has its color changed, text color is fixed so it doesn't get updated.
//	void updateColors() {
//		if (cooldownInSec) {
//			iconColor = colorIceNadeDeactivatedIcon;
//			backgroundColor = colorIceNadeDeactivatedBg;
//		}
//		else {
//			iconColor = GameHudColorsManager::getCurrentProfileIceNadeIconColor();
//			backgroundColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();
//		}
//	}
//
//	//! one very hacky way to detect that we should update the coords to make sure custom ice nade is displayed
//	/*bool isPotentialCoordsError() {
//		return fillCoordsVec4.x == 0.0f;
//	}*/
//
//	void updateCoords(idVec4 fragBorderCoords) {
//		computeCustomIceSpriteBorderCoords(fragBorderCoords);
//		fillCoordsVec4 = borderCoordsVec4;
//		//fillCoordsVec4.printMsg("fillCoordsVec4: ");
//		computeIconCoords(borderCoordsVec4);
//		hudCoolDownText.updateCoords(borderCoordsVec4);
//		
//		//iconCoordsVec4 = borderCoordsVec4;
//
//		/*iconCoordsVec4.x = fragBorderCoords.x + fragBorderCoords.w / 4;
//		iconCoordsVec4.y = fragBorderCoords.y + fragBorderCoords.h / 4;
//		iconCoordsVec4.w = fragBorderCoords.w / 2;
//		iconCoordsVec4.h = fragBorderCoords.h / 2;*/
//
//		/*iconColor = _iconColor;
//		backgroundColor = bgColor;*/
//		//? even here may be we want to take data into account when setting colors
//		//iconColor = GameHudColorsManager::getCurrentProfileIceNadeIconColor();
//		//backgroundColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();
//	}
//
//	void computeCustomIceSpriteBorderCoords(idVec4 fragBorderCoords) {
//		const float offsetPrct = 0.7f; //! value found through trial and error
//		borderCoordsVec4 = fragBorderCoords;
//		borderCoordsVec4.x = fragBorderCoords.x + (fragBorderCoords.w * offsetPrct);
//		
//		/*const float offsetPrctDebug = 0.7f;
//		idVec4 fragSpriteBounds = getFragSpriteIdBounds(fragCoolDownFillGlowSpriteId);
//		idVec4 iceSpriteBounds = fragSpriteBounds;
//		iceSpriteBounds.x = fragSpriteBounds.x + (fragSpriteBounds.w * offsetPrctDebug);
//
//		logInfo("computeCustomIceSpriteBounds logging fragSpriteBounds and iceSpriteBounds...");
//		fragSpriteBounds.print();
//		iceSpriteBounds.print();
//
//		return iceSpriteBounds;*/
//	}
//
//	void computeIconCoords(idVec4 borderCoordsVec4) { //! chatgpt version
//		float iconWidth = borderCoordsVec4.w / 2.3f;
//		float iconHeight = borderCoordsVec4.h / 2.3f;
//
//		iconCoordsVec4.x = borderCoordsVec4.x + (borderCoordsVec4.w - iconWidth) / 2.0f;
//		iconCoordsVec4.y = borderCoordsVec4.y + (borderCoordsVec4.h - iconHeight) / 2.0f;
//		iconCoordsVec4.w = iconWidth;
//		iconCoordsVec4.h = iconHeight;
//	}
//};
//
//
///// <summary>
///// an ammo icon and its value as text aligned horizontally
///// </summary>
//class HudAmmo {
//public:
//	hudSpriteId_t id = hudSpriteId_t::HUD_SPRITE_ID_AMMOS_UNKNOWN;	
//	idVec4 textCoordsVec4;
//	idVec4 iconCoordsVec4;
//	int ammoCount = 666;
//	int prevAmmoCount = 777;
//	HudText hudAmmoText = HudText(textCoordsVec4, id, "999");
//	HudIcon ammoIcon = HudIcon(iconCoordsVec4, id);
//	
//	//idColor color = colorWhite;
//
//	HudAmmo()
//	{
//	}
//
//	HudAmmo(hudSpriteId_t _id, int _ammoCount) : id{ _id }, ammoCount{ _ammoCount } {
//
//	}
//
//	HudAmmo(hudSpriteId_t _id, idVec4 _textCoordsVec4, idVec4 _iconCoordsVec4 ) : id{ _id }, textCoordsVec4{ _textCoordsVec4 }, iconCoordsVec4{ _iconCoordsVec4 }
//	{
//		//todo here we could compute the ammo warning values
//		updateCoords(_textCoordsVec4, _iconCoordsVec4);
//		updateId(_id);
//	}
//
//	//! way to update the coords if an ammo goes for example from 100 to 99 so we offset it on the x axis.
//	bool isAmmoTextValLengthChanged() {
//		bool result = false;
//		//logInfo("isAmmoTextValLengthChanged: prevAmmoCount: %d ammoCount: %d", prevAmmoCount, ammoCount);
//		if (prevAmmoCount != ammoCount) {
//			if ((ammoCount < 10 && prevAmmoCount >= 10) || (prevAmmoCount < 10 && ammoCount >= 10)) {
//				result = true;
//			}
//			else if ((ammoCount < 100 && prevAmmoCount >= 100) || (prevAmmoCount < 100 && ammoCount >= 100)) {
//				result = true; 
//			}
//			prevAmmoCount = ammoCount;
//		}		
//		return result;
//	}
//
//
//	void updateColor() {
//		idColor color = GameHudColorsManager::getCurrentAmmoColor(id);
//		hudAmmoText.updateColor(computeAmmoTextColor(id, color));
//		ammoIcon.updateColor(color); 
//	}
//
//	/*void updateData(hudSpriteId_t _id, int _ammoCount) {
//		updateId(_id);
//		ammoCount = _ammoCount;
//		hudAmmoText.update(_ammoCount);
//		
//	}*/
//
//	void updateId(hudSpriteId_t _id) {
//		id = _id;
//		ammoIcon.id = _id;
//		hudAmmoText.id = _id;
//	}
//
//	/*void updateCoords(idVec4 _textCoordsVec4, idVec4 _iconCoordsVec4 ) {
//		hudAmmoText.updateCoords(_textCoordsVec4);
//		ammoIcon.updateCoords(_iconCoordsVec4);
//	}*/
//
//	void print() {
//		logInfo("id: %d fontScale: %.2f text: %s ",  (int)id, hudAmmoText.fontScale, hudAmmoText.text.c_str());
//		textCoordsVec4.printMsg("textCoordsVec4: ");
//		iconCoordsVec4.printMsg("iconCoordsVec4: ");
//	}
//
//	
//	idColor computeAmmoTextColor(hudSpriteId_t _id, idColor _color) {
//		switch (_id)
//		{			
//		case HUD_SPRITE_ID_AMMOS_SHELL:
//			if (ammoCount <= 6) { //! found values with trial and errors
//				return colorRed;
//			}
//			break;
//		case HUD_SPRITE_ID_AMMOS_BULLET:
//			if (ammoCount <= 16) {
//				return colorRed;
//			}
//			break;
//		case HUD_SPRITE_ID_AMMOS_ROCKET:
//			if (ammoCount <= 3) {
//				return colorRed;
//			}
//			break;
//		case HUD_SPRITE_ID_AMMOS_CELL:
//			if (ammoCount <= 30) {
//				return colorRed;
//			}
//			break;				
//		}
//		return _color;
//		//return GameHudColorsManager::getCurrentAmmoColor(id);
//	}
//
//};
//
///// <summary>
///// the 4 ammos count (shell, bullets, rocket, cells) each ammo is an ammo icon + the value as text
///// </summary>
//class HudAmmos {
//
//public:
//	//idVec4 iconCoordsVec4;
//	const unsigned int hudAmmosModuleCount = 4; //! 4 because 3 is just a pain for many reasons.
//	std::vector<HudAmmo> hudAmmosVec;
//	//std::vector< HudAmmoDataV2> hudAmmoDataVec;
//
//	HudAmmos()
//	{
//		//hudAmmoDataVec = { HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, 6), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, 26), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, 666) };
//		
//		initialize();
//	}
//
//	HudAmmos(idVec4 weaponInfoBgSpriteVec4)
//	{
//		initialize();
//		computeAndUpdateCoordsV3(weaponInfoBgSpriteVec4, idInventoryCollectionManager::getHudAmmoDataVec_V2());
//	}
//
//	//! making sure there are 3 HudAmmo obj in the vec
//	void initialize() {
//		hudAmmosVec.clear();
//		hudAmmosVec.push_back(HudAmmo(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, 0));
//		hudAmmosVec.push_back(HudAmmo(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, 0));
//		hudAmmosVec.push_back(HudAmmo(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, 0));
//		hudAmmosVec.push_back(HudAmmo(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, 0));
//
//		/*for (size_t i = 0; i < hudAmmosModuleCount; i++)
//		{
//			hudAmmosVec.push_back(HudAmmo());
//		}*/
//	}
//
//    //! is any of the ammo text length changed
//	bool isAmmoTextengthChanged() {
//		for (size_t i = 0; i < hudAmmosVec.size(); i++)
//		{
//			if (hudAmmosVec[i].isAmmoTextValLengthChanged()) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void updateColors() {
//		for (size_t i = 0; i < hudAmmosVec.size(); i++)
//		{
//			hudAmmosVec[i].updateColor();
//		}
//		/*if (cooldownInSec) {
//			iconColor = colorIceNadeDeactivatedIcon;
//			backgroundColor = colorIceNadeDeactivatedBg;
//		}
//		else {
//			iconColor = GameHudColorsManager::getCurrentProfileIceNadeIconColor();
//			backgroundColor = GameHudColorsManager::getCurrentProfileIceNadeBackgroundColor();
//		}*/
//	}
//
//	
//	void updateData(std::vector< HudAmmoDataV2> hudAmmoDataVec) {
//		if (hudAmmosVec.size() < hudAmmoDataVec.size()) {
//			logErr("HudAmmos::updateData: can not updateColor data cause hudAmmosVec.size() < hudAmmoDataVec.size()");
//			return;
//		}
//		for (size_t i = 0; i < hudAmmoDataVec.size(); i++)
//		{
//			hudAmmosVec[i].updateData(hudAmmoDataVec[i].id, hudAmmoDataVec[i].ammoCount);
//			hudAmmosVec[i].updateColor();
//			//logInfo("here......");
//
//		/*	hudAmmosVec[i].hudAmmoText.update(hudAmmoDataVec[i].ammoCount);
//			hudAmmosVec[i].hudAmmoText.updateId(hudAmmoDataVec[i].id);
//			hudAmmosVec[i].ammoIcon.updateId(hudAmmoDataVec[i].id);*/
//		}
//	}
//
//	void computeAndUpdateCoordsV3(idVec4 weaponInfoBgSpriteVec4, std::vector< HudAmmoDataV2> hudAmmoDataVec) {
//		//! we could use a prct of the weapon sprite width to determine the width of ammos sprite
//		float ammosWidth = weaponInfoBgSpriteVec4.w * 0.8f;
//		float separatorWidth = 0.0f;
//		//float separatorWidth = ammosWidth * 0.02f;
//		float ammoUnitWidth = (ammosWidth - (2.f * separatorWidth)) / 3.0f;
//		float ammoUnitHeight = 0.5f * weaponInfoBgSpriteVec4.h;
//		float ammosX = weaponInfoBgSpriteVec4.x + weaponInfoBgSpriteVec4.w * 0.08f;
//		float ammosY = weaponInfoBgSpriteVec4.y + weaponInfoBgSpriteVec4.h * .9f;
//		//float ammosY = weaponInfoBgSpriteVec4.y + weaponInfoBgSpriteVec4.h * .85f; // a bit too close to bar above
//
//		idVec4 textCoords = getTextCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//		idVec4 iconCoords = getIconCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//
//		//? may be we there should be empty data in the hudAmmoDataVec is player is at the start of the game when he only has one weapon
//
//		if (hudAmmoDataVec.size() != hudAmmosVec.size()) {
//			logErr("HudAmmos:computeAndUpdateCoordsV3: Error: hudAmmoDataVec.size() != hudAmmosVec.size() can not updateColor data or coords");
//			return;
//		}			
//		for (size_t i = 0; i < hudAmmoDataVec.size(); i++)
//		{
//			//if (i != 0) { //! the first ammo doesn't need an offset
//			//	ammosX += getAmmoUnitVisibleWidth_For(hudAmmoDataVec[i].ammoCount, ammosWidth, separatorWidth);
//			//}
//			//ammosX += getAmmoUnitVisibleWidth_For(hudAmmoDataVec[i].ammoCount, ammosWidth, separatorWidth);
//			ammosX += getAmmoUnitVisibleWidth_For(i, hudAmmoDataVec[i].ammoCount, ammosWidth, separatorWidth);
//			textCoords = getTextCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//			iconCoords = getIconCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//			hudAmmosVec[i].updateData(hudAmmoDataVec[i].id, hudAmmoDataVec[i].ammoCount);
//			hudAmmosVec[i].updateCoords(textCoords, iconCoords);
//			
//			
//		}
//	}
//
//	//! visible because it would be bigger but would appear smaller because it only has 1 number for example
//	float getAmmoUnitVisibleWidth_For(size_t index, int ammoCount, float ammosWidth, float separatorWidth) {
//		float defaultWidth =( ammosWidth - (2.f * separatorWidth)) / 3.0f;
//		//return defaultWidth; 
//
//		if (index == 0) {
//			return 0;
//		}
//		else if (ammoCount < 10) {
//			return .8f * defaultWidth;
//		}
//		else if (ammoCount < 100) {
//			return .9f * defaultWidth;
//		}
//		else {
//			return defaultWidth;
//		}
//	}
//
//	//void computeAndUpdateCoordsV2(idVec4 weaponInfoBgSpriteVec4) {
//	//	//! we could use a prct of the weapon sprite width to determine the width of ammos sprite
//	//	float ammosWidth = weaponInfoBgSpriteVec4.w * 0.8f;
//	//	float separatorWidth = 0.0f;
//	//	//float separatorWidth = ammosWidth * 0.02f;
//	//	float ammoUnitWidth = (ammosWidth - (2.f * separatorWidth)) / 3.0f;
//	//	float ammoUnitHeight = 0.5 * weaponInfoBgSpriteVec4.h;
//	//	float ammosX = weaponInfoBgSpriteVec4.x + weaponInfoBgSpriteVec4.w * 0.08f;
//	//	float ammosY = weaponInfoBgSpriteVec4.y + weaponInfoBgSpriteVec4.h * .9f;
//	//	//float ammosY = weaponInfoBgSpriteVec4.y + weaponInfoBgSpriteVec4.h * .85f; // a bit too close to bar above
//
//	//	idVec4 textCoords = getTextCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//	//	idVec4 iconCoords = getIconCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//
//	//	hudAmmosVec.clear();
//
//	//	for (size_t i = 0; i < hudAmmosModuleCount; i++)
//	//	//for (size_t i = 0; i < hudAmmoDataVec.size(); i++)
//	//	{
//	//		hudAmmosVec.push_back(HudAmmo(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_UNKNOWN, textCoords, iconCoords));
//	//		ammosX += ammoUnitWidth + separatorWidth;
//	//		textCoords = getTextCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//	//		iconCoords = getIconCoords(ammosX, ammosY, ammoUnitWidth, ammoUnitHeight);
//	//	}
//	//}
//
//	idVec4 getTextCoords(float ammosX, float ammosY, float ammoUnitWidth, float ammoUnitHeight) {
//		return idVec4(ammosX, ammosY, ammoUnitWidth * .7f, ammoUnitHeight);
//	}
//
//	idVec4 getIconCoords(float ammosX, float ammosY, float ammoUnitWidth, float ammoUnitHeight) {
//		return idVec4(ammosX + ammoUnitWidth * .63f, ammosY , ammoUnitWidth * .3f, ammoUnitHeight * .7f); // just right
//		//return idVec4(ammosX + ammoUnitWidth * .6f, ammosY , ammoUnitWidth * .3f, ammoUnitHeight * .8f);// icon a tad too big in h
//		//return idVec4(ammosX + ammoUnitWidth * .6f, ammosY + ammoUnitHeight * .15f, ammoUnitWidth * .3f, ammoUnitHeight * .8f); //icon too low
//	}
//
//
//	/*void updateCoords() {
//
//	}*/
//	/*idVec4 getTextCoords(float x, float y, float w, float h) {
//
//		return idVec4(x, y, w * .6f, h);
//	}
//
//	idVec4 getIconCoords(float x, float y, float w, float h) {
//
//		return idVec4(x , y, w * .6f, h);
//	}*/
//
//	
//};
//
//
////? i could not manage to display this hud equipment somehow, hud perf loss and streteched images, not sure what happened may be all those references or not reference that messed with my head.
////class HudEquipment {
////public:
////	idVec4 coordsVec4;
////	std::vector<hudSpriteId_t> ids; //! so we know which sprites are part of equipment hud
////	std::vector<HudEquipmentSprite> spritesVec;
////	const float spriteSeparatorSizePrct = .2f; //! spacing of sprites in the equipment hud
////
////
////	HudEquipment(idVec4 _coordsVec4, std::vector<hudSpriteId_t> _ids) : coordsVec4{ _coordsVec4 }, ids{ _ids }
////	{
////		generateSprites();
////
////	}
////
////	//! updates position/scale and types of sprites (like flame blech, hammer or crucilble, 1,2 or 0 frag...) 
////	void updateBase(std::vector<hudSpriteId_t> _ids, idVec4 _coordsVec4) {
////		ids = _ids;
////		coordsVec4 = _coordsVec4;
////		generateSprites();
////	}
////
////	void updateCoords() {
////		for (size_t i = 0; i < spritesVec.size(); i++)
////		{
////			spritesVec[i].updateCoords(coordsVec4);
////		}
////	}
////
////
////	// void updateColor(idVec4 _coordinatesVec4, unsigned int totalPipsCount, unsigned int activePipsCount, int coolDownInt) 
////	void updateData(unsigned int totalPipsCount, unsigned int activePipsCount, int coolDownInt) {
////		for (size_t i = 0; i < spritesVec.size(); i++)
////		{
////			spritesVec[i].updateData(totalPipsCount, activePipsCount, coolDownInt);
////		}
////	}
////
////	void generateSprites() {
////		spritesVec.clear();
////
////		float spritePlusSeparatorSize = getSpritePlusSeparatorSize();
////		float spriteSize = spritePlusSeparatorSize - getSeparatorSize();
////		//float spriteSize = coordsVec4.w / ids.size() - getSeparatorSize();
////		//float spriteSize = coordsVec4.w / ids.size() - (coordsVec4.w * spriteSeparatorSizePrct * (ids.size() - 1));
////		/*float x = coordsVec4.x;
////		float y = coordsVec4.y;*/
////
////		idVec4 spriteBounds = idVec4(coordsVec4.x, coordsVec4.y, spriteSize, spriteSize);
////
////		for (size_t i = 0; i < ids.size(); i++)
////		{
////			/*logInfo("generateSprites...");
////			spriteBounds.print();*/
////
////			spritesVec.push_back(HudEquipmentSprite(spriteBounds, ids[i]));
////			spriteBounds.x += spritePlusSeparatorSize;
////		}
////	}
////
////	float getSeparatorSize() {
////		int separatorCount = ids.size() - 1;
////		if (separatorCount < 0) {
////			separatorCount = 0;
////		}
////		//float spritePlusSeparatorSize = coordsVec4.w / ids.size();
////		return getSpritePlusSeparatorSize() * spriteSeparatorSizePrct;
////		//return coordsVec4.w * spriteSeparatorSizePrct * separatorCount;
////	}
////
////	float getSpritePlusSeparatorSize() {
////		return coordsVec4.w / ids.size();
////	}
////
////
////
////
////};
