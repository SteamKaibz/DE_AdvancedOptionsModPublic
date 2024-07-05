#pragma once


//#include "../Config/Config.h"
#include "../ImGui/dependencies/imgui/imgui.h" //! i struggled to find this freaking include....




class ImGuiDebug {
private:
	//static bool m_isRenderEnabled;

	static bool m_lastIsMouseWithinImGuiWindow;
	//static bool m_isFirtTimeWantCaptureMouse;

	/*static bool m_lastisWindowHovered;
	static bool m_isFirtTimeisWindowHovered;*/

public:


	/*static bool isRenderEnabled() {
		return m_isRenderEnabled;
		
	}*/

	static bool IsMouseWithinImGuiWindow()
	{
		// Ensure ImGui context is available
		if (ImGui::GetCurrentContext() == nullptr) {
			logInfo("GetCurrentContext is nullptr...");
			return false;
		}

		// Check if the window exists and is active
		/*if (!ImGui::IsWindowFocused()) {
			logInfo("IsWindowFocused is false...");
			return false;
		}*/

		ImVec2 windowPos = ImGui::GetWindowPos();
		ImVec2 windowSize = ImGui::GetWindowSize();
		ImVec2 mousePos = ImGui::GetMousePos();

		logInfo("windowPos: x: %.2f y: %.2f  windowSize: x: %.2f y: %.2f mousePos:  x: %.2f y: %.2f", windowPos.x, windowPos.y, windowSize.x, windowSize.y, mousePos.x, mousePos.y);
		// Debug logging
		// Log windowPos, windowSize, and mousePos to identify any issues

		if (mousePos.x >= windowPos.x && mousePos.x <= windowPos.x + windowSize.x &&
			mousePos.y >= windowPos.y && mousePos.y <= windowPos.y + windowSize.y)
		{
			logInfo("IsMouseWithinImGuiWindow: true");
			return true; // Mouse is within the ImGui window
		}
		logInfo("IsMouseWithinImGuiWindow: false");
		return false; // Mouse is outside the ImGui window
	}
	
	
	//! those don't work
	/*static void logWantCaptureMouseChange(bool isWantCaptureMouse) {
		if (m_isFirtTimeWantCaptureMouse) {
			m_lastWantCaptureMouse = isWantCaptureMouse;
			logInfo("isWantCaptureMouse is: %d", isWantCaptureMouse);
		}
		else if (isWantCaptureMouse != m_lastWantCaptureMouse ) {
			
			m_lastWantCaptureMouse = isWantCaptureMouse;
			logInfo("isWantCaptureMouse has changed to: %d", isWantCaptureMouse);
		}
		m_isFirtTimeWantCaptureMouse = false;
	}

	static void logIsWindowHovered(bool ishovered) {
		if (m_isFirtTimeisWindowHovered) {
			m_lastisWindowHovered = ishovered;
			logInfo("isWindowHovered is: %d", ishovered);
		}
		else if (ishovered != m_lastisWindowHovered) {
			m_lastisWindowHovered = ishovered;
			logInfo("isWindowHovered has changed to: %d", ishovered);
		}
		m_isFirtTimeisWindowHovered = false;
	}*/


};
 bool ImGuiDebug::m_lastIsMouseWithinImGuiWindow = false;
 //bool ImGuiDebug::m_isRenderEnabled = false;
 //bool ImGuiDebug::m_isFirtTimeWantCaptureMouse = true;

 //bool ImGuiDebug::m_lastisWindowHovered = true;
 //bool ImGuiDebug::m_isFirtTimeisWindowHovered = true;
