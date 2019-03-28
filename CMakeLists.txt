cmake_minimum_required (VERSION 2.6)

# Подключение модулей
set(    CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake"  )

################################
# Variables
################################
set(    BR_WINDOWS 0    )
set(    BR_UNIX 1       )

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
set(    SPDLOG_LIB_INCLUDE      "${CMAKE_SOURCE_DIR}/lib/spdlog"            CACHE PATH "spdlog lib include"     )
set(    CXXOPTS_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/cxxopts"           CACHE PATH "cxxopts lib include"    )
set(    SQLITE3_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/sqlite3"           CACHE PATH "sqlite3 lib include"    )
set(    PICOSHA2_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/picosha2"          CACHE PATH "picosha2 lib include"   )

if(BR_WINDOWS)
    # SQLite3
    set(    SQLITE3_LIBRARY     "${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll"   CACHE FILEPATH  "sqlite3 *.dll file)"   )
endif()

################################
# Build
################################
if(BR_WINDOWS)
    add_compile_options(-Wall)
    add_compile_options(-O0)
    add_compile_options(-pipe)
endif()

if(BR_UNIX)
    add_compile_options(-Wall -O0 -pipe)
    add_compile_options(-lsqlite3 -lpthread)
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
