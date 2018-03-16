macro(add_exec file)
    add_executable(${file} ${file}.cpp)
    target_include_directories(${file} PRIVATE ${CMAKE_SOURCE_DIR}/googletest/googletest/include)
    target_link_libraries(${file} gtest gtest_main)
    gtest_add_tests(${file} "" ${file}.cpp)
endmacro()

#add_exec(simple_string_operators_solution)
#add_exec(simple_string_functions_solution)
#add_exec(simple_string_functions_excercise)

#add_exec(template_array_solution)
add_exec(template_array_excercise)

#add_exec(circular_buffer)
#add_exec(operator_vector)
#add_exec(template_array2)
#add_exec(template_array3)
