#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int s, d, wt;
};

void bellmanFord(int n, int m, vector<Edge>& edges, int s) {
    vector<int> distance(n, INT_MAX);
    distance[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.s;
            int v = edge.d;
            int w = edge.wt;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge.s;
        int v = edge.d;
        int w = edge.wt;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Negative cycle detected" << endl;
            return;
        }
    }

    cout << "Shortest distances from source node:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int n, m;
    cout<<"Enter the value of total node and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout<<"Enter the value of edges: ";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int s = 0;
    bellmanFord(n, m, edges, s);

    return 0;
}

