int minMul(int i, int j, vector<int> &arr, int n, vector<vector<int>> &dp){
	if(i == j) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int mini = INT_MAX;
	for(int k = i; k < j; k++){
		int muls = minMul(i, k, arr, n, dp) + minMul(k+1, j, arr, n, dp) + arr[i-1]*arr[k]*arr[j];
		mini = min(mini, muls);
	}
	return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int n)
{
// 	vector<vector<int>> dp(n, vector<int>(n, 0));
  vector<vector<int>> dp(n, vector<int>(n, 0));
	
	for(int i = 1; i < n; i++) dp[i][i] = 0;
	
	for(int i = n-1; i >= 1; i--){
		for(int j = i+1; j < n; j++){ // j is always be greater or equal than i
			int mini = INT_MAX;
			for(int k = i; k < j; k++){
				int muls = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
				mini = min(mini, muls);
			}
			dp[i][j] = mini;
		}
	}
	return dp[1][n-1];
	
//     return minMul(1, n-1, arr, n, dp);
}
