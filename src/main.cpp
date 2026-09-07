#include <iostream>
#include "Edge_Neighbor.hpp"


int main()
{
    // Instanciando o grafo para o Bellman-Ford
    // Cada elemento do vetor representa uma aresta no grafo
    std::vector<Edge> edges;

    // Instanciando o grafo para o Dijkstra
    // neighborhood[u] retorna um vetor com todos os vizinhos do vértice 'u'
    std::vector<std::vector<Neighbor>> neighborhood(NODECOUNT);
    Dijkstra(NODECOUNT, INFINITY, neighborhood);
}