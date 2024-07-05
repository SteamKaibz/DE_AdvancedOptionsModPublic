#pragma once

#include <Windows.h>
#include "../../Config/Config.h"

#include "guiHelpers.h"
#include "DebugGui.h"
#include "KaibzCrosshair.h"
#include "GoToSettingsGui.h"
#include "KaibzHud.h"


#include "../Fonts/Robotto.h"
#include "../Fonts/EternalUiRegular_BWZGd.h"
#include "../Fonts/icomoonDoomEternal.h"
#include "../Fonts/font_awesome.h"
#include "../Fonts/font_awesome.cpp"

#include "../../DE/idDeclGlobalShellManager.h"
#include "../../DE/PlayerStateChecker.h"
#include "../../DE/idDeclUIColorManager.h"

#include "../../DE/winFocusManager.h"


//#include "../../DE/CustomizedWeaponManager.h"



namespace Menu {
   
    //inline bool isAltTabFlag = false;

    inline ImFont* icons_font_awesome = nullptr;
    inline ImFont* modMenuFont = nullptr;
    inline ImFont* debugWindow_font = nullptr;
    inline ImFont* customHud_Eternal1font = nullptr;
    inline ImFont* kaibzHudIconsFont = nullptr;
    inline ImFont* kaibzIconsDE_Medium_Font = nullptr;

    inline bool bShowMenu = false;
    inline bool bShowDebugWindow = false;
    inline bool bShowKaibzCrosshairWindow = false;   
    inline bool bShowKaibzHudWindow = false;   

    inline ImVec4 BlackColorImVec4 = ImVec4(0.0f, 0.0f, 0.0f, 1.0f); // RGBA: (0, 0, 0, 1)
    inline ImVec4 WhiteColorImVec4 = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); 
    inline ImVec4 InvisibleColorImVec4 = ImVec4(1.0f, 1.0f, 1.0f, 0.0f); 
    inline ImVec4 YellowColorImVec4 = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); 
    inline ImVec4 OrangeColorImVec4 = ImVec4(1.0f, 0.5f, 0.0f, 1.0f);
    inline ImVec4 RedColorImVec4 = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); 
    inline ImVec4 DarkGreyColorImVec4 = ImVec4(.4f, .4f, .4f, 1.0f);

    ////! menu colors
    //inline ImVec4 shortcutTextColorImVec4 = BlackColorImVec4;

    //! custom crosshair colors
    inline ImVec4 customDotCrosshairColorImVec4 = WhiteColorImVec4;
    inline ImVec4 customDotCrosshairCooldownColor = RedColorImVec4;

    //! kaibz Hud
    inline ImVec4 ExtraLivesIconColorImVec4 = BlackColorImVec4;
    inline ImVec4 BloodPunch1ColorImVec4 = BlackColorImVec4;
    inline ImVec4 BloodPunch2ColorImVec4 = BlackColorImVec4;
    inline ImVec4 BloodPunchDesperateColorImVec4 = BlackColorImVec4;
    inline ImVec4 RadsuitColorImVec4 = BlackColorImVec4;
    inline ImVec4 OxygenColorImVec4 = BlackColorImVec4;
    inline ImVec4 HealthMaxColorImVec4 = BlackColorImVec4;
    inline ImVec4 HealthColorImVec4 = BlackColorImVec4;
    inline ImVec4 ArmorMaxColorImVec4 = BlackColorImVec4;
    inline ImVec4 ArmorColorImVec4 = BlackColorImVec4;
    inline ImVec4 AmmoColorImVec4 = BlackColorImVec4;
    inline ImVec4 HammerCrucibleColorImVec4 = BlackColorImVec4;
    inline ImVec4 FlameBelchColorImVec4 = BlackColorImVec4;
    inline ImVec4 Fuel1ColorImVec4 = BlackColorImVec4;
    inline ImVec4 Fuel2ColorImVec4 = BlackColorImVec4;
    inline ImVec4 Fuel3ColorImVec4 = BlackColorImVec4;
    inline ImVec4 Frag1ColorImVec4 = BlackColorImVec4;
    inline ImVec4 Frag2ColorImVec4 = BlackColorImVec4;
    inline ImVec4 IceColorImVec4 = BlackColorImVec4;
    inline ImVec4 IceCooldownColorImVec4 = BlackColorImVec4;

    inline ImVec4 CautionColorImVec4 = BlackColorImVec4;
    inline ImVec4 WarningColorImVec4 = BlackColorImVec4;
    inline ImVec4 CriticalColorImVec4 = BlackColorImVec4;
    inline ImVec4 DisabledColorImVec4 = BlackColorImVec4;

   

    //? doesn't help:
    /*inline bool bIsMenuInitialised = false;*/ //! an attempt to prevent issues where mod shortcut text randomly doesn't show up in main page                                         
                             


    void InitializeContext(HWND hwnd);
    void raiseAltTabFlag();
    void Render();
    void showModMenu(bool* p_open = NULL);
    bool isLeavingModMenu();

    void initKaibzHudColors();
    //void setKaibzHudColorsToCurrentGameProfileColor();
    ImVec4 getHudColor(KaibzHudColor_t colorId);
    void debugLogColor(ImVec4 ImVec4Color, std::string colorName);
    void debugLogHudColors();



    //inline static idColor colorCustom_test1 = idColor{ 1.00f, 1.00f, 0.00f, 1.00f };
    //inline static idColor colorCustom_test2 = idColor{ 1.00f, 0.00f, 0.00f, 1.00f };
    //void debugChangeCustColor();
    //idColor* getCustomColorTest();
    //inline bool isColorChange = false;

} // namespace Menu
