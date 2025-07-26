#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int StartNode)
{   
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> distances(V, INT_MAX);

    distances[StartNode] = 0;
    pq.push({0, StartNode});

    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        
        pq.pop();

        for (auto it: adj[node]) // access all the neighbors of the current node
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < distances[adjNode]) {
                distances[adjNode] = dis + edgeWeight;
                pq.push({distances[adjNode], adjNode});
            }
        }
    }
    return distances;
 }
int main() {
    cout << "=== Dijkstra's Shortest Path Algorithm ===" << endl;
    cout << "Enter number of vertices: ";
    int V;
    cin >> V;
    
    vector<pair<int,int>> adj[V];
    
    cout << "Enter number of edges: ";
    int edges;
    cin >> edges;
    
    cout << "Enter edges (format: from to weight):" << endl;
    for(int i = 0; i < edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back(make_pair(to, weight));
        // For undirected graph, uncomment the next line:
        // adj[to].push_back(make_pair(from, weight));
    }
    
    cout << "Enter starting node: ";
    int StartNode;
    cin >> StartNode;
    
    cout << "\nGraph representation:" << endl;
    for (int i = 0; i < V; i++) {
        for (auto &edge : adj[i]) {
            cout << "Node " << i << " is connected to node " << edge.first << " with weight " << edge.second << endl;
        }
    }
    
    vector<int> distances = dijkstra(V, adj, StartNode);
    
    cout << "\nShortest distances from source " << StartNode << ":" << endl;
    for (int i = 0; i < V; i++) {
        if(distances[i] == INT_MAX) {
            cout << "Distance to node " << i << " is INFINITY (unreachable)" << endl;
        } else {
            cout << "Distance to node " << i << " is " << distances[i] << endl;
        }
    }
    return 0;
}