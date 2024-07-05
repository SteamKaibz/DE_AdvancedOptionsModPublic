#pragma once

#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
#include "menu.hpp"
#include "guiHelpers.h"


class GoToSettingsGui
{

private:

	//static bool m_isdebugConfigWarning;

public:

	//static bool isInsideRect(const ImVec2& point, const ImVec2& topLeft, const ImVec2& bottomRight);

	//static void setIsDebugConfigWarning(ModConfig modConfig);
	//static void showGoToSettingsButtonGui(bool* p_open = NULL);
	static void showModKeyShortcutText(bool* p_open = NULL);
};

