#include <iostream>

using namespace std;

// Structure to define a node in the max-heap
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to display the elements of the max-heap using inorder traversal
void displayHeap(Node* root) {
    if (root) {
        displayHeap(root->left);
        cout << root->value << " ";
        displayHeap(root->right);
    }
}

// Function to perform the reheapify-up operation after insertion for a max-heap
Node* reheapifyUp(Node* root, Node* newNode) {
    while (newNode->value > newNode->parent->value) {
        swap(newNode->value, newNode->parent->value);
        newNode = newNode->parent;
    }
    return root;
}

// Function to insert a new node into the max-heap
Node* insertNode(Node* root, int value) {
    Node* newNode = new Node(value);
    if (!root) {
        return newNode; // If the heap is empty, the new node becomes the root
    }

    // Find the parent of the new node
    Node* parent = nullptr;
    Node* current = root;

    while (current) {
        parent = current;
        if (value > current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Attach the new node as the left or right child of the parent
    if (value > parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // Set the parent of the new node
    newNode->parent = parent;

    // Perform reheapify-up to maintain the max-heap property
    return reheapifyUp(root, newNode);
}

int main() {
    Node* root = nullptr;

    // Initial heap elements
    root = insertNode(root, 80);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 35);
    root = insertNode(root, 50);
    root = insertNode(root, 20);
    root = insertNode(root, 10);

    // Display the heap before insertion
    cout << "Heap before insertion: ";
    displayHeap(root);
    cout << endl;

    // Insert a new node with value 90
    root = insertNode(root, 90);

    // Display the heap after insertion
    cout << "Heap after insertion: ";
    displayHeap(root);
    cout << endl;

    return 0;
}