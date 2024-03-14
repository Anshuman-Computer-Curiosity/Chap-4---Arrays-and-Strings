#include <iostream>
using namespace std;

// Function to swap two elements in the heap
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive function to fix the max-heap property after inserting an element
void reheapifyUp(int heap[], int index) {
    if (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            reheapifyUp(heap, parentIndex); // Recursively fix the parent
        }
    }
}

// Recursive function to insert a new element into a max-heap
void insertMaxHeap(int*& heap, int& size, int value) {
    if (size == 0) {
        heap = new int[1]; // Allocate memory for the heap when inserting the first element
    } else {
        // Resize the heap if needed
        int newSize = size * 2;
        if (size + 1 > newSize) {
            newSize = size + 1;
        }
        int* newHeap = new int[newSize];
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
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

    // Insert elements into the max-heap recursively
    insertMaxHeap(maxHeap, size, 80);
    insertMaxHeap(maxHeap, size, 70);
    insertMaxHeap(maxHeap, size, 60);
    insertMaxHeap(maxHeap, size, 30);
    insertMaxHeap(maxHeap, size, 40);
    insertMaxHeap(maxHeap, size, 35);
    insertMaxHeap(maxHeap, size, 50);
    insertMaxHeap(maxHeap, size, 20);
    insertMaxHeap(maxHeap, size, 10);

    display(maxHeap, size);// Display the max-heap
   
    insertMaxHeap(maxHeap, size, 90);

    // Display the max-heap
    display(maxHeap, size);

    // Clean up allocated memory
    delete[] maxHeap;

    return 0;
}