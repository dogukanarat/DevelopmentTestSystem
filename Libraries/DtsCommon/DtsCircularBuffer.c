#include "DtsCommon/DtsCircularBuffer.h"
#include "DtsCommon/DtsUtilities.h"

DBool dtsCircularBufferInitialize(DtsCircularBuffer *self)
{
    self->pBuffer = NULL;
    self->nBufferSize = 0;
    self->nBufferHead = 0;
    self->nBufferTail = 0;
    self->nBufferCount = 0;

    return TRUE;
}

DBool dtsCircularBufferSetBuffer(DtsCircularBuffer *self, DBytePointer pNewBuffer, DUInt32 nNewBufferSize)
{
    DBool bResult = FALSE;

    if (self->pBuffer != NULL)
    {
        bResult = FALSE;
    }
    else
    {
        self->pBuffer = pNewBuffer;
        self->nBufferSize = nNewBufferSize;
        self->nBufferHead = 0;
        self->nBufferTail = 0;
        self->nBufferCount = 0;

        bResult = TRUE;
    }

    return TRUE;
}

DBool dtsCircularBufferClear(DtsCircularBuffer *self)
{
    DBool bResult = FALSE;

    if (self->pBuffer == NULL)
    {
        bResult = FALSE;
    }
    else
    {
        self->nBufferHead = 0;
        self->nBufferTail = 0;
        self->nBufferCount = 0;

        bResult = TRUE;
    }

    return bResult;
}

DBool dtsCircularBufferPush(DtsCircularBuffer *self, DConstBytePointer pSource, DUInt32 nSourceSize)
{
    DBool bResult = FALSE;

    if (self->pBuffer == NULL)
    {
        bResult = FALSE;
    }
    else if (nSourceSize > self->nBufferSize)
    {
        bResult = FALSE;
    }
    else if (nSourceSize > (self->nBufferSize - self->nBufferCount))
    {
        bResult = FALSE;
    }
    else
    {
        DUInt32 nFirstCopySize = 0;
        DUInt32 nSecondCopySize = 0;

        if ((self->nBufferTail + nSourceSize) > self->nBufferSize)
        {
            nFirstCopySize = self->nBufferSize - self->nBufferTail;
            nSecondCopySize = nSourceSize - nFirstCopySize;
        }
        else
        {
            nFirstCopySize = nSourceSize;
            nSecondCopySize = 0;
        }

        dtsMemCopy(
            (DVoidPointer)(self->pBuffer + self->nBufferTail),
            (DConstVoidPointer)(pSource),
            nFirstCopySize);

        self->nBufferTail += nFirstCopySize;
        if (self->nBufferTail >= self->nBufferSize)
        {
            self->nBufferTail = 0;
        }

        if (nSecondCopySize > 0)
        {
            dtsMemCopy(
                (DVoidPointer)(self->pBuffer + self->nBufferTail),
                (DConstVoidPointer)(pSource + nFirstCopySize),
                nSecondCopySize);

            self->nBufferTail += nSecondCopySize;
        }

        self->nBufferCount += nSourceSize;

        bResult = TRUE;
    }

    return bResult;
}

DBool dtsCircularBufferPop(DtsCircularBuffer *self, DBytePointer pDestination, DUInt32 nDestinationSize)
{
    DBool bResult = FALSE;

    if (self->pBuffer == NULL)
    {
        bResult = FALSE;
    }
    else if (nDestinationSize > self->nBufferSize)
    {
        bResult = FALSE;
    }
    else if (nDestinationSize > self->nBufferCount)
    {
        bResult = FALSE;
    }
    else
    {
        DUInt32 nFirstCopySize = 0;
        DUInt32 nSecondCopySize = 0;

        if ((self->nBufferHead + nDestinationSize) > self->nBufferSize)
        {
            nFirstCopySize = self->nBufferSize - self->nBufferHead;
            nSecondCopySize = nDestinationSize - nFirstCopySize;
        }
        else
        {
            nFirstCopySize = nDestinationSize;
            nSecondCopySize = 0;
        }

        dtsMemCopy(
            (DVoidPointer)(pDestination),
            (DConstVoidPointer)(self->pBuffer + self->nBufferHead),
            nFirstCopySize);

        self->nBufferHead += nFirstCopySize;
        if (self->nBufferHead >= self->nBufferSize)
        {
            self->nBufferHead = 0;
        }

        if (nSecondCopySize > 0)
        {
            dtsMemCopy(
                (DVoidPointer)(pDestination + nFirstCopySize),
                (DConstVoidPointer)(self->pBuffer + self->nBufferHead),
                nSecondCopySize);

            self->nBufferHead += nSecondCopySize;
        }

        self->nBufferCount -= nDestinationSize;

        bResult = TRUE;
    }

    return bResult;
}