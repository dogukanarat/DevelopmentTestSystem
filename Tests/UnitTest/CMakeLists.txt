include(${DTS_CMAKE_DIR}/Applications.cmake)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG  release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

option(INSTALL_GTEST "Enable installation of googletest." OFF)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(
    DtsUnitTest
    Main.cpp
    TestDtsUtilities.cpp
    TestDtsCircularBuffer.cpp
    TestDtsIterator.cpp
    TestDtsParameterController.cpp
    TestDtsParameterController.h
    TestProjectSpesificCommon.cpp
    TestDtsUpdate.cpp
    TestDtsMonitor.cpp
    TestDtsProtocol.cpp
)

target_compile_definitions(DtsUnitTest PUBLIC CTEST)

target_link_libraries(
    DtsUnitTest
      gtest_main
      DtsCommon
)

gtest_discover_tests(DtsUnitTest
    PROPERTIES
        LABELS "unit"
    DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
        240
)
