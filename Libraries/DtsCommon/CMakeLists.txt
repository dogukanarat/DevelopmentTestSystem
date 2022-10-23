include(${DTS_CMAKE_DIR}/Libraries.cmake)

add_library(
    DtsCommon
)

# target_link_libraries(
#     DtsCommon
#     PRIVATE
# )

target_sources(
    DtsCommon
    PRIVATE
        DtsCommon.c
        DtsUtilities.c
        DtsCircularBuffer.c
        DtsIterator.c
        DtsProtocol.c
        DtsParameterController.c
        DtsSettings.c
        DtsUpdate.c
        DtsMonitor.c
)

target_include_directories(
    DtsCommon 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS DtsCommon
    EXPORT DtsLibraries-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/DtsCommon
    FILES_MATCHING PATTERN "*.h"
)
