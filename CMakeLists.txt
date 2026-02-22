cmake_minimum_required(VERSION 3.16)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build the cli and gui interface
add_subdirectory(cli)
add_subdirectory(gui)