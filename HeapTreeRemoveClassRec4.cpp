#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

    // Function to swap two elements in the heap
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Recursive function to fix the max-heap property if necessary after insertion
    void recursiveReheapifyUp(int index) {
        if (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                recursiveReheapifyUp(parentIndex);
            }
        }
    }

    // Recursive function to perform the reheapify operation after deletion
    void recursiveReheapifyDown(int index) {
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
            recursiveReheapifyDown(maxIndex);
        }
    }

    // Function to resize the heap array when needed
    void resizeHeap() {
        int newSize = capacity * 2;
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

        // Update the heap pointer and capacity
        heap = newHeap;
        capacity = newSize;
    }

public:
    MaxHeap() {
        capacity = 1; // Initial capacity
        heap = new int[capacity];
        size = 0;
    }

    // Destructor to release dynamically allocated memory
    ~MaxHeap() {
        delete[] heap;
    }

    // Recursive function to insert a new element into a max-heap
    void recursiveInsert(int value, int index) {
        if (size == 0) {
            // Allocate memory for the heap when inserting the first element
            heap = new int[1];
        } else if (size + 1 >= capacity) {
            // Resize the heap if it's full
            resizeHeap();
        }

        heap[index] = value;
        recursiveReheapifyUp(index);
        size++;
    }

    // Recursive function to delete a node with a specific value from the max-heap
    void recursiveRemoveNode(int value, int index) {
        if (size == 0) {
            cout << "Heap is empty. Cannot remove." << endl;
            return;
        }

        if (index >= size) {
            cout << "Element not found in the heap." << endl;
            return;
        }

        // Replace the node with the last element in the heap
        heap[index] = heap[size - 1];
        size--;

        // Re-heapify to maintain the max-heap property
        recursiveReheapifyDown(index);
    }

    // Function to display the contents of the max-heap
    void display() {
        cout << "Max-Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.recursiveInsert(80, 0);
    maxHeap.recursiveInsert(70, 1);
    maxHeap.recursiveInsert(60, 2);
    maxHeap.recursiveInsert(30, 3);
    maxHeap.recursiveInsert(40, 4);
    maxHeap.recursiveInsert(35, 5);
    maxHeap.recursiveInsert(50, 6);
    maxHeap.recursiveInsert(20, 7);
    maxHeap.recursiveInsert(10, 8);
    maxHeap.recursiveInsert(90, 9);

    maxHeap.display();
    
    maxHeap.recursiveRemoveNode(90, 0);
    maxHeap.display();
    
    maxHeap.recursiveRemoveNode(80, 0);
    maxHeap.display();
    
    return 0;
}