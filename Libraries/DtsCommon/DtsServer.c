#include "DtsCommon/DtsServer.h"

DBool dtsServerInitialize(
    DtsServer *pServer,
    DtsParameter *pParameters,
    DSize nParameterCount,
    DBytePointer pReceiveBuffer,
    DSize nReceiveBufferSize,
    DBytePointer pTransmitBuffer,
    DSize nTransmitBufferSize)
{
    DBool result = FALSE;

    if (pServer != NULL)
    {
        if (pReceiveBuffer != NULL &&
            pTransmitBuffer != NULL &&
            nTransmitBufferSize > 0 &&
            nReceiveBufferSize > 0)
        {
            result = TRUE;
        }

        if (result == TRUE)
        {
            result = dtsParameterControllerInitialize(&pServer->sParameterController, pParameters, nParameterCount);
        }

        if (result == TRUE)
        {
            result = dtsIteratorInitialize(
                &pServer->sIteratorTransmit,
                pTransmitBuffer,
                nTransmitBufferSize,
                DTS_ITERATOR_WRITE,
                DTS_ITERATOR_NO_BLOCK_SIZE);
        }

        if (result == TRUE)
        {
            result = dtsIteratorInitialize(
                &pServer->sIteratorReceive,
                pReceiveBuffer,
                nReceiveBufferSize,
                DTS_ITERATOR_READ,
                DTS_ITERATOR_NO_BLOCK_SIZE);
        }

        if (result == TRUE)
        {
            pServer->pReceiveBuffer = pReceiveBuffer;
            pServer->nReceiveBufferSize = nReceiveBufferSize;
            pServer->pTransmitBuffer = pTransmitBuffer;
            pServer->nTransmitBufferSize = nTransmitBufferSize;
            pServer->eState = DTS_SERVER_STATE_IDLE;
            pServer->sFlags.bIsDiscoveryPacketReceived = FALSE;
            pServer->bIsInitialized = TRUE;
        }
        else
        {
            pServer->bIsInitialized = FALSE;
        }
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsServerMain(DtsServer *pServer)
{
    DBool result = FALSE;
    DBool resultMonitor = FALSE;
    DBool resultUpdate = FALSE;
    DBool resultTransition = FALSE;
    DBool resultResolve = FALSE;

    resultResolve = dtsServerResolverMain(pServer);

    resultTransition = dtsServerProcessStateTransition(pServer);

    resultUpdate = dtsServerUpdateMain(pServer);

    resultMonitor = dtsServerMonitorMain(pServer);

    // TODO: update this condition since monitoring is not an error
    if (resultMonitor == TRUE &&
        resultUpdate == TRUE &&
        resultTransition == TRUE)
    {
        result = TRUE;
    }

    return result;
}

DBool dtsServerResolverMain(DtsServer *pServer)
{
    DBool result = FALSE;

    if (pServer != NULL)
    {
        if (pServer->bIsInitialized == TRUE)
        {
            dtsIteratorReset(&pServer->sIteratorReceive);

            DBool resolveResult = FALSE;

            resolveResult = dtsProtocolResolveDiscoveryMessage(&pServer->sIteratorReceive);

            if (resolveResult == TRUE)
            {
                pServer->sFlags.bIsDiscoveryPacketReceived = TRUE;
            }
            else
            {
                pServer->sFlags.bIsDiscoveryPacketReceived = FALSE;
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

DBool dtsServerProcessStateTransition(DtsServer *pServer)
{
    DBool result = FALSE;

    if (pServer != NULL && pServer->bIsInitialized == TRUE)
    {
        if (pServer->eState == DTS_SERVER_STATE_IDLE &&
            pServer->sFlags.bIsDiscoveryPacketReceived == TRUE)
        {
            pServer->eState = DTS_SERVER_STATE_MONITOR;
        }

        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsServerMonitorMain(DtsServer *pServer)
{
    DBool result = FALSE;

    if (pServer != NULL)
    {
        if (pServer->eState != DTS_SERVER_STATE_IDLE)
        {
            result = dtsProtocolCreateMonitorMessage(
                &pServer->sIteratorTransmit,
                &pServer->sParameterController);
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

DBool dtsServerUpdateMain(DtsServer *pServer)
{
    return TRUE;
}
