// 1 based indexing
vector<int> bfs(vector<vector<int>> adj, int n) {
	vector<int> bfsTrv;
	vector<bool> vis(n + 1, false);
	
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {

			queue<int> nodes;
			nodes.push(i);
			vis[i] = true;

			while (!nodes.empty()) {
				int node = nodes.front();
				nodes.pop();
				bfsTrv.push_back(node);

				for (auto adjNode : adj[node]) {
					if (vis[adjNode] == false) {
						nodes.push(adjNode);
						vis[adjNode] = true;
					}
				}
			}

		}
	}
	return bfsTrv;
}
