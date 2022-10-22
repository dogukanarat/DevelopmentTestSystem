#ifndef INCLUDED_DTSCIRCULARBUFFER_H
#define INCLUDED_DTSCIRCULARBUFFER_H

#include "DtsCommon/DtsCommon.h"

/// @brief 
typedef struct
{
    DBytePointer pBuffer;
    DUInt32 nBufferSize;
    DUInt32 nBufferHead;
    DUInt32 nBufferTail;
    DUInt32 nBufferCount;
} DtsCircularBuffer;

/// @brief 
/// @param self 
/// @return 
DBool dtsCircularBufferInitialize(DtsCircularBuffer *self);

/// @brief 
/// @param self 
/// @param pNewBuffer 
/// @param nNewBufferSize 
/// @return 
DBool dtsCircularBufferSetBuffer(DtsCircularBuffer *self, DBytePointer pNewBuffer, DUInt32 nNewBufferSize);

/// @brief 
/// @param self 
/// @return 
DBool dtsCircularBufferClear(DtsCircularBuffer *self);

/// @brief 
/// @param self 
/// @param pSource 
/// @param nSourceSize 
/// @return 
DBool dtsCircularBufferPush(DtsCircularBuffer *self, DConstBytePointer pSource, DUInt32 nSourceSize);

/// @brief 
/// @param self 
/// @param pDestination 
/// @param nDestinationSize 
/// @return 
DBool dtsCircularBufferPop(DtsCircularBuffer *self, DBytePointer pDestination, DUInt32 nDestinationSize);

#endif