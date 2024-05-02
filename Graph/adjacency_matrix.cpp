#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number of vertices: "<<endl;
    int vert;
    cin>>vert;
    int adj[10][10];

    int u, v;
    cout<<"Enter the number of edges: "<<endl;
    int  edges;
    cin>>edges;
    for(int i=0;i<vert;i++){
        for(int j = 0;j<vert;j++){
            adj[i][j]=0;;
        }
    }
    for(int i = 0;i<edges;i++){
        cin>>u;
        cin>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=0;i<vert;i++){
        cout<<"v"<<i<<"  ";
    }cout<<endl;
    for(int i=0;i<vert;i++){
        cout<<"v"<<i<<" ";
        for(int j = 0;j<vert;j++){
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    

}