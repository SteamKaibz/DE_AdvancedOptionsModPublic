#include "idRenderModelGuiManager.h"




void idRenderModelGuiManager::parseTextColor(char colorCode, idColor& outColor) {

	switch (colorCode) {
	case '0': outColor = colorMagenta; break;
	case '1': outColor = colorRed; break;
	case '2': outColor = colorGreen; break;
	case '3': outColor = colorYellow; break;
	case '4': outColor = colorBlue; break;
	case '5': outColor = colorCyan; break;
	case '6': outColor = colorOrange; break;
	case '7': outColor = colorWhite; break;
	case '8': outColor = colorVeryLtGrey; break;
	case '9': outColor = colorBlack; break;
		/*default: currentColor = defaultColor; break;*/
	}
}


//! from Doom3: idDeviceContext::PaintChar( float x, float y, const scaledGlyphInfo_t & glyphInfo )
void idRenderModelGuiManager::paintChar(idRenderModelGui* gui, float x, float y, const scaledGlyphInfo_t& glyphInfo) {

	y -= glyphInfo.top;
	x += glyphInfo.left;

	float w = glyphInfo.width;
	float h = glyphInfo.height;
	float s = glyphInfo.s1;
	float t = glyphInfo.t1;
	float s2 = glyphInfo.s2;
	float t2 = glyphInfo.t2;
	idMaterial2* material = glyphInfo.material;

	if (!material) {
		logErr("paintChar: material is null");
		return;
	}

	//todo from orig function, don't think we need it but we should look into it later
	/*if (ClippedCoords(&x, &y, &w, &h, &s, &t, &s2, &t2)) {
		return;
	}*/

	//! we don't have to use the wrapper here.
	pidRenderModelGui_DrawStretchPic(gui, x, y, 0.0f, w, h, s, t, s2, t2, material);

}


void idRenderModelGuiManager::drawStringForRectHeigth_V2(idRenderModelGui* gui, swfRect_t bounds, std::string text, idFontHash fontHash, const idColor& color, bool forceColor, textAlignment alignment, bool isDebug) {


	if (!m_cachedWhiteMaterial) {
		acquirreWhiteMaterial();
	}

	if (text.empty()) {
		return;
	}

	idFontManager::setdebugGUIFont(fontHash);
	float fontHeightForA = (float)idFontManager::getFontHeightForLetter_A(idFontManager::getCurConsoleFont());
	float textScale = bounds.getHeight() / fontHeightForA;

	char refChar = '0';
	scaledGlyphInfo_t ref_glyphInfo;
	idFontManager::GetScaledGlyph(idFontManager::getCurConsoleFont(), textScale, refChar, ref_glyphInfo);

	char firstChar = text[0];
	scaledGlyphInfo_t glyphInfo_FirstChar;
	idFontManager::GetScaledGlyph(idFontManager::getCurConsoleFont(), textScale, refChar, glyphInfo_FirstChar);	
	float textX = bounds.getLeft() - 1.0f * glyphInfo_FirstChar.left; 
	float textY = bounds.getTop() + ref_glyphInfo.top ;
	float textWidth = (float)idFontManager::getTextWidth(idFontManager::getCurConsoleFont(), text.c_str(), textScale, 0);


	if (isDebug) {
		swfRect_t debugBounds = bounds;
		debugBounds.setWidth(textWidth);
		drawSwfRectMaterial_V2(gui, debugBounds, colorGreen, m_cachedWhiteMaterial);
	}

	if (alignment == textAlignment::center) {
		textX = textX + (bounds.getWidth() * .5f - textWidth * .5f);
	}
	else if (alignment == textAlignment::right) {
		textX = bounds.getRight() - textWidth;
	}

	setColor(gui, color);
	idColor newColor = color;

	// Process text and handle color codes
	for (size_t i = 0; i < text.size(); ++i) {
		char c = text[i];

		// Check for color escape sequence (e.g., ^1)
		if (c == '^' && i + 1 < text.size()) {
			char colorCode = text[i + 1];
			parseTextColor(colorCode, newColor);
			if (!forceColor) {
				setColor(gui, newColor);
			}
			i++;  // Skip color code character
			continue;
		}

		// Draw the character
		int charCode = static_cast<int>(c);
		scaledGlyphInfo_t glyphInfo;
		idFontManager::GetScaledGlyph(idFontManager::getCurConsoleFont(), textScale, charCode, glyphInfo);
		paintChar(gui, textX, textY, glyphInfo);
		textX += glyphInfo.xSkip;
	}

	if (!forceColor) {
		// Reset color to default at the end if needed
		setColor(gui, color);
	}
}




void idRenderModelGuiManager::drawSwfRectMaterial_V2(idRenderModelGui* gui, swfRect_t swfRect, const idColor& color, idMaterial2* material) {

	//? commenting those and doing the check at the render of the ice icon so hopefully we have more time to render and fix the flickering of the icon
	/*if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
	logErr("drawDrawStretchPicSwfRectidRenderModelGuiAdrr bad ptr %p", (void*)idRenderModelGuiAdrr);
	return;
	}*/

	if (MemHelper::isBadReadPtr(material)) {
		logErr("drawSwfRectMaterial_V2 bad matr ptr %p", material);
		return;
	}

	//DrawStretchPic(x, y, 0.0, w, h, 0.0, 0.0, 1.0, 1.0, whitemat);
	float s1 = 0.0;
	float t1 = 0.0;
	float s2 = 1.0;
	float t2 = 1.0;

	setColor_V2(gui, color);	
	
	float x = swfRect.tl.x;
	float y = swfRect.tl.y;
	float width = swfRect.br.x - swfRect.tl.x;
	float height = swfRect.br.y - swfRect.tl.y;

	//m_drawStretchPicFp_V2(gui, x, y, 0.0, width, height, s1, t1, s2, t2, material);

	pidRenderModelGui_DrawStretchPic(gui, x, y, 0.0, width, height, s1, t1, s2, t2, material);
}


void idRenderModelGuiManager::setColor_V2(idRenderModelGui* gui, const idColor& idColor) {
	if (MemHelper::isBadReadPtr((void*)gui)) {
		logErr("setColor_V2: can not set color cause idRenderModelGuiAdrr is bad ptr");
		return;
	}
	gui->currentVertexColor = idColor.PackColor();
}


bool idRenderModelGuiManager::acquirreWhiteMaterial()
{
	m_cachedWhiteMaterial = MaterialLib::getMaterialPtr("_white", 0);
	if (!m_cachedWhiteMaterial) {
		logErr("acquirreWhiteMaterial: FAILED");
		return false;
	}
	return true;

	//? no we can not do that as _white in the debugHud can be null.....
	/*idDebugHUDLocal* debugHudLocal = TypeInfoManager::getdebugHUD();
	if (!debugHudLocal) {
		logErr("acquirreWhiteMaterial: debugHudLocal is null (?!)");
		return false;
	}
	if (!debugHudLocal->whiteMaterial) {
		logErr("acquirreWhiteMaterial: debugHudLocal->whiteMaterial is nullptr (?!)");
		return false;
	}

	m_cachedWhiteMaterial = debugHudLocal->whiteMaterial;
	logInfo("acquirreWhiteMaterial: m_cachedWhiteMaterial set to %p", m_cachedWhiteMaterial);
	return true;*/
}


std::string idRenderModelGuiManager::debugGetFontNameString(idFontHash fontHash) {

	switch (fontHash)
	{
	case idFontHash::unknown:
		return "unknown...";
	case idFontHash::courier:
		return "courier";
	case idFontHash::eternal_bold:
		return "eternal_bold";
	case idFontHash::eternal_reg:
		return "eternal_reg";
	case idFontHash::eternal_num:
		return "eternal_num";
	case idFontHash::tt_supermolot:
		return "tt_supermolot";
	case idFontHash::idTactical:
		return "idTactical";
	case idFontHash::eurostileconreg:
		return "eurostileconreg";
	default:
		return "default case (?!)";
	}
}

void idRenderModelGuiManager::debugDrawAllFonts(idRenderModelGui* gui) {

	float screenX = (float)fastCvarManager::getWindowWidthInt();
	float screenY = (float)fastCvarManager::getWindowHeightInt();
	
	std::vector<idFontHash> fontHashes = {
	   idFontHash::courier, idFontHash::eternal_bold, idFontHash::eternal_reg,
	   idFontHash::eternal_num, idFontHash::tt_supermolot,
	   idFontHash::idTactical, idFontHash::eurostileconreg
	};

	float padX = 0.05f * screenX;
	float padY = 0.05f * screenY;

	unsigned int linesCount = (unsigned int)fontHashes.size() + 1;
	unsigned int vertDivs = linesCount * 2;

	float lineHeight = ( screenY - 2 * padY) / (float)vertDivs;
	float lineWidth = screenX - 2 * padX;

	float curY = padY;
	float adjustYMul = 1.2f;

	swfRect_t bounds(padX, curY, lineWidth, lineHeight);

	std::string testString = " AEWXIJBO 191 201 11";
	
	for (size_t i = 0; i < fontHashes.size(); i++)
	{
		std::string str = debugGetFontNameString(fontHashes[i]) + testString;
		drawStringForRectHeigth_V2(gui, bounds, str, fontHashes[i], colorWhite, false, textAlignment::left, true);

		curY += (lineHeight * adjustYMul);
		bounds = swfRect_t(padX, curY, lineWidth, lineHeight);
	}

	

}


 /*bool idRenderModelGuiManager::acquireStaticWhiteMaterialAddr(__int64 addr) {

	logDebug("acquireStaticWhiteMaterialAddr");
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquireStaticWhiteMaterialAddr: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	__int64 matAddr = *(__int64*)addr;
	if (MemHelper::isBadReadPtr((void*)matAddr)) {
		logErr("acquireStaticWhiteMaterialAddr: matAddr is bad ptr: %p", (void*)matAddr);
		return false;
	}
	m_staticMaterialWhiteAddr = matAddr;
	logInfo("acquireStaticWhiteMaterialAddr:  white matr ptr addr: %p m_staticMaterialWhiteAddr is being set to: %p ", (void*)addr, (void*)m_staticMaterialWhiteAddr);
	return true;
}*/

 bool idRenderModelGuiManager::acquirreDrawStretchPicFuncAdd(__int64 fAdd) {
	logDebug("setIdHud_Debug_Print_SmthFuncAddr");
	if (MemHelper::isBadReadPtr((void*)fAdd)) {
		logErr("acquirreDrawStretchPicFuncAdd: fAdd is bad ptr: %p", (void*)fAdd);
		return false;
	}
	pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(fAdd);
	logInfo("acquirreDrawStretchPicFuncAdd: pidRenderModelGui_DrawStretchPic is being set to : %p ", (void*)pidRenderModelGui_DrawStretchPic);
	

	return true;
}

 bool idRenderModelGuiManager::acquirreDrawStringFuncAdd(__int64 fAdd) {
	logDebug("acquirreDrawStringFuncAdd");
	if (MemHelper::isBadReadPtr((void*)fAdd)) {
		logErr("acquirreDrawStringFuncAdd: fAdd is bad ptr: %p", (void*)fAdd);
		return false;
	}
	m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(fAdd);
	logInfo("acquirreDrawStringFuncAdd: m_pidRenderModelGui_DrawString is being set to : %p ", (void*)m_pidRenderModelGui_DrawString);
	return true;
}

 bool idRenderModelGuiManager::acquirreSmallCharWidhtAddr(__int64 addr) {
	logDebug("acquirreSmallCharWidhtAddr");
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquirreSmallCharWidhtAddr: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	m_smallCharWidthAddr = addr;
	logInfo("acquirreSmallCharWidhtAddr: m_smallCharWidthAddr is being set to : %p ", (void*)m_smallCharWidthAddr);
	return true;
}

 bool idRenderModelGuiManager::acquirreSmallCharHeightAddr(__int64 addr) {
	logDebug("acquirreSmallCharHeightAddr");
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquirreSmallCharHeightAddr: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	m_smallCharHeightAddr = addr;
	logInfo("acquirreSmallCharHeightAddr: m_smallCharHeightAddr is being set to : %p ", (void*)m_smallCharHeightAddr);
	return true;
}

 bool idRenderModelGuiManager::acquirreUseScaleAddr(__int64 addr) {
	logDebug("acquirreUseScaleAddr");
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquirreUseScaleAddr: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	m_useScaleAddr = addr;
	logInfo("acquirreUseScaleAddr: m_useScaleAddr is being set to : %p ", (void*)m_useScaleAddr);
	return true;
}

 bool idRenderModelGuiManager::acquirreScreenWidthAddr(__int64 addr) {
	logDebug("acquirreScreenWidthAddr");
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquirreScreenWidthAddr: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	m_screenWidthAddr = addr;
	logInfo("acquirreScreenWidthAddr: m_screenWidthAddr is being set to : %p ", (void*)m_screenWidthAddr);
	return true;
}

 bool idRenderModelGuiManager::acquirreScreenHeight(__int64 addr) {
	if (MemHelper::isBadReadPtr((void*)addr)) {
		logErr("acquirreScreenHeight: addr is bad ptr: %p", (void*)addr);
		return false;
	}
	m_screenHeightAddr = addr;
	logInfo("acquirreScreenHeight: m_screenHeightAddr is being set to : %p ", (void*)m_screenHeightAddr);
	return true;

}

 //bool idRenderModelGuiManager::acquirepackedColorMemberOffset(__int64 offset)
 //{
	// if (!offset) {
	//	 logErr("acquirepackedColorMemberOffset: offset is 0", offset);
	//	 return false;
	// }


	//
 //}




//! not sure what that values is supposed to be exactly but it's used in DrawString_623530

 float idRenderModelGuiManager::getUseScaleVal() {
	if (!m_useScaleAddr) {
		logErr("getUseScaleVal useScaleAddr is bad ptr returning 0");
		return 0;
	}
	return *(float*)m_useScaleAddr;
}

 float idRenderModelGuiManager::getSmallCharWidth() {
	if (!m_smallCharWidthAddr) {
		logErr("getSmallCharWidth m_smallCharWidthAddr is bad ptr returning 0");
		return 0;
	}
	return *(float*)m_smallCharWidthAddr;
}

 float idRenderModelGuiManager::getSmallCharHeight() {
	if (!m_smallCharHeightAddr) {
		logErr("getSmallCharHeight m_smallCharHeightAddr is bad ptr returning 0");
		return 0;
	}
	return *(float*)m_smallCharHeightAddr;
}

 //? 2
 float idRenderModelGuiManager::getScreenWidth() {
	if (!m_screenWidthAddr) {
		logErr("getScreenWidth m_screenWidthAddr is bad ptr returning 0");
		return 0.0f;
	}
	return ((float)(*(int*)(m_screenWidthAddr)));
	//return *(float*)m_screenWidthAddr;
}

 float idRenderModelGuiManager::getScreenHeight() {
	if (!m_screenHeightAddr) {
		logErr("getScreenHeight m_screenHeightAddr is bad ptr returning 0");
		return 0.0f;
	}
	return ((float)(*(int*)(m_screenHeightAddr)));
	//return *(float*)m_screenHeightAddr;
}

 unsigned idRenderModelGuiManager::GetStringWidthInPixels(const char* string, const float scale)
{
	int i; // er8
	char v4; // cl
	__int64 v5; // rax

	for (i = 0; *string; string += v5)
	{
		//! K: 94 is ^ so it means there are 2 chars i suppose.
		if (*string == 94 && ((v4 = string[1], (unsigned __int8)(v4 - 48) <= 9u) || (unsigned __int8)(v4 - 97) <= 3u))
		{
			v5 = 2i64;
		}
		else
		{
			++i;
			v5 = 1i64;
		}
	}
	return (unsigned int)(int)(float)((float)((float)i * getSmallCharWidth()) * scale);
}

// unsigned int idRenderModelGuiManager::getCurrentPackedColor(__int64 idRenderModelGuiAdr) {
//	if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdr)) {
//		logErr("getCurrentPackedColor: idRenderModelGuiAdrr is bad ptr returning colorWhite.PackColor()");
//		return colorWhite.PackColor();
//	}
//	return 	*(unsigned int*)(idRenderModelGuiAdr + m_packedColorOffset);
//}

//! this is just a version that does not check for bad ptr to try to optimize the render of ice icon(the check is already done in the container func.
 void idRenderModelGuiManager::setColorNoCheck(idRenderModelGui* gui, const idColor& idColor) {

	//*(unsigned int*)(idRenderModelGuiAdrr + m_packedColorOffset) = idColor.PackColor();
	 gui->currentVertexColor = idColor.PackColor();
}

 void idRenderModelGuiManager::setColor(idRenderModelGui* gui, const idColor& idColor) {
	if (MemHelper::isBadReadPtr(gui)) {
		logErr("setColor: can not set color cause idRenderModelGuiAdrr is bad ptr");
		return;
	}
	gui->currentVertexColor = idColor.PackColor();
	//*(unsigned int*)(idRenderModelGuiAdrr + m_packedColorOffset) = idColor.PackColor();
}

 //? 1
// float idRenderModelGuiManager::getScreenWidth(__int64 idRenderModelGuiAddr) {
//	if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAddr)) {
//		logErr("getScreenWidth: idRenderModelGuiAddr is bad ptr: %p", (void*)idRenderModelGuiAddr);
//		return 0;
//	}
//	//return ((float)(*(int*)(MemHelper::getAddr(0x39AF8BC))));
//	return ((float)(*(int*)(idRenderModelGuiAddr + m_screenWidthOffset)));
//}

// float idRenderModelGuiManager::getScreenHeigth(__int64 idRenderModelGuiAddr) {
//	if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAddr)) {
//		logErr("getScreenHeigth: idRenderModelGuiAddr is bad ptr: %p", (void*)idRenderModelGuiAddr);
//		return 0;
//	}
//	//return ((float)(*(int*)(MemHelper::getAddr(0x39AF8BC))));
//	return ((float)(*(int*)(idRenderModelGuiAddr + m_screenHeighthOffset)));
//}

 float idRenderModelGuiManager::getCenterX(idRenderModelGui* gui) {
	//return getScreenWidth(idRenderModelGuiAddr) / 2.0f;
	return getScreenWidth() / 2.0f;
}

 float idRenderModelGuiManager::getCenterY(idRenderModelGui* gui) {
	//return getScreenHeigth(idRenderModelGuiAddr) / 2.0f;
	return getScreenHeight() / 2.0f;
}

 

 float idRenderModelGuiManager::getFontScaleFromWidthV2(idVec4 rect, size_t strLettersCount) {


	float scaleMaxFromWidth = (float)rect.w / (getSmallCharWidth() * strLettersCount);

	if (scaleMaxFromWidth * getSmallCharHeight() > rect.h) {
		return (float)rect.h / getSmallCharHeight();
	}
	return scaleMaxFromWidth;

	//return width / (getSmallCharWidth() * str.size());
	//float result = width / (getSmallCharWidth() * str.size());
	//logInfo("getFontScaleFromWidth: width: %.2f, str.size(): %zu getSmallCharWidth: %.2f result: %.2f", width, str.size(), getSmallCharWidth(), result);
	//return result;
}

 float idRenderModelGuiManager::getFontScaleFromWidthV3(idVec4 rect, size_t strLettersCount) {

	return  (float)rect.w / (getSmallCharWidth() * strLettersCount);

}


//! because we don't stretch the string vertically a string height value will be a ratio of the charwidth and charheight

 void idRenderModelGuiManager::adjustRectHeightToFitTheStr(idVec4& rect, size_t strCharCount) {
	if (strCharCount <= 0) {
		logErr("adjustRectHeightToFitTheStr: strCharCount <= 0 can not adjust rect height");
		return;
	}
	float charRatio = getSmallCharHeight() / getSmallCharWidth();
	float widhtFor1char = rect.w / strCharCount;
	float normalizedRectHeight = widhtFor1char * charRatio;
	//float normalizedRectHeight = widhtFor1char * (getSmallCharHeight() / getSmallCharWidth());
	/*logInfo("debugGetNormalizedStringContainerRectV2: charRatio: %.2f, current rect height: %.2f minRectHeight: %.2f", charRatio, rect.h, normalizedRectHeight);*/
	/*if (rect.h != normalizedRectHeight) {
	logInfo("debugGetNormalizedStringContainerRectV2: rect.h != normalizedRectHeight");
	}*/
	rect.h = normalizedRectHeight;
}

 //? 2/11/24 removing this as it's wrong anyway...
// idVec2 idRenderModelGuiManager::getGlyphOffset(idVec4 rect, const char* str, float textScale) {
//	idVec2 offsetsVec2;
//	auto Glyph_4CC330 = (unsigned __int8*)idFontManager::getGlyphInfoForCurConsoleFont(str);
//	//auto Glyph_4CC330 = (unsigned __int8*)idFontManager::getGlyphDataAddr(str);
//	//if (Glyph_4CC330) {
//		auto y_offset_v30 = (float)(char)Glyph_4CC330[2] * (float)(getUseScaleVal() * textScale);
//		auto smallCharHeight_Plus_YArg_v22 = getSmallCharHeight() + rect.y;
//
//		float y_fromDrawStringFunc = smallCharHeight_Plus_YArg_v22 - y_offset_v30;
//
//		offsetsVec2.x = rect.w;
//		offsetsVec2.y = rect.y - y_fromDrawStringFunc;
//		//float y_final_offset = rect.y - y_fromDrawStringFunc;
//
//		/*logInfo("getGlyphOffset: y_offset_v30: %.2f smallCharHeight_Plus_YArg_v22: %.2f y_fromDrawStringFunc: %.2f  rect.y: %.2f offsetsVec2.y: %.2f, offsetsVec2.x: %.2f", y_offset_v30, smallCharHeight_Plus_YArg_v22, y_fromDrawStringFunc, rect.y, offsetsVec2.y, offsetsVec2.x);*/
//
//		//logInfo("getGlyphOffset: offsetsVec2.x  before font offset adjustment: %.2f  offsetsVec2.y before font offset adjustment:  %.2f ", offsetsVec2.x, offsetsVec2.y );
//
//		//float x_final_offset = 0;
//		idFontManager::adjustStringOffsetForCurrentFont(offsetsVec2);
//
//	}
//	return offsetsVec2;
//}

 void idRenderModelGuiManager::setIceNadeCooldDownTextScale(idVec4& rectRef, float rectPrct) {
	// Calculate the original center of the rectangle
	float centerX = rectRef.x + rectRef.w / 2.0f;
	float centerY = rectRef.y + rectRef.h / 2.0f;

	// Scale the width and height
	rectRef.w *= rectPrct;
	rectRef.h *= rectPrct;

	// Recalculate the top-left corner (x, y) so that the center remains the same
	rectRef.x = centerX - rectRef.w / 2.0f;
	rectRef.y = centerY - rectRef.h / 2.0f;
}


 //? 2/11/24: modifying this as the getGlyphOffset is wrong but this will need adjustment
 void idRenderModelGuiManager::drawIceNadeCooldownTextWithOutline(idRenderModelGui* gui, idColor color, std::string textStr, idVec4 rect, float textScaleF, float outlineOffset, bool isDebug) {

	setIceNadeCooldDownTextScale(rect, textScaleF);
	adjustRectHeightToFitTheStr(rect, textStr.size());
	//rect.y -= rect.h;
	/*if (isDebug) {
		debugDrawColoredRect(idRenderModelGuiAdr, rect.x, rect.y, rect.w, rect.h, colorOrange);
		debugDrawString(idRenderModelGuiAdr, colorPurple, idFontManager::getCurrentFontAsStr().c_str(), getScreenWidth() / 2, getScreenHeight() / 2, 2);
		
	}*/
	float computedTextScale = idRenderModelGuiManager::getFontScaleFromWidthV3(rect, textStr.size());
	//logInfo("computedTextScale: %.2f", computedTextScale);
	float stringHeight = computedTextScale * getSmallCharHeight();

	//? 2/11/24: this is wrong but i need to compile !!!!
	idVec2 offsetsVec2;
	//auto offsetsVec2 = getGlyphOffset(rect, textStr.c_str(), computedTextScale);

	m_pidRenderModelGui_DrawString(gui, rect.x + offsetsVec2.x - outlineOffset, rect.y + offsetsVec2.y - outlineOffset, textStr.c_str(), (__int64)&colorBlack, 0, computedTextScale);

	m_pidRenderModelGui_DrawString(gui, rect.x + offsetsVec2.x, rect.y + offsetsVec2.y, textStr.c_str(), (__int64)&color, 0, computedTextScale);

}

 void idRenderModelGuiManager::drawIceNadeCooldownText(idRenderModelGui* gui, idColor color, std::string textStr, idVec4 rect, float textScaleF, bool isDebug) {
	setIceNadeCooldDownTextScale(rect, textScaleF);
	adjustRectHeightToFitTheStr(rect, textStr.size());
	
	/*if (isDebug) {
		debugDrawColoredRect(idRenderModelGuiAdr, rect.x, rect.y, rect.w, rect.h, colorOrange);
		debugDrawString(idRenderModelGuiAdr, colorPurple, idFontManager::getCurrentFontAsStr().c_str(), getScreenWidth() / 2, getScreenHeight() / 2, 2);
	
	}*/
	float computedTextScale = idRenderModelGuiManager::getFontScaleFromWidthV3(rect, textStr.size());
	//logInfo("computedTextScale: %.2f", computedTextScale);
	float stringHeight = computedTextScale * getSmallCharHeight();
	//? 2/11/24: this is wrong but i need to compile !!!!
	idVec2 offsetsVec2;
	//auto offsetsVec2 = getGlyphOffset(rect, textStr.c_str(), computedTextScale);

	m_pidRenderModelGui_DrawString(gui, rect.x + offsetsVec2.x, rect.y + offsetsVec2.y, textStr.c_str(), (__int64)&color, 0, computedTextScale);
 }



 void idRenderModelGuiManager::drawIceIcon(idRenderModelGui* gui, CustomIceNadeIconUIData& data) {
	
	 if (MemHelper::isBadReadPtr(gui)) {
		logErr("drawIceIcon: idRenderModelGuiAdrr is bad ptr: %p not drawing (how did that happen???)", gui);
		return;
	 }	

	drawDrawStretchPicSwfRect(gui, data.outerIconBounds, data.extraBorderMrt, data.extraBorderColor);
	drawDrawStretchPicSwfRect(gui, data.outerIconBounds, data.backgroundMrt, data.backgroundColor);
	drawDrawStretchPicSwfRect(gui, data.outerIconBounds, data.borderMrt, data.borderColor);
	drawDrawStretchPicSwfRect(gui, data.innerIconBounds, data.iconMrt, data.iconColor);
	if (data.isIceOnCoolDown) {
		drawIceNadeCooldownTextWithOutline(gui, colorLtGrey, data.cooldownText, idVec4(data.innerIconBounds), .8f, 1.0f, false);
	}	
 }


 void idRenderModelGuiManager::drawDrawStretchPicSwfRect(idRenderModelGui* gui, swfRect_t swfRect, idMaterial2* matPtr, const idColor& idColor, bool isMiroredX, bool isMiroredY) {

	//? commenting those and doing the check at the render of the ice icon so hopefully we have more time to render and fix the flickering of the icon
	/*if (MemHelper::isBadReadPtr((void*)idRenderModelGuiAdrr)) {
	logErr("drawDrawStretchPicSwfRectidRenderModelGuiAdrr bad ptr %p", (void*)idRenderModelGuiAdrr);
	return;
	}*/

	if (MemHelper::isBadReadPtr((void*)matPtr)) {
		logErr("drawDrawStretchPicSwfRect bad matr ptr %p", (void*)matPtr);
		return;
	}

	//DrawStretchPic(x, y, 0.0, w, h, 0.0, 0.0, 1.0, 1.0, whitemat);
	float s1 = 0.0;
	float t1 = 0.0;
	float s2 = 1.0;
	float t2 = 1.0;

	setColorNoCheck(gui, idColor);
	//setColor(idRenderModelGuiAdrr, idColor);

	if (isMiroredX) {
		s1 = 1.0;
		s2 = 0.0;
		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 1.0, 0.0, 0.0, 1.0, matPtr);
	}
	if (isMiroredY) {
		t1 = 1.0;
		t2 = 0.0;
		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 1.0, 1.0, 0.0, matPtr);
	}
	float x = swfRect.tl.x;
	float y = swfRect.tl.y;
	float width = swfRect.br.x - swfRect.tl.x;
	float height = swfRect.br.y - swfRect.tl.y;

	pidRenderModelGui_DrawStretchPic(gui, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
 }






 void idRenderModelGuiManager::debugDrawMaterialLibMatr(idRenderModelGui* gui, idMaterial2* matr, std::string materialNameStr) {
	 swfRect_t smallSwfRect(50, 50, 50, 50);
	 swfRect_t midSwfRect(200, 200, 100, 100);
	 swfRect_t BigSwfRect(400, 400, 200, 200);
	 swfRect_t Big2SwfRect(600, 400, 200, 400);

	 drawDrawStretchPicSwfRect(gui, smallSwfRect, matr, colorWhite);
	 drawDrawStretchPicSwfRect(gui, midSwfRect, matr, colorYellow);
	 drawDrawStretchPicSwfRect(gui, BigSwfRect, matr, colorGreen);
	 drawDrawStretchPicSwfRect(gui, Big2SwfRect, matr, colorPurple);

	 debugDrawString(gui, colorOrange, materialNameStr.c_str(), 50.0f, getScreenHeight() - 100, 1.0f);
	 //debugDrawString(idRenderModelGuiAdrr, colorOrange, materialNameStr.c_str(), 50.0f, getScreenHeigth(idRenderModelGuiAdrr) - 100, 1.0f);

 }







 void idRenderModelGuiManager::drawDrawStretchPicTest3(idRenderModelGui* gui, float x, float y, float width, float height, idMaterial2* matPtr, const idColor& idColor, bool isMiroredX, bool isMiroredY) {
	//static bool BasPtrThisError = false;
	static bool lastisBadPtrMaterial = false;
	static bool isFirstTime = true;

	//__int64 idRenderModelGuiAdrr = ObjectLocator::get__DebugHud_idRenderModelGuiAddr();
	//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idConsoleLocal_idRenderModelGuiAddr();
	//__int64 idRenderModelGuiAdrr = ObjectLocator::get_idSWF_idRenderModelGuiAddr();

	if (MemHelper::isBadReadPtr(gui)) {

		return;
	}

	if (MemHelper::isBadReadPtr(matPtr)) {
		logErr("drawDrawStretchPicTest3 bad matr ptr %p", matPtr);
		return;
	}

	//bool isBadPtrMaterial = MemHelper::isBadReadPtr((void*)matPtr);
	//if (isBadPtrMaterial != lastisBadPtrMaterial || isFirstTime) {
	//	logWarn("isBadPtrMaterial is now %d", isBadPtrMaterial);
	//	lastisBadPtrMaterial = isBadPtrMaterial;
	//	isFirstTime = false;
	//	/*	if(BasPtrMaterialError != true)
	//		BasPtrMaterialError = true;*/
	//		//return;
	//}

	//DrawStretchPic(x, y, 0.0, w, h, 0.0, 0.0, 1.0, 1.0, whitemat);
	float s1 = 0.0;
	float t1 = 0.0;
	float s2 = 1.0;
	float t2 = 1.0;

	setColor(gui, idColor);

	if (isMiroredX) {
		s1 = 1.0;
		s2 = 0.0;
		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 1.0, 0.0, 0.0, 1.0, matPtr);
	}
	if (isMiroredY) {
		t1 = 1.0;
		t2 = 0.0;
		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 1.0, 1.0, 0.0, matPtr);
	}
	pidRenderModelGui_DrawStretchPic(gui, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
}

//! this will make the string as big as it can be, meaning that if the string is 1 char length it will be 3 times bigger than a 3 chars lenght string, so the idea is that you always make sure that your string lenght is the same, meaning that if you do a count down from 60 to 0, from 10 to 0 the count will be 09, 08...
//! if you want to use this to print the health with 3 numbers, you use a space to make sure the text keep the same width, for ex text can be 200 or 'space'10, or 'space''scpace'0 

// void idRenderModelGuiManager::debugDrawStringInRect(__int64 idRenderModelGuiAdr, idColor color, std::string textStr, idVec4 rect) {
//
//	auto normalizedRect = idRenderModelGuiManager::debugGetNormalizedStringContainerRectV2(rect, textStr.size());
//
//	//! doing this so where we set our bl rect will be the start of the string, a bit like a cursor
//	normalizedRect.y -= normalizedRect.h;
//
//	debugDrawColoredRect(idRenderModelGuiAdr, normalizedRect.x, normalizedRect.y, normalizedRect.w, normalizedRect.h, colorOrange);
//
//	float computedTextScale = idRenderModelGuiManager::getFontScaleFromWidthV3(normalizedRect, textStr.size());
//
//	/*float arbitraryOffsetVal = .55f;*/
//	//float y_string_offsetTest = (computedTextScale * getSmallCharHeight() * (arbitraryOffsetVal));		
//
//	//float y_string_offsetTest = 0.0f; //? test value for testing !!!!!!!!
//
//
//	//float y_string_offsetTest = (computedTextScale * getSmallCharHeight() * (arbitraryOffsetVal)) / (float)textStr.size();
//
//	float debugSupposedlyStringHeight = computedTextScale * getSmallCharHeight();
//
//
//	//! this is code inspired from ida draw string func.
//	//!  this will indeed center the text on the y axis on the debug rect
//	auto Glyph_4CC330 = (unsigned __int8*)idFontManager::getGlyphDataAddr(textStr.c_str());
//	if (Glyph_4CC330) {
//		auto y_offset_v30 = (float)(char)Glyph_4CC330[2] * (float)(getUseScaleVal() * computedTextScale);
//		auto smallCharHeight_Plus_YArg_v22 = getSmallCharHeight() + normalizedRect.y;
//
//		float y_fromDrawStringFunc = smallCharHeight_Plus_YArg_v22 - y_offset_v30;
//
//		float x_final_offset = 0;
//		float y_final_offset = normalizedRect.y - y_fromDrawStringFunc;
//
//
//
//		//logInfo("debugDrawStringInRect: y_offset_v30: %.2f smallCharHeight_Plus_YArg_v22: %.2f y_fromDrawStringFunc: %.2f  normalizedRect.y: %.2f  y_final_offset: %.2f", y_offset_v30, smallCharHeight_Plus_YArg_v22, y_fromDrawStringFunc, normalizedRect.y, y_final_offset);
//
//		//logInfo("debugDrawStringInRect:  x_final_offset before font offset adjustment:  %.2f y_final_offset before font offset adjustment: %.2f and normalizedRect: %s", x_final_offset, y_final_offset, normalizedRect.getStrData().c_str());
//
//
//		auto currentFont = idFontManager::getCurrentFont();
//		switch (currentFont)
//		{
//		case idFontHash::unknown:
//			break;
//		case idFontHash::eternal88: //! not useful, don't use it
//			break;
//		case idFontHash::eternal90:
//			x_final_offset = normalizedRect.w * .12f;
//			y_final_offset = y_final_offset + std::abs(.3f * debugSupposedlyStringHeight);
//			break;
//		case idFontHash::ttSuper98:
//			x_final_offset = normalizedRect.w * .12f;
//			y_final_offset = y_final_offset + std::abs(.3f * debugSupposedlyStringHeight);
//			break;
//		case idFontHash::ttSuperA0:
//			x_final_offset = normalizedRect.w * .1f;
//			y_final_offset = y_final_offset + std::abs(.14f * debugSupposedlyStringHeight);
//			break;
//		case idFontHash::idTacticA8:
//			x_final_offset = normalizedRect.w * .145f;
//			y_final_offset = y_final_offset - std::abs(.26f * debugSupposedlyStringHeight);
//			break;
//		case idFontHash::euroStilB0:  //! not useful, don't use it
//			break;
//		case idFontHash::defaultCourrierF8:
//			x_final_offset = normalizedRect.w * .036f;
//			y_final_offset = y_final_offset + std::abs(.05f * debugSupposedlyStringHeight);
//			break;
//		case idFontHash::MAX_ID_FONTS:
//			break;
//		default:
//			break;
//		}
//		//logInfo("debugDrawStringInRect: curent font is %s y_final_offset is overidden to: %.2f ", idFontManager::getFontAsStr(currentFont).c_str(), y_final_offset);
//
//		//! font name:
//		debugDrawString(idRenderModelGuiAdr, colorPurple, idFontManager::getFontAsStr(currentFont).c_str(), 500, 500, 2);
//
//
//		//debugDrawColoredRect(idRenderModelGuiAdr, rect.x + 300, rect.y, normalizedRect.w, debugSupposedlyStringHeight, colorWhite);
//
//		//debugDrawColoredRect(idRenderModelGuiAdr, rect.x + 200, y_fromDrawStringFunc, normalizedRect.w, debugSupposedlyStringHeight, colorPurple);
//
//		/*logInfo("for textStr.size(): %zu computedTextScale: %.2f getSmallCharHeight(): %.2f arbitraryOffsetVal: %.2f y_string_offsetTest is: %.2f", textStr.size(), computedTextScale, getSmallCharHeight(), arbitraryOffsetVal, y_string_offsetTest);*/
//
//
//		logInfo("debugDrawStringInRect: curent font is %s x_final_offset: %.2f, y_final_offset: %.2f ", idFontManager::getFontAsStr(currentFont).c_str(), x_final_offset, y_final_offset);
//
//
//		//m_pidRenderModelGui_DrawString(idRenderModelGuiAdr, normalizedRect.x, normalizedRect.y + y_string_offsetTest, textStr.c_str(), (__int64)&color, 0, computedTextScale);
//		m_pidRenderModelGui_DrawString(idRenderModelGuiAdr, normalizedRect.x + x_final_offset, normalizedRect.y + y_final_offset, textStr.c_str(), (__int64)&color, 0, computedTextScale);
//
//	}
//}

 idVec4 idRenderModelGuiManager::debugGetNormalizedStringContainerRectV2(idVec4 rect, size_t charCountInString) {
	idVec4 normalizedRect;
	normalizedRect.update(rect.x, rect.y, rect.w, rect.h);

	float charRatio = getSmallCharHeight() / getSmallCharWidth();

	float widhtFor1char = rect.w / charCountInString;
	float normalizedRectHeight = widhtFor1char * (getSmallCharHeight() / getSmallCharWidth());
	logInfo("debugGetNormalizedStringContainerRectV2: charRatio: %.2f, current rect height: %.2f minRectHeight: %.2f", charRatio, rect.h, normalizedRectHeight);
	if (rect.h < normalizedRectHeight) {
		logInfo("debugGetNormalizedStringContainerRectV2: rect.h < normalizedRectHeight");
		//normalizedRect.h = normalizedRectHeight;
	}
	normalizedRect.h = normalizedRectHeight;
	return normalizedRect;
}

 float idRenderModelGuiManager::debugGetTextCentered_X(idVec4 rect, int strLettersCount) {

	//const float Eternal90_text_x_Offset_base = 3.6f; //? this val works ok for eternal font actually
	const float Eternal90_text_x_Offset_base = 23.5f; //? 
	const float ttSuper98_text_x_Offset_base = 3.7f; //! numeral 7segments.
	const float ttSuper98_text_y_Offset_base = -0.7f; //! numeral 7segments.

	//float desiredTextWidth = (float) (rect.w - (rect.w * 0.2));//! hardcoding this for now.
	//float fontScale = getFontScaleFromWidth(desiredTextWidth, strLettersCount);
	float fontScale = getFontScaleFromWidthV2(rect, strLettersCount);
	//float fontScale = getFontScaleFromWidth(desiredTextWidth - 2 * getSpacingCentered(2, desiredTextWidth), strLength);
	//float text_x_Offset = (Eternal90_text_x_Offset_base * fontScale) / strLettersCount;
	float text_x_Offset = Eternal90_text_x_Offset_base * (fontScale / strLettersCount);
	//float strPixelSize = fontScale * getSmallCharWidth() * ;
	//float strPixelSize = fontScale * getSmallCharWidth();
	//float text_x_Offset = (rect.w - strPixelSize) / 2;
	//logInfo("debugGetTextCentered_X: fontScale: %.2f, getSmallCharWidth(): %.2f, strPixelSize: %.2f", fontScale, getSmallCharWidth(), strPixelSize);
	logInfo("debugGetTextCentered_X: fontScale: %.2f, getSmallCharWidth(): %.2f, ", fontScale, getSmallCharWidth());

	return text_x_Offset;
}

 float idRenderModelGuiManager::debugGetStringLengthInPixel(idVec4 rect, size_t strLettersCount) {
	float fontScale = getFontScaleFromWidthV2(rect, strLettersCount);
	float strPixelSize = fontScale * getSmallCharWidth() * strLettersCount;
	return strPixelSize;
}

 float idRenderModelGuiManager::debugGetString_X(idVec4 rect, size_t strLettersCount) {
	const float Eternal90_text_x_Offset_base = 600.75f;

	float fontScale = getFontScaleFromWidthV2(rect, strLettersCount);
	float strPixelSize = fontScale * getSmallCharWidth() * strLettersCount;
	//return rect.x + ((rect.w - strPixelSize) /2);
	//float rectCenter = rect.x + rect.w / 2 ;
	float rectCenter = rect.x + rect.w / 2;
	logInfo("debugGetString_X strPixelSize: %.2f", strPixelSize);
	float result = rectCenter - (strPixelSize / 2) + (Eternal90_text_x_Offset_base / strPixelSize);
	return result;

	//return rect.x + ((rect.w - strPixelSize) /2) + (Eternal90_text_x_Offset_base * fontScale) / strLettersCount;
}


 //void idRenderModelGuiManager::drawAllNeededIconsTest(idRenderModelGui* gui) {
	// float x = 50.0f;
	// float y = 100.0f;
	// float width = 30;
	// float height = 30;
	// __int64 matPtr = 0;


	// setColor(gui, colorGreen);



	// x += 40.0f;

	// //logInfo("drawAllNeededIconsTest:  idRenderModelGuiAdrr: %p  MaterialLib::getHealthMtr(): %p ", (void*)idRenderModelGuiAdrr, (void*)MaterialLib::getHealthMtr());

	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getHealthMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getArmorMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getDashMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getBloodPunchMtr());
	// setColor(idRenderModelGuiAdrr, colorYellow);
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getCrucibleMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getHammerMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getFlameBelchMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getFluelAmmoMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getFragGrenadeMtr());
	// x += 50.0f;
	// drawDrawStretchPicTest5(idRenderModelGuiAdrr, x += 10, y += 10, 30, 30, MaterialLib::getIceGrenadeMtr());

 //}


 void idRenderModelGuiManager::debugDrawString(idRenderModelGui* gui, idColor color, const char* text, float x, float y, float scale) {
	 if (MemHelper::isBadReadPtr(gui)) {
		 logErr("debugDrawString: idRenderModelGuiAdr is bad ptr");
		 return;
	 }
	 m_pidRenderModelGui_DrawString(gui, x, y, text, (__int64)&color, 0, scale);
 }



 void idRenderModelGuiManager::drawDrawStretchPicTest5(idRenderModelGui* gui, float x, float y, float width, float height, idMaterial2* matPtr) {
	 //__int64 matPtr = MaterialLib::getRocketIconMtr();
	 //__int64 matPtr = MaterialLib::getWhite();
	 if (MemHelper::isBadReadPtr((void*)matPtr)) return;
	 pidRenderModelGui_DrawStretchPic(gui, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
 }

 void idRenderModelGuiManager::debugDrawColoredRect(idRenderModelGui* gui, float x, float y, float width, float height, idColor color) {
	 idMaterial2* matPtr = MaterialLib::getWhite();
	 setColor(gui, color);
	 pidRenderModelGui_DrawStretchPic(gui, x, y, 0.0, width, height, s1, t1, s2, t2, matPtr);
 }


 //? we can not use this cause we can't include the .h in the debugGui.h file...still not sure why.
 std::string idRenderModelGuiManager::getDbgStrForImgui() {
	 std::string result = "idRenderModelGuiManager DBG: \n";

	 result += "getScreenWidth: ";
	 result += std::to_string(idRenderModelGuiManager::getScreenWidth());
	 result += " getScreenHeight: ";
	 result += std::to_string(idRenderModelGuiManager::getScreenHeight());
	 result += "cvar width: ";
	 result += std::to_string(fastCvarManager::getWindowWidthInt());
	 result += " cvar height: ";
	 result += std::to_string(fastCvarManager::getWindowHeightInt());

	 return result;
 }


 //! Will drawn a string, scaling it horizontally to fill the rect width, however it will not scale it vertically.
//! A 1 char length str will be 3 times bigger than a 3 chars lenght string, so if you want to do a countdown make sure the char count is the same, meaning if count from 60 to 0, from 10 to 0 the count should be 09, 08...
//! if you want to use this to print the health with 3 numbers, you use a space to make sure the text keep the same width, for ex text can be 200 or 'space'10, or 'space''scpace'0 

 //void idRenderModelGuiManager::drawStringCenteredInBounds(__int64 idRenderModelGuiAdr, idColor color, std::string textStr, idVec4 rect, bool isDebug) {
	// adjustRectHeightToFitTheStr(rect, textStr.size());
	// //? doing this so where we set our bl rect will be the start of the string, a bit like a cursor BUT WE COULD MAKE IT LOOK BETTER
	// rect.y -= rect.h;
	// if (isDebug) {
	//	 debugDrawColoredRect(idRenderModelGuiAdr, rect.x, rect.y, rect.w, rect.h, colorOrange);
	//	 debugDrawString(idRenderModelGuiAdr, colorPurple, idFontManager::getCurrentFontAsStr().c_str(), getScreenWidth() / 2, getScreenHeight() / 2, 2);
	//	 //debugDrawString(idRenderModelGuiAdr, colorPurple, idFontManager::getCurrentFontAsStr().c_str(), getScreenWidth(idRenderModelGuiAdr) / 2, getScreenHeigth(idRenderModelGuiAdr) / 2, 2);
	// }
	// float computedTextScale = idRenderModelGuiManager::getFontScaleFromWidthV3(rect, textStr.size());
	// //logInfo("computedTextScale: %.2f", computedTextScale);
	// float stringHeight = computedTextScale * getSmallCharHeight();
	// auto offsetsVec2 = getGlyphOffset(rect, textStr.c_str(), computedTextScale);

	// //logInfo("drawStringCenteredInBounds: current font is %s offsetsVec2.x: %.2f, offsetsVec2.y: %.2f rect: %s", idFontManager::getCurrentFontAsStr().c_str(), offsetsVec2.x, offsetsVec2.y, rect.getStrData().c_str());

	// m_pidRenderModelGui_DrawString(idRenderModelGuiAdr, rect.x + offsetsVec2.x, rect.y + offsetsVec2.y, textStr.c_str(), (__int64)&color, 0, computedTextScale);
 //}



 void idRenderModelGuiManager::drawDrawStretchPicBounds(idRenderModelGui* gui, idVec4 bounds, idMaterial2* matPtr) {
	 //__int64 matPtr = MaterialLib::getRocketIconMtr();
	 //__int64 matPtr = MaterialLib::getWhite();
	 if (MemHelper::isBadReadPtr((void*)matPtr)) return;
	 pidRenderModelGui_DrawStretchPic(gui, bounds.x, bounds.y, 0.0, bounds.w, bounds.h, s1, t1, s2, t2, matPtr);
 }



 // void idRenderModelGuiManager::drawDrawStretchPicWhiteMatrSwfRect(__int64 idRenderModelGuiAdrr, swfRect_t swfRect, const idColor& idColor, bool isMiroredX, bool isMiroredY) {
//
//	if (!m_staticMaterialWhiteAddr) {
//		logErr("m_staticMaterialWhiteAddr is null can not draw ");
//		return;
//	}
//
//	//DrawStretchPic(x, y, 0.0, w, h, 0.0, 0.0, 1.0, 1.0, whitemat);
//	float s1 = 0.0;
//	float t1 = 0.0;
//	float s2 = 1.0;
//	float t2 = 1.0;
//
//	setColorNoCheck(idRenderModelGuiAdrr, idColor);
//	//setColor(idRenderModelGuiAdrr, idColor);
//
//	if (isMiroredX) {
//		s1 = 1.0;
//		s2 = 0.0;
//		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 1.0, 0.0, 0.0, 1.0, matPtr);
//	}
//	if (isMiroredY) {
//		t1 = 1.0;
//		t2 = 0.0;
//		//pidRenderModelGui_DrawStretchPic(m_idRenderModelGuiPtr, x, y, 0.0, width, height, 0.0, 1.0, 1.0, 0.0, matPtr);
//	}
//	float x = swfRect.tl.x;
//	float y = swfRect.tl.y;
//	float width = swfRect.br.x - swfRect.tl.x;
//	float height = swfRect.br.y - swfRect.tl.y;
//
//	pidRenderModelGui_DrawStretchPic(idRenderModelGuiAdrr, x, y, 0.0, width, height, s1, t1, s2, t2, m_staticMaterialWhiteAddr);
//}
