#include "../include/Edge_Neighbor.hpp"

std::vector<std::optional<value_type>> Dijkstra(Graph graph, Vertex source) {}

// transformar Dijkstra para receber um grafo e um source
std::vector<std::optional<value_type>> Dijkstra(value_type nodecount, value_type inf, std::vector<std::vector<Neighbor>> neighborhood)
{
    // Fase de Inicialização
    // Criando listas de distâncias, de vértices anteriores e de nós visitados
    std::vector<value_type> distance(nodecount, inf);
    value_type source = 0;
    distance[source] = 0;
    std::vector<std::optional<value_type>> predecessor(nodecount);
    std::vector<bool> visitedList(nodecount, false);

    for (auto i = 0; i < nodecount; i++)
    {
        value_type current_vertex = -1;
        value_type shortest_dist = inf;

        // A operação de extrair o valor mínimo do conjunto visitedList
        // de vértices não visitados é feita por meio de uma busca linear.
        // Isso foi feito para seguir a complexidade e implementação sugerida no artigo
        for (auto j = 0; j < nodecount; j++)
        {
            if (visitedList[j] == false and distance[j] < shortest_dist)
            {
                current_vertex = j;
                shortest_dist = distance[j];
            }
        }

        // Verificação de segurança para otimização em grafos desconectados, 
        // poupando iterações desnecessárias
        if(current_vertex == -1) {
            // Se um vértice for inalcançável, a distância dele continuará sendo inf
            // significa que todos os nós restantes no grafo estão desconectados da origem
            break;
        }

        // Marca o nó como visitado
        visitedList[current_vertex] = true;

        // Relaxamento das arestas (atualização das distâncias)
        for (auto &neighbor : neighborhood[current_vertex])
        {
            if (visitedList[neighbor.dest] != true)
            {
                // A nova distância é a distância até o nó atual + o peso da aresta
                value_type new_distance = distance[current_vertex] + neighbor.weight;
                if (new_distance < distance[neighbor.dest])
                {
                    distance[neighbor.dest] = new_distance;
                    predecessor[neighbor.dest] = current_vertex;
                }
            }
        }
    }

    return predecessor;
}