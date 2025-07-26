#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
    private:
        Node* root;
    
        Node* insert(Node* node, int val)
        {
            if(node ==nullptr){
                return new Node(val);
            }
            if(val<node->data)
            {
                node->left=insert(node->left, val);
            }
            else
            {
                node->right=insert(node->right, val);
            }
            return node;

        }

    public:
        BinaryTree() {
            root = nullptr;
        }
        Node* getRoot() {
            return root;
        }
        void insert(int val) {
            root = insert(root, val);
        }
        
        void inorder(Node* node) {
            if(node != nullptr) {
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            }
        }
        
        void preorder(Node* node) {
            if(node != nullptr) {
                cout << node->data << " ";
                preorder(node->left);
                preorder(node->right);
            }
        }
        
        void postorder(Node* node) {
            if(node != nullptr) {
                postorder(node->left);
                postorder(node->right);
                cout << node->data << " ";
            }
        }
        
        void printInorder() {
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
        }
        
        void printPreorder() {
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
        }
        
        void printPostorder() {
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
        }
        
        bool search(int val) {
            return searchHelper(root, val);
        }
        
    private:
        bool searchHelper(Node* node, int val) {
            if(node == nullptr) return false;
            if(node->data == val) return true;
            if(val < node->data) return searchHelper(node->left, val);
            return searchHelper(node->right, val);
        }
};

int main() {
    cout << "=== Binary Search Tree Implementation ===" << endl;
    cout << "Enter number of values to insert: ";
    int n;
    cin >> n;
    
    BinaryTree tree;
    
    cout << "Enter " << n << " values: ";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
        cout << "Inserted " << val << endl;
    }
    
    cout << "\nTree Traversals:" << endl;
    tree.printInorder();
    tree.printPreorder();
    tree.printPostorder();
    
    cout << "\nSearch for values:" << endl;
    cout << "Enter value to search (or -1 to exit): ";
    int searchVal;
    while(cin >> searchVal && searchVal != -1) {
        if(tree.search(searchVal)) {
            cout << "Value " << searchVal << " found in the tree!" << endl;
        } else {
            cout << "Value " << searchVal << " not found in the tree." << endl;
        }
        cout << "Enter another value to search (or -1 to exit): ";
    }
    
    return 0;
}