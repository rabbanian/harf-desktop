cmake_minimum_required(VERSION 3.13)

project(harf-desktop)
set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

include(cmake/prevent_in_source_builds.cmake)
#include(cmake/compiler_warnings.cmake)
include(cmake/external.cmake)

add_subdirectory(external)
add_subdirectory(src)
