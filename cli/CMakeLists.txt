cmake_minimum_required(VERSION 3.16..3.19)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Curses for the CLI
find_package(Curses)

add_executable(Anime-Fetch
    src/main.cpp
)

# Link the library
target_link_libraries(Anime-Fetch PRIVATE Anime-Fetch-Lib ${CURSES_LIBRARIES})

set_target_properties(Anime-Fetch
 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
