#!/usr/bin/env bash
# Roda o benchmark (Dijkstra vs Bellman-Ford) varias vezes por tamanho de
# grafo, para depois tirar a media com o average_results.py.
#
# Uso:
#   ./run_benchmark.sh <executavel> <repeticoes> <n_min> <n_max> <passo>
#
# Exemplo (32 repeticoes, n de 10 a 5000, passo 10 - igual ao seu sweep):
#   ./run_benchmark.sh ./main 32 10 5000 10
#
# Cada repeticao roda o programa do zero (novo grafo aleatorio, nova
# medicao de tempo), exatamente como ele ja funciona hoje. O script so
# automatiza a repeticao e apaga o results.csv antigo antes de comecar,
# para nao misturar com dados de outra unidade/versao do codigo.

set -euo pipefail

EXE="${1:?Uso: ./run_benchmark.sh <executavel> <repeticoes> <n_min> <n_max> <passo>}"
REPS="${2:?informe o numero de repeticoes, ex: 32}"
N_MIN="${3:?informe o n minimo}"
N_MAX="${4:?informe o n maximo}"
STEP="${5:?informe o passo}"

if [ ! -x "$EXE" ]; then
    echo "Erro: '$EXE' nao existe ou nao e executavel." >&2
    exit 1
fi

rm -f results.csv

total_n=$(( (N_MAX - N_MIN) / STEP + 1 ))
idx=0
start_ts=$(date +%s)

for (( n=N_MIN; n<=N_MAX; n+=STEP )); do
    idx=$((idx+1))
    printf "\r[%d/%d] n=%d (%d repeticoes)          " "$idx" "$total_n" "$n" "$REPS"
    for (( rep=1; rep<=REPS; rep++ )); do
        "$EXE" "$n" > /dev/null
    done
done

end_ts=$(date +%s)
echo
echo "Concluido em $(( end_ts - start_ts ))s."
echo "results.csv tem $(( total_n * REPS )) linhas (antes de tirar a media)."
echo "Agora rode: python3 average_results.py"