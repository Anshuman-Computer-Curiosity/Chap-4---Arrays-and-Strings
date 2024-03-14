#include <iostream>
using namespace std;

// Function to shift elements in the array
void shift(int arr[], int start, int end, int gap) {
    int temp = arr[end];
    int j = end;

    std::cout << "Shifting elements in sublist starting at index " << start << ": ";
    while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        std::cout << arr[j] << " ";
        j -= gap;
    }

    arr[j] = temp;
    std::cout << "=> " << temp << std::endl;
}

// Function to perform insertion sort with a given gap
void insertionSort(int arr[], int n, int gap) {
    for (int i = gap; i < n; ++i) {
        shift(arr, i, i, gap);
    }
}


// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        insertionSort(arr, n, gap);
    }
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {36, 56, 22, 7, 15, 12, 43, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}