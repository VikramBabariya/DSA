    bool allVis(vector<bool> &vis, int node, int N){
        for(int i = 1; i <= N; i++){
            if(i != node && vis[i] == false) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<int>> &Edges, vector<bool> &vis, int N, int M, int node){
        if(allVis(vis, node, N)){
            return true;
        }
        
        for(auto e : Edges){
            int t;
            if(e[0] == node)
                t = e[1];
            else if(e[1] == node)
                t = e[0];
            else
                continue;
                
            if(!vis[t]){
                vis[node] = true;
                if(solve(Edges, vis, N, M, t)) return true;
                vis[node] = false;
            }
        }
        return false;
    }
