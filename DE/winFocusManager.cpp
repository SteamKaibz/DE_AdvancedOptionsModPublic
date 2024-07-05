#include "winFocusManager.h"

bool winFocusManager::acquireWin32Vars(__int64 addr)
{
    if (MemHelper::isBadReadPtr((void*)addr)) {
        logErr("acquireWin32Vars: failed to get Win32Vars, bad ptr: %p", (void*)addr);
        m_Win32Vars_t = nullptr;
        return false;
    }

    m_Win32Vars_t = (Win32Vars_t*)*(__int64*)addr;
    if (MemHelper::isBadReadPtr(m_Win32Vars_t)) {
        logErr("acquireWin32Vars: m_Win32Vars_t is bad ptr: %p, mod can not work properly and should not be running, contact mod author and show him this log", m_Win32Vars_t);
        m_Win32Vars_t = nullptr;
        return false;
    }

    logInfo("m_Win32Vars_t set to %p", m_Win32Vars_t);
    return true;

}

bool winFocusManager::isGameFocused()
{
    if (!m_Win32Vars_t) {
        logErr("isGameFocused: m_Win32Vars_t, mod should not be running....");
        return false;
    }

    return m_Win32Vars_t->isGameFocused;
}
