bool dfs(int node, vector<vector<int>> &adj, vector<int> &state, vector<int> &safe) {
      state[node] = 1;

      for (auto adjNode : adj[node]) {
        if (state[adjNode] == 0) {
          if(dfs(adjNode, adj, state, safe)){
              safe[node] = 0;
              return true;
          }
        }
        else if(state[adjNode] == 1){
            safe[node] = 0;
            safe[adjNode] = 0;
            return true;
        }
      }

      state[node] = -1;
      safe[node] = 1;
      return false;
    }

  vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
      int n = adj.size();
      vector<int> state(n, 0); // 0->not visited, 1->visiting, -1->dead
      vector<int> safe(n, 0); // 1->not decided , 0->not safe
      vector<int> safeNodes;

      for (int i = 0; i < n; i++) {
          if(state[i] == 0){
              dfs(i, adj, state, safe);
          }
      }

      for(int i = 0; i < n; i++){
          if(safe[i] == 1) safeNodes.push_back(i);
      }
      return safeNodes;

  }
