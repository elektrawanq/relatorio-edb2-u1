#include <stdexcept>
#include <vector>
#include <random>

#include "../include/Edge_Neighbor.hpp"
#include "../include/graph_generator.hpp"

/* se edgecount < nodecount - 1, a função ainda gera nodecount - 1 arestas na etapa 1
(garantia de conectividade), ignorando o edgecount pedido, sem avisar.
Como o experimento depende de controlar precisamente m, evite tomar um valor de n/m por
garantido, quando na prática o gerador entregou mais arestas que o pedido.*/

Graph generate_random_graph(value_type nodecount, value_type edgecount, value_type max_weight, unsigned seed)
{
    if (max_weight < 1)
        throw std::invalid_argument("The provided max_weight value must be at least 1.\n");

    std::mt19937 rd(seed);
    std::uniform_int_distribution<value_type> weight_dist(1, max_weight);

    Graph graph;

    if (nodecount <= 0)
    {
        return graph;
    }

    graph.vertices.resize(nodecount);
    graph.neighborhood.resize(nodecount);

    auto add_edge = [&](value_type source, value_type dest, value_type weight)
    {
        graph.edges.push_back({source, dest, weight});
        graph.neighborhood[source].push_back({dest, weight});
    };

    // 1) Garante que o grafo seja conexo: cada novo vértice i (a partir de 1)
    //    recebe uma aresta vinda de algum vértice já existente (0..i-1),
    //    escolhido aleatoriamente. Isso monta uma "árvore geradora" com
    //    nodecount - 1 arestas antes de completar o restante.
    for (value_type i = 1; i < nodecount; i++)
    {
        std::uniform_int_distribution<value_type> parent_pick(0, i - 1);
        value_type parent = parent_pick(rd);
        add_edge(parent, i, weight_dist(rd));
    }

    // 2) Completa até 'edgecount' arestas com pares aleatórios (sem laços).
    value_type edges_so_far = nodecount - 1;
    if (nodecount > 1)
    {
        std::uniform_int_distribution<value_type> node_pick(0, nodecount - 1);
        // Limite de tentativas para não travar caso edgecount seja
        // impossivelmente alto para o nodecount pedido.
        value_type max_attempts = (edgecount - edges_so_far) * 20 + 100;
        value_type attempts = 0;
        while (edges_so_far < edgecount and attempts < max_attempts)
        {
            attempts++;
            value_type u = node_pick(rd);
            value_type v = node_pick(rd);
            if (u == v)
            {
                continue;
            }
            add_edge(u, v, weight_dist(rd));
            edges_so_far++;
        }
    }

    return graph;
}

bool has_negative_weight(const std::vector<std::vector<Neighbor>> &neighborhood)
{
    for (const auto &neighbors : neighborhood)
    {
        for (const auto &neighbor : neighbors)
        {
            if (neighbor.weight < 0)
            {
                return true;
            }
        }
    }
    return false;
}