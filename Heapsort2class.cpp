#include <iostream>
using namespace std;

class HeapSort {
private:
    void siftDown(int arr[], int index, int size) {
        int largest = index;
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;

        if (leftChildIndex < size && arr[leftChildIndex] > arr[largest]) {
            largest = leftChildIndex;
        }

        if (rightChildIndex < size && arr[rightChildIndex] > arr[largest]) {
            largest = rightChildIndex;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            siftDown(arr, largest, size);
        }
    }

    void heapifyFromBottom(int arr[], int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            siftDown(arr, i, size);
        }
    }

public:
    void heapSort(int arr[], int size) {
        heapifyFromBottom(arr, size);

        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            siftDown(arr, 0, i);
        }
    }

    void display(int arr[], int size) {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {40, 10, 60, 30, 80, 35, 50, 20, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    HeapSort sorter;
    
    cout << "Original Array: ";
    sorter.display(arr, size);

    sorter.heapSort(arr, size);

    cout << "Sorted Array: ";
    sorter.display(arr, size);

    return 0;
}