cmake_minimum_required(VERSION 3.16)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses)

set(ANIME_FETCH_SRC
    src/cmdline_utils.cpp
    src/main.cpp
)

add_executable(Anime-Fetch ${ANIME_FETCH_SRC})

set_target_properties(Anime-Fetch
 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)