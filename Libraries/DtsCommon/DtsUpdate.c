#include "DtsCommon/DtsUpdate.h"
#include "DtsCommon/DtsUtilities.h"

DBool dtsUpdateForBool(DtsParameterController *pControler, DUInt16 nId, DBool bDefaultValue)
{
    DBool finalParameter = bDefaultValue;

    if (pControler != NULL)
    {
        DtsParameter *pParameter = NULL;
        if (TRUE == dtsParameterControllerFind(pControler, nId, &pParameter))
        {
            if (
                sizeof(DBool) == pParameter->nSize &&
                pParameter->bIsUpdatable == TRUE &&
                DTS_PARAMETER_STATE_UPDATE == pParameter->eState)
            {
                finalParameter = (DBool)(pParameter->nData);
            }
            else
            {
                finalParameter = bDefaultValue;
            }
        }
        else
        {
            finalParameter = bDefaultValue;
        }
    }
    else
    {
        finalParameter = bDefaultValue;
    }

    return finalParameter;
}

DInt32 dtsUpdateForInt32(DtsParameterController *pControler, DUInt16 nId, DInt32 nDefaultValue)
{
    DInt32 finalParameter = nDefaultValue;

    if (pControler != NULL)
    {
        DtsParameter *pParameter = NULL;

        if (dtsParameterControllerFind(pControler, nId, &pParameter) == TRUE)
        {
            if (
                sizeof(DInt32) == pParameter->nSize &&
                pParameter->bIsUpdatable == TRUE &&
                DTS_PARAMETER_STATE_UPDATE == pParameter->eState)
            {
                finalParameter = (DInt32)(pParameter->nData);
            }
            else
            {
                finalParameter = nDefaultValue;
            }
        }
        else
        {
            finalParameter = nDefaultValue;
        }
    }
    else
    {
        finalParameter = nDefaultValue;
    }

    return finalParameter;
}

DFloat64 dtsUpdateForFloat64(DtsParameterController *pControler, DUInt16 nId, DFloat64 dDefaultValue)
{
    DFloat64 finalParameter = dDefaultValue;

    if (pControler != NULL)
    {
        DtsParameter *pParameter = NULL;

        if (dtsParameterControllerFind(pControler, nId, &pParameter) == TRUE)
        {
            if (
                pParameter->nSize == sizeof(DFloat64) &&
                pParameter->bIsUpdatable == TRUE &&
                DTS_PARAMETER_STATE_UPDATE == pParameter->eState)
            {
                dtsMemCopy(
                    (DVoidPointer)&finalParameter,
                    (DConstVoidPointer)&pParameter->nData,
                    sizeof(DFloat64));
            }
            else
            {
                dtsMemCopy(
                    (DVoidPointer)&finalParameter,
                    (DConstVoidPointer)&dDefaultValue,
                    sizeof(DFloat64));
            }
        }
        else
        {
            dtsMemCopy(
                (DVoidPointer)&finalParameter,
                (DConstVoidPointer)&dDefaultValue,
                sizeof(DFloat64));
        }
    }
    else
    {
        dtsMemCopy(
            (DVoidPointer)&finalParameter,
            (DConstVoidPointer)&dDefaultValue,
            sizeof(DFloat64));
    }

    return finalParameter;
}