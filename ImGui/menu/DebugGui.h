#pragma once


#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
#include "../../Debug/ImGuiDebugWin.h"
#include "../../K_Utils/K_Utils.h"
#include "../../DE/idInventoryManager.h"

//? this include created a nigthmare, still not sure why to this day....
//qsdfqsdf#include "../../DE/idRenderModelGuiManager.h"

#include "menu.hpp"






class DebugGui
{

private:

public:
	//static void drawBg(ImVec2& window_pos, ImVec2& window_size, float bgAlpha);
	static void drawFullScreenBlackBackground(bool* p_open = NULL);
	static void showDebugWindow(bool* p_open = NULL);
	//static void showDebugWindow(bool* p_open, float bgAlpha);
	//static void showDebugWindow(float bgAlpha);
};

