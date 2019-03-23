project(${BR_SERVER_NAME})

set(BR_SERVER_HEADERS
	BattleshipRoyale.h
	Map.h
	Player.h
	../bd/Server.h)

set(BR_SERVER_SOURCES
	BattleshipRoyale.cpp
	Map.cpp
	Player.cpp
	../bd/Server.cpp)

add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})

include_directories(${SPDLOG_LIB_INCLUDE})
include_directories(${CXXOPTS_LIB_INCLUDE})
include_directories(${SQLITE3_LIB_INCLUDE})