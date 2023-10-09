cmake_minimum_required(VERSION 3.10)
project(aed2324_p02)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
add_subdirectory(lib/benchmark)
include_directories(lib/benchmark/include)

file(COPY Tests/river DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(aed2324_p02 main.cpp Tests/tests.cpp Tests/funWithComplexity.cpp)

target_link_libraries(aed2324_p02 gtest gtest_main benchmark benchmark_main)