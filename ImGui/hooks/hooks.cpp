#include <cstdio>
#include <mutex>
#include <thread>

#include "hooks.hpp"

#include "backend/dx10/hook_directx10.hpp"
#include "backend/dx11/hook_directx11.hpp"
#include "backend/dx12/hook_directx12.hpp"
#include "backend/dx9/hook_directx9.hpp"

#include "backend/opengl/hook_opengl.hpp"
#include "backend/vulkan/hook_vulkan.hpp"

#include "../console/console.hpp"
#include "../menu/menu.hpp"
#include "../utils/utils.hpp"

#include "../dependencies/minhook/MinHook.h"
#include <MinHook.h>
#include "../../Config/Config.h"
#include "../dependencies/imgui/imgui.h"
#include "../ImGuiDebug.h"
//#include "../ImGuiDebug.h"

static HWND g_hWindow = NULL;
static std::mutex g_mReinitHooksGuard;

static DWORD WINAPI ReinitializeGraphicalHooks(LPVOID lpParam) {
    std::lock_guard<std::mutex> guard{g_mReinitHooksGuard};

    logInfo("ReinitializeGraphicalHooks: Hooks will reinitialize!\n");

    HWND hNewWindow = U::GetProcessWindow( );
    while (hNewWindow == reinterpret_cast<HWND>(lpParam)) {
        hNewWindow = U::GetProcessWindow( );
    }

    H::bShuttingDown = true;

    H::Free( );
    H::Init( );

    H::bShuttingDown = false;
    Menu::bShowMenu = true;

    return 0;
}

static WNDPROC oWndProc;
static LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_KEYDOWN ) {                    


        //! atm we only allow acces to mod settings if user is in main menu or the pause menu 'pause' and only escape key can get user out of mod menu.
        if (wParam == modSettings::getToggleModSettingsVkCode()) {
            if (PlayerStateChecker::isInMainMenu() && !Menu::bShowMenu) {
                Menu::bShowMenu = true;
                return 0;
            }
            //! if a level is loaded and we are in the pause menu 'pause'
            else if (idHudManager::isWorldMenuActive(hudMenuID_t::HUD_MENU_PAUSE) && !Menu::bShowMenu) {
                Menu::bShowMenu = true;
                return 0;
            }
            else if(PlayerStateChecker::isPlayingAndActive()){
                idCmd::ToggleMainMenu(); //! open the pause menu
                Menu::bShowMenu = true;
                return 0;
            }
        }      
      

        else if (wParam == VK_ESCAPE) {
            if (Menu::bShowMenu) {
                logInfo("WndProc: user pressed escape and mod menu is showing: setting bShowMenu to false ");
                Menu::bShowMenu = false;
                return 0;
            }
        }  


        else if (Config::get() != ModConfig::nexusRelease) {

            if (wParam == modSettings::getReloadImguiHooksVk_Key()) {
                logWarn("WndProc: ReinitializeGraphicalHooks called ");
                HANDLE hHandle = CreateThread(NULL, 0, ReinitializeGraphicalHooks, NULL, 0, NULL);
                TTS::addToQueue(L"U.I Hook Restart");
                if (hHandle != NULL)
                    CloseHandle(hHandle);
                return 0;
            }
        }
       

       
        /*else if (wParam == VK_END) {
            H::bShuttingDown = true;
            U::UnloadDLL( );
            return 0;
        }*/
    } 
    if (uMsg == WM_DESTROY) {

        (logWarn("IMgui Hook WndProcmod WM_DESTROY: forcing in_mouse to 1 to prevent mouse being disabled next time game is launched "));
        idCmd::SetInMouseEnabled(true);

        HANDLE hHandle = CreateThread(NULL, 0, ReinitializeGraphicalHooks, hWnd, 0, NULL);
        if (hHandle != NULL)
            CloseHandle(hHandle);
    }

    ImGuiIO& io = ImGui::GetIO();
    //! this is from new colossus mod:
    LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
   


    if (Menu::bShowMenu)
    {      

        io.MouseDrawCursor = true;
        if (io.WantCaptureMouse) {
            return true;
        }
    }
    else {
        io.MouseDrawCursor = false;
    }
    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
   

    //LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    //if (Menu::bShowMenu) {
    //   ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
    //    //logInfo("ImGui_ImplWin32_WndProcHandler: here...");
    //    // (Doesn't work for some games like 'Sid Meier's Civilization VI')
    //    // Window may not maximize from taskbar because 'H::bShowDemoWindow' is set to true by default. ('hooks.hpp')
    //    //
    //    // return ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam) == 0;


    //   
    //    
    //   

    //    /*if (isInWindow != m_lastIsMouseWithinImGuiWindow)
    //    {

    //        m_lastIsMouseWithinImGuiWindow = isInWindow;
    //        logInfo("m_lastIsMouseWithinImGuiWindow is now : %d", isInWindow);

    //    }
    //    return isInWindow;*/


    //   /* ImGuiIO& io = ImGui::GetIO();
    //    io.MouseDrawCursor = true;*/
    //    //ImGuiDebug::IsMouseWithinImGuiWindow();

    //    //! WantCaptureMouse will only return true if you are actually trying to interact with an element but not if the mouse is where the lmgui ui window is if that makes sens. 
    //    //ImGuiDebug::logWantCaptureMouseChange(io.WantCaptureMouse);

    //    //ImGuiDebug::logIsWindowHovered(ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow));

    //    
    //    //if (io.WantCaptureMouse) {
    //    //    io.MouseDrawCursor = true;
    //    //    ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam); //block input to game while menu is visible
    //    //    return true;
    //    //}
    //    //else {
    //    //    io.MouseDrawCursor = false;
    //    //}



    //    //ver 1:
    //    ImGuiIO& io = ImGui::GetIO();
    //    ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam); //block input to game while menu is visible
    //    io.MouseDrawCursor = true; //Draw Mouse Cursor


    //    //? this will make the game crash because g.CurrentWindow will be nullptr
    //    //ImGuiDebug::IsMouseWithinImGuiWindow();



    //    return true;


    //}

    //return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}



//? this is WndProc without with (or without) our keybinds tweaks
//static LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    if (uMsg == WM_KEYDOWN && Config::isDevMode()) {
//        if (wParam == VK_INSERT) {
//            Menu::bShowMenu = !Menu::bShowMenu;
//            return 0;
//        }
//        else if (wParam == VK_HOME) {
//            HANDLE hHandle = CreateThread(NULL, 0, ReinitializeGraphicalHooks, NULL, 0, NULL);
//            if (hHandle != NULL)
//                CloseHandle(hHandle);
//            return 0;
//        }
//        else if (wParam == VK_END) {
//            H::bShuttingDown = true;
//            U::UnloadDLL();
//            return 0;
//        }
//    }
//    else if (uMsg == WM_DESTROY) {
//        HANDLE hHandle = CreateThread(NULL, 0, ReinitializeGraphicalHooks, hWnd, 0, NULL);
//        if (hHandle != NULL)
//            CloseHandle(hHandle);
//    }
//
//
//
//
//    LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//    if (Menu::bShowMenu) {
//        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
//   
//         //ver 1:
//        ImGuiIO& io = ImGui::GetIO();
//        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam); //block input to game while menu is visible
//        io.MouseDrawCursor = true; //Draw Mouse Cursor
//
//        ImGuiDebug::IsMouseWithinImGuiWindow();
//
//        return true;
//            }
//
//    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
//}

namespace Hooks {
    void Init( ) {
        g_hWindow = U::GetProcessWindow( );

#ifdef DISABLE_LOGGING_CONSOLE
        bool bNoConsole = GetConsoleWindow( ) == NULL;
        if (bNoConsole) {
            AllocConsole( );
        }
#endif

        RenderingBackend_t eRenderingBackend = U::GetRenderingBackend( );
        switch (eRenderingBackend) {
            case DIRECTX9:
                DX9::Hook(g_hWindow);
                break;
            case DIRECTX10:
                DX10::Hook(g_hWindow);
                break;
            case DIRECTX11:
                DX11::Hook(g_hWindow);
                break;
            case DIRECTX12:
                DX12::Hook(g_hWindow);
                break;
            case OPENGL:
                GL::Hook(g_hWindow);
                break;
            case VULKAN:
                VK::Hook(g_hWindow);
                break;
        }

#ifdef DISABLE_LOGGING_CONSOLE
        if (bNoConsole) {
            FreeConsole( );
        }
#endif

        oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(g_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc)));
    }

    void Free( ) {
        if (oWndProc) {
            SetWindowLongPtr(g_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(oWndProc));
        }

        MH_DisableHook(MH_ALL_HOOKS);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        RenderingBackend_t eRenderingBackend = U::GetRenderingBackend( );
        switch (eRenderingBackend) {
            case DIRECTX9:
                DX9::Unhook( );
                break;
            case DIRECTX10:
                DX10::Unhook( );
                break;
            case DIRECTX11:
                DX11::Unhook( );
                break;
            case DIRECTX12:
                DX12::Unhook( );
                break;
            case OPENGL:
                GL::Unhook( );
                break;
            case VULKAN:
                VK::Unhook( );
                break;
        }
    }
} // namespace Hooks
