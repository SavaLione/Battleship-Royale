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
set(SQLITE3_LIB "${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll" CACHE FILEPATH "sqlite3 *.dll file")

# Boost
set(BOOST_ROOT c:/boost)
#set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib)
#set(BOOST_INCLUDEDIR ${BOOST_ROOT}/include)
set(boost_COMPONENTS
    date_time
    regex
    system
)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS ${boost_COMPONENTS} REQUIRED)
#if(NOT Boost_FOUND)
#    message(FATAL_ERROR "Boost NOT FOUND: " ${BOOST_ROOT} )
#endif()
#add_definitions(-DBOOST_THREAD_USE_LIB)

#set(boost_COMPONENTS
#    atomic chrono context coroutine date_time exception filesystem graph iostreams locale log
#    log_setup math_c99 program_options random regex serialization 
#    signals system thread timer wave wserialization 
#)

#	${BOOST_ROOT}/lib/boost_date_time-mgw81-mt-1_69.dll
#	${BOOST_ROOT}/lib/boost_regex-mgw81-mt-1_69.dll
#	${BOOST_ROOT}/lib/boost_system-mgw81-mt-1_69.dll

################################
# Build
################################
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -pipe ${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll ${BOOST_ROOT}/lib/boost_date_time-mgw81-mt-1_69.dll ${BOOST_ROOT}/lib/boost_regex-mgw81-mt-1_69.dll ${BOOST_ROOT}/lib/boost_system-mgw81-mt-1_69.dll")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -pipe")

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
