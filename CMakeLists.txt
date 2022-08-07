cmake_minimum_required(VERSION 3.23)
project(raycasting_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(raycasting_engine main.cpp headers/Variable.hpp headers/Map.hpp headers/Cell.hpp headers/Player.hpp src/Cell.cpp src/Map.cpp src/Player.cpp headers/World.hpp src/World.cpp headers/Ray.hpp src/Ray.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
SET(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(raycasting_engine sfml-system sfml-window sfml-graphics sfml-audio)

