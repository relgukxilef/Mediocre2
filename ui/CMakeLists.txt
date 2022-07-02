cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ui VERSION 0.1 LANGUAGES CXX)

add_library(
    ui STATIC
    include/ui/ui.h source/ui.cpp
    include/ui/controls.h
)

target_include_directories(
    ui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_library(
    ui_win32 STATIC
    source/win32/controls.cpp
    source/win32/controls_win32.cpp
    include/ui/controls_win32.h
)

target_link_libraries(ui_win32 ui)
