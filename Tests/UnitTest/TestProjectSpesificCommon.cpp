#include "TestProjectSpesificCommon.h"

// This definition is project spesific
DtsParameter g_projectParameters[PRIVATE_PARAMETER_COUNT] =
{
        {
            PRIVATE_PARAMETER_1_DEC, /* nId */
            8, /* nSize */
            0, /* nData */
            TRUE, /* bIsMonitorable */
            TRUE, /* bIsUpdatable */
            DTS_PARAMETER_STATE_IDLE /* eState */
        },
        {
            PRIVATE_PARAMETER_2_INT, /* nId */
            4, /* nSize */
            0, /* nData */
            TRUE, /* bIsMonitorable */
            TRUE, /* bIsUpdatable */
            DTS_PARAMETER_STATE_IDLE /* eState */
        },
        {
            PRIVATE_PARAMETER_3_BOOL, /* nId */
            1, /* nSize */
            0, /* nData */
            TRUE, /* bIsMonitorable */
            TRUE, /* bIsUpdatable */
            DTS_PARAMETER_STATE_IDLE /* eState */
        },
};

// This definition is project spesific
DtsParameter g_projectParametersClient[PRIVATE_PARAMETER_COUNT] =
{
        {
            PRIVATE_PARAMETER_1_DEC, /* nId */
            8, /* nSize */
            0, /* nData */
            TRUE, /* bIsMonitorable */
            TRUE, /* bIsUpdatable */
            DTS_PARAMETER_STATE_IDLE /* eState */
        },
        {
            PRIVATE_PARAMETER_2_INT, /* nId */
            4, /* nSize */
            0, /* nData */
            TRUE, /* bIsMonitorable */
            TRUE, /* bIsUpdatable */
            DTS_PARAMETER_STATE_IDLE /* eState */
        },
        {
            PRIVATE_PARAMETER_3_BOOL, /* nId */
            1, /* nSize */
            0, /* nData */
            TRUE, /* bIsMonitorable */
            TRUE, /* bIsUpdatable */
            DTS_PARAMETER_STATE_IDLE /* eState */
        },
};