#include <iostream>
#include <queue>

using namespace std;

void BFS(int start, int adj[10][10], int vert) {
    queue<int> q;
    int visited[10] = {0}; // Initialize the visited array

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int j = 0; j < vert; j++) {
            if (adj[node][j] == 1 && visited[j] == 0) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    int vert;
    cin >> vert;

    int adj[10][10] = {0}; // Initialize the adjacency matrix with 0

    cout << "Enter the number of edges: ";
    int edges;
    cin >> edges;

    cout << "Enter the edges (start end):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Set the adjacency matrix
        adj[v][u] = 1; // For undirected graph, set both ways
    }

    // Print the adjacency matrix
    cout << "\nAdjacency matrix:" << endl;
    for (int i = 0; i < vert; i++) {
        cout << "v" << i << ": ";
        for (int j = 0; j < vert; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nBFS starting from vertex 0: ";
    BFS(0, adj, vert);
    cout << endl;

    return 0;
}
