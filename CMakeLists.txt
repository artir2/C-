cmake_minimum_required(VERSION 3.13)  # CMake version check
project(cpp_snippets)               # Create project "cpp_snippets"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES test1.cpp)
set(SOURCE_FILES fast_container.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(cpp_snippets ${SOURCE_FILES})
