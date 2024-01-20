project(tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the tests_run target
add_executable(tests_run ComplexNumber_tests.cpp)

# linking tests_run with ComplexNumbersLib which will be tested
target_link_libraries(tests_run ComplexNumber_lib)

target_link_libraries(tests_run gtest gtest_main)

