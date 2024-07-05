#pragma once

#include <Windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include "MemHelper.h"
#include "../Config/Config.h"

struct Patcher
{


	static bool patch(std::string patchNameStr, uintptr_t addr, const std::vector<unsigned char>& newInstructionVec);

	static bool patchIfNeeded(std::string patchNameStr, uintptr_t addr, const std::vector<unsigned char>& newInstructionVec);


};

//std::vector<unsigned char> Patcher::m_NewInstructionVec{};
//std::vector<unsigned char> Patcher::m_OriginalInstructionVec{};

//const unsigned int DrawStringOffset = 0x623B2F;
//const unsigned int SetupMSFOffset = 0x6248D1;


//static const std::vector<unsigned char> eternalFontOffsetPatch_88 = { 0x88, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_90 = { 0x90, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_98 =  { 0x98, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_A0 =  { 0xA0, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_A8 =  { 0xA8, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_B0 = { 0xB0, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_B8 =  { 0xB8, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_C0 =  { 0xC0, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_C8 =  { 0xC8, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_D0 =  { 0xD0, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_D8 =  { 0xD8, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_E0 = { 0xE0, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_E8 = { 0xE8, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontOffsetPatch_F0 = { 0xF0, 0x00, 0x00, 0x00 };
//
//static const std::vector<unsigned char> eternalFontDefaultOffsetPatch_F8 =  { 0xF8, 0x00, 0x00, 0x00 }; //! default font 




