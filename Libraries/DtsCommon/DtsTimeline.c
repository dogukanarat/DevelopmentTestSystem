#include "DtsCommon/DtsTimeline.h"

DBool dtsTimelineInitialize(
    DtsTimeline *self,
    DtsParameterController *pController,
    DtsTimelineParameter *pTimelineParameter,
    DSize nTimelineParameterCount)
{
    DBool result = FALSE;

    if (self != NULL)
    {
        if (pTimelineParameter != NULL &&
            nTimelineParameterCount > 0 &&
            pController != NULL)
        {
            self->pTimelineParameter = pTimelineParameter;
            self->nTimelineParameterCount = nTimelineParameterCount;
            self->nAppendedParameterCount = 0;
            self->pController = pController;

            result = dtsIteratorInitialize(
                &self->sIteratorWrite,
                (DBytePointer)pTimelineParameter,
                nTimelineParameterCount * sizeof(DtsTimelineParameter),
                DTS_ITERATOR_WRITE,
                DTS_ITERATOR_NO_BLOCK_SIZE);

            if (result == TRUE)
            {
                result = dtsIteratorInitialize(
                    &self->sIteratorRead,
                    (DBytePointer)pTimelineParameter,
                    nTimelineParameterCount * sizeof(DtsTimelineParameter),
                    DTS_ITERATOR_READ,
                    DTS_ITERATOR_NO_BLOCK_SIZE);
            }

            if (result == TRUE)
            {
                self->bIsInitialized = TRUE;
            }
            else
            {
                self->bIsInitialized = FALSE;
            }
        }
        else
        {
            self->bIsInitialized = FALSE;
            result = FALSE;
        }
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsTimelineParameterAppend(
    DtsTimeline *self,
    DInt16 nId,
    DUInt64 nData,
    DUInt32 nCycle)
{
    DBool result = FALSE;

    if (self != NULL)
    {
        if (self->bIsInitialized == TRUE)
        {
            DtsParameter *pFoundParameter = NULL;

            result = dtsParameterControllerFind(self->pController, nId, &pFoundParameter);

            if (result == TRUE)
            {
                DtsTimelineParameter timelineParameter;

                timelineParameter.pParameter = pFoundParameter;
                timelineParameter.nData = nData;
                timelineParameter.nCycle = nCycle;

                result = dtsIteratorWrite(
                    &self->sIteratorWrite,
                    (DBytePointer)&timelineParameter,
                    sizeof(DtsTimelineParameter));

                self->nAppendedParameterCount += 1;
            }
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

DBool dtsTimelineParameterSort(DtsTimeline *self)
{
    DBool result = FALSE;

    if (self != NULL)
    {
        if (self->bIsInitialized == TRUE)
        {
            // here is a sorting algorithm
            // that sorts the DtsTimelineParameter
            // according to its cycle number

            DBool bIsSorted = FALSE;

            while (bIsSorted == FALSE)
            {
                DSize nCurrentIndex = 0;
                DSize nNextIndex = 1;
                DSize nLastIndex = self->nAppendedParameterCount - 1;
                DtsTimelineParameter *pCurrentTimelineParameter = NULL;
                DtsTimelineParameter *pNextTimelineParameter = NULL;

                bIsSorted = TRUE;

                DtsIterator searchIterator;

                dtsIteratorInitialize(
                    &searchIterator,
                    (DBytePointer)self->pTimelineParameter,
                    self->nTimelineParameterCount * sizeof(DtsTimelineParameter),
                    DTS_ITERATOR_FORWARD,
                    sizeof(DtsTimelineParameter)
                    );

                while (nNextIndex <= nLastIndex)
                {
                    pCurrentTimelineParameter = NULL;
                    dtsIteratorGetPointer(
                        &self->sIteratorRead,
                        nCurrentIndex,
                        (DBytePointer*)&pCurrentTimelineParameter
                        );

                    pNextTimelineParameter = NULL;
                    dtsIteratorGetPointer(
                        &self->sIteratorRead,
                        nNextIndex,
                        (DBytePointer*)&pNextTimelineParameter
                        );

                    if (pCurrentTimelineParameter != NULL &&
                        pNextTimelineParameter != NULL)
                    {
                        if (pCurrentTimelineParameter->nCycle > pNextTimelineParameter->nCycle)
                        {
                            DtsTimelineParameter tempTimelineParameter;

                            tempTimelineParameter = *pCurrentTimelineParameter;
                            *pCurrentTimelineParameter = *pNextTimelineParameter;
                            *pNextTimelineParameter = tempTimelineParameter;

                            bIsSorted = FALSE;
                        }
                    }
                    else
                    {
                        result = FALSE;
                        break;
                    }

                    nCurrentIndex += 1;
                    nNextIndex += 1;
                }
            }

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