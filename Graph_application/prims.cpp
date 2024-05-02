#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;

class Graph {
    struct Node {
        char vertex;
        int weight;
        Node* next;
        Node(char v, int w) : vertex(v), weight(w), next(nullptr) {}
    };

    Node* adjList[MAX_VERTICES];

public:
    Graph() {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            adjList[i] = nullptr;
        }
    }

    void addEdge(char u, char v, int w) {
        Node* node1 = new Node(v, w);
        node1->next = adjList[u - 'a'];
        adjList[u - 'a'] = node1;

        Node* node2 = new Node(u, w);
        node2->next = adjList[v - 'a'];
        adjList[v - 'a'] = node2;
    }

    void findMST(int vertCount, char source) {
        int key[MAX_VERTICES];
        int parent[MAX_VERTICES];
        bool visited[MAX_VERTICES] = {false};

        for (int i = 0; i < vertCount; ++i) {
            key[i] = INT_MAX;
            parent[i] = -1;
        }

        key[source - 'a'] = 0;

        for (int i = 0; i < vertCount - 1; ++i) {
            char u;
            int minKey = INT_MAX;

            for (int j = 0; j < vertCount; ++j) {
                if (!visited[j] && key[j] < minKey) {
                    u = j + 'a';
                    minKey = key[j];
                }
            }

            visited[u - 'a'] = true;
            Node* current = adjList[u - 'a'];

            while (current != nullptr) {
                char v = current->vertex;
                int weight = current->weight;

                if (!visited[v - 'a'] && weight < key[v - 'a']) {
                    parent[v - 'a'] = u - 'a';
                    key[v - 'a'] = weight;
                }

                current = current->next;
            }
        }

        int totalCost = 0;
        cout << "Minimum Spanning Tree (MST):" << endl;
        for (int i = 0; i < vertCount; ++i) {
            if (parent[i] != -1) {
                cout << char('a' + parent[i]) << " - " << char('a' + i) << " (" << key[i] << ")" << endl;
                totalCost += key[i];
            }
        }
        cout << "Total cost: " << totalCost << endl;
    }
};

int main() {
    Graph graph;
    int vertCount, edgeCount, weight;

    cout << "Enter the number of vertices: ";
    cin >> vertCount;

    cout << "Enter the number of edges: ";
    cin >> edgeCount;

    char u, v;
    for (int i = 0; i < edgeCount; i++) {
        cout << "Enter edge " << i + 1 << " (format: u v weight): ";
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    char source;
    cout << "Enter the source vertex: ";
    cin >> source;

    graph.findMST(vertCount, source);

    return 0;
}
