#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    int findMin() {
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    int findMax() {
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }
};

int main() {
    BST bst;
    cout << "Enter the data for the BST (enter -1 to stop): ";
    int data;
    while (cin >> data && data != -1) {
        bst.insert(data);
    }

    cout << "Minimum value in the BST: " << bst.findMin() << endl;
    cout << "Maximum value in the BST: " << bst.findMax() << endl;

    return 0;
}
