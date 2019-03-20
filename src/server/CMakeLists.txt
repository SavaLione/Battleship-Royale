project(${BR_SERVER_NAME})

set(BR_SERVER_HEADERS
	BattleshipRoyale.h)

set(BR_SERVER_SOURCES
	BattleshipRoyale.cpp)

add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})
