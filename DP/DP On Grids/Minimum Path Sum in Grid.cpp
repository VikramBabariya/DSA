
int minPath(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
	if(i == 0 && j == 0) return grid[0][0];
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int p1 = INT_MAX, p2 = INT_MAX; // int boundary should be considered
	if(i > 0) p1 = grid[i][j] + minPath(i-1, j, dp, grid);
	if(j > 0) p2 = grid[i][j] + minPath(i, j-1, dp, grid);
	
	return dp[i][j] = min(p1, p2);
}
int minSumPath(vector<vector<int>> &grid) {
	int n = grid.size(), m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
	return minPath(n-1, m-1, dp, grid);	 
}


int minSumPath(vector<vector<int>> &grid) {
	int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			
			if(i == 0 && j == 0) dp[0][0] = grid[0][0];
			else{
				int p1 = INT_MAX, p2 = INT_MAX;
				if(i > 0) p1 = grid[i][j] + dp[i-1][j]; 
				if(j > 0) p2 = grid[i][j] + dp[i][j-1]; 

				dp[i][j] = min(p1, p2);
			}
		}
	}
	return dp[n-1][m-1];
}





