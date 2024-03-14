#include <iostream>
using namespace std;

const int MAX_SIZE = 5;  // Maximum size of the queue

class Queue {
private:
    int queue[MAX_SIZE];  // Array to store the queue
    int front = 0;        // Initialize front 
    int rear = -1;        // Initialize rear 

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
bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

public:
    

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

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;  // Return a sentinel value or handle this case accordingly
        } else {
            return queue[front];
        }
    }
};

int main() {
    Queue myQueue;

    // Enqueue items into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Peek at the front item
    cout << "Front item (peek): " << myQueue.peek() << endl;

    // Dequeue items from the queue
    myQueue.dequeue();
    myQueue.dequeue();

    // Enqueue more items
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Dequeue remaining items
    myQueue.dequeue();
    myQueue.dequeue();

    return 0;
}