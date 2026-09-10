
#ifndef GRAPH_GENERATOR_HPP
#define GRAPH_GENERATOR_HPP

#include <vector>
#include <random>

#include "../include/Edge_Neighbor.hpp"
const value_type MAX_WEIGHT = 100;

// Gera um grafo aleatório com exatamente 'nodecount' vértices e exatamente
// 'edgecount' arestas (dirigidas, sem laços, sem arestas paralelas).
//
// GARANTIAS E PRÉ-CONDIÇÕES:
// - edgecount deve estar em [nodecount - 1, nodecount * (nodecount - 1)],
//   caso contrário a função lança std::invalid_argument. O limite inferior
//   existe porque a etapa 1 (ver .cpp) sempre constrói uma árvore geradora
//   com nodecount - 1 arestas para garantir conectividade; o limite
//   superior é o número máximo de arestas dirigidas distintas possíveis
//   sem laços.
// - Se, mesmo dentro desse intervalo, não for possível completar o
//   edgecount pedido dentro do limite de tentativas (grafos quase
//   completos), a função lança std::runtime_error em vez de devolver
//   silenciosamente um grafo com menos arestas do que o solicitado.
// - CONECTIVIDADE: a árvore geradora da etapa 1 conecta cada vértice i
//   a um "pai" com índice MENOR que i (pai em [0, i-1]). Isso garante
//   que o vértice 0 alcance todos os demais, mas NÃO garante que outro
//   vértice qualquer alcance todo o grafo. Portanto, ao rodar os
//   benchmarks de Dijkstra/Bellman-Ford sobre grafos produzidos por esta
//   função, source_idx DEVE ser 0 — usar outro vértice como origem pode
//   deixar parte do grafo inalcançável, fazendo o Dijkstra (que tem uma
//   otimização de parada antecipada) terminar mais cedo e distorcer a
//   medição de tempo em relação ao O(n^2) teórico esperado.
Graph generate_random_graph(value_type nodecount, value_type edgecount, value_type max_weight = MAX_WEIGHT, unsigned seed = std::random_device{}());

// Verifica se existe algum peso negativo na lista de adjacência.
// Dijkstra espera por pesos >= 0; isso deve ser chamado apenas uma vez, fora do
// trecho cronometrado, antes de rodar o Dijkstra,
// nunca dentro do laço de medição de tempo.
bool has_negative_weight(const std::vector<std::vector<Neighbor>> &neighborhood);

#endif