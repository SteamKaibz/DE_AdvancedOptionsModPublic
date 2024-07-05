#pragma once

#include "MemHelper.h"
#include "GeneratedClasses.h"
#include "idMapInstanceLocalManager.h"

struct idEventDefInterfaceLocal;

struct idEventDefInterfaceLocalVtb
{
	void* (__fastcall* dctor)(void* Memory, char a2);
	void* _ZN24idEventDefInterfaceLocal8AddEventE11eventType_tPKcS2_cP10idEventDef;
	void(__fastcall* nullsub_1)();
	void* (__fastcall* _ZNK24idEventDefInterfaceLocal15GetEventCommandEi)(idEventDefInterfaceLocal* thiz, int);
	char** (__fastcall* _ZNK24idEventDefInterfaceLocal9FindEventEPKc)(idEventDefInterfaceLocal* a1, __int64 a2);
	__int64(__fastcall* _ZNK24idEventDefInterfaceLocal18GetEventNumForNameEPKc)(idEventDefInterfaceLocal* a1);
	const char* (__fastcall* _ZNK24idEventDefInterfaceLocal18GetEventNameForNumEi)(idEventDefInterfaceLocal* a1, unsigned);
	unsigned (*_ZNK24idEventDefInterfaceLocal12GetNumEventsEv)(idEventDefInterfaceLocal*);
	unsigned(__fastcall* _ZNK24idEventDefInterfaceLocal15GetNumEventArgsEi)(idEventDefInterfaceLocal* a1, int evt);
	void(__fastcall* _ZNK24idEventDefInterfaceLocal19GetEventArgTypeNameEiiR5idStr)(idEventDefInterfaceLocal* thiz, int, int, idStr*);
	void(__fastcall* _ZNK24idEventDefInterfaceLocal15GetEventArgNameEiiR5idStr)(idEventDefInterfaceLocal* thiz, int, int, idStr*);
	void* field_58;
	void(__fastcall* anonymous_0)();
	void* field_68;
};


struct idEventDefInterfaceLocal {
	idEventDefInterfaceLocalVtb* vtb;

	unsigned GetNumEvents() {
		return vtb->_ZNK24idEventDefInterfaceLocal12GetNumEventsEv(this);
	}

	const char* GetEventNameForNum(unsigned evtnum) {
		return vtb->_ZNK24idEventDefInterfaceLocal18GetEventNameForNumEi(this, evtnum);
	}

	unsigned GetNumEventArgs(unsigned evtnum) {
		return vtb->_ZNK24idEventDefInterfaceLocal15GetNumEventArgsEi(this, evtnum);
	}
	void GetEventArgTypeName(int evt, int arg, idStr* outstr) {
		vtb->_ZNK24idEventDefInterfaceLocal19GetEventArgTypeNameEiiR5idStr(this, evt, arg, outstr);
	}
	void GetEventArgName(int evt, int arg, idStr* outstr) {
		vtb->_ZNK24idEventDefInterfaceLocal15GetEventArgNameEiiR5idStr(this, evt, arg, outstr);
	}


	idEventDef* FindEvent(const char* name) {

		return (idEventDef*)vtb->_ZNK24idEventDefInterfaceLocal9FindEventEPKc(this, (long long)name);
	}
	idEventDef* GetEventForNum(unsigned idx) {
		//ewww 
		return FindEvent(GetEventNameForNum(idx));
	}
	//static idEventDefInterfaceLocal* Singleton();

};



typedef char(__fastcall* idSendEvent_t)(__int64 a1, __int64 idEventDef_a2, int a3, __int64 a4);


/// <summary>
/// this is the event system of the game, at least we found one function used by the game to send events.
/// </summary>
class idEventManager
{
private:

	static inline idEventDefInterfaceLocal* m_idEventDefInterfaceLocal = nullptr;
	static inline idSendEvent_t m_idSendEventFp = nullptr;

public:

	static bool acquireIdEventDefInterfaceLocal(__int64 addr);

	static unsigned int GetNumEvents();

	static idEventDef* GetEventForNum(unsigned idx);

	static const char* GetEventNameForNum(unsigned int eventNum);

	static void debug();

	static void testSendEvent();


	static void debugLogEventAddr(int eventNum);

};

