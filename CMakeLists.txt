cmake_minimum_required(VERSION 3.16..3.19)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# compile command
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# build the shared library
add_subdirectory(lib)

# Build the cli and gui interface
add_subdirectory(cli)
add_subdirectory(gui)