vector<int> topoSort(int n, vector<int> adj[]) 
  {
      vector<int> topoOrd;
      vector<int> indeg(n, 0);

      for (int i = 0; i < n; i++) {
          for(auto node : adj[i]){
              indeg[node]++;
          }
      }

      queue<int> ready;
      for (int i = 0; i < n; i++) {
          if(indeg[i] == 0) ready.push(i);       
      }

      while(ready.size()){
          int node = ready.front();
          topoOrd.push_back(node);
          ready.pop();

          for(auto anode : adj[node]){
              indeg[anode]--;
              if(indeg[anode] == 0) ready.push(anode);
          }
      }

      return topoOrd;
  }

public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int n, vector<int> adj[]) {
     return topoSort(n, adj).size() == n ? false : true;
  }
