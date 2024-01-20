cmake_minimum_required(VERSION 3.26)

project(ComplexNumber)

set(CMAKE_CXX_STANDARD 23)

add_executable(ComplexNumber_run main.cpp)

include_directories(ComplexNumber_lib)
add_subdirectory(ComplexNumber_lib)

target_link_libraries(ComplexNumber_run ComplexNumber_lib)

add_subdirectory(tests)