#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return -1; // Return a value to indicate an error
        } else {
            Node* ptr = top;
            int poppedItem = ptr->data;
            top = top->next;
            delete ptr;
            return poppedItem;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a value to indicate an error
        } else {
            return top->data;
        }
    }

    void display() {
        Node* current = top;
        cout << "Stack contents: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~Stack() {
        // Destructor to deallocate memory when the stack is destroyed
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(25);
    stack.push(20);

    // Display the stack
    stack.display();

    // Pop elements from the stack
    int poppedItem = stack.pop();
    cout << "Popped item: " << poppedItem << endl;

    // Peek at the top element
    int topItem = stack.peek();
    cout << "Top item: " << topItem << endl;

    // Display the stack after popping
    stack.display();

    return 0;
}