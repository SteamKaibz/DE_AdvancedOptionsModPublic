#pragma once
#include "CommonDE.h"
#include "../Config/Config.h"
#include "MemHelper.h"
#include "GeneratedEnums.h"
#include "GeneratedClasses.h"



//typedef void(__fastcall* broadcastHudEvent_t)(__int64 idBroadcastManagerPtr_a1, unsigned __int16 hudSysId_a2, __int16 hudEventID_t_a3);
typedef void(__fastcall* broadcastHudEvent_t)(__int64 idBroadcastManagerPtr_a1, uint16_t hudSysId_a2, __int16 hudEventID_t_a3);

/// <summary>
/// this basically hooks idBroadcastManager::ReleaseBroadcastEvent_4899C0 and parse the event type and its data, so we get what we are interested in.
/// </summary>
class idHudEventManager {
	
private:

	static inline __int64 m_broadcastManager = 0;
	static inline broadcastHudEvent_t m_broadcastHudEventFp = nullptr;

public:

	static bool acquireBroadcastManager(__int64 addr);
	static bool acquireBroadcastHudEventFp(__int64 faddr);
	static void send_HUD_EVENT_CURRENCY_CONFIRM(idHUDElement* idHUDMenu_CurrencyConfirmationAddr);
	static void testSendHudEvent(__int64 idHUDMenu_CurrencyConfirmationAddr);

	//static void onReleasedBroadcastEvent(__int64 eventData_a3); //! broken atm


};