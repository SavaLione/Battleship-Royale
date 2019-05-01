project(${BR_TEST_SERVER_NAME})

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
add_executable(${BR_TEST_SERVER_NAME} ${BR_SERVER_HEADERS_TEST} ${BR_SERVER_SOURCES_TEST})

################################
# Link Lib
################################
target_link_libraries(${BR_TEST_SERVER_NAME} ${USE_LIB})

target_include_directories(${BR_TEST_SERVER_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(${BR_TEST_SERVER_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})

#if(BR_UNIX)
#	target_link_libraries(${BR_TEST_SERVER_NAME} sqlite3)
#endif()

# OS Specific
if(BR_WINDOWS)
#	target_link_libraries(${BR_TEST_SERVER_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_TEST_SERVER_NAME} ws2_32)
	target_link_libraries(${BR_TEST_SERVER_NAME} wsock32)
endif()