#!/bin/bash

mkdir -p bin
g++ teste.cpp ../includes/sortings.cpp -o ./bin/exec

echo -e "\n=== TESTE DE EXECUCAO E PERFORMANCE DE ALGORTIMOS DE ORDENACAO ==="
echo -n -e "\nInforme o tamanho de vetor: "
read number
echo -n -e "\n"

if [ "$number" -ne 0 ]; then
    for i in {1..8}; do
        ./bin/exec "$number" "$i"
    done
fi