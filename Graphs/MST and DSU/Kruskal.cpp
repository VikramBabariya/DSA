//TC: O(ElogE) , SC: O(V + E)

//DisjoinSet ..

int spanningTree(int v, vector<vector<int>> adj[])
{
    // adj[u] = {v, wt}
    //edges[i][0] = wt, edges[i][1] = u, edges[i][2] = v
    int mstWt = 0;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < v; i++){
        for(auto edge : adj[i]){
            int u = i, v = edge[0], wt = edge[1];
            edges.push_back({wt, {u, v}});
        }
    }
    sort(edges.begin(), edges.end());

    DisjointSet ds(v);
    for(auto e : edges){
        int wt = e.first, u = e.second.first, v = e.second.second;
        if(ds.ultimateParent(u) != ds.ultimateParent(v)){
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}
