#ifndef INCLUDED_DTSCOMMON_H
#define INCLUDED_DTSCOMMON_H

#include "stdint.h"

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef DTS_EXPECT
#include <assert.h>
#define DTS_EXPECT(A) assert(A);
#endif

#ifndef DTS_NO_IMPLEMENTATION
#define DTS_NO_IMPLEMENTATION
#endif

#ifndef DTS_UNUSED_PARAMETER
#define DTS_UNUSED_PARAMETER(A) (void)(A);
#endif

#ifndef DTS_TYPE_DEFINITION
#define DTS_TYPE_DEFINITION
typedef uint8_t UInt8;
typedef uint16_t DUInt16;
typedef uint32_t DUInt32;
typedef uint64_t DUInt64;
typedef int8_t DInt8;
typedef int16_t DInt16;
typedef int32_t DInt32;
typedef int64_t DInt64;
typedef float DFloat32;
typedef double DFloat64;
typedef UInt8 DBool;
typedef void *Void;
typedef Void *DVoidPointer;
typedef const DVoidPointer DConstVoidPointer;
typedef UInt8 DByte;
typedef DByte *DBytePointer;
typedef const DBytePointer DConstBytePointer;
typedef DUInt32 DSize;
#endif

#ifndef DTS_ENDIAN_DEFINITION
#define DTS_ENDIAN_DEFINITION
typedef enum
{
    DTS_ENDIAN_LITTLE = 0,
    DTS_ENDIAN_BIG
} DtsEndian;
#endif

#endif // INCLUDED_DTSCOMMON_H
