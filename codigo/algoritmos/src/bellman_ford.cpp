#include <cassert>
#include <iostream>
#include <stdexcept>

#include "../include/Edge_Neighbor.hpp"

// Função usada também em Dijkstra
void Initialize_graph(std::vector<Vertex> &vertices, const value_type &source_idx, const value_type &inf)
{
    for (std::size_t i = 0; i < vertices.size(); i++)
    {
        if (i == static_cast<std::size_t>(source_idx))
            vertices[i].distance = 0;
        else
            vertices[i].distance = inf;

        vertices[i].predecessor = std::nullopt; // "v.predecessor := null", para Alvaro rodar milhões de vezes sem quebrar
    }
}

// Relaxa todas as arestas |V| - 1 vezes
void Relax_edges_bellman_ford(std::vector<Vertex> &vertices, const std::vector<Edge> &edges, const value_type &inf)
{
    for (std::size_t i = 1; i < vertices.size(); i++)
    {
        for (const Edge &ed : edges)
        {
            value_type e = ed.source;
            value_type d = ed.dest;

            assert(e >= 0 and static_cast<size_t>(e) < vertices.size() and "ed.source is out of bounds for vertices.");
            assert(d >= 0 and static_cast<size_t>(d) < vertices.size() and "ed.dest is out of bounds for vertices.");

            if (vertices[e].distance < inf)
            {
                if (vertices[d].distance > vertices[e].distance + ed.weight)
                {
                    vertices[d].distance = vertices[e].distance + ed.weight;
                    vertices[d].predecessor = e;
                }
            }
        }
    }
}

// Verifica se há ciclo de peso negativo
bool Check_negative_weight_cycles(const std::vector<Vertex> &vertices, const std::vector<Edge> &edges, const value_type &inf)
{
    for (const auto &ed : edges)
    {
        value_type e = ed.source;
        value_type d = ed.dest;

        assert(e >= 0 and static_cast<size_t>(e) < vertices.size() and "ed.source is out of bounds for vertices.");
        assert(d >= 0 and static_cast<size_t>(d) < vertices.size() and "ed.dest is out of bounds for vertices.");
        
        if (vertices[e].distance < inf)
        {
            if (vertices[d].distance > vertices[e].distance + ed.weight)
            {
                std::cerr << "Graph contains a negative-weight cycle!\n";
                return true;
            }
        }
    }
    return false;
}

// Retorna true se o resultado é válido (sem ciclo negativo), false caso contrário.
// graph.vertices fica preenchido com distance/predecessor ao final.
bool Bellman_Ford(Graph &graph, const value_type &source_idx)
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

    // Procedimento de Bellman-Ford

    // Pré-condição: assume que toda Edge em graph.edges tem
    // source e dest dentro de [0, graph.vertices.size()), tratar no gerador de grafos
    // Para fazer: Garantir que o gerador de grafos nunca seja capaz
    // de produzir uma Edge com source/dest fora de [0, nodecount)
    Initialize_graph(graph.vertices, source_idx, INFINITY_VAL);
    Relax_edges_bellman_ford(graph.vertices, graph.edges, INFINITY_VAL);
    bool has_negative_cycle = Check_negative_weight_cycles(graph.vertices, graph.edges, INFINITY_VAL);
    return !has_negative_cycle;
}