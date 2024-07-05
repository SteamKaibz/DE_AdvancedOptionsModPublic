#pragma once
#include "GeneratedClasses.h"
#include "idDeclGlobalShellManager.h"
#include "../ModSettings/modSettings.h"
#include "idPlayer.h"
#include "../ImGui/dependencies/imgui/imgui_internal.h"




//! a way to restore the default colors we modify, everytime user changes profile
struct idDeclUIColor_Custom {
	bool isInitialized = false; //! will be set to true in createCustomColorDeclBAK 

	idStrId displayName ;
	//Offset 0x8C 	Size 0x1 (1)	 Whether or not this color profile is for color blind accessibility
	bool isColorBlindProfile;
	//Offset 0x90 	Size 0x14 (20)	 The color the hud draws in	
	idDeclUIColor_uiColorDef_t uiRadiation;
	//Offset 0x1BC 	Size 0x14 (20)	 The color used across the UI for radiation gradients
	idDeclUIColor_uiColorDef_t uiRadiationGradient;

	idDeclUIColor_uiColorDef_t white;
	//Offset 0x518 	Size 0x14 (20)	 The color representing the chainsaw in UI
	idDeclUIColor_uiColorDef_t weaponChainsaw;
	//Offset 0x52C 	Size 0x14 (20)	 The color representing the combat shotgun in UI
	idDeclUIColor_uiColorDef_t weaponShotgun;
	//Offset 0x540 	Size 0x14 (20)	 The color representing the double barrel shotgun in UI
	idDeclUIColor_uiColorDef_t weaponDoubleBarrel;
	//Offset 0x554 	Size 0x14 (20)	 The color representing the assualt rifle in UI
	idDeclUIColor_uiColorDef_t weaponAssualtRifle;
	//Offset 0x568 	Size 0x14 (20)	 The color representing the chaingun in UI
	idDeclUIColor_uiColorDef_t weaponChaingun;
	//Offset 0x57C 	Size 0x14 (20)	 The color representing the plasma rifle in UI
	idDeclUIColor_uiColorDef_t weaponPlasmaRifle;
	//Offset 0x590 	Size 0x14 (20)	 The color representing the ballista in UI
	idDeclUIColor_uiColorDef_t weaponBallista;
	//Offset 0x5A4 	Size 0x14 (20)	 The color representing the rocket launcher in UI
	idDeclUIColor_uiColorDef_t weaponRocketLauncher;
	//Offset 0x5B8 	Size 0x14 (20)	 The color representing the BFG in UI
	idDeclUIColor_uiColorDef_t weaponBfg;
	//Offset 0x5CC 	Size 0x14 (20)	 The color representing the Unmaykr in UI
	idDeclUIColor_uiColorDef_t weaponUnmaykr;
	//Offset 0x5E0 	Size 0x14 (20)	 The color representing the crucible in UI
	idDeclUIColor_uiColorDef_t weaponCrucible;
	//Offset 0x5F4 	Size 0x14 (20)	 The color representing the hammer in UI
	idDeclUIColor_uiColorDef_t weaponHammer;	
	//Offset 0x630 	Size 0x14 (20)	 The color representing the combat shotgun when full in UI
	idDeclUIColor_uiColorDef_t weaponShotgunFull;
	//Offset 0x644 	Size 0x14 (20)	 The color representing the double barrel shotgun when full in UI
	idDeclUIColor_uiColorDef_t weaponDoubleBarrelFull;
	//Offset 0x658 	Size 0x14 (20)	 The color representing the assualt rifle when full in UI
	idDeclUIColor_uiColorDef_t weaponAssualtRifleFull;
	//Offset 0x66C 	Size 0x14 (20)	 The color representing the chaingun when full in UI
	idDeclUIColor_uiColorDef_t weaponChaingunFull;
	//Offset 0x680 	Size 0x14 (20)	 The color representing the plasma rifle when full in UI
	idDeclUIColor_uiColorDef_t weaponPlasmaRifleFull;
	//Offset 0x694 	Size 0x14 (20)	 The color representing the ballista when full in UI
	idDeclUIColor_uiColorDef_t weaponBallistaFull;
	//Offset 0x6A8 	Size 0x14 (20)	 The color representing the rocket launcher when full in UI
	idDeclUIColor_uiColorDef_t weaponRocketLauncherFull;
	//Offset 0x6BC 	Size 0x14 (20)	 The color representing the BFG when full in UI
	idDeclUIColor_uiColorDef_t weaponBfgFull;
	//Offset 0x6D0 	Size 0x14 (20)	 The color representing the Unmaykr when full in UI
	idDeclUIColor_uiColorDef_t weaponUnmaykrFull;
	//Offset 0x6E4 	Size 0x14 (20)	 The color representing the hammer when full in UI
	idDeclUIColor_uiColorDef_t weaponHammerFull;
	//Offset 0x6F8 	Size 0x14 (20)	 The color representing the reticle base
	idDeclUIColor_uiColorDef_t reticleBase;
	//Offset 0x70C 	Size 0x14 (20)	 The color representing the reticle glow
	idDeclUIColor_uiColorDef_t reticleGlow;	//Offset 0x720 	Size 0x14 (20)	 The color representing the reticle cooldown 	
	//Offset 0x11D4 	Size 0x14 (20)	 frag grenade hud color
	idDeclUIColor_uiColorDef_t hudEquipmentFrag;
	//Offset 0x11E8 	Size 0x14 (20)	 frag grenade Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentFragIcon;
	//Offset 0x11FC 	Size 0x14 (20)	 cyro grenade hud color
	idDeclUIColor_uiColorDef_t hudEquipmentCyro;
	//Offset 0x1210 	Size 0x14 (20)	 cyro grenade Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentCyroIcon;
	//Offset 0x1224 	Size 0x14 (20)	 chainsaw hud color
	idDeclUIColor_uiColorDef_t hudEquipmentChainsaw;
	//Offset 0x1238 	Size 0x14 (20)	 chainsaw Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentChainsawIcon;	
	//Offset 0x1288 	Size 0x14 (20)	 crucible Icon hud color	
	//Offset 0x14B8 	Size 0x14 (20)	 color used for supercharged blood punch on HUD
	idDeclUIColor_uiColorDef_t bloodPunchSuperchargeBase;
	//Offset 0x14CC 	Size 0x14 (20)	 glow color used for supercharged blood punch on HUD
	idDeclUIColor_uiColorDef_t bloodPunchSuperchargeGlow;
	//Offset 0x14E0 	Size 0x14 (20)	 glow color used for supercharged blood punch on HUD	

};

/// <summary>
/// this should be used to change idDeclUIColor::uiColorDef_t of a idDeclUIColor so we can easily change the hud color elements
/// </summary>
class idDeclUIColorManager
{
private:

	//? this was wrong as we got this from a hook which is not active when the game in is main menu....
	//static inline idDeclUIColor* m_currentIdDeclUIColor = nullptr;

	//! default idDeclUIColor_Custom used to restore hud to default game colors 
	static inline std::vector<idDeclUIColor_Custom> m_idDeclUIColor_Custom_Vec;

	static inline bool m_isInitialized = false;

public:

	//! just a way to group funcs
	//static void initColors();

	//! we get it from a hook which is already used by GameHudColorsManager
	//static void updateCurrentIdDeclUIColorFromHook(idDeclUIColor* idDeclUIColorPtr);

	static ImU32 ConvertIdColorToU32(const idColor& idColor);

	//? forcing alpha to max as user can not change alpha value in color picker cause it's a bit confusing.
	//static ImVec4 convertIdColorToImVec4(idColor idcolor);

	static void setKaibzHudColorsToGameColorProfile();

	static ImU32 getCurGameProfileColorElemImU32(KaibzHudColor_t color_k);

	//static ImVec4 getCurGameProfileColorElemImVec4(KaibzHudColor_t color_k);

	//static void debugLogCurrentColorProfileName(int index);

	////! those idDeclUIColor ptrs swill not change during game lifetime from my tests.
	//static void acquireDefaultColors();

	//static bool createCustomColorDeclBAK(idDeclUIColor_Custom& customColor,  const idDeclUIColor* originalColor);

	//static void restoreColorsForHudElement(hudElementColorRef hudElementRef, idDeclUIColor* originalColorPtr);

	//static idDeclUIColor_Custom findCustomColorByDisplayName(unsigned int displayNameId);

	////! this sould be called by each reset button in the hud color section of the mod menu
	//static void restoreAllProfilesColorsForHudElement(hudElementColorRef hudElementRef);

	////? we shouldn't have to apply to all profile as a hook or func is going to check the status of everything and will change the current color profile values if needed
	////static void applyHudColorsFromModSettings();

	////static void applyUserSettingsToColorProfile(idDeclUIColor* colorProfilePtr);

	////? should be called at start and when out of mod menu
	////static void updateCustomIdColors();

	//static void updateHudColors();



	//static void restoreOriginalColorProfile(idDeclUIColor_Custom customColor, idDeclUIColor* originalColorPtr);

};

