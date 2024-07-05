#pragma once
#include "../Config/Config.h"

//! -1 should mean not owned as 0 could be the current count of item like 0 ammo should not mean we don't own the ammo.
class PlayerInventory {
private:
	static inline int m_Shotgun = 0;
	static inline int m_HeavyCannon = 0;
	static inline int m_PlasmaRifle = 0;
	static inline int m_RocketLauncher = 0;
	static inline int m_SuperShotgun = 0;
	static inline int m_Ballista = 0;
	static inline int m_MiniGun = 0;
	static inline int m_Bfg = 0;
	static inline int m_Unmaykr = 0;
	static inline int m_Crucible = 0;
	static inline int m_Hammer = 0;
	static inline int m_ShellAmmo = 0;
	static inline int m_BulletAmmo = 0;
	static inline int m_CellAmmo = 0;
	static inline int m_RocketAmmo = 0;
	static inline int m_BfgAmmo = 0;
	static inline int m_FuelAmmo = 0;
	static inline int m_FragGrenadeEquipment = 0;
	static inline int m_IceBombEquipment = 0;

public:
	// Getter methods
	int IsShotgun() const;
	int IsHeavyCannon() const;
	int IsPlasmaRifle() const;
	int IsRocketLauncher() const;
	int IsSuperShotgun() const;
	int IsBallista() const;
	int IsMiniGun() const;
	int IsBfg() const;
	int IsUnmaykr() const;
	int IsCrucible() const;
	int IsHammer() const;
	int IsShellAmmo() const;
	int IsBulletAmmo() const;
	int IsCellAmmo() const;
	int IsRocketAmmo() const;
	int IsBfgAmmo() const;
	int IsFuelAmmo() const;
	int IsFragGrenadeEquipment() const;
	int IsIceBombEquipment() const;

	// Setter methods
	void SetShotgun(int value);
	void SetHeavyCannon(int value);
	void SetPlasmaRifle(int value);
	void SetRocketLauncher(int value);
	void SetSuperShotgun(int value);
	void SetBallista(int value);
	void SetMiniGun(int value);
	void SetBfg(int value);
	void SetUnmaykr(int value);
	void SetCrucible(int value);
	void SetHammer(int value);
	void SetShellAmmo(int value);
	void SetBulletAmmo(int value);
	void SetCellAmmo(int value);
	void SetRocketAmmo(int value);
	void SetBfgAmmo(int value);
	void SetFuelAmmo(int value);
	void SetFragGrenadeEquipment(int value);
	void SetIceBombEquipment(int value);

	bool isWeaponOwned(int weaponIndex);

	void ResetAmmoInventory();

	void PrintAmmoInventory() const;
};


//class PlayerInventory {
//
//public:
//
//	int Shotgun = 0;
//	int HeavyCannon = 0;
//	int PlasmaRifle = 0;
//	int RocketLauncher = 0;
//	int SuperShotgun = 0;
//	int Ballista = 0;
//	int MiniGun = 0;
//	int Bfg = 0;
//	int Unmaykr = 0;
//	int Crucible = 0;
//	int Hammer = 0;
//	int ShellAmmo = 0;
//	int BulletAmmo = 0;
//	int CellAmmo = 0;
//	int RocketAmmo = 0;
//	int BfgAmmo = 0;
//	int FuelAmmo = 0;
//	int FragGrenade = 0;
//	int IceBomb = 0;
//
//
//	void reset() {
//		Shotgun = 0;
//		HeavyCannon = 0;
//		PlasmaRifle = 0;
//		RocketLauncher = 0;
//		SuperShotgun = 0;
//		Ballista = 0;
//		MiniGun = 0;
//		Bfg = 0;
//		Unmaykr = 0;
//		Crucible = 0;
//		Hammer = 0;
//		ShellAmmo = 0;
//		BulletAmmo = 0;
//		CellAmmo = 0;
//		RocketAmmo = 0;
//		BfgAmmo = 0;
//		FuelAmmo = 0;
//		FragGrenade = 0;
//		IceBomb = 0;
//	}
//
//
//	//? this does not handle all the weapons, on purpose but still.
//	bool isWeaponOwned(int weaponIndex) {
//		switch (weaponIndex) {
//		case 1:
//			return m_Shotgun > 0;
//		case 2:
//			return m_HeavyCannon > 0;
//		case 3:
//			return m_PlasmaRifle > 0;
//		case 4:
//			return m_RocketLauncher > 0;
//		case 5:
//			return m_SuperShotgun > 0;
//		case 6:
//			return m_Ballista > 0;
//		case 7:
//			return m_MiniGun > 0;
//		default:
//			return false;
//			break;
//		}
//	}
//
//	void debugPrint() {
//		logInfo("Player Weapons and Ammo Inventory debugPrint: ");
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
//		logInfo("ShellAmmo: %d ", ShellAmmo);
//		logInfo("BulletAmmo: %d ", BulletAmmo);
//		logInfo("CellAmmo: %d ", CellAmmo);
//		logInfo("RocketAmmo: %d ", RocketAmmo);
//		logInfo("BfgAmmo: %d ", BfgAmmo);
//		logInfo("FuelAmmo: %d ", FuelAmmo);
//	}
//
//
//};
