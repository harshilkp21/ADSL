#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right; 
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree() {
    cout<<"Enter the data (-1 for NULL): ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    node* root = new node(data);
    cout<<"Enter the left child of "<<data<<": ";
    root->left = buildtree();
    cout<<"Enter the right child of "<<data<<": ";
    root->right = buildtree();
    return root;
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void printLeaves(node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

node* mirror(node* root) {
    if (root == NULL) {
        return NULL;
    }
    node* mirroredRoot = new node(root->data);
    mirroredRoot->left = mirror(root->right);
    mirroredRoot->right = mirror(root->left);
    return mirroredRoot;
}

void levelordertraversal(node* root) {
    if (root == NULL) {
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

int main() {
    // Create binary tree
    node* root = buildtree();

    // Find height of the tree
    cout << "Height of the tree: " << height(root) << endl;

    // Print leaf nodes
    cout << "Leaf nodes: ";
    printLeaves(root);
    cout << endl;

    // Find mirror image of the tree
    node* mirrorRoot = mirror(root);

    // Print original tree level-wise
    cout << "Original tree level-wise:" << endl;
    levelordertraversal(root);

    // Print mirror tree level-wise
    cout << "Mirror tree level-wise:" << endl;
    levelordertraversal(mirrorRoot);

    return 0;
}
