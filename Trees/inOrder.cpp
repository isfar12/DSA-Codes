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
        void inorder(Node *node)
        {
            if (node == nullptr) {
                return;
            }
            inorder(node->left);         // Traverse left subtree
            cout << node->data << " ";  // Visit the root
            inorder(node->right);        // Traverse right subtree
        }
    public:
        BinaryTree() {
            root = nullptr;
        }
        void insert(int val) {
            root = insert(root, val);
        }
        void Printinorder() {
            inorder(root);
        }



};

int main() {

    int values[] = {44, 30, 50, 22, 60, 55, 77, 57};

    BinaryTree tree;
    // Build tree from the sequence
    for (int val : values) {
        tree.insert(val);
    }
    tree.Printinorder(); // Perform preorder traversal

    return 0;
}