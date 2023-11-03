cmake_minimum_required(VERSION 3.12)

project(CodingChallenge)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	#set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/../install" CACHE PATH "" FORCE)
	set(CMAKE_INSTALL_PREFIX "C:/Users/tombo/Dropbox/CodingChallange/install" CACHE PATH "" FORCE)
	
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

find_package(OpenCV REQUIRED
		PATHS "${CMAKE_SOURCE_DIR}/ext/opencv/build"  
	)

#find_package(GTest REQUIRED)

add_subdirectory(src)

