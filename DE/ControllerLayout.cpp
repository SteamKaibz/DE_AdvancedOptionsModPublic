#include "ControllerLayout.h"

ControllerLayout::ControllerLayout(std::string name, unsigned int ControllerLayoutOffset, int equipmentLauncherStrOffset, int missionInfoStrOffset)
{
    m_name = name;
    m_idStrOffset = ControllerLayoutOffset;
    m_equipmentLauncherStrPtrOffset = equipmentLauncherStrOffset;
    m_missionInfoStrPtrOffset = missionInfoStrOffset;
}

ControllerLayout::ControllerLayout(std::string name, unsigned int ControllerLayoutOffset, std::vector<int> stringsAddrOffsetsVec)
{
    m_name = name;
    m_idStrOffset = ControllerLayoutOffset;
    m_stringAddrOffsetsVec = stringsAddrOffsetsVec;
}


void ControllerLayout::overwriteBindLabels(LocalizedBindStringData& localBindStringData, uintptr_t idStrListFirstPtr)
{
    // Method definition
}

std::string ControllerLayout::getLayoutName()
{
    // Method definition
    return m_name;
}

unsigned int ControllerLayout::getControllerLayoutOffset()
{
    // Method definition
    return m_idStrOffset;
}

int ControllerLayout::getEquipmentLauncherStrOffset()
{
    // Method definition
    return m_equipmentLauncherStrPtrOffset;
}

int ControllerLayout::getMissionInfoStrOffset()
{
    // Method definition
    return m_missionInfoStrPtrOffset;
}

void ControllerLayout::overwriteBindLabel(uintptr_t idStrAddr, int bindStrOffset, std::u8string& replacementStr)
{
    // Method definition
}
