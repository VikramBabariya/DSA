#include <bits/stdc++.h>

using namespace std;

// undirected + 1 based indexing

// adejecency matrix
int main(){
  int n, m;
  cin>>n>>m;
  int graph[n+1][n+1] = {0};
  for(int i = 0; i < m; i++){
    int u, v;
    cin>>u>>v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  return 0;
}

//adejecency list
int main(){
  int n, m;
  cin>>n>>m;
  vector<int> graph[n+1];
//   vector<pair<int, int>> graph[n+1]; // for wighted graph
  for(int i = 0; i < m; i++){
    int u, v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  return 0;
}
