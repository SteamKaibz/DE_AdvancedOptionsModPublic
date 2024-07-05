#pragma once


#include "MemHelper.h"



//! __int64 reapplySwfColors_Mb_4F56D0()
typedef __int64(__fastcall* reapplySwfColors_t)();

/// <summary>
/// this should have limited scale as atm it's just used to reload the hud color so we can change them in realtime.
/// </summary>
/// 
class ColorManager
{
private:

	inline static reapplySwfColors_t reapplySwfColorsFp = nullptr;
	inline static uint64_t m_lastReapplySwfColorCallMs = 0;
	inline static unsigned int m_autoReapplyColorFrequenceMs = 1000;


	//inline static __int64 m_reapplySwfColorsFuncAdd = 0;

public:
	static bool acquirreReapplySwfColorsFuncAddr(__int64 reapplySwfColorsFuncAddr);
	static void reapplySwfColors();
	static void autoReapplySwfColors();
};

