#include<bits/stdc++.h>
using namespace std;



vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int StartNode)
{   
    set<pair<int,int>> s;
    vector<int> distances(V, 1e9);

    s.insert({0, StartNode});
    distances[StartNode] = 0;

    while(!s.empty())
    {
        auto it = *(s.begin());
        s.erase(it);
        
        int dis = it.first;
        int node = it.second;

        for (auto neighbor : adj[node]) // access all the neighbors of the current node
        {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (dis + edgeWeight < distances[adjNode]) {
                // If the node is already in the set, remove it before updating
                // Otherwise, it will not update the distance correctly
                if (distances[adjNode] != 1e9) {
                    s.erase({distances[adjNode], adjNode});
                }
                distances[adjNode] = dis + edgeWeight;
                s.insert({distances[adjNode], adjNode});
            }
        }
    }
}

int main() {
    int V = 5;
    vector<pair<int,int>> adj[V];
    int StartNode = 0;
    // Example graph represented as an adjacency list
    // each index in adj represents a node
    // and the pairs represent the connected nodes and their respective weights
    adj[0] = {{1, 10}, {2, 3}};
    adj[1] = {{2, 1}, {3, 2}};
    adj[2] = {{1, 4}, {3, 8}, {4, 2}};
    adj[3] = {{4, 7}};
    adj[4] = {{3, 9}};
    for (int i = 0; i < V; i++) {
        for (auto &edge : adj[i]) {
            cout << "Node " << i << " is connected to node " << edge.first << " with weight " << edge.second << endl;
        }
    }
    vector<int> distances = dijkstra(V, adj, StartNode);
    for (int i = 0; i < V; i++) {
        cout << "Distance from source " << StartNode << " to node " << i << " is " << distances[i] << endl;
    }
    return 0;
}