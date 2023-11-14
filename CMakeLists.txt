cmake_minimum_required(VERSION 3.28)

project(CodingChallengeVideoProcessing)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
        set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/../install" CACHE PATH "" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

find_package(OpenCV REQUIRED)

add_subdirectory(src)

install(
        FILES
            ${CMAKE_SOURCE_DIR}/data/example/video.avi
        DESTINATION
            bin
    )