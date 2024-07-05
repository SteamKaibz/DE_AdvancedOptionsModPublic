#include "cvarInfoGenerator.h"

//! in console using listCvars i find 7397 cvars
void cvarInfoGenerator::dumpCvarsListToFile()
{
	size_t cvarsCounter = 0;
	std::vector<std::string> cvarsStrVec{};
	cvarsStrVec.reserve(131072);

	__int64 cvarSystemLocalPtr = TypeInfoManager::getCvarSystemPtrAddr();
	if (!cvarSystemLocalPtr) {
		logErr("dumpCvarsListToFile: can not dump list cause cvarSystemLocalPtr == 0");
		return;
	}

	__int64 cvarSystemLocal = *(__int64*)cvarSystemLocalPtr;
	logInfo("dumpCvarsListToFile: cvarSystemLocal set to: %p", (void*)cvarSystemLocal);

	idCVar* cvarPtr = getFirstCvarPtrInList(cvarSystemLocal);
	if (!cvarPtr) {
		logErr("dumpCvarsListToFile: firstCvarPtr is nullptr");
		return;
	}

	logInfo("dumpCvarsListToFile: first cvarPtr is: %p and its name is: %s description: %s", cvarPtr, cvarPtr->data->name, cvarPtr->data->description);

	while (true)
	{
		if (!cvarPtr || (cvarPtr == nullptr)) {
			logWarn("found nullptr, breaking");
			break;
		}

		std::string cvarInfoAsStr = getCvarInfoAsText(cvarPtr);
		cvarsStrVec.push_back(cvarInfoAsStr);
		//logInfo("cvar: %s current val: %s flags: %X description: %s ", cvarPtr->name, cvarPtr->valueString.data, cvarPtr->flags, cvarPtr->description);
		cvarsCounter++;

		if (cvarPtr->next == nullptr) {
			break;
		}
		cvarPtr = cvarPtr->next;
	}

	logInfo("dumpCvarsListToFile: sorting cvars by name");
	std::sort(cvarsStrVec.begin(), cvarsStrVec.end());
	std::string cvarCountInfoStr = "Found " + std::to_string(cvarsCounter) + " cvars.";
	cvarsStrVec.push_back(cvarCountInfoStr);

	K_Utils::saveVecToFile(m_cvarListFileName, cvarsStrVec);
}


idCVar* cvarInfoGenerator::getFirstCvarPtrInList(__int64 cvarSystemLocal) {	
	if (!cvarSystemLocal) {
		logErr("getFirstCvarPtrInList: can not get ptr cause cvarSystemLocal == 0");
		return nullptr;
	}	
	idCVar** firstCvarpPtrToPtr = **(idCVar****)(cvarSystemLocal + 8);
	return *firstCvarpPtrToPtr;
}


std::string cvarInfoGenerator::getCvarInfoAsText(idCVar* cvarPtr) {

	std::string result;
	std::string fourSpaces = "    ";

	if (MemHelper::isBadReadPtr(cvarPtr)) {
		logErr("getCvarInfoAsText: found bad ptr: %p", cvarPtr);
		return result;
	}
	//lkjlkjresult += "name: ";
	result += cvarPtr->data->name;
	result += "\n";

	result += getCvarStaticOffsetsAsStr(cvarPtr);
	result += "\n";

	result += "Cur val: ";
	//lkjlkjresult += cvarPtr->valueString.data;
	result += cvarPtr->data->valueString;
	if (cvarPtr->data->resetString) {
		result += " (Reset val: ";
		result += cvarPtr->data->resetString;
		result += ")";
	}	
	result += fourSpaces;
	result += "ValueMinFloat: ";
	result += K_Utils::floatToStringWithoutTrailingZeros(cvarPtr->data->valueMin);
	result += fourSpaces;
	result += "ValueMaxFloat: ";
	result += K_Utils::floatToStringWithoutTrailingZeros(cvarPtr->data->valueMax);
	result += "\n";

	/*std::string formatedFlags = getCvarFlagsAsString(cvarPtr->flags);
	result += "Flags: ";
	result += formatedFlags;
	result += "\n";*/

	result += "Description: ";
	result += cvarPtr->data->description;
	result += "\n";
	result += "\n";

	//? we don't dump the onChange ptrs cause there are very few of them and i logged them in our reminder file.

	if (cvarPtr->data->onChange != nullptr) {
		logWarn("getCvarInfoAsText found a non null cvarPtr->onChange for cvar: %s at addr: %p", cvarPtr->data->name, cvarPtr->data->onChange);
	}

	return result;
}


std::string cvarInfoGenerator::getCvarStaticOffsetsAsStr(idCVar* cvarPtr) {

	__int64 cvarOffset = (uintptr_t)cvarPtr - MemHelper::getModuleBaseAddr();

	//? for this ida db cvar offset are not important as they are not directly reference, instead it will be cvarOffset + 1, 2, 3 for ex.
	/*__int64 cvarDataOffset = (*(uintptr_t*)cvarPtr) - MemHelper::getModuleBaseAddr();
	__int64 valIntOffset = cvarDataOffset + 0x8;
	__int64 valFloatOffset = cvarDataOffset + 0xC;*/

	/*return "Cvar Offset: " + K_Utils::intToHexString(cvarOffset) + " Cvar DATA Offset: " + K_Utils::intToHexString(cvarDataOffset) + "  Val Int Offset: " + K_Utils::intToHexString(valIntOffset) + "  Val Float Offset: " + K_Utils::intToHexString(valFloatOffset);*/
	return "Cvar Offset: " + K_Utils::intToHexString(cvarOffset);


}



//idCVar** idCVar::GetList(unsigned& out_n) {
//	void* sys = get_cvarsystem();
//	
//	idList* entries = *mh_lea<idList*>(sys, 8);
//
//
//	out_n = entries->num;
//
//	return (idCVar**)entries->list;
//}
