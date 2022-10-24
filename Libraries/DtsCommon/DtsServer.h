#ifndef INCLUDED_DTSSERVER_H
#define INCLUDED_DTSSERVER_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"

typedef struct
{
    DtsParameterController sParameterController;
    DBool bIsInitialized;
} DtsServer;

DBool dtsServerInitialize(
    DtsServer* pServer,
    DtsParameter* pParameters,
    DSize nParameterCount
    );

#endif // INCLUDED_DTSSERVER_H
