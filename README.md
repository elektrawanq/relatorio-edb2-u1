# Relatório do artigo de análise de algoritmos Bellman-Ford e Dijkstra

## Resumo

Este repositório tem como objetivo analisar o artigo _A Study on Contrast and Comparison between Bellman-Ford algorithm and Dijkstras Algorithms_, no que tange os algoritmos _Bellman-Ford_ e _Dijkstra_. Foi feito uma análise empírica do código, analisando a eficiência e fazendo uma comparação entre eles.

## Como compilar

1) Entre na pasta `build` do projeto e compile utilizando o comando `make`.
2) Ao terminar de compilar, use o arquivo `run_benchmark.sh` para realizar a bateria de testes.

```sh
# Crie o executável:
chmod +x run_benchmark.sh
# Usage:
./run_benchmark.sh <executavel> <repeticoes> <n_min> <n_max> <passo>
# Exemplo: 32 repeticoes, n de 10 a 5000, passo 10
./run_benchmark.sh ./main 32 10 5000 10
```

1) Na finalização do programa, um arquivo `results.csv` irá aparecer dentro de `build`, contendo os resultados em _ms_ dos algoritmos

- **EXTRA:** Também há um script em Python que calcula as médias dos tempos para cada tamanho do grafo.

```sh
python3 average_results.py [entrada.csv] [saida.csv]
```
