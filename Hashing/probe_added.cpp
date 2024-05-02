#include<iostream>
using namespace std;

int main()
{
    int maxsize;
    cout<<"Enter the maximum size of the hash table: ";
    cin>>maxsize;

    int keys[maxsize];
    int probe[maxsize];
    for(int i = 0; i < maxsize; ++i)
    {
        keys[i] = -1;
        probe[i] = 0;
    }

    cout<<"Enter the keyvalues (-1 to stop): "<<endl;
    int key;

    while(cin >> key && key != -1)
    {
        
        int index = key % maxsize;
        if(keys[index] == -1)
        {
            keys[index] = key;
            probe[index] = 1;
        }

        else
        {
            int i = (index + 1) % maxsize;
            probe[i] = probe[index];
            while(i != index)
            {
                if(keys[i] == -1)
                {
                    keys[i] = key;
                    probe[i]++;
                    break;
                }
                i = (i + 1) % maxsize;
            }
            if(i == index)
            {
                cout<<"Hash table is Full cannot insert key "<<key<<" :"<<endl;
            } 
        }
    }

    cout << "Hash table: "<<endl;

    for(int i = 0; i < maxsize; ++i)
    {
        cout<<"Index :"<<i<<", key : ";
        if(keys[i] != -1)
        {
            cout<<keys[i];
        }
        else
        {
            cout<<"-1";
        }
        cout<<" ,Probe: "<<probe[i];
        cout<<endl;
    }

    return 0;
}