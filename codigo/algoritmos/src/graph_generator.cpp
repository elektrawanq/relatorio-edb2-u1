#include <stdexcept>
#include <unordered_set>
#include <vector>
#include <random>

#include "../include/Edge_Neighbor.hpp"
#include "../include/graph_generator.hpp"

/* IMPORTANTE (ver comentário completo no .hpp):
   - edgecount fora de [nodecount - 1, nodecount * (nodecount - 1)] agora
     lança std::invalid_argument em vez de ser silenciosamente ignorado.
   - Se as tentativas se esgotarem antes de atingir edgecount, lança
     std::runtime_error em vez de devolver um grafo com menos arestas do
     que o pedido. Isso é essencial porque o experimento depende de saber
     exatamente qual m foi testado.
   - Não há mais arestas paralelas: cada par (u, v) dirigido só pode
     aparecer uma vez em graph.edges.
   - Conectividade: a árvore geradora da etapa 1 só garante que o vértice
     0 alcance todos os outros. Os benchmarks devem sempre usar
     source_idx = 0 com este gerador. */

Graph generate_random_graph(value_type nodecount, value_type edgecount, value_type max_weight, unsigned seed)
{
    if (max_weight < 1)
        throw std::invalid_argument("The provided max_weight value must be at least 1.\n");

    if (nodecount <= 0)
    {
        return Graph{};
    }

    if (edgecount < 0)
    {
        throw std::invalid_argument("The provided edgecount value cannot be negative.\n");
    }

    // Mínimo de arestas (sempre é a quantidade de nós - 1) para garantir a conectividade do grafo
    const value_type min_edges = nodecount - 1;

    // Máximo de arestas deve ser sempre o máximo de conexões possíveis:
    // nodecount nós * quantidade restante de nós (nodecount - 1)
    const long long max_edges_ll =
        static_cast<long long>(nodecount) * static_cast<long long>(nodecount - 1);

    // Validação dos valores mínimo e máximo de arestas
    if (edgecount < min_edges)
    {
        throw std::invalid_argument(
            "edgecount is too small: a connected graph with 'nodecount' vertices "
            "requires at least (nodecount - 1) edges.\n");
    }
    if (static_cast<long long>(edgecount) > max_edges_ll)
    {
        throw std::invalid_argument(
            "edgecount is too large: it exceeds the maximum number of distinct "
            "directed edges (without self-loops) possible for this nodecount.\n");
    }

    std::mt19937 rd(seed);
    std::uniform_int_distribution<value_type> weight_dist(1, max_weight);

    Graph graph;

    graph.vertices.resize(nodecount);
    graph.neighborhood.resize(nodecount);
    graph.edges.reserve(static_cast<size_t>(edgecount));

    // Guarda os pares (source, dest) já usados, para impedir arestas
    // paralelas. Codifica o par como uma chave 64 bits única.
    std::unordered_set<int64_t> existing_edges;
    existing_edges.reserve(static_cast<size_t>(edgecount) * 2);

    auto encode_pair = [nodecount](value_type source, value_type dest) -> int64_t
    {
        return static_cast<int64_t>(source) * static_cast<int64_t>(nodecount) + static_cast<int64_t>(dest);
    };

    auto add_edge = [&](value_type source, value_type dest, value_type weight)
    {
        graph.edges.push_back({source, dest, weight});
        graph.neighborhood[source].push_back({dest, weight});
        existing_edges.insert(encode_pair(source, dest));
    };

    // 1) Garante que o grafo seja conexo (a partir do vértice 0): cada
    //    novo vértice i (a partir de 1) recebe uma aresta vinda de algum
    //    vértice já existente (0..i-1), escolhido aleatoriamente. Isso
    //    monta uma "árvore geradora" com nodecount - 1 arestas antes de
    //    completar o restante.
    //
    //    ATENÇÃO: isso garante alcançabilidade a PARTIR do vértice 0, não
    //    a partir de um vértice arbitrário. Ver nota de conectividade no
    //    graph_generator.hpp — os benchmarks devem sempre usar
    //    source_idx = 0 com este gerador.
    for (value_type i = 1; i < nodecount; i++)
    {
        std::uniform_int_distribution<value_type> parent_pick(0, i - 1);
        value_type parent = parent_pick(rd);
        add_edge(parent, i, weight_dist(rd));
    }

    // 2) Completa até 'edgecount' arestas com pares aleatórios distintos
    // (sem laços, sem paralelas).
    value_type edges_so_far = nodecount - 1;
    if (nodecount > 1 and edges_so_far < edgecount)
    {
        std::uniform_int_distribution<value_type> node_pick(0, nodecount - 1);
        // Limite de tentativas para não travar caso edgecount esteja
        // próximo do máximo teórico (muitas colisões esperadas)
        long long remaining = static_cast<long long>(edgecount) - static_cast<long long>(edges_so_far);
        long long max_attempts = remaining * 20 + 100;
        long long attempts = 0;

        while (edges_so_far < edgecount and attempts < max_attempts)
        {
            attempts++;
            value_type e = node_pick(rd);
            value_type d = node_pick(rd);
            if (e == d)
            {
                continue;
            }
            if (existing_edges.find(encode_pair(e, d)) != existing_edges.end())
            {
                // já existe essa aresta dirigida, evita paralela
                continue;
            }
            add_edge(e, d, weight_dist(rd));
            edges_so_far++;
        }

        // Antes: se as tentativas se esgotassem, a função devolvia o
        // grafo incompleto silenciosamente. Agora isso é um erro: o
        // experimento não pode assumir um m diferente do que foi pedido.
        if (edges_so_far < edgecount)
        {
            throw std::runtime_error(
                "generate_random_graph: could not reach the requested edgecount "
                "within the attempt limit (the requested edge density may be too "
                "close to the maximum for this nodecount).\n");
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