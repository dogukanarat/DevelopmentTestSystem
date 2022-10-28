#ifndef TESTDTSTIMELINE_H
#define TESTDTSTIMELINE_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsParameterController.h"
#include "DtsCommon/DtsTimeline.h"
}

#include "TestProjectSpesificCommon.h"

class TestDtsTimeline : public ::testing::Test
{
public:
    TestDtsTimeline()
    {
    }
    virtual ~TestDtsTimeline()
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


#endif // TESTDTSTIMELINE_H
