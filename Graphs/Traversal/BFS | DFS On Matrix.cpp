// bfs
void bfs(int si, int sj, vector<vector<int>>& matrix, int n, int m, vector<vector<bool>>& visited){
    queue<pair<int, int>> cells;
    cells.push({si, sj});
    visited[si][sj] = true;

    while(cells.size()){
        auto pr = cells.front();
        cells.pop();
        int i = pr.first, j = pr.second;

        int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
        for(int k = 0; k < 4; k++){
            int ni = i + delRow[k], nj = j + delCol[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] == false /* && some condition */){
                cells.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
        // for 8 direction
//         for(int deli = -1; deli <= 1; deli++){
//           for(int delj = -1; delj <= 1; delj++{
//             int ni = i + deli, nj = j + delj;
//             if(ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] == false /* && some condition */){
//                 cells.push({ni, nj});
//                 visited[ni][nj] = true;
//             }
//           }
//         }
    }
}

//dfs
void dfs(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<bool>>& visited){
    visited[i][j] = true;

    int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
    for(int k = 0; k < 4; k++){
        int ni = i + delRow[k], nj = j + delCol[k];
        if(ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] == false /* && some condition */){
            visited[ni][nj] = true;
            dfs(n1, nj, matrix, n, m, visited);
        }
    }
    // for 8 direction
//     for(int deli = -1; deli <= 1; deli++){
//       for(int delj = -1; delj <= 1; delj++{
//         int ni = i + deli, nj = j + delj;
//         if(ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] == false /* && some condition */){
//             visited[ni][nj] = true;
//             dfs(n1, nj, matrix, n, m, visited);
//         }
//       }
//     }
}
