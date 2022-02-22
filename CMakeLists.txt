cmake_minimum_required(VERSION 3.21)
project(idj_engine)

set(CMAKE_C_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-lSDL2 -lSDL2_image -lSDL2_mixer -lm")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(idj-engine src/Game.cpp src/State.cpp src/Sprite.cpp src/Music.cpp src/main.cpp src/GameObject.cpp src/Sound.cpp src/Face.cpp src/Rect.cpp src/Vec2.cpp src/Component.cpp src/TileSet.cpp src/TileMap.cpp src/Resources.cpp include/Resources.h src/InputManager.cpp include/InputManager.h src/Camera.cpp include/Camera.h)
add_executable(Testes test/tileMapTest.cpp src/Game.cpp src/State.cpp src/Sprite.cpp src/Music.cpp src/GameObject.cpp src/Sound.cpp src/Face.cpp src/Rect.cpp src/Vec2.cpp src/Component.cpp src/TileSet.cpp src/TileMap.cpp src/Resources.cpp include/Resources.h)
target_include_directories(idj-engine PRIVATE include)
target_include_directories(Testes PRIVATE include)
