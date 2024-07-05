#include "MaterialLib.h"


size_t MaterialLib::m_libIndex = 0;
idDeclInfo MaterialLib::m_idDeclInfo;
bool MaterialLib::m_isdebugMatrVecInitialized = false;



//! extra info is still unknow, but it's not related to get the material low/high res.

 __int64 MaterialLib::get(const char* matNameStr, unsigned int extraInfo) {
	return m_idDeclInfo.getMaterialPtr(matNameStr, extraInfo);
}

 __int64 MaterialLib::get(hudSpriteId_t hudSpriteId) {
	switch (hudSpriteId)
	{
	case HUD_SPRITE_ID_UNKNOWN:
		return getWhite();
	case HUD_SPRITE_ID_FLAMEBELCH:
		return getFlameBelchMtr();
	case HUD_SPRITE_ID_FUEL:
		return getFluelAmmoMtr();
	case HUD_SPRITE_ID_FRAG:
		return getFragGrenadeMtr();
	case HUD_SPRITE_ID_ICE:
		return getIceGrenadeMtr();
	case HUD_SPRITE_ID_CRUCIBLE:
		return getRocketIconMtr();
	case HUD_SPRITE_ID_HAMMER:
		return getRocketIconMtr();
	case HUD_SPRITE_ID_BLOODPUNCH:
		return getRocketIconMtr();
	case HUD_SPRITE_ID_DASH:
		return getRocketIconMtr();
	case HUD_SPRITE_ID_AMMOS_UNKNOWN:
		return getWhite();;
	case HUD_SPRITE_ID_AMMOS_SHELL:
		return getShellIconMtr();
	case HUD_SPRITE_ID_AMMOS_BULLET:
		return getBulletIconMtr();
	case HUD_SPRITE_ID_AMMOS_ROCKET:
		return getRocketIconMtr();
	case HUD_SPRITE_ID_AMMOS_CELL:
		return getCellIconMtr();
	case HUD_SPRITE_ID_MAX:
		return getWhite();
	default:
		return getWhite();
	}
}

 __int64 MaterialLib::getWhite() {
	return  m_idDeclInfo.getMaterialPtr("_white", 0);
	/*if (!m_cached_whiteMatr) {
	m_cached_whiteMatr =  m_idDeclInfo.getMaterialPtr("_white", 0);
	}
	return m_cached_whiteMatr;*/

}

//? doesn't work it's not green:

 __int64 MaterialLib::getGreen() {
	return  m_idDeclInfo.getMaterialPtr("_green", 0);
	/*if (!m_cached_greenMatr) {
	m_cached_greenMatr = m_idDeclInfo.getMaterialPtr("_green", 0);
	}*/
	/*__int64 matrAddr = m_idDeclInfo.getMaterialPtr("_white", 0);
	logInfo("getWhite: matrAddr: %llx ", matrAddr);
	return matrAddr;*/
	//return m_cached_greenMatr;
}

//? setting the bool to 1 will do nothing to prevent the current flickering of the texture

 __int64 MaterialLib::getFragGrenadeMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_grenade_frag_", 0);
	/*if (!m_cached_FragNadeMtr) {
	m_cached_FragNadeMtr =  m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_grenade_frag_", 0);
	}
	return m_cached_FragNadeMtr;*/
}

 __int64 MaterialLib::getFlameBelchMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ability_flame_belch_racecar_", 0);
	/*if (!m_cached_FlameBelchMtr) {
	m_cached_FlameBelchMtr =  m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ability_flame_belch_racecar_", 0);
	}
	return m_cached_FlameBelchMtr;*/
}

 __int64 MaterialLib::getFluelAmmoMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_fuel_", 0);
	/*if (!m_cached_FuelMtr) {
	m_cached_FuelMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_fuel_", 0);
	}
	return m_cached_FuelMtr;*/
}

 __int64 MaterialLib::getHammerMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_hammer_racecar_", 0);
	/*if (!m_cached_HammerMtr) {
	m_cached_HammerMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_hammer_racecar_", 0);
	}
	return m_cached_HammerMtr;*/
}

 __int64 MaterialLib::getCrucibleMtr() {
	return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_reticle_textures/swf_images/reticles/crucible/ret_center_circle_4pins_", 0);
	/*if (!m_cached_CrucibleMtr) {
	m_cached_CrucibleMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_reticle_textures/swf_images/reticles/crucible/ret_center_circle_4pins_", 0);
	}
	return m_cached_CrucibleMtr;*/
}

 __int64 MaterialLib::getBloodPunchMtr() {
	return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_rune_bloodpunch_racecar_", 0);
	/*	if (!m_cached_bloodPunchMtr) {
	m_cached_bloodPunchMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_rune_bloodpunch_racecar_", 0);
	}
	return m_cached_bloodPunchMtr;*/
}

 __int64 MaterialLib::getDashMtr() {
	return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_dash_textures/swf_images/hud/buffs/hud_slayer_rune_container_corner_", 0);
	/*if (!m_cached_dashMtr) {
	m_cached_dashMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_dash_textures/swf_images/hud/buffs/hud_slayer_rune_container_corner_", 0);
	}
	return m_cached_dashMtr;*/
}

 __int64 MaterialLib::getHealthMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_healthinfo_textures/swf_images/icons/icon_health_new_", 0);
	/*if (!m_cached_healthMtr) {
	m_cached_healthMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_healthinfo_textures/swf_images/icons/icon_health_new_", 0);
	}
	return m_cached_healthMtr;*/
}

 __int64 MaterialLib::getArmorMtr() {
	return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_healthinfo_textures/swf_images/icons/icon_armor_", 0);
	/*if (!m_cached_armorMtr) {
	m_cached_armorMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_healthinfo_textures/swf_images/icons/icon_armor_", 0);
	}
	return m_cached_armorMtr;*/
}

 __int64 MaterialLib::getIceGrenadeMtr() {

	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_", 0);
	/*if (!m_cached_IceNadeStarIconMtr) {
	m_cached_IceNadeStarIconMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_", 0);
	}
	return m_cached_IceNadeStarIconMtr;*/
}

 __int64 MaterialLib::getIceNadeBorderMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_backer_", 0);

	/*if (!m_cached_IceNadeBorderMtr) {

	m_cached_IceNadeBorderMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_backer_", 0);
	}
	return m_cached_IceNadeBorderMtr;	*/

	//! this one is slighty thicker
	//return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_fill_", 0);
}

 __int64 MaterialLib::getIceNadeExtraBorderMtr() {
	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_fill_", 0);

	/*if (!m_cached_IceNadeExtraBorderMtr) {
	m_cached_IceNadeExtraBorderMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_fill_", 0);
	}*/
	//return m_cached_IceNadeExtraBorderMtr;	
}

 __int64 MaterialLib::getIceNadeBackgroundMtr() {

	return m_idDeclInfo.getMaterialPtr("swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_radsuit_iconbacker_", 0);

	/*	if (!m_cached_IceNadeBackgroundMtr) {
	m_cached_IceNadeBackgroundMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_radsuit_iconbacker_", 0);
	}
	return m_cached_IceNadeBackgroundMtr;*/


	//! this is really good BUT you need to set the color to be less intense that the outline, for ex if both are white it will lookd very wrong.
	//return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_flash_", 0);
	//return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_new_", 0); // too dark
	//return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_backer_", 0); // this is same as border, weird.
}

 __int64 MaterialLib::getShellIconMtr() {
	return  m_idDeclInfo.getMaterialPtr("art/ui/icons/ammo/shells", 0);
}

 __int64 MaterialLib::getBulletIconMtr() {
	return  m_idDeclInfo.getMaterialPtr("art/ui/icons/ammo/bullets", 0);
}

 __int64 MaterialLib::getRocketIconMtr() {
	return  m_idDeclInfo.getMaterialPtr("art/ui/icons/ammo/rocket", 0);
}

 __int64 MaterialLib::getCellIconMtr() {
	return  m_idDeclInfo.getMaterialPtr("swf/hud/hud_reticle_textures/swf_images/icons/icon_ammo_cell_", 0);
}

 __int64 MaterialLib::getCursorEmptyMtr() {
	return  m_idDeclInfo.getMaterialPtr("textures/guis/cursor_empty", 0);
}

 __int64 MaterialLib::getMtr(std::string matrStr) {
	return  m_idDeclInfo.getMaterialPtr(matrStr.c_str(), 0);
}

//! found this studying idFont16GetMaterialWidth_4CCA50 but org code is for a idfont

 unsigned MaterialLib::getMaterialWidth(__int64 matrPtr)
{
	if (MemHelper::isBadReadPtr((void*)matrPtr)) {
		logWarn("getMaterialWidth:  bad ptr returning -1");
		return -1;
	}

	if (matrPtr)
		return (unsigned int)*(__int16*)(matrPtr + 0x18);
	else
		return 1i64;
}

//! Found this studying idFont::GetMaterialHeight_4CCA20 but org code is for a idfont

 unsigned int MaterialLib::getMaterialHeight(__int64 matrPtr)
{
	if (MemHelper::isBadReadPtr((void*)matrPtr)) {
		logWarn("getMaterialHeight:  bad ptr returning -1");
		return -1;
	}
	if (matrPtr)
		return (unsigned int)*(__int16*)(matrPtr + 0x1A);
	else
		return 1i64;

	// this code if for an idfont as input
	//typedef unsigned long long QWORD;
	//__int64 i; // rax
	//__int64 v2; // rax

	//for (i = *(QWORD*)(a1 + 0x58); i; i = *(QWORD*)(i + 0x58))
	//	a1 = i;
	//v2 = *(QWORD*)(a1 + 0x60);
	//if (v2)
	//	return (unsigned int)*(__int16*)(v2 + 0x1A);
	//else
	//	return 1i64;
}
