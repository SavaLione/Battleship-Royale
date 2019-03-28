project(${BR_SERVER_NAME})

################################
# Files
################################

set(BR_SERVER_HEADERS
	BattleshipRoyale.h
	Db.h
	Map.h
	Player.h)

set(BR_SERVER_SOURCES
	BattleshipRoyale.cpp
	Db.cpp
	Map.cpp
	Player.cpp)


################################
# Inclu desu
################################

include_directories(${SPDLOG_LIB_INCLUDE})
include_directories(${CXXOPTS_LIB_INCLUDE})
include_directories(${SQLITE3_LIB_INCLUDE})
include_directories(${PICOSHA2_LIB_INCLUDE})

################################
# Executable
################################
add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})

################################
# Link Lib
################################

if(BR_WINDOWS)
	target_link_libraries (${BR_SERVER_NAME} ${SQLITE3_LIBRARY})
endif()

if(BR_UNIX)
	include_directories(/usr/include)
	link_directories(/usr/lib)
	target_link_libraries(${BR_SERVER_NAME} sqlite3)
endif()

################################
# Specific
################################
if(BR_WINDOWS)
	target_link_libraries(${BR_SERVER_NAME} ws2_32)
	target_link_libraries(${BR_SERVER_NAME} wsock32)
endif()