import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv("results.csv")

df["dijkstra_time_ms"] = df["dijkstra_time_ms"] * 1000
df["bellman_ford_time_ms"] = df["bellman_ford_time_ms"] * 1000

fig1, ax1 = plt.subplots()
max_execution_time = df["dijkstra_time_ms"].max()
max_n_squared = (df["size_n"].max()) ** 2
adjust_factor = max_execution_time / max_n_squared
theoric_n = np.linspace(100, df["size_n"].max(), num=350)
theoric_n_squared = (theoric_n**2) * adjust_factor

ax1.plot(df["size_n"], df["dijkstra_time_ms"], label="Dijkstra Empírico", marker="o")
ax1.plot(
    df["size_n"], df["bellman_ford_time_ms"], label="Bellman-Ford Empírico", marker="s"
)
ax1.plot(
    theoric_n,
    theoric_n_squared,
    label="$O(|V|^2)$ teórico",
    linestyle="--",
    color="gray",
    alpha=0.5,
)

ax1.set(xlabel="Tamanho da Entrada (n)", ylabel="Tempo de Execução (ms)")
ax1.legend()
ax1.grid()

fig1.savefig("grafico_tempos.pdf", bbox_inches="tight")
plt.close(fig1)

fig2, ax2 = plt.subplots()
norm_dijkstra = df["dijkstra_time_ms"] / df["dijkstra_time_ms"].max()
norm_bellman_ford = df["bellman_ford_time_ms"] / df["bellman_ford_time_ms"].max()
norm_theoric_n = theoric_n_squared / theoric_n_squared.max()

ax2.plot(df["size_n"], norm_dijkstra, label="Dijkstra Normalizado", marker="o")
ax2.plot(df["size_n"], norm_bellman_ford, label="Bellman-Ford Normalizado", marker="s")
ax2.plot(
    theoric_n, norm_theoric_n, label="$O(|V|^2)$ Teórico", linestyle="--", color="gray"
)

ax2.set(xlabel="Tamanho da Entrada (n)", ylabel="Tempo Normalizado (0 a 1)")
ax2.legend()
ax2.grid()

fig2.savefig("grafico_normalizado.pdf", bbox_inches="tight")
plt.close(fig2)
