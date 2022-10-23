#ifndef INCLUDED_DTSPROTOCOL_H
#define INCLUDED_DTSPROTOCOL_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsIterator.h"

DBool dtsProtocolSetHeader(DtsIterator* pIterator, DUInt16 nHeader);
DBool dtsProtocolSetValue(DtsIterator* pIterator, DConstVoidPointer pValue, DSize nValueSize);

#endif // INCLUDED_DTSPROTOCOL_H
