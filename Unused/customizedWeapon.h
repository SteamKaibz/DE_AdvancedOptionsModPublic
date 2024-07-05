#pragma once
#include "GeneratedEnums.h"
#include <string>
#include <vector>



//? i think i'm just going to remove this feature it's just so convulted, so complex as so many systems interact with each others and just EXTREMELY ANNOYING to the point i want to stop working on this so...we'll just use the older system and if someday we want to torture ourself we can come back to it.
class customizedWeapon {
	

private:

	

public:
	
	//! the actual name of the decl like: weapon/player/shotgun_secondary_pop_rockets
	std::string name = "";

	//customizedWeaponID id = customizedWeaponID::UNKNOWN;
	//! this is used to identify if the decl is part of the same weapon so we can make sure that handsFOV is the same for all each decl that belongs to this group in the mod menu.
	customizedWeaponGroupID groupId = customizedWeaponGroupID::MAX_GROUP_ID;

	//! this is used to order the weapon in the weapon mod menu
	int order = 0;	

	//? only this value in the base player weapon (like weapon/player/shotgun) modify the actual 'weapon fov'
	float handsFovScale = 0; 

	//! this is to be used by ui
	bool isRemoveZoom = false;

	//! those should be mostly untouched for most weapons aside balista and shotgun as user may know not understand how to configure them right. instead we should have tick box like remove shotgun zoom, remove balista zoom...
	float zoomedHandsFOV = 0;
	float zoomedFOV = 0;

	bool isRemoveLoweredSens = false;
	//! sens when using the mod version of the weapon (like the prop rocket for shotgun)
	//? those are muls meaning 1.0 will be the same as non ads sens.	
	float mouseADSSensScale = 0;
	float controllerADSSensSclae = 0;

	bool isDotReticleShowCoolDown = false;

	
	
	customizedWeapon()
	{
	}

	customizedWeapon(std::string weaponName);

	// Assignment operator overload
	customizedWeapon& operator=(const customizedWeapon& other) {
		if (this != &other) { // Check for self-assignment
			// Copy values from 'other' to 'this'
			this->name = other.name;
			this->groupId = other.groupId;
			this->order = other.order;
			this->handsFovScale = other.handsFovScale;
			this->isRemoveZoom = other.isRemoveZoom;
			this->zoomedHandsFOV = other.zoomedHandsFOV;
			this->zoomedFOV = other.zoomedFOV;
			this->mouseADSSensScale = other.mouseADSSensScale;
			this->controllerADSSensSclae = other.controllerADSSensSclae;
			this->isDotReticleShowCoolDown = other.isDotReticleShowCoolDown;		
		}
		return *this;
	}

};






