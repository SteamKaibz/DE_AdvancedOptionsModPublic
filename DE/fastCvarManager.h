#pragma once

#include "MemHelper.h"
#include "idCvarManager.h"
#include "GeneratedClasses.h"



/// <summary>
/// getting the cvar ptr to get access to its value faster, this should only be used to READ value. NOT to set them cause each cvars has flags and also callback funtions for some cvars.
/// </summary>
class fastCvarManager
{
private:


	static inline idCVar* m_reticleModeCvarPtr = nullptr;
	static inline idCVar* m_enableGameTimeScalingCvarPtr = nullptr;
	static inline idCVar* m_in_mouseCvarPtr = nullptr;
	static inline idCVar* m_swf_colorProfileCvarPtr = nullptr;
	static inline idCVar* m_g_setting_hud_showCvarPtr = nullptr;
	static inline idCVar* m_g_setting_equipment_infoCvarPtr = nullptr;
	static inline idCVar* m_r_windowWidthCvarPtr = nullptr;
	static inline idCVar* m_r_windowHeightCvarPtr = nullptr;
	static inline idCVar* m_sys_langCvarPtr = nullptr;
	static inline idCVar* m_r_antialiasingCvarPtr = nullptr;


public:



	static bool cacheCriticalCvars();

	static UI_ReticleMode getReticleMode();

	static bool isGameTimeScalingEnabled();

	static bool isMouseInputEnabled();

	static int getColorProfileIndex();

	static bool getIsShowHudEnabled(); //! this corresponds to the game seetings hud croshair only or Full

	static bool getIsEquipmentInfoEnabled();

	//? those 2 will be 0 when in fullscreen.
	static int getWindowWidthInt();
	static int getWindowHeightInt();

	static std::string getLang();

	static antialiasingLevel getCurAntiAliasLevel();

	static std::string getDbgStrFromImgui();

};

