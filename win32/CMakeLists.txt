cmake_minimum_required(VERSION 3.5)

project(mediocre_win32 VERSION 0.1 LANGUAGES CXX)

add_executable(
    mediocre_win32 WIN32
    main.cpp
    DeclareDPIAware.manifest
    track_view.cpp track_view.h
)

target_compile_options(mediocre_win32 PRIVATE -mwindows)

target_link_libraries(
    mediocre_win32 PRIVATE
    mediocre_core
)
