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

    // Function to fix the max-heap property if necessary
    void reheapifyUp(int index) {
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

    // Function to perform the reheapify operation after deletion
    void reheapifyDown(int index) {
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
                swap(heap[index], heap[maxIndex]);
                index = maxIndex;
            } else {
                break; // Element is in the correct position
            }
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

    // Function to insert a new element into a max-heap
    void insert(int value) {
        if (size == 0) {
            // Allocate memory for the heap when inserting the first element
            heap = new int[1];
        } else if (size + 1 >= capacity) {
            // Resize the heap if it's full
            resizeHeap();
        }

        heap[size] = value;
        reheapifyUp(size);
        size++;
    }

    // Function to delete a node with a specific value from the max-heap
    void removeNode(int value) {
        if (size == 0) {
            cout << "Heap is empty. Cannot remove." << endl;
            return;
        }

        // Search for the element in the heap
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Element not found in the heap." << endl;
            return;
        }

        // Replace the node with the last element in the heap
        heap[index] = heap[size - 1];
        size--;

        // Re-heapify to maintain the max-heap property
        reheapifyDown(index);
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

   maxHeap.insert(80);
    maxHeap.insert(70);
    maxHeap.insert(60);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(35);
    maxHeap.insert(50);
    maxHeap.insert(20);
    maxHeap.insert(10);
    maxHeap.insert(90);

    maxHeap.display();

    maxHeap.removeNode(90); // Remove node with value 8
    maxHeap.display();

    maxHeap.removeNode(80); // Attempt to remove node not in heap
    maxHeap.display();

    return 0;
}