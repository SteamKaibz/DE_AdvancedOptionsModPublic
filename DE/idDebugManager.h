//#pragma once
//#include "TypeInfoManager.h"
////
////#include <Windows.h>
////#include "Config.h"
////#include "idDeclInfo.h"
////#include "MaterialInfo.h"
////#include "MaterialLib.h"
////#include "idFont.h"
////#include "idColor.h"
////#include "idRenderModelGui.h"
//////#include "HudData.h"
////#include "Crosshair.h"
////#include "PlayerStateChecker.h"
////#include "idInventoryCollectionManager.h"
////#include "../Hud/HudData.h"
//
////? don't use this cls for the moment, if not ever.
//class idDebugHudManager {
//
//private:
//
//	static __int64 m_cvarIdDebugHudPtrAddr;
//	static const unsigned int m_screenWidthOffset;
//	static const unsigned int m_screenHeighthOffset;
//
//public:
//	/*static float getScreenWidth() {
//		if (!m_cvarIdDebugHudPtrAddr) {
//			m_cvarIdDebugHudPtrAddr = TypeInfoManager::getIdDebugHudAddr();
//			logInfo("getScreenWidth: idDebugHudManager: m_cvarIdDebugHudPtrAddr is now: %p", (void*)m_cvarIdDebugHudPtrAddr);
//		}
//		if (MemHelper::isBadReadPtr((void*)m_cvarIdDebugHudPtrAddr)) {
//			logErr("getScreenWidth: m_cvarIdDebugHudPtrAddr is bad ptr returning 0");
//			return .0f;
//		}
//		return ((float)(*(int*)(m_cvarIdDebugHudPtrAddr + m_screenWidthOffset)));
//	}
//
//	static float getScreenHeight() {
//		if (!m_cvarIdDebugHudPtrAddr) {
//			m_cvarIdDebugHudPtrAddr = TypeInfoManager::getIdDebugHudAddr();
//			logInfo("getScreenHeight: idDebugHudManager: m_cvarIdDebugHudPtrAddr is now: %p", (void*)m_cvarIdDebugHudPtrAddr);
//		}
//		if (MemHelper::isBadReadPtr((void*)m_cvarIdDebugHudPtrAddr)) {
//			logErr("getScreenHeight: m_cvarIdDebugHudPtrAddr is bad ptr returning 0");
//			return .0f;
//		}
//		return ((float)(*(int*)(m_cvarIdDebugHudPtrAddr + m_screenHeighthOffset)));
//	}*/
//
//};
//
//__int64 idDebugHudManager::m_cvarIdDebugHudPtrAddr = 0;
//const unsigned int idDebugHudManager::m_screenWidthOffset = 0x4568;
//const unsigned int idDebugHudManager::m_screenHeighthOffset = 0x456C;
//
//
//
//// 
//// 
//
//////? There is a list of ida function at the end of this file
////class idDebugHUDLocal
////{
////private:
////	//__int64 m_idDebugHUDLocalAddr = 0;
////	//__int64 m_idRenderModelGuiPtr = 0;
////
////	//idRenderModelGui gui{ 0 };
////
////	idFont font;
////
////	bool isTrue = false;
////
////	//std::vector<__int64> m_idMaterial2Vec;
////	//
////	//__int64* idMaterialPtr = nullptr;
////
////	//std::vector<__int64> m_idMaterialPtr2Vec;
////	//size_t materialIndex = 0;
////
////	//idDeclInfo m_idDeclInfo;
////
////	__int64 m_testMaterial = 0;
////	std::string m_strToDisplay = "no str to display";
////
////	idColor m_idColor = colorRed;
////
////	float m_fontSpacing = -1.0f;
////f
////	int m_fontIndex = 0;
////
////	std::vector<idFontEnum> m_idFontsVec{ idFontEnum::eternal88 , idFontEnum::eternal90 , idFontEnum::ttSuper98 , idFontEnum::ttSuperA0 , idFontEnum::idTacticA8 ,idFontEnum::defaultCourrierF8 };
////
////	HudData hudData;
////
////	const std::vector<char> m_allLettersCharVec = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
////
////
////	CrosshairDot crosshairDot = CrosshairDot(3, colorWhite, colorBlack, 2);
////
////	//CrosshairCrossWithDot crosshairCrossWithDot = CrosshairCrossWithDot(gui.getCenterX(), gui.getCenterY(), )
////
////
////	//float m_debugDrawHudDataLine_Y = 0.0f;
////
////
////
////
////public:
////
////	bool isRenderAllowedTest = false;
////
////	//void acquirePtrs(__int64 idDebugHUDLocalPtr, _int64 idRenderModelGuiPtrDEBUG) {
////	//	if (idDebugHUDLocalPtr != m_idDebugHUDLocalAddr) {
////	//		m_idDebugHUDLocalAddr = idDebugHUDLocalPtr;
////	//		logInfo("acquirePtrs: m_idDebugHUDLocalAddr has changed to: %p", (void*)m_idDebugHUDLocalAddr);
////	//	}
////	//	/*if (idRenderModelGuiPtrDEBUG != m_idRenderModelGuiPtr) {
////	//		m_idRenderModelGuiPtr = idRenderModelGuiPtrDEBUG;
////	//		gui = idRenderModelGui(m_idRenderModelGuiPtr);
////	//		logInfo("acquirePtrs: m_idRenderModelGuiPtr has changed to: %p recreating idRenderModelGui obj.", (void*)m_idRenderModelGuiPtr);
////	//	}*/
////	//}
////
////
////	//void testDrawTextAtExactLocation() {
////
////	//	__int64 idDebugHUDAddr = ObjectLocator::get_idDebugHUDAddr();
////	//	if (MemHelper::isBadReadPtr((void*)idDebugHUDAddr)) {
////	//		logWarn("testDrawTextLocation: idDebugHUDAddr is bad ptr");			
////	//		return;
////	//	}
////
////	//	if (m_testMaterial == 0) {
////	//		getNextMaterial();
////	//	}
////
////	//	if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////	//		return;
////	//	}
////	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////	//	if (!PlayerStateChecker::isPlaying()) return;
////
////	//	idRenderModelGui::drawDrawStretchPicTest3(100, 450, 100, 100, m_testMaterial, colorGreen);
////	//	idRenderModelGui::drawSomeTextTest("hello world", 100, 450, 1, colorWhite);
////
////	//}
////
////
////	//void testCrosshairObject() {
////
////	//	__int64 idDebugHUDAddr = ObjectLocator::get_idDebugHUDAddr();
////	//	if (MemHelper::isBadReadPtr((void*)idDebugHUDAddr)) {
////	//		logWarn("testCrosshairObject: idDebugHUDAddr is bad ptr");
////	//		return;
////	//	}
////	//	
////
////	//	/*if (m_testMaterial == 0) {
////	//		getNextMaterial();
////	//	}*/
////
////	//	/*if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////	//		return;
////	//	}*/
////	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////	//	if (!PlayerStateChecker::isPlaying()) return;
////
////
////	//	idRenderModelGui::drawCrosshairDot(crosshairDot);
////
////	//	//logInfo("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
////
////	//	//HudDataCrosshairMap fakeHudDataCrosshairMap;
////
////
////	//	//hudData.debugFAKEUpdate(); //! every second
////
////
////	//	/*CrosshairCrossWithDot crosshairCrossWithDot = CrosshairCrossWithDot(2.0f, true, 1.0f, colorBlack, colorGreen, 8.0f, 3.0f, true, Nades_Bp_Fuel_NoHealth_CrosshairDataMap, hudData);
////
////	//	for (size_t i = 0; i < crosshairCrossWithDot.OutlineRectVec.size(); i++)
////	//	{
////	//		Rect& outlineRect = crosshairCrossWithDot.OutlineRectVec[i];
////	//		idRenderModelGui::drawRect(outlineRect);
////	//	}
////	//	for (size_t i = 0; i < crosshairCrossWithDot.FillRectVec.size(); i++)
////	//	{
////	//		Rect& fillRect = crosshairCrossWithDot.FillRectVec[i];
////	//		idRenderModelGui::drawRect(fillRect);
////	//	}*/
////
////
////	//}
////
////	//? do not use this for actual mod we need smth better
////	bool debugIsSafeToRender() {
////
////		static bool lastisBadMaterialPtr = false;
////
////		__int64 idDebugHUDAddr = ObjectLocator::get_idDebugHUDAddr();
////		if (MemHelper::isBadReadPtr((void*)idDebugHUDAddr)) {
////			logWarn("debugIsSafeToRender: idDebugHUDAddr is bad ptr");
////			return false;
////		}
////
////		if (m_testMaterial == 0) {
////			getNextMaterial();
////		}
////
////		bool isBadMaterialPtr = MemHelper::isBadReadPtr((void*)m_testMaterial);
////		if (lastisBadMaterialPtr != isBadMaterialPtr) {
////			lastisBadMaterialPtr = isBadMaterialPtr;
////			logWarn("testDraw: m_testMaterial is bad ptr is now %d ", isBadMaterialPtr);
////		}
////		if (isBadMaterialPtr) {
////			return false;
////		}
////		//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////		if (!PlayerStateChecker::isPlaying()) return false;
////
////		return true;
////	}
////
////
////	//void testDraw() {
////
////	//	static bool lastisBadMaterialPtr = false;
////
////	//	static uint64_t lastChangeMs = 0;
////	//	static int fontIndex = 0;
////
////	//	//! see glyphInfo_t in Sam's db
////	//	uint8_t glyphWidth = 0;
////	//	uint8_t glyphHeight = 0;
////	//	char glyph_Top = 0;
////	//	char glyph_Left = 0;
////	//	uint8_t glyph_XSkip = 0;
////
////	//	float charWidth = 0.0f;
////	//	float charHeight = 0.0f;
////
////	//	std::string fontStr = "unknown font";
////
////	//	
////	//	static int letterIndex = 0;
////	//	static std::string testString = "X";
////
////	//	try
////	//	{
////	//		if (! debugIsSafeToRender()) return;	
////
////	//		//! font cycle
////	//		//if (EpochMillis() - lastChangeMs > 2000) { //! change x seconds.
////	//		//	fontIndex++;
////	//		//	lastChangeMs = EpochMillis();
////	//		//	if (fontIndex >= m_idFontsVec.size()) {
////	//		//		fontIndex = 0;
////	//		//	}
////	//		//}						
////	//		//font.set(m_idFontsVec[fontIndex]);
////	//		//fontStr = font.getFontAsStr(m_idFontsVec[fontIndex]);
////	//		
////
////	//	
////	//		static float textScale = 4.0f;
////
////	//		//! text scale cycle
////	//		//font.set(idFontEnum::eternal88);
////	//		////font.set(idFontEnum::idTacticA8);
////
////	//		//fontStr = font.getFontAsStr(idFontEnum::eternal88);
////	//		////fontStr = font.getFontAsStr(idFontEnum::idTacticA8);
////
////	//		//if (EpochMillis() - lastChangeMs > 2000) { //! change x seconds.
////
////	//		//	textScale += 1.0f;
////	//		//	lastChangeMs = EpochMillis();
////
////	//		//	if (textScale > 8.0f) {
////	//		//		textScale = 1.0f;
////	//		//	}
////	//		//}
////
////	//		//font.set(idFontEnum::eternal90);
////	//		font.set(idFontEnum::defaultCourrierF8);
////	//		fontStr = font.getFontAsStr(idFontEnum::defaultCourrierF8);
////
////	//		//if (EpochMillis() - lastChangeMs > 1000) { //! change x seconds.
////	//		//	lastChangeMs = EpochMillis();
////
////	//		//	letterIndex++;
////	//		//	if (letterIndex >= m_allLettersCharVec.size()) {
////	//		//		letterIndex = 0;
////	//		//	}
////	//		//	//logInfo("letterIndex is %d and m_allLettersCharVec[letterIndex] is: %c", letterIndex, m_allLettersCharVec[letterIndex]);
////	//		//	//testString = std::to_string(m_allLettersCharVec[letterIndex]);
////	//		//	testString = m_allLettersCharVec[letterIndex];
////	//		//	//testString = std::to_string(m_allLettersCharVec[letterIndex]);
////	//		//}
////
////	//		//testString = "1234567890";
////	//		testString = "OWAIW";
////
////
////
////
////	//		//std::string testString = "Z0_xA";
////	//		//std::string testString = "_";
////
////	//		
////
////	//		//logInfo("internalScaleVal: %.2f", internalScaleVal);
////
////	//		float v24_scaleVal = idRenderModelGui::getInternalScaleVal() * textScale;
////
////	//		float glyph_Top_v28 = 0;
////
////	//		float rectSkipTest = 0;
////
////	//		__int64 glyphAddr = font.getGlyphDataAddr(testString.c_str());
////	//		//logInfo("glyphAddr: %llx", glyphAddr);
////	//		if (!MemHelper::isBadReadPtr((void*)glyphAddr)) {
////	//			glyphWidth = *(unsigned __int8*)(glyphAddr);
////	//			//charWidth = (float)((float)sizeX ) * internalScaleVal;
////	//			charWidth = (float)((float)glyphWidth + 1.0) * (idRenderModelGui::getInternalScaleVal() * textScale);
////
////	//			glyphHeight = *((unsigned __int8*)(glyphAddr + 1));
////	//			glyph_Top = *((char*)(glyphAddr + 2));
////	//			glyph_Left = *((char*)(glyphAddr + 3));
////	//			//charHeight = (float)((float)sizeY ) * internalScaleVal;
////	//			charHeight = (float)((float)glyphHeight + 1.0) * (idRenderModelGui::getInternalScaleVal() * textScale);
////	//			//logInfo("for cstring: %s sizeX: %hhu sizeY: %hhu", testString.c_str(), sizeX, sizeY);
////	//			//logInfo("sizeX: %hhu sizeY: %hhu", sizeX, sizeY);
////	//			glyph_XSkip = *((unsigned __int8*)(glyphAddr + 4));
////
////	//			//float rectSkipTest = (float)((float)glyph_XSkip + 1.0) * idRenderModelGui::getInternalScaleVal();
////
////	//			
////
////	//			//logInfo("testDraw: glyphWidth: %hhu glyphHeight: %hhu glyph_Top: %d glyph_Left: %d glyph_XSkip: %hhu", glyphWidth, glyphHeight, glyph_Top, glyph_Left, glyph_XSkip);
////
////	//		}
////	//		else {
////	//			logWarn("testDraw: bad ptr glyphAddr returning ");
////	//			return;
////	//		}
////
////	//		float IdacharWidthMinusXSkip = idRenderModelGui::getInternalScaleVal() * idRenderModelGui::getSmallCharWidth() - (float)glyph_XSkip * 0.5f + (float)glyph_Left * v24_scaleVal;
////	//		
////	//		glyph_Top_v28 = idRenderModelGui::getInternalScaleVal() * textScale * (float)glyph_Top;		
////
////
////	//		float center_x = idRenderModelGui::getCenterX();
////	//		float center_y = idRenderModelGui::getCenterY();
////
////	//		//! text is generally too much on the right, however for some it's just right....
////	//		//float text_x = center_x - IdacharWidthMinusXSkip;
////	//		
////	//		//! text too much on the left by at least one character:
////	//		//float text_x = center_x - glyph_XSkip * v24_scaleVal; 
////
////	//		//! text too much on the left by half a char except for courrier where it's just right:
////	//		//float text_x = center_x - idRenderModelGui::getSmallCharWidth() / 4;
////	//		
////	//		//! text too much on the left by less than 1/2 a char except for courrier which is a bit too on the right
////	//		//float text_x = center_x;
////
////	//		//! for the o character the char width will have to be adjusted to calculate string width
////	//		float text_x_Offset_eternal90_Base = 4.0f;
////	//		float text_x_Offset_eternal88_Base = 2.7f;
////	//		float text_x_Offset_idTacticA8_Base = 3.68f;
////
////	//		float text_x_Offset = text_x_Offset_eternal90_Base * textScale;
////	//		//float text_x_Offset = 2.54 * textScale;
////
////	//		float text_x = center_x + text_x_Offset;
////	//		float text_y = center_y;
////
////	//		float pic_x = center_x;
////	//		float pic_y = center_y;
////
////	//					
////	//		unsigned int stringWidth = idRenderModelGui::GetStringWidthInPixels(testString.c_str(), textScale);
////	//		//logInfo("testDraw: stringWidth: %.2f", stringWidth);
////	//		/*float text_x = center_x;
////	//		float text_y = center_y + idRenderModelGui::getSmallCharHeight() * textScale;*/
////	//		float picWidth = (float)stringWidth;
////	//		//float picWidth = idRenderModelGui::getSmallCharWidth() * textScale;
////	//		//float picWidth = glyphWidth * idRenderModelGui::getInternalScaleVal() * textScale;
////	//		float picHeight = charHeight;
////	//		//logInfo("testDraw: picWidth: %.2f  picHeight : %.2f", picWidth, picHeight);
////	//		
////
////
////	//		//logInfo("testDraw: screenWidth: %.2f  screenHeight : %.2f center_x: %.2f center_y: %.2f SmallCharWidth: %.2f SmallCharHeight: %.2f  idRenderModelGui::getInternalScaleVal(): %.2f textScale: %.2f", idRenderModelGui::getScreenWidth(), idRenderModelGui::getScreenHeigth(), center_x, center_y, idRenderModelGui::getSmallCharWidth(), idRenderModelGui::getSmallCharHeight(), idRenderModelGui::getInternalScaleVal(), textScale);
////
////	//		//idRenderModelGui::drawDrawStretchPicTest3(pic_x, pic_y, picWidth, picHeight, m_testMaterial, colorGreen);
////
////	//		idRenderModelGui::drawTextOutline(testString.c_str(), center_x, center_y, textScale, colorWhite, colorBlack, 1);
////	//		idRenderModelGui::drawTextOutline(testString.c_str(), text_x, text_y, textScale, colorWhite, colorBlack, 1);
////	//		//gui.drawTextOutline(testString.c_str(), center_x, center_y, textScale, colorWhite, colorBlack, 1);
////
////	//		std::string debugStr1 = "ScreenWidth: ";
////	//		debugStr1.append(std::to_string(idRenderModelGui::getScreenWidth()));
////	//		debugStr1.append(" ScreenHeight: ");
////	//		debugStr1.append(std::to_string(idRenderModelGui::getScreenHeigth()));
////
////	//		std::string debugStr2 = "getSmallCharWidth: ";
////	//		debugStr2.append(std::to_string(idRenderModelGui::getSmallCharWidth()));
////	//		debugStr2.append(" getSmallCharHeight: ");
////	//		debugStr2.append(std::to_string(idRenderModelGui::getSmallCharHeight()));
////
////	//		std::string debugStr3 = "IdacharWidthMinusXSkip: ";
////	//		debugStr3.append(std::to_string(IdacharWidthMinusXSkip));
////	//		debugStr3.append(" glyph_XSkip: ");
////	//		debugStr3.append(std::to_string(glyph_XSkip));
////	//		debugStr3.append(" glyph_Top_v28: ");
////	//		debugStr3.append(std::to_string(glyph_Top_v28));
////	//		debugStr3.append(" textScale: ");
////	//		debugStr3.append(std::to_string(textScale));
////	//		debugStr3.append(" InternalScaleVal: ");
////	//		debugStr3.append(std::to_string(idRenderModelGui::getInternalScaleVal()));
////
////	//		std::string debugStr4 = "pic_x: ";
////	//		debugStr4.append(std::to_string(pic_x));
////	//		debugStr4.append(" pic_y: ");
////	//		debugStr4.append(std::to_string(pic_y));
////	//		debugStr4.append(" picWidth: ");
////	//		debugStr4.append(std::to_string(picWidth));
////	//		debugStr4.append(" picHeight: ");
////	//		debugStr4.append(std::to_string(picHeight));
////
////	//		std::string debugStr5 = "text_x: ";
////	//		debugStr5.append(std::to_string(text_x));
////	//		debugStr5.append(" text_x_Offset: ");
////	//		debugStr5.append(std::to_string(text_x_Offset));
////	//		debugStr5.append(" text_y: ");
////	//		debugStr5.append(std::to_string(text_y));
////
////	//		std::string debugStr6 = "font: ";
////	//		debugStr6.append(fontStr);
////
////	//		idRenderModelGui::drawSomeTextTest(debugStr5.c_str(), 50,  25, 1, colorGreen);
////	//		idRenderModelGui::drawSomeTextTest(debugStr4.c_str(), 50,  50, 1, colorGreen);
////	//		idRenderModelGui::drawSomeTextTest(debugStr1.c_str(), 50,  75, 1, colorGreen);
////	//		idRenderModelGui::drawSomeTextTest(debugStr2.c_str(), 50, 100, 1, colorGreen);
////	//		idRenderModelGui::drawSomeTextTest(debugStr3.c_str(), 50, 125, 1, colorGreen);
////	//		idRenderModelGui::drawSomeTextTest(debugStr6.c_str(), 50, 150, 1, colorGreen);	
////
////
////	//		//font.set(idFontEnum::defaultCourrierF8); //? attempting to have the console readable..
////
////	//	}
////	//	catch (const std::exception& ex)
////	//	{
////	//		logErr("testDraw: exception: %s", ex.what());
////	//	}
////	//}
////
////	//void addMaterialPtr(__int64 materialPtr) {
////	//	if (std::find(m_idMaterialPtr2Vec.begin(), m_idMaterialPtr2Vec.end(), materialPtr) == m_idMaterialPtr2Vec.end()) {
////	//		// value not found, add it to the vector
////
////
////	//		__int64 typeAddr = *(__int64*)(materialPtr + 0x10);
////	//		__int64 typeStr = *(__int64*)(typeAddr + 0x8);
////
////	//		std::string typeString = (const char*)(typeStr);
////	//		if (typeString == "idMaterial2") {
////	//			__int64 materialNameStr = *(__int64*)(materialPtr + 0x8);
////	//			logInfo("addMaterialPtr adding materialPtr: %p (name: %s)", (void*)materialPtr, (const char*)(materialNameStr));
////	//			m_idMaterialPtr2Vec.push_back(materialPtr);
////	//		}
////	//	}
////	//}
////
////	//void addResourcePtr(__int64 resourcePtr) {
////
////	//	//__int64 resourcePtr = m_idMaterial2Vec[i];
////	//	if (!MemHelper::isBadReadPtr((void*)resourcePtr))
////	//	{
////	//		__int64 typeAddr = *(__int64*)(resourcePtr + 0x10);
////	//		__int64 typeStr = *(__int64*)(typeAddr + 0x8);
////
////	//		std::string typeString = (const char*)(typeStr);
////	//		if (typeString == "idMaterial2") {
////	//			//__int64 materialNameStr = *(__int64*)(resourcePtr + 0x8);
////	//			//logInfo("printIdMaterialsInfo found idMaterial2: %s", (const char*)(materialNameStr));
////	//			if (std::find(m_idMaterial2Vec.begin(), m_idMaterial2Vec.end(), resourcePtr) == m_idMaterial2Vec.end()) {
////	//				// value not found, add it to the vector
////
////	//				m_idMaterial2Vec.push_back(resourcePtr);
////	//			}
////	//		}
////
////	//		//logInfo("printIdMaterialsInfo found type: %s", (const char*)(typeStr));
////	//		//uintptr_t materialStrAddr = *(uintpt0r_t*)(resourcePtr + 0x8);
////	//	}		
////	//}
////
////
////	//void testAlignLeft() {
////	//	if (!MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		*(BYTE*)(m_idDebugHUDLocalAddr + 0x58) = 0;
////	//		//*(_BYTE*)(a1 + 0x58) = 0;
////	//	}
////	//	
////	//}
////
////	//void testAlignRight() {
////	//	if (!MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		*(BYTE*)(m_idDebugHUDLocalAddr + 0x58) = 1;
////	//		//*(_BYTE*)(a1 + 0x58) = 0;
////	//	}
////
////	//}
////
////	
////	float setFontSpacing(float currentSpacing) {
////		if (m_fontSpacing == -1.0f) {
////			m_fontSpacing = currentSpacing;			
////		}
////		return m_fontSpacing;
////	}
////
////	void increaseFontSpacing() {
////		m_fontSpacing += 0.1f;
////	}
////
////	void decreaseFontSpacing() {
////		m_fontSpacing -= 0.1f;
////	}
////
////	//void printIdMaterialsInfo() {
////	//	if (m_idMaterial2Vec.size() == 0) {
////	//		logWarn("printIdMaterialsInfo: no data in m_idMaterial2Vec");
////	//		return;
////	//	}
////	//	else {
////	//		logInfo("printIdMaterialsInfo: m_idMaterial2Vec has data.");
////	//	}
////
////	//	for (size_t i = 0; i < m_idMaterial2Vec.size(); i++)
////	//	{
////	//		__int64 resourcePtr = m_idMaterial2Vec[i];
////	//		if (!MemHelper::isBadReadPtr((void*)resourcePtr))
////	//		{
////	//			__int64 typeAddr = *(__int64*)(resourcePtr + 0x10);
////	//			__int64 typeStr = *(__int64*)(typeAddr + 0x8);
////
////	//			std::string typeString = (const char*)(typeStr);
////	//			if (typeString == "idMaterial2") {
////	//				__int64 materialNameStr = *(__int64*)(resourcePtr + 0x8);
////	//				logInfo("printIdMaterialsInfo found idMaterial2: %s", (const char*)(materialNameStr));
////	//			}
////
////	//			//logInfo("printIdMaterialsInfo found type: %s", (const char*)(typeStr));
////	//			//uintptr_t materialStrAddr = *(uintptr_t*)(resourcePtr + 0x8);
////	//		}
////	//	}
////	//}
////
////
////
////	//void drawCrosshair(bool isEnabled) {
////	//	if (MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		return;
////	//	}
////	//	if (isEnabled) {
////	//		//gui.drawCrosshairTest();
////	//		//gui.drawCrosshairTest2();
////	//		//gui.drawCenteredCrosshairTest();
////	//		//gui.drawCenteredCrosshairWithOutlineTest();
////	//		//gui.drawDrawStretchPicTest();
////	//	}
////	//}
////
////	/*void drawBox(bool isEnabled) {
////		try
////		{
////			if (MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////				return;
////			}
////			if (isEnabled) {
////				if (m_idMaterialPtr2Vec.size() == 0) {
////					logWarn("drawBox: can not draw m_idMaterialPtr2Vec.size() == 0");
////					return;
////				}
////				gui.drawDrawStretchPicTest2(m_idMaterialPtr2Vec[materialIndex]);
////			}
////		}
////		catch (const std::exception& ex)
////		{
////			logErr("drawBox: exception: %s", ex.what());
////		}
////	}*/
////
////	//void changeMaterial() {
////	//	if (m_idMaterialPtr2Vec.size() == 0) {
////	//		logWarn("changeMaterial: no material found, returning");
////	//		return;
////	//	}
////	//	//if (idMaterialPtr == nullptr ) {
////	//	//	// get a pointer to the beginning of the array
////	//	//	idMaterialPtr = m_idMaterial2Vec.data();
////	//	//}
////
////	//	//idMaterialPtr++;
////
////	//	//if (idMaterialPtr >= (m_idMaterial2Vec.data() + m_idMaterial2Vec.size())) {
////	//	//	idMaterialPtr = m_idMaterial2Vec.data();
////	//	//}
////	//	
////	//	materialIndex++;
////	//	if (materialIndex >= m_idMaterialPtr2Vec.size()) {
////	//		materialIndex = 0;
////	//	}
////	//	__int64 matPtr = m_idMaterialPtr2Vec[materialIndex];
////	//	std::string s = getMaterialStringFromMaterialPtr(matPtr);
////	//	logInfo("changeMaterial: material ptr is: %p (name: %s )", (void*)matPtr, s.c_str());
////	//	//idMaterialPtr = &m_idMaterial2Vec[materialIndex];
////	//}
////
////
////	//void debugGetMaterial() {
////	//	static __int64 lastIceBombMaterial = -1;
////	//	m_testMaterial = m_idDeclInfo.getMaterialIdStrPtr("fontfx/supermolot/outline/normal/red", 1);
////	//	//m_testMaterial = m_idDeclInfo.getMaterialIdStrPtr("swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_", 0);
////	//	if (lastIceBombMaterial != m_testMaterial) {
////	//		lastIceBombMaterial = m_testMaterial;
////	//		logInfo("debugGetMaterial updating m_testMaterial:  %llx", m_testMaterial);
////	//	}
////	//}
////
////
////
////	//std::vector<std::string> debutgGetIdPlayerDataVec() {
////	//	std::vector<std::string> idPlayerDataVec;
////	//	idPlayerDataVec.push_back("IdPlayer Data:");
////
////	//	auto idPlayerAddr = ObjectLocator::getIdPlayerAdrr();
////	//	if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
////	//		idPlayer_t* idPlayer = (idPlayer_t*)idPlayerAddr;
////
////	//		//std::string healthFStr = "Health:(float) " + std::to_string(idPlayer->getHealthF());
////	//		//idPlayerDataVec.push_back(healthFStr);
////	//		std::string healthStr = "Health:(int) " + std::to_string(idPlayer->getHealthInt());
////	//		idPlayerDataVec.push_back(healthStr);
////
////	//		//std::string ArmorFStr = "Armor:(float) " + std::to_string(idPlayer->getArmorF());
////	//		//idPlayerDataVec.push_back(ArmorFStr);
////	//		std::string ArmorStr = "Armor:(int) " + std::to_string(idPlayer->getArmorInt());
////	//		idPlayerDataVec.push_back(ArmorStr);
////
////	//		std::string CrucibleCountStr = "Crucible Ammo: " + std::to_string(idPlayer->CrucibleCount);
////	//		idPlayerDataVec.push_back(CrucibleCountStr);
////
////	//		std::string HammerAmmoCountStr = "Hammer Ammo: " + std::to_string(idPlayer->HammerCharge);
////	//		idPlayerDataVec.push_back(HammerAmmoCountStr);
////
////	//		std::string IsFlameBelchReadyStr = "Is Flame Ready: " + std::to_string(idPlayer->IsFlameBelchAvailable);
////	//		idPlayerDataVec.push_back(IsFlameBelchReadyStr);
////
////	//		std::string EquippedNadeTypeStr = "Grenade type: " + std::to_string(idPlayer->EquippedGrenadeType);
////	//		idPlayerDataVec.push_back(EquippedNadeTypeStr);
////
////	//		std::string FragNadeCountStr = "Frag Nade Count: " + std::to_string(idPlayer->FragNadeCount);
////	//		idPlayerDataVec.push_back(FragNadeCountStr);
////
////	//		std::string FragNadeCooldownStr = "Frag Cooldown: " + std::to_string(idPlayer->getFradNadeCoolDownSec());
////	//		idPlayerDataVec.push_back(FragNadeCooldownStr);
////
////	//		std::string IceNadeCountStr = "Ice Nade Count: " + std::to_string(idPlayer->IceNadeCount);
////	//		idPlayerDataVec.push_back(IceNadeCountStr);
////
////	//		std::string IceNadeCooldownStr = "Ice Cooldown: " + std::to_string(idPlayer->getIceNadeCoolDownSec());
////	//		idPlayerDataVec.push_back(IceNadeCooldownStr);
////
////	//		std::string BloodPunchStr = "Blood Punch: " + std::to_string(idPlayer->BloodPunch);
////	//		idPlayerDataVec.push_back(BloodPunchStr);
////
////	//		std::string DashMeterStr = "Dash Meter: " + std::to_string(idPlayer->DashMeter);
////	//		idPlayerDataVec.push_back(DashMeterStr);
////
////	//	}
////	//	return idPlayerDataVec;
////
////	//}
////
////
////
////	/*std::vector<std::string> debuggGetWeaponInfo() {
////		std::vector<std::string> weaponInfoVec;
////		auto idPlayerAddr = ObjectLocator::getIdPlayerAddr();
////		if (!MemHelper::isBadReadPtr((void*)idPlayerAddr)) {
////			__int64 idHUD_ReticleAddr = *(__int64*)(idPlayerAddr + 0x47348);
////			if (!MemHelper::isBadReadPtr((void*)idHUD_ReticleAddr)) {
////				idHUD_Reticle_t* idHUD_Reticle = (idHUD_Reticle_t*)idHUD_ReticleAddr;
////
////				std::string healthStr = "Health:(int) " + std::to_string(idPlayer->getHealthInt());
////				idPlayerDataVec.push_back(healthStr);
////
////			}
////
////		}
////	}*/
////
////	//void debugDrawHudData(bool isEnabled, uint64_t lastidHudReticuleUpdateMs) {
////	//	if (!isEnabled || ((EpochMillis() - lastidHudReticuleUpdateMs > 100))) return; //! will prevent crashes
////
////	//	std::vector<std::string> inventoryStrVec = idInventoryCollectionManager::debugGetPlayerInventoryAsVec();
////	//	float y = 20;
////
////	//	for (size_t i = 0; i < inventoryStrVec.size(); i++)
////	//	{
////	//		idRenderModelGui::drawSomeTextTest(inventoryStrVec[i].c_str(), 50, y, 1, colorWhite);
////	//		y += 20;
////	//	}
////
////	//	y = 20;
////	//	auto idPlayerDataVec = debutgGetIdPlayerDataVec();
////	//	for (size_t i = 0; i < idPlayerDataVec.size(); i++)
////	//	{
////	//		idRenderModelGui::drawSomeTextTest(idPlayerDataVec[i].c_str(), 600, y, 1, colorWhite);
////	//		y += 20;
////	//	}
////
////	//}
////
////
////	//void drawDrawRectangle(float x, float y, float width, float height, __int64 materialPtr, const idColor& crosshairColor) {
////
////	//	//void drawDrawStretchPicTest3(float x, float y, float width, float height, __int64 matPtr, const idColor& idColor, bool isMiroredX = false, bool isMiroredY = false) {
////	//	//logInfo("x = %f, y = %f, width = %f, height = %f, materialPtr = %lld)", x, y, width, height, materialPtr);
////	//	idRenderModelGui::drawDrawStretchPicTest3(x, y, width, height, materialPtr, crosshairColor);
////	//}
////
////
////
////
////
////	//void drawCircleWithOutline(bool isEnabled, uint64_t lastidHudReticuleUpdateMs, float radius, float outlineThickness) {
////
////
////	//	if (!isEnabled) return;
////
////	//	if (MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		logWarn("testDraw: m_idDebugHUDLocalAddr is bad ptr");
////	//		return;
////	//	}
////
////	//	if (m_testMaterial == 0) {
////	//		getNextMaterial();
////	//	}
////
////	//	if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////	//		return;
////	//	}
////	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////	//	if (EpochMillis() - lastidHudReticuleUpdateMs > 100) return;
////
////	//	// Calculate dimensions of the crosshair
////	//	__int64 materialPtr = m_testMaterial;
////	//	idColor fillColor = colorGreen;
////	//	idColor outlineColor = colorBlack;
////
////	//	float centerX = gui.getScreenWidth()/2.0f;
////	//	float centerY = gui.getScreenHeigth()/2.0f;
////
////
////
////	//	// Draw the circle with the fill color
////	//	float diameter = radius * 2.0f;
////	//	drawDrawRectangle(centerX - radius, centerY - radius, diameter, diameter, m_testMaterial, fillColor);
////
////	//	// Draw the outline
////	//	drawDrawRectangle(centerX - radius - outlineThickness, centerY - radius - outlineThickness, diameter + outlineThickness * 2.0f, outlineThickness, m_testMaterial, outlineColor); // Top
////	//	drawDrawRectangle(centerX + radius, centerY - radius - outlineThickness, outlineThickness, diameter + outlineThickness * 2.0f, m_testMaterial, outlineColor); // Right
////	//	drawDrawRectangle(centerX - radius - outlineThickness, centerY + radius, diameter + outlineThickness * 2.0f, outlineThickness, m_testMaterial, outlineColor); // Bottom
////	//	drawDrawRectangle(centerX - radius - outlineThickness, centerY - radius - outlineThickness, outlineThickness, diameter + outlineThickness * 2.0f, m_testMaterial, outlineColor); // Left
////	//}
////
////
////
////
////
////	//void drawCrosshairCrossGpt(bool isEnabled, uint64_t lastidHudReticuleUpdateMs) {
////
////	//	if (!isEnabled) return;
////
////	//	if (MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		logWarn("testDraw: m_idDebugHUDLocalAddr is bad ptr");
////	//		return;
////	//	}
////
////	//	if (m_testMaterial == 0) {
////	//		getNextMaterial();
////	//	}
////
////	//	if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////	//		return;
////	//	}
////	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////	//	if (EpochMillis() - lastidHudReticuleUpdateMs > 100) return;
////
////
////	//	float crosshairWidth = 20.0f;
////	//	float crosshairHeigth = 2.0f;
////	//	float crosshairOutlineSize = 1.0f;
////
////	//	std::string crosshairWidthTxt = std::to_string(crosshairWidth);
////	//	std::string crosshairHeigthTxt = std::to_string(crosshairHeigth);
////	//	std::string crosshairOulineSizeTxt = std::to_string(crosshairOutlineSize);
////	//	//float crosshairOutlineSize = 1.0f;
////	//	std::string output = "drawCrosshairCrossGpt: crosshairWidth: " + crosshairWidthTxt + " crosshairHeigth: " + crosshairHeigthTxt + " crosshairOutlineSize " + crosshairOulineSizeTxt;
////
////	//	font.set(idFontEnum::defaultCourrierF8);
////	//	idRenderModelGui::drawSomeTextTest(output.c_str(), 50, 300, 1.5, colorWhite);
////	//	/*float crosshairSize = 16;
////	//	float crosshairOurlineSize = 4;*/
////
////	//	//gui.drawCrosshairCrossGpt(gui.getCenterX(), gui.getCenterY(), crosshairSize, crosshairOurlineSize, m_testMaterial);
////	//	//gui.drawCenteredBar(8, 4, 2, m_testMaterial);
////	//	//gui.drawCentereHordBar(16, 4, 2, m_testMaterial);
////	//	//gui.drawCenteredVerBar(16, 4, 2, m_testMaterial);
////
////	//	idRenderModelGui::drawCrossHairPlusWithOutline(crosshairWidth, crosshairHeigth, crosshairOutlineSize, m_testMaterial);
////
////	//}
////
////
////
////	//void CrosshairDotOutlineGPT(bool isEnabled, uint64_t lastidHudReticuleUpdateMs) {
////	//	if (!isEnabled) return;
////
////	//	if (MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		logWarn("testDraw: m_idDebugHUDLocalAddr is bad ptr");
////	//		return;
////	//	}
////
////
////	//	if (m_testMaterial == 0) {
////	//		getNextMaterial();
////	//	}
////
////	//	if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////	//		return;
////	//	}
////	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////	//	if (EpochMillis() - lastidHudReticuleUpdateMs > 100) return;
////
////	//	//logWarn("CrosshairDotOutlineGPT: running");
////
////	//	//! check steam screeshot for values we experimented with
////
////	//	float crosshairSize = 4.2f;
////	//	float crosshairOutlineSize = 4.0f;
////
////	//	std::string crosshairSizeTxt = std::to_string(crosshairSize);
////	//	std::string crosshairOulineSizeTxt = std::to_string(crosshairOutlineSize);
////	//	std::string output = "CrosshairDotOutlineGPT: VectorCrosshair size: " + crosshairSizeTxt + " VectorCrosshair outline size: " + crosshairOulineSizeTxt;
////
////	//	font.set(idFontEnum::defaultCourrierF8);
////	//	idRenderModelGui::drawSomeTextTest(output.c_str(), 50, 300, 2, colorWhite);
////
////	//	//__int64 crosshairMaterial = ... // Choose the material for the crosshair
////	//	//__int64 outlineMaterial = ... // Choose the material for the outline
////	//	idColor crosshairColor = colorGreen;
////	//	idColor outlineColor = colorBlack;
////
////	//	// Calculate the position and size of the crosshair and outline
////	//	float crosshairX = idRenderModelGui::getCenterX() - crosshairSize / 2.0f;
////	//	float crosshairY = idRenderModelGui::getCenterY() - crosshairSize / 2.0f;
////	//	float outlineX = crosshairX - crosshairOutlineSize / 2.0f;
////	//	float outlineY = crosshairY - crosshairOutlineSize / 2.0f;
////	//	float outlineWidth = crosshairSize + crosshairOutlineSize;
////	//	float outlineHeight = crosshairSize + crosshairOutlineSize;
////
////	//	//logInfo("crosshairX: %.2f crosshairY: %.2f outlineX: %.2f outlineY: %.2f outlineWidth: %.2f outlineHeight: %.2f", crosshairX, crosshairY, outlineX, outlineY, outlineWidth, outlineHeight);
////
////	//	// Draw the outline
////	//	idRenderModelGui::drawDrawStretchPicTest3(outlineX, outlineY, outlineWidth, outlineHeight, m_testMaterial, outlineColor);
////
////	//	//gui.drawCenteredCross(20, 2, m_testMaterial, colorGreen);
////
////	//	// Draw the crosshair
////	//	idRenderModelGui::drawDrawStretchPicTest3(crosshairX, crosshairY, crosshairSize, crosshairSize, m_testMaterial, crosshairColor);
////	//}
////
////
////
////	//void testDrawCenteredCrossHair(bool isEnabled, uint64_t lastidHudReticuleUpdateMs) {
////	//	if (!isEnabled) return;
////
////	//	if (MemHelper::isBadReadPtr((void*)m_idDebugHUDLocalAddr)) {
////	//		logWarn("testDraw: m_idDebugHUDLocalAddr is bad ptr");
////	//		return;
////	//	}
////
////
////	//	if (m_testMaterial == 0) {
////	//		getNextMaterial();
////	//	}
////
////	//	if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////	//		return;
////	//	}
////	//	//? not drawning if default game reticule should not be drawn, also should prevent crashes (hopefully)
////	//	if (EpochMillis() - lastidHudReticuleUpdateMs > 100) return;
////
////
////	//	idRenderModelGui::drawCenteredCross(20, 2, m_testMaterial, colorGreen);
////
////	//}
////
////
////	
////
////
////	//void drawAllCharactersOfFont(idFontEnum idFontEnum) {
////	//	font.set(idFontEnum);
////
////	//	float x = 50;
////	//	float y = 50;
////	//	for (int i = 0; i < 1024; ++i) {
////	//		char letter = static_cast<char>(i);
////	//		std::string text = std::string(1, letter);
////	//		idRenderModelGui::drawSomeTextTest(text.c_str(), x, y, 2, colorWhite);
////	//		x += 20;
////	//		if (x >= 1500) {
////	//			x = 50;
////	//			y += 50;
////	//		}
////
////
////	//		/*drawTextOutline(text.c_str(), x, y, 1, textColor, outlineColor, outlineWidth);
////	//		x += scale * face->glyph->advance.x / 64.0f;*/
////	//	}
////	//}
////
////	void showMaterial(__int64 idRenderModelGuiAddr) {
////		if (MemHelper::isBadReadPtr((void*)m_testMaterial)) {
////			logWarn("showMaterial: m_testMaterial is badPtr, setting it to _white instead...");
////			m_testMaterial = MaterialLib::getWhite();
////		}
////		idRenderModelGui::drawDebugMaterialCenter100x100(idRenderModelGuiAddr, m_testMaterial);
////	}
////
////
////	void getNextMaterial() {
////		/*__int64 idDebugHUDAddr = ObjectLocator::get_idDebugHUDAddr();
////		if (MemHelper::isBadReadPtr((void*)idDebugHUDAddr)) {
////			logWarn("getNextMaterial: idDebugHUDAddr is bad ptr");
////			return;
////		}*/
////		
////		//logWarn("getNextMaterial called");
////		//m_testMaterial = MaterialLib::debugGetNext();
////		m_testMaterial = MaterialLib::getLibNext();
////
////
////		/*auto result = MaterialLib::getNext();
////		m_testMaterial = result.MatPtr;
////		m_strToDisplay = result.Name;*/
////	}
////
////
////	void getPreviousMaterial() {
////		/*__int64 idDebugHUDAddr = ObjectLocator::get_idDebugHUDAddr();
////		if (MemHelper::isBadReadPtr((void*)idDebugHUDAddr)) {
////			logWarn("getPreviousMaterial: idDebugHUDAddr is bad ptr");
////			return;
////		}	*/	
////		//logWarn("getPreviousMaterial called");
////		//m_testMaterial = MaterialLib::debugGetPrev();
////
////		m_testMaterial = MaterialLib::getLibPrev();
////
////
////		/*auto result = MaterialLib::getPrevious();
////		m_testMaterial = result.MatPtr;
////		m_strToDisplay = result.Name;*/
////	}
////
////
////	/*void fontsTest() {
////		set(idFontEnum::eternal88);
////		gui.drawSomeTextTest("eternal88", 50, 50, 1);
////		gui.drawSomeTextTest("100 + . *", 400, 50, 2);
////		set(idFontEnum::idTacticA8);
////		gui.drawSomeTextTest("idTacticA8", 50, 100, 1);
////		gui.drawSomeTextTest("100 + . *", 400, 100, 2);
////		set(idFontEnum::eternal90);
////		gui.drawSomeTextTest("eternal90", 50, 150, 1);
////		gui.drawSomeTextTest("100 + . *", 400, 150, 2);
////		set(idFontEnum::euroStilB0);
////		gui.drawSomeTextTest("EeuroStilB0", 50, 200, 1);
////		gui.drawSomeTextTest("100 + . * ", 400, 200, 2);
////		set(idFontEnum::ttSuper98);
////		gui.drawSomeTextTest("TtSuper98 100", 50, 250, 1);
////		gui.drawSomeTextTest("100 + . *", 400, 250, 3);
////		set(idFontEnum::ttSuperA0);
////		gui.drawSomeTextTest("TtSuperA0", 50, 300, 1);
////		gui.drawSomeTextTest("100 + . *", 400, 300, 2);
////		set(idFontEnum::defaultCourrierF8);
////		gui.drawSomeTextTest("defaultCourrierF8", 50, 350, 1);
////		gui.drawSomeTextTest("100 + . *", 400, 350, 2);
////		set(idFontEnum::defaultCourrierF8);
////	}*/
////
////
////	/*__int64 getIdMaterialPtr() {
////
////	}*/
////
////
////
////
////
////};
////
//////? keep this: From MeatHook mod in gameapi.cpp
/////*
////struct idDebugHUD_vtbl
////{
////	void(__fastcall* dctor_idDebugHUD)(idDebugHUD* thiz);
////	void(__fastcall* Render)(idDebugHUD* thiz, idRenderModelGui*);
////	void(__fastcall* Frame)(idDebugHUD* thiz);
////	void(__fastcall* Clear)(idDebugHUD* thiz, bool);
////	void (*Printf3)(idDebugHUD* thiz, const char*, ...);
////	void(__fastcall* Printf1)(idDebugHUD* thiz, int, int, const char*, char*);
////	void (*Printf4)(idDebugHUD* thiz, int, int, const char*, ...);
////	void(__fastcall* Printf2)(idDebugHUD* thiz, int, int, const idColor*, const idColor*, const char*, char*);
////	void (*Printf5)(idDebugHUD* thiz, int, int, const idColor*, const idColor*, const char*, ...);
////	void(__fastcall* Printf6)(idDebugHUD* thiz, int, int, const idColor*, const char*, char*);
////	void (*Printf7)(idDebugHUD* thiz, int, int, const idColor*, const char*, ...);
////	void (*Printf8)(idDebugHUD* thiz, int, int, const idColor*, const float, const char*, ...);
////	void(__fastcall* Printf9)(idDebugHUD* thiz, int, int, const idColor*, const float, const int, const char*, char*);
////	void (*Printf10)(idDebugHUD* thiz, int, int, const idColor*, const idColor*, const float, const char*, ...);
////	void(__fastcall* Printf11)(idDebugHUD* thiz, int, int, const idColor*, const idColor*, const float, const int, const char*, char*);
////	void(__fastcall* Printf)(idDebugHUD* thiz, int, int, const idColor*, const idColor*, const float, const int, const char*, char*);
////	void* unk2;
////	void (*AddPersistentText)(idDebugHUD* thiz, int, int, const idColor*, const float, const char*, ...);
////	void(__fastcall* RemovePersistentText)(idDebugHUD* thiz, int, int);
////	void(__fastcall* SetLeftAlign)(idDebugHUD* thiz);
////	void(__fastcall* SetRightAlign)(idDebugHUD* thiz);
////	void(__fastcall* SetTextPosition)(idDebugHUD* thiz, const int, const int);
////	void(__fastcall* SetTextScale)(idDebugHUD* thiz, const float);
////	void(__fastcall* SetTextColor)(idDebugHUD* thiz, const idColor*);
////};    */
