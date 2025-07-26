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
        bool isEmpty() {
            return head == nullptr;
        }
        
        int size() {
            int count = 0;
            Node* current = head;
            while(current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }
        
        void printList()
        {
            if(isEmpty()) {
                cout << "List is empty!" << endl;
                return;
            }
            Node* current = head;
            while (current != nullptr) {
                cout << current->data;
                if(current->next != nullptr) cout << " -> ";
                current = current->next;
            }
            cout << " -> NULL" << endl;
        }
        
        void displayMenu() {
            cout << "\n=== LinkedList Operations ===" << endl;
            cout << "1. Push Front" << endl;
            cout << "2. Push Back" << endl;
            cout << "3. Pop Front" << endl;
            cout << "4. Pop Back" << endl;
            cout << "5. Insert at Position" << endl;
            cout << "6. Print List" << endl;
            cout << "7. Get Size" << endl;
            cout << "8. Check if Empty" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
        }
};

int main() {
    LinkedList list;
    int choice, value, position;
    
    cout << "=== Interactive LinkedList Implementation ===" << endl;
    
    while(true) {
        list.displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to push front: ";
                cin >> value;
                list.push_front(value);
                cout << "Value " << value << " added to front." << endl;
                break;
                
            case 2:
                cout << "Enter value to push back: ";
                cin >> value;
                list.push_back(value);
                cout << "Value " << value << " added to back." << endl;
                break;
                
            case 3:
                if(!list.isEmpty()) {
                    list.pop_front();
                    cout << "Front element removed." << endl;
                } else {
                    cout << "List is empty! Cannot pop front." << endl;
                }
                break;
                
            case 4:
                if(!list.isEmpty()) {
                    list.pop_back();
                    cout << "Back element removed." << endl;
                } else {
                    cout << "List is empty! Cannot pop back." << endl;
                }
                break;
                
            case 5:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position (0-based): ";
                cin >> position;
                list.insert_at_position(value, position);
                cout << "Value " << value << " inserted at position " << position << "." << endl;
                break;
                
            case 6:
                cout << "Current List: ";
                list.printList();
                break;
                
            case 7:
                cout << "List size: " << list.size() << endl;
                break;
                
            case 8:
                cout << "List is " << (list.isEmpty() ? "empty" : "not empty") << endl;
                break;
                
            case 0:
                cout << "Exiting LinkedList program..." << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
} 