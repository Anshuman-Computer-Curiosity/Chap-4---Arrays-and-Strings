//Merge sort with classes
#include <iostream>
using namespace std;

class MergeSort {
    private:
    int* arrPtr; // Pointer to the array to be sorted
    int arrSize; // Size of the array

    // Private method to merge two sorted subarrays into a single sorted array
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1];
        int R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arrPtr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arrPtr[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arrPtr[k++] = L[i++];
            } else {
                arrPtr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arrPtr[k++] = L[i++];
        }

        while (j < n2) {
            arrPtr[k++] = R[j++];
        }
    }
public:
    // Constructor
    MergeSort(int arr[], int size) {
        arrPtr = arr;
        arrSize = size;
    }

    // Public method to perform iterative 2-way merge sort
    void sort() {
        int curr_size;
        for (curr_size = 1; curr_size <= arrSize; curr_size *= 2) {
            for (int left = 0; left < arrSize - 1; left += 2 * curr_size) {
                int mid = left + curr_size - 1;
                int right = (left + 2 * curr_size - 1 < arrSize - 1) ? left + 2 * curr_size - 1 : arrSize - 1;
                merge(left, mid, right);
            }
        }
    }

    // Public method to print the array
    void printArray() {
        cout << "Array: ";
        for (int i = 0; i < arrSize; i++) {
            cout << arrPtr[i] << " ";
        }
        std::cout << std::endl;
    }


};

int main() {
    // Example usage of MergeSort class

    // Initialize the array
    int arr[] = {41, 19, 65, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create an instance of the MergeSort class
    MergeSort mergeSortObj(arr, n);

    // Print the original array
    mergeSortObj.printArray();

    // Call the sort method to sort the array
    mergeSortObj.sort();

    // Print the sorted array
    mergeSortObj.printArray();

    return 0;
}