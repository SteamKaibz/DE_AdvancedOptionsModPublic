#pragma once
#include <string>
//#include "idColor.h"
//#include "drawStringHookArgs.h"
//#include "Game.h"
//#include "Config.h"

#include "../DE/idColor.h"
//#include "../DE/Types.h"
#include "../DE/drawStringHookArgs.h"
//#include "Hud/HudAmmoData.h"





//class HudAmmoDataContainer {
//private:
//	//const unsigned int m_maxAmmoTypes = 4;
//	//std::vector< HudAmmoDataV2> m_ammoDataVec;
//	/*HudAmmoDataV2 m_ShellData ;
//	HudAmmoDataV2 m_BulletData ;
//	HudAmmoDataV2 m_RocketData;
//	HudAmmoDataV2 m_CellData ;*/
//
//public:
//
//	static std::vector< HudAmmoDataV2> getDefault() {
//		return std::vector<HudAmmoDataV2>{HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, 0), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, 0), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, 0), HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, 0)};
//	}
	/*HudAmmoDataContainer()
	{
		initialize();
	}*/

	
	//void initialize() {	
	//	/*HudAmmoDataV2 m_ShellData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_SHELL, -1);
	//	HudAmmoDataV2 m_BulletData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_BULLET, -1);
	//	HudAmmoDataV2 m_RocketData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_ROCKET, -1);
	//	HudAmmoDataV2 m_CellData = HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, -1);*/
	//	//m_ammoDataVec.clear(); //! just in case...
	//	//m_ammoDataVec.push_back(HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_UNKNOWN, -1));
	//	//m_ammoDataVec.push_back(HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_UNKNOWN, -1));
	//	//m_ammoDataVec.push_back(HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_UNKNOWN, -1));
	//	//m_ammoDataVec.push_back(HudAmmoDataV2(hudSpriteId_t::HUD_SPRITE_ID_AMMOS_CELL, -1));
	//}

	/*std::vector< HudAmmoDataV2> getVec() {
		std::vector< HudAmmoDataV2> ammoDataVec;
		ammoDataVec.push_back(m_ShellData);
		ammoDataVec.push_back(m_BulletData);
		ammoDataVec.push_back(m_RocketData);
		ammoDataVec.push_back(m_CellData);
	}

	HudAmmoDataV2 get(hudSpriteId_t ammoTypeId) {
		if (ammoTypeId == HUD_SPRITE_ID_AMMOS_SHELL) {
			return m_ShellData;
		}
		else if (ammoTypeId == HUD_SPRITE_ID_AMMOS_BULLET) {
			return m_BulletData;
		}
		else if (ammoTypeId == HUD_SPRITE_ID_AMMOS_ROCKET) {
			return m_RocketData;
		}
		else if (ammoTypeId == HUD_SPRITE_ID_AMMOS_CELL) {
			return m_CellData;
		}
		else {
			logErr("Else condition in HudAmmoDataContainer: get retunring bad data...");
			return m_ShellData;
		}
	}

	void set(hudSpriteId_t ammoTypeId, int ammoCount) {
		if (ammoTypeId == HUD_SPRITE_ID_AMMOS_SHELL) {
			m_ShellData.ammoCount = ammoCount;
		}
		else if (ammoTypeId == HUD_SPRITE_ID_AMMOS_BULLET) {
			m_BulletData.ammoCount = ammoCount;
		}
		else if (ammoTypeId == HUD_SPRITE_ID_AMMOS_ROCKET) {
			m_RocketData.ammoCount = ammoCount;
		}
		else if (ammoTypeId == HUD_SPRITE_ID_AMMOS_CELL) {
			m_CellData.ammoCount = ammoCount;
		}
		else {
			logErr("HudAmmoDataV2:set: could not find data...");			
		}
	}*/

	

//};



/// <summary>
/// this should contain the coordinates for each ammo string. this should be based on trial and error for the 1080p version of the game then the user will have a x/y offset adjust in the ini file. however you should test and see what happen when you resize the screen if the positioning is still correct, and may be once you have good value for 1080p, compute the % of the placement and hopefully it will work for any resolution.
/// </summary>
//class HudAmmoData {
//
//public:
//	static float m_shellsStr_x;
//	static float m_bulletsStr_x;
//	static float m_rocketsStr_x;
//	static float m_cellsStr_x;
//	static float m_ammoStr_y; //! all ammo are on the same line
//
//	static std::string m_shellAmmoStr;
//	static std::string m_bulletAmmoStr;
//	static std::string m_rocketAmmoStr;
//	static std::string m_cellAmmoStr;
//	static std::string m_errorAmmoStr;
//
//
//	static idColor shellColor;
//	static idColor bulletColor;
//	static idColor rocketColor;
//	static idColor cellColor;
//	static idColor errorColor;
//
//	static float m_spacing; // distance between each number (basically SmallCharWidth)
//
//	static float m_scale; //? this can not be 0 !!!
//
//	//static idVec2 m_strOrigin_idVec2;
//
//	//static unsigned int m_UI_Scale;
//
////! instead of centering the string we always assume that even if player has just the shotgun then it will draw at the start on the left under the equipment module. and that shell and rocket will have max 99 ammo and the other have max 999 that way we can keep the spacing consistent.
//	//? this should only be updateColor if ammo has change which we can know with the event system
//	//? need to handle situation where user doesn't have the weapon info enabled and set the x,y at arbitrary location if not 1080p
//	//? much simpler, for any resolution other than 1080 we draw the ammo bottom rigth of the screnn, end of story we calculate the font scale by may be res/1080 or may be in the middle at the bottom of the screen just to be sure?
//	static void computeCoordinates(int index) {
//		
//		//todo get data here
//		idVec2 strStartVec2 = computeStrStartVec2();
//
//		if (index == 0) {	//! conditionals here to reduce calculations (?)
//			m_shellsStr_x = strStartVec2.x;
//			//logInfo("m_shellsStr_x: %.2f ", m_shellsStr_x);
//		}
//		else if (index == 1) {
//			m_bulletsStr_x = getBulletString_XOffset();
//		}
//		else if (index == 2) {
//			m_rocketsStr_x = getRocketString_XOffset();
//		}
//		else if (index == 3) {
//			m_cellsStr_x = getCellString_XOffset();
//		}
//		m_ammoStr_y = strStartVec2.y;
////logInfo("m_ammoStr_y: %.2f ", m_ammoStr_y);
//
////logInfo("uiScaling: %u ", uiScaling);
//
//	}
//
//	static idVec2 computeStrStartVec2() {
//		auto uiScalingInt = Game::getUIScallingInt();
//
//		idVec2 strStartVec2;
//
//		float x = 0.0f;
//		float y = 0.0f;
//
//		//! if not 1080 we don't really know what coula happen so we just set the armor bottom middle to be sure
//		if (!isRes1080p()) {
//			x = Game::getCenterX() - getWholeAmmoStringWidth() / 2;
//			y = 93.7 * Game::getScreenHeigth() / 100;
//			m_scale = 1.0f;
//		}
//		else if (uiScalingInt == (unsigned int)UI_Scalling::Small) {
//			x = 83 * Game::getScreenWidth() / 100;
//			y = 93.7 * Game::getScreenHeigth() / 100;
//			//m_strOrigin_idVec2.set(x, y);
//			m_scale = 1.0f;
//		}
//		else if (uiScalingInt == (unsigned int)UI_Scalling::Medium) { // try go right and font scale to 1
//			x = 83 * Game::getScreenWidth() / 100;
//			y = 93.7 * Game::getScreenHeigth() / 100;
//			strStartVec2.set(x, y);
//			m_scale = 1.0f;
//		}
//		else if (uiScalingInt == (unsigned int)UI_Scalling::Large) {
//			x = 79.5 * Game::getScreenWidth() / 100;
//			y = 93.5 * Game::getScreenHeigth() / 100;
//			//m_strOrigin_idVec2.set(x, y);
//			m_scale = 1.25f;
//		}
//		else {
//			x = 78 * Game::getScreenWidth() / 100;
//			y = 93.5 * Game::getScreenHeigth() / 100;
//			//m_strOrigin_idVec2.set(x, y);
//			m_scale = 1.25f;
//		}
//		strStartVec2.set(x, y);
//		return strStartVec2;
//	}
//
//
//	static float getBulletString_XOffset() {
//		return  m_shellsStr_x + Game::GetStringWidthInPixels(m_shellAmmoStr.c_str(), m_scale) + m_spacing;
//	}
//
//	static float getRocketString_XOffset() {
//		return  m_bulletsStr_x + Game::GetStringWidthInPixels(m_bulletAmmoStr.c_str(), m_scale) + m_spacing;
//	}
//
//	static float getCellString_XOffset() {
//		return  m_rocketsStr_x + Game::GetStringWidthInPixels(m_rocketAmmoStr.c_str(), m_scale) + m_spacing;
//	}
//
//	static unsigned int getWholeAmmoStringWidth() {
//		return Game::GetStringWidthInPixels(m_shellAmmoStr.c_str(), m_scale) + Game::GetStringWidthInPixels(m_bulletAmmoStr.c_str(), m_scale) + Game::GetStringWidthInPixels(m_rocketAmmoStr.c_str(), m_scale) + Game::GetStringWidthInPixels(m_cellAmmoStr.c_str(), m_scale) + (unsigned int)( 3 * m_spacing);
//	}
//
//	//static void updateData() {
//
//	//}
//
//	static DrawStringHookArgs getStrData(int index) {
//		computeCoordinates(index);
//		if (index == 0) {
//			return DrawStringHookArgs(m_shellAmmoStr, m_shellsStr_x, m_ammoStr_y, shellColor, m_scale);
//		}
//		else if (index == 1) {
//			return DrawStringHookArgs(m_bulletAmmoStr, m_bulletsStr_x, m_ammoStr_y, bulletColor, m_scale);
//		}
//		else if (index == 2) {
//			return DrawStringHookArgs(m_rocketAmmoStr, m_rocketsStr_x, m_ammoStr_y, rocketColor, m_scale);
//		}
//		else if (index == 3) {
//			return DrawStringHookArgs(m_cellAmmoStr, m_cellsStr_x, m_ammoStr_y, cellColor, m_scale);
//		}
//		//logWarn("getStrData out of index returns...Index is: %d", index);
//		return DrawStringHookArgs(m_errorAmmoStr, m_shellsStr_x - 50, m_ammoStr_y, errorColor, m_scale); //? this should never trigger hopefully.
//	}
//
//
//	static bool isRes1080p() {
//		float epsilon = 1.0;
//		if ((std::abs(Game::getScreenWidth() - 1920.0f) < epsilon) && (std::abs(Game::getScreenHeigth() - 1080.0f) < epsilon)){
//			return true;
//		}
//		return false;
//		
//	}
//};

//float HudAmmoData::m_shellsStr_x = 0;
//float HudAmmoData::m_bulletsStr_x = 0;
//float HudAmmoData::m_rocketsStr_x = 0;
//float HudAmmoData::m_cellsStr_x = 0;
//float HudAmmoData::m_ammoStr_y = 0;
//
//std::string HudAmmoData::m_shellAmmoStr = "6";
//std::string HudAmmoData::m_bulletAmmoStr = "242";
//std::string HudAmmoData::m_rocketAmmoStr = "2";
//std::string HudAmmoData::m_cellAmmoStr = "225";
//std::string HudAmmoData::m_errorAmmoStr = "XX";
//
//idColor HudAmmoData::shellColor = colorYellow;
//idColor HudAmmoData::bulletColor = colorGreen;
//idColor HudAmmoData::rocketColor = colorRed;
//idColor HudAmmoData::cellColor = colorPurple;
//idColor HudAmmoData::errorColor = colorLtGrey;
//
//float HudAmmoData::m_spacing = Game::getSmallCharWidth();
//float HudAmmoData::m_scale = 1.25; //! this is the value found in GetPerfMetricsStr_Smth_48FE40
//idVec2 HudAmmoData::m_strOrigin_idVec2;
