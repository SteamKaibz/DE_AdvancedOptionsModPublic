
#pragma once

#include "MemHelper.h"
#include "CommonDE.h"
#include "idLib_Dynamic.h"
#include "TypeInfoManager.h"
#include "MaterialLib.h"
#include "idResourceListManager.h"



/// 2/11/24 ADDING THIS HERE AS we need IdMaterial defined 
//! found in Doom3 code in Font.h
struct scaledGlyphInfo_t {
	float	top, left;
	float	width, height;
	float	xSkip;
	float	s1, t1, s2, t2;
	//const class idMaterial* material;
	idMaterial2* material;
};

enum class textAlignment {
	left,
	center,
	right
};


typedef glyphInfo_t* (__fastcall* idFont_GetGlyphInfo_t)(idFont* idFont_a1, unsigned int charCode_a2);


class idFontManager
{
private:

	static inline idFont_GetGlyphInfo_t m_idFont_GetGlyphInfoFp = nullptr;

	static inline idDeclGlobalFontTable* m_idDeclGlobalFontTable = nullptr;
	
	static inline idFont* m_courrierFont = nullptr; //! need cache cause it's not as a var  in the idDeclGlobalFontTable

	static inline char m_ascii_courier[128] = { -1 };            
	static inline char m_ascii_eternal_bold[128] = { -1 };       
	static inline char m_ascii_eternal_reg[128] = { -1 };        
	static inline char m_ascii_eternal_num[128] = { -1 };   
	static inline char m_ascii_tt_supermolot[128] = { -1 }; 
	static inline char m_ascii_idTactical[128] = { -1 };               
	static inline char m_ascii_eurostileconreg[128] = { -1 };         
	
	static inline bool m_isAsciiCachedForAllFonts = false;

	static inline const int C_COLOR_ESCAPE = '^';
	static inline const int C_COLOR_DEFAULT = '0';
	static inline const int C_COLOR_RED = '1';
	static inline const int C_COLOR_GREEN = '2';
	static inline const int C_COLOR_YELLOW = '3';
	static inline const int C_COLOR_BLUE = '4';
	static inline const int C_COLOR_CYAN = '5';
	static inline const int C_COLOR_ORANGE = '6';
	static inline const int C_COLOR_WHITE = '7';
	static inline const int C_COLOR_GRAY = '8';
	static inline const int C_COLOR_BLACK = '9';
			

public:

	static bool init(idDeclGlobalFontTable* idDeclGlobalFontTablePtr);

	static bool cacheCourrierFont();

	static void setdebugGUIFont(idFontHash fontEnum);

	static std::string getFontName(idFont* fontPtr);

	static idFont* getCurConsoleFont();

	static idFont* getFont(idFontHash fontEnum);

	static idFontHash getFontHash(idFont* fontPtr);

	static void cacheFontAscii(idFont* fontPtr, char(&asciiCache)[128]);

	static void cacheAsciiForAllFonts();

	static char* getAsciiCacheForFontId(idFontHash fontEnum);

	static glyphInfo_t* getGlyphInfo(idFont* fontPtr, unsigned int charCode);

	static glyphInfo_t* getGlyphInfoForCurConsoleFont(unsigned int charCode);

	static int GetGlyphIndex(idFont* idFontPtr, unsigned int idx);

	static unsigned int getFontHeightForLetter_A(idFont* fontPtr);

	static unsigned int getFontHeightForChar(idFont* fontPtr, unsigned int charCode);

	static float GetGlyphWidth(idFont* fontPtr, float scale, unsigned int idx);

	static float GetGlyphLeft(idFont* fontPtr, float scale, unsigned int idx);

	static void GetScaledGlyph(idFont* fontPtr, float scale, unsigned int idx, scaledGlyphInfo_t& glyphInfo);

	static bool IsColor(const char* s);

	static int getTextWidth(idFont* idFontPtr, const char* text, float scale, int limit);

	//static int getTextWidth_V2(idFont* idFontPtr, const char* text, float scale, int limit);

	static float getTextScaleForRectHeight(float rectHeight);

	static float getTextScaleForRectHeight(float rectHeight, unsigned int charCode);

	//static void debugDrawAllFonts(idRenderModelGui* gui);

	static void debugLogFonts();


	static bool acquirreIdFontGetGlyphDataFuncPtr(__int64 fAdd);



};

































/// ORIGINAL CLASS 

//#pragma once
//#include "MemHelper.h"
//#include "Patcher.h"
//#include "CommonDE.h"
//#include "idLib_Dynamic.h"
//#include "TypeInfoManager.h"
//
//
//
////? 27/10/23 i'm initializing _idFontEnum = idFontHash::defaultCourrierF8 which is a bit of a hack as id' rather get the actual value but we get of verbose but we know that's the one we have on by default with our patching, because of it and as we don't use fonts atm as we just use the default one as for the other one we really struggle to center them, i guess we can say we're good. ERR| getCurrentFontAddr: m_monoSpaceFontAddr is null can not get data 03:13 : 01.227         idFontManager.h : 264    ERR | getGlyphDataAddr currentFontAddr is null, returning 0
//class idFontManager {
//
//private:
//
//
//	//! __int64 *__fastcall sub_4CC330(__int64 a1, __int64 a2) post denuvo
//	//typedef __int64(__fastcall* idFont_getGlyphData)(__int64 a1, __int64 a2);
//
//
//	typedef glyphInfo_t* (__fastcall* idFont_GetGlyphInfo_t)(idFont* idFont_a1, unsigned int charCode_a2);
//
//
//	static inline idFontHash m_idFontEnum = idFontHash::unknown;
//
//	static inline __int64 m_monoSpaceFontAddr = 0;
//	static inline __int64 m_monoSpaceFont_FontOffsetAddr = 0;
//	static inline __int64 m_drawStringFontOffsetAddr = 0;
//	static inline __int64 m_consoleHistoryFontOffsetAddr = 0;
//	//static inline __int64 m_idFont_getGlyphInfo_tFp = 0;
//	static inline idFont_GetGlyphInfo_t m_idFont_GetGlyphInfoFp = nullptr;
//
//	static inline idDeclGlobalFontTable* m_idDeclGlobalFontTable = nullptr;
//	static inline idFont* m_courrierFont = nullptr;
//
//
//public:
//
//	//? note: setting font from main: init: causes an error: log : ERR | set : m_monoSpaceFontAddr is bad ptr can not set font but  we don't need it as we just use the default font anyway, until may be someday we decide to implement stats...
//	//static void init();
//
//	
//
//	static bool init(idDeclGlobalFontTable* idDeclGlobalFontTablePtr);
//
//	static bool acquirreSetMonospaceFondOffsetAddr(__int64 offsetAddr);
//
//	static bool acquirreDrawStringFontOffsetAddr(__int64 fontOffsetAddr);
//
//	static bool acquirreConsoleHistoryFontOffsetAddr(__int64 offsetAddr);
//
//	static bool acquirreIdFontGetGlyphDataFuncAddr(__int64 fAdd);
//
//	
//
//
//	static std::string getCurrentFontAsStr();
//
//	static std::string getFontAsStr(idFontHash idFontHash);
//
//
//	static int getcurrentFontAddrOffset();
//	
//	//? i'm fed up of this  bs. Will not use text inside boxes to indicate countdown will use self maderect bars instead, will only use text for the health, armor and ammo and that is. Basically i got to a point where i managed to align eternal 90 but it was ok for scale 15 and no way to align it of the y axis for lower value so . I'm not even sure why the f i'm doing all this anyway, way too much work for what???!!!!!
//	static void adjustStringOffsetForCurrentFont(idVec2& currentStringXY);
//
//
//	//! each font must be offset differently so that we can render text in a consistant position. the y offset is computed in idRenderModelGui
//	
//
//
//	static __int64 getCurrentFontAddr();
//
//	static __int64 getGlyphDataAddr(const char* str);
//
//
//	//static idFontHash getCurrentFont();
//
//	static std::string getFontName(idFont* fontPtr);
//
//	static void setConsoleFont(idFontHash idFontHash);
//
//	static bool cacheCourrierFont(idDeclGlobalFontTable* idDeclGlobalFontTablePtr);
//
//	//? calling this function too often will degrade performance
//	//static void set(idFontHash idFontHash);
//
//	//static void debugCycleFonts();
//
//
//	static fontInfo_t* getFontInfoPtr();
//
//	//? this could crash as we don't check for bad ptr but as long as we are in debug mode it's ok.
//	static void printcurrentFontData();
//
//	
//};
//
//
//
//
//



