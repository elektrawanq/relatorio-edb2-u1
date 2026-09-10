#!/bin/bash
# Limpa o arquivo CSV anterior se existir
rm -f results.csv

echo "Iniciando a bateria de testes..."

# Executa para n variando de 100 até 5000, incrementando de 100 em 100
for n in $(seq 100 100 5000); do
    ./seu_executavel $n
done

echo "Todos os testes finalizados! Verifique results.csv."