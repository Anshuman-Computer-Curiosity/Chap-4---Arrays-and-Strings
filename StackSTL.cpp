#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Display the top element
    cout << "Top element: " << myStack.top() << endl;

    // Pop elements from the stack
    myStack.pop();
    myStack.pop();

    // Check if the stack is empty
    if (myStack.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    // Display the remaining elements
    while (!myStack.empty()) {
        cout << "Popped item: " << myStack.top() << endl;
        myStack.pop();
    }

    return 0;
}