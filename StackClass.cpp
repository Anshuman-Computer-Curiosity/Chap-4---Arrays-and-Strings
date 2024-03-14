#include <iostream>
using namespace std;

class Stack {
private:
    int* S; // pointer to int
    int top; // for top of stack
    int capacity; // for max. no. of elements

public:
    Stack(int size) { // constructor
        capacity = size;
        S = new int[capacity]; // dynamically creating S array
        top = -1; // indicating empty stack
    }

    ~Stack() { //destructor
        delete[] S; // deallocate memory to array S
    }

    void push(int item) {
        if (!is_full()) {
            // top = top + 1;
            // S[top] = item;
            S[++top] = item;
        } else {
            cout << "Stack is full" << endl;
        }
    }

    int pop() {
        if (!is_empty()) {
            return S[top--];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value to indicate an empty stack
        }
    }

    bool is_empty() {
        return top == -1; // indicating empty stack
    }

    bool is_full() {
        return top == capacity - 1;
    }

    void display() {
        if (!is_empty()) {
            cout << "Stack contents:" << endl;
            for (int i = top; i >= 0; i--) {
                cout << S[i] << endl;
            }
        } else {
            cout << "Stack is empty" << endl;
        }
    }
};

int main() {
    Stack my_stack(5);// creating object

    // Push some elements onto the stack
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    // Display the stack
    my_stack.display();

    // Pop elements from the stack
    cout << "Popped item: " << my_stack.pop() << endl;
    cout << "Popped item: " << my_stack.pop() << endl;

    // Display the updated stack
    my_stack.display();

    return 0;
}