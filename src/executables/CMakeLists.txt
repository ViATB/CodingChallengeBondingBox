project(myExe)

add_executable(${PROJECT_NAME}
        file.cpp
    )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
            myLib
    )


install(
        TARGETS
            ${PROJECT_NAME}
        CONFIGURATIONS
            Release
        DESTINATION
            bin
    )

    install(
        FILES
            myData.mpeg
        DESTINATION
            bin
    )