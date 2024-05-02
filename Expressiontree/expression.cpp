#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    
    Node(char data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* createPrefixTree() {
    cout << "Enter the prefix expression: " << endl;
    string pre;
    cin >> pre;
    
    stack<Node*> st;
    for (int i = pre.length() - 1; i >= 0; --i) {
        Node* temp = new Node(pre[i]);
        if (!isalnum(pre[i])) {
            temp->left = st.top();
            st.pop();
            temp->right = st.top();
            st.pop();
        }
        st.push(temp);
    }
    return st.top();
}

Node* createPostfixTree() {
    cout << "Enter the postfix expression: " << endl;
    string post;
    cin >> post;
    
    stack<Node*> st;
    for (int i = 0; i < post.length(); ++i) {
        Node* temp = new Node(post[i]);
        if (!isalnum(post[i])) {
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
        }
        st.push(temp);
    }
    return st.top();
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root;

    root = createPostfixTree();
    cout << "Inorder traversal of the postfix expression tree: ";
    inorderTraversal(root);
    cout << endl;

    root = createPrefixTree();
    cout << "Inorder traversal of the prefix expression tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
