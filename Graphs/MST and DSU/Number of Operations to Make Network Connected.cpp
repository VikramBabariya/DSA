//TC: O(E * 4c + V) ; SC: O(V)

//disjointSet

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int extraEdges = 0;
    for(auto edge: connections){
        int u = edge[0], v = edge[1];
        if(ds.ultimateParent(u) == ds.ultimateParent(v)) extraEdges++;
        else ds.unionBySize(u, v);
    }

    int compo = 0;
    for(int i = 0; i < n; i++) if(ds.parent[i] == i) compo++;

    return (extraEdges >= compo-1) ? compo-1 : -1;
}
