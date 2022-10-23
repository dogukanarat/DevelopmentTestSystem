#ifndef INCLUDED_DTSPARAMETERCONTROLLER_H
#define INCLUDED_DTSPARAMETERCONTROLLER_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameter.h"

typedef struct 
{
    DtsParameter* pParameters;
    DUInt16 nParameterCount;
    DBool bIsInitialized;
} DtsParameterController;

DBool dtsParameterControllerInitialize(DtsParameterController* pController, DtsParameter* pParameters, DUInt16 nParameterCount);
DBool dtsParameterControllerFind(DtsParameterController* pController, DUInt16 nId, DtsParameter** ppParameter);

#endif // DTSPARAMETERCONTROLLER_H
