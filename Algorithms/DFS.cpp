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
    dfs(graph, 9, start);
    return 0;
}