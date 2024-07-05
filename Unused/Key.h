#pragma once
#include <windows.h>
#include <string>

class Key
{
private:
	std::string  m_label;
	unsigned long m_scanCode;
	bool m_isExtended;

public:
	Key(std::string label, unsigned int scanCode, bool isExtended)
	{
		m_label = label;
		m_scanCode = scanCode;
		m_isExtended = isExtended;
	}

	std::string getLabel();
	unsigned long getScanCode();
	bool getIsExtended();
};

