#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <fstream>
// #include <iomanip>
#include <stdexcept>
#include <filesystem>

#include "timer.hpp"

struct CsvParser {
    static void save_csv(Dijkstra_Timer dij, Bellman_Ford_Timer bell, int size_n) {

        bool file_exist = std::filesystem::exists("results.csv") && std::filesystem::file_size("results.csv") > 0;
        std::ofstream csv("results.csv", std::ios::app);
        if (csv.is_open()) {
            if (!file_exist) {
                csv << "dijkstra_time_ms,bellman_ford_time_ms,size_n\n"; // columns
            }
            // csv << std::scientific << std::setprecision(2);
            csv << dij.d_timer.total_time() << "," // Djikstra time
            << bell.BF_timer.total_time() << "," // Bellman TIme
            << size_n << "\n"; // Size of n
            csv.close();
        } else {
            throw std::runtime_error("Erro: o arquivo csv não pôde ser aberto.");
        }
    }
};

#endif