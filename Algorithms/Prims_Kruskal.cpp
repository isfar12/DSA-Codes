#include <bits/stdc++.h>
using namespace std;

// Edge structure for Kruskal's algorithm
struct Edge {
    int src, dest, weight;
    
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Comparator for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find (Disjoint Set) class for Kruskal's algorithm
class UnionFind {
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; // Already in same set
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Prim's Algorithm
vector<Edge> primsAlgorithm(int n, vector<vector<pair<int, int>>>& graph, int start) {
    vector<Edge> mst;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<bool> visited(n, false);
    
    // Start with the given node
    pq.push(make_tuple(0, start, -1)); // {weight, current_node, parent_node}
    
    while (!pq.empty()) {
        tuple<int, int, int> top = pq.top();
        pq.pop();
        
        int weight = get<0>(top);
        int current = get<1>(top);
        int parent = get<2>(top);
        
        if (visited[current]) continue; // Skip if already visited
        
        visited[current] = true; // Mark current node as visited
        
        if (parent != -1) {
            mst.push_back(Edge(parent, current, weight)); // Add edge to MST
        }
        
        // Add all adjacent edges to priority queue
        for (auto& edge : graph[current]) {
            int neighbor = edge.first;
            int edgeWeight = edge.second;
            
            if (!visited[neighbor]) {
                pq.push(make_tuple(edgeWeight, neighbor, current));
            }
        }
    }
    
    return mst;
}

// Kruskal's Algorithm
vector<Edge> kruskalsAlgorithm(int n, vector<Edge>& edges) {
    vector<Edge> mst;
    
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);
    
    UnionFind uf(n);
    
    for (const Edge& edge : edges) {
        // If adding this edge doesn't create a cycle
        if (uf.unionSets(edge.src, edge.dest)) {
            mst.push_back(edge);
            
            // MST will have n-1 edges
            if (mst.size() == n - 1) break;
        }
    }
    
    return mst;
}

// Utility function to print MST
void printMST(const vector<Edge>& mst, const string& algorithmName) {
    cout << "\n" << algorithmName << " - Minimum Spanning Tree:" << endl;
    cout << "Edge\t\tWeight" << endl;
    cout << "----\t\t------" << endl;
    
    int totalWeight = 0;
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << "\t\t" << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
}

int main() {
    cout << "Implementing Prim's and Kruskal's Algorithms for MST" << endl;
    cout << "====================================================" << endl;
    
    int n = 5; // Number of vertices (0 to 4)
    
    // Graph representation for Prim's algorithm (adjacency list)
    vector<vector<pair<int, int>>> graph(n);
    
    // Adding edges (bidirectional)
    // Edge format: {neighbor, weight}
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
    
    // Edge list for Kruskal's algorithm
    vector<Edge> edges;
    edges.push_back(Edge(0, 1, 4));
    edges.push_back(Edge(0, 2, 1));
    edges.push_back(Edge(1, 2, 2));
    edges.push_back(Edge(1, 3, 5));
    edges.push_back(Edge(1, 4, 3));
    edges.push_back(Edge(2, 3, 8));
    edges.push_back(Edge(2, 4, 6));
    
    // Run Prim's Algorithm
    cout << "\nRunning Prim's Algorithm..." << endl;
    vector<Edge> primsMST = primsAlgorithm(n, graph, 0);
    printMST(primsMST, "PRIM'S ALGORITHM");
    
    // Run Kruskal's Algorithm
    cout << "\nRunning Kruskal's Algorithm..." << endl;
    vector<Edge> kruskalsMST = kruskalsAlgorithm(n, edges);
    printMST(kruskalsMST, "KRUSKAL'S ALGORITHM");
    
    // Comparison
    cout << "\n" << string(50, '=') << endl;
    cout << "COMPARISON:" << endl;
    cout << "Both algorithms should produce the same total weight!" << endl;
    cout << "Prim's MST edges: " << primsMST.size() << endl;
    cout << "Kruskal's MST edges: " << kruskalsMST.size() << endl;
    
    return 0;
}
