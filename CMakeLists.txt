cmake_minimum_required (VERSION 2.6)

################################
# Variables
################################
set(BR_SERVER 1 CACHE BOOL "BR_SERVER")
set(BR_CLIENT_CURSES 0 CACHE BOOL "BR_CLIENT_CURSES")

set(BR_SERVER_NAME BattleshipRoyale_Server)
set(BR_CLIENT_CURSES_NAME BattleshipRoyale_Client_curses)

# Lib
set(SPDLOG_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/spdlog" CACHE PATH "spdlog lib")
set(CXXOPTS_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/cxxopts" CACHE PATH "cxxopts lib")
set(SQLITE3_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/sqlite3" CACHE PATH "sqlite3 lib")

################################
# Build
################################
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -pipe ${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll")

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

################################
# 
################################

if(BR_CLIENT_CURSES)
	add_subdirectory(src/client)
endif()

if(BR_SERVER)
	add_subdirectory(src/server)
endif()
