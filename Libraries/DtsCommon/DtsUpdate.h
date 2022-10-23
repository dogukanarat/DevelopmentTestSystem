#ifndef INCLUDED_DTSUPDATE_H
#define INCLUDED_DTSUPDATE_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameter.h"
#include "DtsCommon/DtsParameterController.h"

DBool dtsUpdateForBool(DtsParameterController* pControler, DUInt16 nId, DBool bDefaultValue);
DInt32 dtsUpdateForInt32(DtsParameterController* pControler, DUInt16 nId, DInt32 nDefaultValue);
DFloat64 dtsUpdateForFloat64(DtsParameterController* pControler, DUInt16 nId, DFloat64 dDefaultValue);

#endif // INCLUDED_DTSUPDATE_H
