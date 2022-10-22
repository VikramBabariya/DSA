vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
    vector<int> dist(v, 1e8);
    dist[s] = 0;

    for(int i = 1; i <= v-1; i++){
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // checking for nagative weight cycle ; Nth iteration
    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];
        if(dist[u] != 1e8 && dist[u] + w < dist[v]){
            return {-1};
        }
    }

    return dist;
}
