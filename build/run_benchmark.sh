#!/usr/bin/env bash

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