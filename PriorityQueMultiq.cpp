#include <iostream>
using namespace std;

const int MAX_LEVELS = 10;
const int MAX_SIZE = 100;

struct QueueElement {
    int value;
    int priority;
};

QueueElement multiQueue[MAX_LEVELS][MAX_SIZE];
int queueSizes[MAX_LEVELS];

void initializeMultiQueue() {
    for (int i = 0; i < MAX_LEVELS; i++) {
        queueSizes[i] = 0;
    }
}

void push(QueueElement element) {
    if (element.priority < 0 || element.priority >= MAX_LEVELS) {
        cerr << "Invalid priority level for the element." << endl;
        return;
    }

    int level = element.priority;
    if (queueSizes[level] == MAX_SIZE) {
        cerr << "Queue at level " << level << " is full. Cannot push." << endl;
        return;
    }

    multiQueue[level][queueSizes[level]] = element;
    queueSizes[level]++;
}

QueueElement pop() {
    for (int level = 0; level < MAX_LEVELS; level++) {
        if (queueSizes[level] > 0) {
            QueueElement top = multiQueue[level][0];
            
            for (int i = 1; i < queueSizes[level]; i++) {
                multiQueue[level][i - 1] = multiQueue[level][i];
            }
            
            queueSizes[level]--;
            return top;
        }
    }

    cerr << "Priority queue is empty." << endl;
    return { -1, -1 };
}

bool isEmpty() {
    for (int level = 0; level < MAX_LEVELS; level++) {
        if (queueSizes[level] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    initializeMultiQueue();

    QueueElement elements[] = { {60, 2}, {70, 1}, {15, 3}, {35, 2}, {20, 1} };
    int numElements = 5;

    for (int i = 0; i < numElements; i++) {
        push(elements[i]);
    }

    while (!isEmpty()) {
        QueueElement element = pop();
        cout << "Value: " << element.value << ", Priority: " << element.priority << endl;
    }

    return 0;
}