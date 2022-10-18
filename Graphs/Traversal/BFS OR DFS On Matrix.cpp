// bfs

bool inRange(int i, int j, int n, int m){
    return i >= 0 &&  j >= 0 &&  i < n && j < m;
}

void bfs(int si, int sj, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& state){
    queue<pair<int, int>> cells;
    cells.push({si, sj});
    state[si][sj] = 1;

    while(cells.size()){
        auto pr = cells.front();
        cells.pop();
        int i = pr.first, j = pr.second;

        int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
        for(int k = 0; k < 4; k++){
            int ni = i + delRow[k], nj = j + delCol[k];
            if(inRange(ni, nj, n, m) && state[ni][nj] == 0 /* && some condition */){
                cells.push({ni, nj});
                state[ni][nj] = 1;
            }
        }
        // for 8 direction
//         for(int deli = -1; deli <= 1; deli++){
//           for(int delj = -1; delj <= 1; delj++){
//             int ni = i + deli, nj = j + delj;
//             if(ni >= 0 && nj >= 0 && ni < n && nj < m && state[ni][nj] == 0 /* && some condition */){
//                 cells.push({ni, nj});
//                 state[ni][nj] = 1;
//             }
//           }
//         }
    }
}

//dfs
void dfs(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& state){
    state[i][j] = 1;

    int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
    for(int k = 0; k < 4; k++){
        int ni = i + delRow[k], nj = j + delCol[k];
        if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] == 1 && state[ni][nj] == 0){
            dfs(ni, nj, matrix, n, m, state);
        }
    }
    // for 8 direction
//     for(int deli = -1; deli <= 1; deli++){
//       for(int delj = -1; delj <= 1; delj++{
//         int ni = i + deli, nj = j + delj;
//         if(ni >= 0 && nj >= 0 && ni < n && nj < m && state[ni][nj] == 0 /* && some condition */){
//             state[ni][nj] = 1;
//             dfs(n1, nj, matrix, n, m, state);
//         }
//       }
//     }
}

// main code
int n = grid.size(), m = grid[0].size();
vector<vector<int>> state(n, vector<int>(m, 0));

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(matrix[i][j] == 1 && state[i][j] == 0){
            dfs(i, j, matrix, n, m, state);
        }
    }
}
