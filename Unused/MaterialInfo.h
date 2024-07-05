#pragma once


#include <Windows.h>
#include <algorithm>
#include <string>
#include <vector>

///Mainly used for debug and finding the materials we might want for the custom hub
class MaterialInfo
{

public:
	std::string Name;
	bool ExtraInfo = false;
	__int64 IdDeclInfoPtr = 0;

	//! atm i don't know what that bool actually is, hence why it's called extraInfo.
	MaterialInfo(__int64 idDeclInfoPtr, std::string name, bool extraInfo)
	{
		IdDeclInfoPtr = idDeclInfoPtr;
		Name = name;
		ExtraInfo = extraInfo;
	}
};


