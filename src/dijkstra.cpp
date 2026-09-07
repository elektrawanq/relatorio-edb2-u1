#include "Edge_Neighbor.hpp"

void Dijkstra(value_type nodecount, value_type inf, std::vector<std::vector<Neighbor>> neighborhood)
{

    // Criando listas de distâncias, de vértices anteriores e de nós visitados
    std::vector<value_type> distance(nodecount, inf); // nodecount é o tamanho e inf é o valor guardado
    value_type source = 0;
    distance[source] = 0;
    // std::optional inicializa os anteriores como vazios do tipo value_type
    std::vector<std::optional<value_type>> predecessor(nodecount);
    std::vector<bool> visitedList(nodecount, false);
    value_type current_vertex;

    for (auto i = 0; i < nodecount; i++)
    {
        value_type distmin = inf;
        for(auto j = 0; j < nodecount; j++) {
            if(visitedList[j] == false and distance[j] <= distmin) {
                current_vertex = j;
                distmin = distance[j];
            }
        }
        visitedList[current_vertex] = true;
        for(auto i = 0; i < nodecount; i++) {
            for(auto j = 0; j < neighborhood[current_vertex].size(); j++) {
                //aqui
            }
        }
    }
}