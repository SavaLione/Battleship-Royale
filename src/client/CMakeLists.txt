project(${BR_CLIENT_CURSES_NAME})

################################
# Sources
################################

set(BR_CLIENT_CURSES_HEADERS)

set(BR_CLIENT_CURSES_SOURCES
	BattleshipRoyale.cpp)


#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

################################
# Executable
################################

add_executable(${BR_CLIENT_CURSES_NAME} ${BR_CLIENT_CURSES_HEADERS} ${BR_CLIENT_CURSES_SOURCES})

################################
# Link Lib
################################

target_link_libraries(${BR_CLIENT_CURSES_NAME} ${CURSES_LIBRARIES})

#include_directories(${PDCURSES_LIB_INCLUDE})
#target_link_libraries(${BR_CLIENT_CURSES_NAME} ${PDCURSES_LIB})
