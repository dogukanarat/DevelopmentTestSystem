#ifndef TESTDTSPARAMETERCONTROLLER_H
#define TESTDTSPARAMETERCONTROLLER_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
}

#include "TestProjectSpesificCommon.h"

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
