#pragma once

//#include <MinHook.h>
//
//#include "../ModSettings/ModSettings.h"
//#include "../Config/Config.h"
//#include "../MinHookManager/MinHookManager.h"
//#include "../ImGui/menu/menu.hpp"
//
//#include "../ImGui/console/console.hpp"
//#include "../ImGui/hooks/hooks.hpp"
//#include "../ImGui/utils/utils.hpp"
//#include "../ImGui/dependencies/minhook/MinHook.h"
//#include "../dllmain.h"



//#include "../Config/Config.h"
//#include "MenuStateManager.h"
//#include "idCvarManager.h"
//#include "../ImGui/dependencies/imgui/imgui.h"
////#include "../ModSettings/ModSettings.h"
//#include "../ModSettings/ModSettingsManager.h"


#include "../Config/Config.h"





class ImGuiManager
{

private:

	//static bool m_isInitialized;
	static bool m_isInitFlag;
	static bool m_isOneInitAttempt;

	static bool m_isUserForceOpenModMenu;

	//static bool m_isShowModMenuUserRequest;
	//static bool m_isShowModMenu; //! this should be handle by Menu::bShowMenu in hooks.cpp

	//static bool m_isShowDebugWindow;


public:
	

	//static bool isInitialized();
	static void setIsInitFlag(bool isInitFlag);

	static bool isInitFlag();

	//! we don't want to try init imgui more than once
	static void setInitAttempt();

	static bool isPreviousInitAttempt();

	static void toggleForceOpenMenuState();

	static bool isUserForceOpenModMenu();

	//static void init();

};

