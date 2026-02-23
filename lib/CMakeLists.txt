cmake_minimum_required(VERSION 3.16..3.19)
project(Anime-Fetch-Lib VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the shared library target
add_library(Anime-Fetch-Lib SHARED 
    src/lib.cpp
    src/os_type.hpp
    src/colors.hpp
    src/models/cpu_info.hpp
    src/models/gpu_info.hpp
    src/services/system_info_service.cpp
    src/services/system_info_service.h
    src/utils/cmdline_utils.cpp
    src/utils/cmdline_utils.h
    src/utils/utils.cpp
    src/utils/utils.hpp
)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # lfreist-hwinfo for Hardware Info 
    set(lfreist-hwinfo_DIR "/usr/local/lib/cmake/hwinfo")
    find_package(lfreist-hwinfo REQUIRED PATHS ${lfreist-hwinfo_DIR} NO_DEFAULT_PATH)
endif()

# Specify the include directories for targets that link to 'utils'.
# The PUBLIC keyword means that the include directory will be passed to 
# the main application as well.
target_include_directories(Anime-Fetch-Lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(Anime-Fetch-Lib PRIVATE lfreist-hwinfo::hwinfo)
endif()