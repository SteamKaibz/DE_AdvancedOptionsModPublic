#pragma once
#include "GeneratedClasses.h"
#include "../Config/Config.h"
#include "MemHelper.h"


class idDeclWeaponReticleManager {

public:

	static bool isShotgunDeclWeaponStickyReticle(idDeclWeaponReticle* declWeaponReticlePtr);

	static bool isMeatHookDeclWeaponReticle(idDeclWeaponReticle* declWeaponReticlePtr);
	
	static std::string getReticleStyleString(idDeclWeaponReticle_reticleStyle_t reticleStyle);


	static void debugPrintCurrentDeclWeaponReticle(idDeclWeaponReticle* declWeaponReticlePtr);


};