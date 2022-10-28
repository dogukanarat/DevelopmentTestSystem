#ifndef INCLUDED_DTSSERVER_H
#define INCLUDED_DTSSERVER_H

#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
#include "DtsCommon/DtsIterator.h"
#include "DtsCommon/DtsProtocol.h"

typedef enum
{
    // The server is waiting for any message
    DTS_SERVER_STATE_IDLE = 0,
    // The server is sending monitor messages
    DTS_SERVER_STATE_MONITOR,
    // The server is receiving a update data message chunks 
    DTS_SERVER_STATE_PROCESSING,
    // The server is waiting for a start command message
    DTS_SERVER_STATE_ARM,
    // The server is processing update messages
    DTS_SERVER_STATE_RUNNING,
} DtsServerState;

typedef struct
{ 
    DBool bIsDiscoveryPacketReceived;
} DtsServerFlags;

typedef struct
{
    DtsParameterController sParameterController;
    DtsServerState eState;
    DBytePointer pReceiveBuffer;
    DSize nReceiveBufferSize;
    DBytePointer pTransmitBuffer;
    DSize nTransmitBufferSize;
    DBool bIsInitialized;
    DtsServerFlags sFlags;
    DtsIterator sIteratorTransmit;
    DtsIterator sIteratorReceive;
} DtsServer;

DBool dtsServerInitialize(
    DtsServer* pServer,
    DtsParameter* pParameters,
    DSize nParameterCount,
    DBytePointer pReceiveBuffer,
    DSize nReceiveBufferSize,
    DBytePointer pTransmitBuffer,
    DSize nTransmitBufferSize
    );

DBool dtsServerMain(DtsServer* pServer);

DBool dtsServerMonitorMain(DtsServer* pServer);

DBool dtsServerUpdateMain(DtsServer* pServer);

DBool dtsServerResolverMain(DtsServer *pServer);

DBool dtsServerProcessStateTransition(DtsServer* pServer);

#endif // INCLUDED_DTSSERVER_H
