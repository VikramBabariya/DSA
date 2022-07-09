
int totalPaths(int i, int j, vector<vector<int>> &dp, vector< vector< int> > &mat){
	if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int p1 = totalPaths(i-1, j, dp, mat);
	int p2 = totalPaths(i, j-1, dp, mat);
	
	return dp[i][j] = p1 + p2;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
	  return totalPaths(n-1, m-1, dp, mat);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {  
  vector<vector<int>> dp(n, vector<int>(m, 0));
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(mat[i][j] == -1) dp[i][j] = 0;
      else if(i == 0 && j == 0) dp[i][j] = 1;
      else{
        int p1 = 0, p2 = 0;
        if(i>0) p1 = dp[i-1][j]; 
        if(j>0) p2 = dp[i][j-1]; 
        dp[i][j] = p1 + p2;
      }
    }
  }
  return dp[n-1][m-1];
}
