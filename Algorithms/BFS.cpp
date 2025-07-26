#include <bits/stdc++.h>
using namespace std;


bool bfs(unordered_map<int, vector<int>> graph, int n, int start) {

    unordered_map<int, bool> visited;
    queue<int> q;
    vector<int> result;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int current=q.front();
        q.pop();
        result.push_back(current);
        
        for(auto i: graph[current]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }

    }
    for (auto i : result) {
        cout << i << " ";
    };
}

int main() {
    cout << "=== BFS (Breadth-First Search) ===" << endl;
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    
    unordered_map<int, vector<int>> graph;
    
    cout << "Enter number of edges: ";
    int edges;
    cin >> edges;
    
    cout << "Enter edges (format: from to):" << endl;
    for(int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    
    cout << "Enter starting node: ";
    int start;
    cin >> start;
    
    cout << "BFS traversal starting from node " << start << ": ";
    bfs(graph, n, start);
    cout << endl;
    
    return 0;
}