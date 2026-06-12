cmake_minimum_required(VERSION 3.16..3.19)
project(Anime-Fetch-Lib VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the shared library target
add_library(Anime-Fetch-Lib STATIC 
    "src/os_type.hpp"
    "src/colors.hpp"
    "src/models/cpu_info.hpp"
    "src/models/gpu_info.hpp"
    "src/models/battery_info.hpp"
    "src/models/disk_info.hpp"
    "src/models/gpu_info.hpp"
    "src/models/mainboard_info.hpp"
    "src/models/memory_info.hpp"
    "src/models/os_info.hpp"
    "src/models/kernel_info.hpp"
    "src/models/location.hpp"
    "src/models/image.hpp"
    "src/models/os_tan_family.hpp"
    "src/models/os_tan.hpp"
    "src/models/os_info.hpp"
    "src/modules/cpu_module.cpp"
    "src/modules/cpu_module.h"
    "src/modules/gpu_module.cpp"
    "src/modules/gpu_module.h"
    "src/modules/kernel_info_module.cpp"
    "src/modules/kernel_info_module.h"
    "src/modules/disk_module.cpp"
    "src/modules/disk_module.h"
    "src/modules/os_module.cpp"
    "src/modules/os_module.h"
    "src/modules/mainboard_module.cpp"
    "src/modules/mainboard_module.h"
    "src/modules/disk_module.cpp"
    "src/modules/disk_module.h"
    "src/modules/battery_module.cpp"
    "src/modules/battery_module.h"
    "src/modules/os_tan_module.cpp" 
    "src/modules/os_tan_module.h"
    "src/modules/module.hpp" 
    "src/services/system_info_service.cpp"
    "src/services/system_info_service.h"
    "src/utils/cmdline_utils.cpp"
    "src/utils/cmdline_utils.h"
    "src/utils/utils.cpp"
    "src/utils/utils.hpp"
    "src/configs/lib_config.cpp"
    "src/configs/lib_config.h"
    "src/configs/cmd_args.h"
    "src/configs/cmd_args.cpp"
)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(lfreist-hwinfo_DIR "/usr/local/lib/cmake/hwinfo")
    find_package(lfreist-hwinfo REQUIRED PATHS ${lfreist-hwinfo_DIR} NO_DEFAULT_PATH)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_package(lfreist-hwinfo CONFIG REQUIRED)
endif()

target_include_directories(Anime-Fetch-Lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(Anime-Fetch-Lib PRIVATE lfreist-hwinfo::hwinfo)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(Anime-Fetch-Lib PRIVATE lfreist-hwinfo::hwinfo)
endif()