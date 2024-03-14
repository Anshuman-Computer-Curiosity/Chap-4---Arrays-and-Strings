#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> myQueue;

    // Enqueue items into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Peek at the front item
    cout << "Front item (peek): " << myQueue.front() << endl;

    // Dequeue items from the queue
    cout << "Dequeued item: " << myQueue.front() << endl;
    myQueue.pop();
    cout << "Dequeued item: " << myQueue.front() << endl;
    myQueue.pop();

    // Check if the queue is empty
    if (myQueue.empty()) {
        cout << "The queue is empty." << endl;
    } else {
        cout << "The queue is not empty." << endl;
    }

    // Enqueue more items
    myQueue.push(40);
    myQueue.push(50);

    // Dequeue remaining items
    cout << "Dequeued item: " << myQueue.front() << endl;
    myQueue.pop();
    cout << "Dequeued item: " << myQueue.front() << endl;
    myQueue.pop();

    return 0;
}