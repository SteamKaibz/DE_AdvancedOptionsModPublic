#pragma once
#include "CommonDE.h"
#include "MemHelper.h"
#include "Types.h"
#include "idLib.h"
#include "GeneratedClasses.h"
#include "idResourceManager.h"


class idSWFSpriteInstanceManager {

private:
	

	//! char __fastcall sub_52F670(__int64 a1, float a2, float a3)
	typedef  char(__fastcall* pSetSpriteInstanceScale)(idSWFSpriteInstance* spriteInstancePtr_a1, float reticelScaleF_a2, float reticelScaleF_a3);
	static inline pSetSpriteInstanceScale m_pSetSpriteInstanceScale = nullptr;

	//! void __fastcall updateSpriteInstanceColor_52F290(__int64 spriteInstancePtr_a1, __int64 namedColorId_a2)
	typedef void(__fastcall* pUpdateSpriteInstanceColor)(idSWFSpriteInstance* thiz, __int64 namedColorId_a2);
	//static pUpdateSpriteInstanceColor m_pUpdateSpriteInstanceColor;
	static inline __int64 m_updateSpriteInstanceColorFuncAdd = 0;


public: 


	


	static bool acquireUpdateSpriteInstanceColorFuncAdd(__int64 funcAddr);


	static swfRect_t getBounds(idSWFSpriteInstance* thiz);

	static void debugPrintCoords(idSWFSpriteInstance* thiz);

	static void updateSpriteInstanceColor(idSWFSpriteInstance* thiz, swfNamedColors_t swfColorId);


	static void setHitMarkerState(idHUD_Reticle* idHUD_Reticle, HitMarkerState state);


	//! check made in hook for idSWFSpriteInstance exists
	static bool updateScale(idSWFSpriteInstance* idSWFSpriteInstance, float reticleScaleF);

	static bool acquirreSetSpriteInstanceScaleFpAdd(__int64 funcPtrAdd);

	//! the reason why we have to do it that way is because and idList is always going to be a list of __int64* but in the this case for ex, the idList is a list of swfDisplayEntry_t and a swfDisplayEntry_t has a size of 64 bytes, so it's just easier to do it this way:
	static std::vector<idSWFSpriteInstance*> getSpriteInstancesPtrVecFromDisplayEntry(idSWFSpriteInstance* spriteInstance);


	static void debugPrintfullPathHashForColorId(idSWFSpriteInstance* spriteInstance, swfNamedColors_t colorId);


	static void debugPrintSpriteInstanceMaterialOverrideNameForColorId(__int64 spriteInstanceAddr, int colorId);

	static bool debugPrintSpriteInstanceMaterialName(idSWFSpriteInstance* idSWFSpriteInstance);

	static void debugPrintSpriteInstanceDisplayList(idSWFSpriteInstance* idSWFSpriteInstanceObj);


	//! still have to work on this to make it work and not crash imo:
	/*static idSWFSpriteInstance* FindRoot(__int64 spriteInstanceAdd, int fullPathHash) {
		if (MemHelper::isBadReadPtr((void*)spriteInstanceAdd)) {
			return 0;
		}
		idSWFSpriteInstance* spriteInstance = (idSWFSpriteInstance*)spriteInstanceAdd;

		while (true)
		{
			if (MemHelper::isBadReadPtr((void*)&spriteInstance->parent)) break;
			spriteInstance = spriteInstance->parent;
			if (spriteInstance->fullPathHash == fullPathHash) {
				return spriteInstance;
			}
		}
		return 0;
	}*/

	/*
	
	19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name cooldown2 hash: 456271084
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name cooldown hash: 1452392179
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name equipment hash: 929754470
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name weaponInfo hash: -938331194
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name hudElement hash: -2107815822
19:26:08.555 idSWFSpriteInstanceMana:221   INFO| debugPrintSpriteInstanceInfo: fount parent with name _root hash: 91240897
	
	*/
	//! from my logs those values do not change for the nade icon whether you're in a menu or not or if the hud element is disabled in the settings or if in cinematic
	static void debugPrintSpriteInstanceInfo(idSWFSpriteInstance* spriteInstance);



};


//idSWFSpriteInstanceManager::pUpdateSpriteInstanceColor idSWFSpriteInstanceManager::m_pUpdateSpriteInstanceColor;
