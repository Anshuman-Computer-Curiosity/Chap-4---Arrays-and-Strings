#include <iostream>

using namespace std;

// Function to perform the sift-down operation to maintain the max-heap property
void siftDown(int arr[], int index, int size) {
    int largest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    // Compare with left child
    if (leftChildIndex < size && arr[leftChildIndex] > arr[largest]) {
        largest = leftChildIndex;
    }

    // Compare with right child
    if (rightChildIndex < size && arr[rightChildIndex] > arr[largest]) {
        largest = rightChildIndex;
    }

    // If the largest element is not the current node, swap and sift down
    if (largest != index) {
        swap(arr[index], arr[largest]);
        siftDown(arr, largest, size);
    }
}

// Function to perform heapify from the bottom up
void heapifyFromBottom(int arr[], int size) {
    // Start with the last non-leaf node and sift down each element
    for (int i = size / 2 - 1; i >= 0; i--) {
        siftDown(arr, i, size);
    }
}

// Function to perform heap sort using the bottom-up approach
void heapSort(int arr[], int size) {
    // Build the max-heap from the bottom up
    heapifyFromBottom(arr, size);

    // Extract elements from the max-heap and place them in sorted order
    for (int i = size - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        swap(arr[0], arr[i]);

        // Perform sift-down to maintain the max-heap property
        siftDown(arr, 0, i);
    }
}

// Function to display the elements of an array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {40, 10, 60, 30, 80, 35, 50, 20, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    display(arr, size);

    // Perform heap sort using the bottom-up approach
    heapSort(arr, size);

    cout << "Sorted Array: ";
    display(arr, size);

    return 0;
}