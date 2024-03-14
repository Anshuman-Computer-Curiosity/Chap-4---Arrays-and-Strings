#include <iostream>
using namespace std;
int data[10]; // Array to store the data
int link[10]; // Array to store the indices of the next nodes

int head = -1; // Index of the head node

void addNode(int value) {
    static int curIndex = 0; // Static variable to keep track of the cur index

    data[curIndex] = value;
    if (head == -1) {
        head = curIndex;  // Set the head to the first node
    } else {
        link[curIndex - 1] = curIndex;  // Update the next pointer of the previous node
        //cout<<"link["<<curIndex - 1<<"] = "<<link[curIndex - 1]<<endl;
    }
    link[curIndex] = -1;  // Set the next pointer of the new node to -1 indicating end of the list
    
    curIndex++; // Increment the current index
}

// Function to traverse and print the linked list
void printList() {
    int curIndex = head; // Start from the head
    
    while (curIndex != -1) {
        cout << data[curIndex] << " ";
        curIndex = link[curIndex]; // Move to the next node
    }
    cout<<endl;
}

int main() {
    // Adding nodes to the linked list
    addNode(10);
    addNode(20);
    addNode(30);
    addNode(40);

    printList();

    return 0;
}