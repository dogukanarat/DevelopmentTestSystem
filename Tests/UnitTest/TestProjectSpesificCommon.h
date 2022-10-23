#ifndef TESTPROJECTSPESIFICCOMMON_H
#define TESTPROJECTSPESIFICCOMMON_H

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

#endif // TESTPROJECTSPESIFICCOMMON_H
