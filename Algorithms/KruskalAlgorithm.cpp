#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edgeInfo;

vector<pair<int,int>> KruskalAlgorithm(int n, vector<edgeInfo> &edges) {

    vector<pair<int,int>> mst;
    set<int> visited;

    sort(edges.begin(),edges.end());
    
    for(auto i: edges) {
        int u = get<1>(i);
        int v = get<2>(i);
        int weight = get<0>(i);

        if(visited.find(u) == visited.end() || visited.find(v) == visited.end()) {
            // If either node is not visited, add the edge to the MST
            mst.push_back(make_pair(u, v));
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

    vector<pair<int,int>> mst = KruskalAlgorithm(7, edges);
    cout << "Minimum Spanning Tree Edges:" << endl;
    for(auto edge: mst) {   
        cout << edge.first << " - " << edge.second << endl;
    }


    return 0;
}