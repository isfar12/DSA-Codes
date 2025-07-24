#include <iostream>
using namespace std;

#define SIZE 100

struct Element {
    int value;
    int priority;
};

Element pq[SIZE]; // Priority queue array
int size = 0;

// Enqueue: insert based on priority
void enqueue(int value, int priority) {
    if (size == SIZE) {
        cout << "Priority Queue is full\n";
        return;
    }

    pq[size].value = value;
    pq[size].priority = priority;
    size++;

    cout << "Enqueued: " << value << " with priority " << priority << "\n";
}

// Dequeue: remove the element with highest priority (lowest number)
void dequeue() {
    if (size == 0) {
        cout << "Priority Queue is empty\n";
        return;
    }

    // Find the highest priority element (lowest priority number)
    int highestPriority = pq[0].priority;
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i].priority < highestPriority) {
            highestPriority = pq[i].priority;
            index = i;
        }
    }

    cout << "Dequeued: " << pq[index].value << " with priority " << pq[index].priority << "\n";

    // Shift elements to fill the gap
    for (int i = index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Display all elements in the queue
void display() {
    if (size == 0) {
        cout << "Priority Queue is empty\n";
        return;
    }

    cout << "Priority Queue elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Value: " << pq[i].value << ", Priority: " << pq[i].priority << "\n";
    }
}

int main() {
    enqueue(10, 2);   // 10 with priority 2
    enqueue(30, 1);   // 30 with priority 1
    enqueue(20, 3);   // 20 with priority 3

    display();        // Should list all three

    dequeue();        // Should remove 30 (priority 1)
    display();        // Should show 10 and 20

    dequeue();        // Should remove 10
    dequeue();        // Should remove 20
    dequeue();        // Should say empty

    return 0;
}
