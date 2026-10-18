#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS using recursion
void DFS(int node, vector<int> graph[], bool visited[]) {

    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            DFS(next, graph, visited);
        }
    }
}

// BFS using queue
void BFS(int start, vector<int> graph[], int n) {

    bool visited[10] = {false};

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {

    int n = 6;

    vector<int> graph[10];

    // Creating the graph
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(0);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[4].push_back(1);
    graph[5].push_back(2);

    bool visited[10] = {false};

    cout << "DFS Traversal: ";
    DFS(0, graph, visited);

    cout << endl;

    cout << "BFS Traversal: ";
    BFS(0, graph, n);

    return 0;
}