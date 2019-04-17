project(${BR_SERVER_NAME})

################################
# Sources
################################

set(BR_SERVER_HEADERS
	src/con_handler.h
	src/Console.h
	src/MemDBmap.h
	src/MemDBuid.h
	src/MiniDB.h
	src/Processing.h
	src/rand_sse.h
	src/Regex.h
	src/Server.h)

set(BR_SERVER_SOURCES
	src/BattleshipRoyale.cpp
	src/con_handler.cpp
	src/Console.cpp
	src/MemDBmap.cpp
	src/MemDBuid.cpp
	src/MiniDB.cpp
	src/Processing.cpp
	src/rand_sse.cpp
	src/Regex.cpp
	src/Server.cpp)

################################
# Executable
################################
add_executable(${BR_SERVER_NAME} ${BR_SERVER_HEADERS} ${BR_SERVER_SOURCES})

################################
# Link Lib
################################
target_link_libraries(${BR_SERVER_NAME} ${USE_LIB})

target_include_directories(${BR_SERVER_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})
target_include_directories(${BR_SERVER_NAME} PUBLIC ${CXXOPTS_LIB_INCLUDE})
target_include_directories(${BR_SERVER_NAME} PUBLIC ${BR_LIB_INCLUDE})
target_include_directories(${BR_SERVER_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(${BR_SERVER_NAME} PUBLIC ${SQLITE3_LIB_INCLUDE})
target_include_directories(${BR_SERVER_NAME} PUBLIC ${PICOSHA2_LIB_INCLUDE})

if(BR_UNIX)
	target_link_libraries(${BR_SERVER_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_SERVER_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_SERVER_NAME} ws2_32)
	target_link_libraries(${BR_SERVER_NAME} wsock32)
endif()