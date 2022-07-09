#include<bits/stdc++.h>

int maxPath(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp){
	if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return INT_MIN;
	if(i == n-1){
		if(j1 == j2) return grid[i][j1];
		return grid[i][j1] + grid[i][j2];
	}
	
	if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
	
	int maxi = INT_MIN;
	int dj[] = {-1, 0, 1};
	for(int d1 = 0; d1 < 3; d1++){
		for(int d2 = 0; d2 < 3; d2++){
			if(j1 == j2) maxi = max(maxi, grid[i][j1] + maxPath(i+1, j1 + dj[d1], j2 + dj[d2], grid, n, m, dp));
			else maxi = max(maxi, grid[i][j1] + grid[i][j2] + maxPath(i+1, j1 + dj[d1], j2 + dj[d2], grid, n, m, dp));
		}
	}
	return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
   return maxPath(0, 0, m-1, grid, n, m, dp);
}


int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
	
	for(int j1 = 0; j1 < m; j1++){
		for(int j2 = 0; j2 < m; j2++){
			if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
			else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
		}
	}
	
	for(int i = n-2; i >= 0; i--){
		for(int j1 = m-1; j1 >= 0; j1--){
			for(int j2 = m-1; j2 >= 0; j2--){
				int maxi = INT_MIN;
				int dj[] = {-1, 0, 1};
				for(int d1 = 0; d1 < 3; d1++){
					for(int d2 = 0; d2 < 3; d2++){
						if((j1 + dj[d1] >= 0 && j1 + dj[d1] <= m-1) && ((j2 + dj[d2] >= 0 && j2 + dj[d2] <= m-1))){
							if(j1 == j2){
								maxi = max(maxi, grid[i][j1] +  dp[i+1][j1 + dj[d1]][j2 + dj[d2]]); 
							}else{
								maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i+1][j1 + dj[d1]][j2 + dj[d2]]); 
							}
						}
					}
				}
				dp[i][j1][j2] = maxi;
			}
		}
	}
	return dp[0][0][m-1];
}
