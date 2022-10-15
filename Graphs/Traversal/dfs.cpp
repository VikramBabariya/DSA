//1 based indexing

void dfs(int node, vector<vector<int>> &adj, vector<bool> &state) {
	state[node] = 1;
	
	for (auto adjNode : adj[node]) {
		if (state[adjNode] == 0) {
			dfs(adjNode, adj, state);
		}
	}
}

// for adjMatrix
for (int i = 1; i < adj.size(); i++) {
    if (adj[node][i] == 1 && state[i] == 0) {
	dfsHelp(i, adj, state);
    }
}

void dfs(vector<vector<int>> adj, int n) {
	vector<bool> state(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (state[i] == 0) {
			dfs(i, adj, state);
		}
	}
}
