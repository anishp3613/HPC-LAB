#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

// ---------------- PARALLEL BFS ----------------
void parallelBFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node;

        #pragma omp critical
        {
            node = q.front();
            q.pop();
            cout << node << " ";
        }

        #pragma omp parallel for
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];

            #pragma omp critical
            {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
}

// ---------------- PARALLEL DFS ----------------
void parallelDFS(vector<vector<int>>& graph, int node, vector<bool>& visited) {

    if (visited[node])
        return;

    #pragma omp critical
    {
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];

        if (!visited[neighbor]) {
            parallelDFS(graph, neighbor, visited);
        }
    }
}

// ---------------- MAIN FUNCTION ----------------
int main() {

    int n = 5;
    vector<vector<int>> graph(n);

    // Undirected Graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    double start_time, end_time;

    // -------- BFS --------
    start_time = omp_get_wtime();
    parallelBFS(graph, 0);
    end_time = omp_get_wtime();

    cout << "\nBFS Execution Time: " << end_time - start_time << " seconds\n\n";

    // -------- DFS --------
    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    start_time = omp_get_wtime();
    parallelDFS(graph, 0, visited);
    end_time = omp_get_wtime();

    cout << "\nDFS Execution Time: " << end_time - start_time << " seconds\n";

    return 0;
}
