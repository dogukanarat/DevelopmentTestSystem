#ifndef INCLUDED_DTSITERATOR_H
#define INCLUDED_DTSITERATOR_H

#include "DtsCommon/DtsCommon.h"

typedef struct
{
    DUInt32 nCurrentIndex;
    DUInt32 nEndIndex;
} DtsIterator;

DBool dtsIteratorInitialize(DtsIterator *self, DUInt32 nStartIndex, DUInt32 nEndIndex);
DBool dtsIteratorIncrement(DtsIterator *self);
DBool dtsIteratorDecrement(DtsIterator *self);
DBool dtsIteratorIsDone(DtsIterator *self);

#endif