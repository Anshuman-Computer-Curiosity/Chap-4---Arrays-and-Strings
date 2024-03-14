#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
int maxSize = 5;  // Set the maximum size of the queue

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

bool isFull() {
    if (front == nullptr)
        return false;
    int count = 1;
    Node* temp = front;
    while (temp != rear) {
        count++;
        temp = temp->next;
    }
    return count == maxSize;
}

bool isEmpty() {
    return front == nullptr;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = front;
    cout << "Queue contents: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != rear->next);
    delete temp;
    cout << endl;
}

void enqueue(int data) {
    if (isFull()) {
        Node* temp = front;
        front = front->next;
        delete temp;  // Remove the oldest element
    }

    Node* newNode = createNode(data);

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front;  // Make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // Make it circular
    }
    cout << "Enqueued: " << data << endl;
    display();
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return -1;
    }

    int frontItem = front->data;
    Node* temp = front;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        rear->next = front;  // Update the circular link
    }
    delete temp;
    cout << "Dequeued: " << frontItem << endl;
    display();
    return frontItem;
}

int main() {
    enqueue(10);
    enqueue(25);
    enqueue(15);
    enqueue(35);
    enqueue(20);
    enqueue(80);

    dequeue();
    dequeue();
    enqueue(60);
    enqueue(70);

    dequeue();

    return 0;
}