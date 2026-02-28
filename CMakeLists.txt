# Add VCPKG for MS Windows, it is a experiment for the Windows version
if (WIN32)
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    endif()
endif()

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

# Build the GUI interface
add_subdirectory(gui)
