if(UNIX)
	message("unix")
	set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda) #note: on the industrial PC, cmake is only version 3.5, and searches for directory usr/local/cuda/ NOT cuda-9.0
        #on each mashine, create symlink by sudo ln -s /usr/local/cuda-X.X /usr/local/cuda
	set(DYNLIB_EXT "a")
endif()
if(WIN32)
	set(DYNLIB_EXT "dll")
endif()

cmake_minimum_required(VERSION 2.8)
project(kliens_main)
find_package(OpenCV REQUIRED)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set( COMMON_SOURCES config.h config.cpp PracticalSocket.cpp PracticalSocket.h)

add_executable( kliens_main kliens_main.cpp ${COMMON_SOURCES} udp_kliens.h udp_kliens.cpp  )
target_link_libraries( kliens_main ${OpenCV_LIBS} )
if(WIN32)
	target_link_libraries(kliens_main wsock32) # ws2_32)
endif()
