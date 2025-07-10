#ifndef SORTINGS_HPP
#define SORTINGS_HPP

using namespace std;

class Sortings {
    private:
        static void swap(int*, int, int);
        
    public:
        Sortings();
        static int* bubbleSort(int*, int); 
        static int* insertionSort(int*, int);
        static int* selectionSort(int*, int, int = 0);
        static int* countingSort(int*, int);
        static int* quickSort(int*, int, int = 0);
        static int* mergeSort(int*, int);
};
#endif // SORTINGS_HPP