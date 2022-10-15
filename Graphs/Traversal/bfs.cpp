// 1 based indexing
void bfs(vector<vector<int>> adj, int n) {
	vector<int> state(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		if (state[i] == 0) {

			queue<int> nodes;
			nodes.push(i);
			state[i] = 1;

			while (!nodes.empty()) {
				int node = nodes.front();
				nodes.pop();

				for (auto adjNode : adj[node]) {
					if (state[adjNode] == 0) {
						nodes.push(adjNode);
						state[adjNode] = 1;
					}
				}		
			}
		}
	}
}

//for adjMatrix
for(int i = 1; i < adj.size(); i++){
	if (adj[node][i] == 1 && state[i] == 0) {
		nodes.push(i);
		state[i] = 1;
	}
}
