cmake_minimum_required(VERSION 3.21)
project(idj_engine)

set(CMAKE_C_STANDARD 14)


add_executable(idj-engine src/Game.cpp src/State.cpp src/Sprite.cpp  src/Music.cpp src/main.cpp)
target_include_directories(idj-engine PRIVATE include)
