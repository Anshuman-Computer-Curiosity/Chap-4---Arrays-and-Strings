#include <iostream>
using namespace std;

// Define the Node struct to represent elements in the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool isEmpty(Node* top) {
    return top == nullptr;
}

void push(Node*& top, int data) {
    Node* newNode = new Node(data);
    if (isEmpty(top)) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

int pop(Node*& top) {
    if (isEmpty(top)) {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1; // Return a sentinel value to indicate an error
    } else {
        Node* ptr = top;
        int poppedItem = ptr->data;
        top = top->next;
        delete ptr;
        return poppedItem;
    }
}

int peek(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack is empty. Cannot peek." << endl;
        return -1; // Return a value to indicate an error
    } else {
        return top->data;
    }
}

void display(Node* top) {
    Node* current = top;
    cout << "Stack contents: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* stacktop = nullptr; // empty stack

    // Push elements onto the stack
    push(stacktop, 10);
    push(stacktop, 25);
    push(stacktop, 20);

    // Display the stack
    display(stacktop);

    // Pop elements from the stack
    int poppedItem = pop(stacktop);
    cout << "Popped item: " << poppedItem << endl;

    // Peek at the top element
    int topItem = peek(stacktop);
    cout << "Top item: " << topItem << endl;

    // Display the stack after popping
    display(stacktop);

    // Clean up memory by popping remaining elements and deallocating nodes
    while (!isEmpty(stacktop)) {
        pop(stacktop);
    }

    return 0;
}