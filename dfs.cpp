#include <iostream>
using namespace std;

int n;
int graph[10][10];
int visited[10];

void dfs(int node) {
    cout << node << " ";
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int start;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);

    return 0;
}