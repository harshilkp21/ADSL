#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VERTICES = 20;

struct Edge {
    int weight;
    char u;
    char v;

    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
public:
    vector<char> parent;
    vector<int> rank;

    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i + 'a';
        }
    }

    char find(char u) {
        if (parent[u - 'a'] != u) {
            parent[u - 'a'] = find(parent[u - 'a']);
        }
        return parent[u - 'a'];
    }

    void unionSet(char u, char v) {
        char rootU = find(u);
        char rootV = find(v);

        if (rootU == rootV) return;

        if (rank[rootU - 'a'] < rank[rootV - 'a']) {
            parent[rootU - 'a'] = rootV;
        } else if (rank[rootV - 'a'] < rank[rootU - 'a']) {
            parent[rootV - 'a'] = rootU;
        } else {
            parent[rootV - 'a'] = rootU;
            rank[rootU - 'a']++;
        }
    }
};

int main() {
    int vert, edges;
    cin >> vert >> edges;

    vector<Edge> edgeList(edges);

    for (int i = 0; i < edges; i++) {
        cin >> edgeList[i].u >> edgeList[i].v >> edgeList[i].weight;
    }

    sort(edgeList.begin(), edgeList.end());

    DisjointSet ds(vert);

    int mstWeight = 0;
    for (const auto &edge : edgeList) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unionSet(edge.u, edge.v);
            cout << edge.u << " - " << edge.v << " (" << edge.weight << ")" << endl;
            mstWeight += edge.weight;
        }
    }

    cout << "Minimum cost: " << mstWeight << endl;
    return 0;
}
