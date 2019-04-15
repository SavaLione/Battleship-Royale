project(${BR_CLIENT_NAME})

################################
# Sources
################################

set(BR_CLIENT_HEADERS)

set(BR_CLIENT_SOURCES
	src/BattleshipRoyale.cpp)

#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

################################
# Executable
################################

add_executable(${BR_CLIENT_NAME} ${BR_CLIENT_HEADERS} ${BR_CLIENT_SOURCES})

################################
# Link Lib
################################

target_link_libraries(${BR_CLIENT_NAME} ${USE_LIB} ${CURSES_LIBRARIES})

target_include_directories(${BR_CLIENT_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})
target_include_directories(${BR_CLIENT_NAME} PUBLIC ${CXXOPTS_LIB_INCLUDE})
target_include_directories(${BR_CLIENT_NAME} PUBLIC ${BR_LIB_INCLUDE})
target_include_directories(${BR_CLIENT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})

#if(BR_UNIX)
#	target_link_libraries(${BR_CLIENT_NAME} sqlite3)
#endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_CLIENT_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_CLIENT_NAME} ws2_32)
	target_link_libraries(${BR_CLIENT_NAME} wsock32)
endif()

#include_directories(${PDCURSES_LIB_INCLUDE})
#target_link_libraries(${BR_CLIENT_NAME} ${PDCURSES_LIB})
