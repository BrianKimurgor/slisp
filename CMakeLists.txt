cmake_minimum_required(VERSION 3.15)

project(slisp)

set(CMAKE_CXX_STANDARD 14)

# Add include directories
include_directories(include)

# Add source files
add_executable(slisp
    src/main.cpp
    src/environment.cpp
    src/expression.cpp
    src/interpreter.cpp
    src/tokenize.cpp
)
