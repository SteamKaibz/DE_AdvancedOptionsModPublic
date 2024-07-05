#include "BindLabelChanger.h"

bool BindLabelChanger::acquirreIdStringBigListOffset(int offset) {
    logDebug("acquirreIdStringBigListOffset");

    if (offset <= 0) { // < cause neg offset would be out of game memory for sure
        logWarn("acquirreIdStringBigListOffset: idStringBigListOffset <= 0, setting m_idStringBigListAddr to 0 so it triggers bad ptr ");
        return false;
        //m_idStringBigListAddr = 0;
    }
    else {
        m_idStringBigAddrStart = MemHelper::getModuleBaseAddr() + offset;
        logInfo("acquirreIdStringBigListOffset: m_idStringBigAddrStart: %p", (void*)m_idStringBigAddrStart);
        if (!MemHelper::isBadReadPtr((void*)m_idStringBigAddrStart)) {
            return true;
        }
    }
    return false;
}

void BindLabelChanger::overwriteDynamicBindLabels(unsigned char* strPtr, LocalizedBindStringData localizedOverwriteData) {
    logDebug("overwriteDynamicBindLabels");

    try
    {
        std::string str(reinterpret_cast<char const*>(strPtr));
        if (m_isEquipmentLauncherFlag && str != EquipmentLauncherControllerFlagStr) {
            std::string replacementStrFormatedForCopy(localizedOverwriteData.getEquipmentLauncherOverwriteStr().cbegin(), localizedOverwriteData.getEquipmentLauncherOverwriteStr().cend());
            strcpy((char*)strPtr, replacementStrFormatedForCopy.c_str());
            m_isEquipmentLauncherFlag = false;
        }
        else if (m_isSwitchEquipmentFlag && str != SwitchEquipmentControllerFlagStr) {
            std::string replacementStrFormatedForCopy(localizedOverwriteData.getSwitchEquipmentOverwriteStr().cbegin(), localizedOverwriteData.getSwitchEquipmentOverwriteStr().cend());
            strcpy((char*)strPtr, replacementStrFormatedForCopy.c_str());
            m_isSwitchEquipmentFlag = false;
        }
        else if (str == EquipmentLauncherFlagStr) {
            m_isEquipmentLauncherFlag = true;
        }
        else if (str == SwitchEquipmentFlagStr) {
            m_isSwitchEquipmentFlag = true;
        }
    }
    catch (const std::exception& ex)
    {
        logErr("overwriteDynamicBindLabels: exception error: %s (resetting flags)", ex.what());
        m_isEquipmentLauncherFlag = false;
        m_isSwitchEquipmentFlag = false;
    }
}

bool BindLabelChanger::isControllerStaticStringsOverwriteAttempt() {
    logDebug("isControllerStaticStringsOverwriteAttempt");
    return m_isOverwriteControllerBindStrAttempt;
}

BindLabelChanger::BindLabelChanger()
{
    createControllerLayoutsVec();
}



void BindLabelChanger::overwriteControllerLabels(LocalizedBindStringData localizedOverwriteData) {
    logDebug("overwriteControllerLabels");

    if (MemHelper::isBadReadPtr((void*)m_idStringBigAddrStart)) {
        logErr("overwriteControllerLabels: found bad ptr for addr: %p can not overwrite controller labels strings.", (void*)m_idStringBigAddrStart);
        return;
    }

    logInfo("overwriteControllerLabels:  m_idStringBigAddrStart: %p. Attempting to Overwrite Bind labels...", (void*)m_idStringBigAddrStart);
    for (size_t i = 0; i < m_controllerLayouts.size(); i++)
    {
        uintptr_t idStrAddr = *(uintptr_t*)(m_idStringBigAddrStart + m_controllerLayouts[i].getControllerLayoutOffset());
        if (MemHelper::isBadReadPtr((void*)idStrAddr)) {
            logErr("overwriteControllerLabels: found bad ptr for idStrAddr: %p can not overwrite bind strings for controller layout: %s", (void*)idStrAddr, m_controllerLayouts[i].getLayoutName().c_str());
            continue;
        }
        m_controllerLayouts[i].overwriteBindLabels(localizedOverwriteData, m_idStringBigAddrStart);
    }

    m_isOverwriteControllerBindStrAttempt = true;
}

void BindLabelChanger::createControllerLayoutsVec() {
    logDebug("createControllerLayoutsVec");

    m_controllerLayouts.clear(); //! not necessary, just safety in case it's called twice.
    m_controllerLayouts.push_back(ControllerLayout("Default", 0, 0xC8, 0x308));
    m_controllerLayouts.push_back(ControllerLayout("Classic", 0x18, 0xF8, 0x308));
    m_controllerLayouts.push_back(ControllerLayout("Knucles", 0x30, 0xC8, 0x308));
    m_controllerLayouts.push_back(ControllerLayout("Mirrored", 0x48, 0xF8, 0x308));
    m_controllerLayouts.push_back(ControllerLayout("Strafe", 0x60, 0xF8, 0x308));
    m_controllerLayouts.push_back(ControllerLayout("Tactical", 0x78, 0x158, 0x308));
}
