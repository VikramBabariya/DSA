class Solution {
    
    bool canFill(vector<vector<char>>& board, int i, int j, char c){
        for(int k = 0; k < 9; k++){
            if(board[i][k] == c) return false;
            if(board[k][j] == c) return false;
            
            int ir = 3 * (i/3) + k/3;
            int jc = 3 * (j/3) + k%3;
            if(board[ir][jc] == c) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    
                    for(char c = '1'; c <= '9'; c++){
                        if(canFill(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                    
                }
            }    
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
