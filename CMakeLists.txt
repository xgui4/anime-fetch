# Make CMake 3.16 the minimum and add 3.19 versions for presets supports
cmake_minimum_required(VERSION 3.16..3.19)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

# Set the language to C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# make sure compile_command.json is created
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add Compilers Warning
include(CompilerWarnings.cmake)

# build the shared library
add_subdirectory(lib)

# Build the cli and gui interface
add_subdirectory(cli)
add_subdirectory(gui)