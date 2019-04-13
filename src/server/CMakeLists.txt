project(${BR_SERVER_NAME})

################################
# Sources
################################

set(BR_SERVER_HEADERS
	src/con_handler.h
	src/DB.h
	src/rand_sse.h
	src/Regex.h
	src/Server.h)

set(BR_SERVER_SOURCES
	src/BattleshipRoyale.cpp
	src/con_handler.cpp
	src/DB.cpp
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

if(BR_UNIX)
	target_link_libraries(${BR_SERVER_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_SERVER_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_SERVER_NAME} ws2_32)
	target_link_libraries(${BR_SERVER_NAME} wsock32)
endif()

# Compiler
#target_compile_options(${BR_SERVER_NAME} PUBLIC -j4)