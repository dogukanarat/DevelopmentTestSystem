#include "DtsCommon/DtsUtilities.h"
#include "string.h"

DVoidPointer memSet(DVoidPointer destination, DInt32 value, DSize length)
{
    return memset(destination, value, length);
}

DVoidPointer memCopy(DVoidPointer destination, DConstVoidPointer source, DSize length)
{
    return memcpy(destination, source, length);
}
