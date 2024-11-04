#include "idFontManager.h"



bool idFontManager::init(idDeclGlobalFontTable* idDeclGlobalFontTablePtr) {
	if (!idDeclGlobalFontTablePtr) {
		logErr("init: failed to acquire");
		return false;
	}
	m_idDeclGlobalFontTable = idDeclGlobalFontTablePtr;
	logInfo("init: m_idDeclGlobalFontTable set to %p ", m_idDeclGlobalFontTable);

	if (!cacheCourrierFont()) {
		return false;
	}	

	return true;
}


//x because courrier doens't have an actual var in idDeclGlobalFontTable but is just set as the debugGUIFont
//! because courier is not in the idDeclGlobalFontTable (aside when game starts and we dont modify the debugFont) we had to get here, other wise when using Xenos it will be a pain to get it back as we modify the debugFont ptr. 
bool idFontManager::cacheCourrierFont() {

	m_courrierFont = idResourceListManager::find_idFont("courier");
	if (!m_courrierFont) {
		logErr("cacheCourrierFont: FAILED");
		return false;
	}
	logInfo("cacheCourrierFont: m_courrierFont set to %p", m_courrierFont);
	return true;

	/*if (!idDeclGlobalFontTablePtr) {
		logErr("cacheCourrierFont: idDeclGlobalFontTablePtr is null, how did that happen?!");
		return false;
	}*/

	/*m_courrierFont = idDeclGlobalFontTablePtr->debugGUIFont;
	if (!m_courrierFont) {
		logErr("cacheCourrierFont: m_courrierFont, smth is wrong !!!!");
		return false;
	}
	else if (idFontManager::getFontName(idDeclGlobalFontTablePtr->debugGUIFont) != "courier") {
		logErr("cacheCourrierFont: debugGUIFont is not courrier, smth is wrong, this func may have been called more than once.");
		return false;
	}
	logInfo("m_courrierFont: set to %p", m_courrierFont);
	return true;*/
}


bool idFontManager::acquirreIdFontGetGlyphDataFuncPtr(__int64 fAdd) {
	if (MemHelper::isBadReadPtr((void*)fAdd)) {
		logErr("acquirreIdFontGetGlyphDataFuncPtr: fAdd is bad ptr: %p", (void*)fAdd);
		return false;
	}
	m_idFont_GetGlyphInfoFp = (idFont_GetGlyphInfo_t)fAdd;
	logInfo("acquirreIdFontGetGlyphDataFuncPtr: m_idFont_GetGlyphInfoFp is being set to : %p ", m_idFont_GetGlyphInfoFp);
	return true;
}



idFont* idFontManager::getCurConsoleFont() {

	if (m_idDeclGlobalFontTable && m_idDeclGlobalFontTable->debugGUIFont) {
		return m_idDeclGlobalFontTable->debugGUIFont;
	}
	logErr("getCurConsoleFont font is null");
	return nullptr;
}


void idFontManager::setdebugGUIFont(idFontHash fontEnum) {
	
	if (m_idDeclGlobalFontTable) {
		m_idDeclGlobalFontTable->debugGUIFont = idFontManager::getFont(fontEnum);
	}
	else {
		logErr("setdebugGUIFont: m_idDeclGlobalFontTable is null (?!)");
	}
	
}

 std::string idFontManager::getFontName(idFont* fontPtr) {

	 if (fontPtr) {
		 idResource* res = (idResource*)fontPtr;
		 return res->name.str;
	 }
	 logErr("getFontName fontPtr is null returning empty str");
	 return std::string();
 }


 idFont* idFontManager::getFont(idFontHash fontEnum) {

	 switch (fontEnum)
	 {
	 case idFontHash::courier:
		 return m_courrierFont;
		 break;
	 case idFontHash::eternal_bold:
		 return m_idDeclGlobalFontTable->eternal_bold;
		 break;
	 case idFontHash::eternal_reg:
		 return m_idDeclGlobalFontTable->eternal_reg;
		 break;
	 case idFontHash::eternal_num:
		 return m_idDeclGlobalFontTable->eternal_num;
		 break;
	 case idFontHash::tt_supermolot:
		 return m_idDeclGlobalFontTable->tt_supermolot;
		 break;
	 case idFontHash::idTactical:
		 return m_idDeclGlobalFontTable->idTactical;
		 break;
	 case idFontHash::eurostileconreg:
		 return m_idDeclGlobalFontTable->eurostileconreg;
		 break;	
	 default:
		 logErr("getFont failed to find font: %d", (int)fontEnum);
		 return  m_courrierFont;
		 break;
	 }
 }

 idFontHash idFontManager::getFontHash(idFont* fontPtr) {

	 if (fontPtr) {

		 return (idFontHash)fontPtr->fontNameHash;
	 }

	 return idFontHash::unknown;
 }



 void idFontManager::cacheFontAscii(idFont* fontPtr, char(&asciiCache)[128]) {
	 memset(asciiCache, -1, sizeof(asciiCache));  // Initialize all values to -1
	 for (int i = 0; i < fontPtr->fontInfo->numGlyphs; i++) {
		 if (fontPtr->fontInfo->charIndex[i] < 128) {
			 asciiCache[fontPtr->fontInfo->charIndex[i]] = i;
		 }
		 else {
			 break;  // Stop when non-ASCII characters are encountered
		 }
	 }
 }

 //! an adaptation of the D3 methods
 void idFontManager::cacheAsciiForAllFonts() {

	 int counter = 0;

	 logInfo("cacheAsciiForAllFonts: attempting to cache all fonts...");

	 std::vector<idFontHash> fontHashes = {
		idFontHash::courier, idFontHash::eternal_bold, idFontHash::eternal_reg,
		idFontHash::eternal_num, idFontHash::tt_supermolot,
		idFontHash::idTactical, idFontHash::eurostileconreg
	 };

	 for (idFontHash fontHash : fontHashes) {
		 idFont* fontPtr = getFont(fontHash); // Get the font pointer for the given ID
		 if (!fontPtr) {
			 logErr("cacheAsciiForAllFonts: Failed to get font with Hash: %u mod should not be running !!!!", (uint32_t)fontHash);
			 return;
		 }

		 switch (fontHash)
		 {
		 case idFontHash::courier:
			 if (m_ascii_courier[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_courier);
				 counter++;
			 }
			 break;
		 case idFontHash::eternal_bold:
			 if (m_ascii_eternal_bold[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_eternal_bold);
				 counter++;
			 }
			 break;
		 case idFontHash::eternal_reg:
			 if (m_ascii_eternal_reg[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_eternal_reg);
				 counter++;
			 }
			 break;
		 case idFontHash::eternal_num:
			 if (m_ascii_eternal_num[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_eternal_num);
				 counter++;
			 }
			 break;
		 case idFontHash::tt_supermolot:
			 if (m_ascii_tt_supermolot[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_tt_supermolot);
				 counter++;
			 }
			 break;
		 case idFontHash::idTactical:
			 if (m_ascii_idTactical[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_idTactical);
				 counter++;
			 }
			 break;
		 case idFontHash::eurostileconreg:
			 if (m_ascii_eurostileconreg[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_eurostileconreg);
				 counter++;
			 }
			 break;		
		 default:
			 logErr("cacheAsciiForAllFonts: default case...How did that happen??!! fontHash: %u Mod should not be running", (uint32_t)fontHash);
			 if (m_ascii_courier[0] == -1) {
				 cacheFontAscii(fontPtr, m_ascii_courier);
				 counter++;
			 }
			 return; //? !!!
			 break;
		 }
	 }

	 m_isAsciiCachedForAllFonts = true;	
	 logInfo("cacheAsciiForAllFonts: cached %d fonts (assuming this is all the fonts to cache)", counter);
 }



 char* idFontManager::getAsciiCacheForFontId(idFontHash fontHash) {

	 switch (fontHash)
	 {
	 case idFontHash::courier:
		 return m_ascii_courier;		 
	 case idFontHash::eternal_bold:
		 return m_ascii_eternal_bold;
	 case idFontHash::eternal_reg:
		 return m_ascii_eternal_reg;
	 case idFontHash::eternal_num:
		 return m_ascii_eternal_num;
	 case idFontHash::tt_supermolot:
		 return m_ascii_tt_supermolot;
	 case idFontHash::idTactical:
		 return m_ascii_idTactical;
	 case idFontHash::eurostileconreg:
		 return m_ascii_eurostileconreg;	
	 default:
		 logErr("getAsciiCacheForFontId: unknown fontHash: %u", (uint32_t)fontHash);
		 return nullptr;
		 break;
	 }	
 }


 glyphInfo_t* idFontManager::getGlyphInfo(idFont* fontPtr, unsigned int charCode) {

	 if (!fontPtr) {
		 return nullptr;
	 }
	 if (!m_idFont_GetGlyphInfoFp) {
		 return nullptr;
	 }

	 return m_idFont_GetGlyphInfoFp(fontPtr, charCode);

 }

 glyphInfo_t* idFontManager::getGlyphInfoForCurConsoleFont(unsigned int charCode) {

	 idFont* curFont = getCurConsoleFont();
	 if (!curFont) {
		 return nullptr;
	 }

	 return getGlyphInfo(curFont, charCode);
 }



 //! from Doom3 but changed a bit
 int idFontManager::GetGlyphIndex(idFont* idFontPtr, unsigned int idx) {

	 if (!m_isAsciiCachedForAllFonts) {
		 idFontManager::cacheAsciiForAllFonts();
	 }

	 idFontHash fontHash = getFontHash(idFontPtr);
	 if (fontHash == idFontHash::unknown) {
		 logErr("GetGlyphIndex: unknow font or font is null, can not get glyph index");
		 return 0;
	 }

	 // Retrieve the ASCII cache for the specific font
	 char* asciiCache = getAsciiCacheForFontId(fontHash);

	 if (asciiCache && idx < 128) {
		 return asciiCache[idx];  // Use the cache for the specific font
	 }

	 /*if (idx < 128) {
		 return m_ascii[idx];

	 }*/
	 if (idFontPtr->fontInfo->numGlyphs == 0) {
		 return -1;
	 }
	 if (idFontPtr->fontInfo->charIndex == NULL) {
		 return idx;
	 }
	 int len = idFontPtr->fontInfo->numGlyphs;
	 int mid = idFontPtr->fontInfo->numGlyphs;
	 int offset = 0;
	 while (mid > 0) {
		 mid = len >> 1;
		 if (idFontPtr->fontInfo->charIndex[offset + mid] <= idx) {
			 offset += mid;
		 }
		 len -= mid;
	 }
	 return (idFontPtr->fontInfo->charIndex[offset] == idx) ? offset : -1;

 }


 unsigned int idFontManager::getFontHeightForLetter_A(idFont* fontPtr)
 {
	 if (!fontPtr) {
		 logErr("getFontHeightForLetter_A: font is null");
		 return 1;
	 }

	 glyphInfo_t* glyphInfo = getGlyphInfo(fontPtr, 65);
	 if (!glyphInfo) {
		 logErr("failed to find glyphInfo for letter A");
		 return 1;
	 }

	 return glyphInfo->height;
 }

 unsigned int idFontManager::getFontHeightForChar(idFont* fontPtr, unsigned int charCode)
 {
	 if (!fontPtr) {
		 logErr("getFontHeightForChar: font is null");
		 return 1;
	 }

	 glyphInfo_t* glyphInfo = getGlyphInfo(fontPtr, charCode);
	 if (!glyphInfo) {
		 logErr("getFontHeightForChar: font is null, charCode: '%c' (hex: %#x)", charCode, charCode);
		 return 1;
	 }

	 return glyphInfo->top;
	 //return glyphInfo->height;
 }



 //! from Doom3
 float idFontManager::GetGlyphWidth(idFont* fontPtr, float scale, unsigned int idx) {

	 if (!fontPtr) {
		 logErr("GetGlyphWidth: fontPtr is null");
		 return 0.0f;
	 }
	 if (fontPtr->alias != NULL) {
		 return GetGlyphWidth(fontPtr->alias, scale, idx);
	 }
	 if (fontPtr->fontInfo != NULL) {
		 int i = GetGlyphIndex(fontPtr, idx);
		 const int asterisk = 42;
		 if (i == -1 && idx != asterisk) {
			 i = GetGlyphIndex(fontPtr, asterisk);
		 }
		 if (i >= 0) {
			 return scale * fontPtr->fontInfo->glyphData[i].xSkip;
		 }
	 }
	 logWarn("GetGlyphWidth: returning 0.0f");
	 return 0.0f;
 }

 //! 3/11/24 experimenting...
 float idFontManager::GetGlyphLeft(idFont* fontPtr, float scale, unsigned int idx) {

	 if (!fontPtr) {
		 logErr("GetGlyphLeft: fontPtr is null");
		 return 0.0f;
	 }
	 if (fontPtr->alias != NULL) {
		 return GetGlyphLeft(fontPtr->alias, scale, idx);
	 }
	 if (fontPtr->fontInfo != NULL) {
		 int i = GetGlyphIndex(fontPtr, idx);
		 const int asterisk = 42;
		 if (i == -1 && idx != asterisk) {
			 i = GetGlyphIndex(fontPtr, asterisk);
		 }
		 if (i >= 0) {
			 return scale * fontPtr->fontInfo->glyphData[i].left;
		 }
	 }
	 logWarn("GetGlyphLeft: returning 0.0f");
	 return 0.0f;
 }


 //! from Doom3 code
 void idFontManager::GetScaledGlyph(idFont* fontPtr, float scale, unsigned int idx, scaledGlyphInfo_t& glyphInfo) {

	 if (!fontPtr) {
		 logErr("GetScaledGlyph: fontPtr is null");
		 return;
	 }

	 if (fontPtr->alias != NULL) {
		 //return curFontPtr.GetScaledGlyph(scale, idx, glyphInfo);
		 return GetScaledGlyph(fontPtr->alias, scale, idx, glyphInfo);
	 }
	 if (fontPtr->fontInfo != NULL) {
		 int i = GetGlyphIndex(fontPtr, idx);
		 const int asterisk = 42;
		 if (i == -1 && idx != asterisk) {
			 i = GetGlyphIndex(fontPtr, asterisk);
		 }
		 if (i >= 0) {
			 //float invMaterialWidth = 1.0f / fontPtr->fontInfo->material->GetImageWidth();
			 float invMaterialWidth = 1.0f / (float)fontPtr->fontInfo->imageWidth;
			 //float invMaterialHeight = 1.0f / fontInfo->material->GetImageHeight();
			 float invMaterialHeight = 1.0f / (float)fontPtr->fontInfo->imageHeight;
			 glyphInfo_t& gi = fontPtr->fontInfo->glyphData[i];
			 glyphInfo.xSkip = scale * gi.xSkip;
			 glyphInfo.top = scale * gi.top;
			 glyphInfo.left = scale * gi.left;
			 glyphInfo.width = scale * gi.width;
			 glyphInfo.height = scale * gi.height;
			 glyphInfo.s1 = (gi.s - 0.5f) * invMaterialWidth;
			 glyphInfo.t1 = (gi.t - 0.5f) * invMaterialHeight;
			 glyphInfo.s2 = (gi.s + gi.width + 0.5f) * invMaterialWidth;
			 glyphInfo.t2 = (gi.t + gi.height + 0.5f) * invMaterialHeight;
			 glyphInfo.material = fontPtr->fontInfo->material;
			 return;
		 }
	 }
	 memset(&glyphInfo, 0, sizeof(glyphInfo));
 }

 //! from D3: idStr::IsColor
 bool idFontManager::IsColor(const char* s) {
	 return (s[0] == C_COLOR_ESCAPE && s[1] != '\0' && s[1] != ' ');
 }


 //! from Doom3: idDeviceContext::TextWidth
 int idFontManager::getTextWidth(idFont* idFontPtr, const char* text, float scale, int limit) {

	 if (!idFontPtr) {
		 logErr("getTextWidth: font is null");
		 return 0;
	 }

	 if (!text) {
		 return 0;
	 }

	 int i;
	 float width = 0;
	 if (limit > 0) {
		 for (i = 0; text[i] != '\0' && i < limit; i++) {
			 if (IsColor(text + i)) { //! k: related to setting colors in console with ^
				 i++;
			 }
			 else {
				 width += GetGlyphWidth(idFontPtr, scale, ((const unsigned char*)text)[i]);
			 }
		 }
	 }
	 else {
		 for (i = 0; text[i] != '\0'; i++) {
			 if (IsColor(text + i)) {
				 i++;
			 }
			 else {
				 width += GetGlyphWidth(idFontPtr, scale, ((const unsigned char*)text)[i]);
			 }
		 }
	 }
	 return static_cast<int>(width);
 }

 


 //! based on letter 'A' height
 float idFontManager::getTextScaleForRectHeight(float rectHeight) {
	 float fontHeightForA = (float)getFontHeightForLetter_A(getCurConsoleFont());
	 return rectHeight / fontHeightForA;
 }

 float idFontManager::getTextScaleForRectHeight(float rectHeight, unsigned int charCode) {
	 float charHeight = (float)getFontHeightForChar(getCurConsoleFont(), charCode);
	 return rectHeight / charHeight;
 }







 void idFontManager::debugLogFonts()
 {
	 if (!m_idDeclGlobalFontTable) {
		 logErr("debugLogFonts: m_idDeclGlobalFontTable is null");
		 return;
	 }	
	 
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_courrierFont).c_str(), m_courrierFont->fontNameHash, m_courrierFont->fontNameHash, m_courrierFont, (uint32_t)m_courrierFont->fontNameHash == (uint32_t)idFontHash::courier);
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_idDeclGlobalFontTable->eternal_bold).c_str(), m_idDeclGlobalFontTable->eternal_bold->fontNameHash, m_idDeclGlobalFontTable->eternal_bold->fontNameHash, m_idDeclGlobalFontTable->eternal_bold, (uint32_t)m_idDeclGlobalFontTable->eternal_bold->fontNameHash == (uint32_t)idFontHash::eternal_bold);
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_idDeclGlobalFontTable->eternal_reg).c_str(), m_idDeclGlobalFontTable->eternal_reg->fontNameHash, m_idDeclGlobalFontTable->eternal_reg->fontNameHash, m_idDeclGlobalFontTable->eternal_reg, (uint32_t)m_idDeclGlobalFontTable->eternal_reg->fontNameHash == (uint32_t)idFontHash::eternal_reg);
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_idDeclGlobalFontTable->eternal_num).c_str(), m_idDeclGlobalFontTable->eternal_num->fontNameHash, m_idDeclGlobalFontTable->eternal_num->fontNameHash, m_idDeclGlobalFontTable->eternal_num, (uint32_t)m_idDeclGlobalFontTable->eternal_num->fontNameHash == (uint32_t)idFontHash::eternal_num);
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_idDeclGlobalFontTable->tt_supermolot).c_str(), m_idDeclGlobalFontTable->tt_supermolot->fontNameHash, m_idDeclGlobalFontTable->tt_supermolot->fontNameHash, m_idDeclGlobalFontTable->tt_supermolot, (uint32_t)m_idDeclGlobalFontTable->tt_supermolot->fontNameHash == (uint32_t)idFontHash::tt_supermolot);
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_idDeclGlobalFontTable->idTactical).c_str(), m_idDeclGlobalFontTable->idTactical->fontNameHash, m_idDeclGlobalFontTable->idTactical->fontNameHash, m_idDeclGlobalFontTable->idTactical, (uint32_t)m_idDeclGlobalFontTable->idTactical->fontNameHash == (uint32_t)idFontHash::idTactical);
	 logInfo("font: %s hash: %d (hex: 0x%X enum val: addr: %p isHashValid: %d", getFontName(m_idDeclGlobalFontTable->eurostileconreg).c_str(), m_idDeclGlobalFontTable->eurostileconreg->fontNameHash, m_idDeclGlobalFontTable->eurostileconreg->fontNameHash, m_idDeclGlobalFontTable->eurostileconreg, (uint32_t)m_idDeclGlobalFontTable->eurostileconreg->fontNameHash == (uint32_t)idFontHash::eurostileconreg);
 }














 //? doesn't work, the result is way too short
 //x tryint this so we may get a bit more accurate string width as atm, the value we get is slightly higher than the actual thing
 //int idFontManager::getTextWidth_V2(idFont* idFontPtr, const char* text, float scale, int limit) {

	// if (!idFontPtr) {
	//	 logErr("getTextWidth: font is null");
	//	 return 0;
	// }

	// if (!text) {
	//	 return 0;
	// }

	// int i;
	// float width = 0;
	// if (limit > 0) {
	//	 for (i = 0; text[i] != '\0' && i < limit; i++) {
	//		 if (IsColor(text + i)) { //! k: related to setting colors in console with ^
	//			 i++;
	//		 }
	//		 else {
	//			 width += GetGlyphWidth(idFontPtr, scale, ((const unsigned char*)text)[i]);
	//		 }
	//	 }
	// }
	// else {
	//	 for (i = 0; text[i] != '\0'; i++) {
	//		 if (IsColor(text + i)) {
	//			 i++;
	//		 }
	//		 else {
	//			 width += (GetGlyphWidth(idFontPtr, scale, ((const unsigned char*)text)[i]) - GetGlyphLeft(idFontPtr, scale, ((const unsigned char*)text)[i]));
	//		 }
	//	 }
	// }
	// return static_cast<int>(width);
 //}





/// ORIGINAL CODE:


//? note: setting font from main: init: causes an error: log : ERR | set : m_monoSpaceFontAddr is bad ptr can not set font but  we don't need it as we just use the default font anyway, until may be someday we decide to implement stats...

// void idFontManager::init() {
//
//	m_monoSpaceFontAddr = TypeInfoManager::getGlobalFontTable();
//	idFontHash defaultFont = idFontHash::defaultCourrierF8;
//	std::string defaultFontStr = getFontAsStr(defaultFont);
//	logInfo("init: setting Font to: %s", defaultFontStr.c_str());
//	set(defaultFont);
//}
//
//
//bool idFontManager::init(idDeclGlobalFontTable* idDeclGlobalFontTablePtr) {
//	if (!idDeclGlobalFontTablePtr) {
//		logErr("init: failed to acquire");
//		return false;
//	}
//	m_idDeclGlobalFontTable = idDeclGlobalFontTablePtr;
//	logInfo("init: m_idDeclGlobalFontTable set to %p ", m_idDeclGlobalFontTable);
//
//	if (!cacheCourrierFont(m_idDeclGlobalFontTable)) {
//		return false;
//	}
//
//	return true;
//}
//
//
////! because courrier doens't have an actual var in idDeclGlobalFontTable but is just set as the debugGUIFont
//bool idFontManager::cacheCourrierFont(idDeclGlobalFontTable* idDeclGlobalFontTablePtr) {
//
//	if (!idDeclGlobalFontTablePtr) {
//		logErr("cacheCourrierFont: idDeclGlobalFontTablePtr is null, how did that happen?!");
//		return false;
//	}
//
//	m_courrierFont = idDeclGlobalFontTablePtr->debugGUIFont;
//	if (!m_courrierFont) {
//		logErr("cacheCourrierFont: m_courrierFont, smth is wrong !!!!");
//		return false;
//	}
//	else if (idFontManager::getFontName(idDeclGlobalFontTablePtr->debugGUIFont) != "courier") {
//		logErr("cacheCourrierFont: debugGUIFont is not courrier, smth is wrong, this func may have been called more than once.");
//		return false;
//	}
//	logInfo("m_courrierFont: set to %p", m_courrierFont);
//	return true;
//}
//
//
//bool idFontManager::acquirreSetMonospaceFondOffsetAddr(__int64 offsetAddr) {
//	logDebug("acquirreSetMonospaceFondOffsetAddr");
//	if (MemHelper::isBadReadPtr((void*)offsetAddr)) {
//		logErr("acquirreSetMonospaceFondOffsetAddr: bad ptr for offsetAddr: %p", (void*)offsetAddr);
//		return false;
//	}
//	m_monoSpaceFont_FontOffsetAddr = offsetAddr;
//	logInfo("acquirreSetMonospaceFondOffsetAddr: m_monoSpaceFont_FontOffsetAddr is being set to : %p ", (void*)m_monoSpaceFont_FontOffsetAddr);
//	return true;
//}
//
//bool idFontManager::acquirreDrawStringFontOffsetAddr(__int64 fontOffsetAddr) {
//	logDebug("acquirreDrawStringFontOffsetAddr");
//	if (MemHelper::isBadReadPtr((void*)fontOffsetAddr)) {
//		logErr("acquirreDrawStringFontOffsetAddr: bad ptr for offsetAddr: %p", (void*)fontOffsetAddr);
//		return false;
//	}
//	m_drawStringFontOffsetAddr = fontOffsetAddr;
//	logInfo("acquirreDrawStringFontOffsetAddr: m_drawStringFontOffsetAddr is being set to : %p ", (void*)m_drawStringFontOffsetAddr);
//	return true;
//}
//
// bool idFontManager::acquirreConsoleHistoryFontOffsetAddr(__int64 offsetAddr) {
//	logDebug("acquirreConsoleHistoryFontOffsetAddr");
//	if (MemHelper::isBadReadPtr((void*)offsetAddr)) {
//		logErr("acquirreConsoleHistoryFontOffsetAddr: bad ptr for offsetAddr: %p", (void*)offsetAddr);
//		return false;
//	}
//	m_consoleHistoryFontOffsetAddr = offsetAddr;
//	logInfo("acquirreConsoleHistoryFontOffsetAddr: m_consoleHistoryFontOffsetAddr is being set to : %p ", (void*)m_consoleHistoryFontOffsetAddr);
//	return true;
//}
//
// bool idFontManager::acquirreIdFontGetGlyphDataFuncAddr(__int64 fAdd) {
//	logDebug("acquirreIdFontGetGlyphDataFuncAddr");
//	if (MemHelper::isBadReadPtr((void*)fAdd)) {
//		logErr("acquirreIdFontGetGlyphDataFuncAddr: fAdd is bad ptr: %p", (void*)fAdd);
//		return false;
//	}
//	m_idFont_GetGlyphInfoFp = (idFont_GetGlyphInfo_t)fAdd;
//	//m_idFont_getGlyphInfo_tFp = fAdd;
//	logInfo("acquirreIdFontGetGlyphDataFuncAddr: m_idFont_GetGlyphInfoFp is being set to : %p ", m_idFont_GetGlyphInfoFp);
//	return true;
//}
//
// std::string idFontManager::getCurrentFontAsStr() {
//	return getFontAsStr(m_idFontEnum);
//}
//
// std::string idFontManager::getFontAsStr(idFontHash idFontHash) {
//	switch (idFontHash)
//	{
//	case idFontHash::unknown:
//		return "unknown";
//		break;
//	case idFontHash::eternal88:
//		return "eternal88";
//	case idFontHash::eternal90:
//		return "eternal90";
//	case idFontHash::ttSuper98:
//		return "ttSuper98";
//	case idFontHash::ttSuperA0:
//		return "ttSuperA0";
//	case idFontHash::idTacticA8:
//		return "idTacticA8";
//	case idFontHash::euroStilB0:
//		return "euroStilB0";
//	case idFontHash::defaultCourrierF8:
//		return "defaultCourrierF8";
//	case idFontHash::MAX_ID_FONTS:
//		return "MAX_ID_FONTS";
//	default:
//		return "getFontAsStr default case, how did that happen?!";
//	}
//}
//
// int idFontManager::getcurrentFontAddrOffset() {
//	switch (m_idFontEnum)
//	{
//	case idFontHash::eternal88:
//		return 0x88;
//		break;
//	case idFontHash::eternal90:
//		return 0x90;
//		break;
//	case idFontHash::ttSuper98:
//		return 0x98;
//		break;
//	case idFontHash::ttSuperA0:
//		return 0xA0;
//		break;
//	case idFontHash::idTacticA8:
//		return 0xA8;
//		break;
//	case idFontHash::euroStilB0:
//		return 0xB0;
//		break;
//	case idFontHash::defaultCourrierF8:
//		return 0xF8;
//		break;
//	default:
//		logErr("getFontAddrOffset failed to find offset for font: %s returning 0", getFontAsStr(m_idFontEnum).c_str());
//		return 0;
//		break;
//	}
//}
//
////? i'm fed up of this  bs. Will not use text inside boxes to indicate countdown will use self maderect bars instead, will only use text for the health, armor and ammo and that is  to align it of the y axis for lower value so . I'm not even sure why the  i'm doing all this anyway, way too much work for what???!!!!!
//
// void idFontManager::adjustStringOffsetForCurrentFont(idVec2& currentStringXY) {
//
//	switch (m_idFontEnum)
//	{
//	case idFontHash::unknown:
//		break;
//	case idFontHash::eternal88:
//		break;
//	case idFontHash::eternal90:
//		currentStringXY.x = currentStringXY.x * .18f;
//		currentStringXY.y += std::abs(.57f * currentStringXY.y);
//		return;
//	case idFontHash::ttSuper98:
//		currentStringXY.x = currentStringXY.x * .18f;
//		currentStringXY.y += std::abs(.57f * currentStringXY.y);
//		return;
//	case idFontHash::ttSuperA0:
//		currentStringXY.x = currentStringXY.x * .155f;
//		currentStringXY.y += std::abs(.145f * currentStringXY.y);
//		return;
//	case idFontHash::idTacticA8:
//		currentStringXY.x = currentStringXY.x * .21f;
//		currentStringXY.y -= std::abs(.26f * currentStringXY.y);
//		return;
//	case idFontHash::euroStilB0:  //! not useful, don't use it
//		break;
//	case idFontHash::defaultCourrierF8:
//		currentStringXY.x = currentStringXY.x * .036f;
//		currentStringXY.y += std::abs(.05f * currentStringXY.y);
//		return;
//	case idFontHash::MAX_ID_FONTS:
//		break;
//	}
//	logWarn("adjustStringOffsetForCurrentFont did not find any Vec2 offset for font: %s not modifying Vec2", getFontAsStr(m_idFontEnum).c_str());
//
//}
//
// __int64 idFontManager::getCurrentFontAddr() {
//	if (!m_idFont_getGlyphInfo_tFp) {
//		logErr("getCurrentFontAddr: m_idFont_getGlyphInfo_tFp is null can not get data");
//		return 0;
//	}
//
//	if (!m_monoSpaceFontAddr) {
//		logErr("getCurrentFontAddr: m_monoSpaceFontAddr is null can not get data");
//		return 0;
//	}
//
//	auto fontOffset = getcurrentFontAddrOffset();
//	if (!fontOffset) {
//		logErr("getCurrentFontAddr: failed to find current font offset returning 0");
//		return 0;
//	}
//
//	return m_monoSpaceFontAddr + fontOffset;
//}
//
// __int64 idFontManager::getGlyphDataAddr(const char* str) {
//
//
//	auto currentFontAddr = getCurrentFontAddr();
//	if (currentFontAddr) {
//		auto getGlyphFunc = reinterpret_cast<idFont_getGlyphData>(m_idFont_getGlyphInfo_tFp);
//		return getGlyphFunc(currentFontAddr, (__int64)str);
//	}
//	logErr("getGlyphDataAddr currentFontAddr is null, returning 0");
//	return 0;
//
//}
//
//
// std::string idFontManager::getFontName(idFont* fontPtr) {
//
//	 if (fontPtr) {
//		 idResource* res = (idResource*)fontPtr;
//		 return res->name.str;
//	 }
//	 logErr("getFontName fontPtr is null");
//	 return std::string();
// }
// 
//
// //! using ptr change instead of game mem patching. update it works!
// //todo maybe this should be triggered in a hook to prevent race conditions
// void idFontManager::setConsoleFont(idFontHash idFontHash) {
//	
//	 if (!m_courrierFont) {
//		 cacheCourrierFont(m_idDeclGlobalFontTable);		 
//	 }
//
//	 if (idFontHash == idFontHash::eternal88) {
//		 m_idDeclGlobalFontTable->debugGUIFont = m_idDeclGlobalFontTable->eternal_bold;
//	 }
//	 else if ((idFontHash == idFontHash::eternal90)) {
//		 m_idDeclGlobalFontTable->debugGUIFont = m_idDeclGlobalFontTable->eternal_reg;
//	 }
//	 else if ((idFontHash == idFontHash::ttSuper98)) {
//		 m_idDeclGlobalFontTable->debugGUIFont = m_idDeclGlobalFontTable->eternal_num;
//	 }
//	 else if ((idFontHash == idFontHash::ttSuperA0)) {
//		 m_idDeclGlobalFontTable->debugGUIFont = m_idDeclGlobalFontTable->tt_supermolot;
//	 }
//	 else if ((idFontHash == idFontHash::idTacticA8)) {
//		 m_idDeclGlobalFontTable->debugGUIFont = m_idDeclGlobalFontTable->idTactical;
//	 }
//	 else if ((idFontHash == idFontHash::euroStilB0)) {
//		 m_idDeclGlobalFontTable->debugGUIFont = m_idDeclGlobalFontTable->eurostileconreg;
//	 }
//	 else {
//		 logWarn("setConsoleFont failed to set font: %d", (int)idFontHash);
//	 }
// }
//
//
//
//
// fontInfo_t* idFontManager::getFontInfoPtr() {
//	logInfo("getFontInfoPtr called");
//	auto currentFontAddr = getCurrentFontAddr();
//	if (!currentFontAddr) {
//		logErr("getFontInfoPtr, failed to find currentFontAddr");
//		return 0;
//	}
//	idFont* currentFontPtr = (idFont*)*(__int64*)currentFontAddr;
//	if (MemHelper::isBadReadPtr(currentFontPtr)) {
//		logErr("getFontInfoPtr, currentFontPtr is bad ptr: %p", currentFontPtr);
//		return 0;
//	}
//	return currentFontPtr->fontInfo;
// }
//
//
////? this could crash as we don't check for bad ptr but as long as we are in debug mode it's ok.
// void idFontManager::printcurrentFontData() {
//	logInfo("printcurrentFontData called");
//	auto currentFontAddr = getCurrentFontAddr();
//	if (!currentFontAddr) {
//		logErr("printcurrentFontData, failed to find currentFontAddr");
//		return;
//	}
//	idFont* currentFontPtr = (idFont*)*(__int64*)currentFontAddr;
//	if (MemHelper::isBadReadPtr(currentFontPtr)) {
//		logErr("printcurrentFontData, currentFontPtr is bad ptr: %p", currentFontPtr);
//		return;
//	}
//	logInfo("Current font: %s, currentFontPtr->fontInfo->ascender: %d,  currentFontPtr->fontInfo->descender: %d", getCurrentFontAsStr().c_str(), currentFontPtr->fontInfo->ascender, currentFontPtr->fontInfo->descender);
//
//	glyphInfo_t* glyphInfo = currentFontPtr->fontInfo->glyphData;
//	if (MemHelper::isBadReadPtr(glyphInfo)) {
//		logErr("printcurrentFontData, glyphInfo is bad ptr: %p and currentFontPtr: %p  currentFontPtr->fontInfo: %p", glyphInfo, currentFontPtr, currentFontPtr->fontInfo);
//		return;
//	}
//	logInfo("Current font: %s, glyphInfo: glyphInfo->left: %d glyphInfo->top: %d glyphInfo->width: %u glyphInfo->height: %u glyphInfo->s: %u glyphInfo->xSkip: %u glyphInfo->t: %u ", getCurrentFontAsStr().c_str(), glyphInfo->left, glyphInfo->top, glyphInfo->width, glyphInfo->height, glyphInfo->s, glyphInfo->xSkip, glyphInfo->t);
//}
//
//
//
//
// // idFontHash idFontManager::getCurrentFont() {
// //	if (m_idFontEnum == idFontHash::unknown) {
// //		set(idFontHash::defaultCourrierF8);
// //		logWarn("getCurrentFont: idFont is unknown, attempting to set it to defaultCourrierF8");
// //	}
// //	return m_idFontEnum;
// //}
//
//
// //? calling this function too often will degrade performance. update not using this anymore, chaging ptrs instead with setConsoleFont
// /*void idFontManager::set(idFontHash idFontHash) {
//	std::vector<unsigned char> fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;
//
//	if (MemHelper::isBadReadPtr((void*)m_monoSpaceFontAddr)) {
//		logErr("set: m_monoSpaceFontAddr is bad ptr can not set font");
//		return;
//	}
//	m_idFontEnum = idFontHash;
//	logInfo("set: m_monoSpaceFontAddr %p (font enum: %x font name: %s)", (void*)m_monoSpaceFontAddr, m_idFontEnum, getFontAsStr(m_idFontEnum).c_str());
//
//	switch (m_idFontEnum)
//	{
//	case idFontHash::eternal88:
//		fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;
//		break;
//	case idFontHash::eternal90:
//		fontOffsetPatch = eternalFontOffsetPatch_90;
//		break;
//	case idFontHash::ttSuper98:
//		fontOffsetPatch = eternalFontOffsetPatch_98;
//		break;
//	case idFontHash::ttSuperA0:
//		fontOffsetPatch = eternalFontOffsetPatch_A0;
//		break;
//	case idFontHash::idTacticA8:
//		fontOffsetPatch = eternalFontOffsetPatch_A8;
//		break;
//	case idFontHash::defaultCourrierF8:
//		fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;;
//		break;
//	default:
//		logWarn("set: default case, setting font to eternalFontDefaultOffsetPatch_F8");
//		fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;;
//		break;
//
//	}
//
//	Patcher::patchIfNeeded("monoSpaceFont_FontOffset_Patch", m_monoSpaceFont_FontOffsetAddr, fontOffsetPatch);
//
//	Patcher::patchIfNeeded("drawStringFontOffset_Patch", m_drawStringFontOffsetAddr, fontOffsetPatch);
//
//	Patcher::patchIfNeeded("consoleHistoryFontOffset_Patch", m_consoleHistoryFontOffsetAddr, fontOffsetPatch);
//
//
//
//}*/
//
//// void idFontManager::debugCycleFonts() {
////	int currentFontInt = (int)m_idFontEnum;
////	currentFontInt++;
////	if (currentFontInt >= (int)idFontHash::MAX_ID_FONTS) {
////		currentFontInt = 0;
////	}
////	else if (currentFontInt <0) {
////		currentFontInt = 0;
////	}
////	m_idFontEnum = (idFontHash)currentFontInt;
////	logInfo("debugCycleFont_Next: setting font to: %s", getFontAsStr(m_idFontEnum).c_str());
////	set(m_idFontEnum);
////}