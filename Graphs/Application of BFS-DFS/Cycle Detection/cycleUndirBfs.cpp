bool cycleDetect(vector<vector<int>> adj, int n) {
	vector<bool> vis(n + 1, false);

	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {

			queue<pair<int, int>> nodes; // node,parent
			nodes.push({i, -1});
			vis[i] = true;

			while (!nodes.empty()) {
				int node = nodes.front().first;
				int parent = nodes.front().second;
				nodes.pop();

				for (auto adjNode : adj[node]) {
					if (vis[adjNode] == false) {
						nodes.push({adjNode, node});
						vis[adjNode] = true;
					} else if (adjNode != parent) return true;

				}
			}

		}
	}
	return false;
}
