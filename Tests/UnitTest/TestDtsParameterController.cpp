#include "TestDtsParameterController.h"

// This definition is project spesific
DtsParameter g_projectParameters[PRIVATE_PARAMETER_COUNT] =
{
        {PRIVATE_PARAMETER_1_DEC, 8, 0, TRUE, TRUE},
        {PRIVATE_PARAMETER_2_INT, 4, 0, TRUE, TRUE},
        {PRIVATE_PARAMETER_3_BOOL, 1, 0, TRUE, TRUE},
};

TEST_F(TestDtsParameterController, dtsParameterControllerInitialize)
{
    DBool result = dtsParameterControllerInitialize(
        &m_parameterController,
        g_projectParameters,
        PRIVATE_PARAMETER_COUNT);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(PRIVATE_PARAMETER_COUNT, m_parameterController.nParameterCount);
    EXPECT_EQ(g_projectParameters, m_parameterController.pParameters);
    EXPECT_EQ(TRUE, m_parameterController.bIsInitialized);
}

TEST_F(TestDtsParameterController, dtsParameterControllerFind)
{
    DtsParameter *pParameter = NULL;

    DBool result = dtsParameterControllerFind(
        &m_parameterController,
        PRIVATE_PARAMETER_1_DEC,
        &pParameter);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(&g_projectParameters[PRIVATE_PARAMETER_1_DEC], pParameter);

    result = dtsParameterControllerFind(
        &m_parameterController,
        PRIVATE_PARAMETER_2_INT,
        &pParameter);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(&g_projectParameters[PRIVATE_PARAMETER_2_INT], pParameter);

    result = dtsParameterControllerFind(
        &m_parameterController,
        PRIVATE_PARAMETER_3_BOOL,
        &pParameter);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(&g_projectParameters[PRIVATE_PARAMETER_3_BOOL], pParameter);
}