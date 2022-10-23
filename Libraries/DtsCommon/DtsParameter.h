#ifndef INCLUDED_DTSPARAMETER_H
#define INCLUDED_DTSPARAMETER_H

#include "DtsCommon/DtsCommon.h"

typedef struct 
{
    DInt16 nId;
    DUInt16 nSize;
    DUInt64 nData;
    DBool bIsMonitorable;
    DBool bIsUpdatable;
} DtsParameter;

#endif // INCLUDED_DTSPARAMETER_H
