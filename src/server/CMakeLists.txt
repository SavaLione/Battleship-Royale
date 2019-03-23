project(${BR_SERVER_NAME})

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

add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})

include_directories(${SPDLOG_LIB_INCLUDE})
include_directories(${CXXOPTS_LIB_INCLUDE})
include_directories(${SQLITE3_LIB_INCLUDE})