#pragma once
#include <windows.h>
#include <sapi.h>
//#include <string>
//#include <codecvt>
//#include <map>
#include <string>
//#include "spdlog/spdlog.h"
#include <queue>
//#include "Config/Config.h"
#include "../Config/Config.h"





//#include "Config.h"


class TTS
{
private:
    static std::queue<std::wstring> m_wstrsQueue;
    //void addToQueue(std::wstring str);

public:
    //void say(std::wstring& wstr);        
    static void addToQueue(std::wstring wstr);
    static void sayAllInQueue();


    //void sayWrongGameNameError();
    //void sayHookingError();
};



//void TTS_Say(const std::wstring& input);
//
//void TTS_Say2(const std::wstring& input);



