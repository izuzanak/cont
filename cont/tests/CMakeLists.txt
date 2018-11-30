
cmake_minimum_required(VERSION 3.1.0)

project(cont_c)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/proc_files)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source_files)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/header_files)
set(PROC_FILES proc_files)

# - process p_basic -
add_custom_command(OUTPUT ${PROC_FILES}/p.basic.c
    DEPENDS ${SOURCE_FILES}/basic.c
    DEPENDS ${HEADER_FILES}/basic.h
    COMMAND process_c ${SOURCE_FILES}/basic.c ${HEADER_FILES} > ${PROC_FILES}/p.basic.c)

add_custom_target(p_basic
    DEPENDS ${PROC_FILES}/p.basic.c)

# - process p_array_test -
add_custom_command(OUTPUT ${PROC_FILES}/p.array_test.c
    DEPENDS ${SOURCE_FILES}/array_test.c
    DEPENDS ${HEADER_FILES}/basic.h
    DEPENDS ${HEADER_FILES}/array_test.h
    COMMAND process_c ${SOURCE_FILES}/array_test.c ${HEADER_FILES} > ${PROC_FILES}/p.array_test.c)

add_custom_target(p_array_test
    DEPENDS ${PROC_FILES}/p.array_test.c)

# - array test -
add_executable(array_test ${PROC_FILES}/p.basic.c ${PROC_FILES}/p.array_test.c)
add_dependencies(array_test p_basic p_array_test)
add_test(array_test_all array_test all)

# - process p_queue_test -
add_custom_command(OUTPUT ${PROC_FILES}/p.queue_test.c
    DEPENDS ${SOURCE_FILES}/queue_test.c
    DEPENDS ${HEADER_FILES}/basic.h
    DEPENDS ${HEADER_FILES}/queue_test.h
    COMMAND process_c ${SOURCE_FILES}/queue_test.c ${HEADER_FILES} > ${PROC_FILES}/p.queue_test.c)

add_custom_target(p_queue_test
    DEPENDS ${PROC_FILES}/p.queue_test.c)

# - queue test -
add_executable(queue_test ${PROC_FILES}/p.basic.c ${PROC_FILES}/p.queue_test.c)
add_dependencies(queue_test p_basic p_queue_test)
add_test(queue_test_all queue_test all)

#add_definitions(-O3 -Wall -Wfatal-errors -Wno-class-memaccess)
#add_definitions(-g -Wall -Wfatal-errors -Wno-class-memaccess)
add_definitions(-Wall -Wfatal-errors)

