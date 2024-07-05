#pragma once

#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
//#include "menu.hpp"
#include "../../Debug/ImGuiDebugWin.h"
#include "../../K_Utils/K_Utils.h"
#include "../../DE/idInventoryManager.h"
#include "../../Hud/CustomCrosshairManager.h"


class KaibzCrosshair
{
private:

	/*static inline ImU32 fillColorImU32 = IM_COL32(255, 255, 255, 255);
	static inline ImU32 fillCooldownColorImU32 = IM_COL32(255, 0, 0, 255);*/
	static inline ImU32 outlineColorImU32 = IM_COL32(0, 0, 0, 255);

public:

	static void showCircleCrosshair(KaibzHudData& data);
	//static void showCircleCrosshair(bool* p_open = NULL);


};

