#include "DtsCommon/DtsProtocol.h"

DBool dtsProtocolSetHeader(DtsIterator* pIterator, DUInt16 nHeader)
{
    DBool result = FALSE;

    if (pIterator != NULL)
    {
        result = dtsIteratorWrite(pIterator, (DConstBytePointer)&nHeader, sizeof(nHeader));
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsProtocolCreateDiscoveryMessage(DtsIterator* pIterator)
{
    DBool result = FALSE;

    if (pIterator != NULL)
    {
        result = dtsProtocolSetHeader(pIterator, DTS_PROTOCOL_DISCOVERY_HEADER);
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsProtocolResolveDiscoveryMessage(DtsIterator* pIterator)
{
    DBool result = FALSE;
    DUInt16 nHeader = 0;

    if (pIterator != NULL)
    {
        result = dtsIteratorRead(pIterator, (DBytePointer)&nHeader, sizeof(nHeader));

        if (result == TRUE)
        {
            if (nHeader == DTS_PROTOCOL_DISCOVERY_HEADER)
            {
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
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsProtocolSetValue(DtsIterator* pIterator, DConstVoidPointer pValue, DSize nValueSize)
{
    DBool result = FALSE;

    if (pIterator != NULL && pValue != NULL && nValueSize > 0)
    {
        result = dtsIteratorWrite(pIterator, (DConstBytePointer)pValue, nValueSize);
    }
    else
    {
        result = FALSE;
    }

    return result;
}

DBool dtsProtocolSetParameter(DtsIterator* pIterator, const DtsParameter* pParameter)
{
    DBool result = FALSE;

    if (pIterator != NULL && pParameter != NULL)
    {
        result = dtsProtocolSetValue(pIterator, (DConstVoidPointer)&pParameter->nId, sizeof(DInt16));
        // TODO: refactor here for optimization
        result = dtsProtocolSetValue(pIterator, (DConstVoidPointer)&pParameter->nSize, sizeof(DUInt16));
        // TODO: check endian and alignment here
        result = dtsProtocolSetValue(pIterator, (DConstVoidPointer)&pParameter->nData, pParameter->nSize);
    }
    return result;
}

DBool dtsProtocolCreateMonitorMessage(DtsIterator* pIterator, const DtsParameterController* pController)
{
    DBool result = FALSE;

    if (pIterator != NULL && pController != NULL)
    {
        DtsIterator itParameters;
        DtsParameter* pParameter = NULL;

        dtsIteratorInitialize(
            &itParameters,
            (DBytePointer)pController->pParameters,
            pController->nParameterCount * sizeof(DtsParameter),
            DTS_ITERATOR_FORWARD,
            sizeof(DtsParameter)
            );
        
        result = dtsProtocolSetHeader(pIterator, DTS_PROTOCOL_MONITOR_HEADER);
        
        while(dtsIteratorNext(&itParameters, (DBytePointer*)&pParameter) == TRUE)
        {
            if(pParameter->bIsMonitorable == TRUE)
            {
                result = dtsProtocolSetParameter(pIterator, pParameter);
            }
            else
            {
                // pass the parameter
                // no implementation
            }
        }
    }
    else
    {
        result = FALSE;
    }

    return result;
}
