project(BoundingBoxHelper)

add_library(${PROJECT_NAME}
        BoundingBoxHelper.cpp
        include/BoundingBoxHelper.h
    )

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
        	${OpenCV_LIBS}	
    )

install(
	TARGETS
		${PROJECT_NAME}
        LIBRARY DESTINATION
            lib
        RUNTIME DESTINATION
            bin
        INCLUDES DESTINATION
            include
    )