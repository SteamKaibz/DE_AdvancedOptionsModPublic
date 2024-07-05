#include "CustomWeapon.h"

CustomWeapon::CustomWeapon(std::string nameStr, float zoomedFOV, float zoomedHandsFOV, float controllerSens, float mouseSens)
{
    m_nameStr = nameStr;
    m_zoomedFOV = zoomedFOV;
    m_zoomedHandsFOV = zoomedHandsFOV;
    m_controllerSens = controllerSens;
    m_mouseSens = mouseSens;
}

void CustomWeapon::print()
{
    logInfo("CustomWeapon: name: %s zoomedFov: %.2f zoomedHandsFOV: %.2f controllerSens: %.2f mouseSens: %.2f", m_nameStr.c_str(), m_zoomedFOV, m_zoomedHandsFOV, m_controllerSens, m_mouseSens);
}

std::string CustomWeapon::getNameStr()
{
    return m_nameStr;
}

float CustomWeapon::getZoomedFov()
{
    return m_zoomedFOV;
}

float CustomWeapon::getzoomedHandsFOV()
{
    return m_zoomedHandsFOV;
}

float CustomWeapon::getControllerSens()
{
    return m_controllerSens;
}

float CustomWeapon::getMouseSens()
{
    return m_mouseSens;
}

void CustomWeapon::setZoomedFov(float val)
{
    m_zoomedFOV = val;
}

void CustomWeapon::setzoomedHandsFOV(float val)
{
    m_zoomedHandsFOV = val;
}

void CustomWeapon::setControllerSens(float settingsValPrct) //! the input value should between 0 and 100
{
    m_controllerSens = settingsValPrct;
}

void CustomWeapon::setMouseSens(float settingsValPrct) //! the input value should between 0 and 100
{
    m_mouseSens = settingsValPrct;
}
