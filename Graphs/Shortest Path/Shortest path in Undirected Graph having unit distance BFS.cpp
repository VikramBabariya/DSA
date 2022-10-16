vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
    vector<int> adj[n];
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> dist(n, INT_MAX);

		queue<int> nodes;
		nodes.push(src);
		dist[src] = 0;

		while (!nodes.empty()) {
			int node = nodes.front();
			nodes.pop();

			for (auto adjNode : adj[node]) {
				if (dist[node] + 1 < dist[adjNode]) {
					nodes.push(adjNode);
					dist[adjNode] = dist[node] + 1;
				}
			}		
		}
		
		for(int i = 0; i < n; i++) if(dist[i] == INT_MAX) dist[i] = -1;
    return dist;   
}
