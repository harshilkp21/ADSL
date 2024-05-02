#include <iostream>
#include <queue>
using namespace std;

struct TBTNode
{
    int data;
    TBTNode *left;
    TBTNode *right;
    bool leftThread;
    bool rightThread;
};

class TBT
{
    TBTNode *root;
    TBTNode *dummyNode;

public:
    TBT()
    {
        root = nullptr;
    }

    TBTNode *createTBTNode()
    {
        TBTNode *newTBTNode = new TBTNode();
        newTBTNode->left = newTBTNode->right = nullptr;
        newTBTNode->leftThread = newTBTNode->rightThread = true;
        cout << "\nEnter Data: ";
        cin >> newTBTNode->data;
        return newTBTNode;
    }

    void create() //Create Tree
    {
        TBTNode *newNode;
        newNode = createTBTNode();
        if (root == nullptr)
        {
            root = newNode;
            dummyNode = new TBTNode();
            dummyNode->data = -999;
            dummyNode->left = root;
            dummyNode->right = dummyNode;
            dummyNode->leftThread = dummyNode->rightThread = true;
            root->left = root->right = dummyNode;
        }
        else
            insert(root, newNode);
    }

    void insert(TBTNode *root, TBTNode *newNode)
    {
        if (newNode->data < root->data) // Left Subtree
        {
            if (root->leftThread == true)
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = newNode;
                root->leftThread = false;
            }
            else
                insert(root->left, newNode);
        }
        else if (newNode->data >= root->data) // Right Subtree
        {
            if (root->rightThread == true)
            {
                newNode->right = root->right;
                newNode->left = root;
                root->rightThread = false;
                root->right = newNode;
            }
            else
                insert(root->right, newNode);
        }
    }

    void inOrder(TBTNode *temp, TBTNode *dummyNode) //Inorder display  (root, headerNode)
    {
        while (temp != dummyNode)
        {
            while (temp->leftThread == false) // Left Subtree
            {
                temp = temp->left;
            }
            cout << " " << temp->data; // Print Data
            while (temp->rightThread == true) // Right Subtree
            {
                temp = temp->right;
                if (temp == dummyNode)
                    return;
                cout << " " << temp->data;
            }
            temp = temp->right;
        }
    }

    void preOrder(TBTNode *temp, TBTNode *dummyNode) // Preorder traversal
    {
        while (temp != dummyNode)
        {
            cout << " " << temp->data;
            if (temp->leftThread == false)
                preOrder(temp->left, dummyNode);
            temp = temp->right;
        }
    }

    void postOrder(TBTNode *temp, TBTNode *dummyNode) // Postorder traversal
    {
        if (temp != dummyNode)
        {
            if (temp->leftThread == false)
                postOrder(temp->left, dummyNode);
            if (temp->rightThread == false)
                postOrder(temp->right, dummyNode);
            cout << " " << temp->data;
        }
    }
};

int main()
{
    TBT tree;
    int choice;
    do
    {
        cout << "\n\nThreaded Binary Search Tree\n1. Insert 2. Inorder Display 3. Preorder Display 4. Postorder Display 5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            tree.create();
            break;
        case 2:
            cout << "\nInorder BST: ";
            tree.inOrder(tree.root, tree.dummyNode);
            cout << endl;
            break;
        case 3:
            cout << "\nPreorder BST: ";
            tree.preOrder(tree.root, tree.dummyNode);
            cout << endl;
            break;
        case 4:
            cout << "\nPostorder BST: ";
            tree.postOrder(tree.root, tree.dummyNode);
            cout << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Enter Proper Input" << endl;
        }
    } while (choice != 5);

    return 0;
}
