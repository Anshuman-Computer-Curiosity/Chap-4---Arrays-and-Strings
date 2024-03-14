#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;  // Added size counter

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;  // Initialize size to 0
    }

    bool isEmpty() {
        return front == nullptr;
    }

    bool isFull() {
        return size == 5;  // Limit the size to 5
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue contents: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;

        if (isEmpty()) {
            newNode->next = newNode;
            front = newNode;
            rear = newNode;
        } else {
            newNode->next = front;
            rear->next = newNode;
            rear = newNode;
        }
        size++;  // Increment the size counter
        cout << "Enqueued: " << data << endl;
        display();
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int frontItem = front->data;

        if (front == rear) {
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        size--;  // Decrement the size counter
        cout << "Dequeued: " << frontItem << endl;
        display();
        return frontItem;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(25);
    cq.enqueue(15);
    cq.enqueue(35);
    cq.enqueue(20);
    cq.enqueue(40);

    cq.dequeue();
    cq.dequeue();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.dequeue();

    return 0;
}