#pragma once
#include "idLib.h"
#include "idColor.h"
#include "GeneratedEnums.h"
#include "CommonDE.h"


//#pragma pack(push, 1) // making sure no padding is added by compiler


//? THIS IS NOT GENERATED THIS IS MANUALLY MADE/ADDED ATM KEEP THAT IN MIND
//? THIS IS NOT GENERATED THIS IS MANUALLY MADE/ADDED ATM KEEP THAT IN MIND
//? THIS IS NOT GENERATED THIS IS MANUALLY MADE/ADDED ATM KEEP THAT IN MIND

//F declarations
class idWeapon;
class idDeclWeaponReticle;
class idDeclWeapon;



//? mod helper cls

class KaibzHudData {

public:
	const int hudNumberMaxValue = 999;
	const std::string hudNumberMaxValueStr = "999";

	//! if >0 || infinite =>  user color otherwise: greyed out.
	//? you can have zero but if is infinite it should be colored
	int extraLives = 0;
	KaibzHudColor_t extraLivesColor = KaibzHudColor_t::disabledColor;

	//! 0 => grey  1 => user color 1, 2 => user color 2, 3(desp punch) => user color 3 
	int bloodPunchCount = 0; //todo could have option to show them as float on hud ?
	bool isDesperatePunchReady = false; //! get it from idPlayer_K::isDesperatePunchAvailable()
	//bool isBloodPunchFlash = false;
	KaibzHudColor_t bloodPunchColor = KaibzHudColor_t::disabledColor;

	//! maxed, normal, low, critical. max and normal could be set by user, the other would be from customisable warning and critical colors.
	int health = 0;
	std::string healthStr = "0";
	KaibzHudColor_t healthColor = KaibzHudColor_t::disabledColor;
	//HealthState_K healthState = HealthState_K::normal;

	//! maxed, normal defined by user 
	int armor = 0;
	std::string armorStr = "0";
	KaibzHudColor_t armorColor = KaibzHudColor_t::disabledColor;
	//ArmorState armorState = ArmorState::normal;	

	//! normal color defined by user + warning and critical color 
	bool isRadsuitEquipped = false;
	KaibzHudColor_t radsuitColor = KaibzHudColor_t::disabledColor;
	//MeterState_K radsuitState = MeterState_K::normal; //! the warning, max and potentially critical colors will all be the same for each element


	//! normal color defined by user + warning and critical color 
	bool isOxygenEquipped = false;
	KaibzHudColor_t oxygenColor = KaibzHudColor_t::disabledColor;
	//MeterState_K oxygenState = MeterState_K::normal;


	//! normal color defined by user + low (warning or critical?) color. if is infinite set it to 999.
	int ammo = 0;
	std::string ammoStr = "0";
	KaibzHudColor_t ammoColor = KaibzHudColor_t::disabledColor;
	bool isInfinite = false; 
	//AmmoState_K ammoState = AmmoState_K::normal;		


	//! if we own the crucible and the hammer, the hammer has priority to be shown it seems. 
	bool isHammerShownOnHud = false;
	int hammerCharges = 0;
	//bool isHammerFlash = false; //! used to trigger a hud flash
	KaibzHudColor_t hammerColor = KaibzHudColor_t::disabledColor;

	bool isCrucibleShownOnHud = false;
	int crucibleCharges = 0;
	KaibzHudColor_t crucibleColor = KaibzHudColor_t::disabledColor;

	//! We don't care if we own the equipments or not, we just check the charges and show them as greyed even if we don't own them.
	int flamebelchCharges = 0;
	KaibzHudColor_t flamebelchColor = KaibzHudColor_t::disabledColor;

	int fuelCharges = 0;
	KaibzHudColor_t fuelColor = KaibzHudColor_t::disabledColor;



	bool isFragSelected = true;

	int fragCharges = 0;
	//bool isFragFlash = false;
	KaibzHudColor_t fragColor = KaibzHudColor_t::disabledColor;


	int iceCharges = 0;
	//bool isIceFlash = false;
	float iceNadeCooldownProgress = 0;
	KaibzHudColor_t iceColor = KaibzHudColor_t::disabledColor;

	bool isHudFlash = false;
	ImU32 hudFlashColor = modSettingsDefault::g_defaultkaibzHudWhiteColorImU32;

	ImU32 crosshairHealthColorImU32 = modSettingsDefault::g_defaultkaibzHudDisabledColorImU32;
	

};






//? Game Cls

struct Win32Vars_t {
	char pad0[0x23];
	bool isGameFocused;
};


struct idManagedClassPtr_idEntity {
    //Offset 0x0 	Size 0x4 (4)
    int spawnId;
    //Offset 0x4 	Size 0x4 (4)	 The spawnid that we just serialized into the client. It's held until PostSerializeRead, where it is then officially set.
    int serializedSpawnId;
    //Offset 0x8 	Size 0x8 (8) idEntity* ptr;
    void* entity_ptr;
    //Offset 0x10 	Size 0x8 (8)
    idManagedClassPtr_idEntity* next; //? this will be null for the ones in playerInventory
    //Offset 0x18 	Size 0x8 (8)
    idManagedClassPtr_idEntity* prev; //? this will be null for the ones in playerInventory
}; // Size: 0x20 (Size Dec: 32)


struct idManagedClassPtr_idPlayer {
    //Offset 0x0 	Size 0x4 (4)
    int spawnId;
    //Offset 0x4 	Size 0x4 (4)	 The spawnid that we just serialized into the client. It's held until PostSerializeRead, where it is then officially set.
    int serializedSpawnId;
    //Offset 0x8 	Size 0x8 (8) idEntity* ptr;
    void* ptr;
    //Offset 0x10 	Size 0x8 (8)
    idManagedClassPtr_idEntity* next;
    //Offset 0x18 	Size 0x8 (8)
    idManagedClassPtr_idEntity* prev;
}; // Size: 0x20 (Size Dec: 32)


struct idManagedClassPtr_idWeapon {
    //Offset 0x0 	Size 0x4 (4)
    int spawnId;
    //Offset 0x4 	Size 0x4 (4)	 The spawnid that we just serialized into the client. It's held until PostSerializeRead, where it is then officially set.
    int serializedSpawnId;
    //Offset 0x8 	Size 0x8 (8)
    idWeapon* ptr;
    //Offset 0x10 	Size 0x8 (8)
    idManagedClassPtr_idWeapon* next;
    //Offset 0x18 	Size 0x8 (8)
    idManagedClassPtr_idWeapon* prev;
}; // Size: 0x20 (Size Dec: 32)


struct idManagedClassPtr_idSyncEntity {
    //Offset 0x0 	Size 0x4 (4)
    int spawnId;
    //Offset 0x4 	Size 0x4 (4)	 The spawnid that we just serialized into the client. It's held until PostSerializeRead, where it is then officially set.
    int serializedSpawnId;
    //Offset 0x8 	Size 0x8 (8)
    void* idSyncEntity_ptr;
    //Offset 0x10 	Size 0x8 (8)
    idManagedClassPtr_idWeapon* next;
    //Offset 0x18 	Size 0x8 (8)
    idManagedClassPtr_idWeapon* prev;   
}; // Size: 0x20 (Size Dec: 32)



struct idSWF_GameObject {
    //Offset 0x0 	Size 0x8 (8)	 the swf file associated with this object.
    void* idSWF_swfPtr; // idSWF* swf;
    //Offset 0x8 	Size 0x8 (8)	 the cached render model used to render the swf if we're not using the global model.
    void* customModel; // idRenderModelGui* customModel;
    //Offset 0x10 	Size 0x8 (8)	 the render model used to render the swf. Will be equal to m_customModel if we're using the custom model, or NULL if we're using the global model.
    void* guiModel; // idRenderModelGui* guiModel;
    //Offset 0x18 	Size 0x8 (8)	 the actual render model to render the GUI onto. If not set will render full screen.
    void* renderModel; // idRenderModel* renderModel;
    //Offset 0x20 	Size 0x8 (8)	 optional custom material we can apply to the render model
    //void* idMaterial2_customMaterialPtr;
    idMaterial2* customMaterialPtr;
    //Offset 0x28 	Size 0x4 (4)	 Sort type for the GUI
    int sortType; //guiModelSortType_t sortType;
    //Offset 0x2C 	Size 0x1 (1)	 Render with depth testing
    bool depthTest;
    //Offset 0x30 	Size 0x4 (4)
    float emissiveScale;
    //Offset 0x34 	Size 0xC (12)	 origin of the swf object. {{ units = m }}
    idVec3 origin;
    //Offset 0x40 	Size 0x24 (36)	 axis of the swf object.
    idMat3 axis;
    //Offset 0x64 	Size 0x4 (4)	 scale of the swf object.
    float scale;
    //Offset 0x68 	Size 0x1 (1)	 if true the swf is our responsibility to clean up
    bool manageSwf;
    //Offset 0x6C 	Size 0x4 (4)	 force this swf to always render at this FOV.
    float forceFov;
    //Offset 0x70 	Size 0x1 (1)
    bool dormant;
}; // Size: 0x78 (Size Dec: 120)





// Inheritance: idGameDeclTypeInfo: idDeclTypeInfo: idDecl: idResource
struct idDeclCampaign {
    char pad0[488];
    //Offset 0x1E8 	Size 0x18 (24)	 popups to show when creating a new save slot for this campaign
    //idList < idDeclCampaign::newCampaignPopup_t, TAG_IDLIST, false > newCampaignPopups;
    idList newCampaignPopups;
}; // Size: 0x200 (Size Dec: 512)



class idDeclUIColor_uiColorDef_t {
public:
    idColor color; // offset: 0h (0d)  size: 16
    idStrId name; // offset: 10h (16d)  size: 4
}; // size: 20


// idDeclUIColor : idDeclTypeInfo : idDecl : idResource
//class idDeclUIColor {
//public:
//    char pad_0[4564]; // offset: 0h (0d) size: 4564
//    idDeclUIColor_uiColorDef_t hudEquipmentFrag; // offset: 11D4h (4564d)  size: 20
//    idDeclUIColor_uiColorDef_t hudEquipmentFragIcon; // offset: 11E8h (4584d)  size: 20
//    idDeclUIColor_uiColorDef_t hudEquipmentCyro; // offset: 11FCh (4604d)  size: 20
//    idDeclUIColor_uiColorDef_t hudEquipmentCyroIcon; // offset: 1210h (4624d)  size: 20
//    idDeclUIColor_uiColorDef_t hudEquipmentChainsaw; // offset: 1224h (4644d)  size: 20
//    idDeclUIColor_uiColorDef_t hudEquipmentChainsawIcon; // offset: 1238h (4664d)  size: 20
//    char pad_End[844]; // offset: 124Ch (4684d) size: 844
//}; // size: 5528



// idDeclGlobalShell : idDeclTypeInfo : idDecl : idResource
class idDeclGlobalShell {
public:
    char pad_0[336]; // offset: 0h (0d) size: 336
    idDeclCampaign* mainCampaignDecl; // offset: 150h (336d)  size: 8
    char pad_344[104]; // offset: 158h (344d) size: 104
    // idList < const idDeclUIColor * , TAG_IDLIST , false >
    idList colorProfile; // offset: 1C0h (448d)  size: 24
    char pad_End[344]; // offset: 1D8h (472d) size: 344
}; // size: 816

//// idDeclGlobalShell : idDeclTypeInfo : idDecl : idResource
//class idDeclGlobalShell {
//public:
//    char pad_0[448]; // offset: 0h (0d) size: 448
//    // idList < const idDeclUIColor * , TAG_IDLIST , false >
//    idList colorProfile; // offset: 1C0h (448d)  size: 24
//    char pad_End[344]; // offset: 1D8h (472d) size: 344
//}; // size: 816


class glyphInfo_t {
public:
    unsigned char width; // offset: 0h (0d)  size: 1
    unsigned char height; // offset: 1h (1d)  size: 1
    char top; // offset: 2h (2d)  size: 1
    char left; // offset: 3h (3d)  size: 1
    unsigned char xSkip; // offset: 4h (4d)  size: 1
    char pad_5[1]; // offset: 5h (5d) size: 1
    unsigned short s; // offset: 6h (6d)  size: 2
    unsigned short t; // offset: 8h (8d)  size: 2
}; // size: 10


class fontInfo_t {
public:
    char pad_0[24]; // offset: 0h (0d) size: 24
    short imageWidth; // offset: 18h (24d)  size: 2
    short imageHeight; // offset: 1Ah (26d)  size: 2
    short pointSize; // offset: 1Ch (28d)  size: 2
    short ascender; // offset: 1Eh (30d)  size: 2
    short descender; // offset: 20h (32d)  size: 2
    short edgeExpand; // offset: 22h (34d)  size: 2
    short largestGlyphWidth; // offset: 24h (36d)  size: 2
    short numGlyphs; // offset: 26h (38d)  size: 2
    glyphInfo_t* glyphData; // offset: 28h (40d)  size: 8
    char pad_End[8]; // offset: 30h (48d) size: 8
}; // size: 56


// idFont : idResource
class idFont {
public:
    char pad_0[88]; // offset: 0h (0d) size: 88
    idFont* alias; // offset: 58h (88d)  size: 8
    fontInfo_t* fontInfo; // offset: 60h (96d)  size: 8
    char pad_End[56]; // offset: 68h (104d) size: 56
}; // size: 160


//// idDeclInventory : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
//class idDeclInventory {
//public:
//    char pad_0[292]; // offset: 0h (0d) size: 292
//    idStrId displayName; // offset: 124h (292d)  size: 4
//    char pad_End[720]; // offset: 128h (296d) size: 720
//}; // size: 1016


// idDeclInventory : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
class idDeclInventory {
public:
    char pad_0[168]; // offset: 0h (0d) size: 168
    bool useWeaponFOVScale; // offset: A8h (168d)  size: 1
    char pad_169[119]; // offset: A9h (169d) size: 119
    float handsFovScale; // offset: 120h (288d)  size: 4
    idStrId displayName; // offset: 124h (292d)  size: 4
    char pad_End[720]; // offset: 128h (296d) size: 720
}; // size: 1016



class idDeclWeapon_zoomInfo_t {
public:
    float zoomedFOV; // offset: 0h (0d)  size: 4
    float zoomedHandsFOV; // offset: 4h (4d)  size: 4
    char pad_8[4]; // offset: 8h (8d) size: 4
    float sensitivity_scale_controller; // offset: Ch (12d)  size: 4
    float sensitivity_scale_mouse; // offset: 10h (16d)  size: 4
    char pad_End[116]; // offset: 14h (20d) size: 116
}; // size: 136



// idDeclWeapon : idDeclInventory : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
class idDeclWeapon {
public:
    char pad_0[2496]; // offset: 0h (0d) size: 2496
    idDeclWeapon_weaponSelectionGroup_t weaponSelectionGroup; // offset: 9C0h (2496d)  size: 4
    idDeclWeapon_weaponSelectionGroupSlot_t weaponSelectionGroupSlot; // offset: 9C4h (2500d)  size: 4
    char pad_2504[3384]; // offset: 9C8h (2504d) size: 3384
    idDeclWeapon_zoomInfo_t ironSightZoom; // offset: 1700h (5888d)  size: 136
    char pad_6024[2512]; // offset: 1788h (6024d) size: 2512
    idDeclWeaponReticle* reticle; // offset: 2158h (8536d)  size: 8
    idDeclWeaponReticle* reticleWhenZoomed; // offset: 2160h (8544d)  size: 8
    char pad_8552[420]; // offset: 2168h (8552d) size: 420
    idDeclWeapon_weaponCategory_t weaponCategory; // offset: 230Ch (8972d)  size: 4
    char pad_End[24]; // offset: 2310h (8976d) size: 24

    std::string getNameStr() {
        return std::string(reinterpret_cast<const idResource*>(this)->name.str);
    }

}; // size: 9000







// idWeapon : idInventoryItem : idEventReceiver : idManagedClass : idClass : idEventArgUser
class idWeapon {
public:
    char pad_0[9160]; // offset: 0h (0d) size: 9160
    bool emptyWhenSelected; // offset: 23C8h (9160d)  size: 1
    bool playedIntroBringUp; // offset: 23C9h (9161d)  size: 1
    bool gameChallengeDisabled; // offset: 23CAh (9162d)  size: 1
    char pad_End[6101]; // offset: 23CBh (9163d) size: 6101
}; // size: 15264


// idDeclWeaponReticle : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
class idDeclWeaponReticle {
public:
    char pad_0[144]; // offset: 0h (0d) size: 144
    idDeclWeaponReticle_reticleStyle_t style; // offset: 90h (144d)  size: 4
    char pad_148[100]; // offset: 94h (148d) size: 100
    float reticleModelScale; // offset: F8h (248d)  size: 4
    char pad_End[812]; // offset: FCh (252d) size: 812
}; // size: 1064


// idDeclFX : idDeclTypeInfo : idDecl : idResource
class idDeclFX {
public:
    char pad_0[160]; // offset: 0h (0d) size: 160
    int changeId; // offset: A0h (160d)  size: 4
    int cycleConditionMax; // offset: A4h (164d)  size: 4
    fxCondition_t cycleStartCondition; // offset: A8h (168d)  size: 4
    bool cycleEvents; // offset: ACh (172d)  size: 1
    char pad_End[75]; // offset: ADh (173d) size: 75
}; // size: 248


// idDeclAbility_Dash : idDeclInventory : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
class idDeclAbility_Dash {
public:
    char pad_0[1104]; // offset: 0h (0d) size: 1104
    idDeclFX* fxDecl; // offset: 450h (1104d)  size: 8
    char pad_End[24]; // offset: 458h (1112d) size: 24
}; // size: 1136







class idSWFSpriteInstance {
public:
    char pad_0[24]; // offset: 0h (0d) size: 24
    idAtomicString name; // offset: 18h (24d)  size: 8
    int fullPathHash; // offset: 20h (32d)  size: 4
    char pad_36[28]; // offset: 24h (36d) size: 28
    idSWFSpriteInstance* parent; // offset: 40h (64d)  size: 8
    char pad_72[8]; // offset: 48h (72d) size: 8
    bool isPlaying; // offset: 50h (80d)  size: 1
    bool isVisible; // offset: 51h (81d)  size: 1
    bool visibilityRestricted; // offset: 52h (82d)  size: 1
    bool firstRun; // offset: 53h (83d)  size: 1
    int spriteFlags; // offset: 54h (84d)  size: 4
    char pad_88[8]; // offset: 58h (88d) size: 8
    //sdfvoid* idMaterial2_materialOverride; // offset: 60h (96d)  size: 8  
    idMaterial2* materialOverride; // offset: 60h (96d)  size: 8
    char pad_104[4]; // offset: 68h (104d) size: 4
    int namedColorId; // offset: 6Ch (108d)  size: 4
    // idList < swfDisplayEntry_t , TAG_SWF , false >
    idList displayList; // offset: 70h (112d)  size: 24
    char pad_136[32]; // offset: 88h (136d) size: 32
    swfRect_t bounds; // offset: A8h (168d)  size: 16
    char pad_End[120]; // offset: B8h (184d) size: 120
}; // size: 304


class idSWFCachedSpriteInstance {
public:
    char pad_0[16]; // offset: 0h (0d) size: 16
    idSWFSpriteInstance* SpriteInstance; // offset: 10h (16d)  size: 8
    char pad_End[24]; // offset: 18h (24d) size: 24
}; // size: 48


class idSWFTextInstance {
public:
	char pad_0[64]; // offset: 0h (0d) size: 64
	idStr text; // offset: 40h (64d)  size: 48
	char pad_112[96]; // offset: 70h (112d) size: 96
	swfColorRGBA_t color; // offset: D0h (208d)  size: 4
	char pad_End[412]; // offset: D4h (212d) size: 412
}; // size: 624



struct idHUD_HealthInfo_ComponentDescriptor {
	//Offset 0x0 	Size 0x4 (4)
	float maxValue;
	//Offset 0x4 	Size 0x4 (4)
	float previousValue;
	//Offset 0x8 	Size 0x4 (4)
	float currentValue;
	//Offset 0xC 	Size 0x4 (4)
	float warningLevel;
	//Offset 0x10 	Size 0x4 (4)
	float changeValue;
	//Offset 0x14 	Size 0x4 (4)
	float fillRateSpeed;
	//Offset 0x18 	Size 0x1 (1)
	bool manualFillControl;
	//Offset 0x19 	Size 0x1 (1)
	bool isLowHealthState;
	//Offset 0x20 	Size 0x8 (8)
	long long lastUpdateTime; //idTypesafeTime < long long, gameTimeUnique_t, 999960 > lastUpdateTime;
	//Offset 0x28 	Size 0x30 (48)
	idSWFCachedSpriteInstance componentSpr;
	//Offset 0x58 	Size 0x30 (48)
	idSWFCachedSpriteInstance fillBarSpr;
	//Offset 0x88 	Size 0x30 (48)
	idSWFCachedSpriteInstance fillPulseSpr;
	//Offset 0xB8 	Size 0x30 (48)
	idSWFCachedSpriteInstance addAmountPopupSpr;
	//Offset 0xE8 	Size 0x30 (48)
	idSWFCachedSpriteInstance infoSpr;
	//Offset 0x118 	Size 0x30 (48)
	idSWFCachedSpriteInstance infoPulseSpr;
	//Offset 0x148 	Size 0x30 (48)
	idSWFCachedSpriteInstance backSpr;
	//Offset 0x178 	Size 0x30 (48)
	idSWFCachedSpriteInstance backPulseSpr;
	//Offset 0x1A8 	Size 0x30 (48)
	idSWFCachedSpriteInstance backIconSpr;
	//Offset 0x1D8 	Size 0x8 (8)
	idSWFTextInstance* infoTxt; 
	//Offset 0x1E0 	Size 0x8 (8)
	idSWFTextInstance* infoPulseTxt; 
}; // Size: 0x1E8 (Size Dec: 488)



// Inheritance: idHUDElement: idUIElement: idClass: idEventArgUser
struct idHUD_HealthInfo  {
	char pad0[248];
	//Offset 0xF8 	Size 0x1E8 (488)	 Health store off.
	idHUD_HealthInfo_ComponentDescriptor healthDesc;
	//Offset 0x2E0 	Size 0x1E8 (488)
	idHUD_HealthInfo_ComponentDescriptor armorDesc;
	//Offset 0x4C8 	Size 0x1E8 (488)
	idHUD_HealthInfo_ComponentDescriptor radShieldDesc;
	//Offset 0x6B0 	Size 0x1E8 (488)
	idHUD_HealthInfo_ComponentDescriptor oxygenDesc;
	//Offset 0x898 	Size 0x30 (48)
	idSWFCachedSpriteInstance mainSpr;
	//Offset 0x8C8 	Size 0x30 (48)
	idSWFCachedSpriteInstance topAdor_nmentSpr;
	//Offset 0x8F8 	Size 0x30 (48)
	idSWFCachedSpriteInstance bottomAdornmentSpr;
	//Offset 0x928 	Size 0x30 (48)
	idSWFCachedSpriteInstance sentinelArmorSpr;
	//Offset 0x958 	Size 0x1 (1)	 Flag for when we have to heal the normal health before showing the overhealth anim
	bool waitForOverflowAnimation;
	//Offset 0x959 	Size 0x1 (1)	 The the radiation suit equipped for this player
	bool radShieldEquipped;
	//Offset 0x95A 	Size 0x1 (1)	 Is the Radiation suit actively blocking damage
	bool radShieldActive;
	//Offset 0x95B 	Size 0x1 (1)	 The the oxygen suit equipped for this player
	bool oxygenEquipped;
	//Offset 0x95C 	Size 0x1 (1)	 Is the oxygen suit actively blocking damage
	bool oxygenActive;
	//Offset 0x95D 	Size 0x1 (1)	 Does the player have the ability to dash and see it on the UI
	bool dashUnlockedAndVisible;
	//Offset 0x95E 	Size 0x1 (1)	 Does the player have the ability to use blood punch and see it on the UI
	bool bloodPunchUnlockedAndVisible;
	//Offset 0x95F 	Size 0x1 (1)
	bool sentinelArmorActive;
}; // Size: 0x960 (Size Dec: 2400)


class swfDisplayEntry_t {
public:
    unsigned short characterID; // offset: 0h (0d)  size: 2
    char pad_2[46]; // offset: 2h (2d) size: 46
    idSWFSpriteInstance* spriteInstance; // offset: 30h (48d)  size: 8
    char pad_End[8]; // offset: 38h (56d) size: 8
}; // size: 64




// idSWFWidget : idClass : idEventArgUser
class idSWFWidget {
public:
    char pad_0[24]; // offset: 0h (0d) size: 24
    idSWFSpriteInstance* boundSprite; // offset: 18h (24d)  size: 8
    idStr spriteName; // offset: 20h (32d)  size: 48
    char pad_80[72]; // offset: 50h (80d) size: 72
    int spritePathHash; // offset: 98h (152d)  size: 4
    char pad_156[184]; // offset: 9Ch (156d) size: 184
    idSWFWidgetState_t widgetState; // offset: 154h (340d)  size: 4
    char pad_344[36]; // offset: 158h (344d) size: 36
    int deferredOperations; // offset: 17Ch (380d)  size: 4
}; // size: 384


struct idUIElement {
    char pad0[16];
    //Offset 0x10 	Size 0x78 (120)
    idSWF_GameObject swfObject;
    //Offset 0x88 	Size 0x8 (8)
    idSWFWidget* rootWidget;
    //Offset 0x90 	Size 0x18 (24) // idList < idUIElement*, TAG_IDLIST, false > childElements;
    idList childElements;
    //Offset 0xA8 	Size 0x8 (8)
    idVec3* viewOrigin;
    //Offset 0xB0 	Size 0x8 (8)
    idMat3* viewAxis;
    //Offset 0xB8 	Size 0x1 (1)
    bool isActive;
    //Offset 0xBC 	Size 0x4 (4)
    int focusedChildElementIndex;
    //Offset 0xC0 	Size 0x1 (1)
    bool queuedActivate;
    //Offset 0xC1 	Size 0x1 (1)
    bool queuedDeactivate;
}; // Size: 0xC8 (Size Dec: 200)



class idHUDEvent_ReticleDataUpdate_idReticleData_t {
public:
    idDeclWeaponReticle* currentReticle; // offset: 0h (0d)  size: 8
    idDeclWeapon* currentWeaponDecl; // offset: 8h (8d)  size: 8
    char pad_16[44]; // offset: 10h (16d) size: 44
    float chargeCooldown; // offset: 3Ch (60d)  size: 4
    char pad_64[24]; // offset: 40h (64d) size: 24
    float zoom; // offset: 58h (88d)  size: 4
    float zoomFraction; // offset: 5Ch (92d)  size: 4
    bool isZooming; // offset: 60h (96d)  size: 1
    bool isFullyZoomedIn; // offset: 61h (97d)  size: 1
    bool inScope; // offset: 62h (98d)  size: 1
    char pad_End[173]; // offset: 63h (99d) size: 173
}; // size: 272


// idSWFWidget_Hud_Reticle : idSWFWidget : idClass : idEventArgUser
class idSWFWidget_Hud_Reticle {
public:
    char pad_0[384]; // offset: 0h (0d) size: 384
    idHUDEvent_ReticleDataUpdate_idReticleData_t currentData; // offset: 180h (384d)  size: 272
    idHUDEvent_ReticleDataUpdate_idReticleData_t previousData; // offset: 290h (656d)  size: 272
    idDeclWeaponReticle_reticleStyle_t style; // offset: 3A0h (928d)  size: 4
    char pad_932[4]; // offset: 3A4h (932d) size: 4
    idDeclWeaponReticle* declReticle; // offset: 3A8h (936d)  size: 8
    idSWFSpriteInstance* reticleSprite; // offset: 3B0h (944d)  size: 8
    char pad_End[776]; // offset: 3B8h (952d) size: 776
}; // size: 1728


// idHUD_Reticle : idHUDElement : idUIElement : idClass : idEventArgUser
class idHUD_Reticle {
public:
    char pad_0[248]; // offset: 0h (0d) size: 248
    idHUDEvent_ReticleDataUpdate_idReticleData_t currentReticleData; // offset: F8h (248d)  size: 272
    // idArray < idSWFWidget_Hud_Reticle * , 37 >
    idSWFWidget_Hud_Reticle* reticles_ptr[37]; // offset: 208h (520d)  size: 296
    int activeReticleStyle; // offset: 330h (816d)  size: 4
    char pad_820[4]; // offset: 334h (820d) size: 4
    idDeclWeaponReticle* activeReticleDecl; // offset: 338h (824d)  size: 8
    char pad_832[8]; // offset: 340h (832d) size: 8
    idSWFCachedSpriteInstance hitFlashSpr; // offset: 348h (840d)  size: 48
    idSWFCachedSpriteInstance hitFlashLoopSpr; // offset: 378h (888d)  size: 48
}; // size: 936


// idSWFWidget_EquipmentItem : idSWFWidget : idClass : idEventArgUser
class idSWFWidget_EquipmentItem {
public:
    char pad_0[384]; // offset: 0h (0d) size: 384
    idStr dynamincIconName; // offset: 180h (384d)  size: 48
    idStr staticIconName; // offset: 1B0h (432d)  size: 48
    char pad_480[4]; // offset: 1E0h (480d) size: 4
    float cooldownValue; // offset: 1E4h (484d)  size: 4
    swfNamedColors_t swfColor; // offset: 1E8h (488d)  size: 4
    swfNamedColors_t iconSWFColor; // offset: 1ECh (492d)  size: 4
    idSWFSpriteInstance* ctaSpr; // offset: 1F0h (496d)  size: 8
    idSWFSpriteInstance* cooldownSpr; // offset: 1F8h (504d)  size: 8
    char pad_End[24]; // offset: 200h (512d) size: 24
}; // size: 536


// Inheritance: idHUDElement: idUIElement: idClass: idEventArgUser
struct idHUD_BloodPunch  {
	char pad0[0xF8];
	//Offset 0xF8 	Size 0x4 (4)
	float currentCharge;
	//Offset 0xFC 	Size 0x4 (4)
	float maxCharge;
	//Offset 0x100 	Size 0x4 (4)
	float previousCharge;
	//Offset 0x104 	Size 0x4 (4)
	float healthCurrent;
	//Offset 0x108 	Size 0x4 (4)
	float healthMax;
	//Offset 0x10C 	Size 0x4 (4)
	float lowHealthThreshold;
	//Offset 0x110 	Size 0x8 (8)
	idSWFWidget* chargedAnim;
	//Offset 0x118 	Size 0x30 (48)
	idSWFCachedSpriteInstance ctaSpr;
	//Offset 0x148 	Size 0x4 (4)
	//swfPlatform_t swfPlatform;
	int swfPlatform;
	//Offset 0x14C 	Size 0x1 (1)
	bool showCta;
	//Offset 0x14D 	Size 0x1 (1)
	bool radShieldOrOxygenEquipped;
	//Offset 0x14E 	Size 0x1 (1)
	bool dashEquipped;
}; // Size: 0x150 (Size Dec: 336)


// Inheritance: idHUDElement: idUIElement: idClass: idEventArgUser
struct idHUD_LowWarning  {
	char pad0[0xF8];
	//Offset 0xF8 	Size 0x8 (8)
	void* idSWFWidget_wgtDemonHidden;
	//Offset 0x100 	Size 0x4 (4)
	float healthCurrent;
	//Offset 0x104 	Size 0x4 (4)
	float healthMax;
	//Offset 0x108 	Size 0x4 (4)
	float lowHealthThreshold;
	//Offset 0x10C 	Size 0x4 (4)
	float criticalHealthThreshold;
	//Offset 0x110 	Size 0x4 (4)
	float armorCurrent;
	//Offset 0x114 	Size 0x4 (4)
	float armorMax;
	//Offset 0x118 	Size 0x4 (4)
	int currentAmmoCount;
	//Offset 0x11C 	Size 0x4 (4)
	int maxAmmoCount;
	//Offset 0x120 	Size 0x4 (4)
	int lowAmmoThreshold;
	//Offset 0x124 	Size 0x4 (4)
	int ammoPerShot;
	//Offset 0x128 	Size 0x1 (1)
	bool overammoActive;
	//Offset 0x129 	Size 0x1 (1)
	bool infinite;
	//Offset 0x12A 	Size 0x1 (1)
	bool bfgInfinite;
	//Offset 0x12B 	Size 0x1 (1)
	bool isBFG;
	//Offset 0x12C 	Size 0x1 (1)	 false == no mod, true == mod disabled
	bool modStringFlag;
	//Offset 0x130 	Size 0x8 (8)
	long long  chainsawShowTime;
	//Offset 0x138 	Size 0x10 (16)
	char pad0x138_chainsawFailData[16];
	//Offset 0x148 	Size 0x8 (8)
	long long noModShowTime;
	//Offset 0x150 	Size 0x1 (1)
	bool isDemonPlayer;
	//Offset 0x151 	Size 0x1 (1)
	bool showingChainsawWarning;
	//Offset 0x154 	Size 0x4 (4)
	int lockonStatus;
	//Offset 0x158 	Size 0x10 (16)
	char pad0x138_demonInvasionStateData[16];
}; // Size: 0x168 (Size Dec: 360)


// Inheritance: idHUDElement: idUIElement: idClass: idEventArgUser
struct idHUD_ExtraLives {
	char pad0[0xF8];
	//Offset 0xF8 	Size 0x4 (4)
	int currentExtraLives;
	//Offset 0xFC 	Size 0x1 (1)
	bool infiniteExtraLives;
	//Offset 0xFD 	Size 0x1 (1)
	bool waitingToUpdateCount;
}; // Size: 0x100 (Size Dec: 256)




//// idHUD_AbilityIndicators : idHUDElement : idUIElement : idClass : idEventArgUser
//class idHUD_AbilityIndicators {
//public:
//    char pad_0[312]; // offset: 0h (0d) size: 312
//    idSWFWidget* grenadeWidget; // offset: 138h (312d)  size: 8
//    char pad_320[32]; // offset: 140h (320d) size: 32
//    idSWFWidget* iceGrenadeWidget; // offset: 160h (352d)  size: 8
//    char pad_360[8]; // offset: 168h (360d) size: 8
//    idSWFWidget* iceGrenadeHollowPipWidget; // offset: 170h (368d)  size: 8
//    idHUD_AbilityIndicators_elementState_t elementState; // offset: 178h (376d)  size: 4
//    int updateFlags; // offset: 17Ch (380d)  size: 4
//    float bloodPunchCharge; // offset: 180h (384d)  size: 4
//    float chainsawCharge; // offset: 184h (388d)  size: 4
//    char pad_392[20]; // offset: 188h (392d) size: 20
//    float iceGrenadeCharge; // offset: 19Ch (412d)  size: 4
//    char pad_416[7]; // offset: 1A0h (416d) size: 7
//    bool grenadeShowing; // offset: 1A7h (423d)  size: 1
//    bool iceGrenadeShowing; // offset: 1A8h (424d)  size: 1
//    char pad_425[5]; // offset: 1A9h (425d) size: 5
//    bool icegrenadeHollowPipShowing; // offset: 1AEh (430d)  size: 1
//    char pad_431[1]; // offset: 1AFh (431d) size: 1
//    bool inCampaign; // offset: 1B0h (432d)  size: 1
//    bool fragEquipped; // offset: 1B1h (433d)  size: 1
//    char pad_End[6]; // offset: 1B2h (434d) size: 6
//}; // size: 440



// Inheritance: idHUDElement: idUIElement: idClass: idEventArgUser
struct idHUD_AbilityIndicators  {
	char pad0[0xF8];
	//Offset 0xF8 	Size 0x8 (8)
	idSWFWidget* bloodPunchWidget;
	//Offset 0x100 	Size 0x8 (8)
	idSWFWidget* bloodPunchPipWidget;
	//Offset 0x108 	Size 0x8 (8)
	idSWFWidget* hammerWidget;
	//Offset 0x110 	Size 0x8 (8)
	idSWFWidget* chainsawWidget;
	//Offset 0x118 	Size 0x8 (8)
	idSWFWidget* chainsawHighPipWidget;
	//Offset 0x120 	Size 0x8 (8)
	idSWFWidget* chainsawMidPipWidget;
	//Offset 0x128 	Size 0x8 (8)
	idSWFWidget* chainsawLowPipWidget;
	//Offset 0x130 	Size 0x8 (8)
	idSWFWidget* flameBelchWidget;
	//Offset 0x138 	Size 0x8 (8)
	idSWFWidget* grenadeWidget;
	//Offset 0x140 	Size 0x8 (8)
	idSWFWidget* grenadeHighPipWidget;
	//Offset 0x148 	Size 0x8 (8)
	idSWFWidget* grenadeLowPipWidget;
	//Offset 0x150 	Size 0x8 (8)
	idSWFWidget* grenadeHighHollowPipWidget;
	//Offset 0x158 	Size 0x8 (8)
	idSWFWidget* grenadeLowHollowPipWidget;
	//Offset 0x160 	Size 0x8 (8)
	idSWFWidget* iceGrenadeWidget;
	//Offset 0x168 	Size 0x8 (8)
	idSWFWidget* iceGrenadePipWidget;
	//Offset 0x170 	Size 0x8 (8)
	idSWFWidget* iceGrenadeHollowPipWidget;
	//Offset 0x178 	Size 0x4 (4)
	int elementState; // idHUD_AbilityIndicators::elementState_t elementState;
	//Offset 0x17C 	Size 0x4 (4)
	int updateFlags;
	//Offset 0x180 	Size 0x4 (4)
	float bloodPunchCharge;
	//Offset 0x184 	Size 0x4 (4)
	float chainsawCharge;
	//Offset 0x188 	Size 0x4 (4)
	float flameBelchCharge;
	//Offset 0x18C 	Size 0x1 (1)
	bool hammerShown;
	//Offset 0x190 	Size 0x4 (4)
	float hammerRecharge;
	//Offset 0x194 	Size 0x4 (4)
	float hammerSupercharge;
	//Offset 0x198 	Size 0x4 (4)
	float grenadeCharge;
	//Offset 0x19C 	Size 0x4 (4)
	float iceGrenadeCharge;
	//Offset 0x1A0 	Size 0x1 (1)
	bool bloodPunchShowing;
	//Offset 0x1A1 	Size 0x1 (1)
	bool bloodPunchPipShowing;
	//Offset 0x1A2 	Size 0x1 (1)
	bool chainsawShowing;
	//Offset 0x1A3 	Size 0x1 (1)
	bool chainsawHighPipShowing;
	//Offset 0x1A4 	Size 0x1 (1)
	bool chainsawMidPipShowing;
	//Offset 0x1A5 	Size 0x1 (1)
	bool hammerShowing;
	//Offset 0x1A6 	Size 0x1 (1)
	bool flameBelchShowing;
	//Offset 0x1A7 	Size 0x1 (1)
	bool grenadeShowing;
	//Offset 0x1A8 	Size 0x1 (1)
	bool iceGrenadeShowing;
	//Offset 0x1A9 	Size 0x1 (1)
	bool grenadeHighPipShowing;
	//Offset 0x1AA 	Size 0x1 (1)
	bool grenadeHighHollowPipShowing;
	//Offset 0x1AB 	Size 0x1 (1)
	bool grenadeLowPipShowing;
	//Offset 0x1AC 	Size 0x1 (1)
	bool grenadeLowHollowPipShowing;
	//Offset 0x1AD 	Size 0x1 (1)
	bool icegrenadePipShowing;
	//Offset 0x1AE 	Size 0x1 (1)
	bool icegrenadeHollowPipShowing;
	//Offset 0x1AF 	Size 0x1 (1)	 Probably grenade pips right here
	bool swimming;
	//Offset 0x1B0 	Size 0x1 (1)
	bool inCampaign;
	//Offset 0x1B1 	Size 0x1 (1)
	bool fragEquipped;
}; // Size: 0x1B8 (Size Dec: 440)




//! side note i failed to use the whole cls cause i get a size of 680 and it should be 688
// idHUD_WeaponInfo : idHUDElement : idUIElement : idClass : idEventArgUser
class idHUD_WeaponInfo {
public:
	char pad_0[248]; // offset: 0h (0d) size: 248
	int updateFlags; // offset: F8h (248d)  size: 4
	char pad_252[4]; // offset: FCh (252d) size: 4
	idDeclWeapon* currentWeapon; // offset: 100h (256d)  size: 8
	char pad_264[84]; // offset: 108h (264d) size: 84
	int chainsawAmmo; // offset: 15Ch (348d)  size: 4
	int chainsawMaxAmmo; // offset: 160h (352d)  size: 4
	char pad_356[4]; // offset: 164h (356d) size: 4
	bool crucibleEquipped; // offset: 168h (360d)  size: 1
	bool crucibleShown; // offset: 169h (361d)  size: 1
	char pad_362[2]; // offset: 16Ah (362d) size: 2
	int crucibleCharge; // offset: 16Ch (364d)  size: 4
	int crucibleMaxCharges; // offset: 170h (368d)  size: 4
	char pad_372[4]; // offset: 174h (372d) size: 4
	idDeclInventory* equipmentItem; // offset: 178h (376d)  size: 8
	char pad_384[57]; // offset: 180h (384d) size: 57
	bool hammerShown; // offset: 1B9h (441d)  size: 1
	char pad_442[2]; // offset: 1BAh (442d) size: 2
	float hammerRecharge; // offset: 1BCh (444d)  size: 4
	float hammerSupercharge; // offset: 1C0h (448d)  size: 4
	bool hammerPulse; // offset: 1C4h (452d)  size: 1
	char pad_453[11]; // offset: 1C5h (453d) size: 11
	idSWFWidget_EquipmentItem* equipmentWidget; // offset: 1D0h (464d)  size: 8
	char pad_472[53]; // offset: 1D8h (472d) size: 53
	bool playingLowAmmoAnim; // offset: 20Dh (525d)  size: 1
	char pad_End[162]; // offset: 20Eh (526d) size: 162
}; // size: 688




//// idHUD_WeaponInfo : idHUDElement : idUIElement : idClass : idEventArgUser
//class idHUD_WeaponInfo {
//public:
//	char pad_0[248]; // offset: 0h (0d) size: 248
//	int updateFlags; // offset: F8h (248d)  size: 4
//	char pad_252[4]; // offset: FCh (252d) size: 4
//	idDeclWeapon* currentWeapon; // offset: 100h (256d)  size: 8
//	char pad_264[84]; // offset: 108h (264d) size: 84
//	int chainsawAmmo; // offset: 15Ch (348d)  size: 4
//	int chainsawMaxAmmo; // offset: 160h (352d)  size: 4
//	char pad_356[4]; // offset: 164h (356d) size: 4
//	bool crucibleEquipped; // offset: 168h (360d)  size: 1
//	bool crucibleShown; // offset: 169h (361d)  size: 1
//	char pad_362[2]; // offset: 16Ah (362d) size: 2
//	int crucibleCharge; // offset: 16Ch (364d)  size: 4
//	int crucibleMaxCharges; // offset: 170h (368d)  size: 4
//	char pad_372[4]; // offset: 174h (372d) size: 4
//	idDeclInventory* equipmentItem; // offset: 178h (376d)  size: 8
//	char pad_384[80]; // offset: 180h (384d) size: 80
//	idSWFWidget_EquipmentItem* equipmentWidget; // offset: 1D0h (464d)  size: 8
//	char pad_End[216]; // offset: 1D8h (472d) size: 216
//}; // size: 688




class idHUD_playerInhibitInfo_t {
public:
    //Offset 0x0 	Size 0x4 (4)
    idUCmdTracker_inhibitFlags_t inhibitFlags;
    //Offset 0x8 	Size 0x20 (32)
    idManagedClassPtr_idPlayer inhibitPlayer;
    //Offset 0x28 	Size 0x1 (1)
    bool takesDamage;
    //Offset 0x29 	Size 0x1 (1)
    bool controlTakesDamage;
    //Offset 0x2A 	Size 0x1 (1)
    bool disableMovementDuringCustomAnim;
};// Size: 0x30 (Size Dec: 48)


class tagData_t {
public:
    idVec3 trans; // offset: 0h (0d)  size: 12
    idQuat rot; // offset: Ch (12d)  size: 16
    char pad_End[4]; // offset: 1Ch (28d) size: 4
}; // size: 32


//class idDeclHUDElement_idHudSWFInfo_t {
//public:
//    char pad_0[16]; // offset: 0h (0d) size: 16
//    float nonPerspectiveScale; // offset: 10h (16d)  size: 4
//    char pad_20[20]; // offset: 14h (20d) size: 20
//    float swfScale; // offset: 28h (40d)  size: 4
//    char pad_End[36]; // offset: 2Ch (44d) size: 36
//}; // size: 80



struct idDeclHUDElement_idHudSWFInfo_t {
	//Offset 0x0 	Size 0x8 (8)	 The SWF to use for this HUD Element.
	void* idDeclSWF_swf; //idDeclSWF* swf;
	//Offset 0x8 	Size 0x1 (1)	 Do we create a custom gui model or use Global.
	bool customGUIModel; //! changes nothing for perspective collide
	//Offset 0xC 	Size 0x4 (4)	 The perspective plane this gui uses
	hudElementPerspective_t perspectiveGUI; //idDeclHUDElement::idHudSWFInfo_t::hudElementPerspective_t perspectiveGUI;
	//Offset 0x10 	Size 0x4 (4)	 The scale this GUI will use when shown the HUD perspective mode is off (HUD is fullscreen and flat)
	float nonPerspectiveScale;
	//Offset 0x14 	Size 0x1 (1)	 is this gui full screen?
	bool fullscreen;
	//Offset 0x15 	Size 0x1 (1)	 should the swf be a reference as opposed to a completely separate instance of the swf
	bool referencedGui;
	//Offset 0x18 	Size 0x8 (8)	 Tag to use from the player's helmet.
	idAtomicString helmetTag;
	//Offset 0x20 	Size 0x8 (8)	 Tag to use for the demon player.
	idAtomicString demonTag;
	//Offset 0x28 	Size 0x4 (4)	 scale of the swf.
	float swfScale;
	//Offset 0x2C 	Size 0xC (12)	 offset of the swf. ( from origin if no tag ) {{ units = m }}
	idVec3 swfOffset;
	//Offset 0x38 	Size 0x1 (1)	 Set this to true if this element will pause the game.
	bool pauseGame;
	//Offset 0x3C 	Size 0x4 (4)	 The hud element variant that this swf coresponds to
	int variant;
	//Offset 0x40 	Size 0x8 (8)	 The optional custom material to use for this hud elements render model
	idMaterial2* customMaterial;
	//Offset 0x48 	Size 0x1 (1)	 do we depth test this element.
	bool depthTest;
	//Offset 0x49 	Size 0x1 (1)	 does this unlink for hide Hud.
	bool neverUnlinkForHide;
	//Offset 0x4A 	Size 0x1 (1)	 Does this element support fade
	bool supportsFade;
	//Offset 0x4B 	Size 0x1 (1)	 Set this to true if this element will always run at normal speed even if gametime slows or pauses.
	bool forceRealtimeUpdates;
}; // Size: 0x50 (Size Dec: 80)



// idDeclHUDElement : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
class idDeclHUDElement {
public:
    char pad_0[144]; // offset: 0h (0d) size: 144
    idDeclHUDElement_idHudSWFInfo_t swfInfo; // offset: 90h (144d)  size: 80
    char pad_224[16]; // offset: E0h (224d) size: 16
    // idList < hudEventID_t , TAG_IDLIST , false >
    idList hudEventIDs; // offset: F0h (240d)  size: 24
    char pad_264[288]; // offset: 108h (264d) size: 288
    bool cacheImages; // offset: 228h (552d)  size: 1
    char pad_End[23]; // offset: 229h (553d) size: 23
}; // size: 576


// idHUDElement : idUIElement : idClass : idEventArgUser
class idHUDElement {
public:
    char pad_0[200]; // offset: 0h (0d) size: 200
    idDeclHUDElement* decl; // offset: C8h (200d)  size: 8
    unsigned short hudSysId; // offset: D0h (208d)  size: 2
    char pad_210[2]; // offset: D2h (210d) size: 2
    tagData_t tagData; // offset: D4h (212d)  size: 32
    bool isFaded; // offset: F4h (244d)  size: 1
    char pad_End[3]; // offset: F5h (245d) size: 3
}; // size: 248





//? this was so wrong, offsets were bs.
class idHUD_OLD {
public:
    char pad_0[12]; // offset: 0h (0d) size: 12
    unsigned short broadcastSystemId; // offset: Ch (12d)  size: 2
    char pad_14[2]; // offset: Eh (14d) size: 2
    // idGrowableList < idHUDElement * , 20 , TAG_IDLIST >
    void* idGrowableList_elements; // offset: 10h (16d)  size: 184
    char pad_200[720]; // offset: C8h (200d) size: 720 
    // idList < idMenu * , TAG_IDLIST , false >
    idList menus; // offset: 398h (920d)  size: 24
    int pauseMenuIndex; // offset: 3B0h (944d)  size: 4
    bool isPOIVisible; // offset: 3B4h (948d)  size: 1
    bool readyForMapStart; // offset: 3B5h (949d)  size: 1
    char pad_950[50]; // offset: 3B6h (950d) size: 50
    int currentHudMode; // offset: 3E8h (1000d)  size: 4
    bool gameWasPaused; // offset: 3ECh (1004d)  size: 1
    bool inScope; // offset: 3EDh (1005d)  size: 1
    bool prevShowMenuVisibilityMask; // offset: 3EEh (1006d)  size: 1
    char pad_End[1]; // offset: 3EFh (1007d) size: 1
}; // size: 1008



struct idHUD {
    //Offset 0x0 	Size 0x8 (8)	 decl that defines the hud.
    void* idDeclHUD_declHUD;
    //Offset 0x8 	Size 0x4 (4)	 The player index this HUD responds to
    int playerIndex;
    //Offset 0xC 	Size 0x2 (2)	 system id for 'HUD' in the event system
    int broadcastSystemId;
    //Offset 0x10 	Size 0xB8 (184)	 All hud elements known by idHUD
    //void* idGrowableList_elements;
    //char pad_18[176]; //  idGrowableList < idHUDElement*, 20, TAG_IDLIST > elements;   
    char idGrowableList_idHUDElement_elements[184]; //  idGrowableList < idHUDElement*, 20, TAG_IDLIST > elements;   
    //Offset 0xC8 	Size 0xB8 (184)	 All hud notifications known by idHUD
    char idGrowableList_idHUDElement_notifications[184]; // idGrowableList < idHUDElement*, 20, TAG_IDLIST > otifications;
    //Offset 0x180 	Size 0xB8 (184)	 The hud elements and notifications lists, combined, sorted in render order.
    char idGrowableList_idHUDElement_hudElementRenderOrder[184];  //idGrowableList < idHUDElement*, 20, TAG_IDLIST > hudElementRenderOrder;
    //Offset 0x238 	Size 0x160 (352)	 OLD - All of the HUD menus (that are elements)
    char idStaticList_idHUDElement_menuElements[352];  //idStaticList < idHUDElement*, 41, false, TAG_IDLIST > menuElements;
    //Offset 0x398 	Size 0x18 (24)	 NEW - All of the HUD menus (that are menus)
    idList menus; //  idList < idMenu*, TAG_IDLIST, false > menus;
    //Offset 0x3B0 	Size 0x4 (4)	 Into into 'm_menus' where the pause menu resides. Cache this since it's needed specially in update and render calls.
    int pauseMenuIndex;
    //Offset 0x3B4 	Size 0x1 (1)	 State if the POI hidden
    bool isPOIVisible;
    //Offset 0x3B5 	Size 0x1 (1)	 Ready to show map start UI when HUD becomes visible
    bool readyForMapStart;
    //Offset 0x3B8 	Size 0x30 (48)
    idHUD_playerInhibitInfo_t savedInhibit;
    //Offset 0x3E8 	Size 0x4 (4)	 Hud Modes Mode that we are currently in.
    hudElementFlags_t currentHudMode;
    //Offset 0x3EC 	Size 0x1 (1)	 was the game paused last frame according to mapLocal
    bool gameWasPaused;
    //Offset 0x3ED 	Size 0x1 (1)
    bool inScope;
    //Offset 0x3EE 	Size 0x1 (1)
    bool prevShowMenuVisibilityMask;
    //Offset 0x3EF 	Size 0x1 (1)
    bool requestAntialiasingFlush;
}; // Size: 0x3F0 (Size Dec: 1008)



// idGameSystemLocal : idGameSystem
class idGameSystemLocal {
public:
    char pad_0[80]; // offset: 0h (0d) size: 80
    // idMapInstance_Interface
    void* mapInstance; // offset: 50h (80d)  size: 8
    char pad_End[40592]; // offset: 58h (88d) size: 40592
}; // size: 40680


// idInventoryItem : idEventReceiver : idManagedClass : idClass : idEventArgUser
class idInventoryItem {
public:
    char pad_0[56]; // offset: 0h (0d) size: 56
    idDeclInventory* decl; // offset: 38h (56d)  size: 8
    char pad_End[208]; // offset: 40h (64d) size: 208
}; // size: 272


// idEntity : idEngineEntity : idEventReceiver : idManagedClass : idClass : idEventArgUser
class idEntity {
public:
    char pad_0[64]; // offset: 0h (0d) size: 64
    idStr name; // offset: 40h (64d)  size: 48
    unsigned int prefabInstanceId; // offset: 70h (112d)  size: 4
    idVec3 spawnPosition; // offset: 74h (116d)  size: 12
    char pad_End[448]; // offset: 80h (128d) size: 448
}; // size: 576


class idInventoryCollection {
public:
    // idList < idManagedClassPtr < idInventoryItem > , TAG_IDLIST , false >
    idList inventory; // offset: 0h (0d)  size: 24
    char pad_End[1360]; // offset: 18h (24d) size: 1360
}; // size: 1384


// idActor : idAnimatedEntity : idBloatedEntity : idEntity : idEngineEntity : idEventReceiver : idManagedClass : idClass : idEventArgUser
class idActor {
public:
    char pad_0[10272]; // offset: 0h (0d) size: 10272
    bool pinged; // offset: 2820h (10272d)  size: 1
    char pad_10273[3511]; // offset: 2821h (10273d) size: 3511
    idInventoryCollection inventory; // offset: 35D8h (13784d)  size: 1384
    char pad_15168[4112]; // offset: 3B40h (15168d) size: 4112
    float overdrivePoints; // offset: 4B50h (19280d)  size: 4
    char pad_19284[124]; // offset: 4B54h (19284d) size: 124
    // idTypesafeTime < long long , gameTimeUnique_t , 999960 >
    long long lastTeleportTime; // offset: 4BD0h (19408d)  size: 8
}; // size: 19416


// idGK_UpgradeHandler : idUpgradeHandler
class idGK_UpgradeHandler {
public:
    char pad_0[312]; // offset: 0h (0d) size: 312
    float bloodPunchChargePercent; // offset: 138h (312d)  size: 4
    char pad_316[68]; // offset: 13Ch (316d) size: 68
    fxCondition_t fxBloodPunchAOE; // offset: 180h (384d)  size: 4
    char pad_388[5]; // offset: 184h (388d) size: 5
    bool bloodPunchSuperChargedSoundActivated; // offset: 189h (393d)  size: 1
    char pad_End[6]; // offset: 18Ah (394d) size: 6
}; // size: 400


// idPlayerDashboard : idDamageCompiler_Listener
class idPlayerDashboard {
public:
    char pad_0[61768]; // offset: 0h (0d) size: 61768
    idGK_UpgradeHandler GKUpgrades; // offset: F148h (61768d)  size: 400
    char pad_End[1856]; // offset: F2D8h (62168d) size: 1856
}; // size: 64024


class idPlayer_equipmentInfo_t_itemData_t {
public:
    // idTypesafeTime < long long , gameTimeUnique_t , 999960 >
    long long equipmentRechargeStartTime; // offset: 0h (0d)  size: 8
    // idTypesafeTime < long long , gameTimeUnique_t , 999960 >
    long long equipmentRechargeDuration; // offset: 8h (8d)  size: 8
    // idTypesafeTime < long long , gameTimeUnique_t , 999960 >
    long long equipmentRechargeTime; // offset: 10h (16d)  size: 8
    // idTypesafeTime < long long , gameTimeUnique_t , 999960 >
    long long equipmentReuseTime; // offset: 18h (24d)  size: 8
    int equipmentUsesAvailable; // offset: 20h (32d)  size: 4
    char pad_End[4]; // offset: 24h (36d) size: 4
}; // size: 40


class idPlayer_equipmentInfo_t {
public:
    int currentIndex; // offset: 0h (0d)  size: 4
    char pad_4[36]; // offset: 4h (4d) size: 36
    // idArray < idPlayer::equipmentInfo_t::itemData_t , 4 >
    idPlayer_equipmentInfo_t_itemData_t equipmentItems_ptr[4]; // offset: 28h (40d)  size: 160
    char pad_End[16]; // offset: C8h (200d) size: 16
}; // size: 216



//! Player props:

struct idDeclPlayerProps_validEquipmentEntry_t {
    //Offset 0x0 	Size 0x8 (8)	 the equipment item
    idDeclInventory* item;
    //Offset 0x8 	Size 0x1 (1)	 selectable or not - generally yes but in the case of the equipment launcher
    bool selectable;
    //Offset 0xC 	Size 0x4 (4)	 there are left and right equipment launcher items but only the left will be selectable and then both are used at once if present for convenience to be able to associate this decl with a type for use with Equipment_UpgradeHandler
    equipmentType_t type;
}; // Size: 0x10 (Size Dec: 16)




struct idPlayerBodyReactionState_t {
    //Offset 0x0 	Size 0x8 (8)	 the name of the state
    idAtomicString name;
    //Offset 0x8 	Size 0x30 (48)	 the destination animweb state for the third person body
    char idAnimWebPath_tpBodyDestPath[48];
    //Offset 0x38 	Size 0x30 (48)	 the via animweb state for the third person body
    char idAnimWebPath_tpBodyViaPath[48];
    //Offset 0x68 	Size 0x4 (4)	 the first person hands anim to play (or NONE to hide the fp hands)
    idHandsCustomAnimSelect fpHandsCustomAnim;
}; // Size: 0x70 (Size Dec: 112)


// Inheritance: idPlayerBodyReactionDescriptor_t
struct idPlayerBodyReaction_t {
    char pad0[18];
    //Offset 0x18 	Size 0x1 (1)	 on / off switch for this state
    bool enable;
    //Offset 0x1C 	Size 0x4 (4)	 event position must be no closer than this distance for this reaction to apply (0 to ignore) {{ units = m }}
    float rangeMin;
    //Offset 0x20 	Size 0x4 (4)	 event position must be no farther than this distance for this reaction to apply (0 to ignore) {{ units = m }}
    float rangeMax;
    //Offset 0x28 	Size 0x70 (112)	 start state
    idPlayerBodyReactionState_t state_start;
    //Offset 0x98 	Size 0x70 (112)	 impact ground (alive)
    idPlayerBodyReactionState_t state_impactGround;
    //Offset 0x108 	Size 0x70 (112)	 impact ground (dead)
    idPlayerBodyReactionState_t state_impactGroundDead;
    //Offset 0x178 	Size 0x4 (4)	 number of directions for this reaction
    playerBodyReactionNumDirs_t reactionNumDirs;
    //Offset 0x17C 	Size 0x4 (4)	 supports randomization within the reaction
    int reactionNumVariations;
    //Offset 0x180 	Size 0x1 (1)	 rotate the body so the selected direction is aligned with the reaction center
    bool reactionAlignToDir;
    //Offset 0x181 	Size 0x1 (1)	 whether the view is inhibited or not
    bool inhibitView;
    //Offset 0x184 	Size 0x4 (4)	 the size of the pitch constraint cone
    float pitchConstraintDegs;
    //Offset 0x188 	Size 0x4 (4)	 the size of the yaw constraint cone
    float yawConstraintDegs;
    //Offset 0x18C 	Size 0x1 (1)	 either clip the camera movement on an anim with a fixed origin or, better, let the physics system clip the origin movement, but most anims in this system have fixed origin
    bool clipCameraMovement;
}; // Size: 0x190 (Size Dec: 400)


// Inheritance: idDeclTypeInfo: idDecl: idResource
struct idSoundEvent{
	char pad0[0x88];
	//Offset 0x88 	Size 0x4 (4)
	int idSoundWwiseID_eventID;
	int padLast;
}; // Size: 0x90 (Size Dec: 144)



struct idDeclPlayerProps_playerSounds_t {
	//Offset 0x0 	Size 0x8 (8)	 Sound to play when a tutorial starts.
	idSoundEvent* sndObjectiveAdded;
	//Offset 0x8 	Size 0x8 (8)	 Sound to play when a tutorial starts.
	idSoundEvent* sndObjectiveCompleted;
	//Offset 0x10 	Size 0x8 (8)	 Sound to play when a tutorial starts.
	idSoundEvent* sndMainObjectiveAdded;
	//Offset 0x18 	Size 0x8 (8)	 Sound to play when a tutorial starts.
	idSoundEvent* sndMainObjectiveCompleted;
	//Offset 0x20 	Size 0x8 (8)	 Sound to play when a tutorial starts.
	idSoundEvent* sndMapUpdated;
	//Offset 0x28 	Size 0x8 (8)	 Sound to play when a tutorial starts.
	idSoundEvent* sndTutorialStart;
	//Offset 0x30 	Size 0x8 (8)	 Sound to play when starting to use something
	idSoundEvent* sndUseStart;
	//Offset 0x38 	Size 0x8 (8)	 Sound to play when finished using something
	idSoundEvent* sndUseEnd;
	//Offset 0x40 	Size 0x8 (8)	 sound to play when down and almost dead ( formerly while waiting for d e f i b )
	idSoundEvent* sndAlmostDead;
	//Offset 0x48 	Size 0x8 (8)	 sound to play when health drops below 10
	idSoundEvent* sndBreatheHeavy;
	//Offset 0x50 	Size 0x8 (8)	 sound to play when health drops below 20
	idSoundEvent* sndBreatheMedium;
	//Offset 0x58 	Size 0x8 (8)	 sound to play when health drops below 20
	idSoundEvent* sndBreatheSprinting;
	//Offset 0x60 	Size 0x8 (8)	 sound to play when player cannot use or pickup an item
	idSoundEvent* sndCantUseItem;
	//Offset 0x68 	Size 0x8 (8)	 sound to play when a checkpoint is saved
	idSoundEvent* sndCheckpointSaved;
	//Offset 0x70 	Size 0x8 (8)	 sound to play when quick using with no items available
	idSoundEvent* sndOutOfItems;
	//Offset 0x78 	Size 0x8 (8)	 generic sound for picking up an item
	idSoundEvent* sndPickup;
	//Offset 0x80 	Size 0x8 (8)	 sound for possessing actors
	idSoundEvent* sndPossess;
	//Offset 0x88 	Size 0x8 (8)	 sound looped during actor possession
	idSoundEvent* sndPossessLoop;
	//Offset 0x90 	Size 0x8 (8)	 sound to play when player receives potential health
	idSoundEvent* sndUseBandage;
	//Offset 0x98 	Size 0x8 (8)	 sound when burning
	idSoundEvent* sndBurn;
	//Offset 0xA0 	Size 0x8 (8)	 controller sound
	idSoundEvent* sndButtonBad;
	//Offset 0xA8 	Size 0x8 (8)	 controller sound
	idSoundEvent* sndButtonDown;
	//Offset 0xB0 	Size 0x8 (8)	 When we go into Weapon select
	idSoundEvent* sndWeaponSelectIn;
	//Offset 0xB8 	Size 0x8 (8)	 When we go Out of Weapon select
	idSoundEvent* sndWeaponSelectOut;
	//Offset 0xC0 	Size 0x8 (8)	 When secondary fire is pulled but the weapon has none
	idSoundEvent* sndWeaponNoSecondary;
	//Offset 0xC8 	Size 0x8 (8)	 controller sound
	idSoundEvent* sndButtonUp;
	//Offset 0xD0 	Size 0x8 (8)	 sound when player tries dropping an item into a solid
	idSoundEvent* sndCantDropItem;
	//Offset 0xD8 	Size 0x8 (8)	 sound to play when the player tries to loot something but can't... maybe it's empty?
	idSoundEvent* sndCantLootEntity;
	//Offset 0xE0 	Size 0x8 (8)	 controller sound
	idSoundEvent* sndClickDown;
	//Offset 0xE8 	Size 0x8 (8)	 controller sound
	idSoundEvent* sndClickUp;
	//Offset 0xF0 	Size 0x8 (8)	 death sound
	idSoundEvent* sndDeath;
	//Offset 0xF8 	Size 0x8 (8)	 sound to play when the player disassembles something successfully
	idSoundEvent* sndDisassemble;
	//Offset 0x100 	Size 0x8 (8)	 sound to play when the player view enters water (ie: a bubble loop)
	idSoundEvent* sndEnterWater;
	//Offset 0x108 	Size 0x8 (8)	 sound to play when the player view exits water (ie: some sort of gasp)
	idSoundEvent* sndExitWater;
	//Offset 0x110 	Size 0x8 (8)	 sound to play when jumping
	idSoundEvent* sndJump;
	//Offset 0x118 	Size 0x8 (8)	 sound to play when double jumping (demon player)
	idSoundEvent* sndDoubleJump;
	//Offset 0x120 	Size 0x8 (8)	 sound to play when crouching
	idSoundEvent* sndCrouch;
	//Offset 0x128 	Size 0x8 (8)	 sound to play when standing up
	idSoundEvent* sndStandUp;
	//Offset 0x130 	Size 0x8 (8)	 sound to play for a landing on a surface that has NO DAMAGE
	idSoundEvent* sndLandNoDamage;
	//Offset 0x138 	Size 0x8 (8)	 sound to play while falling when impact will be a large landing or worse
	idSoundEvent* sndFallingLargeLandingStart;
	//Offset 0x140 	Size 0x8 (8)	 sound to play to stop fallingLargeLanding sound
	idSoundEvent* sndFallingLargeLandingStop;
	//Offset 0x148 	Size 0x8 (8)	 sound to play when falling a fatal distance
	idSoundEvent* sndFallingFatal;
	//Offset 0x150 	Size 0x8 (8)	 sound to play when the player successfully loots something.
	idSoundEvent* sndLootEntity;
	//Offset 0x158 	Size 0x8 (8)	 sound to play when a cinematic is skipped
	idSoundEvent* sndSkipCinematic;
	//Offset 0x160 	Size 0x8 (8)	 sound to play when the player is at low health.
	idSoundEvent* sndLowHealth;
	//Offset 0x168 	Size 0x8 (8)	 sound to play when the player recovers from low health.
	idSoundEvent* sndLowHealthRecovery;
	//Offset 0x170 	Size 0x4 (4)	 how many ms to wait before can play sndLowHealth or sndLowHealthRecovery again after playing each one (tracked separately)
	//idTypesafeTime < int, millisecondUnique_t, 1000 > minLowHealthSoundsRepeatMS;
	int minLowHealthSoundsRepeatMS;
	//Offset 0x178 	Size 0x8 (8)	 foley sound for legs crossing (added from Doom4)
	idSoundEvent* sndLegsCrossing;
	//Offset 0x180 	Size 0x8 (8)	 foley sound for legs crossing when crouched (added from Doom4)
	idSoundEvent* sndLegsCrossingCrouched;
	//Offset 0x188 	Size 0x8 (8)	 sound shader to play for small amounts of damage
	idSoundEvent* sndPainSmall;
	//Offset 0x190 	Size 0x8 (8)	 sound shader to play for medium amounts of damage
	idSoundEvent* sndPainMedium;
	//Offset 0x198 	Size 0x8 (8)	 sound shader to play for large amounts of damage
	idSoundEvent* sndPainLarge;
	//Offset 0x1A0 	Size 0x8 (8)	 sound shader to play for small amounts of damage instead of sndPainSmall when it's self-inflicted
	idSoundEvent* sndSelfPainSmall;
	//Offset 0x1A8 	Size 0x8 (8)	 sound shader to play for medium amounts of damage instead of sndPainMedium when it's self-inflicted
	idSoundEvent* sndSelfPainMedium;
	//Offset 0x1B0 	Size 0x8 (8)	 sound shader to play for large amounts of damage instead of sndPainMedium when it's self-inflicted
	idSoundEvent* sndSelfPainLarge;
	//Offset 0x1B8 	Size 0x4 (4)	 health threshold to use very low pain small, medium, large
	float veryLowSoundsHealthThreshold;
	//Offset 0x1C0 	Size 0x8 (8)	 if health is under veryLowSoundsHealthThreshold we always play this sound
	idSoundEvent* sndVeryLowPain;
	//Offset 0x1C8 	Size 0x8 (8)	 sound to play when the player's armor gets depleted
	idSoundEvent* sndSelfArmorDepleted;
	//Offset 0x1D0 	Size 0x8 (8)	 sound shader to play when the player is low health
	idSoundEvent* sndHeartBeatLub;
	//Offset 0x1D8 	Size 0x8 (8)	 sound shader to play when the player is low health
	idSoundEvent* sndHeartBeatDub;
	//Offset 0x1E0 	Size 0x8 (8)	 shader for canceling revive
	idSoundEvent* sndCancelRevive;
	//Offset 0x1E8 	Size 0x8 (8)	 shader for when revive goes through
	idSoundEvent* sndFinishRevive;
	//Offset 0x1F0 	Size 0x4 (4)	 don't play two of the same type of feedback sounds sooner than this many MS apart
	//idTypesafeTime < int, millisecondUnique_t, 1000 > feedbackSoundMinRetriggerMS;
	int feedbackSoundMinRetriggerMS;
	//Offset 0x1F8 	Size 0x8 (8)	 damage feedback sound to play (non headshots only - headshots use sndDmgDealtHeadShotFeedback)
	idSoundEvent* sndDmgDealtFeedback;
	//Offset 0x200 	Size 0x8 (8)	 damage to armor feedback sound
	idSoundEvent* sndDmgDealtToArmorFeedback;
	//Offset 0x208 	Size 0x8 (8)	 damage feedback sound to play for melee damage
	idSoundEvent* sndMeleeDmgDealtFeedback;
	//Offset 0x210 	Size 0x8 (8)	 damage feedback sound to play for non melee headshots (headShot = true in damageScalarDamageFlags_t) (supersedes sndDmgDealthHeadShotFeedback)
	idSoundEvent* sndHeadShotDmgDealtFeedback;
	//Offset 0x218 	Size 0x8 (8)	 damage feedback on critical hits
	idSoundEvent* sndCritDmgDealtFeedback;
	//Offset 0x220 	Size 0x8 (8)	 attempted to teleport to a location that player will not fit and no good teleport positions were ever discovered
	idSoundEvent* sndMPTeleportFailed;
	//Offset 0x228 	Size 0x8 (8)	 threw a teleporter but never activated it
	idSoundEvent* sndMPTeleporterTimedOut;
	//Offset 0x230 	Size 0x8 (8)	 threw a teleporter but someone shot it
	idSoundEvent* sndMPTeleporterDestroyed;
	//Offset 0x238 	Size 0x8 (8)	 threw an exploding projectile and it didn't hit anyone
	idSoundEvent* sndMPExplosionMissed;
	//Offset 0x240 	Size 0x8 (8)	 my slicer got destroyed
	idSoundEvent* sndMPSlicerDestroyed;
	//Offset 0x248 	Size 0x8 (8)	 i got pinged by an enemy sensor
	idSoundEvent* sndMPPingVictim;
	//Offset 0x250 	Size 0x8 (8)	 my threat sensor got destroyed
	idSoundEvent* sndMPThreatSensorDestroyedExpired;
	//Offset 0x258 	Size 0x8 (8)	 my threat sensor expired or reployed
	idSoundEvent* sndMPThreatSensorExpired;
	//Offset 0x260 	Size 0x8 (8)	 i got pinged by an enemy sensor
	idSoundEvent* sndMPHealBySiphon;
	//Offset 0x268 	Size 0x8 (8)	 drone is seeking me
	idSoundEvent* sndMPDroneTarget;
	//Offset 0x270 	Size 0x8 (8)	 my drone is seeking a target
	idSoundEvent* sndMPDroneSeeking;
	//Offset 0x278 	Size 0x8 (8)	 my drone attacked its target
	idSoundEvent* sndMPDroneAttackedTarget;
	//Offset 0x280 	Size 0x8 (8)	 my turret was destroyed or timed out
	idSoundEvent* sndMPTurretDestroyed;
	//Offset 0x288 	Size 0x8 (8)	 my turret attacked somebody
	idSoundEvent* sndMPTurretAttacked;
	//Offset 0x290 	Size 0x8 (8)	 damaged by a siphon grenade
	idSoundEvent* sndMPDamageBySiphon;
	//Offset 0x298 	Size 0x8 (8)	 becoming frozen in Freeze Tag
	idSoundEvent* sndMPOnFrozen;
	//Offset 0x2A0 	Size 0x8 (8)	 played on a frozen player who begins being thawed
	idSoundEvent* sndMPStartThawingLoop;
	//Offset 0x2A8 	Size 0x8 (8)	 played when a frozen player being thawed is interrupted from thawing
	idSoundEvent* sndMPInterruptThawing;
	//Offset 0x2B0 	Size 0x8 (8)	 played when a frozen player is successfully thawed
	idSoundEvent* sndMPOnThawed;
	//Offset 0x2B8 	Size 0x8 (8)	 i entered an enemy siphon, start the loop
	idSoundEvent* sndMPStartEnterSiphonLoop;
	//Offset 0x2C0 	Size 0x8 (8)	 stop the siphon loop
	idSoundEvent* sndMPStopEnterSiphonLoop;
	//Offset 0x2C8 	Size 0x8 (8)	 i'm inside the siphon, modify all sounds
	idSoundEvent* sndMPStartSiphonDistortion;
	//Offset 0x2D0 	Size 0x8 (8)	 left the siphon, stop the distortion
	idSoundEvent* sndMPStopSiphonDistortion;
	//Offset 0x2D8 	Size 0x8 (8)	 sound shader to play when quad damage end
	idSoundEvent* sndEndQuadDamage;
	//Offset 0x2E0 	Size 0x8 (8)	 gieger tick which is played more rapidly as we approach danger
	idSoundEvent* sndRadiationWarning;
	//Offset 0x2E8 	Size 0x8 (8)	 sound when we are actually in the radiation volume
	idSoundEvent* sndRadiationDamage;
	//Offset 0x2F0 	Size 0x8 (8)	 sound to play when the player gets to full Radiation.
	idSoundEvent* sndRadiationVO;
	//Offset 0x2F8 	Size 0x8 (8)	 extreme heat tick which is played more rapidly as we approach danger
	idSoundEvent* sndFireWarning;
	//Offset 0x300 	Size 0x8 (8)	 sound when we are taking damage from heat
	idSoundEvent* sndFireDamage;
	//Offset 0x308 	Size 0x8 (8)	 sound to play when the player gets to full Heat.
	idSoundEvent* sndFireVO;
	//Offset 0x310 	Size 0x8 (8)	 gieger tick which is played more rapidly as we approach danger
	idSoundEvent* sndBioWarning;
	//Offset 0x318 	Size 0x8 (8)	 sound when we are actually in the radiation volume
	idSoundEvent* sndBioDamage;
	//Offset 0x320 	Size 0x8 (8)	 sound to play when the player gets to full Radiation.
	idSoundEvent* sndBioVO;
	//Offset 0x328 	Size 0x8 (8)	 extreme heat tick which is played more rapidly as we approach danger
	idSoundEvent* sndLavaWarning;
	//Offset 0x330 	Size 0x8 (8)	 sound when we are taking damage from heat
	idSoundEvent* sndLavaDamage;
	//Offset 0x338 	Size 0x8 (8)	 sound to play when the player gets to full Heat.
	idSoundEvent* sndLavaVO;
	//Offset 0x340 	Size 0x8 (8)	 sound to play when EMInterference is present
	idSoundEvent* sndEMIPresent;
	//Offset 0x348 	Size 0x8 (8)	 sound to play when EMInterference dissipates
	idSoundEvent* sndEMIDissipate;
	//Offset 0x350 	Size 0x8 (8)	 sound when the environment suit is charging
	idSoundEvent* sndEnviromentSuitCharge;
	//Offset 0x358 	Size 0x8 (8)	 sound when the environment suit is finished charging
	idSoundEvent* sndEnviromentSuitChargeDone;
	//Offset 0x360 	Size 0x8 (8)	 Sound when player initiates a dodge.
	idSoundEvent* sndDodgeInitiate;
	//Offset 0x368 	Size 0x8 (8)	 Sound when player ends a dodge.
	idSoundEvent* sndDodgeEnd;
	//Offset 0x370 	Size 0x8 (8)	 Sound when player has valid backstab.
	idSoundEvent* sndDodgeBackstab;
	//Offset 0x378 	Size 0x8 (8)	 Sound when enemy is glory killable.
	idSoundEvent* sndHostileGloryKillable;
	//Offset 0x380 	Size 0x8 (8)	 Sound when player goes up a level
	idSoundEvent* sndLevelUp;
	//Offset 0x388 	Size 0x8 (8)	 Sound when player goes up an echelon
	idSoundEvent* sndEchelonUp;
	//Offset 0x390 	Size 0x8 (8)	 Sound when player completes a challenge
	idSoundEvent* sndChallengeComplete;
	//Offset 0x398 	Size 0x8 (8)	 Sound when player completes a challenge
	idSoundEvent* sndChallengeUpdate;
	//Offset 0x3A0 	Size 0x8 (8)	 Sound when player finds secret.
	idSoundEvent* sndSecretFound;
	//Offset 0x3A8 	Size 0x8 (8)	 sound when player unlocks suit slot.
	idSoundEvent* sndSuitSlotUnlock;
	//Offset 0x3B0 	Size 0x8 (8)	 sound when player purchases an upgrade
	idSoundEvent* sndDossierPurchaseUpgrade;
	//Offset 0x3B8 	Size 0x8 (8)	 sound when player begins a purchase
	idSoundEvent* sndDossierBeginPurchase;
	//Offset 0x3C0 	Size 0x8 (8)	 sound when player cancels a purchase
	idSoundEvent* sndDossierCancelPurchase;
	//Offset 0x3C8 	Size 0x8 (8)	 sound when player gains a mastery
	idSoundEvent* sndDossierGetMastery;
	//Offset 0x3D0 	Size 0x8 (8)	 sound when player gains a mod
	idSoundEvent* sndGainWeaponMod;
	//Offset 0x3D8 	Size 0x8 (8)	 Sound when player is in fast Hint level.
	idSoundEvent* secretHintLevelFast;
	//Offset 0x3E0 	Size 0x8 (8)	 Sound when player is in medium Hint level.
	idSoundEvent* secretHintLevelMedium;
	//Offset 0x3E8 	Size 0x8 (8)	 Sound when player is in slow Hint level.
	idSoundEvent* secretHintLevelSlow;
	//Offset 0x3F0 	Size 0x8 (8)	 Sound when player Gains a codex.
	idSoundEvent* sndCodexGained;
	//Offset 0x3F8 	Size 0x8 (8)	 Sound when player gains a point from combat score.
	idSoundEvent* sndCombatScoreStarComplete;
	//Offset 0x400 	Size 0x8 (8)	 Sound when visor appears on EOL.
	idSoundEvent* sndEOLVisor;
	//Offset 0x408 	Size 0x8 (8)	 Sound when combat score appears on EOL
	idSoundEvent* sndEOLCombatScore;
	//Offset 0x410 	Size 0x8 (8)	 Sound when challenges appear on EOL.
	idSoundEvent* sndEOLChallenges;
	//Offset 0x418 	Size 0x8 (8)	 Sound when collectibles appear on EOL.
	idSoundEvent* sndEOLCollectables;
	//Offset 0x420 	Size 0x8 (8)	 Sound when player continues to the next level.
	idSoundEvent* sndEOLContinue;
	//Offset 0x428 	Size 0x8 (8)	 Sound photomode pause unpause events
	idSoundEvent* sndPhotoModePause;
	//Offset 0x430 	Size 0x8 (8)	 Sound photomode pause unpause events
	idSoundEvent* sndPhotoModeUnpause;
	//Offset 0x438 	Size 0x8 (8)	 Sound when an equipped rune's passive ability activates
	idSoundEvent* sndRunePassiveTriggered;
	//Offset 0x440 	Size 0x8 (8)	 Sound when the player tries to use an argentum ability when it's not ready to be used.
	idSoundEvent* sndArgentumAbilityUnusable;
	//Offset 0x448 	Size 0x8 (8)	 sound to play when equipment is charged and ready
	idSoundEvent* sndEquipmentChargedAndReadyFrag;
	//Offset 0x450 	Size 0x8 (8)	 sound to play when the ice bomb is charged and ready
	idSoundEvent* sndEquipmentChargedAndReadyIceBomb;
	//Offset 0x458 	Size 0x8 (8)	 sound to play when flame belch is charged and ready
	idSoundEvent* sndEquipmentChargedAndReadyFlameBelch;
	//Offset 0x460 	Size 0x8 (8)	 sound to play when chainsaw is charged and ready
	idSoundEvent* sndChainsawChargedAndReady;
	//Offset 0x468 	Size 0x8 (8)	 sound to play when using chainsaw with not enough fuel
	idSoundEvent* sndOutOfChainsawFuel;
	//Offset 0x470 	Size 0x8 (8)	 sound to play when using crucible with not enough fuel
	idSoundEvent* sndOutOfCrucibleFuel;
	//Offset 0x478 	Size 0x8 (8)	 sound to play when demon ability is denied
	idSoundEvent* sndDemonAbilityDenied;
	//Offset 0x480 	Size 0x18 (24)	 locked on sounds
	//idList < idDeclPlayerProps::lockOnSoundInfo_t, TAG_IDLIST, false > lockedOnSounds;
	idList lockedOnSounds;
}; // Size: 0x498 (Size Dec: 1176)




// idDeclPlayerProps : idGameDeclTypeInfo : idDeclTypeInfo : idDecl : idResource
class idDeclPlayerProps {
public:
	char pad_0[144]; // offset: 0h (0d) size: 144
	idDeclPlayerProps_playerSounds_t sounds; // offset: 90h (144d)  size: 1176
	char pad_1320[792]; // offset: 528h (1320d) size: 792
	// idList < idDeclPlayerProps::validEquipmentEntry_t , TAG_IDLIST , false >
	idList validEquipmentList; // offset: 840h (2112d)  size: 24
	char pad_End[224]; // offset: 858h (2136d) size: 224
}; // size: 2360


// idPlayer : idActor : idAnimatedEntity : idBloatedEntity : idEntity : idEngineEntity : idEventReceiver : idManagedClass : idClass : idEventArgUser
class idPlayer {
public:
	char pad_0[28472]; // offset: 0h (0d) size: 28472
	// idTypesafeTime < long long , gameTimeUnique_t , 999960 >
	long long lastDelay; // offset: 6F38h (28472d)  size: 8
	// idTypesafeTime < int , millisecondUnique_t , 1000 >
	int globalCooldownTimeMS; // offset: 6F40h (28480d)  size: 4
	char pad_28484[4]; // offset: 6F44h (28484d) size: 4
	idPlayer_equipmentInfo_t equipmentInfo; // offset: 6F48h (28488d)  size: 216
	char pad_28704[1008]; // offset: 7020h (28704d) size: 1008
	bool wantZoom; // offset: 7410h (29712d)  size: 1
	char pad_29713[4244]; // offset: 7411h (29713d) size: 4244
	bool hideReticle; // offset: 84A5h (33957d)  size: 1
	bool hideHudForCinematic; // offset: 84A6h (33958d)  size: 1
	char pad_33959[521]; // offset: 84A7h (33959d) size: 521
	bool contextOptionSelected; // offset: 86B0h (34480d)  size: 1
	char pad_34481[15]; // offset: 86B1h (34481d) size: 15
	int hudFlagsBeforeDemon; // offset: 86C0h (34496d)  size: 4
	char pad_34500[60364]; // offset: 86C4h (34500d) size: 60364
	idPlayerDashboard dashboard; // offset: 17290h (94864d)  size: 64024
	char pad_158888[34896]; // offset: 26CA8h (158888d) size: 34896
	idDeclPlayerProps* playerProps; // offset: 2F4F8h (193784d)  size: 8
	char pad_193792[97744]; // offset: 2F500h (193792d) size: 97744
	idHUD playerHud; // offset: 472D0h (291536d)  size: 1008
	char pad_End[23704]; // offset: 476C0h (292544d) size: 23704
}; // size: 316248

// idPlayer : idActor : idAnimatedEntity : idBloatedEntity : idEntity : idEngineEntity : idEventReceiver : idManagedClass : idClass : idEventArgUser
//class idPlayer {
//public:
//    char pad_0[28472]; // offset: 0h (0d) size: 28472
//    // idTypesafeTime < long long , gameTimeUnique_t , 999960 >
//    long long lastDelay; // offset: 6F38h (28472d)  size: 8
//    // idTypesafeTime < int , millisecondUnique_t , 1000 >
//    int globalCooldownTimeMS; // offset: 6F40h (28480d)  size: 4
//    char pad_28484[4]; // offset: 6F44h (28484d) size: 4
//    idPlayer_equipmentInfo_t equipmentInfo; // offset: 6F48h (28488d)  size: 216
//    char pad_28704[1008]; // offset: 7020h (28704d) size: 1008
//    bool wantZoom; // offset: 7410h (29712d)  size: 1
//    char pad_29713[4244]; // offset: 7411h (29713d) size: 4244
//    bool hideReticle; // offset: 84A5h (33957d)  size: 1
//    bool hideHudForCinematic; // offset: 84A6h (33958d)  size: 1
//    char pad_33959[521]; // offset: 84A7h (33959d) size: 521
//    bool contextOptionSelected; // offset: 86B0h (34480d)  size: 1
//    char pad_34481[15]; // offset: 86B1h (34481d) size: 15
//    int hudFlagsBeforeDemon; // offset: 86C0h (34496d)  size: 4
//    char pad_34500[60364]; // offset: 86C4h (34500d) size: 60364
//    idPlayerDashboard dashboard; // offset: 17290h (94864d)  size: 64024
//    char pad_158888[132648]; // offset: 26CA8h (158888d) size: 132648
//    idHUD playerHud; // offset: 472D0h (291536d)  size: 1008
//    char pad_End[23704]; // offset: 476C0h (292544d) size: 23704
//}; // size: 316248


struct idHands_idHandsAction {
    //Offset 0x0 	Size 0x4 (4)	 action to perform
    idHands_handsAction_t action;
    //Offset 0x8 	Size 0x20 (32)	 weapon associated with action
    idManagedClassPtr_idWeapon weapon;
    //Offset 0x28 	Size 0x1 (1)	 specifically request the intro bringup?
    bool useIntroBringup;
    //Offset 0x30 	Size 0x8 (8)	 throwable item associated with action
    void* idDeclThrowable_throwable;
    //Offset 0x38 	Size 0x4 (4)	 custom anim to play
    idHandsCustomAnimSelect customAnim;
    //Offset 0x3C 	Size 0x4 (4)	 custom weapon anim to play
    idHandsCustomWeaponAnimSelect customWeaponAnim;
    //Offset 0x40 	Size 0x4 (4)	 chainsaw failed gk anims
    idHandsFailedChainsawSelect chainFailedAnim;
    //Offset 0x48 	Size 0x8 (8)	 time stamp when the action was queued
    long long timestamp;
}; // Size: 0x50 (Size Dec: 80)



struct idPlayerBodyReactions {
    char pad0[8];
    //Offset 0x8 	Size 0x1 (1)	 enable or disable the entire system
    bool enable;
    //Offset 0x10 	Size 0x8 (8)
    idPlayer* owner;
    //Offset 0x18 	Size 0x8 (8)	 the reaction that is currently playing
    idPlayerBodyReaction_t* curReaction;
    //Offset 0x20 	Size 0x8 (8)	 the reaction state that is currently playing
    idPlayerBodyReactionState_t* curReactionState;
    //Offset 0x28 	Size 0x8 (8)	 the time the current reaction started
    long long curReactionStartTime;
    //Offset 0x30 	Size 0x8 (8)	 the time the current reaction state started
   long long curReactionStateStartTime;
    //Offset 0x38 	Size 0x4 (4)
    int inhibitFlagsSave;
    //Offset 0x3C 	Size 0x1 (1)
    bool deferredBodySave;
    //Offset 0x3D 	Size 0x1 (1)	 tracks whether the current reaction is a test reaction
    bool isTestReaction;
    //Offset 0x40 	Size 0xC (12)	 store the view origin for collision testing {{ units = m }}
    idVec3 viewOrigin;
    //Offset 0x4C 	Size 0x1 (1)	 tracks whether this mechanic hid the FP hands so it knows to unhide them
    bool hidFPHands;
    //Offset 0x50 	Size 0xC (12)	 save the start pos so that we can do a clipped trace to the endpos to be sure to end in a valid place {{ units = m }}
    idVec3 startPos;
}; // Size: 0x60 (Size Dec: 96)





// Inheritance: idClass: idEventArgUser
struct idGUIComponent {
	char pad0[0x10];
	//Offset 0x10 	Size 0x8 (8)	 Which SWF file to use.
	void* swfFile; // idDeclSWF* swfFile;
	//Offset 0x18 	Size 0x4 (4)	 Scale of the GUI.
	float scale;
	//Offset 0x1C 	Size 0x24 (36)	 The axis the gui is set on.
	idMat3 axis;
	//Offset 0x40 	Size 0x4 (4)	 How far away the gui is visible. {{ units = m }}
	float showDistance;
	//Offset 0x48 	Size 0x18 (24)	 commands that execute after initialization.
	idList initialCommands; // idList < guiComponentCommand_t, TAG_IDLIST, false > initialCommands;
	//Offset 0x60 	Size 0xC (12)	 scale the clip model of the gui by this amount.
	idVec3 clipScale;
	//Offset 0x70 	Size 0x30 (48)	 What tag to attach this to.
	idStr tagName;
	//Offset 0xA0 	Size 0xC (12)	 offset of the position ( if no Tag, off origin ) {{ units = m }}
	idVec3 positionOffset;
	//Offset 0xAC 	Size 0x4 (4)	 if non 0, scale based on distance to this gui.
	float minDistanceScale;
	//Offset 0xB0 	Size 0x4 (4)	 if non 0, scale based on distance to this gui.
	float maxDistanceScale;
	//Offset 0xB4 	Size 0x4 (4)	 Some lighting thing billy made Jeff put in.
	float uiMultiplier;
	//Offset 0xB8 	Size 0x1 (1)	 Dont show the active screen when changing next screen.
	bool noShowActiveOnNextScreen;
	//Offset 0xB9 	Size 0x1 (1)	 billboard the gui.
	bool billboard;
	//Offset 0xC0 	Size 0x78 (120)
	idSWF_GameObject swfObject;
	//Offset 0x138 	Size 0x18 (24)
	idList pendingCommands; //idList < guiComponentCommand_t, TAG_IDLIST, false > pendingCommands;
	//Offset 0x150 	Size 0x18 (24)
	idList processedCommands;  //idList < guiComponentCommand_t, TAG_IDLIST, false > processedCommands;
	//Offset 0x168 	Size 0x20 (32)
	idManagedClassPtr_idEntity owningEntity; // idManagedClassPtr < idEntity > owningEntity;
	//Offset 0x188 	Size 0x20 (32)
	tagData_t tagData;
	//Offset 0x1A8 	Size 0x4 (4)
	int initialCommandsRan;
}; // Size: 0x1B0 (Size Dec: 432)





// Inheritance: idDeclTypeInfo: idDecl: idResource
struct idDeclUIColor {
	char pad0[136];
	//Offset 0x88 	Size 0x4 (4)	 The display name of this color profile.
	idStrId displayName;
	//Offset 0x8C 	Size 0x1 (1)	 Whether or not this color profile is for color blind accessibility
	bool isColorBlindProfile;
	//Offset 0x90 	Size 0x14 (20)	 The color the hud draws in
	idDeclUIColor_uiColorDef_t hudBase;
	//Offset 0xA4 	Size 0x14 (20)	 The shadow color for the hud
	idDeclUIColor_uiColorDef_t hudShadow;
	//Offset 0xB8 	Size 0x14 (20)	 The text color for the hud
	idDeclUIColor_uiColorDef_t hudText;
	//Offset 0xCC 	Size 0x14 (20)	 The text header color for the hud
	idDeclUIColor_uiColorDef_t hudHeader;
	//Offset 0xE0 	Size 0x14 (20)	 The base color for dash fills and the icon
	idDeclUIColor_uiColorDef_t dashBase;
	//Offset 0xF4 	Size 0x14 (20)	 The glow color for dash for the fill bar
	idDeclUIColor_uiColorDef_t dashGlow;
	//Offset 0x108 	Size 0x14 (20)	 The color used for "ghost" images in notifications
	idDeclUIColor_uiColorDef_t notificationGhost;
	//Offset 0x11C 	Size 0x14 (20)	 The color used across the UI for health
	idDeclUIColor_uiColorDef_t uiHealth;
	//Offset 0x130 	Size 0x14 (20)	 The color used across the UI for health gradients
	idDeclUIColor_uiColorDef_t uiHealthGradient;
	//Offset 0x144 	Size 0x14 (20)	 The color used across the UI for low health
	idDeclUIColor_uiColorDef_t uiHealthLow;
	//Offset 0x158 	Size 0x14 (20)	 The color used across the UI for REALLY low health
	idDeclUIColor_uiColorDef_t uiHealthReallyLow;
	//Offset 0x16C 	Size 0x14 (20)	 The color used across the UI for demon health
	idDeclUIColor_uiColorDef_t uiHealthDemon;
	//Offset 0x180 	Size 0x14 (20)	 The color used across the UI for armor
	idDeclUIColor_uiColorDef_t uiArmor;
	//Offset 0x194 	Size 0x14 (20)	 The color used across the UI for armor gradients
	idDeclUIColor_uiColorDef_t uiArmorGradient;
	//Offset 0x1A8 	Size 0x14 (20)	 The color used across the UI for radiation
	idDeclUIColor_uiColorDef_t uiRadiation;
	//Offset 0x1BC 	Size 0x14 (20)	 The color used across the UI for radiation gradients
	idDeclUIColor_uiColorDef_t uiRadiationGradient;
	//Offset 0x1D0 	Size 0x14 (20)	 The color used across the UI for oxygen
	idDeclUIColor_uiColorDef_t uiOxygen;
	//Offset 0x1E4 	Size 0x14 (20)	 The color used across the UI for oxygen gradients
	idDeclUIColor_uiColorDef_t uiOxygenGradient;
	//Offset 0x1F8 	Size 0x14 (20)	 The color used across the UI for urgent warnings and alerts
	idDeclUIColor_uiColorDef_t uiWarning;
	//Offset 0x20C 	Size 0x14 (20)	 The color used across the UI for successful actions
	idDeclUIColor_uiColorDef_t uiSuccess;
	//Offset 0x220 	Size 0x14 (20)	 The color used across the UI for failed actions
	idDeclUIColor_uiColorDef_t uiFailure;
	//Offset 0x234 	Size 0x14 (20)	 The color used across the UI for cautions
	idDeclUIColor_uiColorDef_t uiCaution;
	//Offset 0x248 	Size 0x14 (20)	 The color used across the UI for the fill color in progress bars
	idDeclUIColor_uiColorDef_t uiProgressBarFill;
	//Offset 0x25C 	Size 0x14 (20)	 The color used across the UI for progress complete (bars, text, etc.)
	idDeclUIColor_uiColorDef_t uiProgressComplete;
	//Offset 0x270 	Size 0x14 (20)	 The color used for health background of demon players
	idDeclUIColor_uiColorDef_t uiHealthDemonBackground;
	//Offset 0x284 	Size 0x14 (20)	 The color used for health background of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonBackgroundLow;
	//Offset 0x298 	Size 0x14 (20)	 The color used for health background of demon players when health is really low
	idDeclUIColor_uiColorDef_t uiHealthDemonBackgroundReallyLow;
	//Offset 0x2AC 	Size 0x14 (20)	 The color used for health background of demon players when dead
	idDeclUIColor_uiColorDef_t uiHealthDemonBackgroundDead;
	//Offset 0x2C0 	Size 0x14 (20)	 The color used for health background glow of demon players
	idDeclUIColor_uiColorDef_t uiHealthDemonBackgroundGlow;
	//Offset 0x2D4 	Size 0x14 (20)	 The color used for health background glow of demon players when health is really low
	idDeclUIColor_uiColorDef_t uiHealthDemonBackgroundGlowReallyLow;
	//Offset 0x2E8 	Size 0x14 (20)	 The color used for health background glow of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonBackgroundGlowLow;
	//Offset 0x2FC 	Size 0x14 (20)	 The color used for health bar pip of green demon players when health is full
	idDeclUIColor_uiColorDef_t uiHealthDemonPipGreen;
	//Offset 0x310 	Size 0x14 (20)	 The color used for health bar pip gradient of green demon players when health is full
	idDeclUIColor_uiColorDef_t uiHealthDemonPipGreenGradient;
	//Offset 0x324 	Size 0x14 (20)	 The color used for health bar pip of orange demon players when health is full
	idDeclUIColor_uiColorDef_t uiHealthDemonPipOrange;
	//Offset 0x338 	Size 0x14 (20)	 The color used for health bar pip gradient of orange demon players when health is full
	idDeclUIColor_uiColorDef_t uiHealthDemonPipOrangeGradient;
	//Offset 0x34C 	Size 0x14 (20)	 The color used for health bar pip of blue demon players when health is full
	idDeclUIColor_uiColorDef_t uiHealthDemonPipBlue;
	//Offset 0x360 	Size 0x14 (20)	 The color used for health bar pip gradient of blue demon players when health is full
	idDeclUIColor_uiColorDef_t uiHealthDemonPipBlueGradient;
	//Offset 0x374 	Size 0x14 (20)	 The color used for health bar pip of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonPipLow;
	//Offset 0x388 	Size 0x14 (20)	 The color used for health bar pip gradient of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonPipLowGradient;
	//Offset 0x39C 	Size 0x14 (20)	 The color used for health bar pip and gradient of demon players when dead
	idDeclUIColor_uiColorDef_t uiHealthDemonPipDead;
	//Offset 0x3B0 	Size 0x14 (20)	 The color used for health bar icon of demon players
	idDeclUIColor_uiColorDef_t uiHealthDemonIcon;
	//Offset 0x3C4 	Size 0x14 (20)	 The color used for health bar icon gradient of demon players
	idDeclUIColor_uiColorDef_t uiHealthDemonIconGradient;
	//Offset 0x3D8 	Size 0x14 (20)	 The color used for health bar icon of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonIconLow;
	//Offset 0x3EC 	Size 0x14 (20)	 The color used for health bar icon gradient of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonIconGradientLow;
	//Offset 0x400 	Size 0x14 (20)	 The color used for health bar icon of demon players when health is really low
	idDeclUIColor_uiColorDef_t uiHealthDemonIconReallyLow;
	//Offset 0x414 	Size 0x14 (20)	 The color used for health bar icon gradient of demon players when health is really low
	idDeclUIColor_uiColorDef_t uiHealthDemonIconGradientReallyLow;
	//Offset 0x428 	Size 0x14 (20)	 The color used for health bar icon of demon players when dead
	idDeclUIColor_uiColorDef_t uiHealthDemonIconDead;
	//Offset 0x43C 	Size 0x14 (20)	 The color used for health bar icon gradient of demon players when dead
	idDeclUIColor_uiColorDef_t uiHealthDemonIconGradientDead;
	//Offset 0x450 	Size 0x14 (20)	 The color used for health bar glow bits of demon players
	idDeclUIColor_uiColorDef_t uiHealthDemonGlowBits;
	//Offset 0x464 	Size 0x14 (20)	 The color used for health bar glow bits of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonGlowBitsLow;
	//Offset 0x478 	Size 0x14 (20)	 The color used for health bar text of demon players
	idDeclUIColor_uiColorDef_t uiHealthDemonText;
	//Offset 0x48C 	Size 0x14 (20)	 The color used for health bar text of demon players when health is low
	idDeclUIColor_uiColorDef_t uiHealthDemonTextLow;
	//Offset 0x4A0 	Size 0x14 (20)	 The color used for unlocked doors in the world
	idDeclUIColor_uiColorDef_t worldUnlocked;
	//Offset 0x4B4 	Size 0x14 (20)	 The color used for locked doors in the world
	idDeclUIColor_uiColorDef_t worldLocked;
	//Offset 0x4C8 	Size 0x14 (20)	 The color of green for slayer ui
	idDeclUIColor_uiColorDef_t slayerGreen;
	//Offset 0x4DC 	Size 0x14 (20)	 The shade of red for demon ui
	idDeclUIColor_uiColorDef_t demonRed;
	//Offset 0x4F0 	Size 0x14 (20)	 The shade of yellow for demon ui
	idDeclUIColor_uiColorDef_t demonYellow;
	//Offset 0x504 	Size 0x14 (20)	 The shade of yellow for demon ui
	idDeclUIColor_uiColorDef_t white;
	//Offset 0x518 	Size 0x14 (20)	 The color representing the chainsaw in UI
	idDeclUIColor_uiColorDef_t weaponChainsaw;
	//Offset 0x52C 	Size 0x14 (20)	 The color representing the combat shotgun in UI
	idDeclUIColor_uiColorDef_t weaponShotgun;
	//Offset 0x540 	Size 0x14 (20)	 The color representing the double barrel shotgun in UI
	idDeclUIColor_uiColorDef_t weaponDoubleBarrel;
	//Offset 0x554 	Size 0x14 (20)	 The color representing the assualt rifle in UI
	idDeclUIColor_uiColorDef_t weaponAssualtRifle;
	//Offset 0x568 	Size 0x14 (20)	 The color representing the chaingun in UI
	idDeclUIColor_uiColorDef_t weaponChaingun;
	//Offset 0x57C 	Size 0x14 (20)	 The color representing the plasma rifle in UI
	idDeclUIColor_uiColorDef_t weaponPlasmaRifle;
	//Offset 0x590 	Size 0x14 (20)	 The color representing the ballista in UI
	idDeclUIColor_uiColorDef_t weaponBallista;
	//Offset 0x5A4 	Size 0x14 (20)	 The color representing the rocket launcher in UI
	idDeclUIColor_uiColorDef_t weaponRocketLauncher;
	//Offset 0x5B8 	Size 0x14 (20)	 The color representing the BFG in UI
	idDeclUIColor_uiColorDef_t weaponBfg;
	//Offset 0x5CC 	Size 0x14 (20)	 The color representing the Unmaykr in UI
	idDeclUIColor_uiColorDef_t weaponUnmaykr;
	//Offset 0x5E0 	Size 0x14 (20)	 The color representing the crucible in UI
	idDeclUIColor_uiColorDef_t weaponCrucible;
	//Offset 0x5F4 	Size 0x14 (20)	 The color representing the hammer in UI
	idDeclUIColor_uiColorDef_t weaponHammer;
	//Offset 0x608 	Size 0x14 (20)	 The color representing the weapons lacking ammo in UI
	idDeclUIColor_uiColorDef_t weaponNoAmmo;
	//Offset 0x61C 	Size 0x14 (20)	 The color representing the disabled weapons in UI
	idDeclUIColor_uiColorDef_t weaponDisabled;
	//Offset 0x630 	Size 0x14 (20)	 The color representing the combat shotgun when full in UI
	idDeclUIColor_uiColorDef_t weaponShotgunFull;
	//Offset 0x644 	Size 0x14 (20)	 The color representing the double barrel shotgun when full in UI
	idDeclUIColor_uiColorDef_t weaponDoubleBarrelFull;
	//Offset 0x658 	Size 0x14 (20)	 The color representing the assualt rifle when full in UI
	idDeclUIColor_uiColorDef_t weaponAssualtRifleFull;
	//Offset 0x66C 	Size 0x14 (20)	 The color representing the chaingun when full in UI
	idDeclUIColor_uiColorDef_t weaponChaingunFull;
	//Offset 0x680 	Size 0x14 (20)	 The color representing the plasma rifle when full in UI
	idDeclUIColor_uiColorDef_t weaponPlasmaRifleFull;
	//Offset 0x694 	Size 0x14 (20)	 The color representing the ballista when full in UI
	idDeclUIColor_uiColorDef_t weaponBallistaFull;
	//Offset 0x6A8 	Size 0x14 (20)	 The color representing the rocket launcher when full in UI
	idDeclUIColor_uiColorDef_t weaponRocketLauncherFull;
	//Offset 0x6BC 	Size 0x14 (20)	 The color representing the BFG when full in UI
	idDeclUIColor_uiColorDef_t weaponBfgFull;
	//Offset 0x6D0 	Size 0x14 (20)	 The color representing the Unmaykr when full in UI
	idDeclUIColor_uiColorDef_t weaponUnmaykrFull;
	//Offset 0x6E4 	Size 0x14 (20)	 The color representing the hammer when full in UI
	idDeclUIColor_uiColorDef_t weaponHammerFull;
	//Offset 0x6F8 	Size 0x14 (20)	 The color representing the reticle base
	idDeclUIColor_uiColorDef_t reticleBase;
	//Offset 0x70C 	Size 0x14 (20)	 The color representing the reticle glow
	idDeclUIColor_uiColorDef_t reticleGlow;
	//Offset 0x720 	Size 0x14 (20)	 The color representing the reticle cooldown base
	idDeclUIColor_uiColorDef_t reticleCooldownBase;
	//Offset 0x734 	Size 0x14 (20)	 The color representing the reticle cooldown glow
	idDeclUIColor_uiColorDef_t reticleCooldownGlow;
	//Offset 0x748 	Size 0x14 (20)	 The color representing the reticle warning base
	idDeclUIColor_uiColorDef_t reticleWarningBase;
	//Offset 0x75C 	Size 0x14 (20)	 The color representing the reticle warning glow
	idDeclUIColor_uiColorDef_t reticleWarningGlow;
	//Offset 0x770 	Size 0x14 (20)	 The color representing the reticle alt stroke (eg. crucible)
	idDeclUIColor_uiColorDef_t reticleAltStroke;
	//Offset 0x784 	Size 0x14 (20)	 The color representing the reticle alt base (eg. crucible)
	idDeclUIColor_uiColorDef_t reticleAltBase;
	//Offset 0x798 	Size 0x14 (20)	 The color representing the reticle alt glow (eg. crucible)
	idDeclUIColor_uiColorDef_t reticleAltGlow;
	//Offset 0x7AC 	Size 0x14 (20)	 The color representing the reticle alt 2 stroke (eg. unmakyr)
	idDeclUIColor_uiColorDef_t reticleAlt2Stroke;
	//Offset 0x7C0 	Size 0x14 (20)	 The color representing the reticle alt 2 base (eg. unmakyr)
	idDeclUIColor_uiColorDef_t reticleAlt2Base;
	//Offset 0x7D4 	Size 0x14 (20)	 The color representing the reticle alt 2 glow (eg. unmakyr)
	idDeclUIColor_uiColorDef_t reticleAlt2Glow;
	//Offset 0x7E8 	Size 0x14 (20)	 The color representing blue keycards
	idDeclUIColor_uiColorDef_t keycardBlue;
	//Offset 0x7FC 	Size 0x14 (20)	 The color representing red keycards
	idDeclUIColor_uiColorDef_t keycardRed;
	//Offset 0x810 	Size 0x14 (20)	 The color representing yellow keycards
	idDeclUIColor_uiColorDef_t keycardYellow;
	//Offset 0x824 	Size 0x14 (20)	 The color representing the slayer key
	idDeclUIColor_uiColorDef_t keycardSlayer;
	//Offset 0x838 	Size 0x14 (20)	 The color used in menus for background bases
	idDeclUIColor_uiColorDef_t menuBackBase;
	//Offset 0x84C 	Size 0x14 (20)	 The color used in menus for background strokes
	idDeclUIColor_uiColorDef_t menuBackStroke;
	//Offset 0x860 	Size 0x14 (20)	 The color used in menus for background bases when selected
	idDeclUIColor_uiColorDef_t menuSelectionBase;
	//Offset 0x874 	Size 0x14 (20)	 The color used in menus for background strokes when selected
	idDeclUIColor_uiColorDef_t menuSelectionStroke;
	//Offset 0x888 	Size 0x14 (20)	 The color used in menus for background bases when pressed
	idDeclUIColor_uiColorDef_t menuBackPress;
	//Offset 0x89C 	Size 0x14 (20)	 The color used in menus for header text
	idDeclUIColor_uiColorDef_t menuHeaderText;
	//Offset 0x8B0 	Size 0x14 (20)	 The color used in menus for items that have been collected
	idDeclUIColor_uiColorDef_t collectedItem;
	//Offset 0x8C4 	Size 0x14 (20)	 The color used for the corruption meter hex background cleared element
	idDeclUIColor_uiColorDef_t corruptionHexCleared;
	//Offset 0x8D8 	Size 0x14 (20)	 The color used for the corruption meter hex glow background cleared element
	idDeclUIColor_uiColorDef_t corruptionHexGlowCleared;
	//Offset 0x8EC 	Size 0x14 (20)	 The color used for the corruption meter hex background corrupt element
	idDeclUIColor_uiColorDef_t corruptionHexCorrupt;
	//Offset 0x900 	Size 0x14 (20)	 The color used for the corruption meter hex glow background corrupt element
	idDeclUIColor_uiColorDef_t corruptionHexGlowCorrupt;
	//Offset 0x914 	Size 0x14 (20)	 The color used for the corruption meter container cleared element
	idDeclUIColor_uiColorDef_t corruptionContainerCleared;
	//Offset 0x928 	Size 0x14 (20)	 The color used for the corruption meter container corrupt element
	idDeclUIColor_uiColorDef_t corruptionContainerCorrupt;
	//Offset 0x93C 	Size 0x14 (20)	 The color used for the corruption cleared indicators
	idDeclUIColor_uiColorDef_t corruptionClear;
	//Offset 0x950 	Size 0x14 (20)	 The color used for the glow of corruption cleared indicators
	idDeclUIColor_uiColorDef_t corruptionClearGlow;
	//Offset 0x964 	Size 0x14 (20)	 The color used for the corruption cleared indicators when partially cleared
	idDeclUIColor_uiColorDef_t corruptionPartialClear;
	//Offset 0x978 	Size 0x14 (20)	 The color used for the glow of corruption cleared indicators when partially cleared
	idDeclUIColor_uiColorDef_t corruptionPartialClearGlow;
	//Offset 0x98C 	Size 0x14 (20)	 The color used for the combat encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionCombat;
	//Offset 0x9A0 	Size 0x14 (20)	 The color used for the glow of combat encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionCombatGlow;
	//Offset 0x9B4 	Size 0x14 (20)	 The color used for the slayer gate corruption indicators
	idDeclUIColor_uiColorDef_t corruptionSlayerGate;
	//Offset 0x9C8 	Size 0x14 (20)	 The color used for the glow of slayer gate corruption indicators
	idDeclUIColor_uiColorDef_t corruptionSlayerGateGlow;
	//Offset 0x9DC 	Size 0x14 (20)	 The color used for the secret encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionSecret;
	//Offset 0x9F0 	Size 0x14 (20)	 The color used for the glow of secret encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionSecretGlow;
	//Offset 0xA04 	Size 0x14 (20)	 The color used for the boss encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionBoss;
	//Offset 0xA18 	Size 0x14 (20)	 The color used for the glow of boss encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionBossGlow;
	//Offset 0xA2C 	Size 0x14 (20)	 The color used for the default corruption indicators
	idDeclUIColor_uiColorDef_t corruptionBase;
	//Offset 0xA40 	Size 0x14 (20)	 The color used for the default corruption overlays
	idDeclUIColor_uiColorDef_t corruptionOverlay;
	//Offset 0xA54 	Size 0x14 (20)	 The color used for the escalation encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionEscalation;
	//Offset 0xA68 	Size 0x14 (20)	 The color used for the glow of escalation encounter corruption indicators
	idDeclUIColor_uiColorDef_t corruptionEscalationGlow;
	//Offset 0xA7C 	Size 0x14 (20)	 The color used for the extra life icon
	idDeclUIColor_uiColorDef_t extraLifeIcon;
	//Offset 0xA90 	Size 0x14 (20)	 The color used for the extra life icon glow
	idDeclUIColor_uiColorDef_t extraLifeIconGlow;
	//Offset 0xAA4 	Size 0x14 (20)	 The color used for the extra life refund timer
	idDeclUIColor_uiColorDef_t extraLifeTimer;
	//Offset 0xAB8 	Size 0x14 (20)	 The color used for the extra life refund timer glow
	idDeclUIColor_uiColorDef_t extraLifeTimerGlow;
	//Offset 0xACC 	Size 0x14 (20)	 The color used for the argent cell menu
	idDeclUIColor_uiColorDef_t argentCell;
	//Offset 0xAE0 	Size 0x14 (20)	 The color used for weapon point earned notifications
	idDeclUIColor_uiColorDef_t weaponPoint;
	//Offset 0xAF4 	Size 0x14 (20)	 The color used for praetor point earned notifications
	idDeclUIColor_uiColorDef_t praetorPoint;
	//Offset 0xB08 	Size 0x14 (20)	 The color used for sentinel battery earned notifications
	idDeclUIColor_uiColorDef_t sentinelBattery;
	//Offset 0xB1C 	Size 0x14 (20)	 The color used for the demon hud's backers
	idDeclUIColor_uiColorDef_t demonHudBacker;
	//Offset 0xB30 	Size 0x14 (20)	 The color used for the demon ability hud selection elements glow
	idDeclUIColor_uiColorDef_t demonHudAbilitiesSelectionGlow;
	//Offset 0xB44 	Size 0x14 (20)	 The color used for the demon ability hud selection elements stroke
	idDeclUIColor_uiColorDef_t demonHudAbilitiesSelectionStroke;
	//Offset 0xB58 	Size 0x14 (20)	 The color used for the demon ability hud frame
	idDeclUIColor_uiColorDef_t demonHudAbilityFrame;
	//Offset 0xB6C 	Size 0x14 (20)	 The color used for the demon ability hud glow that appears under the frame when unselected
	idDeclUIColor_uiColorDef_t demonHudAbilityFrameGlowUnselected;
	//Offset 0xB80 	Size 0x14 (20)	 The color used for the demon ability hud glow that appears under the frame when selected
	idDeclUIColor_uiColorDef_t demonHudAbilityFrameGlowSelected;
	//Offset 0xB94 	Size 0x14 (20)	 The color used for the demon cards that need a teal color base
	idDeclUIColor_uiColorDef_t demonHudTealBase;
	//Offset 0xBA8 	Size 0x14 (20)	 The color used for the demon cards that need a teal color gradient
	idDeclUIColor_uiColorDef_t demonHudTealGradient;
	//Offset 0xBBC 	Size 0x14 (20)	 The color used for the demon cards that need a teal color overlay
	idDeclUIColor_uiColorDef_t demonHudTealOverlay;
	//Offset 0xBD0 	Size 0x14 (20)	 The color used for the demon cards that need a teal color icon
	idDeclUIColor_uiColorDef_t demonHudTealIcon;
	//Offset 0xBE4 	Size 0x14 (20)	 The color used for the demon cards that need a yellow color base
	idDeclUIColor_uiColorDef_t demonHudYellowBase;
	//Offset 0xBF8 	Size 0x14 (20)	 The color used for the demon cards that need a yellow color gradient
	idDeclUIColor_uiColorDef_t demonHudYellowGradient;
	//Offset 0xC0C 	Size 0x14 (20)	 The color used for the demon cards that need a yellow color overlay
	idDeclUIColor_uiColorDef_t demonHudYellowOverlay;
	//Offset 0xC20 	Size 0x14 (20)	 The color used for the demon cards that need a yellow color icon
	idDeclUIColor_uiColorDef_t demonHudYellowIcon;
	//Offset 0xC34 	Size 0x14 (20)	 The color used for the demon cards that need a orange color base
	idDeclUIColor_uiColorDef_t demonHudOrangeBase;
	//Offset 0xC48 	Size 0x14 (20)	 The color used for the demon cards that need a orange color gradient
	idDeclUIColor_uiColorDef_t demonHudOrangeGradient;
	//Offset 0xC5C 	Size 0x14 (20)	 The color used for the demon cards that need a orange color overlay
	idDeclUIColor_uiColorDef_t demonHudOrangeOverlay;
	//Offset 0xC70 	Size 0x14 (20)	 The color used for the demon cards that need a orange color icon
	idDeclUIColor_uiColorDef_t demonHudOrangeIcon;
	//Offset 0xC84 	Size 0x14 (20)	 The color used for the demon cards that need a blue color base
	idDeclUIColor_uiColorDef_t demonHudBlueBase;
	//Offset 0xC98 	Size 0x14 (20)	 The color used for the demon cards that need a blue color gradient
	idDeclUIColor_uiColorDef_t demonHudBlueGradient;
	//Offset 0xCAC 	Size 0x14 (20)	 The color used for the demon cards that need a blue color overlay
	idDeclUIColor_uiColorDef_t demonHudBlueOverlay;
	//Offset 0xCC0 	Size 0x14 (20)	 The color used for the demon cards that need a blue color icon
	idDeclUIColor_uiColorDef_t demonHudBlueIcon;
	//Offset 0xCD4 	Size 0x14 (20)	 The color used for the demon cards that need a purple color base
	idDeclUIColor_uiColorDef_t demonHudPurpleBase;
	//Offset 0xCE8 	Size 0x14 (20)	 The color used for the demon cards that need a purple color gradient
	idDeclUIColor_uiColorDef_t demonHudPurpleGradient;
	//Offset 0xCFC 	Size 0x14 (20)	 The color used for the demon cards that need a purple color overlay
	idDeclUIColor_uiColorDef_t demonHudPurpleOverlay;
	//Offset 0xD10 	Size 0x14 (20)	 The color used for the demon cards that need a purple color icon
	idDeclUIColor_uiColorDef_t demonHudPurpleIcon;
	//Offset 0xD24 	Size 0x14 (20)	 The color used for the demon cards that need a red color base
	idDeclUIColor_uiColorDef_t demonHudRedBase;
	//Offset 0xD38 	Size 0x14 (20)	 The color used for the demon cards that need a red color gradient
	idDeclUIColor_uiColorDef_t demonHudRedGradient;
	//Offset 0xD4C 	Size 0x14 (20)	 The color used for the demon cards that need a red color overlay
	idDeclUIColor_uiColorDef_t demonHudRedOverlay;
	//Offset 0xD60 	Size 0x14 (20)	 The color used for the demon cards that need a red color icon
	idDeclUIColor_uiColorDef_t demonHudRedIcon;
	//Offset 0xD74 	Size 0x14 (20)	 The color used for the demon cards that need a green color base
	idDeclUIColor_uiColorDef_t demonHudGreenBase;
	//Offset 0xD88 	Size 0x14 (20)	 The color used for the demon cards that need a green color gradient
	idDeclUIColor_uiColorDef_t demonHudGreenGradient;
	//Offset 0xD9C 	Size 0x14 (20)	 The color used for the demon cards that need a green color overlay
	idDeclUIColor_uiColorDef_t demonHudGreenOverlay;
	//Offset 0xDB0 	Size 0x14 (20)	 The color used for the demon cards that need a green color icon
	idDeclUIColor_uiColorDef_t demonHudGreenIcon;
	//Offset 0xDC4 	Size 0x14 (20)	 The color used for the demon card icons that are on cooldown
	idDeclUIColor_uiColorDef_t demonHudIconCooldown;
	//Offset 0xDD8 	Size 0x14 (20)	 The color used for the demon card base that are on cooldown
	idDeclUIColor_uiColorDef_t demonHudBaseCooldown;
	//Offset 0xDEC 	Size 0x14 (20)	 The color used for the demon card gradient that are on cooldown
	idDeclUIColor_uiColorDef_t demonHudGradientCooldown;
	//Offset 0xE00 	Size 0x14 (20)	 The color used for the demon card overlay that are on cooldown
	idDeclUIColor_uiColorDef_t demonHudOverlayCooldown;
	//Offset 0xE14 	Size 0x14 (20)	 The color used for the cover of a demon card on cooldown
	idDeclUIColor_uiColorDef_t demonHudAbilityCooldownCover;
	//Offset 0xE28 	Size 0x14 (20)	 The color used for the gamepad summons wheel stroke lines
	idDeclUIColor_uiColorDef_t demonHudWheelStroke;
	//Offset 0xE3C 	Size 0x14 (20)	 The color used for the gamepad summons wheel base
	idDeclUIColor_uiColorDef_t demonHudWheelBase;
	//Offset 0xE50 	Size 0x14 (20)	 The color used for the gamepad summons wheel glow
	idDeclUIColor_uiColorDef_t demonHudWheelGlow;
	//Offset 0xE64 	Size 0x14 (20)	 The base color for demon hud notifications
	idDeclUIColor_uiColorDef_t demonHudNotificationBase;
	//Offset 0xE78 	Size 0x14 (20)	 The icon color for demon hud notifications
	idDeclUIColor_uiColorDef_t demonHudNotificationIcon;
	//Offset 0xE8C 	Size 0x14 (20)	 The stroke color for demon hud notifications
	idDeclUIColor_uiColorDef_t demonHudNotificationStroke;
	//Offset 0xEA0 	Size 0x14 (20)	 The header color for demon hud notifications
	idDeclUIColor_uiColorDef_t demonHudNotificationHeader;
	//Offset 0xEB4 	Size 0x14 (20)	 The text color for demon hud notifications
	idDeclUIColor_uiColorDef_t demonHudNotificationText;
	//Offset 0xEC8 	Size 0x14 (20)	 The glow color for demon hud notifications
	idDeclUIColor_uiColorDef_t demonHudNotificationGlow;
	//Offset 0xEDC 	Size 0x14 (20)	 The color used for the frame of the player widget in the HUD's header when the player is a demon
	idDeclUIColor_uiColorDef_t demonHudDemonPlayerFrame;
	//Offset 0xEF0 	Size 0x14 (20)	 The color used for the frame of the player widget in the HUD's header when the player is the slayer
	idDeclUIColor_uiColorDef_t demonHudSlayerPlayerFrame;
	//Offset 0xF04 	Size 0x14 (20)	 The color used for the back-glow of the frame of the player widget in the HUD's header when the player is a demon
	idDeclUIColor_uiColorDef_t demonHudDemonPlayerFrameBackglow;
	//Offset 0xF18 	Size 0x14 (20)	 The color used for the back-glow of the frame of the player widget in the HUD's header when the player is the slayer
	idDeclUIColor_uiColorDef_t demonHudSlayerPlayerFrameBackglow;
	//Offset 0xF2C 	Size 0x14 (20)	 The color used for common text in the HUD's header (player list and match summary)
	idDeclUIColor_uiColorDef_t demonHudHeaderText;
	//Offset 0xF40 	Size 0x14 (20)	 The color used for number text in the HUD's match summary
	idDeclUIColor_uiColorDef_t demonHudHeaderTextNumbers;
	//Offset 0xF54 	Size 0x14 (20)	 The color used for the match summary's frame elements
	idDeclUIColor_uiColorDef_t demonHudMatchSummaryFrame;
	//Offset 0xF68 	Size 0x14 (20)	 The color used for the match summary's background elements
	idDeclUIColor_uiColorDef_t demonHudMatchSummaryBacking;
	//Offset 0xF7C 	Size 0x14 (20)	 The color used for player's status list backglow
	idDeclUIColor_uiColorDef_t hudStatusBuffBackglow;
	//Offset 0xF90 	Size 0x14 (20)	 The color used for player's status list backer
	idDeclUIColor_uiColorDef_t hudStatusBuffBacker;
	//Offset 0xFA4 	Size 0x14 (20)	 Seaons Menu - Default element color
	idDeclUIColor_uiColorDef_t menuSeasonBase;
	//Offset 0xFB8 	Size 0x14 (20)	 Cosmetic Items - Default Rarity
	idDeclUIColor_uiColorDef_t cosmeticRarityDefault;
	//Offset 0xFCC 	Size 0x14 (20)	 Cosmetic Items - Tier 1 Rarity
	idDeclUIColor_uiColorDef_t cosmeticRarityTier1;
	//Offset 0xFE0 	Size 0x14 (20)	 Cosmetic Items - Tier 2 Rarity
	idDeclUIColor_uiColorDef_t cosmeticRarityTier2;
	//Offset 0xFF4 	Size 0x14 (20)	 Cosmetic Items - Tier 3 Rarity
	idDeclUIColor_uiColorDef_t cosmeticRarityTier3;
	//Offset 0x1008 	Size 0x14 (20)	 pvp notifications ticker item stroke color
	idDeclUIColor_uiColorDef_t pvpTickerStroke;
	//Offset 0x101C 	Size 0x14 (20)	 pvp notifications ticker item backer color
	idDeclUIColor_uiColorDef_t pvpTickerBacker;
	//Offset 0x1030 	Size 0x14 (20)	 pvp notifications ticker item color when slayer player is the actor of the notification
	idDeclUIColor_uiColorDef_t pvpTickerSlayer;
	//Offset 0x1044 	Size 0x14 (20)	 base color for all demon reticles
	idDeclUIColor_uiColorDef_t demonReticle;
	//Offset 0x1058 	Size 0x14 (20)	 glow color for the revenant reticle
	idDeclUIColor_uiColorDef_t revenantReticleGlow;
	//Offset 0x106C 	Size 0x14 (20)	 gradient color for the revenant reticle
	idDeclUIColor_uiColorDef_t revenantReticleGradient;
	//Offset 0x1080 	Size 0x14 (20)	 base color for the revenant reticle
	idDeclUIColor_uiColorDef_t revenantReticleBase;
	//Offset 0x1094 	Size 0x14 (20)	 glow color for the archvile reticle
	idDeclUIColor_uiColorDef_t archvileReticleGlow;
	//Offset 0x10A8 	Size 0x14 (20)	 gradient color for the archvile reticle
	idDeclUIColor_uiColorDef_t archvileReticleGradient;
	//Offset 0x10BC 	Size 0x14 (20)	 base color for the archvile reticle
	idDeclUIColor_uiColorDef_t archvileReticleBase;
	//Offset 0x10D0 	Size 0x14 (20)	 glow color for the painElemental reticle
	idDeclUIColor_uiColorDef_t painElementalReticleGlow;
	//Offset 0x10E4 	Size 0x14 (20)	 gradient color for the painElemental reticle
	idDeclUIColor_uiColorDef_t painElementalReticleGradient;
	//Offset 0x10F8 	Size 0x14 (20)	 base color for the painElemental reticle
	idDeclUIColor_uiColorDef_t painElementalReticleBase;
	//Offset 0x110C 	Size 0x14 (20)	 gradient color for the painElemental reticle in low shields
	idDeclUIColor_uiColorDef_t painElementalReticleWarningGradient;
	//Offset 0x1120 	Size 0x14 (20)	 base color for the painElemental reticle in low shields
	idDeclUIColor_uiColorDef_t painElementalReticleWarningBase;
	//Offset 0x1134 	Size 0x14 (20)	 base color for a completed milestone
	idDeclUIColor_uiColorDef_t milestoneCompleteBase;
	//Offset 0x1148 	Size 0x14 (20)	 gradient color for a completed milestone
	idDeclUIColor_uiColorDef_t milestoneCompleteGradient;
	//Offset 0x115C 	Size 0x14 (20)	 icon color for a completed milestone
	idDeclUIColor_uiColorDef_t milestoneCompleteIcon;
	//Offset 0x1170 	Size 0x14 (20)	 text color for a completed milestone
	idDeclUIColor_uiColorDef_t milestoneCompleteText;
	//Offset 0x1184 	Size 0x14 (20)	 base color for a completed milestone
	idDeclUIColor_uiColorDef_t progressionItemCompleteBase;
	//Offset 0x1198 	Size 0x14 (20)	 base color for the sentinel armor hud
	idDeclUIColor_uiColorDef_t sentinelArmorStroke;
	//Offset 0x11AC 	Size 0x14 (20)	 glow color for the sentinel armor hud
	idDeclUIColor_uiColorDef_t sentinelArmorGlow;
	//Offset 0x11C0 	Size 0x14 (20)	 the color definition for the screen damage hud effect
	idDeclUIColor_uiColorDef_t screenDamage;
	//Offset 0x11D4 	Size 0x14 (20)	 frag grenade hud color
	idDeclUIColor_uiColorDef_t hudEquipmentFrag;
	//Offset 0x11E8 	Size 0x14 (20)	 frag grenade Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentFragIcon;
	//Offset 0x11FC 	Size 0x14 (20)	 cyro grenade hud color
	idDeclUIColor_uiColorDef_t hudEquipmentCyro;
	//Offset 0x1210 	Size 0x14 (20)	 cyro grenade Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentCyroIcon;
	//Offset 0x1224 	Size 0x14 (20)	 chainsaw hud color
	idDeclUIColor_uiColorDef_t hudEquipmentChainsaw;
	//Offset 0x1238 	Size 0x14 (20)	 chainsaw Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentChainsawIcon;
	//Offset 0x124C 	Size 0x14 (20)	 flame belch hud color
	idDeclUIColor_uiColorDef_t hudEquipmentFlameBelch;
	//Offset 0x1260 	Size 0x14 (20)	 flame belch Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentFlameBelchIcon;
	//Offset 0x1274 	Size 0x14 (20)	 crucible hud color
	idDeclUIColor_uiColorDef_t hudEquipmentCrucible;
	//Offset 0x1288 	Size 0x14 (20)	 crucible Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentCrucibleIcon;
	//Offset 0x129C 	Size 0x14 (20)	 hammer hud color
	idDeclUIColor_uiColorDef_t hudEquipmentHammer;
	//Offset 0x12B0 	Size 0x14 (20)	 hammer Icon hud color
	idDeclUIColor_uiColorDef_t hudEquipmentHammerIcon;
	//Offset 0x12C4 	Size 0x14 (20)	 hammer Icon hud color when supercharged
	idDeclUIColor_uiColorDef_t hudEquipmentHammerSupercharge;
	//Offset 0x12D8 	Size 0x14 (20)	 hammer gradient hud color
	idDeclUIColor_uiColorDef_t hudEquipmentHammerGradient;
	//Offset 0x12EC 	Size 0x14 (20)	 boss health color
	idDeclUIColor_uiColorDef_t hudBossHealthBase;
	//Offset 0x1300 	Size 0x14 (20)	 boss health gradient color
	idDeclUIColor_uiColorDef_t hudBossHealthGradient;
	//Offset 0x1314 	Size 0x14 (20)	 boss shield color
	idDeclUIColor_uiColorDef_t hudBossShieldBase;
	//Offset 0x1328 	Size 0x14 (20)	 boss shield glow color
	idDeclUIColor_uiColorDef_t hudBossShieldGlow;
	//Offset 0x133C 	Size 0x14 (20)	 boss Stuff
	idDeclUIColor_uiColorDef_t hudBossKhanMykerBarBorder;
	//Offset 0x1350 	Size 0x14 (20)	 boss Stuff
	idDeclUIColor_uiColorDef_t hudBossKhanMykerBarGradient;
	//Offset 0x1364 	Size 0x14 (20)	 boss Stuff
	idDeclUIColor_uiColorDef_t hudBossKhanMykerBarBase;
	//Offset 0x1378 	Size 0x14 (20)	 boss Stuff
	idDeclUIColor_uiColorDef_t hudBossDemonLordMortarPOIBase;
	//Offset 0x138C 	Size 0x14 (20)	 boss Stuff
	idDeclUIColor_uiColorDef_t hudBossDemonLordMortarPOIArrow;
	//Offset 0x13A0 	Size 0x14 (20)	 door Stuff
	idDeclUIColor_uiColorDef_t doorLockRed;
	//Offset 0x13B4 	Size 0x14 (20)	 door Stuff
	idDeclUIColor_uiColorDef_t doorLockBlue;
	//Offset 0x13C8 	Size 0x14 (20)	 door Stuff
	idDeclUIColor_uiColorDef_t doorLockYellow;
	//Offset 0x13DC 	Size 0x14 (20)	 door Stuff
	idDeclUIColor_uiColorDef_t doorLockGreen;
	//Offset 0x13F0 	Size 0x14 (20)	 invasion red color
	idDeclUIColor_uiColorDef_t invasionRed;
	//Offset 0x1404 	Size 0x14 (20)	 invasion orange color
	idDeclUIColor_uiColorDef_t invasionOrange;
	//Offset 0x1418 	Size 0x14 (20)	 invasion yellow color
	idDeclUIColor_uiColorDef_t invasionYellow;
	//Offset 0x142C 	Size 0x14 (20)	 player badge streak win color
	idDeclUIColor_uiColorDef_t playerBadgeStreakWin;
	//Offset 0x1440 	Size 0x14 (20)	 player badge streak loss color
	idDeclUIColor_uiColorDef_t playerBadgeStreakLoss;
	//Offset 0x1454 	Size 0x14 (20)	 color used for the button of master levels that are locked
	idDeclUIColor_uiColorDef_t masterLevelLocked;
	//Offset 0x1468 	Size 0x14 (20)	 color used for the support rune elements
	idDeclUIColor_uiColorDef_t supportRuneBase;
	//Offset 0x147C 	Size 0x14 (20)	 glow color used for the support rune elements
	idDeclUIColor_uiColorDef_t supportRuneGlow;
	//Offset 0x1490 	Size 0x14 (20)	 The color used in menus for background strokes
	idDeclUIColor_uiColorDef_t supportRuneStroke;
	//Offset 0x14A4 	Size 0x14 (20)	 The color used in menus for background bases when selected
	idDeclUIColor_uiColorDef_t supportRuneSelectionBase;
	//Offset 0x14B8 	Size 0x14 (20)	 color used for supercharged blood punch on HUD
	idDeclUIColor_uiColorDef_t bloodPunchSuperchargeBase;
	//Offset 0x14CC 	Size 0x14 (20)	 glow color used for supercharged blood punch on HUD
	idDeclUIColor_uiColorDef_t bloodPunchSuperchargeGlow;
	//Offset 0x14E0 	Size 0x14 (20)	 glow color used for supercharged blood punch on HUD
	idDeclUIColor_uiColorDef_t cursedProwlerBase;
	//Offset 0x14F4 	Size 0x14 (20)	 glow color used for supercharged blood punch on HUD
	idDeclUIColor_uiColorDef_t cursedProwlerGlow;
	//Offset 0x1508 	Size 0x14 (20)	 color used for onslaught powerup on HUD
	idDeclUIColor_uiColorDef_t powerupOnslaught;
	//Offset 0x151C 	Size 0x14 (20)	 color used for overdrive powerup on HUD
	idDeclUIColor_uiColorDef_t powerupOverdrive;
	//Offset 0x1530 	Size 0x14 (20)	 color used for berserk powerup on HUD
	idDeclUIColor_uiColorDef_t powerupBerserk;
	//Offset 0x1544 	Size 0x14 (20)	 color used for horde progress nodes that have been beaten
	idDeclUIColor_uiColorDef_t hordeProgressSuccess;
	//Offset 0x1558 	Size 0x14 (20)	 color used for the horde progress node that is active
	idDeclUIColor_uiColorDef_t hordeProgressCurrent;
	//Offset 0x156C 	Size 0x14 (20)	 color used for horde progress nodes that have not been beaten
	idDeclUIColor_uiColorDef_t hordeProgressLocked;
	//Offset 0x1580 	Size 0x14 (20)	 color used for horde progress nodes that are bonus
	idDeclUIColor_uiColorDef_t hordeProgressBonus;
}; // Size: 0x1598 (Size Dec: 5528)


//#pragma pack(pop) // Restore default packing alignment

