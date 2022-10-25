

//DisjointSet

int findCircleNum(vector<vector<int>>& adj) {
    int v = adj.size();
    DisjointSet ds(v);
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(adj[i][j] == 1){
                ds.unionBySize(i, j);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < v; i++) if(ds.parent[i] == i) cnt++;
    return cnt;
}
