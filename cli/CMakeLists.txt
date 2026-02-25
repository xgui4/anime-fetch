cmake_minimum_required(VERSION 3.16..3.19)

project(Anime-Fetch VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (LINUX)
    find_package(Curses)
endif()

add_executable(Anime-Fetch
    src/main.cpp
)

if (WIN32)
    add_definitions(-DWIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    target_link_libraries(Anime-Fetch PRIVATE Anime-Fetch-Lib)
else()
    target_link_libraries(Anime-Fetch PRIVATE Anime-Fetch-Lib ${CURSES_LIBRARIES})
endif()