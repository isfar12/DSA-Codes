#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void print(Node* h) {
    while (h) cout << h->data << " -> ", h = h->next;
    cout << "NULL\n";
}

void insert(Node*& avail, Node* x, int n) {
    if (!avail) avail = new Node{0, nullptr};
    Node* newNode = avail;
    avail = avail->next;
    newNode->data = n;
    newNode->next = x->next;
    x->next = newNode;
}

void del(Node*& avail, Node*& head, int val) {
    Node* curr = head, *prev = nullptr;
    while (curr && curr->data != val) prev = curr, curr = curr->next;
    if (!curr) return;
    if (prev) prev->next = curr->next; else head = curr->next;
    curr->next = avail; curr->data = 0; avail = curr;
}

int main() {
    int n; cout << "Size: "; cin >> n;
    Node* L = nullptr;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (!L) L = new Node{v, nullptr};
        else {
            Node* curr = L;
            while (curr->next) curr = curr->next;
            curr->next = new Node{v, nullptr};
        }
    }
    
    Node* avail = new Node{0, new Node{0, new Node{0, nullptr}}};
    cout << "Main: "; print(L);
    cout << "Avail: "; print(avail);
    
    int c;
    while (cout << "\n1.Insert 2.Delete 3.Show 0.Exit: ", cin >> c, c) {
        if (c == 1) {
            int newVal, afterVal;
            cout << "Value: "; cin >> newVal;
            cout << "After: "; cin >> afterVal;
            Node* curr = L;
            while (curr && curr->data != afterVal) curr = curr->next;
            if (curr) insert(avail, curr, newVal);
        } else if (c == 2) {
            int delVal; cout << "Delete: "; cin >> delVal;
            del(avail, L, delVal);
        } else if (c == 3) {
            cout << "Main: "; print(L);
            cout << "Avail: "; print(avail);
        }
    }
    return 0;
}
