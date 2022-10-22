include(${KM_CMAKE_DIR}/Applications.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    DtsServer
)

set(CUSTOM_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/GeneratedHeader.h")

target_sources(
    DtsServer 
    PRIVATE
        Main.c
        ${CUSTOM_HEADER}
)

# target_link_libraries(
#     KitchenManagerViewer
#     PUBLIC
#         Qt5::Core
#         Qt5::Widgets
#         Qt5::Gui
#         Qt5::Sql
#         Qt5::Multimedia
#         Qt5::MultimediaWidgets
#         KmBaseWidget
#         KmMediaPlayerWidget
#         KmOrderViewWidget
#         KmSessionWidget
# )

install(
    TARGETS DtsServer
    EXPORT DtsServer-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})


