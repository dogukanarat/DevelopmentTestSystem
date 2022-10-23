
#ifndef TESTDTSPROTOCOL_H
#define TESTDTSPROTOCOL_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
#include "DtsCommon/DtsProtocol.h"
}

#include "TestProjectSpesificCommon.h"

class TestDtsProtocol : public ::testing::Test
{
public:
    TestDtsProtocol()
    {
    }
    virtual ~TestDtsProtocol()
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

#endif // TESTDTSPROTOCOL_H
