#pragma once
#include "MemHelper.h"
#include "Patcher.h"
#include "CommonDE.h"
#include "idLib.h"
#include "GeneratedClasses.h"
#include "TypeInfoManager.h"



//? 27/10/23 i'm initializing _idFontEnum = idFontEnum::defaultCourrierF8 which is a bit of a hack as id' rather get the actual value but we get of verbose but we know that's the one we have on by default with our patching, because of it and as we don't use fonts atm as we just use the default one as for the other one we really struggle to center them, i guess we can say we're good. ERR| getCurrentFontAddr: m_monoSpaceFontAddr is null can not get data 03:13 : 01.227         idFontManager.h : 264    ERR | getGlyphDataAddr currentFontAddr is null, returning 0
class idFontManager {

private:


	//! __int64 *__fastcall sub_4CC330(__int64 a1, __int64 a2) post denuvo
	typedef __int64(__fastcall* idFont_getGlyphData)(__int64 a1, __int64 a2);


	static inline idFontEnum m_idFontEnum = idFontEnum::unknown;

	static inline __int64 m_monoSpaceFontAddr = 0;
	static inline __int64 m_monoSpaceFont_FontOffsetAddr = 0;
	static inline __int64 m_drawStringFontOffsetAddr = 0;
	static inline __int64 m_consoleHistoryFontOffsetAddr = 0;
	static inline __int64 m_idFont_getGlyphDataFuncAddr = 0;


public:

	//? note: setting font from main: init: causes an error: log : ERR | set : m_monoSpaceFontAddr is bad ptr can not set font but  we don't need it as we just use the default font anyway, until may be someday we decide to implement stats...
	static void init();

	

	static bool acquirreSetMonospaceFondOffsetAddr(__int64 offsetAddr);

	static bool acquirreDrawStringFontOffsetAddr(__int64 fontOffsetAddr);

	static bool acquirreConsoleHistoryFontOffsetAddr(__int64 offsetAddr);

	static bool acquirreIdFontGetGlyphDataFuncAddr(__int64 fAdd);

	


	static std::string getCurrentFontAsStr();

	static std::string getFontAsStr(idFontEnum idFontEnum);


	static int getcurrentFontAddrOffset();
	
	//? i'm fed up of this  bs. Will not use text inside boxes to indicate countdown will use self maderect bars instead, will only use text for the health, armor and ammo and that is. Basically i got to a point where i managed to align eternal 90 but it was ok for scale 15 and no way to align it of the y axis for lower value so . I'm not even sure why the f i'm doing all this anyway, way too much work for what???!!!!!
	static void adjustStringOffsetForCurrentFont(idVec2& currentStringXY);


	//! each font must be offset differently so that we can render text in a consistant position. the y offset is computed in idRenderModelGui
	


	static __int64 getCurrentFontAddr();

	static __int64 getGlyphDataAddr(const char* str);


	static idFontEnum getCurrentFont();

	//? calling this function too often will degrade performance
	static void set(idFontEnum idFontEnum);

	static void debugCycleFonts();


	static fontInfo_t* getFontInfoPtr();

	//? this could crash as we don't check for bad ptr but as long as we are in debug mode it's ok.
	static void printcurrentFontData();

	
};








