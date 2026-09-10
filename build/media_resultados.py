#!/usr/bin/env python3
"""
Agrupa um results.csv com várias repetições e calcula apenas a média
dos tempos para cada tamanho de grafo, mantendo o formato de colunas
compatível com o script de plotagem.

Uso:
    python3 average_results.py [entrada.csv] [saida.csv]
"""
import csv
import statistics
import sys
from collections import defaultdict

entrada = sys.argv[1] if len(sys.argv) > 1 else "results.csv"
saida = sys.argv[2] if len(sys.argv) > 2 else "results.csv"

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
        "dijkstra_time_ms",
        "bellman_ford_time_ms",
    ])
    for n in sorted(grupos):
        d = grupos[n]["dijkstra"]
        b = grupos[n]["bellman"]
        d_mean = statistics.mean(d)
        b_mean = statistics.mean(b)
        writer.writerow([n, d_mean, b_mean])

n_sizes = len(grupos)
print(f"Escrito '{saida}': {n_sizes} tamanhos de grafo processados com as médias.")
