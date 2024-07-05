//#pragma once
//
///// <summary>
///// if a weapon has ammo -1 it means the gun is not owned by the player.
///// </summary>
//class PlayerInventory {
//
//public:
//	int Fists = -1;
//	int BerserkFists = -1;
//	int Doom5MeleeFists = -1;
//	int SwimFists = -1;
//	int PointingArm = -1;	 //! don't know what that is
//	int DoomBlade = -1;	 //! don't know what that is
//	int Shotgun = -1;
//	int HeavyCannon = -1;
//	int PlasmaRifle = -1;
//	int RocketLauncher = -1;
//	int SuperShotgun = -1;
//	int Ballista = -1;
//	int MiniGun = -1;
//	int Bfg = -1;
//	int Unmaykr = -1;
//	int Crucible = -1;
//	int Hammer = -1;
//	int LeftEquipementLauncher = -1; //! not useful but we take it anyway
//	int ChainsawEquipement = -1;
//	int FragGrenade = -1;
//	int IceGrenadeEquipment = -1;
//	int FlameBelch = -1;
//	int ExtraLife = -1;
//	int DashAbility = -1;
//	int BloodPunchAbility = -1;
//	int EnvironmentSuit = -1;
//	int RadSuit = -1; //! anti radiation suit, when its armor get to 0 it stays in the inventory.
//	int OxygentSuit = -1;
//	int GrappleGloves = -1;
//	int FistsAmmo = -1;
//	int ShellAmmo = -1;
//	int BulletAmmo = -1;
//	int CellAmmo = -1;
//	int RocketAmmo = -1;
//	int BfgAmmo = -1;
//	int CrucibleAmmo = -1;
//	int HammerAmmo = -1;
//	int FluelAmmo = -1;
//	int DoomBladeAmmo = -1; //! afaik this is not used by the game
//	int RevenantModifier = -1;
//	int JumpBoots = -1;
//
//
//	bool isWeaponOwned(int weaponIndex) {
//		switch (weaponIndex) {
//		case 1:
//			return Shotgun > 0;
//		case 2:
//			return HeavyCannon > 0;
//		case 3:
//			return PlasmaRifle > 0;
//		case 4:
//			return RocketLauncher > 0;
//		case 5:
//			return SuperShotgun > 0;
//		case 6:
//			return Ballista > 0;
//		case 7:
//			return MiniGun > 0;
//		default:
//			return false;
//			break;
//		}
//	}
//
//	void debugPrint() {
//		logInfo("PlayerInventory debugPrint: ");
//		logInfo("Fists: %d ", Fists);
//		logInfo("BerserkFists: %d ", BerserkFists);
//		logInfo("Doom5MeleeFists: %d ", Doom5MeleeFists);
//		logInfo("SwimFists: %d ", SwimFists);
//		logInfo("PointingArm: %d ", PointingArm);
//		logInfo("DoomBlade: %d ", DoomBlade);
//		logInfo("Shotgun: %d ", Shotgun);
//		logInfo("HeavyCannon: %d ", HeavyCannon);
//		logInfo("PlasmaRifle: %d ", PlasmaRifle);
//		logInfo("RocketLauncher: %d ", RocketLauncher);
//		logInfo("SuperShotgun: %d ", SuperShotgun);
//		logInfo("Ballista: %d ", Ballista);
//		logInfo("MiniGun: %d ", MiniGun);
//		logInfo("Unmaykr: %d ", Unmaykr);
//		logInfo("Crucible: %d ", Crucible);
//		logInfo("Hammer: %d ", Hammer);
//		logInfo("LeftEquipementLauncher: %d ", LeftEquipementLauncher);
//		logInfo("ChainsawEquipement: %d ", ChainsawEquipement);
//		logInfo("FragGrenade: %d ", FragGrenade);
//		logInfo("IceGrenadeEquipment: %d ", IceGrenadeEquipment);
//		logInfo("FlameBelch: %d ", FlameBelch);
//		logInfo("ExtraLife: %d ", ExtraLife);
//		logInfo("DashAbility: %d ", DashAbility);
//		logInfo("BloodPunchAbility: %d ", BloodPunchAbility);
//		logInfo("EnvironmentSuit: %d ", EnvironmentSuit);
//		logInfo("RadSuit: %d ", RadSuit);
//		logInfo("OxygentSuit: %d ", OxygentSuit);
//		logInfo("GrappleGloves: %d ", GrappleGloves);
//		logInfo("FistsAmmo: %d ", FistsAmmo);
//		logInfo("ShellAmmo: %d ", ShellAmmo);
//		logInfo("BulletAmmo: %d ", BulletAmmo);
//		logInfo("CellAmmo: %d ", CellAmmo);
//		logInfo("RocketAmmo: %d ", RocketAmmo);
//		logInfo("BfgAmmo: %d ", BfgAmmo);
//		logInfo("CrucibleAmmo: %d ", CrucibleAmmo);
//		logInfo("HammerAmmo: %d ", HammerAmmo);
//		logInfo("FluelAmmo: %d ", FluelAmmo);
//		logInfo("DoomBladeAmmo: %d ", DoomBladeAmmo);
//		logInfo("RevenantModifier: %d ", RevenantModifier);
//		logInfo("JumpBoots: %d ", JumpBoots);
//
//	}
//
//
//};
