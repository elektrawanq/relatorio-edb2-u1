#ifndef EDGE_NEIGHBOR_HPP
#define EDGE_NEIGHBOR_HPP

#include <cassert>
#include <limits>
#include <optional>
#include <stdexcept>
#include <vector>

using value_type = int;
const value_type INFINITY_VAL = std::numeric_limits<value_type>::max();

struct Vertex
{
    value_type distance;
    std::optional<value_type> predecessor;
};

// Estrutura focada no Bellman-Ford
struct Edge
{
    value_type source; // guarda o índice de source
    value_type dest;   // guarda o índice de destination
    value_type weight;
};

// Estrutura focada no Dijkstra
// Armazena as informações das arestas: destino e o peso para chegar lá
struct Neighbor
{
    value_type dest;
    value_type weight;
};

// Dijkstra pede para receber um grafo (neighborhood), usei em Bellman-Ford também
struct Graph
{
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<std::vector<Neighbor>> neighborhood;
};

// Dijkstra: funções

void Relax_edges_dijkstra(Graph &graph, const value_type &current_vertex, const std::vector<bool> &visitedList);

void Dijkstra(Graph &graph, const value_type &source_idx);

// Bellman-Ford: funções auxiliares

void Initialize_graph(std::vector<Vertex> &vertices, const value_type &source_idx, const value_type &inf);

void Relax_edges_bellman_ford(std::vector<Vertex> &vertices, const std::vector<Edge> &edges, const value_type &inf);

bool Check_negative_weight_cycles(const std::vector<Vertex> &vertices, const std::vector<Edge> &edges, const value_type &inf);

// Retorna bool: true se não há ciclo negativo (resultado válido), false se detectou ciclo negativo.
// Recebe Graph por referência porque graph.vertices é modificado in-place (distance/predecessor).
bool Bellman_Ford(Graph &graph, const value_type &source_idx);

#endif