macro(add_exec file)
    add_executable(${file} ${file}.cpp)
    target_include_directories(${file} PRIVATE ${CMAKE_SOURCE_DIR}/googletest/googletest/include)
    target_link_libraries(${file} gtest gtest_main)
    gtest_add_tests(${file} "" ${file}.cpp)
endmacro()

#add_exec(c_class_excercise)
add_exec(c_class_solution)