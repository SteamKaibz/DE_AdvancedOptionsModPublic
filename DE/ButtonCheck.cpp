#include "ButtonCheck.h"

bool ButtonCheck::isKeyPressedCustom(__int64& ptr, __int64 btnEnum)
{

    if (!*(BYTE*)(ptr + 0xA1)) {
        val_0xA8 = *(unsigned __int64*)(ptr + 0xA8);
    }
    val_0xA8Anda2Result = val_0xA8 & btnEnum;
    if ((val_0xA8Anda2Result) == 0) {
        return false;
    }
    if (!*(BYTE*)(ptr + 9)) {
        val_0x10 = *(unsigned __int64*)(ptr + 0x10);
    }
    return (val_0x10 & btnEnum) == 0;
}
