#include <gtest/gtest.h>

extern "C"
{
    #include "DtsCommon/DtsUtilities.h"
}

TEST(DtsUtilitiesTest, memCopy)
{
    DByte pSource[128];
    DByte pDestination[128];
    DSize nSize = 128;

    dtsMemCopy((DVoidPointer)pDestination,(DVoidPointer)pSource, nSize);


    for(DSize i = 0; i < nSize; i++)
    {
        EXPECT_EQ(pSource[i], pDestination[i]);
    }
}

TEST(DtsUtilitiesTest, memSet)
{
    DByte pDestination[128];
    DSize nSize = 128;
    DByte nValue = 0x55;

    dtsMemSet((DVoidPointer)pDestination, nValue, nSize);

    for(DSize i = 0; i < nSize; i++)
    {
        EXPECT_EQ(nValue, pDestination[i]);
    }
}

TEST(DtsUtilitiesTest, dtsSwap)
{
    DUInt16 nValue = 0x1234;
    DUInt16 nSwappedValue = 0x3412;

    DBool result = dtsSwap((DVoidPointer)(&nValue), (DSize)(sizeof(nValue)));

    EXPECT_EQ(TRUE, result);

    EXPECT_EQ(nSwappedValue, nValue);
}