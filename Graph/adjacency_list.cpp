#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<char,list<char>> g;
    void add_edge(char u,char v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void display(){
        for(auto it: g){
            cout<<it.first<<"->";
            for(auto it2:g[it.first]){
                cout<<it2<<"-> ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g;
    char u,v;
    int edge;
    cout<<"Enter the number of edges:"<<endl;
    cin>>edge;
    for(int i=0;i<edge;i++){
        cin>>u;
        cin>>v;
        g.add_edge(u,v);
    }
    g.display();
}

