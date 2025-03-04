#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's Algorithm function
void dijkstra(vector<vector<int>>& graph, int source, int N) {
    vector<int> distance(N, INT_MAX);  // Distance to each node initialized to infinity
    distance[source] = 0;  // Distance to source node is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});  // {distance, node}

    vector<bool> visited(N, false);  // Track visited nodes

    while (!pq.empty()) {
        int u = pq.top().second;  // Node with the smallest distance
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // Relax all edges from node u
        for (int v = 0; v < N; v++) {
            if (graph[u][v] > 0) {  // There is an edge from u to v
                if (distance[v] > distance[u] + graph[u][v]) {
                    distance[v] = distance[u] + graph[u][v];
                    pq.push({distance[v], v});
                }
            }
        }
    }

    // Output shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < N; i++) {
        if (distance[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << distance[i] << "\n";
    }
}

// Main function
int main() {
    int N;
    cout << "Enter the number of nodes: ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter the source node (0 to " << N-1 << "): ";
    cin >> source;

    dijkstra(graph, source, N);

    return 0;
}
