#pragma once

#include <cstdint>
#include <vector>

#include "../Common/Patcher.h"
#include "../Common/MinHookManager.h"
#include "../DE/Sigs.h"

#include "../DE/idRenderModelGuiManager.h"
#include "../DE/idGameSystemLocalManager.h"
#include "../DE/LoadingScreenManager.h"
#include "../DE/idDeclGlobalShellManager.h"
#include "../DE/idResourceListManager.h"
#include "../DE/LangManager.h"
#include "../DE/BindLabelChanger.h"
#include "../DE/GameVersionInfoManager.h"
#include "../DE/idMapInstanceLocalManager.h"
#include "../DE/idCvarManager.h"
#include "../DE/ColorManager.h"
#include "../DE/playerPropsManager.h"
#include "../DE/idFxManager.h"
#include "../DE/idEventManager.h"
#include "../DE/idHudEventManager.h"
#include "../DE/winFocusManager.h"
#include "../DE/EquipmentManager.h"






//? this whole cls will need a lot of refactoring and name change !!!!!!!!
//! These static addresses have to be found at run time so that we don't rely on an offset that could change in a potential future game update. We get all the addresses needed for minhook, for idCmd,

class Scanner {

private:


	////? don't forget to keep adding addres to the vec when you create new ones 


public:
	
    static inline uintptr_t SetGetFovTargetValAddr = 0;
    static inline uintptr_t IdPlayerSelectWeaponForSelectionGroupAddr = 0;
    static inline uintptr_t GetIsKeyPressedAddr = 0;
    static inline uintptr_t GetIdMenuUpdateAddr = 0;
    static inline uintptr_t GetPBindsStrSetAddr = 0;
    static inline uintptr_t GetSetActiveReticleAddr = 0;
    static inline uintptr_t GetConvertIdDeclUIColorToIdColorTargetAddr = 0;
    static inline uintptr_t SetSpriteInstanceAddr = 0;
    static inline uintptr_t PrintOutlinedStringMBFuncAddr = 0;
    static inline uintptr_t IdInventoryCollectionSmthFuncAdd = 0;
    static inline uintptr_t IdHUDMenu_CurrencyConfirmationSmthFuncAdd = 0;
    static inline uintptr_t StartSyncFuncAdd = 0;
    static inline uintptr_t IdPlayerFovLerpFuncAdd = 0;
    static inline uintptr_t SyncEndFuncAdd = 0;
    static inline uintptr_t RenderSpriteFuncAdd = 0;
    static inline uintptr_t IdUsercmdGenLocalSendBtnPressFuncAdd = 0;
    static inline uintptr_t ConsoleLogFuncAdd = 0;



	static bool scanForAddrs();

};


