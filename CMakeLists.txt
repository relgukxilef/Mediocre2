cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mediocre VERSION 0.1 LANGUAGES CXX)

add_subdirectory(core)
add_subdirectory(qwidget)
add_subdirectory(win32)
add_subdirectory(gtk)

add_subdirectory(ui)
