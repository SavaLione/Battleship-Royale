project(${BR_TEST_MINIDB_NAME})

################################
# Sources
################################

set(BR_TEST_MINIDB_HEADERS
	MiniDB.h)

set(BR_TEST_MINIDB_SOURCES
	test.cpp
	MiniDB.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_MINIDB_NAME} ${BR_TEST_MINIDB_HEADERS} ${BR_TEST_MINIDB_SOURCES})

################################
# Link Lib
################################
#target_link_libraries(${BR_MINIDB_NAME_TEST} ${USE_LIB})

target_include_directories(${BR_TEST_MINIDB_NAME} PUBLIC ${BR_LIB_INCLUDE})
target_include_directories(${BR_TEST_MINIDB_NAME} PUBLIC ${SQLITE3_LIB_INCLUDE})

if(BR_UNIX)
	target_link_libraries(${BR_TEST_MINIDB_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_TEST_MINIDB_NAME} ${SQLITE3_LIBRARY})
#	target_link_libraries(${BR_TEST_MINIDB_NAME} ws2_32)
#	target_link_libraries(${BR_TEST_MINIDB_NAME} wsock32)
endif()