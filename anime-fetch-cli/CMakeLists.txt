cmake_minimum_required(VERSION 3.16..3.19)

project(anime-fetch VERSION 0.0.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(WIN32)
    enable_language(RC)
    set(CMAKE_RC_FLAGS "-D-I${CMAKE_CURRENT_SOURCE_DIR}")
    set(WIN_RESOURCES "app.rc")
endif()

set_source_files_properties("src/animefetch.c" PROPERTIES LANGUAGE C)


add_executable(anime-fetch
    "src/animefetch.c"
    "src/services/system_info_service.h"
    ${WIN_RESOURCES}
)

if (LINUX)
target_compile_definitions(anime-fetch PRIVATE POSIXLY_CORRECT=1)
endif()

if (HURD)
target_compile_definitions(anime-fetch PRIVATE POSIXLY_CORRECT=1)
endif()

target_include_directories(anime-fetch PRIVATE src/services)

if (WIN32)
    add_definitions(-DWIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
