cmake_minimum_required(VERSION 3.28)
project(hello-module)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello-module)

target_sources(hello-module
  PRIVATE
    main.cpp
  PRIVATE FILE_SET CXX_MODULES FILES
    helloworld.cpp
)
