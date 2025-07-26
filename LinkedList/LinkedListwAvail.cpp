#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 🔹 Print any linked list (used for both L and avail)
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// 🔹 Insert new item N between X and Y, taking node from avail
void insertAfter(Node*& avail, Node* X, Node* Y, int N) {
    if (avail == nullptr) {
        cout << "No free nodes available in AVAIL list!" << endl;
        return;
    }

    cout << "\nTaking node from AVAIL list..." << endl;

    // Step 1: Take first node from avail list
    Node* newNode = avail;
    avail = avail->next;  // Move avail head forward

    // Step 2: Assign data to new node
    newNode->data = N;

    // Step 3: Adjust pointers to insert into main list
    newNode->next = Y;
    X->next = newNode;

    cout << "\nInserted " << N << " between " << X->data << " and " << Y->data << endl;
}

int main() {
    // 🔹 Linked List L: 10 -> 20 -> 30
    Node* L1 = new Node{10, nullptr};
    Node* L2 = new Node{20, nullptr};
    Node* L3 = new Node{30, nullptr};

    L1->next = L2;
    L2->next = L3;

    // 🔹 Avail list: 0 -> 0 -> 0
    Node* A1 = new Node{0, nullptr};
    Node* A2 = new Node{0, nullptr};
    Node* A3 = new Node{0, nullptr};
    A1->next = A2;
    A2->next = A3;
    Node* avail = A1;

    cout << "Initial MAIN LIST: ";
    printList(L1);

    cout << "Initial AVAIL LIST: ";
    printList(avail);

    // 🔹 Insert 15 between 10 and 20
    insertAfter(avail, L1, L2, 15);

    cout << "\nMAIN LIST after insertion: ";
    printList(L1);

    cout << "AVAIL LIST after insertion: ";
    printList(avail);

    // 🔹 Insert another 25 between 20 and 30
    insertAfter(avail, L2, L3, 25);

    cout << "MAIN LIST after second insertion: ";
    printList(L1);

    cout << "AVAIL LIST after second insertion: ";
    printList(avail);

    return 0;
}
