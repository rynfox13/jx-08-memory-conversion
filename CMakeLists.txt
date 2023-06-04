cmake_minimum_required(VERSION 3.23)
project(jx-08_memory_conversion VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(wxBUILD_SHARED OFF)

# wxWidgets GUI library
add_subdirectory(lib/wxWidgets)

set(xrc_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/resources.xrc)
set(resource_cpp ${CMAKE_CURRENT_BINARY_DIR}/resource.cpp)

set(cpp_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/src/jx_08_memory_converter_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dlg_jx08_memory_converter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/aboutjxconversion.cpp
)

set(cpp_headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dlg_jx08_memory_converter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/jx_08_memory_converter_app.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/aboutjxconversion.h
)

set(wxrc $<TARGET_FILE:wxrc>)

add_custom_command(
        OUTPUT ${resource_cpp}
        COMMAND ${wxrc} -c -o ${resource_cpp} ${xrc_sources}
        DEPENDS ${xrc_sources}
        DEPENDS ${wxrc}
        COMMENT "Compiling XRC resources"
)


if (${CMAKE_HOST_APPLE})
    set(APP_NAME JX-08-Conversion)

    add_executable(${APP_NAME} MACOSX_BUNDLE ${cpp_sources})
elseif(${CMAKE_HOST_WIN32})
    set(APP_NAME jx_08_conversion)
    add_executable(${APP_NAME} WIN32 ${cpp_sources})
else()
    set(APP_NAME jx_08_conversion)
    add_executable(${APP_NAME} ${cpp_sources})
endif()

target_sources(${APP_NAME} PRIVATE ${resource_cpp} ${CMAKE_CURRENT_SOURCE_DIR}/src/jx-08_mem_conv.rc)
target_link_libraries(${APP_NAME} wx::xrc wx::core wx::base)
target_compile_definitions(${APP_NAME}
        PUBLIC JX_CONV_MAJOR=${PROJECT_VERSION_MAJOR}
        PUBLIC JX_CONV_MINOR=${PROJECT_VERSION_MINOR}
        PUBLIC JX_CONV_PATCH=${PROJECT_VERSION_PATCH}
        PUBLIC JX_CONV_VERSION="${PROJECT_VERSION}"
)

set(CPACK_NSIS_PACKAGE_NAME "JX-08 Conversion Tool")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_NAME "${APP_NAME}")
set(CPACK_PACKAGE_VENDOR "rynfox13")
set(CPACK_PACKAGE_CONTACT "rynfox13@users.noreply.github.com")

set (CPACK_PACKAGE_EXECUTABLES "${APP_NAME}" "JX-08 Conversion" )

if(${CMAKE_HOST_APPLE})
    # Note Mac specific extension .app
    set(APPS "\${CMAKE_INSTALL_PREFIX}/${APP_NAME}.app")

    # Destination paths below are relative to ${CMAKE_INSTALL_PREFIX}
    install(TARGETS ${APP_NAME}
            BUNDLE DESTINATION . COMPONENT Runtime
            RUNTIME DESTINATION bin COMPONENT Runtime
            )

    # Directories to look for dependencies
    set(DIRS ${CMAKE_BINARY_DIR})

    install(CODE "include(BundleUtilities)
    fixup_bundle(\"${APPS}\" \"\" \"${DIRS}\")")

    set(CPACK_GENERATOR "DragNDrop")
else()
    # Destination paths below are relative to ${CMAKE_INSTALL_PREFIX}
    install(TARGETS ${APP_NAME} RUNTIME DESTINATION bin COMPONENT Runtime)
endif()
include(CPack)
