#pragma once

#include <string>
#include "../Config/Config.h"
#include "../K_Utils/K_Utils.h"
#include "../DE/TypeInfoManager.h"
#include "../DE/GeneratedClasses.h"


/// <summary>
/// an attempt to move away from having tools part of the game mod project so we can still generate while working on critical features for the mod that would not let us use the mod.
/// </summary>
class cvarInfoGenerator
{
private:

	static inline std::string m_cvarListFileName = "cvarsList_K.txt";

public:

	static void dumpCvarsListToFile();

	static idCVar* getFirstCvarPtrInList(__int64 cvarSystemLocal);

	static std::string getCvarInfoAsText(idCVar* cvarPtr);

	static std::string getCvarStaticOffsetsAsStr(idCVar* cvarPtr);

};

