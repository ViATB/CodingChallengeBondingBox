project(myLib)

add_library(${PROJECT_NAME}
        file.cpp
        file.h
    )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
            ext::myLib
    )


install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION
            lib
        RUNTIME DESTINATION
            bin
        INCLUDES DESTINATION
            include
    )