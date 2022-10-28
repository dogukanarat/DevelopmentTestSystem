#include "TestDtsTimeline.h"

TEST_F(TestDtsTimeline, TestDtsTimelineInitialize)
{
    DBool result = FALSE;
    DtsTimelineParameter aTimelineParameterBuffer[128];
    DtsTimeline timeline;

    result = dtsTimelineInitialize(
        &timeline,
        &m_parameterController,
        aTimelineParameterBuffer,
        128);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(&m_parameterController, timeline.pController);
    EXPECT_EQ(aTimelineParameterBuffer, timeline.pTimelineParameter);
    EXPECT_EQ(128, timeline.nTimelineParameterCount);
    EXPECT_EQ(TRUE, timeline.bIsInitialized);
    EXPECT_EQ(0, timeline.nAppendedParameterCount);
}

TEST_F(TestDtsTimeline, TestDtsTimelineAppend)
{
    DBool result = FALSE;
    DtsTimelineParameter aTimelineParameterBuffer[128];
    DtsTimeline timeline;

    result = dtsTimelineInitialize(
        &timeline,
        &m_parameterController,
        aTimelineParameterBuffer,
        128);

    EXPECT_EQ(TRUE, result);

    DInt32 appendDataDecimal = 123;

    result = dtsTimelineParameterAppend(
        &timeline,
        PRIVATE_PARAMETER_1_DEC,
        appendDataDecimal,
        999);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(1, timeline.nAppendedParameterCount);

    EXPECT_EQ(
        aTimelineParameterBuffer[0].pParameter,
        &m_parameterController.pParameters[PRIVATE_PARAMETER_1_DEC]);
        
    EXPECT_EQ(aTimelineParameterBuffer[0].nData, appendDataDecimal);
    EXPECT_EQ(aTimelineParameterBuffer[0].nCycle, 999);
}
