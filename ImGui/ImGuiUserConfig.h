#pragma once


//#include "../ImGui/dependencies/imgui/imgui.h"

//! K: this is a file that is recommended to create (read imconfig.h) that way if we ever want to update Imgui version we can keep our settings here. What we have to do is make sure have this just after the pragma once in imconfig.h: #define IMGUI_USER_CONFIG "../ImGui/ImGuiUserConfig.h" 

//#include "../ImGui/dependencies/imgui/imgui.h"
//#include "../ImGui/dependencies/imgui/imgui_impl_win32.h"


//class ImGuiConfigManager {
//public:
//	static void Init() {
//		//IMGUI_CHECKVERSION();
//		//ImGui::CreateContext();
//		ImGuiIO& io = ImGui::GetIO();
//		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
//		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
//	}
//
//};


//#include "../DE/MemHelper.h"
//
//
//using _QWORD = unsigned  long long;
//
//
//class ImGuiTest {
//private:
//
//
//	//__int64 __fastcall ImGui::LogText_1E48CE0(__int64 a1)
//	typedef __int64(__fastcall* ImGui_LogText_1E48CE0)(__int64 a1);
//
//
//public:
//
//	//? this will make the game crash, and changing the arg will still crash.
//	static void LogText() {
//		auto funcAdd = MemHelper::getFuncAddr(0x1E48CE0);
//		auto logTextFp = reinterpret_cast<ImGui_LogText_1E48CE0>(funcAdd);
//		logTextFp(0);
//		//auto cvarSys = reinterpret_cast<CvarFindAddrTest>(funcAddr);
//	}
//
//};
//





