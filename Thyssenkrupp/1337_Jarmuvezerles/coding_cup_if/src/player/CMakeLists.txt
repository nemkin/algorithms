#if(UNIX)
#	message("unix")
#	set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda) #note: on the industrial PC, cmake is only version 3.5, and searches for directory usr/local/cuda/ NOT cuda-9.0
	#on each mashine, create symlink by sodo ln -s /usr/local/cuda-X.X /usr/local/cuda
#endif()

cmake_minimum_required(VERSION 2.8)
SET(PROJECT_NAME shm_udp_server_player)
add_definitions(-DUDP_SERVER_MODE_PLAYBACK)
project(${PROJECT_NAME})
set (CMAKE_CXX_STANDARD 14)
set( COMMON_SOURCES ../config.h ../config.cpp ../PracticalSocket.cpp ../PracticalSocket.h)
add_executable(${PROJECT_NAME} server_copy.cpp ${COMMON_SOURCES} )
#find_package( OpenCV REQUIRED )
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )
if(WIN32)
	target_link_libraries(${PROJECT_NAME} wsock32) # ws2_32)
endif()

