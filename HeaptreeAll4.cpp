#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Adjust this as needed

class MaxHeap {
private:
    int heap[MAX_SIZE];
    int size;

    // Function to heapify an element at a given index
    void maxHeapify(int index) {
        int largest = index; // Initialize the largest as the root
        int leftChild = 2 * index + 1; // Index of the left child
        int rightChild = 2 * index + 2; // Index of the right child

        // Compare with left child
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Compare with right child
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If the largest is not the root, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }

    // Function to restore the max-heap property by shifting an element up
    void restoreMaxHeap(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    // Function to display the contents of the max-heap
    void display() {
        cout << "Max-Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Function to insert an element into the max-heap
    void insert(int element) {
        if (size >= MAX_SIZE) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        // Insert the new element at the end of the heap
        heap[size] = element;
        size++;

        // Restore the max-heap property by shifting the element up
        restoreMaxHeap(size - 1);
    }

    // Function to remove an element from a max-heap
    void removeElement(int element) {
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

        // Restore the max-heap property
        restoreMaxHeap(index);
        maxHeapify(index);
    }

    // Function to remove the maximum element from the max-heap
    int removeMax() {
        if (size <= 0) {
            cout << "Heap is empty. Cannot remove elements." << endl;
            return -1; // Return some sentinel value indicating failure
        }

        // Save the maximum element (the root)
        int removedValue = heap[0];

        // Replace the root with the last element in the heap
        heap[0] = heap[size - 1];
        size--;

        // Restore the max-heap property by calling maxHeapify
        maxHeapify(0);

        return removedValue;
    }
};

int main() {
    MaxHeap maxHeap;

    // Insert elements into the max-heap
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(9);
    maxHeap.insert(7);
    maxHeap.insert(6);
    maxHeap.insert(5);

    // Display the original max-heap
    maxHeap.display();

    // Remove an element from the max-heap (e.g., remove 8)
    maxHeap.removeElement(8);

    // Display the modified max-heap
    maxHeap.display();

    // Remove the maximum element from the max-heap
    int removedValue = maxHeap.removeMax();
    cout << "Removed: " << removedValue << endl;

    // Display the modified max-heap after removal
    maxHeap.display();

    return 0;
}