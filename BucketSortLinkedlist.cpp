#include <iostream>

using namespace std;

// Simple structure for a linked list node
struct Node {
    float data;
    Node* next;
    Node(float value) : data(value), next(nullptr) {}
};

// Function to insert a new node into a linked list
void insertNode(Node*& head, float value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to perform insertion sort on a linked list
Node* insertionSort(Node* head) {
    Node* sorted = nullptr;//new linked list to store sorted elements
    while (head) { //iterates as long as elements in org. list
        Node* current = head; //current set to current head of link. list
        head = head->next; // head updated to next element

        //if sorted is empty or current node data is less than or equal to first node
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;//insert curr. node at beginning
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next && search->next->data < current->data) {
                search = search->next; // search and insert at correct place
            }
            current->next = search->next;
            search->next = current; // current node at end of list
        }
    }
    return sorted;
}

// Function to sort each bucket using insertion sort
void sortBucket(Node* buckets[], int num_buckets) {
    for (int i = 0; i < num_buckets; ++i) {
        buckets[i] = insertionSort(buckets[i]);
    }
}

// Function to merge sorted buckets back into the original array
void mergeBuckets(float arr[], Node* buckets[], int num_buckets) {
    int index = 0; //keeps track of positino of org. array
    for (int i = 0; i < num_buckets; ++i) { //loop through buckets
        Node* current = buckets[i];
        while (current) {
            arr[index++] = current->data;//copy data in current node into org. array
            Node* temp = current;
            current = current->next; // move to next node
            delete temp; // Free memory for the node
        }
    }
}

// Function to perform bucket sort on an array of floating-point numbers
void bucketSort(float arr[], int n) {
    int num_buckets = 10;
    Node* buckets[num_buckets] = {nullptr};

    // Put elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = arr[i] * num_buckets;
        insertNode(buckets[bucketIndex], arr[i]);
    }

    // Sort each bucket using insertion sort
    sortBucket(buckets, num_buckets);

    // Merge the sorted buckets back into the original array
    mergeBuckets(arr, buckets, num_buckets);
}

// Function to print an array
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Example usage
    float arr[] = {0.89, 0.32, 0.53, 0.52, 0.37, 0.17, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}