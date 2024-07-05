#pragma once

#include <chrono>
#include <windows.h>
#include <mmsystem.h>
//#include "resource1.h"
//#include "resource.h"
#include <string>
#include <locale>
#include <codecvt>
#include <thread>
#include <string_view>


uint64_t EpochMillis();

std::wstring StandardKeyToStringW(DWORD VKey);

std::string getBuildDate();


static bool isStrStartsWith(const char* ptr, const char* templateCharPtr) {
	std::string_view sv(ptr);
	size_t strLength = 0;
	while (sv[strLength] != '\0') {
		++strLength;
	}
	if (sv.starts_with(templateCharPtr)) {
		return true;
	}
	return false;
}


//static bool areCStrsEqual(const char* str1, const char* str2) {
//	while (*str1 && (*str1 == *str2)) {
//		++str1;
//		++str2;
//	}
//	return (*str1 == *str2); // Return true if both strings have the same null character.
//}


static bool AreStringsEqual(const char* str1, const char* str2) {	
	//logDebug("AreStringsEqual");
	return strcmp(str1, str2) == 0;
}


static uint64_t EpochMillis() {
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

static std::wstring StandardKeyToStringW(DWORD VKey)
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


static std::string wide_to_narrow(const std::wstring& wide_str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
	return convert.to_bytes(wide_str);
}

static std::string getBuildDate()
{
	std::string date = __DATE__;
	std::string time = __TIME__;
	return date + " " + time;
}



static void PlayModLoadSuccesBeeps() {
	/*Beep(880, 100);
	Beep(1760, 100);*/

	Beep(558, 100);
	Beep(837, 100);
	
}

static void PlayModUnloadedBeeps() {
	/*Beep(880, 100);
	Beep(1760, 100);*/
	
	Beep(837, 100);
	Beep(558, 100);

}

static void playWeaponSwitchOverideSound() {
	Beep(1500, 50);
}

static void playWeaponSwitchOverideSoundAsync() {
	// Create a thread to play the Beep sound
	std::thread beep([]() {
		Beep(1500, 50); // Replace the values with your desired frequency and duration
		});

	// Detach the thread so that it can continue playing the sound in the background
	beep.detach();
}

static void playWavModLoadSucces() { //? for some reason there is no sound when using this.
	//PlaySound(TEXT("ModLoadedBeeps.wav"), NULL, SND_ASYNC);
	/*PlaySound(
		MAKEINTRESOURCE(IDR_WAVE1),
		GetModuleHandle(NULL),
		SND_RESOURCE | SND_ASYNC);*/

	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMSTART, NULL, SND_ALIAS_ID); //! this works.
	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMDEFAULT, NULL, SND_ALIAS_ID); //! this works.
	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMEXCLAMATION, NULL, SND_ALIAS_ID); //! this works.
	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMEXIT, NULL, SND_ALIAS_ID); //! this works.
	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMHAND, NULL, SND_ALIAS_ID); //! this works.
	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMQUESTION, NULL, SND_ALIAS_ID); //! this works.
	//PlaySound((LPCTSTR)SND_ALIAS_SYSTEMWELCOME, NULL, SND_ALIAS_ID); //! this works.
}

//static void playWindowsErrorSound() { //? for some reason there is no sound when using this.
//	PlaySound((LPCTSTR)SND_ALIAS_SYSTEMEXCLAMATION, NULL, SND_ALIAS_ID);
//}
//
//static void showHoorErrorMessageBox() { //? for some reason there is no sound when using this.
//	MessageBox(NULL, L"Hooking Error", L"Dedicated Grenade Mod", 0);	
//
//}

//SND_LOOP | SND_ASYNC

