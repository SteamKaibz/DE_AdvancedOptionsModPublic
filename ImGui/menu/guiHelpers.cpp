#include "guiHelpers.h"




const char* guiHelper::getAllowedKeyName(unsigned int vkCode)
{
    for (const auto& key : allowedKeyBindsKeyInfos)
    {
        if (key.vkCode == vkCode)
        {
            return key.name;
        }
    }
    logErr("getAllowedKeyName: failed to find str for key code: %u vkCode", vkCode);
    return "???";
}




void guiHelper::ShowTooltip(const char* tooltip) {
    ImGui::BeginTooltip();
    ImGui::Text("%s", tooltip);
    ImGui::EndTooltip();
}


void guiHelper::insertToolTipSameLine(const char* tooltipText) {
    ImGui::SameLine();
    ImGui::Text("  ");
    ImGui::SameLine();
    ImGui::Text("[?]");
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip(tooltipText);
    }
}


// Function to parse the font file and extract icon codes
//std::vector<std::string> guiHelper::parseFontFile(const std::string& filename) {
//    std::vector<std::string> icons;
//    std::ifstream file(filename, std::ios::binary); // Open file in binary mode
//
//    if (!file.is_open()) {
//        std::cerr << "Unable to open file: " << filename << std::endl;
//        return icons;
//    }
//
//    std::stringstream buffer;
//    buffer << file.rdbuf(); // Read entire file into stringstream
//    file.close(); // Close file
//
//    std::string line;
//    while (std::getline(buffer, line)) {
//        // Assuming each line contains an icon definition like ICON_FA_ICON_NAME "\xef\x99\x80"
//        std::string iconCode = line.substr(line.find("\\x") + 2, 4);
//        icons.push_back(iconCode);
//    }
//
//    return icons;
//}


std::vector<std::pair<std::string, std::string>> guiHelper::parseFontAwesomeFile(const std::string& filename) {
    std::vector<std::pair<std::string, std::string>> icons;

    std::ifstream file(filename);
    if (!file.is_open()) {
        // Handle file opening error
        return icons;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        if (std::getline(iss, token, '\"')) {
            std::string iconName = token;
            if (std::getline(iss, token, '\"')) {
                std::string unicodeString = token;
                icons.emplace_back(iconName, unicodeString);
            }
        }
    }

    return icons;
}


std::string guiHelper::removeDefineAndSpaces(const std::string& input) {
    // Find the position of the first non-space character
    auto start = std::find_if_not(input.begin(), input.end(), isspace);

    // Remove '#define' if present
    if (input.substr(start - input.begin(), 7) == "#define") {
        start += 7; // Skip '#define'
    }

    // Remove all spaces
    std::string result;
    std::remove_copy_if(start, input.end(), std::back_inserter(result), isspace);

    return result;
}


float guiHelper::getSafeFontSize(float fontSize) {
    if (fontSize > modSettingsDefault::g_defaultKaibzHudFontSizeMax) {
        return modSettingsDefault::g_defaultKaibzHudFontSizeMax;
    }
    else if (fontSize < modSettingsDefault::g_defaultKaibzHudFontSizeMin) {
        return modSettingsDefault::g_defaultKaibzHudFontSizeMin;
    }
    return fontSize;
}



float guiHelper::computeNegativeSpacing(float fontSize) {
   
    
    return -.1f * fontSize;
    
    //! i just fed gpt with: font spacing for a font size of 22, i need a spacing of -16, for a font size of 44 i need a spacing of -22
    // Slope of the line
    //float m = -3.0f / 11.0f;

    //// Y-intercept of the line
    //float b = -10.0f;

    //// Compute negative spacing using the formula
    //float negativeSpacing = m * fontSize + b;

    //return negativeSpacing;
}


//void guiHelper::addDummySpacing(float spacingPix) {
//
//    ImGui::Dummy(ImVec2(spacingPix, 0));
//}


//float guiHelper::getHudIconsExtraSpacing(float currentFontSize) {
//
//    const float baseFontSize = 22.0f;
//    const float baseNegativeSpacing = -16.0f; //! this is the val that works for a font of 22.0f
//
//    // Calculate the scaling factor based on the current font size
//    float fontSizeScale = currentFontSize / baseFontSize;
//
//    return baseNegativeSpacing * fontSizeScale;
//}





float guiHelper::computeHudIconOffset_Y(float eternalTextFontSize, float hudIconFontSize)
{
    float offset = (eternalTextFontSize - hudIconFontSize) / 2.0f;
    int roundedOffset = static_cast<int>(offset);
    if (roundedOffset % 2 != 0) {
        roundedOffset--; // Adjust down to the nearest even number
    }
    return (float)roundedOffset;
}


bool guiHelper::startsWithOne(const std::string& str) {
    return !str.empty() && str[0] == '1';
}

//float guiHelper::computeHudIconOffset_Y(float eternalTextFontSize, float hudIconFontSize)
//{
//    return (eternalTextFontSize - hudIconFontSize) / 2.0f;
//}




//std::vector<std::string> guiHelper::parseIconDefinitions(const std::string& filename) {
//    std::ifstream file(filename);
//    std::vector<std::string> icons;
//
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            if (line.find("#define ICON_FA_") != std::string::npos) {
//                size_t start = line.find("\"");
//                size_t end = line.find("\"", start + 1);
//                if (start != std::string::npos && end != std::string::npos) {
//                    std::string icon = line.substr(start + 1, end - start - 1);
//                    icons.push_back(icon);
//                }
//            }
//        }
//        file.close();
//    }
//
//    return icons;
//}



//// Function to display icons in ImGui
//void guiHelper::displayIcons(const std::vector<std::string>& icons) {
//    // Iterate through the list of icon codes and display them in ImGui
//    for (const auto& icon : icons) {
//        logInfo("displayIcons: debug, icon str: %s", icon.c_str());
//        ImGui::Text("%s", icon.c_str());
//    }
//}



//std::string guiHelper::hexToUtf8(const std::string& hex) {
//    std::string utf8String;
//    for (size_t i = 0; i < hex.length(); i += 4) {
//        unsigned int codepoint;
//        sscanf(hex.substr(i, 4).c_str(), "%x", &codepoint);
//        utf8String += static_cast<char>((codepoint >> 16) & 0xFF);
//        utf8String += static_cast<char>((codepoint >> 8) & 0xFF);
//        utf8String += static_cast<char>(codepoint & 0xFF);
//    }
//    return utf8String;
//}

 /*std::string guiHelper::hexToUtf8(const std::string& hex) {
    std::stringstream ss;
    for (size_t i = 0; i < hex.length(); i += 4) {
        unsigned int codepoint;
        std::stringstream(hex.substr(i, 4)) >> std::hex >> codepoint;
        ss << static_cast<char>((codepoint >> 12) | 0xE0);
        ss << static_cast<char>(((codepoint >> 6) & 0x3F) | 0x80);
        ss << static_cast<char>((codepoint & 0x3F) | 0x80);
    }
    return ss.str();
}*/



//void guiHelper::renderAllAwesomeFontIcons() {
//    // Assume `icons` is an array containing all the icon strings
//    const char* icons[] = {
//        ICON_FA_ABACUS, ICON_FA_ACORN, ICON_FA_AD, /* Add all icons here */
//    };
//    const int numIcons = sizeof(icons) / sizeof(icons[0]);
//
//    for (int i = 0; i < numIcons; ++i) {
//        ImGui::Text("(%s) %s", icons[i]);
//    }
//}


//void guiHelper::DrawWeaponSettings(customizedWeapon* weapon) {
//    ImGui::Text("Name: %s", weapon->name.c_str());
//    ImGui::SliderFloat(("Hands FOV Scale##" + weapon->name).c_str(), &weapon->handsFovScale, 0.0f, 1.0f);
//    ImGui::Checkbox(("Remove Zoom##" + weapon->name).c_str(), &weapon->isRemoveZoom);
//    ImGui::SliderFloat(("Zoomed Hands FOV##" + weapon->name).c_str(), &weapon->zoomedHandsFOV, 0.0f, 100.0f);
//    ImGui::SliderFloat(("Zoomed FOV##" + weapon->name).c_str(), &weapon->zoomedFOV, 0.0f, 100.0f);
//    ImGui::SliderFloat(("Mouse ADS Sens Scale##" + weapon->name).c_str(), &weapon->mouseADSSensScale, 0.0f, 2.0f);
//    ImGui::SliderFloat(("Controller ADS Sens Scale##" + weapon->name).c_str(), &weapon->controllerADSSensSclae, 0.0f, 2.0f);
//    ImGui::SliderInt(("Reticle Style##" + weapon->name).c_str(), &weapon->reticleStyleInt, 0, 3);
//    ImGui::SliderInt(("Reticle Style ADS##" + weapon->name).c_str(), &weapon->reticleStyleADSInt, 0, 3);
//    ImGui::SliderFloat(("Reticle Scale##" + weapon->name).c_str(), &weapon->reticleScale, 0.0f, 1.0f);
//    ImGui::SliderFloat(("Reticle Secondary Scale##" + weapon->name).c_str(), &weapon->reticleSecondaryScale, 0.0f, 1.0f);
//    ImGui::ColorEdit3(("Reticle Dot Color##" + weapon->name).c_str(), (float*)&weapon->reticleDotColorPacked);
//    ImGui::ColorEdit3(("Reticle Dot Cool Down Color##" + weapon->name).c_str(), (float*)&weapon->reticleDotCoolDownColorPacked);
//}

//// Draw settings for a single weapon
//void guiHelper::DrawWeaponSettings(customizedWeapon weapon) {
//    ImGui::Text("Name: %s", weapon.name.c_str());
//    ImGui::SliderFloat("Hands FOV Scale", &weapon.handsFovScale, 0.0f, 1.0f);
//    ImGui::Checkbox("Remove Zoom", &weapon.isRemoveZoom);
//    ImGui::SliderFloat("Zoomed Hands FOV", &weapon.zoomedHandsFOV, 0.0f, 100.0f);
//    ImGui::SliderFloat("Zoomed FOV", &weapon.zoomedFOV, 0.0f, 100.0f);
//    ImGui::SliderFloat("Mouse ADS Sens Scale", &weapon.mouseADSSensScale, 0.0f, 2.0f);
//    ImGui::SliderFloat("Controller ADS Sens Scale", &weapon.controllerADSSensSclae, 0.0f, 2.0f);
//    ImGui::SliderInt("Reticle Style", &weapon.reticleStyleInt, 0, 3);
//    ImGui::SliderInt("Reticle Style ADS", &weapon.reticleStyleADSInt, 0, 3);
//    ImGui::SliderFloat("Reticle Scale", &weapon.reticleScale, 0.0f, 1.0f);
//    ImGui::SliderFloat("Reticle Secondary Scale", &weapon.reticleSecondaryScale, 0.0f, 1.0f);
///*    ImGui::ColorEdit3("Reticle Dot Color", (float*)&weapon->reticleDotColorPacked);
//    ImGui::ColorEdit3("Reticle Dot Cool Down Color", (float*)&weapon->reticleDotCoolDownColorPacked); */
//}

