
#pragma once

#include "CommonDE.h"

class CustomWeapon
{
private:
     std::string m_nameStr = "0";
     float m_zoomedFOV = 0;
     float m_zoomedHandsFOV = 0;
     float m_controllerSens = 0;
     float m_mouseSens = 0;

public:
    CustomWeapon(std::string nameStr, float zoomedFOV, float zoomedHandsFOV, float controllerSens, float mouseSens);

    void print();

    std::string getNameStr();
    float getZoomedFov();
    float getzoomedHandsFOV();
    float getControllerSens();
    float getMouseSens();

    void setZoomedFov(float val);

    void setzoomedHandsFOV(float val);

    void setControllerSens(float settingsValPrct);  //! the input value should between 0 and 100
   
    void setMouseSens(float settingsValPrct);  //! the input value should between 0 and 100
};









//#pragma once
//
//#include "CommonDE.h"
//
//
///// <summary>
///// this is used to customize a idDeclWeapon to change the fov of the secondary if it has a zoom and change its mouse or controller sensitivity.
///// </summary>
//class CustomWeapon
//{
//
//private:
//	std::string m_nameStr = "0";
//	//declWeaponModId m_id = undefinedModId;
//	float m_zoomedFOV = 0;
//	float m_zoomedHandsFOV = 0;
//	float m_controllerSens = 0;
//	float m_mouseSens = 0;
//
//public:
//	
//
//	CustomWeapon(std::string nameStr, float zoomedFOV, float zoomedHandsFOV, float controllerSens, float mouseSens) : m_nameStr{ nameStr }, m_zoomedFOV{ zoomedFOV }, m_zoomedHandsFOV{ zoomedHandsFOV }, m_controllerSens{ controllerSens }, m_mouseSens{ mouseSens }
//	{
//
//	}
//
//	void print() {
//		logInfo("CustomWeapon: name: %s zoomedFov: %.2f zoomedHandsFOV: %.2f controllerSens: %.2f mouseSens: %.2f", m_nameStr.c_str(), m_zoomedFOV, m_zoomedHandsFOV, m_controllerSens, m_mouseSens);
//	}
//
//	
//
//	std::string getNameStr() {
//		return m_nameStr;
//	}
//	float getZoomedFov() {
//		return m_zoomedFOV;
//	}
//	float getzoomedHandsFOV() {
//		return m_zoomedHandsFOV;
//	}
//	float getControllerSens() {
//		return m_controllerSens;
//	}
//	float getMouseSens() {
//		return m_mouseSens;
//	}
//
//	void setZoomedFov(float val) {
//		m_zoomedFOV = val;
//	}
//	void setzoomedHandsFOV(float val) {
//		m_zoomedHandsFOV = val;
//	}
//	void setControllerSens(float val) {
//		m_controllerSens = val;
//	}
//	void setMouseSens(float val) {
//		m_mouseSens = val;
//	}
//
//};
//
//
