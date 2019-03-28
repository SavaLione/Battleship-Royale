cmake_minimum_required (VERSION 2.6)

# Подключение модулей
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

################################
# Variables
################################
set(BR_SERVER 1 CACHE BOOL "BR_SERVER")
set(BR_CLIENT_CURSES 0 CACHE BOOL "BR_CLIENT_CURSES")

set(BR_SERVER_NAME BattleshipRoyale_Server)
set(BR_CLIENT_CURSES_NAME BattleshipRoyale_Client_curses)

################################
# Lib
################################
set(SPDLOG_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/spdlog" CACHE PATH "spdlog lib")
set(CXXOPTS_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/cxxopts" CACHE PATH "cxxopts lib")
set(SQLITE3_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/sqlite3" CACHE PATH "sqlite3 lib")
set(PICOSHA2_LIB_INCLUDE "${CMAKE_SOURCE_DIR}/lib/picosha2" CACHE PATH "picosha2 lib")
set(SQLITE3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/sqlite3/include" CACHE PATH "sqslite3 lib include")

# SQLite3

if(MINGW)
    set(SQLITE3_LIBRARY "c:/sqlite3/lib/sqlite3.dll" CACHE FILEPATH "sqlite3 *.dll file)")
    #set(SQLITE3_INCLUDE_DIR "c:/sqlite3/include")
else()
    set(SQLITE3_LIBRARY "${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3" CACHE FILEPATH "sqlite3 lib file)")
    #set(SQLITE3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/sqlite3/include")
    #find_package(SQLite3 REQUIRED)
    #include(FindThreads)
    # SQLITE3_LIBRARIES
    #set(SQLITE3_LIBRARIES SQLite3)
endif()

# Boost
set(boost_COMPONENTS
    date_time
    regex
    system
)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS ${boost_COMPONENTS} REQUIRED)

################################
# Build
################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -pipe")

################################
# SubDirs
################################

if(BR_CLIENT_CURSES)
	add_subdirectory(src/client)
endif()

if(BR_SERVER)
	add_subdirectory(src/server)
endif()
