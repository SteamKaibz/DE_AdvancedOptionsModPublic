#pragma once
#include "MemHelper.h"
//#include "Config.h"


class idDeclInfo {

private:
   

    typedef __int64(__fastcall* idDeclInfo_FindWithInheritance)(__int64 a1, const char* a2, unsigned int a3);

    static inline __int64 m_idDeclInfoTemplate_idMaterial2Ptr = 0;
    static inline idDeclInfo_FindWithInheritance pidDeclInfo_FindWithInheritance = 0; 



public:
       
    static bool acquirreIdDeclInfoTemplate_idMaterial2Ptr(__int64 ptr);

    static bool acquirreIdDeclInfo_FindWithInheritanceFuncPtr(__int64 ptr);

    static __int64 getMaterialPtr(const char* matNameStr, unsigned int extraInfo);

    static __int64 FindWithInheritance(__int64 resListAddr, const char* nameCStr, unsigned int extraInfo);

};

