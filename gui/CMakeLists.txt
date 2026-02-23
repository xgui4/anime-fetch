cmake_minimum_required(VERSION 3.16..3.19)

project(Anime-Fetch-GUI VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(Anime-Fetch-GUI
    src/app.cpp
)

target_link_libraries(Anime-Fetch-GUI PRIVATE Anime-Fetch-Lib Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Anime-Fetch-GUI
 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)