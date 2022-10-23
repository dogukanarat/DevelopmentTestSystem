#include "DtsCommon/DtsIterator.h"
#include "DtsCommon/DtsUtilities.h"
#include <string.h>

DBool dtsIteratorInitialize(DtsIterator *self, DBytePointer pRawBuffer, DUInt32 nRawBufferSize,  DtsIteratorType eType)
{
    DBool result = FALSE;

    if(self != NULL && pRawBuffer != NULL && nRawBufferSize > 0)
    {
        self->pRawBuffer = pRawBuffer;
        self->nRawBufferSize = nRawBufferSize;
        self->nCurrentIndex = 0;
        self->eType = eType;
        self->bIsInitialized = TRUE;
        result = TRUE;
    }
    else
    {
        if(self != NULL)
        {
            self->bIsInitialized = FALSE;
        }

        result = FALSE;
    }

    return result;
}

DBool dtsIteratorWrite(DtsIterator *self, DConstBytePointer pValue, DSize nValueSize)
{
    DBool result = FALSE;

    if(
        self != NULL &&
        pValue != NULL &&
        nValueSize > 0 &&
        self->bIsInitialized == TRUE &&
        self->eType == DTS_ITERATOR_WRITE
        )
    {
        if(self->nCurrentIndex + nValueSize <= self->nRawBufferSize)
        {
            DVoidPointer pDestination = self->pRawBuffer + self->nCurrentIndex;
            DConstVoidPointer pSource = pValue;

            dtsMemCopy(pDestination, pSource, nValueSize);
            
            self->nCurrentIndex += nValueSize;
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsIteratorRead(DtsIterator *self, DBytePointer pValue, DSize nValueSize)
{
    DBool result = FALSE;

    if(
        self != NULL &&
        pValue != NULL &&
        nValueSize > 0 &&
        self->bIsInitialized == TRUE &&
        self->eType == DTS_ITERATOR_READ
        )
    {
        if(self->nCurrentIndex + nValueSize <= self->nRawBufferSize)
        {
            DVoidPointer destination = pValue;
            DConstVoidPointer source = self->pRawBuffer + self->nCurrentIndex;

            dtsMemCopy(destination, source, nValueSize);

            self->nCurrentIndex += nValueSize;
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
    }
    else
    {
        result = FALSE;
    }

    return result;
}