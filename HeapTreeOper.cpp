#include <iostream>

const int MAX_HEAP_SIZE = 100; // Adjust the size as needed

class MinHeap {
private:
    int heap[MAX_HEAP_SIZE];
    int size;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parentIndex]) {
            int temp = heap[index];
            heap[index] = heap[parentIndex];
            heap[parentIndex] = temp;
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestIndex = index;

        if (leftChildIndex < size && heap[leftChildIndex] < heap[smallestIndex]) {
            smallestIndex = leftChildIndex;
        }

        if (rightChildIndex < size && heap[rightChildIndex] < heap[smallestIndex]) {
            smallestIndex = rightChildIndex;
        }

        if (index != smallestIndex) {
            int temp = heap[index];
            heap[index] = heap[smallestIndex];
            heap[smallestIndex] = temp;
            heapifyDown(smallestIndex);
        }
    }

public:
    MinHeap() : size(0) {}

    bool isFull() {
        return size == MAX_HEAP_SIZE;
    }

    void insert(int item) {
        if (isFull()) {
            std::cout << "Heap is full. Cannot insert." << std::endl;
            return;
        }
        heap[size] = item;
        size++;
        heapifyUp(size - 1);
    }

    bool isEmpty() {
        return size == 0;
    }

    int extractMin() {
        if (isEmpty()) {
            std::cout << "Heap is empty. Cannot extract minimum." << std::endl;
            return -1; // Return a sentinel value to indicate failure
        }

        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return min;
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(4);
    minHeap.insert(8);
    minHeap.insert(2);
    minHeap.insert(10);
    minHeap.insert(6);

    while (!minHeap.isEmpty()) {
        std::cout << minHeap.extractMin() << " ";
    }

    return 0;
}