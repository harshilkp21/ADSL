#include<iostream>
using namespace std;
//with repalcement
class Hashtable{
    pair<int,int> arr[10];
    public:
    Hashtable(){
        for(int i=0;i<10;i++){
            arr[i]=make_pair(-1,0);
        }
    }
    int hashfunc(int key){
        return key%10;
    }
    void insert(int key){
        int pos=hashfunc(key);
        int probe=1;
        if(arr[pos].first==-1){
            arr[pos].first=key;
            arr[pos].second=probe;
        }
        else{
            int key2=arr[pos].first;
            if(hashfunc(key2)!=pos){
                    probe=arr[pos].second;

                for(int i=pos+1;i%10!=pos;i++){
                    
                    probe++;
                    if(arr[i].first==-1){
                        arr[i].first=key2;
                        arr[i].second=probe;
                        arr[pos].first=key;
                        arr[pos].second=1;
                        return ;
                    }
                }
            }
            else{
                for(int i=pos+1;i%10!=pos;i++){
                probe++;
                if(arr[i].first==-1){
                arr[i].first=key;
                arr[i].second=probe;
                return ;
                }
                }
            }
            
            cout<<"HashTable Full";
        }
    }
    void display(){
        cout<<"index  key  probe "<<endl;
        for(int i=0;i<10;i++){
            cout<<i<<"       "<<arr[i].first<<"     "<<arr[i].second<<endl;
        }
    }
};
int main(){
    Hashtable h1;
    int key;
    while(cin>>key){
        if(key==-1)
        {
            break;
        }
        h1.insert(key);
    }
    cout<<"This Hash Table is Given Below: "<<endl;
    h1.display();
}