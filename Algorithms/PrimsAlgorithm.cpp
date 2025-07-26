#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int, int> nodeInfo;

vector<pair<int,int>> primsAlgorithm(int n, unordered_map<int, vector<pair<int,int>>> &graph, int start) {

    vector<pair<int,int>> mst;
    priority_queue<nodeInfo, vector<nodeInfo>, greater<nodeInfo>> pq;
    vector<bool> visited(n, false);

    pq.push(make_tuple(0, start, -1)); // {weight, current_node, parent_node}

    while (!pq.empty())
    {
        nodeInfo top = pq.top();
        pq.pop();
        
        int weight = get<0>(top);
        int current = get<1>(top);
        int parent = get<2>(top);
        
        if(visited[current]) 
            continue;
        
        visited[current] = true; 
        
        if (parent != -1) {
            mst.push_back(make_pair(parent, current)); 
        }
        for(auto it: graph[current])
        {
            if(visited[it.first]) 
                continue; 
            pq.push(make_tuple(it.second, it.first, current)); // {weight, child_node, parent_node}

        }

    }
    

    return mst;
}

int main() {
    cout << "=== Prim's Algorithm for Minimum Spanning Tree ===" << endl;
    cout << "Enter number of vertices: ";
    int n;
    cin >> n;
    
    unordered_map<int, vector<pair<int,int>>> graph;
    
    cout << "Enter number of edges: ";
    int edges;
    cin >> edges;
    
    cout << "Enter edges (format: from to weight):" << endl;
    for(int i = 0; i < edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        // Since MST works on undirected graphs, add both directions
        graph[from].push_back(make_pair(to, weight));
        graph[to].push_back(make_pair(from, weight));
    }
    
    cout << "Enter starting vertex: ";
    int start;
    cin >> start;
    
    vector<pair<int,int>> mst = primsAlgorithm(n, graph, start);
    
    cout << "\nMinimum Spanning Tree edges:" << endl;
    cout << "Edge\t\tWeight" << endl;
    cout << "----\t\t------" << endl;
    
    int totalWeight = 0;
    for(int i = 0; i < mst.size(); i++) {
        // Find the weight of this edge
        int u = mst[i].first;
        int v = mst[i].second;
        int weight = 0;
        
        // Search for the weight in the adjacency list
        for(auto edge : graph[u]) {
            if(edge.first == v) {
                weight = edge.second;
                break;
            }
        }
        
        cout << u << " - " << v << "\t\t" << weight << endl;
        totalWeight += weight;
    }
    
    cout << "Total Weight: " << totalWeight << endl;
    cout << "Total edges in MST: " << mst.size() << endl;
    
    return 0;
}