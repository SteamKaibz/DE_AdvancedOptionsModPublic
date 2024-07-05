//#pragma once
//#include <vector>
//#include <string>
////#include "Config.h"
////#include "MemHelper.h"
//
//#include <limits>
////#include "../DE/HudData.h"
//#include "../DE/Config.h"
//#include "../DE/MemHelper.h"
//
//
//struct reticleColorInfo {
//
//	float r;
//	float g;
//	float b;
//	float a;
//	//std::string materialNameStr = "unknown";
//};
//
//
//struct swfAddr_And_Str {
//	__int64 addr;
//	std::string name = "unknown";
//};
//
//class SwfDebug {
//
//private:
//	//std::vector<__int64> m_idDeclSWFptrsVec;
//	std::vector<swfAddr_And_Str> m_swfAddr_And_StrVec;
//
//	std::vector<__int64> m_swfHudShapesAddrVec;
//
//	std::vector<__int64> m_raceHudShapesAddrVec;
//
//	std::vector<__int64> m_idDeclHudReticleptrsVec;
//
//	std::vector<reticleColorInfo> reticleColorInfoVec;
//
//	std::vector<std::string>SwfNamesVec;
//
//	__int64 m_testMaterial = 0;
//
//	HudData hudData;
//
//	float m_hudEquipmentMiniBarShape_Y = std::numeric_limits<float>::lowest();
//	float m_hudEquipmentArrowShape_Y = std::numeric_limits<float>::lowest();
//
//
//public:
//	std::string swfReticuleName = "swf/hud/hud_reticle.swf";
//	std::string swfWeaponinfoName = "swf/hud/hud_weaponinfo.swf";
//	std::string swfRaceCarHudinfoName = "swf/hud/hud_abilityindicators_singlestack.swf";
//	std::string swfBloodPunchName = "swf/hud/hud_bloodpunch.swf";
//
//	/*
//
//22:04:45.457                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_blackbackdrop.swf idDeclSWFptr: 0000022B8631D720
//22:04:45.457                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/overlays/overlay_simple.swf idDeclSWFptr: 0000022B8630E8B0
//22:04:45.457                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/common/command_bar.swf idDeclSWFptr: 0000022B86314EE0
//22:04:45.457                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/main_menu/options_list.swf idDeclSWFptr: 0000022B86323D50
//22:04:45.457                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/common/social_bar.swf idDeclSWFptr: 0000022B86312CD0
//
//22:04:47.691                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_abilityindicators_singlestack.swf idDeclSWFptr: 0000022B87BF2C50
//22:04:47.692                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_healthinfo.swf idDeclSWFptr: 0000022B86EDF080
//22:04:47.691                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_runeinfo.swf idDeclSWFptr: 0000022B87750150
//22:04:47.691                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_score.swf idDeclSWFptr: 0000022B8775ABA0
//22:04:47.692                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_weaponinfo.swf idDeclSWFptr: 0000022B86ED0210
//22:04:47.692                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_reticle.swf idDeclSWFptr: 0000022B86ED4630
//22:04:47.693                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_dash.swf idDeclSWFptr: 0000022B86EEBCE0
//22:04:47.693                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_bloodpunch.swf idDeclSWFptr: 0000022B86EE9AD0
//22:04:47.693                 SwfDebug.h:567   INFO| log_SWF_Name: found swf name: swf/hud/hud_compass.swf idDeclSWFptr: 0000022B86F055A0
//
//
//	*/
//
//	void modifyBloodPunchHudColor(__int64 idDeclSWFptr,  __int64 arg3, __int64 arg4Color, float* arg5, float* arg6) {
//		if (!isHudSwf(idDeclSWFptr, swfBloodPunchName)) return;
//		//setArg4Color(arg4Color, 1, 1, 1, 0);
//		setArg4Color(arg4Color, 1.00000f, 0.60000f, 0.20000f, 1.0f); //orange
//	}
//
//
//	//? it seems we can only modify x...fuuuuuuck.
//	void modifyRaceCarHud(__int64 idDeclSWFptr, __int64 arg2, __int64 arg3, __int64 arg4Color, float* arg5) {
//		const float epsilon = 0.001f;
//		if (isHudSwf(idDeclSWFptr, swfRaceCarHudinfoName)) {
//
//
//			if (std::abs(*(float*)(arg4Color)-1.000000) < epsilon &&
//				std::abs(*(float*)(arg4Color + 4) - 0.473531) < epsilon &&
//				std::abs(*(float*)(arg4Color + 8) - 0.088656) < epsilon &&
//				std::abs(*(float*)(arg4Color + 0xC) - 1.000000) < epsilon) {
//
//
//				*(float*)(arg3) = -50.0f;
//				//*(float*)(arg3 ) = -150.0f; 
//				*(float*)(arg3 + 4) = -50.0f;
//				//*(float*)(arg3 + 4) = -150.0f;
//				*(float*)(arg3 + 8) = 350.0f;
//				//*(float*)(arg3 + 8) = 150.0f; 
//				*(float*)(arg3 + 0xC) = 350.0f;
//				//*(float*)(arg3 + 0xC) = 150.0f;
//
//			}
//
//
//
//			//? modifying anyhing in arg2 will result in a crash. great.
//			//*(float*)(arg2 + 0x4) = 0.2f;
//
//			//! this changes the...widht i guess of the icons
//			//*(float*)(arg5) = 5.0f;
//
//			//! this sets all the race icons to the same X position.
//			//*(float*)(arg5 + 0x4) = 700.0f; 
//
//			//! don't see no change here from -100 to 100
//			//*(float*)(arg5 + 0x8) = -100.0f;
//
//			//! don't see no change here from -200 to 200
//			//* (float*)(arg5 + 0xC) = -200.0f;
//
//			//! don't see no change
//			//* (float*)(arg5 + 0x10) = 100.0f;
//		}
//	}
//
//
//	/*
//	00:28:01.355              SwfDebug.h:522   INFO| logSwfHudElementInfos: idDeclSWFptr addr: 0000029D974966A0, 29d1357abd0, 29d4dafecc0, 29d53823120, 29cecd06c40, 29d32550a00,
//00:28:01.355              SwfDebug.h:531   INFO| farg2_0: 1418.00 farg2_4: 1.00 uarg2_18: 0 uarg2_1C: 0
//00:28:01.355              SwfDebug.h:540   INFO| arg3: 29d4fc4d9e0 f_arg3: -80.00, f_arg3+4: 0.00, f_arg3+8: 0.00 f_arg3+C: 80.00 f_arg3+0x10: -80.00, f_arg3+0x14: 0.00,  f_arg3+0x18: 0.00,  f_arg3+0x1C: 80.00
//00:28:01.355          ReclassTypes.h:349   INFO| swfFillStyle_t print: type: 4 subType: 1  bitmapID: 65535 startColor: r:255 g:255 b:255 a:255 endColor: r:255 g:255 b:255 a:255
//00:28:01.355              SwfDebug.h:549   INFO| (arg4Color): r: 0.947308 g: 1.000000 b: 0.552011 a: 1.000000
//00:28:01.355              SwfDebug.h:558   INFO| f_arg5: 0.639965 f_arg5+4: 1795.747314 f_arg5+8: 0.000000 f_arg5+C: 0.000000 f_arg5+10: 0.500000 f_arg5+14: 1655.800049
//00:28:01.355              SwfDebug.h:566   INFO| f_arg6: 0.00 f_arg6+4: 0.00 f_arg6+8: 0.95
//
//	*/
//
//	void changeEquipmentArrowColor(__int64 idDeclSWFptr, __int64 arg2, __int64 arg3, __int64 arg4Color, float* arg5, float* arg6) {
//		const float epsilon = 0.001f;
//		if (!isHudSwf(idDeclSWFptr, swfWeaponinfoName)) return;
//		if ((std::abs(*(float*)(arg3)- -80.00) < epsilon) && (std::abs(*(float*)(arg3 + 0xC) - 80.00) < epsilon) && (std::abs(*(float*)(arg3 + 0x10) - - 80.00) < epsilon) && (std::abs(*(float*)(arg3 + 0x1C) - 80.00) < epsilon)) {
//			logInfo("changeEquipmentArrowColor: trigger 1");
//			logInfo("f_arg5: %f f_arg5+4: %f f_arg5+8: %f f_arg5+C: %f f_arg5+10: %f f_arg5+14: %f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
//			logInfo("changeEquipmentArrowColor: f_arg6: %f f_arg6+4: %f f_arg6+8: %f ", *(float*)arg6, *(float*)(arg6 + 4), *(float*)(arg6 + 8));
//			if ((std::abs(*(float*)(arg6) - 0.00) < epsilon) && (std::abs(*(float*)(arg6 + 0x8)  - 0.947308) < epsilon)) {
//			//if ((std::abs(*(float*)(arg6) - 0.00) < epsilon) && (std::abs(*(float*)(arg6 + 0x4) - 0.00) < epsilon) && (std::abs(*(float*)(arg6 + 0x8)  - 0.95) < epsilon)) {
//
//				logInfo("changeEquipmentArrowColor: trigger 2");
//				setArg4Color(arg4Color, 0, 0, 1, 0);
//			}
//		}
//	}
//
//
//	//? this works you can use it as a base to make the arrow+little bar colored BUT when you swith nades it stops working i suspect because of some effect on the hud that messes with everything.
//	void OverideEquipmentArrowAndBarColors(__int64 idDeclSWFptr, __int64 arg4, float* arg5) {
//		const float epsilon = 0.001f;
//
//		if (isHudSwf(idDeclSWFptr,swfWeaponinfoName)) {
//
//			float element_Y_Val = *(float*)(arg5 + 4);
//			
//			if (element_Y_Val > m_hudEquipmentMiniBarShape_Y && element_Y_Val > m_hudEquipmentArrowShape_Y)
//			{
//
//				m_hudEquipmentMiniBarShape_Y = m_hudEquipmentArrowShape_Y;
//				m_hudEquipmentArrowShape_Y = element_Y_Val;
//
//				logInfo("1: element_Y_Val: %f, m_hudEquipmentMiniBarShape_Y: %f, m_hudEquipmentArrowShape_Y: %f", element_Y_Val, m_hudEquipmentMiniBarShape_Y, m_hudEquipmentArrowShape_Y);
//				
//
//				/*if (element_Y_Val > m_hudEquipmentArrowShape_Y) {
//					m_hudEquipmentArrowShape_Y = element_Y_Val;
//					logInfo("setting m_hudEquipmentArrowShape_Y to %f", m_hudEquipmentArrowShape_Y);
//				}
//				else {
//					m_hudEquipmentMiniBarShape_Y = element_Y_Val;
//					logInfo("setting m_hudEquipmentMiniBarShape_Y to %f", m_hudEquipmentMiniBarShape_Y);
//
//				}		*/		
//			}
//			else if (element_Y_Val > m_hudEquipmentMiniBarShape_Y && element_Y_Val < m_hudEquipmentArrowShape_Y) {
//				
//				m_hudEquipmentMiniBarShape_Y = element_Y_Val;
//
//				logInfo("2: element_Y_Val: %f, m_hudEquipmentMiniBarShape_Y: %f, m_hudEquipmentArrowShape_Y: %f", element_Y_Val, m_hudEquipmentMiniBarShape_Y, m_hudEquipmentArrowShape_Y);
//			}
//
//			if (std::abs(*(float*)(arg5 + 4) - m_hudEquipmentMiniBarShape_Y) < epsilon) {
//				logInfo("Minibar trigger:  element_Y_Val: %f, m_hudEquipmentMiniBarShape_Y: %f, m_hudEquipmentArrowShape_Y: %f", element_Y_Val, m_hudEquipmentMiniBarShape_Y, m_hudEquipmentArrowShape_Y);
//				logInfo("NOT CHANGING COLOR ATM");
//				//setArg4Color(arg4, 0, 0, 0, 0);
//				//setArg4Color(arg4Color, 0, 0, 0, 0.1);
//				//setArg4Color(arg4, 0.1, 0.1, 0.1, 1);
//				//setArg4Color(arg4, 1, 1, 1, 0);
//			}
//			else if (std::abs(*(float*)(arg5 + 4) - m_hudEquipmentArrowShape_Y) < epsilon) {
//				logInfo("Arrow trigger:  element_Y_Val: %f, m_hudEquipmentMiniBarShape_Y: %f, m_hudEquipmentArrowShape_Y: %f", element_Y_Val, m_hudEquipmentMiniBarShape_Y, m_hudEquipmentArrowShape_Y);
//				logInfo("NOT CHANGING COLOR ATM");
//
//				//setArg4Color(arg4, 0, 1, 1, 1);
//				//setArg4Color(arg4, 0, 0, 0, 1);
//				//setArg4Color(arg4, 1, 1, 1, 0);
//
//
//			}
//		}		
//	}
//
//
//
//	
//
//	void modifyWeaponInfoVals(__int64 idDeclSWFptr, __int64 arg2, __int64 arg3, __int64 arg4Color, float* arg5, float* arg6) {
//		//! just a way to try to identify who's who
//	// (arg4Color): r: 1.000000 g: 1.000000 b: 1.000000 a: 0.390625 => no result when modifying it
//	// (arg4Color): r: 1.000000 g: 1.000000 b: 1.000000 a: 1.000000 => no result when modifying it
//	// (arg4Color): r: 0.218750 g: 0.218750 b: 0.218750 a: 0.601562 => no result when modifying it
//	// (arg4Color): r: 1.000000f g: 0.386430 b: 0.254152 a: 0.199219 => crucible bg color 
//	// (arg4Color): r: 1.000000 g: 0.617206 b: 0.603827 a: 1.000000 => crucible icon color 
//	// (arg4Color): r: 1.000000 g: 0.386430 b: 0.254152 a: 1.000000 => crucible outline and pips
//	// (arg4Color): r: 0.947308 g: 1.000000 b: 0.552011 a: 1.000000 => THIS IS THE ARROW OF EQUIPMENT AND THE BG OF BIND LETTERS...
//	// (arg4Color): r: 1.000000 g: 1.000000 b: 1.000000 a: 0.351562 => bg of the bg of the whole equipment, very subtle but why not.
//	// (arg4Color): r: 0.730460 g: 0.838799 b: 0.327778 a: 1.000000 => no result when modifying it
//	// (arg4Color): r: 0.644479 g: 1.000000 b: 0.119538 a: 1.000000 => no result when modifying it
//	// (arg4Color): r: 0.439658 g: 0.947308 b: 1.000000 a: 1.000000 => THIS IS THE LITTLE BAR THAT SHOULD SHOW OTHER NADE²
//
//		//logInfo("test1");
//
//		const float epsilon = 0.001f;
//		if (isHudSwf(idDeclSWFptr, swfWeaponinfoName)) {			
//
//			logSwfHudElementInfos(idDeclSWFptr, arg2, arg3, arg4Color, arg5, arg6, swfWeaponinfoName);
//			//logInfo("test2");
//
//			if (std::abs(*(float*)(arg4Color) - 0.947308) < epsilon &&
//				std::abs(*(float*)(arg4Color + 4) - 1.000000) < epsilon &&
//				std::abs(*(float*)(arg4Color + 8) - 0.552011) < epsilon &&
//				std::abs(*(float*)(arg4Color + 0xC) - 1.000000) < epsilon) {
//				
//				//! this reduce the width of the bind texts bg
//				//*(float*)(arg5 + 0x10) = 50.0f; // pict
//
//				//! this one is a bit more complex but sets an x value for many elements and also the strings but it seems to set the postions even when the mod is unloaded (!?)
//				//*(float*)(arg5 + 0x14) = 900.0f; // pict
//
//				//! no change
//				//*(float*)(arg3 + 0x4) = -60.0f; 
//
//				//! this will basically reduce the width of every bg of each bind string and it will stay that way even if mod is unloaded
//				//*(float*)(arg3) = -200.0f;
//
//				//! this just like above i think
//				//*(float*)(arg3 +0x4) = -200.0f;
//
//				//? this will make the game crash even though arg2 is alway 1400 in that case...
//				//*(float*)(arg2) = 1200.0f; 
//				
//
//				//! this will set the x position of both bind keyx rectangle
//				//*(float*)(arg5 + 0x4) = 1300.0f; // pic arg5_4_1300.jpg in screenshot of DE steam folder
//
//				//? i just realise this would decrease the value over time and will make it O and below potentially (?):
//				//! those will change something because all the equipment icons are blank
//				/**(float*)(arg3 ) -= 10.0f;   
//				*(float*)(arg3 + 0x4) -= 10.0f;*/
//
//				//*(float*)(arg5 + 4) -= 100.0f;
//
//				setArg4Color(arg4Color, 1, 0, 1, 1);
//			}
//
//
//		}
//	}
//
//
//	//? i think arg2 could be the coordinates of the element.....
//	//void modifyHeavyCannonReticuleColors(__int64 idDeclSWFptr, __int64 arg2, __int64 arg4Color) {
//	//	static __int64 lastidDeclSWFptr = 0;
//	//	static int counter = 0;
//	//	if (isHudSwf(idDeclSWFptr, m_swfReticuleName)) {
//	//		if (idDeclSWFptr != lastidDeclSWFptr) {
//	//			lastidDeclSWFptr = idDeclSWFptr;
//	//			logInfo("modifyHeavyCannonReticuleColors: hud reticle addr is now: %p", (void*)idDeclSWFptr);
//	//		}
//	//		//reticleColorInfo colorInfo;
//	//		if (MemHelper::isBadReadPtr((void*)arg4Color)) {
//	//			logErr("modifyHeavyCannonReticuleColors: found bad ptr: %p", (void*)arg4Color);
//	//			return;
//	//		}
//	//		float r = *(float*)arg4Color;
//
//
//	//		if (counter == 0) { 
//	//		//if (r < 0.36f) { 
//	//			*(float*)arg4Color = 1.0f;
//	//			*(float*)(arg4Color + 4) = 0.0f;
//	//			*(float*)(arg4Color + 8) = 0.0f;
//	//			*(float*)(arg4Color + 0xC) = 1.0f;
//	//		}
//	//		else if(counter == 1) { 
//	//		//else if (r < 0.53f) { 
//	//			*(float*)arg4Color = 1.0f;
//	//			*(float*)(arg4Color + 4) = 0.0f;
//	//			*(float*)(arg4Color + 8) = 1.0f;
//	//			*(float*)(arg4Color + 0xC) = 1.0f;
//	//		}
//	//		else if (counter == 2) {
//	//		//else if (r < 0.79f) {
//	//			*(float*)arg4Color = 0.0f;
//	//			*(float*)(arg4Color + 4) = 1.0f;
//	//			*(float*)(arg4Color + 8) = 0.0f;
//	//			*(float*)(arg4Color + 0xC) = 1.0f;
//	//		}
//	//		else if (counter == 3) {
//	//			//else if (r < 0.79f) {
//	//			*(float*)arg4Color = 0.0f;
//	//			*(float*)(arg4Color + 4) = 1.0f;
//	//			*(float*)(arg4Color + 8) = 1.0f;
//	//			*(float*)(arg4Color + 0xC) = 1.0f;
//	//		}
//	//		else  {
//	//			*(float*)arg4Color = 1.0f;
//	//			*(float*)(arg4Color + 4) = 1.0f;
//	//			*(float*)(arg4Color + 8) = 1.0f;
//	//			*(float*)(arg4Color + 0xC) = 1.0f;
//	//		}
//	//		counter++;
//	//		if (counter >= 4) counter = 0;
//
//
//	//		modifyPotentialXYPos(arg2); // this works but it seems we're missing the bottom right coordinates
//
//	//		//modify_swfRect_t_Bounds(addr);
//
//	//	
//	//		//logInfo("r: %.2f g: %.2f b: %.2f a: %.2f ", colorInfo.r, colorInfo.g, colorInfo.b, colorInfo.a);
//	//	}
//	//	else {
//	//		counter = 0;
//	//	}
//	//}
//
//	//! using idSWFSpriteInstance.h as a reference
//	//? this doesn't have to have any influence at all on the crosshair position
//	void modify_swfRect_t_Bounds(__int64 idDeclSWFptr) {
//		__int64 static lastidSWFSpriteInstanceAddr = 0;
//		__int64 idSWFSpriteInstanceAddr = idDeclSWFptr + 0x18;
//		if (MemHelper::isBadReadPtr((void*)(idSWFSpriteInstanceAddr))) {
//			logErr("modify_swfRect_t_Bounds: found bad ptr: %p", (void*)(idSWFSpriteInstanceAddr));
//			return;
//		}
//		if (idSWFSpriteInstanceAddr != lastidSWFSpriteInstanceAddr) {
//			lastidSWFSpriteInstanceAddr = idSWFSpriteInstanceAddr;
//			logInfo("modify_swfRect_t_Bounds: idSWFSpriteInstanceAddrr is now: %p", (void*)idSWFSpriteInstanceAddr);
//		}
//		idSWFSpriteInstanceAddr = *(__int64*)(idSWFSpriteInstanceAddr);
//		*(float*)(idSWFSpriteInstanceAddr+0xA8) = 100.0f;
//		*(float*)(idSWFSpriteInstanceAddr+0xAC) = 100.0f;
//		*(float*)(idSWFSpriteInstanceAddr+0xB0) = 300.0f;
//		*(float*)(idSWFSpriteInstanceAddr+0xB4) = 300.0f;
//
//	}
//
//	void modifyHeavyCannonReticuleColors(__int64 idDeclSWFptr, __int64 arg4, float* arg5) {
//
//		if (isHudSwf(idDeclSWFptr, "swf/hud/hud_reticle.swf")) {
//			if (MemHelper::isBadReadPtr((void*)arg4)) {
//				logErr("modifyHeavyCannonReticuleColors: found bad ptr for arg4Color: %p", (void*)arg4);
//				return;
//			}
//			if (MemHelper::isBadReadPtr((void*)arg5)) {
//				logErr("modifyHeavyCannonReticuleColors: found bad ptr for arg5: %p", (void*)arg5);
//				return;
//			}
//		}
//
//		//r: 0.851562 g: 1.000000 b: 0.910156 a: 0.250000
//
//	//f_arg5: 0.00 f_arg5 + 4 : 606.42 f_arg5 + 8 : 0.00 f_arg5 + C : 0.00 f_arg5 + 10 : -0.51 f_arg5 + 14 : 642.00
//	//f_arg5: -0.20 f_arg5 + 4 : 657.25 f_arg5 + 8 : 0.00 f_arg5 + C : -1.00 f_arg5 + 10 : 0.00 f_arg5 + 14 : 662.33
//	//f_arg5: 0.00 f_arg5+4: 677.58 f_arg5+8: 0.00 f_arg5+C: 0.00 f_arg5+10: 0.51 f_arg5+14: 642.00
//	//f_arg5: 0.20 f_arg5 + 4 : 626.75 f_arg5 + 8 : 0.00 f_arg5 + C : 1.00 f_arg5 + 10 : 0.00 f_arg5 + 14 : 621.67
//		//const float epsilon = 0.0001f;
//		const float epsilon = 0.001f;
//
//		//? i guess we'll have to replace this with a check of the current crossahir style (?)
//		if (std::abs(*(float*)arg4 - 0.851562f) < epsilon &&
//			std::abs(*(float*)(arg4 + 4) - 1.000000f) < epsilon &&
//			std::abs(*(float*)(arg4 + 8) - 0.910156f) < epsilon &&
//			std::abs(*(float*)(arg4 + 0xC) - 0.250000f) < epsilon) {
//
//
//				//f_arg5 + C: 1.000000 f_arg5 + 10 : 0.000060
//				//f_arg5 + C : 0.000000 f_arg5 + 10 : -0.652719
//				//f_arg5 + C : -1.000000 f_arg5 + 10 : 0.000060
//				//f_arg5 + C : 0.000000 f_arg5 + 10 : 0.652719
//
//
//
//
//
//			//*(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
//			//logInfo("f_arg5: %f f_arg5+4: %f f_arg5+8: %f f_arg5+C: %f f_arg5+10: %f f_arg5+14: %f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
//
//			if ((std::abs(*(float*)(arg5 + 0xC) - 1.0f)) < epsilon ) { // top
//				//setArg4Color(arg4Color, 1, 1, 0, 1);
//
//				setArg4Color(arg4, 0, 0, 0, 0);
//				return;
//			}
//			if (std::abs(*(float*)(arg5 + 0xC) - 0.0f) < epsilon && // left
//				(*(float*)(arg5 + 0x10)) < 0.0f) {
//				//setArg4Color(arg4Color, 0, 1, 0, 1);
//				setArg4Color(arg4, 0, 0, 0, 0);
//
//
//				return;
//			}
//			if ((std::abs(*(float*)(arg5 + 0xC) - -1.0f)) < epsilon){ // bottom
//				//setArg4Color(arg4Color, 1.00000, 0.40000, 0.00000, 1);
//				setArg4Color(arg4, 0, 0, 0, 0);
//
//
//				return;
//			}
//			if (std::abs(*(float*)(arg5 + 0xC) - 0.0f) < epsilon &&( // right
//				*(float*)(arg5 + 0x10) > 0.0f)) {
//				//setArg4Color(arg4Color, 0, 1, 1, 1);
//				setArg4Color(arg4, 0, 0, 0, 0);
//
//
//				return;
//			}
//
//		/*	*(float*)arg4Color = 1.0f;
//			*(float*)(arg4Color + 4) = 0.0f;
//			*(float*)(arg4Color + 8) = 0.0f;
//			*(float*)(arg4Color + 0xC) = 1.0f;*/
//
//		}		
//	}
//
//	void setArg4Color(__int64 arg4, float r, float g, float b, float a) {
//		//logInfo("setArg4Color called seting rgba: %.2f,  %.2f,  %.2f,  %.2f,", r, g, b, a);
//
//
//		*(float*)arg4 = r;
//		*(float*)(arg4 + 4) = g;
//		*(float*)(arg4 + 8) =b;
//		*(float*)(arg4 + 0xC) = a;
//	}
//
//	void modifyUnknown(__int64 idDeclSWFptr, __int64 arg3) {
//		static __int64 lastidDeclSWFptr = 0;
//		static int counter = 0;
//
//		if (isHudSwf(idDeclSWFptr, "swf/hud/hud_reticle.swf")) {
//			if (idDeclSWFptr != lastidDeclSWFptr) {
//				lastidDeclSWFptr = idDeclSWFptr;
//				logInfo("modifyUnknown: hud reticle addr is now: %p", (void*)idDeclSWFptr);
//			}
//			if (MemHelper::isBadReadPtr((void*)arg3)) {
//				logErr("modifyUnknown: found bad ptr: %p", (void*)arg3);
//				return;
//			}
//
//			logInfo("arg3+8: %.2f arg3+C: %.2f", *(float*)(arg3 + 8), *(float*)(arg3 + 0xC));
//			
//
//			*(float*)(arg3 + 18) = 200.0f; 
//			*(float*)(arg3 + 0x1C) = 300.0f;
//
//			//! executing this will permanently set those values in the arg, which is weird. but it doesn't change anything.
//			//*(float*)(arg3 + 8) = 200.0f; 
//			//*(float*)(arg3 + 0xC) = 300.0f;
//
//			/**(unsigned char*)(arg4Color + 0x60) = 255;
//			*(unsigned char*)(arg4Color + 0x61) = 0;
//			*(unsigned char*)(arg4Color + 0x62) = 0;
//			*(unsigned char*)(arg4Color + 0x63) = 255;*/
//
//			/**(unsigned char*)(arg4Color + 0x64) = 0;
//			*(unsigned char*)(arg4Color + 0x65) = 255;
//			*(unsigned char*)(arg4Color + 0x66) = 255;
//			*(unsigned char*)(arg4Color + 0x67) = 255;*/
//			
//
//			/**(float*)arg4Color = 1.0f;
//			*(float*)(arg4Color + 4) = 0.0f;
//			*(float*)(arg4Color + 8) = 0.0f;
//			*(float*)(arg4Color + 0xC) = 1.0f;*/
//
//			counter++;
//			if (counter >= 4) counter = 0;
//
//			
//
//			//logInfo("r: %.2f g: %.2f b: %.2f a: %.2f ", colorInfo.r, colorInfo.g, colorInfo.b, colorInfo.a);
//		}
//		else {
//			counter = 0;
//		}
//	}
//
//	void modifyPotentialXYPos(__int64 arg2) {
//		if (MemHelper::isBadReadPtr((void*)arg2)) {
//			logErr("modifyPotentialXYPos: found bad ptr: %p", (void*)arg2);
//			return;
//		}
//		__int64 addr = *(__int64*)(arg2);
//		if (MemHelper::isBadReadPtr((void*)addr)) {
//			logErr("modifyPotentialXYPos: (2)found bad ptr: %p", (void*)arg2);
//			return;
//		}
//		*(float*)addr = 400.0f;
//		*(float*)(addr+4) = 400.0f;
//		*(float*)(addr+30) = 500.0f;
//		*(float*)(addr+38) = 400.0f;
//	}
//
//
//	void logFillDraws(__int64 fillDrawsPtr) {
//		if (!MemHelper::isBadReadPtr((void*)fillDrawsPtr)) {
//			__int64 fillDrawsAddr = *(__int64*)(fillDrawsPtr);
//			swfFillStyle_t* fillDraws = (swfFillStyle_t*)fillDrawsAddr;
//			fillDraws->print();
//		}
//		else {
//			logWarn("logFillDraws fillDrawsPtr is badptr");
//		}
//	}
//	
//
//	//if (swfDebug.isHudSwf(a1, swfDebug.swfWeaponinfoName))
//
//	void logSwfHudElementInfos(__int64 idDeclSWFptr, __int64 arg2, __int64 arg3, __int64 arg4, float* arg5, float* arg6, std::string hudElementSwfName) {
//		//! thos address do not change for each element of the reticule
//		__int64  idDeclSWFAddr = *(__int64*)idDeclSWFptr;
//		__int64  idSWFResourceAddr = *(__int64*)(idDeclSWFptr + 8);
//		__int64  idSWFScriptObjectAddr = *(__int64*)(idDeclSWFptr + 0x10);
//		__int64  idSWFSpriteInstanceAddr = *(__int64*)(idDeclSWFptr + 0x18);
//		__int64  idMaterial2Addr = *(__int64*)(idDeclSWFptr + 0x520);
//
//		logInfo("logSwfHudElementInfos: idDeclSWFptr addr: %p, %llx, %llx, %llx, %llx, %llx,", (void*)idDeclSWFptr, idDeclSWFAddr, idSWFResourceAddr, idSWFScriptObjectAddr, idSWFSpriteInstanceAddr, idMaterial2Addr);
//
//
//		__int64 arg2_addr = *(__int64*)(arg2);
//		if (MemHelper::isBadReadPtr((void*)arg2_addr)) {
//			logErr("logSwfHudElementInfos: found bad ptr: arg2 %p", (void*)arg2_addr);
//			return;
//		}
//
//		logInfo("arg2: %llx farg2_0: %f farg2_4: %f uarg2_18: %x uarg2_1C: %x ", arg2, *(float*)arg2_addr, *(float*)(arg2_addr + 4), *(unsigned int*)(arg4 + 0x18), *(unsigned int*)(arg4 + 0x1C));
//
//
//		if (MemHelper::isBadReadPtr((void*)arg3)) {
//			logErr("logSwfHudElementInfos: found bad ptr: arg3 %p", (void*)arg3);
//			return;
//		}
//
//
//		logInfo("arg3: %llx f_arg3: %f, f_arg3+4: %f, f_arg3+8: %f f_arg3+C: %f f_arg3+0x10: %f, f_arg3+0x14: %f,  f_arg3+0x18: %f,  f_arg3+0x1C: %f", arg3, *(float*)arg3, *(float*)(arg3 + 4), *(float*)(arg3 + 8), *(float*)(arg3 + 0xC), *(float*)(arg3 + 0x10), *(float*)(arg3 + 0x14), *(float*)(arg3 + 0x18), *(float*)(arg3 + 0x1C));
//
//		//logFillDraws(arg3 + 0x20);
//
//		if (MemHelper::isBadReadPtr((void*)arg4)) {
//			logErr("logSwfHudElementInfos: found bad ptr: arg4Color %p", (void*)arg4);
//			return;
//		}
//
//		logInfo("(arg4Color): r: %f g: %f b: %f a: %f ", *(float*)arg4, *(float*)(arg4 + 4), *(float*)(arg4 + 8), *(float*)(arg4 + 0xC));
//		//logInfo("r: %.2f g: %.2f b: %.2f a: %.2f ", *(float*)arg4Color, *(float*)(arg4Color + 4), *(float*)(arg4Color + 8), *(float*)(arg4Color + 0xC));
//
//		if (MemHelper::isBadReadPtr((void*)arg5)) {
//			logErr("logSwfHudElementInfos: found bad ptr: arg5 %p", (void*)arg5);
//			return;
//		}
//
//		//logInfo("f_arg5: %.2f f_arg5+4: %.2f f_arg5+8: %.2f f_arg5+C: %.2f f_arg5+10: %.2f f_arg5+14: %.2f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
//		logInfo("f_arg5: %f f_arg5+4: %f f_arg5+8: %f f_arg5+C: %f f_arg5+10: %f f_arg5+14: %f", *(float*)arg5, *(float*)(arg5 + 4), *(float*)(arg5 + 8), *(float*)(arg5 + 0xC), *(float*)(arg5 + 0x10), *(float*)(arg5 + 0x14));
//
//
//		if (MemHelper::isBadReadPtr((void*)arg6)) {
//			logErr("logSwfHudElementInfos: found bad ptr: arg6 %p", (void*)arg6);
//			return;
//		}
//
//		logInfo("f_arg6: %f f_arg6+4: %f f_arg6+8: %f ", *(float*)arg6, *(float*)(arg6 + 4), *(float*)(arg6 + 8));
//		//reticleColorInfo colorInfo;
//		/*if (MemHelper::isBadReadPtr((void*)arg4Color)) {
//			logErr("logHudReticleInfos: (0) found bad ptr: %p", (void*)arg4Color);
//			return;
//		}*/
//
//		for (size_t i = 0; i < m_swfHudShapesAddrVec.size(); i++)
//		{
//			if (arg3 == m_swfHudShapesAddrVec[i]) return;
//		}
//		m_swfHudShapesAddrVec.push_back(arg3);
//		logInfo("logSwfHudElementInfos: found raceHudShapesAdd: %p", (void*)arg3);
//
//		/*colorInfo.r = *(float*)arg4Color;
//		colorInfo.g = *(float*)(arg4Color + 4);
//		colorInfo.b = *(float*)(arg4Color + 8);
//		colorInfo.a = *(float*)(arg4Color + 0xC);
//		logInfo("r: %.2f g: %.2f b: %.2f a: %.2f ", colorInfo.r, colorInfo.g, colorInfo.b, colorInfo.a);*/
//	}
//
//
//	void log_renderSWF_Smth_4FCF80_MatrName(__int64 matArgAddr) {
//		std::string matName = getMaterialStringFromMaterialPtr(matArgAddr);
//		logInfo("log_renderSWF_Smth_4FCF80_MatrName: matArgAddr: %p matrName: %s", (void*)matArgAddr, matName.c_str());
//
//	}
//
//	std::string getMaterialStringFromMaterialPtr(__int64 matPtr) {
//		if (MemHelper::isBadReadPtr((void*)matPtr)) {
//			return "bad ptr";
//		}
//		uintptr_t materialStrAddr = *(uintptr_t*)(matPtr + 0x8);
//		//logInfo("debugMaterialName: material String Addr : %p with name: %s", (void*)materialStrAddr, (const char*)(materialStrAddr));
//		std::string s = (const char*)(materialStrAddr);
//		return s;
//	}
//
//	/*void saveRenderShapeidDeclSWFptrOfRenderShape_Smth_4FDD30(__int64 idDeclSWFptr) {
//		for (size_t i = 0; i < m_idDeclSWFptrsVec.size(); i++)
//		{
//			if (m_idDeclSWFptrsVec[i] == idDeclSWFptr) {
//				return;
//			}
//		}
//		m_idDeclSWFptrsVec.push_back(idDeclSWFptr);
//
//	}*/
//
//	/*void Log_idDeclSWFVec() {
//		try
//		{
//			logInfo("Log_idDeclSWFVec from func RenderShape_Smth_4FDD30: ");
//			for (size_t i = 0; i < m_idDeclSWFptrsVec.size(); i++)
//			{
//				__int64 addr = m_idDeclSWFptrsVec[i];
//				if (addr == 0) continue;
//				addr = *(__int64*)addr;
//				if (addr == 0) continue;
//				addr += 8;
//				if (addr == 0) continue;
//				addr = *(__int64*)addr;
//				if (addr == 0) continue;
//				std::string swfNameStr = (const char*)addr;
//				logInfo("%s", swfNameStr.c_str());
//
//			}
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("LogidDeclSWFVec: %s", ex.what());
//		}
//
//	}*/
//
//	void saveHudReticleSwfAddr(__int64 idDeclSWFptr) {
//		//if (isHud_reticle_SWF(idDeclSWFptr)) {
//		if (isHudSwf(idDeclSWFptr, "swf/hud/hud_reticle.swf")) {
//			for (size_t i = 0; i < m_idDeclHudReticleptrsVec.size(); i++)
//			{
//				if (idDeclSWFptr == m_idDeclHudReticleptrsVec[i]) return;
//			}
//			m_idDeclHudReticleptrsVec.push_back(idDeclSWFptr);
//		}
//	}
//
//
//	bool isHudSwf(__int64 addr, std::string hudSwfName) {
//		if (addr == 0) return false;
//		addr = *(__int64*)addr;
//		if (addr == 0) return false;
//		addr += 8;
//		if (addr == 0) return false;
//		addr = *(__int64*)addr;
//		if (addr == 0) return false;
//		std::string swfNameStr = (const char*)addr;
//		//logWarn("swfNameStr: %s  hudSwfName: %s", swfNameStr.c_str(), hudSwfName.c_str());
//		//if (swfNameStr != "swf/hud/hud_reticle.swf") {
//		if (swfNameStr != hudSwfName) {
//			//logWarn("isHudSwf wrong name, found: %s", swfNameStr.c_str());
//			return false;
//		}
//		return true;
//	}
//
//	//bool isHud_reticle_SWF(__int64 addr) {
//	//	/*__int64 addr = m_idDeclSWFptrsVec[i];*/
//	//	if (addr == 0) return false;
//	//	addr = *(__int64*)addr;
//	//	if (addr == 0) return false;
//	//	addr += 8;
//	//	if (addr == 0) return false;
//	//	addr = *(__int64*)addr;
//	//	if (addr == 0) return false;
//	//	std::string swfNameStr = (const char*)addr;
//	//	//if (swfNameStr != "swf/hud/hud_reticle.swf") {
//	//	if (swfNameStr != hudSwfName) {
//	//		return false;
//	//	}
//	//	return true;
//	//}
//
//	
//	//void log_SWF_Name(__int64 idDeclSWFptr) { //! use a1 of RenderShapeHook as an arg:
//	//	try
//	//	{
//	//		__int64 addr = idDeclSWFptr;
//	//		if (addr == 0) return ;
//	//		addr = *(__int64*)addr;
//	//		if (addr == 0) return;
//	//		addr += 8;
//	//		if (addr == 0) return;
//	//		addr = *(__int64*)addr;
//	//		if (addr == 0) return;
//	//		std::string swfNameStr = (const char*)addr;
//	//		for (size_t i = 0; i < SwfNamesVec.size(); i++)
//	//		{
//	//			if (SwfNamesVec[i] == swfNameStr) return;
//	//		}
//	//		SwfNamesVec.push_back(swfNameStr);
//	//		logInfo("log_SWF_Name: found swf name: %s idDeclSWFptr: %p", (const char*)addr, (void*)idDeclSWFptr);
//	//	}
//	//	catch (const std::exception& ex)
//	//	{
//	//		logErr("log_SWF_Name: %s", ex.what());
//	//	}		
//	//}
//
//	void log_SWF_Data(__int64 idDeclSWFptr) { //! use a1 of RenderShapeHook as an arg:
//		try
//		{
//			__int64 addr = idDeclSWFptr;
//			if (addr == 0) return;
//			addr = *(__int64*)addr;
//			if (addr == 0) return;
//			addr += 8;
//			if (addr == 0) return;
//			addr = *(__int64*)addr;
//			if (addr == 0) return;
//			std::string swfNameStr = (const char*)addr;
//			for (size_t i = 0; i < m_swfAddr_And_StrVec.size(); i++)
//			{
//				if (m_swfAddr_And_StrVec[i].addr == idDeclSWFptr && m_swfAddr_And_StrVec[i].name == swfNameStr) return;
//			}
//			m_swfAddr_And_StrVec.push_back(swfAddr_And_Str(idDeclSWFptr, swfNameStr));
//			//SwfNamesVec.push_back(swfNameStr);
//			logInfo("log_SWF_Name: found swf name: %s idDeclSWFptr: %p", (const char*)addr, (void*)idDeclSWFptr);
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("log_SWF_Name: %s", ex.what());
//		}
//	}
//
//	
//
//	
//
//	void GetHudReticleVec4InfoFromArg4_RenderShape_Smth_4FDD30(__int64 arg4) {
//		try
//		{
//			reticleColorInfo colorInfo;
//			if (MemHelper::isBadReadPtr((void*)arg4)) {
//				logErr("GetHudReticleVec4InfoFromArg4_RenderShape_Smth_4FDD30: (0) found bad ptr: %p", (void*)arg4);
//				return;
//			}
//			colorInfo.r = *(float*)arg4;
//			colorInfo.g = *(float*)(arg4 + 4);
//			colorInfo.b = *(float*)(arg4 + 8);
//			colorInfo.a = *(float*)(arg4 + 0xC);
//			
//			/*__int64 matPtr = arg4Color + 0x20;
//			if (MemHelper::isBadReadPtr((void*)matPtr)) {
//				logErr("GetColorInfoFromRenderShape_Smth_4FDD30: found bad ptr: %p", (void*)matPtr);
//				return;
//			}
//			__int64 matAddr = *(__int64*)matPtr;
//			if (MemHelper::isBadReadPtr((void*)matAddr)) {
//				logErr("GetColorInfoFromRenderShape_Smth_4FDD30: (2) found bad ptr: %p", (void*)matAddr);
//				return;
//			}
//			matAddr += 8;
//			if (MemHelper::isBadReadPtr((void*)matAddr)) {
//				logErr("GetColorInfoFromRenderShape_Smth_4FDD30: (3) found bad ptr: %p", (void*)matAddr);
//				return;
//			}
//			__int64 matAddrStr = *(__int64*)matAddr;
//			colorInfo.materialNameStr = (const char*)matAddrStr;*/
//
//			/*for (size_t i = 0; i < reticleColorInfoVec.size(); i++)
//			{
//				if (reticleColorInfoVec[i].materialNameStr == colorInfo.materialNameStr) return;
//			}
//			reticleColorInfoVec.push_back(colorInfo);*/
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("GetColorInfoFromRenderShape_Smth_4FDD30: %s", ex.what());
//		}
//		
//	}
//
//	/*void log_reticleColorInfo() {
//		logInfo("log_reticleColorInfo logging reticleColorInfoVec info: ");
//		for (size_t i = 0; i < reticleColorInfoVec.size(); i++)
//		{
//			reticleColorInfo colorInfo = reticleColorInfoVec[i];
//			logInfo("r: %.2f g: %.2f b: %.2f a: %.2f matrName: %s", colorInfo.r, colorInfo.g, colorInfo.b, colorInfo.a, colorInfo.materialNameStr.c_str());
//		}
//	}*/
//
//
//
//	//! doesn't work performance wise
//	/*void crosshairTest() {
//		if (!debugIsSafeToRender()) return;
//
//		CrosshairCrossWithDot crosshairCrossWithDot = CrosshairCrossWithDot(6.0f, true, 2.0f, colorBlack, colorGreen, m_testMaterial, 12.0f, 4.0f, true, NoData_CrosshairDataMap, hudData);
//
//		for (size_t i = 0; i < crosshairCrossWithDot.OutlineRectVec.size(); i++)
//		{
//			Rect& outlineRect = crosshairCrossWithDot.OutlineRectVec[i];
//			idRenderModelGui::drawRect(outlineRect);
//		}
//		for (size_t i = 0; i < crosshairCrossWithDot.FillRectVec.size(); i++)
//		{
//			Rect& fillRect = crosshairCrossWithDot.FillRectVec[i];
//			idRenderModelGui::drawRect(fillRect);
//		}
//
//
//	}*/
//
//
//	//bool debugIsSafeToRender() {
//
//	//	static bool lastisBadMaterialPtr = false;
//
//	//	/*__int64 idDebugHUDAddr = ObjectLocator::get_idDebugHUDAddr();
//	//	if (MemHelper::isBadReadPtr((void*)idDebugHUDAddr)) {
//	//		logWarn("debugIsSafeToRender: idDebugHUDAddr is bad ptr");
//	//		return false;
//	//	}*/
//
//	//	if (m_testMaterial == 0) {
//	//		getNextMaterial();
//	//	}
//
//	//	bool isBadMaterialPtr = MemHelper::isBadReadPtr((void*)m_testMaterial);
//	//	if (lastisBadMaterialPtr != isBadMaterialPtr) {
//	//		lastisBadMaterialPtr = isBadMaterialPtr;
//	//		logWarn("debugIsSafeToRender: m_testMaterial is bad ptr is now %d ", isBadMaterialPtr);
//	//	}
//	//	if (isBadMaterialPtr) {
//	//		return false;
//	//	}
//	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
//	//	if (!PlayerStateChecker::isPlaying()) return false;
//
//	//	return true;
//	//}
//
//	/*void getNextMaterial() {
//
//		m_testMaterial = MaterialLib::getLibNext();
//	}*/
//
//};