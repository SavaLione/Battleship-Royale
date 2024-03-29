project(${BR_CLIENT_NAME})

################################
# Sources
################################

set(BR_CLIENT_HEADERS
	src/Args.h
	src/Client.h
	src/Test.h
	src/test/LoopConnections.h
	src/test/SimultaneousConnections.h
	src/Window.h
	src/TUI.h
	src/Registration.h)

set(BR_CLIENT_SOURCES
	src/Args.cpp
	src/BattleshipRoyale.cpp
	src/Client.cpp
	src/test/LoopConnections.cpp
	src/test/SimultaneousConnections.cpp
	src/Window.cpp
	src/TUI.cpp
	src/Registration.cpp)

#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

################################
# Executable
################################

add_executable(${BR_CLIENT_NAME} ${BR_CLIENT_HEADERS} ${BR_CLIENT_SOURCES})

################################
# Link Lib
################################

target_link_libraries(${BR_CLIENT_NAME} ${USE_LIB})

target_include_directories(${BR_CLIENT_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})
target_include_directories(${BR_CLIENT_NAME} PUBLIC ${CXXOPTS_LIB_INCLUDE})
target_include_directories(${BR_CLIENT_NAME} PUBLIC ${BR_LIB_INCLUDE})
target_include_directories(${BR_CLIENT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})

# OS Specific
if(BR_UNIX)
	target_include_directories(${BR_CLIENT_NAME} PUBLIC ${CURSES_INCLUDE_DIR})
	target_link_libraries(${BR_CLIENT_NAME} ${CURSES_LIBRARIES})
endif()

if(BR_WINDOWS)
	target_include_directories(${BR_CLIENT_NAME} PUBLIC ${PDCURSES_LIB_INCLUDE})
	target_link_libraries(${BR_CLIENT_NAME} ${PDCURSES_LIBRARY})
	
	target_link_libraries(${BR_CLIENT_NAME} ws2_32)
	target_link_libraries(${BR_CLIENT_NAME} wsock32)
endif()

#include_directories(${PDCURSES_LIB_INCLUDE})
#target_link_libraries(${BR_CLIENT_NAME} ${PDCURSES_LIB})
