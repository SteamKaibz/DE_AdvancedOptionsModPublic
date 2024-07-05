#pragma once


#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
#include "menu.hpp"
#include "../../Debug/ImGuiDebugWin.h"
#include "../../K_Utils/K_Utils.h"
#include "../../DE/idInventoryManager.h"
#include "../../Hud/CustomCrosshairManager.h"
#include "../../Hud/KaibzHudManager.h"


class KaibzHud
{

private:

public:	

	static void DebugShowAllIcons();

	static std::string getPaddedString(int value, size_t width);
	
	//static ImVec2 safeGuardHudPos(ImVec2 hudPosVec2, ImVec2 displayeSize);

	static ImVec2 computeHudPos(float hudSizeX, ImVec2 zeroCharSize, float heightSafepaddingMul);

	static ImVec4 getElementColor(KaibzHudColor_t hudColor, int outlineRef);

	static void writePaddedNumberALT(std::string paddedStr, float zeroCharWidth, KaibzHudColor_t hudColor, int outlineRef);


	//static void writePaddedNumber(std::string paddedStr, float zeroCharWidth, ImVec4 color, int outlineRef);

	static void adjustSize(ImVec2& coordsVec2, float mul);

	static void drawHudBg(KaibzHudData& dataRef, ImVec2 hudStartVec2, float hudSizeX, float zeroCharSizeY, float alpha);

	static void drawCoolDownCircleV2(ImVec2 centerCoords, float radius, float progress, ImU32 colorImU32);

	//static void drawCoolDownCircle(ImVec2 centerCoords, float radius, int segments, float progress);

	static void drawSlayerHud(KaibzHudData& data, int outlineRef);

	static void drawDemonHud(KaibzHudData& data, int outlineRef);

	static void showCustomHud(KaibzHudData& data);
	//static void showCustomHud(bool* p_open = NULL);
};

