//#pragma once
//#include "../Config/Config.h"
//#include "../DE/idResource.h"
//#include "../DE/Types.h"
//
//
//class ReticleSettingsDebug
//{
//
//private:
//
//    static const unsigned int m_nextDeclWeaponReticlePtrOffset;
//    static const unsigned int m_declReticleMaxCount;
//
//public:
//
//    static void overwriteAllReticlesScaleDebug(float newreticleModelScaleVal) {
//        unsigned int declCount = 1;
//        unsigned int changedCount = 0;
//        logInfo("overwriteAllReticlesScaleDebug() called");
//        uintptr_t declWeaponReticlePtr = idResource::getResourceListFirstElementPtr("idDeclWeaponReticle");
//        while (!MemHelper::isBadReadPtr((void*)declWeaponReticlePtr))
//        {
//            uintptr_t declWeaponReticleAddr = *(uintptr_t*)declWeaponReticlePtr;
//            if (MemHelper::isBadReadPtr((void*)declWeaponReticleAddr)) {
//                logWarn("overwriteAllReticlesScaleDebug declWeaponReticleAddr: %p BREAKING !!!!!", (void*)declWeaponReticleAddr);
//                break;
//            }
//            idDeclWeaponReticle* declWeaponReticle = (idDeclWeaponReticle*)declWeaponReticleAddr;
//            logInfo("declWeaponReticle addr: %p ", (void*)declWeaponReticle);
//            if (MemHelper::isBadReadPtr((void*)declWeaponReticle)) {
//                logErr("overwriteAllReticlesScaleDebug: bad ptr detected for: declWeaponReticle: %p returning ", (void*)declWeaponReticle);
//                return;
//            }
//            //! this is used to actually prevent crash as we find 38 declReticle in the idResource and trying to change the scale value of the 38th one will create crash, especially as the last ptr will "morph" into another object which is not a declReticle when the player load a single player level.
//            if (declCount >= m_declReticleMaxCount) {
//                logInfo("overwriteAllReticlesScaleDebug: declCount is: %d. Max Reticle count reached, not going further to prevent potential crash. %d declWeaponReticles had their scale value changed to: %.2f", declCount, changedCount, newreticleModelScaleVal);
//                return;
//            }
//            /*if (strcmp(declWeaponReticle->name, g_weaponreticleRevenant.c_str()) == 0) {
//                logInfo("updateAllReticlesScale: declCountDebug is: %d. Found Revenant Reticle, not going further to prevent potential crash. %d declWeaponReticles had their scale value changed to: %.2f", changedCount, newreticleModelScaleVal, declCountDebug);
//                return;
//            }*/
//
//            logInfo("overwriteAllReticlesScaleDebug: NOT OVERWRITING WEAPONS. declWeaponReticle at addr: %p with name: %s has a current reticleModelScale of: %.3f overwritting it with value: %.3f", (void*)declWeaponReticle, declWeaponReticle->name, declWeaponReticle->reticleModelScale, newreticleModelScaleVal);
//
//           /* if (declWeaponReticle->reticleModelScale != newreticleModelScaleVal) {
//                logInfo("overwriteAllReticlesScaleDebug: declWeaponReticle at addr: %p with name: %s has a current reticleModelScale of: %.3f overwritting it with value: %.3f", (void*)declWeaponReticle, declWeaponReticle->name, declWeaponReticle->reticleModelScale, newreticleModelScaleVal);
//                declWeaponReticle->reticleModelScale = newreticleModelScaleVal;
//                changedCount++;
//            }*/
//            declWeaponReticlePtr += m_nextDeclWeaponReticlePtrOffset;
//
//            declCount++;
//
//        }
//        logWarn("overwriteAllReticlesScaleDebug: (We should not be here) %d declWeaponReticle had their scale value changed to: %.2f ", changedCount, newreticleModelScaleVal);
//    }
//
//
//
//
//};
//
//
//
//
//const unsigned int ReticleSettingsDebug::m_declReticleMaxCount = 39;
//const unsigned int ReticleSettingsDebug::m_nextDeclWeaponReticlePtrOffset = 0x18;