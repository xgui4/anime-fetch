cmake_minimum_required(VERSION 3.16..3.19)

project(Anime-Fetch-GUI VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

if(WIN32) 
    qt_add_executable(Anime-Fetch-GUI
        "src/app.cpp"
        "src/configs/gui_config.cpp"
        "app.rc"
    )
else()
    qt_add_executable(Anime-Fetch-GUI
       "src/app.cpp"
       "src/configs/gui_config.cpp"
    )
endif()

target_link_libraries(Anime-Fetch-GUI PRIVATE Anime-Fetch-Lib Qt${QT_VERSION_MAJOR}::Widgets)