#include <bits/stdc++.h>
using namespace std;



bool dfs(unordered_map<int, vector<int>> graph, int n, int start) {

    unordered_map<int, bool> visited;
    stack<int> s;
    vector<int> result;
    visited[start] = true;
    s.push(start);
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        result.push_back(current);
        
        for(auto i: graph[current]) {
            if (!visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
    for (auto i : result) {
        cout << i << " ";
    };
}

int main() {
    cout << "=== DFS (Depth-First Search) ===" << endl;
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
    
    cout << "DFS traversal starting from node " << start << ": ";
    dfs(graph, n, start);
    cout << endl;
    
    return 0;
}