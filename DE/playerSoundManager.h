#pragma once
#include "GeneratedClasses.h"
#include "idMapInstanceLocalManager.h"


typedef __int64(__fastcall* idPlayerPlaySoundEventFp)(
    idPlayer* idPlayerPtr,
    idSoundEvent* idSoundEventPtr
    );

/// <summary>
/// related to the sounds in idDeclPlayerProps::playerSounds_t. mainly used to trigger out of items sound atm.
/// </summary>
class playerSoundManager
{
private:
    static inline idPlayerPlaySoundEventFp m_playSoundFp = nullptr;

public:

    //static idSoundEvent* getOutOfItemSoundEventPtr();
    static void playOutOfItemSound();
};

