project(${BR_TEST_TRANSLATE_NAME})

################################
# Sources
################################

set(BR_TRANSLATE_SOURCES_TEST
	translation.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_TRANSLATE_NAME} ${BR_TRANSLATE_SOURCES_TEST})

################################
# Link Lib
################################
target_link_libraries(${BR_TEST_TRANSLATE_NAME} ${USE_LIB})

target_include_directories(${BR_TEST_TRANSLATE_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(${BR_TEST_TRANSLATE_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})
#target_include_directories(${BR_TEST_TRANSLATE_NAME} PUBLIC ${TINYXML2_LIB_INCLUDE})

#if(BR_UNIX)
#	target_link_libraries(${BR_TEST_TRANSLATE_NAME} sqlite3)
#endif()

# OS Specific
if(BR_WINDOWS)
#	target_link_libraries(${BR_TEST_TRANSLATE_NAME} ${SQLITE3_LIBRARY})
	target_link_libraries(${BR_TEST_TRANSLATE_NAME} ws2_32)
	target_link_libraries(${BR_TEST_TRANSLATE_NAME} wsock32)
endif()