project(${BR_NEWSERVER_NAME})

################################
# Sources
################################

set(BR_NEWSERVER_SOURCES
	server.cpp)

################################
# Executable
################################
add_executable(${BR_NEWSERVER_NAME} ${BR_NEWSERVER_SOURCES})

################################
# Link Lib
################################
target_link_libraries(${BR_NEWSERVER_NAME} ${USE_LIB})

if(BR_UNIX)
	target_link_libraries(${BR_NEWSERVER_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_NEWSERVER_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_NEWSERVER_NAME} ws2_32)
	target_link_libraries(${BR_NEWSERVER_NAME} wsock32)
endif()