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


bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> adj[n];
    for(auto dep : prerequisites){
        adj[dep[1]].push_back(dep[0]);
    }

    return topoSort(n, adj).size() == n ? true : false;
}
