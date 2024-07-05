#include "MaterialDebug.h"



int MaterialDebug::m_testMaterialNameIndex = 0;

//bool MaterialDebug::m_isMaterialDebugMode;

__int64 MaterialDebug::m_testMtr;

idDeclInfo MaterialDebug::m_idDeclInfo;

std::string MaterialDebug::ammoEquipmentFilterStr = "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/";

bool MaterialDebug::m_isInitialized;

//materialDebugMode MaterialDebug::debugMode = materialDebugMode::gameList;
materialDebugMode MaterialDebug::debugMode = materialDebugMode::none;

std::vector<std::string> MaterialDebug::m_materialsNamesVec = { "art/ui/icons/argent_cells_upgrade/upgrade_categories/environmental_resistance_off", "art/ui/icons/argent_cells_upgrade/upgrade_categories/powerup_on", "swf/hud/menus/collectible_viewer_textures/swf_images/hud/collectible_viewer/titlebar_bg_", "swf/hud/menus/collectible_viewer_textures/swf_images/pvp_battlearena_lobby/menu_ba_footer_backing_center_", "swf/hud/menus/collectible_viewer_textures/swf_images/pvp_battlearena_lobby/menu_ba_footer_backing_leftside_", "swf/hud/menus/collectible_viewer_textures/swf_images/pvp_battlearena_lobby/menu_ba_footer_backing_rightside_", "swf/hud/menus/dossier/dossier_map_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_pip_glow_", "swf/hud/menus/dossier/dossier_runes_textures/swf_images/dossier/runes/rune_btn_default_", "swf/hud/menus/dossier/dossier_runes_textures/swf_images/dossier/runes/rune_btn_hover_", "swf/main_menu/overlay_textures/swf_images/common/buttons/command_bar/command_bar_social_backing_", "swf/hud/hud_walkthrough_textures/swf_images/hud/tutorial/tutorial_container_ctafooter_glow_", "swf/common/social_bar_textures/swf_images/common/buttons/command_bar/command_bar_social_backing_", "swf/common/social_bar_textures/swf_images/common/buttons/command_bar/command_bar_social_glow_", "swf/main_menu/screens/leaderboards_textures/swf_images/dossier/overlay/dossier_btn_default_center_tile_stroke_glow_", "swf/main_menu/screens/leaderboards_textures/swf_images/dossier/overlay/dossier_btn_default_left_cap_stroke_glow_", "swf/main_menu/screens/leaderboards_textures/swf_images/dossier/overlay/dossier_btn_default_right_cap_stroke_glow", "swf/hud/menus/dossier/dossier_arsenal_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_glowblast_c_", "swf/hud/demon/hud_abilitybar_textures/swf_images/hud_demon/ability_containers/hud_demon_ability_cooldown_fill_", "swf/main_menu/overlay_textures/swf_images/customization/tab_backing_down_stroke_", "_white",
   "art/ui/icons/ammo/shells",
   "art/ui/icons/ammo/rocket",
   "swf/hud/hud_reticle_textures/swf_images/icons/icon_ammo_cell_",
   "art/ui/icons/argent_cells_upgrade/argent_cell_health",
   "art/ui/icons/ammo/ico_shells",
   "art/ui/icons/ammo/bullets",
   "art/ui/icons/ammo/fist",
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_",
   "art/ui/weapon/equipment_frag_grenade",  // this one is lowRes by default
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/hud/ammo_equipment/hud_slayer_equipment_circlepip_full_",
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_hammer_racecar_",
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_grenade_frag_",  // this one is HiRes by default
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ability_flame_belch_racecar_",
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_fuel_",
   "swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_rune_bloodpunch_racecar_",
   "swf/hud/pvp/hud_matchheader_textures/swf_images/icons/callouts/icon_callout_plus_",
   "swf/hud/hud_poi_textures/swf_images/icons/icon_grenade_frag_",
   "swf/hud/hud_weaponinfo_textures/swf_images/icons/icon_ability_flame_belch_", //? without the dot
   "swf/hud/hud_weaponinfo_textures/swf_images/icons/icon_ammo_fuel_",
   "swf/hud/hud_bossvitals_textures/swf_images/icons/callouts/icon_callout_plus_outline_",
   "swf/hud/hud_bossvitals_textures/swf_images/icons/callouts/icon_callout_plus_",
   "swf/hud/hud_healthinfo_textures/swf_images/icons/icon_health_new_",
   "swf/hud/hud_healthinfo_textures/swf_images/icons/icon_health_new_glow_",
   "swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_full_",
   "swf/hud/hud_healthinfo_textures/swf_images/icons/icon_armor_",
   "swf/hud/menus/death_textures/swf_images/icons/icon_armor_",
   "swf/hud/menus/end_of_level/eol_horde_map_score_textures/swf_images/common/scrollbar/hud_scrollbar_endcap_arrow_",
   "swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/painelemental/demon_reticle_painelemental_outerrim_glow_",
   "swf/hud/hud_compass_textures/swf_images/icons/icon_objective_arrow_",
   "swf/hud/hud_dash_textures/swf_images/hud/buffs/hud_slayer_rune_container_corner_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/rocket_launcher/ret_rocket_lock_part01_top_",
   "swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/marauder/demon_reticle_marauder_outerrim_glow_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/crucible/ret_center_circle_4pins_",
   "swf/main_menu/screens/settings_textures/swf_images/icons/icon_tab_notification_",
   "textures/guis/icons/weapons/simple/bfg",
   "textures/swf_images/hud/weapon_icon/weaponicon_heavycannon"  //! found this in an idimage of a idmaterial of chaingun
   "textures/guis/icons/weapons/simple/har",
   "textures/guis/icons/weapons/simple/gauss",
   "textures/guis/icons/weapons/simple/chaingun",
   "textures/guis/icons/weapons/simple/dbshotgun",
   "textures/guis/icons/weapons/simple/rocket",
   "textures/guis/icons/weapons/simple/plasma",
   "textures/guis/icons/weapons/simple/shotgun",
   "textures/guis/hud/damage_icons/weapon_rocket",
   "textures/guis/icons/perks/weapons/shotgun/pop_rocket",
   "textures/guis/loading_screen/sp/img_loading_sp_rocket_launcher",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_ammo_top_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_ammo_glow_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_top_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_glow_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_mastered_glow_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_mastered_top_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_pin_glow_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_pin_top_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/super_shotgun/ret_supershotgun_base_top_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/super_shotgun/ret_supershotgun_hook_top_",
   "swf/hud/hud_reticle_textures/swf_images/reticles/super_shotgun/ret_supershotgun_hook_glow_",
   "swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/revenant/demon_reticle_revenant_innerrim_glow_",
   "swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/revenant/demon_reticle_revenant_innerrim_",
   "swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/revenant/demon_reticle_revenant_outerrim_",
   "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_new_",
   "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_backer_",
   "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_fill_",
   "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_2pip_backer_",
   "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_2pip_fill_",
   "swf/hud/hud_weaponinfo_textures/swf_images/icons/icon_swap2_",
   "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_swap_alt_",
   "swf/hud/hud_score_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_pip_",
   "swf/common/social_bar_textures/swf_images/common/buttons/command_bar/command_bar_social_backing_",
   "swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_empty_",
   "swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_fadednumbers_",
   "swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_full_",
   "swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_radsuit_iconbacker_",
   "swf/hud/hud_healthinfo_textures/swf_images/icons/icon_armor_", "swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_flash_" };




 bool MaterialDebug::isMaterialDebugMode() {
	initialize(); // will only get materials if in gameList mode
	return debugMode != materialDebugMode::none;
}

 void MaterialDebug::initialize() {
	if (!m_isInitialized && debugMode == materialDebugMode::gameList) {
		acquiredFilteredMaterialsFromTheGame(ammoEquipmentFilterStr);
	}

	m_isInitialized = true;
}

 void MaterialDebug::setPrevTestMtr() {
	initialize();
	m_testMaterialNameIndex--;
	if (m_materialsNamesVec.size() <= 0) {
		logErr("setPrevTestMtr: liveTestMtrStrVec is empty");
		return;
	}
	if (m_testMaterialNameIndex <= 0) {
		m_testMaterialNameIndex = (int)m_materialsNamesVec.size() - 1;
	}
	else if (!(m_testMaterialNameIndex >= 0) || !(m_testMaterialNameIndex < m_materialsNamesVec.size())) {
		logWarn("setPrevTestMtr: index out of bounds: %d setting it to 0", m_testMaterialNameIndex);
		m_testMaterialNameIndex = 0;
	}
	std::string matrStr = m_materialsNamesVec[m_testMaterialNameIndex];
	m_testMtr = m_idDeclInfo.getMaterialPtr(matrStr.c_str(), 0);
	logInfo("setPrevTestMtr: mtr name: %s (index: %d)", matrStr.c_str(), m_testMaterialNameIndex);
}

 void MaterialDebug::setNextTestMtr() {
	initialize();
	m_testMaterialNameIndex++;
	if (m_materialsNamesVec.size() <= 0) {
		logErr("setNextTestMtr: liveTestMtrStrVec is empty");
		return;
	}
	if (!(m_testMaterialNameIndex >= 0) || !(m_testMaterialNameIndex < m_materialsNamesVec.size())) {
		logWarn("setNextTestMtr: index out of bounds: %d setting it to 0", m_testMaterialNameIndex);
		m_testMaterialNameIndex = 0;
	}
	std::string matrStr = m_materialsNamesVec[m_testMaterialNameIndex];
	m_testMtr = m_idDeclInfo.getMaterialPtr(matrStr.c_str(), 0);
	logInfo("setNextTestMtr: mtr name: %s (index: %d)", matrStr.c_str(), m_testMaterialNameIndex);

}

//! material to display

 __int64 MaterialDebug::getTestMtr() {
	if (!m_testMtr) {
		setNextTestMtr(); //! bit of a hack but i'm tired.
	}
	if (MemHelper::isBadReadPtr((void*)m_testMtr)) {
		logErr("getLiveTestMtr:  m_testMtr: %p is bad ptr", (void*)m_testMtr);
		return 0;
	}
	return m_testMtr;
}

 std::string MaterialDebug::getMaterialName(__int64 mtrAdd) {
	if (MemHelper::isBadReadPtr((void*)mtrAdd)) {
		return "bad ptr found for mtrAdd";
	}
	uintptr_t materialStrAddr = *(uintptr_t*)(mtrAdd + 0x8);
	//logInfo("debugMaterialName: material String Addr : %p with name: %s", (void*)materialStrAddr, (const char*)(materialStrAddr));
	std::string s = (const char*)(materialStrAddr);
	return s;
}

 std::string MaterialDebug::getTestMaterialName() {
	if (MemHelper::isBadReadPtr((void*)m_testMtr)) {
		return "bad ptr found for material ptr";
	}
	uintptr_t materialStrAddr = *(uintptr_t*)(m_testMtr + 0x8);
	//logInfo("debugMaterialName: material String Addr : %p with name: %s", (void*)materialStrAddr, (const char*)(materialStrAddr));
	std::string s = (const char*)(materialStrAddr);
	return s;
}

 bool MaterialDebug::FilterMaterialNames(__int64 matrAdd, std::string startWithFilter) {
	// Check if matrAdd is a valid pointer
	if (MemHelper::isBadReadPtr((void*)matrAdd)) {
		logErr("FilterMaterialNames:  matrAdd: %p is bad ptr", (void*)matrAdd);
		return false;
	}

	// Check if matrAdd + 0x8 is a valid memory location
	uintptr_t potentialStringAddress = *(uintptr_t*)(matrAdd + 0x8);
	if (MemHelper::isBadReadPtr((void*)potentialStringAddress)) {
		logErr("FilterMaterialNames: potentialStringAddress: %p is bad ptr", (void*)potentialStringAddress);
		return false;
	}

	// Since the previous checks passed, we can safely dereference the pointer
	std::string matrName = std::string((const char*)potentialStringAddress);

	//if ((matrName.starts_with("models/") || matrName.starts_with("physics/") ||  matrName.starts_with("fontfx/") || matrName.starts_with("effect/"))) {
	if (matrName.starts_with(startWithFilter)) {
		//if (matrName.starts_with("swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/")) {
		return true;
	}

	return false;
}

 void MaterialDebug::acquiredFilteredMaterialsFromTheGame(std::string startWithfilter) {

	logWarn("acquiredFilteredMaterialsFromTheGame: clearing m_materialsNamesVec !");
	m_materialsNamesVec.clear();

	//static bool isDone = false;

	/*if (m_isdebugMatrVecInitialized) {
	logWarn("debugFillMatPtrVec: m_isdebugMatrVecInitialized already initialized, returning");
	return;
	}*/
	//int count = 0;

	__int64 Material2Add = idResourceListManager::getResourceListFirstElementPtr("idMaterial2");
	while (true)
	{
		if (MemHelper::isBadReadPtr((void*)Material2Add)) {
			logWarn("acquiredFilteredMaterialsFromTheGame:  Material2Add: %p is bad ptr  breaking", (void*)Material2Add);
			break;
		}
		else if (MemHelper::isBadReadPtr((void*)*(__int64*)Material2Add)) {
			logWarn("acquiredFilteredMaterialsFromTheGame:  *(__int64*)Material2Add: %p is bad ptr  breaking", (void*)Material2Add);
			break;
		}
		if (FilterMaterialNames(*(__int64*)Material2Add, startWithfilter)) {
			m_materialsNamesVec.push_back(getMaterialName(*(__int64*)Material2Add));
			//count++;
		}
		Material2Add += 0x18; //? yeah hard coded....
		//count++;

	}
	//logInfo("debugFillMatPtrVec: done adding materials to vec: count is: %d", count);
	logInfo("addMtrAddrToDebugVec: DONE m_materialsAddrsDebugVec.size() is: %zu", m_materialsNamesVec.size());
	m_isInitialized = true;

}
