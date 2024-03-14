#include <iostream>
using namespace std;

#define MAX_SIZE 10 // Maximum size of the stack

int S[MAX_SIZE]; // Array to store stack elements
int top = -1; // Initialize top of empty stack

// Function to push an element onto the stack
void push(int item) {
    if (top >= MAX_SIZE - 1) {//overflow
        cout << "Stack is full" << std::endl;
    } else {
        // top = top + 1;
        // S[top] = item;
        S[++top] = item; // combined
    }
}

// Function to pop and return the top element from the stack
int pop() {
    if (top < 0) {//Underflow
        cout << "Stack is empty" << endl;
        return -1; // Return a sentinel value to indicate an empty stack
    } else {
        // int item = S[top];
	    // top = top - 1;
        // return item;

        return S[top--];
    }
}

// Function to display the contents of the stack
void display() {
    if (top==-1) {
         cout << "Stack is empty" << endl;
    } else{
        cout << "Stack contents:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }
}

int main() {
    // Push some elements onto the stack
    push(1);
    push(2);
    push(3);

    // Display the stack
    display();

    // Pop elements from the stack
    cout << "Popped item: " << pop() << endl;
    cout << "Popped item: " << pop() << endl;

    // Display the updated stack
    display();

    return 0;
}