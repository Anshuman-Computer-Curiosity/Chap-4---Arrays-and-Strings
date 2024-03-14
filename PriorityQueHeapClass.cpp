#include <iostream>
using namespace std;
const int MAX_SIZE = 10; // Maximum capacity of the heap

class PriorityQueue {
public:
    struct QueueElement {
        int value;
        int priority;
        int insertionOrder;
    };

private:
    QueueElement heap[MAX_SIZE];
    int heapSize = 0;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void swap(QueueElement& a, QueueElement& b) {
        QueueElement temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 &&
               (heap[i].priority < heap[parent(i)].priority ||
                (heap[i].priority == heap[parent(i)].priority && heap[i].insertionOrder < heap[parent(i)].insertionOrder))) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heapSize &&
            (heap[left].priority < heap[minIndex].priority ||
             (heap[left].priority == heap[minIndex].priority && heap[left].insertionOrder < heap[minIndex].insertionOrder))) {
            minIndex = left;
        }

        if (right < heapSize &&
            (heap[right].priority < heap[minIndex].priority ||
             (heap[right].priority == heap[minIndex].priority && heap[right].insertionOrder < heap[minIndex].insertionOrder))) {
            minIndex = right;
        }

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    void enqueue(int value, int priority) {
        if (heapSize == MAX_SIZE) {
            cout << "Priority queue is full. Cannot enqueue." << endl;
            return;
        }

        QueueElement element;
        element.value = value;
        element.priority = priority;
        element.insertionOrder = heapSize; // Derive insertionOrder
        heap[heapSize] = element;
        heapifyUp(heapSize);
        heapSize++;
    }

    QueueElement dequeue() {
        if (heapSize == 0) {
            cout << "Priority queue is empty." << endl;
            return { -1, -1, -1 }; // or some sentinel value
        }

        QueueElement top = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapifyDown(0);
        return top;
    }

    bool isEmpty() {
        return heapSize == 0;
    }
};

int main() {
    PriorityQueue priorityQueue;

    int elements[][2] = { {60, 2}, {70, 3}, {15, 1}, {35, 2}, {20, 1} };
    int numElements = 5;

    for (int i = 0; i < numElements; i++) {
        priorityQueue.enqueue(elements[i][0], elements[i][1]);
    }

    while (!priorityQueue.isEmpty()) {
        PriorityQueue::QueueElement element = priorityQueue.dequeue();
        cout << "Value: " << element.value << ", Priority: " << element.priority << endl;
    }

    return 0;
}