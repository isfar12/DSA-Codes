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
        void preorder(Node *node)
        {
            if (node == nullptr) {
                return;
            }
            cout << node->data << " "; // Visit the root
            preorder(node->left);       // Traverse left subtree
            preorder(node->right);      // Traverse right subtree
        }

    public:
        BinaryTree() {
            root = nullptr;
        }
        void insert(int val) {
            root = insert(root, val);
        }
        void Printpreorder() {
            preorder(root);
        }



};

int main() {

    int values[] = {44, 30, 50, 22, 60, 55, 77, 57};

    BinaryTree tree;
    // Build tree from the sequence
    for (int val : values) {
        tree.insert(val);
    }
    tree.Printpreorder(); // Perform preorder traversal

    return 0;
}