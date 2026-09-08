#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "../include/RunningOpt.hpp"
#include "../include/sequence.hpp"

struct CsvParser {
    static void save_csv(RunningOptions& run_opt, Sequence& seq, value_type L, double total_time, double max_worker_time, double min_worker_time, double agregation_time) {

        std::ofstream csv(run_opt.FILE_EXIT, std::ios::app); // append mode (2.1.1)
        if (csv.is_open()) {
            csv << std::scientific << std::setprecision(2);
            csv << run_opt.MODE << ","
            << run_opt.PARTITION << ","
            << run_opt.W << ","
            << L << ","
            << total_time << ","
            << max_worker_time << ","
            << min_worker_time << ","
            << agregation_time << ","
            << seq.get_qtd() << ","
            << seq.get_high_n() << ","
            << seq.get_high_s() << "\n";

            csv.close();
        } else {
            throw std::runtime_error("Erro: o arquivo csv não pôde ser aberto.");
        }
    }
};

#endif