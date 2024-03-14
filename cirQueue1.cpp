#include <iostream>
using namespace std;

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0, rear = -1;

bool isFull() {
    return ((front == 0 && rear == MAX_SIZE-1) || (rear != -1 && front == rear+1 ));
}

void display() {
    if ((rear != MAX_SIZE-1) && isFull()) {
        cout << "Queue is full.\n";
    } else {
        cout << "Queue contents: ";
        int i = front ;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear+1) % MAX_SIZE);
        cout << endl;
    }
}

void enqueue(int item) {
    if ( isFull()) {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    } else if (rear == -1) {
        front = rear = 0;
        queue[rear] = item;
    } else {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
    }
    display(); // Display the queue after enqueuing
}

int dequeue() {
    if (rear == -1) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return -1;
    }

    int frontItem = queue[front];
    if (front == rear) {
        front = 0;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return frontItem;
}

int main() {
    enqueue(10);
    enqueue(25);
    enqueue(15);
    enqueue(35);
    enqueue(20);
    enqueue(80);

    cout << "Dequeued 3 elements " << endl;
    for(int i = 0; i <3; i++)
        dequeue();

    display(); // Display the queue after dequeuing

    enqueue(60);
    enqueue(70);

    cout << "Dequeued: " << dequeue() << endl;
    display(); // Display the queue after dequeuing

    return 0;
}