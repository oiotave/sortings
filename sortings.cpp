#include "sortings.hpp"
#include <algorithm>
#include <utility>
#include <climits>
#include <cstdlib>
#include <cmath>

using namespace std;

Sortings::Sortings() {
}

void Sortings::bubbleSort(int* nums, int tam) {
    if(tam <= 1) return;

    // Faz a permuta de valores adjacentes quando desordenados
    for(int i = 0; i <= tam - 2; i++) {
        if(nums[i] > nums[i + 1]) swap(nums[i], nums[i + 1]);
    }
    bubbleSort(nums, tam - 1);
}

void Sortings::insertionSort(int* nums, int tam) {
    int aux;
    for(int i = 1; i < tam; i++) {
        aux = nums[i];
        for(int j = i - 1; j >= 0; j--) {
            if(nums[j] > aux) swap(nums[j], nums[j + 1]);
        }
    }
}

void Sortings::selectionSort(int* nums, int tam) {
    for(int i = 0; i <= tam - 2; i++) {
        int idx_min = i;
        
        for(int j = i + 1; j <= tam - 1; j++) {
            if(nums[j] < nums[idx_min]) idx_min = j;
        }
        if(nums[i] != nums[idx_min]) swap(nums[i], nums[idx_min]);
    }
}

// Função auxiliar para fazer a divisão e ordenação pelo mergeSort
void Sortings::merge(int *nums, int esq, int meio, int dir) {
    int *nums_esq, *nums_dir;
    int i = 0, j = 0;

    // Calcula o tamanho de cada divisão do vetor
    int tam_esq = meio - esq + 1, tam_dir = dir - meio;

    nums_esq = (int*) malloc(sizeof(int) * (tam_esq + 1));
    nums_dir = (int*) malloc(sizeof(int) * (tam_dir + 1));

    // Copia os valores do vetores para cada parte
    for(int i = 0; i < tam_esq; i++) nums_esq[i] = nums[esq + i];
    for(int i = 0; i < tam_dir; i++) nums_dir[i] = nums[meio + 1 + i];
    
    nums_esq[tam_esq] = INT_MAX;
    nums_dir[tam_dir] = INT_MAX;
    
    // Ordena fazendo a mesclagem de cada parte
    for(int k = esq; k <= dir; k++) {
        if(nums_esq[i] <= nums_dir[j]) nums[k] = nums_esq[i++];

        else nums[k] = nums_dir[j++];
    }
    free(nums_esq);
    free(nums_dir);
}

void Sortings::mergeSort(int* nums, int ini, int fin) {
    if(ini < fin) {
        int meio = floor((ini + fin) / 2);
        mergeSort(nums, ini, meio);
        mergeSort(nums, meio + 1, fin);
        merge(nums, ini, meio, fin);
    }
}

// Função auxiliar para obter a partição seguindo o método de Hoare
int Sortings::partition(int* nums, int ini, int fin) {
    int pivo = nums[ini], i = ini - 1, j = fin + 1;

    while(true) {
        do i++; 
        while(nums[i] < pivo);

        do j--;
        while(nums[j] > pivo);

        if(i >= j) return j;
        swap(nums[i], nums[j]);
    }
}

void Sortings::quickSort(int *nums, int ini, int fin) {
    if(ini < fin) {
        int aux = partition(nums, ini, fin);
        quickSort(nums, ini, aux);
        quickSort(nums, aux + 1, fin);
    }
}

void Sortings::countingSort(int* nums, int tam) {
    int maior = nums[0];
    
    // Encontra o maior elemento do array
    for(int i = 1; i < tam; i++)
        if(nums[i] > maior) maior = nums[i];

    int *aux = (int*) calloc(maior + 1, sizeof(int));
    
    // Monta o array auxiliar com a frequência de cada chave
    for(int j = 0; j < tam; j++) aux[nums[j]]++;

    // Altera o array auxiliar para armazenar a frequência acumulada
    for(int k = 1; k <= maior; k++) aux[k] += aux[k - 1];

    int *temp = (int*) calloc(tam, sizeof(int));
    for(int l = tam - 1; l >= 0; l--) {
        temp[aux[nums[l]] - 1] = nums[l];
        aux[nums[l]]--;
    }
    for(int m = 0; m < tam; m++) nums[m] = temp[m];

    free(aux);
    free(temp);
}

// Deve ser usado apenas em vetores com valores entre 0 e 100
void Sortings::bucketSort(int *nums, int tam) {
    int **buckets = (int**) malloc(sizeof(int*) * 10);

    if(!buckets) exit(1);
    
    // Aloca espaço para cada bucket
    for(int i = 0; i < 10; i++) {
        buckets[i] = (int*) malloc(sizeof(int) * tam);
        if(!buckets[i]) {
            for(int j = i - 1; j >= 0; j--) free(buckets[j]);
            exit(1);
        }
    }
    int bucketIndex[10] = {0}; // Armazena quantos elementos há em cada bucket

    for(int i = 0; i < tam; i++) {
        int index = nums[i] / 10;
        buckets[index][bucketIndex[index]++] = nums[i];
    }
    // Ordena cada bucket usando o insertionSort
    for(int j = 0; j < 10; j++) {
        Sortings::insertionSort(buckets[j], bucketIndex[j]);
    }
    int idx = 0;
    for(int k = 0; k < 10; k++)
        for(int l = 0; l < bucketIndex[k]; l++)
            nums[idx++] = buckets[k][l];
    
    for(int t = 0; t < 10; t++) free(buckets[t]);
    free(buckets);
}

void Sortings::heapify(int *nums, int index, int tam) {
    int max = index, lft = 2 * index + 1, rgt = 2 * index + 2;

    if(lft < tam and nums[lft] > nums[max]) max = lft;
    if(rgt < tam and nums[rgt] > nums[max]) max = rgt;

    if(max != index) {
        swap(nums[max], nums[index]);
        heapify(nums, max, tam);
    }
}

void Sortings::heapSort(int *nums, int tam) {
    // Constrói um heap de máximo em cima do vetor
    for(int i = tam / 2 - 1; i >= 0; i--) {
        heapify(nums, i, tam);
    }
    // Ordena recursivamente usando o heap
    for(int i = tam - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, 0, --tam);
    }
}