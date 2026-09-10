#!/usr/bin/env python3
"""
Agrupa um results.csv (com varias linhas por size_n, uma por repeticao)
e calcula media e desvio padrao de dijkstra_time_ms e bellman_ford_time_ms
para cada tamanho de grafo.

Uso:
    python3 average_results.py [entrada.csv] [saida.csv]

Padrao: entrada = results.csv, saida = results_avg.csv
"""
import csv
import statistics
import sys
from collections import defaultdict

entrada = sys.argv[1] if len(sys.argv) > 1 else "results.csv"
saida = sys.argv[2] if len(sys.argv) > 2 else "results_avg.csv"

grupos = defaultdict(lambda: {"dijkstra": [], "bellman": []})

with open(entrada, newline="") as f:
    reader = csv.DictReader(f)
    for row in reader:
        n = int(row["size_n"])
        grupos[n]["dijkstra"].append(float(row["dijkstra_time_ms"]))
        grupos[n]["bellman"].append(float(row["bellman_ford_time_ms"]))

with open(saida, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow([
        "size_n",
        "dijkstra_time_ms_mean", "dijkstra_time_ms_std",
        "bellman_ford_time_ms_mean", "bellman_ford_time_ms_std",
        "reps",
    ])
    for n in sorted(grupos):
        d = grupos[n]["dijkstra"]
        b = grupos[n]["bellman"]
        d_mean = statistics.mean(d)
        d_std = statistics.pstdev(d) if len(d) > 1 else 0.0
        b_mean = statistics.mean(b)
        b_std = statistics.pstdev(b) if len(b) > 1 else 0.0
        writer.writerow([n, d_mean, d_std, b_mean, b_std, len(d)])

n_sizes = len(grupos)
reps_exemplo = len(next(iter(grupos.values()))["dijkstra"])
print(f"Escrito '{saida}': {n_sizes} tamanhos de grafo, {reps_exemplo} repeticoes cada.")