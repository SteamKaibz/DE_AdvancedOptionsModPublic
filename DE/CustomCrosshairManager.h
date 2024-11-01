#pragma once
#include "idLib_Dynamic.h"
#include "../DE/idDeclWeaponReticleManager.h"
//#include "../DE/idSWFWidget_Hud_ReticleManager.h"
#include "idWeaponManager.h"


//todo 12/9/24: this is code from defunct kaibzHud mod project, but because atm the imgui crosshair works fine i do not really need it, but, if for any reason we notice performance issue in specific situations, going back to a crosshair that is only handled by the game gui using drawstretchpic could be the solution, if indeed the perf issue using it is now solved.
//class CrosshairDot {
//
//private:
//    float m_size = 4.0f;
//    idColor m_idColorFill = colorWhite;
//    idColor m_idColorOutline = colorBlack;
//    float m_outlineThickness = 1.0f;
//
//
//public:
//    CrosshairDot()
//    {
//
//    }
//
//    CrosshairDot(float size, float outlineThickness) : m_size(size), m_outlineThickness(outlineThickness)
//    {
//
//    }
//
//    CrosshairDot(float size, const idColor idColorFill, const idColor idColorOutline, float outlineThickness)
//        : m_size(size), m_idColorFill(idColorFill), m_idColorOutline(idColorOutline), m_outlineThickness(outlineThickness)
//    {
//
//        //m_fillRect = Rect(RectID::centerDot, m_centerX - m_size / 2, m_centerY - m_size / 2, m_size, m_size, m_materialPtr, m_idColorFill);
//    }
//
//
//
//    void setFillColor(const idColor& newColor) {
//        m_idColorFill = newColor;
//    }
//
//    void setOutlineColor(const idColor& newColor) {
//        m_idColorOutline = newColor;
//    }
//
//    const idColor getFillColor() {
//        return m_idColorFill;
//    }
//
//    const idColor getOutlineColor() {
//        return m_idColorOutline;
//    }
//
//    void setSize(float size) {
//        m_size = size;
//    }
//
//    float getSize() {
//        return m_size;
//    }
//
//    void setOutlineThickness(float thickness) {
//        m_outlineThickness = thickness;
//    }
//
//    float getOutlineThickness() {
//        return m_outlineThickness;
//    }
//
//};


//todo this was used by imgui but now could be repurposed to handled the game gui custom crosshair
class CustomCrosshairManager {

private:

	//static inline bool m_isWeaponCooldownFlag = false;	

public:

	//static bool getIsWeaponCooldownFlag();


	//static void updateData(bool isSlayerActiveFlag, bool isGameSettingsHudEnabled);


	//static void updateWeaponCooldownFlag(weaponSlot_t weaponSlot, bool isCooldownActive);

	//static void acquireWeaponCoolDownStatus(idSWFWidget_Hud_Reticle* idSWFWidget_Hud_ReticlePtr, idDeclWeaponReticle* declWeaponReticle);


};
