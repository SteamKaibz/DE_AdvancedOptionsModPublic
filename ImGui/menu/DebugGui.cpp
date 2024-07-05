#include "DebugGui.h"



void DebugGui::drawFullScreenBlackBackground(bool* p_open) {
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 window_pos = ImVec2(viewport->Pos.x, viewport->Pos.y);
    ImVec2 window_size = ImVec2(viewport->Size.x, viewport->Size.y);

    ImGui::GetWindowDrawList()->AddRectFilled(window_pos, window_size, IM_COL32(0, 0, 0, 255));
}


//void DebugGui::drawBg(ImVec2& window_pos, ImVec2& window_size, float bgAlpha) {
//
//    logInfo("drawBg: window_pos.x: %.3f window_pos.y: %.3f window_size.x: %.3f window_size.x: %.3f", window_pos.x, window_pos.y, window_size.x, window_size.y);
//
//    ImU32 bgColor = IM_COL32(0, 0, 0, (int)(bgAlpha * 255));
//
//    ImDrawList* drawList = ImGui::GetWindowDrawList();
//
//    // Draw background rectangle
//    drawList->AddRectFilled(window_pos, window_size, bgColor);
//}


//! drawing text with outline, it works but there is a small issue with lines spacing
void DebugGui::showDebugWindow(bool* p_open) {

    ImGuiViewport* viewport = ImGui::GetMainViewport();

    if (viewport->Size.x <= 0 || viewport->Size.y <= 0) {
        // Delay rendering the window until the viewport size becomes valid
        return;
    }

    ImGui::PushFont(Menu::debugWindow_font);

    ImGuiDebugWin::ClearMessages();
    ImGuiDebugWin::AddMessage("DEBUG GUI:\n");   

    //? keep those comments:
    //ImGuiDebugWin::AddMessage(idPlayer_K::getDbgStrForImgui());
    //ImGuiDebugWin::AddMessage(idHudManager::getDdgStrForImgui());  
    //ImGuiDebugWin::AddMessage(PlayerStateChecker::getDbgStrForImgui());
    //ImGuiDebugWin::AddMessage(KaibzHudManager::getDdgStrForImgui());
    ImGuiDebugWin::AddMessage(fastCvarManager::getDbgStrFromImgui());
    //ImGuiDebugWin::AddMessage(idInventoryCollectionManager::getDebugStr()); 

    //ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 window_pos = ImVec2(viewport->Pos.x, viewport->Pos.y);
    ImVec2 window_size = ImVec2(viewport->Size.x, viewport->Size.y);

    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always);
   
    //ImGui::SetNextWindowSize(window_size);

    float bgAlpha = .5f;
    ImGui::SetNextWindowBgAlpha(bgAlpha);

    if (ImGui::Begin("Debug Window", p_open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |  ImGuiWindowFlags_NoScrollbar)) {
    //if (ImGui::Begin("Debug Window", p_open, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoBackground)) {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Outline color

        ImVec2 cursorPos = ImGui::GetCursorPos();

        // Draw the text with a slight offset for the outline effect
        for (const auto& msg : ImGuiDebugWin::getMessages()) {
            ImGui::TextWrapped(msg.c_str());
            //ImGui::SameLine();
        }

        ImGui::PopStyleColor();

        // Draw the main text
        ImGui::SetCursorPosX(cursorPos.x - 2.0f); // Offset by 1 pixel to the left
        ImGui::SetCursorPosY(cursorPos.y - 2.0f); // Offset by 1 pixel upwards
        for (const auto& msg : ImGuiDebugWin::getMessages()) {
            ImGui::TextWrapped(msg.c_str());
            //ImGui::SameLine();
        }
    }

    ImGui::PopFont();
    ImGui::End();
}




//void DebugGui::showDebugWindow(bool* p_open)
//{
//    ImGui::PushFont(Menu::debugWindow_font);  
//
//   
//    ImGuiDebugWin::ClearMessages();
//
//    ImGuiDebugWin::AddMessage("DEBUG GUI:\n");
//
//    //? keep those comments:
//    ImGuiDebugWin::AddMessage(idPlayer_K::getDbgStrForImgui());
//    ImGuiDebugWin::AddMessage(idHudManager::getDdgStrForImgui());  
//    ImGuiDebugWin::AddMessage(PlayerStateChecker::getDbgStrForImgui());
//    ImGuiDebugWin::AddMessage(KaibzHudManager::getDdgStrForImgui());
//    //ImGuiDebugWin::AddMessage(idInventoryCollectionManager::getDebugStr()); 
//
//
//
//    ImGuiViewport* viewport = ImGui::GetMainViewport();
//
//    ImVec2 window_pos = ImVec2(viewport->Pos.x, viewport->Pos.y);
//    ImVec2 window_size = ImVec2(viewport->Size.x, viewport->Size.y);
//
//    ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always);
//    ImGui::SetNextWindowSize(window_size);
//
//    ImGui::SetNextWindowBgAlpha(0.0f);   
//
//    if (ImGui::Begin("Debug Window", p_open, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoBackground))
//    {
//        for (const auto& msg : ImGuiDebugWin::getMessages()) {
//            //ImGui::TextUnformatted(msg.c_str());
//            ImGui::TextWrapped(msg.c_str());
//        }
//    }
//
//
//    ImGui::PopFont();      
//
//    ImGui::End();
//   
//}
