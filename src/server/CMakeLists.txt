project(${BR_SERVER_NAME})

set(BR_SERVER_HEADERS
	BattleshipRoyale.h
	Player.h
	../bd/Server.h)

set(BR_SERVER_SOURCES
	BattleshipRoyale.cpp
	Player.cpp
	../bd/Server.cpp)

add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})
