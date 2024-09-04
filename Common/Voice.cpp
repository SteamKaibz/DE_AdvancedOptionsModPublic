#include "Voice.h"

void TTS_Say(const std::wstring& input)
{
	try
	{
		using namespace std;

		ISpVoice* pVoice = NULL; //just a function to process voice
		HRESULT hr;
		//wstring input = L"ERROR, mod can not start!"; //used to take in sound 
		auto a = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
		if (FAILED(a))
		{
			logErr("TTS_Say: ERROR 404 FAILED INITIALIZING COM");
			//cout << "ERROR 404 FAILED INITIALIZING COM\n";
			return;
			//exit(1);
		}
		HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
		hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice); // just some code to handle things when there is an error

		if (SUCCEEDED(hr))
		{
			try
			{
				hr = pVoice->Speak(input.c_str(), 0, NULL);
				pVoice->Release();
				pVoice = NULL; //does the work
			}
			catch (const std::exception& ex)
			{
				logErr("TTS_Say exception 1: %s ", ex.what());
			}
			//getline(wcin, input);
		
		}
		return;
	}
	catch (const std::exception& ex)
	{
		logErr("TTS_Say exception 2: %s ", ex.what());

	}
	
}





//void TTS::say(std::wstring& wstr)
//{
//	TTS_Say(wstr);
//}

std::queue<std::wstring> TTS::m_wstrsQueue{};

/// <summary>
/// this will not say the wstring right away to prevent it from freezing/slowing execution in hook functions and instead use TTS in mail loop
/// </summary>
/// <param name="wstr"></param>
void TTS::addToQueue(std::wstring wstr)
{
	m_wstrsQueue.push(wstr);
}

void TTS::sayAllInQueue()
{
	while (!m_wstrsQueue.empty())
	{
		TTS_Say(m_wstrsQueue.front());
		m_wstrsQueue.pop();
	}
}
