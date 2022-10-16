/*
Logic:
-Will start doing dfs or bfs from one point will call this starting point as base point for that shape(traversal).
-Will subtract this base point from all point included in the traversal , including start point.
-So that all shape can be compared absolutely.

Lerning:
-how to create shapes in matrix
-how to compare this shapes (making shapes absolute to each other)

*/


void dfs(int i, int j, int baseI, int baseJ, vector<vector<int>>& matrix, int n, int m, vector<vector<bool>>& visited, vector<pair<int, int>> &shape){
    visited[i][j] = true;
    shape.push_back({i-baseI, j-baseJ});

    int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
    for(int k = 0; k < 4; k++){
        int ni = i + delRow[k], nj = j + delCol[k];
        if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] == 1 && visited[ni][nj] == false){
            dfs(ni, nj, baseI, baseJ, matrix, n, m, visited, shape);
        }
    }
}


int countDistinctIslands(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> allShapes;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1 && visited[i][j] == false){
                vector<pair<int, int>> shape;
                dfs(i, j, i, j, matrix, n, m, visited, shape);
                // for(auto e : shape) 
                //     cout<<"("<<e.first<<","<<e.second<<") ";
                // cout<<endl;
                allShapes.insert(shape);
            }
        }
    }

    return allShapes.size();
}

