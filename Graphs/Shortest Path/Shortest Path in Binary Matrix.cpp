bool inRange(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    queue<pair<int, int>> cells;
    if(grid[0][0] == 0) cells.push({0, 0});
    grid[0][0] = 1;

    while(cells.size()){
        auto pr = cells.front();
        cells.pop();
        int i = pr.first, j = pr.second;
        if(i == n-1 && j == m-1) return grid[n-1][m-1];

        for(int deli = -1; deli <= 1; deli++){
            for(int delj = -1; delj <= 1; delj++){
                int ni = i + deli, nj = j + delj;
                if(inRange(ni, nj, n, m) && grid[ni][nj] == 0 /*&& state[i][j] + 1 < state[ni][nj]*/){
                    cells.push({ni, nj});
                    grid[ni][nj] = grid[i][j] + 1;
                }
            }
        }
    }
    return -1;
}
