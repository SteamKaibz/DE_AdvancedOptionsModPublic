#include "KaibzHud.h"



void KaibzHud::showCustomHud(KaibzHudData& data)
{
    static bool isDemonActive = false;
    static uint64_t lastDemonCheckMs = 0;

    ImGuiIO& io = ImGui::GetIO();
    ImGuiViewport* viewport = ImGui::GetMainViewport();

    if (viewport->Size.x <= 0 || viewport->Size.y <= 0) {
        // Delay rendering the window until the viewport size becomes valid
        return;
    }

    float windowPosX = viewport->Pos.x;
    float windowPosY = viewport->Pos.y;

    //logInfo("showCustomHud: debug: viewport->Size.x: %.3f viewport->Size.y: %.3f", viewport->Size.x, viewport->Size.y);

    //? this is what prevent clipping issues with the hud:
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowPos(ImVec2(windowPosX, windowPosY), ImGuiCond_Always);

    //x trying to prevent cliping when hud is too low on the screen. UPDATE DOESNT HELP
    //ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f)); 

    ImGui::Begin("KaibzHudGui", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar);


    if (K_Utils::EpochMillis() - lastDemonCheckMs > 500) {
        lastDemonCheckMs = K_Utils::EpochMillis();

        isDemonActive = idPlayer_K::isDemonActiveFlag();
    }   

    //KaibzHud::drawHud(2); //! outlines
    //KaibzHud::drawHud(1);

    if (isDemonActive) {
        KaibzHud::drawDemonHud(data, 0); //: fill
    }
    else {
        KaibzHud::drawSlayerHud(data, 0); //: fill

    }
    
    //DebugShowAllIcons(); //! if you use this, don't pop the font   

    //? not here font switch are handled in drawHud funcs
    //qsdfImGui::PopFont(); 

    ImGui::PopStyleColor();  // Restore text color

    ImGui::End();

    //qsdfImGui::PopStyleVar();

}







std::string KaibzHud::getPaddedString(int value, size_t width) {
    std::ostringstream oss;
    oss << std::setw(width) << std::setfill('0') << value; // Pad with leading zeros
    return oss.str();
}




ImVec2 KaibzHud::computeHudPos(float hudSizeX, ImVec2 zeroCharSize, float heightSafepaddingMul) {

    static bool isFirstTime = true;

    ImVec2 displayeSize = ImGui::GetIO().DisplaySize;
    float maxPosX = displayeSize.x - zeroCharSize.x;
    float maxPosY = displayeSize.y - zeroCharSize.y;

    float userOffsetX = ((float)modSettings::getKaibzHudOffsetX() * displayeSize.x) / 100.0f;
    float userOffsetY = ((float)modSettings::getKaibzHudOffsetY() * displayeSize.y) / 100.0f;

    //? update no it's the setting of window size in showCustomHud that prevent the bug
    //x this is what prevent the bug of the hud being only displayable in the area set by user offsets limits
    /*if (isFirstTime) {
        userOffsetX = displayeSize.x;
        userOffsetY = displayeSize.y;  
        isFirstTime = false; 
    } */

    float hudPosX = 0.0f;
    float hudPosY = 0.0f;

    hudPosX = (displayeSize.x - hudSizeX) / 2.0f + userOffsetX;
    hudPosY = displayeSize.y - zeroCharSize.y * heightSafepaddingMul + userOffsetY;


    
    ImVec2 hudPosVec2 = ImVec2(hudPosX, hudPosY);

    //! prevent the hud from going completely offscreen
    if (hudPosVec2.x < 0.0f) {
        hudPosVec2.x = 0.0f;
    }
    else if (hudPosVec2.x > maxPosX) {
        hudPosVec2.x = maxPosX;
    }

    if (hudPosVec2.y < 0.0f) {
        hudPosVec2.y = 0.0f;
    }
    else if (hudPosVec2.y > maxPosY) {
        hudPosVec2.y = maxPosY;
    }

    //logInfo("computeHudPos: hudPosVec2.x: %.3f hudPosVec2.y: %.3f displayeSize.x:  %.3f, displayeSize.y:  %.3f", hudPosVec2.x, hudPosVec2.y, displayeSize.x, displayeSize.y);

    //isFirstTime = false; //? important

    return hudPosVec2;        
}


ImVec4 KaibzHud::getElementColor(KaibzHudColor_t hudColor, int outlineRef) {

    if (outlineRef) {
        return Menu::BlackColorImVec4;
    }
    return Menu::getHudColor(hudColor);
}



void KaibzHud::writePaddedNumberALT(std::string paddedStr, float zeroCharWidth, KaibzHudColor_t hudColor, int outlineRef) {
    float charOffsetX = zeroCharWidth * 0.55f;
    float iconToTextForChar_1_OffsetX = zeroCharWidth * 0.15f;
    float iconToTextOffsetX = zeroCharWidth * 0.35f;

    bool leadingZeros = true;

    for (size_t i = 0; i < paddedStr.size(); i++) {
        char c = paddedStr[i]; // Access character using index

        if (i == 0) { //! setting custom spacing between health/armor/ammo icon to text
            if (c == '1') {
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + iconToTextForChar_1_OffsetX);
            }
            else {
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + iconToTextOffsetX);
            }
        }

        if (c != '0') {
            leadingZeros = false;
        }

        if (leadingZeros) {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() - charOffsetX);

            if (hudColor == KaibzHudColor_t::criticalColor || outlineRef) {
                ImGui::TextColored(getElementColor(hudColor, outlineRef), "%c", c);
            }            
            else {
                ImGui::TextColored(Menu::DisabledColorImVec4, "%c", c);
            }

        }
        else {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() - charOffsetX);

            if (c == '1') {
                //logInfo("1 detected, using shifted version");
                c = 'E'; //! setting the one that is shifted
            }

            ImGui::TextColored(getElementColor(hudColor, outlineRef), "%c", c);
            //ImGui::TextColored(color, "%c", c);
        }

        ImGui::SameLine();
    }


}


//void KaibzHud::writePaddedNumber(std::string paddedStr, float zeroCharWidth, ImVec4 color, int outlineRef) {
//    float charOffsetX = zeroCharWidth * 0.55f;
//    float iconToTextForChar_1_OffsetX = zeroCharWidth * 0.15f;
//    float iconToTextOffsetX = zeroCharWidth * 0.35f;    
//
//    bool leadingZeros = true;
//
//    for (size_t i = 0; i < paddedStr.size(); i++) {
//        char c = paddedStr[i]; // Access character using index
//
//        if (i == 0) { //! setting custom spacing between health/armor/ammo icon to text
//            if (c == '1') {
//                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + iconToTextForChar_1_OffsetX);
//            }
//            else {
//                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + iconToTextOffsetX);
//            }
//        }
//
//        if (c != '0') {
//            leadingZeros = false;
//        }
//
//        if (leadingZeros) {
//            ImGui::SetCursorPosX(ImGui::GetCursorPosX() - charOffsetX);  
//
//            if (outlineRef) {
//                ImGui::TextColored(Menu::BlackColorImVec4, "%c", c);
//            }           
//            else {
//                ImGui::TextColored(Menu::DisabledColorImVec4, "%c", c);
//            }
//
//        }
//        else {
//            ImGui::SetCursorPosX(ImGui::GetCursorPosX() - charOffsetX);
//
//            if (c == '1') {
//                //logInfo("1 detected, using shifted version");
//                c = 'E'; //! setting the one that is shifted
//            }
//
//            ImGui::TextColored(color, "%c", c);
//        }
//
//        ImGui::SameLine();
//    }
//}


void KaibzHud::adjustSize(ImVec2& coordsVec2, float mul) {
    coordsVec2.x = coordsVec2.x * mul;
    coordsVec2.y = coordsVec2.y * mul;
}

//! will draw black bg and will flash on some conditions
void KaibzHud::drawHudBg(KaibzHudData& dataRef, ImVec2 hudStartVec2, float hudSizeX, float zeroCharSizeY, float alpha) {

    ImU32 bgColor = IM_COL32(0, 0, 0, (int)(alpha * 255));

    ImDrawList* drawList = ImGui::GetWindowDrawList();
    float sizeAjustMul = 0.003f;    
    float sizeAjustMinusXMul = 0.02f;
    static ImU32 flashColor = IM_COL32(255, 255, 255, 255);
    static bool isFlashFlag = false;   
    int flashDurationMs = 200;  
    static uint64_t lastFlashStartMs = 0;


    // Calculate the end position of the HUD
    ImVec2 hudEndVec2 = ImVec2(hudStartVec2.x + hudSizeX, hudStartVec2.y + zeroCharSizeY);
    //adjustSize(hudEndVec2, sizeAjustXMul);

    hudStartVec2.x -= hudStartVec2.x * sizeAjustMinusXMul; //! to make it really nicely centered
    //hudStartVec2.x -= hudStartVec2.x * sizeAjustMul;
    hudStartVec2.y -= hudStartVec2.y * sizeAjustMul;

    hudEndVec2.x += hudEndVec2.x * sizeAjustMul;
    hudEndVec2.y += hudEndVec2.y * sizeAjustMul;

    //! prioritization based on personal view on what is the most important here
    if (dataRef.isHudFlash && !isFlashFlag) {

        logInfo("drawHudBg: dataRef.isHudFlash trigger... ");

        isFlashFlag = true;
        flashColor = dataRef.hudFlashColor;
        lastFlashStartMs = K_Utils::EpochMillis();
    }

    if (isFlashFlag) {

        uint64_t millis = K_Utils::EpochMillis();

        if ((millis - lastFlashStartMs) < flashDurationMs) {

            bgColor = flashColor;

            //logInfo("drawHudBg: flashColor trigger: millis: %llu  lastFlashStartMs: %llu flashDurationMs: %d", millis, lastFlashStartMs, flashDurationMs);
        }
        else {
            isFlashFlag = false;
            logInfo("drawHudBg: isFlashFlag set to false");
        }
    }   

    // Draw background rectangle
    drawList->AddRectFilled(hudStartVec2, hudEndVec2, bgColor, 5.0f); // 5.0f is the rounding radius
    
}





void KaibzHud::drawCoolDownCircleV2(ImVec2 centerCoords, float radius, float progress, ImU32 colorImU32) {
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    int segments = 60;
    float arcThickness = radius * .4f;

    // Only draw the arc if progress is less than 1.0
    if (progress < 1.0f) {
        // Calculate the angle for the arc based on cooldown progress (0 to 1)
        float arcEndAngle = -IM_PI * 0.5f;
        float arcStartAngle = arcEndAngle + (progress * 2 * IM_PI); // No inversion of progress

        // Draw the growing arc representing cooldown progress
        drawList->PathArcTo(centerCoords, radius - 2.0f, arcStartAngle, arcEndAngle, segments); // No inversion of start and end angles

        // Increase stroke width to make the arc thicker
      
        drawList->PathStroke(colorImU32, false, arcThickness);
        //drawList->PathStroke(colorImU32, false, 4.0f);
    }
}





//! USES ONE FONT. 

void KaibzHud::drawSlayerHud(KaibzHudData& data, int outlineRef){
   
    uint64_t lastDataChangeMs = 0;
    static int healthInt = 0;

    ImVec4 colorWhite = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    ImVec4 colorGray = ImVec4(0.5f, 0.5f, 0.5f, 1.0f); // Dark gray color

    ImGui::PushFont(Menu::kaibzHudIconsFont); //? keep this here

    const char* zeroChar = "0"; // Replace 'A' with the character you want to measure
    ImVec2 zeroCharSize = ImGui::CalcTextSize(zeroChar);
    float zeroCharWidth = zeroCharSize.x;
    float zeroCharHeight = zeroCharSize.y;
    float heightSafepaddingMul = 1.2f;

    float hudIconsSafeFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudIconFontSize());
    //logInfo("hudIconsSafeFontSize: %.3f zeroCharWidth: %.3f", hudIconsSafeFontSize, zeroCharWidth);

    float hudTextsSpacing = zeroCharWidth * 3;  
    float elementsExtraSpacingPix = hudIconsSafeFontSize * modSettings::getKaibzHudIconExtraSpacingMul();

    int iconCount = 0;


    //! setting these pos so that changing:
    float ArmorIconPosX = -1.0f;
    float AmmoIconPosX = -1.0f;
    float FirstEquipmentIconPosX = -1.0f;
    float lastIconSizeAdjustXMul = 0.3f; //! this is to get more accurate hud size X

    //KaibzHudData data = KaibzHudManager::getTestData();
    //KaibzHudData data = KaibzHudManager::getData();


    static float hudSizeX = 0; //! init   
    //float huxStartX = 0.0f;


    ImGuiViewport* viewport = ImGui::GetMainViewport();
    if (viewport->Size.x <= 0 || viewport->Size.y <= 0) {
        logWarn("drawSlayerHud: returning cause viewport is not initialized...");
        // Delay rendering the window until the viewport size becomes valid
        return;
    }


    ImVec2 displayeSize = ImGui::GetIO().DisplaySize;
    //! attempting to use this instead of ImGui::GetIO().DisplaySize; to see if it fix the hud diseapearing bug
    //? update it doesn't help
    //ImVec2 displayeSize = viewport->Size;
    //logInfo("drawHud: hudSizeX: %.3f displayeSize.x: %.3f displayeSize.y: %.3f", hudSizeX, displayeSize.x, displayeSize.y);
   

    ImVec2 hudOffsetComputed = computeHudPos(hudSizeX, zeroCharSize, heightSafepaddingMul);
    if (outlineRef == 1) {
        hudOffsetComputed.x += .5f;
        hudOffsetComputed.y += .5f;
    }
    else if (outlineRef == 2) {
        hudOffsetComputed.x -= .5f;
        hudOffsetComputed.y -= .5f;
    }

    //! setting cursor so the hud is centered whatever how many icons/text are rendered
    ImGui::SetCursorPos(hudOffsetComputed);

    //! drawing the hud doesnt change cursor positions cause it uses drawList
    drawHudBg(data, hudOffsetComputed, hudSizeX, zeroCharSize.y, modSettings::getKaibzHudBgOpacity());


    //logInfo("drawHud: hudSizeX: %.3f screenWidth: %.3f hudOffsetX: %.3f hudOffsetY: %.3f CursorPosX: %.3f", hudSizeX, displayeSize.x, hudOffsetX, hudOffsetY, ImGui::GetCursorPosX());


    hudSizeX = 0; //! reset


    //! EXTRA LIFE
    if (modSettings::getFlag(KaibzHudFlag::ShowExtraLives)) {

        ImGui::TextColored(getElementColor(data.extraLivesColor, outlineRef), ICON_HUD_EXTRALIFE_HELMET);
        //ImGui::TextColored(getElementColor(data.extraLivesColor, outlineRef), ICON_HUD_EXTRALIFE_BOTTLE);
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        iconCount++;        
    }  



    //! RADSUIT/OXYGEN
    if (modSettings::getFlag(KaibzHudFlag::ShowRadsuitOrOxygen)) {
        if (data.isOxygenEquipped) {
            ImGui::TextColored(getElementColor(data.oxygenColor, outlineRef), ICON_HUD_OXYGEN);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
            iconCount++;
        }
        else if (data.isRadsuitEquipped) {
            ImGui::TextColored(getElementColor(data.radsuitColor, outlineRef), ICON_HUD_RADSUIT);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
            iconCount++;
        }       
    } 



    //! BP  
    if (modSettings::getFlag(KaibzHudFlag::ShowBloodPunch)) {
        ImGui::TextColored(getElementColor(data.bloodPunchColor, outlineRef), ICON_HUD_BLOODPUNCH_ALT);
        //ImGui::TextColored(getElementColor(data.bloodPunchColor, isOutline), ICON_HUD_BLOODPUNCH);
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        iconCount++;
    }



    //! Health
    if (modSettings::getFlag(KaibzHudFlag::ShowBasics)) {     

        if (modSettings::getFlag(KaibzHudFlag::ShowNumbers)) {
            /*if (iconCount != 0) {
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + defaultSpacing);
            }*/
        }        
       
        ImGui::TextColored(getElementColor(data.healthColor, outlineRef), ICON_HUD_HEALTH);
        ImGui::SameLine();

        if (modSettings::getFlag(KaibzHudFlag::ShowNumbers)) {
            
            //HealthStr += data.healthStr;     
            ArmorIconPosX = ImGui::GetCursorPosX() + hudTextsSpacing; //! this is very important to be able to draw any 'health' value without having the whole hud shifting to the right or left every time the health value goes from 9 to 10 and 99 to 100
            //! writePaddedNumber always ends by a ImGui::SameLine();
            //KaibzHud::writePaddedNumber(getPaddedString(data.health, 3), zeroCharWidth, getElementColor(data.healthColor, outlineRef), outlineRef);
            KaibzHud::writePaddedNumberALT(getPaddedString(data.health, 3), zeroCharWidth, data.healthColor, outlineRef);
        } 
        else {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }
        iconCount++;    
    }  


    //! ARMOR
    if (modSettings::getFlag(KaibzHudFlag::ShowBasics)) {

        if (ArmorIconPosX >= 0.0f) { //! if ShowNumbers and health is displayed
            ImGui::SetCursorPosX(ArmorIconPosX);
        }

        ImGui::TextColored(getElementColor(data.armorColor, outlineRef), ICON_HUD_ARMOR);
        ImGui::SameLine();
      
        if (modSettings::getFlag(KaibzHudFlag::ShowNumbers)) {
         
            AmmoIconPosX = ImGui::GetCursorPosX() + hudTextsSpacing;
           //! writePaddedNumber always ends by a ImGui::SameLine();
            //KaibzHud::writePaddedNumber(getPaddedString(data.armor, 3), zeroCharWidth, getElementColor(data.armorColor, outlineRef), outlineRef);
            KaibzHud::writePaddedNumberALT(getPaddedString(data.armor, 3), zeroCharWidth, data.armorColor, outlineRef);
        }
        else {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }
       
        //hudSizeX += ImGui::CalcTextSize(ArmorStr.c_str()).x;
        iconCount++;
    }


    //! AMMO
    if (modSettings::getFlag(KaibzHudFlag::ShowBasics)) {

        if (AmmoIconPosX >= 0.0f) { //! if ShowNumbers and health is displayed
            ImGui::SetCursorPosX(AmmoIconPosX);
        }    

        ImGui::TextColored(getElementColor(data.ammoColor, outlineRef), ICON_HUD_AMMO);
        ImGui::SameLine();
       
        if (modSettings::getFlag(KaibzHudFlag::ShowNumbers)) {
           
            FirstEquipmentIconPosX = ImGui::GetCursorPosX() +  hudTextsSpacing + 0.5f * elementsExtraSpacingPix;
            //FirstEquipmentIconPosX = ImGui::GetCursorPosX() + elementsExtraSpacingPix;
            //! writePaddedNumber always ends by a ImGui::SameLine();
            //KaibzHud::writePaddedNumber(getPaddedString(data.ammo, 3), zeroCharWidth, getElementColor(data.ammoColor, outlineRef), outlineRef);
            KaibzHud::writePaddedNumberALT(getPaddedString(data.ammo, 3), zeroCharWidth, data.ammoColor, outlineRef);
        }
        else {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }


        //ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        //else {
        //    FirstEquipmentIconPosX = ImGui::GetCursorPosX() + defaultSpacing * 2;
        //    //ImGui::SameLine();
        //}
        //ImGui::TextColored(getElementColor(data.ammoColor, outlineRef), AmmoStr.c_str());       
        iconCount++;

        
    }    
    /*ImGui::SameLine();
    std::string ammoString = std::to_string(data.ammo);*/   
    //ImGui::SameLine();
    //float NextEquipmentIconPosX = ImGui::GetCursorPosX() + defaultSpacing;
   /* ImGui::TextColored(colorWhite, ammoString.c_str());*/
    //ImGui::SameLine();

    



    //! HAMMER/CRUCIBLE   
    if (modSettings::getFlag(KaibzHudFlag::ShowHammerOrCrucible)) {
        if (data.isHammerShownOnHud) {
            if (FirstEquipmentIconPosX > 0.0f) {
                ImGui::SetCursorPosX(FirstEquipmentIconPosX);
                FirstEquipmentIconPosX = -1.0f;
            }           
            ImGui::TextColored(getElementColor(data.hammerColor, outlineRef), ICON_HUD_HAMMER);        
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }
        else if (data.isCrucibleShownOnHud) {
            if (FirstEquipmentIconPosX > 0.0f) {
                ImGui::SetCursorPosX(FirstEquipmentIconPosX);
                FirstEquipmentIconPosX = -1.0f;
            }
            ImGui::TextColored(getElementColor(data.crucibleColor, outlineRef), ICON_HUD_CRUCIBLE);            
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }        
    }
   
   /* ImGui::TextColored(colorWhite, ICON_HUD_HAMMER);
    hudSizeX += ImGui::CalcTextSize(ICON_HUD_HAMMER).x;*/


    //! FLAME BELCH
    if (modSettings::getFlag(KaibzHudFlag::ShowFlameBelch)) {  
        if (FirstEquipmentIconPosX > 0.0f) {
            ImGui::SetCursorPosX(FirstEquipmentIconPosX);
            FirstEquipmentIconPosX = -1.0f;
        }        
        //ImGui::TextColored(getElementColor(data.flamebelchColor, outlineRef), ICON_HUD_FLAMEBELCH);        
        ImGui::TextColored(getElementColor(data.flamebelchColor, outlineRef), ICON_HUD_FLAMEBELCH_ALT);
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
    }
   


    //! FUEL
    if (modSettings::getFlag(KaibzHudFlag::ShowFuel)) {
        if (FirstEquipmentIconPosX > 0.0f) {
            ImGui::SetCursorPosX(FirstEquipmentIconPosX);
            FirstEquipmentIconPosX = -1.0f;
        }
        ImGui::TextColored(getElementColor(data.fuelColor, outlineRef), ICON_HUD_FUEL_ALT);
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
    } 


    if (!modSettings::getIsUseDedicatedNadeKeys()) {

        if (modSettings::getFlag(KaibzHudFlag::ShowFragOrEquipment)) {
            if (FirstEquipmentIconPosX > 0.0f) {
                ImGui::SetCursorPosX(FirstEquipmentIconPosX);
                FirstEquipmentIconPosX = -1.0f;
            }

            equipmentType_t selectedNade = idPlayer_K::getSelectedGrenadeType();
           
            float savedPosX = ImGui::GetCursorPosX();

            if (selectedNade == equipmentType_t::EQUIPMENT_FRAG_GRENADE) {
                ImGui::TextColored(getElementColor(data.fragColor, outlineRef), ICON_HUD_FRAG_NADE_ALT_2);
            }
            else if (selectedNade == equipmentType_t::EQUIPMENT_ICE_BOMB) {
                ImGui::TextColored(getElementColor(data.iceColor, outlineRef), ICON_HUD_ICE_NADE_ALT_3);
            }
            else {
                ImGui::TextColored(getElementColor(KaibzHudColor_t::disabledColor, outlineRef), ICON_HUD_FRAG_NADE_ALT_2);
            }
          
            ImGui::SameLine();
            ImGui::SetCursorPosX(savedPosX + zeroCharWidth * 1.2f); //! this works very well to prevent the shift of the whole hud when switching grenade types.
        }
       

    }
    else {

        //! FRAG NADE
        if (modSettings::getFlag(KaibzHudFlag::ShowFragOrEquipment)) {
            if (FirstEquipmentIconPosX > 0.0f) {
                ImGui::SetCursorPosX(FirstEquipmentIconPosX);
                FirstEquipmentIconPosX = -1.0f;
            }
            ImGui::TextColored(getElementColor(data.fragColor, outlineRef), ICON_HUD_FRAG_NADE_ALT_2);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }


        //! ICE NADE
        if (modSettings::getFlag(KaibzHudFlag::ShowIce)) {
            if (FirstEquipmentIconPosX > 0.0f) {
                ImGui::SetCursorPosX(FirstEquipmentIconPosX);
                FirstEquipmentIconPosX = -1.0f;
            }

            ImVec2 iceIconStartPos = ImGui::GetCursorScreenPos();
            ImVec2 iceIconEndPos = ImVec2(iceIconStartPos.x + zeroCharWidth, iceIconStartPos.y + zeroCharHeight);

            if (data.iceNadeCooldownProgress < 1.0f) { //! if cooldown

                //ImGui::TextColored(getElementColor(KaibzHudColor_t::iceColorCoolDown, outlineRef), ICON_HUD_HOURGLASS);
                ImGui::TextColored(getElementColor(data.iceColor, outlineRef), ICON_HUD_HOURGLASS);

                ImVec2 iceIconSize = ImVec2(iceIconEndPos.x - iceIconStartPos.x, iceIconEndPos.y - iceIconStartPos.y);

                ImVec2  coolDownCicleCenterVec2 = ImVec2(iceIconStartPos.x + iceIconSize.x * 0.5f, iceIconStartPos.y + iceIconSize.y * 0.5f);

                float radiusSafeMul = 1.0f; //! so we are sure to cover the whole icon
                float coolDownCircleRadius = iceIconSize.y * .5f * radiusSafeMul;

                KaibzHud::drawCoolDownCircleV2(coolDownCicleCenterVec2, coolDownCircleRadius, data.iceNadeCooldownProgress, modSettings::getkaibzHudIceCooldownColorImU32());
            }
            else {
                ImGui::TextColored(getElementColor(data.iceColor, outlineRef), ICON_HUD_ICE_NADE_ALT_3);
            }
            ImGui::SameLine();

           
        }

    }

    

    //! this is to prevent the added space by ImGui::SameLine() so we can get an accurate hud size
    float itemSpacingX = ImGui::GetStyle().ItemSpacing.x;
    
    hudSizeX = ImGui::GetCursorPosX() - itemSpacingX - hudOffsetComputed.x ;
    
    
   /* ImGui::SameLine();
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + defaultSpacing);
    ImGui::SameLine();*/    
    
    
    ImGui::PopFont(); //? <= IMPORTANT !!!
}




void KaibzHud::drawDemonHud(KaibzHudData& data, int outlineRef) {

    uint64_t lastDataChangeMs = 0;
    static int healthInt = 0;

    ImVec4 colorWhite = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    ImVec4 colorGray = ImVec4(0.5f, 0.5f, 0.5f, 1.0f); // Dark gray color

    ImGui::PushFont(Menu::kaibzHudIconsFont); //? keep this here

    const char* zeroChar = "0"; // Replace 'A' with the character you want to measure
    ImVec2 zeroCharSize = ImGui::CalcTextSize(zeroChar);
    float zeroCharWidth = zeroCharSize.x;
    float zeroCharHeight = zeroCharSize.y;
    float heightSafepaddingMul = 1.2f;

    float hudIconsSafeFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudIconFontSize());
    //logInfo("hudIconsSafeFontSize: %.3f zeroCharWidth: %.3f", hudIconsSafeFontSize, zeroCharWidth);

    float hudTextsSpacing = zeroCharWidth * 3;
    float elementsExtraSpacingPix = hudIconsSafeFontSize * modSettings::getKaibzHudIconExtraSpacingMul();

    int iconCount = 0;


    //! setting these pos so that changing:
    float ArmorIconPosX = -1.0f;
    float AmmoIconPosX = -1.0f;
    float FirstEquipmentIconPosX = -1.0f;
    float lastIconSizeAdjustXMul = 0.3f; //! this is to get more accurate hud size X

    //KaibzHudData data = KaibzHudManager::getTestData();
    //KaibzHudData data = KaibzHudManager::getData();


    static float hudSizeX = 0; //! init   
    //float huxStartX = 0.0f;


    ImGuiViewport* viewport = ImGui::GetMainViewport();
    if (viewport->Size.x <= 0 || viewport->Size.y <= 0) {
        logWarn("drawSlayerHud: returning cause viewport is not initialized...");
        // Delay rendering the window until the viewport size becomes valid
        return;
    }


    ImVec2 displayeSize = ImGui::GetIO().DisplaySize;
    //! attempting to use this instead of ImGui::GetIO().DisplaySize; to see if it fix the hud diseapearing bug
    //? update it doesn't help
    //ImVec2 displayeSize = viewport->Size;
    //logInfo("drawHud: hudSizeX: %.3f displayeSize.x: %.3f displayeSize.y: %.3f", hudSizeX, displayeSize.x, displayeSize.y);


    ImVec2 hudOffsetComputed = computeHudPos(hudSizeX, zeroCharSize, heightSafepaddingMul);
    if (outlineRef == 1) {
        hudOffsetComputed.x += .5f;
        hudOffsetComputed.y += .5f;
    }
    else if (outlineRef == 2) {
        hudOffsetComputed.x -= .5f;
        hudOffsetComputed.y -= .5f;
    }

    //! setting cursor so the hud is centered whatever how many icons/text are rendered
    ImGui::SetCursorPos(hudOffsetComputed);

    //! drawing the hud doesnt change cursor positions cause it uses drawList
    drawHudBg(data, hudOffsetComputed, hudSizeX, zeroCharSize.y, modSettings::getKaibzHudBgOpacity());


    //logInfo("drawHud: hudSizeX: %.3f screenWidth: %.3f hudOffsetX: %.3f hudOffsetY: %.3f CursorPosX: %.3f", hudSizeX, displayeSize.x, hudOffsetX, hudOffsetY, ImGui::GetCursorPosX());


    hudSizeX = 0; //! reset   


    //! Health
    if (modSettings::getFlag(KaibzHudFlag::ShowBasics)) {       

        ImGui::TextColored(getElementColor(data.healthColor, outlineRef), ICON_HUD_HEALTH);
        ImGui::SameLine();

        if (modSettings::getFlag(KaibzHudFlag::ShowNumbers)) {

            //HealthStr += data.healthStr;     
            ArmorIconPosX = ImGui::GetCursorPosX() + hudTextsSpacing; //! this is very important to be able to draw any 'health' value without having the whole hud shifting to the right or left every time the health value goes from 9 to 10 and 99 to 100
            //! writePaddedNumber always ends by a ImGui::SameLine();
            //KaibzHud::writePaddedNumber(getPaddedString(data.health, 3), zeroCharWidth, getElementColor(data.healthColor, outlineRef), outlineRef);
            KaibzHud::writePaddedNumberALT(getPaddedString(data.health, 3), zeroCharWidth, data.healthColor, outlineRef);
        }
        else {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + elementsExtraSpacingPix);
        }
    }  



    //! this is to prevent the added space by ImGui::SameLine() so we can get an accurate hud size
    float itemSpacingX = ImGui::GetStyle().ItemSpacing.x;

    hudSizeX = ImGui::GetCursorPosX() - itemSpacingX - hudOffsetComputed.x;


    /* ImGui::SameLine();
     ImGui::SetCursorPosX(ImGui::GetCursorPosX() + defaultSpacing);
     ImGui::SameLine();*/


    ImGui::PopFont(); //? <= IMPORTANT !!!
}






void KaibzHud::DebugShowAllIcons() {
    //? be careful with fonts stacks it may lead to crashes (dont pop same font twice)

    ImVec4 colorWhite = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);




    for (char letter = 'a'; letter <= 'z'; ++letter) {

        //qsdfqsdf ImGui::PushFont(Menu::modMenuFont); // Using this will crash, leaving it here for doc.

        ImGui::Text("%c - ", letter);

        ImGui::PushFont(Menu::kaibzHudIconsFont); // Set the custom font

        ImGui::SameLine();

        ImGui::TextColored(colorWhite, "%c ", letter);

        ImGui::PopFont();

        // Restore default font
    }
}







//? it just looked horrible
//void KaibzHud::drawHourglass(ImDrawList* drawList, ImVec2 center, float size) {
//    float halfSize = size * 0.5f;
//    ImVec2 top[] = {
//        ImVec2(center.x - halfSize, center.y - halfSize),
//        ImVec2(center.x + halfSize, center.y - halfSize)
//    };
//    ImVec2 middle[] = {
//        ImVec2(center.x - halfSize, center.y - halfSize),
//        ImVec2(center.x + halfSize, center.y + halfSize)
//    };
//    ImVec2 bottom[] = {
//        ImVec2(center.x - halfSize, center.y + halfSize),
//        ImVec2(center.x + halfSize, center.y + halfSize)
//    };
//    drawList->AddPolyline(top, 2, IM_COL32_WHITE, false, 1.0f);
//    drawList->AddPolyline(middle, 2, IM_COL32_WHITE, false, 1.0f);
//    drawList->AddPolyline(bottom, 2, IM_COL32_WHITE, false, 1.0f);
//}



//? this doesn't work it as the numbers are spaced too much and changing kaibzHudIconsFont_cfg.GlyphExtraSpacing.x makes it harder to calculate hud line size. 
   //std::string paddedHealthStr = KaibzHud::getPaddedString(data.health, 3);
   //bool leadingZeros = true;
   //for (char& c : paddedHealthStr) {
   //    if (c != '0') {
   //        leadingZeros = false;
   //    }
   //    if (leadingZeros) {

   //        //? this will crash:
   //        //ImGui::TextColored(colorGray, "%s", c); // Display leading zeros in dark gray        
   //       
   //        //ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 15.0f);
   //        ImGui::TextColored(colorGray, "%c", c); // Display leading zeros in dark gray
   //        
   //    }
   //    else {
   //        //ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 15.0f);
   //        ImGui::TextColored(colorWhite, "%c", c); // Display the rest in white

   //    }
   //    ImGui::SameLine();
   //}

   //ImGui::SameLine();
   //ImGui::Text(fourSpaces.c_str()); // Spacing   

   //ImGui::SameLine();    








//! USES 2 FONTS:
//void KaibzHud::drawHud()
//{
//    uint64_t lastDataChangeMs = 0;
//    static int healthInt = 0;
//
//    ImVec4 colorWhite = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
//    ImVec4 colorGray = ImVec4(0.5f, 0.5f, 0.5f, 1.0f); // Dark gray color
//
//    std::string fourSpaces = "    ";
//
//    KaibzHudData data = KaibzHudManager::getTestData();
//
//    float debug_iconHeight = 0.0f;
//
//    float hudTextFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudTextFontSize());
//    float hudIconsFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudIconFontSize());
//    float iconOffsetTest = (hudTextFontSize - hudIconsFontSize) / 2;   
//    
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    std::string dummyHudTextForSize = "__________9999999__________";
//    float hudTextSizeX = ImGui::CalcTextSize(dummyHudTextForSize.c_str()).x;
//    ImGui::PopFont();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//    std::string dummyHudIconsForSize = "aaaaaaaaa";
//    float hudIconsSizeX = ImGui::CalcTextSize(dummyHudIconsForSize.c_str()).x;
//    ImGui::PopFont();
//
//    float hudSizeX = hudTextSizeX + hudIconsSizeX;
//
//    float screenWidth = ImGui::GetIO().DisplaySize.x;
//    float hudOffsetX = (screenWidth - hudSizeX) / 2.0f;
//   
//    ImGui::SetCursorPosX(hudOffsetX);
//    logInfo("drawHud: hudSizeX: %.3f screenWidth: %.3f hudOffsetX: %.3f CursorPosX: %.3f", hudSizeX, screenWidth, hudOffsetX, ImGui::GetCursorPosX());
//
//
//
//    //! BP   
//   
//    //? this line below is the one that messed with the hud not being centered at all
//    //ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);      
//    ImGui::TextColored(colorWhite, ICON_HUD_BLOODPUNCH);
//    ImGui::PopFont(); 
//
//
//
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//
//
//    //! Health
//
//    ImGui::SameLine();
//    ImGui::PushFont(Menu::kaibzHudIconsFont);   
//    ImGui::TextColored(colorWhite, ICON_HUD_HEALTH);
//    ImGui::PopFont();   
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    float textHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    ImGui::SameLine();
//    //logInfo(" ImGui::GetCursorPosY() 4: %.3f", ImGui::GetCursorPosY());
//    std::string paddedHealthStr = KaibzHud::getPaddedString(data.health, 3);
//
//    bool leadingZeros = true;
//    for (char& c : paddedHealthStr) {
//        if (c != '0') {
//            leadingZeros = false;
//        }
//        if (leadingZeros) {
//            ImGui::TextColored(colorGray, "%c", c); // Display leading zeros in dark gray
//        }
//        else {
//            ImGui::TextColored(colorWhite, "%c", c); // Display the rest in white
//        }
//        ImGui::SameLine();
//    }
//
//    ImGui::SameLine();
//    ImGui::Text(fourSpaces.c_str()); // Spacing   
//
//
//    //ImGui::TextColored(colorWhite, paddedHealthStr.c_str());
//    ImGui::PopFont();
//
//
//    //! Armor
//    
//    ImGui::SameLine();
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//    ImGui::TextColored(colorWhite, ICON_HUD_ARMOR);
//    ImGui::SameLine();  
//    ImGui::PopFont();
//
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    ImGui::SameLine();
//    ImGui::TextColored(colorWhite, "000");
//    ImGui::SameLine();
//    ImGui::Text(fourSpaces.c_str()); // Spacing   
//    ImGui::PopFont();
//
//
//    //! Ammo
//    
//    ImGui::SameLine();
//    ImGui::PushFont(Menu::kaibzHudIconsFont);   
//    ImGui::TextColored(colorWhite, ICON_HUD_AMMO);
//    ImGui::PopFont();
//
//
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    ImGui::SameLine();
//    ImGui::TextColored(colorWhite, data.ammoStr.c_str());
//    ImGui::PopFont();
//
//
//
//    //! HAMMER/CRUCIBLE
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//   
//
//    ImGui::TextColored(colorWhite, ICON_HUD_HAMMER);
//    ImGui::PopFont();
//
//
//    //! FLAME BELCH
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//   
//
//    ImGui::TextColored(colorWhite, ICON_HUD_FLAMEBELCH);
//    ImGui::PopFont();
//
//
//    //! FUEL
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//   
//
//    ImGui::TextColored(colorWhite, ICON_HUD_FUEL);
//    ImGui::PopFont();
//
//
//    //! FRAG NADE
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//   
//
//    ImGui::TextColored(colorWhite, ICON_HUD_FRAG_NADE);
//    ImGui::PopFont();
//
//
//
//    //! ICE NADE
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//   
//
//    ImGui::TextColored(colorWhite, ICON_HUD_ICE_NADE);
//    ImGui::PopFont();
//
//}












//!  BAK
//void KaibzHud::drawHud()
//{
//    uint64_t lastDataChangeMs = 0;
//    static int healthInt = 0;
//
//    ImVec4 colorWhite = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
//    ImVec4 colorGray = ImVec4(0.5f, 0.5f, 0.5f, 1.0f); // Dark gray color
//
//    std::string fourSpaces = "    ";
//
//    KaibzHudData data = KaibzHudManager::getTestData();
//
//    float debug_iconHeight = 0.0f;
//    
//    float hudTextFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudTextFontSize());
//    float hudIconsFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudIconFontSize());
//    float iconOffsetTest = (hudTextFontSize - hudIconsFontSize) / 2;
//
//    static float offsetXForCentering = 350.0f;
//    //static float offsetXForCentering = 956.0f;
//
//    //float initialCursorPosX = ImGui::GetCursorPosX();
//    float initialCursorPosX = 0.0f;
//
//    static bool isFirstTime = true;
//
//
//
//    /*logInfo("drawHud: debug initialCursorPosX: %.3F offsetXForCentering: %.3f ", initialCursorPosX, offsetXForCentering);
//    if (isFirstTime) {
//        isFirstTime = false;
//    }
//    else {
//        ImGui::SetCursorPosX(offsetXForCentering);
//    }*/
//
//    //! BP
//    ImGui::Text("_________"); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight bp: %.3f", debug_iconHeight);    
//    //! this value works to make icons and text aligned if text font size is 28 and icon size is 16
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest);
//    logInfo("drawHud: debug  defor drawing bp icon CursorPosX: %.3f  CursorPosY: %.3f", ImGui::GetCursorPosX(), ImGui::GetCursorPosY());
//    ImGui::TextColored(colorWhite, ICON_HUD_BLOODPUNCH);
//    ImGui::PopFont(); 
//
//
//
//
//    //! Health
//    ImGui::SameLine();
//    ImGui::Text(fourSpaces.c_str()); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight hp: %.3f", debug_iconHeight);
//    //float yOffset = 5.0f; // Adjust this value to change the offset   
//    //logInfo(" ImGui::GetCursorPosY() 1: %.3f", ImGui::GetCursorPosY());    
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest); //! this works fine
//    //ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconHeight * .25f); //! this works fine
//    //logInfo(" ImGui::GetCursorPosY() 2: %.3f", ImGui::GetCursorPosY());
//    ImGui::TextColored(colorWhite, ICON_HUD_HEALTH);
//    ImGui::PopFont();
//    //logInfo(" ImGui::GetCursorPosY() 3: %.3f", ImGui::GetCursorPosY());
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    float textHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("customHud_Eternal1font text heigth: %.3f", textHeight);
//    ImGui::SameLine();
//    //logInfo(" ImGui::GetCursorPosY() 4: %.3f", ImGui::GetCursorPosY());
//    std::string paddedHealthStr = KaibzHud::getPaddedString(data.health, 3);
//
//    bool leadingZeros = true;
//    for (char& c : paddedHealthStr) {
//        if (c != '0') {
//            leadingZeros = false;
//        }
//        if (leadingZeros) {
//            ImGui::TextColored(colorGray, "%c", c); // Display leading zeros in dark gray
//        }
//        else {
//            ImGui::TextColored(colorWhite, "%c", c); // Display the rest in white
//        }
//        ImGui::SameLine();
//    }
//
//
//    //ImGui::TextColored(colorWhite, paddedHealthStr.c_str());
//    ImGui::PopFont();
//
//
//    //! Armor
//
//    ImGui::SameLine();
//    ImGui::Text(fourSpaces.c_str()); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight armor: %.3f", debug_iconHeight);
//    //float yOffset = 5.0f; // Adjust this value to change the offset   
//
//
//    //logInfo(" ImGui::GetCursorPosY() 1: %.3f", ImGui::GetCursorPosY());    
//
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest); //! 
//    //logInfo(" ImGui::GetCursorPosY() 2: %.3f", ImGui::GetCursorPosY());
//    ImGui::TextColored(colorWhite, ICON_HUD_ARMOR);
//    ImGui::PopFont();
//
//
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    ImGui::SameLine();
//    ImGui::TextColored(colorWhite, data.armorStr.c_str());
//    ImGui::PopFont();
//
//
//    //! Ammo
//
//    ImGui::SameLine();
//    ImGui::Text(fourSpaces.c_str()); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight ammo3: %.3f", debug_iconHeight);    
//
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest); //! 
//    ImGui::TextColored(colorWhite, ICON_HUD_AMMO);
//    ImGui::PopFont();
//
//
//    ImGui::PushFont(Menu::customHud_Eternal1font);
//    ImGui::SameLine();
//    ImGui::TextColored(colorWhite, data.ammoStr.c_str());
//    ImGui::PopFont();
//
//
//
//    //! HAMMER/CRUCIBLE
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight crucible or hammer: %.3f", debug_iconHeight);
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest); //! this works fine
//
//    ImGui::TextColored(colorWhite, ICON_HUD_HAMMER);
//    ImGui::PopFont();
//
//
//    //! FLAME BELCH
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight FLAME BELCH: %.3f", debug_iconHeight);
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest); //! this works fine
//
//    ImGui::TextColored(colorWhite, ICON_HUD_FLAMEBELCH);
//    ImGui::PopFont();
//
//
//    //! FUEL
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight FUEL: %.3f", debug_iconHeight);
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest); //! this works fine
//
//    ImGui::TextColored(colorWhite, ICON_HUD_FUEL);
//    ImGui::PopFont();
//
//
//    //! FRAG NADE
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight FRAG NADE: %.3f", debug_iconHeight);
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest);
//
//    ImGui::TextColored(colorWhite, ICON_HUD_FRAG_NADE);
//    ImGui::PopFont();
//
//
//
//    //! ICE NADE
//    ImGui::SameLine();
//    ImGui::Text("  "); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzHudIconsFont);
//
//    debug_iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    logInfo("debug_iconHeight ICE NADE: %.3f", debug_iconHeight);
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconOffsetTest);
//
//    ImGui::TextColored(colorWhite, ICON_HUD_ICE_NADE);
//    ImGui::PopFont();
//
//
//
//
//    offsetXForCentering = 956.0;
//
//    //float finalCursorPosX = ImGui::GetCursorPosX();
//    //logInfo("drawHud: debug: finalCursorPosX: %.3f", finalCursorPosX);
//    //// Calculate the line width
//    //float lineWidth = finalCursorPosX - initialCursorPosX;
//    //logInfo("drawHud: debug: lineWidth: %.3f", lineWidth);
//    //// Center the line horizontally
//    //float screenWidth = ImGui::GetIO().DisplaySize.x;
//    //logInfo("drawHud: debug: screenWidth: %.3f", screenWidth);
//    //offsetXForCentering = (screenWidth - lineWidth) / 2.0f;
//    //logInfo("drawHud: debug: offsetXForCentering: %.3f", offsetXForCentering);
//
//   /* if (offsetX != initialCursorPosX) {
//        initialCursorPosX = 
//    }*/
//
//
//
//}




//! icon offset test. This works keep it.
//void KaibzHud::drawHud()
//{
//    ImVec4 colorWhite = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
//
//    KaibzHudData data = KaibzHudManager::getTestData();
//
//    ImGui::Text("_________"); // Spacing   
//    ImGui::SameLine();
//
//    ImGui::PushFont(Menu::kaibzIconsDE_Small_Font);
//
//    float iconHeight = ImGui::GetTextLineHeightWithSpacing(); // Get icon height
//    //logInfo("iconHeight: %.3f", iconHeight);
//    //float yOffset = 5.0f; // Adjust this value to change the offset
//
//    /*
//    16:36:07.898            KaibzHud.cpp:41    INFO| iconHeight: 20.000
//    16:36:07.898            KaibzHud.cpp:51    INFO|  ImGui::GetCursorPosY() 1: 8.000
//    16:36:07.898            KaibzHud.cpp:54    INFO|  ImGui::GetCursorPosY() 2: 13.000
//    16:36:07.898            KaibzHud.cpp:58    INFO|  ImGui::GetCursorPosY() 3: 40.000
//    16:36:07.898            KaibzHud.cpp:62    INFO|  ImGui::GetCursorPosY() 4: 8.000
//    */
//
//
//    //logInfo(" ImGui::GetCursorPosY() 1: %.3f", ImGui::GetCursorPosY());    
//
//    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + iconHeight * .25f); //! this works fine
//    //logInfo(" ImGui::GetCursorPosY() 2: %.3f", ImGui::GetCursorPosY());
//    ImGui::TextColored(colorWhite, ICON_HUD_HEALTH);
//    ImGui::PopFont();
//
//    //logInfo(" ImGui::GetCursorPosY() 3: %.3f", ImGui::GetCursorPosY());
//
//    ImGui::PushFont(Menu::customHud_Eternal1font);   
//    ImGui::SameLine();
//    //logInfo(" ImGui::GetCursorPosY() 4: %.3f", ImGui::GetCursorPosY());
//    ImGui::TextColored(colorWhite, data.healthStr.c_str());
//    ImGui::PopFont();
//}
