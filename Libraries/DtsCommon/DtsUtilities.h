#ifndef INCLUDED_DTSUTILITIES_H
#define INCLUDED_DTSUTILITIES_H

#include "DtsCommon/DtsCommon.h"

/// @brief 
/// @param destination 
/// @param value 
/// @param length 
/// @return 
DVoidPointer memSet(DVoidPointer destination, DInt32 value, DSize length);

/// @brief
/// @param destination
/// @param source
/// @param length
/// @return
DVoidPointer memCopy(DVoidPointer destination, DConstVoidPointer source, DSize length);

#endif // INCLUDED_DTSUTILITIES_H
