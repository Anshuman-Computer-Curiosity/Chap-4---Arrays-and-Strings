#include <iostream>
using namespace std;

int* queue;        // Array to store the queue
int maxSize;       // Maximum size of the queue
int front = 0;     // Initialize front
int rear = -1;     // Initialize rear

void initializeQueue(int size) {
    queue = new int[size];
    maxSize = size;
}

bool isEmpty() {
    return front > rear;
}

bool isFull() {
    return rear == maxSize - 1;
}

void displayQueue() {
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
        displayQueue();
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
        displayQueue();
        return frontItem;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot peek." << endl;
        return -1;  // Return a sentinel value or handle this case accordingly
    } else {
        cout << "Front item (peek): " << queue[front] << endl;
        return queue[front];
    }
}

int main() {
    int size;
    cout << "Enter the maximum size of the queue: ";
    cin >> size;
    initializeQueue(size);

    int choice = 0;

    while (choice != 5) {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if the queue is empty" << endl;
        cout << "5. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (rear < maxSize - 1) {
                int item;
                cout << "Enter the value to enqueue: ";
                cin >> item;
                enqueue(item);
            } else {
                cout << "Queue is full. Cannot enqueue." << endl;
            }
        } else if (choice == 2) {
            if (!isEmpty()) {
                dequeue();
            } else {
                cout << "Queue is empty. Cannot dequeue." << endl;
            }
        } else if (choice == 3) {
            if (!isEmpty()) {
                peek();
            } else {
                cout << "Queue is empty. Cannot peek." << endl;
            }
        } else if (choice == 4) {
            if (isEmpty()) {
                cout << "The queue is empty." << endl;
            } else {
                cout << "The queue is not empty." << endl;
            }
        } else if (choice != 5) {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    delete[] queue;  // Free the dynamically allocated memory
    cout << "Quitting the program." << endl;

    return 0;
}