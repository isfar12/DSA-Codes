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
    vector<edgeInfo> edges;
    edges.push_back(make_tuple(1, 1, 4));
    edges.push_back(make_tuple(2, 1, 2));
    edges.push_back(make_tuple(3, 2, 3));  
    edges.push_back(make_tuple(3, 2, 4));
    edges.push_back(make_tuple(4, 1, 5));
    edges.push_back(make_tuple(5, 3, 4));
    edges.push_back(make_tuple(7, 2, 6));
    edges.push_back(make_tuple(8, 3, 6));
    edges.push_back(make_tuple(9, 4, 5));

    vector<tuple<int,int,int>> mst = KruskalAlgorithm( edges);
    cout << "Minimum Spanning Tree Edges:" << endl;
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


    return 0;
}