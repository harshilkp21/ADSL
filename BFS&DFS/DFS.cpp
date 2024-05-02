#include <iostream>
#include <stack>

using namespace std;

void DFS(int start, int adj[10][10], int vert) {
    stack<int> st;
    int visited[10] = {0}; // Initialize the visited array

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        // Only process the node if it has not been visited yet
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = 1;

            // Process the neighbors of the current node
            for (int j = 0; j < vert; j++) {
                if (adj[node][j] == 1 && !visited[j]) {
                    st.push(j);
                }
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

    cout << "\nDFS starting from vertex 0: ";
    DFS(0, adj, vert);
    cout << endl;

    return 0;
}
