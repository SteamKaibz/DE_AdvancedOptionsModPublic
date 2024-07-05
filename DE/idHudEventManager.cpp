#include "idHudEventManager.h"

bool idHudEventManager::acquireBroadcastManager(__int64 addr)
{
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquireBroadcastManager: addr is bad ptr: %p", (void*)addr);
		m_broadcastManager = 0;
		return false;
	}
	m_broadcastManager = *(__int64*)addr;
	logInfo("acquireBroadcastManager: m_broadcastManager set to %p", (void*)m_broadcastManager);
	return true;
}

bool idHudEventManager::acquireBroadcastHudEventFp(__int64 faddr)
{
	if (MemHelper::isBadReadPtr((void*)faddr)) {
		logErr("acquireBroadcastHudEventFp: faddr is bad ptr: %p", (void*)faddr);
		m_broadcastHudEventFp = nullptr;
		return false;
	}
	m_broadcastHudEventFp = (broadcastHudEvent_t)faddr;
	logInfo("acquireBroadcastHudEventFp: m_broadcastHudEventFp set to %p", m_broadcastHudEventFp);
	return true;
}


void idHudEventManager::send_HUD_EVENT_CURRENCY_CONFIRM( idHUDElement* idHUDMenu_CurrencyConfirmationAddr) {
	//__int16 hudSysId = *(__int16*)(idHUDMenu_CurrencyConfirmationAddr + 0xD0);
	uint16_t hudSysId = idHUDMenu_CurrencyConfirmationAddr->hudSysId;
	m_broadcastHudEventFp(m_broadcastManager, hudSysId, HUD_EVENT_CURRENCY_CONFIRM);
	//m_broadcastHudEventFp(m_broadcastManager, hudSysId, 0x118);

}

void idHudEventManager::testSendHudEvent(__int64 idHUDMenu_CurrencyConfirmationAddr)
{

	logWarn("testSendHudEvent attempting to dismiss pop up...");
	//result: matches @ 0x4A7EA0, sig direct : 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 41 0F B7 F0
	m_broadcastHudEventFp = (broadcastHudEvent_t)MemHelper::getFuncAddr(0x4A7EA0);


	__int16 hudSysId = *(__int16*)(idHUDMenu_CurrencyConfirmationAddr + 0xD0);
	logWarn("testSendHudEvent hudSysId is: %X", hudSysId);
	__int64 broadcastManagerPtr = MemHelper::getFuncAddr(0x452EA88);
	__int64 broadcastManager = *(__int64*)broadcastManagerPtr;
	m_broadcastHudEventFp(broadcastManager, hudSysId, 0x118);
	//sdfm_broadcastHudEventFp(broadcastManager, 0x8E, 0x118);

}


//? this doesn't work don't use it
//void idHudEventManager::onReleasedBroadcastEvent(__int64 eventData_a3) {
//
//	//? no pretty sure this is not right:
//	hudEventID_t hudEvent = (hudEventID_t) * (unsigned int*)eventData_a3;
//	switch (hudEvent)
//	{
//	case HUD_EVENT_INVALID:
//		break;
//	case HUD_EVENT_ACTIVATE_MENU:
//		//? this is trigger, all, the, time.
//		//logInfo("HUD_EVENT_ACTIVATE_MENU triggered");
//		break;
//	case HUD_EVENT_DEACTIVATE_MENU:
//		logInfo("HUD_EVENT_DEACTIVATE_MENU triggered");
//		break;
//	case HUD_EVENT_PLAYER_HEALTHCHANGE:
//		break;
//	case HUD_EVENT_PLAYER_HEALTH_ABSOLUTE:
//		break;
//	case HUD_EVENT_PLAYER_HEALTH_UPGRADE:
//		break;
//	case HUD_EVENT_PLAYER_HEALTH_FLOURISH:
//		break;
//	case HUD_EVENT_PLAYER_AMMOCHANGE:
//		//logInfo("HUD_EVENT_PLAYER_AMMOCHANGE triggered, updating custom hud data...");
//		//? got a crash with this i think during map load:
//		/*HudManager::updateCustomHudIceSpriteData();
//		HudManager::updateCustomHudAmmosData();*/
//		break;
//	case HUD_EVENT_PLAYER_AMMO_PICKUP:
//		//logInfo("HUD_EVENT_PLAYER_AMMO_PICKUP triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_SET_INFINITE_AMMO:
//		//logInfo("HUD_EVENT_PLAYER_SET_INFINITE_AMMO triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_SET_INFINITE_AMMO_BFG:
//		break;
//	case HUD_EVENT_PLAYER_SET_OVERAMMO:
//		//logInfo("HUD_EVENT_PLAYER_SET_OVERAMMO triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_CHANGE_WEAPON:
//		break;
//	case HUD_EVENT_PLAYER_CHANGE_MOD:
//		break;
//	case HUD_EVENT_PLAYER_GAIN_MOD:
//		break;
//		//! this triggers when changing nade, when throwing nade, when nade is refilled even if it's the nade that is not currently selected so that's great.
//	case HUD_EVENT_PLAYER_EQUIPMENT_UPDATE:
//		//logInfo("HUD_EVENT_PLAYER_EQUIPMENT_UPDATE triggered eventData_a3: %llx", eventData_a3);
//		//logWarn("HUD_EVENT_PLAYER_EQUIPMENT_UPDATE Debug: reapplying color overide ");
//		//? this may have been creating crashes, keep that in mind:
//		//GameHudColorsManager::setEquipmentBackerColor(colorRed);
//		break;
//	case HUD_EVENT_PLAYER_EQUIPMENT_UPDATE_ALT:
//		//logInfo("HUD_EVENT_PLAYER_EQUIPMENT_UPDATE_ALT triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_EQUIPMENT_RACECAR_UPDATE:
//		//logInfo("HUD_EVENT_PLAYER_EQUIPMENT_RACECAR_UPDATE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_FLAME_BELCH_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_EQUIPMENT_FLASH_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_FLAME_BELCH_FLASH_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_QUICK_CHAINSAW_FLASH_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_CRUCIBLE_FLASH_FAIL:
//		break;
//	case HUD_EVENT_INPUT:
//		//logInfo("HUD_EVENT_INPUT triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_SPAWNED:
//		//logInfo("HUD_EVENT_PLAYER_SPAWNED triggered eventData_a3: %llx", eventData_a3);
//		//GameHudColorsManager::resetLastBloodPunchVal();
//		break;
//	case HUD_EVENT_PLAYER_POST_SPAWN:
//		//logInfo("HUD_EVENT_PLAYER_POST_SPAWN triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_KILLED:
//		break;
//	case HUD_EVENT_PLAYER_DASH_INIT:
//		break;
//	case HUD_EVENT_PLAYER_WEAPONWHEEL_OPEN:
//		break;
//	case HUD_EVENT_PLAYER_WEAPONWHEEL_CLOSE:
//		break;
//	case HUD_EVENT_PLAYER_WEAPONWHEEL_FORCE_CLOSE:
//		break;
//	case HUD_EVENT_PLAYER_COMBAT_STATE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_RETICLE_UPDATE:
//		//! this triggers many times per seconds even when just moving the mouse around
//		//logInfo("HUD_EVENT_PLAYER_RETICLE_UPDATE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_RADAR_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_DIAGNOSTICS_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_DIAGNOSTICS_ONLINE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_TARGETSTRIKE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_DASHBOARD_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_DEMON_KILL:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_CODEX:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_CODEX_END:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_FAST_TRAVEL:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_CHECKPOINT:
//		//logInfo("HUD_EVENT_PLAYER_NOTIFICATION_CHECKPOINT triggered");
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_KEYCARD:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SLAYER_KEY:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_OBJECTIVE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_OBJECTIVE_COMPLETE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_OBJECTIVE_SHOW_LAST:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_MISSION_CHALLENGE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_MISSION_CHALLENGE_COMPLETE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_WEEKLY_CHALLENGE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_WEEKLY_CHALLENGE_COMPLETE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_WEAPON_MASTERY_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_RUNE_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_RUNE_MASTERY_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_MOD_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_PRAETOR_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SENTINEL_BATTERY_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SLAYER_BATTERY_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_EQUIPMENT_POINT_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_ARGENTUPGRADE_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_COLLECTIBLE_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_WEAPON_POINT_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_WEAPON_MASTERY_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_WEAPON_BROKEN:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_CALLOUT:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_TICKER:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_INVASION_CALLOUT:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_INVASION_INCOMING:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SECRET_HINT:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SECRET_FOUND:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_COMBAT_POINT:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_BOUNTY_ACTIVE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_BOUNTY_COMPLETE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_DOOM_EVENT:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_MILESTONE_COMPLETE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_GAME_HINT:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_HIDE:
//		//logInfo("HUD_EVENT_PLAYER_NOTIFICATION_HIDE triggered");
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_LEVEL_UP:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SEASON_LEVEL_UP:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_LATER_IN_THE_MISSION_E3:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_BUFF_POD_NEARBY:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_UPGRADE_REMINDER:
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_INTRO:
//		//logInfo("HUD_EVENT_PLAYER_MISSION_CHALLENGE_INTRO triggered");
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_TIMER:
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_TIMER_BONUS_TIME:
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_SUCCESS:
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_TIMER_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_PLAYER_CURSED:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_PLAYER_UNCURSED:
//		break;
//	case HUD_EVENT_PLAYER_TIME_ATTACK_TIMER:
//		break;
//	case HUD_EVENT_PLAYER_TIME_ATTACK_TIMER_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_TIME_ATTACK_TIMER_BONUS_TIME:
//		break;
//	case HUD_EVENT_PLAYER_TIME_ATTACK_TIMER_END:
//		break;
//	case HUD_EVENT_PLAYER_COMBAT_POINT_INITIALIZE:
//		break;
//	case HUD_EVENT_PLAYER_SLAYER_GATE_INITIALIZE:
//		break;
//	case HUD_EVENT_PLAYER_SECRET_ENCOUNTER_INITIALIZE:
//		break;
//	case HUD_EVENT_PLAYER_BOSS_COMBAT_INITIALIZE:
//		break;
//	case HUD_EVENT_PLAYER_COMBAT_POINT_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_SLAYER_GATE_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_ESCALATION_ENCOUNTER_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_SECRET_ENCOUNTER_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_BOSS_COMBAT_POINT_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_COMBAT_WEAPON_POINT:
//		break;
//	case HUD_EVENT_PLAYER_SLAYER_GATE_WEAPON_POINT:
//		break;
//	case HUD_EVENT_PLAYER_SECRET_ENCOUNTER_WEAPON_POINT:
//		break;
//	case HUD_EVENT_PLAYER_ESCALATION_ENCOUNTER_WEAPON_POINT:
//		break;
//	case HUD_EVENT_PLAYER_BOSS_COMBAT_WEAPON_POINT:
//		break;
//	case HUD_EVENT_PLAYER_BOSS_COMBAT_COMPLETE:
//		break;
//	case HUD_EVENT_PLAYER_KEYCARD_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_REMOVE_KEYCARD:
//		break;
//	case HUD_EVENT_PLAYER_ACTIVATE_SENTINEL_ARMOR:
//		break;
//	case HUD_EVENT_PLAYER_DEACTIVATE_SENTINEL_ARMOR:
//		break;
//	case HUD_EVENT_PLAYER_SET_EXTRA_LIVES:
//		break;
//	case HUD_EVENT_PLAYER_ENABLE_INFINITE_EXTRA_LIVES:
//		break;
//	case HUD_EVENT_PLAYER_DISABLE_INFINITE_EXTRA_LIVES:
//		break;
//	case HUD_EVENT_PLAYER_EXTRA_LIFE_ACTIVATED:
//		break;
//	case HUD_EVENT_PLAYER_EXTRA_LIFE_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_CHEAT_CODE_ACQUIRED:
//		break;
//	case HUD_EVENT_PLAYER_CHAINSAW_INIT:
//		break;
//	case HUD_EVENT_PLAYER_CHAINSAW_REMOVED:
//		break;
//	case HUD_EVENT_PLAYER_CHAINSAW_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_CHAINSAW_RECHARGE:
//		break;
//	case HUD_EVENT_PLAYER_HAMMER_INIT:
//		break;
//	case HUD_EVENT_PLAYER_HAMMER_REMOVED:
//		break;
//	case HUD_EVENT_PLAYER_HAMMER_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_HAMMER_RECHARGE:
//		break;
//	case HUD_EVENT_PLAYER_HAMMER_SUPERCHARGE:
//		break;
//	case HUD_EVENT_PLAYER_CRUCIBLE_FAIL:
//		break;
//	case HUD_EVENT_PLAYER_NO_WEAPON_MOD:
//		break;
//	case HUD_EVENT_PLAYER_BFG_INIT:
//		break;
//	case HUD_EVENT_PLAYER_BFG_REMOVED:
//		break;
//	case HUD_EVENT_PLAYER_CRUCIBLE_UPDATE_INVENTORY:
//		break;
//	case HUD_EVENT_PLAYER_CRUCIBLE_UPDATE_CHARGE:
//		break;
//	case HUD_EVENT_PLAYER_ACQUIRE_RAD_SHIELD:
//		break;
//	case HUD_EVENT_PLAYER_ACTIVATE_RAD_SHIELD:
//		break;
//	case HUD_EVENT_PLAYER_DEACTIVATE_RAD_SHIELD:
//		break;
//	case HUD_EVENT_PLAYER_RAD_SHIELD_CHANGE:
//		break;
//	case HUD_EVENT_PLAYER_RAD_SHIELD_UPGRADE:
//		break;
//	case HUD_EVENT_PLAYER_ACQUIRE_OXYGEN:
//		break;
//	case HUD_EVENT_PLAYER_ACTIVATE_OXYGEN:
//		break;
//	case HUD_EVENT_PLAYER_DEACTIVATE_OXYGEN:
//		break;
//	case HUD_EVENT_PLAYER_OXYGEN_CHANGE:
//		break;
//	case HUD_EVENT_PLAYER_OXYGEN_UPGRADE:
//		break;
//	case HUD_EVENT_PLAYER_HIDDEN:
//		//logInfo("HUD_EVENT_PLAYER_HIDDEN triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_OPEN_DOSSIER:
//		//logInfo("HUD_EVENT_OPEN_DOSSIER triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_UPDATE_DOSSIER:
//		break;
//	case HUD_EVENT_DOSSIER_WEAPON_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_MOD_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_UPGRADE_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_WEAPON_WHEEL_SIZE_AND_ORDER_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_RUNE_SLOT:
//		break;
//	case HUD_EVENT_DOSSIER_RUNE_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_SUIT_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_CELL_ROUTING_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_CODEX_INITIALIZE:
//		break;
//	case HUD_EVENT_DOSSIER_MAP_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_MAP_CHALLENGE_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_MAP_PROGRESSION_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_MISSION_CHALLENGES_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_WEEKLY_CHALLENGES_UPDATE:
//		break;
//	case HUD_EVENT_DOSSIER_WEAPON_MASTERY_CHALLENGE_UPDATE:
//		break;
//	case HUD_EVENT_RUNE_UPDATE_AMMO_BOOST:
//		break;
//	case HUD_SONIC_BOOST_HELD:
//		break;
//	case HUD_EVENT_RAD_SHIELD:
//		break;
//	case HUD_EVENT_JET_PACK:
//		break;
//	case HUD_EVENT_INVASION_STATUS_UPDATE:
//		break;
//	case HUD_EVENT_INVASION_COOLDOWN:
//		break;
//	case HUD_EVENT_INVASION_FLASH_WAITING:
//		break;
//	case HUD_EVENT_DEMON_ABILITY_BUTTON_HOLD:
//		break;
//	case HUD_EVENT_DEBUG_ELEMENT:
//		break;
//	case HUD_EVENT_DEBUG_NOTIFICATION:
//		break;
//	case HUD_EVENT_DEMONPLAYER_SPAWNED:
//		break;
//	case HUD_EVENT_DEMONPLAYER_HEALTHCHANGE:
//		break;
//	case HUD_EVENT_DEMONPLAYER_HEALTH_UPGRADED:
//		break;
//	case HUD_EVENT_DEMONPLAYER_HEALTH_ABSOLUTE:
//		break;
//	case HUD_EVENT_DEMONPLAYER_CARDWHEEL_OPEN:
//		break;
//	case HUD_EVENT_DEMONPLAYER_CARDWHEEL_CLOSE:
//		break;
//	case HUD_EVENT_BOSS_HEALTH_BAR_SHOW:
//		break;
//	case HUD_EVENT_BOSS_HEALTH_BAR_HIDE:
//		break;
//	case HUD_EVENT_SLOW_MO_TIMER:
//		break;
//	case HUD_EVENT_BLOOD_PUNCH_UPDATE:
//		//logInfo("HUD_EVENT_BLOOD_PUNCH_UPDATE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_RUNE_UPDATE_EQUIPPED:
//		break;
//	case HUD_EVENT_RUNE_UPDATE_USE_COUNT:
//		break;
//	case HUD_EVENT_RUNE_UPDATE_PULSE:
//		break;
//	case HUD_EVENT_RUNE_UPDATE_TIMER:
//		break;
//	case HUD_EVENT_RUNE_UPDATE_CHARGE_PERCENT:
//		break;
//	case HUD_EVENT_DEMON_BOUNTY_CREATED:
//		break;
//	case HUD_EVENT_DEMON_BOUNTY_ACTIVE:
//		break;
//	case HUD_EVENT_DEMON_CARD_UPDATE:
//		break;
//	case HUD_EVENT_DEMON_CARD_DECK_UPDATE:
//		break;
//	case HUD_EVENT_POI_UPDATE:
//		break;
//	case HUD_EVENT_POI_FLOURISH:
//		break;
//	case HUD_EVENT_POI_FADE:
//		break;
//	case HUD_EVENT_POI_COMPASS_POSITION_UPDATE:
//		break;
//	case HUD_EVENT_LOCKON_UPDATE:
//		//logInfo("HUD_EVENT_LOCKON_UPDATE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_MODBOT_UPDATE:
//		break;
//	case HUD_EVENT_MODBOT_WEAPON_UPDATE:
//		break;
//	case HUD_EVENT_MODBOT_MOD_UPDATE:
//		break;
//	case HUD_EVENT_MODBOT_CHOOSE:
//		break;
//	case HUD_EVENT_MODBOT_CANCEL:
//		break;
//	case HUD_EVENT_DEBUG_METER:
//		break;
//	case HUD_EVENT_POWERUP_METER:
//		break;
//	case HUD_EVENT_POWERUP_EXTENSION:
//		break;
//	case HUD_EVENT_POWERUP_REMOVED:
//		break;
//	case HUD_EVENT_RUNE_TRIAL_UPDATE:
//		break;
//	case HUD_EVENT_RUNE_TRIAL_START:
//		break;
//	case HUD_EVENT_RUNE_TRIAL_CANCEL:
//		break;
//	case HUD_EVENT_RUNE_TRIAL_CHALLENGE_UPDATE:
//		break;
//	case HUD_EVENT_RUNE_INTERACT_RUNE_UPDATE:
//		break;
//	case HUD_EVENT_RUNE_INTERACT_CHOOSE:
//		break;
//	case HUD_EVENT_RUNE_INTERACT_CANCEL:
//		break;
//	case HUD_EVENT_ARGENT_UPGRADES_UPDATE:
//		break;
//	case HUD_EVENT_ARGENT_WEB_LINK_UPDATE:
//		break;
//	case HUD_EVENT_ROUND_SCORE:
//		break;
//	case HUD_EVENT_PVP_MATCH_UPDATE:
//		break;
//	case HUD_EVENT_TEAM_SUPER:
//		break;
//	case HUD_EVENT_DAMAGE_TO_PLAYER:
//		break;
//	case HUD_EVENT_DAMAGE_TO_ENEMY:
//		break;
//	case HUD_EVENT_UPDATE_DAMAGE_TO_ENEMY:
//		break;
//	case HUD_EVENT_CHARACTER_STATUS_EVENT:
//		break;
//	case HUD_EVENT_PVP_ROUND_UPGRADE_CHOSEN:
//		break;
//	case HUD_EVENT_PVP_SHOW_ROUND_UPGRADES_SCREEN:
//		break;
//	case HUD_EVENT_INVASION_MATCH_UPDATE:
//		break;
//	case HUD_EVENT_INVASION_SHOW_INTRO:
//		break;
//	case HUD_EVENT_INVASION_MENU_DEMON_SELECT_UPDATE:
//		break;
//	case HUD_EVENT_DEBUG_INVASION_MENU_DEMON_SELECT:
//		break;
//	case HUD_EVENT_INVASION_SHOW_OUTRO_SCREEN:
//		break;
//	case HUD_EVENT_INVASION_END:
//		break;
//	case HUD_EVENT_SUBTITLE_ADDED_BY_TEXT:
//		break;
//	case HUD_EVENT_SUBTITLE_ADDED_BY_SOUND:
//		break;
//	case HUD_EVENT_SUBTITLE_ADDED_BY_VO:
//		break;
//	case HUD_EVENT_SUBTITLE_REMOVED_BY_SOURCE:
//		break;
//	case HUD_EVENT_SUBTITLE_REMOVED_BY_SOUND:
//		break;
//	case HUD_EVENT_SPEAKER_SHOW:
//		break;
//	case HUD_EVENT_SPEAKER_HIDE:
//		break;
//	case HUD_EVENT_DEMON_INVASION_STATE_UPDATE:
//		break;
//	case HUD_EVENT_DEMON_INVASION_DISGUISE_MOVE:
//		break;
//	case HUD_EVENT_SCORE_UPDATE:
//		break;
//	case HUD_EVENT_DEMON_SHOW_END_OF_INVASION_SCREEN:
//		break;
//	case HUD_EVENT_CAMPAIGN_MAP_START:
//		//logInfo("HUD_EVENT_CAMPAIGN_MAP_START triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_CAMPAIGN_MAP_PLAYABLE:
//		//logInfo("HUD_EVENT_CAMPAIGN_MAP_PLAYABLE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PVP_LOBBY_START:
//		break;
//	case HUD_EVENT_PVP_START_INTRO:
//		break;
//	case HUD_EVENT_PVP_VERSUS_VIDEO:
//		break;
//	case HUD_EVENT_PVP_PLAYERCARD_ANIMATION:
//		break;
//	case HUD_EVENT_PVP_MATCH_START:
//		break;
//	case HUD_EVENT_PVP_DEATH:
//		break;
//	case HUD_EVENT_PVP_RESPAWN:
//		break;
//	case HUD_EVENT_PVP_RESPAWNED_MIDMATCH:
//		break;
//	case HUD_EVENT_PVP_ROUND_END:
//		break;
//	case HUD_EVENT_PVP_MATCH_END_RESULT:
//		break;
//	case HUD_EVENT_PVP_MATCH_END_OUTRO:
//		break;
//	case HUD_EVENT_PVP_MATCH_END_REWARDS:
//		break;
//	case HUD_EVENT_PVP_MATCH_END_SEASON_REFRESH:
//		break;
//	case HUD_EVENT_PVP_VICTORY_ANIMATION:
//		break;
//	case HUD_EVENT_PVP_REWARDS_ANIMATION:
//		break;
//	case HUD_EVENT_PLAY_BOOT_SEQUENCE:
//		//logInfo("HUD_EVENT_PLAY_BOOT_SEQUENCE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_SHOW_TUTORIAL:
//		break;
//	case HUD_EVENT_SHOW_TUTORIAL_OBJECTIVES_ONLY:
//		break;
//	case HUD_EVENT_SHOW_TUTORIAL_CINEMATIC:
//		break;
//	case HUD_EVENT_CLEAR_ACTIVE_OBJECTIVES:
//		break;
//	case HUD_EVENT_UPDATE_UI_WALKTHROUGH:
//		//logInfo("HUD_EVENT_UPDATE_UI_WALKTHROUGH triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_START_CINEMATIC:
//		//logInfo("HUD_EVENT_START_CINEMATIC triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_STOP_CINEMATIC:
//		//logInfo("HUD_EVENT_STOP_CINEMATIC triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_SECRET_HINT_START:
//		break;
//	case HUD_EVENT_SECRET_HINT_STOP:
//		break;
//	case HUD_EVENT_OPEN_END_OF_LEVEL:
//		//logInfo("HUD_EVENT_OPEN_END_OF_LEVEL triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_MASTER_LEVEL_COMPLETE:
//		break;
//	case HUD_EVENT_MASTER_LEVEL_EARNED_REWARD:
//		break;
//	case HUD_EVENT_SHOW_INGAME_REWARDS:
//		break;
//	case HUD_EVENT_SHOW_ESCALATION_REWARDS:
//		break;
//	case HUD_EVENT_SHOW_ESCALATION_PERKS:
//		break;
//	case HUD_EVENT_ESCALATION_SUMMARY:
//		break;
//	case HUD_EVENT_SHOW_CAMPAIGN_REWARDS:
//		break;
//	case HUD_EVENT_CAMPAIGN_REWARDS_SKIPPED:
//		break;
//	case HUD_EVENT_CAMPAIGN_REWARDS_COMPLETE:
//		break;
//	case HUD_EVENT_CURRENCY_CONFIRMATION_CURRENCY_UPDATE:
//		logInfo("HUD_EVENT_CURRENCY_CONFIRMATION_CURRENCY_UPDATE");
//		break;
//	case HUD_EVENT_CURRENCY_CONFIRM:
//		logInfo("HUD_EVENT_CURRENCY_CONFIRM");
//		break;
//	case HUD_EVENT_CURRENCY_CANCEL:
//		logInfo("HUD_EVENT_CURRENCY_CANCEL");
//		break;
//	case HUD_EVENT_PLAYER_MISSION_CHALLENGE_TIMER_END:
//		break;
//	case HUD_EVENT_PIN_CHALLENGE:
//		//logInfo("HUD_EVENT_PIN_CHALLENGE triggered");
//		break;
//	case HUD_EVENT_UNPIN_CHALLENGE:
//		//logInfo("HUD_EVENT_UNPIN_CHALLENGE triggered");
//		break;
//	case HUD_EVENT_PINNED_CHALLENGES_UPDATE:
//		break;
//	case HUD_EVENT_RETURN_TO_LEVEL:
//		logInfo("HUD_EVENT_RETURN_TO_LEVEL triggered");
//		break;
//	case HUD_EVENT_UPDATE_USER_CURRENCIES:
//		break;
//	case HUD_EVENT_COLLECTIBLE_SELECTION_CHANGE:
//		break;
//	case HUD_EVENT_COLLECTIBLE_EXTERNAL_CHANGE:
//		break;
//	case HUD_EVENT_UPDATE_AVAILABLE_UPGRADES:
//		break;
//	case HUD_EVENT_UPDATE_JUKEBOX:
//		break;
//	case HUD_EVENT_UPDATE_RESPEC_STATION:
//		break;
//	case HUD_EVENT_UPDATE_CURRENCY_EXCHANGE:
//		break;
//	case HUD_EVENT_SPECTATE_BEGIN:
//		logInfo("HUD_EVENT_SPECTATE_BEGIN triggered");
//		break;
//	case HUD_EVENT_SPECTATOR_UPDATE:
//		break;
//	case HUD_EVENT_SPECTATE_END:
//		logInfo("HUD_EVENT_SPECTATE_END triggered");
//		break;
//	case HUD_EVENT_INNATE_DEMON_ABILITY_UPDATE:
//		break;
//	case HUD_EVENT_INVASION_DEMON_ABILITY_UPDATE:
//		break;
//	case HUD_EVENT_DEMON_DASH_INIT:
//		break;
//	case HUD_EVENT_DEMON_DASH_UPDATE:
//		break;
//	case HUD_EVENT_PLAYER_NOTIFICATION_SKYBOX_UNLOCK_EVENT:
//		break;
//	case HUD_EVENT_PLAY_VIDEO:
//		logInfo("HUD_EVENT_PLAY_VIDEO triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_STOP_VIDEO:
//		logInfo("HUD_EVENT_STOP_VIDEO triggered");
//		break;
//	case HUD_EVENT_TUTORIAL_DAMAGE_EVENT:
//		break;
//	case HUD_EVENT_COLLECTIBLE_SINGLE_TOY_VIEW:
//		break;
//	case HUD_EVENT_COLLECTIBLE_SINGLE_TOY_REAL_VIEW:
//		break;
//	case HUD_EVENT_COLLECTIBLE_MULTI_TOY_VIEW:
//		break;
//	case HUD_EVENT_COLLECTIBLE_MULTI_TOY_REAL_VIEW:
//		break;
//	case HUD_EVENT_COLLECTIBLE_WEAPON_VIEW:
//		break;
//	case HUD_EVENT_COLLECTIBLE_RECORD_VIEW:
//		break;
//	case HUD_EVENT_COLLECTIBLE_RECORD_PLAY:
//		break;
//	case HUD_EVENT_COLLECTIBLE_RECORD_PAUSE:
//		break;
//	case HUD_EVENT_PLAYER_KEY_BINDS_CHANGED:
//		//logInfo("HUD_EVENT_PLAYER_KEY_BINDS_CHANGED triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_CRYO_GRENADE_ADDED:
//		//logInfo("HUD_EVENT_CRYO_GRENADE_ADDED triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_COLLECTIBLE_WEAPON_MOD_SWAP:
//		break;
//	case HUD_EVENT_PVP_SHOW_PLAYER_DAMAGE_REPORT:
//		break;
//	case HUD_EVENT_PVP_HIDE_PLAYER_DAMAGE_REPORT:
//		break;
//	case HUD_EVENT_NETWORK_STATUS_HIGH_LATENCY:
//		break;
//	case HUD_EVENT_NETWORK_STATUS_LATENCY_VARIATION:
//		break;
//	case HUD_EVENT_NETWORK_STATUS_PACKET_LOSS:
//		break;
//	case HUD_EVENT_INVASION_STORYTIME_CUTSCENE_START:
//		break;
//	case HUD_EVENT_SHOW_TEXT_CRAWL:
//		break;
//	case HUD_EVENT_SHOW_OUTRO_TEXT_CRAWL:
//		break;
//	case HUD_EVENT_HIDE_TEXT_CRAWL:
//		break;
//	case HUD_EVENT_TEXT_CRAWL:
//		break;
//	case HUD_EVENT_TEXT_CRAWL_END:
//		break;
//	case HUD_EVENT_ENABLE_PAUSE:
//		//logInfo("HUD_EVENT_ENABLE_PAUSE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_DISABLE_PAUSE:
//		//logInfo("HUD_EVENT_DISABLE_PAUSE triggered eventData_a3: %llx", eventData_a3);
//		break;
//	case HUD_EVENT_PLAYER_MODS_DISABLED:
//		break;
//	case HUD_EVENT_MORTAR_SOUND_UPDATE:
//		break;
//	case HUD_EVENT_BOSS_HEALTH_GAIN:
//		break;
//	case HUD_EVENT_ROLL_CREDITS:
//		//logInfo("HUD_EVENT_ROLL_CREDITS triggered");
//		break;
//	case HUD_EVENT_CREDITS_WATCHED:
//		break;
//	case HUD_EVENT_CREDITS_SKIPPED:
//		break;
//	case HUD_EVENT_MENU_ACTIVATED:
//		break;
//	case HUD_EVENT_HORDE_GAIN_SCORE:
//		break;
//	case HUD_EVENT_HORDE_SET_SCORE:
//		break;
//	case HUD_EVENT_HORDE_SET_PREVIOUS_BEST:
//		break;
//	case HUD_EVENT_HORDE_SCORE_MULTIPLIER_START:
//		break;
//	case HUD_EVENT_HORDE_SCORE_MULTIPLIER_END:
//		break;
//	case HUD_EVENT_HORDE_LEVEL_COMPLETE:
//		//logInfo("HUD_EVENT_HORDE_LEVEL_COMPLETE triggered");
//		break;
//	case HUD_EVENT_HORDE_ROUND_START:
//		//logInfo("HUD_EVENT_HORDE_ROUND_START triggered");
//		break;
//	case HUD_EVENT_HORDE_ROUND_END:
//		//logInfo("HUD_EVENT_HORDE_ROUND_END triggered");
//		break;
//	case HUD_EVENT_HORDE_WAVE_START:
//		break;
//	case HUD_EVENT_HORDE_WAVE_END:
//		break;
//	case HUD_EVENT_HORDE_BLITZ_SCORE:
//		break;
//	case HUD_EVENT_HORDE_BLITZ_START:
//		break;
//	case HUD_EVENT_HORDE_BLITZ_END:
//		break;
//	case HUD_EVENT_HORDE_BLITZ_TARGET_REACHED:
//		break;
//	case HUD_EVENT_HORDE_BOUNTY_TARGET_REACHED:
//		break;
//	case HUD_EVENT_HORDE_COIN_TARGET_REACHED:
//		break;
//	case HUD_EVENT_HORDE_GET_COIN:
//		break;
//	case HUD_EVENT_HORDE_COIN_ROUND_START:
//		break;
//	case HUD_EVENT_HORDE_COIN_ROUND_END:
//		break;
//	case HUD_EVENT_HORDE_MATCH_COMPLETE:
//		break;
//	case HUD_EVENT_HORDE_BOUNTY_ROUND_START:
//		break;
//	case HUD_EVENT_HORDE_BOUNTY_ROUND_END:
//		break;
//	case HUD_EVENT_HORDE_BOUNTY_ROUND_KILL:
//		break;
//	case HUD_EVENT_HORDE_TOTAL_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_BLITZ_ROUND_SETUP:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_START:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_END_AND_HIDE:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_END_NO_HIDE:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_HIDE:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_PULSE:
//		break;
//	case HUD_EVENT_HORDE_STAGED_TIMER_STAGE_CHANGE:
//		break;
//	case HUD_EVENT_HORDE_TIMELINE_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_TIMELINE_ARENA_WAVE_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_ARENA_WAVE_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_ROUND_TRANSITION:
//		break;
//	case HUD_EVENT_HORDE_SHOW_HORDE_SUMMARY:
//		break;
//	case HUD_EVENT_HORDE_CLOSE_HORDE_SUMMARY:
//		break;
//	case HUD_EVENT_HORDE_VICTORY_SHOW:
//		break;
//	case HUD_EVENT_HORDE_VICTORY_HIDE:
//		break;
//	case HUD_EVENT_HORDE_SUMMARY_TIMELINE_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_SUMMARY_ARENA_WAVE_UPDATE:
//		break;
//	case HUD_EVENT_HORDE_MEDAL_UPDATE:
//		break;
//	case HUD_EVENT_POWERUP_CHANGED:
//		break;
//	case HUD_EVENT_TEXT_CHAT_INIT:
//		break;
//	case HUD_EVENT_TEXT_CHAT_MARK_READ:
//		break;
//	case HUD_EVENT_TEXT_CHAT_MARK_UNREAD:
//		break;
//	case HUD_EVENT_MAX:
//		break;
//	default:
//		break;
//	}
//}
