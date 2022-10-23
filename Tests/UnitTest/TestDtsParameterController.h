#ifndef TESTDTSPARAMETERCONTROLLER_H
#define TESTDTSPARAMETERCONTROLLER_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
}

// This definition is project spesific
typedef enum
{
    PRIVATE_PARAMETER_1_DEC = 0,
    PRIVATE_PARAMETER_2_INT,
    PRIVATE_PARAMETER_3_BOOL,
    PRIVATE_PARAMETER_COUNT,
} ProjectParameters;

// This declaration is project spesific
extern DtsParameter g_projectParameters[PRIVATE_PARAMETER_COUNT];

class TestDtsParameterController : public ::testing::Test
{
public:
    TestDtsParameterController()
    {

    }
    virtual ~TestDtsParameterController()
    {

    }

    virtual void SetUp()
    {
        dtsParameterControllerInitialize(
            &m_parameterController,
            g_projectParameters,
            PRIVATE_PARAMETER_COUNT);
    }
    virtual void TearDown()
    {
    }

protected:
    DtsParameterController m_parameterController;
};

#endif // TESTDTSPARAMETERCONTROLLER_H
