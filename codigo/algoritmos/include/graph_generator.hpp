
#ifndef GRAPH_GENERATOR_HPP
#define GRAPH_GENERATOR_HPP

#include <vector>
#include <random>

#include "../include/Edge_Neighbor.hpp"
const value_type MAX_WEIGHT = 100;

Graph generate_random_graph(value_type nodecount, value_type edgecount, value_type max_weight = MAX_WEIGHT, unsigned seed = std::random_device{}());

// Verifica se existe algum peso negativo na lista de adjacência.
// Dijkstra espera por pesos >= 0; isso deve ser chamado apenas uma vez, fora do
// trecho cronometrado, antes de rodar o Dijkstra,
// nunca dentro do laço de medição de tempo.
bool has_negative_weight(const std::vector<std::vector<Neighbor>> &neighborhood);

#endif