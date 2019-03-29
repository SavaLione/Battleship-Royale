cmake_minimum_required (VERSION 2.6)

################################
# Variables
################################
set(    BR_WINDOWS 0    )
set(    BR_UNIX 0       )

if(MINGW)
    set(    BR_WINDOWS 1    )
    set(    BR_UNIX 0       )
else()
    set(    BR_WINDOWS 0    )
    set(    BR_UNIX 1       )
endif()

set(    BR_SERVER 1         CACHE BOOL "BR_SERVER"          )
set(    BR_CLIENT_CURSES 0  CACHE BOOL "BR_CLIENT_CURSES"   )

set(    BR_SERVER_NAME          BattleshipRoyale_Server         )
set(    BR_CLIENT_CURSES_NAME   BattleshipRoyale_Client_curses  )

################################
# Lib
################################
set(    SPDLOG_LIB_INCLUDE      "${CMAKE_SOURCE_DIR}/lib/spdlog"                CACHE PATH "spdlog lib include"         )
set(    CXXOPTS_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/cxxopts"               CACHE PATH "cxxopts lib include"        )
set(    SQLITE3_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/sqlite3"               CACHE PATH "sqlite3 lib include"        )
set(    PICOSHA2_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/picosha2"              CACHE PATH "picosha2 lib include"       )

set(    SQLITE3_LIBRARY         "${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll"   CACHE FILEPATH  "sqlite3 *.dll file"    )

# Boost
set(    Boost_USE_STATIC_LIBS   OFF     )
set(    Boost_USE_MULTITHREAD   ON      )
find_package(Boost 1.65.0 REQUIRED COMPONENTS system thread regex)

################################
# Inclu desu
################################

# Header only
include_directories(${SPDLOG_LIB_INCLUDE})
include_directories(${CXXOPTS_LIB_INCLUDE})
include_directories(${PICOSHA2_LIB_INCLUDE})

# OS Specific
if(BR_WINDOWS)
    include_directories(${SQLITE3_LIB_INCLUDE})
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(BR_UNIX)
    include_directories(/usr/include)
    link_directories(/usr/lib)
endif()

#
set(USE_LIB ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBARY})

################################
# Build
################################
if(BR_WINDOWS)
    add_compile_options(-Wall -O0 -pipe -msse2)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

if(BR_UNIX)
    add_compile_options(-Wall -O0 -pipe -msse2 -fopenmp -lsqlite3 -lpthread)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BR_ARGS}")

################################
# SubDirs
################################

if(BR_CLIENT_CURSES)
	add_subdirectory(src/client)
endif()

if(BR_SERVER)
	add_subdirectory(src/server)
endif()
