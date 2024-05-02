#include <iostream>

using namespace std;

int main() {
    int maxSize;
    cout << "Enter the maximum size of the hash table: ";
    cin >> maxSize;

    int *keys = new int[maxSize]; 
    
    for (int i = 0; i < maxSize; ++i) 
    {
        keys[i] = -1; 
    }

    cout << "Enter key values (-1 to stop):" << endl;
    int key;

    while (cin >> key && key != -1) 
    {
        int index = key % maxSize;

        if (keys[index] == -1) 
        {
            keys[index] = key;
        }

        else 
        {            
            int i = (index + 1) % maxSize;
            while (i != index) 
            {
                if (keys[i] == -1) 
                {
                    keys[i] = key;
                    break;
                }
                i = (i + 1) % maxSize;
            }
            if (i == index) 
            {
                cout << "Hash table is full, cannot insert key " << key << endl;
            }
        }
    }

    cout << "Hash Table:" << endl;

    for (int i = 0; i < maxSize; ++i) 
    {
        cout << "Index: " << i << ", Key: ";

        if (keys[i] != -1) 
        {
            cout << keys[i];
        } 

        else 
        {
            cout << "-1";
        }
        cout << endl;
    }

    delete[] keys;

    return 0;
}
