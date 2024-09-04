#pragma once

#include "TypeInfoManager.h"
#include "idPlayer.h"
#include "idLib_Static.h"
#include "idResourceManager.h"

#include "../Common/K_Utils.h"
#include "idLib_Dynamic.h"
//#include "idHUDElementManager.h"
//#include "idHUD_ReticleManager.h"


class idHudManager {

private:


    //! char __fastcall sub_52F670(__int64 a1, float a2, float a3)
    typedef  char(__fastcall* pSetSpriteInstanceScale)(__int64 spriteInstancePtr_a1, float reticelScaleF_a2, float reticelScaleF_a3);

    typedef char(__fastcall* isWorldMenuAtIndexActive_t)(idHUD* playerHudPtr, hudMenuID_t hudMenuID_a2);

   static inline const std::string m_idHUD_ReticleName = "hud_reticle";
   static inline idHudManager::pSetSpriteInstanceScale m_pSetSpriteInstanceScale = 0;

   static inline  std::set<std::string> m_debugTempUniqueDeclNames;

   static inline isWorldMenuAtIndexActive_t m_isWorldMenuAtIndexActiveFp = nullptr;

   static inline std::unordered_map<std::string, idHUDElement*> m_elementCache;

public:


    static bool acquireIsWorldMenuAtIndexActiveFuncAddr(__int64 faddr);


    //std::vector<idHUDElement*> getIdHudPtrsVec(std::vector<std::string> idHudNamesStrVec);

    static idHUDElement* getIdHud_Element(std::string requestedHudElementName);

    static bool isWorldMenuActive(hudMenuID_t hudMenuID);


    static void debugPrintAllHud_ElementsAddr();

   

    static std::string getDdgStrForImgui();

    static std::string getHudStateString(hudElementFlags_t state);

    static void debugLogUniqueDeclName(std::string declName, __int64 hudElementAddr);



   


};



