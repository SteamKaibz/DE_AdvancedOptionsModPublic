#pragma once
#include "../Config/Config.h"
#include "MemHelper.h"
#include "GeneratedClasses.h"
#include "../K_Utils/K_Utils.h"
#include "idResourceListManager.h"
#include "fastCvarManager.h"


class idDeclGlobalShellManager {

private:

	//static inline __int64 m_decGlobalShellPtP = 0;
	static inline idDeclGlobalShell* m_idDeclGlobalShellPtr = nullptr;

public:
	
	//static bool acquireGlobalDeclAddr(__int64 Ptr);

	//static __int64 getGlobalDeclAddr();

	//! this address will be a ptr to the first profile in the list of profiles.
	//static __int64 getColorProfileColorsListAddr();

	static idDeclUIColor* getCurrentColorProfile();

	static idList* getColorProfileColorsIdList();

	//! the beauty here is that setting a list num to zero will make the game logic thing the list is empty...
	//! also if the pop up is currently displayed, sure it will not dismiss it but it will not crash the game, and next time user launches a campaign it will be gone.
	static void disableNewCampaignPopUp(bool isDisabled);
	

};

