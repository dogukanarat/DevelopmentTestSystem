#ifndef TESTDTSUPDATE_H
#define TESTDTSUPDATE_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
#include "DtsCommon/DtsUpdate.h"
}

#include "TestProjectSpesificCommon.h"

class TestDtsUpdate : public ::testing::Test
{
public:
    TestDtsUpdate()
    {
    }
    virtual ~TestDtsUpdate()
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


#endif // TESTDTSUPDATE_H
