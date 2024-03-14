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
    void siftUp(int index) {
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
        siftUp(size);
        size++;
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
    MaxHeap maxHeap;//object of Maxheap class

    // Insert elements into the max-heap
    maxHeap.insert(80);
    maxHeap.insert(70);
    maxHeap.insert(60);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(35);
    maxHeap.insert(50);
    maxHeap.insert(20);
    maxHeap.insert(10);

    maxHeap.display();// Display the max-heap
 
    maxHeap.insert(90);
    
    maxHeap.display();// Display the max-heap

    return 0;
}