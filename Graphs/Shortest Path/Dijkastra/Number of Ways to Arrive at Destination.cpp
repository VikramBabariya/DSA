int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto road : roads){
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> explore;
    vector<ll> dist(n, 1e18);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    explore.push({0,0});

    while(explore.size()){
        ll d = explore.top().first;
        int node = explore.top().second;
        explore.pop();

        if(node == n-1) return ways[n-1];

        for(auto edge : adj[node]){
            int adjNode = edge.first, edgeWeight = edge.second;
            if(d + edgeWeight < dist[adjNode]){
                dist[adjNode] = d + edgeWeight;
                ways[adjNode] = ways[node] % MOD;
                explore.push({dist[adjNode], adjNode});
            }
            else if(d + edgeWeight == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] % MOD + ways[node] % MOD) % MOD;
            } 
        }
    }
    return 0;
}
