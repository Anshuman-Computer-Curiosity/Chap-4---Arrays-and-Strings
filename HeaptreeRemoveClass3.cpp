#include <iostream>
const int MAX_HEAP_SIZE = 63; // 2^5+1-1
using namespace std;

class MaxHeap {
private:
    int heap[MAX_HEAP_SIZE];
    int size;

    // Function to perform the reheapify operation after insertion
    void reheapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    // Function to perform the reheapify operation after deletion
    void reheapifyDown(int index) {
        while (true) {
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
                index = maxIndex;
            } else {
                break; // Element is in the correct position
            }
        }
    }

public:
    MaxHeap() : size(0) {}

    // Function to insert a node into the max-heap
    void insert(int value) {
        if (size == MAX_HEAP_SIZE) {
            cout << "Heap is full. Cannot insert." << endl;
            return;
        }

        // Place the new element at the end of the heap
        heap[size] = value;
        size++;

        // Perform reheapify (heapify up) to maintain the max-heap property
        reheapifyUp(size - 1);
    }

    // Function to remove an element from the max-heap
    void removeElement(int element) {
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
        reheapifyDown(index);
    }

    // Function to display the elements of the heap
    void display() {
        cout << "Heap: ";
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

    maxHeap.removeElement(90); // Remove element with value 10
    maxHeap.display();

    maxHeap.removeElement(80); // Attempt to remove element not in heap
    maxHeap.display();

    return 0;
}