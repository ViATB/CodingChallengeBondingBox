cmake_minimum_required(VERSION 3.12)

project(CodingChallenge
        VERSION 0.0.1
    )

set(USE_OPENCV ON CACHE BOOL "use opencv")

if(${USE_OPENCV})
    find_package(opencv
            PATHS "C:/SDK"
            Components
                myLib@1.0.0    
        )

endif(${USE_OPENCV})

find_package(GTest REQUIRED)

add_subdirectory(src)

