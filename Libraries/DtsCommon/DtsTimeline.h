#ifndef INCLUDED_DTSTIMELINE_H
#define INCLUDED_DTSTIMELINE_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameter.h"
#include "DtsCommon/DtsIterator.h"
#include "DtsCommon/DtsParameterController.h"

typedef struct 
{
    DtsParameter *pParameter;
    DUInt64 nData;
    DUInt32  nCycle;
} DtsTimelineParameter;

typedef struct 
{
    DtsParameterController* pController;
    DtsTimelineParameter* pTimelineParameter;
    DSize nTimelineParameterCount;
    DtsIterator sIteratorWrite;
    DtsIterator sIteratorRead;
    DSize nAppendedParameterCount;
    DBool bIsInitialized;
} DtsTimeline;

DBool dtsTimelineInitialize(
    DtsTimeline* self,
    DtsParameterController* pController,
    DtsTimelineParameter* pTimelineParameter,
    DSize nTimelineParameterCount
    );

DBool dtsTimelineParameterAppend(
    DtsTimeline* self,
    DInt16 nId,
    DUInt64 nData,
    DUInt32 nCycle
    );

DBool dtsTimelineParameterSort(DtsTimeline* self);


#endif // INCLUDED_DTSTIMELINE_H
