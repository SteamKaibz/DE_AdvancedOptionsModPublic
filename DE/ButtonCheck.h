#pragma once

#include <Windows.h>
#include <algorithm>
#include <string>

class ButtonCheck
{
public:
    bool isKeyPressedCustom(__int64& ptr, __int64 btnEnum);

private:
    static inline __int64 val_0x10 = 0;
    static inline __int64 val_0xA8 = 0;
    static inline __int64 val_0xA8Anda2Result = 0;
};









//#pragma once
//
//#include <Windows.h>
//#include <algorithm>
//#include <string>
//
///// <summary>
///// this recreates one of the game function to check if a button (key or controller button) corresponding to a game action has been pressed
///// </summary>
//class ButtonCheck
//{
//
//public:
//	bool isKeyPressedCustom(__int64& ptr, __int64 btnEnum)
//	{
//		logDebug("isKeyPressedCustom");
//		//! we use this to know if a key is pressed so we can handle different cases
//		//! this is however the exact replica of what the actual isKeyPress function does (ida: 1AE54F0)
//		__int64 val_0x10 = 0;
//		__int64 val_0xA8 = 0;
//
//		if (!*(BYTE*)(ptr + 0xA1)) {
//			val_0xA8 = *(unsigned __int64*)(ptr + 0xA8);
//		}
//		__int64 val_0xA8Anda2Result = val_0xA8 & btnEnum;
//		if ((val_0xA8Anda2Result) == 0) {
//			return false;
//		}
//		if (!*(BYTE*)(ptr + 9)) {
//			val_0x10 = *(unsigned __int64*)(ptr + 0x10);
//		}
//		return(val_0x10 & btnEnum) == 0;
//	}
//
//};
//
