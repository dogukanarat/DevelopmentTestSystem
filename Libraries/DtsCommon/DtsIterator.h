#ifndef INCLUDED_DTSITERATOR_H
#define INCLUDED_DTSITERATOR_H

#include "DtsCommon/DtsCommon.h"

#define DTS_ITERATOR_NO_BLOCK_SIZE -1

typedef enum
{
    DTS_ITERATOR_WRITE,
    DTS_ITERATOR_READ,
    DTS_ITERATOR_FORWARD,
} DtsIteratorType;

typedef struct
{
    DtsIteratorType eType;
    DBytePointer pRawBuffer;
    DInt32 nBlockSize;
    DUInt32 nRawBufferSize;
    DUInt32 nCurrentIndex;
    DBool bIsInitialized;
} DtsIterator;

DBool dtsIteratorInitialize(
    DtsIterator *self,
    DBytePointer pRawBuffer,
    DUInt32 nRawBufferSize,
    DtsIteratorType eType,
    DInt32 nBlockSize
    );

DUInt32 dtsIteratorGetSize(DtsIterator *self);
DBool dtsIteratorReset(DtsIterator *self);
DBool dtsIteratorGetPointer(DtsIterator *self, DUInt16 nIndex, DBytePointer* pResult);
DBool dtsIteratorReserve(DtsIterator *self, DBytePointer *ppPointer, DUInt32 nSize);
DBool dtsIteratorWrite(DtsIterator *self, DConstBytePointer pValue, DSize nValueSize);
DBool dtsIteratorRead(DtsIterator *self, DBytePointer pValue, DSize nValueSize);
DBool dtsIteratorNext(DtsIterator *self, DBytePointer *ppValue);

#endif