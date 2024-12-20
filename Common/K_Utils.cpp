#include "K_Utils.h"



bool K_Utils::IsBitSet(int value, int bitPosition) {
	if (bitPosition < 0 || bitPosition > 31) {
		logErr("IsBitSet: Bit position %d is out of range (0-31). ", bitPosition);
		return false;
	}
	return (value & (1 << bitPosition)) != 0;
}


uint64_t K_Utils::EpochMillis()
{
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

std::string K_Utils::unicode_to_utf8(wchar_t* wide_string)
{
	if (wide_string == nullptr)

		return std::string();

	// Calculate the size of the buffer needed for the conversion
	int buffer_size = WideCharToMultiByte(CP_UTF8, 0, wide_string, -1, nullptr, 0, nullptr, nullptr);
	if (buffer_size == 0)
	{
		throw std::runtime_error("Failed to convert wide string to UTF-8.");
	}

	// Create a buffer for the UTF-8 string
	std::string utf8_string(buffer_size, '\0');

	// Perform the conversion from wide string to UTF-8
	if (WideCharToMultiByte(CP_UTF8, 0, wide_string, -1, utf8_string.data(), buffer_size, nullptr, nullptr) == 0)
	{
		throw std::runtime_error("Failed to convert wide string to UTF-8.");
	}

	// Resize the string to remove the null terminator
	utf8_string.resize(buffer_size - 1);

	return utf8_string;
}

std::string K_Utils::getBuildDate()
{
	std::string date = __DATE__;
	std::string time = __TIME__;
	return date + " " + time;
}

void K_Utils::PlayModLoadSuccesBeeps()
{
	Beep(558, 100);
	Beep(837, 100);
}

void K_Utils::PlayModLoadFailBeeps()
{
	Beep(400, 100);
	Beep(170, 500);
}


void K_Utils::PlayModUnloadedBeeps()
{

	Beep(837, 100);
	Beep(558, 100);
}

void K_Utils::PlayFileGeneratedBeeps()
{
	Beep(900, 100);
	Beep(900, 100);
}

void K_Utils::PlayModeFileLoadedBeeps()
{
	Beep(600, 100);
	Beep(700, 100);
	Beep(800, 100);
}

std::wstring K_Utils::StandardKeyToStringW(DWORD VKey)
{
	static WCHAR name[32] = L"";
	static BYTE kbState[256] = { 0 };
	DWORD idThread;
	idThread = GetWindowThreadProcessId(GetForegroundWindow(), nullptr);
	long code = MapVirtualKeyExW(VKey, MAPVK_VK_TO_VSC,
		GetKeyboardLayout(idThread)) << 16;
	ToUnicodeEx(VKey, MapVirtualKey(VKey, MAPVK_VK_TO_VSC), kbState, name,
		32, 0, GetKeyboardLayout(idThread));
	return name;
}



std::string K_Utils::wide_to_narrow(const std::wstring& wide_str) {
	int requiredSize = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, nullptr, 0, nullptr, nullptr);
	if (requiredSize == 0) {
		// Handle error
		return "";
	}

	std::string narrow_str(requiredSize, '\0');
	WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, &narrow_str[0], requiredSize, nullptr, nullptr);

	return narrow_str;
}

//std::string K_Utils::wide_to_narrow(const std::wstring& wide_str)
//{
//	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
//	return convert.to_bytes(wide_str);
//}


bool K_Utils::AreStringsEqual(const char* str1, const char* str2) {
	//logDebug("AreStringsEqual");
	return strcmp(str1, str2) == 0;
}


std::wstring K_Utils::WstrtoLower(const std::wstring& input) {
	std::wstringstream wss;
	const std::ctype<wchar_t>& facet = std::use_facet<std::ctype<wchar_t>>(wss.getloc());

	for (wchar_t ch : input) {
		wss << facet.tolower(ch);
	}

	return wss.str();
}


std::string K_Utils::replaceDoubleScopeWithUnderscore(std::string input) {
	std::regex doubleScope("::");
	return std::regex_replace(input, doubleScope, "_");
}


std::string K_Utils::intToHexString(__int64 decimalValue) {
	std::stringstream ss;
	//ss << "0x" << std::hex << decimalValue;
	ss << "0x" << std::uppercase << std::hex << decimalValue;
	return ss.str();
}


std::string K_Utils::ptrToHexString(void* addr) {
	std::stringstream ss;
	ss << "0x" << std::uppercase << std::hex << reinterpret_cast<uintptr_t>(addr);
	return ss.str();
}

std::string K_Utils::getBoolAsStr(bool isTrue) {
	if (isTrue) {
		return "true";
	}
	return "false";
}

std::string K_Utils::toStringWithPrecision(float value, int nDecimals) {
	std::ostringstream out;
	out << std::fixed << std::setprecision(nDecimals) << value;
	return out.str();
}


std::string K_Utils::floatToStringWithoutTrailingZeros(float value) {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(9) << value; // Set precision to maximum number of significant digits

	std::string valueString = ss.str();

	// Remove trailing zeros after the decimal point
	size_t pos = valueString.find('.');
	if (pos != std::string::npos) {
		size_t end = valueString.size() - 1;
		while (end > pos && valueString[end] == '0') {
			end--;
		}
		if (end == pos) {
			// If the last non-zero character is the decimal point, remove it too
			valueString.erase(pos);
		}
		else {
			// If the last non-zero character is a digit, erase trailing zeros
			valueString.erase(end + 1);
		}
	}

	return valueString;
}



bool K_Utils::caseInsensitiveCompare(const std::string& str1, const std::string& str2) {
	// Convert both strings to lowercase for comparison
	std::string str1Lower, str2Lower;
	for (char c : str1) str1Lower += std::tolower(c);
	for (char c : str2) str2Lower += std::tolower(c);

	// Compare lowercase strings
	return str1Lower < str2Lower;
}


bool K_Utils::compareEventNames(const idEventDef* a, const idEventDef* b) {
	if (a->name && b->name) {
		return std::string(a->name) < std::string(b->name);
	}
	// Handle null names by placing them at the end of the sorted list
	return a->name != nullptr;
}



bool K_Utils::saveSetToFile(std::string fileName, std::set<std::string> StrSet)
{
	int counter = 0;
	std::ofstream outputFile(fileName);
	if (!outputFile.is_open()) {
		logErr("saveSetToFile: Error opening file %s for writing returning", fileName.c_str());
		return false;
	}
	for (const auto& entity : StrSet) {
		outputFile << entity << std::endl;
		counter++;
	}
	outputFile.close();
	logInfo("saveSetToFile: %d elements were saved to file: %s ", counter, fileName.c_str());
	return true;
}

bool K_Utils::saveVecToFile(std::string fileName, std::vector<std::string> StrVec)
{
	int counter = 0;
	std::ofstream outputFile(fileName);
	if (!outputFile.is_open()) {
		logErr("saveVecToFile: Error opening file %s for writing returning", fileName.c_str());
		return false;
	}
	for (const auto& entity : StrVec) {
		outputFile << entity << std::endl;
		counter++;
	}
	outputFile.close();
	logInfo("saveVecToFile: %d elements were saved to file: %s ", counter, fileName.c_str());
	return true;
}


//! using this to generate clean strings from ida, we could improve this by removing the str which start with a space, number, symbol...but that will do for now.
void K_Utils::removeDuplicatesAndSort(const std::string& inputFilePath, const std::string& outputFilePath) {
	
	logInfo("removeDuplicatesAndSort: starting....(this might take a while)");

	std::ifstream inputFile(inputFilePath);
	if (!inputFile.is_open()) {
		logErr("removeDuplicatesAndSort: Error opening input file: %s. Returning.", inputFilePath.c_str());
		return;
	}

	// Read lines from input file into a set to remove duplicates
	std::set<std::string> uniqueLines;
	std::string line;
	while (std::getline(inputFile, line)) {
		uniqueLines.insert(line);
	}
	inputFile.close();

	// Convert set to vector for sorting
	std::vector<std::string> sortedLines(uniqueLines.begin(), uniqueLines.end());

	// Sort the lines
	std::sort(sortedLines.begin(), sortedLines.end());

	// Open output file
	std::ofstream outputFile(outputFilePath);
	if (!outputFile.is_open()) {
		logErr("removeDuplicatesAndSort: Error opening output file: %s. Returning.", outputFilePath.c_str());
		return;
	}

	// Write sorted lines to output file
	for (const auto& sortedLine : sortedLines) {
		outputFile << sortedLine << '\n';
	}
	outputFile.close();

	logInfo("removeDuplicatesAndSort: Duplicates removed and lines sorted. File contains %zu strings. Saved to: %s", uniqueLines.size(), outputFilePath.c_str());
}



void K_Utils::sortStringsByName(const std::string& inputFilePath, const std::string& outputFilePath) {
	// Open input file
	std::ifstream inputFile(inputFilePath);
	if (!inputFile.is_open()) {
		logErr("Error opening input file: %s. Returning.", inputFilePath.c_str());
		return;
	}

	// Read lines from input file into a vector
	std::vector<std::string> lines;
	std::string line;
	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();

	// Sort the lines
	std::sort(lines.begin(), lines.end());

	// Open output file
	std::ofstream outputFile(outputFilePath);
	if (!outputFile.is_open()) {
		logErr("Error opening output file: %s. Returning.", outputFilePath.c_str());
		return;
	}

	// Write sorted lines to output file
	for (const auto& sortedLine : lines) {
		outputFile << sortedLine << '\n';
	}
	outputFile.close();

	logErr("Lines sorted by name. Saved to: %s", outputFilePath.c_str());
}



void K_Utils::fileRemoveDuplicates(const std::string& inputFilePath, const std::string& outputFilePath) {
	std::ifstream inputFile(inputFilePath);
	if (!inputFile.is_open()) {
		logErr("fileRemoveDuplicates: Error opening input file : %s returning", inputFilePath.c_str());
		return;
	}

	std::set<std::string> uniqueLines;
	std::string line;
	while (std::getline(inputFile, line)) {
		uniqueLines.insert(line);
	}

	inputFile.close();

	std::ofstream outputFile(outputFilePath);
	if (!outputFile.is_open()) {
		logErr("fileRemoveDuplicates: Error opening output file : %s returning", outputFilePath.c_str());
		return;
	}

	for (const auto& uniqueLine : uniqueLines) {
		outputFile << uniqueLine << '\n';
	}

	outputFile.close();

	logInfo("fileRemoveDuplicates: Duplicates removed. Unique lines saved to:: %s ", outputFilePath.c_str());
}

std::set<std::string> K_Utils::loadFileToSet(std::string inputFilePath)
{
	int counter = 0;
	std::set<std::string> uniqueStrsSet;

	std::ifstream inputFile(inputFilePath);

	if (!inputFile.is_open()) {
		logErr("loadFileToSet: Error opening file: %s returning", inputFilePath.c_str());
		return uniqueStrsSet;
	}
		
	
	std::string line;
	while (std::getline(inputFile, line)) {
		uniqueStrsSet.insert(line);  // Insert the line into the set (automatically removes duplicates)
		counter++;
	}
	inputFile.close();

	logInfo("loadFileToSet: found %d elements in file: %s ", counter, inputFilePath.c_str());
	return uniqueStrsSet;
}



// Function to call RtlGetVersion and get the full version info
RTL_OSVERSIONINFOW  K_Utils::GetWindowsVersionInfo() {
	typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);
	RTL_OSVERSIONINFOW rovi = { 0 };
	rovi.dwOSVersionInfoSize = sizeof(rovi);

	RtlGetVersionPtr RtlGetVersion = (RtlGetVersionPtr)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "RtlGetVersion");
	if (RtlGetVersion != nullptr) {
		RtlGetVersion(&rovi);
	}
	return rovi;
}

std::string  K_Utils::GetWindowsVersion() {
	std::string version = "Windows ";
	RTL_OSVERSIONINFOW osInfo = GetWindowsVersionInfo();

	// Check for Windows version using MajorVersion and BuildNumber
	if (osInfo.dwMajorVersion == 10) {
		if (osInfo.dwBuildNumber >= 22000) {
			version += "11";
		}
		else {
			version += "10";
		}
	}
	else if (osInfo.dwMajorVersion == 6) {
		if (osInfo.dwMinorVersion == 3) {
			version += "8.1";
		}
		else if (osInfo.dwMinorVersion == 2) {
			version += "8";
		}
		else if (osInfo.dwMinorVersion == 1) {
			version += "7";
		}
	}
	else {
		version += std::to_string(osInfo.dwMajorVersion) + "." + std::to_string(osInfo.dwMinorVersion);
	}

	version += " (Build " + std::to_string(osInfo.dwBuildNumber) + ")";
	return version;
}


std::string K_Utils::getCpuInfoStr() {
	

	/*int cpuInfo[4] = { -1 };
	__cpuid(cpuInfo, 0x80000002);
	char cpuBrand[0x40];
	memcpy(cpuBrand, cpuInfo, sizeof(cpuInfo));
	__cpuid(cpuInfo, 0x80000003);
	memcpy(cpuBrand + 16, cpuInfo, sizeof(cpuInfo));
	__cpuid(cpuInfo, 0x80000004);
	memcpy(cpuBrand + 32, cpuInfo, sizeof(cpuInfo));

	return std::string(cpuBrand);*/

	int cpuInfo[4] = { -1 };
	char cpuBrand[0x40] = { 0 }; // Ensure the array is zero-initialized

	__cpuid(cpuInfo, 0x80000002);
	memcpy(cpuBrand, cpuInfo, sizeof(cpuInfo));
	__cpuid(cpuInfo, 0x80000003);
	memcpy(cpuBrand + 16, cpuInfo, sizeof(cpuInfo));
	__cpuid(cpuInfo, 0x80000004);
	memcpy(cpuBrand + 32, cpuInfo, sizeof(cpuInfo));

	return std::string(cpuBrand);
}



const char* K_Utils::getAllowedKeyName(unsigned int vkCode)
{
	for (const auto& key : allowedKeyBindsKeyInfos)
	{
		if (key.vkCode == vkCode)
		{
			return key.name;
		}
	}
	logErr("getAllowedKeyName: failed to find str for key code: %u vkCode", vkCode);
	return "???";
}


unsigned int K_Utils::convertKeyStrToVkCode(std::string keyStr, unsigned int defaultVKCode) {
	
	unsigned int vkCodeResult = 0;


	for (const auto& key : allowedKeyBindsKeyInfos)
	{
		if (std::string(key.name) == keyStr)
		{			
			//logInfo("convertKeyStrToVkCode: debug: keyStr: %s key.vkCode: %u", keyStr.c_str(), key.vkCode);
			return key.vkCode;
		}
	}

	std::string validKeys;
	for (const auto& key : allowedKeyBindsKeyInfos)
	{
		validKeys += key.name;
		validKeys += ", ";
	}

	if (!validKeys.empty()) {
		validKeys.pop_back();
		validKeys.pop_back();
	}

	logWarn("convertKeyStrToVkCode: failed to parse vk code for input %s. Setting it to: %u. "
		"If you manually edited the json file, remember the only valid keys are: %s (without the comma of course)", keyStr.c_str(), defaultVKCode, validKeys.c_str());


	return defaultVKCode;
	
}

std::string K_Utils::convertVkCodeToKeyStr(unsigned int vkCode) {


	for (const auto& key : allowedKeyBindsKeyInfos)
	{
		if (key.vkCode == vkCode)
		{
			//logInfo("convertVkCodeToKeyStr: debug: vkCode: %u vkCode key.name: %s", vkCode, key.name);
			return std::string(key.name);
		}
	}

	// If no match is found, return a default or error string
	logWarn("convertVkCodeToKeyStr: No valid key found for vkCode: %u returning ???", vkCode);
	return "???";
}






//! going to use game data to get those infos
//? this almost work but we can not get the gpu driver info right. May be a solution would be to try this: https://github.com/SaschaWillems/vulkan.gpuinfo.org/blob/1e6ca6e3c0763daabd6a101b860ab4354a07f5d3/functions.php#L294
//std::string K_Utils::getGPUInfo() {
//	VkInstance instance;
//	VkApplicationInfo appInfo = {};
//	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//	appInfo.pApplicationName = "GPU Info App";
//	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
//	appInfo.pEngineName = "No Engine";
//	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
//	appInfo.apiVersion = VK_API_VERSION_1_0;
//
//	VkInstanceCreateInfo createInfo = {};
//	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//	createInfo.pApplicationInfo = &appInfo;
//
//	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
//		return "Failed to create Vulkan instance!";
//	}
//
//	uint32_t deviceCount = 0;
//	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
//
//	if (deviceCount == 0) {
//		vkDestroyInstance(instance, nullptr);
//		return "No GPUs with Vulkan support found!";
//	}
//
//	std::vector<VkPhysicalDevice> devices(deviceCount);
//	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
//
//	std::stringstream gpuInfoStream;
//	for (const auto& device : devices) {
//		VkPhysicalDeviceProperties properties;
//		vkGetPhysicalDeviceProperties(device, &properties);
//
//		uint32_t driverVersion = properties.driverVersion;
//		uint32_t major = (driverVersion >> 22) & 0x3FF;
//		uint32_t minor = (driverVersion >> 12) & 0x3FF;
//		uint32_t patch = driverVersion & 0xFFF;
//
//		gpuInfoStream << "GPU: " << properties.deviceName << "\n";
//		gpuInfoStream << "  Vulkan API Version: " << VK_VERSION_MAJOR(properties.apiVersion) << "."
//			<< VK_VERSION_MINOR(properties.apiVersion) << "."
//			<< VK_VERSION_PATCH(properties.apiVersion) << "\n";
//		gpuInfoStream << "  Driver Version: " << major << "." << minor << "." << patch << "\n";		
//		gpuInfoStream << "  Vendor ID: " << properties.vendorID << "\n";
//		gpuInfoStream << "  Device ID: " << properties.deviceID << "\n";
//	}
//
//	vkDestroyInstance(instance, nullptr);
//	return gpuInfoStream.str();
//}



//! don't list the same proces twice
//std::unordered_set<std::string> K_Utils::GetUniqueRunningProcessesSet()
//{
//	std::unordered_set<std::string> processSet;
//
//	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (hSnapshot == INVALID_HANDLE_VALUE)
//	{
//		return processSet;
//	}
//
//	PROCESSENTRY32 pe32;
//	pe32.dwSize = sizeof(PROCESSENTRY32);
//
//	if (!Process32First(hSnapshot, &pe32))
//	{
//		CloseHandle(hSnapshot);
//		return processSet;
//	}
//
//	do
//	{
//		processSet.insert(pe32.szExeFile);
//	} while (Process32Next(hSnapshot, &pe32));
//
//	CloseHandle(hSnapshot);
//
//	return processSet;
//}




//? these functions work in debug mode but not in release mode:
//std::string K_Utils::WideCharToMultiByte_K(const wchar_t* wideStr)
//{
//	// Convert wide-character string to narrow-character string
//	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
//	return converter.to_bytes(wideStr);
//}
//
//std::unordered_set<std::string> K_Utils::GetUniqueRunningProcessesSet()
//{
//	std::unordered_set<std::string> processSet;
//
//	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (hSnapshot == INVALID_HANDLE_VALUE)
//	{
//		return processSet;
//	}
//
//	PROCESSENTRY32 pe32;
//	pe32.dwSize = sizeof(PROCESSENTRY32);
//
//	if (!Process32First(hSnapshot, &pe32))
//	{
//		CloseHandle(hSnapshot);
//		return processSet;
//	}
//
//	do
//	{
//		// Convert wide-character string to narrow-character string
//		std::string processName = WideCharToMultiByte_K(pe32.szExeFile);
//		processSet.insert(processName);
//	} while (Process32Next(hSnapshot, &pe32));
//
//	CloseHandle(hSnapshot);
//
//	return processSet;
//}



//bool K_Utils::IsProcessRunning(const std::string& processName)
//{
//	logInfo("Checking if potentially conflicting process: %s is running....", processName.c_str());
//
//	std::wstring wProcessName(processName.begin(), processName.end());
//
//	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (hSnapshot == INVALID_HANDLE_VALUE)
//	{
//		return false;
//	}
//
//	PROCESSENTRY32 pe32;
//	pe32.dwSize = sizeof(PROCESSENTRY32);
//
//	if (!Process32First(hSnapshot, &pe32))
//	{
//		CloseHandle(hSnapshot);
//		return false;
//	}
//
//	bool isRunning = false;
//	do
//	{
//		wchar_t wCurrentProcessName[MAX_PATH];
//		MultiByteToWideChar(CP_ACP, 0, pe32.szExeFile, -1, wCurrentProcessName, MAX_PATH);
//
//		std::wstring currentProcessName(wCurrentProcessName);
//		if (currentProcessName == wProcessName)
//		{
//			isRunning = true;
//			break;
//		}
//	} while (Process32Next(hSnapshot, &pe32));
//
//	CloseHandle(hSnapshot);
//	return isRunning;
//}



//! RGBA

