#pragma once
//? not using this atm, may be if we ever implement a custom hud we'll come back to it

#include <vector>
//#include "Rectangle.h"
//#include "idColor.h"
#include "../DE/idColor.h"
#include "../DE/idLib.h"
//#include "../DE/Common.h"

//#include "Config/Config.h"


/// <summary>
/// Thoses are crossahir made with the game renderer. We won't be using this as it may impact performance by 1-5%. At least on old cpu.
/// </summary>

struct CustomCrosshair
{
    bool isShown;
    swfRect_t outlineRect;
    swfRect_t fillRect;
    idColor m_idColorOutline = colorBlack;
    idColor m_idColorFill = colorWhite; 
};



/// <summary>
/// rewriting crosshair class cause i messed the other one in way i can not understand....
/// </summary>
class CrosshairDot {

private:
    float m_size = 4.0f;   
    idColor m_idColorFill = colorWhite;
    idColor m_idColorOutline = colorBlack;
    float m_outlineThickness = 1.0f;


public:
    CrosshairDot()
    {

    }

    CrosshairDot(float size, float outlineThickness) : m_size(size), m_outlineThickness(outlineThickness)
    {

    }

    CrosshairDot(float size, const idColor idColorFill, const idColor idColorOutline, float outlineThickness)
        : m_size(size), m_idColorFill(idColorFill), m_idColorOutline(idColorOutline), m_outlineThickness(outlineThickness)
    {

        //m_fillRect = Rect(RectID::centerDot, m_centerX - m_size / 2, m_centerY - m_size / 2, m_size, m_size, m_materialPtr, m_idColorFill);
    }

 

    void setFillColor(const idColor& newColor) {
        m_idColorFill = newColor;
    }

    void setOutlineColor(const idColor& newColor) {
        m_idColorOutline = newColor;
    }

    const idColor getFillColor() {
        return m_idColorFill;
    }

    const idColor getOutlineColor() {
        return m_idColorOutline;
    }

    void setSize(float size) {
        m_size = size;
    }

    float getSize() {
        return m_size;
    }

    void setOutlineThickness(float thickness) {
        m_outlineThickness = thickness;
    }

    float getOutlineThickness() {
        return m_outlineThickness;
    }
    
};







/// <summary>
/// crosshair made with rectangles/squares filled with uniform material.
/// </summary>
//class VectorCrosshair {
//
//public:
//
//    std::vector<Rect> OutlineRectVec;
//    std::vector<Rect> FillRectVec;
//    bool hasOutline;
//    float outlineThickness;
//    float centerX = 0;
//    float centerY = 0;
//    float size = 0; // this would be 
//    const idColor& IdColorOutline;
//    const idColor& IdColorFill;
//    __int64 MaterialPtr;
//
//   
//    VectorCrosshair(float size_, bool hasOutline_, float outlineThickness_, const idColor& idColorOutline_, const idColor& idColorFill_)
//        :size(size_),hasOutline(hasOutline_), outlineThickness(outlineThickness_), IdColorOutline(idColorOutline_), IdColorFill(idColorFill_){
//    }
//   /* void updateCenterScreenCoordinates(float center_x, float center_y) {
//        centerX = center_x;
//        centerY = center_y;
//    }   */ 
//    virtual void generateRectangles() = 0; // virtual function, the = 0 means it HAS to be implemented by subclasses
//       
//};




//todo maybe we need a CrosshairHudDataMap cls which is a mapping a hud data to a specific element of the crosshair like frag to left bar or even is crosshair color health, ....

//? i don't think we need to make the exta dots info for the crosshair, let's reduce the motivation please and KISS....


//! With this we can create a crosshair cross plain with no dot by setting gap to 0, a dot by setting barScale_ to 0 and a cross+dot.
//class CrosshairCrossWithDot : public VectorCrosshair {
//
//public:
//
//    float gap;
//    float barScale;
//    const std::map<RectID, HudDataID>& dataMap;
//    const HudData& hudData;
//    bool hasHudData;
//
//    CrosshairCrossWithDot(float size_, bool hasOutline_, float outlineThickness_, const idColor& idColorOutline_, const idColor& idColorFill_,   float gap_, float barScale_, bool hasHudData_, const std::map<RectID, HudDataID>& dataMap_, const HudData& hudData_)
//        : VectorCrosshair(size_, hasOutline_, outlineThickness_, idColorOutline_, idColorFill_), gap(gap_), barScale(barScale_), hasHudData(hasHudData_), dataMap(dataMap_), hudData(hudData_){
//
//        generateRectangles();
//    }
//
//    //? keep in mind you'll have to updateColor centerX and centerY if you updateColor anything in this crosshair .....
//
//    void generateRectangles() override {
//        centerX = idRenderModelGui::getCenterX();
//        centerY = idRenderModelGui::getCenterY();
//        if (MaterialPtr == 0) {
//            MaterialPtr = MaterialLib::getWhite();
//            logInfo("MaterialPtr : %p", (void*)MaterialPtr);
//        }    
//
//        FillRectVec.clear();
//        FillRectVec.push_back(Rect(RectID::centerDot, centerX - size / 2, centerY - size / 2, size, size, MaterialPtr, getColor(RectID::centerDot)));
//        if (barScale > 0.0f) { //! performance optimization (hopefully...)
//            FillRectVec.push_back(Rect(RectID::leftBar, centerX - size / 2 - gap - size * barScale, centerY - size / 2, size * barScale, size, MaterialPtr, getColor(RectID::leftBar)));
//            FillRectVec.push_back(Rect(RectID::rightBar, centerX + size / 2 + gap, centerY - size / 2, size * barScale, size, MaterialPtr, getColor(RectID::rightBar)));
//            FillRectVec.push_back(Rect(RectID::topBar, centerX - size / 2, centerY - size / 2 - gap - size * barScale, size, size * barScale, MaterialPtr, getColor(RectID::topBar)));
//            FillRectVec.push_back(Rect(RectID::bottomBar, centerX - size / 2, centerY + size / 2 + gap, size, size * barScale, MaterialPtr, getColor(RectID::bottomBar)));
//        }       
//        
//        if (hasOutline) {
//            OutlineRectVec.clear();
//            for (size_t i = 0; i < FillRectVec.size(); i++)
//            {
//                Rect& rec = FillRectVec[i];
//                OutlineRectVec.push_back(Rect(rec.ID, rec.X - outlineThickness, rec.Y - outlineThickness, rec.Width + 2 * outlineThickness, rec.Height + 2 * outlineThickness, MaterialPtr, IdColorOutline));              
//            }
//        }
//    }
//
//    const idColor& getColor(RectID rectID) {
//        if (hasHudData) { //! this should be true wheter crosshair shows for ex nade status but also if crosshair shows player health           
//            return HudCrosshairDataConverter::getDataAsColor(rectID, hudData, dataMap, IdColorFill);
//        }
//        return IdColorFill;     
//    }
//};


//! before we inverse the fill/outline vecs just in case...
//class CrosshairCrossWithDot : public VectorCrosshair {
//
//public:
//
//    float gap;
//    float barScale;
//
//    CrosshairCrossWithDot(float centerX_, float centerY_, float size_, bool hasOutline_, float outlineThickness_, const idColor& idColorOutline_, const idColor& idColorFill_, __int64 materialPtr_, float gap_, float barScale_)
//        : VectorCrosshair(centerX_, centerY_, size_, hasOutline_, outlineThickness_, idColorOutline_, idColorFill_, materialPtr_), gap(gap_), barScale(barScale_) {
//
//        generateRectangles();
//    }
//
//    void generateRectangles() override {
//        OutlineRectVec.clear();
//        OutlineRectVec.push_back(Rect(RectID::centerDot, centerX - size / 2, centerY - size / 2, size, size, MaterialPtr, IdColorOutline));
//        OutlineRectVec.push_back(Rect(RectID::leftBar, centerX - size / 2 - gap - size * barScale, centerY - size / 2, size * barScale, size, MaterialPtr, IdColorOutline));
//        OutlineRectVec.push_back(Rect(RectID::rightBar, centerX + size / 2 + gap, centerY - size / 2, size * barScale, size, MaterialPtr, IdColorOutline));
//        OutlineRectVec.push_back(Rect(RectID::topBar, centerX - size / 2, centerY - size / 2 - gap - size * barScale, size, size * barScale, MaterialPtr, IdColorOutline));
//        OutlineRectVec.push_back(Rect(RectID::bottomBar, centerX - size / 2, centerY + size / 2 + gap, size, size * barScale, MaterialPtr, IdColorOutline));
//
//        if (hasOutline) {
//            FillRectVec.clear();
//            for (size_t i = 0; i < OutlineRectVec.size(); i++)
//            {
//                Rect& rec = OutlineRectVec[i];
//                FillRectVec.push_back(Rect(rec.ID, rec.X + outlineThickness, rec.Y + outlineThickness, rec.Width - 2 * outlineThickness, rec.Height - 2 * outlineThickness, MaterialPtr, IdColorFill));
//            }
//        }
//
//
//        /*
//        rectCenterDot = rect(centerx - size/2, centery - size/2, size, size, mat)
//                rectL = rect(centerx - size/2 - gap - size * barLengthSizeMultiplicator , centery - size/2, size * barLengthSizeMultiplicator, size)
//                rectR = rect(centerx + size/2 + gap, centery - size/2, size * barLengthSizeMultiplicator, size)
//                rectT = rect(centerx - size/2, centery - size/2 - gap - size * barLengthSizeMultiplicator, size, size * barLengthSizeMultiplicator)
//                rectB = rect(centerx - size/2, centery+ size/2 + gap, size, size * barLengthSizeMultiplicator);
//        */
//    }
//
//
//};