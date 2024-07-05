#pragma once
#include "CommonDE.h"
#include "MemHelper.h"


class Game {

private:

	static int m_lastGameScreenWidth;
	static int m_lastScreenHeigth;

public:

	//static unsigned int getUIScallingInt() {
	//	//*(_DWORD *)(swf_anchorProfile_44454C0 + 8);
	//	__int64 addr = *(__int64*)(MemHelper::getAddr(0x44454C0));
	//	return *(unsigned int*)(addr + 0x8);
	//}



	/*static float getScreenWidth() {

		return ((float)(*(int*)(MemHelper::getAddr(0x39AF8BC))));
	}

	static float getScreenHeigth() {

		return ((float)(*(int*)(MemHelper::getAddr(0x39AF8C0))));
	}

	static int getScreenWidthInt() {

		return ((*(int*)(MemHelper::getAddr(0x39AF8BC))));
	}

	static int getScreenHeigthInt() {

		return ((*(int*)(MemHelper::getAddr(0x39AF8C0))));
	}


	static float getCenterX() {

		return getScreenWidth() / 2.0f;
	}

	static float getCenterY() {

		return getScreenHeigth() / 2.0f;
	}*/


	//! using ints so we don't have any potential float comparison issue.
	/*static bool isResolutionChanged() {
		if ((Game::getScreenWidthInt() != m_lastGameScreenWidth) || (Game::getScreenHeigthInt() != m_lastScreenHeigth)) {
			m_lastGameScreenWidth = Game::getScreenWidthInt();
			m_lastScreenHeigth = Game::getScreenHeigthInt();
			logInfo("Resolution has changed !");
			return true;
		}
		return false;
	}*/

	//! this value doesn't change if you change the scale of a drawnstring, it changes if you change font i believe
	/*static float getSmallCharWidth() {
		__int64 smallCharWidthAddr = MemHelper::getAddr(0x5547D70);
		if (MemHelper::isBadReadPtr((void*)smallCharWidthAddr)) {
			logWarn("getSmallCharWidth smallCharWidthAddr is bad ptr returning 0");
			return 0;
		}
		return *(float*)smallCharWidthAddr;
	}*/

	//! this value doesn't change if you change the scale of a drawnstring, it changes if you change font i believe
	/*static float getSmallCharHeight() {
		__int64 smallCharHeightAddr = MemHelper::getAddr(0x5547D74);
		if (MemHelper::isBadReadPtr((void*)smallCharHeightAddr)) {
			logWarn("getSmallCharHeight smallCharHeightAddr is bad ptr returning 0");
			return 0;
		}
		return *(float*)smallCharHeightAddr;
	}*/

	//static unsigned  GetStringWidthInPixels(const char* string, const float scale)
	//{
	//	int i; // er8
	//	char v4; // cl
	//	__int64 v5; // rax

	//	for (i = 0; *string; string += v5)
	//	{
	//		//! K: 94 is ^ so it means there are 2 chars i suppose.
	//		if (*string == 94 && ((v4 = string[1], (unsigned __int8)(v4 - 48) <= 9u) || (unsigned __int8)(v4 - 97) <= 3u))
	//		{
	//			v5 = 2i64;
	//		}
	//		else
	//		{
	//			++i;
	//			v5 = 1i64;
	//		}
	//	}
	//	return (unsigned int)(int)(float)((float)((float)i * getSmallCharWidth()) * scale);
	//}

	static float getFontScaleFromWidth(float width, unsigned int strSize) {
		//int charCount = str.size();
		//return (float)str.size() / getSmallCharWidth();
		// small char * char count  * scale = width
		return width / (getSmallCharWidth() * strSize);
		//return width / (getSmallCharWidth() * str.size());
		//float result = width / (getSmallCharWidth() * str.size());
		//logInfo("getFontScaleFromWidth: width: %.2f, str.size(): %zu getSmallCharWidth: %.2f result: %.2f", width, str.size(), getSmallCharWidth(), result);
		//return result;
	}

	/*
	_QWORD *__fastcall GetGameMs_D073D0(__int64 a1, __int64 a2, int a3)
	{
	  __int64 v3; // r9

	  v3 = *(_QWORD *)(a1 + 0x10);
	  if ( *(_DWORD *)(qword_6B3F2C0 + 8) )
		*(_QWORD *)a2 = *(_QWORD *)(v3 + 0x48i64 * a3 + 0x18);
	  else
		*(_QWORD *)a2 = *(_QWORD *)(v3 + 0x18);
	  return (_QWORD *)a2;
	}
	
	*/
	//GetGameMs_D073D0(__int64 a1, __int64 a2, int a3)
	//! this function takes a "mysterious" int in a3 but as most time it's used with the int==1 i will just use gameTime with a 1 by default.
	//? commenting this to make our life easier to create scran patterns for now...:
	//static uint64_t getGameTime() { // 
	//	__int64 a1= *(__int64*)MemHelper::getAddr(0x6B409B0) + 0x125A60;
	//	__int64 v3; // r9
	//	v3 = *(__int64*)(a1 + 0x10);
	//	if (*(__int64*)(*(__int64*)MemHelper::getAddr(0x6B3F2C0)) + 8) {
	//		return *(uint64_t*)(v3 + 0x48i64 * 1 + 0x18);
	//	}
	//	else {
	//		return *(uint64_t*)(v3 + 0x18);
	//	}
	//}


};

 int Game::m_lastGameScreenWidth = 0;
int Game::m_lastScreenHeigth = 0;