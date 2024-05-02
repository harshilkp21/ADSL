#include <iostream>
#include <set>
#include <vector>
#include <limits.h>

using namespace std;

void dijkstras(int start, int adj[10][10], int vert) {
    set<pair<int, int>> st;
    vector<int> dist(vert, INT_MAX);

    dist[start] = 0;
    st.insert({0, start});

    while (!st.empty()) {
        auto temp = *(st.begin());
        int distOfNode = temp.first;
        int node = temp.second;
        st.erase(st.begin());

        for (int j = 0; j < vert; j++) {
            if (adj[node][j] != 0) {
                int currentDist = dist[j];
                int weight = adj[node][j];
                
                if (distOfNode + weight < currentDist) {
                    dist[j] = distOfNode + weight;
                    
                    st.erase({currentDist, j});
                    st.insert({dist[j], j});
                }
            }
        }
    }

    for (int i = 0; i < vert; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of vertices: ";
    int vert;
    cin >> vert;

    int adj[10][10] = {0};

    cout << "Enter the number of edges: ";
    int edges;
    cin >> edges;

    cout << "Enter the edges (start, end, weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    cout << "\nAdjacency matrix:" << endl;
    for (int i = 0; i < vert; i++) {
        cout << "v" << i << ": ";
        for (int j = 0; j < vert; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nShortest distances from node 0 using Dijkstra's algorithm:" << endl;
    dijkstras(0, adj, vert);

    return 0;
}
