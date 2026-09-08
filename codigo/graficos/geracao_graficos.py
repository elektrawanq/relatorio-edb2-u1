import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("results.csv")

fig, ax = plt.subplots()

ax.plot(df["size_n"], df["dijkstra_time_ms"], label="Dijkstra", marker="o")
ax.plot(df["size_n"], df["bellman_ford_time_ms"], label="Bellman-Ford", marker="s")

ax.set(xlabel="Tamanho da Entrada (n)", ylabel="Tempo de Execução (ms)")

ax.legend()
ax.grid()

fig.savefig("grafico.pdf", bbox_inches="tight")
