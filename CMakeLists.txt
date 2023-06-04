cmake_minimum_required(VERSION 3.23)
project(jx-08_memory_conversion)

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

add_executable(jx-08_memory_conversion ${cpp_sources})
target_sources(jx-08_memory_conversion PRIVATE ${resource_cpp} ${CMAKE_CURRENT_SOURCE_DIR}/src/jx-08_mem_conv.rc)
target_link_libraries(jx-08_memory_conversion wx::xrc wx::core wx::base)
