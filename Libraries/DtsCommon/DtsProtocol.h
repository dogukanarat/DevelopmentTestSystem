#ifndef INCLUDED_DTSPROTOCOL_H
#define INCLUDED_DTSPROTOCOL_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsIterator.h"
#include "DtsCommon/DtsParameterController.h"

DBool dtsProtocolSetHeader(DtsIterator* pIterator, DUInt16 nHeader);

DBool dtsProtocolSetValue(DtsIterator* pIterator, DConstVoidPointer pValue, DSize nValueSize);

DBool dtsProtocolSetParameter(DtsIterator* pIterator, const DtsParameter* pParameter);

DBool dtsProtocolCreateMonitorMessage(DtsIterator* pIterator, const DtsParameterController* pController);

#endif // INCLUDED_DTSPROTOCOL_H
