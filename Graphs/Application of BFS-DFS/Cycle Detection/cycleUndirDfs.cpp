bool dfsHelp(int node, int parent, vector<int> adj[], vector<bool> &vis) {
  vis[node] = true;

  for (auto adjNode : adj[node]) {
    if (vis[adjNode] == false) {
      if(dfsHelp(adjNode, node, adj, vis)) return true;
    }else if(adjNode != parent) return true;
  }
  return false;
}
    
    
    // Function to detect cycle in an undirected graph.
bool isCycle(int n, vector<int> adj[]) {
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    if (vis[i] == false) {
      if(dfsHelp(i, -1, adj, vis)) return true;
    }
  }
  return false;
}
