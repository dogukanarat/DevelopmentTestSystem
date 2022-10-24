#ifndef INCLUDED_DTSPARAMETER_H
#define INCLUDED_DTSPARAMETER_H

#include "DtsCommon/DtsCommon.h"

typedef enum
{
    DTS_PARAMETER_STATE_IDLE = 0,
    DTS_PARAMETER_STATE_UPDATE,
} DtsParameterState;

#pragma pack(push, 1)
typedef struct 
{
    DInt16 nId;
    DUInt16 nSize;
    DUInt64 nData;
    DBool bIsMonitorable;
    DBool bIsUpdatable;
    DtsParameterState eState;
} DtsParameter;
#pragma pack(pop)

#endif // INCLUDED_DTSPARAMETER_H
