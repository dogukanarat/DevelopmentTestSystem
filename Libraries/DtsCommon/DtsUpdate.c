#include "DtsCommon/DtsUpdate.h"

DBool dtsUpdateForBool(DtsParameterController* pControler, DUInt16 nId, DBool bDefaultValue)
{
    DBool finalParameter = bDefaultValue;

    if(pControler != NULL)
    {
        DtsParameter* pParameter = NULL;
        if(dtsParameterControllerFind(pControler, nId, &pParameter) == TRUE)
        {
            if(pParameter->nSize == sizeof(DBool))
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

DInt32 dtsUpdateForInt32(DtsParameterController* pControler, DUInt16 nId, DInt32 nDefaultValue)
{
    DInt32 finalParameter = nDefaultValue;

    if(pControler != NULL)
    {
        DtsParameter* pParameter = NULL;

        if(dtsParameterControllerFind(pControler, nId, &pParameter) == TRUE)
        {
            if(pParameter->nSize == sizeof(DInt32))
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

DFloat64 dtsUpdateForFloat64(DtsParameterController* pControler, DUInt16 nId, DFloat64 dDefaultValue)
{
    DFloat64 finalParameter = dDefaultValue;

    if(pControler != NULL)
    {
        DtsParameter* pParameter = NULL;

        if(dtsParameterControllerFind(pControler, nId, &pParameter) == TRUE)
        {
            if(pParameter->nSize == sizeof(DFloat64))
            {
                finalParameter = (DFloat64)(pParameter->nData);
            }
            else
            {
                finalParameter = dDefaultValue;
            }
        }
        else
        {
            finalParameter = dDefaultValue;
        }
    }
    else
    {
        finalParameter = dDefaultValue;
    }

    return finalParameter;
}