#include <Windows.h>

#include <fstream>

#include "console.hpp"

#include "../hooks/hooks.hpp"
#include "../Common/loguru.hpp"
#include "../../Config.h"



//! uncomment this if you don't want to have the console show anymore
#define DISABLE_LOGGING_CONSOLE

//! the only way i found to not have the game close it self when we disable the mod using Xenos but it doesn't work as intended as the console is ALWAYS created when the mod start but  it works well enough for debug purposes, i spent the whole funking day on this, 
void Console::Enable( ) {
#ifndef DISABLE_LOGGING_CONSOLE

	loguru::g_preamble_thread = false;
	loguru::g_preamble_date = false;
	loguru::g_preamble_uptime = false;
	loguru::g_stderr_verbosity = loguru::Verbosity_INFO;

	bool isConsoleAlreadyExist = false;

	if (!GetConsoleWindow()) {
		//isConsoleAlreadyOpen = false;
		AllocConsole();
		SetConsoleTitleA("DE Advanced Options Mod - Debug Console");

		freopen_s(reinterpret_cast<FILE**>(stdin), "conin$", "r", stdin);
		freopen_s(reinterpret_cast<FILE**>(stdout), "conout$", "w", stdout);
		freopen_s(reinterpret_cast<FILE**>(stderr), "conout$", "w", stderr);
	}
	else {
		isConsoleAlreadyExist = true;
	}

	// Show the console window
	::ShowWindow(GetConsoleWindow(), SW_SHOW);
	/*if (isConsoleAlreadyExist) {
		logInfo("Console already exist, using existing one");
	}
	else {
		logInfo("Console does NOT exist, allocating one");
	}*/


	/*AllocConsole( );

	SetConsoleTitleA("UniversalHookX - Debug Console");
	

	freopen_s(reinterpret_cast<FILE**>(stdin), "conin$", "r", stdin);
	freopen_s(reinterpret_cast<FILE**>(stdout), "conout$", "w", stdout);
	freopen_s(reinterpret_cast<FILE**>(stderr), "conout$", "w", stderr);

	::ShowWindow(GetConsoleWindow( ), SW_SHOW);*/
#endif
}

void Console::Hide( ) {
#ifndef DISABLE_LOGGING_CONSOLE
	/*freopen_s(nullptr, "NUL", "r", stdin);
	freopen_s(nullptr, "NUL", "w", stdout);
	freopen_s(nullptr, "NUL", "w", stderr);*/
	//logInfo("1");
	//FreeConsole();
	//logInfo("2");

	//fclose(stdin);
	//logInfo("3");

	//fclose(stdout);
	//logInfo("4");

	//fclose(stderr);
	//logInfo("5");

	// Hide the console window instead of freeing the console
	::ShowWindow(GetConsoleWindow(), SW_HIDE);

	//FreeConsole();

	/*if (H::bShuttingDown) {
		logInfo("6");

		::ShowWindow(GetConsoleWindow( ), SW_HIDE);
	} else {
		logInfo("7");
		FreeConsole( );
	}*/
#endif
}
