cmake_minimum_required (VERSION 2.6)

################################
# Variables
################################
set(    BR_WINDOWS 0    )
set(    BR_UNIX    0    )

if(MINGW)
    set(    BR_WINDOWS 1    )
    set(    BR_UNIX    0    )
else()
    set(    BR_WINDOWS 0    )
    set(    BR_UNIX    1    )
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

set(    BR_SERVER_NAME          BattleshipRoyale_Server         )
set(    BR_CLIENT_NAME          BattleshipRoyale_Client         )
set(    BR_TEST_SERVER_NAME     BattleshipRoyale_Server_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_CLIENT_NAME     BattleshipRoyale_CLIENT_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_REGEX_NAME      BattleshipRoyale_REGEX_TEST     )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_MINIDB_NAME     BattleshipRoyale_MINIDB_TEST    )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_MEMDB_NAME      BattleshipRoyale_MEMDB_TEST     )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_CONSO_NAME      BattleshipRoyale_CONSO_TEST     )       # <--- DELETE THIS ON STABLE
set(    BR_TEST_SPDLOG_NAME     BattleshipRoyale_SPDLOG_TEST    )       # <--- DELETE THIS ON STABLE

################################
# Lib
################################
set(    SPDLOG_LIB_INCLUDE      "${CMAKE_SOURCE_DIR}/lib/spdlog"                        CACHE PATH "spdlog lib include"                      )
set(    CXXOPTS_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/cxxopts"                       CACHE PATH "cxxopts lib include"                     )
set(    SQLITE3_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/sqlite3"                       CACHE PATH "sqlite3 lib include"                     )
set(    PICOSHA2_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/picosha2"                      CACHE PATH "picosha2 lib include"                    )
set(    PDCURSES_LIB_INCLUDE    "${CMAKE_SOURCE_DIR}/lib/PDCurses/include"              CACHE PATH "PDCurses lib include"                    )
set(    NCURSES_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/ncurses/include"               CACHE PATH "ncurses MingW64 port lib include"        )

set(    SQLITE3_LIBRARY         "${CMAKE_SOURCE_DIR}/lib/sqlite3/sqlite3.dll"           CACHE FILEPATH  "sqlite3 *.dll file"                 )

# ncurses
set(    NCURSES_LIBRARY_FORM    "${CMAKE_SOURCE_DIR}/lib/ncurses/bin/libformw6.dll"     CACHE FILEPATH  "ncurses form *.dll file"            )
set(    NCURSES_LIBRARY_MENU    "${CMAKE_SOURCE_DIR}/lib/ncurses/bin/libmenuw6.dll"     CACHE FILEPATH  "ncurses panel *.dll file"           )
set(    NCURSES_LIBRARY         "${CMAKE_SOURCE_DIR}/lib/ncurses/bin/libncursesw6.dll"  CACHE FILEPATH  "ncurses library *.dll file"         )
set(    NCURSES_LIBRARY_PANEL   "${CMAKE_SOURCE_DIR}/lib/ncurses/bin/libpanelw6.dll"    CACHE FILEPATH  "ncurses panel *.dll file"           )


#set(    PDCURSES_LIBRARY       "${CMAKE_SOURCE_DIR}/lib/PDCurses/pdcurses.a"           CACHE FILEPATH  "PDCurses *.a file"                  )

# Boost
set(    Boost_USE_STATIC_LIBS   OFF     )
set(    Boost_USE_MULTITHREAD   ON      )
find_package(Boost 1.65.0 REQUIRED COMPONENTS system thread regex)

################################
# Local Lib
################################
set(    BR_LIB_INCLUDE          "${CMAKE_SOURCE_DIR}/src/BattleshipRoyale"              CACHE PATH "BattleshipRoyale lib include"            )

################################
# Inclu desu
################################

# OS Specific
if(BR_WINDOWS)
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(BR_UNIX)
    include_directories(/usr/include)
    link_directories(/usr/lib)
endif()

#
set(USE_LIB_EXP Boost::regex)
set(USE_LIB ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBARY} ${USE_LIB_EXP})

################################
# Build
################################
if(BR_WINDOWS)
    #debug
    #add_compile_options(-Wall -O0 -pipe -msse2)

    #release
    add_compile_options(-Wall -O2 -pipe -msse2)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

if(BR_UNIX)
    #debug
    #add_compile_options(-Wall -O0 -g -pipe -msse2 -fopenmp -lsqlite3 -lpthread)

    #release
    add_compile_options(-Wall -O2 -g -pipe -msse2 -fopenmp -lsqlite3 -lpthread)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${BR_ARGS}")

################################
# SubDirs
################################

if(BR_CLIENT)
	add_subdirectory(src/client)
endif()

if(BR_SERVER)
	add_subdirectory(src/server)
endif()

################################
# Тестирование
################################

if(BR_TEST_SERVER)                                 # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/server)           # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE

if(BR_TEST_CLIENT)                                 # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/client)           # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE

if(BR_TEST_REGEX)                                  # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/regex)            # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE

if(BR_TEST_MINIDB)                                 # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/minidb)           # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE

if(BR_TEST_MEMDB)                                  # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/memorydb)         # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE

if(BR_TEST_CONSO)                                  # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/console)          # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE

if(BR_TEST_SPDLOG)                                 # <--- DELETE THIS ON STABLE
	add_subdirectory(src/testing/spdlog)           # <--- DELETE THIS ON STABLE
endif()                                            # <--- DELETE THIS ON STABLE