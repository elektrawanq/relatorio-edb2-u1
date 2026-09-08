#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <fstream>
#include <iomanip>
#include <stdexcept>

#include "Edge_Neighbor.hpp"
struct CsvParser {
    static void save_csv(Dijkstra_Timer dij, Bellman_Ford_Timer bell, int size_n) {

        std::ofstream csv("results.csv", std::ios::app);
        if (csv.is_open()) {
            csv << std::scientific << std::setprecision(2);
            csv << dij.d_timer.total_time() << "," // Djikstra time
            << bell.BF_timer.total_time() << "," // Bellman TIme
            << size_n << ","; // Size of n
            csv.close();
        } else {
            throw std::runtime_error("Erro: o arquivo csv não pôde ser aberto.");
        }
    }
};

#endif