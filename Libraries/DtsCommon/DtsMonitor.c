#include "DtsCommon/DtsMonitor.h"
#include "DtsCommon/DtsUtilities.h"

DBool dtsMonitorForBool(DtsParameterController* pControler, DUInt16 nId, DBool bCurrentValue)
{
    DBool result = FALSE;

    if (pControler != NULL)
    {
        DtsParameter* pParameter = NULL;
        if (TRUE == dtsParameterControllerFind(pControler, nId, &pParameter))
        {
            if (
                sizeof(DBool) == pParameter->nSize &&
                pParameter->bIsMonitorable == TRUE
                )
            {
                pParameter->nData = (DUInt64)bCurrentValue;
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

DBool dtsMonitorForInt32(DtsParameterController* pControler, DUInt16 nId, DInt32 nCurrentValue)
{
    DBool result = FALSE;

    if (pControler != NULL)
    {
        DtsParameter* pParameter = NULL;
        if (TRUE == dtsParameterControllerFind(pControler, nId, &pParameter))
        {
            if (
                sizeof(DInt32) == pParameter->nSize &&
                pParameter->bIsMonitorable == TRUE
                )
            {
                pParameter->nData = (DUInt64)nCurrentValue;
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

DBool dtsMonitorForFloat64(DtsParameterController* pControler, DUInt16 nId, DFloat64 dCurrentValue)
{
    DBool result = FALSE;

    if (pControler != NULL)
    {
        DtsParameter* pParameter = NULL;
        if (TRUE == dtsParameterControllerFind(pControler, nId, &pParameter))
        {
            if (
                sizeof(DFloat64) == pParameter->nSize &&
                pParameter->bIsMonitorable == TRUE
                )
            {
                dtsMemCopy((DVoidPointer)&pParameter->nData, (DConstVoidPointer)&dCurrentValue, sizeof(DFloat64));
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