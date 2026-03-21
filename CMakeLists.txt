cmake_minimum_required(VERSION 3.28)

project(using-std-cpp-26)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp)
