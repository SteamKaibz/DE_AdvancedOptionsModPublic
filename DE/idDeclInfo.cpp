#include "idDeclInfo.h"

bool idDeclInfo::acquirreIdDeclInfoTemplate_idMaterial2Ptr(__int64 ptr) {
    logDebug("acquirreIdDeclInfoTemplate_idMaterial2Ptr");
    if (MemHelper::isBadReadPtr((void*)ptr)) {
        logErr("acquirreIdDeclInfoTemplate_idMaterial2Ptr: ptr is bad: %p ", (void*)ptr);
        return false;
    }
    m_idDeclInfoTemplate_idMaterial2Ptr = ptr;
    logInfo("acquirreIdDeclInfoTemplate_idMaterial2Ptr: m_idDeclInfoTemplate_idMaterial2Ptr is being set to : %p ", (void*)m_idDeclInfoTemplate_idMaterial2Ptr);
    return true;
}

bool idDeclInfo::acquirreIdDeclInfo_FindWithInheritanceFuncPtr(__int64 ptr) {
    logDebug("acquirreIdDeclInfo_FindWithInheritanceFuncPtr");
    if (MemHelper::isBadReadPtr((void*)ptr)) {
        logErr("acquirreIdDeclInfo_FindWithInheritanceFuncPtr: ptr is bad: %p ", (void*)ptr);
        return false;
    }
    pidDeclInfo_FindWithInheritance = reinterpret_cast<idDeclInfo_FindWithInheritance>(ptr);
    logInfo("acquirreIdDeclInfo_FindWithInheritanceFuncPtr: pidDeclInfo_FindWithInheritance is being set to : %p ", (void*)pidDeclInfo_FindWithInheritance);
    return true;

}

 __int64 idDeclInfo::getMaterialPtr(const char* matNameStr, unsigned int extraInfo) {
    if (MemHelper::isBadReadPtr((void*)m_idDeclInfoTemplate_idMaterial2Ptr)) {
        logErr("getMaterialPtr: m_idDeclInfoTemplate_idMaterial2Ptr is bad ptr, returning 0. ");
        return 0;
    }
    return pidDeclInfo_FindWithInheritance(m_idDeclInfoTemplate_idMaterial2Ptr, matNameStr, extraInfo);
}

 //? side note this doesn't work to get idDeclGlobalShell using a idDeclGlobalShell and idDeclGlobalShell as the name and extra info 1, it actually return a idMaterial2 for idDeclGlobalShell....(?!)
 __int64 idDeclInfo::FindWithInheritance(__int64 resListAddr, const char* nameCStr, unsigned int extraInfo) {
     if (MemHelper::isBadReadPtr((void*)resListAddr)) {
         logErr("FindWithInheritance: resListAddr is bad ptr (%p) returning 0. ", (void*)resListAddr);
         return 0;
     }
     else if (MemHelper::isBadReadPtr((void*)nameCStr)) {
         logErr("FindWithInheritance: nameCStr is bad ptr (%p), returning 0. ", (void*)nameCStr);
         return 0;
     }

     return pidDeclInfo_FindWithInheritance(m_idDeclInfoTemplate_idMaterial2Ptr, nameCStr, extraInfo);
 }
