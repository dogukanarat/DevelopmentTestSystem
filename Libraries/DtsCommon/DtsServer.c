#include "DtsCommon/DtsServer.h"

DBool dtsServerInitialize(
    DtsServer* pServer,
    DtsParameter* pParameters,
    DSize nParameterCount
)
{
    DBool result = FALSE;

    if(pServer != NULL && pParameters != NULL && nParameterCount > 0)
    {
        pServer->pParameters = pParameters;
        pServer->nParameterCount = nParameterCount;
        pServer->bIsInitialized = TRUE;
        result = TRUE;
    }
    else
    {
        if(pServer != NULL)
        {
            pServer->bIsInitialized = FALSE;
        }

        result = FALSE;
    }

    return result;
}