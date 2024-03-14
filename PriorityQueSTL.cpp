#include <iostream>
#include <queue>  // Include the priority_queue STL
using namespace std;

// Define a struct to hold both value and priority
struct QueueElement {
    int value;
    int priority;

    // Define a custom comparison operator to reverse the priority order
    bool operator<(const QueueElement& other) const {
        return priority > other.priority;
    }
};

int main() {
    //creating an instance of a priority queue where each element is of type QueueElement
    priority_queue<QueueElement> priorityQueue;

    // Insert elements with values and priorities
    priorityQueue.push({60, 2});
    priorityQueue.push({70, 3});
    priorityQueue.push({15, 1});
    priorityQueue.push({35, 2});
    priorityQueue.push({20, 1});

    cout << "Top element: Value=" << priorityQueue.top().value << ", Priority=" << priorityQueue.top().priority << endl;

    // Pop elements (removing the element with the highest priority)
    while (!priorityQueue.empty()) {
        QueueElement top = priorityQueue.top();
        cout << "Pop: Value=" << top.value << ", Priority=" << top.priority << endl;
        priorityQueue.pop();
    }

    return 0;
}