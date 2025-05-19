cmake_minimum_required(VERSION 3.26)
project(Project2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}")
set(CMAKE_BUILD_TYPE "Release")
#add_subdirectory(lib/googletest)
#include_directories(lib/googletest/googletest/include)
#include_directories(lib/googletest/googlemock/include)
include_directories(Code)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")


set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP})
add_executable(Project2
    Code/Main.cpp
    Code/Menu.cpp
    Code/Menu.h
    Code/readCSV.h)
