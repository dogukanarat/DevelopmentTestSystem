#include "TestDtsMonitor.h"

TEST_F(TestDtsMonitor, dtsMonitorForBool)
{
    DBool monitoredValue = TRUE;
    DBool result = FALSE;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_3_BOOL].eState = DTS_PARAMETER_STATE_IDLE;
    g_projectParameters[PRIVATE_PARAMETER_3_BOOL].nData = !monitoredValue;

    result = dtsMonitorForBool(&m_parameterController, PRIVATE_PARAMETER_3_BOOL, monitoredValue);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(monitoredValue, g_projectParameters[PRIVATE_PARAMETER_3_BOOL].nData);
}

TEST_F(TestDtsMonitor, dtsMonitorForInt32)
{
    DInt32 monitoredValue = 1234;
    DBool result = FALSE;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_2_INT].eState = DTS_PARAMETER_STATE_IDLE;
    g_projectParameters[PRIVATE_PARAMETER_2_INT].nData = 0;

    result = dtsMonitorForInt32(&m_parameterController, PRIVATE_PARAMETER_2_INT, monitoredValue);

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(monitoredValue, g_projectParameters[PRIVATE_PARAMETER_2_INT].nData);
}

TEST_F(TestDtsMonitor, dtsMonitorForFloat64)
{
    DFloat64 monitoredValue = 1234.5678;
    DFloat64 monitoredValueStored = 0.0;
    DBool result = FALSE;

    // This is just for test
    g_projectParameters[PRIVATE_PARAMETER_1_DEC].eState = DTS_PARAMETER_STATE_IDLE;

    memcpy(
        &g_projectParameters[PRIVATE_PARAMETER_1_DEC].nData,
        &monitoredValueStored,
        sizeof(monitoredValueStored)
        );

    result = dtsMonitorForFloat64(&m_parameterController, PRIVATE_PARAMETER_1_DEC, monitoredValue);

    memcpy(
        &monitoredValueStored,
        &g_projectParameters[PRIVATE_PARAMETER_1_DEC].nData,
        sizeof(monitoredValueStored)
        );

    EXPECT_EQ(TRUE, result);
    EXPECT_EQ(monitoredValue, monitoredValueStored);
}