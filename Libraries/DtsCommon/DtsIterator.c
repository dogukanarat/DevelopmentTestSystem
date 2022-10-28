#include "DtsCommon/DtsIterator.h"
#include "DtsCommon/DtsUtilities.h"
#include <string.h>

DBool dtsIteratorInitialize(
    DtsIterator *self,
    DBytePointer pRawBuffer,
    DUInt32 nRawBufferSize,
    DtsIteratorType eType,
    DInt32 nBlockSize
    )
{
    DBool result = FALSE;

    if(self != NULL && pRawBuffer != NULL && nRawBufferSize > 0)
    {
        DBool isForwardBackwardIterator = FALSE;

        if(eType == DTS_ITERATOR_FORWARD)
        {
            isForwardBackwardIterator = TRUE;
        }
        else {}

        if(isForwardBackwardIterator == TRUE && nBlockSize > 0)
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }

        if(isForwardBackwardIterator == FALSE || result == TRUE)
        {
            self->pRawBuffer = pRawBuffer;
            self->nRawBufferSize = nRawBufferSize;
            self->nCurrentIndex = 0;
            self->eType = eType;
            self->bIsInitialized = TRUE;
            self->nBlockSize = nBlockSize;
            result = TRUE;
        }
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

DUInt32 dtsIteratorGetSize(DtsIterator *self)
{
    return self->nCurrentIndex;
}

DBool dtsIteratorReset(DtsIterator *self)
{
    DBool result = FALSE;

    if(self != NULL)
    {
        self->nCurrentIndex = 0;
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsIteratorReserve(DtsIterator *self, DBytePointer *ppPointer, DUInt32 nSize)
{
    DBool result = FALSE;

    if(self != NULL && ppPointer != NULL && nSize > 0)
    {
        if(self->nCurrentIndex + nSize <= self->nRawBufferSize)
        {
            *ppPointer = self->pRawBuffer + self->nCurrentIndex;
            self->nCurrentIndex += nSize;
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
            DVoidPointer pDestination = (DVoidPointer)(self->pRawBuffer + self->nCurrentIndex);
            DConstVoidPointer pSource = (DConstVoidPointer)(pValue);

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
            DVoidPointer destination = (DVoidPointer)(pValue);
            DConstVoidPointer source = (DConstVoidPointer)(self->pRawBuffer + self->nCurrentIndex);

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

DBool dtsIteratorNext(DtsIterator *self, DBytePointer *ppValue)
{
    DBool result = FALSE;

    if(
        self != NULL &&
        ppValue != NULL &&
        self->bIsInitialized == TRUE &&
        self->eType == DTS_ITERATOR_FORWARD
        )
    {
        if(self->nCurrentIndex + self->nBlockSize <= self->nRawBufferSize)
        {
            *ppValue = self->pRawBuffer + self->nCurrentIndex;
            self->nCurrentIndex += self->nBlockSize;
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

DBool dtsIteratorPrevious(DtsIterator *self, DBytePointer *ppValue)
{
    DBool result = FALSE;

    // if(
    //     self != NULL &&
    //     ppValue != NULL &&
    //     self->bIsInitialized == TRUE &&
    //     self->eType == DTS_ITERATOR_BACKWARD
    //     )
    // {
    //     if(self->nCurrentIndex >= self->nBlockSize)
    //     {
    //         self->nCurrentIndex -= self->nBlockSize;
    //         *ppValue = self->pRawBuffer + self->nCurrentIndex;
    //         result = TRUE;
    //     }
    //     else
    //     {
    //         result = FALSE;
    //     }
    // }
    // else
    // {
    //     result = FALSE;
    // }

    return result;
}