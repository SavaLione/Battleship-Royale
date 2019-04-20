project(${BR_TEST_SPDLOG_NAME})

################################
# Sources
################################

set(BR_SPDLOG_SOURCES_TEST
	spdlog.cpp)

################################
# Executable
################################
add_executable(${BR_TEST_SPDLOG_NAME} ${BR_SPDLOG_SOURCES_TEST})

################################
# Link Lib
################################

target_include_directories(${BR_TEST_SPDLOG_NAME} PUBLIC ${SPDLOG_LIB_INCLUDE})