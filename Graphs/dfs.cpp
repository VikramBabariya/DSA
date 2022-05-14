// Method 1 using stack

vector<int> dfs(vector<vector<int>> adj, int n) {
	vector<int> dfsTrv;
	vector<bool> vis(n + 1, false);

	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {

			stack<int> nodes;
			nodes.push(i);
			vis[i] = true;

			while (!nodes.empty()) {
				int node = nodes.top();
				nodes.pop();
				dfsTrv.push_back(node);

				for (auto adjNode : adj[node]) {
					if (vis[adjNode] == false) {
						nodes.push(adjNode);
						vis[adjNode] = true;
					}
				}
			}

		}
	}
	return dfsTrv;
}


// method 2 using recursion

