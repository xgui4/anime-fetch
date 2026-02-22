cmake_minimum_required(VERSION 3.16)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Curses for the CLI
find_package(Curses)

# lfreist-hwinfo for Hardware Info 
set(lfreist-hwinfo_DIR "/usr/local/lib/cmake/hwinfo")
find_package(lfreist-hwinfo REQUIRED PATHS ${lfreist-hwinfo_DIR} NO_DEFAULT_PATH)

set(ANIME_FETCH_SRC
    src/utils/cmdline_utils.cpp
    src/utils/utils.cpp
    src/services/system_info_service.cpp
    src/config/app_config.cpp
    src/config/cmd_args.cpp
    src/main.cpp
)

add_executable(Anime-Fetch ${ANIME_FETCH_SRC})

# Link the library
target_link_libraries(Anime-Fetch PRIVATE lfreist-hwinfo::hwinfo ${CURSES_LIBRARIES})

set_target_properties(Anime-Fetch
 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
