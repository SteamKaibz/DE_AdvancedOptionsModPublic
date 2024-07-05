#include "customizedWeapon.h"




customizedWeapon::customizedWeapon(std::string weaponName)
    : name(weaponName) {   

    if (name == "weapon/player/shotgun") {
        groupId = customizedWeaponGroupID::SHOTGUN;
        order = 0;
    }
    else if (name == "weapon/player/shotgun_secondary_pop_rockets") {
        groupId = customizedWeaponGroupID::SHOTGUN;
        order = 1;
    }
    else if (name == "weapon/player/shotgun_secondary_pop_rockets_mastery") {
        groupId = customizedWeaponGroupID::SHOTGUN;
        order = 2;
    }
    else if (name == "weapon/player/shotgun_secondary_full_auto") {
        groupId = customizedWeaponGroupID::SHOTGUN;
        order = 3;
    }
    else if (name == "weapon/player/heavy_cannon") {
        groupId = customizedWeaponGroupID::HEAVY_CANNON;
        order = 0;
    }
    else if (name == "weapon/player/heavy_cannon_bolt_action") {
        groupId = customizedWeaponGroupID::HEAVY_CANNON;
        order = 1;
    }
    else if (name == "weapon/player/heavy_cannon_burst_detonate") {
        groupId = customizedWeaponGroupID::HEAVY_CANNON;
        order = 2;
    }
    else if (name == "weapon/player/heavy_cannon_burst_detonate_faster_recharge") {
        groupId = customizedWeaponGroupID::HEAVY_CANNON;
        order = 3;
    }
    else if (name == "weapon/player/heavy_cannon_burst_detonate_mastery") {
        groupId = customizedWeaponGroupID::HEAVY_CANNON;
        order = 4;
    }
    else if (name == "weapon/player/plasma_rifle") {
        groupId = customizedWeaponGroupID::PLASMA;
        order = 0;
    }
    else if (name == "weapon/player/plasma_rifle_secondary_aoe") {
        groupId = customizedWeaponGroupID::PLASMA;
        order = 1;
    }
    else if (name == "weapon/player/plasma_rifle_secondary_aoe_mastery_primary_supercharge") {
        groupId = customizedWeaponGroupID::PLASMA;
        order = 2;
    }
    else if (name == "weapon/player/plasma_rifle_secondary_microwave") {
        groupId = customizedWeaponGroupID::PLASMA;
        order = 3;
    }
    else if (name == "weapon/player/rocket_launcher") {
        groupId = customizedWeaponGroupID::ROCKET_LAUNCHER;
        order = 0;
    }
    else if (name == "weapon/player/rocket_launcher_detonate") {
        groupId = customizedWeaponGroupID::ROCKET_LAUNCHER;
        order = 1;
    }
    else if (name == "weapon/player/rocket_launcher_lock_mod") {
        groupId = customizedWeaponGroupID::ROCKET_LAUNCHER;
        order = 2;
    }
    else if (name == "weapon/player/rocket_launcher_lock_mod_mastery") {
        groupId = customizedWeaponGroupID::ROCKET_LAUNCHER;
        order = 3;
    }
    else if (name == "weapon/player/gauss_rifle") {
        groupId = customizedWeaponGroupID::BALISTA;
        order = 0;
    }
    else if (name == "weapon/player/gauss_rifle_ballista") {
        groupId = customizedWeaponGroupID::BALISTA;
        order = 1;
    }
    else if (name == "weapon/player/gauss_rifle_destroyer") {
        groupId = customizedWeaponGroupID::BALISTA;
        order = 2;
    }
    else if (name == "weapon/player/double_barrel") {
        groupId = customizedWeaponGroupID::DOUBLE_BARREL;
        order = 0;
    }
    else if (name == "weapon/player/double_barrel_meat_hook") {
        groupId = customizedWeaponGroupID::DOUBLE_BARREL;
        order = 1;
    }
    else if (name == "weapon/player/double_barrel_primary_lockon") {
        groupId = customizedWeaponGroupID::DOUBLE_BARREL;
        order = 2;
    }
    else if (name == "weapon/player/chaingun") {
        groupId = customizedWeaponGroupID::CHAINGUN;
        order = 0;
    }
    else if (name == "weapon/player/chaingun_turret_primary") {
        groupId = customizedWeaponGroupID::CHAINGUN;
        order = 1;
    }
    else if (name == "weapon/player/chaingun_turret_secondary") {
        groupId = customizedWeaponGroupID::CHAINGUN;
        order = 2;
    }
    else if (name == "weapon/player/chaingun_energy_shell_primary") {
        groupId = customizedWeaponGroupID::CHAINGUN;
        order = 3;
    }
    //? there are many more bfg versions but....later....
    else if (name == "weapon/player/bfg") {
        groupId = customizedWeaponGroupID::BFG;
        order = 0;
    }
    else if (name == "weapon/player/unmaykr") {
        groupId = customizedWeaponGroupID::UNMAYKR;
        order = 0;
    }
    else if (name == "weapon/player/crucible") {
        groupId = customizedWeaponGroupID::CRUCIBLE;
        order = 0;
    }
    else if (name == "weapon/player/hammer") {
        groupId = customizedWeaponGroupID::HAMMER;
        order = 0;
    }
    else if (name == "weapon/player/hammer_slam") {
        groupId = customizedWeaponGroupID::HAMMER;
        order = 1;
    }
    else if (name == "weapon/player/hammer_horde") {
        groupId = customizedWeaponGroupID::HAMMER;
        order = 2;
    }
    //? obviously if we get here it's a problem, but at least we would see it in the weapon mod gui
    else {
        name = "XXXXXXXX";
        groupId = customizedWeaponGroupID::SHOTGUN;
        order = 0;
    }
    
}