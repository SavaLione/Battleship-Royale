project(${BR_CLIENT_CURSES_NAME})

set(BR_CLIENT_CURSES_HEADERS
	BattleshipRoyale.h
	Registration.h)

set(BR_CLIENT_CURSES_SOURCES
	BattleshipRoyale.cpp
	Registration.cpp)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${BR_CLIENT_CURSES_NAME} ${BR_CLIENT_CURSES_HEADERS} ${BR_CLIENT_CURSES_SOURCES})

target_link_libraries(${BR_CLIENT_CURSES_NAME} ${CURSES_LIBRARIES})

#include_directories(${PDCURSES_LIB_INCLUDE})
#target_link_libraries(${BR_CLIENT_CURSES_NAME} ${PDCURSES_LIB})
