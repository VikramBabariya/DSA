
int maxPath(int i, int j, vector<vector<int>>& mat, int m, vector<vector<int>> &dp){
	if(j < 0 || j >= m) return -1e9;
	if(i == 0) return mat[i][j];
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int up = mat[i][j] + maxPath(i-1, j, mat, m, dp);
	int upLeft = mat[i][j] + maxPath(i-1, j-1, mat, m, dp);
	int upRight = mat[i][j] + maxPath(i-1, j+1, mat, m, dp);
	int max1 = max(up , upLeft);
	
	return dp[i][j] = max(max1, upRight);
}
int getMaxPathSum(vector<vector<int>> &mat)
{
	int n = mat.size(), m = mat[0].size();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	
	int maxi = INT_MIN;
	for(int j = 0; j < m; j++){
		maxi = max(maxPath(n-1, j, mat, m, dp), maxi);
	}
	return maxi;
    
}

int getMaxPathSum(vector<vector<int>> &mat)
{
	int n = mat.size(), m = mat[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	
	for(int j = 0; j < m; j++) dp[0][j] = mat[0][j];
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			int down = mat[i][j] + dp[i-1][j];
			int downLeft = -1e9;
			if(j > 0) downLeft = mat[i][j] + dp[i-1][j-1]; 
			int downRight = -1e9;
			if(j < m-1) downRight = mat[i][j] + dp[i-1][j+1]; 
			int max1 = max(down , downLeft);
			dp[i][j] = max(max1, downRight);
		}
	}
	int maxi = INT_MIN;
	for(int j = 0; j < m; j++){
		maxi = max(dp[n-1][j], maxi);
	}
	return maxi;  
}
