class Solution {
    
    bool canFind(int i, int j, int k, vector<vector<bool>> &vis, vector<vector<char>>& board, string &word){
        if(k == word.size()) return true;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int del = 0; del < 4; del++){
            int ni = i + dx[del], nj = j + dy[del];
            if(ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size()){
                if(vis[ni][nj] == false && board[ni][nj] == word[k]){
                    vis[ni][nj] = true;
                    if(canFind(ni, nj, k+1, vis, board, word)) return true;
                    vis[ni][nj] = false;
                }
            }
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    if(canFind(i, j, 1, vis, board, word)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
