#ifndef INCLUDED_DTSUTILITIES_H
#define INCLUDED_DTSUTILITIES_H

#include "DtsCommon/DtsCommon.h"

/// @brief 
/// @param destination 
/// @param value 
/// @param length 
/// @return 
DVoidPointer dtsMemSet(DVoidPointer destination, DInt32 value, DSize length);

/// @brief
/// @param destination
/// @param source
/// @param length
/// @return
DVoidPointer dtsMemCopy(DVoidPointer destination, DConstVoidPointer source, DSize length);

/// @brief
/// @param pValue
/// @param nValueSize
/// @return
DBool dtsSwap(DVoidPointer pValue, DSize nValueSize);

#endif // INCLUDED_DTSUTILITIES_H
