cmake_minimum_required (VERSION 2.6)

################################
# Вывод информации
################################
set(BR_MSG_LOGO                 "   ___       __  __  __        __   _          ___                 __\n  / _ )___ _/ /_/ /_/ /__ ___ / /  (_)__  ____/ _ \\___  __ _____ _/ /__\n / _  / _ `/ __/ __/ / -_|_-</ _ \\/ / _ \\/___/ , _/ _ \\/ // / _ `/ / -_)\n/____/\\_,_/\\__/\\__/_/\\__/___/_//_/_/ .__/   /_/|_|\\___/\\_, /\\_,_/_/\\__/\n                                  /_/                 /___/\n\n")

set(BR_MSG_CONNECTING_LIBRARIES "Connecting libraries to the project")
set(BR_MSG_CONNECTING_LOCAL_LIBRARIES "Connecting local libraries to the project")

set(BR_MSG_INCLUDE_LIBRARIES "Include libraries to the project")

set(BR_MSG_BUILD "Build")

set(BR_MSG_ADD_SUB_PROJECTS "Add subprojects")

set(BR_MSG_WINDOWS      "You are trying to compile the program under windows")
set(BR_MSG_UNIX         "You are trying to compile a program under *nix")

message(${BR_MSG_LOGO})

################################
# Variables
################################
set(    BR_WINDOWS 0    )
set(    BR_UNIX    0    )

if(MINGW)
    set(    BR_WINDOWS 1    )
    set(    BR_UNIX    0    )
    message(${BR_MSG_WINDOWS})
else()
    set(    BR_WINDOWS 0    )
    set(    BR_UNIX    1    )
    message(${BR_MSG_UNIX})
endif()

set(    BR_SERVER      1    CACHE BOOL "BR_SERVER"          )
set(    BR_CLIENT      1    CACHE BOOL "BR_CLIENT"          )
set(    BR_TEST_SERVER 0    CACHE BOOL "BR_TEST_SERVER"     )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_CLIENT 0    CACHE BOOL "BR_TEST_CLIENT"     )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_REGEX  0    CACHE BOOL "BR_TEST_REGEX"      )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_MINIDB 0    CACHE BOOL "BR_TEST_MINIDB"     )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_MEMDB  0    CACHE BOOL "BR_TEST_MEMDB"      )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_CONSO  0    CACHE BOOL "BR_TEST_CONSO"      )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_SPDLOG 0    CACHE BOOL "BR_TEST_SPDLOG"     )           # <--- DELETE THIS ON STABLE
set(    BR_TEST_TRANSLATE 0 CACHE BOOL "BR_TEST_TRANSLATE"  )           # <--- DELETE THIS ON STABLE

set(    BR_SERVER_NAME          BattleshipRoyale_Server         )
set(    BR_CLIENT_NAME          BattleshipRoyale_Client         )
set(    BR_TEST_SERVER_NAME     BattleshipRoyale_Server_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_CLIENT_NAME     BattleshipRoyale_CLIENT_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_REGEX_NAME      BattleshipRoyale_REGEX_TEST     )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_MINIDB_NAME     BattleshipRoyale_MINIDB_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_MEMDB_NAME      BattleshipRoyale_MEMDB_TEST     )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_CONSO_NAME      BattleshipRoyale_CONSO_TEST     )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_SPDLOG_NAME     BattleshipRoyale_SPDLOG_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_TRANSLATE_NAME  BattleshipRoyale_TRANSLATE_TEST )       # <--- DELETE THIS ON STABLE

################################
# Lib
################################
message(${BR_MSG_CONNECTING_LIBRARIES})

set(    SPDLOG_LIB_INCLUDE      "${CMAKE_SOURCE_DIR}/lib/spdlog"                        CACHE PATH "spdlog lib include"                      )
set(    CXXOPTS_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/cxxopts"                       CACHE PATH "cxxopts lib include"                     )
set(    SQLITE3_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/sqlite3"                       CACHE PATH "sqlite3 lib include"                     )
set(    PICOSHA2_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/picosha2"                      CACHE PATH "picosha2 lib include"                    )
set(    PDCURSES_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/PDCurses/include"              CACHE PATH "PDCurses lib include"                    )
set(    TINYXML2_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/tinyxml2/include"              CACHE PATH "tinyxml2 lib include"                    )

set(    SQLITE3_LIBRARY         "${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll"           CACHE FILEPATH  "sqlite3 *.dll file"                 )
set(    PDCURSES_LIBRARY        "${CMAKE_SOURCE_DIR}/lib/PDCurses/lib/pdcurses.dll"     CACHE FILEPATH  "pdcurses *.dll file"                )

# Boost
set(    Boost_USE_STATIC_LIBS   OFF     )
set(    Boost_USE_MULTITHREAD   ON      )
find_package(Boost 1.65.0 REQUIRED COMPONENTS system thread regex)

################################
# Local Lib
################################
message(${BR_MSG_CONNECTING_LOCAL_LIBRARIES})

set(    BR_LIB_INCLUDE          "${CMAKE_SOURCE_DIR}/src/BattleshipRoyale"              CACHE PATH "BattleshipRoyale lib include"            )

################################
# Inclu desu
################################
message(${BR_MSG_INCLUDE_LIBRARIES})

# OS Specific
if(BR_WINDOWS)
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(BR_UNIX)
    include_directories(/usr/include)
    link_directories(/usr/lib)
endif()

# Boost
set(USE_LIB_EXP Boost::regex)
set(USE_LIB ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBARY} ${USE_LIB_EXP})

# OS Specific
if(BR_UNIX)
    set(CURSES_NEED_WIDE TRUE)
    find_package(Curses REQUIRED)
endif()

################################
# Build
################################
message(${BR_MSG_BUILD})

if(BR_WINDOWS)
    #debug
    add_compile_options(-Wall -O2 -pipe)

    #release
    #add_compile_options(-Wall -O2 -pipe)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

if(BR_UNIX)
    #debug
    add_compile_options(-Wall -O2 -g -pipe -lncursesw -fopenmp -lsqlite3 -lpthread)

    #release
    #add_compile_options(-Wall -O2 -g -lncurses -pipe -fopenmp -lsqlite3 -lpthread)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BR_ARGS}")

################################
# SubDirs
################################
message(${BR_MSG_ADD_SUB_PROJECTS})

if(BR_CLIENT)
	add_subdirectory(src/client)
endif()

if(BR_SERVER)
	add_subdirectory(src/server)
endif()

################################
# Проверка возможностей
################################

if(BR_TEST_SERVER)                                           # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/server)           # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_CLIENT)                                           # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/client)           # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_REGEX)                                            # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/regex)            # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_MINIDB)                                           # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/minidb)           # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_MEMDB)                                            # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/memorydb)         # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_CONSO)                                            # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/console)          # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_SPDLOG)                                           # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/spdlog)           # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE

if(BR_TEST_TRANSLATE)                                        # <--- DELETE THIS ON STABLE
	add_subdirectory(src/opportunity_check/translation)      # <--- DELETE THIS ON STABLE
endif()                                                      # <--- DELETE THIS ON STABLE