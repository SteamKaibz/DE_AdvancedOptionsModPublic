//#pragma once
//
//
//#include "PlayerStateChecker.h"
//#include "MaterialLib.h"
//#include "drawStretchPicHookArgs.h"
//#include "drawStringHookArgs.h"
//
//#include "GameHudColorsManager.h"
//#include "../Hud/HudAmmoData.h"
//
///// <summary>
///// This is not what it may sound like, this is what holds at offset 0xD8 a ptr to a idRenderModelGui obj that displays all the info about perf metrics when it's enabled. We can't use it however to render strings/shape directly cause it will have perf impact so we have to hook drawstring/stretchPic to be able to display things on the hud without (hopefully) performance losses.
///// </summary>
////! so it looks like we can change the font when the console is opened and all the current and past text will be readable, now we need to implement it.
////todo when enabling our custom crosshair we want to set the game settings to crosshair dot + override crosshair to zero so the dot doesn't show up. then if user disables our custom crosshair we set crosshair overide to -1 and disable our custom crosshair display
////! Update: this is not used as it used to before because there is a big performance loss using this system that i didn't notive before somehow...Also the alternative we found of using the render_gTestMaterial doesn't have a perf loss that is that important. It's kind of a relief we don't use this class as it was so bloated. However we still use the console opened/close detection to set the right font so the console can be readable.
//class idConsoleLocalManager {
//
//private:
//
//
//	static __int64 m_idConsoleAddr;
//
//	static const float m_perfMetricsFPSstringScale; //! this is harcoded in the game and a "hacky and fragile" way to identify the FPS string
//
//	//! set to true when GetPerfMetricsStr_Smth_48FE40 is called
//	bool m_renderStretchedPicFlag = false;
//
//	bool m_renderDrawStringFlag = false;
//
//	int m_drawStringFuncCalledCounter = 0;
//
//	//! if user has selected custom crosshair in the ini file instead of the default game's ones.
//	bool m_isShowCustomCrosshair = false;
//
//	//! used to keep track of which custom pics should be drawn and if we're done drawing custom pics
//	int m_drawStretchPicIndex = 0;
//
//	//! keeping track on which string to render and when we can give control back to the game
//	int m_drawStringIndex = 0;
//
//
//	const float m_epsilon = 0.001f; //! used for float comparison
//
//	
//
//
//public:
//
//	static __int64 getStaticWhiteMatrAddr();
//
//	static std::string getEmptyString();
//
//	
//
//
//	static bool isConsoleOpened();
//
//
//
//	//! we let the user get the FPS display on the hud
//	static bool isRenderFpsCounter(float stringScaleFloat) {
//		return stringScaleFloat == m_perfMetricsFPSstringScale;
//
//	}
//
//	void reset() {
//		m_drawStringFuncCalledCounter = 0;
//		m_drawStretchPicIndex = 0;
//		m_drawStringIndex = 0;
//		m_renderDrawStringFlag = 0;
//		m_renderStretchedPicFlag = 0;
//	}
//
//	bool isShowCustomCrosshair() {
//		return m_isShowCustomCrosshair;
//	}
//
//	bool isRenderStretchedPicFlag() {
//		return m_renderStretchedPicFlag;
//	}
//
//
//	void raiseRenderStretchedPicFlag() {
//		m_renderStretchedPicFlag = true;
//	}
//
//	bool isRenderStringFlag() {
//		return m_renderDrawStringFlag;
//	}
//
//	//! this flag basically starts the rendering of all of our custom hud elements (crosshair, strings)
//	void raiseRenderDrawStringFlag() { //! the order here is important....
//		reset();
//		m_renderDrawStringFlag = true;
//
//	}
//
//	void incrementDrawStringFuncCalledCounter() {
//		m_drawStringFuncCalledCounter += 1;
//	}
//
//	//! from my logs, when perf metrics on ultra nightmare drawstring is called 38 times. but has the graph so big no no.
//	void resetDrawStringFuncCalledCounter() {
//		logInfo("resetDrawStringFuncCalledCounter: DrawStringFunc was called: %d times", m_drawStringFuncCalledCounter);
//		m_drawStringFuncCalledCounter = 0;
//	}
//
//
//
//
//};
//
//__int64 idConsoleLocalManager::m_idConsoleAddr = 0;
//const float idConsoleLocalManager::m_perfMetricsFPSstringScale = 1.75f;;
//
