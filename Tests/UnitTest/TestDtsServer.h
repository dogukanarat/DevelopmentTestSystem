#ifndef TESTDTSSERVER_H
#define TESTDTSSERVER_H

#include <gtest/gtest.h>

extern "C"
{
#include "DtsCommon/DtsCommon.h"
#include "DtsCommon/DtsServer.h"
}

#include "TestProjectSpesificCommon.h"

class TestDtsServer : public ::testing::Test
{
public:
    TestDtsServer()
    {
    }
    virtual ~TestDtsServer()
    {
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

protected:
    DByte m_transmitBuffer[256];
    DByte m_receiveBuffer[256];
    DtsServer m_server;
};


#endif // TESTDTSSERVER_H
