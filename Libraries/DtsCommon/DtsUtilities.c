#include "DtsCommon/DtsUtilities.h"
#include <string.h>

DVoidPointer dtsMemSet(DVoidPointer destination, DInt32 value, DSize length)
{
    return memset(destination, value, length);
}

DVoidPointer dtsMemCopy(DVoidPointer destination, DConstVoidPointer source, DSize length)
{
    return memcpy(destination, source, length);
}

DBool dtsSwap(DVoidPointer pValue, DSize nValueSize)
{
    DBool result = FALSE;

    if(pValue != NULL && nValueSize > 0)
    {
        DBytePointer pValueAsByte = (DBytePointer)pValue;
        DSize nHalfValueSize = nValueSize / 2;
        DSize nValueIndex = 0;
        for(nValueIndex = 0; nValueIndex < nHalfValueSize; nValueIndex++)
        {
            DByte temp = pValueAsByte[nValueIndex];
            pValueAsByte[nValueIndex] = pValueAsByte[nValueSize - nValueIndex - 1];
            pValueAsByte[nValueSize - nValueIndex - 1] = temp;
        }
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}