#pragma once

#include <cstdint>
#include <vector>

#include "../DE/Patcher.h"
#include "../MinHookManager/MinHookManager.h"
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





//#include "MemHelper.h"
//#include "Sigs.h"
//#include "idGameLocal.h"
//#include "Patcher.h"
//#include "idGameLocalManager.h"
//#include "TypeInfoManager.h"
//#include "idGameSystemLocalManager.h"
//#include "idMapInstanceLocalManager.h"
//#include "../MinHookManager/MinHookManager.h"
//#include "idCmd.h"
//#include "idInventoryManager.h"
//#include "LangManager.h"
//#include "GameVersionInfoManager.h"
//#include "BindLabelChanger.h"
//#include "idFontManager.h"
//#include "idDeclInfo.h"
//#include "../DE/idRenderModelGuiManager.h"
//#include "idDeclGlobalShellManager.h"
//#include "LoadingScreenManager.h"

//? this whole cls will need a lot of refactoring and name change !!!!!!!!
//! These static addresses have to be found at run time so that we don't rely on an offset that could change in a potential future game update. We get all the addresses needed for minhook, for idCmd,

class Scanner {

private:


	////? don't forget to keep adding addres to the vec when you create new ones 


public:
	

	static bool scanForAddrs();

};


