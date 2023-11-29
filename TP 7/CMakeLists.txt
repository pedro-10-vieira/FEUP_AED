cmake_minimum_required(VERSION 3.10)
project(aed2324_p07)

set(CMAKE_CXX_STANDARD 11)

set( CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}" )
set( CMAKE_BUILD_TYPE "Release" )
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
add_subdirectory(lib/benchmark)
include_directories(lib/benchmark/include)
set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP} )

add_executable(aed2324_p07 main.cpp Tests/tests.cpp Tests/box.cpp Tests/packagingMachine.cpp Tests/funPQProblem.cpp)

target_link_libraries(aed2324_p07 gtest gtest_main benchmark benchmark_main)
