project(${BR_TEST_REGEX_NAME})

################################
# Sources
################################

set(BR_TEST_REGEX_HEADERS)

set(BR_TEST_REGEX_SOURCES
	regex.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_REGEX_NAME} ${BR_TEST_REGEX_HEADERS} ${BR_TEST_REGEX_SOURCES})

################################
# Link Lib
################################
target_link_libraries(${BR_TEST_REGEX_NAME} ${USE_LIB})

target_include_directories(${BR_TEST_REGEX_NAME} PUBLIC ${Boost_INCLUDE_DIRS})

#if(BR_UNIX)
#	target_link_libraries(${BR_TEST_REGEX_NAME} sqlite3)
#endif()

# OS Specific
#if(BR_WINDOWS)
#	target_link_libraries(${BR_TEST_REGEX_NAME} ${SQLITE3_LIBRARY})
#	target_link_libraries(${BR_TEST_REGEX_NAME} ws2_32)
#	target_link_libraries(${BR_TEST_REGEX_NAME} wsock32)
#endif()