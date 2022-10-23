#ifndef INCLUDED_DTSITERATOR_H
#define INCLUDED_DTSITERATOR_H

#include "DtsCommon/DtsCommon.h"

typedef enum
{
    DTS_ITERATOR_WRITE,
    DTS_ITERATOR_READ
} DtsIteratorType;

typedef struct
{
    DtsIteratorType eType;
    DBytePointer pRawBuffer;
    DUInt32 nRawBufferSize;
    DUInt32 nCurrentIndex;
    DBool bIsInitialized;
} DtsIterator;

DBool dtsIteratorInitialize(DtsIterator *self, DBytePointer pRawBuffer, DUInt32 nRawBufferSize, DtsIteratorType eType);
DBool dtsIteratorWrite(DtsIterator *self, DConstBytePointer pValue, DSize nValueSize);
DBool dtsIteratorRead(DtsIterator *self, DBytePointer pValue, DSize nValueSize);

#endif