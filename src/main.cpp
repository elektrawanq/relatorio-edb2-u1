#include <iostream>
#include "../include/Edge_Neighbor.hpp"
#include "../include/csvparser.hpp"


int main()
{
    // Instanciando os temporizadores de cada algoritmo + arquivo .csv
    Dijkstra_Timer dijkstra_timer;
    Bellman_Ford_Timer bellman_ford_timer;
    CsvParser csv;

    // Instanciando o grafo para o Bellman-Ford
    // Cada elemento do vetor representa uma aresta no grafo
    std::vector<Edge> edges;

    // Instanciando o grafo para o Dijkstra
    // neighborhood[u] retorna um vetor com todos os vizinhos do vértice 'u'
    std::vector<std::vector<Neighbor>> neighborhood(NODECOUNT);

    dijkstra_timer.d_timer.start_timer();
    Dijkstra(NODECOUNT, INFINITY_VAL, neighborhood);
    dijkstra_timer.d_timer.end_timer();

    bellman_ford_timer.BF_timer.start_timer();
    Bellman_Ford(edges);
    bellman_ford_timer.BF_timer.end_timer();


    csv.save_csv(dijkstra_timer, bellman_ford_timer, NODECOUNT);
}