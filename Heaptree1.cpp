#include <iostream>
using namespace std;

const int MAX_SIZE = 63; // 2^(5+1) - 1,Adjust this as needed

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
void insertMaxHeap(int heap[], int& size, int value) {
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
    int maxHeap[MAX_SIZE];
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

    return 0;
}