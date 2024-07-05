#include "GoToSettingsGui.h"





void GoToSettingsGui::showModKeyShortcutText(bool* p_open)
{ 

    //static ImVec4 textColor = guiHelper::lightgrayColor;
    //static unsigned int lastToggleModSettingsVkCode = -1;

    ImGuiIO& io = ImGui::GetIO();
    ImGuiViewport* viewport = ImGui::GetMainViewport();

    //! this is what prevent the text not being showed if game is not focused when mod loads.
    if (viewport->Size.x <= 0 || viewport->Size.y <= 0) {
        // Delay rendering the window until the viewport size becomes valid
        return;
    }


    static std::string ToggleModTextStr = "KAIBZ MOD [???]";
    ToggleModTextStr = "KAIBZ MOD [" + std::string(guiHelper::getAllowedKeyName(modSettings::getToggleModSettingsVkCode())) + "]";   


    ImVec2 textSize = ImGui::CalcTextSize(ToggleModTextStr.c_str(), nullptr, true);
    float textPaddingX = 1.05f; //! manually adjusted
    float textPaddingY = 1.3f; //! manually adjusted

    //logInfo("showModKeyShortcutText: textSize.x %.3f textSize.y %.3f", textSize.x, textSize.y);

    // Set window size to match viewport size
    ImVec2 windowSize = ImVec2(viewport->Size.x, viewport->Size.y);

    //logInfo("showModKeyShortcutText: viewport->Size.x %.3f viewport->Size.y %.3f", viewport->Size.x, viewport->Size.y);

    float windowPosX = viewport->Pos.x;
    float windowPosY = viewport->Pos.y;

   /* logInfo("showModKeyShortcutText: windowPosX %.3f windowPosY %.3f", windowPosX, windowPosY);*/

    ImGui::SetNextWindowPos(ImVec2(windowPosX, windowPosY), ImGuiCond_Always);

    ImGui::Begin("GoToSettingsGui", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus |        ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar);

    // Calculate text position relative to windowSize to allow free movement within viewport
    ImVec2 textPos = ImVec2(windowSize.x - textSize.x * textPaddingX, windowSize.y - textSize.y * textPaddingY);
    ImGui::SetCursorPos(textPos);

    //logInfo("showModKeyShortcutText: textPos.x %.3f textPos.y %.3f", textPos.x, textPos.y);


   /* if (modSettings::getModSettingsShortcutTextColorInt() != lastModSettingsColorInt) {

        textColor = modSettings::ConvertIntToImVec4Color(modSettings::getModSettingsShortcutTextColorInt());
        lastModSettingsColorInt = modSettings::getModSettingsShortcutTextColorInt();
    }*/
  
    ImGui::PushFont(Menu::customHud_Eternal1font); // Set the custom font
    //ImGui::PushStyleColor(ImGuiCol_Text, textColor);
   //ImGui::PushStyleColor(ImGuiCol_Text, Menu::shortcutTextColorImVec4);
    ImGui::PushStyleColor(ImGuiCol_Text, ImGui::ColorConvertU32ToFloat4(modSettings::getModSettingsShortcutTextColorImU32()));

    ImGui::Text(ToggleModTextStr.c_str());

    ImGui::PopFont(); // Restore default font
    ImGui::PopStyleColor();  // Restore text color

    ImGui::End();    

}





//bool GoToSettingsGui::isInsideRect(const ImVec2& point, const ImVec2& topLeft, const ImVec2& bottomRight) {
//    return point.x >= topLeft.x && point.x <= bottomRight.x &&
//        point.y >= topLeft.y && point.y <= bottomRight.y;
//}


//void GoToSettingsGui::showGoToSettingsButtonGui(bool* p_open)
//{
//    ImGuiIO& io = ImGui::GetIO();
//    ImGuiViewport* viewport = ImGui::GetMainViewport();
//
//    ImGuiStyle& style = ImGui::GetStyle();
//    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));  // Transparent background
//
//    std::string ModButtonStr = "Kaibz Mod Settings";
//
//    ImVec2 textSize = ImGui::CalcTextSize(ModButtonStr.c_str(), nullptr, true);
//    ImVec2 windowSize = ImVec2(textSize.x * 1.1f, textSize.y * 1.1f);
//    float windowPosX = viewport->Pos.x + viewport->Size.x - windowSize.x;
//    float windowPosY = viewport->Pos.y + viewport->Size.y - windowSize.y;
//
//    ImGui::SetNextWindowPos(ImVec2(windowPosX, windowPosY), ImGuiCond_Always);
//
//    ImVec2 buttonSize = ImVec2(textSize.x + style.FramePadding.x * 2, textSize.y + style.FramePadding.y * 2);
//
//
//    //? not having ImGuiWindowFlags_NoBringToFrontOnFocus changed nothing regarding the clickability of btn on the main page if in_mouse is 1.
//    //ImGui::Begin("GoToSettingsGui", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground);
//       
//    ImGui::Begin("GoToSettingsGui", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground);
//
//    ImVec2 buttonPos = ImVec2((windowSize.x - buttonSize.x) * 0.5f, (windowSize.y - buttonSize.y) * 0.5f);
//
//    ImGui::SetCursorPos(buttonPos);
//
//    if (ImGui::Button(ModButtonStr.c_str(), buttonSize)) {
//        logInfo("mod settings btn pressed, setting Menu::bShowMenu to true");
//        Menu::bShowMenu = true;
//    }
//
//    // Calculate and log the coordinates of the four extremities of the button
//    /*ImVec2 topLeft = ImVec2(windowPosX + buttonPos.x, windowPosY + buttonPos.y);
//    ImVec2 topRight = ImVec2(topLeft.x + buttonSize.x, topLeft.y);
//    ImVec2 bottomLeft = ImVec2(topLeft.x, topLeft.y + buttonSize.y);
//    ImVec2 bottomRight = ImVec2(topRight.x, bottomLeft.y);
//
//    logInfo("Top-Left Corner: x = %f, y = %f", topLeft.x, topLeft.y);
//    logInfo("Top-Right Corner: x = %f, y = %f", topRight.x, topRight.y);
//    logInfo("Bottom-Left Corner: x = %f, y = %f", bottomLeft.x, bottomLeft.y);
//    logInfo("Bottom-Right Corner: x = %f, y = %f", bottomRight.x, bottomRight.y);*/
//
//    ImGui::PopStyleColor();
//    ImGui::End();
//}





//void GoToSettingsGui::showGoToSettingsButtonGui(bool* p_open)
//{
//    ImGuiIO& io = ImGui::GetIO();
//    //io.MouseDown[0] = InputManager::isMouse1Pressed;
//
//    ImGuiViewport* viewport = ImGui::GetMainViewport();
//
//    ImGuiStyle& style = ImGui::GetStyle();
//    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));  // Transparent background
//
//    // Modify button background color to dark gray
//    style.Colors[ImGuiCol_Button] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f); // Dark gray
//    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f); // Slightly lighter dark gray when hovered
//    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f); // Even darker when pressed
//
//    std::string ModButtonStr = "Kaibz Mod Settings";
//
//    // Calculate the size of the button text dynamically based on the current screen resolution
//    ImVec2 textSize = ImGui::CalcTextSize(ModButtonStr.c_str(), nullptr, true);
//
//    // Increase the window size slightly for better aesthetics
//    ImVec2 windowSize = ImVec2(textSize.x * 1.1f, textSize.y * 1.1f);
//    float windowPosX = viewport->Pos.x + viewport->Size.x - windowSize.x * 1.1f;
//    float windowPosY = viewport->Pos.y + viewport->Size.y - windowSize.y * 1.5f;
//
//    ImGui::SetNextWindowPos(ImVec2(windowPosX, windowPosY), ImGuiCond_Always);
//
//    // Adjust button size to accommodate text size and padding
//    ImVec2 buttonSize = ImVec2(textSize.x + style.FramePadding.x * 2, textSize.y + style.FramePadding.y * 2);
//
//    // Create the window without a background
//    ImGui::Begin("GoToSettingsGui", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground);
//
//    // Calculate the button position to center the text vertically
//    ImVec2 buttonPos = ImVec2(windowSize.x - buttonSize.x, windowSize.y - buttonSize.y);
//    buttonPos.y += (buttonSize.y - textSize.y) * 0.5f;  // Adjust for vertical centering
//
//    // Set cursor position to align the button
//    ImGui::SetCursorPos(buttonPos);
//
//    //! this will never be true as long as in_mouse is 1
//   /* if (io.WantCaptureMouse) {
//        logInfo("showGoToSettingsButtonGui : io.WantCaptureMouse is true");
//    }*/
//
//    if (ImGui::Button(ModButtonStr.c_str(), buttonSize)) {
//        logInfo("mod settings btn pressed, setting Menu::bShowMenu to true");
//        Menu::bShowMenu = true;
//    }
//
//    // Calculate and log the coordinates of the four extremities of the button
//    ImVec2 topLeft = buttonPos;
//    ImVec2 topRight = ImVec2(buttonPos.x + buttonSize.x, buttonPos.y);
//    ImVec2 bottomLeft = ImVec2(buttonPos.x, buttonPos.y + buttonSize.y);
//    ImVec2 bottomRight = ImVec2(buttonPos.x + buttonSize.x, buttonPos.y + buttonSize.y);
//
//    logInfo("Top-Left Corner: x = %f, y = %f", topLeft.x, topLeft.y);
//    logInfo("Top-Right Corner: x = %f, y = %f", topRight.x, topRight.y);
//    logInfo("Bottom-Left Corner: x = %f, y = %f", bottomLeft.x, bottomLeft.y);
//    logInfo("Bottom-Right Corner: x = %f, y = %f", bottomRight.x, bottomRight.y);
//
//    //! we can't use this the get the cursor position as long as the game control it...
//   /* ImVec2 currentCursorPos = ImGui::GetCursorPos();
//    logInfo("Current Cursor Position: x = %f, y = %f", currentCursorPos.x, currentCursorPos.y);*/
//
//    // Restore the default window background color
//    ImGui::PopStyleColor();
//
//    // End the window
//    ImGui::End();
//}



