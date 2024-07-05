#pragma once
#include "../Config/Config.h"
#include "MemHelper.h"


class LoadScreenInfo
{
public:
	class N00000273* idLoadScreenThreadPtr; //0x0000
	class N00000287* SFW_Ptr; //0x0008
	class N0000029B* ListOfIdImagePtr; //0x0010
	char pad_0018[16]; //0x0018
	class N000002AF* idRenderModelGuiPtr; //0x0028
	class N000002C3* idDeclMapInfoPtr; //0x0030
	char pad_0038[96]; //0x0038
	float LoadPercentage; //0x0098
	char pad_009C[12]; //0x009C
	bool isInLoadingScreen; //0x00A8
	bool isLoadingComplete; //0x00A9
	char pad_00AA[6]; //0x00AA
	bool IsInMainMenus; //0x00B0
	char pad_00B1[4047]; //0x00B1
}; //Size: 0x1080


class LoadingScreenManager {

private:




	static inline __int64 m_loadingScreenStructAddr = 0;
	static inline LoadScreenInfo* m_loadScreenInfoPtr = nullptr;
	static inline bool m_debug_isFirtTime = true;
	static inline float m_debug_lastLoadPercentage = -1.0f;
	static inline bool m_debug_lastisInLoadingScreen = false;
	static inline bool m_debug_lastisLoadingComplete = false;

public:

	static bool acquirreloadingScreenStructAddr(__int64 addr);

	static bool isReadyToRenderIceIcon();


	static float roundToDecimalPlaces(float value, int decimalPlaces);

	static void printLoadScreenDataChange();

	static void debugPrintLoadScreenInfo();



};


