#include <iostream>
#include <stack>
using namespace std;

stack<int> qStack;

// Enqueue: Just push to the stack
void enqueue(int value) {
    qStack.push(value);
    cout << "Enqueued: " << value << "\n";
}

// Dequeue: Recursively reach the bottom (first inserted element)
int dequeue() {
    if (qStack.empty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    int top = qStack.top();
    qStack.pop();

    // If stack becomes empty, this was the first element (front of queue)
    if (qStack.empty()) {
        cout << "Dequeued: " << top << "\n";
        return top;
    }

    // Recursively dequeue from remaining stack
    int front = dequeue();

    // Push everything back after getting the front
    qStack.push(top);
    return front;
}

// Show the front without removing it
int front() {
    if (qStack.empty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    int top = qStack.top();
    qStack.pop();

    if (qStack.empty()) {
        cout << "Front element is: " << top << "\n";
        qStack.push(top); // Restore the stack
        return top;
    }

    int result = front(); // Recursive call
    qStack.push(top);     // Restore the stack
    return result;
}

// Display by popping all, storing in temp, and restoring
int display() {
    if (qStack.empty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    int top = qStack.top();
    qStack.pop();

    // If stack becomes empty, this was the first element (front of queue)
    if (qStack.empty()) {
        cout << top << " ";
        qStack.push(top);
        return top;
    }
    
    // Recursively dequeue from remaining stack
    int front = display();
    
    // Push everything back after getting the front
    cout << top << "  ";
    qStack.push(top);
    return 0;
}

// Main to test
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);

    display();    // Should print: 10 20 30
    front();      // Should print: 10
    dequeue();    // Should remove: 10
    display();    // Should print: 20 30
    dequeue();    // Should remove: 20
    dequeue();    // Should remove: 30
    display();
    dequeue();    // Should remove: 30
    display();
    return 0;
}
