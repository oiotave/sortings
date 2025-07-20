#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include "../includes/sortings.hpp"

using namespace std;

void printArray(int* nums, int len) {
    for(int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << endl;
}

long long time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        perror("Ausencia de variavel\n");
        exit(1);
    }
    int ini, fin, num = atoi(argv[1]), algorithm = atoi(argv[2]);
    int *array = new int[num];

    srand(time(NULL));
    for(int i = 0; i < num; i++) array[i] = rand() % 100;
    
    cout << ">>> VETOR DESORDENADO: ";
    printArray(array, num);
    
    if(!algorithm) exit(0);
        
    ini = time();
    switch(algorithm) {
        case 1: Sortings::bubbleSort(array, num);
                cout << ">>> BUBBLE SORT: ";
                break;
        case 2: Sortings::insertionSort(array, num);
                cout << ">>> INSERTION SORT: ";
                break;
        case 3: Sortings::selectionSort(array, num);
                cout << ">>> SELECTION SORT: ";
                break;
        case 4: Sortings::quickSort(array, 0, num - 1);
                cout << ">>> QUICK SORT: ";
                break;
        case 5: Sortings::mergeSort(array, 0, num - 1);
                cout << ">>> VIA MERGE SORT: ";
                break;
        case 6: Sortings::countingSort(array, num);
                cout << ">>> VIA COUNTING SORT: ";
                break;
        
        default: break;
    }
    fin = time();
    double tempo = (fin - ini) / 1000000.0;

    printArray(array, num);
    cout << ">>> TEMPO DE EXECUCAO: " << tempo << " ms" << endl << endl;

    delete[] array;
    return 0;
}