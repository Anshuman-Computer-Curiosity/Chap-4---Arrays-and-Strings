#include <iostream>
using namespace std;

// Node structure for a linked list
struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;  // Global front pointer
Node* rear = nullptr;   // Global rear pointer

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

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

// Function to perform enqueue (push) operation
void enqueue(int data) {
    Node* newNode = createNode(data);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << data << endl;
    // Display the queue after enqueuing
    display();
}

// Function to perform dequeue (pop) operation
int dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    int frontItem = front->data;
    Node* ptr = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete ptr;
    cout << "Dequeued: " << frontItem << endl;
    // Display the queue after dequeuing
    display();
    return frontItem;
}

// Function to perform front (peek) operation
int frontElement() {
    if (front == nullptr) {
        cout << "Queue is empty. Cannot peek." << endl;
        return -1;
    }
    return front->data;
}

int main() {
    // Enqueue items into the queue
    enqueue(10);
    enqueue(25);
    enqueue(15);
    enqueue(35);
    enqueue(20);
    

    // Peek at the front item
    cout << "Front item (peek): " << frontElement() << endl;

    // Dequeue items from the queue
    dequeue();
    dequeue();

    // Enqueue more items
    enqueue(60);
    enqueue(70);

    // Dequeue remaining items
    dequeue();
    dequeue();

    

    return 0;
}