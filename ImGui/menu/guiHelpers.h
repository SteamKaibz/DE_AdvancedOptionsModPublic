#pragma once

#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
#include "../../Config.h"
#include "../Fonts/font_awesome.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>  // For std::find_if_not, std::remove_copy_if
#include <cctype>     // For std::isspace
#include "../DE/CommonDE.h"
#include "../../DE/modSettings.h"



//#include "../../DE/customizedWeapon.h"








class guiHelper
{

private:


public:
   
    static inline auto orangeColor = ImVec4(1.0f, 0.65f, 0.0f, 1.0f);
    static inline auto yellowColor = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
    static inline auto redColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    static inline auto darkGrayColor = ImVec4(.4f, .4f, .4f, 1.0f);
    static inline auto grayColor = ImVec4(.6f, .6f, .6f, 1.0f);
    static inline auto lightgrayColor = ImVec4(.8f, .8f, .8f, 1.0f);

   //static const char* GetKeyNameStrForVkCode(unsigned int vkCode);

   //static const char* getAllowedKeyName(unsigned int vkCode);

   static void ShowTooltip(const char* tooltip);

   static void insertToolTipSameLine(const char* tooltipText);

   static std::vector<std::pair<std::string, std::string>> parseFontAwesomeFile(const std::string& filename);

   static std::string removeDefineAndSpaces(const std::string& input);

   static float getSafeFontSize(float fontSize);

   static float computeNegativeSpacing(float fontSize);

   //static void addDummySpacing(float spacingPix);

   //static float getHudIconsExtraSpacing(float currentFontSize);

   static float computeHudIconOffset_Y(float eternalTextFontSize, float hudIconFontSize);

   static bool startsWithOne(const std::string& str);

   static std::string getModTextInGameMenu();


   

   //static std::vector<std::string> parseFontFile(const std::string& filename);

   //static std::vector<std::string> parseIconDefinitions(const std::string& filename);

   //static void displayIcons(const std::vector<std::string>& icons);

   //static std::string hexToUtf8(const std::string& hex);

   //static void renderAllAwesomeFontIcons();

   //static void DrawWeaponSettings(customizedWeapon* weapon);


   //static void DrawWeaponSettings(customizedWeapon weapon);

};

