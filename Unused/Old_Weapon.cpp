//#include "Weapon.h"

//void Weapon::computeIndexFromId(unsigned int weaponId)
//{
//	//7113 (shotgun) 8562(ar), 7404 (plasma), ssg(22668), rl(7732), bfg(20817), unmaker(11052), minigun(7982), ballista(8300), sword(23691), Hammer(10464).
//
//	if (weaponId == WeaponId::shotgun) {
//		m_weaponIndex =  1;
//	}
//	else if (weaponId == WeaponId::assaultRifle) {
//		m_weaponIndex = 2;
//	}
//	else if (weaponId == WeaponId::plasma) {
//		m_weaponIndex = 3;
//	}
//	else if (weaponId == WeaponId::rocketLauncher) {
//		m_weaponIndex = 4;
//	}
//	else if (weaponId == WeaponId::superShotgun) {
//		m_weaponIndex = 5;
//	}
//	else if (weaponId == WeaponId::ballista) {
//		m_weaponIndex = 6;
//	}
//	else if (weaponId == WeaponId::miniGun) {
//		m_weaponIndex = 7;
//	}
//	//! we don't handly bfg cause of the toggle key.
//	/*else if (weaponId == WeaponId::bfg)
//		m_weaponIndex = 8;
//	}*/
//	else {
//		m_weaponIndex = notMonitoredWeapon;
//	}
//	
//
//
//}
//
//int Weapon::getIndex()
//{
//	return m_weaponIndex;
//		
//}
//
//unsigned int Weapon::getId()
//{
//	return m_id;
//}
//
//bool Weapon::isValid()
//{
//	return m_weaponIndex != notMonitoredWeapon;
//}
