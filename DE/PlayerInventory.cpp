#include "PlayerInventory.h"

// Getter methods

 int PlayerInventory::IsShotgun() const { return m_Shotgun; }

 int PlayerInventory::IsHeavyCannon() const { return m_HeavyCannon; }

 int PlayerInventory::IsPlasmaRifle() const { return m_PlasmaRifle; }

 int PlayerInventory::IsRocketLauncher() const { return m_RocketLauncher; }

 int PlayerInventory::IsSuperShotgun() const { return m_SuperShotgun; }

 int PlayerInventory::IsBallista() const { return m_Ballista; }

 int PlayerInventory::IsMiniGun() const { return m_MiniGun; }

 int PlayerInventory::IsBfg() const { return m_Bfg; }

 int PlayerInventory::IsUnmaykr() const { return m_Unmaykr; }

 int PlayerInventory::IsCrucible() const { return m_Crucible; }

 int PlayerInventory::IsHammer() const { return m_Hammer; }

 int PlayerInventory::IsShellAmmo() const { return m_ShellAmmo; }

 int PlayerInventory::IsBulletAmmo() const { return m_BulletAmmo; }

 int PlayerInventory::IsCellAmmo() const { return m_CellAmmo; }

 int PlayerInventory::IsRocketAmmo() const { return m_RocketAmmo; }

 int PlayerInventory::IsBfgAmmo() const { return m_BfgAmmo; }

 int PlayerInventory::IsFuelAmmo() const { return m_FuelAmmo; }

 int PlayerInventory::IsFragGrenadeEquipment() const { return m_FragGrenadeEquipment; }

 int PlayerInventory::IsIceBombEquipment() const { return m_IceBombEquipment; }

// Setter methods

 void PlayerInventory::SetShotgun(int value) { m_Shotgun = value; }

 void PlayerInventory::SetHeavyCannon(int value) { m_HeavyCannon = value; }

 void PlayerInventory::SetPlasmaRifle(int value) { m_PlasmaRifle = value; }

 void PlayerInventory::SetRocketLauncher(int value) { m_RocketLauncher = value; }

 void PlayerInventory::SetSuperShotgun(int value) { m_SuperShotgun = value; }

 void PlayerInventory::SetBallista(int value) { m_Ballista = value; }

 void PlayerInventory::SetMiniGun(int value) { m_MiniGun = value; }

 void PlayerInventory::SetBfg(int value) { m_Bfg = value; }

 void PlayerInventory::SetUnmaykr(int value) { m_Unmaykr = value; }

 void PlayerInventory::SetCrucible(int value) { m_Crucible = value; }

 void PlayerInventory::SetHammer(int value) { m_Hammer = value; }

 void PlayerInventory::SetShellAmmo(int value) { m_ShellAmmo = value; }

 void PlayerInventory::SetBulletAmmo(int value) { m_BulletAmmo = value; }

 void PlayerInventory::SetCellAmmo(int value) { m_CellAmmo = value; }

 void PlayerInventory::SetRocketAmmo(int value) { m_RocketAmmo = value; }

 void PlayerInventory::SetBfgAmmo(int value) { m_BfgAmmo = value; }

 void PlayerInventory::SetFuelAmmo(int value) { m_FuelAmmo = value; }

 void PlayerInventory::SetFragGrenadeEquipment(int value) { m_FragGrenadeEquipment = value; }

 void PlayerInventory::SetIceBombEquipment(int value) { m_IceBombEquipment = value; }

 bool PlayerInventory::isWeaponOwned(int weaponIndex) {
	switch (weaponIndex) {
	case 1:
		return m_Shotgun > 0;
	case 2:
		return m_HeavyCannon > 0;
	case 3:
		return m_PlasmaRifle > 0;
	case 4:
		return m_RocketLauncher > 0;
	case 5:
		return m_SuperShotgun > 0;
	case 6:
		return m_Ballista > 0;
	case 7:
		return m_MiniGun > 0;
	default:
		return false;
		break;
	}
}

 void PlayerInventory::ResetAmmoInventory() {
	m_Shotgun = 0;
	m_HeavyCannon = 0;
	m_PlasmaRifle = 0;
	m_RocketLauncher = 0;
	m_SuperShotgun = 0;
	m_Ballista = 0;
	m_MiniGun = 0;
	m_Bfg = 0;
	m_Unmaykr = 0;
	m_Crucible = 0;
	m_Hammer = 0;
	m_ShellAmmo = 0;
	m_BulletAmmo = 0;
	m_CellAmmo = 0;
	m_RocketAmmo = 0;
	m_BfgAmmo = 0;
	m_FuelAmmo = 0;
	m_FragGrenadeEquipment = 0;
	m_IceBombEquipment = 0;
}

 void PlayerInventory::PrintAmmoInventory() const {
	logInfo("PlayerInventory Print:");
	logInfo("Shotgun: %d", m_Shotgun);
	logInfo("HeavyCannon: %d", m_HeavyCannon);
	logInfo("PlasmaRifle: %d", m_PlasmaRifle);
	logInfo("RocketLauncher: %d", m_RocketLauncher);
	logInfo("SuperShotgun: %d", m_SuperShotgun);
	logInfo("Ballista: %d", m_Ballista);
	logInfo("MiniGun: %d", m_MiniGun);
	logInfo("Bfg: %d", m_Bfg);
	logInfo("Unmaykr: %d", m_Unmaykr);
	logInfo("Crucible: %d", m_Crucible);
	logInfo("Hammer: %d", m_Hammer);
	logInfo("ShellAmmo: %d", m_ShellAmmo);
	logInfo("BulletAmmo: %d", m_BulletAmmo);
	logInfo("CellAmmo: %d", m_CellAmmo);
	logInfo("RocketAmmo: %d", m_RocketAmmo);
	logInfo("BfgAmmo: %d", m_BfgAmmo);
	logInfo("FuelAmmo: %d", m_FuelAmmo);
	logInfo("FragGrenade: %d", m_FragGrenadeEquipment);
	logInfo("IceBomb: %d", m_IceBombEquipment);
}
