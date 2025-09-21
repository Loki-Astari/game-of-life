cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game_of_life 
    src/main.cpp
    src/GameOfLife.cpp
)

target_include_directories(game_of_life PRIVATE include)
