#include <iostream>
using namespace std;

class Queue {
private:
    // Node structure for a linked list
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

    // Function to display the contents of the queue
    void display() {
    Node* current = front;
    cout << "Contents of queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to perform enqueue (push) operation
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << newNode->data << endl;
        display();
    }

    // Function to perform dequeue (pop) operation
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value or handle this case accordingly
        }
        int frontItem = front->data;
        Node* ptr = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete ptr;
        cout << "Dequeued: " << frontItem << endl;
        display();
        return frontItem;
    }

    // Function to perform front (peek) operation
    int frontElement() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value or handle this case accordingly
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue myQueue;

    // Enqueue items into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(25);
    myQueue.enqueue(15);
    myQueue.enqueue(35);
    myQueue.enqueue(20);

    // Peek at the front item
    cout << "Front item (peek): " << myQueue.frontElement() << endl;

    // Dequeue items from the queue
    myQueue.dequeue();
    myQueue.dequeue();

    // Enqueue more items
    myQueue.enqueue(60);
    myQueue.enqueue(70);

    // Dequeue remaining items
    myQueue.dequeue();
    myQueue.dequeue();

    return 0;
}