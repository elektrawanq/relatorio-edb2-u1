#include <cassert>
#include <stdexcept>
#include <vector>

#include "../include/Edge_Neighbor.hpp"

void Relax_edges_dijkstra(Graph &graph, const value_type &current_vertex, const std::vector<bool> &visitedList)
{
    for (const Neighbor &neighbor : graph.neighborhood[current_vertex])
    {
        if (visitedList[neighbor.dest] != true)
        {

            assert(neighbor.weight >= 0 and "Dijkstra does not support negative weights.");
            assert(neighbor.dest >= 0 and static_cast<size_t>(neighbor.dest) < graph.vertices.size() and "neighbor.dest is out of bounds for graph.vertices.");

            // A nova distância é a distância até o nó atual + o peso da aresta
            value_type new_distance = graph.vertices[current_vertex].distance + neighbor.weight;
            if (new_distance < graph.vertices[neighbor.dest].distance)
            {
                graph.vertices[neighbor.dest].distance = new_distance;
                graph.vertices[neighbor.dest].predecessor = current_vertex;
            }
        }
    }
}

// mesma pré-condição: graph.neighborhood deve ter o mesmo tamanho de graph.vertices
// e que todo neighbor.dest deve estar em [0, graph.vertices.size())
void Dijkstra(Graph &graph, const value_type &source_idx)
{

    // Tratamento do índice: verifica se está dentro dos limites
    if (source_idx < 0)
    {
        throw std::invalid_argument("The provided source_idx value cannot be negative.\n");
    }
    if (static_cast<size_t>(source_idx) >= graph.vertices.size())
    {
        throw std::out_of_range("The accessed index source_idx is out of the allowed bounds.\n");
    }

    // Verificação de segurança: lembrar que os tamanhos são iguais porque tratamos de todos os  vértices
    // neighborhood é uma lista de adjacência indexada por vértice — a posição i
    // guarda os vizinhos do vértice i, então ela naturalmente tem uma entrada
    // por vértice (mesmo que vazia), independente de haver ou não aresta de um vértice para ele mesmo.
    assert(graph.neighborhood.size() == graph.vertices.size() and "graph.neighborhood must have the same size as graph.vertices.");

    Initialize_graph(graph.vertices, source_idx, INFINITY_VAL);

    std::vector<bool> visitedList(graph.vertices.size(), false);

    for (size_t i = 0; i < visitedList.size(); i++)
    {
        value_type current_vertex = -1;
        value_type shortest_dist = INFINITY_VAL;

        // A operação de extrair o valor mínimo do conjunto visitedList
        // de vértices não visitados é feita por meio de uma busca linear.
        // Isso foi feito para seguir a complexidade e implementação sugerida no artigo
        for (size_t j = 0; j < visitedList.size(); j++)
        {
            if (visitedList[j] == false and graph.vertices[j].distance < shortest_dist)
            {
                current_vertex = static_cast<value_type>(j);
                shortest_dist = graph.vertices[j].distance;
            }
        }

        // Verificação de segurança para otimização em grafos desconectados,
        // poupando iterações desnecessárias
        if (current_vertex == -1)
        {
            // Se um vértice for inalcançável, a distância dele continuará sendo infinita
            // significa que todos os nós restantes no grafo estão desconectados da origem
            break;
        }

        // Marca o nó como visitado
        visitedList[current_vertex] = true;

        // Relaxamento das arestas (atualização das distâncias)
        Relax_edges_dijkstra(graph, current_vertex, visitedList);
    }
}