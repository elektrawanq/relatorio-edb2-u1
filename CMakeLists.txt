cmake_minimum_required(VERSION 3.10)
project(GraphAlgorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Diretório dos arquivos de cabeçalho
include_directories(${CMAKE_SOURCE_DIR}/include)

# Arquivos fonte localizados na pasta src
set(SOURCES
    src/main.cpp
    src/dijkstra.cpp
    src/bellman_ford.cpp
)

# Executável gerado
add_executable(edb2_graph ${SOURCES})