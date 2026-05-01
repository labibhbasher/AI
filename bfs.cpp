#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, start;

    cout << "Enter number of nodes: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int visited[10] = {0};
    queue<int> q;

    cout << "Enter starting node: ";
    cin >> start;

    q.push(start);
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i = 0; i < n; i++) {
            if(graph[node][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}