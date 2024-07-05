#pragma once


#include <string>
#include "../Config/Config.h"
#include "../K_Utils/K_Utils.h"
#include "../DE/TypeInfoManager.h"
#include "../DE/GeneratedClasses.h"

class cmdInfoGenerator
{
private:

	static inline std::string m_cvarListFileName = "cmdList_K.txt";

public:

	static void dumpCmdListToFile();

	static idList* getCmdPtrIdList(__int64 idCmdSystemLocal);
	static std::string getCmdInfoAsTest(commandDef_s* cmdDefPtr);
	static std::string getCmdStaticOffsetAsStr(commandDef_s* cmdDefPtr);
};

