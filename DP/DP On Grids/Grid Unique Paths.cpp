#include <bits/stdc++.h> 

int totalPaths(int i, int j, vector<vector<int>> &dp){
	if(i == 0 || j == 0) return 1;
	
	if(dp[i][j] != -1) return dp[i][j];
	int p1 = totalPaths(i-1, j, dp);
	int p2 = totalPaths(i, j-1, dp);
	return dp[i][j] = p1+p2;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
  return totalPaths(m-1, n-1, dp);
	for(int i = 1; i <= n; i++){
		dp[1][i] = 1;
	}
	for(int i = 1; i <= m; i++){
		dp[i][1] = 1;
	}
	for(int i = 2; i <= m; i++){
		for(int j = 2; j <= n; j++){
			int p1 = dp[i-1][j]; 
			int p2 = dp[i][j-1]; 
			dp[i][j] = p1+p2;
		}
	}
	return dp[m][n];
}
