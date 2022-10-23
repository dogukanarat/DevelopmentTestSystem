#include "TestDtsUpdate.h"

TEST_F(TestDtsUpdate, dtsUpdateForBoolDefault)
{
    DBool valueDefault = TRUE;
    DBool valueUpdated = FALSE;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_3_BOOL].eState = DTS_PARAMETER_STATE_IDLE;
    g_projectParameters[PRIVATE_PARAMETER_3_BOOL].nData = !valueDefault;

    valueUpdated = dtsUpdateForBool(&m_parameterController, PRIVATE_PARAMETER_3_BOOL, valueDefault);

    EXPECT_EQ(valueDefault, valueUpdated);
}

TEST_F(TestDtsUpdate, dtsUpdateForBoolUpdated)
{
    DBool valueDefault = TRUE;
    DBool valueUpdated = FALSE;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_3_BOOL].eState = DTS_PARAMETER_STATE_UPDATE;
    g_projectParameters[PRIVATE_PARAMETER_3_BOOL].nData = !valueDefault;

    valueUpdated = dtsUpdateForBool(&m_parameterController, PRIVATE_PARAMETER_3_BOOL, valueDefault);

    EXPECT_EQ(!valueDefault, valueUpdated);
}

TEST_F(TestDtsUpdate, dtsUpdateForInt32Default)
{
    DInt32 valueDefault = 123;
    DInt32 valueUpdated = 0;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_2_INT].eState = DTS_PARAMETER_STATE_IDLE;
    g_projectParameters[PRIVATE_PARAMETER_2_INT].nData = 0;

    valueUpdated = dtsUpdateForInt32(&m_parameterController, PRIVATE_PARAMETER_2_INT, valueDefault);

    EXPECT_EQ(valueDefault, valueUpdated);
}

TEST_F(TestDtsUpdate, dtsUpdateForInt32Updated)
{
    DInt32 valueDefault = 123;
    DInt32 valueUpdated = 0;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_2_INT].eState = DTS_PARAMETER_STATE_UPDATE;
    g_projectParameters[PRIVATE_PARAMETER_2_INT].nData = 456;

    valueUpdated = dtsUpdateForInt32(&m_parameterController, PRIVATE_PARAMETER_2_INT, valueDefault);

    EXPECT_EQ(456, valueUpdated);
}

TEST_F(TestDtsUpdate, dtsUpdateForFloat64Default)
{
    DFloat64 valueDefault = 123.456;
    DFloat64 valueWillBeUpdated = 0.0;
    DFloat64 valueUpdated = 0;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_1_DEC].eState = DTS_PARAMETER_STATE_IDLE;
    memcpy(&g_projectParameters[PRIVATE_PARAMETER_1_DEC].nData, &valueWillBeUpdated, sizeof(DFloat64));

    valueUpdated = dtsUpdateForFloat64(&m_parameterController, PRIVATE_PARAMETER_1_DEC, valueDefault);

    EXPECT_EQ(valueDefault, valueUpdated);
}

TEST_F(TestDtsUpdate, dtsUpdateForFloat64Updated)
{
    DFloat64 valueDefault = 123.456;
    DFloat64 valueWillBeUpdated = 456.789;
    DFloat64 valueUpdated = 0;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_1_DEC].eState = DTS_PARAMETER_STATE_UPDATE;
    memcpy(&g_projectParameters[PRIVATE_PARAMETER_1_DEC].nData, &valueWillBeUpdated, sizeof(DFloat64));

    valueUpdated = dtsUpdateForFloat64(&m_parameterController, PRIVATE_PARAMETER_1_DEC, valueDefault);

    EXPECT_EQ(valueUpdated, valueUpdated);
}
