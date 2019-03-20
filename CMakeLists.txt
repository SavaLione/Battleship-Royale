cmake_minimum_required (VERSION 2.6)

################################
# Variables
################################
set(BR_SERVER 1 CACHE BOOL "BR_SERVER")
set(BR_CLIENT_NCURSES 1 CACHE BOOL "BR_CLIENT_NCURSES")

################################
# Build
################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

################################
# 
################################

add_subdirectory(src/skin)
add_subdirectory(src/bd)

if(BR_CLIENT_NCURSES)
	add_subdirectory(src/client_ncurses)
endif()

if(ISS_OPTIMIZED)
	add_subdirectory(src/server)
endif()