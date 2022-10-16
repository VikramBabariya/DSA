void dfs(int node, vector<int>adj[], vector<bool> &vis, vector<int> &topoOrd) {
    vis[node] = 1;

    for (auto adjNode : adj[node]) {
      if (vis[adjNode] == 0) {
        dfs(adjNode, adj, vis, topoOrd);
      }
    }
    topoOrd.push_back(node);
  }

vector<int> topoSort(int n, vector<int> adj[]) 
{
    vector<bool> vis(n, 0);
    vector<int> topoOrd;

    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) {
        dfs(i, adj, vis, topoOrd);
      }
    }

    reverse(begin(topoOrd), end(topoOrd));
    return topoOrd;
}
