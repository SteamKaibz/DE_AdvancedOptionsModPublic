#pragma once

#include "idLib_Static.h"
#include "idColor.h"
#include "GameHudColorsManager.h"
#include "idMapInstanceLocalManager.h"
#include "idFontManager.h"
#include "MaterialLib.h"
#include "UserColorSet.h"
#include "CustomIceNadeIconUIData.h"




//? this file can not get included in other files; otherwise you'll get a weird build error about CustomIceNadeIconUIData. don't ask me why i almost went crasy trying to figure it out. i'm done.

class idRenderModelGuiManager{

private:
	////! hard coding those cause there not documented in typeInfo tool
	//static const unsigned int m_packedColorOffset;
	//static const unsigned int m_screenWidthOffset;
	//static const unsigned int m_screenHeighthOffset;

	//! idRenderModelGui::DrawString(this, float x,float y,const char* string,const idColor* defaultColor,bool forceColor,const float scale)
	typedef __int64(__fastcall* idRenderModelGui_DrawString)(idRenderModelGui* gui, float a2, float a3, const char* a4, __int64 a5, char a6, float a7);
	static inline idRenderModelGui_DrawString m_pidRenderModelGui_DrawString = 0;
	//idRenderModelGui_DrawString m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x6239F0));

	//! DrawStretchPic(guiPtr, x, y, z, w, h, s1, t1, s2, t2, mapPtr)
	typedef void(__fastcall* idRenderModelGui_DrawStretchPic)(idRenderModelGui* gui, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, idMaterial2* mtr_a11);
	static inline idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic = 0;
	
	//typedef void(__fastcall* idRenderModelGui_DrawStretchPic_V2)(idRenderModelGui* gui, float x_a2, float y_a3, float z_a4, float w_a5, float h_a6, float s1_a7, float t1_a8, float s2_a9, float t2_a10, idMaterial2* mtr_a11);
	
	
	//idRenderModelGui_DrawStretchPic pidRenderModelGui_DrawStretchPic = reinterpret_cast<idRenderModelGui_DrawStretchPic>(MemHelper::getFuncAddr(0x498ED0));



	//static inline const unsigned int m_packedColorOffset = GameOffsets::RenderModelGui_PackedColorOffset;
	//static inline const unsigned int m_packedColorOffset = 0x4D0;

	//? why do we have those as we have m_screenWidthAddr below ?????
	/*static inline const unsigned int m_screenWidthOffset = 0x4568;
	static inline const unsigned int m_screenHeighthOffset = 0x456C;*/


	//idRenderModelGuiManager::idRenderModelGui_DrawString idRenderModelGuiManager::m_pidRenderModelGui_DrawString = reinterpret_cast<idRenderModelGui_DrawString>(MemHelper::getFuncAddr(0x623530));
	//static inline idRenderModelGui_DrawString m_pidRenderModelGui_DrawString = 0;


	//static inline idRenderModelGui_DrawStretchPic  pidRenderModelGui_DrawStretchPic = 0;


	//! these are the value to the image is not mirores on x or y:
	static inline float s1 = 0.0;
	static inline float t1 = 0.0;
	static inline float s2 = 1.0;
	static inline float t2 = 1.0;

	

	static inline __int64 m_smallCharWidthAddr = 0;
	static inline __int64 m_smallCharHeightAddr = 0;
	static inline __int64 m_useScaleAddr = 0;
	static inline __int64 m_screenWidthAddr = 0;
	static inline __int64 m_screenHeightAddr = 0;
	static inline const int m_iceIconDrawCallMaxCount = 2;

	//! hard coded address of _white material that seems to be available during all game life time
	//static inline __int64 m_staticMaterialWhiteAddr = 0; 

	//! there is a _white in idDebugHud let's see if it's constant for all game lifespan
	static inline idMaterial2* m_cachedWhiteMaterial = nullptr;



public:


	//static bool isDrawStringTriggered;

	//static int DrawStringCounter;

	//static bool isGetPerfMetricsStrTriggered;

	//static int DrawStretchPic_498ED0_Counter;

	static inline bool isDrawStringTriggered = false;
	static inline bool isGetPerfMetricsStrTriggered = false;
	static inline int DrawStretchPic_498ED0_Counter = 0;
	static inline int DrawStringCounter = 0;
	

	//static inline idRenderModelGui_DrawStretchPic_V2 m_drawStretchPicFp_V2 = nullptr;

	static std::string getDbgStrForImgui();

	//static bool acquireStaticWhiteMaterialAddr(__int64 addr);
	

	static void parseTextColor(char colorCode, idColor& outColor);

	static void paintChar(idRenderModelGui* gui, float x, float y, const scaledGlyphInfo_t& glyphInfo);

	static void drawStringForRectHeigth_V2(idRenderModelGui* gui, swfRect_t bounds, std::string text, idFontHash fontHash, const idColor& color, bool forceColor, textAlignment alignment, bool isDebug);

	

	static void drawSwfRectMaterial_V2(idRenderModelGui* gui, swfRect_t swfRect, const idColor& color, idMaterial2* material);

	static void setColor_V2(idRenderModelGui* gui, const idColor& idColor);

	static bool acquirreWhiteMaterial();

	static std::string debugGetFontNameString(idFontHash fontHash);

	static void debugDrawAllFonts(idRenderModelGui* gui);


	static bool acquirreDrawStretchPicFuncAdd(__int64 fAdd);

	static bool acquirreDrawStringFuncAdd(__int64 fAdd);

	static bool acquirreSmallCharWidhtAddr(__int64 addr);

	static bool acquirreSmallCharHeightAddr(__int64 addr);

	static bool acquirreUseScaleAddr(__int64 addr);

	static bool acquirreScreenWidthAddr(__int64 addr);

	static bool acquirreScreenHeight(__int64 addr);

	//static bool acquirepackedColorMemberOffset(__int64 addr);


	


	//! not sure what that values is supposed to be exactly but it's used in DrawString_623530
	static float getUseScaleVal();

	static float getSmallCharWidth();

	static float getSmallCharHeight();

	static float getScreenWidth();

	static float getScreenHeight();


	static unsigned  GetStringWidthInPixels(const char* string, const float scale);


	//static unsigned int getCurrentPackedColor(__int64 idRenderModelGuiAdr);

	//! this is just a version that does not check for bad ptr to try to optimize the render of ice icon(the check is already done in the container func.
	static void setColorNoCheck(idRenderModelGui* gui, const idColor& idColor);


	static void setColor(idRenderModelGui* gui, const idColor& idColor);


	//? getting rid of those cause it looks we can get those using other means
	//static float getScreenWidth(__int64 idRenderModelGuiAddr);

	//static float getScreenHeigth(__int64 idRenderModelGuiAddr);

	static float getCenterX(idRenderModelGui* gui);

	static float getCenterY(idRenderModelGui* gui);


	

	static void drawDrawStretchPicTest5(idRenderModelGui* gui, float x, float y, float width, float height, idMaterial2* matPtr);


	static void debugDrawColoredRect(idRenderModelGui* gui, float x, float y, float width, float height, idColor color);

	

	static float getFontScaleFromWidthV2(idVec4 rect, size_t strLettersCount);

	static float getFontScaleFromWidthV3(idVec4 rect, size_t strLettersCount);

		

	static void debugDrawString(idRenderModelGui* gui, idColor color, const char* text, float x, float y, float scale);

	//! because we don't stretch the string vertically a string height value will be a ratio of the charwidth and charheight
	static void adjustRectHeightToFitTheStr(idVec4& rect, size_t strCharCount);


	//static idVec2 getGlyphOffset(idVec4 rect, const char* str, float textScale);


	static void setIceNadeCooldDownTextScale(idVec4& rectRef, float rectPrct);
	

	static void drawIceNadeCooldownTextWithOutline(idRenderModelGui* gui, idColor color, std::string textStr, idVec4 rect, float textScaleF, float outlineOffset, bool isDebug = false);


	static void drawIceNadeCooldownText(idRenderModelGui* gui, idColor color, std::string textStr, idVec4 rect, float textScaleF, bool isDebug = false);


	//! Will drawn a string, scaling it horizontally to fill the rect width, however it will not scale it vertically.
	//! A 1 char length str will be 3 times bigger than a 3 chars lenght string, so if you want to do a countdown make sure the char count is the same, meaning if count from 60 to 0, from 10 to 0 the count should be 09, 08...
	//! if you want to use this to print the health with 3 numbers, you use a space to make sure the text keep the same width, for ex text can be 200 or 'space'10, or 'space''scpace'0 
	//static void drawStringCenteredInBounds(__int64 idRenderModelGuiAdr, idColor color, std::string textStr, idVec4 rect, bool isDebug = false);




	//static void drawAllNeededIconsTest(idRenderModelGui* gui);


	static void drawDrawStretchPicBounds(idRenderModelGui* gui, idVec4 bounds, idMaterial2* matPtr);
	
	

	static void debugDrawMaterialLibMatr(idRenderModelGui* gui, idMaterial2* matr, std::string materialNameStr);


	static void drawIceIcon(idRenderModelGui* gui, CustomIceNadeIconUIData& data);


	static void drawDrawStretchPicSwfRect(idRenderModelGui* gui, swfRect_t swfRect, idMaterial2* matPtr, const idColor& idColor, bool isMiroredX = false, bool isMiroredY = false);

	//static void drawDrawStretchPicWhiteMatrSwfRect(__int64 idRenderModelGuiAdrr, swfRect_t swfRect, const idColor& idColor, bool isMiroredX = false, bool isMiroredY = false);




	static void drawDrawStretchPicTest3(idRenderModelGui* gui, float x, float y, float width, float height, idMaterial2* matPtr, const idColor& idColor,  bool isMiroredX = false, bool isMiroredY = false);



	//! DEBUG



	//! this will make the string as big as it can be, meaning that if the string is 1 char length it will be 3 times bigger than a 3 chars lenght string, so the idea is that you always make sure that your string lenght is the same, meaning that if you do a count down from 60 to 0, from 10 to 0 the count will be 09, 08...
	//! if you want to use this to print the health with 3 numbers, you use a space to make sure the text keep the same width, for ex text can be 200 or 'space'10, or 'space''scpace'0 
	//static void debugDrawStringInRect(__int64 idRenderModelGuiAdr, idColor color, std::string textStr, idVec4 rect);



	static idVec4 debugGetNormalizedStringContainerRectV2(idVec4 rect, size_t charCountInString);
	
	static float debugGetTextCentered_X(idVec4 rect, int strLettersCount);

	static float debugGetStringLengthInPixel(idVec4 rect, size_t strLettersCount);

	static float debugGetString_X(idVec4 rect, size_t strLettersCount);
	


};

