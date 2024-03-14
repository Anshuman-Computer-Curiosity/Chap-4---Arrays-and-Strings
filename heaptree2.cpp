#include <iostream>
using namespace std;

// Function to swap two elements in the heap
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to fix the max-heap property if necessary
void reheapifyUp(int heap[], int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

// Function to insert a new element into a max-heap
void insertMaxHeap(int*& heap, int& size, int value) {
    if (size == 0) {
        heap = new int[1]; // Allocate memory for the heap when inserting the first element
    } else {
        // Check if the heap array needs to be resized
        int newSize = size * 2;
        if (size + 1 > newSize) {
            newSize = size + 1;
        }

        // Allocate a new array with the increased size
        int* newHeap = new int[newSize];

        // Copy elements from the old heap to the new heap
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }

        // Release memory occupied by the old heap
        delete[] heap;

        // Update the heap pointer to point to the new heap
        heap = newHeap;
    }

    heap[size] = value;
    reheapifyUp(heap, size);
    size++;
}

// Function to display the contents of the max-heap
void display(int heap[], int size) {
    cout << "Max-Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int* maxHeap = nullptr;
    int size = 0;

    // Insert elements into the max-heap
    insertMaxHeap(maxHeap, size, 80);
    insertMaxHeap(maxHeap, size, 70);
    insertMaxHeap(maxHeap, size, 60);
    insertMaxHeap(maxHeap, size, 30);
    insertMaxHeap(maxHeap, size, 40);
    insertMaxHeap(maxHeap, size, 35);
    insertMaxHeap(maxHeap, size, 50);
    insertMaxHeap(maxHeap, size, 20);
    insertMaxHeap(maxHeap, size, 10);
    
    display(maxHeap, size); // Display the max-heap

    insertMaxHeap(maxHeap, size, 90);

    
    display(maxHeap, size); // Display the max-heap

    // Clean up allocated memory
    delete[] maxHeap;

    return 0;
}