cmake_minimum_required(VERSION 3.10)
project(edb2_graph CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Caminho base dos fontes
set(SRC_DIR ${CMAKE_SOURCE_DIR}/codigo/algoritmos)

add_executable(edb2_graph
    ${SRC_DIR}/src/main.cpp
    ${SRC_DIR}/src/dijkstra.cpp
    ${SRC_DIR}/src/bellman_ford.cpp
    ${SRC_DIR}/src/graph_generator.cpp
)

target_include_directories(edb2_graph PRIVATE
    ${SRC_DIR}/include
)