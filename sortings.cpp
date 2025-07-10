#include "sortings.hpp"
#include <cstdlib>

using namespace std;

Sortings::Sortings() {
}

void Sortings::swap(int* nums, int addr1, int addr2) {
    int aux = nums[addr1];
    nums[addr1] = nums[addr2];
    nums[addr2] = aux;
}

int* Sortings::bubbleSort(int* nums, int tam) {
    if(tam <= 1) return nums;

    for(int i = 0; i <= tam - 2; i++)
        if(nums[i] > nums[i + 1]) swap(nums, i, i + 1);

    bubbleSort(nums, tam - 1);

    return nums;
}

int* Sortings::insertionSort(int* nums, int tam) {
    int aux;
    
    for(int i = 1; i < tam; i++) {
        aux = nums[i];
        for(int j = i - 1; j >= 0; j--)
            if(nums[j] > aux) swap(nums, j, j + 1);
    }
    return nums;
}

int* Sortings::selectionSort(int* nums, int tam, int ini) {
    if(tam == ini + 1) return nums;

    int aux = nums[ini], temp = ini;

    for(int i = ini + 1; i < tam; i++)
        if(nums[i] < aux && nums[i] < nums[temp]) temp = i;

    swap(nums, ini, temp);
    selectionSort(nums, tam, ini + 1);

    return nums;
}

int* Sortings::quickSort(int* nums, int tam, int idx_pivo) {
    if(tam == 1) return nums;
    
    int count = idx_pivo + 1;

    for(int i = 1; i < tam; i++)
        if(nums[i] < nums[idx_pivo]) swap(nums, i, count++);

    swap(nums, idx_pivo, --count);

    quickSort(nums, count);
    quickSort(nums + count + 1, tam - count - 1, count + 1);
    
    return nums;
}

int* Sortings::mergeSort(int* nums, int tam) {
    if(tam == 1) return nums;

    int esq = tam / 2, dir = tam - esq;
    int idx = 0, count1 = 0, count2 = 0, aux1[esq], aux2[dir];

    for(int i = 0; i < tam; i++) {
        if(i < esq) aux1[count1++] = nums[i];
        else aux2[count2++] = nums[i];
    }
    int *result1, *result2, *nums2 = new int[tam];

    result1 = mergeSort(aux1, esq);
    result2 = mergeSort(aux2, dir);

    count1 = 0;
    count2 = 0;

    while(count1 < esq && count2 < dir) {
        if(result1[count1] < result2[count2])
            nums2[idx++] = result1[count1++];
        
        else nums2[idx++] = result2[count2++];
    }
    return nums2;
}

int* Sortings::countingSort(int* nums, int tam) {
    int maior = nums[0];
    
    // Encontra o maior elemento do array
    for(int i = 1; i < tam; i++)
        if(nums[i] > maior) maior = nums[i];

    int *aux = (int*) calloc(maior + 1, sizeof(int));
    
    // Monta o array auxiliar com a frequencia de cada chave
    for(int j = 0; j < tam; j++) aux[nums[j]]++;

    // Altera o array auxiliar para armazenar a frequencia acumulada
    for(int k = 1; k <= maior; k++) aux[k] += aux[k - 1];

    int *temp = (int*) calloc(tam, sizeof(int));
    for(int l = 0; l < tam; l++) {
        temp[aux[nums[l]] - 1] = nums[l];
        aux[nums[l]]--;
    }
    for(int m = 0; m < tam; m++) nums[m] = temp[m];

    free(aux);
    free(temp);

    return nums;
}