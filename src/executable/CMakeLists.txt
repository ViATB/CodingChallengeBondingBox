project(launcher)

add_executable(${PROJECT_NAME}
        launcher.cpp
    )

target_link_libraries(${PROJECT_NAME}
	PUBLIC
            ${OpenCV_LIBS}
            BoundingBoxHelper
            SegmentationHelper
            VideoHelper
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