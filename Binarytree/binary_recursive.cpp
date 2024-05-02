#include<iostream>
using namespace std;

class Node
{
    public: 
        int data;
        Node *left,*right;
        Node(int x)
        {
            data = x;
            left = right = NULL; 
        }
};

class Tree
{
    public:
        Node *createtree(int a)
        {
            if(a == -1)
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
            if(temp != NULL)
            {
                inorder(temp->left);
                cout << temp->data << " ";
                inorder(temp->right);
            }
        }

        void preorder(Node *temp)
        {
            if(temp != NULL)
            {
                cout << temp->data << " ";
                preorder(temp->left);
                preorder(temp->right);
            }
        }

        void postorder(Node *temp)    
        {
            if(temp != NULL)
            {
                postorder(temp->left);
                postorder(temp->right);
                cout << temp->data << " ";
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

    // Perform inorder traversal
    cout << "Inorder traversal: ";
    t1.inorder(root);
    cout << endl;
    
    // Perform preorder traversal
    cout << "Preorder traversal: ";
    t1.preorder(root);
    cout << endl;
    
    // Perform postorder traversal
    cout << "Postorder traversal: ";
    t1.postorder(root);
}
