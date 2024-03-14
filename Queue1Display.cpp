#include <iostream>
using namespace std;

const int MAX_SIZE = 5;  // Maximum size of the queue

int queue[MAX_SIZE];  // Array to store the queue
int front = 0;        // Initialize front
int rear = -1;        // Initialize rear 

bool isEmpty() {
    return front > rear;
}

bool isFull() {
    return rear == MAX_SIZE - 1;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Contents of queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
    } else {
        rear++;
        queue[rear] = item;
        cout << "Enqueued " << item << endl;
        display();  // Display the queue after enqueuing
    }
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;  // Return a sentinel value or handle this case accordingly
    } else {
        int frontItem = queue[front];
        front++;
        if (front > rear) {
            // Reset front and rear when the last element is dequeued
            front = 0;
            rear = -1;
        }
        cout << "Dequeued item: " << frontItem << endl;
        display();  // Display the queue after dequeuing
        return frontItem;
    }
}

int main() {
    // Enqueue items into the queue
    enqueue(10);
    enqueue(25);
    enqueue(15);

    // Dequeue items from the queue
    cout << "Dequeued item: " << dequeue() << endl;
    
    // Enqueue more items
    enqueue(35);
    enqueue(20);

    
    return 0;
}