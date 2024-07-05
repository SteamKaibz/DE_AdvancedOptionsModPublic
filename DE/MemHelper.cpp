#include "MemHelper.h"
//#include "Config.h"




bool MemHelper::isGameFileNameValid()
{
	std::string exeName = GetGameExeNameToLower();
	if (exeName != doomEternalExeNameToLower) {
		logErr("MemHelper::isGameFileNameValid(): wrong module name, was expecting %s got: %s.", doomEternalExeNameToLower.c_str(), exeName.c_str());
		return false;
	}
	
	logInfo("isGameFileNameValid: succes finding game file: %s", exeName.c_str());
	return true;
}

std::string MemHelper::basename(std::string const& pathname)
{
	return std::string(
		std::find_if(pathname.rbegin(), pathname.rend(),
			MatchPathSeparator()).base(),
		pathname.end()); 
}

std::string MemHelper::GetGameExeNameToLower()
{
	const int fnLenMax = 200;
	char fnPtr[fnLenMax];
	auto fnLen = GetModuleFileNameA(0, fnPtr, fnLenMax);

	auto fileName = basename(std::string(fnPtr, fnLen));
	std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
	return fileName;	
}




/// <summary>
/// this is a custom version of isBadReadPtr which "should" be accurate even though this method is intrasectly not perfect.
/// </summary>
/// <param name="ptr"></param>
/// <returns></returns>
bool MemHelper::isBadReadPtr(void* ptr)
{
	MEMORY_BASIC_INFORMATION mbi = { 0 };
	if (::VirtualQuery(ptr, &mbi, sizeof(mbi)))
	{
		DWORD mask = (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
		bool b = !(mbi.Protect & mask);
		// check the page is not a guard page
		if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) b = true;

		return b;
	}
	return true;
}

uintptr_t MemHelper::getModuleBaseAddr() {
	logDebug("getModuleBaseAddr");

	return (uintptr_t)GetModuleHandle(NULL);

	/*if (m_moduleBaseAddr == NULL) {
		spdlog::error("wnd_proc_hook: MemHelper::getModuleBaseAddr() is NULL");
	}
	return m_moduleBaseAddr;*/
	//return (uintptr_t)GetModuleHandle(NULL);
}

//bool MemHelper::isModuleBaseAddrOk()
//{
//	return !isBadReadPtr((void*)getModuleBaseAddr());
//}

uintptr_t MemHelper::getFuncAddr(uintptr_t offset) {
	logDebug("getFuncAddr");

	//uintptr_t newBase = (uintptr_t)GetModuleHandle(NULL);
	//return (m_moduleBaseAddr + offset);
	return (getModuleBaseAddr() + offset);
}

uintptr_t MemHelper::getAddr(uintptr_t offset)
{
	logDebug("getAddr");

	return (getModuleBaseAddr() + offset);
}


bool MemHelper::overwriteInstruction(std::string refStr, const uintptr_t instructionAddr, std::vector<unsigned char> newInstructionVec)
{
	logDebug("overwriteInstruction");
	if (isBadReadPtr((void*)instructionAddr)) {
		logErr("overwriteInstruction: %s :can not overwrite cause instructionAddr is bad ptr: %p", refStr.c_str(), (void*)instructionAddr);		
	}
	try
	{
		//logInfo("overwriting instuction at addr: %p", (void*)instructionAddr);

		// Set the memory protection to allow writing
		DWORD old_protection;
		VirtualProtect((LPVOID)instructionAddr, newInstructionVec.size(), PAGE_EXECUTE_READWRITE, &old_protection);

		// Write the new instruction to the memory address
		memcpy((LPVOID)instructionAddr, newInstructionVec.data(), newInstructionVec.size());
	
		// Restore the original memory protection
		VirtualProtect((LPVOID)instructionAddr, newInstructionVec.size(), old_protection, &old_protection);

		logInfo("succes overwriting Instruction for %s at instructionAddr: %p", refStr.c_str(), (void*)instructionAddr);
		return true;
	}
	catch (const std::exception& ex)
	{
		logErr("overwriteInstruction: ERROR: %s %s overwrite has failed", refStr.c_str(), ex.what());
	}
	return false;
	
}

 bool MemHelper::overwriteInstructionIfNotEqual(std::string refStr, const uintptr_t instructionAddr, std::vector<unsigned char> newInstructionVec)
{

	if (isBadReadPtr((void*)instructionAddr)) {
		logErr("overwriteInstruction: %s :can not overwrite cause instructionAddr is a bad ptr: %p", refStr.c_str(), (void*)instructionAddr);
		return false;
	}

	try
	{
		// Read the current instruction at the memory address
		std::vector<unsigned char> currentInstructionVec(newInstructionVec.size());
		memcpy(currentInstructionVec.data(), (LPVOID)instructionAddr, newInstructionVec.size());

		// Check if the current instruction is equal to the new instruction
		if (currentInstructionVec == newInstructionVec) {
			logInfo("Instruction for %s at instructionAddr: %p is already equal to the desired value, no overwrite needed.", refStr.c_str(), (void*)instructionAddr);
			return true; // Instruction is already what you want, no need to overwrite
		}

		// Set the memory protection to allow writing
		DWORD old_protection;
		VirtualProtect((LPVOID)instructionAddr, newInstructionVec.size(), PAGE_EXECUTE_READWRITE, &old_protection);

		// Write the new instruction to the memory address
		memcpy((LPVOID)instructionAddr, newInstructionVec.data(), newInstructionVec.size());

		// Restore the original memory protection
		VirtualProtect((LPVOID)instructionAddr, newInstructionVec.size(), old_protection, &old_protection);

		logInfo("Successfully overwritten Instruction for %s at instructionAddr: %p", refStr.c_str(), (void*)instructionAddr);
		return true;
	}
	catch (const std::exception& ex)
	{
		logErr("overwriteInstructionIfNotEqual: ERROR: %s %s overwrite has failed", refStr.c_str(), ex.what());
	}
	return false;
}



bool MemHelper::isSameByteArrays(const BYTE* array1, const BYTE* array2, size_t length)
{
	logDebug("isSameByteArrays called ");
	return std::memcmp(array1, array2, length) == 0;
}



//! 6/9/23 adding this to figure out addresses in memory which hopefully will not break if an update is released for Doom Eternal in the future. We had to add this after idSoftware removed Denuvo.




uintptr_t MemHelper::FindPtrAddress(uintptr_t addr, std::vector<unsigned int>& offsets)
{
	logDebug("FindPtrAddress");

	for (unsigned int i = 0; i < offsets.size(); i++) {
		if (isBadReadPtr((void*)addr)) {
			logWarn("MemHelper::FindPtrAddress: found BadReadPtr for addr: %p returning", (void*)addr);
			return 0;
		}
		addr = *(uintptr_t*)addr + offsets[i];
	}
	return addr;
}

//! this is commented almost as a tutorial
__int64 MemHelper::FindPtrFromRelativeOffset(uintptr_t instructionStartAddress, const int instructionOffset, const int nextInstructionOffset) {

	/*
*	Ida Example to illustrate the comments in FindPtrFromRelativeOffset:
	text:0000000000AD4D27    48 8B 0D 72 F8 78 03   mov  rcx, cs:cmdSystem_42645A8
	text:0000000000AD4D2E    48 8D 15 CB B2 F9 01   lea    rdx, aData1
*/
	logInfo("FindPtrFromRelativeOffset instructionStartAddress is %p", (void*)instructionStartAddress);
	//! adding 3 cause we want for ex the address of the "value" 72 F8 78 03 which is a relative offset, the value is little indian so the actual value is 0x378F872
	__int64 relativeOffsetAddr = instructionStartAddress + instructionOffset;
	HANDLE hProcess = GetCurrentProcess();	
	uint8_t buffer[4]; //! reading 4 cause it's an 4 bytes offset.	
	SIZE_T bytesRead;
	//! int and not uint as the offset has to be signed
	int relativeOffsetValue = 0;
	if (ReadProcessMemory(hProcess, (LPCVOID)relativeOffsetAddr, buffer, sizeof(buffer), &bytesRead)) {
		if (bytesRead == sizeof(buffer)) {
			// Successfully read 4 bytes. Convert the bytes to an integer value.
			int relativeOffsetValue = *reinterpret_cast<int*>(buffer);
			// Now 'value' contains the integer value read from memory.
			//logInfo("FindPtrFromRelativeOffset relativeOffsetValue value is %X", relativeOffsetValue);
			//! this is the value of rip as rip always has the address of the next instruction:
			__int64 nextInstructionAddress = instructionStartAddress + nextInstructionOffset;
			//logInfo("FindPtrFromRelativeOffset nextInstructionAddress is %p", (void*)nextInstructionAddress);
			//! in the example mov rcx,[DOOMEternalx64vk.exe+42645A0] means  mov rcx, [rip + relative offset] so as rip is pointing to the next instruction (D4D2E). We know rip and we know the relative offset so we find the ptr:
			__int64 ptr = nextInstructionAddress + relativeOffsetValue;
			logInfo("FindPtrFromRelativeOffset found ptr : %p", (void*)ptr);
			return ptr;
		}
		else {
			logErr("FindPtrFromRelativeOffset ReadProcessMemory did not read the expected number of bytes returning 0");
		}
	}
	else {
		logErr("FindPtrFromRelativeOffset Failed to read process memory. Error code: %d returning 0", GetLastError());
		
	}
	return 0;
}

int MemHelper::FindHardcodedOffset(uintptr_t instructionStartAddress, const int instructionOffset) {
	logDebug("FindHardcodedOffset");

	logInfo("FindHardcodedOffset instructionStartAddress is %p", (void*)instructionStartAddress);
	__int64 relativeOffsetAddr = instructionStartAddress + instructionOffset;
	HANDLE hProcess = GetCurrentProcess();
	uint8_t buffer[4]; //! reading 4 cause it's an 4 bytes offset.	
	SIZE_T bytesRead;
	if (ReadProcessMemory(hProcess, (LPCVOID)relativeOffsetAddr, buffer, sizeof(buffer), &bytesRead)) {
		if (bytesRead == sizeof(buffer)) {
			int hardcodedOffset = *reinterpret_cast<int*>(buffer);
			//logInfo("FindHardcodedValue relativeOffsetValue value is %X", relativeOffsetValue);	
			logInfo("FindHardcodedOffset returning hardcodedOffset : 0x%X", hardcodedOffset);
			return hardcodedOffset;
		}
		else {
			logErr("FindHardcodedOffset ReadProcessMemory did not read the expected number of bytes returning 0");
		}
	}
	else {
		logErr("FindHardcodedOffset Failed to read process memory. Error code: %d returning 0", GetLastError());
	}
	return 0;

}



// Define the pattern_to_byte lambda outside of PatternScan
static auto pattern_to_byte = [](const char* pattern)
	{
		auto bytes = std::vector<char>{};
		auto start = const_cast<char*>(pattern);
		auto end = const_cast<char*>(pattern) + strlen(pattern);

		for (auto current = start; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;
				if (*current == '?')
					++current;
				bytes.push_back('\?');
			}
			else
			{
				bytes.push_back(strtoul(current, &current, 16));
			}
		}
		return bytes;
	};

DWORD64 MemHelper::PatternScan(const char* szModule, const char* signature)
{
	logDebug("PatternScan");

	MODULEINFO mInfo;
	HMODULE hModule = GetModuleHandleA(szModule);

	if (hModule == nullptr)
	{
		logErr("GetModuleHandleA failed to find the module: %s returning", szModule);
		return 0; // Module not found, return an appropriate value (0 in this case).
	}

	K32GetModuleInformation(GetCurrentProcess(), hModule, &mInfo, sizeof(MODULEINFO));
	DWORD64 base = (DWORD64)mInfo.lpBaseOfDll;
	DWORD64 sizeOfImage = (DWORD64)mInfo.SizeOfImage;
	auto patternBytes = pattern_to_byte(signature);

	DWORD64 patternLength = patternBytes.size();
	auto data = patternBytes.data();

	for (DWORD64 i = 0; i < sizeOfImage - patternLength; i++)
	{
		bool found = true;
		for (DWORD64 j = 0; j < patternLength; j++)
		{
			char a = '\?';
			char b = *(char*)(base + i + j);
			found &= data[j] == a || data[j] == b;
		}
		if (found)
		{
			DWORD64 result = base + i;
			logInfo("PatternScan Success. Found Addr: %p", (void*)result);
			return result;
		}
	}

	logErr("!!! PatternScan failed !!!");
	return 0;
}

DWORD64 MemHelper::ModulePatternScan(std::string scanFriendlyName, const char* signature)
{
	logDebug("ModulePatternScan");

	MODULEINFO mInfo;
	HMODULE hModule = GetModuleHandleA(doomEternalExeName.c_str());

	if (hModule == nullptr)
	{
		logErr("GetModuleHandleA failed to find the module: %s returning", doomEternalExeName.c_str());
		return 0; // Module not found, return an appropriate value (0 in this case).
	}

	K32GetModuleInformation(GetCurrentProcess(), hModule, &mInfo, sizeof(MODULEINFO));
	DWORD64 base = (DWORD64)mInfo.lpBaseOfDll;
	DWORD64 sizeOfImage = (DWORD64)mInfo.SizeOfImage;
	auto patternBytes = pattern_to_byte(signature);

	DWORD64 patternLength = patternBytes.size();
	auto data = patternBytes.data();

	for (DWORD64 i = 0; i < sizeOfImage - patternLength; i++)
	{
		bool found = true;
		for (DWORD64 j = 0; j < patternLength; j++)
		{
			char a = '\?';
			char b = *(char*)(base + i + j);
			found &= data[j] == a || data[j] == b;
		}
		if (found)
		{
			DWORD64 result = base + i;
			logInfo("PatternScan Success for %s Found Addr: %p", scanFriendlyName.c_str(), (void*)result);
			return result;
		}
	}

	logErr("!!! PatternScan failed for: %s", scanFriendlyName.c_str());
	return 0;
}

//! Original func, keep it:
//DWORD64 MemHelper::PatternScan(const char* szModule, const char* signature)
//{
//	logDebug("PatternScan");
//	static auto pattern_to_byte = [](const char* pattern)
//		{
//			auto bytes = std::vector<char>{};
//			auto start = const_cast<char*>(pattern);
//			auto end = const_cast<char*>(pattern) + strlen(pattern);
//
//			for (auto current = start; current < end; ++current)
//			{
//				if (*current == '?')
//				{
//					++current;
//					if (*current == '?')
//						++current;
//					bytes.push_back('\?');
//				}
//				else
//				{
//					bytes.push_back(strtoul(current, &current, 16));
//				}
//			}
//			return bytes;
//		};
//
//	MODULEINFO mInfo;
//	K32GetModuleInformation(GetCurrentProcess(), GetModuleHandleA(szModule), &mInfo, sizeof(MODULEINFO));
//	//MODULEINFO mInfo = GetModuleInfo(module);
//	DWORD64 base = (DWORD64)mInfo.lpBaseOfDll;
//	DWORD64 sizeOfImage = (DWORD64)mInfo.SizeOfImage;
//	auto patternBytes = pattern_to_byte(signature);
//
//	DWORD64 patternLength = patternBytes.size();
//	auto data = patternBytes.data();
//
//	for (DWORD64 i = 0; i < sizeOfImage - patternLength; i++)
//	{
//		bool found = true;
//		for (DWORD64 j = 0; j < patternLength; j++)
//		{
//			char a = '\?';
//			char b = *(char*)(base + i + j);
//			found &= data[j] == a || data[j] == b;
//		}
//		if (found)
//		{
//			DWORD64 result = base + i;
//			logInfo("PatternScan Succes. Found Addr: %p", (void*)result);
//			return result;
//			//return base + i;
//		}
//	}
//	logErr("!!! PatternScan failed !!!");
//	return 0;
//}






