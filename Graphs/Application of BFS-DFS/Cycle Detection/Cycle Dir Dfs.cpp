bool dfs(int node, vector<int> adj[], vector<int> &state) {
    state[node] = 1;

    for (auto adjNode : adj[node]) {
      if (state[adjNode] == 0) {
        if(dfs(adjNode, adj, state)) return true;
      }
      else if(state[adjNode] == 1) return true;
    }

    state[node] = -1;
    return false;
  }


  // Function to detect cycle in a directed graph.
  bool isCyclic(int n, vector<int> adj[]) {
      vector<int> state(n, 0); // 0->not visited, 1->visiting, -1->dead

    for (int i = 0; i < n; i++) {
      if (state[i] == 0) {
        if(dfs(i, adj, state)) return true;
      }
    }
    return false;
  }
