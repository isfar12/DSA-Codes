#include <iostream>
using namespace std;

const int SIZE = 100;

struct Node {
    int data;
    int next;
};

Node nodes[SIZE];
int avail = 5;
int start = 0;

void initialize() {
    nodes[0] = {10, 1};
    nodes[1] = {20, 2};
    nodes[2] = {30, -1};

    for (int i = 5; i < SIZE - 1; i++) {
        nodes[i].next = i + 1;
    }
    nodes[SIZE - 1].next = -1;
}

int findIndexByValue(int value) {
    int curr = start;
    while (curr != -1) {
        if (nodes[curr].data == value)
            return curr;
        curr = nodes[curr].next;
    }
    return -1;
}

void insertAfterValue(int X_value, int N_value) {
    if (avail == -1) {
        cout << "No available nodes in avail list!" << endl;
        return;
    }

    int X_index = findIndexByValue(X_value);
    if (X_index == -1) {
        cout << "Value " << X_value << " not found in the list!" << endl;
        return;
    }

    int N_index = avail;
    avail = nodes[avail].next;

    nodes[N_index].data = N_value;
    nodes[N_index].next = nodes[X_index].next;
    nodes[X_index].next = N_index;

    cout << "Inserted " << N_value << " after " << X_value << " successfully.\n";
}

void printList() {
    int curr = start;
    while (curr != -1) {
        cout << nodes[curr].data << " -> ";
        curr = nodes[curr].next;
    }
    cout << "NULL" << endl;
}

void printAvail() {
    cout << "Avail list indexes: ";
    int curr = avail;
    while (curr != -1) {
        cout << curr << " ";
        curr = nodes[curr].next;
    }
    cout << endl;
}

int main() {
    initialize();

    cout << "Initial linked list:\n";
    printList();
    printAvail();

    int X_value, N_value;
    cout << "\nEnter value X (after which to insert): ";
    cin >> X_value;
    cout << "Enter new value N to insert: ";
    cin >> N_value;

    insertAfterValue(X_value, N_value);

    cout << "\nUpdated linked list:\n";
    printList();
    printAvail();

    return 0;
}