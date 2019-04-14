project(${BR_NEWCLIENT_NAME})

################################
# Sources
################################

set(BR_NEWCLIENT_SOURCES
	client.cpp)

################################
# Executable
################################
add_executable(${BR_NEWCLIENT_NAME} ${BR_NEWCLIENT_SOURCES})

################################
# Link Lib
################################
target_link_libraries(${BR_NEWCLIENT_NAME} ${USE_LIB})

if(BR_UNIX)
	target_link_libraries(${BR_NEWCLIENT_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_NEWCLIENT_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_NEWCLIENT_NAME} ws2_32)
	target_link_libraries(${BR_NEWCLIENT_NAME} wsock32)
endif()