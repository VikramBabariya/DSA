void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis){
    vis[i][j] = true;
    if(j >= 1 && grid[i][j-1] == '1' && vis[i][j-1] == 0) dfs(i, j-1, grid, vis);
    if(i >= 1 && grid[i-1][j] == '1' && vis[i-1][j] == 0) dfs(i-1, j, grid, vis);
    if(j <= (int)grid[0].size()-2 && grid[i][j+1] == '1' && vis[i][j+1] == 0) dfs(i, j+1, grid, vis);
    if(i <= (int)grid.size()-2 && grid[i+1][j] == '1' && vis[i+1][j] == 0) dfs(i+1, j, grid, vis);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int island = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1' && vis[i][j] == false){
                island++;
                dfs(i, j, grid, vis);
            }
        }
    }
    return island;
}
