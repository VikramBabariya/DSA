//1 based indexing

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
	vis[node] = 1;
	
	for (auto adjNode : adj[node]) {
		if (vis[adjNode] == 0) {
			dfs(adjNode, adj, vis, dfsTrv);
		}
	}
}

// for adjMatrix
for (int i = 1; i < adj.size(); i++) {
    if (adj[node][i] == 1 && vis[i] == 0) {
	dfsHelp(i, adj, vis);
    }
}

void dfs(vector<vector<int>> adj, int n) {
	vector<bool> vis(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(i, adj, vis);
		}
	}
}
