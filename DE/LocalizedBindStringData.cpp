#include "LocalizedBindStringData.h"

 std::u8string& LocalizedBindStringData::getEquipmentLauncherOverwriteStr() {
	logDebug("getEquipmentLauncherOverwriteStr");
	return m_equipmentLauncherOverwriteStr;
}

 std::u8string& LocalizedBindStringData::getSwitchEquipmentOverwriteStr() {
	logDebug("getSwitchEquipmentOverwriteStr");
	return m_switchEquipmentOverwriteStr;
}
