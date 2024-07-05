#pragma once
#include "GeneratedClasses.h"
#include "MemHelper.h"

//? this doesn't work because when we are in the mod menu m_Win32Vars_t->isGameFocused is always 1. i suppose because we manipulated the in_mouse value.

/// <summary>
/// used to get if game is focused or not. this should mainly be used to disable mod menu if player is alt tab out of the game to prevent input/visual glitches/frezzes.
/// </summary>
class winFocusManager
{

private:

	static inline Win32Vars_t* m_Win32Vars_t = nullptr;


public:

	static bool acquireWin32Vars(__int64 addr);
	static bool isGameFocused();

};

