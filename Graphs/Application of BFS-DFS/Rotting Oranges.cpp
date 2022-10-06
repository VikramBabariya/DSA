class Solution {
    
    void initQ(queue<pair<int, int>> &cells, vector<vector<int>> &grid, int n, int m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    cells.push({i, j});
                }
            }
        }
    }
    
    void rottenAdjecents(int i, int j, queue<pair<int, int>> &cells, vector<vector<int>> &grid, int n, int m){
        int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
        for(int k = 0; k < 4; k++){
            int ni = i + delRow[k], nj = j + delCol[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1){
                grid[ni][nj] = 2;
                cells.push({ni, nj});
            }
        }
    }
    
    bool haveFresh(vector<vector<int>> &grid, int n, int m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return true;
            }
        }
        return false;
    }
    
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int t = 0, n = (int)grid.size(), m = (int)grid[0].size();
        queue<pair<int, int>> cells;
        initQ(cells, grid, n, m);
        
        while(!cells.empty()){
          // outer most rotten oranges start rottening
            int qs = (int)cells.size();
            for(int i = 0; i < qs; i++){
                auto cell = cells.front();
                cells.pop();
                rottenAdjecents(cell.first, cell.second, cells, grid, n, m);
            }
            
            if(cells.size()){ // atleast one orange is rottened
                t++;
            }
        }
        
        return haveFresh(grid, n, m) ? -1 : t;
    }
};
