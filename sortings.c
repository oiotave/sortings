#include <stdio.h>
#include <stdlib.h>
#include "sortings.h"

void swap(int *nums, int add1, int add2) {
    int aux = nums[add1];
    nums[add1] = nums[add2];
    nums[add2] = aux;
}

void bubble_sort(int *nums, int tam) {
    if(tam <= 1) return;

    for(int i = 0; i <= tam - 2; i++)
        if(nums[i] > nums[i + 1]) swap(nums, i, i + 1);

    bubble_sort(nums, tam - 1);
}

void selection_sort(int *nums, int tam, int ini) {
    if(tam == ini + 1) return;

    int aux = nums[ini], temp = ini;

    for(int i = ini + 1; i < tam; i++)
        if(nums[i] < aux && nums[i] < nums[temp]) temp = i;

    swap(nums, ini, temp);
    selection_sort(nums, tam, ini + 1);
}

void insertion_sort(int *nums, int tam) {
    int aux;
    
    for(int i = 1; i < tam; i++) {
        aux = nums[i];
        for(int j = i - 1; j >= 0; j--)
            if(nums[j] > aux) swap(nums, j, j + 1);
    }
}

void counting_sort(int *nums, int tam) {
    // Encontra o maior elemento do array
    int maior = nums[0];
    for(int i = 1; i < tam; i++)
        if(nums[i] > maior) maior = nums[i];

    int *aux = calloc(maior + 1, sizeof(int));
    
    // Monta o array auxiliar com a frequencia de cada chave
    for(int j = 0; j < tam; j++) aux[nums[j]]++;

    // Altera o array auxiliar para armazenar a frequencia acumulada
    for(int k = 1; k <= maior; k++) aux[k] += aux[k - 1];

    int *temp = calloc(tam, sizeof(int));
    for(int l = 0; l < tam; l++) {
        temp[aux[nums[l]] - 1] = nums[l];
        aux[nums[l]]--;
    }
    for(int m = 0; m < tam; m++) nums[m] = temp[m];

    free(aux);
    free(temp);
}