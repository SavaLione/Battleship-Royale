project(${BR_CLIENT_CURSES_NAME})

set(BR_CLIENT_CURSES_HEADERS
	BattleshipRoyale.h
	../bd/Client.h)

set(BR_CLIENT_CURSES_SOURCES
	BattleshipRoyale.cpp
	../bd/Client.cpp)

add_executable(${BR_CLIENT_CURSES_NAME} ${BR_CLIENT_CURSES_HEADERS} ${BR_CLIENT_CURSES_SOURCES})

#include_directories(${PDCURSES_LIB_INCLUDE})
#target_link_libraries(${BR_CLIENT_CURSES_NAME} ${PDCURSES_LIB})