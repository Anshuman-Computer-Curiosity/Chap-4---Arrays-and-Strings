#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int size;

    // Function to perform the sift-up operation to maintain the max-heap property
    void siftUp(int index) {
        if (index == 0) {
            return; // Already at the root
        }

        int parentIndex = (index - 1) / 2;

        // Compare with the parent node and swap if necessary
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            siftUp(parentIndex); // Recursively check parent node
        }
    }

    // Function to perform the sift-down operation to maintain the max-heap property
    void siftDown(int index, int size) {
        int largest = index;
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;

        if (leftChildIndex < size && heap[leftChildIndex] > heap[largest]) {
            largest = leftChildIndex;
        }

        if (rightChildIndex < size && heap[rightChildIndex] > heap[largest]) {
            largest = rightChildIndex;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            siftDown(largest, size);
        }
    }

public:
    MaxHeap(int arr[], int arrSize) {
        size = arrSize;
        heap = new int[size];
        for (int i = 0; i < size; i++) {
            heap[i] = arr[i];
            siftUp(i);
        }
    }

    // Function to perform heap sort
    void heapSort() {
        for (int i = size - 1; i > 0; i--) {
            // Swap the root (maximum element) with the last element
            swap(heap[0], heap[i]);

            // Reduce the size of the heap and perform sift-down to maintain the max-heap property
            siftDown(0, i);
        }
    }

    // Function to display the elements of the max-heap
    void display() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Destructor to release memory
    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    int arr[] = {40, 10, 60, 30, 80, 35, 50, 20, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    MaxHeap maxHeap(arr, size);

    cout << "Original Max-Heap: ";
    maxHeap.display();

    maxHeap.heapSort();

    cout << "Sorted Array: ";
    maxHeap.display();

    return 0;
}