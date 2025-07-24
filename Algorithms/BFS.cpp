#include <bits/stdc++.h>
using namespace std;


bool bfs(unordered_map<int, vector<int>> adj_arr, int n, int start) {

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
        
        for(auto i: adj_arr[current]) {
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


    unordered_map<int, vector<int>> graph;
    
    graph[1] = {2, 6};
    graph[2] = {3, 4};
    graph[3] = {};
    graph[4] = {5};
    graph[5] = {8};
    graph[6] = {7,9};
    graph[7] = {8};
    graph[8] = {5};
    graph[9] = {};

    int start = 1;
    bfs(graph, 9, start);
    return 0;
}