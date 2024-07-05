#pragma once

#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <unordered_set>

#include "customizedWeapon.h"
#include "GeneratedClasses.h"
#include "idResourceListManager.h"
#include "idDeclWeaponReticleManager.h"
#include "../FileOp/FileOp.h"




//! this class was more ambitious than it is now, but it was extremely frustrating to work on, so now and for now, it's just about setting a weapon fov for each weapon. In fact i'm not sure i will use this class after all...
class CustomizedWeaponManager
{
private:

	static inline std::vector<customizedWeapon> m_defaultCustomizedWeaponVec;

	static inline std::vector<customizedWeapon> m_customizedWeaponVec;

	//! used to prevent zoom on some decl weapons;
	static inline const float m_noZoom_zoomedFovvalue = 89.999f;
	//! prevents the hands from to change when no zoom
	static inline const float m_noZoom_zoomedHandsFovValue = 0.0f;

	

public:

	//! not called just init() cause it has many duplicates on VS FindAllRefs
	static void initWeapons();

	//! these will be used if user has never customized weapons or if he wants to reset one of the weapons.
	static void acquireDefaultCustomizedWeapons();


	//! if it is we should NOT put it in vec ever again
	static bool isInDefaultWeaponVec(std::string declName);


	//! should be called in initWeapons and when out of mod menu
	static void applySettingsToDeclWeapons();

	static bool applyToDecl(idDeclWeapon* declWeap);

	//! this should be triggered when user presses reset on a weapon in ui
	static void resetWeapon(std::string weaponName);


	static customizedWeapon* getDefaultCustomWeaponPtrByName(std::string declName);

	static customizedWeapon* getCustomWeaponPtrByName(std::string declName);
	
	static std::vector<customizedWeapon*>  getSortedCustomWeaponRefsForGroup(customizedWeaponGroupID groupID);

	//! for imgui
	//static std::vector<customizedWeapon> getCustomWeaponVecCpy();
	
	//! when out of imgui we want the modified custom weapons
	//static void setCustomWeaponVecCpy(std::vector<customizedWeapon> custWeaponsVec);

	//static std::vector<customizedWeapon> getDefaultCustomWeaponVecCpy();
	//! don't need this one in theory:
	/*static void setCustomWeaponVecCpy(std::vector<customizedWeapon> custWeaponsVec);*/

	//static std::vector<customizedWeapon*> getSortedCustomWeaponRefsForGroup(customizedWeaponGroupID groupID);


	//static customizedWeaponGroupID getCustomizedWeaponGroupID(std::string declWeaponNameStr);

	static bool loadCustomWeaponsFromFile();

	static void saveCustomWeaponsToFile();

	static std::string getWeaponCategoryString(idDeclWeapon_weaponCategory_t weaponCategory);


	static void debugLogWeaponsVals();


	//! we need the default config of a decl if user want to restore any/all of its settings to default
	/*static bool isDefaultSaved(idDeclWeapon* declWeapon);
	static void saveDefault(idDeclWeapon* declWeapon);*/

	//static customizedWeapon getDefaultShotgun();
	//static customizedWeapon getDefaultHeavyCannon();
	//static customizedWeapon getDefaultPlasma();
	//static customizedWeapon getDefaultRL();
	//static customizedWeapon getDefaultSuperShotgun();
	//static customizedWeapon getDefaultBalista();
	//static customizedWeapon getDefaultChaingun();
	//static customizedWeapon getDefaultUnmayKr();
	//static customizedWeapon getDefaultCrucible();
	//static customizedWeapon getDefaultHammer();

};

