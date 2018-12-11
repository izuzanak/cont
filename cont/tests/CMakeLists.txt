
cmake_minimum_required(VERSION 3.1.0)

project(cont_c)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/proc_files)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source_files)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/header_files)
set(PROC_FILES proc_files)

function(process_prep TARGET)
  execute_process(COMMAND process_c --deps ${SOURCE_FILES}/${TARGET}.c ${HEADER_FILES}
      OUTPUT_VARIABLE DEPS)
  add_custom_command(OUTPUT ${PROC_FILES}/p.${TARGET}.c
      DEPENDS ${DEPS}
      COMMAND process_c ${SOURCE_FILES}/${TARGET}.c ${HEADER_FILES} > ${PROC_FILES}/p.${TARGET}.c)
  add_custom_target(p_${TARGET}
      DEPENDS ${PROC_FILES}/p.${TARGET}.c)
endfunction()

# - process p_basic -
process_prep(basic)

# - process p_array_test -
process_prep(array_test)

# - array test -
add_executable(array_test ${PROC_FILES}/p.basic.c ${PROC_FILES}/p.array_test.c)
add_dependencies(array_test p_basic p_array_test)
add_test(array_test_all array_test all)

# - process p_queue_test -
process_prep(queue_test)

# - queue test -
add_executable(queue_test ${PROC_FILES}/p.basic.c ${PROC_FILES}/p.queue_test.c)
add_dependencies(queue_test p_basic p_queue_test)
add_test(queue_test_all queue_test all)

#add_definitions(-O3 -Wall -Wfatal-errors -Wno-class-memaccess)
#add_definitions(-g -Wall -Wfatal-errors -Wno-class-memaccess)
add_definitions(-Wall -Wfatal-errors)

