project(executable)

add_executable(${PROJECT_NAME}
        main.cpp
    )

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
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
            ${CMAKE_SOURCE_DIR}/data/video.avi
        DESTINATION
            bin
    )