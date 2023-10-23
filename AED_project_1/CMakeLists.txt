cmake_minimum_required(VERSION 3.26)
project(projeto_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(schedule/src)

add_executable(projeto_1
        schedule/src/main.cpp
        schedule/src/ucClasses.cpp
        schedule/src/ucClasses.h
        schedule/src/pairUcClasses.cpp
        schedule/src/Student.cpp
        schedule/src/SetStudents.h
        schedule/src/SetStudents.cpp)
