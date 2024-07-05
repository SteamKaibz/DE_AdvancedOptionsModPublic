#include "idFontManager.h"

//? note: setting font from main: init: causes an error: log : ERR | set : m_monoSpaceFontAddr is bad ptr can not set font but  we don't need it as we just use the default font anyway, until may be someday we decide to implement stats...

 void idFontManager::init() {

	m_monoSpaceFontAddr = TypeInfoManager::getGlobalFontTable();
	idFontEnum defaultFont = idFontEnum::defaultCourrierF8;
	std::string defaultFontStr = getFontAsStr(defaultFont);
	logInfo("init: setting Font to: %s", defaultFontStr.c_str());
	set(defaultFont);
}

 bool idFontManager::acquirreSetMonospaceFondOffsetAddr(__int64 offsetAddr) {
	logDebug("acquirreSetMonospaceFondOffsetAddr");
	if (MemHelper::isBadReadPtr((void*)offsetAddr)) {
		logErr("acquirreSetMonospaceFondOffsetAddr: bad ptr for offsetAddr: %p", (void*)offsetAddr);
		return false;
	}
	m_monoSpaceFont_FontOffsetAddr = offsetAddr;
	logInfo("acquirreSetMonospaceFondOffsetAddr: m_monoSpaceFont_FontOffsetAddr is being set to : %p ", (void*)m_monoSpaceFont_FontOffsetAddr);
	return true;
}

 bool idFontManager::acquirreDrawStringFontOffsetAddr(__int64 fontOffsetAddr) {
	logDebug("acquirreDrawStringFontOffsetAddr");
	if (MemHelper::isBadReadPtr((void*)fontOffsetAddr)) {
		logErr("acquirreDrawStringFontOffsetAddr: bad ptr for offsetAddr: %p", (void*)fontOffsetAddr);
		return false;
	}
	m_drawStringFontOffsetAddr = fontOffsetAddr;
	logInfo("acquirreDrawStringFontOffsetAddr: m_drawStringFontOffsetAddr is being set to : %p ", (void*)m_drawStringFontOffsetAddr);
	return true;
}

 bool idFontManager::acquirreConsoleHistoryFontOffsetAddr(__int64 offsetAddr) {
	logDebug("acquirreConsoleHistoryFontOffsetAddr");
	if (MemHelper::isBadReadPtr((void*)offsetAddr)) {
		logErr("acquirreConsoleHistoryFontOffsetAddr: bad ptr for offsetAddr: %p", (void*)offsetAddr);
		return false;
	}
	m_consoleHistoryFontOffsetAddr = offsetAddr;
	logInfo("acquirreConsoleHistoryFontOffsetAddr: m_consoleHistoryFontOffsetAddr is being set to : %p ", (void*)m_consoleHistoryFontOffsetAddr);
	return true;
}

 bool idFontManager::acquirreIdFontGetGlyphDataFuncAddr(__int64 fAdd) {
	logDebug("acquirreIdFontGetGlyphDataFuncAddr");
	if (MemHelper::isBadReadPtr((void*)fAdd)) {
		logErr("acquirreIdFontGetGlyphDataFuncAddr: fAdd is bad ptr: %p", (void*)fAdd);
		return false;
	}
	m_idFont_getGlyphDataFuncAddr = fAdd;
	logInfo("acquirreIdFontGetGlyphDataFuncAddr: m_idFont_getGlyphDataFuncAddr is being set to : %p ", (void*)m_idFont_getGlyphDataFuncAddr);
	return true;
}

 std::string idFontManager::getCurrentFontAsStr() {
	return getFontAsStr(m_idFontEnum);
}

 std::string idFontManager::getFontAsStr(idFontEnum idFontEnum) {
	switch (idFontEnum)
	{
	case idFontEnum::unknown:
		return "unknown";
		break;
	case idFontEnum::eternal88:
		return "eternal88";
	case idFontEnum::eternal90:
		return "eternal90";
	case idFontEnum::ttSuper98:
		return "ttSuper98";
	case idFontEnum::ttSuperA0:
		return "ttSuperA0";
	case idFontEnum::idTacticA8:
		return "idTacticA8";
	case idFontEnum::euroStilB0:
		return "euroStilB0";
	case idFontEnum::defaultCourrierF8:
		return "defaultCourrierF8";
	case idFontEnum::MAX_ID_FONTS:
		return "MAX_ID_FONTS";
	default:
		return "getFontAsStr default case, how did that happen?!";
	}
}

 int idFontManager::getcurrentFontAddrOffset() {
	switch (m_idFontEnum)
	{
	case idFontEnum::eternal88:
		return 0x88;
		break;
	case idFontEnum::eternal90:
		return 0x90;
		break;
	case idFontEnum::ttSuper98:
		return 0x98;
		break;
	case idFontEnum::ttSuperA0:
		return 0xA0;
		break;
	case idFontEnum::idTacticA8:
		return 0xA8;
		break;
	case idFontEnum::euroStilB0:
		return 0xB0;
		break;
	case idFontEnum::defaultCourrierF8:
		return 0xF8;
		break;
	default:
		logErr("getFontAddrOffset failed to find offset for font: %s returning 0", getFontAsStr(m_idFontEnum).c_str());
		return 0;
		break;
	}
}

//? i'm fed up of this  bs. Will not use text inside boxes to indicate countdown will use self maderect bars instead, will only use text for the health, armor and ammo and that is  to align it of the y axis for lower value so . I'm not even sure why the  i'm doing all this anyway, way too much work for what???!!!!!

 void idFontManager::adjustStringOffsetForCurrentFont(idVec2& currentStringXY) {


	switch (m_idFontEnum)
	{
	case idFontEnum::unknown:
		break;
	case idFontEnum::eternal88:
		break;
	case idFontEnum::eternal90:
		currentStringXY.x = currentStringXY.x * .18f;
		currentStringXY.y += std::abs(.57f * currentStringXY.y);
		return;
	case idFontEnum::ttSuper98:
		currentStringXY.x = currentStringXY.x * .18f;
		currentStringXY.y += std::abs(.57f * currentStringXY.y);
		return;
	case idFontEnum::ttSuperA0:
		currentStringXY.x = currentStringXY.x * .155f;
		currentStringXY.y += std::abs(.145f * currentStringXY.y);
		return;
	case idFontEnum::idTacticA8:
		currentStringXY.x = currentStringXY.x * .21f;
		currentStringXY.y -= std::abs(.26f * currentStringXY.y);
		return;
	case idFontEnum::euroStilB0:  //! not useful, don't use it
		break;
	case idFontEnum::defaultCourrierF8:
		currentStringXY.x = currentStringXY.x * .036f;
		currentStringXY.y += std::abs(.05f * currentStringXY.y);
		return;
	case idFontEnum::MAX_ID_FONTS:
		break;
	}
	logWarn("adjustStringOffsetForCurrentFont did not find any Vec2 offset for font: %s not modifying Vec2", getFontAsStr(m_idFontEnum).c_str());

}

 __int64 idFontManager::getCurrentFontAddr() {
	if (!m_idFont_getGlyphDataFuncAddr) {
		logErr("getCurrentFontAddr: m_idFont_getGlyphDataFuncAddr is null can not get data");
		return 0;
	}

	if (!m_monoSpaceFontAddr) {
		logErr("getCurrentFontAddr: m_monoSpaceFontAddr is null can not get data");
		return 0;
	}

	auto fontOffset = getcurrentFontAddrOffset();
	if (!fontOffset) {
		logErr("getCurrentFontAddr: failed to find current font offset returning 0");
		return 0;
	}

	return m_monoSpaceFontAddr + fontOffset;
}

 __int64 idFontManager::getGlyphDataAddr(const char* str) {


	auto currentFontAddr = getCurrentFontAddr();
	if (currentFontAddr) {
		auto getGlyphFunc = reinterpret_cast<idFont_getGlyphData>(m_idFont_getGlyphDataFuncAddr);
		return getGlyphFunc(currentFontAddr, (__int64)str);
	}
	logErr("getGlyphDataAddr currentFontAddr is null, returning 0");
	return 0;

}

 idFontEnum idFontManager::getCurrentFont() {
	if (m_idFontEnum == idFontEnum::unknown) {
		set(idFontEnum::defaultCourrierF8);
		logWarn("getCurrentFont: idFont is unknown, attempting to set it to defaultCourrierF8");
	}
	return m_idFontEnum;
}

//? calling this function too often will degrade performance

 void idFontManager::set(idFontEnum idFontEnum) {
	std::vector<unsigned char> fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;

	if (MemHelper::isBadReadPtr((void*)m_monoSpaceFontAddr)) {
		logErr("set: m_monoSpaceFontAddr is bad ptr can not set font");
		return;
	}
	m_idFontEnum = idFontEnum;
	logInfo("set: m_monoSpaceFontAddr %p (font enum: %x font name: %s)", (void*)m_monoSpaceFontAddr, m_idFontEnum, getFontAsStr(m_idFontEnum).c_str());

	switch (m_idFontEnum)
	{
	case idFontEnum::eternal88:
		fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;
		break;
	case idFontEnum::eternal90:
		fontOffsetPatch = eternalFontOffsetPatch_90;
		break;
	case idFontEnum::ttSuper98:
		fontOffsetPatch = eternalFontOffsetPatch_98;
		break;
	case idFontEnum::ttSuperA0:
		fontOffsetPatch = eternalFontOffsetPatch_A0;
		break;
	case idFontEnum::idTacticA8:
		fontOffsetPatch = eternalFontOffsetPatch_A8;
		break;
	case idFontEnum::defaultCourrierF8:
		fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;;
		break;
	default:
		logWarn("set: default case, setting font to eternalFontDefaultOffsetPatch_F8");
		fontOffsetPatch = eternalFontDefaultOffsetPatch_F8;;
		break;

	}

	Patcher::patchIfNeeded("monoSpaceFont_FontOffset_Patch", m_monoSpaceFont_FontOffsetAddr, fontOffsetPatch);

	Patcher::patchIfNeeded("drawStringFontOffset_Patch", m_drawStringFontOffsetAddr, fontOffsetPatch);

	Patcher::patchIfNeeded("consoleHistoryFontOffset_Patch", m_consoleHistoryFontOffsetAddr, fontOffsetPatch);



}

 void idFontManager::debugCycleFonts() {
	int currentFontInt = (int)m_idFontEnum;
	currentFontInt++;
	if (currentFontInt >= (int)idFontEnum::MAX_ID_FONTS) {
		currentFontInt = 0;
	}
	else if (currentFontInt <0) {
		currentFontInt = 0;
	}
	m_idFontEnum = (idFontEnum)currentFontInt;
	logInfo("debugCycleFont_Next: setting font to: %s", getFontAsStr(m_idFontEnum).c_str());
	set(m_idFontEnum);
}

 fontInfo_t* idFontManager::getFontInfoPtr() {
	logInfo("getFontInfoPtr called");
	auto currentFontAddr = getCurrentFontAddr();
	if (!currentFontAddr) {
		logErr("getFontInfoPtr, failed to find currentFontAddr");
		return 0;
	}
	idFont* currentFontPtr = (idFont*)*(__int64*)currentFontAddr;
	if (MemHelper::isBadReadPtr(currentFontPtr)) {
		logErr("getFontInfoPtr, currentFontPtr is bad ptr: %p", currentFontPtr);
		return 0;
	}
	return currentFontPtr->fontInfo;
}

//? this could crash as we don't check for bad ptr but as long as we are in debug mode it's ok.

 void idFontManager::printcurrentFontData() {
	logInfo("printcurrentFontData called");
	auto currentFontAddr = getCurrentFontAddr();
	if (!currentFontAddr) {
		logErr("printcurrentFontData, failed to find currentFontAddr");
		return;
	}
	idFont* currentFontPtr = (idFont*)*(__int64*)currentFontAddr;
	if (MemHelper::isBadReadPtr(currentFontPtr)) {
		logErr("printcurrentFontData, currentFontPtr is bad ptr: %p", currentFontPtr);
		return;
	}
	logInfo("Current font: %s, currentFontPtr->fontInfo->ascender: %d,  currentFontPtr->fontInfo->descender: %d", getCurrentFontAsStr().c_str(), currentFontPtr->fontInfo->ascender, currentFontPtr->fontInfo->descender);

	glyphInfo_t* glyphInfo = currentFontPtr->fontInfo->glyphData;
	if (MemHelper::isBadReadPtr(glyphInfo)) {
		logErr("printcurrentFontData, glyphInfo is bad ptr: %p and currentFontPtr: %p  currentFontPtr->fontInfo: %p", glyphInfo, currentFontPtr, currentFontPtr->fontInfo);
		return;
	}
	logInfo("Current font: %s, glyphInfo: glyphInfo->left: %d glyphInfo->top: %d glyphInfo->width: %u glyphInfo->height: %u glyphInfo->s: %u glyphInfo->xSkip: %u glyphInfo->t: %u ", getCurrentFontAsStr().c_str(), glyphInfo->left, glyphInfo->top, glyphInfo->width, glyphInfo->height, glyphInfo->s, glyphInfo->xSkip, glyphInfo->t);
}
