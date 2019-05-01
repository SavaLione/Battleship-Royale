project(${BR_TEST_CLIENT_NAME})

################################
# Sources
################################

set(BR_TEST_CLIENT_SOURCES
	client.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_CLIENT_NAME} ${BR_TEST_CLIENT_SOURCES})

################################
# Link Lib
################################
target_link_libraries(${BR_TEST_CLIENT_NAME} ${USE_LIB})

target_include_directories(${BR_TEST_CLIENT_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})
target_include_directories(${BR_TEST_CLIENT_NAME} PUBLIC ${BR_LIB_INCLUDE})
target_include_directories(${BR_TEST_CLIENT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})

# OS Specific
if(BR_WINDOWS)
#	target_link_libraries(${BR_TEST_CLIENT_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_TEST_CLIENT_NAME} ws2_32)
	target_link_libraries(${BR_TEST_CLIENT_NAME} wsock32)
endif()