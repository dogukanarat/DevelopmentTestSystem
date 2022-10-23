#include "DtsCommon/DtsParameterController.h"

DBool dtsParameterControllerInitialize(DtsParameterController* pController, DtsParameter* pParameters, DUInt16 nParameterCount)
{
    DBool result = FALSE;

    if(pController != NULL && pParameters != NULL && nParameterCount > 0)
    {
        pController->pParameters = pParameters;
        pController->nParameterCount = nParameterCount;
        pController->bIsInitialized = TRUE;
        result = TRUE;
    }
    else
    {
        if(pController != NULL)
        {
            pController->bIsInitialized = FALSE;
        }

        result = FALSE;
    }

    return result;
}

DBool dtsParameterControllerFind(DtsParameterController* pController, DUInt16 nId, DtsParameter** ppParameter)
{
    DBool result = FALSE;

    if(pController != NULL && ppParameter != NULL)
    {
        DtsParameter* pParameter = pController->pParameters;
        
        for(DUInt32 nParameterIndex = 0; nParameterIndex < pController->nParameterCount; nParameterIndex++)
        {
            if(pParameter->nId == nId)
            {
                *ppParameter = pParameter;
                result = TRUE;
                break;
            }
            else
            {
                pParameter++;
            }
        }
    }
    else
    {
        result = FALSE;
    }

    return result;
}