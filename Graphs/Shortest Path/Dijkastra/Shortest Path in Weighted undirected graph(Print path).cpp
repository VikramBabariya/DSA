vector<int> shortestPath(int v, int m, vector<vector<int>>& edges) {
    vector<vector<int>> adj[v+1];
    for(auto edge: edges){
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    set<pair<int, int>> explore;
    vector<int> dist(v+1, 1e9);
    vector<int> chain(v+1, 0);
    dist[1] = 0;
    explore.insert({0, 1});

    while(explore.size()){
        auto it = *(explore.begin());
        int d = it.first, node = it.second;
        explore.erase({d, node});

        for(auto edge : adj[node]){
            int adjNode = edge[0], edgeWeight = edge[1];
            if(d + edgeWeight < dist[adjNode]){
                if(dist[adjNode] != 1e9) explore.erase({dist[adjNode], adjNode});
                dist[adjNode] = d + edgeWeight;
                chain[adjNode] = node;
                explore.insert({dist[adjNode], adjNode});
            }
        }
    }
    if(dist[v] == 1e9) return {-1};
    vector<int> path;
    path.push_back(v);
    int next = chain[v];
    while(next != 1){
        path.push_back(next);
        next = chain[next];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}
