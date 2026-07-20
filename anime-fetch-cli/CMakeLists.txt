cmake_minimum_required(VERSION 3.16..3.19)

project(anime-fetch VERSION 0.0.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (LINUX)
    find_package(Curses)
endif() 

if(WIN32)
    enable_language(RC)
        # List your resource file as a source
    set(CMAKE_RC_FLAGS "-D-I${CMAKE_CURRENT_SOURCE_DIR}")
    set(WIN_RESOURCES "app.rc")
endif()

add_executable(anime-fetch
    "src/animefetch.c"
    "src/services/system_info_service.h"
     ${WIN_RESOURCES}
)

if (WIN32)
    add_definitions(-DWIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    target_link_libraries(anime-fetch PRIVATE Anime-Fetch-Lib)
else()
    target_link_libraries(anime-fetch PRIVATE Anime-Fetch-Lib ${CURSES_LIBRARIES})
endif()
