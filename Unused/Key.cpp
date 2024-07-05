#include "Key.h"

std::string Key::getLabel()
{
    return m_label;
}

unsigned long Key::getScanCode()
{
    return m_scanCode;
}

bool Key::getIsExtended()
{
    return m_isExtended;
}
