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

// 🔹 Create AVAIL list with specified number of nodes
Node* createAvailList(int size) {
    if (size <= 0) return nullptr;
    
    Node* head = new Node{0, nullptr};
    Node* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = new Node{0, nullptr};
        current = current->next;
    }
    
    return head;
}

// 🔹 Add a new node to AVAIL list (when we need more nodes)
void addToAvail(Node*& avail) {
    Node* newNode = new Node{0, avail};
    avail = newNode;
    cout << "Added new node to AVAIL list (dynamic allocation)" << endl;
}

// 🔹 Insert new item N between X and Y, taking node from avail
void insertAfter(Node*& avail, Node* X, Node* Y, int N) {
    // If AVAIL is empty, create a new node dynamically
    if (avail == nullptr) {
        cout << "AVAIL list is empty! Creating new node dynamically..." << endl;
        addToAvail(avail);
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

// 🔹 Delete a node and return it to AVAIL list
void deleteNode(Node*& avail, Node*& head, int value) {
    if (head == nullptr) return;
    
    Node* current = head;
    Node* prev = nullptr;
    
    // Find the node to delete
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "Value " << value << " not found in list!" << endl;
        return;
    }
    
    // Remove from main list
    if (prev == nullptr) {
        head = current->next;  // Deleting head
    } else {
        prev->next = current->next;
    }
    
    // Add to AVAIL list
    current->next = avail;
    current->data = 0;  // Reset data
    avail = current;
    
    cout << "Deleted " << value << " and returned node to AVAIL list" << endl;
}

// 🔹 Count nodes in a list
int countNodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    cout << "=== LinkedList with AVAIL List Management ===" << endl;
    
    // Get user input for initial setup
    cout << "Enter number of initial nodes in main list: ";
    int mainSize;
    cin >> mainSize;
    
    cout << "Enter number of nodes in AVAIL list: ";
    int availSize;
    cin >> availSize;
    
    // 🔹 Create main linked list
    Node* L = nullptr;
    if (mainSize > 0) {
        cout << "Enter " << mainSize << " values for main list: ";
        int firstValue;
        cin >> firstValue;
        L = new Node{firstValue, nullptr};
        
        Node* current = L;
        for (int i = 1; i < mainSize; i++) {
            int value;
            cin >> value;
            current->next = new Node{value, nullptr};
            current = current->next;
        }
    }
    
    // 🔹 Create AVAIL list
    Node* avail = createAvailList(availSize);

    cout << "\nInitial MAIN LIST: ";
    printList(L);

    cout << "Initial AVAIL LIST: ";
    printList(avail);
    cout << "AVAIL list has " << countNodes(avail) << " nodes available" << endl;

    // Interactive menu
    int choice;
    while (true) {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Insert after a value" << endl;
        cout << "2. Delete a value" << endl;
        cout << "3. Show current lists" << endl;
        cout << "4. Show AVAIL count" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                if (L == nullptr) {
                    cout << "Main list is empty! Cannot insert." << endl;
                    break;
                }
                
                cout << "Enter value to insert: ";
                int newValue;
                cin >> newValue;
                
                cout << "Enter value after which to insert: ";
                int afterValue;
                cin >> afterValue;
                
                // Find the node with afterValue
                Node* current = L;
                while (current != nullptr && current->data != afterValue) {
                    current = current->next;
                }
                
                if (current == nullptr) {
                    cout << "Value " << afterValue << " not found!" << endl;
                } else if (current->next == nullptr) {
                    cout << "Cannot insert after last node using this method!" << endl;
                } else {
                    insertAfter(avail, current, current->next, newValue);
                }
                break;
            }
            
            case 2: {
                cout << "Enter value to delete: ";
                int delValue;
                cin >> delValue;
                deleteNode(avail, L, delValue);
                break;
            }
            
            case 3: {
                cout << "\nCurrent MAIN LIST: ";
                printList(L);
                cout << "Current AVAIL LIST: ";
                printList(avail);
                break;
            }
            
            case 4: {
                cout << "AVAIL list has " << countNodes(avail) << " nodes available" << endl;
                break;
            }
            
            case 0: {
                cout << "Exiting program..." << endl;
                return 0;
            }
            
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    }

    return 0;
}
