#pragma once

#include <Windows.h>
#include <algorithm>
#include <string>
#include <vector>
//#include "MaterialInfo.h"
#include "MemHelper.h"
#include "idDeclInfo.h"
#include "GeneratedEnums.h"

class MaterialLib {

private:
	//todo we had a crash before because of cached materials, i suppose that the problem was when we were loading different games modes, like i crashed a lot loading horde mode and i even witnessed the cached ice nade icon being wrong and being replaced by the bp icon, but may be if perf is a prob, we could cache them as long as the level has not changed or as long as player state has not changed (?) 

	static idDeclInfo m_idDeclInfo;

	//static size_t m_debugIndex; //! index used for debuging/finding materials

	static size_t m_libIndex;

	//static std::vector<__int64> m_materialsAddrsDebugVec;

	static bool m_isdebugMatrVecInitialized;
	static int m_debugShowMaterialIndex;	


	//? insteresting materials in notes.txt the one we could be interested seem to start at around index 4000 but ofc is you change materials you collect this index will be off...




	//static int m_debugMtrIndex;

	//static std::vector<uintptr_t> m_materialsAddrsFromSigScanVec;



public:	

	/*static void init() {
		logInfo("init called, caching hud materials");
		cacheHudMaterials();
	}*/


	
		

	//! extra info is still unknow, but it's not related to get the material low/high res.
	static __int64 get(const char* matNameStr, unsigned int extraInfo = 0);


	static __int64 get(hudSpriteId_t hudSpriteId);

	static __int64 getWhite();

	//? doesn't work it's not green:
	static __int64 getGreen();

	

	//? setting the bool to 1 will do nothing to prevent the current flickering of the texture
	static __int64 getFragGrenadeMtr();
	

	static __int64 getFlameBelchMtr();

	static __int64 getFluelAmmoMtr();

	static __int64 getHammerMtr();

	static __int64 getCrucibleMtr();

	static __int64 getBloodPunchMtr();

	static __int64 getDashMtr();

	static __int64 getHealthMtr();

	static __int64 getArmorMtr();




	//? trying this to see if it can not only prevent the crash we have when sometimes loading horde mode, the fact that the materials is wrong for the ice nade icon, i mean i got bloodpunch wft???? and that the ice nade icon doesn't show up when the mod is activated i have to reload the mod a second time but the cooldown of the string show up, so may be a material issue (?)
	//! update it seems the crash inded came from the cached materials addresses, i'm getting rid of them all right now...

	static __int64 getIceGrenadeMtr();
	

	static __int64 getIceNadeBorderMtr();

	static __int64 getIceNadeExtraBorderMtr();

	static __int64 getIceNadeBackgroundMtr();

	

	static __int64 getShellIconMtr();

	static __int64 getBulletIconMtr();

	static __int64 getRocketIconMtr();

	static __int64 getCellIconMtr();
		

	static __int64 getCursorEmptyMtr();


	static __int64 getMtr(std::string matrStr);
	

	//! found this studying idFont16GetMaterialWidth_4CCA50 but org code is for a idfont
	static unsigned getMaterialWidth(__int64 matrPtr);

	//! Found this studying idFont::GetMaterialHeight_4CCA20 but org code is for a idfont
	static unsigned int getMaterialHeight(__int64 matrPtr);


	

	//static __int64 getIceBarLeftMtr() {
//	if (!m_cached_IceBarLeftMtr) {
//		
//		//! big outline
//		//m_cached_IceBarLeftMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/screens/leaderboards_textures/swf_images/dossier/overlay/dossier_btn_default_left_cap_stroke_glow_", 0);
//		
//		//! black bg
//		//m_cached_IceBarLeftMtr = m_idDeclInfo.getMaterialPtr("swf/common/social_bar_textures/swf_images/social/social_alert_box_left_", 0);
//		
//		//! black bg too
//		//m_cached_IceBarLeftMtr = m_idDeclInfo.getMaterialPtr("swf/hud/menus/dossier/dossier_map_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_container_left_", 0);

//		m_cached_IceBarLeftMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/overlay_textures/swf_images/dossier/overlay/dossier_btn_default_left_cap_stroke_", 0);


//	}
//	return m_cached_IceBarLeftMtr;
//}


//static __int64 getIceBarMidMtr() {
//	if (!m_cached_IceBarMidMtr) {
//		//m_cached_IceBarMidMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/screens/leaderboards_textures/swf_images/dossier/overlay/dossier_btn_default_center_tile_stroke_glow_", 0);
//		
//		
//		//m_cached_IceBarMidMtr = m_idDeclInfo.getMaterialPtr("swf/common/social_bar_textures/swf_images/social/social_alert_box_mid_", 0);

//		//m_cached_IceBarMidMtr = m_idDeclInfo.getMaterialPtr("swf/hud/menus/dossier/dossier_map_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_container_center_", 0);

//		m_cached_IceBarMidMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/overlay_textures/swf_images/dossier/overlay/dossier_btn_default_center_tile_stroke_", 0);
//	}
//	return m_cached_IceBarMidMtr;
//}

//static __int64 getIceBarRightMtr() {
//	if (!m_cached_IceBarRightMtr) {
//		//m_cached_IceBarRightMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/screens/leaderboards_textures/swf_images/dossier/overlay/dossier_btn_default_right_cap_stroke_glow_", 0);
//		
//		//m_cached_IceBarRightMtr = m_idDeclInfo.getMaterialPtr("swf/common/social_bar_textures/swf_images/social/social_alert_box_right_", 0);
//		
//		//m_cached_IceBarRightMtr = m_idDeclInfo.getMaterialPtr("swf/hud/menus/dossier/dossier_map_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_container_right_", 0);
//		m_cached_IceBarRightMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/overlay_textures/swf_images/dossier/overlay/dossier_btn_default_right_cap_stroke_", 0);
//	}
//	return m_cached_IceBarRightMtr;
//}

//static __int64 getIceBarBgMtr() {
//	if (!m_cached_IceBarBgMtr) {
//		//! doesn't work:
//		//m_cached_IceBarBgMtr = m_idDeclInfo.getMaterialPtr("swf/hud/menus/dossier/dossier_runes_textures/swf_images/dossier/runes/rune_btn_hover_", 0);

//		m_cached_IceBarBgMtr = m_idDeclInfo.getMaterialPtr("swf/hud/hud_score_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_pip_", 0);
//	}
//	return m_cached_IceBarBgMtr;
//}



// this could be perfect for the whole ice container:
// swf/main_menu/screens/triumphs_textures/swf_images/hud/dialogue_containers/hud_slayer_speaker_portrait_glow_
//static __int64 getTestMtr() {
//	if (!m_cached_testMtr) {
//		//! Oriented square that can be good to hold one icon
//		//m_cached_testMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/screens/triumphs_textures/swf_images/hud/dialogue_containers/hud_slayer_speaker_portrait_glow_", 0);

//		//! black bg
//		//m_cached_testMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/screens/mission_select_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_container_left_", 0);
//		
//		m_cached_testMtr = m_idDeclInfo.getMaterialPtr("swf/main_menu/screens/mission_select_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_container_left_", 0);


//	}
//	return m_cached_testMtr;
//}



	

	//static void debugMaterialName(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 matPtr) {


	//	try
	//	{
	//		static __int64 lastMatPtr = 0;
	//		static float lastx = 0;

	//		if (matPtr != lastMatPtr) {
	//			//if (matPtr != lastMatPtr || a2 != lastx) {
	//			lastMatPtr = matPtr;
	//			lastx = a2;

	//			//uintptr_t materialAddr = *(uintptr_t*)matPtr;
	//			//logInfo("debugMaterialName: materialAddr: %p", (void*)materialAddr);
	//			//const char* matStr = (const char*)(materialAddr + 0x8);
	//			logInfo("debugMaterialName: x: %.2f, y: %.2f, z: %.2f, w: %.2f, l: %.2f, matPtr: %p", a2, a3, a4, a5, a6, (void*)matPtr);
	//			uintptr_t materialStrAddr = *(uintptr_t*)(matPtr + 0x8);
	//			logInfo("debugMaterialName: material String Addr : %p with name: %s", (void*)materialStrAddr, (const char*)(materialStrAddr));
	//			//logInfo("debugMaterialName: materialAddr + 0x8: %p", (void*)(matPtr + 0x8));
	//			//logInfo("Mat Name: %s", (const char*)(materialStrAddr));

	//		}
	//	}
	//	catch (const std::exception& ex)
	//	{
	//		logErr("debugMaterialName: exception: %s", ex.what());
	//	}

	//}
		

	



	/*static bool FilterMaterialNames(__int64 matrAdd) {

		if (MemHelper::isBadReadPtr((void*)matrAdd)) {
			logErr("FilterMaterialNames:  matrAdd: %p is bad ptr", (void*)matrAdd);
			return false;
		}
		std::string matrName = std::string((const char*)(*(uintptr_t*)(matrAdd + 0x8)));

		if ((matrName.starts_with("models/") || (matrName.starts_with("physics/")) || (matrName.starts_with("fontfx/")))) {
			return false;
		}
		return true;
	}*/

	
	//! this is used to test the materials for which we alrady have the strings names somewhere and that uses the debug string renderer in the printOutlinedStringMB_hook
	/*static void showLiveTestMaterialNext() {

		std::string testMtr_Name = debugGetMtr_Name();
		
		logInfo("showTestMaterialNext: mtr name: %s (index: %d)", testMtr_Name.c_str(), m_debugShowMaterialIndex);
		m_debugShowMaterialIndex++;
	}*/



	//static __int64 getNext() {
	//	__int64 result = 0;
	//	m_debugIndex++;
	//	if (m_materialsAddrsDebugVec.size() == 0) {
	//		logInfo("getNext:m_materialsAddrsDebugVec.size() == 0 ");
	//		return 0;
	//		//return matrDebughContainer(0, "material list empty");
	//	}

	//	if (m_debugIndex >= m_materialsAddrsDebugVec.size() - 1) {
	//		m_debugIndex = 0;
	//	}
	//	//result = get(m_materialsInfoVec[m_debugIndex].Name.c_str(), m_materialsInfoVec[m_debugIndex].ExtraInfo);
	//	logDebugMaterial(m_materialsAddrsDebugVec[m_debugIndex]);
	//	return m_materialsAddrsDebugVec[m_debugIndex];
	//	//logInfo("getNext:  material:  %llx with name %s : (materials in lib: %zu)", result, m_materialsInfoVec[m_debugIndex].Name.c_str(), m_materialsInfoVec.size());
	//	//return matrDebughContainer(result, m_materialsInfoVec[m_debugIndex].Name);
	//}


	//static __int64 getPrevious() {
	//	__int64 result = 0;
	//	m_debugIndex--;
	//	if (m_materialsAddrsDebugVec.size() == 0) {
	//		logInfo("getPrevious:m_materialsAddrsDebugVec.size() == 0 ");
	//		return 0;
	//		//return matrDebughContainer(0, "material list empty");
	//	}
	//	if (m_debugIndex > m_materialsAddrsDebugVec.size() - 1) {
	//		m_debugIndex = m_materialsAddrsDebugVec.size() - 1;
	//		/*result = get(m_materialsInfoVec[m_debugIndex].Name.c_str(), m_materialsInfoVec[m_debugIndex].ExtraInfo);
	//		logInfo("getPrevious: returning material:  %llx with name %s : (materials in lib: %zu)", result, m_materialsInfoVec[m_debugIndex].Name.c_str(), m_materialsInfoVec.size());
	//		return matrDebughContainer(result, m_materialsInfoVec[m_debugIndex].Name);*/
	//	}
	//	logDebugMaterial(m_materialsAddrsDebugVec[m_debugIndex]);
	//	return m_materialsAddrsDebugVec[m_debugIndex];
	//	/*result = get(m_materialsInfoVec[m_debugIndex].Name.c_str(), m_materialsInfoVec[m_debugIndex].ExtraInfo);
	//	logInfo("getPrevious: returning material:  %llx with name %s : (materials in lib: %zu)", result, m_materialsInfoVec[m_debugIndex].Name.c_str(), m_materialsInfoVec.size());
	//	return matrDebughContainer(result, m_materialsInfoVec[m_debugIndex].Name);*/
	//}


	

	//todo add names once you check those are idMAterials or ptr to idMaterials
	/*static void printMaterialsAddrsDebugVec() {
		for (size_t i = 0; i < m_materialsAddrsDebugVec.size(); i++)
		{
			logInfo("printMaterialsAddrsDebugVec:  %p ", (void*)m_materialsAddrsDebugVec[i]);
		}
		logInfo("printMaterialsAddrsDebugVec:  total unique addrs in vec:  %zu", m_materialsAddrsDebugVec.size());
	}*/







};


//std::vector<MaterialInfo> MaterialLib::m_materialsInfoVec;
//size_t MaterialLib::m_debugIndex = 0; // Define and initialize the static member

//std::vector<__int64> MaterialLib::m_materialsAddrsDebugVec;

//__int64 MaterialLib::m_cached_whiteMatr = 0;
//__int64 MaterialLib::m_cached_greenMatr = 0;
// __int64 MaterialLib::m_cached_FlameBelchMtr = 0;
// __int64 MaterialLib::m_cached_FuelMtr = 0;
// __int64 MaterialLib::m_cached_FragNadeMtr = 0;
// __int64 MaterialLib::m_cached_CrucibleMtr = 0;
// __int64 MaterialLib::m_cached_HammerMtr = 0;
// __int64 MaterialLib::m_cached_bloodPunchMtr = 0;
// __int64 MaterialLib::m_cached_dashMtr = 0;
// __int64 MaterialLib::m_cached_healthMtr = 0;
// __int64 MaterialLib::m_cached_armorMtr = 0;
//
// __int64 MaterialLib::m_cached_IceBarLeftMtr = 0;
// __int64 MaterialLib::m_cached_IceBarMidMtr = 0;
// __int64 MaterialLib::m_cached_IceBarRightMtr = 0;
//
// __int64 MaterialLib::m_cached_IceBarBgMtr = 0;
//
// __int64 MaterialLib::m_cached_IceNadeStarIconMtr = 0;
//__int64 MaterialLib::m_cached_IceNadeExtraBorderMtr = 0;
//__int64 MaterialLib::m_cached_IceNadeBorderMtr = 0;
//__int64 MaterialLib::m_cached_IceNadeBackgroundMtr = 0;

 //__int64 MaterialLib::m_cached_testMtr = 0;

 //__int64 MaterialLib::m_liveTestMtr = 0;
 //int MaterialLib::m_liveTestMtrIndex = 0;
 


 //int MaterialLib::m_debugShowMaterialIndex = 0;

 //bool MaterialLib::m_isMaterialDebugMode = false;



//int MaterialLib::m_debugMtrIndex;
//std::vector<uintptr_t> MaterialLib::m_materialsAddrsFromSigScanVec;

