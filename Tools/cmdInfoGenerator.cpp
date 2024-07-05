#include "cmdInfoGenerator.h"

void cmdInfoGenerator::dumpCmdListToFile()
{
	size_t cmdCounter = 0;
	std::vector<std::string> cmdsStrVec{};
	cmdsStrVec.reserve(131072);

	__int64 idCmdSystemLocalPTR = TypeInfoManager::getCmdSystemPtrAddr();

	if (!idCmdSystemLocalPTR || MemHelper::isBadReadPtr((void*)idCmdSystemLocalPTR)) {
		logErr("dumpEventsListToFile: idCmdSystemLocalPTR: %p is null or bad ptr returning", (void*)idCmdSystemLocalPTR);
		return;
	}

	logInfo("dumpEventsListToFile: idCmdSystemLocalPTR: %p", (void*)idCmdSystemLocalPTR);
	__int64 idCmdSystemLocal = *(__int64*)idCmdSystemLocalPTR;

	idList* cmdsIdList = getCmdPtrIdList(idCmdSystemLocal);
	if (!cmdsIdList) {
		logErr("dumpEventsListToFile: failed to find cmdsIdList.");
		return;
	}

	logInfo("dumpEventsListToFile: cmdsIdList: %p num: %d first cmd: %p", cmdsIdList, cmdsIdList->num, cmdsIdList->list);

	__int64* listEmementPtr = (__int64*)cmdsIdList->list;
	int debugCounter = 0;

	for (size_t i = 0; i < cmdsIdList->num; i++)
	{
		if (!listEmementPtr || !(*(__int64*)listEmementPtr)) {
			logWarn("dumpEventsListToFile: found nullptr, breaking at index: %zu", i);
			break;
		}

		commandDef_s* cmdDefPtr = (commandDef_s*)*(__int64*)listEmementPtr;
		std::string cmdInfoAsStr = getCmdInfoAsTest(cmdDefPtr);
		cmdsStrVec.push_back(cmdInfoAsStr);
		//logInfo("cmdDefPtr: found name: %s", cmdDefPtr->name);
		debugCounter++;

		listEmementPtr++;

	}

	//logInfo("dumpCmdListToFile: debugCounter: %d", debugCounter);

	logInfo("dumpEventsListToFile: sorting cmds by name");
	std::sort(cmdsStrVec.begin(), cmdsStrVec.end(), K_Utils::caseInsensitiveCompare);
	std::string cmdCountInfoStr = "Found " + std::to_string(debugCounter) + " commands.";
	cmdsStrVec.push_back(cmdCountInfoStr);

	K_Utils::saveVecToFile(m_cvarListFileName, cmdsStrVec);
	

}

idList* cmdInfoGenerator::getCmdPtrIdList(__int64 idCmdSystemLocal)
{
	if (!idCmdSystemLocal) {
		return nullptr;
	}
	return (idList*) *(__int64*)(idCmdSystemLocal + 0x10);
}


std::string cmdInfoGenerator::getCmdInfoAsTest(commandDef_s* cmdDefPtr) {
	std::string result;
	std::string fourSpaces = "    ";

	if (!cmdDefPtr) {
		logErr("getCmdInfoAsTest: found null ptr");
		return result;
	}

	result += cmdDefPtr->name;
	result += "\n";

	result += getCmdStaticOffsetAsStr(cmdDefPtr);
	result += "\n";

	result += "Description: ";
	result += cmdDefPtr->description;
	result += "\n";
	result += "\n";

	return result;
}


std::string cmdInfoGenerator::getCmdStaticOffsetAsStr(commandDef_s* cmdDefPtr) {

	__int64 funcOffset = (uintptr_t)cmdDefPtr->function - MemHelper::getModuleBaseAddr();

	return "idCmdArgs_function Offset: " + K_Utils::intToHexString(funcOffset);
	
}

