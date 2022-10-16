bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> state(n, -1); // -1 -> not visited, 0 -> color1 , 1 -> color2

    for (int i = 0; i < n; i++) {
        if (state[i] == -1) {

            queue<int> nodes;
            nodes.push(i);
            state[i] = 0;

            while (!nodes.empty()) {
                int node = nodes.front();
                nodes.pop();
                int nodeCol = state[node];

                for (auto adjNode : adj[node]) {
                    if (state[adjNode] == -1) {
                        nodes.push(adjNode);
                        state[adjNode] = !nodeCol;
                    }
                    else if(state[adjNode] == nodeCol) return false;
                }		


            }

        }
    }
    return true;
}
