#include "TestDtsServer.h"

TEST_F(TestDtsServer, TestDtsServerInitialize)
{
    DBool result = FALSE;

    result = dtsServerInitialize(
        &m_server,
        g_projectParameters,
        PRIVATE_PARAMETER_COUNT,
        m_receiveBuffer,
        sizeof(m_receiveBuffer),
        m_transmitBuffer,
        sizeof(m_transmitBuffer));

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(sizeof(m_receiveBuffer), m_server.nReceiveBufferSize);
    EXPECT_EQ(sizeof(m_transmitBuffer), m_server.nTransmitBufferSize);
    EXPECT_EQ(DTS_SERVER_STATE_IDLE, m_server.eState);
    EXPECT_EQ(TRUE, m_server.bIsInitialized);
    EXPECT_EQ(FALSE, m_server.sFlags.bIsDiscoveryPacketReceived);

}

TEST_F(TestDtsServer, TestDtsServerMonitoringFeature)
{
    DBool result = FALSE;

    result = dtsServerInitialize(
        &m_server,
        g_projectParameters,
        PRIVATE_PARAMETER_COUNT,
        m_receiveBuffer,
        sizeof(m_receiveBuffer),
        m_transmitBuffer,
        sizeof(m_transmitBuffer));

    DtsIterator sIteratorReceive;

    dtsIteratorInitialize(
        &sIteratorReceive,
        m_server.pReceiveBuffer,
        m_server.nReceiveBufferSize,
        DTS_ITERATOR_WRITE,
        DTS_ITERATOR_NO_BLOCK_SIZE
        );

    result = dtsProtocolCreateDiscoveryMessage(&sIteratorReceive);

    EXPECT_EQ(TRUE, result);

    result = dtsServerMain(&m_server);

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(DTS_SERVER_STATE_MONITOR, m_server.eState);

    DUInt32 counter = 0;

    EXPECT_EQ(DTS_PROTOCOL_MONITOR_HEADER & 0x00FF, m_transmitBuffer[counter++]);
    EXPECT_EQ(DTS_PROTOCOL_MONITOR_HEADER & 0xFF00, m_transmitBuffer[counter++]);
}