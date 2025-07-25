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
    cout << "Starting Prim's Algorithm..." << endl;

    unordered_map<int, vector<pair<int,int>>> graph;

    // Manually add edges to avoid braced initialization issues (GPT)
    graph[0].push_back(make_pair(1, 4));
    graph[0].push_back(make_pair(2, 1));
    
    graph[1].push_back(make_pair(0, 4));
    graph[1].push_back(make_pair(2, 2));
    graph[1].push_back(make_pair(3, 5));
    graph[1].push_back(make_pair(4, 3));
    
    graph[2].push_back(make_pair(0, 1));
    graph[2].push_back(make_pair(1, 2));
    graph[2].push_back(make_pair(3, 8));
    graph[2].push_back(make_pair(4, 6));
    
    graph[3].push_back(make_pair(1, 5));
    graph[3].push_back(make_pair(2, 8));
    
    graph[4].push_back(make_pair(1, 3));
    graph[4].push_back(make_pair(2, 6));


    vector<pair<int,int>> mst = primsAlgorithm(5, graph, 0);
    cout << "Minimum Spanning Tree edges:" << endl;
    for(int i = 0; i < mst.size(); i++) {
        cout << "Edge: " << mst[i].first << " - " << mst[i].second << endl;
    }
    cout << "Total edges in MST: " << mst.size() << endl;
    return 0;
}