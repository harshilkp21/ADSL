#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->data) {
            node->left = insertNode(node->left, key);
        } else if (key > node->data) {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    // Recursive function to print leaf nodes of the BST
    void printLeafNodes(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        }

        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void inorderTraversal() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    int getHeight() {
        return height(root);
    }

    // Public function to print leaf nodes
    void printLeafNodes() {
        cout << "Leaf nodes: ";
        printLeafNodes(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int n, x;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values of nodes: ";

    for (int i = 0; i < n; ++i) {
        cin >> x;
        bst.insert(x);
    }

    bst.inorderTraversal();
    cout << "Height: " << bst.getHeight() << endl;
    bst.printLeafNodes();  // Call the function to print leaf nodes

    return 0;
}
