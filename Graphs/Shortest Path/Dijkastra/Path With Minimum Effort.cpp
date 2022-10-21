//sol1: TC:O(ElogV) -> O(n*m*4log(n*m)) | SC:O(n*m)

bool inRange(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}


int minimumEffortPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> cells;
    //{diff, row, col}
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    cells.push({0, 0, 0});
    dist[0][0] = 0;

    while(cells.size()){
        vector<int> pr = cells.top();
        cells.pop();
        int diff = pr[0], i = pr[1], j = pr[2];

        if(i == n-1 && j == m-1) return diff;

        int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
        for(int k = 0; k < 4; k++){
            int ni = i + delRow[k], nj = j + delCol[k]; 
            if(inRange(ni, nj, n, m)){
                int currDiff = abs(grid[ni][nj] - grid[i][j]);
                int effort = max(diff, currDiff);
                if(effort < dist[ni][nj]){
                    dist[ni][nj] = effort;
                    cells.push({effort, ni, nj});
                } 
            }
        }

    }
    return 0;
}
