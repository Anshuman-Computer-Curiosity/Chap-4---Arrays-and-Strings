#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

using namespace std;

// Function to perform reheapify up
void reheapifyUp(Node* root, Node* newNode) {
    Node* current = newNode;
    while (current->data > root->data) {
        swap(current->data, root->data);
        current = root;
        root = (current->data > root->data) ? root->left : root->right;
    }
}

// Function to perform reheapify down
void reheapifyDown(Node* root) {
    if (root == nullptr) {
        return;
    }

    Node* largest = root;
    Node* leftChild = root->left;
    Node* rightChild = root->right;

    if (leftChild != nullptr && leftChild->data > largest->data) {
        largest = leftChild;
    }

    if (rightChild != nullptr && rightChild->data > largest->data) {
        largest = rightChild;
    }

    if (largest != root) {
        swap(root->data, largest->data);
        reheapifyDown(largest);
    }
}

// Function to insert a new element into the max heap
Node* insert(Node* root, int val) {
    Node* newNode = new Node(val);

    if (root == nullptr) {
        return newNode;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        parent = current;
        if (val > current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (val > parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    reheapifyUp(root, newNode);
    return root;
}

// Function to find and delete a specific node from the max heap
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr && current->data != key) {
        parent = current;
        current = (key > current->data) ? current->left : current->right;
    }

    if (current == nullptr) {
        cout << "Node with key " << key << " not found in the max heap." << endl;
        return root;
    }

    // Swap the data with the last node's data
    int lastData = root->data;
    root->data = current->data;
    current->data = lastData;

    // Delete the last node
    Node* lastNodeParent = nullptr;
    Node* lastNode = root;
    while (lastNode->left != nullptr || lastNode->right != nullptr) {
        lastNodeParent = lastNode;
        lastNode = (lastNode->left != nullptr) ? lastNode->left : lastNode->right;
    }

    if (lastNodeParent != nullptr) {
        if (lastNodeParent->left == lastNode) {
            delete lastNodeParent->left;
            lastNodeParent->left = nullptr;
        } else {
            delete lastNodeParent->right;
            lastNodeParent->right = nullptr;
        }
    }

    reheapifyDown(root);
    return root;
}

// Function to display the max heap in tree-like format
void displayHeap(Node* root, int space = 0, int gap = 10) {
    const int spacing = 3;

    if (root == nullptr) {
        return;
    }

    if (root->right != nullptr) {
        displayHeap(root->right, space + 1, spacing);
    }

    for (int i = 0; i < space; i++) {
        cout << " ";
    }

    cout << root->data << endl;

    if (root->left != nullptr) {
        displayHeap(root->left, space + 1, spacing);
    }
}

int main() {
    Node* root = nullptr;
    int elements[] = {80, 70, 60, 30, 40, 35, 50, 20, 10};
    int n = sizeof(elements) / sizeof(elements[0]);

    cout << "Inserting elements into the max heap:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Inserting " << elements[i] << " into the max heap" << endl;
        root = insert(root, elements[i]);
    }

    cout << "\nMax Heap elements (tree-like format):" << endl;
    displayHeap(root);

    int deleteElement = 70;
    root = deleteNode(root, deleteElement);
    cout << "\nAfter deleting " << deleteElement << " from the max heap:" << endl;
    displayHeap(root);

    return 0;
}