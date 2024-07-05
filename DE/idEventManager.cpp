#include "idEventManager.h"


bool idEventManager::acquireIdEventDefInterfaceLocal(__int64 addr)
{
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquireIdEventDefInterfaceLocal: addr is bad ptr: %p", (void*)addr);
		m_idEventDefInterfaceLocal = nullptr;
		return false;
	}

	m_idEventDefInterfaceLocal = (idEventDefInterfaceLocal*) *(__int64*)addr;
	logInfo("acquireIdEventDefInterfaceLocal: m_idEventDefInterfaceLocal set to %p", m_idEventDefInterfaceLocal);
	return true;

}

unsigned int idEventManager::GetNumEvents()
{
	return m_idEventDefInterfaceLocal->GetNumEvents();
}

idEventDef* idEventManager::GetEventForNum(unsigned idx)
{
	return m_idEventDefInterfaceLocal->GetEventForNum(idx);
}

const char* idEventManager::GetEventNameForNum(unsigned int eventNum) {
	return m_idEventDefInterfaceLocal->GetEventNameForNum(eventNum);
}

void idEventManager::debug()
{
	if (!m_idEventDefInterfaceLocal) {
		logErr("debug: m_idEventDefInterfaceLocal is bad ptr");
		return;			
	}

	unsigned int eventNums = m_idEventDefInterfaceLocal->GetNumEvents();
	logInfo("debug: eventNums: %u", eventNums);

	const char* eventName = m_idEventDefInterfaceLocal->GetEventNameForNum(0x267);
	if (eventName) {
		logInfo("debug: eventName: %s", eventName);
	}
	else {
		logWarn("debug: eventName: is bad ptr");
	}

	unsigned int numEventArgs = m_idEventDefInterfaceLocal->GetNumEventArgs(0x267);
	logInfo("debug: numEventArgs: %u", numEventArgs);


	idEventDef* skipCinematicEventDef = m_idEventDefInterfaceLocal->FindEvent("skipCinematic");
	if (skipCinematicEventDef) {
		logInfo("debug: skipCinematicEventDef: %p", skipCinematicEventDef);
	}
	else {
		logWarn("debug: skipCinematicEventDef: is bad ptr");
	}


	idEventDef* skipCinematicEventDefFromNum = m_idEventDefInterfaceLocal->GetEventForNum(0x267);
	if (skipCinematicEventDefFromNum) {
		logInfo("debug: skipCinematicEventDefFromNum event def: %p", skipCinematicEventDefFromNum);
	}
	else {
		logWarn("debug: skipCinematicEventDefFromNum: is bad ptr");
	}
}

//! this works to skip a skipable cutscene but, it will not stip the very start of it like at the start of the campaign AND it will not work for like the 'father' scene
void idEventManager::testSendEvent()
{

	m_idSendEventFp = (idSendEvent_t)MemHelper::getFuncAddr(0x4A5540);
	if (MemHelper::isBadReadPtr(m_idSendEventFp)) {
		logErr("testSendEvent: m_idSendEventFp is bad ptr: %p", m_idSendEventFp);
		return;
	}

	__int64 skipCutSceneEventDefAddr = MemHelper::getFuncAddr(0x6C1CF10);
	logInfo("testSendEvent: skipCutSceneEventDefAddr set to: %p", (void*)skipCutSceneEventDefAddr);

	//! the event def addr fro skip cinematic could be 7FF63C32CF10 let's see if that's true...Confirmed it is!
	//! a3 should be 0x10
	//! a4 should be 0 (even if in at  157A11C E8 1F B4 F2 FE    call  sendEventMB_4A5540 a4 is a structure but as it's not used the the func is called by m_idSendEventFp, we should be ok, but IF IT CRASH MAKE THE FUNC ONLY HAVE 3 ARGS)
	//! 
	
	idPlayer* player = idMapInstanceLocalManager::getIdPlayer();

	if (!player) {
		logErr("testSendEvent: can not send player is nullptr");
		return;
	}

	m_idSendEventFp((__int64)player, skipCutSceneEventDefAddr, 0x10, 0i64);

}


void idEventManager::debugLogEventAddr(int eventNum) {

	idEventDef* eventDef = m_idEventDefInterfaceLocal->GetEventForNum(eventNum);
	if (eventDef) {
		logInfo("debugLogEventAddr: event with eventNum %d addr: %p", eventNum, eventDef);
	}
	else {
		logWarn("debugLogEventAddr:  event with eventNum %d: is nullptr", eventNum);
	}
}