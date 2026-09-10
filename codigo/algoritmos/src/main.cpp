#include <iostream>
#include <string>
#include <random>
#include "../include/Edge_Neighbor.hpp"
#include "../include/csvparser.hpp"
#include "../include/graph_generator.hpp"

int main(int argc, char* argv[])
{
    // 1. Parametrização da entrada n
    if (argc < 2) {
        std::cerr << "Use: " << argv[0] << " <number_of_nodes>\n";
        return EXIT_FAILURE;
    }
    
    value_type nodecount = std::stoi(argv[1]);
    
    // O artigo especifica testes onde o número de arestas (m) é igual ao número de nós (n).
    value_type edgecount = nodecount; 
    
    // 2. Isolamento de variáveis e alocações antes das medições
    Dijkstra_Timer dijkstra_timer;
    Bellman_Ford_Timer bellman_ford_timer;
    CsvParser csv;

    // Inicialização correta da semente
    unsigned seed = std::random_device{}(); 
    
    std::cout << "Generating a graph with " << nodecount << " nodes and " << edgecount << " edges...\n";
    Graph graph = generate_random_graph(nodecount, edgecount, MAX_WEIGHT, seed);
    
    // Conforme estabelecido, usar source_idx = 0 garante alcançar todos os vértices neste gerador
    value_type source_idx = 0;

    // Verificações prévias que NÃO devem estar no tempo medido
    bool has_neg_weight = has_negative_weight(graph.neighborhood);
    if (has_neg_weight)
    {
        std::cerr << "Warning: The graph contains negative weights. Dijkstra assumes positive weights.\n";
    }

    // ==========================================
    // 3. Medição estrita de tempo para Dijkstra
    // ==========================================
    dijkstra_timer.d_timer.start_timer();
    Dijkstra(graph, source_idx);
    dijkstra_timer.d_timer.end_timer();

    // ==========================================
    // 4. Medição estrita de tempo para Bellman-Ford
    // ==========================================
    bellman_ford_timer.BF_timer.start_timer();
    bool bf_success = Bellman_Ford(graph, source_idx);
    bellman_ford_timer.BF_timer.end_timer();

    if (!bf_success)
    {
        std::cerr << "Error: The graph contains negative-weight cycles. Bellman-Ford failed.\n";
        return EXIT_FAILURE;
    }

    // 5. Salvando resultados
    csv.save_csv(dijkstra_timer, bellman_ford_timer, nodecount);
    std::cout << "Execution completed. Times recorded in the .csv file.\n";

    return EXIT_SUCCESS;
}