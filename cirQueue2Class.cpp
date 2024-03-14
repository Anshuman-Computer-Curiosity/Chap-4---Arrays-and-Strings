#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int maxSize;

public:
    CircularQueue(int size) {
        maxSize = size;
        queue = new int[maxSize];
        front = 0;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == maxSize - 1) || (rear != -1 && front == rear + 1);
    }

    bool isEmpty() {
        return (front == 0 && rear == -1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue contents: ";
            int i = front;
            do {
                cout << queue[i] << " ";
                i = (i + 1) % maxSize;
            } while (i != (rear + 1) % maxSize);
            cout << endl;
        }
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else if (front == 0 && rear == -1) {
            rear = 0;
            queue[rear] = data;
        } else {
            rear = (rear + 1) % maxSize;
            queue[rear] = data;
        }
        display();
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int data = queue[front];
        if (front == rear) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
        return data;
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    CircularQueue cirQueue(5);

    cirQueue.enqueue(10);
    cirQueue.enqueue(25);
    cirQueue.enqueue(15);
    cirQueue.enqueue(35);
    cirQueue.enqueue(20);
    cirQueue.enqueue(80);

    cout << "Dequeued 4 elements:" << endl;
    for (int i = 0; i < 4; i++) {
        cirQueue.dequeue();
    }

    cirQueue.display(); // Display the queue after dequeuing

    cirQueue.enqueue(60);
    cirQueue.enqueue(70);

    cout << "Dequeued: " << cirQueue.dequeue() << endl;
    cirQueue.display(); // Display the queue after dequeuing

    return 0;
}