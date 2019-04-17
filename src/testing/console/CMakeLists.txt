project(${BR_TEST_CONSO_NAME})

################################
# Sources
################################

set(BR_CONSO_HEADERS_TEST)

set(BR_CONSO_SOURCES_TEST
	Console.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_CONSO_NAME} ${BR_CONSO_HEADERS_TEST} ${BR_CONSO_SOURCES_TEST})

################################
# Link Lib
################################
target_link_libraries(${BR_TEST_CONSO_NAME} ${USE_LIB})

target_include_directories(${BR_TEST_CONSO_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(${BR_TEST_CONSO_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})

if(BR_UNIX)
#	target_link_libraries(${BR_TEST_CONSO_NAME} sqlite3)
endif()

# OS Specific
if(BR_WINDOWS)
	target_include_directories(${BR_TEST_CONSO_NAME} PUBLIC ${NCURSES_LIB_INCLUDE})
	target_link_libraries(${BR_TEST_CONSO_NAME} ${NCURSES_LIBRARY_FORM})
	target_link_libraries(${BR_TEST_CONSO_NAME} ${NCURSES_LIBRARY_MENU})
	target_link_libraries(${BR_TEST_CONSO_NAME} ${NCURSES_LIBRARY})
	target_link_libraries(${BR_TEST_CONSO_NAME} ${NCURSES_LIBRARY_PANEL})
	target_link_libraries(${BR_TEST_CONSO_NAME} ws2_32)
	target_link_libraries(${BR_TEST_CONSO_NAME} wsock32)
endif()