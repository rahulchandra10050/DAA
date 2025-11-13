Aim: Sort a given set of elements using the Quick sort method and determine the time required to sort the elements. Repeat the experiment for different values of n, 
the number of elements in the list to be sorted. The elements can be read from a file or can be generated using the random number generator.

ans-> 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int SurajPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void SurajQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = SurajPartition(arr, low, high);
        SurajQuickSort(arr, low, pi - 1);
        SurajQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000;

    clock_t start = clock();
    SurajQuickSort(arr, 0, n - 1);
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted elements:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nTime taken: " << timeTaken << " seconds\n";

    delete[] arr;
    return 0;
}
