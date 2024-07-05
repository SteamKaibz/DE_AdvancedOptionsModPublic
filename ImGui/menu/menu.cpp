#include "menu.hpp"

#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_win32.h"

//#include "../ImGuiDebug.h"
//#include "../ImGuiDebug.h"

namespace ig = ImGui;

namespace Menu {


    void InitializeContext(HWND hwnd) {
        if (ig::GetCurrentContext())
            return;

        ImGui::CreateContext();
        ImGui_ImplWin32_Init(hwnd);

        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = io.LogFilename = nullptr;

        //! this doesn't crash the issue was that i was adding io.Fonts->AddFontDefault() before it       
        ImFontConfig modMenuFont_cfg;
        modMenuFont_cfg.FontDataOwnedByAtlas = false;

        //! default font 
        float robotoFontSize = guiHelper::getSafeFontSize(modSettings::getRobotoFontSize());
        modMenuFont = io.Fonts->AddFontFromMemoryTTF(robottoData, sizeof(robottoData), robotoFontSize, &modMenuFont_cfg);

        ImFontConfig debugWindow_font_cfg;
        debugWindow_font_cfg.FontDataOwnedByAtlas = false;
        debugWindow_font = io.Fonts->AddFontFromMemoryTTF(robottoData, sizeof(robottoData), 18.0f, &debugWindow_font_cfg);


        ImFontConfig Eternal1font_cfg;
        Eternal1font_cfg.FontDataOwnedByAtlas = false;
        //qsdfEternal1font_cfg.MergeMode = true;

        float etEternalFontSize = guiHelper::getSafeFontSize(modSettings::getEternalFontSize());
        customHud_Eternal1font = io.Fonts->AddFontFromMemoryTTF(eternalRegularData, sizeof(eternalRegularData), etEternalFontSize, &Eternal1font_cfg);


        float hudIconsSafeFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudIconFontSize());

        ImFontConfig kaibzHudIconsFont_cfg;
        kaibzHudIconsFont_cfg.FontDataOwnedByAtlas = false;
        //qsdfkaibzHudIconsFont_cfg.MergeMode = true;
        //! this is an attemp to have the icons always aligned with text:
        //kaibzHudIconsFont_cfg.GlyphOffset.y = guiHelper::computeHudIconOffset_Y(modSettings::getKaibzHudTextFontSize(), modSettings::getKaibzHudIconFontSize());

        //! we don't use this because it would make calculating hud line harder and we need to know it to center the hud
        //kaibzHudIconsFont_cfg.GlyphExtraSpacing.x = guiHelper::computeNegativeSpacing(hudIconsSafeFontSize);
        //kaibzHudIconsFont_cfg.GlyphExtraSpacing.x = -22.0f;      
         
        kaibzHudIconsFont = io.Fonts->AddFontFromMemoryTTF(KaibzDE, sizeof(KaibzDE), hudIconsSafeFontSize, &kaibzHudIconsFont_cfg);      

    }

   

    


    bool isLeavingModMenu()
    {
        static bool lastbShowMenu = false;

        if (bShowMenu != lastbShowMenu) {
            lastbShowMenu = bShowMenu;

            if (!bShowMenu) return true;
            
        }
        return false;       
    }


    void initKaibzHudColors()
    {
        ExtraLivesIconColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudExtraLivesColorImU32());
        BloodPunch1ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudBloodPunch1ColorImU32());
        BloodPunch2ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudBloodPunch2ColorImU32());
        BloodPunchDesperateColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudBloodPunchDesperateColorImU32());
        RadsuitColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudRadsuitColorImU32());
        OxygenColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudOxygenColorImU32());
        HealthMaxColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudHealthMaxColorImU32());
        HealthColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudHealthColorImU32());
        ArmorMaxColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudArmorMaxColorImU32());
        ArmorColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudArmorColorImU32());
        AmmoColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudAmmoColorImU32());
        HammerCrucibleColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudHammerCrucibleColorImU32());
        FlameBelchColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFlameBelchColorImU32());
        Fuel1ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFuel1ColorImU32());
        Fuel2ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFuel2ColorImU32());
        Fuel3ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFuel3ColorImU32());
        Frag1ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFrag1ColorImU32());
        Frag2ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFrag2ColorImU32());
        IceColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudIceColorImU32());
        IceCooldownColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getkaibzHudIceCooldownColorImU32());
        CautionColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::modSettings::getKaibzHudCautionColorImU32());
        WarningColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudWarningColorImU32());
        CriticalColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudCriticalColorImU32());
        DisabledColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudDisabledColorImU32());
    }




    void debugLogColor(ImVec4 ImVec4Color, std::string colorName) {

        std::string resultStr = modSettings::ImVec4ToString(ImVec4Color);
        logInfo("%s : %s", colorName.c_str(), resultStr.c_str());
    }

    void debugLogHudColors() {
        debugLogColor(ExtraLivesIconColorImVec4, "ExtraLivesIconColorImVec4");
        debugLogColor(BloodPunch1ColorImVec4, "BloodPunch1ColorImVec4");
        debugLogColor(BloodPunch2ColorImVec4, "BloodPunch2ColorImVec4");
        debugLogColor(BloodPunchDesperateColorImVec4, "BloodPunchDesperateColorImVec4");
        debugLogColor(RadsuitColorImVec4, "RadsuitColorImVec4");
        debugLogColor(OxygenColorImVec4, "OxygenColorImVec4");
        debugLogColor(HealthMaxColorImVec4, "HealthMaxColorImVec4");
        debugLogColor(HealthColorImVec4, "HealthColorImVec4");
        debugLogColor(ArmorMaxColorImVec4, "ArmorMaxColorImVec4");
        debugLogColor(ArmorColorImVec4, "ArmorColorImVec4");
        debugLogColor(HammerCrucibleColorImVec4, "HammerCrucibleColorImVec4");
        debugLogColor(FlameBelchColorImVec4, "FlameBelchColorImVec4");
        debugLogColor(Fuel1ColorImVec4, "Fuel1ColorImVec4");
        debugLogColor(Fuel2ColorImVec4, "Fuel2ColorImVec4");
        debugLogColor(Fuel3ColorImVec4, "Fuel3ColorImVec4");
        debugLogColor(Frag1ColorImVec4, "Frag1ColorImVec4");
        debugLogColor(Frag2ColorImVec4, "Frag2ColorImVec4");
        debugLogColor(IceColorImVec4, "IceColorImVec4");
        debugLogColor(IceCooldownColorImVec4, "IceCooldownColorImVec4");
        debugLogColor(CautionColorImVec4, "CautionColorImVec4");
        debugLogColor(WarningColorImVec4, "WarningColorImVec4");
        debugLogColor(CriticalColorImVec4, "CriticalColorImVec4");
        debugLogColor(DisabledColorImVec4, "DisabledColorImVec4");
       
    }




    ImVec4 getHudColor(KaibzHudColor_t colorRef)
    {
        switch (colorRef)
        {
        case KaibzHudColor_t::disabledColor:
            return DisabledColorImVec4;
        case KaibzHudColor_t::cautionColor:
            return CautionColorImVec4;
        case KaibzHudColor_t::warningColor:
            return WarningColorImVec4;
        case KaibzHudColor_t::criticalColor:
            return CriticalColorImVec4;
        case KaibzHudColor_t::extraLivesColor:
            return ExtraLivesIconColorImVec4;
        case KaibzHudColor_t::bloodPunch1Color:
            return BloodPunch1ColorImVec4;
        case KaibzHudColor_t::bloodPunch2Color:
            return BloodPunch2ColorImVec4;
        case KaibzHudColor_t::bloodPunchDesperateColor:
            return BloodPunchDesperateColorImVec4;
        case KaibzHudColor_t::healthMaxColor:
            return HealthMaxColorImVec4;
        case KaibzHudColor_t::healthColor:
            return HealthColorImVec4;
        case KaibzHudColor_t::armorMaxColor:
            return ArmorMaxColorImVec4;
        case KaibzHudColor_t::armorColor:
            return ArmorColorImVec4;
        case KaibzHudColor_t::radsuitColor:
            return RadsuitColorImVec4;
        case KaibzHudColor_t::oxygenColor:
            return OxygenColorImVec4;
        case KaibzHudColor_t::ammoColor:
            return AmmoColorImVec4;
        case KaibzHudColor_t::hammerCrucibleColor:
            return HammerCrucibleColorImVec4;
        case KaibzHudColor_t::flameBelchColor:
            return FlameBelchColorImVec4;
        case KaibzHudColor_t::fuel1Color:
            return Fuel1ColorImVec4;
        case KaibzHudColor_t::fuel2Color:
            return Fuel2ColorImVec4;
        case KaibzHudColor_t::fuel3Color:
            return Fuel3ColorImVec4;
        case KaibzHudColor_t::frag1Color:
            return Frag1ColorImVec4;
        case KaibzHudColor_t::frag2Color:
            return Frag2ColorImVec4;
        case KaibzHudColor_t::iceColor:
            return IceColorImVec4;
        case KaibzHudColor_t::iceColorCoolDown:
            return IceCooldownColorImVec4;
        default:
            logWarn("returning default color (?!)");
            return BlackColorImVec4;
        }        
    }




    bool isEnteringModMenu() {

        static bool lastbShowMenu = false;

        if (bShowMenu != lastbShowMenu) {
            lastbShowMenu = bShowMenu;

            if (bShowMenu) return true;
        }
        return false;
    }


    //! this triggers continuously once Imgui is initialized.
    void Render( ) {
        
      
      static  uint64_t lastInMouseDisabledMs = 0;     

      //! attempt to fix issues with shortcut text not rendering
      if (!PlayerStateChecker::isGameInitialized()) return;


      //! avoiding problems....
      if (PlayerStateChecker::isGameLoading()) {
          return;
      }

      //? this doesn't work unfortunately, check the cls for more info
     /* if (!winFocusManager::isGameFocused()) {
          bShowMenu = false;
      }*/

      //? doesn't work
      /*if (isAltTabFlag) {

          bShowMenu = false;
          isAltTabFlag = false;
      }*/


      //! disabling the game mouse input while in imgui so we can use the mouse:
      if (bShowMenu && fastCvarManager::isMouseInputEnabled()) {
          idCmd::SetInMouseEnabled(false);
          lastInMouseDisabledMs = EpochMillis();
      }
      else if (!bShowMenu && !fastCvarManager::isMouseInputEnabled()) {
          idCmd::SetInMouseEnabled(true);
      }

      if (isEnteringModMenu()) {
          //logInfo("isEnteringModMenu: true");

          //menuCustomWeapons = CustomizedWeaponManager::getCustomWeaponVecCpy();
          //menuDefaultCustomWeapons = CustomizedWeaponManager::getDefaultCustomWeaponVecCpy();
      }

      if (isLeavingModMenu()) {
          //logInfo("isLeavingModMenu: true");

          modSettings::apply();
          modSettings::saveSettings(); 
         
      }

      if (bShowMenu) {
          //! adding a delay which solve the bug of the mouse randomly not moving in mod menu:
          if (EpochMillis() - lastInMouseDisabledMs > 100) {
              showModMenu();
          }
          return;
      }

      if (PlayerStateChecker::isInMenus() && !bShowMenu) {
          //! Update: this didnt help:
          //x attempting to fix bug when main menu is unresponsive:
          /*if (EpochMillis() - lastMainModMenuRenderMs > 500) {
              GoToSettingsGui::showModKeyShortcutText();

          }*/
          GoToSettingsGui::showModKeyShortcutText();
          return;
      }


      if (bShowDebugWindow) {
          //DebugGui::drawFullScreenBlackBackground();
          DebugGui::showDebugWindow();
      }


      if (PlayerStateChecker::isPlayingAndActive()) {

          //logInfo("render: KaibzHudManager::getData(); is becing called ");

          KaibzHudData hudData = KaibzHudManager::getData();

          if (bShowKaibzCrosshairWindow) {
              KaibzCrosshair::showCircleCrosshair(hudData);
          }

          if (!modSettings::getFlag(KaibzHudFlag::HideHudInAds) || !idPlayer_K::isInScope()) {
              if (bShowKaibzHudWindow) {
                  KaibzHud::showCustomHud(hudData);
              }
          }
      }
      



      //ig::ShowDemoWindow( );
    }





    void showModMenu(bool* p_open) {

        //ImGui::PushFont(Menu::customHud_Eternal1font);

        if (GetAsyncKeyState(VK_TAB) & 0x8000 && GetAsyncKeyState(VK_MENU) & 0x8000){
            /*logInfo("alt tab !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");*/

            bShowMenu = false;
        }       


        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

        ImGuiViewport* viewport = ImGui::GetMainViewport();
        float verticalSpacingEndTab = viewport->Size.y * .1f;


        IM_ASSERT(ImGui::GetCurrentContext() != NULL && "Missing dear imgui context. Refer to examples app!");

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10.0f, 10.0f));

        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));

        ImGui::Begin("Settings (Press ESC to go close Mod Menu)", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);


        if (ImGui::BeginTabBar("Tabs")) { 


            if (ImGui::BeginTabItem("Welcome")) {

                ImGui::Indent();
                ImGui::NewLine();

                ImGui::TextWrapped("Welcome to Doom Eternal Advanced Options Mod!\n\n\n\t* The [?] symbol will show you a tooltip for almost every option, just hover your mouse over it to see the tooltip.\n\n\t* If you have spent time configuring colors or settings you should make a back up of the .json file. that way you can have as many configurations as you want \n\n\t* The troubleshooting section on the nexus page of this mod should give you clues if you have any issue, launching the mod.\n\n\t* This mod took more than 2000 hours of work, if you enjoy it please give feedback on the nexus comments.\n\n\nKaibz");
                             

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();
            }


            if (ImGui::BeginTabItem("Q.O.L")) {

                ImGui::Indent();
                ImGui::NewLine();

                bool isUseDedicatedGrenadeKeys = modSettings::getIsUseDedicatedNadeKeys();
                ImGui::Checkbox("Use Dedicated Grenade Keys", &isUseDedicatedGrenadeKeys);
                guiHelper::insertToolTipSameLine("Checked: Gives you a throw Frag and a throw Ice keys that you can bind in the game menu.\nChanging this settings requires restart for controller users. \nUnchecked: defaut game behaviour");
                modSettings::setIsUseDedicatedNadeKeys(isUseDedicatedGrenadeKeys);

                ImGui::NewLine();



                static bool isDisableNewCampaignPopUp = modSettings::getIsDisableNewCampaignPopUp();
                ImGui::Checkbox("Disable New Campaign Pop up", &isDisableNewCampaignPopUp);
                guiHelper::insertToolTipSameLine("Checked: will prevent the annoying window to pop up on the screen every time you start a new campaign. \nUnchecked: defaut game behaviour");

                if (isDisableNewCampaignPopUp != modSettings::getIsDisableNewCampaignPopUp()) {
                    idDeclGlobalShellManager::disableNewCampaignPopUp(isDisableNewCampaignPopUp);
                    modSettings::setIsDisableNewCampaignPopUp(isDisableNewCampaignPopUp);
                }

                ImGui::NewLine();

                static bool isDisableBatterySocketPopUp = modSettings::getIsDisableBatterySocketPopUp();
                ImGui::Checkbox("Disable Battery Cell Socket Pop up", &isDisableBatterySocketPopUp);
                guiHelper::insertToolTipSameLine("Checked: will disable the annoying pop up window that shows up everytime you want to insert a battery cell in a socket on the ship. \nUnchecked: defaut game behaviour");

                modSettings::setIsDisableBatterySocketPopUp(isDisableBatterySocketPopUp);

                ImGui::NewLine();



                static bool isSpeedUpBatterySocketAnimation = modSettings::getIsSpeedUpBatterySocketAnimation();
                ImGui::Checkbox("Speed Up Battery in Socket Animation", &isSpeedUpBatterySocketAnimation);
                guiHelper::insertToolTipSameLine("Checked: will speed up game speed when slayer put the battery cell in socket to unlock new items. \nUnchecked: defaut game behaviour");

                modSettings::setIsSpeedUpBatterySocketAnimation(isSpeedUpBatterySocketAnimation);

                ImGui::NewLine();

                static bool isSkipCustomAnimations = modSettings::getIsSkipCustomAnimations();
                ImGui::Checkbox("Disable Blocking Animations", &isSkipCustomAnimations);
                guiHelper::insertToolTipSameLine("Checked: will disabled blocking animations like finding a secret, battery cell... \nUnchecked: defaut game behaviour");

                modSettings::setIsSkipCustomAnimations(isSkipCustomAnimations);

                ImGui::NewLine();


                bool isUnlockGameFOVMenu = modSettings::getIsGameFovMenuUnlocked();
                ImGui::Checkbox("Unlock FOV in Game Menu", &isUnlockGameFOVMenu);
                guiHelper::insertToolTipSameLine("Checked: unlocks the minimum and maximum FOV you can set in the Video menu of the game min: 70 max: 150.\nYou may need to close and open the game Video Settings again for the changes to take effect \nUnchecked: default game behaviour");
                modSettings::setIsGameFovMenuUnlocked(isUnlockGameFOVMenu);

                ImGui::NewLine();


                static bool isOverideInteractionFOV = modSettings::getIsOverideInteractionFOV();
                ImGui::Checkbox("Overide Interaction FOV", &isOverideInteractionFOV);
                guiHelper::insertToolTipSameLine("Checked: lets you set a custom FOV (fied of view) during interactions locks like glory kills, chainsawing, using battery cells... Unchecked: defaut game behaviour");

                modSettings::setIsOverideInteractionFOV(isOverideInteractionFOV);

                static int interactionsFOV_Int = (int)modSettings::getInteractionFOV();
                if (isOverideInteractionFOV) {
                    ImGui::NewLine();
                    ImGui::Indent();
                    ImGui::SliderInt("Interactions FOV", &interactionsFOV_Int, 60, 150);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##interactionsFOV_Int")) {
                        interactionsFOV_Int = (int)modSettingsDefault::defaultInteractionFOV;
                    }
                    guiHelper::insertToolTipSameLine("The value of the Field Of View during interaction animations");
                    ImGui::Unindent();
                }
                modSettings::setInteractionFOV((float)interactionsFOV_Int);


                ImGui::NewLine();

                ImGui::TextWrapped("*** If you are looking to disable the opening Sequence of the main campaign, i suggest you install a mod called: Doom Eternal - Streamlined Campaign ***");              


                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();

            }


            if (ImGui::BeginTabItem("Custom Hud")) {
               
                ImGui::Indent();
                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "These are the settings for the custom hud and custom crosshair ");

                ImGui::NewLine(); 
                ImGui::NewLine();
               

                if (ImGui::Button("Apply Profile Colors")) {
                    idDeclUIColorManager::setKaibzHudColorsToGameColorProfile();
                }
                guiHelper::insertToolTipSameLine("By pressing this button, the custom crosshair and hud colors will be set close to the game settings color profile");   
                ImGui::SameLine();
                ImGui::TextColored(YellowColorImVec4, "This will automatically set all the colors for the custom hud");
                       
                ImGui::Indent();
                ImGui::NewLine();
                
                CautionColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudCautionColorImU32());
                ImGui::ColorEdit3("Caution Color", (float*)&CautionColorImVec4);
                guiHelper::insertToolTipSameLine("the color of icons/texts when their status is at caution level\n For ex when radiation is below half)");
                modSettings::setKaibzHudCautionColorImU32(ImGui::ColorConvertFloat4ToU32(CautionColorImVec4));

                ImGui::NewLine();

                WarningColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudWarningColorImU32());
                ImGui::ColorEdit3("Warning Color", (float*)&WarningColorImVec4);
                guiHelper::insertToolTipSameLine("the color of icons/texts when their status is at warning level");
                modSettings::setKaibzHudWarningColorImU32(ImGui::ColorConvertFloat4ToU32(WarningColorImVec4));

                ImGui::NewLine();

                CriticalColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudCriticalColorImU32());
                ImGui::ColorEdit3("Critical Color", (float*)&CriticalColorImVec4);
                guiHelper::insertToolTipSameLine("the color of icons/texts when their status is at critical level.\nFor ex when health or ammo is very low");
                modSettings::setKaibzHudCriticalColorImU32(ImGui::ColorConvertFloat4ToU32(CriticalColorImVec4));

                ImGui::NewLine();

                DisabledColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudDisabledColorImU32());
                ImGui::ColorEdit3("Cooldown/empty Color", (float*)&DisabledColorImVec4);
                guiHelper::insertToolTipSameLine("the color of icons/text when recharging or empty");
                modSettings::setKaibzHudDisabledColorImU32(ImGui::ColorConvertFloat4ToU32(DisabledColorImVec4));

                ImGui::Unindent();

                ImGui::NewLine();  
                ImGui::NewLine();

                //! CUSTOM CROSSHAIR:

                bool isUseCustomDotCrosshair = modSettings::getIsUseImguiDotCrosshair();
                ImGui::Checkbox("Use Custom Dot Crosshair", &isUseCustomDotCrosshair);
                guiHelper::insertToolTipSameLine("Checked: uses a custom dot crosshair, you can change its size, color, cooldown color \nIt has a black outline so it's much easier to see compared to the one from the game\nYou can use this dot with the game crosshair if you want\nBut The InGame Dot will be disabled when you use the custom one \nUnchecked: No custom dot crosshair ");
                modSettings::setIsUseImguiDotCrosshair(isUseCustomDotCrosshair);

              

                if (modSettings::getIsUseImguiDotCrosshair()) {
                   
                    ImGui::Indent();
                    ImGui::NewLine(); 


                    bool isShowHealthAsCrosshairColor = modSettings::getCustomCrosshairIsShowHealthAsColor();
                    ImGui::Checkbox("Show Health as crosshair Color", &isShowHealthAsCrosshairColor);
                    guiHelper::insertToolTipSameLine("Checked: Will change the color of the crosshair based how health.\nThis will use the custom colors as so:\nArmor Max Color when health is full (max value of health + armor) \nArmor Color when lower than max health+armor\nHealth Color when no armor and above 50% Health\nCaution Color when below 50% health\nWarning Color when below %25 health\nIf you use the crosshair cooldown color feature make sure the color is not one of those");
                    modSettings::setCustomCrosshairIsShowHealthAsColor(isShowHealthAsCrosshairColor);

                    
                    if (!isShowHealthAsCrosshairColor) {

                        ImGui::NewLine();

                        ImVec4 dotCrosshairColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getCustomDotCrosshairColorImU32());
                        ImGui::ColorEdit3("Custom Dot Crosshair color", (float*)&dotCrosshairColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of the Dot crosshair");
                        modSettings::setCustomDotCrosshairColorImU32(ImGui::ColorConvertFloat4ToU32(dotCrosshairColorImVec4));
                    }

                    

                    ImGui::NewLine();
                   
                 
                    ImVec4 dotCrosshairCooldownColorImVec4  = ImGui::ColorConvertU32ToFloat4(modSettings::getCustomDotCrosshairCooldownColorImU32());                   
                  
                    ImGui::ColorEdit3("Custom Dot Crosshair Coodown color", (float*)&dotCrosshairCooldownColorImVec4);
                    guiHelper::insertToolTipSameLine("the color of the dot crosshair when the weapon is recharging for meathook or stickies");                  
                    modSettings::setCustomDotCrosshairCooldownColorImU32(ImGui::ColorConvertFloat4ToU32(dotCrosshairCooldownColorImVec4));

                    ImGui::NewLine();   


                    int dotCrosshairSizePix = (int)modSettings::getImguiCustomDotCrosshairRadiusPix();
                    ImGui::SliderInt("Custom Dot Crosshair Radius", &dotCrosshairSizePix, 0, 25);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##CustomDotCrosshairRadius")) {
                        dotCrosshairSizePix = 3;
                    }
                    guiHelper::insertToolTipSameLine("The radius in pixels of the custom dot crosshair");
                    modSettings::setImguiCustomDotCrosshairRadiusPix((float)dotCrosshairSizePix);

                    ImGui::Unindent();

                }  

                ImGui::NewLine();
                ImGui::NewLine();
                ImGui::NewLine();


                bool isUseKaibzHud = modSettings::getIsUseKaibzHud();
                ImGui::Checkbox("Use Custom Hud", &isUseKaibzHud);
                guiHelper::insertToolTipSameLine("Checked: a customizable hud\nUnckecked: no custom hud");
                modSettings::setIsUseKaibzHud(isUseKaibzHud);


                if (isUseKaibzHud) {

                    ImGui::Indent();
                    ImGui::NewLine();

                    ImGui::TextColored(WhiteColorImVec4, "Hud Offset X: ");  
                    int hudOffsetXPrct = modSettings::getKaibzHudOffsetX();
                    ImGui::SliderInt("##HudOffsetX", &hudOffsetXPrct, -100, 100);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##hudOffsetXPrct")) {
                        hudOffsetXPrct = 0;
                    }
                    guiHelper::insertToolTipSameLine("You can move the custom Hud more to the left by setting a negative value and to the right with a positive value");
                    modSettings::setKaibzHudOffsetX(hudOffsetXPrct);
                 
                    ImGui::NewLine();

                    ImGui::TextColored(WhiteColorImVec4, "Hud Offset Y: ");
                    int hudOffsetYPrct = modSettings::getKaibzHudOffsetY();
                    ImGui::SliderInt("##HudOffsetY", &hudOffsetYPrct, -100, 0);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##HudOffsetYPrct")) {
                        hudOffsetYPrct = 0;
                    }
                    guiHelper::insertToolTipSameLine("You can move the custom Hud more towards the TOP using a NEGATIVE value ");
                    modSettings::setKaibzHudOffsetY(hudOffsetYPrct);

                   
                    ImGui::NewLine();     

                    ImGui::TextColored(WhiteColorImVec4, "Icons Spacing: ");
                    float HudIconExtraSpacingMul = modSettings::getKaibzHudIconExtraSpacingMul();
                    ImGui::SliderFloat("##HudIconsSpacing", &HudIconExtraSpacingMul, modSettingsDefault::g_defaultIconExtraSpacingMulMin, modSettingsDefault::g_defaultIconExtraSpacingMulMax);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##HudIconExtraSpacingMul")) {
                        HudIconExtraSpacingMul = modSettingsDefault::g_defaultIconExtraSpacingMul;
                    }
                    guiHelper::insertToolTipSameLine("How far apart should the icons be on x axis, in pixels");
                    modSettings::setKaibzHudIconExtraSpacingMul(HudIconExtraSpacingMul);
                  
                    
                    ImGui::NewLine();

                    ImGui::TextColored(WhiteColorImVec4, "Icons/Text Size: ");
                    ImGui::SameLine();
                    ImGui::TextColored(YellowColorImVec4, "(Requires Restart)");

                    int HudFontSize = (int)modSettings::getKaibzHudIconFontSize();
                    ImGui::SliderInt("##HudIconsTextSize", &HudFontSize, 4, 64);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##HHudFontSize")) {
                        HudFontSize = (int)modSettingsDefault::g_defaultKaibzHudIconFontSize;;
                    }
                    guiHelper::insertToolTipSameLine("The size of icons and text, REQUIRES RESTART FOR CHANGES TO REFLECT");
                    modSettings::setKaibzHudIconFontSize((float)HudFontSize);


                    ImGui::NewLine();


                    bool isHideHudInAds = modSettings::getFlag(KaibzHudFlag::HideHudInAds);
                    ImGui::Checkbox("Hide Hud in ADS", &isHideHudInAds);
                    guiHelper::insertToolTipSameLine("Checked: The hud will be hidden when in scope, just like it works with the game hud\nUnchecked: show the hud when in scope");
                    modSettings::setFlag(KaibzHudFlag::HideHudInAds, isHideHudInAds);
                    
                    ImGui::NewLine();

                    bool isFlashHudForFragCountChange = modSettings::getFlag(KaibzHudFlag::FlashHudForFragCount);
                    ImGui::Checkbox("Flash Hud Bg on Frag Count Change", &isFlashHudForFragCountChange);
                    guiHelper::insertToolTipSameLine("Checked: will quickly flash the hud background when the frag nade count went from 0=>1 or 1=>2 \nUnchecked: no hud flash for frag count change");
                    modSettings::setFlag(KaibzHudFlag::FlashHudForFragCount, isFlashHudForFragCountChange);

                    ImGui::NewLine();

                    bool isFlashHudForIceCountChange = modSettings::getFlag(KaibzHudFlag::FlashHudForIceCount);
                    ImGui::Checkbox("Flash Hud Bg on Ice Count Change", &isFlashHudForIceCountChange);
                    guiHelper::insertToolTipSameLine("Checked: will quickly flash the hud background when the ice nade count went from 0=>1 \nUnchecked: no hud flash for ice count change");
                    modSettings::setFlag(KaibzHudFlag::FlashHudForIceCount, isFlashHudForIceCountChange);

                    ImGui::NewLine();

                    bool isFlashHudForBloodPunchCountChange = modSettings::getFlag(KaibzHudFlag::FlashHudForBloodPunchCount);
                    ImGui::Checkbox("Flash Hud Bg on Blood Punch Count Change", &isFlashHudForBloodPunchCountChange);
                    guiHelper::insertToolTipSameLine("Checked: will quickly flash the hud background when the blood punch count went from 0=>1 or 1=>2 \nUnchecked: no hud flash for blood punch count change");
                    modSettings::setFlag(KaibzHudFlag::FlashHudForBloodPunchCount, isFlashHudForBloodPunchCountChange);

                    ImGui::NewLine();

                    bool isFlashHudForHammerCountChange = modSettings::getFlag(KaibzHudFlag::FlashHudForHammerCount);
                    ImGui::Checkbox("Flash Hud Bg on Hammer Count Change", &isFlashHudForHammerCountChange);
                    guiHelper::insertToolTipSameLine("Checked: will quickly flash the hud background when the hammer charge count went from 0=>1  \nUnchecked: no hud flash for hammer charge change");
                    modSettings::setFlag(KaibzHudFlag::FlashHudForHammerCount, isFlashHudForHammerCountChange);

                    ImGui::NewLine();

                    


                    ImGui::NewLine();

                    ImGui::TextColored(WhiteColorImVec4, "Hud Background Opacity: ");
                    float hudBgOpacity = modSettings::getKaibzHudBgOpacity();
                    ImGui::SliderFloat("Hud Background Opacity", &hudBgOpacity, 0.0f, 1.0f);
                    ImGui::SameLine();
                    if (ImGui::Button("RESET##hudBgOpacity")) {
                        hudBgOpacity = modSettingsDefault::g_defaultKaibzHudBgOpacity;
                    }
                    guiHelper::insertToolTipSameLine("How visible should be the black rectangle behind the hud, the lower => the less visible\nIf you have trouble seeing elements on the hud set the opacity higher");
                    modSettings::setKaibzHudBgOpacity(hudBgOpacity);


                    ImGui::NewLine();
                    ImGui::NewLine();

                    ImGui::TextColored(WhiteColorImVec4, "Hud Elements Customisation: (You can set each element color and visibility)");

                    ImGui::NewLine();                   
                   

                    bool hudShowExtraLives = modSettings::getFlag(KaibzHudFlag::ShowExtraLives);
                    ImGui::Checkbox("Show Extra Lives Icon", &hudShowExtraLives);
                    guiHelper::insertToolTipSameLine("Checked: Show extra lives icon\nUnchecked: Do not show extra lives icon");
                    modSettings::setFlag(KaibzHudFlag::ShowExtraLives, hudShowExtraLives);

                    if (hudShowExtraLives) {
                        ImGui::Indent();
                        ImGui::NewLine();

                        ExtraLivesIconColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudExtraLivesColorImU32());
                        ImGui::ColorEdit3("Extra Lives Icon Color", (float*)&ExtraLivesIconColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of the Extra Life Icon when player has extra lives");
                        modSettings::setKaibzHudExtraLivesColorImU32(ImGui::ColorConvertFloat4ToU32(ExtraLivesIconColorImVec4));

                        ImGui::Unindent();                 

                    }

                    ImGui::NewLine();

                    bool hudShowBloodPunch = modSettings::getFlag(KaibzHudFlag::ShowBloodPunch);
                    ImGui::Checkbox("Show Blood Punch Icon", &hudShowBloodPunch);
                    guiHelper::insertToolTipSameLine("Checked: Show blood punch  icon\nUnchecked: Do not show blood punch icon");
                    modSettings::setFlag(KaibzHudFlag::ShowBloodPunch, hudShowBloodPunch);

                    if (hudShowBloodPunch) {

                        ImGui::Indent();
                        ImGui::NewLine();

                        BloodPunch1ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudBloodPunch1ColorImU32());
                        ImGui::ColorEdit3("Blood Punch 1 Color", (float*)&BloodPunch1ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Blood Punch 1");
                        modSettings::setKaibzHudBloodPunch1ColorImU32(ImGui::ColorConvertFloat4ToU32(BloodPunch1ColorImVec4));

                        ImGui::NewLine();


                         BloodPunch2ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudBloodPunch2ColorImU32());
                        ImGui::ColorEdit3("Blood Punch 2 Color", (float*)&BloodPunch2ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Blood Punch 2");
                        modSettings::setKaibzHudBloodPunch2ColorImU32(ImGui::ColorConvertFloat4ToU32(BloodPunch2ColorImVec4));

                        ImGui::NewLine();


                         BloodPunchDesperateColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudBloodPunchDesperateColorImU32());
                        ImGui::ColorEdit3("Blood Punch Desperate Color", (float*)&BloodPunchDesperateColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Desperate Punch");
                        modSettings::setKaibzHudBloodPunchDesperateColorImU32(ImGui::ColorConvertFloat4ToU32(BloodPunchDesperateColorImVec4));

                        ImGui::Unindent();
                    }

                    ImGui::NewLine();

                    bool hudShowRadsuitOrOxygen = modSettings::getFlag(KaibzHudFlag::ShowRadsuitOrOxygen);
                    ImGui::Checkbox("Show Radsuit Or Oxygen Icons", &hudShowRadsuitOrOxygen);
                    guiHelper::insertToolTipSameLine("Checked: Show radsuit or oxygen icon\nUnchecked: Do not show radsuit or oxygen icon");
                    modSettings::setFlag(KaibzHudFlag::ShowRadsuitOrOxygen, hudShowRadsuitOrOxygen);

                    if (hudShowRadsuitOrOxygen) {

                        ImGui::Indent();
                        ImGui::NewLine();

                         RadsuitColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudRadsuitColorImU32());
                        ImGui::ColorEdit3("Radsuit Color", (float*)&RadsuitColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Radsuit HUD element");
                        modSettings::setKaibzHudRadsuitColorImU32(ImGui::ColorConvertFloat4ToU32(RadsuitColorImVec4));

                        ImGui::NewLine();

                         OxygenColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudOxygenColorImU32());
                        ImGui::ColorEdit3("Oxygen Color", (float*)&OxygenColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Oxygen HUD element");
                        modSettings::setKaibzHudOxygenColorImU32(ImGui::ColorConvertFloat4ToU32(OxygenColorImVec4));

                        ImGui::Unindent();
                    }

                    ImGui::NewLine();


                    bool showBasics = modSettings::getFlag(KaibzHudFlag::ShowBasics);
                    ImGui::Checkbox("Show Health/Armor/Ammo Icons", &showBasics);
                    guiHelper::insertToolTipSameLine("Checked: Show health, armor and ammo icons, with or without text\nUnchecked: Do not show basic icons/text");
                    modSettings::setFlag(KaibzHudFlag::ShowBasics, showBasics);      

                    if (showBasics) {

                        ImGui::Indent();
                        ImGui::NewLine();

                        bool hudShowNumbers = modSettings::getFlag(KaibzHudFlag::ShowNumbers);
                        ImGui::Checkbox("Show Numbers", &hudShowNumbers);
                        guiHelper::insertToolTipSameLine("Checked: Show numbers for health, armor, ammor\nUnckecked: no numbers, which is good if you like a minimalistic hud\n with just icons that show health, armor or ammo by their colors");
                        modSettings::setFlag(KaibzHudFlag::ShowNumbers, hudShowNumbers);

                        ImGui::NewLine();

                         HealthMaxColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudHealthMaxColorImU32());
                        ImGui::ColorEdit3("Health Max Color", (float*)&HealthMaxColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Health icon and text when Health is Max");
                        modSettings::setKaibzHudHealthMaxColorImU32(ImGui::ColorConvertFloat4ToU32(HealthMaxColorImVec4));

                        ImGui::NewLine();

                         HealthColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudHealthColorImU32());
                        ImGui::ColorEdit3("Health Color", (float*)&HealthColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Health icon and text when health is NOT low or critical");
                        modSettings::setKaibzHudHealthColorImU32(ImGui::ColorConvertFloat4ToU32(HealthColorImVec4));

                        ImGui::NewLine();

                        ArmorMaxColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudArmorMaxColorImU32());
                        ImGui::ColorEdit3("Armor Max Color", (float*)&ArmorMaxColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Armor icon and text when Armor is Max");
                        modSettings::setKaibzHudArmorMaxColorImU32(ImGui::ColorConvertFloat4ToU32(ArmorMaxColorImVec4));

                        ImGui::NewLine();

                        ArmorColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudArmorColorImU32());
                        ImGui::ColorEdit3("Armor Color", (float*)&ArmorColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of Armor icon when player has armor");
                        modSettings::setKaibzHudArmorColorImU32(ImGui::ColorConvertFloat4ToU32(ArmorColorImVec4));

                        ImGui::NewLine();

                        AmmoColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudAmmoColorImU32());
                        ImGui::ColorEdit3("Ammo Color", (float*)&AmmoColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Ammo text and icon when ammo is NOT critical");
                        modSettings::setKaibzHudAmmoColorImU32(ImGui::ColorConvertFloat4ToU32(AmmoColorImVec4));


                        ImGui::Unindent();

                    }


                    ImGui::NewLine(); 
                    ImGui::NewLine();

                    bool hudShowHammerOrCrucible = modSettings::getFlag(KaibzHudFlag::ShowHammerOrCrucible);
                    ImGui::Checkbox("Show Hammer Or Crucible Icon", &hudShowHammerOrCrucible);
                    guiHelper::insertToolTipSameLine("Checked: Show hammer or crucible icon\nUnchecked: Do not show hammer or crucible icon");
                    modSettings::setFlag(KaibzHudFlag::ShowHammerOrCrucible, hudShowHammerOrCrucible);

                    if (hudShowHammerOrCrucible) {

                        ImGui::Indent();
                        ImGui::NewLine();

                         HammerCrucibleColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudHammerCrucibleColorImU32());
                        ImGui::ColorEdit3("Hammer/Crucible Icon Color", (float*)&HammerCrucibleColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Hammer/Crucible Icon");
                        modSettings::setKaibzHudHammerCrucibleColorImU32(ImGui::ColorConvertFloat4ToU32(HammerCrucibleColorImVec4));

                        ImGui::Unindent();
                    }

                    ImGui::NewLine();

                    bool hudShowFlameBelch = modSettings::getFlag(KaibzHudFlag::ShowFlameBelch);
                    ImGui::Checkbox("Show Flame Belch Icon", &hudShowFlameBelch);
                    guiHelper::insertToolTipSameLine("Checked: Show flame belch icon\nUnchecked: Do not show flame belch icon");
                    modSettings::setFlag(KaibzHudFlag::ShowFlameBelch, hudShowFlameBelch);

                    if (hudShowFlameBelch) {

                        ImGui::Indent();
                        ImGui::NewLine();

                         FlameBelchColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFlameBelchColorImU32());
                        ImGui::ColorEdit3("Flame Belch Icon Color", (float*)&FlameBelchColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Flame Belch Icon");
                        modSettings::setKaibzHudFlameBelchColorImU32(ImGui::ColorConvertFloat4ToU32(FlameBelchColorImVec4));

                        ImGui::Unindent();
                    }

                    ImGui::NewLine();

                    bool hudShowFuel = modSettings::getFlag(KaibzHudFlag::ShowFuel);
                    ImGui::Checkbox("Show Fuel Icon", &hudShowFuel);
                    guiHelper::insertToolTipSameLine("Checked: Show fuel icon\nUnchecked: Do not show fuel icon");
                    modSettings::setFlag(KaibzHudFlag::ShowFuel, hudShowFuel);

                    if (hudShowFuel) {

                        ImGui::Indent();
                        ImGui::NewLine();

                       
                         Fuel1ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFuel1ColorImU32()); 
                        ImGui::ColorEdit3("Fuel 1 Color", (float*)&Fuel1ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Fuel 1 HUD element");
                        modSettings::setKaibzHudFuel1ColorImU32(ImGui::ColorConvertFloat4ToU32(Fuel1ColorImVec4));

                        ImGui::NewLine();

                         Fuel2ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFuel2ColorImU32());
                        ImGui::ColorEdit3("Fuel 2 Color", (float*)&Fuel2ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Fuel 2 HUD element");
                        modSettings::setKaibzHudFuel2ColorImU32(ImGui::ColorConvertFloat4ToU32(Fuel2ColorImVec4));

                        ImGui::NewLine();

                         Fuel3ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFuel3ColorImU32());
                        ImGui::ColorEdit3("Fuel 3 Color", (float*)&Fuel3ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color for the Fuel 3 HUD element");
                        modSettings::setKaibzHudFuel3ColorImU32(ImGui::ColorConvertFloat4ToU32(Fuel3ColorImVec4));

                        ImGui::Unindent();

                    }

                    ImGui::NewLine();

                    bool hudShowFrag = modSettings::getFlag(KaibzHudFlag::ShowFragOrEquipment);
                    ImGui::Checkbox("Show Frag Icon/Equipment", &hudShowFrag);
                    guiHelper::insertToolTipSameLine("Checked: Show frag icon. If user is NOT using the dedicated nades keys mod feature, it will also show ice icon.\nUnchecked: Do not show frag icon/equipment");
                    modSettings::setFlag(KaibzHudFlag::ShowFragOrEquipment, hudShowFrag);

                    if (hudShowFrag) {

                        ImGui::Indent();
                        ImGui::NewLine();

                         Frag1ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFrag1ColorImU32());
                        ImGui::ColorEdit3("1 Frag Icon Color", (float*)&Frag1ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of the Frag Icon when player has 1 frag nade");
                        modSettings::setKaibzHudFrag1ColorImU32(ImGui::ColorConvertFloat4ToU32(Frag1ColorImVec4));

                         Frag2ColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudFrag2ColorImU32());
                        ImGui::ColorEdit3("2 Frag Icon Color", (float*)&Frag2ColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of the Frag Icon when player has 1 frag nade");
                        modSettings::setKaibzHudFrag2ColorImU32(ImGui::ColorConvertFloat4ToU32(Frag2ColorImVec4));

                        ImGui::Unindent();
                    }

                    ImGui::NewLine();

                    bool hudShowIce = modSettings::getFlag(KaibzHudFlag::ShowIce);
                    ImGui::Checkbox("Show Ice Icon", &hudShowIce);
                    guiHelper::insertToolTipSameLine("Checked: Show ice icon\nUnchecked: Do not show ice icon");
                    modSettings::setFlag(KaibzHudFlag::ShowIce, hudShowIce);

                    if (hudShowIce) {

                        ImGui::Indent();
                        ImGui::NewLine();

                        IceColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getKaibzHudIceColorImU32());
                        ImGui::ColorEdit3("Ice Icon Color", (float*)&IceColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of the Ice Icon Color");
                        modSettings::setKaibzHudIceColorImU32(ImGui::ColorConvertFloat4ToU32(IceColorImVec4));

                        ImGui::NewLine();

                        IceCooldownColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getkaibzHudIceCooldownColorImU32());
                        ImGui::ColorEdit3("Ice Cooldown Icon Color", (float*)&IceCooldownColorImVec4);
                        guiHelper::insertToolTipSameLine("the color of the animating circle and icon when Ice nade is recharging");
                        modSettings::setkaibzHudIceCooldownColorImU32(ImGui::ColorConvertFloat4ToU32(IceCooldownColorImVec4));

                        ImGui::Unindent();
                    }

                    ImGui::NewLine();    

                   


                    ImGui::Unindent(); // custom hud

                }         
                
                

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();

            }    



            if (ImGui::BeginTabItem("Game Hud")) {

                ImGui::NewLine();  
                ImGui::NewLine();
                ImGui::Indent();

               
                ImGui::TextColored(WhiteColorImVec4, "Crosshair Scale");
                static int uiReticleScaleInt = (int)(modSettings::getReticleScale() * 100);
                ImGui::SliderInt("##reticleScaleInt", &uiReticleScaleInt, 50, 200);
                ImGui::SameLine();
                if (ImGui::Button("RESET##uiReticleScaleInt")) {
                    uiReticleScaleInt = 100;
                }
                guiHelper::insertToolTipSameLine("The size of the game crosshairs");

                float valF = ((float)uiReticleScaleInt / 100);

                if (modSettings::getReticleScale() != valF) {
                    //logInfo("mod menu setting reticle scale to %.3f ", valF);
                    modSettings::setReticleScale(valF);
                }


                ImGui::NewLine();

                ImVec2 maxBindComboBoxWidhtVec2 = ImGui::CalcTextSize("*******************************************************");
                static float comboBoxMaxWidthF = maxBindComboBoxWidhtVec2.x;

                static int selectedCrosshairLevel = (int)modSettings::getImmersiveCrosshairLevel();

                // Inside your ImGui window or tab
                ImGui::Text("Immersive Crosshair Level:");
               
                const char* crosshairLevels[] = { "Default Game Behaviour", "Only in HAR ADS", "Only in HAR ADS and Balista ADS", "Only in HAR ADS and Balista (ADS or not)" };
                const int numCrosshairLevels = sizeof(crosshairLevels) / sizeof(crosshairLevels[0]);
                if (ImGui::Combo("##CrosshairLevel", &selectedCrosshairLevel, crosshairLevels, numCrosshairLevels)) {
                    // Handle changes in selected crosshair level here
                    modSettings::setImmersiveCrosshairLevel(selectedCrosshairLevel);

                }
                guiHelper::insertToolTipSameLine("This is for people who like to play with no crosshair BUT who think that there should be one in some ADS weapons.\nHere you can select to only show the crosshair in specific situations");
               
               
                ImGui::NewLine();


                bool isCleanHud = modSettings::getIsRemoveBindsReminderOnHud();
                ImGui::Checkbox("Clean Hud", &isCleanHud);
                guiHelper::insertToolTipSameLine("Checked: Removes the shortcuts reminders above the hud, they really clutter the hud. Unchecked: default game behaviour.");
                modSettings::setIsRemoveBindsReminderOnHud(isCleanHud);

                ImGui::NewLine();

                bool isDisableHitMarkers = (bool)modSettings::getIsDisableHitMarker();
                ImGui::Checkbox("Disable Hit Markers", &isDisableHitMarkers);
                guiHelper::insertToolTipSameLine("Checked: Removes the little cross that shows up around the crosshair when you hit something. Unchecked: default game behaviour.");
                modSettings::setIsDisableHitMarker(isDisableHitMarkers);

                ImGui::NewLine();


                bool isDisableDashBlur = modSettings::getIsDisabledDashBlurEffect();
                ImGui::Checkbox("Disable Dash Blur", &isDisableDashBlur);
                guiHelper::insertToolTipSameLine("Checked: Removes white blur on the side of the screen when dashing. Unchecked: default game behaviour.");
                modSettings::setIsDisabledDashBlurEffect(isDisableDashBlur);

             
                ImGui::NewLine();
                ImGui::NewLine();
                
                ImGui::TextColored(WhiteColorImVec4, "Here you can override some of the game's Hud icons colors");

                              

                ImGui::NewLine();

                //? this is very fragile this code, try not to modify or modify the  as mapping the enums to combo selection is..fragile. so DO NOT MODIFY swfNamedColors_t in commonDE.h
                // Define the array of color options
                const char* colorOptions[] = {
                    "Default", "Red", "Green", "Blue", "Yellow", "Magenta", "Cyan", "Orange", "Purple",
                    "Pink", "Brown", "White", "Light Grey", "Mid Grey", "Dark Grey", "Black",
                    "Light Blue", "Dark Blue", "Light Green", "Dark Green", "Light Red",
                    "Light Yellow", "Dark Purple", "Light Pink", "Dark Brown"
                };

                //! this seems weird but we have to do this to make this shitty system work. but i tried an alternative with DeclColorManager and i almost went crazy so no thanks.
                int valStart = (int)SWF_CUSTOM_NAMED_COLOR_DEFAULT;
               

                // Define variables to store the selected color indices
                int selectedColorIndex_BloodPunch_1 = modSettings::getOverrideBloodPunchColor1() - valStart;
                int selectedColorIndex_BloodPunch_2 = modSettings::getOverrideBloodPunchColor2() - valStart;
                int selectedColorIndex_Desperate_Punch = modSettings::getOverrideDesperatePunchColor() - valStart;
                int selectedColorIndex_Fuel_3_Pips = modSettings::getOverrideFuel3PipsColor() - valStart;
                int selectedColorIndex_FragNade_Ready = modSettings::getOverrideFragGrenadeColor() - valStart;
                int selectedColorIndex_FragNade_Cooldown = modSettings::getOverrideFragGrenadeCooldownColor() - valStart;
                int selectedColorIndex_IceNade_Ready = modSettings::getOverrideIceGrenadeColor() - valStart;
                int selectedColorIndex_IceNade_Cooldown = modSettings::getOverrideIceGrenadeCooldownColor() - valStart;
                int selectedColorIndex_RadsuitMeter = modSettings::getOverrideRadMeterColor() - valStart;

                bool isColoredWeaponBar = modSettings::getIsWeaponBarColored();


                ImGui::Text("1 BloodPunch Icon Color:");
                ImGui::Combo("##BloodPunch_1_Color", &selectedColorIndex_BloodPunch_1, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("2 BloodPunch Icon Color:");
                ImGui::Combo("##BloodPunch_2_Color", &selectedColorIndex_BloodPunch_2, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("Desperate Punch Icon Color:");
                ImGui::Combo("##Desperate_Punch_Color", &selectedColorIndex_Desperate_Punch, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("Fuel Full Icon_Color:");
                ImGui::Combo("##Fuel_3_Pips_Color", &selectedColorIndex_Fuel_3_Pips, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("FragNade Ready Icon Color:");
                ImGui::Combo("##FragNade_Ready_Color", &selectedColorIndex_FragNade_Ready, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("FragNade Cooldown Icon Color:");
                ImGui::Combo("##FragNade_Cooldown_Color", &selectedColorIndex_FragNade_Cooldown, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("IceNade Ready Icon Color:");
                ImGui::Combo("##IceNade_Ready_Color", &selectedColorIndex_IceNade_Ready, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("IceNade Cooldown Icon Color:");
                ImGui::Combo("##IceNade_Cooldown_Color", &selectedColorIndex_IceNade_Cooldown, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Text("Radiation Suit Meter Color:");
                ImGui::Combo("##Radiation_Suit_Bar_Color", &selectedColorIndex_RadsuitMeter, colorOptions, IM_ARRAYSIZE(colorOptions));

                ImGui::NewLine();

                ImGui::Checkbox("Colored Weapon Bar", &isColoredWeaponBar);
                guiHelper::insertToolTipSameLine("Checked: default game behaviour. \nUnchecked: will make the weapon/ammo info on the hud white instead of being weapon colored like red for rockets or purple for plasma\nThe goal is to reduce the color feedback so the grenades and equipments colors are easier or more intuitive to notice. ");


                modSettings::setOverrideBloodPunchColor1(selectedColorIndex_BloodPunch_1 + valStart);
                modSettings::setOverrideBloodPunchColor2(selectedColorIndex_BloodPunch_2 + valStart);   
                modSettings::setOverrideDesperatePunchColor(selectedColorIndex_Desperate_Punch + valStart);
                modSettings::setOverrideFuel3PipsColor(selectedColorIndex_Fuel_3_Pips + valStart);
                modSettings::setOverrideFragGrenadeColor(selectedColorIndex_FragNade_Ready + valStart);
                modSettings::setOverrideFragGrenadeCooldownColor(selectedColorIndex_FragNade_Cooldown + valStart);
                modSettings::setOverrideIceGrenadeColor(selectedColorIndex_IceNade_Ready + valStart);
                modSettings::setOverrideIceGrenadeCooldownColor(selectedColorIndex_IceNade_Cooldown + valStart);
                modSettings::setOverrideRadMeterColor(selectedColorIndex_RadsuitMeter + valStart);
               
                modSettings::setIsWeaponBarColored(isColoredWeaponBar);


                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "Reset Colors To default:  ");
                ImGui::SameLine();
                if (ImGui::Button("RESET##ResetGameHudColorsTodefault")) {
                    modSettings::resetGameHudColorsToDefault();
                }
                guiHelper::insertToolTipSameLine("Set the game hud colors back to their default values.");
               

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();
                
            }
           


            if (ImGui::BeginTabItem("Weapons")) {

                ImGui::Indent();

                ImGui::NewLine();


                ImGui::TextColored(WhiteColorImVec4, "Weapons FOV Overide:");
                int weaponsFOV = modSettings::getHandsFOV();
                ImGui::SliderInt("##WeaponsFOVOveride", &weaponsFOV, 0, 100);
                ImGui::SameLine();
                if (ImGui::Button("RESET##weaponsFOV")) {
                    weaponsFOV = 0;
                }
                guiHelper::insertToolTipSameLine("How much of the weapon do you want to see.\nYou can either make the weapon disapear by setting a low value\nor see more of the weapons with a higer value.");
                modSettings::setHandsFOV(weaponsFOV);

                ImGui::NewLine();


                ImGui::TextColored(WhiteColorImVec4, "HAR ADS Mouse sensitivity:");
                int harADSSensitivityMouseInt = (int)(modSettings::getAssaultRiflePrecisionBoltMouseSens() * 100);
                ImGui::SliderInt("##HARADSMousesensitivity", &harADSSensitivityMouseInt, 0, 100);
                ImGui::SameLine();
                if (ImGui::Button("RESET##harADSSensitivityMouseInt")) {
                    harADSSensitivityMouseInt = 50;
                }
                guiHelper::insertToolTipSameLine("You can adjust the mouse sensitivity multiplayer when using the precison bolt rifle in ADS mode here.");
                float harADSSensitivityMouseFloat = ((float)harADSSensitivityMouseInt / 100);
                modSettings::setAssaultRiflePrecisionBoltMouseSens(harADSSensitivityMouseFloat);


                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "HAR ADS Controller sens:");
                int harADSSensitivityControllerInt = (int)(modSettings::getAssaultRiflePrecisionBoltControllerSens() * 100);
                ImGui::SliderInt("##HARADSControllersensitivity", &harADSSensitivityControllerInt, 0, 100);
                ImGui::SameLine();
                if (ImGui::Button("RESET##harADSSensitivityControllerInt")) {
                    harADSSensitivityControllerInt = 40;
                }
                guiHelper::insertToolTipSameLine("You can adjust the controller sensitivity multiplayer when using the precison bolt rifle in ADS mode here.");
                float harADSSensitivityControllerFloat = ((float)harADSSensitivityControllerInt / 100);
                modSettings::setAssaultRiflePrecisionBoltControllerSens(harADSSensitivityControllerFloat);


                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "Balista ADS Mouse sensitivity:");
                int balistaADSSensitivityMouseInt = (int)(modSettings::getBallistaArbalestMouseSens() * 100);
                ImGui::SliderInt("##BalistaADSMousesensitivity", &balistaADSSensitivityMouseInt, 0, 100);
                ImGui::SameLine();
                if (ImGui::Button("RESET##balistaADSSensitivityMouseInt")) {
                    balistaADSSensitivityMouseInt = 60;
                }
                guiHelper::insertToolTipSameLine("You can adjust the mouse sensitivity multiplayer when using the balista ADS mode here.");
                float balistaADSSensitivityMouseFloat = ((float)balistaADSSensitivityMouseInt / 100);
                modSettings::setBallistaArbalestMouseSens(balistaADSSensitivityMouseFloat);


                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "Balista ADS Controller sens:");
                int balistaADSSensitivityControllerInt = (int)(modSettings::getBallistaArbalestControllerSens() * 100);
                ImGui::SliderInt("##BalistaADSControllersensitivity", &balistaADSSensitivityControllerInt, 0, 100);
                ImGui::SameLine();
                if (ImGui::Button("RESET##balistaADSSensitivityControllerInt")) {
                    balistaADSSensitivityControllerInt = 60;
                }
                guiHelper::insertToolTipSameLine("You can adjust the controller sensitivity multiplayer when using the balista ADS mode here.");
                float balistaADSSensitivityControllerFloat = ((float)balistaADSSensitivityControllerInt / 100);
                modSettings::setBallistaArbalestControllerSens(balistaADSSensitivityControllerFloat);


                ImGui::NewLine();


                bool removeShotgunZoomAndLoweredSens = modSettings::isOverideShotgunConfig();
                ImGui::Checkbox("Remove Shotgun Zoom And Lowered Sens", &removeShotgunZoomAndLoweredSens);
                guiHelper::insertToolTipSameLine("Checked: Will remove the 'annoying' zoom and forced lowered sensitivity when using shotgun stickies or the full auto mode. \nUnchecked: default game behaviour ");
                modSettings::setIsOverideShotgunConfig(removeShotgunZoomAndLoweredSens);

                ImGui::NewLine();

                bool isRemoveBalistaZoom = modSettings::isRemoveBalistaZoom();
                ImGui::Checkbox("Remove Balista Zoom", &isRemoveBalistaZoom);
                guiHelper::insertToolTipSameLine("Checked: Will remove the Balista zoom. \nUnchecked: default game behaviour ");
                modSettings::setIsRemoveBalistaZoom(isRemoveBalistaZoom);

                ImGui::NewLine();

                bool isWeaponSwitchFix = modSettings::isImprovedWeaponSwitching();
                ImGui::Checkbox("Improve Weapon Switching", &isWeaponSwitchFix);
                guiHelper::insertToolTipSameLine("Checked: An experimental feature that attempts to improve the reliability of weapon switching for mouse and keyboard users.\nIf you have the feeling that sometimes in heated situation that the weapon you're holding doesn't corresond to the key you pressed, turn this feature on. \nUnchecked: default game behaviour");
                modSettings::setIsImprovedWeaponSwitching(isWeaponSwitchFix);

                ImGui::NewLine();


                bool isWeaponSwitchFixBeep = modSettings::isImprovedWeaponSwitchingBeep();
                ImGui::Checkbox("Weapon Switching Fix beep", &isWeaponSwitchFixBeep);
                guiHelper::insertToolTipSameLine("Checked: Plays a small beep when the mod detects a weapon switch error and resends the right weapon button/key, this is more of a debug feature. Unchecked: no beep.");
                modSettings::setIsImprovedWeaponSwitchingBeep(isWeaponSwitchFixBeep);

                ImGui::NewLine();

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();


            }           


            if (ImGui::BeginTabItem("AI")) {

                ImGui::Indent();

                ImGui::NewLine();
               

                bool isForceAiHaste = modSettings::GetIsForceAiHaste();
                ImGui::Checkbox("Force Ai Haste", &isForceAiHaste);
                guiHelper::insertToolTipSameLine("This will make the AI behave/move/attack as if there was a totem nearby. For players who need a challenge. Default setting: Disabled");               
                modSettings::SetIsForceAiHaste(isForceAiHaste);
                

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();

            }



            if (ImGui::BeginTabItem("Other")) {

                ImGui::Indent();

                ImGui::NewLine();

           
                
                bool isDisableAA = modSettings::getIsDisableAA();
                ImGui::Checkbox("Disable Anti Aliasing", &isDisableAA);
                guiHelper::insertToolTipSameLine("Disable Anti aliasing. \nIf you switch DLSS on, it will force the anti aliasing to level 2\nso forcing it to 0 'could' affect perf or DLSS quality. \nDefault Game Setting: enabled");
                ImGui::SameLine();
                ImGui::TextColored(YellowColorImVec4, "    I recommend to NOT disable AA if you use DLSS");
                modSettings::setIsDisableAA(isDisableAA); 

                ImGui::NewLine();
              

                bool isDisableMouseSmoothing = modSettings::GetIsDisableMouseSmoothing();
                ImGui::Checkbox("Disable Mouse Smoothing", &isDisableMouseSmoothing);
                guiHelper::insertToolTipSameLine("Disable Mouse Smoothing. Default Game Setting: disabled");
                modSettings::SetIsDisableMouseSmoothing(isDisableMouseSmoothing);

                ImGui::NewLine();
               

                bool isDisableBloom = modSettings::GetIsDisableBloom();
                ImGui::Checkbox("Disable Bloom", &isDisableBloom);
                guiHelper::insertToolTipSameLine("Disable Bloom in the game. Default Game Setting: enabled");
                modSettings::SetIsDisableBloom(isDisableBloom);

                ImGui::NewLine();              

                int decalLifetimeMultiplier = modSettings::GetDecalLifetimeMultiplier();
                ImGui::SliderInt("Decal Lifetime Multiplier", &decalLifetimeMultiplier, 1, 5);
                guiHelper::insertToolTipSameLine("How long should decals stay in the world.\nDecals are for ex the holes your gun will create on the wall you shoot \nMake sure you don't push this setting too far if your pc can not handle it.\nDefault value: 1");
                modSettings::SetDecalLifetimeMultiplier(decalLifetimeMultiplier);

                ImGui::NewLine();

                float desaturate = modSettings::GetDesaturate();
                ImGui::SliderFloat("Desaturate Colors", &desaturate, 0.0f, 1.0f);
                guiHelper::insertToolTipSameLine("the more you go towards 1, the more desaturated the colors in the game will become. \nDefault game Setting: 0");
                modSettings::SetDesaturate(desaturate);

                ImGui::NewLine();               
               


                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();               

            }   



            if (ImGui::BeginTabItem("Mod")) {

                ImGui::Indent();

                ImGui::NewLine();
                ImGui::Text("Mod UI and input customisation:");
                ImGui::NewLine();

                ImGui::Indent();

                ImVec2 maxBindComboBoxWidhtVec2 = ImGui::CalcTextSize("25Chars******************");
                static float comboBoxMaxWidthF = maxBindComboBoxWidhtVec2.x;
                const char* toggleModMenuSelectedKey = guiHelper::getAllowedKeyName(modSettings::getToggleModSettingsVkCode());

                ImGui::SetNextItemWidth(comboBoxMaxWidthF);
                if (ImGui::BeginCombo("Toggle Mod Menu Keybind", toggleModMenuSelectedKey))
                {
                    // Iterate through the keys and add them to the dropdown
                    for (const KeyInfo& keyInfo : allowedKeyBindsKeyInfos)
                    {
                        bool isFFKeySelected = (toggleModMenuSelectedKey == keyInfo.name);
                        if (ImGui::Selectable(keyInfo.name, isFFKeySelected))
                        {
                            toggleModMenuSelectedKey = keyInfo.name;
                            modSettings::setToggleModSettingsVkCode(keyInfo.vkCode);
                            // Use keyInfo.vkCode as the VK code for the selected key
                            // You can store this value or use it as needed
                        }
                        if (isFFKeySelected)
                        {
                            ImGui::SetItemDefaultFocus(); // Set the focus on the selected item
                        }
                    }

                    ImGui::EndCombo();
                }


                ImGui::NewLine(); // spacing  
                ImGui::NewLine(); // spacing


                ImVec4 shortcutTextColorImVec4 = ImGui::ColorConvertU32ToFloat4(modSettings::getModSettingsShortcutTextColorImU32());

                ImGui::NewLine();
                ImGui::ColorEdit3("Mod Shortcut Text Color", (float*)&shortcutTextColorImVec4);
                guiHelper::insertToolTipSameLine("changes the color/alpha of the text in the game menu (Kaibz Mod [X]) to anything you wish"); 
                modSettings::setModSettingsShortcutTextColorImU32(ImGui::ColorConvertFloat4ToU32(shortcutTextColorImVec4));


                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "ModShortcut Font Size: ");
                ImGui::SameLine();
                ImGui::TextColored(YellowColorImVec4, "(Requires Restart)");
                int ModShortcutFontSize = (int)modSettings::getEternalFontSize();
                ImGui::SliderInt("Shortcut Font Size", &ModShortcutFontSize, 4, 48);
                ImGui::SameLine();
                if (ImGui::Button("RESET##ModShortcutFontSize")) {
                    ModShortcutFontSize = (int)modSettingsDefault::g_defaultEternalFontSize;
                }
                guiHelper::insertToolTipSameLine("The size of the text in the game main menu (Kaibz Mod [X]), REQUIRES RESTART FOR CHANGES TO REFLECT");
                modSettings::setEternalFontSize((float)ModShortcutFontSize);


                ImGui::NewLine();

                ImGui::TextColored(WhiteColorImVec4, "Mod Menu Font Size: ");
                ImGui::SameLine();
                ImGui::TextColored(YellowColorImVec4, "(Requires Restart)");
                int modMenuFontSize = (int)modSettings::getEternalFontSize();
                ImGui::SliderInt("Menu Font Size", &modMenuFontSize, 4, 48);
                ImGui::SameLine();
                if (ImGui::Button("RESET##MmodMenuFontSize")) {
                    modMenuFontSize = (int)modSettingsDefault::g_defaultRobotoFontSize;
                }
                guiHelper::insertToolTipSameLine("The size of the text in the mod menus, REQUIRES RESTART FOR CHANGES TO REFLECT");
                modSettings::setRobotoFontSize((float)modMenuFontSize);

                ImGui::NewLine();

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();

            }



            if (ImGui::BeginTabItem("About")) {

                ImGui::Indent();

                ImGui::NewLine();
                ImGui::Text(Config::getModInfoTextForGui().c_str());
               

                ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                ImGui::Unindent();
                ImGui::EndTabItem();

            }



            if (Config::get() != ModConfig::nexusRelease) {

                if (ImGui::BeginTabItem("Debug")) {
                   
                    ImGui::Indent();
                    ImGui::NewLine();              

                   
                    
                    bool isLogGameConsoleToLogFile = modSettings::isLogConsoleToLogFile();
                    ImGui::Checkbox("Log Console To Log File", &isLogGameConsoleToLogFile);
                    guiHelper::insertToolTipSameLine("Checked: log the game console to the mod log file so that mod author can check if anything is conflicting with the mod not working on your machine.\nREQUIRES GAME RESTART TO TAKE EFFECT \nUnchecked: no log to file.");
                    ImGui::SameLine();
                    ImGui::TextColored(YellowColorImVec4, "  This Setting Requires Restart !");
                    modSettings::setIsLogConsoleToLogFile(isLogGameConsoleToLogFile);                



                    ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
                    ImGui::Unindent();
                    ImGui::EndTabItem();

                  

                }
            }


           


            ImGui::EndTabBar();
        }

        ImGui::PopStyleColor();        
        ImGui::PopStyleVar();

        //ImGui::PopFont(); // Restore default font

        ImGui::End();





    }

    





} // namespace Menu



//? this is the defunc weapons tab that did work, imgui wise, but it just too annoying and frustrating to work on, as there is no consistency between weapons

//if (ImGui::BeginTabItem("Weapons")) {
//
//    static int currentGroupId = (int)customizedWeaponGroupID::SHOTGUN;
//
//    ImGui::NewLine();
//
//
//    if (ImGui::Button("Previous Group")) {
//        currentGroupId--;
//        if (currentGroupId < (int)customizedWeaponGroupID::SHOTGUN)
//            currentGroupId = (int)customizedWeaponGroupID::HAMMER;
//    }
//    ImGui::SameLine();
//    if (ImGui::Button("Next Group")) {
//        currentGroupId++;
//        if (currentGroupId > (int)customizedWeaponGroupID::HAMMER)
//            currentGroupId = (int)customizedWeaponGroupID::SHOTGUN;
//    }
//
//    // Display weapons for the current group
//    ImGui::Separator();
//    ImGui::Text("Group: %d", static_cast<int>(currentGroupId));
//    ImGui::Separator();
//
//
//    std::vector<customizedWeapon*> sortedWeaponForCurrentGroupVec = CustomizedWeaponManager::getSortedCustomWeaponRefsForGroup((customizedWeaponGroupID)currentGroupId);
//
//    for (auto& weapon : sortedWeaponForCurrentGroupVec) {
//        if (weapon->groupId == (customizedWeaponGroupID)currentGroupId) {
//            ImGui::PushID(weapon->name.c_str()); // Use weapon name as a unique ID
//            guiHelper::DrawWeaponSettings(weapon);
//            ImGui::PopID();
//            ImGui::NewLine();
//            ImGui::Separator();
//            ImGui::NewLine();
//        }
//    }
//
//
//
//    ImGui::Dummy(ImVec2(0.0f, verticalSpacingEndTab));
//
//    ImGui::EndTabItem();
//
//
//}


 //? BAK SO WE CAN EXPERIMENT 6/5/24
    //void InitializeContext(HWND hwnd) {
    //    if (ig::GetCurrentContext( ))
    //        return;

    //    ImGui::CreateContext( );
    //    ImGui_ImplWin32_Init(hwnd);

    //    ImGuiIO& io = ImGui::GetIO( );
    //    io.IniFilename = io.LogFilename = nullptr;

    //    //! this doesn't crash the issue was that i was adding io.Fonts->AddFontDefault() before it       
    //    ImFontConfig font_cfg;
    //    font_cfg.FontDataOwnedByAtlas = false;

    //    //! default font 
    //    modMenuFont = io.Fonts->AddFontFromMemoryTTF(robottoData, sizeof(robottoData), 28.0f, &font_cfg);        

    //    debugWindow_font = io.Fonts->AddFontFromMemoryTTF(robottoData, sizeof(robottoData), 15.0f, &font_cfg);


    //    float hudTextFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudTextFontSize());  
    //    customHud_Eternal1font = io.Fonts->AddFontFromMemoryTTF(eternalRegularData, sizeof(eternalRegularData), hudTextFontSize, &font_cfg);


    //    float hudIconsFontSize = guiHelper::getSafeFontSize(modSettings::getKaibzHudIconFontSize());
    //    kaibzHudIconsFont = io.Fonts->AddFontFromMemoryTTF(KaibzDE, sizeof(KaibzDE), hudIconsFontSize, &font_cfg);

    //    //! this works with eternalRegularData 28, but icons for abilities too small
    //   // kaibzIconsDE_Small_Font = io.Fonts->AddFontFromMemoryTTF(KaibzDE, sizeof(KaibzDE), 16.0f, &font_cfg);

    //    //kaibzIconsDE_Medium_Font = io.Fonts->AddFontFromMemoryTTF(KaibzDE, sizeof(KaibzDE), 28.0f, &font_cfg);

    //    //io.Fonts->AddFontFromMemoryTTF(eternalRegularData, sizeof(eternalRegularData), 28.0f, &font_cfg);


    //    //! i was crashing because i was not using the FontDataOwnedByAtlas = false method from here: https://github.com/ocornut/imgui/blob/master/docs/FONTS.md#loading-font-data-from-memory and also because i was having: io.Fonts->AddFontDefault(); before this block. Finally i used the code from the video to make sure it works: https://www.youtube.com/watch?v=2B_qzPHV4MQ
    //    static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
    //   
    //    ImFontConfig config;
    //    config.MergeMode = true;
    //    config.PixelSnapH = true;
    //    config.OversampleH = true;
    //    config.OversampleV = true;
    //    //config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced                  
    //    config.FontDataOwnedByAtlas = false; //! this is what prevent the crash on mod unload
    //    icons_font_awesome = io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &config, icon_ranges);        

    //}
