#include <gtest/gtest.h>

extern "C"
{
    #include "DtsCommon/DtsIterator.h"
}

TEST(DtsIteratorTest, dtsIteratorInitialize)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;

    DBool result = dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(0, iterator.nCurrentIndex);
    EXPECT_EQ(pRawBuffer, iterator.pRawBuffer);
    EXPECT_EQ(128, iterator.nRawBufferSize);
}

TEST(DtsIteratorTest, dtsIteratorInitializeWithNull)
{
    DtsIterator iterator;

    DBool result = dtsIteratorInitialize(&iterator, NULL, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorInitializeWithZeroSize)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;

    DBool result = dtsIteratorInitialize(&iterator, pRawBuffer, 0, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorInitializeWithNullIterator)
{
    DByte pRawBuffer[128];

    DBool result = dtsIteratorInitialize(NULL, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorGetSize)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;

    dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    for(int i = 0; i < 128; i++)
    {
        dtsIteratorWrite(&iterator, (DConstBytePointer)&i, 1);
    }

    DUInt32 nSize = dtsIteratorGetSize(&iterator);

    EXPECT_EQ(128, nSize);
}

TEST(DtsIteratorTest, dtsIteratorWrite)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;

    dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    DByte pSource[128];
    DSize nSize = 128;

    DBool result = dtsIteratorWrite(&iterator, pSource, nSize);

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(nSize, iterator.nCurrentIndex);

    for(DSize i = 0; i < nSize; i++)
    {
        EXPECT_EQ(pSource[i], pRawBuffer[i]);
    }
}

TEST(DtsIteratorTest, dtsIteratorWriteWithNull)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;

    dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    DSize nSize = 128;

    DBool result = dtsIteratorWrite(&iterator, NULL, nSize);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorWriteWithZeroSize)
{
    DByte pRawBuffer[128];
    DtsIterator iterator;

    dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    DByte pSource[128];

    DBool result = dtsIteratorWrite(&iterator, pSource, 0);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorWriteWithSmallChunks)
{
    DByte pRawBuffer[128];
    DByte pSource[128];
    DtsIterator iterator;
    DSize nSize = 128;

    memset(pSource, 0, nSize);
    memset(pRawBuffer, 0, nSize);

    for(DSize i = 0; i < nSize; i++)
    {
        pSource[i] = i;
    }

    dtsIteratorInitialize(&iterator, pRawBuffer, 128, DTS_ITERATOR_WRITE, DTS_ITERATOR_NO_BLOCK_SIZE);

    for(DSize i = 0; i < nSize; i++)
    {
        DBool result = dtsIteratorWrite(&iterator, &pSource[i], 1);

        EXPECT_EQ(TRUE, result);

        EXPECT_EQ(i + 1, iterator.nCurrentIndex);

        EXPECT_EQ(pSource[i], pRawBuffer[i]);
    }

    DBool result = dtsIteratorWrite(&iterator, pSource, 1);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorRead)
{
    DByte pSource[128];
    DSize nSize = 128;
    DtsIterator iterator;

    for(DSize i = 0; i < nSize; i++)
    {
        pSource[i] = i;
    }

    dtsIteratorInitialize(&iterator, pSource, 128, DTS_ITERATOR_READ, DTS_ITERATOR_NO_BLOCK_SIZE);

    DByte pDestination[128];

    DBool result = dtsIteratorRead(&iterator, pDestination, nSize);

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(nSize, iterator.nCurrentIndex);

    for(DSize i = 0; i < nSize; i++)
    {
        EXPECT_EQ(pSource[i], pDestination[i]);
    }
}

TEST(DtsIteratorTest, dtsIteratorReadWithNull)
{
    DByte pSource[128];
    DSize nSize = 128;
    DtsIterator iterator;

    dtsIteratorInitialize(&iterator, pSource, 128, DTS_ITERATOR_READ, DTS_ITERATOR_NO_BLOCK_SIZE);

    DBool result = dtsIteratorRead(&iterator, NULL, nSize);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorReadWithZeroSize)
{
    DByte pSource[128];
    DtsIterator iterator;

    dtsIteratorInitialize(&iterator, pSource, 128, DTS_ITERATOR_READ, DTS_ITERATOR_NO_BLOCK_SIZE);

    DByte pDestination[128];

    DBool result = dtsIteratorRead(&iterator, pDestination, 0);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorReadWithSmallChunks)
{
    DByte pSource[128];
    DByte pDestination[128];
    DSize nSize = 128;
    DtsIterator iterator;

    memset(pSource, 0, nSize);
    memset(pDestination, 0, nSize);

    for(DSize i = 0; i < nSize; i++)
    {
        pSource[i] = i;
    }

    dtsIteratorInitialize(&iterator, pSource, 128, DTS_ITERATOR_READ, DTS_ITERATOR_NO_BLOCK_SIZE);

    for(DSize i = 0; i < nSize; i++)
    {
        DBool result = dtsIteratorRead(&iterator, &pDestination[i], 1);

        EXPECT_EQ(TRUE, result);

        EXPECT_EQ(i + 1, iterator.nCurrentIndex);

        EXPECT_EQ(pSource[i], pDestination[i]);
    }

    DBool result = dtsIteratorRead(&iterator, pDestination, 1);

    EXPECT_EQ(FALSE, result);
}

TEST(DtsIteratorTest, dtsIteratorForwardIterator)
{
    typedef struct
    {
        DInt16 nValue1;
        DInt32 nValue2;
    } DtsTestStruct;

    DtsTestStruct pTestStruct[12];

    for(DSize i = 0; i < 12; i++)
    {
        pTestStruct[i].nValue1 = i;
        pTestStruct[i].nValue2 = i * 2 + 1;
    }

    DtsIterator iterator;

    dtsIteratorInitialize(
        &iterator,
        (DBytePointer)pTestStruct,
        sizeof(pTestStruct),
        DTS_ITERATOR_FORWARD,
        sizeof(DtsTestStruct)
        );

    DtsTestStruct* pActualTestStruct;

    for(DSize i = 0; i < 12; i++)
    {
        DBool result = dtsIteratorNext(&iterator, (DBytePointer*)&pActualTestStruct);

        EXPECT_EQ(TRUE, result);

        EXPECT_EQ(&pTestStruct[i], pActualTestStruct);
    }

    DBool lastResult = dtsIteratorNext(&iterator, (DBytePointer*)&pActualTestStruct);

    EXPECT_EQ(FALSE, lastResult);
}