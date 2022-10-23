#ifndef TESTDTSMONITOR_H
#define TESTDTSMONITOR_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
#include "DtsCommon/DtsMonitor.h"
}

#include "TestProjectSpesificCommon.h"

class TestDtsMonitor : public ::testing::Test
{
public:
    TestDtsMonitor()
    {
    }
    virtual ~TestDtsMonitor()
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


#endif // TESTDTSMONITOR_H
