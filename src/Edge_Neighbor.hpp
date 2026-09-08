#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <limits>
#include <optional>
#include <vector>

#include "timer.hpp"

using value_type = int;
const value_type INFINITY = std::numeric_limits<value_type>::max();
const value_type NODECOUNT = 100;

struct Bellman_Ford_Timer { 
    Timer BF_timer;
};

struct Dijkstra_Timer {
    Timer d_timer;
};

// Estrutura focada no Bellman-Ford
struct Edge
{
    value_type source;
    value_type dest;
    value_type weight;
};

// Estrutura focada no Dijkstra 
// Armazena as informações das arestas: destino e o peso para chegar lá
struct Neighbor
{
    value_type dest;
    value_type weight;
};

void Dijkstra(value_type nodecount, value_type inf, std::vector<std::vector<Neighbor>> neighborhood);
void Bellman_Ford(std::vector<Edge> edges);

#endif