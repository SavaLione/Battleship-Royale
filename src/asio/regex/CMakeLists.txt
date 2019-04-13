project(${BR_REGEX_NAME_TEST})

################################
# Sources
################################

set(BR_REGEX_HEADERS_TEST)

set(BR_REGEX_SOURCES_TEST
	regex.cpp)

################################
# Executable
################################
add_executable(${BR_REGEX_NAME_TEST} ${BR_REGEX_HEADERS_TEST} ${BR_REGEX_SOURCES_TEST})

################################
# Link Lib
################################
target_link_libraries(${BR_REGEX_NAME_TEST} ${USE_LIB})

if(BR_UNIX)
	target_link_libraries(${BR_REGEX_NAME_TEST} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_link_libraries(${BR_REGEX_NAME_TEST} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_REGEX_NAME_TEST} ws2_32)
	target_link_libraries(${BR_REGEX_NAME_TEST} wsock32)
endif()