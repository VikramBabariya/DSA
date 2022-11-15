{
    bool dfs(int node, vector<int> &visited, vector<vector<pair<int,int>>> &network, int n, vector<int> &ans){
        visited[node] = true;
        if(node == n) return true;
        
        for(auto &adjNode: network[node]){
            int u = adjNode.first, w = adjNode.second;
            if(visited[u] == 0 && w > 0){
                ans.push_back(u);
                if(dfs(u, visited, network, n, ans)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
    
    vector<int> findAugPath(vector<vector<pair<int,int>>> &network, int n){
        vector<int> ans;
        vector<int> visited(n+1, 0);
        ans.push_back(1);
        if(dfs(1, visited, network, n, ans) == false) ans.pop_back();
        return ans;
    }
    
    int findBottleNeck(vector<int> &augPath, vector<vector<pair<int,int>>> &network){
        int bottleNeck = 1e9;
        for(int i = 0; i < (int)augPath.size()-1; i++){
            int u = augPath[i], v = augPath[i+1];
            for(auto &adjNode: network[u]){
                int adj = adjNode.first, w = adjNode.second;
                if(adj == v){
                    bottleNeck = min(bottleNeck, w);
                    break;
                }
            }
        }
        return bottleNeck;
    }
    
    void updateEdge(int u, int v, vector<vector<pair<int,int>>> &network, int bottleNeck, bool increment){
        for(auto &adjNode: network[u]){
            int adj = adjNode.first, w = adjNode.second;
            if(adj == v){
                if(increment) adjNode.second += bottleNeck;
                else adjNode.second -= bottleNeck;
                break;
            }
        }
    }
    
    
public:
    int findMaxFlow(int n,int m,vector<vector<int>> edges)
    {
        vector<vector<pair<int,int>>> network(n+1);
        for(auto edge: edges){
            network[edge[0]].push_back({edge[1], edge[2]});
            network[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int flow = 0;
        vector<int> augPath = findAugPath(network, n);
        
        // for(auto e: augPath) cout<<e<<" ";
        // cout<<endl;
        // int bottleCap = findBottleNeck(augPath, network);
        // cout<<bottleCap<<endl;
        
        while(augPath.size() != 0){
            int augS = augPath.size();
            int bottleNeck = findBottleNeck(augPath, network);
            flow += bottleNeck;
            for(int i = 0; i < augS-1; i++){
                updateEdge(augPath[i], augPath[i+1], network, bottleNeck, false);
                updateEdge(augPath[i+1], augPath[i], network, bottleNeck, true);
            }
            augPath = findAugPath(network, n);
        }
        return flow;
    }
};


//sol2 adjmat
{
    bool dfs(int node, vector<int> &visited, vector<vector<int>> &network, int n, vector<int> &ans){
        visited[node] = true;
        if(node == n) return true;
        
        for(int i = 1; i <= n; i++){
            int u = i, w = network[node][i];
            if(visited[u] == 0 && w > 0){
                ans.push_back(u);
                if(dfs(u, visited, network, n, ans)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
    
    vector<int> findAugPath(vector<vector<int>> &network, int n){
        vector<int> ans;
        vector<int> visited(n+1, 0);
        ans.push_back(1);
        if(dfs(1, visited, network, n, ans) == false) ans.pop_back();
        return ans;
    }
    
    int findBottleNeck(vector<int> &augPath, vector<vector<int>> &network){
        int bottleNeck = 1e9;
        for(int i = 0; i < (int)augPath.size()-1; i++){
            int u = augPath[i], v = augPath[i+1];
            bottleNeck = min(bottleNeck, network[u][v]);
        }
        return bottleNeck;
    }
    
    
public:
    int findMaxFlow(int n,int m,vector<vector<int>> edges)
    {
        vector<vector<int>> network(n+1, vector<int>(n+1, -1));
        for(auto edge: edges){
            network[edge[0]][edge[1]] = edge[2];
            network[edge[1]][edge[0]] = edge[2];
        }
        
        int flow = 0;
        vector<int> augPath = findAugPath(network, n);
        
        // for(auto e: augPath) cout<<e<<" ";
        // cout<<endl;
        // int bottleCap = findBottleNeck(augPath, network);
        // cout<<bottleCap<<endl;
        
        while(augPath.size() != 0){
            int augS = augPath.size();
            int bottleNeck = findBottleNeck(augPath, network);
            flow += bottleNeck;
            for(int i = 0; i < augS-1; i++){
                network[augPath[i]][augPath[i+1]] -= bottleNeck;
                network[augPath[i+1]][augPath[i]] += bottleNeck;
            }
            augPath = findAugPath(network, n);
        }
        return flow;
    }
};
