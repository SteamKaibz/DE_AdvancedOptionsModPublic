#pragma once


#include "idLib.h"
#include "GeneratedClasses.h"
#include "MemHelper.h"
#include "TypeInfoManager.h"






typedef char(__fastcall* idInternalCVar__Set)(idCVar* a1, const char* a2, char a3);

typedef __int64(__fastcall* cvarFindInternal_t)(__int64 addr, const char*);


class idCvarManager
{

private:

	static inline __int64 m_idCVarSystemLocal = 0;

	static inline idInternalCVar__Set m_setCvarFp = nullptr;
	static inline cvarFindInternal_t m_findInternalFp = nullptr;

	//! cached cvars for performance


public:

	
	static bool acquireIdCVarSystemLocalPtr(__int64 add);
	static bool acquireFindInternalFuncPtr();
	//static bool acquireFindInternalFuncPtr(__int64 funcAddr);
	static bool acquireSetInternalFuncAddr(__int64 funcAddr);

	static idCVar* getCvarPtr(std::string cvarStr);

	static int getCvarInt(std::string cvarStr);

	static float getCvarFloat(std::string cvarStr);

	static std::string getCvarString(std::string cvarStr);

	static bool setCvar(std::string cvarStr, std::string val);

	//static bool setCvarFast(idCVar* cvar, const char* valStr);

	//static bool setModInitCvars();

	//! ensuring the mod works as it should. triggers when mod loads and when user exits the console.
	//static bool setCriticalCvars();

	static void setValueMaxFloat(const char* cvarName, float maxValue);

	//! has it's own method to make sure the max value has been updated
	//static void setSafeFrame(float safeFrameFloat);


	//static bool cacheCriticalCvars();

	//static float getFov();

	//void testGetCvar(std::string cvarStr);

	//void testWriteCvar(std::string cvarStr, std::string val);
	


};

