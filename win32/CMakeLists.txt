cmake_minimum_required(VERSION 3.5)

project(mediocre_win32 VERSION 0.1 LANGUAGES CXX)

add_executable(
    mediocre_win32 WIN32
    main.cpp
    DeclareDPIAware.manifest
    track_view.h track_view.cpp
    list_view.h list_view.cpp
)

target_compile_options(mediocre_win32 PRIVATE -mwindows)

target_link_libraries(
    mediocre_win32 PRIVATE
    mediocre_core
    ui_win32
)
