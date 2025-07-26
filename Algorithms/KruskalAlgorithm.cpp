#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edgeInfo;

vector<tuple<int,int,int>> KruskalAlgorithm(vector<edgeInfo> &edges) {

    vector<tuple<int,int,int>> mst;
    set<int> visited;

    sort(edges.begin(),edges.end());
    
    for(auto i: edges) {
        int u = get<1>(i);
        int v = get<2>(i);
        int weight = get<0>(i);

        if(visited.find(u) == visited.end() || visited.find(v) == visited.end()) {
            // If either node is not visited, add the edge to the MST
            mst.push_back(make_tuple(weight, u, v));
            visited.insert(u);
            visited.insert(v);
        }
    }


    return mst;
}

int main() {
    cout << "=== Kruskal's Algorithm for Minimum Spanning Tree ===" << endl;
    cout << "Enter number of edges: ";
    int numEdges;
    cin >> numEdges;
    
    vector<edgeInfo> edges;
    
    cout << "Enter edges (format: weight from to):" << endl;
    for(int i = 0; i < numEdges; i++) {
        int weight, from, to;
        cin >> weight >> from >> to;
        edges.push_back(make_tuple(weight, from, to));
    }
    
    vector<tuple<int,int,int>> mst = KruskalAlgorithm(edges);
    
    cout << "\nMinimum Spanning Tree edges:" << endl;
    cout << "Edge\t\tWeight" << endl;
    cout << "----\t\t------" << endl;
    
    int totalWeight = 0;
    for(auto edge: mst) {   
        int weight = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        cout << u << " - " << v << "\t\t" << weight << endl;
        totalWeight += weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
    cout << "Total edges in MST: " << mst.size() << endl;

    return 0;
}