#include <iostream>
#include "../include/Edge_Neighbor.hpp"
#include "../include/csvparser.hpp"
#include "../include/graph_generator.hpp"

int main()
{
    // Instanciando os temporizadores de cada algoritmo + arquivo .csv
    Dijkstra_Timer dijkstra_timer;
    Bellman_Ford_Timer bellman_ford_timer;
    CsvParser csv;

    // Instanciando a semente de geração aleatória do grafo
    unsigned seed;
    // Instanciando a quantidade de nós e de arestas
    value_type nodecount, edgecount;
    // Instanciando o grafo
    Graph graph = generate_random_graph(nodecount, edgecount, MAX_WEIGHT, seed);
    value_type source_idx;


    dijkstra_timer.d_timer.start_timer();
    Dijkstra(graph, source_idx);
    dijkstra_timer.d_timer.end_timer();

    bellman_ford_timer.BF_timer.start_timer();
    Bellman_Ford(graph, source_idx);
    bellman_ford_timer.BF_timer.end_timer();

    csv.save_csv(dijkstra_timer, bellman_ford_timer, nodecount);
}