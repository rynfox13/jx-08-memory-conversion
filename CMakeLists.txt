cmake_minimum_required(VERSION 3.23)
project(jx-08_memory_conversion)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)

# wxWidgets GUI library
add_subdirectory(libs/wxwidgets)

set(xrc_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/resources.xrc)
set(resource_cpp ${CMAKE_CURRENT_BINARY_DIR}/resource.cpp)

