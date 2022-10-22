int minimumMultiplications(vector<int>& arr, int start, int end) {
    queue<pair<int, int>> explore;
    vector<int> dist(MOD, 1e9);
    dist[start] = 0;
    explore.push({0, start});

    while(explore.size()){
        int d = explore.front().first, node = explore.front().second;
        explore.pop();

        if(node == end) return d;

        for(auto e : arr){
            int adjNode = (node * e) % MOD;
            if(d + 1 < dist[adjNode]){
                dist[adjNode] = d + 1;
                explore.push({dist[adjNode], adjNode});
            }
        }
    }
    return -1;
}
