#pragma once

#include <Windows.h>
#include "../dependencies/imgui/imgui.h"
#include "../../Config/Config.h"
#include "../Fonts/font_awesome.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


//#include "../../DE/customizedWeapon.h"



struct KeyInfo
{
    const char* name;
    unsigned int vkCode;
};



//! currated list by me.
//? removed the   {"NOT BOUND", 0}, entry as if the key is not bound user will never be able to open the mod menu.
inline const KeyInfo allowedKeyBindsKeyInfos[] = {  
    {"MOUSE MIDDLE", VK_MBUTTON},
    {"MOUSE X1", VK_XBUTTON1},
    {"MOUSE X2", VK_XBUTTON2},
    {"TAB", VK_TAB},
    {"SHIFT", VK_SHIFT},
    {"CONTROL", VK_CONTROL},
    {"SPACE", VK_SPACE},
    {"END", VK_END},
    {"HOME", VK_HOME},
    {"ARROW LEFT", VK_LEFT},
    {"ARROW UP", VK_UP},
    {"ARROW RIGHT", VK_RIGHT},
    {"ARROW DOWN", VK_DOWN},
    {"INSERT", VK_INSERT},
    {"DELETE", VK_DELETE},
    {"0", '0'},
    {"1", '1'},
    {"2", '2'},
    {"3", '3'},
    {"4", '4'},
    {"5", '5'},
    {"6", '6'},
    {"7", '7'},
    {"8", '8'},
    {"9", '9'},
    {"A", 'A'},
    {"B", 'B'},
    {"C", 'C'},
    {"D", 'D'},
    {"E", 'E'},
    {"F", 'F'},
    {"G", 'G'},
    {"H", 'H'},
    {"I", 'I'},
    {"J", 'J'},
    {"K", 'K'},
    {"L", 'L'},
    {"M", 'M'},
    {"N", 'N'},
    {"O", 'O'},
    {"P", 'P'},
    {"Q", 'Q'},
    {"R", 'R'},
    {"S", 'S'},
    {"T", 'T'},
    {"U", 'U'},
    {"V", 'V'},
    {"W", 'W'},
    {"X", 'X'},
    {"Y", 'Y'},
    {"Z", 'Z'},
    {"NUMPAD0", VK_NUMPAD0},
    {"NUMPAD1", VK_NUMPAD1},
    {"NUMPAD2", VK_NUMPAD2},
    {"NUMPAD3", VK_NUMPAD3},
    {"NUMPAD4", VK_NUMPAD4},
    {"NUMPAD5", VK_NUMPAD5},
    {"NUMPAD6", VK_NUMPAD6},
    {"NUMPAD7", VK_NUMPAD7},
    {"NUMPAD8", VK_NUMPAD8},
    {"NUMPAD9", VK_NUMPAD9},
    {"F1", VK_F1},
    {"F2", VK_F2},
    {"F3", VK_F3},
    {"F4", VK_F4},
    {"F5", VK_F5},
    {"F6", VK_F6},
    {"F7", VK_F7},
    {"F8", VK_F8},
    {"F9", VK_F9},
    {"F10", VK_F10},
    {"F11", VK_F11},
    {"F12", VK_F12}
};





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

   static const char* getAllowedKeyName(unsigned int vkCode);

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

   //static std::vector<std::string> parseFontFile(const std::string& filename);

   //static std::vector<std::string> parseIconDefinitions(const std::string& filename);

   //static void displayIcons(const std::vector<std::string>& icons);

   //static std::string hexToUtf8(const std::string& hex);

   //static void renderAllAwesomeFontIcons();

   //static void DrawWeaponSettings(customizedWeapon* weapon);


   //static void DrawWeaponSettings(customizedWeapon weapon);

};

