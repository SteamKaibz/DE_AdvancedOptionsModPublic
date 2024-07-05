#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include "../Loguru/loguru.hpp"
#include "../Config/Config.h"
#include <vector>
#include "../ImGui/dependencies/imgui/imgui.h"
#include "GeneratedEnums.h"


//#include <string>
//class Common
//{
//};

//bool isWeaponIndexWarning(int weaponIndex);

//! General:
static const int intMinusOne = -1;


//! Exe

static const std::string doomEternalExeName = "DOOMEternalx64vk.exe";
static const std::string doomEternalExeNameToLower = "doometernalx64vk.exe";



//! Offsets (8/9/23: we still need to use this cause it's very hard to find certain values only with scan pattern, at least at the moment cause we don't understand how meathook mod works well enough, but later we could find a way to only use advanced scanning and some of the game functions like written in our log (libre office) for this day)

//! to find languageStrOffset set the game to french for example and in CE search for french string you will about 2000 results but only 3 should be static offset to doom exe, the higher address one should be the one you want. Good thing is that it doesn't require IDA to be found.
//static const uintptr_t  languageStrOffset = 0x5170248;


//! to find idStringListBaseOffset, (also documented in libreoffice file) search the idb for %s - unable to allocate new index for keyBindingInfo At this point you will have to compare with previous db where that number is and identify where it is, there is also i screenshot i made you can use, hopefully that will be enough.
//!? could we actually get this value with pattern scan as it's hard coded in the func. update we did. we're leaving this here because i think we have a circular depedency issue betwwen Scanner.h and ObjectLocator.h

//static const int  idStringListBaseOffset = 0x6B68570; // old value:  0x6B94670;
//static const uintptr_t  idStringListBaseOffset = 0x6B68570; // old value:  0x6B94670;


//? 8/9/23 this is the offset we used before to find functions and structs
//static const uintptr_t bindInputStrPtrOffset = 0x18;
//static const uintptr_t bindActionStrPtrOffset = 0x48;
//static const uintptr_t Hud_WeaponInfoPtr_idDeclWeaponOffset = 0x100;
//static const uintptr_t currentlyEquippedWeaponDataOffset = 0x34;
//static const uintptr_t idInventoryItemSpacing = 0x20;
//static const uintptr_t idInventoryItemDeclOffset = 0x38;
//static const uintptr_t idInventoryItemDeclIdOffset = 0x34;
//static const uintptr_t idPlayerItemsCountOffset = 0x35E0;
//static const uintptr_t GetPerfMetricsStrOffset = 0x48FE40;
//static const uintptr_t keySerializeEndAddrOffset = 0x4A8D90;
//static const uintptr_t bindListFuncAddrOffset = 0x356150;
//static const uintptr_t currentBindsetFuncAddrOffset = 0x4A8C40;
//static const uintptr_t equipmentFunctionAddrOffset = 0x1585CD0;
//static const uintptr_t idHudWeaponInfoNadeStatusOffset = 0x194;
//static const uintptr_t inMenuDetectionOffset = 0x17CD2C0;
//static const uintptr_t inGameDetectionOffset = 0x16003D0;
//static const uintptr_t idPlayerProfileSerializeOffset = 0x4AF6B0;
//static const uintptr_t idInventoryCollectionGetInventoryItemOffset = 0x1D1D6A0;
//static const uintptr_t idInventoryItempsCountOffset = 0x5C0;
//static const uintptr_t idInventoryFirstItempOffset = 0x8;
//static const uintptr_t BindCopyControllerStrSomethingOffset = 0x1C335A0;
//static const uintptr_t GetPerfMetricsStrOffset = 0x48FE40;
//static const uintptr_t showPerfMetricsStrLineOffset = 0x4930A0;
//static const uintptr_t RenderShapeOffset = 0x4FDD30;
//static const uintptr_t idSWF_Render_CallerOffset = 0x1C09690;
//static const uintptr_t renderSWFOffset = 0x4FCF80;
//static const uintptr_t DrawStretchPic_623070Offset = 0x623070;
//static const uintptr_t DrawStretchPic_498ED0Offset = 0x498ED0;
//static const uintptr_t idPlayerNadeStatusOffset = 0x6F48;
//static const uintptr_t idHUDMenuScreenPauseHandleActionOffset = 0x16003D0;
//static const uintptr_t idSwfCountOffset = 0x38B8B18;
//static const uintptr_t idSWFListOffset =  0x38B8B10;
//static const uintptr_t idDebugHUDLocalOffset = 0x499690;
//static const uintptr_t idRenderModelGui_DrawStringOffset = 0x6239F0;
//static const uintptr_t idResourceSmthOffset = 0x464250;
//static const uintptr_t renderTestMaterialOffset =  0x1AFA8E0;
//static const uintptr_t idPlayerProcessInputOffset = 0x1ABBDD0;
//static const uintptr_t idPLayerSelectWeaponForSelectionGroupOffset = 0x1ADB7A0;
//static const uintptr_t isKeyPressedOffset = 0x1AE54F0;
//static const uintptr_t idGameSystemLocalMinimalGameCleanupOffset = 0xCED020;
//static const uintptr_t idMenu_UpdateOffset = 0x1847CD0;
//static const uintptr_t pBindsStrSetOffset = 0x35CEC0;
//static const uintptr_t setActiveReticleOffset = 0x15773A0;
//static const uintptr_t idBroadcastManager_ReleaseBroadcastEventOffset = 0x4899C0;
//static const uintptr_t convertIdDeclUIColorToidColorTargetOffset = 0x4D5AF0;
//static const uintptr_t setSpriteInstancetOffset = 0x52F750;
//static const uintptr_t showPerfMetricsSmthOffset =  0x48E580;



const bool improvedWeaponSwitchingEnabled = true;
const bool improvedWeaponSwitchingDisabled = false;


const std::string unknownWeaponStr = "unknow weapon name";
const int notMonitoredWeapon = -1;
const int unvalidWeapon = 0;


//const std::wstring sayBindError = L"Bindings missing, DGB mod disabled";
const std::wstring sayWrongGameNameError = L"wrong game file name, mod disabled";
const std::wstring sayHookingError = L"Hooking Error, mod disabled";
const std::wstring sayScanPatternError = L"Pattern Scanning Error, mod disabled";
const std::wstring saySuccesLoadingMod = L"mod levelLoaded";
const std::wstring saySIniFileReLoaded = L"Ini File Reloaded";
const std::wstring sayIniFileParsingError = L"file parsing error, regenerating ini File";
const std::wstring sayIniFileSavingDefault = L"Saving default ini File";
const std::wstring sayConfigExceptionError = L"Config Exception Error";
const std::wstring sayGeneratingTypes = L"Creating Types Files";
//const std::wstring sayGeneratingEnums = L"Generating i.d Enums";

//const std::wstring sayPreviousModVersionXinput1_3FoundError = L"Error: previous version of the mod found, please check the mod log file in the game folder";
const std::wstring sayPreviousModVersionXInput9_1_0FoundError = L"Error: previous version of the mod found, please check the mod log file in the game folder";
const std::wstring sayPreviousModVersionDinput8FoundError = L"Error: previous version of the mod found, please check the mod log file in the game folder";


//static unsigned char FragGrenadeCharArr[] = "Frag Grenade";
//static unsigned char IceGrenadeCharArr[] = "Ice Grenade";

//static std::string EquipmentLauncherStr = "Equipment Launcher";
//static std::string MissionInformationStr = "Mission Information";

//static std::string FragGrenadeStr = "Frag Grenade";
//static std::string IceGrenadeStr = "Ice Grenade";




//const int shotgunWeaponIndex = 1;
//const int assaultRifleWeaponIndex = 2;
//const int plasmaWeaponIndex = 3;
//const int rocketLauncherWeaponIndex = 4;
//const int superShotgunWeaponIndex = 5;
//const int ballistaWeaponIndex = 6;
//const int miniGunWeaponIndex = 7;


//? these are not reliable, they can break if another mod is installed
//const unsigned int unknownItemId = 0;
//const unsigned int shotgunItemId = 7113;
//const unsigned int assaultRiffleItemId = 8562;
//const unsigned int plasmaItemId = 7404;
//const unsigned int superShotgunItemId = 22668;
//const unsigned int rocketLauncherItemId = 7732;
//const unsigned int minigunItemId = 7982;
//const unsigned int balistaItemId = 8300;
//const unsigned int bfgItemId = 20817;
//const unsigned int unmakerItemId = 11052;
//const unsigned int swordItemId = 23691;
//const unsigned int hammerItemId = 10464;
//const unsigned int fragGrenadeItemId = 9843;
//const unsigned int iceGrenadeItemId = 0x276A;


//namespace ConfigData {
//	static int g_
//}


namespace Hashes {
	static std::vector<std::string> PreviousModVersionsHashes = { 
	"606a4a5a2ecaacf5f966d9efbf266260",
	"809025e42bbd7ed9bf196a54ed4b5f41",
	"7e37fd28b4689fcdafbe72e733f6e088",
	"03fad47126553f49e5dcebb42d9670d7",
	"10e520987a04ee27919543c604a1d598",
	"b3d4154f847eecb64f4f03a3ea588d99",
	"ce156454907cf509804010fc5ac72322",
	"17fe2c243bba604f554f7bb69b28c0fe",
	"4407aad8ec9e1415e574866ae0666c8e",
	"1b7fa52a5025191745b5be099626f072"
	};

	static std::string PreviousModsVesionsFileExtension = {
	".dll"
	};

	static std::vector<std::string> MeathookModHashes = {
	"786527af140cb8fea0af7cbc0793fa5a"
	};	

	static std::string MeathookModFileExtension = {
	".dll"
	};

}

namespace ConflictingApps {
	const std::string MsiAfterBurnerProcessName = "MSIAfterburner.exe";
}


//! offset we could not find through typeInfo or otherwise. is game is updated and crashes for unknow reason, recheck  those:
namespace UndocumentedOffsets {

	const int IdPlayer_1_Offset = 0x1AF8;
	const __int64 IdGameTimeManagerLocalOffset = 0x125A60;
	const __int64 CurrentGameModeOffset = 0x6B07DB5;
	const int CvarFindInternalVtbFuncOffset = 0x20;
	const int CmdExecuteFuncAddrOffset = 0x40;
	const int idPlayerPlaySoundVtbOffset = 0x118;
}

namespace WeaponIdStr {
	//! using strings for id is not great but at least i'll be sure:
	static std::string g_shotGunBaseNameIdStr = "weapon/player/shotgun";
	static std::string g_shotGunStickiesNameIdStr = "weapon/player/shotgun_secondary_pop_rockets";
	static std::string g_shotGunFullAutoNameIdStr = "weapon/player/shotgun_secondary_full_auto";
	static std::string g_heavyCannonNameIdStr = "weapon/player/heavy_cannon";
	static std::string g_heavyCannonBoltNameIdStr = "weapon/player/heavy_cannon_bolt_action";
	static std::string g_heavyCannonDetonateNameIdStr = "weapon/player/heavy_cannon_burst_detonate_mastery";
	static std::string g_plasmaNameIdStr = "weapon/player/plasma_rifle";
	static std::string g_plasmaAoeNameIdStr = "weapon/player/plasma_rifle_secondary_aoe";
	static std::string g_plasmaMicroWaveNameIdStr = "weapon/player/plasma_rifle_secondary_microwave";
	static std::string g_rocketLauncherNameIdStr = "weapon/player/rocket_launcher";
	static std::string g_rocketLauncherDetonateNameIdStr = "weapon/player/rocket_launcher_detonate";
	static std::string g_rocketLauncherLockOnNameIdStr = "weapon/player/rocket_launcher_lock_mod_mastery";
	static std::string g_superShotGunOnNameIdStr = "weapon/player/double_barrel";
	static std::string g_superShotGunPrimaryOnNameIdStr = "weapon/player/double_barrel_primary_lockon";
	static std::string g_superShotGunMeathookNameIdStr = "weapon/player/double_barrel_meat_hook";
	static std::string g_balistaNameIdStr = "weapon/player/gauss_rifle";
	static std::string g_balistaArbalesteNameIdStr = "weapon/player/gauss_rifle_ballista";
	static std::string g_balistaDestroyerBladeNameIdStr = "weapon/player/gauss_rifle_destroyer";
	static std::string g_chaingunNameIdStr = "weapon/player/chaingun";
	static std::string g_chaingunShielNameIdStr = "weapon/player/chaingun_energy_shell";
	static std::string g_chaingunShielPrimaryNameIdStr = "weapon/player/chaingun_energy_shell_primary";
	static std::string g_chaingunTurretPrimaryNameIdStr = "weapon/player/chaingun_turret_primary";
	static std::string g_chaingunTurretSecondaryNameIdStr = "weapon/player/chaingun_turret_secondary";
	static std::string g_bfgNameIdStr = "weapon/player/bfg";
	static std::string g_bfgSphereBurnNameIdStr = "weapon/player/bfg_charge_sphere_burn";
	static std::string g_unmaykrNameIdStr = "weapon/player/unmaykr";
	static std::string g_crucibleNameIdStr = "weapon/player/crucible";
	static std::string g_hammerNameIdStr = "weapon/player/hammer";
}



namespace ItemNames {
	static const char* shotGunBaseName = "weapon/player/shotgun";
	static const char* shotGunStickiesName = "weapon/player/shotgun_secondary_pop_rockets";
	static const char* shotGunFullAutoName = "weapon/player/shotgun_secondary_full_auto";
	static const char* heavyCannonName = "weapon/player/heavy_cannon";
	static const char* heavyCannonBoltName = "weapon/player/heavy_cannon_bolt_action";
	static const char* heavyCannonDetonateName = "weapon/player/heavy_cannon_burst_detonate_mastery";
	static const char* plasmaName = "weapon/player/plasma_rifle";
	static const char* plasmaAoeName = "weapon/player/plasma_rifle_secondary_aoe";
	static const char* plasmaMicroWaveName = "weapon/player/plasma_rifle_secondary_microwave";
	static const char* rocketLauncherName = "weapon/player/rocket_launcher";
	static const char* rocketLauncherDetonateName = "weapon/player/rocket_launcher_detonate";
	static const char* rocketLauncherLockOnName = "weapon/player/rocket_launcher_lock_mod_mastery";
	static const char* superShotGunOnName = "weapon/player/double_barrel";
	static const char* superShotGunPrimaryOnName = "weapon/player/double_barrel_primary_lockon";
	static const char* superShotGunMeathookName = "weapon/player/double_barrel_meat_hook";
	static const char* balistaName = "weapon/player/gauss_rifle";
	static const char* balistaArbalesteName = "weapon/player/gauss_rifle_ballista";
	static const char* balistaDestroyerBladeName = "weapon/player/gauss_rifle_destroyer";
	static const char* chaingunName = "weapon/player/chaingun";
	static const char* chaingunShielName = "weapon/player/chaingun_energy_shell";
	static const char* chaingunShielPrimaryName = "weapon/player/chaingun_energy_shell_primary";
	static const char* chaingunTurretPrimaryName = "weapon/player/chaingun_turret_primary";
	static const char* chaingunTurretSecondaryName = "weapon/player/chaingun_turret_secondary";
	static const char* bfgName = "weapon/player/bfg";
	static const char* bfgSphereBurnName = "weapon/player/bfg_charge_sphere_burn";
	static const char* unmaykrName = "weapon/player/unmaykr";
	static const char* crucibleName = "weapon/player/crucible";
	static const char* hammerName = "weapon/player/hammer";
	static const char* fragNadeName = "throwable/player/frag_grenade";
	static const char* iceNadeName = "throwable/player/ice_bomb";
}






//! Mod name:
//static std::string modName = "KaibzHudAndCrosshair";
//! Mod name:
//static std::string modDllName = "XINPUT1_3.dll";

static std::string g_modFullNameWithSpaces = "Dedicated Grenade Keys And QOL";
//! Ini file
//? changing the name of the ini file or the log could create issue for users who would have 2 versions
static std::string g_iniFileName =  "GrenadeKeysMod.ini";
//! log file
static std::string logTxtFileName =  "GrenadeKeysModLog.txt";
//static std::string logTxtFileName =  "DedicatedGrenadeKeysAndQOL_LOG.txt";
//static std::string logTxtFileNameTEST =  "GrenadeKeysModLogTEST.txt";

//! Nexxus link:
//static std::string nexxusModMainPageLink = "http://Idontknowtheaddressyet.com";

//! Mod Author name:
static std::string g_modAuthor = "Kaibz";

//! 2/10/23
static const int g_currentShortModVersion = 14;

//enum IniFileStatus {
//	iniFileStatusUnknown,
//	iniFileUndefined,
//	iniFileVersionMismatch,
//	iniFileSavingDefault,
//	iniFileLoaded,
//	iniFileParsingError,
//	iniFileExceptionError
//
//};

enum class GameState {

	undefined = -2,
	unknown = -1,
	inMainMenu = 0,
	loading = 1,
	levelLoaded = 2,	
	MAX_GAME_STATES
};


enum class PlayerState {

	undefined = -2,
	unknown = -1,
	inMainMenu = 0,
	inLoadingScreen = 1,
	inPauseMenu = 2, //! in pause menue user can also acces settings, so pause menu means in game menus but not main menu. 
	inGameNotAbleToFight = 3,	
	inGameReticleActive = 4
};


enum class PauseMenuState {
	undefined = -2,
	unknown = -1,
	closed = 0,
	opened = 1
};

enum NadeStatus {

	undefinedNade,
	iceNade,
	fragNade,
	badPtrNade,
	unknownNade,
	errorNade,
	MAX_NADE_STATUS
};

//7113 (shotgun) 8562(ar), 7404 (plasma), ssg(22668), rl(7732), bfg(20817), unmaker(11052), minigun(7982), ballista(8300), sword(23691), Hammer(10464).
//? i don't think we can use those as id as they are in fact globalLastLoadIndex (offset 0x34 in idDeclWeapon which is actually an idResouce member cause of inheritance)
//enum WeaponId {
//
//	undefinedWeapon = -1,
//	shotgun = 7113,
//	assaultRifle = 8562,
//	plasma = 7404,
//	rocketLauncher = 7732,
//	superShotgun = 22668,
//	ballista = 8300,
//	miniGun = 7982,
//	bfg = 20817,
//	unmaker = 11052,
//	crucible = 23691,
//	Hammer = 10464
//};

//enum GrenadeTypeId {
//
//	unknownGrenadeType = -1,
//	frag = 9843,
//	ice = 0x276A
//};



enum class usercmdButton : __int64 {

	BUTTON_NONE = 0,
	BUTTON_ATTACK1 = 1,
	BUTTON_ATTACK2 = 2, // K this is actually melee button
	BUTTON_ALTFIRE = 4, //K triggered when pressing mouse 2 but not continuously unfortunately
	BUTTON_USE = 8,
	BUTTON_ZOOM = 0x10,
	BUTTON_SPRINT = 0x20,
	BUTTON_CHANGEWEAPON = 0x40,
	BUTTON_WEAP_RELOAD = 0x80,
	BUTTON_MP_SCOREBOARD = 0x80,
	BUTTON_WEAP_NEXT = 0x100,
	BUTTON_WEAP_PREV = 0x200,
	BUTTON_WEAP_0 = 0x400,
	BUTTON_SHOTGUN = 0x800,					
	BUTTON_ASSAULT_RIFFLE = 0x1000,			
	BUTTON_PLASMA = 0x2000,					
	BUTTON_RL = 0x4000,						
	BUTTON_SUPER_SHOTGUN = 0x8000,
	BUTTON_BALISTA = 0x10000,
	BUTTON_MINIGUN = 0x20000,
	BUTTON_BFG_UNMAKER = 0x40000,
	BUTTON_WEAP_9 = 0x80000,
	BUTTON_BFG = 0x100000,
	BUTTON_WALK = 0x200000,
	BUTTON_DASH = 0x400000,
	BUTTON_USE_EQUIPMENT = 0x800000,		// BUTTON_QUICK_USE = 0x800000,
	BUTTON_SWITCH_EQUIPMENT = 0x1000000,    // BUTTON_QUICK_0 = 0x1000000
	BUTTON_QUICK_1 = 0x2000000,
	BUTTON_QUICK_2 = 0x4000000,
	BUTTON_QUICK_3 = 0x8000000,
	BUTTON_WEAP_SIDEARM = 0x8000000,
	BUTTON_NEXT_QUICK_ITEM = 0x10000000,
	BUTTON_PREV_QUICK_ITEM = 0x20000000,
	BUTTON_INVENTORY = 0x40000000,
	BUTTON_ACTIVATE_ABILITY = 0x80000000,
	BUTTON_MOVEUP = 0x100000000,
	BUTTON_CRUCIBLE_HAMMER = 0x400000000,
	BUTTON_TEAM_SUPER_COMBO = 0x800000000,
	BUTTON_TRAILERCAM_0 = 0x1000000000,
	BUTTON_TRAILERCAM_MENU = 0x2000000000,
	BUTTON_POWER = 0x4000000000,
	BUTTON_OBJECTIVES = 0x8000000000 //! there are more enums but we don't use it and if we add it will set an error for the __int64 type (which is the same as func isKeyPress hook parameter so i would rather use the same the whole enum list is )
};



//? not used, just kept as reference.
//enum class usercmdButtonCompleteList : uint64_t { 
//	BUTTON_NONE = 0,
//	BUTTON_ATTACK1 = 1,
//	BUTTON_ATTACK2 = 2,
//	BUTTON_ALTFIRE = 4,
//	BUTTON_USE = 8,
//	BUTTON_ZOOM = 0x10,
//	BUTTON_SPRINT = 0x20,
//	BUTTON_CHANGEWEAPON = 0x40,
//	BUTTON_WEAP_RELOAD = 0x80,
//	BUTTON_MP_SCOREBOARD = 0x80,
//	BUTTON_WEAP_NEXT = 0x100,
//	BUTTON_WEAP_PREV = 0x200,
//	BUTTON_WEAP_0 = 0x400,
//	BUTTON_SHOTGUN = 0x800,        // K: shotgung
//	BUTTON_ASSAULT_RIFFLE = 0x1000,       // K: assaut rifle 
//	BUTTON_PLASMA = 0x2000,       // K: plasma
//	BUTTON_RL = 0x4000,       // K: rocket launcher
//	BUTTON_SUPER_SHOTGUN = 0x8000,
//	BUTTON_BALISTA = 0x10000,
//	BUTTON_MINIGUN = 0x20000,
//	BUTTON_BFG_UNMAKER = 0x40000,
//	BUTTON_WEAP_9 = 0x80000,
//	BUTTON_BFG = 0x100000,
//	BUTTON_WALK = 0x200000,
//	BUTTON_DASH = 0x400000,
//	BUTTON_USE_EQUIPMENT = 0x800000,		// K: this is throw grenade
//	BUTTON_SWITCH_EQUIPMENT = 0x1000000,     	// K: this is Switch grenade type
//	BUTTON_QUICK_1 = 0x2000000,
//	BUTTON_QUICK_2 = 0x4000000,
//	BUTTON_QUICK_3 = 0x8000000,
//	BUTTON_WEAP_SIDEARM = 0x8000000,
//	BUTTON_NEXT_QUICK_ITEM = 0x10000000,
//	BUTTON_PREV_QUICK_ITEM = 0x20000000,
//	BUTTON_INVENTORY = 0x40000000,
//	BUTTON_ACTIVATE_ABILITY = 0x80000000,
//	BUTTON_MOVEUP = 0x100000000,
//	BUTTON_CRUCIBLE_HAMMER = 0x400000000,
//	BUTTON_TEAM_SUPER_COMBO = 0x800000000,
//	BUTTON_TRAILERCAM_0 = 0x1000000000,
//	BUTTON_TRAILERCAM_MENU = 0x2000000000,
//	BUTTON_POWER = 0x4000000000,
//	BUTTON_OBJECTIVES = 0x8000000000,
//	INPUT_MOVEDOWN = 0x1000000000000,
//	INPUT_MOVELEFT = 0x2000000000000,
//	INPUT_MOVERIGHT = 0x4000000000000,
//	INPUT_MOVEFORWARD = 0x8000000000000,
//	INPUT_MOVEBACK = 0x10000000000000,
//	INPUT_LOOKUP = 0x20000000000000,
//	INPUT_LOOKDOWN = 0x40000000000000,
//	INPUT_LOOKLEFT = 0x80000000000000,
//	INPUT_LOOKRIGHT = 0x100000000000000,
//	BUTTON_ANY = 0x0FFFFFFFFFFFFFFFF
//};


//? afaik this is unrealiable because these numbers are actually globalLastLoadIndex and not pure ids
//enum declWeaponModId
//{
//	undefinedModId = 0,
//	shotgunStickyBombsId = 7121,
//	shotgunFullAutoId = 7132,
//	precisionBoltId = 8588,
//	microMissilesId = 8629,
//	rocketLockOnId = 7783,
//	rocketRemoteDetonateId = 7737,
//	plasmaHeatBlastId = 7433,
//	plasmaMicroWaveBeamId = 7349,
//	superShotGunId = 22657,
//	balistaArbalesteId = 8301,
//	balistaBladeId = 8343,
//	miniGunShieldId = 8002,
//	miniGunTurretId = 7991,
//	bfgId = 20763,
//	unmakerId = 11052
//	//! not adding crucible and hammer and i can see the use for it.
//};

//? this values are wrong they should never be used for ids 
//enum declWeaponResourceId
//{
//	/*undefined = 0,
//	shotgunStickyBombsId = 7121,
//	shotgunFullAutoId = 7132,
//	precisionBoltId = 8588,
//	microMissilesId = 8629,
//	rocketLockOnId = 7783,
//	rocketRemoteDetonateId = 7737,
//	plasmaHeatBlastId = 7433,
//	plasmaMicroWaveBeamId = 7349,
//	superShotGunId = 22657,
//	balistaArbalesteId = 8301,
//	balistaBladeId = 8343,
//	miniGunShieldId = 8002,
//	miniGunTurretId = 7991,
//	bfgId = 20763,
//	unmakerId = 11052*/
//	//! not adding crucible and hammer and i can see the use for it.
//};



//! used chatGpt to generate this:
const std::map<std::string, int> keyStrToVK_KeyMap = {
	{"0", 0x30},
	{"1", 0x31},
	{"2", 0x32},
	{"3", 0x33},
	{"4", 0x34},
	{"5", 0x35},
	{"6", 0x36},
	{"7", 0x37},
	{"8", 0x38},
	{"9", 0x39},
	{"A", 0x41},
	{"B", 0x42},
	{"C", 0x43},
	{"D", 0x44},
	{"E", 0x45},
	{"F", 0x46},
	{"G", 0x47},
	{"H", 0x48},
	{"I", 0x49},
	{"J", 0x4A},
	{"K", 0x4B},
	{"L", 0x4C},
	{"M", 0x4D},
	{"N", 0x4E},
	{"O", 0x4F},
	{"P", 0x50},
	{"Q", 0x51},
	{"R", 0x52},
	{"S", 0x53},
	{"T", 0x54},
	{"U", 0x55},
	{"V", 0x56},
	{"W", 0x57},
	{"X", 0x58},
	{"Y", 0x59},
	{"Z", 0x5A},	
	{"F1", 0x70},
	{"F2", 0x71},
	{"F3", 0x72},
	{"F4", 0x73},
	{"F5", 0x74},
	{"F6", 0x75},
	{"F7", 0x76},
	{"F8", 0x77},
	{"F9", 0x78},
	{"F10", 0x79},
	{"F11", 0x7A},
	{"F12", 0x7B}
};


const std::map<int, std::string> vKToKeyStrMap = {
	{0x41, "A"},
	{0x42, "B"},
	{0x43, "C"},
	{0x44, "D"},
	{0x45, "E"},
	{0x46, "F"},
	{0x47, "G"},
	{0x48, "H"},
	{0x49, "I"},
	{0x4A, "J"},
	{0x4B, "K"},
	{0x4C, "L"},
	{0x4D, "M"},
	{0x4E, "N"},
	{0x4F, "O"},
	{0x50, "P"},
	{0x51, "Q"},
	{0x52, "R"},
	{0x53, "S"},
	{0x54, "T"},
	{0x55, "U"},
	{0x56, "V"},
	{0x57, "W"},
	{0x58, "X"},
	{0x59, "Y"},
	{0x5A, "Z"},
	{0x30, "0"},
	{0x31, "1"},
	{0x32, "2"},
	{0x33, "3"},
	{0x34, "4"},
	{0x35, "5"},
	{0x36, "6"},
	{0x37, "7"},
	{0x38, "8"},
	{0x39, "9"},
	{0x70, "F1"},
	{0x71, "F2"},
	{0x72, "F3"},
	{0x73, "F4"},
	{0x74, "F5"},
	{0x75, "F6"},
	{0x76, "F7"},
	{0x77, "F8"},
	{0x78, "F9"},
	{0x79, "F10"},
	{0x7A, "F11"},
	{0x7B, "F12"}
};



//! Bind Labels Strings


//! when those string appear in the BindString function, it means the next string will be the Equipment launcher or the Mission information label which is the best way to identify the label in any language.
const std::string EquipmentLauncherFlagStr = "#str_bind_slayer_quickuse";
const std::string EquipmentLauncherControllerFlagStr = "#str_bind_slayer_quickuse_CONTROLLER";

const std::string SwitchEquipmentFlagStr = "#str_bind_slayer_quick0";
const std::string SwitchEquipmentControllerFlagStr = "#str_bind_slayer_quick0_CONTROLLER";
//const std::string MissionInfoFlagStr = "#str_bind_slayer_objectives";

//! strings from the current language str ptr in the game
//const std::string EnglishLangStr = "English(US)";
const std::string EnglishLangStr = "english";
//const std::string FrenchLangStr = "French(France)";
const std::string FrenchLangStr = "french";
//const std::string GermanLangStr = "German";
const std::string GermanLangStr = "german";
//const std::string ItalianLangStr = "Italian";
const std::string ItalianLangStr = "italian";
//const std::string JapaneseLangStr = "Japanese";
const std::string JapaneseLangStr = "japanese";
//const std::string PolishLangStr = "Polish";
const std::string PolishLangStr = "polish";
//const std::string PortugueseLangStr = "Portuguese(Brazil)";
const std::string PortugueseLangStr = "portuguese";
//const std::string RussianLangStr = "Russian";
const std::string RussianLangStr = "russian";
//const std::string SpanishSpainLangStr = "Spanish(Spain)";
const std::string SpanishSpainLangStr = "spanish";
//const std::string SpanishMexicoLangStr = "Spanish(Mexico)";
const std::string SpanishMexicoLangStr = "latin_spanish";



static std::u8string FragGrenadeEnglishStr = u8"Frag Grenade";
static std::u8string IceGrenadeEnglishStr = u8"Ice Grenade";

static std::u8string FragGrenadeFrenchStr = u8"Grenade Frag";
static std::u8string IceGrenadeFrenchStr = u8"Grenade Glace";

static std::u8string FragGrenadeGermanStr = u8"Sprenggranate";
static std::u8string IceGrenadeGermanStr = u8"Eisgranate";

static std::u8string FragGrenadeItalianStr = u8"Granata Frag";
static std::u8string IceGrenadeItalianStr = u8"Granata Ghiaccio";
	 
static std::u8string FragGrenadeJapanStr = u8"破片グレネード";
static std::u8string IceGrenadeJapanStr = u8"氷グレネード";
	 
static std::u8string FragGrenadePolishStr = u8"Granat Frag";
static std::u8string IceGrenadePolishStr = u8"Granat Lodowy";
	 
static std::u8string FragGrenadePortugeseStr = u8"Granada Frag";
static std::u8string IceGrenadePortugeseStr = u8"Granada Gelo";
	
//static std::u8string FragGrenadeRussianStr = u8"Фраг Гранада";
static std::u8string FragGrenadeRussianStr = u8"Осколочная Граната"; //! translation from russian dude on discord
//static std::u8string IceGrenadeRussianStr = u8"Лед Гранада";
static std::u8string IceGrenadeRussianStr = u8"Ледяная Бомба"; //! translation from russian dude on discord
	 
static std::u8string FragGrenadeSpanishStr = u8"Granada Frag";
static std::u8string IceGrenadeSpanishStr = u8"Granada Hielo";



enum class GameLanguage
{
	Undefined,
	English,
	French,
	German,
	Italian,
	Japanese,
	Polish,
	Portuguese,
	Russian,
	Spanish
};

	

enum class ExistingModError 
{
	NoPreviousModVersionFound,
	GrenadeKeysModAndQolFound,
	GrenadeKeysModAndQolDebugFound,
	GrenadeKeysModAndQol_04Found,
	ExceptionError
};

enum class ModFileToDelete {
	XInput9_1_0,
	DINPUT8
};

//enum class GrenadeType {
//	None = -1, //! at the start of the game this will be the value at idPlayer+0x6F48
//	Frag = 0,
//	Ice = 1
//};



//! used in idCmd:
static std::string m_ZeroAsStr = "0";
static std::string m_OneAsStr = "1";


//? 15/4/24 We should not use thos....using the actual name should be better, even if a bit slower but as we don't do that critial stuffs with the code i think it should be ok. i'm using them temporarily but soon to be replaced....
//x these IDs are actual resourceIDs and unique fro ex the frag equipement and throwable are different compared to the display id of the decl which is what our old ItemID was based on
//enum class Item_ResourceID : unsigned long long {
//	UNKNOWN = 0xFFFFFFFFFFFFFFFFULL,
//	ABILITIES_BLOOD_PUNCH = 0xF47168A0751A007CULL,
//	ABILITIES_ENVIRONMENTSUIT = 0xC4FECAE8620D6422ULL,
//	ABILITIES_GRAPPLEGLOVES = 0x492E14A8101068D3ULL,
//	ABILITY_DASH = 0xFC27CEE0E5949476ULL,
//	ACTORMODIFIER_SP_DEMON_REVENANT = 0x4D5F4E10C75DC200ULL,
//	AMMO_PLAYER_DOOMBLADE = 0x9563C9F4E598A51FULL,
//	AMMO_SHAREDAMMOPOOL_BFG = 0x803C7BC2CD849430ULL,
//	AMMO_SHAREDAMMOPOOL_BULLETS = 0x622277586D6479C6ULL,
//	AMMO_SHAREDAMMOPOOL_CELLS = 0xB498A965A91A24CDULL,
//	AMMO_SHAREDAMMOPOOL_CRUCIBLE = 0x6AC8E29263A449F1ULL,
//	AMMO_SHAREDAMMOPOOL_HAMMER = 0x92B2B5CEB403C2B1ULL,
//	AMMO_SHAREDAMMOPOOL_FIST = 0x7CDACD0906C3D2ACULL,
//	AMMO_SHAREDAMMOPOOL_FUEL = 0xB6F6BACD01E64E2FULL,
//	AMMO_SHAREDAMMOPOOL_ROCKETS = 0x68D1CA125710F5C1ULL,
//	AMMO_SHAREDAMMOPOOL_SHELLS = 0x4FC1662CE66881ACULL,
//	CHARGE_ATTACK_BASE = 0xDB9D7231EEAD951EULL,
//	EQUIPMENT_FLAME_BELCH = 0x673924F05FE3C6FFULL,
//	EQUIPMENT_FRAG_GRENADE = 0x743C9C82713B45CEULL,
//	EQUIPMENT_ICE_BOMB = 0x1F2C8735616F1B78ULL,
//	EQUIPMENTLAUNCHER_EQUIPMENTLAUNCHERLEFT = 0x66B37C9F10BC1B6AULL,
//	EXTRA_LIFE = 0xF7775862D5108314ULL,
//	JUMPBOOTS_BASE = 0xC5350BE1FB9B3462ULL,
//	THROWABLE_PLAYER_FRAG_GRENADE = 0xA04ABBF5A4FFE0E1ULL,
//	THROWABLE_PLAYER_ICE_BOMB = 0x261DEA0E39F9B6CFULL,
//	WEAPON_PLAYER_BFG = 0x645631C5C67531EAULL,
//	WEAPON_PLAYER_CHAINGUN = 0x719931C4147BBA87ULL,
//	WEAPON_PLAYER_CHAINSAW = 0x479B5D2E771C61D0ULL,
//	WEAPON_PLAYER_CRUCIBLE = 0x7163D1CC7530330EULL,
//	WEAPON_PLAYER_DOOMBLADE = 0xF540EF201C44A090ULL,
//	WEAPON_PLAYER_DOUBLE_BARREL = 0xE1FC691592B659A1ULL,
//	WEAPON_PLAYER_EQUIPMENT_FLAME_BELCH = 0x4553971C46781F26ULL,
//	WEAPON_PLAYER_FISTS = 0x14970210BB43503DULL,
//	WEAPON_PLAYER_FISTS_BERSERK = 0x1DFD28E6B4142BFFULL,
//	WEAPON_PLAYER_FISTS_DOOM5MELEE = 0x38CD385DA246588DULL,
//	WEAPON_PLAYER_FISTS_SWIM = 0x93C512AED91CE8E2ULL,
//	WEAPON_PLAYER_HAMMER = 0x9C999CECCEC9843CULL,
//	WEAPON_PLAYER_GAUSS_RIFLE = 0x42F622CC2B4506C4ULL,
//	WEAPON_PLAYER_HEAVY_CANNON = 0xB7820666379C5A35ULL,
//	WEAPON_PLAYER_PLASMA_RIFLE = 0xF2FAE14A4FAF53BBULL,
//	WEAPON_PLAYER_POINTING_ARM = 0xD99B2C4F1D0E392DULL,
//	WEAPON_PLAYER_ROCKET_LAUNCHER = 0xA90B43917C2D2571ULL,
//	WEAPON_PLAYER_SHOTGUN = 0x11E81EC2AE351302ULL,
//	WEAPON_PLAYER_UNMAYKR = 0xCCDB4A724D9B9412ULL
//	
//};





////! these IDs are found in a decl object at offset 0x124 
//enum class displayName_Id : unsigned int {
//	Unknown = 0,
//	FistsBase = 0xC4CFFF6B,
//	FistsBerzerk = 0x6CD5C552,
//	FistsSwim = 0xC4CFFF6B,
//	DoomBlade = 0xBE5237FD,
//	FlameBelch = 0x5C3B123B,
//	FragGrenade = 0x93C57E83,
//	IceBomb = 0x37B8DB32, 
//	Shotgun = 0xC47BB99E,
//	HeavyCannon = 0xA23893A9, 
//	PlasmaRifle = 0x5C09DABF,
//	RocketLauncher = 0xC9AA4355,
//	SuperShotgun = 0x8247049A,
//	Ballista = 0x6DADE90F,
//	MiniGun = 0xF390750D,
//	Bfg = 0xB1F81501,
//	Unmaykr = 0xEA254476,
//	Crucible = 0xBE2EF931,
//	Hammer = 0x9EAD8C7A,
//	AmmoShells = 0xB50CFED,
//	AmmoBullets = 0xDFC61AFF,
//	AmmoCells = 0xE674C29B,
//	AmmoRockets = 0x3820C1AB,
//	AmmoBfg = 0x98CF1F37,
//	AmmoFuel = 0x98A108CA,
//	DashAbility = 0xB3C3E28C
//};




//static std::map<ItemID, weaponSlot_t> itemIdToWeaponSlotMap = {
//{ItemID::Shotgun, weaponSlot_t::SHOTGUN},
//{ItemID::HeavyCannon, weaponSlot_t::HAR},
//{ItemID::PlasmaRifle, weaponSlot_t::PLASMA},
//{ItemID::RocketLauncher, weaponSlot_t::ROCKET},
//{ItemID::SuperShotgun, weaponSlot_t::SSG},
//{ItemID::Ballista, weaponSlot_t::BALLISTA},
//{ItemID::MiniGun, weaponSlot_t::CHAINGUN},
//{ItemID::Bfg, weaponSlot_t::BFG_UNMAYKR},
//{ItemID::Unmaykr, weaponSlot_t::BFG_UNMAYKR},
//};

struct InventoryItem {
	unsigned int ID = 0; //! some items will have an ID of 0 and some will have same IDs keep that in mind
	//__int64 Address;
	std::string Name = "unknown";
	int Count = -1;
};


//enum class GameState {
//	Unknown = -1,
//	InMainMenu = 0,
//	Loading = 1,
//	Loaded = 2
//};



class matrDebughContainer {

public:
	__int64 MatPtr = 0;
	std::string Name = "unknown";
	matrDebughContainer(__int64 matPtr, std::string name)
	{
		MatPtr = matPtr;
		Name = name;
	}
};

//! name of the currently displayed grenade icon on the hud
//! found at idPlayer + 47320 => idHUD_WeaponInfo + 1D0=> idSWFWidget_EquipmentItem + 188h
static std::string g_icebombIconNameStr = "art/ui/weapon/equipment_ice_bomb";
static std::string g_fragNadeIconNameStr = "art/ui/weapon/equipment_frag_grenade";


const std::vector<std::string> materialsLibFileNames = {
	"_white",
	"art/ui/icons/ammo/shells",
	"art/ui/icons/ammo/rocket",
	"swf/hud/hud_reticle_textures/swf_images/icons/icon_ammo_cell_",
	"art/ui/icons/argent_cells_upgrade/argent_cell_health",
	"art/ui/icons/ammo/ico_shells",
	"art/ui/icons/ammo/bullets",
	"art/ui/icons/ammo/fist",
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_",
	"art/ui/weapon/equipment_frag_grenade",  // this one is lowRes by default
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/hud/ammo_equipment/hud_slayer_equipment_circlepip_full_",
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_hammer_racecar_",
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_grenade_frag_",  // this one is HiRes by default
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ability_flame_belch_racecar_",
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_ammo_fuel_",
	"swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/icon_rune_bloodpunch_racecar_",
	"swf/hud/pvp/hud_matchheader_textures/swf_images/icons/callouts/icon_callout_plus_",
	"swf/hud/hud_poi_textures/swf_images/icons/icon_grenade_frag_",
	"swf/hud/hud_weaponinfo_textures/swf_images/icons/icon_ability_flame_belch_", //? without the dot
	"swf/hud/hud_weaponinfo_textures/swf_images/icons/icon_ammo_fuel_",
	"swf/hud/hud_bossvitals_textures/swf_images/icons/callouts/icon_callout_plus_outline_",
	"swf/hud/hud_bossvitals_textures/swf_images/icons/callouts/icon_callout_plus_",
	"swf/hud/hud_healthinfo_textures/swf_images/icons/icon_health_new_",
	"swf/hud/hud_healthinfo_textures/swf_images/icons/icon_health_new_glow_",
	"swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_full_",
	"swf/hud/hud_healthinfo_textures/swf_images/icons/icon_armor_",
	"swf/hud/menus/death_textures/swf_images/icons/icon_armor_",
	"swf/hud/menus/end_of_level/eol_horde_map_score_textures/swf_images/common/scrollbar/swf/hud/hud_abilityindicators_singlestack_textures/swf_images/icons/callouts/icon_callout_ice_bomb_hud_scrollbar_endcap_arrow_",
	"swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/painelemental/demon_reticle_painelemental_outerrim_glow_",
	"swf/hud/hud_compass_textures/swf_images/icons/icon_objective_arrow_",
	"swf/hud/hud_dash_textures/swf_images/hud/buffs/hud_slayer_rune_container_corner_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/rocket_launcher/ret_rocket_lock_part01_top_",
	"swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/marauder/demon_reticle_marauder_outerrim_glow_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/crucible/ret_center_circle_4pins_",
	"swf/main_menu/screens/settings_textures/swf_images/icons/icon_tab_notification_",
	"textures/guis/icons/weapons/simple/bfg",
	"textures/swf_images/hud/weapon_icon/weaponicon_heavycannon"  //! found this in an idimage of a idmaterial of chaingun
	"textures/guis/icons/weapons/simple/har",
	"textures/guis/icons/weapons/simple/gauss",
	"textures/guis/icons/weapons/simple/chaingun",
	"textures/guis/icons/weapons/simple/dbshotgun",
	"textures/guis/icons/weapons/simple/rocket",
	"textures/guis/icons/weapons/simple/plasma",
	"textures/guis/icons/weapons/simple/shotgun",
	"textures/guis/hud/damage_icons/weapon_rocket",
	"textures/guis/icons/perks/weapons/shotgun/pop_rocket",
	"textures/guis/loading_screen/sp/img_loading_sp_rocket_launcher",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_ammo_top_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_ammo_glow_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_top_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_glow_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_mastered_glow_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_mastered_top_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_pin_glow_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/combat_shotgun/ret_combatshotgun_sticky_circle_pin_top_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/super_shotgun/ret_supershotgun_base_top_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/super_shotgun/ret_supershotgun_hook_top_",
	"swf/hud/hud_reticle_textures/swf_images/reticles/super_shotgun/ret_supershotgun_hook_glow_",
	"swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/revenant/demon_reticle_revenant_innerrim_glow_",
	"swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/revenant/demon_reticle_revenant_innerrim_",
	"swf/hud/hud_reticle_textures/swf_images/hud_demon/reticles/revenant/demon_reticle_revenant_outerrim_",
	"swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_new_",
	"swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_backer_",
	"swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_1pip_fill_",
	"swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_2pip_backer_",
	"swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_fill_2pip_fill_",
	"swf/hud/hud_weaponinfo_textures/swf_images/icons/icon_swap2_",
	"swf/hud/hud_weaponinfo_textures/swf_images/hud/ammo_equipment/equipment_new/hud_slayer_equipment_backer_swap_alt_",
	"swf/hud/hud_score_textures/swf_images/hud/demonic_corruption/hud_slayer_demoncorruption_pip_",
	"swf/common/social_bar_textures/swf_images/common/buttons/command_bar/command_bar_social_backing_",
	"swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_empty_",
	"swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_fadednumbers_",
	"swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_health_pip_full_",
	"swf/hud/hud_healthinfo_textures/swf_images/hud/health_bars/hud_slayer_radsuit_iconbacker_",
	"swf/hud/hud_healthinfo_textures/swf_images/icons/icon_armor_"

};


enum class idFontEnum : unsigned int {
	unknown =  0,		//! works
	eternal88 =  1,		//! works
	eternal90 =  2,		//! thin font 
	ttSuper98 =  3,		//! 7 segments style
	ttSuperA0 =  4,		//! stylish 
	idTacticA8 = 5,		//! flatter 
	euroStilB0 = 6,		//! very thin and low alpha value
	//eternalB8,		//! no display (for fr at least)
	/*eternalC0,
	dfpop3w1C8,
	dfpop2w9D0,
	dfpop1w5D8,
	dfpop3w1E0,
	koreantkE8,
	koreansnF0,*/
	defaultCourrierF8 = 7,
	MAX_ID_FONTS 

};


//! this is the value you have to add to the x position so the text start to get written exactly at this position
const float ttSuper98_text_x_Offset_base = 3.7f; //! numeral 7segments.
const float ttSuper98_text_y_Offset_base = -0.7f; //! numeral 7segments.
//const float ttSuper98_text_y_Offset_base = .00000018f; //! numeral 7segments.


//! elements part of a crosshair/hud
enum class RectID {

	undefined,
	centerDot,
	leftBar,
	topBar,
	rightBar,
	bottomBar
};

enum class HudDataID {

	undefined,
	noData,
	health,
	armor,
	FragGrenade,
	IceGrenade,
	FuelAmmo,
	FlameBelch,
	BloodPunch,
	//BloodPunch2, //! will set color on only if player has 2 bp	
	CrucibleOrHammer
};


static std::map<RectID, HudDataID> NoData_CrosshairDataMap = {
	{RectID::undefined, HudDataID::undefined},
	{RectID::centerDot, HudDataID::noData},
	{RectID::leftBar, HudDataID::noData},
	{RectID::topBar, HudDataID::noData},
	{RectID::rightBar, HudDataID::noData},
	{RectID::bottomBar, HudDataID::noData}
};

static std::map<RectID, HudDataID> HealthOnly_CrosshairDataMap = {
	{RectID::undefined, HudDataID::undefined},
	{RectID::centerDot, HudDataID::health},
	{RectID::leftBar, HudDataID::health},
	{RectID::topBar, HudDataID::health},
	{RectID::rightBar, HudDataID::health},
	{RectID::bottomBar, HudDataID::health}
};

static std::map<RectID, HudDataID> Nades_Bp_Fuel_NoHealth_CrosshairDataMap = {
	{RectID::undefined, HudDataID::undefined},
	{RectID::centerDot, HudDataID::noData},
	{RectID::leftBar, HudDataID::FragGrenade},
	{RectID::topBar, HudDataID::BloodPunch},
	{RectID::rightBar, HudDataID::IceGrenade},
	{RectID::bottomBar, HudDataID::FlameBelch}
};

static std::map<RectID, HudDataID> Nades_Bp_Fuel_Health_CrosshairDataMap = {
	{RectID::undefined, HudDataID::undefined},
	{RectID::centerDot, HudDataID::health},
	{RectID::leftBar, HudDataID::FragGrenade},
	{RectID::topBar, HudDataID::BloodPunch},
	{RectID::rightBar, HudDataID::IceGrenade},
	{RectID::bottomBar, HudDataID::FlameBelch}
};



//! Game Settings:

enum class UI_Scalling {

	Small = 0,
	Medium = 1,
	Large = 2
};

enum class UI_ReticleMode {
	Unknown = -1,
	Full = 0,
	Dot = 1,
	None = 2
};


//! Hud Events (broadcasted events)










//! used for ex in idSWFSpriteInstance.h
enum swfNamedColors_t : int {	

	SWF_NAMED_COLOR_INVALID = -1,
	SWF_NAMED_COLOR_HUD_BASE = 0,
	SWF_NAMED_COLOR_HUD_SHADOW = 1, //! changes with ui profile
	SWF_NAMED_COLOR_HUD_TEXT = 2,  // this might be the color of the hud arrow but it will change if user has set a different color profile...
	SWF_NAMED_COLOR_HUD_HEADER = 3,
	SWF_NAMED_COLOR_DASH_BASE = 4,
	SWF_NAMED_COLOR_DASH_GLOW = 5,
	SWF_NAMED_COLOR_NOTIFICATION_GHOST = 6,
	SWF_NAMED_COLOR_UI_HEALTH = 7,
	SWF_NAMED_COLOR_UI_HEALTH_GRADIENT = 8,
	SWF_NAMED_COLOR_UI_HEALTH_LOW = 9,
	SWF_NAMED_COLOR_UI_HEALTH_REALLY_LOW = 10,
	SWF_NAMED_COLOR_UI_HEALTH_DEMON = 11,
	SWF_NAMED_COLOR_UI_ARMOR = 12,
	SWF_NAMED_COLOR_UI_ARMOR_GRADIENT = 13,
	SWF_NAMED_COLOR_UI_RADIATION = 14,
	SWF_NAMED_COLOR_UI_RADIATION_GRADIENT = 15,
	SWF_NAMED_COLOR_UI_OXYGEN = 16,
	SWF_NAMED_COLOR_UI_OXYGEN_GRADIENT = 17,
	SWF_NAMED_COLOR_UI_WARNING = 18,
	SWF_NAMED_COLOR_UI_CAUTION = 19,
	SWF_NAMED_COLOR_UI_SUCCESS = 20,
	SWF_NAMED_COLOR_UI_FAILURE = 21,
	SWF_NAMED_COLOR_UI_PROGRESS_BAR_FILL = 22,
	SWF_NAMED_COLOR_UI_PROGRESS_COMPLETE = 23,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND = 24,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND_LOW = 25,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND_REALLY_LOW = 26,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND_DEAD = 27,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND_GLOW = 28,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND_GLOW_LOW = 29,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_BACKGROUND_GLOW_REALLY_LOW = 30,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_GREEN = 31,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_GREEN_GRADIENT = 32,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_ORANGE = 33, //!  will not be orange if in demon mode so this color will change depending on ui profile
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_ORANGE_GRADIENT = 34,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_BLUE = 35,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_BLUE_GRADIENT = 36,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_LOW = 37,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_LOW_GRADIENT = 38,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_PIP_DEAD = 39,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON = 40,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_GRADIENT = 41,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_LOW = 42,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_GRADIENT_LOW = 43,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_REALLY_LOW = 44,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_GRADIENT_REALLY_LOW = 45,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_DEAD = 46,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_ICON_GRADIENT_DEAD = 47,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_GLOW_BITS = 48,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_GLOW_BITS_LOW = 49,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_TEXT = 50,
	SWF_NAMED_COLOR_UI_DEMON_HEALTH_TEXT_LOW = 51,
	SWF_NAMED_COLOR_WORLD_UNLOCKED = 52,
	SWF_NAMED_COLOR_WORLD_LOCKED = 53,
	SWF_NAMED_COLOR_SLAYER_GREEN = 54, //! changes with ui profile
	SWF_NAMED_COLOR_DEMON_RED = 55,
	SWF_NAMED_COLOR_DEMON_YELLOW = 56, //! keeps yellow color in any profile
	SWF_NAMED_COLOR_WHITE = 57, //! keeps yellow color in any profile
	SWF_NAMED_COLOR_WEAPON_CHAINSAW = 58, //! weapons colors change with ui profile
	SWF_NAMED_COLOR_WEAPON_SHOTGUN = 59,
	SWF_NAMED_COLOR_WEAPON_DOUBLE_BARREL = 60,
	SWF_NAMED_COLOR_WEAPON_ASSUALT_RIFLE = 61,
	SWF_NAMED_COLOR_WEAPON_CHAINGUN = 62,
	SWF_NAMED_COLOR_WEAPON_PLASMA_RIFLE = 63,
	SWF_NAMED_COLOR_WEAPON_BALLISTA = 64,
	SWF_NAMED_COLOR_WEAPON_ROCKET_LAUNCHER = 65,
	SWF_NAMED_COLOR_WEAPON_BFG = 66,
	SWF_NAMED_COLOR_WEAPON_UNMAYKR = 67,
	SWF_NAMED_COLOR_WEAPON_CRUCIBLE = 68,
	SWF_NAMED_COLOR_WEAPON_HAMMER = 69,
	SWF_NAMED_COLOR_WEAPON_NO_AMMO = 70,
	SWF_NAMED_COLOR_WEAPON_DISABLED = 71,
	SWF_NAMED_COLOR_WEAPON_SHOTGUN_FULL = 72,
	SWF_NAMED_COLOR_WEAPON_DOUBLE_BARREL_FULL = 73,
	SWF_NAMED_COLOR_WEAPON_ASSUALT_RIFLE_FULL = 74,
	SWF_NAMED_COLOR_WEAPON_CHAINGUN_FULL = 75,
	SWF_NAMED_COLOR_WEAPON_PLASMA_RIFLE_FULL = 76,
	SWF_NAMED_COLOR_WEAPON_BALLISTA_FULL = 77,
	SWF_NAMED_COLOR_WEAPON_ROCKET_LAUNCHER_FULL = 78,
	SWF_NAMED_COLOR_WEAPON_BFG_FULL = 79,
	SWF_NAMED_COLOR_WEAPON_UNMAYKR_FULL = 80,
	SWF_NAMED_COLOR_WEAPON_HAMMER_FULL = 81,
	SWF_NAMED_COLOR_RETICLE_BASE = 82,
	SWF_NAMED_COLOR_RETICLE_GLOW = 83,
	SWF_NAMED_COLOR_RETICLE_COOLDOWN_BASE = 84,
	SWF_NAMED_COLOR_RETICLE_COOLDOWN_GLOW = 85,
	SWF_NAMED_COLOR_RETICLE_WARNING_BASE = 86, // nice orange in all huds but reddish in demon hud
	SWF_NAMED_COLOR_RETICLE_WARNING_GLOW = 87,
	SWF_NAMED_COLOR_RETICLE_ALT_STROKE = 88,
	SWF_NAMED_COLOR_RETICLE_ALT_BASE = 89,
	SWF_NAMED_COLOR_RETICLE_ALT_GLOW = 90,
	SWF_NAMED_COLOR_RETICLE_ALT2_STROKE = 91,
	SWF_NAMED_COLOR_RETICLE_ALT2_BASE = 92,
	SWF_NAMED_COLOR_RETICLE_ALT2_GLOW = 93,
	SWF_NAMED_COLOR_KEYCARD_BLUE = 94,
	SWF_NAMED_COLOR_KEYCARD_RED = 95,
	SWF_NAMED_COLOR_KEYCARD_YELLOW = 96,
	SWF_NAMED_COLOR_KEYCARD_SLAYER = 97,
	SWF_NAMED_COLOR_MENU_BACK_BASE = 98, // not linked to equipment arrow color
	SWF_NAMED_COLOR_MENU_BACK_STROKE = 99,
	SWF_NAMED_COLOR_MENU_SELECTION_BASE = 100,
	SWF_NAMED_COLOR_MENU_SELECTION_STROKE = 101,
	SWF_NAMED_COLOR_MENU_BACK_PRESS = 102,
	SWF_NAMED_COLOR_MENU_HEADER_TEXT = 103,
	SWF_NAMED_COLOR_COLLECTED_ITEM = 104,
	SWF_NAMED_COLOR_CORRUPTION_HEX_CLEARED = 105,
	SWF_NAMED_COLOR_CORRUPTION_HEX_GLOW_CLEARED = 106,
	SWF_NAMED_COLOR_CORRUPTION_HEX_CORRUPT = 107,
	SWF_NAMED_COLOR_CORRUPTION_HEX_GLOW_CORRUPT = 108,
	SWF_NAMED_COLOR_CORRUPTION_CONTAINER_CLEARED = 109,
	SWF_NAMED_COLOR_CORRUPTION_CONTAINER_CORRUPT = 110,
	SWF_NAMED_COLOR_CORRUPTION_CLEARED = 111,
	SWF_NAMED_COLOR_CORRUPTION_CLEARED_GLOW = 112,
	SWF_NAMED_COLOR_CORRUPTION_PARTIAL_CLEARED = 113,
	SWF_NAMED_COLOR_CORRUPTION_PARTIAL_CLEARED_GLOW = 114,
	SWF_NAMED_COLOR_CORRUPTION_COMBAT = 115,
	SWF_NAMED_COLOR_CORRUPTION_COMBAT_GLOW = 116,
	SWF_NAMED_COLOR_CORRUPTION_SLAYER_GATE = 117,
	SWF_NAMED_COLOR_CORRUPTION_SLAYER_GATE_GLOW = 118,
	SWF_NAMED_COLOR_CORRUPTION_SECRET = 119,
	SWF_NAMED_COLOR_CORRUPTION_SECRET_GLOW = 120,
	SWF_NAMED_COLOR_CORRUPTION_BOSS = 121,
	SWF_NAMED_COLOR_CORRUPTION_BOSS_GLOW = 122,
	SWF_NAMED_COLOR_CORRUPTION_BASE = 123,
	SWF_NAMED_COLOR_CORRUPTION_OVERLAY = 124,
	SWF_NAMED_COLOR_CORRUPTION_ESCALATION = 125,
	SWF_NAMED_COLOR_CORRUPTION_ESCALATION_GLOW = 126,
	SWF_NAMED_COLOR_EXTRA_LIFE_ICON = 127,
	SWF_NAMED_COLOR_EXTRA_LIFE_ICON_GLOW = 128,
	SWF_NAMED_COLOR_EXTRA_LIFE_TIMER = 129,
	SWF_NAMED_COLOR_EXTRA_LIFE_TIMER_GLOW = 130,
	SWF_NAMED_COLOR_ARGENT_CELL = 131,
	SWF_NAMED_COLOR_WEAPON_POINT = 132,
	SWF_NAMED_COLOR_PRAETOR_POINT = 133,
	SWF_NAMED_COLOR_SENTINEL_BATTERY = 134,
	SWF_NAMED_COLOR_DEMON_HUD_BACKER = 135,
	SWF_NAMED_COLOR_DEMON_HUD_ABILITIES_SELECTION_GLOW = 136,
	SWF_NAMED_COLOR_DEMON_HUD_ABILITIES_SELECTION_STROKE = 137,
	SWF_NAMED_COLOR_DEMON_HUD_ABILITY_FRAME = 138,
	SWF_NAMED_COLOR_DEMON_HUD_ABILITY_FRAME_GLOW_UNSELECTED = 139,
	SWF_NAMED_COLOR_DEMON_HUD_ABILITY_FRAME_GLOW_SELECTED = 140,
	SWF_NAMED_COLOR_DEMON_HUD_TEAL_BASE = 141,  //! DEMON_HUD_ will change alpha a bit in demon ui
	SWF_NAMED_COLOR_DEMON_HUD_TEAL_GRADIENT = 142,
	SWF_NAMED_COLOR_DEMON_HUD_TEAL_OVERLAY = 143,
	SWF_NAMED_COLOR_DEMON_HUD_TEAL_ICON = 144,
	SWF_NAMED_COLOR_DEMON_HUD_YELLOW_BASE = 145,
	SWF_NAMED_COLOR_DEMON_HUD_YELLOW_GRADIENT = 146,
	SWF_NAMED_COLOR_DEMON_HUD_YELLOW_OVERLAY = 147,
	SWF_NAMED_COLOR_DEMON_HUD_YELLOW_ICON = 148,
	SWF_NAMED_COLOR_DEMON_HUD_ORANGE_BASE = 149,
	SWF_NAMED_COLOR_DEMON_HUD_ORANGE_GRADIENT = 150,
	SWF_NAMED_COLOR_DEMON_HUD_ORANGE_OVERLAY = 151,
	SWF_NAMED_COLOR_DEMON_HUD_ORANGE_ICON = 152,
	SWF_NAMED_COLOR_DEMON_HUD_BLUE_BASE = 153,
	SWF_NAMED_COLOR_DEMON_HUD_BLUE_GRADIENT = 154,
	SWF_NAMED_COLOR_DEMON_HUD_BLUE_OVERLAY = 155,
	SWF_NAMED_COLOR_DEMON_HUD_BLUE_ICON = 156,
	SWF_NAMED_COLOR_DEMON_HUD_PURPLE_BASE = 157,
	SWF_NAMED_COLOR_DEMON_HUD_PURPLE_GRADIENT = 158,
	SWF_NAMED_COLOR_DEMON_HUD_PURPLE_OVERLAY = 159,
	SWF_NAMED_COLOR_DEMON_HUD_PURPLE_ICON = 160,
	SWF_NAMED_COLOR_DEMON_HUD_RED_BASE = 161,
	SWF_NAMED_COLOR_DEMON_HUD_RED_GRADIENT = 162,
	SWF_NAMED_COLOR_DEMON_HUD_RED_OVERLAY = 163,
	SWF_NAMED_COLOR_DEMON_HUD_RED_ICON = 164,
	SWF_NAMED_COLOR_DEMON_HUD_GREEN_BASE = 165,
	SWF_NAMED_COLOR_DEMON_HUD_GREEN_GRADIENT = 166,
	SWF_NAMED_COLOR_DEMON_HUD_GREEN_OVERLAY = 167,
	SWF_NAMED_COLOR_DEMON_HUD_GREEN_ICON = 168,
	SWF_NAMED_COLOR_DEMON_HUD_ICON_COOLDOWN = 169,
	SWF_NAMED_COLOR_DEMON_HUD_BASE_COOLDOWN = 170,
	SWF_NAMED_COLOR_DEMON_HUD_GRADIENT_COOLDOWN = 171,
	SWF_NAMED_COLOR_DEMON_HUD_OVERLAY_COOLDOWN = 172,
	SWF_NAMED_COLOR_DEMON_HUD_ABILITY_COOLDOWN_COVER = 173,
	SWF_NAMED_COLOR_DEMON_HUD_WHEEL_STROKE = 174,
	SWF_NAMED_COLOR_DEMON_HUD_WHEEL_BASE = 175,
	SWF_NAMED_COLOR_DEMON_HUD_WHEEL_GLOW = 176,
	SWF_NAMED_COLOR_DEMON_HUD_NOTIFICATION_BASE = 177,
	SWF_NAMED_COLOR_DEMON_HUD_NOTIFICATION_ICON = 178,
	SWF_NAMED_COLOR_DEMON_HUD_NOTIFICATION_STROKE = 179,
	SWF_NAMED_COLOR_DEMON_HUD_NOTIFICATION_HEADER = 180,
	SWF_NAMED_COLOR_DEMON_HUD_NOTIFICATION_TEXT = 181,
	SWF_NAMED_COLOR_DEMON_HUD_NOTIFICATION_GLOW = 182,
	SWF_NAMED_COLOR_DEMON_HUD_DEMON_PLAYER_FRAME = 183,
	SWF_NAMED_COLOR_DEMON_HUD_SLAYER_PLAYER_FRAME = 184,
	SWF_NAMED_COLOR_DEMON_HUD_DEMON_PLAYER_FRAME_BACKGLOW = 185,
	SWF_NAMED_COLOR_DEMON_HUD_SLAYER_PLAYER_FRAME_BACKGLOW = 186,
	SWF_NAMED_COLOR_DEMON_HUD_HEADER_TEXT = 187,
	SWF_NAMED_COLOR_DEMON_HUD_HEADER_TEXT_NUMBERS = 188,
	SWF_NAMED_COLOR_DEMON_HUD_SUMMARY_FRAME = 189,
	SWF_NAMED_COLOR_DEMON_HUD_SUMMARY_BACKING = 190,
	SWF_NAMED_COLOR_HUD_STATUS_BUFF_BACKGLOW = 191,
	SWF_NAMED_COLOR_HUD_STATUS_BUFF_BACKER = 192,
	SWF_NAMED_COLOR_MENU_SEASON_BASE = 193,
	SWF_NAMED_COLOR_COSMETIC_RARITY_DEFAULT = 194,
	SWF_NAMED_COLOR_COSMETIC_RARITY_TIER_1 = 195,
	SWF_NAMED_COLOR_COSMETIC_RARITY_TIER_2 = 196,
	SWF_NAMED_COLOR_COSMETIC_RARITY_TIER_3 = 197,
	SWF_NAMED_COLOR_PVP_TICKER_STROKE = 198,
	SWF_NAMED_COLOR_PVP_TICKER_BACKER = 199,
	SWF_NAMED_COLOR_PVP_TICKER_SLAYER = 200,
	SWF_NAMED_COLOR_DEMON_RETICLE = 201,
	SWF_NAMED_COLOR_REVENANT_RETICLE_GLOW = 202,
	SWF_NAMED_COLOR_REVENANT_RETICLE_GRADIENT = 203,
	SWF_NAMED_COLOR_REVENANT_RETICLE_BASE = 204,
	SWF_NAMED_COLOR_ARCHVILE_RETICLE_GLOW = 205,
	SWF_NAMED_COLOR_ARCHVILE_RETICLE_GRADIENT = 206,
	SWF_NAMED_COLOR_ARCHVILE_RETICLE_BASE = 207,
	SWF_NAMED_COLOR_PAIN_ELEMENTAL_RETICLE_GLOW = 208,
	SWF_NAMED_COLOR_PAIN_ELEMENTAL_RETICLE_GRADIENT = 209,
	SWF_NAMED_COLOR_PAIN_ELEMENTAL_RETICLE_BASE = 210,
	SWF_NAMED_COLOR_PAIN_ELEMENTAL_RETICLE_WARNING_GRADIENT = 211,
	SWF_NAMED_COLOR_PAIN_ELEMENTAL_RETICLE_WARNING_BASE = 212,
	SWF_NAMED_COLOR_MILESTONE_COMPLETED_BASE = 213,
	SWF_NAMED_COLOR_MILESTONE_COMPLETED_GRADIENT = 214,
	SWF_NAMED_COLOR_MILESTONE_COMPLETED_ICON = 215,
	SWF_NAMED_COLOR_MILESTONE_COMPLETED_TEXT = 216,
	SWF_NAMED_COLOR_PROGRESSION_ITEM_COMPLETED_BASE = 217,
	SWF_NAMED_COLOR_SENTINEL_ARMOR_STROKE = 218,
	SWF_NAMED_COLOR_SENTINEL_ARMOR_GLOW = 219,
	SWF_NAMED_COLOR_SCREEN_DAMAGE = 220,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_FRAG = 221, //! equipment colors will change depending on profile
	SWF_NAMED_COLOR_HUD_EQUIPMENT_FRAG_ICON = 222,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_CYRO = 223,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_CYRO_ICON = 224,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_CHAINSAW = 225,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_CHAINSAW_ICON = 226,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_FLAME_BELCH = 227,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_FLAME_BELCH_ICON = 228,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_CRUCIBLE = 229,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_CRUCIBLE_ICON = 230,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_HAMMER = 231,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_HAMMER_ICON = 232,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_HAMMER_SUPERCHARGE = 233,
	SWF_NAMED_COLOR_HUD_EQUIPMENT_HAMMER_GRADIENT = 234,
	SWF_NAMED_COLOR_HUD_BOSS_HEALTH_BASE = 235, //? changes color with profile
	SWF_NAMED_COLOR_HUD_BOSS_HEALTH_GRADIENT = 236,
	SWF_NAMED_COLOR_HUD_BOSS_SHIELD_BASE = 237,
	SWF_NAMED_COLOR_HUD_BOSS_SHIELD_GLOW = 238,
	SWF_NAMED_COLOR_HUD_KHAN_MAYKR_BAR_BORDER = 239,
	SWF_NAMED_COLOR_HUD_KHAN_MAYKR_BAR_GRADIENT = 240,
	SWF_NAMED_COLOR_HUD_KHAN_MAYKR_BAR_BASE = 241,
	SWF_NAMED_COLOR_HUD_DEMON_LORD_MORTAR_POI_BASE = 242,
	SWF_NAMED_COLOR_HUD_DEMON_LORD_MORTAR_POI_ARROW = 243,
	SWF_NAMED_COLOR_DOOR_LOCK_RED = 244, //! thoses door color keep color in any profile
	SWF_NAMED_COLOR_DOOR_LOCK_BLUE = 245,
	SWF_NAMED_COLOR_DOOR_LOCK_YELLOW = 246,
	SWF_NAMED_COLOR_DOOR_LOCK_GREEN = 247,
	SWF_NAMED_COLOR_INVASION_RED = 248, //? these are overwritten by us, do not use !
	SWF_NAMED_COLOR_INVASION_ORANGE = 249,
	SWF_NAMED_COLOR_INVASION_YELLOW = 250,
	SWF_NAMED_COLOR_PLAYER_BADGE_STREAK_WIN = 251,
	SWF_NAMED_COLOR_PLAYER_BADGE_STREAK_LOSS = 252,
	SWF_NAMED_COLOR_MASTER_LEVEL_LOCKED = 253,
	SWF_NAMED_COLOR_SUPPORT_RUNE_BASE = 254,
	SWF_NAMED_COLOR_SUPPORT_RUNE_GLOW = 255,
	SWF_NAMED_COLOR_SUPPORT_RUNE_STROKE = 256,
	SWF_NAMED_COLOR_SUPPORT_RUNE_SELECTION_BASE = 257,
	SWF_NAMED_COLOR_BLOOD_PUNCH_SUPERCHARGE_BASE = 258,
	SWF_NAMED_COLOR_BLOOD_PUNCH_SUPERCHARGE_GLOW = 259,
	SWF_NAMED_COLOR_CURSED_PROWLER_BASE = 260,
	SWF_NAMED_COLOR_CURSED_PROWLER_GLOW = 261,
	SWF_NAMED_COLOR_POWERUP_ONSLAUGHT = 262,
	SWF_NAMED_COLOR_POWERUP_OVERDRIVE = 263,
	SWF_NAMED_COLOR_POWERUP_BERSERK = 264,
	SWF_NAMED_COLOR_HORDE_PROGRESS_SUCCESS = 265,
	SWF_NAMED_COLOR_HORDE_PROGRESS_CURRENT = 266,
	SWF_NAMED_COLOR_HORDE_PROGRESS_LOCKED = 267,
	SWF_NAMED_COLOR_HORDE_PROGRESS_BONUS = 268,
	SWF_NAMED_COLOR_MAX = 269, //? Watch out we have 2 max colors (receipe for disaster but one max is a custom one.
	SWF_CUSTOM_NAMED_COLOR_DEFAULT = 300,
	SWF_CUSTOM_NAMED_COLOR_RED = 301,
	SWF_CUSTOM_NAMED_COLOR_GREEN = 302,
	SWF_CUSTOM_NAMED_COLOR_BLUE = 303,
	SWF_CUSTOM_NAMED_COLOR_YELLOW = 304,
	SWF_CUSTOM_NAMED_COLOR_MAGENTA = 305,
	SWF_CUSTOM_NAMED_COLOR_CYAN = 306,
	SWF_CUSTOM_NAMED_COLOR_ORANGE = 307,
	SWF_CUSTOM_NAMED_COLOR_PURPLE = 308,
	SWF_CUSTOM_NAMED_COLOR_PINK = 309,
	SWF_CUSTOM_NAMED_COLOR_BROWN = 310,
	SWF_CUSTOM_NAMED_COLOR_WHITE = 311,
	SWF_CUSTOM_NAMED_COLOR_LIGHTGREY = 312,
	SWF_CUSTOM_NAMED_COLOR_MIDGREY = 313,
	SWF_CUSTOM_NAMED_COLOR_DARKGREY = 314,
	SWF_CUSTOM_NAMED_COLOR_BLACK = 315,
	SWF_CUSTOM_NAMED_COLOR_LIGHTBLUE = 316,
	SWF_CUSTOM_NAMED_COLOR_DARKBLUE = 317,
	SWF_CUSTOM_NAMED_COLOR_LIGHTGREEN = 318,
	SWF_CUSTOM_NAMED_COLOR_DARKGREEN = 319,
	SWF_CUSTOM_NAMED_COLOR_LIGHTRED = 320,
	SWF_CUSTOM_NAMED_COLOR_LIGHTYELLOW = 321,
	SWF_CUSTOM_NAMED_COLOR_DARKPURPLE = 322,
	SWF_CUSTOM_NAMED_COLOR_LIGHTPINK = 323,
	SWF_CUSTOM_NAMED_COLOR_DARKBROWN = 324,		
	SWF_CUSTOM_NAMED_COLOR_INVISIBLE = 325

};


//enum IniFileColorId_t: int {
//	Default = 0,
//	Red = 1,
//	Green = 2,
//	Blue = 3,
//	Yellow = 4,
//	Magenta = 5,
//	Cyan = 6,
//	Orange = 7,
//	Purple = 8,
//	Pink = 9,
//	Brown = 10,
//	White = 11,
//	LtGrey = 12,
//	MdGrey = 13,
//	DkGrey = 14,
//	Black = 15,
//	LightBlue = 16,
//	DarkBlue = 17,
//	LightGreen = 18,
//	DarkGreen = 19,
//	LightRed = 20,
//	LightYellow = 21,
//	DarkPurple = 22,
//	LightPink = 23,
//	DarkBrown = 24,  // we used to have an invisible color but user might get confused why an element is not displaying anymore forgetting he set invisible in the ini file.	
//	MAX_INI_FILE_COLOR_ID
//};



namespace Reticle {

	static const float g_defaultReticleScale = 1.0f;
	static const float g_invisibleReticleScale = 0.00001f; //! not setting to absolute zero to prevent potential issues.

	//! ingame default values
	static const float defaultReticleScaleForBalistaWeapons = .72f; //? changing to 72 for debug but val should be 71
	static const float defaultReticleScaleAssaultRifleBase = .5f;
	static const float defaultReticleScaleAssaultRifleZoomed = 1.0f;

	//! DeclReticles names:
	const std::string g_weaponreticleDefault = "weaponreticle/default";
	const std::string g_weaponreticleShotgun = "weaponreticle/shotgun";
	const std::string g_weaponreticleShotgunPoprocket = "weaponreticle/shotgun_poprocket";
	const std::string g_weaponreticleShotgunFullAuto = "weaponreticle/shotgun_full_auto";
	const std::string g_weaponreticleShotgunPoprocketMastery = "weaponreticle/shotgun_poprocket_mastery";
	const std::string g_weaponreticlePlasmaRifleBase = "weaponreticle/plasma_rifle_base";
	const std::string g_weaponreticlePlasmaMicrowave = "weaponreticle/plasma_microwave";
	const std::string g_weaponreticlePistolCharged = "weaponreticle/pistol_charged";
	const std::string g_weaponreticlePlasmaRifleAoe = "weaponreticle/plasma_rifle_aoe";
	const std::string g_weaponreticleRocketLauncher = "weaponreticle/rocket_launcher";
	const std::string g_weaponreticleRocketLauncherBase = "weaponreticle/rocket_launcher_base";
	const std::string g_weaponreticleRocketLauncherLockonMod = "weaponreticle/rocket_launcher_lockon_mod";
	const std::string g_weaponreticleChaingunBase = "weaponreticle/chaingun_base";
	const std::string g_weaponreticleChaingunTurret = "weaponreticle/chaingun_turret";
	const std::string g_weaponreticleChaingunEnergyShell = "weaponreticle/chaingun_energy_shell";
	const std::string g_weaponreticleChaingunTurretMastery = "weaponreticle/chaingun_turret_mastery";
	const std::string g_weaponreticleGaussCannon = "weaponreticle/gauss_cannon";
	const std::string g_weaponreticleGaussBallista = "weaponreticle/gauss_ballista";
	const std::string g_weaponreticleGaussSiege = "weaponreticle/gauss_siege";
	const std::string g_weaponreticleBallistaDestroyerMastery = "weaponreticle/ballista_destroyer_mastery";
	const std::string g_weaponreticleAssaultRifleBase = "weaponreticle/assault_rifle_base";
	const std::string g_weaponreticleHeavyCannon = "weaponreticle/heavy_cannon";
	const std::string g_weaponreticleHeavyCannonBoltAction = "weaponreticle/heavy_cannon_bolt_action";
	const std::string g_weaponreticleHeavyCannonBoltActionZoomed = "weaponreticle/heavy_cannon_bolt_action_zoomed";
	const std::string g_weaponreticleHeavyCannonBurstDetonate = "weaponreticle/heavy_cannon_burst_detonate";
	const std::string g_weaponreticleFists = "weaponreticle/fists";
	const std::string g_weaponreticleHammer = "weaponreticle/hammer";
	const std::string g_weaponreticleUnmakyr = "weaponreticle/unmakyr";
	const std::string g_weaponreticleChainsawBase = "weaponreticle/chainsaw_base";
	const std::string g_weaponreticleBfg = "weaponreticle/bfg";
	const std::string g_weaponreticleShotgunDb = "weaponreticle/shotgun_db";
	const std::string g_weaponreticleShotgunDbMeathook = "weaponreticle/shotgun_db_meathook";
	const std::string g_weaponreticleCrucible = "weaponreticle/crucible";
	const std::string g_weaponreticleArchvile = "weaponreticle/archvile";
	const std::string g_weaponreticleMancubus = "weaponreticle/mancubus";
	const std::string g_weaponreticleMarauder = "weaponreticle/marauder";
	const std::string g_weaponreticlePainElemental = "weaponreticle/pain_elemental";
	const std::string g_weaponreticleRevenant = "weaponreticle/revenant";
	const std::string g_weaponreticleDreadknight = "weaponreticle/dreadknight";


}

//! INI FILE DEFAULT SETTINGS:

//! default idDeclWeapons vals:
namespace modSettingsDefault {


	static const bool defaultIsFirstTimeModLaunch = true;	

	static const unsigned int defaultToggleModSettingsVkCode = VK_F8;
	static const int  defaultmodSettingsShortcutTextColorImU32 = IM_COL32(255, 255, 255, 255); //white

	static const bool defaultIsUseDedicatedNadeKeys = true;

	static const bool defaultIsDisableNewCampaignPopUp = true;

	static const bool defaultIsDisableBatterySocketPopUp = true;
	static const bool defaultIsSpeedUpBatterySocketAnimation = false;

	static const bool defaultIsSkipCustomAnimations = false;

	static const bool defaultIsOverideInteractionFOV = false;
	static const float defaultInteractionFOV = 90.0f;

	static const float g_defaultShotGunStickyzoomedFOV = 80.0f;				//! offset 1700
	static const float g_defaultShotGunStickyzoomedHandsFOV = 55.0f;				//! offset 1704

	static const float g_defaultShotGunStickyControllerSens = 0.450f;	//! offset 170C
	static const float g_defaultShotGunStickyMouseSens = 0.650f;		//! offset 1710

	static const float g_defaultShotGunFullAutoZoomedFov = 82.0f;				//! offset 1700
	static const float g_defaultShotGunFullAutozoomedHandsFov = 70.0f;				//! offset 1704

	static const float g_defaultShotGunFullAutoControllerSens = 0.450f;	//! offset 170C
	static const float g_defaultShotGunFullAutoMouseSens = 0.650f;			//! offset 1710

	static const float g_defaultPrecisionBoltzoomedFOV = 45.0f;					//! offset 1700
	static const float g_defaultPrecisionBoltzoomedHandsFOV = 0.0f;					//! offset 1704

	static const float g_defaultPrecisionBoltControllerSens = 0.40f;				// offset 170C
	static const float g_defaultPrecisionBoltMouseSens = 0.50f;                		//! offset 1710

	static const float g_defaultBallistaArbalestezoomedFOV = 65.0f;					//! offset 1700
	static const float g_defaultBallistaArbalestezoomedHandsFOV = 0.0f;					//! offset 1704

	static const float g_defaultBallistaArbalesteControllerSens = 0.6f; 	//! offset 170C
	static const float g_defaultBallistaArbalesteMouseSens = 0.6f;			//! offset 1710

	static const float g_weaponMaxSensitivity = 1.0f; //! this means the sens will be the same as when using for ex plasma or RL.

	static const float g_overideShotGunzoomedFOV = 89.999f;	//! this means it use the fov from settings menu as 90 is the game default fov for many calculations. we don't set it to 90 is because otherwise it would not trigger the gun+reticule animation.
	static const float g_overideShotGunzoomedHandsFov = 0.0f;
	static const float g_overideBalistaArbalestMouseSens = 0.7f; //! personal preference
	static const bool g_defaultIsOverideShotgunConfig = true; //! should the overide shotgun be used if issue with ini file.


	static const float g_overideBalistaArbalestZoomedFOV = 89.999f;	//!  this means it use the fov from settings menu as 90 is the game default fov for many calculations. we don't set it to 90 is because otherwise it would not trigger the gun+reticule animation.
	static const float g_overideBalistaArbalestZoomedHandsFov = 0.0f;	
	static const bool g_defaultIsRemoveBalistaZoom = false;

	//! Improved Weapon Switching. Disabled by default cause it's still experimental imo.
	static const bool g_defaultIsImprovedWeaponSwitchEnabled = false; //! should the improved switching be used if issue with ini file.
	static const bool g_defaultIsImprovedWeaponSwitchBeep = false;


	//! should we reload the ini file as soon as it is saved. Update: i'm setting this to true by default cause i think many miss the feature.
	//static const bool g_defaultIsIniFileAutoReload = true;

	//! default play beep when mod succesfully levelLoaded:
	static const bool g_defaultIsSoundBeepWhenModLoaded = false;

	//! 0 means no change to HandsFOV
	static const int g_defaultHandsFOV = 0;


	static const bool g_defaultIsGameFovUnlocked = false;

	static const int g_defaultGameUISettingMinFOV = 90;
	static const int g_defaultGameUISettingMaxFOV = 120;

	static const int g_gameUISettingAllowedFOV_Min = 70;
	static const int g_gameUISettingAllowedFOV_Max = 150;

	//! crosshair
	static const int g_defaultImmersiveCrosshairLevel = 0;

	//! custom dot crosshair
	static const bool g_defaultUseImguiCustomDotCrosshair = false;
	
	static const ImU32 g_defaultCustomDotCrosshairColorImU32 = IM_COL32(255, 255, 255, 255); //white
	static const ImU32 g_defaultCustomDotCrosshairCooldownColorImU32 = IM_COL32(255, 0, 0, 255);

	static const float g_defaultimguiCustomDotCrosshairRadiusPix = 2.0f;

	static const bool g_defaultCustomDotCrosshairIsShowHealthAsColor = false;


	//! custom hud settings
	static const bool g_defaultIsUseKaibzHud = false;

	/*static const bool g_defaultKaibzHudShowInAds = false;*/

	static const float g_defaultEternalFontSize = 28.0f;

	static const float g_defaultRobotoFontSize = 28.0f;

	static const float g_defaultKaibzHudIconFontSize = 32.0f;

	static const float g_defaultKaibzHudFontSizeMin = 4.0f;
	static const float g_defaultKaibzHudFontSizeMax = 100.0f;

	static const int g_defaultHudOffsetInt = 0;

	static const uint64_t g_defaultHudFlags = 0xFFFFFFFFFFFFFFFF; //! all flags true

	static const float g_defaultIconExtraSpacingMul = 1.25f;

	static const float g_defaultIconExtraSpacingMulMin = 0.0f;
	static const float g_defaultIconExtraSpacingMulMax = 10.0f;

	static const float g_defaultKaibzHudBgOpacity = 0.25f;

	static const ImU32 g_defaultkaibzHudWhiteColorImU32 = IM_COL32(255, 255, 255, 255); // white

	static const ImU32 g_defaultkaibzHudDisabledColorImU32 = IM_COL32(90, 90, 90, 255); // dark grey
	static const ImU32 g_defaultkaibzHudCautionColorImU32 = IM_COL32(255, 255, 0, 255); // pale yellow
	static const ImU32 g_defaultkaibzHudWarningColorImU32 = IM_COL32(238, 105, 9, 255); // orange
	static const ImU32 g_defaultkaibzHudCriticalColorImU32 = IM_COL32(255, 0, 0, 255); // red
	static const ImU32 g_defaultkaibzHudExtraLivesColorImU32 = IM_COL32(152, 251, 152, 255); // pale green
	static const ImU32 g_defaultkaibzHudBloodPunch1ColorImU32 = IM_COL32(255, 165, 0, 255); // orange
	static const ImU32 g_defaultkaibzHudBloodPunch2ColorImU32 = IM_COL32(255, 0, 0, 255); // red
	static const ImU32 g_defaultkaibzHudBloodPunchDesperateColorImU32 = IM_COL32(128, 0, 128, 255); // purple
	static const ImU32 g_defaultkaibzHudHealthMaxColorImU32 = IM_COL32(255, 255, 255, 255); // white
	static const ImU32 g_defaultkaibzHudHealthColorImU32 = IM_COL32(173, 216, 230, 255); // pale blue
	static const ImU32 g_defaultkaibzHudArmorMaxColorImU32 = IM_COL32(255, 255, 255, 255); // white
	static const ImU32 g_defaultkaibzHudArmorColorImU32 = IM_COL32(152, 251, 152, 255); // pale green
	static const ImU32 g_defaultkaibzHudRadsuitColorImU32 = IM_COL32(255, 255, 0, 255); // pale yellow
	static const ImU32 g_defaultkaibzHudOxygenColorImU32 = IM_COL32(0, 0, 255, 255); // blue
	static const ImU32 g_defaultkaibzHudAmmoColorImU32 = IM_COL32(255, 255, 255, 255); // white
	static const ImU32 g_defaultkaibzHudHammerCrucibleColorImU32 = IM_COL32(255, 69, 0, 255); // orange-red
	static const ImU32 g_defaultkaibzHudFlameBelchColorImU32 = IM_COL32(255, 255, 0, 255); // yellow
	static const ImU32 g_defaultkaibzHudFuel1ColorImU32 = IM_COL32(255, 165, 0, 255); // orange
	static const ImU32 g_defaultkaibzHudFuel2ColorImU32 = IM_COL32(139, 0, 0, 255); // dark orange
	static const ImU32 g_defaultkaibzHudFuel3ColorImU32 = IM_COL32(255, 0, 0, 255); // red
	static const ImU32 g_defaultkaibzHudFrag1ColorImU32 = IM_COL32(152, 251, 152, 255); // pale green
	static const ImU32 g_defaultkaibzHudFrag2ColorImU32 = IM_COL32(0, 128, 0, 255); // green
	static const ImU32 g_defaultkaibzHudIceColorImU32 = IM_COL32(173, 216, 230, 255); // pale blue
	static const ImU32 g_defaultkaibzHudIceCooldownColorImU32 = IM_COL32(255, 0, 0, 255); // red

	

	//? i'm keeping this for doc, these colors from gpt are wrong: 
	//static const int g_defaultkaibzHudDisabledColor = 0xFF808080; // dark grey
	//static const int g_defaultkaibzHudWarningColor = 0xFF6A09EE; // orange
	//static const int g_defaultkaibzHudCriticalColor = 0xFFFF0000; // red
	//static const int g_defaultkaibzHudExtraLivesColor = 0xFF98FB98; // pale green
	//static const int g_defaultkaibzHudBloodPunch1Color = 0xFF00A5FF; // orange
	//static const int g_defaultkaibzHudBloodPunch2Color = 0xFFFF0000; // red
	//static const int g_defaultkaibzHudBloodPunchDesperateColor = 0xFF800080; // purple
	//static const int g_defaultkaibzHudHealthMaxColor = 0xFFFF00FF; // magenta
	//static const int g_defaultkaibzHudHealthColor = 0xFFADD8E6; // pale blue
	//static const int g_defaultkaibzHudArmorMaxColor = 0xFF008000; // green
	//static const int g_defaultkaibzHudArmorColor = 0xFF98FB98; // pale green
	//static const int g_defaultkaibzHudRadsuitColor = 0xFFFFFF00; // pale yellow
	//static const int g_defaultkaibzHudOxygenColor = 0xFF0000FF; // blue
	//static const int g_defaultkaibzHudAmmoColor = 0xFFFFFFFF; // white
	//static const int g_defaultkaibzHudHammerCrucibleColor = 0xFF0045FF; // orange-red
	//static const int g_defaultkaibzHudFlameBelchColor = 0xFFFFFF00; // yellow
	//static const int g_defaultkaibzHudFuel1Color = 0xFF00A5FF; // orange
	//static const int g_defaultkaibzHudFuel2Color = 0xFF8B0000; // dark orange
	//static const int g_defaultkaibzHudFuel3Color = 0xFFFF0000; // red
	//static const int g_defaultkaibzHudFrag1Color = 0xFF98FB98; // pale green
	//static const int g_defaultkaibzHudFrag2Color = 0xFF008000; // green
	//static const int g_defaultkaibzHudIceColor = 0xFFADD8E6; // pale blue





	//! game hud settings

	static const int g_defaultOverrideHudColorPackedTest = 0xFFFFA500;;

	static const int g_defaultOverrideBloodPunchColor1 = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_ORANGE;
	static const int g_defaultOverrideBloodPunchColor2 = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED;
	static const int g_defaultOverrideDesperatePunchColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_PURPLE;
	
	static const int g_defaultOverrideFuel3Pips_Color = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED;

	static const int g_defaultOverrideFragGrenadeAvailable_Color = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_GREEN;
	static const int g_defaultOverrideFragGrenadeCooldown_Color = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DARKGREY;

	static const int g_defaultOverrideIceGrenadeAvailable_Color = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;
	static const int g_defaultOverrideIceGrenadeCoolDown_Color = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DARKGREY;
	//static const int g_defaultOverrideIceGrenadeCoolDown_Color = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED;
	
	static const bool g_defaultIsWeaponBarColored = true;


	static const int g_defaultOverrideRadMeterColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_WHITE;

	
	/*static const int g_defaultOverrideDotReticleColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_WHITE;
	static const int g_defaultOverrideDotReticleCooldownColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_RED;
	static const int g_defaultOverrideDotReticleFragNadeReadyColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_GREEN;
	static const int g_defaultOverrideDotReticleIceNadeReadyColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_BLUE;
	static const int g_defaultOverrideDotReticleBothNadesReadyColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_YELLOW;*/

	static const int g_DotColorFeatureDisabledColor = (int)swfNamedColors_t::SWF_CUSTOM_NAMED_COLOR_DEFAULT;



	//! the binds above some of the hud elements
	static const bool g_defaultIsRemoveBindsReminderOnHud = true;

	//! the white effect on screen border when dashing
	static const bool g_defaultIsDashBlurEffectDisabled = false;

	static const bool g_defaultIsHitMarkerDisabled = false;


	//! other settings
	//? this is now a bool cause the DLLS anti aliasing is just a pain to handle cause of user potential graphic card 
	static const bool g_defaultIsDisableAntiAliasing = false;
	static const bool g_defaultIsDisableBloom = false;
	static const bool g_defaultIsDisableMouseSmoothing = false;
	//static const int g_defaultTextureLodBias = 0;
	static const int g_defaultDecalLifetimeMultiplier = 1;
	static const float g_defaultDesaturate = 0.0f;




	//! Gameplay settings
	//static const bool g_defaultForceRainAnywhere = false;
	//static const bool g_defaultForceSnowAnywhere = false;
	static const bool g_defaultisForceAiHaste = false;



	//! debug setting
	static const bool g_defaultisDebugMode = false;

	static const int g_userLogLevelErrorInt = 0;
	static const int g_userLogLevelWarningInt  = 1;
	static const int g_userLogLevelInfoInt = 2;
	//? only communicate this to user who have big crash issues so i can know at which point they crash. We do not let user set this mode by default because the size of log file grows VERY fast and will grow as big as the game for long sessions so it should only be used to figure out why the game crash at start or at the start of a level:
	static const int g_userHiddenLogLevelMaxVerboseInt = 666; 
	//static const int g_userMaxDebugLevelInt = 5;


	//! other settings
	static const bool g_defaulIsUseImgui = true;
	static const bool g_defaulIsLogConsoleToLogFile = false;


	//! debug settings:
	static const unsigned int g_defaultReloadImguiHooksVkCode = VK_F7;
	static const std::string g_defaultReloadImguiHooksKeyName = "F7";

	//! weapons

	const float g_scaledDownGameDotCrosshairScale = 0.0001f;
	const float g_defaultGameCrosshairScale = 1.0f;
	
	//const float g_defaultGameCrosshairScaleBallista = .75f;

	const float g_minSensValue = 0.0f;
	const float g_maxSensValue = 1.0f;

	const float g_userMinReticleScale = .2f;
	const float g_userMaxReticleScale = 2.0f;

	const int g_userMinReticleScaleIntValue = 0;
	const int g_userMaxReticleScaleIntValue = 200;

	const float g_userMaxReticleScaleFloatValue = 200.0f;

	const int g_userMaxSensIntValue = 100;


	//! Ini file:
	//! if parser fails to parse an int value it will return -1
	static const int iniFileIntNotFoundVal = -1;
	//! if parser fails to parse an bool value it will return -1
	static const int iniFileBoolNotFoundVal = -1;
	//const bool iniFileBoolNotFoundValFalse = 0;

}





//! sprites hash ids (these are the member fullPathHash in the idSWFSpriteInstance.h, they are handled in setSpriteInstanceColorHook:
//! doesn't make sens they could be negative but the field says int not unsigned int.


const int32_t unknownHudElementId = -2107815822; //! may be weaponInfo container
const int32_t weaponInfoSriteId = -938331194; //! si name: weaponInfo
const int32_t equipmentSpriteId = 929754470; //! si name: equipment

const int32_t flameBelchIconSpriteId = 183897624;
const int32_t flameBelchCoolDownFillSpriteId = 1747535555;
const int32_t flameBelchCoolDownGlowFillSpriteId = 285385424;
const int32_t flameBelchInnerFillSpriteId = 838311833;

const int32_t fuelRechargeInnerFillSpriteId = -1860842928;
const int32_t fuelIconSpriteId = 853642232;
const int32_t fuelPipFillSpriteId = 2000815950;
const int32_t fuelPipInnerFillSpriteId = 1636335086;

const int32_t fragCoolDownFillGlowSpriteId = 1569359954; //! this is the oriented rectangle structure 
const int32_t fragCoolDownInnerFillSpriteId = 1986816599; //! bg of the nade icon i believe
const int32_t fragCoolDownFillFillSpriteId = 401882437; //! not sure about this one
const int32_t fragIconSpriteId = -1683998079; //! the nade icon

/*
14:00:14.607              idPlayer.h:602   INFO| debugPrintFragNadeCoordsFromWeaponInfoV2: found display entry sprite instance: background with hash: 0xDAE74AB6 (-622376266) rect: 632.38 395.70 674.17 426.20
14:00:14.607              idPlayer.h:602   INFO| debugPrintFragNadeCoordsFromWeaponInfoV2: found display entry sprite instance: ready_flash with hash: 0x3902E1CC (956490188) rect: 504.72 224.42 504.72 224.42
14:00:14.607              idPlayer.h:602   INFO| debugPrintFragNadeCoordsFromWeaponInfoV2: found display entry sprite instance: cooldown with hash: 0x5691BEF3 (1452392179) rect: 635.94 399.52 671.92 422.91
14:00:14.607              idPlayer.h:602   INFO| debugPrintFragNadeCoordsFromWeaponInfoV2: found display entry sprite instance: icon with hash: 0xF828F801 (-131532799) rect: 643.87 405.14 660.15 417.29
14:00:14.607              idPlayer.h:602   INFO| debugPrintFragNadeCoordsFromWeaponInfoV2: found display entry sprite instance: switchedFlash with hash: 0xF4E3275 (256782965) rect: 633.29 386.82 633.29 386.82
*/

const int32_t Equipment_background_Id = 0xDAE74AB6;
const int32_t Equipment_ready_flash_Id = 0x3902E1CC;
const int32_t Equipment_cooldown_Id = 0x5691BEF3;
const int32_t Equipment_icon_Id = 0xF828F801;
const int32_t Equipment_switchedFlash_Id = 0xF4E3275;


const int32_t equipmentArrowSpriteId = -1637630621;
const int32_t equipmentBackerSpriteId = -2014894865; //! the little bar right side of the nade



const int32_t healthIconOuterSpriteId = -1170972450; 
const int32_t healthIconBgSpriteId = -108148670;
const int32_t healthTextSpriteId = -1213354124;
const int32_t healthPipsOutlineSpriteId = 331208024;
const int32_t healthPipsGradientBottomSpriteId = 602032450;
const int32_t healthPipsGradientTopSpriteId = -682387167;
const int32_t healthBottomAdornmentSpriteId = 124287208;
const int32_t healthPulseLoopSpriteId = -903599971;
const int32_t healthGlowSpriteId = -955715598;
const int32_t healthRightSideRightRightSpriteId = 1116648134;
const int32_t healthRightSideMiddleMiddleSpriteId = 113114667;
const int32_t healthRightSideAddAmountSpriteId = -1744332829;
const int32_t healthrightSideRightborderSpriteId = -1710607419;

const int32_t armorBarGradientSpriteId = -440946002;
const int32_t armorBarBaseSpriteId = -1673318065;
const int32_t armorRightSideSpriteId = 718516331;
const int32_t armorTextSpriteId = -600175609;
const int32_t armorIconSpriteId = -465741973;
const int32_t armorIconGlowSpriteId = -250485121;
const int32_t armorInfoSpriteId = -837958482;
const int32_t armorBgSpriteId = -40273562;

const int32_t weaponInfoBgModlessSpriteId = -285705630;
const int32_t weaponInfoTextSpriteId = 1997308846;
const int32_t weaponInfoAmmoIconSpriteId = -831019681;
const int32_t weaponInfoBgSpriteId = -527652115; //! this is the big bar at the bottow that we'll use as a reference for ammos text
const int32_t weaponInfoModIconId = 0x1C99E529; //! current mod icon color
//const int32_t weaponInfoModMayBe = 0xEEF87A62; 
//const int32_t weaponInfoModMayBe = 0x770C83AE;

const int32_t radSuitBarGradientSpriteId = 247756417;
const int32_t radSuitBarBaseSpriteId = -1642539358;
const int32_t radSuitRightSideSpriteId = -1695464456;
const int32_t radSuitTextSpriteId = 841051668;
const int32_t radSuitIconImgSpriteId = -1651990978;
const int32_t radSuitGlowImgSpriteId = -1436734126;
const int32_t radSuitBgSpriteId = 1400953715;
const int32_t radSuitBgPulseSpriteId = 337295309;

const int32_t bloodPunchBgPulseSpriteId = 1334139029;
const int32_t bloodPunchChargeGlowBgSpriteId = -1700059271;
const int32_t bloodPunchBgImgSpriteId = 2038383566;
const int32_t bloodPunchBorderImgSpriteId = -2114214347;
const int32_t bloodPunchIconOnSpriteId = 1200615612;
const int32_t bloodPunchIconOffSpriteId = -1614698948;
const int32_t bloodPunchReadyFlashSpriteId = 654315928;
const int32_t bloodPunchFillRightGlowSpriteId = -216838433;
const int32_t bloodPunchFillRightImgSpriteId = -6992847;
const int32_t bloodPunchFillLeftGlowSpriteId = -1035373996;
const int32_t bloodPunchFillLeftImgSpriteId = -33397220;
const int32_t bloodPunchTextSpriteId = 1430400401;
const int32_t bloodPunchBindKbmSpriteId = -370399847;
const int32_t bloodPunchBindJoySpriteId = 348013304;
const int32_t bloodPunchChargeBgSpriteId = 1938093377;
const int32_t bloodPunchImgImgSpriteId = 1656191230;
const int32_t bloodPunchBgBaseSpriteId = 2093662737;

const int32_t unidentifiedReticleId = 0xECB04FE2;





inline std::unordered_map<std::string, unsigned int> ValidKeyBindsMap = {
	{"0", 0x30},
	{"1", 0x31},
	{"2", 0x32},
	{"3", 0x33},
	{"4", 0x34},
	{"5", 0x35},
	{"6", 0x36},
	{"7", 0x37},
	{"8", 0x38},
	{"9", 0x39},
	{"A", 0x41},
	{"B", 0x42},
	{"C", 0x43},
	{"D", 0x44},
	{"E", 0x45},
	{"F", 0x46},
	{"G", 0x47},
	{"H", 0x48},
	{"I", 0x49},
	{"J", 0x4A},
	{"K", 0x4B},
	{"L", 0x4C},
	{"M", 0x4D},
	{"N", 0x4E},
	{"O", 0x4F},
	{"P", 0x50},
	{"Q", 0x51},
	{"R", 0x52},
	{"S", 0x53},
	{"T", 0x54},
	{"U", 0x55},
	{"V", 0x56},
	{"W", 0x57},
	{"X", 0x58},
	{"Y", 0x59},
	{"Z", 0x5A},
	{"F1", 0x70},
	{"F2", 0x71},
	{"F3", 0x72},
	{"F4", 0x73},
	{"F5", 0x74},
	{"F6", 0x75},
	{"F7", 0x76},
	{"F8", 0x77},
	{"F9", 0x78},
	{"F10", 0x79},
	{"F11", 0x7A},
	{"F12", 0x7B}
};







//! 0:Full  1:Dot  2:None (No Crosshair)
enum gameSettingsCrosshairMode {
	FULL = 0,
	DOT = 1,
	NONE = 2
};






enum idWeapon_chargeState_t : __int32 {
	CHARGE_STATE_NONE = 0,
	CHARGE_STATE_READY = 1,
	CHARGE_STATE_CHARGING = 2,
	CHARGE_STATE_FULLY_CHARGED = 3,
	CHARGE_STATE_DISCHARGING = 4,
	CHARGE_STATE_COOLING = 5,
	CHARGE_STATE_SUSPENDED = 6,
};



//? there are more you can get them by modifying getIdHud_Element
namespace HudElementName {
	//! using strings for id is not great but at least i'll be sure:
	static std::string Backdrop = "backdrop";
	static std::string LowWarning = "hud_lowwarning";
	static std::string DirectionalFeedback = "hud_directionalfeedback";
	static std::string HealthInfo = "hud_healthinfo";
	static std::string WeaponInfo = "hud_weaponinfo";
	static std::string HordeVictory = "hud_horde_victory";
	static std::string Reticle = "hud_reticle";
	static std::string AbilityIndicators = "hud_abilityindicators";
	static std::string SkipCinematic = "hud_skipcinematic";
	static std::string ExtraLives = "hud_extralives";
	static std::string BloodPunch = "hud_bloodpunch";
	static std::string DemonAbilityBar = "demon/hud_abilitybar";
/*
	
backdrop at addr: 0000021177AC31B0  
 hud_lowwarning at addr: 000002117388D130  
 hud_lowwarning_background at addr: 000002117388D2A0  
 hud_directionalfeedback at addr: 00000210F22A08D0  
 hud_healthinfo at addr: 00000211AED892D0  
 hud_weaponinfo at addr: 000002111E66C1C0  
 horde/hud_horde_victory at addr: 0000021177AC38B0  
 hud_reticle at addr: 00000210F56C8790  
 debug at addr: 00000210F589A510  
 hud_bossvitals at addr: 00000211785F67D0  
 hud_dash at addr: 0000021175A405E0  
 hud_bloodpunch at addr: 000002111BADDBA0  
 hud_diagnostics at addr: 00000211B371E1D0  
 hud_diagnostics_online at addr: 00000210F22A0290  
 demon/hud_healthinfo at addr: 00000211B371DB10  
 demon/hud_reticle at addr: 00000211423EC0A0  
 demon/hud_cardwheel_4wedge at addr: 00000210F5899FD0  
 hud_focusinfo at addr: 000002100193BBD0  
 hud_compass at addr: 00000211B3B826C0  
 hud_poi at addr: 00000211B371E410  
 demon/hud_abilitybar at addr: 00000211B371E650  
 pvp/hud_matchheader at addr: 00000211B40846E0  
 demon/hud_abilitybar_bottom_right at addr: 00000211785F61E0  
 hud_damagenumber at addr: 000002100193C230  
 hud_extralives at addr: 000002100193B020  
 hud_keycard at addr: 00000211785F6900  
 hud_subtitles at addr: 0000021175B7DBE0  
 hud_targetstike at addr: 00000210019398C0  
 demon/hud_timer at addr: 000002100193A9C0  
 hud_mission_challenge at addr: 00000210FC8CF930  
 hud_runeinfo at addr: 000002116D1C0F00  
 hud_timer at addr: 000002100193B130  
 pvp/hud_end_of_match at addr: 000002117388CE50  
 hud_score at addr: 00000211785F6310  
 hud_powerup at addr: 00000210F5972E60  
 hud_nameplate at addr: 000002116D1BDE10  
 demon/hud_dash at addr: 00000211785F6C90  
 hud_characterstatustext at addr: 000002100193A360  
 hud_speaker at addr: 000002100193A8B0  
 hud_skipcinematic at addr: 000002111BADD780  
 hud_tutorial_objectives at addr: 00000210F5BC3AF0  
 demon/hud_tutorial_objectives at addr: 00000210F5BC3C20  
 hud_video at addr: 00000210F22A03D0  
 pvp/hud_spectator at addr: 00000210F5BC3170  
 hud_photomodedisplay at addr: 000002100193C890  
 hud_damage_report at addr: 00000210FC859BB0  
 demon/hud_damage_report at addr: 00000210FC858440  
 hud_networkstatus at addr: 00000211B371DC30  
 hud_timeattack_timer at addr: 00000210019389E0  
 hud_textcrawl at addr: 0000021175B7DD60  
 hud_abilityindicators at addr: 00000210F5899E10  
 horde/hud_horde_score at addr: 00000210FFBA9310  
 horde/hud_horde_staged_timer at addr: 000002117388D410  
 hud_textchat at addr: 000002113A294900  
 demon/hud_textchat_demon at addr: 
	
	*/
		
}


enum class ImmersiveCrosshairLevel {
	IMMERSIVE_CROSSHAIR_LEVEL_UNKNOWN = -1,
	NO_IMMERSIVE_CROSSHAIR = 0,
	HAR_ADS, //! only displayed when ads view of Har
	HAR_ADS_BALISTA_ADS, //! only displayed in har ads and ads view of balista
	HAR_ADS_BALISTA_BOTH,	 //! only displayed in har ads and in both views of balista
	MAX_IMMERSIVE_CROSSHAIR
};


enum  class reticleStyle_t {
	RETICLE_K_STYLE_UNKNOWN = -2, 
	RETICLE_K_DEFAULT_STYLE = -1, // will use whatever style is defined for the weapon reticle
	RETICLE_STYLE_NONE = 0, // no crosshair on hud
	RETICLE_STYLE_DOT = 1,
	RETICLE_STYLE_ROCKET_LAUNCHER = 2,
	RETICLE_STYLE_SHOTGUN = 3,
	RETICLE_STYLE_SHOTGUN_STICKY_BOMBS = 4,
	RETICLE_STYLE_SHOTGUN_STICKY_BOMBS_MASTERY = 5,
	RETICLE_STYLE_SHOTGUN_FULL_AUTO = 6,
	RETICLE_STYLE_HEAVY_CANNON = 7,
	RETICLE_STYLE_HEAVY_CANNON_BOLT = 8,
	RETICLE_STYLE_DB_SHOTGUN = 9,
	RETICLE_STYLE_DB_SHOTGUN_MEATHOOK = 10,
	RETICLE_STYLE_PLASMA = 11,
	RETICLE_STYLE_PLASMA_MICROWAVE = 12,
	RETICLE_STYLE_PLASMA_AOE = 13,
	RETICLE_STYLE_PLASMA_STUN_FASTER_RECHARGE = 14,
	RETICLE_STYLE_CHAINGUN = 15,
	RETICLE_STYLE_CHAINGUN_TURRET = 16,
	RETICLE_STYLE_CHAINGUN_TURRET_NOHEAT = 17,
	RETICLE_STYLE_BALLISTA_ARBALEST = 18, //? this is arbalest hips AND ads view unfortunately 
	RETICLE_STYLE_BALLISTA_DESTROYER = 19,
	RETICLE_STYLE_BALLISTA_DESTROYER_MASTERY = 20,
	RETICLE_STYLE_CHAINSAW = 21,
	RETICLE_STYLE_ROCKET_LAUNCHER_LOCKON = 22,
	RETICLE_STYLE_BFG = 23,
	RETICLE_STYLE_CRUCIBLE = 24,
	RETICLE_STYLE_UNMAKYR = 25,
	RETICLE_STYLE_PISTOL = 26,
	RETICLE_STYLE_MP_BARON = 27,
	RETICLE_STYLE_MP_REVENANT = 28,
	RETICLE_STYLE_MP_PROWLER = 29,
	RETICLE_STYLE_MP_MANCUBUS = 30,
	RETICLE_STYLE_MP_HARVESTER = 31,
	RETICLE_STYLE_MP_CACODEMON = 32,
	RETICLE_STYLE_MP_PINKY = 33,
	RETICLE_STYLE_MP_ARCHVILE = 34,
	RETICLE_STYLE_MP_MARAUDER = 35,
	RETICLE_STYLE_MP_DREADKNIGHT = 36,
	RETICLE_STYLE_MAX = 37,
};


enum class HitMarkerState {
	ON = 0,
	OFF = 1
};


static const std::vector<unsigned char> eternalFontOffsetPatch_88 = { 0x88, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_90 = { 0x90, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_98 = { 0x98, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_A0 = { 0xA0, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_A8 = { 0xA8, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_B0 = { 0xB0, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_B8 = { 0xB8, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_C0 = { 0xC0, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_C8 = { 0xC8, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_D0 = { 0xD0, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_D8 = { 0xD8, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_E0 = { 0xE0, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_E8 = { 0xE8, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontOffsetPatch_F0 = { 0xF0, 0x00, 0x00, 0x00 };

static const std::vector<unsigned char> eternalFontDefaultOffsetPatch_F8 = { 0xF8, 0x00, 0x00, 0x00 }; //! default font 




//! ice icon draw related:

namespace hudString {
static const std::string textForidCmd = "66666666666666";
}

//namespace VarName{
//	extern  const char* idPlayer = "idPlayer";
//	extern  const char* playerHud = "playerHud";
//}


//enum idGameSystemLocalState_t : __int32 {
//	GAME_STATE_UNDEFINED_K = -0x1,
//	GAME_STATE_MAIN_MENU = 0x0,
//	GAME_STATE_LOADING = 0x1,
//	GAME_STATE_INGAME = 0x2,
//	GAME_STATE_NUM = 0x3,

//const unsigned int g_declReticleMaxCount = 37;

/*
idSWFSpriteInstance:print: Addr: 000001F741A5CC70 full path name: fill_right:glow:glow, visIndex: 56, fullPathHash: -216838433 namedColorId: 3 bounds.tl.x: 194.53 bounds.tl.y: 644.20  bounds.br.x: 194.53 bounds.br.y: 644.20





*/


