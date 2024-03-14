#include <iostream>
int MAX_HEAP_SIZE = 63; // Adjust the size as needed
using namespace std;

// Function to display the elements of the heap
void displayHeap(int heap[], int size) {
    cout << "Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Function to perform the reheapify operation after deletion for max-heap
void reheapifyDown(int heap[], int size, int index) {
    int leftChildIndex, rightChildIndex, maxIndex;

    while (true) {
        leftChildIndex = 2 * index + 1;
        rightChildIndex = 2 * index + 2;
        maxIndex = index;

        if (leftChildIndex < size && heap[leftChildIndex] > heap[maxIndex]) {
            maxIndex = leftChildIndex;
        }

        if (rightChildIndex < size && heap[rightChildIndex] > heap[maxIndex]) {
            maxIndex = rightChildIndex;
        }

        if (maxIndex != index) {
            std::swap(heap[index], heap[maxIndex]);
            index = maxIndex;
        } else {
            break; // Element is in the correct position
        }
    }
}

// Function to perform the reheapify operation after insertion for max-heap (heapify up)
void reheapifyUp(int heap[], int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] <= heap[parentIndex]) {
            break; // Max-heap property is satisfied
        }
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

// Function to insert a node into the max-heap
void insertNode(int heap[], int& size, int value) {
    if (size == MAX_HEAP_SIZE) {
        cout << "Heap is full. Cannot insert." << endl;
        return;
    }

    // Place the new element at the end of the heap
    heap[size] = value;
    size++;

    // Perform reheapify (heapify up) to maintain the max-heap property
    reheapifyUp(heap, size - 1);
}

// Function to delete a node from the max-heap
bool deleteNode(int heap[], int& size, int value) {
    if (size == 0) {
        cout << "Heap is empty. Cannot delete." << endl;
        return false;
    }

    // Find the index of the element to delete
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Element not found in the heap. Cannot delete." << endl;
        return false;
    }

    // Replace the element to delete with the last element
    heap[index] = heap[size - 1];
    size--;

    // Perform reheapify (heapify down) to maintain the max-heap property
    reheapifyDown(heap, size, index);

    return true;
}

int main() {
    int heap[MAX_HEAP_SIZE];
    int size = 0;

    insertNode(heap, size, 80);
    insertNode(heap, size, 70);
    insertNode(heap, size, 60);
    insertNode(heap, size, 30);
    insertNode(heap, size, 40);
    insertNode(heap, size, 35);
    insertNode(heap, size, 50);
    insertNode(heap, size, 20);
    insertNode(heap, size, 10);
    insertNode(heap, size, 90);

    displayHeap(heap, size);

    deleteNode(heap, size, 90); // Delete element with value 10
    displayHeap(heap, size);

    deleteNode(heap, size, 80); // Attempt to delete element not in heap
    displayHeap(heap, size);

    return 0;
}