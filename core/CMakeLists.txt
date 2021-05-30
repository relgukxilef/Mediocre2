cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    mediocre_core STATIC
    include/mediocre/tracks.h
    source/tracks.cpp
)

target_include_directories(
    mediocre_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
