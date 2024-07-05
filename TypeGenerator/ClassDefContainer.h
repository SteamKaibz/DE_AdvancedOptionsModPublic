#pragma once
#include <vector>
#include "ClassDef.h"


class ClassDefContainer {
public:
    static std::vector<ClassDef>& getInstance() {
        static std::vector<ClassDef> classDefsVec;
        static bool isInitialized = false;

        if (!isInitialized) {
            //? this one is just a test to test sizes
            //classDefsVec.push_back(ClassDef("streamDatabasePrefetchBlock_t", { "name", "firstItemIndex" }));
            classDefsVec.push_back(ClassDef("idMenu", { "menuDecl", "gui", "activeScreen"}));
            classDefsVec.push_back(ClassDef("idStr", { "data", "len", "allocedAndFlag", "baseBuffer"}));
            classDefsVec.push_back(ClassDef("idResource", { "name", "resourceListPtr", "resourceID" }));
            classDefsVec.push_back(ClassDef("idUIElement", {"isActive"}));
            classDefsVec.push_back(ClassDef("idDeclUIColor::uiColorDef_t", {"color", "name"}));
            classDefsVec.push_back(ClassDef("idDeclUIColor", {"hudEquipmentFrag", "hudEquipmentFragIcon", "hudEquipmentCyro", "hudEquipmentCyroIcon", "hudEquipmentChainsaw", "hudEquipmentChainsawIcon"}));
            classDefsVec.push_back(ClassDef("idDeclGlobalShell", {"mainCampaignDecl", "colorProfile"}));
            classDefsVec.push_back(ClassDef("glyphInfo_t", {"width", "height", "top", "left", "xSkip", "s", "t" }));
            classDefsVec.push_back(ClassDef("fontInfo_t", {"imageWidth", "imageHeight", "pointSize", "ascender", "descender", "edgeExpand", "largestGlyphWidth", "numGlyphs", "glyphData"}));
            classDefsVec.push_back(ClassDef("idFont", {"alias", "fontInfo" }));
            classDefsVec.push_back(ClassDef("idDeclInventory", {"useWeaponFOVScale", "handsFovScale", "displayName" }));
            classDefsVec.push_back(ClassDef("idDeclWeapon::zoomInfo_t", { "zoomedFOV", "zoomedHandsFOV", "sensitivity_scale_controller", "sensitivity_scale_mouse"}));
            classDefsVec.push_back(ClassDef("idDeclWeapon", { "weaponSelectionGroup", "weaponSelectionGroupSlot", "ironSightZoom", "reticle", "reticleWhenZoomed", "weaponCategory"}));
            classDefsVec.push_back(ClassDef("idWeapon", { "emptyWhenSelected", "playedIntroBringUp", "gameChallengeDisabled" }));
            classDefsVec.push_back(ClassDef("idDeclWeaponReticle", { "style", "reticleModelScale" }));
            classDefsVec.push_back(ClassDef("idDeclFX", { "changeId", "cycleConditionMax", "cycleStartCondition", "cycleEvents" }));
            classDefsVec.push_back(ClassDef("idDeclAbility_Dash", { "fxDecl" }));           
            classDefsVec.push_back(ClassDef("idMaterial2", { "MaterialIndex"}));            
            classDefsVec.push_back(ClassDef("idSWFTextInstance", { "text", "color"}));
            classDefsVec.push_back(ClassDef("idSWFSpriteInstance", { "name", "fullPathHash",  "namedColorId", "bounds", "materialOverride", "displayList", "isPlayingAndActive", "isVisible", "visibilityRestricted", "firstRun", "spriteFlags", "parent"}));
            classDefsVec.push_back(ClassDef("idSWFCachedSpriteInstance", { "SpriteInstance" }));
            classDefsVec.push_back(ClassDef("swfDisplayEntry_t", { "characterID", "spriteInstance" }));
            classDefsVec.push_back(ClassDef("idSWFWidget", { "boundSprite", "spriteName", "spritePathHash", "widgetState", "deferredOperations"}));
            classDefsVec.push_back(ClassDef("idHUDEvent_ReticleDataUpdate::idReticleData_t", { "currentReticle", "currentWeaponDecl", "chargeCooldown", "zoom", "zoomFraction", "isZooming", "isFullyZoomedIn", "inScope" }));
            classDefsVec.push_back(ClassDef("idSWFWidget_Hud_Reticle", { "currentData", "previousData", "style", "declReticle", "reticleSprite"}));
            classDefsVec.push_back(ClassDef("idHUD_Reticle", { "currentReticleData", "reticles", "activeReticleStyle", "activeReticleDecl", "hitFlashSpr", "hitFlashLoopSpr" }));
            classDefsVec.push_back(ClassDef("idSWFWidget_EquipmentItem", {"dynamincIconName", "staticIconName", "cooldownValue", "swfColor", "iconSWFColor", "ctaSpr", "cooldownSpr"}));
            classDefsVec.push_back(ClassDef("idHUD_LowWarning", { "isDemonPlayer", "healthCurrent", "armorCurrent", "ammoPerShot"}));
            classDefsVec.push_back(ClassDef("idHUD_AbilityIndicators", { "updateFlags", "grenadeWidget", "iceGrenadeWidget", "iceGrenadeHollowPipWidget", "iceGrenadeCharge", "bloodPunchCharge", "chainsawCharge", "fragEquipped", "elementState", "grenadeShowing", "iceGrenadeShowing", "icegrenadeHollowPipShowing", "inCampaign"}));
            classDefsVec.push_back(ClassDef("idHUD_WeaponInfo", { "updateFlags", "currentWeapon",  "chainsawAmmo", "chainsawMaxAmmo",  "crucibleEquipped", "crucibleShown", "crucibleCharge", "crucibleMaxCharges", "equipmentItem",  "hammerShown", "hammerRecharge", "hammerSupercharge", "hammerPulse", "equipmentWidget", "playingLowAmmoAnim"}));
            classDefsVec.push_back(ClassDef("tagData_t", { "trans", "rot"}));
            classDefsVec.push_back(ClassDef("idDeclHUDElement::idHudSWFInfo_t", { "nonPerspectiveScale", "swfScale"}));
            classDefsVec.push_back(ClassDef("idDeclHUDElement", { "swfInfo", "hudEventIDs", "cacheImages"}));
            classDefsVec.push_back(ClassDef("idHUDElement", { "decl", "hudSysId", "tagData", "isFaded"}));
            classDefsVec.push_back(ClassDef("idHUD", { "elements" , "pauseMenuIndex", "gameWasPaused", "inScope", "broadcastSystemId", "menus", "isPOIVisible", "readyForMapStart", "currentHudMode", "prevShowMenuVisibilityMask"}));
            classDefsVec.push_back(ClassDef("idGameSystemLocal", { "mapInstance" }));            
            //classDefsVec.push_back(ClassDef("idDeclInventory", {"name", "displayName" }));
            classDefsVec.push_back(ClassDef("idInventoryItem", { "decl" }));
            classDefsVec.push_back(ClassDef("idEntity", { "name", "spawnPosition", "prefabInstanceId"}));
            classDefsVec.push_back(ClassDef("idInventoryCollection", { "inventory"}));
            classDefsVec.push_back(ClassDef("idActor", { "lastTeleportTime", "pinged", "inventory", "overdrivePoints" }));
            classDefsVec.push_back(ClassDef("idGK_UpgradeHandler", { "fxBloodPunchAOE", "bloodPunchSuperChargedSoundActivated", "bloodPunchChargePercent"}));
            classDefsVec.push_back(ClassDef("idPlayerDashboard", { "GKUpgrades" }));
            classDefsVec.push_back(ClassDef("idPlayer::equipmentInfo_t::itemData_t", {"equipmentRechargeStartTime", "equipmentRechargeDuration", "equipmentUsesAvailable", "equipmentRechargeTime" , "equipmentReuseTime"}));
            classDefsVec.push_back(ClassDef("idPlayer::equipmentInfo_t", { "currentIndex", "equipmentItems" }));
            classDefsVec.push_back(ClassDef("idDeclPlayerProps", { "sounds", "validEquipmentList"}));
            classDefsVec.push_back(ClassDef("idPlayer", { "dashboard", "playerHud" , "equipmentInfo", "lastDelay", "globalCooldownTimeMS", "wantZoom", "hideReticle",  "hideHudForCinematic" , "hudFlagsBeforeDemon", "contextOptionSelected", "playerProps"}));
           

            isInitialized = true; // Mark as initialized.
        }

        return classDefsVec;
    }
};
