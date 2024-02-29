# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(slisp)

# Add the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers and source files
include_directories(include)

# List of source files (excluding tokenize.cpp)
file(GLOB SOURCES "src/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*tokenize.cpp$")

# Add the executable
add_executable(slisp ${SOURCES} src/tokenize.cpp)

# Add any other dependencies or flags as needed
