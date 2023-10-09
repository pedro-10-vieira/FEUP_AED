cmake_minimum_required(VERSION 3.10)
project(aed2324_p01)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(aed2324_p01 main.cpp Tests/tests.cpp Tests/funWithCycles.cpp)

target_link_libraries(aed2324_p01 gtest gtest_main)
