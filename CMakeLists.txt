cmake_minimum_required(VERSION 3.0.2)
project(game_of_life)

set(PROJECT_LINK_LIBS libsfml-audio.so libsfml-graphics.so libsfml-system.so libsfml-window.so libXrandr.so libXcursor.so)
link_directories(/usr/local/lib)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(game_of_life ${SOURCES})
target_link_libraries(game_of_life ${PROJECT_LINK_LIBS})
