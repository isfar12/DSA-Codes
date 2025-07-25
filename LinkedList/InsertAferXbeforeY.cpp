#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList 
{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList()
        {
            head=tail=NULL;
        }
        void push_front(int val)
        {
            Node *newNode = new Node(val);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head; // newvalue -> old head -> other nodes
                head = newNode; // head->newvalue -> old head -> etc
            }
        }
        void push_back(int val)
        {
            Node *newNode = new Node(val);
            if (tail == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode; // old tail -> new value
                tail = newNode; // tail -> new value
            }
        }
        void pop_front()
        {
            if (head == nullptr) return; // List is empty
            Node* temp = head;
            head = head->next; // Move head to the next node
            delete temp; // Free the old head node
            if (head == nullptr) tail = nullptr; // If list becomes empty, update tail
        }
        void pop_back()
        {
            if (head == nullptr) return; // List is empty
            if (head == tail) { // Only one element
                delete head;
                head = tail = nullptr;
                return;
            }
            Node* current = head;
            while (current->next != tail) {
                current = current->next; // Find the second last node
            }
            delete tail; // Delete the last node
            tail = current; // Update tail to the second last node
            tail->next = nullptr; // Set next of new tail to nullptr
        }

        void insertAfterXBeforeY(int x, int y, int val) {
            Node* current = head;
            Node* prev = nullptr;

            // Find the node with value x
            while (current != nullptr && current->data != x) {
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Node with value " << x << " not found." << endl;
                return; // x not found
            }

            // Now find the node with value y
            Node* yNode = head;
            while (yNode != nullptr && yNode->data != y) {
                yNode = yNode->next;
            }

            if (yNode == nullptr) {
                cout << "Node with value " << y << " not found." << endl;
                return; // y not found
            }

            // Insert new node after x and before y
            Node* newNode = new Node(val);
            if (prev != nullptr) {
                prev->next = newNode; // Link previous node to new node
            } else {
                head = newNode; // If x was the head, update head
            }
            newNode->next = current; // Link new node to the node with value x
        }
        void printList()
        {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << endl;
        }


        
};

int main() {
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.printList();

    return 0;
} 