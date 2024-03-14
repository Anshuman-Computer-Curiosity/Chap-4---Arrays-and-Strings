#include <iostream>
using namespace std;

class SelectionSort {
private:
    int* arr;
    int arraySize;
public:
    // Constructor to initialize the object with an array
    SelectionSort(int array[], int size) : arr(new int[size]), arraySize(size) {
        for (int i = 0; i < size; i++) {
            arr[i] = array[i]; // Copy values correctly to arr
        }
    }

    // Destructor to free the dynamically allocated memory
    ~SelectionSort() {
        delete[] arr;
    }

    // Function to find the index of the minimum element in a specified range
    int findMinIndex(int start, int end) {
        int minIndex = start;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Function to swap two elements in the array
    void swap(int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Function to display the elements of the array
    void display() {
        for (int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to perform selection sort
    void selectionSort() {
        for (int beg = 0; beg < arraySize - 1; beg++) {
            // Find the index of the minimum element in the unsorted portion
            int minIndex = findMinIndex(beg, arraySize - 1);

            // Swap the minimum element with the first element in the unsorted portion
            if (minIndex != beg) {
                swap(beg, minIndex);
            }
        }
    }
};

int main() {
    int arr[] = {19, 34, 22, 44, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort sorter(arr, size);

    cout << "Original array: ";
    sorter.display();

    sorter.selectionSort();

    cout << "Sorted array: ";
    sorter.display();

    return 0;
}