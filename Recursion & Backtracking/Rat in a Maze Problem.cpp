class Solution{
    
    bool canMove(vector<vector<int>> &m, vector<vector<bool>> &vis, int n, int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= n) return false;
        
        if(m[i][j] == 0) return false;
        
        if(vis[i][j] == true) return false;
        
        return true;
        
    }
    
    void paths(vector<string> &ans, vector<vector<int>> &m, vector<vector<bool>> &vis, int n, int row, int col, string &path){
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        if(canMove(m, vis, n, row+1, col)){
            vis[row][col] = true;
            path += 'D';
            paths(ans, m, vis, n, row+1, col, path);
            vis[row][col] = false;
            path.erase(path.begin() + (int)path.size() - 1);
        }
        
        if(canMove(m, vis, n, row, col-1)){
            vis[row][col] = true;
            path += 'L';
            paths(ans, m, vis, n, row, col-1, path);
            vis[row][col] = false;
            path.erase(path.begin() + (int)path.size() - 1);
        }
        
        if(canMove(m, vis, n, row, col+1)){
            vis[row][col] = true;
            path += 'R';
            paths(ans, m, vis, n, row, col+1, path);
            vis[row][col] = false;
            path.erase(path.begin() + (int)path.size() - 1);
        }
        
        if(canMove(m, vis, n, row-1, col)){
            vis[row][col] = true;
            path += 'U';
            paths(ans, m, vis, n, row-1, col, path);
            vis[row][col] = false;
            path.erase(path.begin() + (int)path.size() - 1);
        }
        
    }
    
    
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<string> ans;
        string path = "";
        
        if(m[0][0] == 1)
            paths(ans, m, vis, n, 0, 0, path);
        
        return ans;
    }
};
