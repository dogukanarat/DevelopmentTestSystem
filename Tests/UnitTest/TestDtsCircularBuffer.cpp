#include <gtest/gtest.h>

extern "C"
{
    #include "DtsCommon/DtsCircularBuffer.h"
}

TEST(DtsCircularBufferTest, dtsCircularBufferInitialize)
{
    DtsCircularBuffer buffer;
    DBool result = dtsCircularBufferInitialize(&buffer);
    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(NULL, buffer.pBuffer);
    EXPECT_EQ(0, buffer.nBufferSize);
    EXPECT_EQ(0, buffer.nBufferHead);
    EXPECT_EQ(0, buffer.nBufferTail);
    EXPECT_EQ(0, buffer.nBufferCount);
}

TEST(DtsCircularBufferTest, dtsCircularBufferSetBuffer)
{
    DtsCircularBuffer buffer;
    DBool result = dtsCircularBufferInitialize(&buffer);
    EXPECT_EQ(TRUE, result);
    DByte bufferArray[10];
    result = dtsCircularBufferSetBuffer(&buffer, bufferArray, 10);
    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(bufferArray, buffer.pBuffer);
    EXPECT_EQ(10, buffer.nBufferSize);
    EXPECT_EQ(0, buffer.nBufferHead);
    EXPECT_EQ(0, buffer.nBufferTail);
    EXPECT_EQ(0, buffer.nBufferCount);
}

TEST(DtsCircularBufferTest, dtsCircularBufferClear)
{
    DtsCircularBuffer buffer;
    DBool result = dtsCircularBufferInitialize(&buffer);
    EXPECT_EQ(TRUE, result);
    DByte bufferArray[10];
    result = dtsCircularBufferSetBuffer(&buffer, bufferArray, 10);
    EXPECT_EQ(TRUE, result);
    result = dtsCircularBufferClear(&buffer);
    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(bufferArray, buffer.pBuffer);
    EXPECT_EQ(10, buffer.nBufferSize);
    EXPECT_EQ(0, buffer.nBufferHead);
    EXPECT_EQ(0, buffer.nBufferTail);
    EXPECT_EQ(0, buffer.nBufferCount);
}

TEST(DtsCircularBufferTest, dtsCircularBufferPush)
{
    DtsCircularBuffer buffer;
    DBool result = dtsCircularBufferInitialize(&buffer);
    EXPECT_EQ(TRUE, result);
    DByte bufferArray[10];
    result = dtsCircularBufferSetBuffer(&buffer, bufferArray, 10);
    EXPECT_EQ(TRUE, result);
    DByte sourceArray[5] = {1, 2, 3, 4, 5};
    result = dtsCircularBufferPush(&buffer, sourceArray, 5);
    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(bufferArray, buffer.pBuffer);
    EXPECT_EQ(10, buffer.nBufferSize);
    EXPECT_EQ(0, buffer.nBufferHead);
    EXPECT_EQ(5, buffer.nBufferTail);
    EXPECT_EQ(5, buffer.nBufferCount);
}

TEST(DtsCircularBufferTest, dtsCircularBufferPop)
{
    DtsCircularBuffer buffer;
    DBool result = dtsCircularBufferInitialize(&buffer);
    EXPECT_EQ(TRUE, result);
    DByte bufferArray[10];
    result = dtsCircularBufferSetBuffer(&buffer, bufferArray, 10);
    EXPECT_EQ(TRUE, result);
    DByte sourceArray[5] = {1, 2, 3, 4, 5};
    result = dtsCircularBufferPush(&buffer, sourceArray, 5);
    EXPECT_EQ(TRUE, result);
    DByte destinationArray[5];
    result = dtsCircularBufferPop(&buffer, destinationArray, 5);
    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(bufferArray, buffer.pBuffer);
    EXPECT_EQ(10, buffer.nBufferSize);
    EXPECT_EQ(5, buffer.nBufferHead);
    EXPECT_EQ(5, buffer.nBufferTail);
    EXPECT_EQ(0, buffer.nBufferCount);
}
