#ifndef INCLUDED_DTSPROTOCOL_H
#define INCLUDED_DTSPROTOCOL_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsIterator.h"
#include "DtsCommon/DtsParameterController.h"

typedef enum 
{
    DTS_PROTOCOL_NO_HEADER = 0,
    DTS_PROTOCOL_DISCOVERY_HEADER,
    DTS_PROTOCOL_MONITOR_HEADER,
} DtsProtocolPacketHeader;

DBool dtsProtocolSetHeader(DtsIterator* pIterator, DUInt16 nHeader);

DBool dtsProtocolCreateDiscoveryMessage(DtsIterator* pIterator);

DBool dtsProtocolResolveDiscoveryMessage(DtsIterator* pIterator);

DBool dtsProtocolCreateMonitorMessage(DtsIterator* pIterator, const DtsParameterController* pController);

DBool dtsProtocolResolveMonitorMessage(DtsIterator* pIterator, DtsParameterController* pController);

#endif // INCLUDED_DTSPROTOCOL_H
