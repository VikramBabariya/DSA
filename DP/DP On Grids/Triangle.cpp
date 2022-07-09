//Fixed Starting Point and Variable Ending Point

int minPath(int i, int j, vector<vector<int>>& t, int n, vector<vector<int>> &dp){
	if(i == n-1) return t[i][j];
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int down = t[i][j] + minPath(i+1, j, t, n, dp);
	int digonal = t[i][j] + minPath(i+1, j+1, t, n, dp);
	
	return dp[i][j] = min(down, digonal);
}
int minimumPathSum(vector<vector<int>>& t, int n){
	vector<vector<int>> dp(n);
	for(int i = 0; i < n; i++){
		vector<int> temp(i+1, -1);
		dp[i] = temp;
	}
	return minPath(0, 0, t, n, dp);
}

int minimumPathSum(vector<vector<int>>& t, int n){
	vector<vector<int>> dp(n);
	for(int i = 0; i < n; i++){
		vector<int> temp(i+1, 0);
		dp[i] = temp;
	}
	
	for(int j = 0; j < n; j++) dp[n-1][j] = t[n-1][j];
	
	for(int i = n-2; i >= 0; i--){
		for(int j = i; j >= 0; j--){
			int down = t[i][j] + dp[i+1][j]; 
			int digonal = t[i][j] + dp[i+1][j+1]; 

			dp[i][j] = min(down, digonal);
		}
	}
	return dp[0][0];	
}
