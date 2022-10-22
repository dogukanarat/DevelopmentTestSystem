add_subdirectory(DtsCommon)

install(
    EXPORT DtsLibraries-config
    NAMESPACE DtsLibraries::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
