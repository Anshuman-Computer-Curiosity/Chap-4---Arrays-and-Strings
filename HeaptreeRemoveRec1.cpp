#include <iostream>

using namespace std;

const int MAX_SIZE = 63; // Adjust this as needed

// Function to swap two elements in the heap
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive function to reheapify an element at a given index
void recursiveReheapifyDown(int heap[], int size, int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int maxIndex = index;

    if (leftChildIndex < size && heap[leftChildIndex] > heap[maxIndex]) {
        maxIndex = leftChildIndex;
    }

    if (rightChildIndex < size && heap[rightChildIndex] > heap[maxIndex]) {
        maxIndex = rightChildIndex;
    }

    if (maxIndex != index) {
        swap(heap[index], heap[maxIndex]);
        recursiveReheapifyDown(heap, size, maxIndex);
    }
}

// Function to display the contents of the max-heap
void display(int heap[], int size) {
    cout << "Max-Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Function to remove an element from a max-heap
void removeElement(int heap[], int& size, int element) {
    // Search for the element in the heap
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (heap[i] == element) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Element not found in the heap." << endl;
        return;
    }

    // Replace the element with the last element in the heap
    heap[index] = heap[size - 1];
    size--;

    // Re-heapify to maintain the max-heap property
    recursiveReheapifyDown(heap, size, index);
}

int main() {
    int maxHeap[] = {80, 70, 60, 30, 40, 35, 50, 20, 10};
    int size = sizeof(maxHeap) / sizeof(maxHeap[0]);

    // Display the original max-heap
    display(maxHeap, size);

    // Remove an element from the max-heap
    removeElement(maxHeap, size, 70);

    // Display the modified max-heap
    display(maxHeap, size);

    return 0;
}