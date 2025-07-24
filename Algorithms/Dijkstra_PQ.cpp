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