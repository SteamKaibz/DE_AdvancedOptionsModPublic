#include "fastCvarManager.h"



bool fastCvarManager::cacheCriticalCvars()
{

	m_reticleModeCvarPtr = (idCVar*)idCvarManager::getCvarPtr("g_reticleMode");
	if (MemHelper::isBadReadPtr(m_reticleModeCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_reticleModeCvarPtr");
		m_reticleModeCvarPtr = nullptr;
		return false;
	}	

	m_enableGameTimeScalingCvarPtr = (idCVar*)idCvarManager::getCvarPtr("g_enableGameTimeScaling");
	if (MemHelper::isBadReadPtr(m_enableGameTimeScalingCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_enableGameTimeScalingCvarPtr");
		m_enableGameTimeScalingCvarPtr = nullptr;
		return false;
	}

	m_in_mouseCvarPtr = (idCVar*)idCvarManager::getCvarPtr("in_mouse");
	if (MemHelper::isBadReadPtr(m_in_mouseCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_in_mouseCvarPtr");
		m_in_mouseCvarPtr = nullptr;
		return false;
	}


	m_swf_colorProfileCvarPtr = (idCVar*)idCvarManager::getCvarPtr("swf_colorProfile");
	if (MemHelper::isBadReadPtr(m_swf_colorProfileCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_swf_colorProfileCvarPtr");
		m_swf_colorProfileCvarPtr = nullptr;
		return false;	
	}


	m_g_setting_hud_showCvarPtr = (idCVar*)idCvarManager::getCvarPtr("g_setting_hud_show");
	if (MemHelper::isBadReadPtr(m_g_setting_hud_showCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_g_setting_hud_showCvarPtr");
		m_g_setting_hud_showCvarPtr = nullptr;
		return false;
	}

	m_g_setting_equipment_infoCvarPtr = (idCVar*)idCvarManager::getCvarPtr("g_setting_equipment_info");
	if (MemHelper::isBadReadPtr(m_g_setting_equipment_infoCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_g_setting_equipment_infoCvarPtr");
		m_g_setting_equipment_infoCvarPtr = nullptr;
		return false;
	}

	m_r_windowWidthCvarPtr = (idCVar*)idCvarManager::getCvarPtr("r_windowWidth");
	if (MemHelper::isBadReadPtr(m_r_windowWidthCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_r_windowWidthCvarPtr");
		m_r_windowWidthCvarPtr = nullptr;
		return false;
	}

	m_r_windowHeightCvarPtr = (idCVar*)idCvarManager::getCvarPtr("r_windowHeight");
	if(MemHelper::isBadReadPtr(m_r_windowHeightCvarPtr)){
		logErr("cacheCriticalCvars: failed to find m_r_windowHeightCvarPtr");
		m_r_windowHeightCvarPtr = nullptr;
		return false;
	}

	m_sys_langCvarPtr = (idCVar*)idCvarManager::getCvarPtr("sys_lang");
	if (MemHelper::isBadReadPtr(m_sys_langCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_sys_langCvarPtr");
		m_sys_langCvarPtr = nullptr;
		return false;
	}

	m_r_antialiasingCvarPtr = (idCVar*)idCvarManager::getCvarPtr("r_antialiasing");
	if (MemHelper::isBadReadPtr(m_r_antialiasingCvarPtr)) {
		logErr("cacheCriticalCvars: failed to find m_r_antialiasingCvarPtr");
		m_r_antialiasingCvarPtr = nullptr;
		return false;
	}



	logInfo("cacheCriticalCvars: succes caching critical cvars");
	return true;
}


UI_ReticleMode fastCvarManager::getReticleMode() {

	if (!m_reticleModeCvarPtr) {
		logErr("getReticleMode m_reticleModeCvarPtr is nullptr");
		return UI_ReticleMode::Unknown;
	}
	return (UI_ReticleMode)m_reticleModeCvarPtr->data->valueInteger;
}

bool fastCvarManager::isGameTimeScalingEnabled() {

	if (!m_enableGameTimeScalingCvarPtr) {
		logErr("isGameTimeScalingEnabled m_enableGameTimeScalingCvarPtr is nullptr");
		return false;
	}
	return (bool)m_enableGameTimeScalingCvarPtr->data->valueInteger;
}

bool fastCvarManager::isMouseInputEnabled() {

	if (!m_in_mouseCvarPtr) {
		logErr("isMouseInputEnabled m_in_mouseCvarPtr is nullptr");
		return false;
	}
	return (bool)m_in_mouseCvarPtr->data->valueInteger;
}

int fastCvarManager::getColorProfileIndex() {
	if (!m_swf_colorProfileCvarPtr) {
		logErr("getColorProfileIndex m_swf_colorProfileCvarPtr is nullptr");
		return -1;
	}
	return m_swf_colorProfileCvarPtr->data->valueInteger;
}


bool fastCvarManager::getIsShowHudEnabled() {
	if (!m_g_setting_hud_showCvarPtr) {
		logErr("getIsShowHudEnabled m_g_setting_hud_showCvarPtr is nullptr");
		return false;
	}
	return (bool)m_g_setting_hud_showCvarPtr->data->valueInteger;
}

bool fastCvarManager::getIsEquipmentInfoEnabled() {
	if (!m_g_setting_equipment_infoCvarPtr) {
		logErr("getIsEquipmentInfoEnabled: m_g_setting_equipment_infoCvarPtr is nullptr");
		return false;
	}
	return (bool)m_g_setting_equipment_infoCvarPtr->data->valueInteger;
}


int fastCvarManager::getWindowWidthInt() {
	if (!m_r_windowWidthCvarPtr) {
		logErr("getWindowWidthInt: m_r_windowWidthCvarPtr is nullptr");
		return 0;
	}

	return m_r_windowWidthCvarPtr->data->valueInteger;
}

int fastCvarManager::getWindowHeightInt() {
	if (!m_r_windowHeightCvarPtr) {
		logErr("getWindowHeightInt: m_r_windowHeightCvarPtr is nullptr");
		return 0;
	}
	return m_r_windowHeightCvarPtr->data->valueInteger;
}


std::string fastCvarManager::getLang() {
	if (!m_sys_langCvarPtr) {
		logErr("getLang: m_sys_langCvarPtr is nullptr");
		return std::string();
	}
	return m_sys_langCvarPtr->data->valueString;
}


antialiasingLevel fastCvarManager::getCurAntiAliasLevel() {
	if (!m_r_antialiasingCvarPtr) {
		logErr("getCurAntiAliasLevel: m_r_antialiasingCvarPtr is nullptr");
		return antialiasingLevel::UNKNOWN;
	}

	return (antialiasingLevel)m_r_antialiasingCvarPtr->data->valueInteger;
}




std::string fastCvarManager::getDbgStrFromImgui() {

	std::string result = "fastCvarManager DBG: \n";

	/*result += "getScreenWidth: ";
	result += std::to_string(idRenderModelGuiManager::getScreenWidth());
	result += " getScreenHeight: ";
	result += std::to_string(idRenderModelGuiManager::getScreenHeight());*/
	result += "cvar width: ";
	result += std::to_string(fastCvarManager::getWindowWidthInt());
	result += " cvar height: ";
	result += std::to_string(fastCvarManager::getWindowHeightInt());

	return result;
}


