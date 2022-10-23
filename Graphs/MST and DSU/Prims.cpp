//TC:O(ElogE) , SC:O(E)

int spanningTree(int v, vector<vector<int>> adj[])
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> explore;
    //{weight, node, parent}
    vector<int> vis(v, 0);
    vector<pair<int,int>> mst;
    int sum = 0;

    explore.push({0, 0, -1});

    while(explore.size()){
        vector<int> edge = explore.top();
        explore.pop();
        int w = edge[0], node = edge[1], parent = edge[2];
        if(vis[node] == 0){
            vis[node] = 1;
            mst.push_back({node, parent});
            sum += w;
            for(auto edge : adj[node]){
                int adjNode = edge[0], w = edge[1];
                if(vis[adjNode] == 0) explore.push({w, adjNode, node});
            }
        }
    }

    return sum;
}
