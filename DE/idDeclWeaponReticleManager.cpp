#include "idDeclWeaponReticleManager.h"

bool idDeclWeaponReticleManager::isShotgunDeclWeaponStickyReticle(idDeclWeaponReticle* declWeaponReticlePtr) {
	logDebug("isShotgunDeclWeaponStickyReticle");
	if (MemHelper::isBadReadPtr(declWeaponReticlePtr)) {
		logErr("isShotgunDeclWeaponStickyReticle: declWeaponReticlePtr is bad ptr: %p returning false", declWeaponReticlePtr);
		return false;
	}
	return declWeaponReticlePtr->style == idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_SHOTGUN_STICKY_BOMBS || declWeaponReticlePtr->style == idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_SHOTGUN_STICKY_BOMBS_MASTERY;
}

bool idDeclWeaponReticleManager::isMeatHookDeclWeaponReticle(idDeclWeaponReticle* declWeaponReticlePtr) {	
	if (MemHelper::isBadReadPtr(declWeaponReticlePtr)) {
		logErr("isMeatHookDeclWeaponReticle: declWeaponReticlePtr is bad ptr: %p returning false", declWeaponReticlePtr);
		return false;
	}
	return declWeaponReticlePtr->style == idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_DB_SHOTGUN_MEATHOOK;
}

void idDeclWeaponReticleManager::debugPrintCurrentDeclWeaponReticle(idDeclWeaponReticle* declWeaponReticlePtr) {
	logDebug("debugPrintCurrentDeclWeaponReticle");
	if (MemHelper::isBadReadPtr(declWeaponReticlePtr)) {
		logErr("debugPrintCurrentDeclWeaponReticle:  declWeaponReticlePtr is bad ptr: %p returning false", declWeaponReticlePtr);
	}
	logInfo("declWeaponReticlePtr->style: %d", declWeaponReticlePtr->style);
}


std::string idDeclWeaponReticleManager::getReticleStyleString(idDeclWeaponReticle_reticleStyle_t reticleStyle) {
    switch (reticleStyle) {
    case RETICLE_STYLE_NONE: return "RETICLE_STYLE_NONE";
    case RETICLE_STYLE_DOT: return "RETICLE_STYLE_DOT";
    case RETICLE_STYLE_ROCKET_LAUNCHER: return "RETICLE_STYLE_ROCKET_LAUNCHER";
    case RETICLE_STYLE_SHOTGUN: return "RETICLE_STYLE_SHOTGUN";
    case RETICLE_STYLE_SHOTGUN_STICKY_BOMBS: return "RETICLE_STYLE_SHOTGUN_STICKY_BOMBS";
    case RETICLE_STYLE_SHOTGUN_STICKY_BOMBS_MASTERY: return "RETICLE_STYLE_SHOTGUN_STICKY_BOMBS_MASTERY";
    case RETICLE_STYLE_SHOTGUN_FULL_AUTO: return "RETICLE_STYLE_SHOTGUN_FULL_AUTO";
    case RETICLE_STYLE_HEAVY_CANNON: return "RETICLE_STYLE_HEAVY_CANNON";
    case RETICLE_STYLE_HEAVY_CANNON_BOLT: return "RETICLE_STYLE_HEAVY_CANNON_BOLT";
    case RETICLE_STYLE_DB_SHOTGUN: return "RETICLE_STYLE_DB_SHOTGUN";
    case RETICLE_STYLE_DB_SHOTGUN_MEATHOOK: return "RETICLE_STYLE_DB_SHOTGUN_MEATHOOK";
    case RETICLE_STYLE_PLASMA: return "RETICLE_STYLE_PLASMA";
    case RETICLE_STYLE_PLASMA_MICROWAVE: return "RETICLE_STYLE_PLASMA_MICROWAVE";
    case RETICLE_STYLE_PLASMA_AOE: return "RETICLE_STYLE_PLASMA_AOE";
    case RETICLE_STYLE_PLASMA_STUN_FASTER_RECHARGE: return "RETICLE_STYLE_PLASMA_STUN_FASTER_RECHARGE";
    case RETICLE_STYLE_CHAINGUN: return "RETICLE_STYLE_CHAINGUN";
    case RETICLE_STYLE_CHAINGUN_TURRET: return "RETICLE_STYLE_CHAINGUN_TURRET";
    case RETICLE_STYLE_CHAINGUN_TURRET_NOHEAT: return "RETICLE_STYLE_CHAINGUN_TURRET_NOHEAT";
    case RETICLE_STYLE_BALLISTA_ARBALEST: return "RETICLE_STYLE_BALLISTA_ARBALEST";
    case RETICLE_STYLE_BALLISTA_DESTROYER: return "RETICLE_STYLE_BALLISTA_DESTROYER";
    case RETICLE_STYLE_BALLISTA_DESTROYER_MASTERY: return "RETICLE_STYLE_BALLISTA_DESTROYER_MASTERY";
    case RETICLE_STYLE_CHAINSAW: return "RETICLE_STYLE_CHAINSAW";
    case RETICLE_STYLE_ROCKET_LAUNCHER_LOCKON: return "RETICLE_STYLE_ROCKET_LAUNCHER_LOCKON";
    case RETICLE_STYLE_BFG: return "RETICLE_STYLE_BFG";
    case RETICLE_STYLE_CRUCIBLE: return "RETICLE_STYLE_CRUCIBLE";
    case RETICLE_STYLE_UNMAKYR: return "RETICLE_STYLE_UNMAKYR";
    case RETICLE_STYLE_PISTOL: return "RETICLE_STYLE_PISTOL";
    case RETICLE_STYLE_MP_BARON: return "RETICLE_STYLE_MP_BARON";
    case RETICLE_STYLE_MP_REVENANT: return "RETICLE_STYLE_MP_REVENANT";
    case RETICLE_STYLE_MP_PROWLER: return "RETICLE_STYLE_MP_PROWLER";
    case RETICLE_STYLE_MP_MANCUBUS: return "RETICLE_STYLE_MP_MANCUBUS";
    case RETICLE_STYLE_MP_HARVESTER: return "RETICLE_STYLE_MP_HARVESTER";
    case RETICLE_STYLE_MP_CACODEMON: return "RETICLE_STYLE_MP_CACODEMON";
    case RETICLE_STYLE_MP_PINKY: return "RETICLE_STYLE_MP_PINKY";
    case RETICLE_STYLE_MP_ARCHVILE: return "RETICLE_STYLE_MP_ARCHVILE";
    case RETICLE_STYLE_MP_MARAUDER: return "RETICLE_STYLE_MP_MARAUDER";
    case RETICLE_STYLE_MP_DREADKNIGHT: return "RETICLE_STYLE_MP_DREADKNIGHT";
    case RETICLE_STYLE_MAX: return "RETICLE_STYLE_MAX";
    default: return "Unknown";
    }
}
