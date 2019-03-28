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


# SQLite3
if(MINGW)
	include_directories(${SQLITE3_INCLUDE_DIR})
else()
	include_directories(${SQLITE3_INCLUDE_DIRS})
endif()

# Boost
include_directories(${Boost_INCLUDE_DIRS})

# Exec
add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})

include_directories(${SPDLOG_LIB_INCLUDE})
include_directories(${CXXOPTS_LIB_INCLUDE})
include_directories(${SQLITE3_LIB_INCLUDE})
include_directories(${PICOSHA2_LIB_INCLUDE})

#target_link_libraries(${BR_SERVER_NAME} ${SQLITE3_LIB})

# SQLite3
if(MINGW)
	target_link_libraries (${BR_SERVER_NAME} ${SQLITE3_LIBRARY})
else()
	target_link_libraries (${BR_SERVER_NAME} ${SQLITE3_LIBRARIES})
endif()

# Boost
target_link_libraries(${BR_SERVER_NAME} ${Boost_LIBRARIES})
if(MINGW)
	target_link_libraries(${BR_SERVER_NAME} ws2_32)
	target_link_libraries(${BR_SERVER_NAME} wsock32)
endif()