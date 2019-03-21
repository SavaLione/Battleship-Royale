cmake_minimum_required (VERSION 2.6)

################################
# Variables
################################
set(BR_SERVER 1 CACHE BOOL "BR_SERVER")
set(BR_CLIENT_CURSES 1 CACHE BOOL "BR_CLIENT_CURSES")

#set(PDCURSES_LIB "${CMAKE_SOURCE_DIR}/lib/pdcurses/pdcurses.a" CACHE FILEPATH "PDCurses *.a file")
#set(PDCURSES_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/pdcurses/include" CACHE PATH "PDCurses lib include")

set(BR_SERVER_NAME BattleshipRoyale_Server)
set(BR_CLIENT_CURSES_NAME BattleshipRoyale_Client_curses)

################################
# Build
################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

################################
# 
################################

#add_subdirectory(src/skin)
#add_subdirectory(src/bd)

if(BR_CLIENT_CURSES)
	add_subdirectory(src/client_curses)
endif()

if(ISS_OPTIMIZED)
	add_subdirectory(src/server)
endif()
