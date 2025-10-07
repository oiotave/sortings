#ifndef SORTINGS_HPP
#define SORTINGS_HPP

using namespace std;

class Sortings {
    private:
        static void merge(int*, int, int, int);
        static int partition(int*, int, int);
        static void heapify(int*, int, int);

    public:
        Sortings();
        static void bubbleSort(int*, int); 
        static void insertionSort(int*, int);
        static void selectionSort(int*, int);
        static void countingSort(int*, int);
        static void mergeSort(int*, int, int);
        static void quickSort(int*, int, int);
        static void bucketSort(int*, int);
        static void heapSort(int*, int);
};
#endif // SORTINGS_HPP