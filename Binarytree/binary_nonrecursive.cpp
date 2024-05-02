#include <iostream>
#include <stack>
using namespace std;

class Node 
{
public:
    int data;
    Node *left, *right;
    Node(int x) 
    {
        data = x;
        left = right = NULL;
    }
};

class Tree {
public:
    Node *createtree(int a) 
    {
        if (a == -1) 
        {
            return NULL;
        }
        Node *temp = new Node(a);
        int d;
        cout << "Enter the left child of " << a << ": ";
        cin >> d;
        temp->left = createtree(d);
        cout << "Enter the right child of " << a << ": ";
        cin >> d;
        temp->right = createtree(d);
        return temp;
    }

    void inorder(Node *temp) 
    {
        stack<Node *> s;
        Node *curr = temp;
        while (curr != NULL || !s.empty()) 
        {
            while (curr != NULL) 
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void preorder(Node *temp) 
    {
        stack<Node *> s;
        s.push(temp);
        while (!s.empty()) 
        {
            Node *curr = s.top();
            s.pop();
            cout << curr->data << " ";
            if (curr->right != NULL) 
            {
                s.push(curr->right);
            }
            if (curr->left != NULL) 
            {
                s.push(curr->left);
            }
        }
    }

    void postorder(Node *temp) 
    {
        stack<Node *> s1, s2;
        s1.push(temp);
        while (!s1.empty()) 
        {
            Node *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left != NULL) 
            {
                s1.push(curr->left);
            }
            if (curr->right != NULL) 
            {
                s1.push(curr->right);
            }
        }
        while (!s2.empty()) 
        {
            cout << s2.top()->data << " ";
            s2.pop();   
        }
    }
};

int main() 
{
    int d;
    cout << "Enter the root node: ";
    cin >> d;
    Tree t1;
    Node *root;
    root = t1.createtree(d);
    cout << endl << endl;

    cout << "Inorder traversal: ";
    t1.inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    t1.preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    t1.postorder(root);
}