#include <iostream>

const int MAX_SIZE = 100; // Maximum capacity of the circular queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int size = MAX_SIZE;

bool isFull() {
    return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int element) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    } else {
        if (front == -1)
            front = rear = 0;
        else if (rear == size - 1)
            rear = 0;
        else
            rear++;

        queue[rear] = element;
    }
}

int dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return -1; // or some sentinel value
    } else {
        int element = queue[front];
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return element;
    }
}

int main() {
    enqueue(5);
    enqueue(2);
    enqueue(8);

    while (!isEmpty()) {
        std::cout << dequeue() << " ";  // Print the dequeued element
    }

    return 0;
}