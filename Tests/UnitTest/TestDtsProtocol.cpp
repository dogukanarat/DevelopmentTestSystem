#include "TestDtsProtocol.h"

TEST_F(TestDtsProtocol, dtsProtocolSetHeader)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;
    DBool result = FALSE;

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    result = dtsProtocolSetHeader(&iterator, 0x1234);

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(0x34, pRawBuffer[0]);
    EXPECT_EQ(0x12, pRawBuffer[1]);

    EXPECT_EQ(2, iterator.nCurrentIndex);
}

TEST_F(TestDtsProtocol, dtsProtocolSetValue)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;
    DInt32 nValue = 0x12345678;
    DBool result = FALSE;

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    result = dtsProtocolSetValue(&iterator, (DConstVoidPointer)&nValue, sizeof(nValue));

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(0x78, pRawBuffer[0]);
    EXPECT_EQ(0x56, pRawBuffer[1]);
    EXPECT_EQ(0x34, pRawBuffer[2]);
    EXPECT_EQ(0x12, pRawBuffer[3]);

    EXPECT_EQ(4, iterator.nCurrentIndex);
}

TEST_F(TestDtsProtocol, dtsProtocolSetParameter)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;
    DBool result = FALSE;

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    DtsParameter* pParameter = &m_parameterController.pParameters[PRIVATE_PARAMETER_2_INT];

    pParameter->nData = 0x12345678;

    result = dtsProtocolSetParameter(&iterator, pParameter);

    EXPECT_EQ(TRUE, result);

    // Parameter Id
    EXPECT_EQ(0x01, pRawBuffer[0]);
    EXPECT_EQ(0x00, pRawBuffer[1]);

    // Parameter Size
    EXPECT_EQ(0x04, pRawBuffer[2]);
    EXPECT_EQ(0x00, pRawBuffer[3]);

    // Parameter Value
    EXPECT_EQ(0x78, pRawBuffer[4]);
    EXPECT_EQ(0x56, pRawBuffer[5]);
    EXPECT_EQ(0x34, pRawBuffer[6]);
    EXPECT_EQ(0x12, pRawBuffer[7]);
}

TEST_F(TestDtsProtocol, dtsProtocolCreateMonitorMessage)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;
    DBool result = FALSE;

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    DFloat64 decimalValue = 0x12345678;
    DByte decimalValueByteArray[8];

    memcpy(decimalValueByteArray, &decimalValue, sizeof(decimalValue));

    memcpy(
        &m_parameterController.pParameters[PRIVATE_PARAMETER_1_DEC].nData,
        &decimalValue, 
        sizeof(decimalValue)
        );

    m_parameterController.pParameters[PRIVATE_PARAMETER_2_INT].nData = 0x12345678;
    m_parameterController.pParameters[PRIVATE_PARAMETER_3_BOOL].nData = TRUE;

    result = dtsProtocolCreateMonitorMessage(&iterator, &m_parameterController);

    EXPECT_EQ(TRUE, result);

    DUInt16 counter = 0;

    // Header
    EXPECT_EQ(DTS_PROTOCOL_MONITOR_HEADER & 0x00FF, pRawBuffer[counter++]);
    EXPECT_EQ(DTS_PROTOCOL_MONITOR_HEADER & 0xFF00, pRawBuffer[counter++]);

    // PRIVATE_PARAMETER_1_DEC
    // Parameter Id
    EXPECT_EQ(0x00, pRawBuffer[counter++]);
    EXPECT_EQ(0x00, pRawBuffer[counter++]);

    // Parameter Size
    EXPECT_EQ(0x08, pRawBuffer[counter++]);
    EXPECT_EQ(0x00, pRawBuffer[counter++]);

    // Parameter Value
    EXPECT_EQ(decimalValueByteArray[0], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[1], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[2], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[3], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[4], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[5], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[6], pRawBuffer[counter++]);
    EXPECT_EQ(decimalValueByteArray[7], pRawBuffer[counter++]);

    // PRIVATE_PARAMETER_2_INT
    // Parameter Id
    EXPECT_EQ(0x01, pRawBuffer[counter++]);
    EXPECT_EQ(0x00, pRawBuffer[counter++]);

    // Parameter Size
    EXPECT_EQ(0x04, pRawBuffer[counter++]);
    EXPECT_EQ(0x00, pRawBuffer[counter++]);

    // Parameter Value
    EXPECT_EQ(0x78, pRawBuffer[counter++]);
    EXPECT_EQ(0x56, pRawBuffer[counter++]);
    EXPECT_EQ(0x34, pRawBuffer[counter++]);
    EXPECT_EQ(0x12, pRawBuffer[counter++]);

    // PRIVATE_PARAMETER_3_BOOL
    // Parameter Id
    EXPECT_EQ(0x02, pRawBuffer[counter++]);
    EXPECT_EQ(0x00, pRawBuffer[counter++]);

    // Parameter Size
    EXPECT_EQ(0x01, pRawBuffer[counter++]);
    EXPECT_EQ(0x00, pRawBuffer[counter++]);

    // Parameter Value
    EXPECT_EQ(0x01, pRawBuffer[counter++]);
}

TEST_F(TestDtsProtocol, dtsProtocolCreateDiscoveryMessage)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;
    DBool result = FALSE;

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    result = dtsProtocolCreateDiscoveryMessage(&iterator);

    EXPECT_EQ(TRUE, result);

    DUInt16 counter = 0;

    // Discovery Packet Header
    EXPECT_EQ(DTS_PROTOCOL_DISCOVERY_HEADER & 0x00FF, pRawBuffer[counter++]);
    EXPECT_EQ(DTS_PROTOCOL_DISCOVERY_HEADER & 0xFF00, pRawBuffer[counter++]);
}

TEST_F(TestDtsProtocol, dtsProtocolResolveDiscoveryResponseMessage)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;
    DBool result = FALSE;

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    result = dtsProtocolCreateDiscoveryMessage(&iterator);

    EXPECT_EQ(TRUE, result);

    DUInt16 counter = 0;

    // Discovery Packet Header
    EXPECT_EQ(DTS_PROTOCOL_DISCOVERY_HEADER, pRawBuffer[counter++]);

    result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_READ, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    result = dtsProtocolResolveDiscoveryMessage(&iterator);

    EXPECT_EQ(TRUE, result);
}