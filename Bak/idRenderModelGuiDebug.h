//#pragma once
//
//#include <Windows.h>
//#include "MemHelper.h"
//#include "idColor.h"
//#include "Config.h"
//#include "ObjectLocator.h"
//#include "Rectangle.h"
//#include "Crosshair.h"
//#include "Game.h"
//#include "HudElements.h"
//
//
//class idRenderModelGui
//{
//private:
//	//__int64 m_idRenderModelGuiPtr = 0;
//
//
//	typedef __int64(__fastcall* idRenderModelGui_DrawString)(__int64 a1, float a2, float a3, const char* a4, __int64 a5, char a6, float a7);
//	static idRenderModelGui_DrawString m_pidRenderModelGui_DrawString;
//	//idRenderModelGui_DrawString m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x6239F0));
//
//	typedef void(__fastcall* idRenderModelGui_DrawStretchPic)(__int64 a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, __int64 a11);
//	static idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic;
//	//idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(MemHelper::getFuncAddr(0x498ED0));
//
//	static float s1;
//	static float t1;
//	static float s2;
//	static float t2;
//
//
//
//public:
//
//
//	static bool isDrawStringTriggered;
//
//	static int DrawStringCounter;
//
//	static bool isGetPerfMetricsStrTriggered;
//
//	static int DrawStretchPic_498ED0_Counter;
//
//
//
//	/*idRenderModelGui(__int64 idRenderModelGuiPtr)
//	{
//		m_idRenderModelGuiPtr = idRenderModelGuiPtr;
//	}*/
//	/*void acquirePtr(__int64 idRenderModelGuiPtr) {
//		if (idRenderModelGuiPtr != m_idRenderModelGuiPtr) {
//			m_idRenderModelGuiPtr = idRenderModelGuiPtr;
//			logInfo("acquirePtr: m_idRenderModelGuiPtr has changed to: %p", (void*)m_idRenderModelGuiPtr);
//		}
//
//	}*/
//
//
//	static float getScreenWidth() {
//
//		/*if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//			return 0;
//		}*/
//		return ((float)(*(int*)(MemHelper::getAddr(0x39AF8BC))));
//		//return ((float)(*(int*)(m_idRenderModelGuiPtr + 0x4568)));
//	}
//
//	static float getScreenHeigth() {
//		return ((float)(*(int*)(MemHelper::getAddr(0x39AF8C0))));
//		/*if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//			return 0;
//		}
//		return ((float)(*(int*)(m_idRenderModelGuiPtr + 0x456C)));*/
//	}
//
//
//
//	static float getCenterX(float scale = 1.0f) {
//		/*if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//			return 0;
//		}*/
//
//		//logInfo(" getCenterX: scale:  %.2f", scale);
//		//return 0.0f;
//
//		return getScreenWidth() / 2.0f;
//		//return ((float)(*(int*)(m_idRenderModelGuiPtr + 0x4568))) / 2.0f;
//		//logInfo("getCenterX: m_idRenderModelGuiPtr: %p width:  %.2f", (void*)m_idRenderModelGuiPtr,  width);
//		//return (width - 48.0f)/ 2.0f;
//		//return (width - 24.0f)/ 2.0f;
//		//return (width - (8.f * scale)) / 2.0f;
//		//return (width / 2.0f) - (4.f * scale /2);
//		//return (width / 2.0f) - (4.5f * scale);
//	}
//
//	static float getCenterY(float scale = 1.0f) {
//		return getScreenHeigth() / 2.0f;
//
//		/*if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//			return 0;
//		}
//		return ((float)(*(int*)(m_idRenderModelGuiPtr + 0x456C))) / 2.0f;*/
//
//		//logInfo(" getCenterY: scale:  %.2f", scale);
//
//		//return 0.0f;
//
//		//logInfo("getCenterX: height:  %.2f", height);
//		//return (height - 48.0f) / 2.0f;
//		//return (height - 16.41f) / 2.0f; //! 16.41 is SMALLCHAR_HEIGHT_5547D74 it doesn't work.
//		//return (height - 24.0f) / 2.0f; //! 
//		//return (height - (24.0f * scale)) / 2.0f; //! 
//		//return (height  / 2.0f) + (12.0f * scale / 2); //! 
//		//return (height  / 2.0f) + (1.0f/2 * scale ); //! c1, c2 too low, c3 bit too high 
//		//return (height / 2.0f) ; //  not aligned too low on screen
//		//return ((height / 2.0f) - 16.41f) + (4.5f * scale);
//		//return (height  / 2.0f) + (1.0f/2 * scale ); //!  not aligned and bit too low on screen 
//		//return (height  / 2.0f) - (12.0f * scale ); //! 
//		//return (height  / 2.0f) + (12.0f * scale ); // not aligned and too low on screen 
//	}
//
//	/*void drawCrosshairTest() {
//		if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//			return;
//		}
//		try
//		{
//			const char* dotCh = ".";
//			m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, 800.00, 102.00, dotCh, (__int64)&colorRed, 0, 3.0f);
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("drawCrosshairTest: exception: %s", ex.what());
//		}
//	}*/
//
//	/*void drawCrosshairTest2() {
//		if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//			return;
//		}
//		try
//		{
//			const char* dotCh = ".";
//			m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, 600.00, 102.00, dotCh, (__int64)&colorGreen, 0, 4.0f);
//		}
//		catch (const std::exception& ex)
//		{
//			logErr("drawCrosshairTest2: exception: %s", ex.what());
//		}
//	}*/
//
//	//void drawCenteredCrosshairTest() {
//	//	if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//	//		return;
//	//	}
//	//	const char* crossCh = "+";
//	//	m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(), getCenterY(), crossCh, (__int64)&colorGreen, 0, 1.0f);
//	//}
//
//	//void drawCenteredCrosshairWithOutlineTest() {
//	//	if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//	//		return;
//	//	}
//	//	//const char* constChatPtr = "A";
//	//	//const char* constChatPtr = "+";
//	//	const char* constChatPtr = ".";
//
//	//	float c3Scale = 3.5f;
//	//	float c2Scale = 2.0f;
//	//	//float c1Scale = 1.0f;
//
//
//
//
//	//	//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c3Scale), getCenterY(c3Scale), constChatPtr, (__int64)&colorBlack, 0, c3Scale);
//	//	m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c2Scale), getCenterY(c2Scale), constChatPtr, (__int64)&colorGreen, 0, c2Scale);
//	//	//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c1Scale), getCenterY(c1Scale), constChatPtr, (__int64)&colorGreen, 0, c1Scale);
//
//	//}
//
//
//
//
//	static void drawTextOutline(const char* text, float x, float y, float scale, const idColor& textColor, const idColor& outlineColor, float outlineWidth) {
//		// Render text outline. K: yes you need 4 calls, try with less and it will look wrong
//		drawSomeTextTest(text, x - outlineWidth, y - outlineWidth, scale, outlineColor);
//		drawSomeTextTest(text, x + outlineWidth, y + outlineWidth, scale, outlineColor);
//		drawSomeTextTest(text, x - outlineWidth, y + outlineWidth, scale, outlineColor);
//		drawSomeTextTest(text, x + outlineWidth, y - outlineWidth, scale, outlineColor);
//
//		// Render text
//		drawSomeTextTest(text, x, y, scale, textColor);
//	}
//
//
//
//
//
//	static void drawSomeTextTest(const char* text, float x, float y, float scale, const idColor& idColor) {
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get__DebugHud_idRenderModelGuiAddr();
//		__int64 idRenderModelGuiAdrr = ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr();
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idSWF_idRenderModelGuiAddr();
//
//		if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
//			return;
//		}
//		//const char* constChatPtr = "A";
//		//const char* constChatPtr = "+";
//		//const char* constCharPtr = "150 + . o";
//
//		//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c3Scale), getCenterY(c3Scale), constChatPtr, (__int64)&colorBlack, 0, c3Scale);
//		//setColor(idColor);
//		m_pidRenderModelGui_DrawString(idRenderModelGuiAdrr, x, y, text, (__int64)&idColor, 0, scale);
//		//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, x, y, text, (__int64)&colorGreen, 0, scale);
//		//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c1Scale), getCenterY(c1Scale), constChatPtr, (__int64)&colorGreen, 0, c1Scale);
//
//	}
//
//
//	//void drawCenteredCross(float size, float thickness, __int64 matPtr, const idColor& idColor) {
//
//	//	float screenWidth = ((float)(*(int*)(m_idRenderModelGuiPtr + 0x4568)));
//	//	float screenHeight = (float)(*(int*)(m_idRenderModelGuiPtr + 0x456C));
//
//	//	//logInfo("screenWidth: %.2f  screenHeight: %.2f", screenWidth, screenHeight);
//	//	//return (width - 48.0f)/ 2.0f;
//	//	//return (width - 24.0f)/ 2.0f;
//	//	//return (width - (8.f * scale)) / 2.0f;
//	//	//return (width / 2.0f) - (4.f * scale /2);			
//	//	float centerx = screenWidth / 2.0f;
//	//	float centery = screenHeight / 2.0f;
//	//	float scale = 1;
//
//	//	float hor_rect_X = centerx - size / 2.0f;
//	//	float hor_rect_Y = centery - thickness / 2.0f;
//
//	//	drawDrawStretchPicTest3(hor_rect_X, hor_rect_Y, size, thickness, matPtr, idColor);
//
//	//	float vert_rect_X = centerx - thickness / 2.0f;
//	//	float vert_rect_Y = centery - size / 2.0f;
//
//	//	drawDrawStretchPicTest3(vert_rect_X, vert_rect_Y, thickness, size, matPtr, idColor);
//
//
//	//	/*float centerxFinal = centerx - (sizeX_F / 2.0f);
//	//	float centeryFinal = centery - (sizeY_F / 2.0f);*/
//	//}
//
//
//
//	/*void drawCentereHordBar(float width, float height, float outlineSize, __int64 matPtr) {
//		float centerX = getCenterX() ;
//		float centerY = getCenterY();
//		drawDrawStretchPicTest3(centerX - width / 2.0f - outlineSize, centerY - height / 2.0f - outlineSize, width + outlineSize * 2.0f, height + outlineSize * 2.0f, matPtr, colorBlack);
//		drawDrawStretchPicTest3(centerX - width / 2.0f, centerY - height / 2.0f, width, height, matPtr, colorWhite);
//	}
//
//	void drawCenteredVerBar(float width, float height, float outlineSize, __int64 matPtr) {
//		float centerX = getCenterX();
//		float centerY = getCenterY();
//		drawDrawStretchPicTest3(centerX - height / 2.0f - outlineSize, centerY - width / 2.0f - outlineSize, height + outlineSize * 2.0f, width + outlineSize * 2.0f, matPtr, colorBlack);
//		drawDrawStretchPicTest3(centerX - height / 2.0f, centerY - width / 2.0f, height, width, matPtr, colorWhite);
//	}*/
//
//	/*void drawCrossHairPlusWithOutline(float width, float height, float outlineSize, __int64 matPtr) {
//		float centerX = getCenterX();
//		float centerY = getCenterY();
//		drawDrawStretchPicTest3(centerX - width / 2.0f - outlineSize, centerY - height / 2.0f - outlineSize, width + outlineSize * 2.0f, height + outlineSize * 2.0f, matPtr, colorBlack);
//		drawDrawStretchPicTest3(centerX - height / 2.0f - outlineSize, centerY - width / 2.0f - outlineSize, height + outlineSize * 2.0f, width + outlineSize * 2.0f, matPtr, colorBlack);
//		drawDrawStretchPicTest3(centerX - width / 2.0f, centerY - height / 2.0f, width, height, matPtr, colorWhite);
//		drawDrawStretchPicTest3(centerX - height / 2.0f, centerY - width / 2.0f, height, width, matPtr, colorWhite);
//	}*/
//
//
//
//	//void drawCrosshair(VectorCrosshair crosshair) {
//	//	if (MemHelper::isBadReadPtr((void*)m_idRenderModelGuiPtr)) {
//	//		return;
//	//	}
//	//	float s1 = 0.0;
//	//	float t1 = 0.0;
//	//	float s2 = 1.0;
//	//	float t2 = 1.0;
//
//	//	setColor(idColor);
//
//	//	if (!isBadPtrMaterial) {
//	//		//! guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr
//
//
//	//		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 0.0, 1.0, 1.0, matPtr);
//
//	//		//return; //? don't forget that return !!!!!!!!!!!!!!
//
//
//
//	//		if (isMiroredX) {
//	//			s1 = 1.0;
//	//			s2 = 0.0;
//	//			//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 1.0, 0.0, 0.0, 1.0, matPtr);
//	//		}
//	//		if (isMiroredY) {
//	//			t1 = 1.0;
//	//			t2 = 0.0;
//	//			//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 1.0, 1.0, 0.0, matPtr);
//	//		}
//	//		pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
//
//	//		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, 0, 0, 0.0, 1000, 1000, 0.0, 0.0, 1.0, 1.0, matPtr);
//	//	}
//	//}
//
//
//	/*static void drawCrossHairPlusWithOutline(float width, float height, float outlineSize, __int64 matPtr) {
//		float centerX = getCenterX();
//		float centerY = getCenterY();
//		drawDrawStretchPicTest3(centerX - width / 2.0f - outlineSize, centerY - height / 2.0f - outlineSize, width + outlineSize * 2.0f, height + outlineSize * 2.0f, matPtr, colorBlack);
//		drawDrawStretchPicTest3(centerX - height / 2.0f - outlineSize, centerY - width / 2.0f - outlineSize, height + outlineSize * 2.0f, width + outlineSize * 2.0f, matPtr, colorBlack);
//		drawDrawStretchPicTest3(centerX - width / 2.0f, centerY - height / 2.0f, width, height, matPtr, colorWhite);
//		drawDrawStretchPicTest3(centerX - height / 2.0f, centerY - width / 2.0f, height, width, matPtr, colorWhite);
//	}*/
//
//
//
//
//	//! this is a val used in DrawString_6239F0
//	static float getInternalScaleVal() {
//		__int64 internalScaleValAddr = MemHelper::getAddr(0x3981A94);
//		if (MemHelper::isBadReadPtr((void*)internalScaleValAddr)) {
//			logWarn("getInternalScaleVal internalScaleValAddr is bad ptr returning 0");
//			return 0;
//		}
//		return *(float*)internalScaleValAddr;
//	}
//
//	static float getSmallCharWidth() {
//		__int64 smallCharWidthAddr = MemHelper::getAddr(0x5547D70);
//		if (MemHelper::isBadReadPtr((void*)smallCharWidthAddr)) {
//			logWarn("getSmallCharWidth smallCharWidthAddr is bad ptr returning 0");
//			return 0;
//		}
//		return *(float*)smallCharWidthAddr;
//	}
//
//	static float getSmallCharHeight() {
//		__int64 smallCharHeightAddr = MemHelper::getAddr(0x5547D74);
//		if (MemHelper::isBadReadPtr((void*)smallCharHeightAddr)) {
//			logWarn("getSmallCharHeight smallCharHeightAddr is bad ptr returning 0");
//			return 0;
//		}
//		return *(float*)smallCharHeightAddr;
//	}
//
//
//	static unsigned  GetStringWidthInPixels(const char* string, const float scale)
//	{
//		int i; // er8
//		char v4; // cl
//		__int64 v5; // rax
//
//		for (i = 0; *string; string += v5)
//		{
//			//! K: 94 is ^ so it means there are 2 chars i suppose.
//			if (*string == 94 && ((v4 = string[1], (unsigned __int8)(v4 - 48) <= 9u) || (unsigned __int8)(v4 - 97) <= 3u))
//			{
//				v5 = 2i64;
//			}
//			else
//			{
//				++i;
//				v5 = 1i64;
//			}
//		}
//		return (unsigned int)(int)(float)((float)((float)i * getSmallCharWidth()) * scale);
//	}
//
//	static void drawCrosshairDot(__int64 idRenderModelGuiAdrr, CrosshairDot crosshairDot) {
//
//		//logWarn("drawRect: called...");
//
//		static bool lastisBadPtrMaterial = false;
//		static bool isFirstTime = true;
//
//		//! commenting this for improving performance?:
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get__DebugHud_idRenderModelGuiAddr();
//
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr();
//		__int64 materialAddr = MaterialLib::getWhite();
//
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idSWF_idRenderModelGuiAddr();
//		/*if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
//			return;
//		}*/
//
//
//
//		bool isBadPtrMaterial = MemHelper::isBadReadPtr((void*)materialAddr);
//		if (isBadPtrMaterial != lastisBadPtrMaterial || isFirstTime) {
//			logWarn("drawRect: isBadPtrMaterial is now %d", isBadPtrMaterial);
//			lastisBadPtrMaterial = isBadPtrMaterial;
//			isFirstTime = false;
//
//		}
//		if (isBadPtrMaterial) return;
//
//		//logWarn("drawRect: about to draw...");
//
//
//
//
//
//		//logWarn("wea rendering with testMatr !!! drawRect: idRenderModelGuiAdrr: %p getCenterX(): %.2f getCenterY(): %.2f crosshairDot.getSize(): %.2f, materialAddr: %p", (void*)idRenderModelGuiAdrr, getCenterX(), getCenterY(), crosshairDot.getSize(), (void*)materialAddr);
//
//		//! guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr
//
//
//
//		//OutlineRectVec.push_back(Rect(rec.ID, rec.X - outlineThickness, rec.Y - outlineThickness, rec.Width + 2 * outlineThickness, rec.Height + 2 * outlineThickness, MaterialPtr, IdColorOutline));
//		setColor(idRenderModelGuiAdrr, crosshairDot.getOutlineColor());
//		pidRenderModelGui_DrawStretchPic(ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr(), getCenterX() - crosshairDot.getSize() / 2 - crosshairDot.getOutlineThickness(), getCenterY() - crosshairDot.getSize() / 2 - crosshairDot.getOutlineThickness(), 0, crosshairDot.getSize() + 2 * crosshairDot.getOutlineThickness(), crosshairDot.getSize() + 2 * crosshairDot.getOutlineThickness(), s1, t1, s2, t2, MaterialLib::getWhite());
//		//pidRenderModelGui_DrawStretchPic(ObjectLocator::get__DebugHud_idRenderModelGuiAddr(), getCenterX() - crosshairDot.getSize() / 2 - crosshairDot.getOutlineThickness(), getCenterY() - crosshairDot.getSize() / 2 - crosshairDot.getOutlineThickness(), 0, crosshairDot.getSize() + 2 * crosshairDot.getOutlineThickness(), crosshairDot.getSize() + 2 * crosshairDot.getOutlineThickness(), s1, t1, s2, t2, MaterialLib::getWhite());
//
//		setColor(idRenderModelGuiAdrr, crosshairDot.getFillColor());
//		//pidRenderModelGui_DrawStretchPic(ObjectLocator::get__DebugHud_idRenderModelGuiAddr(), getCenterX() - crosshairDot.getSize() / 2, getCenterY() - crosshairDot.getSize() / 2, 0, crosshairDot.getSize(), crosshairDot.getSize(), s1, t1, s2, t2, MaterialLib::getWhite());
//		pidRenderModelGui_DrawStretchPic(ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr(), getCenterX() - crosshairDot.getSize() / 2, getCenterY() - crosshairDot.getSize() / 2, 0, crosshairDot.getSize(), crosshairDot.getSize(), s1, t1, s2, t2, MaterialLib::getWhite());
//
//		//if (!isBadPtrMaterial) {
//		//	//! guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr
//
//		//	//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 0.0, 1.0, 1.0, matPtr);
//
//		//	//return; //? don't forget that return !!!!!!!!!!!!!!
//
//		//	pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, rect.X, rect.Y, 0.0, rect.Width, rect.Height, s1, t1, s2, t2, rect.MaterialPtr);
//
//		//	//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, 0, 0, 0.0, 1000, 1000, 0.0, 0.0, 1.0, 1.0, matPtr);
//		//}
//	}
//
//
//
//
//
//	static void drawDrawStretchPicTest3(__int64 idRenderModelGuiAdrr, float x, float y, float width, float height, __int64 matPtr, const idColor& idColor, bool isMiroredX = false, bool isMiroredY = false) {
//		//static bool BasPtrThisError = false;
//		static bool lastisBadPtrMaterial = false;
//		static bool isFirstTime = true;
//
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get__DebugHud_idRenderModelGuiAddr();
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr();
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idSWF_idRenderModelGuiAddr();
//
//		if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
//			return;
//		}
//
//		bool isBadPtrMaterial = MemHelper::isBadReadPtr((void*)matPtr);
//		if (isBadPtrMaterial != lastisBadPtrMaterial || isFirstTime) {
//			logWarn("isBadPtrMaterial is now %d", isBadPtrMaterial);
//			lastisBadPtrMaterial = isBadPtrMaterial;
//			isFirstTime = false;
//			/*	if(BasPtrMaterialError != true)
//				BasPtrMaterialError = true;*/
//				//return;
//		}
//
//		//DrawStretchPic(x, y, 0.0, w, h, 0.0, 0.0, 1.0, 1.0, whitemat);
//		float s1 = 0.0;
//		float t1 = 0.0;
//		float s2 = 1.0;
//		float t2 = 1.0;
//
//		setColor(idRenderModelGuiAdrr, idColor);
//
//		if (!isBadPtrMaterial) {
//			//! guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr
//
//
//			//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 0.0, 1.0, 1.0, matPtr);
//
//			//return; //? don't forget that return !!!!!!!!!!!!!!
//
//
//
//			if (isMiroredX) {
//				s1 = 1.0;
//				s2 = 0.0;
//				//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 1.0, 0.0, 0.0, 1.0, matPtr);
//			}
//			if (isMiroredY) {
//				t1 = 1.0;
//				t2 = 0.0;
//				//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 1.0, 1.0, 0.0, matPtr);
//			}
//			pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
//
//			//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, 0, 0, 0.0, 1000, 1000, 0.0, 0.0, 1.0, 1.0, matPtr);
//		}
//	}
//
//
//
//
//	static void setColor(__int64 idRenderModelGuiAdrr, const idColor& idColor) {
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get__DebugHud_idRenderModelGuiAddr();
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr();
//		//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idSWF_idRenderModelGuiAddr();
//
//		if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
//			logErr("setColor: can not set color cause idRenderModelGuiAdrr is bad ptr");
//			return;
//		}
//		*(unsigned int*)(idRenderModelGuiAdrr + 0x4D0) = idColor.PackColor();
//	}
//
//	static void drawDrawStretchPicTest4(__int64 idRenderModelGuiAdrr) {
//		//__int64 matPtr = MaterialLib::getRocketIconMtr();
//		__int64 matPtr = MaterialLib::getWhite();
//		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, Game::getCenterX(), Game::getCenterY(), 0.0, 20, 20, s1, t1, s2, t2, matPtr);
//	}
//
//	static void drawSomeText2(__int64 idRenderModelGuiAdrr, const char* text, float x, float y, float scale, const idColor& idColor) {
//		//logInfo("drawSomeText2: scale: %.2f getSmallCharHeight: %.2f ", scale, Game::getSmallCharHeight());
//
//		//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c3Scale), getCenterY(c3Scale), constChatPtr, (__int64)&colorBlack, 0, c3Scale);
//		//setColor(idColor);
//		m_pidRenderModelGui_DrawString(idRenderModelGuiAdrr, x, y, text, (__int64)&idColor, 0, scale);
//		//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, x, y, text, (__int64)&colorGreen, 0, scale);
//		//m_pidRenderModelGui_DrawString(m_idRenderModelGuiPtr, getCenterX(c1Scale), getCenterY(c1Scale), constChatPtr, (__int64)&colorGreen, 0, c1Scale);
//
//	}
//
//	static void drawDrawStretchPicTest5(__int64 idRenderModelGuiAdrr, float x, float y, float width, float height, __int64 matPtr) {
//		//__int64 matPtr = MaterialLib::getRocketIconMtr();
//		//__int64 matPtr = MaterialLib::getWhite();
//		pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
//	}
//
//	static void renderCustomSprite(__int64 idRenderModelGuiAdrr, HudEquipmentSprite& equipmentSprite) {
//		//drawDrawStretchPicTest5(__int64 idRenderModelGuiAdrr, float x, float y, float width, float height, __int64 matPtr)&
//
//		setColor(idRenderModelGuiAdrr, colorDkGrey);
//		drawDrawStretchPicTest5(idRenderModelGuiAdrr, equipmentSprite.hudIcon.iconContainerCoordsVec4.x, equipmentSprite.hudIcon.iconContainerCoordsVec4.y, equipmentSprite.hudIcon.iconContainerCoordsVec4.w, equipmentSprite.hudIcon.iconContainerCoordsVec4.h, MaterialLib::getFragGrenadeMtr());
//		setColor(idRenderModelGuiAdrr, colorWhite);
//		drawSomeText2(idRenderModelGuiAdrr, equipmentSprite.hudCoolDownText.text.c_str(), equipmentSprite.hudCoolDownText.coordinatesVec2.x, equipmentSprite.hudCoolDownText.coordinatesVec2.y, equipmentSprite.hudCoolDownText.fontScale, colorWhite);
//	}
//
//
//};
//
//idRenderModelGui::idRenderModelGui_DrawString idRenderModelGui::m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x6239F0));
//
//idRenderModelGui::idRenderModelGui_DrawStretchPic  idRenderModelGui::pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(MemHelper::getFuncAddr(0x498ED0));
//
//float idRenderModelGui::s1 = 0.0;
//float idRenderModelGui::t1 = 0.0;
//float idRenderModelGui::s2 = 1.0;
//float idRenderModelGui::t2 = 1.0;
//bool idRenderModelGui::isDrawStringTriggered = false;
//bool idRenderModelGui::isGetPerfMetricsStrTriggered = false;
//int idRenderModelGui::DrawStretchPic_498ED0_Counter = 0;
//int idRenderModelGui::DrawStringCounter = 0;