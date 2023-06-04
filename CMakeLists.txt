cmake_minimum_required(VERSION 3.23)
project(jx-08_memory_conversion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(wxBUILD_SHARED OFF)

# wxWidgets GUI library
add_subdirectory(lib/wxWidgets)

set(xrc_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/resources.xrc)
set(resource_cpp ${CMAKE_CURRENT_BINARY_DIR}/resource.cpp)

set(cpp_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/src/jx_08_memory_converter_app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dlg_jx08_memory_converter.cpp
)

set(cpp_headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dlg_jx08_memory_converter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/jx_08_memory_converter_app.h
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
else()
    set(APP_NAME jx_08_conversion)
    add_executable(${APP_NAME} ${cpp_sources})
endif()

target_sources(${APP_NAME} PRIVATE ${resource_cpp} ${CMAKE_CURRENT_SOURCE_DIR}/src/jx-08_mem_conv.rc)
target_link_libraries(${APP_NAME} wx::xrc wx::core wx::base)

if(${CMAKE_HOST_APPLE})
    # Destination paths below are relative to ${CMAKE_INSTALL_PREFIX}
    install(TARGETS ${APP_NAME}
            BUNDLE DESTINATION . COMPONENT Runtime
            RUNTIME DESTINATION bin COMPONENT Runtime
            )

    # Note Mac specific extension .app
    set(APPS "\${CMAKE_INSTALL_PREFIX}/${APP_NAME}.app")

    # Directories to look for dependencies
    set(DIRS ${CMAKE_BINARY_DIR})

    install(CODE "include(BundleUtilities)
    fixup_bundle(\"${APPS}\" \"\" \"${DIRS}\")")

    set(CPACK_GENERATOR "DRAGNDROP")
    include(CPack)
endif()
