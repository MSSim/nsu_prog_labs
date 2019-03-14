cmake_minimum_required(VERSION 3.5.1)
project(lab0 C)

set(SRC src/main.c)

add_executable(${PROJECT_NAME} ${SRC})

if(${CMAKE_C_COMPILER} STREQUAL "GNU")
	target_link_libraries(${PROJECT_NAME} m)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
