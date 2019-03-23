if(WIN32)
	set(EXE ".exe")
endif(WIN32)

set(TEST_RUNNER_NAME "test${PROJECT_NAME}${EXE}")
set(TEST_RUNNER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test/${TEST_RUNNER_NAME})

include(valgrind)

include (CTest)
enable_testing()

add_test(
        NAME ${TEST_RUNNER_NAME}
        COMMAND ${TEST_RUNNER_PATH} ./${PROJECT_NAME}
)

set_tests_properties(${TEST_RUNNER_NAME} PROPERTIES DEPENDS ${PROJECT_NAME})
