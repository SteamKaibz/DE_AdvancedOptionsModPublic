#pragma once

#include <vector>
#include <string>
#include <limits>
#include "../Config/Config.h"

#include "../DE/CommonDE.h"
#include "../DE/idColor.h"
#include "../DE/MemHelper.h"

/// <summary>
/// overrides huds elements like reticule, equipement icons...
/// </summary>
class SwfHud {


//? update 18/10/23: i think it's safe to say we don't need this anymore. Let's keep it anyway for doc.
private:

	float m_hudEquipmentMiniBarShape_Y = std::numeric_limits<float>::lowest();
	float m_hudEquipmentArrowShape_Y = std::numeric_limits<float>::lowest();

	std::string m_swfReticuleName = "swf/hud/hud_reticle.swf";
	std::string m_swfWeaponinfoName = "swf/hud/hud_weaponinfo.swf";
	std::string m_swfRaceCarHudinfoName = "swf/hud/hud_abilityindicators_singlestack.swf";
	std::string m_swfBloodPunchName = "swf/hud/hud_bloodpunch.swf";
	std::string m_swfHealthInfohName = "swf/hud/hud_healthinfo.swf";
	std::string m_swfScoreInfoName = "swf/hud/hud_score.swf"; //! bar top right
	std::string m_swfRuneInfoName = "swf/hud/hud_runeinfo.swf"; 
	std::string m_swfDashInfoName = "swf/hud/hud_dash.swf"; 
	std::string m_swfCompassName = "swf/hud/hud_compass.swf"; 
	//! see SwfDebug.h for more hud elements names

	//const float m_epsilon = 0.001f;
	const float epsilon = 0.001f;

	idColor m_equipmentArrowColor = colorInvisible;
	idColor m_bloodPunchIconColor = colorOrange;

public:



	void OverrideBloodPunchIconColor(__int64 idDeclSWFptr, __int64 arg3, __int64 arg4Color, float* arg6) {
		logDebug("OverrideBloodPunchIconColor");

		if (!isHudSwf(idDeclSWFptr, m_swfBloodPunchName)) return;
		setShapeColor(arg4Color, m_bloodPunchIconColor);
	}

	//todo this should be linked to gamedata in the way that our new event system class, in fact making this class static could make sens as the event class would modify the value of m_equipmentArrowColor and that's it for the nade status.
	void OverideEquipmentArrowColor(__int64 idDeclSWFptr, __int64 arg3, __int64 arg4Color, float* arg6) {		
		logDebug("OverideEquipmentArrowColor");

		if (!isHudSwf(idDeclSWFptr, m_swfWeaponinfoName)) return;
		if ((std::abs(*(float*)(arg3)- -80.00) < epsilon) && (std::abs(*(float*)(arg3 + 0xC) - 80.00) < epsilon) && (std::abs(*(float*)(arg3 + 0x10) - -80.00) < epsilon) && (std::abs(*(float*)(arg3 + 0x1C) - 80.00) < epsilon)) {
			/*logInfo("changeEquipmentArrowColor: trigger 1");
			logInfo("f_arg5: %f f_arg5+4: %f f_arg5+8: %f f_arg5+C: %f f_arg5+10: %f f_arg5+14: %f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
			logInfo("changeEquipmentArrowColor: f_arg6: %f f_arg6+4: %f f_arg6+8: %f ", *(float*)arg6, *(float*)(arg6 + 4), *(float*)(arg6 + 8));*/
			if ((std::abs(*(float*)(arg6)-0.00) < epsilon) && (std::abs(*(float*)(arg6 + 0x8) - 0.947308) < epsilon)) {
				//if ((std::abs(*(float*)(arg6) - 0.00) < epsilon) && (std::abs(*(float*)(arg6 + 0x4) - 0.00) < epsilon) && (std::abs(*(float*)(arg6 + 0x8)  - 0.95) < epsilon)) {

				//logInfo("changeEquipmentArrowColor: trigger 2");

				//setArg4Color(arg4Color, 0, 0, 1, 0);
				setShapeColor(arg4Color, m_equipmentArrowColor);
			}
		}
	}

	bool isHealthHud(__int64 addr) {
		logDebug("isHealthHud");

		return isHudSwf(addr, m_swfHealthInfohName);
	}

	bool isBloodPunchHud(__int64 addr) {
		logDebug("isBloodPunchHud");

		return isHudSwf(addr, m_swfBloodPunchName);
	}

	bool isEquipmentHud(__int64 addr) {
		logDebug("isEquipmentHud");

		return isHudSwf(addr, m_swfWeaponinfoName);
	}


	bool isHudSwf(__int64 addr, std::string hudSwfName) {
		logDebug("isHudSwf");

		if (addr == 0) return false;
		addr = *(__int64*)addr;
		if (addr == 0) return false;
		addr += 8;
		if (addr == 0) return false;
		addr = *(__int64*)addr;
		if (addr == 0) return false;
		std::string swfNameStr = (const char*)addr;
		//if (swfNameStr != "swf/hud/hud_reticle.swf") {
		if (swfNameStr == hudSwfName) {
			return true;
		}
		return false;
	}


	/*void setShapeInvisible(__int64 arg4) {
		*(float*)arg4 = 1;
		*(float*)(arg4 + 4) = 1;
		*(float*)(arg4 + 8) = 1;
		*(float*)(arg4 + 0xC) = 0;
	}*/

	void setShapeColor(__int64 arg4, idColor color) {
		logDebug("setShapeColor");

		*(float*)arg4 = color.r;
		*(float*)(arg4 + 4) = color.g;
		*(float*)(arg4 + 8) = color.b;
		*(float*)(arg4 + 0xC) = color.a;
	}

	//void setArg4Color(__int64 arg4, float r, float g, float b, float a) {
	//	//logInfo("setArg4Color called seting rgba: %.2f,  %.2f,  %.2f,  %.2f,", r, g, b, a);

	//	*(float*)arg4 = r;
	//	*(float*)(arg4 + 4) = g;
	//	*(float*)(arg4 + 8) = b;
	//	*(float*)(arg4 + 0xC) = a;
	//}


	void logSwfHudElementInfos(__int64 idDeclSWFptr, __int64 arg2, __int64 arg3, __int64 arg4, float* arg5, 
float* arg6, std::string hudElementSwfName) {
		logDebug("logSwfHudElementInfos");

		if (isHudSwf(idDeclSWFptr, hudElementSwfName)) {
			//! thos address do not change for each element of the reticule
			__int64  idDeclSWFAddr = *(__int64*)idDeclSWFptr;
			__int64  idSWFResourceAddr = *(__int64*)(idDeclSWFptr + 8);
			__int64  idSWFScriptObjectAddr = *(__int64*)(idDeclSWFptr + 0x10);
			__int64  idSWFSpriteInstanceAddr = *(__int64*)(idDeclSWFptr + 0x18);
			__int64  idMaterial2Addr = *(__int64*)(idDeclSWFptr + 0x520);

			logInfo("logSwfHudElementInfos: idDeclSWFptr addr: %p, %llx, %llx, %llx, %llx, %llx,", (void*)idDeclSWFptr, idDeclSWFAddr, idSWFResourceAddr, idSWFScriptObjectAddr, idSWFSpriteInstanceAddr, idMaterial2Addr);


			__int64 arg2_addr = *(__int64*)(arg2);
			if (MemHelper::isBadReadPtr((void*)arg2_addr)) {
				logErr("logSwfHudElementInfos: found bad ptr: arg2 %p", (void*)arg2_addr);
				return;
			}

			logInfo("arg2: %llx farg2_0: %f farg2_4: %f uarg2_18: %x uarg2_1C: %x ", arg2, *(float*)arg2_addr, *(float*)(arg2_addr + 4), *(unsigned int*)(arg4 + 0x18), *(unsigned int*)(arg4 + 0x1C));


			if (MemHelper::isBadReadPtr((void*)arg3)) {
				logErr("logSwfHudElementInfos: found bad ptr: arg3 %p", (void*)arg3);
				return;
			}


			logInfo("arg3: %llx f_arg3: %f, f_arg3+4: %f, f_arg3+8: %f f_arg3+C: %f f_arg3+0x10: %f, f_arg3+0x14: %f,  f_arg3+0x18: %f,  f_arg3+0x1C: %f", arg3, *(float*)arg3, *(float*)(arg3 + 4), *(float*)(arg3 + 8), *(float*)(arg3 + 0xC), *(float*)(arg3 + 0x10), *(float*)(arg3 + 0x14), *(float*)(arg3 + 0x18), *(float*)(arg3 + 0x1C));

			//logFillDraws(arg3 + 0x20);

			if (MemHelper::isBadReadPtr((void*)arg4)) {
				logErr("logSwfHudElementInfos: found bad ptr: arg4Color %p", (void*)arg4);
				return;
			}

			logInfo("(arg4Color): r: %f g: %f b: %f a: %f ", *(float*)arg4, *(float*)(arg4 + 4), *(float*)(arg4 + 8), *(float*)(arg4 + 0xC));
			//logInfo("r: %.2f g: %.2f b: %.2f a: %.2f ", *(float*)arg4Color, *(float*)(arg4Color + 4), *(float*)(arg4Color + 8), *(float*)(arg4Color + 0xC));

			if (MemHelper::isBadReadPtr((void*)arg5)) {
				logErr("logSwfHudElementInfos: found bad ptr: arg5 %p", (void*)arg5);
				return;
			}

			//logInfo("f_arg5: %.2f f_arg5+4: %.2f f_arg5+8: %.2f f_arg5+C: %.2f f_arg5+10: %.2f f_arg5+14: %.2f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
			logInfo("f_arg5: %f f_arg5+4: %f f_arg5+8: %f f_arg5+C: %f f_arg5+10: %f f_arg5+14: %f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));


			if (MemHelper::isBadReadPtr((void*)arg6)) {
				logErr("logSwfHudElementInfos: found bad ptr: arg6 %p", (void*)arg6);
				return;
			}

			logInfo("f_arg6: %f f_arg6+4: %f f_arg6+8: %f ", *(float*)arg6, *(float*)(arg6 + 4), *(float*)(arg6 + 8));
			//reticleColorInfo colorInfo;
			/*if (MemHelper::isBadReadPtr((void*)arg4Color)) {
				logErr("logHudReticleInfos: (0) found bad ptr: %p", (void*)arg4Color);
				return;
			}*/

			/*for (size_t i = 0; i < m_swfHudShapesAddrVec.size(); i++)
			{
				if (arg3 == m_swfHudShapesAddrVec[i]) return;
			}
			m_swfHudShapesAddrVec.push_back(arg3);
			logInfo("logSwfHudElementInfos: found raceHudShapesAdd: %p", (void*)arg3);*/

			/*colorInfo.r = *(float*)arg4Color;
			colorInfo.g = *(float*)(arg4Color + 4);
			colorInfo.b = *(float*)(arg4Color + 8);
			colorInfo.a = *(float*)(arg4Color + 0xC);
			logInfo("r: %.2f g: %.2f b: %.2f a: %.2f ", colorInfo.r, colorInfo.g, colorInfo.b, colorInfo.a);*/
		}
		else {
			//logWarn("aaaaaaaaaaaaaaaaaaaaaaaaaaa hudElementSwfName is: %s", hudElementSwfName.c_str());
		}
	}








};
