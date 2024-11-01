#pragma once

#include <string>
#include "../Config.h"
#include "idColor.h"
#include "idLib_Static.h"
#include "MemHelper.h"
#include "idDeclUIColorManager.h"

//#include <vector>
//#include <string>
//#include <cmath>
//#include "../Config/Config.h"
//#include "CommonDE.h"
//#include "Types.h"
//#include "../IniFile/IniFileData.h"
//#include "idCmd.h"

//#include "UserColorSet.h"
//#include "idInventoryManager.h"
//#include "idPlayer.h"
//#include "idSWFSpriteInstanceManager.h"
//#include "ColorManager.h"
//#include "UserColorSet.h"
//#include "idSWFSpriteInstanceManager.h"
//#include "../ImGui/menu/menu.hpp"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



//#include "../IniFile/IniConfig.h"

//! used to figure out the hash of all the hud's elements so we can identify/change them easily
struct spriteDebug {
	int fullPathHash = 0;
	int visIndex = 0;
	std::string name = "unknown";

	void print() {
		logInfo("print: name: %s, fullPathHash: %d, visIndex: %d, ", name.c_str(), fullPathHash, visIndex);
	}
};

//! basically a hasid/sprite instance map
//struct SpriteIdData {
//	int fullPathHash = 0;
//	__int64 address = 0;
//};

/// <summary>
/// used mainly to change the colors of the game's hud elements (not our custom hud's colors btw)
/// </summary>

//! Update2 we could not use this method as we got too many crashes so using a simpler method, we just do everything through the hooks and do not modify the color diretly in the spriteInstance
//! Update 3: this is still usefull but just as a way to make some hud elements disappears like the health pips or bloodpunch color, but we now have a way to make the hud totally customizable so not sure if we'll need this.
class GameHudColorsManager {
private:
	//! data acquired from convertIdDeclUIColorToidColorHook
	inline static __int64 m_currentIdDeclUIColor = 0;
	inline static idColor m_defaultFragNadeIconColor = colorGreen;
	inline static idColor m_defaultFragNadeBackgroundColor = colorGreen;
	inline static idColor m_defaultIceNadeIconColor = colorBlue;
	inline static idColor m_defaultIceNadeBackgroundColor = colorBlue;
	inline static idColor m_fragNadePulseColor = colorGreen;
	inline static idColor m_iceNadePulseColor = colorBlue;
	inline static bool m_isEquipmentFlag = false;

	inline static idSWFSpriteInstance* m_currentEquipmentArrowSpriteInstanceAddr = 0;
	inline static idSWFSpriteInstance* m_EquipmentBackerSpriteInstanceAddr = 0;
	inline static idSWFSpriteInstance* m_healthIconOuterSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_healthIconBgSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthTextSpriteIdAddr = 0;
	inline static idSWFSpriteInstance*  m_healthPipsOutlineSpriteIdAddr = 0;
	inline static idSWFSpriteInstance*  m_healthPipsGradientBottomSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthPipsGradientTopSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthBgLeftLeftSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthRightSideMiddleMiddleSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthRightSideRightRightSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthGlowSpriteIdSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthPulseLoopSpriteAddr = 0;
	inline static idSWFSpriteInstance*  m_healthBottomAdornmentSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_healthRightSideAddAmountSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_healthrightSideRightborderSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorBarGradientSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorBarBaseSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorRightSideSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorTextSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorIconSpritAddr = 0;
	inline static idSWFSpriteInstance* m_armorIconGlowSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorInfoSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_armorBgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_weaponInfoCoolDownSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_weaponInfoBgModlessSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_weaponInfoTextSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_weaponInfoBgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchBgPulseSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchChargeGlowBgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchBgImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchBorderImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchIconOnSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchIconOffSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchReadyFlashSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchFillRightGlowSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchFillRightImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchFillLeftGlowSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchFillLeftImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchTextSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchBindKbmSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchBindJoySpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchChargeBgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_bloodPunchImgImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitBarGradientSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitBarBaseSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitRightSideSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitTextSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitIconImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitGlowImgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitBgSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_radSuitBgPulseSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_fragCoolDownFillGlowSpriteAddr = 0;
	inline static idSWFSpriteInstance* m_debug_EquipmentSpriteInstanceAddr = 0;
	inline static idSWFSpriteInstance* m_weaponInfoBigBarSpriteAddr = 0;

	//! cached the ptrs so we that we only logged each sprite instance once, this is used mainly to get the path hash of a specific sprite instance we're looking for.
	inline static std::unordered_set<idSWFSpriteInstance*> debug_LoggedSprinteInstances;

	inline static int m_debugLastHash = 0;
	inline static std::vector<__int64> m_debugSpriteInstanceAddressesVec;
	inline static size_t m_debugIndex = 0;
	inline static std::vector<unsigned int> m_debugColorIdVec = { SWF_NAMED_COLOR_HUD_BASE, SWF_NAMED_COLOR_HUD_TEXT, SWF_NAMED_COLOR_HUD_HEADER, SWF_NAMED_COLOR_DASH_BASE, SWF_NAMED_COLOR_DASH_GLOW };
	inline  static std::vector<int32_t> bloodPunchSpriteIdsVec = { bloodPunchBgPulseSpriteId , bloodPunchChargeGlowBgSpriteId, bloodPunchBgImgSpriteId, bloodPunchBorderImgSpriteId, bloodPunchIconOnSpriteId, bloodPunchIconOffSpriteId, bloodPunchFillRightGlowSpriteId, bloodPunchFillRightImgSpriteId ,bloodPunchFillLeftGlowSpriteId , bloodPunchFillLeftImgSpriteId , bloodPunchTextSpriteId, bloodPunchBindKbmSpriteId, bloodPunchBindJoySpriteId, bloodPunchChargeBgSpriteId , bloodPunchImgImgSpriteId };
	inline  static std::vector<int32_t> radSuitSpriteIdsVec = { radSuitBarGradientSpriteId, radSuitBarBaseSpriteId ,radSuitRightSideSpriteId ,radSuitTextSpriteId ,radSuitIconImgSpriteId , radSuitGlowImgSpriteId ,radSuitBgSpriteId , radSuitBgPulseSpriteId };
	inline  static std::vector<int32_t> fragNadeSpriteIdsVec = { fragCoolDownFillGlowSpriteId, fragCoolDownInnerFillSpriteId, fragCoolDownFillFillSpriteId, fragIconSpriteId };
	inline  static std::vector<unsigned int> m_HudEquipmentFragHashIdsVec{ 0xE187B796, 0x69411733, 0x163F64A6, 0x5D8A8852, 0x766C6A57, 0x17F43D45 };
	inline  static std::vector<unsigned int> m_HudEquipmentFragIconHashIdsVec{ 0x9BA03A81, 0xFFB27971 };
	
	
	/*
	_root/lowAmmo//glow, hash: 48DCE082 (dec: 1222434946)
	_root/lowAmmo//decor, hash: D2918D10 (dec: -762213104)
	_root/lowAmmo//decor_outline, hash: F19B2C13 (dec: -241488877)
	_root/lowAmmo//decor, hash: D2918D10 (dec: -762213104)
	_root/lowAmmo//decor_outline, hash: F19B2C13 (dec: -241488877)
	_root/lowAmmo/info/message, hash: C76E7720 (dec: -949061856)
	*/	
	inline  static std::vector<unsigned int> m_HudLowAmmoWarningShapeHashIdsVec{0x48DCE082, 0xD2918D10, 0xF19B2C13 }; 

	/*
	_root/lowHealth///hex_base, hash: F6439B40 (dec: -163341504)
	_root/lowHealth///hex_overlay, hash: D838A581 (dec: -667376255)
	_root/lowHealth/warningGlow/glow, hash: 92ACC4FD (dec: -1834171139)
	_root/lowHealth/decorLeft/decor, hash: 129982B8 (dec: 312050360)
	_root/lowHealth/decorLeft/decor_outline, hash: 5C6F9BB (dec: 96926139)
	_root/lowHealth/decorRight/decor, hash: 5F904459 (dec: 1603290201)
	_root/lowHealth/decorRight/decor_outline, hash: D3768A5C (dec: -747206052)
	_root/lowHealth/fontGlow/frameSlayer, hash: 12A63624 (dec: 312882724)
	_root/lowHealth/fontGlow/frameDemonLeft, hash: 1F439E4C (dec: 524525132)
	_root/lowHealth/fontGlow/frameDemonRight, hash: C9868C77 (dec: -913929097)
	_root/lowHealth/txt/base, hash: 41867A5A (dec: 1099332186)
	_root/lowHealth/txt/pulse, hash: F0171930 (dec: -266921680)
	_root/lowHealth/icon, hash: EEA450C4 (dec: -291221308)	
	*/

	//! low ammor warning and low health warning
	inline static std::vector<unsigned int> m_HudLowWarningElementsHashIdsVec{ 0x48DCE082, 0xD2918D10 ,0xF19B2C13, 0xC76E7720,  0xF6439B40,  0xD838A581, 0x92ACC4FD , 0x129982B8, 0x5C6F9BB, 0x5F904459, 0xD3768A5C, 0x12A63624, 0x41867A5A, 0xF0171930, 0xEEA450C4 };


	inline  static int m_debugNamedColorIndex = -1;
	inline  static float const m_epsilon = 0.001f;


public:


	

	



	


	static void acquireIdDeclUIColorAddr(__int64 IdDeclUIColorAddr);

	static idColor blendWithWhite(const idColor& color, float blendFactor);

	static void setAlpha(const idColor& baseColor, idColor& destColor, float alphaF);

	static void setIconWhiteBlendColor(const idColor& baseColor, idColor& destColor, float blendFactor);

	//static void setIconExtraBorderColor(const idColor& baseColor, idColor& destColor);

	//static void setIconBackgroundColor(const idColor& baseColor, idColor& destColor);

	static const idColor* getCustomIdColor(int namedColorId);

	static bool isUserColorCustom(swfNamedColors_t userColorId);

	static idColor getCurrentProfileFragNadeIconColor();

	static idColor getCurrentProfileFragNadeBackgroundColor();

	static idColor getCurrentProfileIceNadeIconColor();

	static idColor getCurrentProfileIceNadeBackgroundColor();

	static bool isHudElementWeaponRelated(int fullPathHash);

	static bool isHudElementFragNade(int fullPathHash);

	static bool isHudElementFragNadeBackGround(int fullPathHash);

	static bool isHudElementFragNadeIcon(int fullPathHash);

	static bool isHudElementFuelIcon(int fullPathHash);

	static bool isHudElementWeaponColor(int namedColorId);

	static bool isHudElementLowAmmoWarningShape(int fullPathHash);

	static bool isHudElementLowWarning(int fullPathHash);

	static void forceUpdateHudElementsColors();

	static unsigned int getColor(idSWFSpriteInstance* spritInstancePtr, unsigned int namedColorId);

	static __int32 getOriginalColorAlt(int spriteId);

	static __int32 getOriginalColor(int spriteId);

	static bool isEquipmentArrow(__int64 spriteInstanceAddr);

	static void acquireMonitoredSpriteInstanceAddr(idSWFSpriteInstance* spriteInstance);

	static swfRect_t getFragIconCoords();

	static swfRect_t getEquipmentArrowBounds();

	static swfRect_t getEquipmentBackerBounds();

	static swfRect_t getSpriteBounds(int spriteHashId);



	static void debugLogUniqueSpriteInstance(idSWFSpriteInstance* idSWFSpriteInstance, const std::unordered_set<std::string>& excludeFilter);

	static void debugLogUniqueSpriteInstance(idSWFSpriteInstance* idSWFSpriteInstance);

	static std::string spriteInstancegetFullPathStr(const idSWFSpriteInstance* instance);


	static unsigned int debugLogInstancesDefaultNamesColors(__int64 spriteInstanceAddr, unsigned int namedColorId);

	static unsigned int testColors(__int64 spriteInstanceAddr, unsigned int namedColorId);

	static void debugLogFragIconCoords();

	static void addSpriteInstanceAddrToDebugVec(__int64 addr);

	static bool isSpriteIdBeingDebugged(__int64 spriteInstanceAddr);

	static bool isSpriteColorIdBeingDebugged(unsigned int namedColorId);

};

//__int64 GameHudColorsManager::m_currentIdDeclUIColor = 0;
//
//idColor GameHudColorsManager::m_defaultFragNadeIconColor = colorGreen;
//idColor GameHudColorsManager::m_defaultFragNadeBackgroundColor = colorGreen;
//
//idColor GameHudColorsManager::m_defaultIceNadeIconColor = colorBlue;
//idColor GameHudColorsManager::m_defaultIceNadeBackgroundColor = colorBlue;
//
//idColor GameHudColorsManager::m_fragNadePulseColor = colorGreen;
//idColor GameHudColorsManager::m_iceNadePulseColor = colorBlue;
//
//bool GameHudColorsManager::m_isEquipmentFlag = false;
//__int64 GameHudColorsManager::m_currentEquipmentArrowSpriteInstanceAddr = 0;
//__int64 GameHudColorsManager::m_EquipmentBackerSpriteInstanceAddr = 0;
//
// __int64  GameHudColorsManager::m_healthIconOuterSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthIconBgSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthTextSpriteIdAddr = 0;
// __int64  GameHudColorsManager::m_healthPipsOutlineSpriteIdAddr = 0;
// __int64  GameHudColorsManager::m_healthPipsGradientBottomSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthPipsGradientTopSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthBgLeftLeftSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthRightSideMiddleMiddleSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthRightSideRightRightSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthGlowSpriteIdSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthPulseLoopSpriteAddr = 0;
// __int64  GameHudColorsManager::m_healthBottomAdornmentSpriteAddr = 0;
// __int64 GameHudColorsManager::m_healthRightSideAddAmountSpriteAddr = 0;
// __int64 GameHudColorsManager::m_healthrightSideRightborderSpriteAddr = 0;
//
// __int64 GameHudColorsManager::m_armorBarGradientSpriteAddr = 0;
// __int64 GameHudColorsManager::m_armorBarBaseSpriteAddr = 0;
// __int64 GameHudColorsManager::m_armorRightSideSpriteAddr = 0;
// __int64 GameHudColorsManager::m_armorTextSpriteAddr = 0;
// __int64 GameHudColorsManager::m_armorIconSpritAddr = 0;
// __int64 GameHudColorsManager::m_armorIconGlowSpriteAddr = 0;
// __int64 GameHudColorsManager::m_armorInfoSpriteAddr = 0;
// __int64 GameHudColorsManager::m_armorBgSpriteAddr = 0;
//
// __int64 GameHudColorsManager::m_weaponInfoCoolDownSpriteAddr = 0;
// __int64 GameHudColorsManager::m_weaponInfoBgModlessSpriteAddr = 0;
// __int64 GameHudColorsManager::m_weaponInfoTextSpriteAddr = 0;
// __int64 GameHudColorsManager::m_weaponInfoBgSpriteAddr = 0;
//
// __int64 GameHudColorsManager::m_bloodPunchBgPulseSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchChargeGlowBgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchBgImgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchBorderImgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchIconOnSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchIconOffSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchReadyFlashSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchFillRightGlowSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchFillRightImgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchFillLeftGlowSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchFillLeftImgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchTextSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchBindKbmSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchBindJoySpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchChargeBgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_bloodPunchImgImgSpriteAddr = 0;
//
// __int64 GameHudColorsManager::m_radSuitBarGradientSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitBarBaseSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitRightSideSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitTextSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitIconImgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitGlowImgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitBgSpriteAddr = 0;
// __int64 GameHudColorsManager::m_radSuitBgPulseSpriteAddr = 0;
//
// __int64 GameHudColorsManager::m_fragCoolDownFillGlowSpriteAddr = 0;
//
// __int64 GameHudColorsManager::m_debug_EquipmentSpriteInstanceAddr = 0;
//
// __int64 GameHudColorsManager::m_weaponInfoBigBarSpriteAddr = 0;
//
// int GameHudColorsManager::m_debugLastHash = 0;
//
//std::vector<__int64> GameHudColorsManager::m_debugSpriteInstanceAddressesVec;
//size_t GameHudColorsManager::m_debugIndex = 0;
//
//
//std::vector<unsigned int> GameHudColorsManager::m_debugColorIdVec = { SWF_NAMED_COLOR_HUD_BASE, SWF_NAMED_COLOR_HUD_TEXT, SWF_NAMED_COLOR_HUD_HEADER, SWF_NAMED_COLOR_DASH_BASE, SWF_NAMED_COLOR_DASH_GLOW };
//
//
//
////! trying without the bloodPunchReadyFlashSpriteId which has several colors....
//std::vector<int32_t> GameHudColorsManager::bloodPunchSpriteIdsVec = { bloodPunchBgPulseSpriteId , bloodPunchChargeGlowBgSpriteId, bloodPunchBgImgSpriteId, bloodPunchBorderImgSpriteId, bloodPunchIconOnSpriteId, bloodPunchIconOffSpriteId, bloodPunchFillRightGlowSpriteId, bloodPunchFillRightImgSpriteId ,bloodPunchFillLeftGlowSpriteId , bloodPunchFillLeftImgSpriteId , bloodPunchTextSpriteId, bloodPunchBindKbmSpriteId, bloodPunchBindJoySpriteId, bloodPunchChargeBgSpriteId , bloodPunchImgImgSpriteId, bloodPunchBgBaseSpriteId };
//
//
//std::vector<int32_t> GameHudColorsManager::radSuitSpriteIdsVec = { radSuitBarGradientSpriteId, radSuitBarBaseSpriteId ,radSuitRightSideSpriteId ,radSuitTextSpriteId ,radSuitIconImgSpriteId , radSuitGlowImgSpriteId ,radSuitBgSpriteId , radSuitBgPulseSpriteId };
//
//std::vector<int32_t> GameHudColorsManager::fragNadeSpriteIdsVec = { fragCoolDownFillGlowSpriteId, fragCoolDownInnerFillSpriteId, fragCoolDownFillFillSpriteId, fragIconSpriteId };
//
//
////! 27/10/23 this is our latest experiement, basically using debugPrintfullPathHashIfIsColorId in the hook to get all the hash ids of the elements that have the HUD_EQUIPMENT_FRAG which means they should all have its color, so it means we should color them is user want to customize the nade icon through our mod, so these are the full path ids i found in the log:
//std::vector<unsigned int> GameHudColorsManager::m_HudEquipmentFragHashIdsVec{ 0xE187B796, 0x69411733, 0x163F64A6, 0x5D8A8852, 0x766C6A57, 0x17F43D45 };
//std::vector<unsigned int> GameHudColorsManager::m_HudEquipmentFragIconHashIdsVec{ 0x9BA03A81, 0xFFB27971 };
//
//
//int GameHudColorsManager::m_debugNamedColorIndex = -1;
//
//float const GameHudColorsManager::m_epsilon = 0.001f;
