project(${BR_TEST_MEMDB_NAME})

################################
# Sources
################################

set(BR_MEMDB_HEADERS_TEST)

set(BR_MEMDB_SOURCES_TEST
	mem.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_MEMDB_NAME} ${BR_MEMDB_HEADERS_TEST} ${BR_MEMDB_SOURCES_TEST})

################################
# Link Lib
################################
target_link_libraries(${BR_TEST_MEMDB_NAME} ${USE_LIB})

target_include_directories(${BR_TEST_MEMDB_NAME} PUBLIC ${BR_LIB_INCLUDE})
target_include_directories(${BR_TEST_MEMDB_NAME} PUBLIC ${SQLITE3_LIB_INCLUDE})

if(BR_UNIX)
	target_link_libraries(${BR_TEST_MEMDB_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_TEST_MEMDB_NAME} ${SQLITE3_LIBRARY})
endif()