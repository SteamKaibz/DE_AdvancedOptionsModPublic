#pragma once

#include "idLib_Static.h"


/// 2/9/24 classes/ enums in idLib_Sandbox.h and idLib_Vanilla.h should be regenerated for each update. Some structs/enums are different between Sandbox and Vanilla. 


#ifdef GAME_VERSION_SANDBOX
#include "idLib_Sandbox.h"
#else
#include "idLib_Vanilla.h"
#endif


