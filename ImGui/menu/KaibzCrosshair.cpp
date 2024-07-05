#include "KaibzCrosshair.h"





void KaibzCrosshair::showCircleCrosshair(KaibzHudData& data)
{
    ImGuiViewport* viewport = ImGui::GetMainViewport();

    ImVec2 window_pos = ImVec2(viewport->Pos.x, viewport->Pos.y);
    ImVec2 window_size = ImVec2(viewport->Size.x, viewport->Size.y);

    ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always);
    ImGui::SetNextWindowSize(window_size);

    ImGui::SetNextWindowBgAlpha(0.0f);

    if (ImGui::Begin("customcrosshair", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoBackground))
    {

        static float outlineThickness = 1.0f; // Initial outline thickness  

        // Calculate crosshair position and size
        ImVec2 crosshairPos = ImVec2(window_size.x / 2.0f, window_size.y / 2.0f);

        // Draw crosshair outline
        ImDrawList* drawList = ImGui::GetWindowDrawList();
        drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix() + outlineThickness, outlineColorImU32); // Outer background. always black  


        if (CustomCrosshairManager::getIsWeaponCooldownFlag()) {           
            drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix(), modSettings::getCustomDotCrosshairCooldownColorImU32()); // Inner crosshair
        }

        else if (modSettings::getCustomCrosshairIsShowHealthAsColor()) {
            drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix(), data.crosshairHealthColorImU32);
        }

        else {
            drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix(), modSettings::getCustomDotCrosshairColorImU32()); // Inner crosshair
        }
    }
    ImGui::End();
}


//! BAK
//void KaibzCrosshair::showCircleCrosshair(bool* p_open)
//{
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
//    if (ImGui::Begin("customcrosshair", p_open, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoBackground))
//    {
//
//        static float outlineThickness = 1.0f; // Initial outline thickness  
//
//        // Calculate crosshair position and size
//        ImVec2 crosshairPos = ImVec2(window_size.x / 2.0f, window_size.y / 2.0f);
//
//        // Draw crosshair outline
//        ImDrawList* drawList = ImGui::GetWindowDrawList();
//        drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix() + outlineThickness, outlineColorImU32); // Outer background. always black  
//
//
//        if (CustomCrosshairManager::getIsWeaponCooldownFlag()) {
//            drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix(), modSettings::getCustomDotCrosshairCooldownColorImU32()); // Inner crosshair
//        }
//
//        /* else if (modSettings::getCustomCrosshairIsShowHealthAsColor()) {
//             drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix(), );
//         }*/
//
//        else {
//            drawList->AddCircleFilled(crosshairPos, modSettings::getImguiCustomDotCrosshairRadiusPix(), modSettings::getCustomDotCrosshairColorImU32()); // Inner crosshair
//        }
//    }
//    ImGui::End();
//}

