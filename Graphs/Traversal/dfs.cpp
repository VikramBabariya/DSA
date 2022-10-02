void dfsHelp(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dfsTrv) {
	vis[node] = true;
	dfsTrv.push_back(node);
	
	// for adjMatrix
	for (int i = 1; i < adj.size(); i++) {
            if (adj[node][i] == 1 && vis[i] == false) {
                dfsHelp(i, adj, vis);
            }
        }
	
	// for adjList
// 	for (auto adjNode : adj[node]) {
// 		if (vis[adjNode] == false) {
// 			dfsHelp(adjNode, adj, vis, dfsTrv);
// 		}
// 	}
}

vector<int> dfs(vector<vector<int>> adj, int n) {
	vector<int> dfsTrv;
	vector<bool> vis(n + 1, false);

	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			dfsHelp(i, adj, vis, dfsTrv);
		}
	}
	return dfsTrv;
}
