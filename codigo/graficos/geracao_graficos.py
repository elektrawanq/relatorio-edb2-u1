import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv("results.csv")

fig1, ax1 = plt.subplots()
tempo_max = df["dijkstra_time_ms"].max()
n_max_quadrado = (df["size_n"].max()) ** 2
fator_ajuste = tempo_max / n_max_quadrado
n_teorico = np.linspace(100, df["size_n"].max(), num=350)
n_quadrado_teorico = (n_teorico**2) * fator_ajuste

ax1.plot(df["size_n"], df["dijkstra_time_ms"], label="Dijkstra", marker="o")
ax1.plot(df["size_n"], df["bellman_ford_time_ms"], label="Bellman-Ford", marker="s")
ax1.plot(
    n_teorico,
    n_quadrado_teorico,
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
dijkstra_norm = df["dijkstra_time_ms"] / df["dijkstra_time_ms"].max()
bellman_ford_norm = df["bellman_ford_time_ms"] / df["bellman_ford_time_ms"].max()
n_teorico_norm = n_quadrado_teorico / n_quadrado_teorico.max()

ax2.plot(df["size_n"], dijkstra_norm, label="Dijkstra Empírico", marker="o")
ax2.plot(df["size_n"], bellman_ford_norm, label="Bellman-Ford Empírico", marker="s")
ax2.plot(
    n_teorico, n_teorico_norm, label="$O(|V|^2)$ Teórico", linestyle="--", color="gray"
)

ax2.set(xlabel="Tamanho da Entrada (n)", ylabel="Tempo Normalizado (0 a 1)")
ax2.legend()
ax2.grid()

fig2.savefig("grafico_normalizado.pdf", bbox_inches="tight")
plt.close(fig2)
