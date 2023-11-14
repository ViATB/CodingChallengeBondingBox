cmake_minimum_required(VERSION 3.28)

project(opencv)

set(BUILD_TESTS OFF CACHE BOOL " FORCE)
set(BUILD_PERF_TESTS OFF CACHE BOOL " FORCE)

set(OPENCV_EXTRA_MODULES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/opencv_contrib/modules" CACHE PATH "" FORCE)

add_subdirectory(opencv)
