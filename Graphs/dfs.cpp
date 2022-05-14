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
void dfsHelp(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dfsTrv) {
	if (vis[node] == true) return;
	vis[node] = true;
	dfsTrv.push_back(node);

	for (auto adjNode : adj[node]) {
		if (vis[adjNode] == false) {
			dfsHelp(adjNode, adj, vis, dfsTrv);
		}
	}
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
