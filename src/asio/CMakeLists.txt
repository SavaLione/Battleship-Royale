project(${BR_SERVER_NAME_TEST})

################################
# Sources
################################

set(BR_SERVER_HEADERS_TEST
	con_handler.h
	Server.h)

set(BR_SERVER_SOURCES_TEST
	async.cpp
	con_handler.cpp
	Server.cpp)

################################
# Executable
################################
add_executable(${BR_SERVER_NAME_TEST} ${BR_SERVER_HEADERS_TEST} ${BR_SERVER_SOURCES_TEST})

################################
# Link Lib
################################
target_link_libraries(${BR_SERVER_NAME_TEST} ${USE_LIB})

if(BR_UNIX)
	target_link_libraries(${BR_SERVER_NAME_TEST} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_SERVER_NAME_TEST} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_SERVER_NAME_TEST} ws2_32)
	target_link_libraries(${BR_SERVER_NAME_TEST} wsock32)
endif()