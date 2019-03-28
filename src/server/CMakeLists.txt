project(${BR_SERVER_NAME})

################################
# Sources
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
# Executable
################################
add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})

################################
# Link Lib
################################
target_link_libraries(${BR_SERVER_NAME} ${USE_LIB})

if(BR_UNIX)
	target_link_libraries(${BR_SERVER_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_SERVER_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_SERVER_NAME} ws2_32)
	target_link_libraries(${BR_SERVER_NAME} wsock32)
endif()