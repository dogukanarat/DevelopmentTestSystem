#ifndef INCLUDED_DTSMONITOR_H
#define INCLUDED_DTSMONITOR_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameter.h"
#include "DtsCommon/DtsParameterController.h"

DBool dtsMonitorForBool(DtsParameterController* pControler, DUInt16 nId, DBool bCurrentValue);
DBool dtsMonitorForInt32(DtsParameterController* pControler, DUInt16 nId, DInt32 nCurrentValue);
DBool dtsMonitorForFloat64(DtsParameterController* pControler, DUInt16 nId, DFloat64 dCurrentValue);

#endif // INCLUDED_DTSMONITOR_H
