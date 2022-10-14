/*

Logic: start dfs from boundry o's and mark all chai o's which are part of this traversal .
        now remaining o's which are not connected with boundry nodes(marked unvisited) need to be converted to x.
*/


void dfs(int i, int j, vector<vector<char>>& matrix, int n, int m, vector<vector<bool>>& visited){
    visited[i][j] = true;

    int delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1};
    for(int k = 0; k < 4; k++){
        int ni = i + delRow[k], nj = j + delCol[k];
        if(ni >= 0 && nj >= 0 && ni < n && nj < m  && matrix[ni][nj] == 'O' && visited[ni][nj] == false){
            dfs(ni, nj, matrix, n, m, visited);
        }
    }

}


void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));


    for(int j = 0; j < m; j++){
        if(board[0][j] == 'O' && visited[0][j] == false){
            dfs(0, j, board, n, m, visited);
        }
        if(board[n-1][j] == 'O' && visited[n-1][j] == false){
            dfs(n-1, j, board, n, m, visited);
        }
    }

    for(int i = 0; i < n; i++){
        if(board[i][0] == 'O' && visited[i][0] == false){
            dfs(i, 0, board, n, m, visited);
        }
        if(board[i][m-1] == 'O' && visited[i][m-1] == false){
            dfs(i, m-1, board, n, m, visited);
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O' && visited[i][j] == false)
                board[i][j] = 'X';
        }
    }
}
