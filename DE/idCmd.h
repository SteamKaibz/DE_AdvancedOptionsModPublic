#pragma once

#include <Windows.h>
#include <emmintrin.h> // This should make the __m128i type available 
#include "MemHelper.h"
//#include "Scanner.h"
#include "Common.h"
#include "TypeInfoManager.h"
#include "idCvarManager.h"
#include "fastCvarManager.h"


//! meathook struts:
struct idListVoid
{
	unsigned __int64* list;
	int num;
	int size;
	__int16 granularity;
	unsigned __int8 memTag;
	unsigned __int8 listStatic;
};

struct idCmdSystemLocalVftbl; // Forward declaration

struct idCmdSystemLocal {
	idCmdSystemLocalVftbl* vftbl;
};

//! this is from Meathook mod:
using _QWORD = unsigned  long long;
struct idCmdSystemLocalVftbl
{
	void* first; // 0
	void* field_8; // 8
	__int64(__fastcall* field_10)(__int64 a1, int a2); // 10
	void* _ZN16idCmdSystemLocal10AddCommandEPKcPFvRK9idCmdArgsES1_PFvR14idAutoCompleteEi; // 18
	const char* (__fastcall* _ZN16idCmdSystemLocal21GetCommandDescriptionEPKc)(__int64 a1, __int64 a2); // 20
	_QWORD(__fastcall* _ZN16idCmdSystemLocal13CommandExistsEPKcb)(idCmdSystemLocal* thiz, const char*, bool); // 28
	void* _ZN16idCmdSystemLocal12FindCommandsEPKcR6idListI5idStrL8memTag_t5ELb0EE; // 30
	void* field_38; // 38 
	_QWORD(__fastcall* _ZN16idCmdSystemLocal18ExecuteCommandTextEPKc)(idCmdSystemLocal* thiz, const char*); // 40
	void* field_48;
	//void *field_50;
	_QWORD(__fastcall* _AppendCommandHack)(idCmdSystemLocal* thiz, const char*); // 48
	void* _GenerateTestCases__$TestDummyTemplatedParametricTestFixture_V_$hash_map_H_NU_$hash_H_core__U_$equal_to_H_std___core___SuiteTemplatedTestkUnitTestCategory__SAXAEAU_$TestCaseEmitter_HXXXX_Testing___Z;
	void* field_60;
	__int64(__fastcall* field_68)(_QWORD* a1);
	idListVoid* (__fastcall* GetCommands)(idCmdSystemLocal* a1);
	_QWORD(*_ZN16idCmdSystemLocal20ExecuteCommandBufferEv)(idCmdSystemLocal* thiz);
	void* field_80;
};




class idCmd {

private:


	//! using __int64 and not *__int64 so we never make the last ptr arithmetic mistake again...
	//! cvar and cmd system loc ptr never change.
	//inline static __int64 m_cvarSystemLocalPtrAddr = 0;
	inline static __int64 m_idCmdSystemLocal = 0;

	//inline static __int64 m_findCvarFuncAddr = 0;
	//inline static __int64 m_executeCmdFuncAddr = 0;

	//inline static idCVar* m_cached_GetReticleModeCvarPtr = nullptr;
	//inline static idCVar* m_cached_isGameTimeScalingEnabledPtr = nullptr;

	//inline static __int64 m_reapplySwfColorsFuncAdd = 0;

	
	//static __int64 m_skipHudBtnsCallOutOffset;
	//static __int64 m_enableMenuOnMinimizeStructOffset;
	//static __int64 m_settings_ShowHudEquipmentOffset;
	//static __int64 m_settings_ObjectiveMarkerOffset;
	//static __int64 m_settings_UI_SideNotificationOffset;

	//static __int64 m_handsFovScale_SideNotificationOffset;

	
	//static reapplySwfColors m_preapplySwfColors;

	//! _QWORD(__fastcall* _ZN16idCmdSystemLocal18ExecuteCommandTextEPKc)(idCmdSystemLocal* thiz, const char*)
	typedef _QWORD(__fastcall* idCmdSystemLocal_Execute_t)(idCmdSystemLocal* thiz, const char*);
	static inline idCmdSystemLocal_Execute_t m_idCmdSystemLocal_ExecuteFp = nullptr;

	//typedef __int64(__fastcall* CvarFindAddrTest)(__int64* addr, const char*);


	

public:

	
	static uintptr_t executeCommandText(const char* txt);

	static bool acquireIdCmdSystemLocalPtr(__int64 idCmdSystemLocalPtr);

	static bool acquirreExecuteCommandTextFuncPtr();



	//static uintptr_t executeCommandText_K2(const char* txt);


	static void setGameSpeed(gameSpeed_K gameSpeed);

	static void setReticleMode(UI_ReticleMode mode);

	static void showEquipmentInfo(bool isTrue);

	static void skipHudBtnsCallOut(bool isTrue);

	static void showTestMaterial(std::string materialNameStr);

	static void forceDebug_hud_string();

	static void setReticleOverride(reticleStyle_t reticleStyle);

	static void setMinMaxFov(bool isUnlockedFovInMenu);

	/*static void setGameSettingsMinFov(int iniFileValue);

	static void setGameSettingsMaxFov(int iniFileValue);*/

	static void setHandsFov(int iniFileValue);

	static std::string getHandsFovFloatValAsStr(int iniFileValue);

	//! enable/disable mouse input so user can use the mouse in imgui
	static void SetInMouseEnabled(bool isEnable);

	static void ToggleMainMenu();

	static void setAntiAliasingState(bool isDisabledAA);

	static void setMouseSmoothing(bool isDisabled);

	static void setHdrBloom(bool isDisabled);

	static void setDecalLifetimeMultiplier(int value);

	static void setDesaturate(float value);

	static void setIsForceAiHaste(bool isForceAiHaste);




};



//idCmd::idCvar_Set idCmd::m_pIdCvar_Set = reinterpret_cast<idCvar_Set>(MemHelper::getFuncAddr(0x3721A0));

//idCmd::reapplySwfColors idCmd::m_preapplySwfColors = reinterpret_cast<reapplySwfColors>(MemHelper::getFuncAddr(0x4F56D0));

//__int64 idCmd::m_skipHudBtnsCallOutOffset = (__int64)MemHelper::getFuncAddr(0x4549DA0);
//__int64 idCmd::m_enableMenuOnMinimizeStructOffset = (__int64)MemHelper::getFuncAddr(0x6B400C0);
//__int64 idCmd::m_settings_ShowHudEquipmentOffset = (__int64)MemHelper::getFuncAddr(0x6B3E6C0);
////__int64 idCmd::m_settings_ObjectiveMarkerOffset = (__int64)MemHelper::getFuncAddr(0x6B3DF40);
//__int64 idCmd::m_settings_UI_SideNotificationOffset = (__int64)MemHelper::getFuncAddr(0x6B3EF40);
//__int64 idCmd::m_handsFovScale_SideNotificationOffset = (__int64)MemHelper::getFuncAddr(0x6BBAD90);


//idRenderModelGui::idRenderModelGui_DrawString idRenderModelGui::m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x6239F0));






