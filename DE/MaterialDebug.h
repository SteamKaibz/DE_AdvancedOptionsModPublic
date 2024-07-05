#pragma once
#include <vector>
#include <string>
#include "../Config/Config.h"
#include "idDeclInfo.h"
#include "idResourceListManager.h"

enum materialDebugMode {
	none,
	localList, // we use a list of str we acquired before
	gameList // we get a list of matr str from the game using idResourceListManager::getResourceListFirstElementPtr
	
};


class MaterialDebug {

private:

	static std::vector<std::string> m_materialsNamesVec;

	static int m_testMaterialNameIndex;

	//static bool m_isMaterialDebugMode;

	static __int64 m_testMtr;

	static idDeclInfo m_idDeclInfo;

	static std::string ammoEquipmentFilterStr;

	static bool m_isInitialized;

	static materialDebugMode debugMode;

public:

	static bool isMaterialDebugMode();

	static void initialize();


	static void setPrevTestMtr();


	static void setNextTestMtr();

	//! material to display
	static __int64 getTestMtr();

	//! just use another function to find the name of the material itself
	/*static std::string getLiveTestMtrStr() {
		if (liveTestMtrStrVec.size() <= 0) {
			logErr("setPrevLiveTestMtr: liveTestMtrStrVec is empty");
			return std::string("liveTestMtrStrVec is empty");
		}
		if (!(m_liveTestMtrIndex >= 0) || !(m_liveTestMtrIndex < liveTestMtrStrVec.size())) {
			logWarn("setPrevLiveTestMtr: index out of bounds: %d setting it to 0", m_liveTestMtrIndex);
			m_liveTestMtrIndex = 0;
		}
		std::string result = liveTestMtrStrVec[m_liveTestMtrIndex];
		logInfo("getLiveTestMtrStr: %s", result.c_str());
		return result;
	}*/


	static std::string getMaterialName(__int64 mtrAdd);


	static std::string getTestMaterialName();

	static bool FilterMaterialNames(__int64 matrAdd, std::string startWithFilter);


	
	static void acquiredFilteredMaterialsFromTheGame(std::string startWithfilter);


	/*static std::string debugGetMtr_Name() {
		if (!m_isdebugMatrVecInitialized) {
			logWarn("debugGetMtr_Name: m_isdebugMatrVecInitialized is false, initiliazing...");
			debugFillMatPtrVec();
			m_debugShowMaterialIndex = 0;
		}

		if (m_materialsAddrsDebugVec.size() <= 0) {
			logErr("debugGetMtr_Name: m_materialsAddrsDebugVec size is <=0 can not get mat name m_debugShowMaterialIndex: %d", m_debugShowMaterialIndex);
			return std::string();
		}
		if (!(m_debugShowMaterialIndex >= 0) || !(m_debugShowMaterialIndex < m_materialsAddrsDebugVec.size())) {
			logWarn("debugGetMtr_Name: m_debugShowMaterialIndex is out of bound: %d setting it to 0", m_debugShowMaterialIndex);
			m_debugShowMaterialIndex = 0;
		}

		__int64 matrAdd = m_materialsAddrsDebugVec[m_debugShowMaterialIndex];
		if (MemHelper::isBadReadPtr((void*)matrAdd)) {
			logErr("debugGetMtr_Name:  matrAdd: %p is bad ptr", (void*)matrAdd);
			return std::string();
		}
		return std::string((const char*)(*(uintptr_t*)(matrAdd + 0x8)));

	}*/

	//! this is used to show materials that we don't know about:
	/*static void showTestMaterialNext() {

		std::string testMtr_Name = debugGetMtr_Name();
		idCmd::showTestMaterial(testMtr_Name);
		logInfo("showTestMaterialNext: mtr name: %s (index: %d)", testMtr_Name.c_str(), m_debugShowMaterialIndex);
		m_debugShowMaterialIndex++;
	}

	static void showTestMaterialPrev() {

		std::string testMtr_Name = debugGetMtr_Name();
		idCmd::showTestMaterial(testMtr_Name);
		logInfo("showTestMaterialPrev: mtr name: %s (index: %d)", testMtr_Name.c_str(), m_debugShowMaterialIndex);
		m_debugShowMaterialIndex--;
		if (m_debugShowMaterialIndex < 0) {
			m_debugShowMaterialIndex = (int)m_materialsAddrsDebugVec.size() - 1;
		}
	}*/





};




